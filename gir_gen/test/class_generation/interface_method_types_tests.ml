(* Tests for Phase 7: Layer 2 interface method types.
 *
 * Verifies:
 *   1. A class with a method returning an interface type generates proper wrapping:
 *      new GMyIface.my_iface (or Option.map ...)
 *   2. A class with a method accepting an interface parameter generates:
 *      - arg#as_my_iface accessor let-binding in the body
 *      - GMyIface.my_iface_t in the type signature
 *
 * All validation uses Ml_ast_helpers / Ml_validation (AST-based checks).
 * See docs/code_guidelines/test-patterns.md.
 *)

open Ppxlib.Parsetree

(* ========================================================================= *)
(* GIR XML fixtures                                                           *)
(* ========================================================================= *)

(** Interface + class with a method that RETURNS the interface type. get_model
    returns MyIface. *)
let gir_method_returns_interface =
  Helpers.wrap_namespace ~version:"4.0"
    {|<interface name="MyIface"
                 c:type="GtkMyIface"
                 glib:type-name="GtkMyIface"
                 glib:get-type="gtk_my_iface_get_type">
      </interface>
      <class name="MyClass"
             c:type="GtkMyClass"
             glib:type-name="GtkMyClass"
             glib:get-type="gtk_my_class_get_type"
             parent="GObject.Object">
        <implements name="MyIface"/>
        <constructor name="new" c:identifier="gtk_my_class_new"
                     introspectable="1">
          <return-value transfer-ownership="none">
            <type name="MyClass" c:type="GtkMyClass*"/>
          </return-value>
        </constructor>
        <method name="get_iface" c:identifier="gtk_my_class_get_iface"
                introspectable="1">
          <return-value transfer-ownership="none" nullable="1">
            <type name="GtkMyIface" c:type="GtkMyIface*"/>
          </return-value>
        </method>
      </class>|}

(** Interface + class with a method that ACCEPTS the interface as a parameter.
*)
let gir_method_takes_interface =
  Helpers.wrap_namespace ~version:"4.0"
    {|<interface name="MyIface"
                 c:type="GtkMyIface"
                 glib:type-name="GtkMyIface"
                 glib:get-type="gtk_my_iface_get_type">
      </interface>
      <class name="MyClass"
             c:type="GtkMyClass"
             glib:type-name="GtkMyClass"
             glib:get-type="gtk_my_class_get_type"
             parent="GObject.Object">
        <implements name="MyIface"/>
        <constructor name="new" c:identifier="gtk_my_class_new"
                     introspectable="1">
          <return-value transfer-ownership="none">
            <type name="MyClass" c:type="GtkMyClass*"/>
          </return-value>
        </constructor>
        <method name="set_iface" c:identifier="gtk_my_class_set_iface"
                introspectable="1">
          <parameters>
            <parameter name="iface" transfer-ownership="none">
              <type name="GtkMyIface" c:type="GtkMyIface*"/>
            </parameter>
          </parameters>
          <return-value transfer-ownership="none">
            <type name="none" c:type="void"/>
          </return-value>
        </method>
      </class>|}

(** Interface + class where the method accepting an interface param is nullable.
*)
let gir_method_takes_nullable_interface =
  Helpers.wrap_namespace ~version:"4.0"
    {|<interface name="MyIface"
                 c:type="GtkMyIface"
                 glib:type-name="GtkMyIface"
                 glib:get-type="gtk_my_iface_get_type">
      </interface>
      <class name="MyClass"
             c:type="GtkMyClass"
             glib:type-name="GtkMyClass"
             glib:get-type="gtk_my_class_get_type"
             parent="GObject.Object">
        <implements name="MyIface"/>
        <constructor name="new" c:identifier="gtk_my_class_new"
                     introspectable="1">
          <return-value transfer-ownership="none">
            <type name="MyClass" c:type="GtkMyClass*"/>
          </return-value>
        </constructor>
        <method name="set_iface" c:identifier="gtk_my_class_set_iface"
                introspectable="1">
          <parameters>
            <parameter name="iface" transfer-ownership="none" nullable="1">
              <type name="GtkMyIface" c:type="GtkMyIface*"/>
            </parameter>
          </parameters>
          <return-value transfer-ownership="none">
            <type name="none" c:type="void"/>
          </return-value>
        </method>
      </class>|}

(* ========================================================================= *)
(* Runner helper: run gir_gen and return parsed Layer 2 .ml AST              *)
(* ========================================================================= *)

(** Run gir_gen.exe on [gir_content], return (raw_content, ml_ast) for the Layer
    2 g<ClassName>.ml file. Cleans up temp files on exit. *)
let run_and_parse_layer2_ml gir_content class_name =
  let gir_file = Filename.temp_file "test_iface_method" ".gir" in
  let output_dir = Filename.temp_file "test_iface_method_out" "" in
  Sys.remove output_dir;
  Unix.mkdir output_dir 0o755;
  Fun.protect
    ~finally:(fun () ->
      (try Sys.remove gir_file with Sys_error _ -> ());
      let generated_dir = Helpers.generated_dir output_dir in
      (try
         Array.iter
           (fun f -> Sys.remove (Filename.concat generated_dir f))
           (Sys.readdir generated_dir);
         Unix.rmdir generated_dir
       with Sys_error _ | Unix.Unix_error _ -> ());
      try
        Array.iter
          (fun f -> Sys.remove (Filename.concat output_dir f))
          (Sys.readdir output_dir);
        Unix.rmdir output_dir
      with Sys_error _ | Unix.Unix_error _ -> ())
    (fun () ->
      Helpers.create_gir_file gir_file gir_content;
      Helpers.ensure_output_dir output_dir;
      ignore (Helpers.run_gir_gen gir_file output_dir);
      let ml_path = Helpers.g_wrapper_file output_dir class_name in
      if not (Helpers.file_exists ml_path) then
        Alcotest.failf "Expected Layer 2 file not found: %s" ml_path;
      let content = Helpers.read_file ml_path in
      (content, Ml_ast_helpers.parse_implementation content))

(* ========================================================================= *)
(* Tests: method returning an interface type                                  *)
(* ========================================================================= *)

(** The method 'get_iface' should be generated (previously skipped). *)
let test_interface_return_method_is_generated () =
  let _content, ml_ast =
    run_and_parse_layer2_ml gir_method_returns_interface "MyClass"
  in
  let cd =
    Helpers.expect_some "class my_class not found"
      (Ml_ast_helpers.find_class_definition ml_ast "my_class")
      Fun.id
  in
  if not (Ml_ast_helpers.method_exists_as_definition cd.pci_expr "get_iface")
  then Alcotest.fail "method get_iface not generated"

(** The method return type annotation should reference GMyIface.my_iface_t. *)
let test_interface_return_type_annotation () =
  let _content, ml_ast =
    run_and_parse_layer2_ml gir_method_returns_interface "MyClass"
  in
  Layer2_helpers.validate_method_type_annotation ~structure:ml_ast
    ~class_name:"my_class" ~method_name:"get_iface"
    ~expected_type:"unit -> GMy_iface.my_iface_t option"

(** The method body should use Option.map with 'new GMy_iface.my_iface' for
    wrapping the returned interface object. *)
let test_interface_return_wrapping () =
  let _content, ml_ast =
    run_and_parse_layer2_ml gir_method_returns_interface "MyClass"
  in
  let cd =
    Helpers.expect_some "class my_class not found"
      (Ml_ast_helpers.find_class_definition ml_ast "my_class")
      Fun.id
  in
  let method_field =
    Helpers.expect_some "method get_iface not found"
      (Ml_ast_helpers.find_method_in_class cd.pci_expr "get_iface")
      Fun.id
  in
  let body =
    Helpers.expect_some "could not extract method body"
      (Ml_ast_helpers.get_method_body method_field)
      Fun.id
  in
  (* The body should contain 'Option.map' (nullable return) *)
  if not (Ml_ast_helpers.contains_function_call body "Option.map") then
    Alcotest.fail
      "method body does not contain Option.map for nullable interface return"

(* ========================================================================= *)
(* Tests: method accepting an interface parameter                             *)
(* ========================================================================= *)

(** The method 'set_iface' should be generated (previously skipped). *)
let test_interface_param_method_is_generated () =
  let _content, ml_ast =
    run_and_parse_layer2_ml gir_method_takes_interface "MyClass"
  in
  let cd =
    Helpers.expect_some "class my_class not found"
      (Ml_ast_helpers.find_class_definition ml_ast "my_class")
      Fun.id
  in
  if not (Ml_ast_helpers.method_exists_as_definition cd.pci_expr "set_iface")
  then Alcotest.fail "method set_iface not generated"

(** The method type annotation in the .ml class type should use
    GMyIface.my_iface_t as the parameter type. *)
let test_interface_param_type_in_class_type () =
  let _content, ml_ast =
    run_and_parse_layer2_ml gir_method_takes_interface "MyClass"
  in
  let ctd =
    Helpers.expect_some "class type my_class_t not found"
      (Ml_ast_helpers.find_class_type_declaration_impl ml_ast "my_class_t")
      Fun.id
  in
  (* Find the set_iface method in the class type *)
  let method_type_str =
    match ctd.pci_expr.pcty_desc with
    | Pcty_signature { pcsig_fields; _ } -> (
        Helpers.expect_some "set_iface not in class type my_class_t"
          (List.find_opt
             (fun f ->
               match f.pctf_desc with
               | Pctf_method ({ txt; _ }, _, _, _) ->
                   String.equal txt "set_iface"
               | _ -> false)
             pcsig_fields)
        @@ fun f ->
        match f.pctf_desc with
        | Pctf_method (_, _, _, t) -> Ml_ast_helpers.core_type_to_string t
        | _ -> Alcotest.fail "not a method field")
    | _ -> Alcotest.fail "class type is not a signature"
  in
  if not (String.equal method_type_str "GMy_iface.my_iface_t -> unit") then
    Alcotest.failf
      "expected 'GMy_iface.my_iface_t -> unit' in class type, got '%s'"
      method_type_str

(** The method body should contain 'iface#as_my_iface' accessor to unwrap the
    interface wrapper and pass the Layer 1 value to the C stub. *)
let test_interface_param_accessor_binding () =
  let _content, ml_ast =
    run_and_parse_layer2_ml gir_method_takes_interface "MyClass"
  in
  let cd =
    Helpers.expect_some "class my_class not found"
      (Ml_ast_helpers.find_class_definition ml_ast "my_class")
      Fun.id
  in
  let method_field =
    Helpers.expect_some "method set_iface not found"
      (Ml_ast_helpers.find_method_in_class cd.pci_expr "set_iface")
      Fun.id
  in
  let body =
    Helpers.expect_some "could not extract method body"
      (Ml_ast_helpers.get_method_body method_field)
      Fun.id
  in
  (* The body should send #as_my_iface to coerce the interface wrapper *)
  if not (Ml_ast_helpers.contains_method_send body "as_my_iface") then
    Alcotest.fail "method body does not send #as_my_iface for interface param"

(** Nullable interface param should use Option.map and the #as_my_iface
    accessor. *)
let test_nullable_interface_param_accessor_binding () =
  let _content, ml_ast =
    run_and_parse_layer2_ml gir_method_takes_nullable_interface "MyClass"
  in
  let cd =
    Helpers.expect_some "class my_class not found"
      (Ml_ast_helpers.find_class_definition ml_ast "my_class")
      Fun.id
  in
  let method_field =
    Helpers.expect_some "method set_iface not found"
      (Ml_ast_helpers.find_method_in_class cd.pci_expr "set_iface")
      Fun.id
  in
  let body =
    Helpers.expect_some "could not extract method body"
      (Ml_ast_helpers.get_method_body method_field)
      Fun.id
  in
  (* The body should contain Option.map for the nullable param *)
  if not (Ml_ast_helpers.contains_function_call body "Option.map") then
    Alcotest.fail "nullable interface param body does not contain Option.map";
  (* And should send #as_my_iface *)
  if not (Ml_ast_helpers.contains_method_send body "as_my_iface") then
    Alcotest.fail "nullable interface param body does not send #as_my_iface"

(* ========================================================================= *)
(* Test suite                                                                 *)
(* ========================================================================= *)

let test_suite =
  [
    ( "interface return: method is generated",
      `Quick,
      test_interface_return_method_is_generated );
    ( "interface return: type annotation uses my_iface_t option",
      `Quick,
      test_interface_return_type_annotation );
    ( "interface return: body wraps with Option.map",
      `Quick,
      test_interface_return_wrapping );
    ( "interface param: method is generated",
      `Quick,
      test_interface_param_method_is_generated );
    ( "interface param: class type uses my_iface_t",
      `Quick,
      test_interface_param_type_in_class_type );
    ( "interface param: body sends #as_my_iface accessor",
      `Quick,
      test_interface_param_accessor_binding );
    ( "interface param nullable: body uses Option.map and #as_my_iface",
      `Quick,
      test_nullable_interface_param_accessor_binding );
  ]
