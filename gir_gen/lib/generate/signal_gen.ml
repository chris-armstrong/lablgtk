(* Signal code generation — pure-data API.
   Provides classify / emit_l1_val / emit_l1_let / emit_l2_method.
   No file I/O: all functions return strings. *)

open StdLabels
open Gen_buffer
open Types

(* ================================================================= *)
(* OCaml keyword list (shared with parameter sanitization)           *)
(* ================================================================= *)

let ocaml_keywords =
  [
    "and";
    "as";
    "assert";
    "begin";
    "class";
    "constraint";
    "do";
    "done";
    "downto";
    "else";
    "end";
    "exception";
    "external";
    "false";
    "for";
    "fun";
    "function";
    "functor";
    "if";
    "in";
    "include";
    "inherit";
    "initializer";
    "land";
    "lazy";
    "let";
    "lor";
    "lsl";
    "lsr";
    "lxor";
    "match";
    "method";
    "mod";
    "module";
    "mutable";
    "new";
    "nonrec";
    "object";
    "of";
    "open";
    "or";
    "private";
    "rec";
    "sig";
    "struct";
    "then";
    "to";
    "true";
    "try";
    "type";
    "val";
    "virtual";
    "when";
    "while";
    "with";
  ]

(* ================================================================= *)
(* Name sanitization                                                  *)
(* ================================================================= *)

let sanitize_signal_name name =
  let base =
    name
    |> String.map ~f:(function '-' -> '_' | c -> c)
    |> Utils.to_snake_case
  in
  "on_"
  ^
  if List.exists ocaml_keywords ~f:(String.equal base) then base ^ "_" else base

let sanitize_param_name name =
  let base =
    name
    |> String.map ~f:(function '-' -> '_' | c -> c)
    |> Utils.to_snake_case
  in
  if List.exists ocaml_keywords ~f:(String.equal base) then base ^ "_" else base

(* ================================================================= *)
(* signal_emission record                                             *)
(* ================================================================= *)

type signal_emission = {
  signal : gir_signal;
  method_name : string;
  raw_signal_name : string;
  param_marshallers : (gir_param * Signal_marshaller.marshaller) list;
  return_marshaller : Signal_marshaller.marshaller option;
  strategy : [ `Connect_simple | `Closure ];
}

(* ================================================================= *)
(* classify                                                           *)
(* ================================================================= *)

(** Classify a single [gir_param], returning [Ok marshaller] or [Error reason].
    Only [In]-direction parameters are supported. *)
let classify_param ~ctx (param : gir_param) :
    (gir_param * Signal_marshaller.marshaller, string) result =
  match param.direction with
  | Out | InOut -> Fmt.error "non-In direction parameter '%s'" param.param_name
  | In -> (
      let gir_type =
        {
          param.param_type with
          nullable = param.nullable || param.param_type.nullable;
        }
      in
      match Signal_marshaller.classify ~ctx ~gir_type with
      | Signal_marshaller.Unsupported reason ->
          Fmt.error "unsupported parameter type for '%s': %s" param.param_name
            reason
      | Signal_marshaller.Supported m -> Ok (param, m))

(** Check whether any parameter classification failed; return the first error or
    the list of supported (param, marshaller) pairs. *)
let collect_param_results param_results :
    ((gir_param * Signal_marshaller.marshaller) list, string) result =
  match
    List.find_map
      ~f:(function Error reason -> Some reason | Ok _ -> None)
      param_results
  with
  | Some reason -> Error reason
  | None ->
      let supported =
        List.filter_map
          ~f:(function Ok pair -> Some pair | Error _ -> None)
          param_results
      in
      Ok supported

(** Classify the return type, converting void/unit to [None] and other supported
    types to [Some marshaller]. *)
let classify_return ~ctx (return_type : gir_type) :
    (Signal_marshaller.marshaller option, string) result =
  match Signal_marshaller.classify ~ctx ~gir_type:return_type with
  | Signal_marshaller.Supported m when String.equal m.ocaml_type "unit" ->
      Ok None
  | Signal_marshaller.Supported m -> Ok (Some m)
  | Signal_marshaller.Unsupported reason ->
      Fmt.error "unsupported return type: %s" reason

let classify ~ctx (signal : gir_signal) : (signal_emission, string) result =
  let ( let* ) = Result.bind in
  (* Collect In-direction parameters; fail on Out/InOut or unsupported type *)
  let param_results = List.map signal.sig_parameters ~f:(classify_param ~ctx) in
  let* supported_params = collect_param_results param_results in
  (* Classify the return type *)
  let* return_marshaller = classify_return ~ctx signal.return_type in
  let strategy =
    match (supported_params, return_marshaller) with
    | [], None -> `Connect_simple
    | _ -> `Closure
  in
  let method_name = sanitize_signal_name signal.signal_name in
  Ok
    {
      signal;
      method_name;
      raw_signal_name = signal.signal_name;
      param_marshallers = supported_params;
      return_marshaller;
      strategy;
    }

(* ================================================================= *)
(* Callback type rendering                                            *)
(* ================================================================= *)

(** Build the callback type string for an emission, using [render_param] to
    resolve each marshaller's OCaml type. *)
let build_callback_type ~render_param ~render_return
    (param_marshallers : (gir_param * Signal_marshaller.marshaller) list)
    (return_marshaller : Signal_marshaller.marshaller option) : string =
  let param_parts =
    List.map param_marshallers
      ~f:(fun (param, (m : Signal_marshaller.marshaller)) ->
        Fmt.str "%s:%s" (sanitize_param_name param.param_name) (render_param m))
  in
  let return_type =
    match return_marshaller with None -> "unit" | Some m -> render_return m
  in
  match param_parts with
  | [] -> Fmt.str "unit -> %s" return_type
  | _ -> Fmt.str "%s -> %s" (String.concat ~sep:" -> " param_parts) return_type

let l1_callback_type ~current_class (e : signal_emission) : string =
  let render m = Signal_marshaller.render_l1_type ~current_class m in
  build_callback_type ~render_param:render ~render_return:render
    e.param_marshallers e.return_marshaller

let l2_callback_type ~current_layer2_module (e : signal_emission) : string =
  let render m = Signal_marshaller.render_l2_type ~current_layer2_module m in
  build_callback_type ~render_param:render ~render_return:render
    e.param_marshallers e.return_marshaller

(* ================================================================= *)
(* emit_l1_val                                                        *)
(* ================================================================= *)

let emit_l1_val ~current_class (e : signal_emission) : string =
  Fmt.str
    "val %s : ?after:bool -> t -> callback:(%s) -> Gobject.Signal.handler_id\n"
    e.method_name
    (l1_callback_type ~current_class e)

(* ================================================================= *)
(* emit_l1_let                                                        *)
(* ================================================================= *)

(** Substitute the placeholder [v] in a [getter_expr] with the actual
    [Gobject.Closure.nth argv ~pos:N] expression for position [pos]. *)
let substitute_getter_expr (getter_expr : string) (pos : int) : string =
  let nth_expr = Fmt.str "(Gobject.Closure.nth argv ~pos:%d)" pos in
  Fmt.str "(let v = %s in %s)" nth_expr getter_expr

(** Emit the closure body for signals with parameters and/or a return value. *)
let emit_closure_body (e : signal_emission) : string =
  let buf = Buffer.create 256 in
  Buffer.add_string buf "Gobject.Closure.create (fun argv ->\n";
  (* Extract each parameter from the closure argv (positions start at 1) *)
  List.iteri e.param_marshallers
    ~f:(fun i (param, (m : Signal_marshaller.marshaller)) ->
      let pos = i + 1 in
      let pname = sanitize_param_name param.param_name in
      bprintf buf "    let %s = %s in\n" pname
        (substitute_getter_expr m.getter_expr pos));
  (* Build the callback application *)
  let callback_args =
    List.map e.param_marshallers ~f:(fun (param, _) ->
        Fmt.str "~%s" (sanitize_param_name param.param_name))
  in
  let callback_call =
    match callback_args with
    | [] -> "callback ()"
    | args -> Fmt.str "callback %s" (String.concat ~sep:" " args)
  in
  (match e.return_marshaller with
  | None -> bprintf buf "    %s)\n" callback_call
  | Some m ->
      bprintf buf "    let result = %s in\n" callback_call;
      (* setter_expr uses x as placeholder for the value to set *)
      let setter =
        (* The setter_expr pattern is like "Gobject.Value.set_boolean v x"
           where v is the target GValue (Gobject.Closure.result argv) and x is
           the OCaml value.  Replace v with the result value argument and x
           with result. *)
        Fmt.str
          "let v = Gobject.Closure.result argv in\n\
          \    let x = result in\n\
          \    %s"
          m.setter_expr
      in
      bprintf buf "    %s)" setter);
  Buffer.contents buf

let emit_l1_let (e : signal_emission) : string =
  match e.strategy with
  | `Connect_simple ->
      Fmt.str
        "let %s ?after obj ~callback =\n\
        \  Gobject.Signal.connect_simple obj ~name:\"%s\" ~callback\n\
        \    ~after:(Option.value after ~default:false)\n\n"
        e.method_name e.raw_signal_name
  | `Closure ->
      let buf = Buffer.create 256 in
      bprintf buf "let %s ?after obj ~callback =\n" e.method_name;
      bprintf buf "  let closure = %s in\n" (emit_closure_body e);
      bprintf buf
        "  Gobject.Signal.connect obj ~name:\"%s\" ~callback:closure\n"
        e.raw_signal_name;
      bprintf buf "    ~after:(Option.value after ~default:false)\n\n";
      Buffer.contents buf

(* ================================================================= *)
(* emit_l2_method                                                     *)
(* ================================================================= *)

(** True iff at least one param or the return value of this signal carries an
    [l2_class] and therefore requires L1↔L2 wrapping inside the L2 forwarder. *)
let needs_l2_wrapping (e : signal_emission) : bool =
  List.exists e.param_marshallers
    ~f:(fun (_, (m : Signal_marshaller.marshaller)) ->
      Option.is_some m.l2_class)
  || Option.fold e.return_marshaller ~none:false
       ~some:(fun (m : Signal_marshaller.marshaller) ->
         Option.is_some m.l2_class)

let emit_l2_method ~current_layer2_module ~layer1_module_name ~class_snake
    (e : signal_emission) : string =
  if not (needs_l2_wrapping e) then
    (* No GObject params or return — the L1 callback type matches L2 exactly,
       so forward the user's callback through unchanged. *)
    Fmt.str
      "  method %s ?(after = false) ~callback () =\n\
      \    %s.%s ~after self#as_%s ~callback\n\n"
      e.method_name layer1_module_name e.method_name class_snake
  else
    let buf = Buffer.create 256 in
    bprintf buf "  method %s ?(after = false) ~callback () =\n" e.method_name;
    bprintf buf "    %s.%s ~after self#as_%s\n" layer1_module_name e.method_name
      class_snake;
    (* Build the L1→L2 adapter so the runtime marshalling layer stays hidden from user callbacks. *)
    let format_user_arg (p, m) =
      let pname = sanitize_param_name p.param_name in
      let wrapped =
        Signal_marshaller.l2_param_wrap_expr ~current_layer2_module m pname
      in
      if String.equal wrapped pname then Fmt.str "~%s" pname
      else Fmt.str "~%s:%s" pname wrapped
    in
    let fun_param_list, _user_callback_args, user_call =
      match e.param_marshallers with
      | [] -> ("()", "()", "callback ()")
      | params ->
          let names =
            List.map params ~f:(fun (p, _) -> sanitize_param_name p.param_name)
          in
          let fun_params =
            String.concat ~sep:" " (List.map names ~f:(Fmt.str "~%s"))
          in
          let user_callback_args =
            String.concat ~sep:" " (List.map params ~f:format_user_arg)
          in
          ( fun_params,
            user_callback_args,
            Fmt.str "callback %s" user_callback_args )
    in
    let body =
      match e.return_marshaller with
      | None -> user_call
      | Some m -> Signal_marshaller.l2_return_unwrap_expr m user_call
    in
    bprintf buf "      ~callback:(fun %s -> %s)\n\n" fun_param_list body;
    Buffer.contents buf

(* ================================================================= *)
(* emit_l2_method_sig                                                 *)
(* ================================================================= *)

(** Emit a class type method signature for insertion into a generated L2 class
    type body (.mli / class type definition). Unlike [emit_l2_method] (which
    emits a concrete method body), this emits only the method type. *)
let emit_l2_method_sig ~current_layer2_module (e : signal_emission) : string =
  Fmt.str
    "    method %s : ?after:bool -> callback:(%s) -> unit -> \
     Gobject.Signal.handler_id\n"
    e.method_name
    (l2_callback_type ~current_layer2_module e)
