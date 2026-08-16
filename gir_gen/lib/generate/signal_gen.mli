(** Signal code generation — pure-data API.

    [Signal_gen] classifies GIR signals into a [signal_emission] record that
    captures all information needed to emit L1 module bindings and L2 class
    method forwarders. All functions are pure and produce strings; no file I/O
    is performed here.

    The marshaller stored on each [signal_emission] is structural, not
    pre-rendered: the L1 emitter passes [~current_class] to [emit_l1_val] /
    [emit_l1_let] and the L2 emitter passes [~current_layer2_module] to
    [emit_l2_method] / [emit_l2_method_sig]; each side renders the callback type
    and any wrap/unwrap expressions in its own context.

    Invariants:
    - [classify] only returns [Ok] when every [In]-direction parameter has a
      supported marshaller and the return type is supported.
    - All [emit_*] functions are total over their inputs — they never fail. *)

open Types

type signal_emission = {
  signal : gir_signal;  (** The original GIR signal record. *)
  method_name : string;
      (** Sanitized OCaml method name, prefixed with ["on_"]. Example:
          ["on_clicked"] for signal ["clicked"]. *)
  raw_signal_name : string;
      (** Original GIR signal name used as the GLib signal string. Example:
          ["key-pressed"]. *)
  param_marshallers : (gir_param * Signal_marshaller.marshaller) list;
      (** In-direction parameters paired with their marshalling specs. Non-In
          parameters are excluded (signals with Out/InOut params return [Error]
          from [classify]). *)
  return_marshaller : Signal_marshaller.marshaller option;
      (** [None] for void/unit return; [Some m] for a non-void return type. *)
  strategy : [ `Connect_simple | `Closure ];
      (** [`Connect_simple] when no parameters and void return (fast path);
          [`Closure] otherwise (uses [Gobject.Closure.create]). *)
}
(** All computed values for a single signal, derived from [classify].

    The callback type is not pre-rendered: emit functions build it from the
    structural [param_marshallers] / [return_marshaller] using their layer's
    rendering helpers in {!Signal_marshaller}. *)

val sanitize_signal_name : string -> string
(** [sanitize_signal_name name] converts a GIR signal name to a valid OCaml
    identifier prefixed with ["on_"]. Delegates to [Utils.ocaml_parameter_name]
    for hyphen replacement, snake_casing, and keyword escaping.

    Example: ["key-pressed"] -> ["on_key_pressed"]. *)

val classify :
  ctx:generation_context -> gir_signal -> (signal_emission, string) result
(** [classify ~ctx signal] analyses [signal] and returns a fully-populated
    [signal_emission] record when all parameters and the return type can be
    marshalled.

    Returns [Error reason] when:
    - Any parameter has a non-In direction (Out or InOut).
    - Any parameter type is [Unsupported] by {!Signal_marshaller.classify}.
    - The return type is [Unsupported] by {!Signal_marshaller.classify}.

    The [reason] string is human-readable and suitable for stderr skip messages
    (format: ["Skipping signal '<name>' for <Class> (<reason>)"]). *)

val l1_callback_type : current_class:string -> signal_emission -> string
(** [l1_callback_type ~current_class e] returns the OCaml callback function type
    as it appears in L1 emission (e.g.
    ["~child:Widget.t option -> page:int -> unit"]). Same-namespace GObject
    references to [current_class] collapse to [t option]. Exposed primarily for
    tests; production callers use {!emit_l1_val}. *)

val emit_l1_val : current_class:string -> signal_emission -> string
(** [emit_l1_val ~current_class e] returns a single [val] declaration for
    insertion into the L1 [.mli] of [current_class].

    Same-namespace GObject references to [current_class] render as bare
    [t option] to avoid the standalone module's self-alias error; all other
    types are rendered in their qualified L1 form.

    Example output:
    {[
    val on_clicked :
      ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
    ]}

    The [t] argument is the L1 module's own [t] (positional, not labelled). *)

val emit_l1_let : signal_emission -> string
(** [emit_l1_let e] returns a [let] binding for insertion into a generated L1
    [.ml] file.

    For [`Connect_simple] strategy, the binding delegates to
    [Gobject.Signal.connect_simple]. For [`Closure] strategy, a
    [Gobject.Closure.create] expression is built that extracts each parameter
    with [Gobject.Closure.nth argv ~pos:N] (positions start at 1; position 0 is
    the sender object and is implicit).

    The [let] body uses only the marshaller's [getter_expr] / [setter_expr]
    fields — no type rendering — so it does not depend on the current class. *)

val emit_l2_method :
  current_layer2_module:string ->
  layer1_module_name:string ->
  class_snake:string ->
  signal_emission ->
  string
(** [emit_l2_method ~current_layer2_module ~layer1_module_name ~class_snake e]
    returns a class method definition for insertion into a generated L2 class
    body.

    When the signal has no GObject-typed params or return, the L2 forwarder is a
    thin pass-through:
    {[
      method on_clicked ?(after = false) ~callback () =
        Button.on_clicked ~after self#as_button ~callback
    ]}

    When at least one param or the return value carries an [l2_class], the
    forwarder builds an L1↔L2 wrapping closure: GObject params are wrapped with
    [Option.map (fun w -> new <class> w)] before being passed to the user
    callback, and a GObject return is unwrapped with
    [Option.map (fun w -> w#<accessor>)] before being handed back to L1:
    {[
      method on_page_added ?(after = false) ~callback () =
        Notebook.on_page_added ~after self#as_notebook
          ~callback:(fun ~child ~page ->
            callback ~child:(Option.map (fun w -> new widget w) child) ~page)
    ]}

    The trailing [()] terminator is present so the optional [?after] argument
    does not trigger OCaml warning 16. *)

val emit_l2_method_sig :
  current_layer2_module:string -> signal_emission -> string
(** [emit_l2_method_sig ~current_layer2_module e] returns a class type method
    signature for insertion into a generated L2 class type body.

    GObject params and returns render as their L2 class types (e.g.
    [widget_t option]), qualified by [current_layer2_module] only when the
    target class lives in a different L2 module. Non-object types render as
    their L1 form.

    Example output:
    {[
      method on_close_request :
        ?after:bool -> callback:(unit -> bool) -> unit ->
        Gobject.Signal.handler_id
    ]} *)
