(* GValue Handling *)

open Containers
open StdLabels
open Types

(** GValue handling *)
module GValue = struct
  (** Classification of GValue types into categories for dispatch *)
  type gvalue_type_category =
    | Enum  (** GEnum types *)
    | Bitfield  (** GFlags/bitfield types *)
    | Boolean  (** gboolean *)
    | Integer of {
        c_type_name : string;
        getter : string;  (** g_value_get_* function name *)
      }  (** Integer types (int, uint, long, etc.) *)
    | Float of string  (** Float/double types with getter name *)
    | String  (** String types *)
    | Boxed of {
        c_type : string;
        is_pointer : bool;  (** true if passed by pointer *)
      }  (** Boxed types (records/structs) *)
    | Object of string  (** Object types with C type name *)
    | GVariant  (** GLib.Variant — uses g_value_get/set_variant *)
    | Pointer  (** Generic pointer types *)
    | Unsupported of string  (** Fallback for unsupported types *)

  (** Classify a property_gvalue_info into a gvalue_type_category *)
  let classify_gvalue_type ~c_type_name
      (prop_info : C_stub_type_analysis.Type_analysis.property_gvalue_info) =
    let open C_stub_type_analysis.Type_analysis in
    let base_lower = prop_info.base_lower in
    if prop_info.is_enum then Enum
    else if prop_info.is_bitfield then Bitfield
    else if String.equal base_lower "gboolean" then Boolean
    else if list_contains ~value:base_lower int32_types then
      Integer { c_type_name; getter = "get_int" }
    else if list_contains ~value:base_lower uint32_types then
      Integer { c_type_name; getter = "get_uint" }
    else if list_contains ~value:base_lower int64_types then
      Integer { c_type_name; getter = "get_int64" }
    else if list_contains ~value:base_lower uint64_types then
      Integer { c_type_name; getter = "get_uint64" }
    else if list_contains ~value:base_lower long_types then
      Integer { c_type_name; getter = "get_long" }
    else if list_contains ~value:base_lower ulong_types then
      Integer { c_type_name; getter = "get_ulong" }
    else if list_contains ~value:base_lower ssize_types then
      Integer { c_type_name; getter = "get_ssize" }
    else if list_contains ~value:base_lower size_types then
      Integer { c_type_name; getter = "get_size" }
    else if list_contains ~value:base_lower double_types then Float "get_double"
    else if list_contains ~value:base_lower float_types then Float "get_float"
    else if
      prop_info.has_pointer && list_contains ~value:base_lower string_base_types
    then String
    else if
      String.equal c_type_name "GVariant"
      || String.equal c_type_name "GVariant*"
    then GVariant
    else
      match prop_info.record_info with
      | Some (record, is_pointer, _) ->
          Boxed { c_type = record.c_type; is_pointer }
      | None ->
          if Option.is_some prop_info.class_info then Object c_type_name
          else if prop_info.pointer_like then Pointer
          else Unsupported base_lower

  (** Dispatch function that takes generator functions for getter/setter
      generation. Eliminates duplication between generate_getter_for_category
      and generate_setter_for_category. *)
  let gvalue_type_dispatch ~c_type_name ~(gen_enum : unit -> string)
      ~gen_bitfield ~gen_boolean ~gen_integer ~gen_float ~gen_string ~gen_boxed
      ~gen_boxed_no_ptr ~gen_object ~gen_gvariant ~gen_pointer category =
    match category with
    | Enum -> gen_enum ()
    | Bitfield -> gen_bitfield ()
    | Boolean -> gen_boolean ()
    | Integer { getter; _ } -> gen_integer getter
    | Float getter -> gen_float getter
    | String -> gen_string ()
    | Boxed { c_type; is_pointer } ->
        if is_pointer then gen_boxed c_type else gen_boxed_no_ptr c_type
    | Object c_type -> gen_object c_type
    | GVariant -> gen_gvariant ()
    | Pointer -> gen_pointer c_type_name
    | Unsupported _ ->
        Fmt.str "    caml_failwith(\"unsupported property type\");\n"

  (** Generate getter code based on type category *)
  let generate_getter_for_category ~ml_name:_ ~prop:_ ~c_type_name category =
    gvalue_type_dispatch ~c_type_name
      ~gen_enum:(fun () ->
        Fmt.str "    prop_value = (%s)g_value_get_enum(&prop_gvalue);\n"
          c_type_name)
      ~gen_bitfield:(fun () ->
        Fmt.str "    prop_value = (%s)g_value_get_flags(&prop_gvalue);\n"
          c_type_name)
      ~gen_boolean:(fun () ->
        "    prop_value = g_value_get_boolean(&prop_gvalue);\n")
      ~gen_integer:(fun getter ->
        Fmt.str "    prop_value = g_value_%s(&prop_gvalue);\n" getter)
      ~gen_float:(fun getter ->
        Fmt.str "    prop_value = g_value_%s(&prop_gvalue);\n" getter)
      ~gen_string:(fun () ->
        "    prop_value = g_value_get_string(&prop_gvalue);\n")
      ~gen_boxed:(fun c_type ->
        Fmt.str "    prop_value = (%s*)g_value_get_boxed(&prop_gvalue);\n"
          c_type)
      ~gen_boxed_no_ptr:(fun c_type ->
        Fmt.str "    prop_value = (%s*)g_value_get_boxed(&prop_gvalue);\n"
          c_type)
      ~gen_object:(fun c_type ->
        Fmt.str "    prop_value = (%s*)g_value_get_object(&prop_gvalue);\n"
          c_type)
        (* g_value_get_variant is transfer-none; g_variant_ref gives Val_GVariant an owned ref *)
      ~gen_gvariant:(fun () ->
        "    prop_value = g_variant_ref(g_value_get_variant(&prop_gvalue));\n")
      ~gen_pointer:(fun ct ->
        Fmt.str "    prop_value = (%s)g_value_get_pointer(&prop_gvalue);\n" ct)
      category

  (** Convert getter name to setter name (e.g., "get_int" -> "set_int") *)
  let getter_to_setter getter = CCString.replace ~sub:"get_" ~by:"set_" getter

  (** Generate setter code based on type category *)
  let generate_setter_for_category ~ml_name:_ ~c_type_name category =
    gvalue_type_dispatch ~c_type_name
      ~gen_enum:(fun () -> "    g_value_set_enum(&prop_gvalue, c_value);\n")
      ~gen_bitfield:(fun () ->
        "    g_value_set_flags(&prop_gvalue, c_value);\n")
      ~gen_boolean:(fun () ->
        "    g_value_set_boolean(&prop_gvalue, c_value);\n")
      ~gen_integer:(fun getter ->
        Fmt.str "    g_value_%s(&prop_gvalue, c_value);\n"
          (getter_to_setter getter))
      ~gen_float:(fun getter ->
        Fmt.str "    g_value_%s(&prop_gvalue, c_value);\n"
          (getter_to_setter getter))
      ~gen_string:(fun () -> "    g_value_set_string(&prop_gvalue, c_value);\n")
      ~gen_boxed:(fun _ -> "    g_value_set_boxed(&prop_gvalue, c_value);\n")
      ~gen_boxed_no_ptr:(fun _ ->
        "    g_value_set_boxed(&prop_gvalue, &c_value);\n")
      ~gen_object:(fun _ -> "    g_value_set_object(&prop_gvalue, c_value);\n")
      ~gen_gvariant:(fun () ->
        "    g_value_set_variant(&prop_gvalue, c_value);\n")
      ~gen_pointer:(fun _ ->
        "    g_value_set_pointer(&prop_gvalue, c_value);\n")
      category

  let generate_gvalue_getter_assignment ~ml_name ~prop ~c_type_name ~prop_info =
    let category = classify_gvalue_type ~c_type_name prop_info in
    generate_getter_for_category ~ml_name ~prop ~c_type_name category

  let generate_gvalue_setter_assignment ~ml_name ~prop:_
      ~(prop_info : C_stub_type_analysis.Type_analysis.property_gvalue_info) =
    let category =
      classify_gvalue_type ~c_type_name:prop_info.base_type prop_info
    in
    generate_setter_for_category ~ml_name ~c_type_name:prop_info.base_type
      category
end
