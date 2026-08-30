(* C Stub Code Generation - Main orchestration module *)

open Gen_buffer
open StdLabels
open Types

(* Re-export helpers *)
include C_stub_helpers

(* Re-export property generation functions directly from property module *)
let generate_c_property_getter = C_stub_property.generate_c_property_getter
let generate_c_property_setter = C_stub_property.generate_c_property_setter

(* Re-export record generation functions *)
let has_copy_method = C_stub_record.has_copy_method
let is_value_like_record = C_stub_record.is_value_like_record
let generate_record_c_code = C_stub_record.generate_record_c_code

(* Base namespaces that should not be included as dependencies *)
let base_namespaces = [ "GLib"; "GModule"; "GObject"; "HarfBuzz" ]

(* Extract dependency namespaces from cross_references map.
   Returns sorted list of namespace names (excluding base namespaces like GLib, GObject, GModule) *)
let get_dependency_namespaces cross_references =
  StringMap.fold (fun ns _ acc -> ns :: acc) cross_references []
  |> List.filter ~f:(fun ns -> not (List.mem ~set:base_namespaces ns))
  |> List.sort_uniq ~cmp:String.compare

(* Generate #include directives for dependency namespaces.
   Headers are included as "generated/<ns>_decls.h" because OCaml automatically
   passes -I path/to/<library> when you depend on a library, so the full path
   resolves to path/to/<library>/generated/<ns>_decls.h *)
let generate_dependency_includes dependency_namespaces =
  match dependency_namespaces with
  | [] -> ""
  | deps ->
      deps
      |> List.map ~f:(fun ns ->
          let ns_lower = String.lowercase_ascii ns in
          Fmt.str "#include \"generated/%s_decls.h\"" ns_lower)
      |> String.concat ~sep:"\n"
      |> fun s -> s ^ "\n"

(* Generate common header file with forward declarations for enum/bitfield converters *)
let generate_decls_header ~ctx ~classes ~interfaces ~gtk_enums ~gtk_bitfields
    ~records ?(header_overrides = []) () =
  let buf = Buffer.create 4096 in
  let ns_lower = String.lowercase_ascii ctx.namespace.namespace_name in
  Buffer.add_string buf "/* GENERATED CODE - DO NOT EDIT */\n";
  Buffer.add_string buf
    "/* Forward declarations for generated enum, bitfield, class and record \
     converters */\n";
  Buffer.add_string buf "\n";
  bprintf buf "#ifndef _%s_decls_h_\n" ns_lower;
  bprintf buf "#define _%s_decls_h_\n" ns_lower;
  Buffer.add_string buf "\n";
  (* Include C headers from the repository (parsed from GIR).
     Headers with an (os ...) override in the library's override file are
     wrapped in the appropriate #ifdef guard (e.g. #ifdef __linux__). *)
  let find_header_os path =
    List.find_map
      ~f:(fun { Override_types.header_path = hp; header_os } ->
        if String.equal hp path then header_os else None)
      header_overrides
  in
  (* Group headers by their OS guard (None = unconditional) *)
  let unconditional, conditional =
    List.partition
      ~f:(fun h -> find_header_os h = None)
      ctx.repository.repository_c_includes
  in
  List.iter
    ~f:(fun c_include ->
      Buffer.add_string buf (Fmt.str "#include <%s>\n" c_include))
    unconditional;
  (* Emit conditional headers grouped by OS guard *)
  let os_groups =
    List.filter_map
      ~f:(fun h ->
        match find_header_os h with Some os -> Some (os, h) | None -> None)
      conditional
  in
  (* Collect unique OS filter values in order *)
  let seen_os = Hashtbl.create 4 in
  let ordered_os =
    List.filter_map
      ~f:(fun (os, _) ->
        if Hashtbl.mem seen_os os then None
        else begin
          Hashtbl.add seen_os os ();
          Some os
        end)
      os_groups
  in
  List.iter
    ~f:(fun os ->
      let headers_for_os =
        List.filter_map
          ~f:(fun (g_os, h) -> if Os_filter.equal g_os os then Some h else None)
          os_groups
      in
      Buffer.add_string buf (C_stub_helpers.os_to_c_guard_open os ^ "\n");
      List.iter
        ~f:(fun c_include ->
          Buffer.add_string buf (Fmt.str "#include <%s>\n" c_include))
        headers_for_os;
      Buffer.add_string buf (C_stub_helpers.os_to_c_guard_close os ^ "\n"))
    ordered_os;
  Buffer.add_string buf "#include <caml/mlvalues.h>\n";
  Buffer.add_string buf "\n";

  (* Generate dependency header includes *)
  let dependency_namespaces = get_dependency_namespaces ctx.cross_references in
  let dependency_includes =
    generate_dependency_includes dependency_namespaces
  in
  if not (CCString.is_empty dependency_includes) then begin
    Buffer.add_string buf "/* Dependency headers for cross-namespace types */\n";
    Buffer.add_string buf dependency_includes;
    Buffer.add_string buf "\n"
  end;

  let namespace_prefix = ctx.namespace.namespace_name in

  (* Generate class/interface forward declarations *)
  Buffer.add_string buf
    (C_stub_class.generate_forward_decls ~namespace_prefix ~classes ~interfaces);

  (* Generate record forward declarations *)
  Buffer.add_string buf
    (C_stub_record.generate_forward_decls ~namespace_prefix ~records);

  Buffer.add_string buf "/* Const-safe string extraction for setters */\n";
  Buffer.add_string buf
    "#define ML_DECL_CONST_STRING(name, expr) const gchar *name = (const gchar \
     *)(expr)\n";
  Buffer.add_string buf "\n";
  Buffer.add_string buf
    "/* Note: Res_Ok, Res_Error, ValUnit, and Val_GError are defined in \
     wrappers.h */\n";
  Buffer.add_string buf "\n";

  (* Generate enum forward declarations *)
  if List.length gtk_enums > 0 then begin
    Buffer.add_string buf
      (C_stub_enum.generate_forward_decls ~namespace_prefix ~gtk_enums)
  end;

  (* Generate bitfield forward declarations *)
  if List.length gtk_bitfields > 0 then begin
    Buffer.add_string buf
      (C_stub_bitfield.generate_forward_decls ~namespace_prefix ~gtk_bitfields)
  end;

  Buffer.add_string buf "\n";
  (* Include manually-maintained core header for namespace-specific additions
     (e.g. UNIX headers not present in older GIR versions) *)
  bprintf buf "#include \"../core/%s_core.h\"\n" ns_lower;
  Buffer.add_string buf "\n";
  bprintf buf "#endif /* _%s_decls_h_ */\n" ns_lower;
  Buffer.contents buf
