(* C Stub Code Generation - Shared Helpers *)

(** This module provides organized C stub code generation functionality. The
    following sub-modules have been extracted to separate files for better
    organization:
    - Type_analysis: Type classification and property introspection
      (c_stub_type_analysis.ml)
    - Array_conv: Array conversion between OCaml and C (c_stub_array_conv.ml)
    - GValue: GValue getter/setter generation (c_stub_gvalue.ml)

    This module re-exports these modules for backward compatibility and
    provides:
    - Code_gen: Code generation utilities (headers, return statements, etc.)
    - Forward_decl: Forward declaration generation helpers *)

open Printf
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
  | _ -> sprintf "#include <%s/%s.h>" ns_lower ns_lower

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
        Buffer.add_string buf (sprintf "#include <%s>\n" c_include))
      regular_includes;
    (match linux_only_includes with
    | [] -> ()
    | _ ->
        Buffer.add_string buf "#ifdef __linux__\n";
        List.iter
          ~f:(fun c_include ->
            Buffer.add_string buf (sprintf "#include <%s>\n" c_include))
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
          sprintf
            "if (error == NULL) CAMLreturn(Res_Ok(%s)); else \
             CAMLreturn(Res_Error(Val_GError(error)));"
            v
        else sprintf "CAMLreturn(%s);" v
    | None, [ single ] ->
        if throws then
          "CAMLlocal1(ret);\n    ret = " ^ single
          ^ ";\n\
            \    if (error == NULL) CAMLreturn(Res_Ok(ret)); else \
             CAMLreturn(Res_Error(Val_GError(error)));"
        else sprintf "CAMLreturn(%s);" single
    | Some v, outs ->
        let all = v :: outs in
        let stores =
          List.mapi
            ~f:(fun i expr -> sprintf "Store_field(ret, %d, %s);" i expr)
            all
        in
        let alloc = sprintf "ret = caml_alloc(%d, 0);" (List.length all) in
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
            ~f:(fun i expr -> sprintf "Store_field(ret, %d, %s);" i expr)
            outs
        in
        let alloc = sprintf "ret = caml_alloc(%d, 0);" (List.length outs) in
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
            eprintf "  Warning: skipping constructor %s: %s\n" ctor.ctor_name
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
            eprintf "  Warning: skipping method %s: %s\n" meth.method_name msg)
      (List.rev methods)
end

(** Forward declaration generation helpers - shared across record, class, enum,
    and bitfield modules *)
module Forward_decl = struct
  (** Generate a section of forward declarations. Common pattern across record,
      class, enum, and bitfield modules.

      Parameters:
      - buf: Buffer to append declarations to
      - items: List of items to generate declarations for
      - section_comment: Comment header for this section
      - generate_one: Function to generate declarations for a single item
      - deduplicate: Whether to track seen types with Hashtbl (default: true) *)
  let generate_section ~(buf : Buffer.t) ~(items : 'a list)
      ~(section_comment : string) ~(generate_one : 'a -> unit)
      ?(deduplicate : bool = true) () =
    if List.length items > 0 then (
      Buffer.add_string buf section_comment;
      let seen = if deduplicate then Some (Hashtbl.create 97) else None in
      List.iter
        ~f:(fun item ->
          match seen with
          | Some tbl when Hashtbl.mem tbl item -> ()
          | Some tbl ->
              Hashtbl.add tbl item ();
              generate_one item
          | None -> generate_one item)
        items;
      Buffer.add_string buf "\n")
end

(* Re-export commonly used functions at top level for backward compatibility *)
(* Type alias — shares the definition with Type_analysis, no conversion needed *)
type property_gvalue_info =
  C_stub_type_analysis.Type_analysis.property_gvalue_info

(* Accumulator for parameter processing - kept at top level for record field access *)
type param_acc = {
  ocaml_idx : int;
  decls : Buffer.t;
  args : string list;
  cleanups : string list;
}

let analyze_property_type ~ctx (gir_type : Types.gir_type) =
  C_stub_type_analysis.Type_analysis.analyze_property_type ~ctx gir_type

let is_copy_method = Filtering.is_copy_method
let is_free_method = Filtering.is_free_method
let is_copy_or_free = Filtering.is_copy_or_free
let fold_mapi = C_stub_type_analysis.Type_analysis.fold_mapi
let list_contains = C_stub_type_analysis.Type_analysis.list_contains
let is_string_type = Filtering.is_string_type
let generate_array_ml_to_c = C_stub_array_conv.Array_conv.generate_array_ml_to_c
let generate_array_c_to_ml = C_stub_array_conv.Array_conv.generate_array_c_to_ml
let is_string_array = Filtering.is_string_array

(* No conversion needed — property_gvalue_info is now a type alias *)
let generate_gvalue_getter_assignment ~ml_name ~prop ~c_type_name ~prop_info =
  C_stub_gvalue.GValue.generate_gvalue_getter_assignment ~ml_name ~prop
    ~c_type_name ~prop_info

(* Generate setter without the unused prop parameter *)
let generate_gvalue_setter_assignment ~ml_name ~prop_info =
  C_stub_gvalue.GValue.generate_gvalue_setter_assignment ~ml_name ~prop:()
    ~prop_info

let generate_c_file_header = Code_gen.generate_c_file_header
let base_c_type_of = Code_gen.base_c_type_of
let build_return_statement = Code_gen.build_return_statement
let generate_constructors = Code_gen.generate_constructors
let generate_methods = Code_gen.generate_methods
let default_type_mapping = Code_gen.default_type_mapping

(* Nullable conversion expressions - these depend on Type_analysis.analyze_property_type *)
let nullable_c_to_ml_expr ~ctx ~var ~(gir_type : gir_type)
    ~(mapping : type_mapping) ?(direction : Types.gir_direction = In) () =
  (* out parameters that are record types are stack allocated, so we need to pass by reference
     to their Val_x function, which will copy them into the OCaml heap.
     Check both the type_mapping flag (works for cross-namespace) and analyze_property_type
     (works for current namespace records with full record info). *)
  let var_expr =
    match direction with
    | (Out | InOut) when mapping.is_value_type_record -> sprintf "&%s" var
    | Out | InOut -> (
        match analyze_property_type ~ctx gir_type with
        | { record_info = Some ({ opaque = false; _ }, _, _); _ } ->
            sprintf "&%s" var
        | _ -> var)
    | In -> var
  in
  if not gir_type.nullable then sprintf "%s(%s)" mapping.c_to_ml var_expr
  else
    match gir_type with
    | { c_type; _ } when is_string_type c_type ->
        sprintf "Val_option_string(%s)" var_expr
    | { c_type = Some c_type; _ }
      when String.length c_type > 0
           && String.equal
                (String.sub c_type ~pos:(String.length c_type - 1) ~len:1)
                "*" ->
        sprintf "Val_option(%s, %s)" var_expr mapping.c_to_ml
    | _ -> sprintf "%s(%s)" mapping.c_to_ml var_expr

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
    | TransferFull when is_string_type gir_type.c_type ->
        (* String with transfer-full: copy to mutable buffer before passing *)
        if not gir_type.nullable then sprintf "String_copy(%s)" var
        else sprintf "String_option_val(String_copy(%s))" var
    | (TransferFull | TransferFloating)
      when match mapping.transfer_strategy with
           | Ts_gobject -> true
           | Ts_none | Ts_boxed _ | Ts_gvariant -> false ->
        (* GObject in-parameter the callee takes ownership of
           (gtk_widget_add_controller is the canonical case). The OCaml
           wrapper's finalizer keeps dropping its own reference, so hand the
           callee a NEW one — passing the wrapper's only ref made widget
           teardown + wrapper GC double-drop it (GTK_IS_EVENT_CONTROLLER
           criticals, segfaults). The nullable
           form re-reads the pure Option_val expression rather than
           introducing a statement expression. *)
        if not gir_type.nullable then
          sprintf "g_object_ref(%s(%s))" mapping.ml_to_c var
        else
          sprintf "(Option_val(%s, %s, NULL) ? g_object_ref(Option_val(%s, %s, NULL)) : NULL)"
            var mapping.ml_to_c var mapping.ml_to_c
    | TransferNone | TransferContainer | TransferFloating | TransferFull -> (
        if
          (* Normal case - no copy needed *)
          not gir_type.nullable
        then sprintf "%s(%s)" mapping.ml_to_c var
        else
          match gir_type with
          | { c_type; _ } when is_string_type c_type ->
              sprintf "String_option_val(%s)" var
          | { c_type = Some c_type; _ }
            when String.length c_type > 0
                 && String.equal
                      (String.sub c_type ~pos:(String.length c_type - 1) ~len:1)
                      "*" ->
              sprintf "Option_val(%s, %s, NULL)" var mapping.ml_to_c
          | _ -> sprintf "%s(%s)" mapping.ml_to_c var)

(* Re-export forward declaration helper *)
let generate_forward_decl_section = Forward_decl.generate_section

(* {1 Version Guard Support} *)

(** Build a CAMLprim failwith stub. [params] and [param_names] must correspond.
    [param_count_for_caml] controls how many names appear in CAMLparam. *)
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
    | n -> List.init ~len:n ~f:(fun i -> sprintf "arg%d" (i + 1))
  in
  let params =
    match param_count with
    | 0 -> [ "value unit" ]
    | n -> List.init ~len:n ~f:(fun i -> sprintf "value arg%d" (i + 1))
  in
  (params, param_names)

(** Build params and param_names for a method with [n] in-parameters plus self.
*)
let make_method_params in_param_count =
  let param_names =
    "self"
    :: List.init ~len:in_param_count ~f:(fun i -> sprintf "arg%d" (i + 1))
  in
  let params =
    "value self"
    :: List.init ~len:in_param_count ~f:(fun i -> sprintf "value arg%d" (i + 1))
  in
  (params, param_names)

(* [generate_multi_param_function ~ml_name ~params ~param_names body_code]
   generates both native and bytecode C wrapper variants for functions with >5 parameters.
   Shared by generate_c_constructor and generate_c_method to eliminate the
   byte-for-byte duplication that previously lived in both modules.
   Takes the function name, C parameter declarations, parameter names, and body code.
   Returns the combined native + bytecode function code as a string. *)
let generate_multi_param_function ~ml_name ~params ~param_names body_code =
  let first_five = List.filteri ~f:(fun i _ -> i < 5) param_names in
  let rest = List.filteri ~f:(fun i _ -> i >= 5) param_names in

  (* Split remaining params into chunks of at most 5 for CAMLxparam *)
  let rec chunk_params params =
    match params with
    | [] -> []
    | _ ->
        let chunk = List.filteri ~f:(fun i _ -> i < 5) params in
        let remaining = List.filteri ~f:(fun i _ -> i >= 5) params in
        chunk :: chunk_params remaining
  in
  let xparam_chunks = chunk_params rest in
  let xparam_lines =
    String.concat ~sep:"\n"
      (List.map
         ~f:(fun chunk ->
           sprintf "CAMLxparam%d(%s);" (List.length chunk)
             (String.concat ~sep:", " chunk))
         xparam_chunks)
  in

  let native_func =
    sprintf
      "\nCAMLexport CAMLprim value %s_native(%s)\n{\nCAMLparam5(%s);\n%s\n%s}\n"
      ml_name
      (String.concat ~sep:", " params)
      (String.concat ~sep:", " first_five)
      xparam_lines body_code
  in

  let bytecode_func =
    sprintf
      "\n\
       CAMLexport CAMLprim value %s_bytecode(value * argv, int argn)\n\
       {\n\
       return %s_native(%s);\n\
       }\n"
      ml_name ml_name
      (String.concat ~sep:", "
         (List.mapi ~f:(fun i _ -> sprintf "argv[%d]" i) param_names))
  in

  native_func ^ bytecode_func

(** Get the display name for a namespace for use in failwith messages *)
let namespace_display_name namespace_name =
  match namespace_name with
  | "Gtk" -> "GTK"
  | "Gdk" -> "GTK"
  | "Gsk" -> "GTK"
  | "Pango" -> "Pango"
  | "PangoCairo" -> "Pango"
  | "GdkPixbuf" -> "GdkPixbuf"
  | "Gio" -> "GLib"
  | "Graphene" -> "Graphene"
  | "Cairo" -> "Cairo"
  | other -> other

(** Format version string for failwith messages: "M.m" (omit micro if 0) *)
let format_version_for_message (version : Version_guard.version) =
  if version.micro = 0 then sprintf "%d.%d" version.major version.minor
  else sprintf "%d.%d.%d" version.major version.minor version.micro

(** Emit a class-level fallback stub for a constructor. The stub accepts the
    same parameters and raises caml_failwith with the appropriate message. *)
let emit_fallback_constructor_stub ~ctx ~c_type:_ ~class_name ~ml_name
    ~c_identifier:_ ~version (ctor : gir_constructor) =
  let param_count = List.length ctor.ctor_parameters in
  let params, param_names = make_constructor_params param_count in
  let param_count_for_caml = if param_count = 0 then 1 else param_count in
  let display_ns = namespace_display_name ctx.namespace.namespace_name in
  let failwith_msg =
    sprintf "%s requires %s >= %s" class_name display_ns
      (format_version_for_message version)
  in
  emit_failwith_stub_core ~ml_name ~params ~param_names ~param_count_for_caml
    ~failwith_msg

(** Emit a class-level fallback stub for a method. *)
let emit_fallback_method_stub ~ctx ~c_type:_ ~class_name ~ml_name
    ~c_identifier:_ ~version (meth : gir_method) =
  let in_params =
    List.filter
      ~f:(fun p -> match p.direction with Out -> false | In | InOut -> true)
      meth.parameters
  in
  let param_count = 1 + List.length in_params in
  let params, param_names = make_method_params (List.length in_params) in
  let param_count_for_caml = if param_count = 0 then 1 else min param_count 5 in
  let display_ns = namespace_display_name ctx.namespace.namespace_name in
  let failwith_msg =
    sprintf "%s requires %s >= %s" class_name display_ns
      (format_version_for_message version)
  in
  emit_failwith_stub_core ~ml_name ~params ~param_names ~param_count_for_caml
    ~failwith_msg

(** Emit a class-level fallback stub for a property getter. *)
let emit_fallback_property_getter_stub ~ctx ~c_type:_ ~class_name ~ml_name
    ~version (_prop : gir_property) =
  let display_ns = namespace_display_name ctx.namespace.namespace_name in
  let failwith_msg =
    sprintf "%s requires %s >= %s" class_name display_ns
      (format_version_for_message version)
  in
  emit_failwith_stub_core ~ml_name ~params:[ "value self" ]
    ~param_names:[ "self" ] ~param_count_for_caml:1 ~failwith_msg

(** Emit a class-level fallback stub for a property setter. *)
let emit_fallback_property_setter_stub ~ctx ~c_type:_ ~class_name ~ml_name
    ~version (_prop : gir_property) =
  let display_ns = namespace_display_name ctx.namespace.namespace_name in
  let failwith_msg =
    sprintf "%s requires %s >= %s" class_name display_ns
      (format_version_for_message version)
  in
  emit_failwith_stub_core ~ml_name
    ~params:[ "value self"; "value arg1" ]
    ~param_names:[ "self"; "arg1" ] ~param_count_for_caml:2 ~failwith_msg

(** Emit a class-level fallback stub for a record method. *)
let emit_fallback_record_method_stub ~ctx ~c_type:_ ~class_name ~ml_name
    ~version (meth : gir_method) =
  let in_params =
    List.filter
      ~f:(fun p -> match p.direction with Out -> false | In | InOut -> true)
      meth.parameters
  in
  let param_count = 1 + List.length in_params in
  let params, param_names = make_method_params (List.length in_params) in
  let param_count_for_caml = if param_count = 0 then 1 else min param_count 5 in
  let display_ns = namespace_display_name ctx.namespace.namespace_name in
  let failwith_msg =
    sprintf "%s requires %s >= %s" class_name display_ns
      (format_version_for_message version)
  in
  emit_failwith_stub_core ~ml_name ~params ~param_names ~param_count_for_caml
    ~failwith_msg

(* {1 OS Guard Support} *)

(** Map a single OS platform name to its C defined() expression. *)
let os_name_to_c_expr = function
  | "linux" -> "defined(__linux__)"
  | "macos" -> "(defined(__APPLE__) && defined(__MACH__))"
  | "freebsd" -> "defined(__FreeBSD__)"
  | "unix" -> "defined(G_OS_UNIX)"
  | "windows" -> "defined(_WIN32)"
  | os -> sprintf "defined(OS_%s)" (String.uppercase_ascii os)

(** Map an [Os_filter.t] to the opening C preprocessor guard line. *)
let os_to_c_guard_open = function
  | Os_filter.Os_only names ->
      let parts = List.map ~f:os_name_to_c_expr names in
      sprintf "#if %s" (String.concat ~sep:" || " parts)
  | Os_filter.Os_except names ->
      let parts =
        List.map ~f:(fun n -> sprintf "!(%s)" (os_name_to_c_expr n)) names
      in
      sprintf "#if %s" (String.concat ~sep:" && " parts)

(** Map an [Os_filter.t] to the closing C preprocessor guard line. *)
let os_to_c_guard_close = function
  | Os_filter.Os_only names ->
      sprintf "#endif /* %s */" (String.concat ~sep:" || " names)
  | Os_filter.Os_except names ->
      sprintf "#endif /* not %s */" (String.concat ~sep:", " names)

(** Human-readable display name for an [Os_filter.t] (used in failwith
    messages). *)
let os_display_name = function
  | Os_filter.Os_only [ "linux" ] -> "Linux"
  | Os_filter.Os_only [ "macos" ] -> "macOS"
  | Os_filter.Os_only [ "freebsd" ] -> "FreeBSD"
  | Os_filter.Os_only [ "unix" ] -> "Unix"
  | Os_filter.Os_only [ "windows" ] -> "Windows"
  | Os_filter.Os_only names -> String.concat ~sep:" or " names
  | Os_filter.Os_except names ->
      sprintf "non-%s" (String.concat ~sep:"/non-" names)

(** Wrap a generated stub in an OS guard. [os]: OS filter, or [None] to emit
    stub as-is. [failwith_stub]: string placed in the [#else] branch. [stub]:
    the actual implementation placed in the [#if] branch. *)
let emit_with_os_guard ~os ~failwith_stub ~stub buf =
  match os with
  | None -> Buffer.add_string buf stub
  | Some os_filter ->
      Buffer.add_char buf '\n';
      Buffer.add_string buf (os_to_c_guard_open os_filter);
      Buffer.add_char buf '\n';
      Buffer.add_string buf stub;
      Buffer.add_char buf '\n';
      Buffer.add_string buf "#else\n";
      Buffer.add_string buf failwith_stub;
      Buffer.add_char buf '\n';
      Buffer.add_string buf (os_to_c_guard_close os_filter);
      Buffer.add_char buf '\n'

(** Emit an OS-fallback constructor stub that raises [caml_failwith]. Used in
    the [#else] branch of an OS guard. *)
let emit_os_fallback_constructor_stub ~ctx:_ ~c_type:_ ~class_name ~ml_name
    ~c_identifier:_ ~os (ctor : gir_constructor) =
  let param_count = List.length ctor.ctor_parameters in
  let params, param_names = make_constructor_params param_count in
  let param_count_for_caml = if param_count = 0 then 1 else param_count in
  let failwith_msg =
    sprintf "%s is only available on %s" class_name (os_display_name os)
  in
  emit_failwith_stub_core ~ml_name ~params ~param_names ~param_count_for_caml
    ~failwith_msg

(** Emit an OS-fallback method stub that raises [caml_failwith]. *)
let emit_os_fallback_method_stub ~ctx:_ ~c_type:_ ~class_name ~ml_name
    ~c_identifier:_ ~os (meth : gir_method) =
  let in_params =
    List.filter
      ~f:(fun p -> match p.direction with Out -> false | In | InOut -> true)
      meth.parameters
  in
  let param_count = 1 + List.length in_params in
  let params, param_names = make_method_params (List.length in_params) in
  let param_count_for_caml = if param_count = 0 then 1 else min param_count 5 in
  let failwith_msg =
    sprintf "%s is only available on %s" class_name (os_display_name os)
  in
  emit_failwith_stub_core ~ml_name ~params ~param_names ~param_count_for_caml
    ~failwith_msg

(** Emit an OS-fallback property getter stub that raises [caml_failwith]. *)
let emit_os_fallback_property_getter_stub ~ctx:_ ~c_type:_ ~class_name ~ml_name
    ~os (_prop : gir_property) =
  let failwith_msg =
    sprintf "%s is only available on %s" class_name (os_display_name os)
  in
  emit_failwith_stub_core ~ml_name ~params:[ "value self" ]
    ~param_names:[ "self" ] ~param_count_for_caml:1 ~failwith_msg

(** Emit an OS-fallback property setter stub that raises [caml_failwith]. *)
let emit_os_fallback_property_setter_stub ~ctx:_ ~c_type:_ ~class_name ~ml_name
    ~os (_prop : gir_property) =
  let failwith_msg =
    sprintf "%s is only available on %s" class_name (os_display_name os)
  in
  emit_failwith_stub_core ~ml_name
    ~params:[ "value self"; "value arg1" ]
    ~param_names:[ "self"; "arg1" ] ~param_count_for_caml:2 ~failwith_msg

(** Wrap a generated stub in a member-level version guard when [resolve_guard]
    returns [Member_guard]. [fallback v] is called with the member version to
    produce the [#else] stub. Falls through to plain emit on parse errors or
    when no guard is needed (e.g. [No_guard] for same-version members). *)
let emit_with_member_guard ~ctx ?(version_namespace : string option = None)
    ~class_version ~member_version ~fallback ~stub buf =
  let guard_ns =
    match version_namespace with
    | Some ns -> ns
    | None -> ctx.namespace.namespace_name
  in
  match Version_guard.resolve_guard ~class_version ~member_version with
  | Ok (Version_guard.Member_guard v) -> (
      match Version_guard.emit_c_guard guard_ns v ~is_opening:true with
      | Ok guard_if -> (
          Buffer.add_char buf '\n';
          Buffer.add_string buf guard_if;
          Buffer.add_char buf '\n';
          Buffer.add_string buf stub;
          Buffer.add_char buf '\n';
          Buffer.add_string buf Version_guard.c_guard_else;
          Buffer.add_char buf '\n';
          Buffer.add_string buf (fallback v);
          match Version_guard.emit_c_guard guard_ns v ~is_opening:false with
          | Ok guard_endif -> Buffer.add_string buf (guard_endif ^ "\n")
          | Error _ -> Buffer.add_string buf "#endif\n")
      | Error _ -> Buffer.add_string buf stub)
  | _ -> Buffer.add_string buf stub
