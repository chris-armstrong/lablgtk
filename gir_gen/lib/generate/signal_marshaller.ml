(* Signal parameter marshalling: maps Types.gir_type to a marshaller
   specification (OCaml type + getter/setter expressions for
   Gobject.Value.t). *)

open Containers
open Types

type marshaller = {
  ocaml_type : string;
  getter_expr : string;
  setter_expr : string;
  l2_class : ocaml_class option;
  is_same_ns_class : bool;
  nullable : bool;
}

type result = Supported of marshaller | Unsupported of string

let make_marshaller ?(l2_class = None) ?(is_same_ns_class = false)
    ?(nullable = false) ~ocaml_type ~getter_expr ~setter_expr () : marshaller =
  { ocaml_type; getter_expr; setter_expr; l2_class; is_same_ns_class; nullable }

(* ===================================================================== *)
(* Primitive type table                                                  *)
(* ===================================================================== *)

(** Association list mapping GIR primitive names to (ocaml_type,
    getter_fn, setter_fn) triples for [Gobject.Value].

    Covers every GIR primitive that maps to a [Gobject.Value] accessor
    defined in [gobject.ml].  Types without a corresponding GValue accessor
    ([guint64], [glong], [gulong], [gchar], [guchar], [gpointer], [gsize],
    [gssize], [goffset]) fall through to [Tk_Primitive -> Unsupported]
    in [classify]. *)
let primitive_marshallers : (string * (string * string * string)) list =
  [
    (* G_TYPE_BOOLEAN *)
    ( "gboolean",
      ("bool", "Gobject.Value.get_boolean v", "Gobject.Value.set_boolean v x") );
    (* G_TYPE_INT: gint and its sized aliases are all G_TYPE_INT *)
    ("gint", ("int", "Gobject.Value.get_int v", "Gobject.Value.set_int v x"));
    ( "gint16",
      ("int", "Gobject.Value.get_int v", "Gobject.Value.set_int v x") );
    ( "gint32",
      ("int", "Gobject.Value.get_int v", "Gobject.Value.set_int v x") );
    (* G_TYPE_UINT: guint and its sized aliases are all G_TYPE_UINT *)
    ("guint", ("int", "Gobject.Value.get_uint v", "Gobject.Value.set_uint v x"));
    ( "guint16",
      ("int", "Gobject.Value.get_uint v", "Gobject.Value.set_uint v x") );
    ( "guint32",
      ("int", "Gobject.Value.get_uint v", "Gobject.Value.set_uint v x") );
    ("gunichar",
      ("int", "Gobject.Value.get_uint v", "Gobject.Value.set_uint v x") );
    (* G_TYPE_INT64 *)
    ( "gint64",
      ("Int64.t", "Gobject.Value.get_int64 v", "Gobject.Value.set_int64 v x") );
    (* G_TYPE_DOUBLE *)
    ( "gdouble",
      ("float", "Gobject.Value.get_double v", "Gobject.Value.set_double v x") );
    (* G_TYPE_FLOAT *)
    ( "gfloat",
      ("float", "Gobject.Value.get_float v", "Gobject.Value.set_float v x") );
    (* G_TYPE_STRING *)
    ( "utf8",
      ("string", "Gobject.Value.get_string v", "Gobject.Value.set_string v x") );
    ( "filename",
      ("string", "Gobject.Value.get_string v", "Gobject.Value.set_string v x") );
    ( "gchararray",
      ("string", "Gobject.Value.get_string v", "Gobject.Value.set_string v x") );
    ("gchar*",
      ("string", "Gobject.Value.get_string v", "Gobject.Value.set_string v x") );
    ( "const gchar*",
      ("string", "Gobject.Value.get_string v", "Gobject.Value.set_string v x") );
  ]

(* ===================================================================== *)
(* Helpers                                                               *)
(* ===================================================================== *)

(** Return true when [gir_type] represents a GLib.Variant value. *)
let is_glib_variant (gir_type : gir_type) =
  String.equal gir_type.name "GLib.Variant"
  || (match gir_type.c_type with Some ct -> String.equal ct "GVariant*" | None -> false)

(** Return true when [gir_type] is a GObject.Value (raw GValue parameter).
    The closure marshaller already copies each GValue param into a fresh
    [Gobject.Value.t] block, so the getter expression is simply [v] — the
    closure arg itself is the value the callback receives. *)
let is_gobject_value (gir_type : gir_type) =
  String.equal gir_type.name "GObject.Value"

(** Return true when [gir_type] represents a void / none return type. *)
let is_void_type (gir_type : gir_type) =
  String.equal gir_type.name "none"
  || (match gir_type.c_type with Some ct -> String.equal ct "void" | None -> false)

(** Return true when [gir_type] represents a callback / varargs parameter
    that cannot be marshalled until Milestone 4. GIR callback types typically
    have names containing "Func" or "Callback" (case-insensitive). *)
let is_callback_type (gir_type : gir_type) =
  let lower = String.lowercase_ascii gir_type.name in
  String.mem ~sub:"func" lower || String.mem ~sub:"callback" lower

(** Build the enums module prefix for a same-namespace enum/bitfield. *)
let same_ns_enums_module ~ctx =
  Utils.internal_namespace_to_module_name ctx.namespace.namespace_name ^ "_enums"

(** Build the enums module prefix for a cross-namespace enum/bitfield,
    given the external namespace name (e.g. ["Gdk"]). *)
let cross_ns_enums_module namespace =
  let pkg = Utils.library_wrapper_name namespace in
  (* Ocgtk_<ns>.<Ns>_enums *)
  String.capitalize_ascii pkg
  ^ "."
  ^ Utils.internal_namespace_to_module_name namespace
  ^ "_enums"

(** Build the L1 OCaml type for a same-namespace GObject class / interface.
    [<Mod>.t] is itself a [Gobject.obj] phantom (e.g.
    [type t = [`widget | ...] Gobject.obj]) so no extra [Gobject.obj] is
    appended; users see a value typed as [Widget.t], unifying with the
    underlying [Gobject.Value.get_object : t -> 'a obj option]. *)
let same_ns_object_type ~ctx class_name =
  let mod_path =
    Type_mappings.calculate_class_or_interface_or_record_module_name ~ctx
      ~name:class_name
  in
  mod_path ^ ".t"

(** Build the L1 OCaml type for a cross-namespace GObject class / interface.
    Cross-namespace classes are exposed via the library wrapper's [Wrappers]
    submodule, e.g. [Ocgtk_gio.Gio.Wrappers.App_info.t]. As with same-namespace
    classes, the [.t] is already a [Gobject.obj]. *)
let cross_ns_object_type ~namespace ~class_name =
  let ext = Utils.external_namespace_to_module_name namespace in
  let mod_ = Utils.module_name_of_class class_name in
  ext ^ ".Wrappers." ^ mod_ ^ ".t"

(** Look up the L2 [ocaml_class] info for a GIR type via [Type_mappings].
    Returns [None] when the type has no L2 representation (e.g. an interface
    whose layer2_class is None). *)
let lookup_l2_class ~ctx gir_type : ocaml_class option =
  match Type_mappings.find_type_mapping_for_gir_type ~ctx gir_type with
  | Some { layer2_class = Some lc; _ } -> Some lc
  | Some { layer2_class = None; _ } | None -> None

(* ===================================================================== *)
(* Enum / bitfield classification helpers                                *)
(* ===================================================================== *)

let classify_enum ~ctx ~namespace ~name =
  let enums_module =
    if String.equal namespace ctx.namespace.namespace_name then
      same_ns_enums_module ~ctx
    else cross_ns_enums_module namespace
  in
  let lower_name = String.lowercase_ascii name in
  let ocaml_type = enums_module ^ "." ^ lower_name in
  let of_int = enums_module ^ "." ^ lower_name ^ "_of_int" in
  let to_int = enums_module ^ "." ^ lower_name ^ "_to_int" in
  let getter_expr =
    of_int ^ " (Gobject.Value.get_enum_int v)"
  in
  let setter_expr =
    "Gobject.Value.set_enum_int v (" ^ to_int ^ " x)"
  in
  Supported (make_marshaller ~ocaml_type ~getter_expr ~setter_expr ())

let classify_bitfield ~ctx ~namespace ~name =
  let enums_module =
    if String.equal namespace ctx.namespace.namespace_name then
      same_ns_enums_module ~ctx
    else cross_ns_enums_module namespace
  in
  let lower_name = String.lowercase_ascii name in
  let ocaml_type = enums_module ^ "." ^ lower_name in
  let of_int = enums_module ^ "." ^ lower_name ^ "_of_int" in
  let to_int = enums_module ^ "." ^ lower_name ^ "_to_int" in
  let getter_expr =
    of_int ^ " (Gobject.Value.get_flags_int v)"
  in
  let setter_expr =
    "Gobject.Value.set_flags_int v (" ^ to_int ^ " x)"
  in
  Supported (make_marshaller ~ocaml_type ~getter_expr ~setter_expr ())

(* ===================================================================== *)
(* Class / interface classification helpers                              *)
(* ===================================================================== *)

let classify_gobject ~ctx ~gir_type ~namespace ~name : result =
  (* GObject class / interface parameters resolve to ['a obj option] when the
     GIR declares them nullable, and to a bare ['a obj] otherwise.
     Same-namespace edges are fed into [Dependency_analysis.build_dependency_graph]
     via [extract_signal_dependencies], so any cycle they create is absorbed
     into a combined module by the Tarjan SCC pass.

      The marshaller carries structured info (l2_class, is_same_ns_class, nullable)
      so that L1 emission can collapse same-class references to bare [t] or [t option]
      and L2 emission can render the L2 [class_type] and emit the correct
      [new <class>] / [#<accessor>] wrap/unwrap expressions, all without
      re-running classify. *)
  let same_ns = String.equal namespace ctx.namespace.namespace_name in
  let base_type =
    if same_ns then same_ns_object_type ~ctx name
    else cross_ns_object_type ~namespace ~class_name:name
  in
  let l2_class = lookup_l2_class ~ctx gir_type in
  let is_same_ns_class = same_ns in
  if gir_type.nullable then
    Supported
      (make_marshaller ~ocaml_type:(base_type ^ " option")
         ~getter_expr:"Gobject.Value.get_object v"
         ~setter_expr:"Gobject.Value.set_object v x"
         ~l2_class ~is_same_ns_class ~nullable:true ())
  else
    Supported
      (make_marshaller ~ocaml_type:base_type
         ~getter_expr:"Gobject.Value.get_object_exn v"
         ~setter_expr:"Gobject.Value.set_object_exn v x"
         ~l2_class ~is_same_ns_class ~nullable:false ())

(* ===================================================================== *)
(* Main classify function                                                *)
(* ===================================================================== *)

let classify ~ctx ~gir_type : result =
  (* Array types are not yet supported *)
  if Option.is_some gir_type.array then
    Unsupported "GArray not yet supported"
  (* Void / none is the return-only unit path *)
  else if is_void_type gir_type then
    Supported
      (make_marshaller ~ocaml_type:"unit" ~getter_expr:"()" ~setter_expr:"()" ())
  (* GLib.Variant has special handling before general classification *)
  else if is_glib_variant gir_type then
    Supported
      (make_marshaller ~ocaml_type:"Gvariant.t"
         ~getter_expr:"Gobject.Value.get_variant v"
         ~setter_expr:"Gobject.Value.set_variant v x" ())
  (* GObject.Value — the closure arg IS the Gobject.Value.t we want to pass.
     The closure marshaller already copies each param_values[i] into a fresh
     ml_gvalue block, so getter_expr = "v" passes it through unchanged. *)
  else if is_gobject_value gir_type then
    Supported
      (make_marshaller ~ocaml_type:"Gobject.Value.t"
         ~getter_expr:"v"
         ~setter_expr:"()" ())
  else if is_callback_type gir_type then
    Unsupported "callback parameters require Milestone 4"
  else
    (* Look up a primitive mapping before falling back to classify_type *)
    let primitive_result =
      List.assoc_opt ~eq:String.equal gir_type.name primitive_marshallers
      |> Option.map (fun (ocaml_type, getter_expr, setter_expr) ->
             Supported
               (make_marshaller ~ocaml_type ~getter_expr ~setter_expr ()))
    in
    match primitive_result with
    | Some r -> r
    | None ->
        (* Resolve namespace and name for the type *)
        let namespace, name = Utils.name_to_parts ~ctx gir_type.name in
        let type_kind = Type_mappings.classify_type ~ctx gir_type in
        (match type_kind with
        | Type_mappings.Tk_Enum -> classify_enum ~ctx ~namespace ~name
        | Type_mappings.Tk_Bitfield ->
            classify_bitfield ~ctx ~namespace ~name
        | Type_mappings.Tk_Class | Type_mappings.Tk_Interface ->
            classify_gobject ~ctx ~gir_type ~namespace ~name
        | Type_mappings.Tk_Record ->
            Unsupported
              (Printf.sprintf "boxed type %s.%s not yet supported" namespace
                 name)
        | Type_mappings.Tk_Primitive ->
            (* A primitive not in our table — should not happen often *)
            Unsupported
              (Printf.sprintf "primitive type %s not in marshaller table"
                 gir_type.name)
        | Type_mappings.Tk_Unknown ->
            Unsupported
              (Printf.sprintf "unknown type %s" gir_type.name))

(* ===================================================================== *)
(* Type rendering helpers                                                 *)
(* ===================================================================== *)

(** Render the OCaml type for a marshaller as it should appear inside the L1
    module of [current_class]. For non-object marshallers this is just
    [ocaml_type]; for a same-namespace object whose type is literally the class
    being defined, the bare ["t"] or ["t option"] is used to avoid forming a
    self-referential compilation-unit alias inside the standalone module. For
    other same-namespace objects the fully qualified type is returned. *)
let render_l1_type ~current_class (m : marshaller) : string =
  if m.is_same_ns_class then
    if String.equal m.ocaml_type (current_class ^ ".t") then "t"
    else if String.equal m.ocaml_type (current_class ^ ".t option") then
      "t option"
    else m.ocaml_type
  else
    m.ocaml_type

(** Render the L2-form OCaml type for a marshaller in the context of
    [current_layer2_module]. For object marshallers this is the L2 class type
    (e.g. ["widget_t"] or ["widget_t option"]); the module prefix is dropped
    when the class is in the current L2 module. For non-object marshallers, the
    L1 [ocaml_type] is used unchanged. *)
let render_l2_type ~current_layer2_module (m : marshaller) : string =
  match m.l2_class with
  | Some lc ->
      let qualified =
        if String.equal current_layer2_module lc.class_module then lc.class_type
        else lc.class_module ^ "." ^ lc.class_type
      in
      if m.nullable then qualified ^ " option" else qualified
  | None -> m.ocaml_type

(** Build an OCaml expression that converts an L1-form value [param_name] into
    its L2 form (used inside L2 callback param wrapping).

    For nullable object marshallers, wraps with [Option.map (fun w -> new <class> w)].
    For non-nullable object marshallers, wraps with [new <class>].
    For non-object marshallers, returns [param_name] unchanged. *)
let l2_param_wrap_expr ~current_layer2_module (m : marshaller) param_name :
    string =
  match m.l2_class with
  | Some lc ->
      let qualified =
        if String.equal current_layer2_module lc.class_module then
          lc.class_ml_name
        else lc.class_module ^ "." ^ lc.class_ml_name
      in
      if m.nullable then
        Printf.sprintf "(Option.map (fun w -> new %s w) %s)" qualified param_name
      else
        Printf.sprintf "(new %s %s)" qualified param_name
  | None -> param_name

(** Build an OCaml expression that converts an L2-form value [result_expr]
    back into its L1 form (used inside L2 callback return unwrapping).

    For nullable object marshallers, wraps with [Option.map (fun w -> w#<accessor>)].
    For non-nullable object marshallers, wraps with [(<expr>)#<accessor>].
    For non-object marshallers, returns [result_expr] unchanged. *)
let l2_return_unwrap_expr (m : marshaller) result_expr : string =
  match m.l2_class with
  | Some lc ->
      if m.nullable then
        (* The result_expr is usually a curried callback application that
           carries its own labelled arguments. Wrap it in parens before passing
           to Option.map so the labelled args bind to the callback, not to
           Option.map. *)
        Printf.sprintf "(Option.map (fun w -> w#%s) (%s))"
          lc.class_layer1_accessor result_expr
      else
        Printf.sprintf "(%s)#%s" result_expr lc.class_layer1_accessor
  | None -> result_expr
