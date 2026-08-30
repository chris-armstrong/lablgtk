(* Copyright (C) 2025 - ocgtk contributors *)

open Types
open Utils
open StdLabels
open Gen_buffer

(* Generate a top-level library module that exposes:
   1. Direct references to each class (including mutually recursive classes)
   2. A Wrappers submodule with module aliases for layer 1 modules
   3. Direct references to each enumeration at the same level as classes

   This makes it easier to find each class and enumeration by putting them
   at the top-level instead of in their respective modules, while still
   taking advantage of module aliasing to prevent needing to reference
   everything in the library at compile time.
*)

let get_layer1_module_reference ~ctx class_name =
  (* Get the qualified module path for a class *)
  match Hashtbl.find_opt ctx.module_groups class_name with
  | Some combined_module_name
    when combined_module_name <> module_name_of_class class_name ->
      (* This is part of a cyclic module *)
      Fmt.str "%s.%s" combined_module_name (module_name_of_class class_name)
  | _ ->
      (* This is a standalone module *)
      module_name_of_class class_name

let get_layer2_class_module_reference ~ctx class_name =
  (* Get the qualified module path for a class *)
  match Hashtbl.find_opt ctx.module_groups class_name with
  | Some combined_module_name
    when combined_module_name <> module_name_of_class class_name ->
      (* This is part of a cyclic module *)
      combined_module_name
  | _ ->
      (* This is a standalone module *)
      module_name_of_class class_name

let generate_library_interface ~ctx =
  (* Generate the .mli signature file *)
  let buf = Buffer.create 4096 in

  Buffer.add_string buf "(* GENERATED CODE - DO NOT EDIT *)\n";
  Buffer.add_string buf
    "(* Top-level library module with direct references to all classes and \
     enumerations *)\n\n";

  (* Collect all class/interface/record names *)
  let all_entities =
    List.filter_map ctx.classes ~f:(fun (c : gir_class) ->
        match Filtering.should_generate_class c with
        | true -> Some c.class_name
        | false -> None)
    @ List.map ctx.interfaces ~f:(fun (i : gir_interface) -> i.interface_name)
    @ List.map ctx.records ~f:(fun (r : gir_record) -> r.record_name)
  in
  let sorted_entities = List.sort all_entities ~cmp:String.compare in

  (* Generate Wrappers submodule BEFORE module aliases to avoid shadowing *)
  if not (List.is_empty sorted_entities) then begin
    Buffer.add_string buf "(** {1 Layer 1 Module Wrappers}\n";
    Buffer.add_string buf "    \n";
    Buffer.add_string buf
      "    This submodule provides aliases to the layer 1 (low-level) modules.\n";
    Buffer.add_string buf
      "    These are the modules containing external declarations and basic \
       bindings.\n";
    Buffer.add_string buf " *)\n";
    Buffer.add_string buf "module Wrappers : sig\n";
    List.iter sorted_entities ~f:(fun name ->
        let module_ref = get_layer1_module_reference ~ctx name in
        bprintf buf "  module %s = %s\n" (module_name_of_class name) module_ref);
    Buffer.add_string buf "end\n\n"
  end;

  (* Generate module aliases for classes and interfaces *)
  if not (List.is_empty sorted_entities) then begin
    Buffer.add_string buf "(** {1 Classes and Interfaces} *)\n\n";
    List.iter sorted_entities ~f:(fun name ->
        let module_name = module_name_of_class name in
        let g_module_name = Utils.layer2_module_name name in
        bprintf buf "module %s = %s\n" module_name g_module_name);
    Buffer.add_string buf "\n"
  end;

  (* Generate enumeration and bitfield references *)
  let has_enums = not (List.is_empty ctx.enums) in
  let has_bitfields = not (List.is_empty ctx.bitfields) in
  let has_constants = not (List.is_empty ctx.constants) in

  if has_enums || has_bitfields then begin
    Buffer.add_string buf "(** {1 Enumerations and Bitfields} *)\n\n";

    if has_enums then begin
      let sorted_enums =
        ctx.enums
        |> List.sort ~cmp:(fun (a : gir_enum) (b : gir_enum) ->
            String.compare a.enum_name b.enum_name)
      in
      List.iter sorted_enums ~f:(fun (enum : gir_enum) ->
          let enum_module = enums_module_name ctx enum in
          let enum_name = ocaml_enum_name enum in
          bprintf buf "type %s = %s.%s\n" enum_name enum_module enum_name)
    end;

    if has_bitfields then begin
      let sorted_bitfields =
        ctx.bitfields
        |> List.sort ~cmp:(fun (a : gir_bitfield) (b : gir_bitfield) ->
            String.compare a.bitfield_name b.bitfield_name)
      in
      List.iter sorted_bitfields ~f:(fun (bitfield : gir_bitfield) ->
          let bitfield_module = bitfields_module_name ctx bitfield in
          let bitfield_name = ocaml_bitfield_name bitfield in
          bprintf buf "type %s = %s.%s\n" bitfield_name bitfield_module
            bitfield_name)
    end
  end;

  (* Generate constants module reference *)
  if has_constants then begin
    Buffer.add_string buf "\n(** {1 Constants} *)\n\n";
    let constants_module =
      internal_namespace_to_module_name ctx.namespace.namespace_name
      ^ "_constants"
    in
    bprintf buf "module %s = %s\n" constants_module constants_module
  end;

  Buffer.contents buf

let generate_library_implementation ~ctx =
  (* Generate the .ml implementation file *)
  let buf = Buffer.create 4096 in

  Buffer.add_string buf "(* GENERATED CODE - DO NOT EDIT *)\n";
  Buffer.add_string buf
    "(* Top-level library module with direct references to all classes and \
     enumerations *)\n\n";

  (* Collect all class/interface names *)
  let all_entities =
    List.map ctx.classes ~f:(fun (c : gir_class) -> c.class_name)
    @ List.map ctx.interfaces ~f:(fun (i : gir_interface) -> i.interface_name)
    @ List.map ctx.records ~f:(fun (r : gir_record) -> r.record_name)
  in
  let sorted_entities = List.sort all_entities ~cmp:String.compare in

  (* Generate Wrappers submodule BEFORE module aliases to avoid shadowing *)
  if not (List.is_empty sorted_entities) then begin
    Buffer.add_string buf "(** Layer 1 Module Wrappers *)\n";
    Buffer.add_string buf "module Wrappers = struct\n";
    List.iter sorted_entities ~f:(fun name ->
        let module_ref = get_layer1_module_reference ~ctx name in
        bprintf buf "  module %s = %s\n" (module_name_of_class name) module_ref);
    Buffer.add_string buf "end\n\n"
  end;

  (* Generate module aliases for classes and interfaces *)
  if not (List.is_empty sorted_entities) then begin
    Buffer.add_string buf "(** Classes and Interfaces *)\n\n";
    List.iter sorted_entities ~f:(fun name ->
        let module_name = module_name_of_class name in
        let g_module_name = Utils.layer2_module_name name in
        bprintf buf "module %s = %s\n" module_name g_module_name);
    Buffer.add_string buf "\n"
  end;

  (* Generate enumeration and bitfield references *)
  let has_enums = not (List.is_empty ctx.enums) in
  let has_bitfields = not (List.is_empty ctx.bitfields) in
  let has_constants = not (List.is_empty ctx.constants) in

  if has_enums || has_bitfields then begin
    Buffer.add_string buf "(** Enumerations and Bitfields *)\n\n";

    if has_enums then begin
      let sorted_enums =
        List.sort ctx.enums ~cmp:(fun (a : gir_enum) (b : gir_enum) ->
            String.compare a.enum_name b.enum_name)
      in
      List.iter sorted_enums ~f:(fun (enum : gir_enum) ->
          let enum_module = enums_module_name ctx enum in
          let enum_name = ocaml_enum_name enum in
          bprintf buf "type %s = %s.%s\n" enum_name enum_module enum_name)
    end;

    if has_bitfields then begin
      let sorted_bitfields =
        List.sort ctx.bitfields
          ~cmp:(fun (a : gir_bitfield) (b : gir_bitfield) ->
            String.compare a.bitfield_name b.bitfield_name)
      in
      List.iter sorted_bitfields ~f:(fun (bitfield : gir_bitfield) ->
          let bitfield_module = bitfields_module_name ctx bitfield in
          let bitfield_name = ocaml_bitfield_name bitfield in
          bprintf buf "type %s = %s.%s\n" bitfield_name bitfield_module
            bitfield_name)
    end
  end;

  (* Generate constants module reference *)
  if has_constants then begin
    Buffer.add_string buf "\n(** Constants *)\n\n";
    let constants_module =
      internal_namespace_to_module_name ctx.namespace.namespace_name
      ^ "_constants"
    in
    bprintf buf "module %s = %s\n" constants_module constants_module
  end;

  Buffer.contents buf

let generate_library_module ~ctx =
  (* Generate both .ml and .mli files *)
  let mli_content = generate_library_interface ~ctx in
  let ml_content = generate_library_implementation ~ctx in
  (ml_content, mli_content)
