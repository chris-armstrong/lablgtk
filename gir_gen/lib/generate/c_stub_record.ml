(* C Stub Code Generation - Record Support *)

open Gen_buffer
open Containers
open StdLabels
open Types

(* Check if a record has a copy method, indicating it's a value-like record
    that should be stack-allocated in C but heap-allocated in OCaml *)
let has_copy_method (record : gir_record) =
  List.exists record.methods ~f:C_stub_helpers.is_copy_method

let is_non_opaque_record (record : gir_record) =
  (not record.opaque) && not record.disguised

let is_value_like_record (record : gir_record) =
  is_non_opaque_record record && has_copy_method record

(* Build the C call expression that wraps an owned pointer in an OCaml
   custom block. Records that expose glib:get-type are registered with
   the GType system (typically as boxed types) and need GType-aware
   finalization so g_boxed_free runs the per-type destructor. Records
   without glib:get-type fall through to the legacy entry point, whose
   finalizer uses g_free. *)
let val_ptr_call_for_record (record : gir_record) ~ptr_expr =
  match record.glib_get_type with
  | Some get_type_func when not record.disguised ->
      Fmt.str "ml_gir_record_val_ptr_with_type(%s(), %s)" get_type_func ptr_expr
  | _ -> Fmt.str "ml_gir_record_val_ptr(%s)" ptr_expr

(** Generate forward declarations for record converters.

    This function generates declarations only for records in the current
    namespace. External record declarations come from included headers via the
    library-specific <ns>_decls.h files as part of cross-namespace header
    refactoring. *)

let emit_version_guard_open buf ~namespace version_str =
  let ( let* ) = Result.bind in
  match
    let* version = Version_guard.parse_version version_str in
    Version_guard.emit_c_guard namespace version ~is_opening:true
  with
  | Error msg -> failwith msg
  | Ok guard -> Buffer.add_string buf (guard ^ "\n")

let generate_forward_decls ~namespace_prefix ~records =
  let buf = Buffer.create 2048 in
  let seen = Hashtbl.create 97 in

  (* Generate macros for value-like records that have copy methods *)
  let value_like_records, non_value_like_records =
    List.partition ~f:is_value_like_record records
  in
  if List.length value_like_records > 0 then begin
    Buffer.add_string buf "/* Value-returning structs copied into OCaml */\n";

    (* First, add forward declarations for the copy functions *)
    List.iter
      ~f:(fun (record : gir_record) ->
        if not (Hashtbl.mem seen record.c_type) then begin
          Option.iter
            (emit_version_guard_open buf ~namespace:namespace_prefix)
            record.version;
          bprintf buf "value copy_%s(const %s *ptr);\n" record.c_type
            record.c_type;
          Option.iter (fun _ -> Buffer.add_string buf "#endif\n") record.version
        end)
      value_like_records;
    Buffer.add_string buf "\n";

    (* Then add the macros that use those functions *)
    List.iter
      ~f:(fun (record : gir_record) ->
        if not (Hashtbl.mem seen record.c_type) then begin
          Hashtbl.add seen record.c_type ();
          (* Find the copy method - use is_copy_method for consistent detection *)
          let copy_func =
            List.find_opt record.methods ~f:C_stub_helpers.is_copy_method
          in
          match copy_func with
          | Some _ ->
              Option.iter
                (emit_version_guard_open buf ~namespace:namespace_prefix)
                record.version;
              bprintf buf "#ifndef Val_%s\n" record.c_type;
              bprintf buf
                "#define %s_val(val) ((%s*)ml_gir_record_ptr_val((val), %S))\n"
                record.c_type record.c_type record.c_type;
              bprintf buf "#define Val_%s(obj) copy_%s((obj))\n" record.c_type
                record.c_type;
              bprintf buf
                "#define Val_%s_option(ptr) ((ptr) ? Val_some(copy_%s(ptr)) : \
                 Val_none)\n"
                record.c_type record.c_type;
              bprintf buf "#endif /* Val_%s */\n\n" record.c_type;
              Option.iter
                (fun _ -> Buffer.add_string buf "#endif\n")
                record.version
          | None -> ()
        end)
      value_like_records;
    Buffer.add_string buf "\n"
  end;

  (* Add forward declarations for non-value-like records *)
  Buffer.add_string buf
    "/* Forward declarations for record converters (non-opaque records) */\n";
  List.iter
    ~f:(fun (record : gir_record) ->
      Option.iter
        (fun os -> bprintf buf "%s\n" (C_stub_os_guard.os_to_c_guard_open os))
        record.os;
      Option.iter
        (emit_version_guard_open buf ~namespace:namespace_prefix)
        record.version;
      bprintf buf "/* Forward declarations for %s converters */\n" record.c_type;
      bprintf buf "%s *%s_val(value val);\n" record.c_type record.c_type;
      bprintf buf "value Val_%s(const %s *ptr);\n" record.c_type record.c_type;
      bprintf buf "value Val_%s_option(const %s *ptr);\n" record.c_type
        record.c_type;
      Option.iter (fun _ -> Buffer.add_string buf "#endif\n") record.version;
      Option.iter
        (fun os -> bprintf buf "%s\n" (C_stub_os_guard.os_to_c_guard_close os))
        record.os;
      bprintf buf "\n")
    non_value_like_records;

  Buffer.contents buf

let generate_opaque_record_conversions ~namespace_prefix ~buf
    (record : gir_record) =
  (* Generate public conversion functions for opaque records *)
  Option.iter
    (fun os ->
      Buffer.add_string buf (C_stub_os_guard.os_to_c_guard_open os ^ "\n"))
    record.os;
  Option.iter
    (emit_version_guard_open buf ~namespace:namespace_prefix)
    record.version;
  bprintf buf
    "/* Conversion functions for %s (opaque record with hidden fields) */\n"
    record.c_type;

  (* X_val function — must route through ml_gir_record_ptr_val so it reads
     the wrapped pointer from the gir_record_box (GType + void* pointer)
     custom-block payload instead of dereferencing the GType slot. *)
  bprintf buf "%s *%s_val(value v) {\n" record.c_type record.c_type;
  bprintf buf "  return (%s *)ml_gir_record_ptr_val(v, \"%s\");\n" record.c_type
    record.c_type;
  bprintf buf "}\n\n";

  (* Val_X function *)
  bprintf buf "value Val_%s(const %s *ptr) {\n" record.c_type record.c_type;
  bprintf buf "  if (ptr == NULL) return Val_none;\n";
  bprintf buf "  return %s;\n" (val_ptr_call_for_record record ~ptr_expr:"ptr");
  bprintf buf "}\n\n";

  (* Val_X_option function *)
  bprintf buf "value Val_%s_option(const %s *ptr) {\n" record.c_type
    record.c_type;
  bprintf buf "  if (ptr == NULL) return Val_none;\n";
  bprintf buf "  return Val_some(Val_%s(ptr));\n" record.c_type;
  bprintf buf "}\n";
  Option.iter (fun _ -> Buffer.add_string buf "#endif\n") record.version;
  Option.iter
    (fun os ->
      Buffer.add_string buf (C_stub_os_guard.os_to_c_guard_close os ^ "\n"))
    record.os;
  bprintf buf "\n"

let generate_value_record_conversions ~namespace_prefix ~buf
    (record : gir_record) =
  (* Generate copy function for value-like records *)
  Option.iter
    (fun os ->
      Buffer.add_string buf (C_stub_os_guard.os_to_c_guard_open os ^ "\n"))
    record.os;
  Option.iter
    (emit_version_guard_open buf ~namespace:namespace_prefix)
    record.version;
  bprintf buf
    "/* Copy function for %s (value-like record with copy method) */\n"
    record.c_type;

  (* Find the copy function from the methods *)
  let copy_method =
    List.find_opt record.methods ~f:(fun (meth : gir_method) ->
        let lower_name = String.lowercase_ascii meth.method_name in
        String.equal lower_name "copy")
  in

  bprintf buf "value copy_%s(const %s *ptr)\n" record.c_type record.c_type;
  bprintf buf "{\n";
  bprintf buf "  if (ptr == NULL) return Val_none;\n";
  (match record.glib_get_type with
  | Some get_type_func ->
      (* Registered boxed type: delegate copy semantics to the GType system.
         g_boxed_copy handles ref-counting, deep copy, or whatever the type
         requires — no need to locate a type-specific _copy function. *)
      bprintf buf "  %s *copy = g_boxed_copy(%s(), ptr);\n" record.c_type
        get_type_func
  | None ->
      (* No GType registration: fall back to a plain memcpy. *)
      ignore copy_method;
      bprintf buf "  %s *copy = g_malloc(sizeof(%s));\n" record.c_type
        record.c_type;
      bprintf buf "  memcpy(copy, ptr, sizeof(%s));\n" record.c_type);
  bprintf buf "  return %s;\n" (val_ptr_call_for_record record ~ptr_expr:"copy");
  bprintf buf "}\n";
  Option.iter (fun _ -> Buffer.add_string buf "#endif\n") record.version;
  Option.iter
    (fun os ->
      Buffer.add_string buf (C_stub_os_guard.os_to_c_guard_close os ^ "\n"))
    record.os;
  bprintf buf "\n"

let generate_record_converters ~namespace_prefix ~buf (record : gir_record) =
  (* Generate conversion functions for non-opaque records *)
  let is_value_record = is_value_like_record record in

  if not is_value_record then
    generate_opaque_record_conversions ~namespace_prefix ~buf record
  else generate_value_record_conversions ~namespace_prefix ~buf record

let generate_record_c_code ~ctx (record : gir_record) =
  let buf = Buffer.create 2048 in

  Buffer.add_string buf
    (C_stub_helpers.generate_c_file_header ~ctx ~class_name:record.record_name
       ());

  let namespace_prefix = ctx.namespace.namespace_name in
  let class_snake = Utils.to_snake_case record.record_name in

  (* Generate conversion functions for non-opaque records *)
  generate_record_converters ~namespace_prefix ~buf record;

  C_stub_helpers.generate_constructors ~ctx ~c_type:record.c_type
    ~class_name:record.record_name ~buf
    ~generator:C_stub_constructor.generate_c_constructor record.constructors;

  let namespace_snake = Utils.to_snake_case ctx.namespace.namespace_name in

  (* Synthetic allocator for non-opaque records without constructors *)
  if is_non_opaque_record record && List.length record.constructors = 0 then begin
    let ml_name = Fmt.str "ml_%s_%s_new" namespace_snake class_snake in
    bprintf buf "\n/* Synthetic allocator for non-opaque record %s */\n"
      record.record_name;
    bprintf buf "CAMLexport CAMLprim value %s(value unit)\n{\n" ml_name;
    bprintf buf "    CAMLparam1(unit);\n";
    bprintf buf "    %s *obj = g_new0(%s, 1);\n" record.c_type record.c_type;
    bprintf buf
      "    if (obj == NULL) caml_failwith(\"%s allocation failed\");\n"
      record.c_type;
    bprintf buf "    CAMLreturn(Val_%s(obj));\n" record.c_type;
    bprintf buf "}\n"
  end;

  (* Generate methods with version guard wrapping *)
  let generate_record_method_with_guards ~ctx ~c_type meth class_name =
    let base_stub =
      C_stub_method.generate_c_method ~ctx ~c_type meth class_name
    in
    (* For records, apply version guards using the same logic as for class methods *)
    base_stub
  in

  C_stub_helpers.generate_methods ~ctx ~c_type:record.c_type
    ~class_name:record.record_name ~buf
    ~generator:generate_record_method_with_guards ~entity_kind:Filtering.Record
    record.methods;

  (* Emit a get_type wrapper for records registered with the GType system.
     This lets OCaml code pass the GType to APIs like GtkDropTarget.new_. *)
  (match record.glib_get_type with
  | Some get_type_func ->
      let ml_name = Fmt.str "ml_%s_%s_get_type" namespace_snake class_snake in
      bprintf buf "\nCAMLprim value %s(value unit)\n{\n" ml_name;
      bprintf buf "  CAMLparam1(unit);\n";
      bprintf buf "  CAMLreturn(Val_long(%s()));\n" get_type_func;
      bprintf buf "}\n"
  | None -> ());

  Buffer.contents buf
