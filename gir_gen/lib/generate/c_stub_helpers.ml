(* C Stub Code Generation - Shared Helpers *)

(** This module provides the C stub code generation primitives that are shared
    across the stub generators (method, constructor, property, record, class)
    and the guard fallback emitters.

    Concern-specific generation has been extracted to dedicated modules:
    - C_stub_type_analysis: type classification and property introspection
    - C_stub_array_conv: array conversion between OCaml and C
    - C_stub_gvalue: GValue getter/setter generation and property analysis
    - C_stub_forward_decl: forward declaration section generation
    - C_stub_multi_param: multi-parameter C wrapper generation
    - C_stub_version_guard: version-guard fallback stub emission
    - C_stub_os_guard: OS-guard fallback stub emission *)

open Gen_buffer
open Containers
open StdLabels
open Types

(* Get C include header for a namespace. This uses
   hardcoded values for now because the c:include is
   not properly parsed from the GIR file. *)
let include_header_for_namespace namespace_name =
  let ns_lower = String.lowercase_ascii namespace_name in
  match ns_lower with
  | "gtk" -> "#include <gtk/gtk.h>"
  | "gdk" -> "#include <gtk/gtk.h>"
  | "pango" -> "#include <pango/pango.h>"
  | "gdkpixbuf" -> "#include <gdk-pixbuf/gdk-pixbuf.h>"
  | "gsk" -> "#include <gtk/gtk.h>"
  | "graphene" -> "#include <graphene.h>"
  | "gio" -> "#include <gio/gio.h>"
  | "gobject" -> "#include <glib-object.h>"
  | "cairo" -> "#include <cairo-gobject.h>"
  | "pangocairo" -> "#include <pango/pangocairo.h>"
  | _ -> Fmt.str "#include <%s/%s.h>" ns_lower ns_lower

(* [get_c_type_str ~ctx gir_type] retrieves the C type string representation for a
   GIR type. Returns the c_type directly if present, otherwise consults the
   type mapping context. Falls back to "void" if no mapping is found. Shared
   by the method and property C-stub generators. *)
let get_c_type_str ~ctx (gir_type : gir_type) =
  match gir_type.c_type with
  | Some c_type -> c_type
  | None ->
      Type_mappings.find_type_mapping_for_gir_type ~ctx gir_type
      |> Option.map (fun (tm : type_mapping) -> tm.c_type)
      |> Option.value ~default:"void"

(** Code generation utilities *)
module Code_gen = struct
  (* Default type mapping for when no mapping is found *)
  let default_type_mapping =
    {
      ocaml_type = "unit";
      c_to_ml = "Val_unit";
      ml_to_c = "Unit_val";
      layer2_class = None;
      c_type = "void";
      is_value_type_record = false;
      transfer_strategy = Ts_none;
    }

  (* Generate C file header with common includes and type conversions *)
  let generate_c_file_header ~ctx ?(class_name = "") () =
    let buf = Buffer.create 1024 in
    Buffer.add_string buf "/* GENERATED CODE - DO NOT EDIT */\n";
    if not (String.equal class_name "") then
      bprintf buf "/* C bindings for %s */\n" class_name
    else
      bprintf buf "/* Generated from %s.gir */\n" ctx.namespace.namespace_name;
    Buffer.add_string buf "\n";
    bprintf buf "%s\n"
      (include_header_for_namespace ctx.namespace.namespace_name);
    Buffer.add_string buf "#include <caml/mlvalues.h>\n";
    Buffer.add_string buf "#include <caml/memory.h>\n";
    Buffer.add_string buf "#include <caml/alloc.h>\n";
    Buffer.add_string buf "#include <caml/callback.h>\n";
    Buffer.add_string buf "#include <caml/fail.h>\n";
    Buffer.add_string buf "#include <caml/hash.h>\n";
    Buffer.add_string buf "#include <caml/custom.h>\n";
    Buffer.add_string buf "#include \"wrappers.h\"\n";
    (* Include converters.h for GTK library - contains GTK/GDK/Pango specific type conversions *)
    if String.equal (String.lowercase_ascii ctx.namespace.namespace_name) "gtk"
    then Buffer.add_string buf "#include \"converters.h\"\n";
    Buffer.add_string buf "\n";
    (* Linux-only GIO headers are guarded so the stub file compiles on macOS/FreeBSD. *)
    let is_linux_only_header h =
      let starts_with prefix s =
        let n = String.length prefix in
        String.length s >= n && String.equal (String.sub s ~pos:0 ~len:n) prefix
      in
      starts_with "gio/gunix" h
      || String.equal h "gio/gdesktopappinfo.h"
      || String.equal h "gio/gfiledescriptorbased.h"
    in
    let regular_includes, linux_only_includes =
      List.partition
        ~f:(fun h -> not (is_linux_only_header h))
        ctx.repository.repository_c_includes
    in
    List.iter
      ~f:(fun c_include ->
        Buffer.add_string buf (Fmt.str "#include <%s>\n" c_include))
      regular_includes;
    (match linux_only_includes with
    | [] -> ()
    | _ ->
        Buffer.add_string buf "#ifdef __linux__\n";
        List.iter
          ~f:(fun c_include ->
            Buffer.add_string buf (Fmt.str "#include <%s>\n" c_include))
          linux_only_includes;
        Buffer.add_string buf "#endif /* __linux__ */\n");

    (* Include library-specific header for type conversions and forward declarations *)
    Buffer.add_string buf
      "/* Include library-specific type conversions and forward declarations */\n";
    let ns_lower = String.lowercase_ascii ctx.namespace.namespace_name in
    bprintf buf "#include \"%s_decls.h\"\n" ns_lower;
    Buffer.add_string buf "\n";

    (* Type-specific macros are defined in the library-specific <ns>_decls.h header
       which is included above. No need to generate them here. *)
    Buffer.contents buf

  (* Helper: extract base C type by removing trailing pointer *)
  let base_c_type_of c_type =
    CCString.chop_suffix ~suf:"*" c_type |> Option.value ~default:c_type

  (** Build return statement code based on return type and out parameters.
      Handles both throwing and non-throwing methods. *)
  let build_return_statement ~throws ml_primary out_conversions =
    match (ml_primary, out_conversions) with
    | None, [] ->
        if throws then
          "if (error == NULL) CAMLreturn(Res_Ok(ValUnit)); else \
           CAMLreturn(Res_Error(Val_GError(error)));"
        else "CAMLreturn(Val_unit);"
    | Some v, [] ->
        if throws then
          Fmt.str
            "if (error == NULL) CAMLreturn(Res_Ok(%s)); else \
             CAMLreturn(Res_Error(Val_GError(error)));"
            v
        else Fmt.str "CAMLreturn(%s);" v
    | None, [ single ] ->
        if throws then
          "CAMLlocal1(ret);\n    ret = " ^ single
          ^ ";\n\
            \    if (error == NULL) CAMLreturn(Res_Ok(ret)); else \
             CAMLreturn(Res_Error(Val_GError(error)));"
        else Fmt.str "CAMLreturn(%s);" single
    | Some v, outs ->
        let all = v :: outs in
        let stores =
          List.mapi
            ~f:(fun i expr -> Fmt.str "Store_field(ret, %d, %s);" i expr)
            all
        in
        let alloc = Fmt.str "ret = caml_alloc(%d, 0);" (List.length all) in
        if throws then
          String.concat ~sep:"\n    "
            ([ "CAMLlocal1(ret);"; alloc ]
            @ stores
            @ [
                "if (error == NULL) CAMLreturn(Res_Ok(ret)); else \
                 CAMLreturn(Res_Error(Val_GError(error)));";
              ])
        else
          String.concat ~sep:"\n    "
            ([ "CAMLlocal1(ret);"; alloc ] @ stores @ [ "CAMLreturn(ret);" ])
    | None, outs ->
        let stores =
          List.mapi
            ~f:(fun i expr -> Fmt.str "Store_field(ret, %d, %s);" i expr)
            outs
        in
        let alloc = Fmt.str "ret = caml_alloc(%d, 0);" (List.length outs) in
        if throws then
          String.concat ~sep:"\n    "
            ([ "CAMLlocal1(ret);"; alloc ]
            @ stores
            @ [
                "if (error == NULL) CAMLreturn(Res_Ok(ret)); else \
                 CAMLreturn(Res_Error(Val_GError(error)));";
              ])
        else
          String.concat ~sep:"\n    "
            ([ "CAMLlocal1(ret);"; alloc ] @ stores @ [ "CAMLreturn(ret);" ])

  (** Generate C code for constructors by iterating and filtering. Applies
      [Filtering.should_generate_constructor] filter and appends generated code
      to the buffer. *)
  let generate_constructors ~ctx ~c_type ~class_name ~buf ~generator
      constructors =
    List.iter
      ~f:(fun ctor ->
        if Filtering.should_generate_constructor ~ctx ctor then
          try Buffer.add_string buf (generator ~ctx ~c_type ~class_name ctor)
          with Failure msg ->
            Fmt.epr "  Warning: skipping constructor %s: %s\n" ctor.ctor_name
              msg)
      constructors

  (** Generate C code for methods by iterating and filtering. Applies the
      central [Filtering.should_skip_method_binding], passing [entity_kind] so
      the record copy/free/unref filter is folded into the same answer as
      varargs / unsupported arrays / non-introspectable etc. Methods are
      processed in reverse order (List.rev). *)
  let generate_methods ~ctx ~c_type ~class_name ~buf ~generator ~entity_kind
      methods =
    List.iter
      ~f:(fun (meth : gir_method) ->
        if not (Filtering.should_skip_method_binding ~ctx ~entity_kind meth)
        then
          try Buffer.add_string buf (generator ~ctx ~c_type meth class_name)
          with Failure msg ->
            Fmt.epr "  Warning: skipping method %s: %s\n" meth.method_name msg)
      (List.rev methods)
end

(* Accumulator for parameter processing - kept at top level for record field access *)
type param_acc = {
  ocaml_idx : int;
  decls : Buffer.t;
  args : string list;
  cleanups : string list;
}

let is_copy_method = Filtering.is_copy_method
let is_free_method = Filtering.is_free_method
let is_copy_or_free = Filtering.is_copy_or_free
let fold_mapi = C_stub_type_analysis.Type_analysis.fold_mapi
let list_contains = C_stub_type_analysis.Type_analysis.list_contains
let generate_c_file_header = Code_gen.generate_c_file_header
let base_c_type_of = Code_gen.base_c_type_of
let build_return_statement = Code_gen.build_return_statement
let generate_constructors = Code_gen.generate_constructors
let generate_methods = Code_gen.generate_methods
let default_type_mapping = Code_gen.default_type_mapping

(* Nullable conversion expressions - these depend on GValue.analyze_property_type *)
let nullable_c_to_ml_expr ~ctx ~var ~(gir_type : gir_type)
    ~(mapping : type_mapping) ?(direction : Types.gir_direction = In) () =
  (* out parameters that are record types are stack allocated, so we need to pass by reference
     to their Val_x function, which will copy them into the OCaml heap.
     Check both the type_mapping flag (works for cross-namespace) and analyze_property_type
     (works for current namespace records with full record info). *)
  let var_expr =
    match direction with
    | (Out | InOut) when mapping.is_value_type_record -> Fmt.str "&%s" var
    | Out | InOut -> (
        match C_stub_gvalue.GValue.analyze_property_type ~ctx gir_type with
        | { record_info = Some ({ opaque = false; _ }, _, _); _ } ->
            Fmt.str "&%s" var
        | _ -> var)
    | In -> var
  in
  if not gir_type.nullable then Fmt.str "%s(%s)" mapping.c_to_ml var_expr
  else
    match gir_type with
    | { c_type; _ } when Filtering.is_string_type c_type ->
        Fmt.str "Val_option_string(%s)" var_expr
    | { c_type = Some c_type; _ }
      when String.length c_type > 0
           && String.equal
                (String.sub c_type ~pos:(String.length c_type - 1) ~len:1)
                "*" ->
        Fmt.str "Val_option(%s, %s)" var_expr mapping.c_to_ml
    | _ -> Fmt.str "%s(%s)" mapping.c_to_ml var_expr

let nullable_ml_to_c_expr ~var ~(gir_type : gir_type) ~(mapping : type_mapping)
    =
  (* Handle LIST_INLINE marker - should not reach here, handled by caller *)
  if String.equal mapping.ml_to_c "LIST_INLINE" then
    failwith
      "nullable_ml_to_c_expr: LIST_INLINE should be handled by caller before \
       reaching here"
  else
    (* Check for string types with transfer-ownership="full" - need to copy to mutable buffer *)
    match gir_type.transfer_ownership with
    | TransferFull when Filtering.is_string_type gir_type.c_type ->
        (* String with transfer-full: copy to mutable buffer before passing *)
        if not gir_type.nullable then Fmt.str "String_copy(%s)" var
        else Fmt.str "String_option_val(String_copy(%s))" var
    | TransferNone | TransferContainer | TransferFloating | TransferFull -> (
        if
          (* Normal case - no copy needed *)
          not gir_type.nullable
        then Fmt.str "%s(%s)" mapping.ml_to_c var
        else
          match gir_type with
          | { c_type; _ } when Filtering.is_string_type c_type ->
              Fmt.str "String_option_val(%s)" var
          | { c_type = Some c_type; _ }
            when String.length c_type > 0
                 && String.equal
                      (String.sub c_type ~pos:(String.length c_type - 1) ~len:1)
                      "*" ->
              Fmt.str "Option_val(%s, %s, NULL)" var mapping.ml_to_c
          | _ -> Fmt.str "%s(%s)" mapping.ml_to_c var)

(** Build a CAMLprim failwith stub. [params] and [param_names] must correspond.
    [param_count_for_caml] controls how many names appear in CAMLparam. Shared
    by the version-guard and OS-guard fallback stub emitters. *)
let emit_failwith_stub_core ~ml_name ~params ~param_names ~param_count_for_caml
    ~failwith_msg =
  let param_names_for_caml = CCList.take param_count_for_caml param_names in
  let buf = Buffer.create 256 in
  bprintf buf "\nCAMLexport CAMLprim value %s(%s)\n{\n" ml_name
    (String.concat ~sep:", " params);
  bprintf buf "CAMLparam%d(%s);\n" param_count_for_caml
    (String.concat ~sep:", " param_names_for_caml);
  List.iter ~f:(fun pname -> bprintf buf "(void)%s;\n" pname) param_names;
  bprintf buf "caml_failwith(\"%s\");\n" failwith_msg;
  bprintf buf "return Val_unit;\n}\n";
  Buffer.contents buf

(** Build params and param_names for a constructor with [n] parameters. *)
let make_constructor_params param_count =
  let param_names =
    match param_count with
    | 0 -> [ "unit" ]
    | n -> List.init ~len:n ~f:(fun i -> Fmt.str "arg%d" (i + 1))
  in
  let params =
    match param_count with
    | 0 -> [ "value unit" ]
    | n -> List.init ~len:n ~f:(fun i -> Fmt.str "value arg%d" (i + 1))
  in
  (params, param_names)

(** Build params and param_names for a method with [n] in-parameters plus self.
*)
let make_method_params in_param_count =
  let param_names =
    "self"
    :: List.init ~len:in_param_count ~f:(fun i -> Fmt.str "arg%d" (i + 1))
  in
  let params =
    "value self"
    :: List.init ~len:in_param_count ~f:(fun i -> Fmt.str "value arg%d" (i + 1))
  in
  (params, param_names)
