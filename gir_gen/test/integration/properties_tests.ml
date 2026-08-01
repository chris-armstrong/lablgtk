(* Property generation tests *)

open Helpers

let properties_gir =
  wrap_namespace
    {|
    <class name="TestWidget" c:type="GtkTestWidget" parent="Widget">
      <constructor name="new" c:identifier="gtk_test_widget_new"/>
      <property name="read-only-prop" readable="1">
        <type name="utf8" c:type="const gchar*"/>
      </property>
      <property name="read-write-prop" readable="1" writable="1">
        <type name="gboolean" c:type="gboolean"/>
      </property>
      <property name="construct-only-prop" readable="1" writable="1" construct-only="1">
        <type name="gint" c:type="gint"/>
      </property>
    </class>
|}

let properties_only_gir =
  wrap_namespace
    {|
    <class name="PropertiesOnly" c:type="GtkPropertiesOnly" parent="Widget">
      <property name="label" readable="1" writable="1">
        <type name="utf8" c:type="const gchar*"/>
      </property>
      <property name="active" readable="1" writable="1">
        <type name="gboolean" c:type="gboolean"/>
      </property>
    </class>
|}

let test_property_generation () =
  let output_dir =
    run_integration_test ~gir_content:properties_gir
      ~class_names:[ "TestWidget" ] ~test_name:"property_gen" ()
  in
  let widget_file = mli_file output_dir "test_widget" in
  assert_true "TestWidget.mli should be created" (file_exists widget_file);

  let content = read_file widget_file in
  let sig_ast = Ml_ast_helpers.parse_interface content in

  Ml_validation.assert_value_exists_sig sig_ast "get_read_only_prop";
  Ml_validation.assert_no_value_matching_sig sig_ast
    (fun name -> name = "set_read_only_prop")
    "set_read_only_prop";

  Ml_validation.assert_value_exists_sig sig_ast "get_read_write_prop";
  Ml_validation.assert_value_exists_sig sig_ast "set_read_write_prop";

  Ml_validation.assert_value_exists_sig sig_ast "get_construct_only_prop";
  Ml_validation.assert_no_value_matching_sig sig_ast
    (fun name -> name = "set_construct_only_prop")
    "set_construct_only_prop";

  (* Check property return types via AST *)
  expect_some "get_read_write_prop not found"
    (Ml_ast_helpers.find_value_declaration_sig sig_ast "get_read_write_prop")
    (fun vd -> Ml_validation.assert_return_type vd "bool");

  expect_some "get_construct_only_prop not found"
    (Ml_ast_helpers.find_value_declaration_sig sig_ast "get_construct_only_prop")
    (fun vd -> Ml_validation.assert_return_type vd "int")

let test_c_property_generation () =
  let output_dir =
    run_integration_test ~gir_content:properties_gir
      ~class_names:[ "TestWidget" ] ~test_name:"c_property_gen" ()
  in
  let c_file = stub_c_file output_dir "TestWidget" in
  assert_true "C file should be created" (file_exists c_file);

  let c_content = read_file c_file in
  let c_functions = C_parser.parse_c_code c_content in

  let find_fn name =
    expect_some
      (Fmt.str "C function '%s' not found" name)
      (List.find_opt (fun (f : C_ast.c_function) -> f.name = name) c_functions)
      Fun.id
  in

  let getter = find_fn "ml_gtk_test_widget_get_read_only_prop" in
  assert_true "C getter should call g_object_get_property"
    (C_validation.calls_c_function getter "g_object_get_property");

  let setter = find_fn "ml_gtk_test_widget_set_read_write_prop" in
  assert_true "C setter should call g_object_set_property"
    (C_validation.calls_c_function setter "g_object_set_property");

  assert_true "C code should use CAMLparam"
    (List.exists (fun f -> C_validation.has_caml_param_macro f) c_functions);
  assert_true "C code should use CAMLreturn"
    (List.exists (fun f -> C_validation.has_caml_return f) c_functions);

  let _ = find_fn "ml_gtk_test_widget_get_construct_only_prop" in
  assert_true "Should not generate C setter for construct-only property"
    (not
       (List.exists
          (fun (f : C_ast.c_function) ->
            f.name = "ml_gtk_test_widget_set_construct_only_prop")
          c_functions))

let test_properties_only_class () =
  let output_dir =
    run_integration_test ~gir_content:properties_only_gir
      ~class_names:[ "PropertiesOnly" ] ~test_name:"properties_only" ()
  in
  let mli = mli_file output_dir "properties_only" in
  let content = read_file mli in
  let sig_ast = Ml_ast_helpers.parse_interface content in

  Ml_validation.assert_value_exists_sig sig_ast "get_label";
  Ml_validation.assert_value_exists_sig sig_ast "set_label";
  Ml_validation.assert_value_exists_sig sig_ast "get_active";
  Ml_validation.assert_value_exists_sig sig_ast "set_active"

let tests =
  [
    Alcotest.test_case "Property generation" `Quick test_property_generation;
    Alcotest.test_case "C property generation (Phase 5.2)" `Quick
      test_c_property_generation;
    Alcotest.test_case "Properties-only class" `Quick test_properties_only_class;
  ]
