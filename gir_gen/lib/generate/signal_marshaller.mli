(** Signal parameter marshalling — maps a GIR type to the OCaml getter/setter
    expressions and OCaml type string needed to marshal a signal parameter
    through [Gobject.Value.t].

    This module is purely functional: it has no side effects and does not
    perform any I/O or code emission. Callers use the returned [marshaller]
    record to splice getter/setter expressions into the generated signal
    wrappers, and the [render_*] / [l2_*] helpers to obtain the type and
    conversion expressions appropriate to the current emission context. *)

open Types

type marshaller = {
  ocaml_type : string;
      (** Default L1-form OCaml type expression — fully qualified and not
          self-aware.

          Examples:
          - ["bool"] for [gboolean]
          - ["Gtk_enums.orientation"] for a same-namespace enum
          - ["Ocgtk_gdk.Gdk_enums.modifiertype"] for a cross-namespace bitfield
          - ["Widget.t"] for a non-nullable same-namespace GObject class
          - ["Widget.t option"] for a nullable same-namespace GObject class
          - ["Ocgtk_gio.Gio.Wrappers.File.t"] for a non-nullable cross-namespace
          - ["Gvariant.t"] for [GLib.Variant]

          Object types render as ["<Mod>.t"] or ["<Mod>.t option"] — not
          [".t Gobject.obj"] — because the per-class [.t] alias is itself a
          [Gobject.obj] phantom; appending another [Gobject.obj] would
          double-wrap and break unification with the L1↔L2 conversion.

          For non-object marshallers this string is used directly at both L1 and
          L2 emission. For object marshallers, callers should prefer
          {!render_l1_type} (so same-class references collapse to bare ["t"] or
          ["t option"]) and {!render_l2_type} (which yields the L2 class type
          [widget_t] or [widget_t option]). *)
  getter_expr : string;
      (** OCaml expression that extracts the typed value from a
          [Gobject.Value.t]. Context-independent: references the placeholder
          [v]. *)
  setter_expr : string;
      (** OCaml expression that stores a typed value into a [Gobject.Value.t].
          Context-independent: references placeholders [v] and [x]. *)
  l2_class : ocaml_class option;
      (** Populated when this marshaller represents a GObject class / interface
          for which an L2 class wrapper exists. Used by L2 emission to render
          the [class_type] in method sigs and the [class_ml_name] /
          [class_layer1_accessor] in L1↔L2 wrap/unwrap expressions. *)
  is_same_ns_class : bool;
      (** [true] when the target is a GObject class / interface in the same
          namespace as the generation context. Used by L1 emission to detect a
          self-reference and emit the bare [t] or [t option] form. [false] for
          non-object marshallers and for cross-namespace objects. *)
  nullable : bool;
      (** [true] when the GIR type declares this parameter nullable. Object
          marshallers use [get_object] / [set_object] (option types) when [true]
          and [get_object_exn] / [set_object_exn] (bare types) when [false]. *)
}
(** A resolved marshalling specification for a single signal parameter or return
    type. *)

(** The result of classifying a GIR type for signal marshalling. *)
type result =
  | Supported of marshaller
      (** The type can be marshalled; the record contains full details. *)
  | Unsupported of string
      (** The type cannot currently be marshalled; the string is a
          human-readable reason (used for error messages and test assertions).
      *)

val classify : ctx:generation_context -> gir_type:gir_type -> result
(** [classify ~ctx ~gir_type] determines how to marshal [gir_type] as a signal
    parameter or return type in the context of the namespace described by [ctx].
    The returned [marshaller] is structural — no rendering context is threaded
    through; rendering happens at emit time via {!render_l1_type} /
    {!render_l2_type} / {!l2_param_wrap_expr} / {!l2_return_unwrap_expr}.

    Same-namespace types are resolved directly from [ctx.enums],
    [ctx.bitfields], [ctx.classes], [ctx.interfaces], and [ctx.records].
    Cross-namespace types are resolved via [ctx.cross_references].

    GObject class / interface parameters are [Supported] with [ocaml_type] of
    the form ["<Mod>.t"] when non-nullable and ["<Mod>.t option"] when nullable.
    The marshaller chooses [get_object_exn] / [set_object_exn] for non-nullable
    params and [get_object] / [set_object] for nullable ones. Same-namespace
    edges introduced by signal params are fed into the dependency graph via
    [Dependency_analysis.extract_signal_dependencies], so any cycles are
    absorbed by the Tarjan SCC pass into combined modules.

    Returns [Supported m] when marshalling is possible, [Unsupported reason]
    otherwise. Currently unsupported cases include:
    - Array types ([GLib.Array])
    - Boxed record types (e.g. [Gtk.TextIter])
    - Callback parameter types (deferred to Milestone 4) *)

val render_l1_type : current_class:string -> marshaller -> string
(** [render_l1_type ~current_class m] returns the OCaml type expression for [m]
    as it should appear inside the L1 module of [current_class]. For non-object
    marshallers this is just [m.ocaml_type]; for a same-namespace object whose
    [is_same_ns_class] is true, the bare ["t"] or ["t option"] is used to avoid
    forming a self-referential compilation-unit alias inside the standalone
    module. *)

val render_l2_type : current_layer2_module:string -> marshaller -> string
(** [render_l2_type ~current_layer2_module m] returns the L2-form OCaml type
    expression for [m]. Object marshallers render as the L2 [class_type] (e.g.
    ["widget_t"] or ["widget_t option"]), with the module prefix dropped when
    the L2 class lives in [current_layer2_module]. Non-object marshallers render
    as [m.ocaml_type] unchanged. *)

val l2_param_wrap_expr :
  current_layer2_module:string -> marshaller -> string -> string
(** [l2_param_wrap_expr ~current_layer2_module m name] builds an OCaml
    expression that converts the L1-form value bound to [name] into its L2 form,
    suitable for inlining where the L2 callback param is forwarded to the user's
    callback. Nullable object marshallers wrap with
    [Option.map (fun w -> new <class> w) name]; non-nullable object marshallers
    wrap with [new <class> name]; non-object marshallers return [name]
    unchanged. *)

val l2_return_unwrap_expr : marshaller -> string -> string
(** [l2_return_unwrap_expr m expr] builds an OCaml expression that converts the
    L2-form value produced by [expr] (typically the user callback's return
    value) back into its L1 form. Nullable object marshallers wrap with
    [Option.map (fun w -> w#<accessor>) expr]; non-nullable object marshallers
    wrap with [(expr)#<accessor>]; non-object marshallers return [expr]
    unchanged. *)
