(* C Stub Code Generation - Property Support *)

open Containers
open StdLabels
open Types

module Log =
  (val Logs.src_log
         (Logs.Src.create "gir_gen.c_stub_property"
            ~doc:"C stub code generation for property support"))

(* Template record for property wrapper sections *)
type property_wrapper_template = {
  header : string;
  locals : string;
  obj_decl : string;
  pspec_find : string;
  pspec_check : string;
  gvalue_init : string;
  operation : string;
  gvalue_unset : string;
  footer : string;
}

(* [generate_property_wrapper ~ctx ~c_type prop class_name ~is_getter
    ~c_to_ml_expr ~ml_to_c_expr ~gvalue_assignment ~result_expr ~caml_params ~caml_locals] generates a C wrapper
    function for both property getters and setters. Uses a template-based approach with named sections
    for clearer code structure. *)
let generate_property_wrapper ~ctx ~c_type (prop : gir_property) class_name
    ~is_getter ~c_to_ml_expr ~ml_to_c_expr ~gvalue_assignment ~result_expr
    ~caml_params ~caml_locals =
  let prop_info =
    C_stub_gvalue.GValue.analyze_property_type ~ctx prop.prop_type
  in
  let c_cast = Fmt.str "%s_val" c_type in

  let prop_name =
    if is_getter then Utils.ml_property_name ~ctx ~class_name prop
    else Utils.ml_property_setter_name ~ctx ~class_name prop
  in

  let value_declaration =
    if is_getter then
      let c_type_name = C_stub_helpers.get_c_type_str ~ctx prop.prop_type in
      let prop_pointer = if prop_info.stack_allocated then "" else "*" in
      Fmt.str "    %s %sprop_value;\n" c_type_name prop_pointer
    else
      let type_info =
        Type_mappings.find_type_mapping_for_gir_type ~ctx prop.prop_type
        |> Option.value ~default:C_stub_helpers.default_type_mapping
      in
      let is_string_type =
        prop.prop_type.c_type
        |> Option.map (fun ct ->
            List.exists
              ~f:(fun s -> String.equal s ct)
              [ "gchar*"; "gchararray"; "utf8"; "const gchar*"; "const char*" ])
        |> Option.value ~default:false
      in
      if is_string_type then
        Fmt.str "    ML_DECL_CONST_STRING(c_value, %s);\n" ml_to_c_expr
      else
        let pointer_prefix = if prop_info.stack_allocated then "" else "*" in
        Fmt.str "    %s %sc_value = %s;\n" type_info.c_type pointer_prefix
          ml_to_c_expr
  in

  let property_operation =
    if is_getter then
      Fmt.str
        "      g_object_get_property(G_OBJECT(obj), \"%s\", &prop_gvalue);\n\
        \      %s\n\
        \      result = %s;\n"
        prop.prop_name gvalue_assignment c_to_ml_expr
    else
      Fmt.str
        "      %sg_object_set_property(G_OBJECT(obj), \"%s\", &prop_gvalue);\n"
        gvalue_assignment prop.prop_name
  in

  (* Template-based code generation with named sections *)
  let template =
    {
      header =
        Fmt.str "\nCAMLexport CAMLprim value %s(%s)\n{\n" prop_name caml_params;
      locals = caml_locals;
      obj_decl = Fmt.str "%s *obj = (%s *)%s(self);\n" c_type c_type c_cast;
      pspec_find =
        Fmt.str
          "%sGParamSpec *pspec = \
           g_object_class_find_property(G_OBJECT_GET_CLASS(obj), \"%s\");\n"
          value_declaration prop.prop_name;
      pspec_check =
        Fmt.str
          "if (pspec == NULL) caml_failwith(\"%s: property '%s' not found\");\n"
          prop_name prop.prop_name;
      gvalue_init =
        "GValue prop_gvalue = G_VALUE_INIT;\n\
         g_value_init(&prop_gvalue, pspec->value_type);\n";
      operation = property_operation;
      gvalue_unset = "g_value_unset(&prop_gvalue);\n";
      footer = Fmt.str "%s}\n" result_expr;
    }
  in

  (* Render template sections in order *)
  let buf = Buffer.create 256 in
  Buffer.add_string buf template.header;
  Buffer.add_string buf template.locals;
  Buffer.add_string buf template.obj_decl;
  Buffer.add_string buf template.pspec_find;
  Buffer.add_string buf template.pspec_check;
  Buffer.add_string buf template.gvalue_init;
  Buffer.add_string buf template.operation;
  Buffer.add_string buf template.gvalue_unset;
  Buffer.add_string buf template.footer;
  Buffer.contents buf

(* [generate_c_property_getter ~ctx ~c_type prop class_name] generates a C wrapper function
   to read a GObject property via g_object_get_property. Initializes GValue for the property,
   reads the property value via g_object_get_property, converts from C GValue to OCaml value
   using type mapping, and unsets the GValue. Properly declares property variable as stack or
   heap allocated based on property type analysis. Handles arrays with inline conversion.
   Wraps with version guards if the class or property has a version.
   Returns the complete C function code. *)
let generate_c_property_getter_impl ~ctx ~c_type (prop : gir_property)
    class_name =
  match prop.prop_type.array with
  | Some array_info ->
      (* Handle array property with inline conversion *)
      let element_mapping =
        match
          Type_mappings.find_type_mapping_for_gir_type ~ctx
            array_info.element_type
        with
        | Some mapping -> mapping
        | None ->
            failwith
              (Fmt.str
                 "Array element type '%s' not supported in property getter"
                 array_info.element_type.name)
      in
      let element_c_type =
        match array_info.element_type.c_type with
        | Some ct -> ct
        | None -> element_mapping.c_type
      in

      (* Bare string alias types (e.g. "utf8", "gchararray") have no pointer
         suffix, but g_value_get_boxed returns a NULL-terminated array of
         strings.  Use const char* as the element type so c_result is declared
         as const char** and array indexing gives const char*, making NULL
         comparison and caml_copy_string calls well-typed. *)
      let effective_element_c_type =
        if
          String.equal element_mapping.c_to_ml "caml_copy_string"
          && not (String.contains element_c_type '*')
        then "const char*"
        else element_c_type
      in

      let prop_name = Utils.ml_property_name ~ctx ~class_name prop in
      let c_cast = Fmt.str "%s_val" c_type in
      let c_array_var = "c_result" in

      (* Generate array conversion code.
         Don't pass length_expr - let generate_array_c_to_ml figure it out
         from the array type (zero-terminated, etc.) *)
      let conv_code, ml_array_var_name, _cleanup_code =
        C_stub_array_conv.Array_conv.generate_array_c_to_ml ~ctx
          ~var:c_array_var ~array_info ~length_expr:None
          ~element_c_type:effective_element_c_type
          ~transfer_ownership:prop.prop_type.transfer_ownership ()
      in

      (* Generate property getter with array handling.
         Note: conv_code includes its own CAMLlocal1 declaration, so don't add another. *)
      Fmt.str
        "\n\
         CAMLexport CAMLprim value %s(value self)\n\
         {\n\
         %s *obj = (%s *)%s(self);\n\
         CAMLparam1(self);\n\
         GValue prop_gvalue = G_VALUE_INIT;\n\
         GParamSpec *pspec = \
         g_object_class_find_property(G_OBJECT_GET_CLASS(obj), \"%s\");\n\
         if (pspec == NULL) caml_failwith(\"%s: property '%s' not found\");\n\
         g_value_init(&prop_gvalue, pspec->value_type);\n\
         g_object_get_property(G_OBJECT(obj), \"%s\", &prop_gvalue);\n\
         %s* %s = (%s*)g_value_get_boxed(&prop_gvalue);\n\
         %s\n\
         g_value_unset(&prop_gvalue);\n\
         CAMLreturn(%s);\n\
         }"
        prop_name c_type c_type c_cast prop.prop_name prop_name prop.prop_name
        prop.prop_name effective_element_c_type c_array_var
        effective_element_c_type conv_code ml_array_var_name
  | None ->
      (* Regular property - use existing type mapping *)
      let type_info =
        Type_mappings.find_type_mapping_for_gir_type ~ctx prop.prop_type
        |> Option.value ~default:C_stub_helpers.default_type_mapping
      in

      let c_to_ml_expr =
        C_stub_helpers.nullable_c_to_ml_expr ~ctx ~var:"prop_value"
          ~gir_type:prop.prop_type ~mapping:type_info ()
      in

      let c_type_name = C_stub_helpers.get_c_type_str ~ctx prop.prop_type in
      let gvalue_assignment =
        C_stub_gvalue.GValue.generate_gvalue_getter_assignment ~ml_name:"getter"
          ~prop ~c_type_name
          ~prop_info:
            (C_stub_gvalue.GValue.analyze_property_type ~ctx prop.prop_type)
      in

      generate_property_wrapper ~ctx ~c_type prop class_name ~is_getter:true
        ~c_to_ml_expr ~ml_to_c_expr:"" ~gvalue_assignment
        ~result_expr:"CAMLreturn(result);" ~caml_params:"value self"
        ~caml_locals:"    CAMLparam1(self);\n    CAMLlocal1(result);\n"

(* [generate_c_property_setter_impl ~ctx ~c_type prop class_name] generates a C wrapper function
   to write a GObject property via g_object_set_property. Converts OCaml value to C value,
   initializes GValue for the property, stores converted value in GValue, calls g_object_set_property,
   and unsets the GValue. Optimizes string types using const string declarations. Handles arrays
   with inline conversion. Returns the complete C function code (unwrapped). *)
let generate_c_property_setter_impl ~ctx ~c_type (prop : gir_property)
    class_name =
  match prop.prop_type.array with
  | Some array_info ->
      (* Handle array property with inline conversion *)
      let element_mapping =
        match
          Type_mappings.find_type_mapping_for_gir_type ~ctx
            array_info.element_type
        with
        | Some mapping -> mapping
        | None ->
            failwith
              (Fmt.str
                 "Array element type '%s' not supported in property setter"
                 array_info.element_type.name)
      in
      let element_c_type =
        match array_info.element_type.c_type with
        | Some ct -> ct
        | None -> element_mapping.c_type
      in

      let prop_name = Utils.ml_property_setter_name ~ctx ~class_name prop in
      let c_cast = Fmt.str "%s_val" c_type in

      (* Generate array conversion code *)
      let nullable = prop.prop_type.nullable in
      let conv_code, c_array_var, _length_var, cleanup_code =
        C_stub_array_conv.Array_conv.generate_array_ml_to_c ~ctx
          ~var:"new_value" ~array_info ~element_mapping ~element_c_type
          ~transfer_ownership:prop.prop_type.transfer_ownership ~nullable
      in

      (* Generate property setter with array handling *)
      Fmt.str
        "\n\
         CAMLexport CAMLprim value %s(value self, value new_value)\n\
         {\n\
         %s *obj = (%s *)%s(self);\n\
         CAMLparam2(self, new_value);\n\
         %s\n\
         GValue prop_gvalue = G_VALUE_INIT;\n\
         GParamSpec *pspec = \
         g_object_class_find_property(G_OBJECT_GET_CLASS(obj), \"%s\");\n\
         if (pspec == NULL) caml_failwith(\"%s: property '%s' not found\");\n\
         g_value_init(&prop_gvalue, pspec->value_type);\n\
         g_value_set_boxed(&prop_gvalue, %s);\n\
         g_object_set_property(G_OBJECT(obj), \"%s\", &prop_gvalue);\n\
         g_value_unset(&prop_gvalue);\n\
         %s\n\
         CAMLreturn(Val_unit);\n\
         }"
        prop_name c_type c_type c_cast conv_code prop.prop_name prop_name
        prop.prop_name c_array_var prop.prop_name cleanup_code
  | None ->
      (* Regular property - use existing type mapping *)
      let type_info =
        Type_mappings.find_type_mapping_for_gir_type ~ctx prop.prop_type
        |> Option.value ~default:C_stub_helpers.default_type_mapping
      in

      let ml_to_c_expr =
        C_stub_helpers.nullable_ml_to_c_expr ~var:"new_value"
          ~gir_type:prop.prop_type ~mapping:type_info
      in

      let prop_info =
        C_stub_gvalue.GValue.analyze_property_type ~ctx prop.prop_type
      in
      let setter_assignment =
        C_stub_gvalue.GValue.generate_gvalue_setter_assignment ~ml_name:"setter"
          ~prop_info
      in

      generate_property_wrapper ~ctx ~c_type prop class_name ~is_getter:false
        ~c_to_ml_expr:"" ~ml_to_c_expr ~gvalue_assignment:setter_assignment
        ~result_expr:"    CAMLreturn(Val_unit);\n"
        ~caml_params:"value self, value new_value"
        ~caml_locals:"    CAMLparam2(self, new_value);\n"

(** Public getter function - emits impl without wrapping (version guards are
    handled at class level in gir_gen.ml) *)
let generate_c_property_getter ~ctx ~c_type (prop : gir_property) class_name =
  generate_c_property_getter_impl ~ctx ~c_type prop class_name

(** Public setter function - emits impl without wrapping (version guards are
    handled at class level in gir_gen.ml) *)
let generate_c_property_setter ~ctx ~c_type (prop : gir_property) class_name =
  generate_c_property_setter_impl ~ctx ~c_type prop class_name
