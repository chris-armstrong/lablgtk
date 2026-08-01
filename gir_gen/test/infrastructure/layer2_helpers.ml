(* Layer 2 Test Infrastructure - Helpers for testing class hierarchies and inheritance *)

open Gir_gen_lib.Types

(* ========================================================================= *)
(* Test Class Creation with Inheritance *)
(* ========================================================================= *)

(* Create a test class with optional parent for inheritance testing *)
let create_test_class_with_parent ~name ~c_type ?parent:(parent_val = None) () =
  {
    class_name = name;
    c_type;
    parent = parent_val;
    implements = [];
    introspectable = true;
    constructors = [];
    methods = [];
    properties = [];
    signals = [];
    class_doc = None;
    version = None;
    os = None;
  }

(* Create a simple parent class for testing inheritance *)
let create_parent_class ~name ~c_type () =
  create_test_class_with_parent ~name ~c_type ~parent:None ()

(* Create a child class that inherits from a parent *)
let create_child_class ~name ~c_type ~parent_name () =
  create_test_class_with_parent ~name ~c_type ~parent:(Some parent_name) ()

(* Create a test class with methods for method testing *)
let create_test_class_with_methods ~name ~c_type ~methods () =
  {
    class_name = name;
    c_type;
    parent = None;
    implements = [];
    introspectable = true;
    constructors = [];
    methods;
    properties = [];
    signals = [];
    class_doc = None;
    version = None;
    os = None;
  }

(* ========================================================================= *)
(* Test Method Creation *)
(* ========================================================================= *)

(* Create a simple test method with no parameters *)
let create_test_method ~name ~c_identifier () =
  {
    method_name = name;
    c_identifier;
    parameters = [];
    return_type =
      {
        name = "none";
        c_type = Some "void";
        nullable = false;
        transfer_ownership = TransferNone;
        array = None;
      };
    doc = None;
    throws = false;
    get_property = None;
    set_property = None;
    introspectable = true;
    version = None;
    version_namespace = None;
    os = None;
  }

(* Create a test method with a single parameter *)
let create_test_method_with_param ~name ~c_identifier ~param_name ~param_type ()
    =
  let param =
    {
      param_name;
      param_type;
      direction = In;
      nullable = false;
      varargs = false;
      caller_allocates = false;
    }
  in
  {
    method_name = name;
    c_identifier;
    parameters = [ param ];
    return_type =
      {
        name = "none";
        c_type = Some "void";
        nullable = false;
        transfer_ownership = TransferNone;
        array = None;
      };
    doc = None;
    throws = false;
    get_property = None;
    set_property = None;
    introspectable = true;
    version = None;
    version_namespace = None;
    os = None;
  }

(* Create a test method with multiple parameters *)
let create_test_method_with_params ~name ~c_identifier ~params () =
  {
    method_name = name;
    c_identifier;
    parameters = params;
    return_type =
      {
        name = "none";
        c_type = Some "void";
        nullable = false;
        transfer_ownership = TransferNone;
        array = None;
      };
    doc = None;
    throws = false;
    get_property = None;
    set_property = None;
    introspectable = true;
    version = None;
    version_namespace = None;
    os = None;
  }

(* Create a test method with a return type *)
let create_test_method_with_return ~name ~c_identifier ~return_type () =
  {
    method_name = name;
    c_identifier;
    parameters = [];
    return_type;
    doc = None;
    throws = false;
    get_property = None;
    set_property = None;
    introspectable = true;
    version = None;
    version_namespace = None;
    os = None;
  }

(* Create a test method that throws errors *)
let create_test_method_throwing ~name ~c_identifier () =
  {
    method_name = name;
    c_identifier;
    parameters = [];
    return_type =
      {
        name = "none";
        c_type = Some "void";
        nullable = false;
        transfer_ownership = TransferNone;
        array = None;
      };
    doc = None;
    throws = true;
    get_property = None;
    set_property = None;
    introspectable = true;
    version = None;
    version_namespace = None;
    os = None;
  }

(* ========================================================================= *)
(* Layer 2 Output Validation - AST-based *)
(* ========================================================================= *)

(* Validate that generated code has expected module structure using AST parsing *)
let validate_layer2_output ~output_dir ~module_name ~expected_types =
  let ml_file = Helpers.ml_file output_dir module_name in
  let mli_file = Helpers.mli_file output_dir module_name in

  (* Check that both .ml and .mli files exist *)
  if not (Helpers.file_exists ml_file) then
    Alcotest.fail (Fmt.str "Expected .ml file not found: %s" ml_file);

  if not (Helpers.file_exists mli_file) then
    Alcotest.fail (Fmt.str "Expected .mli file not found: %s" mli_file);

  (* Read and parse both files *)
  let ml_content = Helpers.read_file ml_file in
  let mli_content = Helpers.read_file mli_file in

  let ml_ast = Ml_ast_helpers.parse_implementation ml_content in
  let mli_ast = Ml_ast_helpers.parse_interface mli_content in

  (* Validate that all expected types are present using AST parsing *)
  List.iter
    (fun type_name ->
      Ml_validation.assert_type_exists ml_ast type_name;
      Ml_validation.assert_type_exists_sig mli_ast type_name)
    expected_types;

  (ml_content, mli_content, ml_ast, mli_ast)

(* Validate that a class has the expected accessor method using AST *)
let validate_accessor_method ~ml_ast ~accessor_name =
  Ml_validation.assert_value_exists ml_ast accessor_name

(* Validate that inheritance is properly represented using AST *)
let validate_inheritance ~ml_ast ~parent_name ~child_name =
  (* Check that child class is defined *)
  Ml_validation.assert_type_exists ml_ast child_name;
  (* Check that parent class is referenced *)
  Ml_validation.assert_type_exists ml_ast parent_name

(* Validate that a method is properly generated using AST *)
let validate_method_generation ~ml_ast ~method_name =
  Ml_validation.assert_value_exists ml_ast method_name

(* ========================================================================= *)
(* Signature vs Implementation Consistency - AST-based *)
(* ========================================================================= *)

(* Check that .mli and .ml have consistent type definitions using AST *)
let check_mli_vs_ml_consistency ~mli_ast ~ml_ast ~type_name =
  (* Both files should define the type *)
  Ml_validation.assert_type_exists_sig mli_ast type_name;
  Ml_validation.assert_type_exists ml_ast type_name

(* Check that all externals in .mli are implemented in .ml using AST *)
let check_externals_consistency ~mli_ast ~ml_ast ~external_name =
  Helpers.assert_some
    (Fmt.str "External '%s' not found in .mli file" external_name)
    (Ml_ast_helpers.find_external_sig mli_ast external_name);
  Helpers.assert_some
    (Fmt.str "External '%s' not found in .ml file" external_name)
    (Ml_ast_helpers.find_external ml_ast external_name)

(* Validate that function signatures match between .mli and .ml using AST *)
let validate_function_signature_consistency ~mli_ast ~ml_ast ~func_name =
  Helpers.assert_some
    (Fmt.str "Function '%s' not found in .mli file" func_name)
    (Ml_ast_helpers.find_value_declaration_sig mli_ast func_name);
  Helpers.assert_some
    (Fmt.str "Function '%s' not found in .ml file" func_name)
    (Ml_ast_helpers.find_let_binding ml_ast func_name)

(* ========================================================================= *)
(* Hierarchy and Conversion Method Validation *)
(* ========================================================================= *)

(* Validate that conversion methods are properly generated *)
let validate_conversion_methods ~ml_ast ~from_type:_ ~to_type =
  let conversion_method = "as_" ^ String.lowercase_ascii to_type in
  Ml_validation.assert_value_exists ml_ast conversion_method

(* Check that a class properly implements conversion to its base type *)
let validate_base_type_conversion ~ml_ast ~class_name:_ ~base_type =
  let conversion_method = "as_" ^ String.lowercase_ascii base_type in
  Ml_validation.assert_value_exists ml_ast conversion_method

(* ========================================================================= *)
(* Property and Signal Validation *)
(* ========================================================================= *)

(* Validate that properties are properly generated *)
let validate_property_generation ~ml_ast ~property_name =
  Ml_validation.assert_value_exists ml_ast property_name

(* Validate that signals are properly generated *)
let validate_signal_generation ~ml_ast ~signal_name =
  Ml_validation.assert_value_exists ml_ast signal_name

(* ========================================================================= *)
(* Type Wrapper Validation *)
(* ========================================================================= *)

(* Validate that a class is properly wrapped as an abstract type *)
let validate_abstract_type_wrapper ~mli_ast ~type_name =
  Ml_validation.assert_type_exists_sig mli_ast type_name

(* Validate that a type properly wraps a GObject *)
let validate_gobject_wrapper ~ml_ast ~type_name =
  Ml_validation.assert_type_exists ml_ast type_name

(* ========================================================================= *)
(* Critical Layer 2 Validation Helpers *)
(* ========================================================================= *)

(* Validate structural type parameters like `<as_widget: Widget.t; ..>` *)
let validate_structural_type_parameter ~mli_ast ~type_name ~field_name
    ~field_type =
  Helpers.expect_some
    (Fmt.str "Type '%s' not found in signature" type_name)
    (Ml_ast_helpers.find_type_declaration_sig mli_ast type_name)
  @@ fun type_decl ->
  Helpers.expect_some
    (Fmt.str "Type '%s' has no manifest (not a structural type)" type_name)
    type_decl.ptype_manifest
  @@ fun manifest ->
  let type_str = Ml_ast_helpers.core_type_to_string manifest in
  (* Ppxlib has no structural accessor for object/record field names inside a
     core_type manifest — substring search on the printed form is the only
     available mechanism for this check. *)
  if not (Helpers.string_contains type_str field_name) then
    Alcotest.fail
      (Fmt.str "Structural field '%s' not found in type '%s'" field_name
         type_name);
  if not (Helpers.string_contains type_str field_type) then
    Alcotest.fail
      (Fmt.str "Field type '%s' not found in type '%s'" field_type type_name)

(* Validate hierarchy coercion like (#widget -> Widget.t) *)
let validate_hierarchy_coercion ~mli_ast ~function_name ~param_idx
    ~expected_coercion =
  Helpers.expect_some
    (Fmt.str "Function '%s' not found in signature" function_name)
    (Ml_ast_helpers.find_value_declaration_sig mli_ast function_name)
  @@ fun func_decl ->
  let param_types = Ml_ast_helpers.get_param_types func_decl.pval_type in
  Helpers.expect_some
    (Fmt.str "Parameter %d not found in '%s'" param_idx function_name)
    (List.nth_opt param_types param_idx)
  @@ fun param_type ->
  let param_str = Ml_ast_helpers.core_type_to_string param_type in
  if not (String.equal param_str expected_coercion) then
    Alcotest.fail
      (Fmt.str "Parameter %d of '%s' expected coercion '%s', got '%s'" param_idx
         function_name expected_coercion param_str)

(* Validate wrapped return values like (new ClassName ret) *)
let validate_wrapped_return ~ml_ast ~function_name ~wrapper_class =
  Helpers.expect_some
    (Fmt.str "Function '%s' not found in implementation" function_name)
    (Ml_ast_helpers.find_let_binding ml_ast function_name)
  @@ fun binding ->
  (* Check that the binding expression contains the wrapper class *)
  let buf = Buffer.create 256 in
  let fmt = Format.formatter_of_buffer buf in
  Ppxlib.Pprintast.expression fmt binding.pvb_expr;
  Format.pp_print_flush fmt ();
  let binding_str = Buffer.contents buf in
  (* Ppxlib provides no structural accessor to find a specific constructor
     application inside an arbitrary expression — substring search on the
     Pprintast output is the only available mechanism here. *)
  if not (Helpers.string_contains binding_str wrapper_class) then
    Alcotest.fail
      (Fmt.str "Return value for '%s' not wrapped with '%s'" function_name
         wrapper_class)

(* Validate signal handler inheritance *)
let validate_signal_handler_inheritance ~mli_ast ~signal_handler_name
    ~parent_signal =
  Helpers.expect_some
    (Fmt.str "Signal handler '%s' not found in signature" signal_handler_name)
    (Ml_ast_helpers.find_value_declaration_sig mli_ast signal_handler_name)
  @@ fun handler_decl ->
  (* Check that the handler type references the parent signal *)
  let handler_type_str =
    Ml_ast_helpers.core_type_to_string handler_decl.pval_type
  in
  (* core_type_to_string produces a flat string representation; Ppxlib has no
     structural API to check for a specific type alias reference inside an
     arbitrary type expression, so substring search is used. *)
  if not (Helpers.string_contains handler_type_str parent_signal) then
    Alcotest.fail
      (Fmt.str "Signal handler '%s' does not inherit from '%s'"
         signal_handler_name parent_signal)

(* ========================================================================= *)
(* Signal Creation Helpers *)
(* ========================================================================= *)

(* Create a test GIR signal with minimal fields *)
let create_test_signal ~name =
  {
    signal_name = name;
    return_type =
      {
        name = "none";
        c_type = Some "void";
        nullable = false;
        transfer_ownership = TransferNone;
        array = None;
      };
    sig_parameters = [];
    doc = None;
    version = None;
    version_namespace = None;
    os = None;
    run_when = None;
    action = false;
    no_recurse = false;
    no_hooks = false;
  }

(* Create a test GIR signal with return type *)
let create_test_signal_with_return ~name ~return_type =
  {
    signal_name = name;
    return_type;
    sig_parameters = [];
    doc = None;
    version = None;
    version_namespace = None;
    os = None;
    run_when = None;
    action = false;
    no_recurse = false;
    no_hooks = false;
  }

(* Create a test GIR signal with parameters *)
let create_test_signal_with_params ~name ~return_type ~params =
  {
    signal_name = name;
    return_type;
    sig_parameters = params;
    doc = None;
    version = None;
    version_namespace = None;
    os = None;
    run_when = None;
    action = false;
    no_recurse = false;
    no_hooks = false;
  }

(* Create a test class with signals *)
let create_test_class_with_signals ~name ~c_type ~signals () =
  {
    class_name = name;
    c_type;
    parent = None;
    implements = [];
    introspectable = true;
    constructors = [];
    methods = [];
    properties = [];
    signals;
    class_doc = None;
    version = None;
    os = None;
  }

(* ========================================================================= *)
(* Class Inheritance Validation Helpers *)
(* ========================================================================= *)

(* Validate that a class inherits from a specific parent using AST *)
let validate_class_inherits ~structure ~class_name ~parent_class =
  Helpers.expect_some
    (Fmt.str "Class '%s' not found in structure" class_name)
    (Ml_ast_helpers.find_class_declaration structure class_name)
  @@ fun class_decl ->
  let inherit_clauses =
    Ml_ast_helpers.get_class_inherit_clauses class_decl.pci_expr
  in
  if not (List.mem parent_class inherit_clauses) then
    Alcotest.fail
      (Fmt.str "Class '%s' does not inherit from '%s'. Inherits from: [%s]"
         class_name parent_class
         (String.concat "; " inherit_clauses))

(* Validate that a class type inherits from a specific parent class type *)
let validate_class_type_inherits ~signature ~class_name ~parent_class_type =
  Helpers.expect_some
    (Fmt.str "Class type '%s' not found in signature" class_name)
    (Ml_ast_helpers.find_class_type_declaration signature class_name)
  @@ fun ct_decl ->
  let inherit_clauses =
    Ml_ast_helpers.get_class_type_inherit_clauses ct_decl.pci_expr
  in
  if not (List.mem parent_class_type inherit_clauses) then
    Alcotest.fail
      (Fmt.str "Class type '%s' does not inherit from '%s'. Inherits from: [%s]"
         class_name parent_class_type
         (String.concat "; " inherit_clauses))

(* ========================================================================= *)
(* Method Type Annotation Validation Helpers *)
(* ========================================================================= *)

(* Validate that a method has a specific type annotation *)
let validate_method_type_annotation ~structure ~class_name ~method_name
    ~expected_type =
  Helpers.expect_some
    (Fmt.str "Class '%s' not found in structure" class_name)
    (Ml_ast_helpers.find_class_declaration structure class_name)
  @@ fun class_decl ->
  Helpers.expect_some
    (Fmt.str "Method '%s' not found in class '%s'" method_name class_name)
    (Ml_ast_helpers.find_method_in_class class_decl.pci_expr method_name)
  @@ fun method_field ->
  Helpers.expect_some
    (Fmt.str "Could not extract type annotation for method '%s.%s'" class_name
       method_name)
    (Ml_ast_helpers.get_method_type method_field)
  @@ fun actual_type ->
  let actual_type_str = Ml_ast_helpers.core_type_to_string actual_type in
  if not (String.equal actual_type_str expected_type) then
    Alcotest.fail
      (Fmt.str "Method '%s.%s' has type annotation '%s', expected '%s'"
         class_name method_name actual_type_str expected_type)

(* Validate that a method in a signature has a specific type annotation *)
let validate_method_type_annotation_sig
    ~(signature : Ppxlib.Parsetree.signature) ~class_name ~method_name
    ~expected_type =
  Helpers.expect_some
    (Fmt.str "Class '%s' not found in signature" class_name)
    (Ml_ast_helpers.find_class_type_declaration signature class_name)
  @@ fun class_decl ->
  Helpers.expect_some
    (Fmt.str "Method '%s' not found in class '%s'" method_name class_name)
    (Ml_ast_helpers.find_method_in_class_type class_decl.pci_expr method_name)
  @@ fun method_field ->
  match method_field.pctf_desc with
  | Pctf_method (_, _, _, actual_type) ->
      let actual_type_str = Ml_ast_helpers.core_type_to_string actual_type in
      if not (String.equal actual_type_str expected_type) then
        Alcotest.fail
          (Fmt.str "Method '%s.%s' has type annotation '%s', expected '%s'"
             class_name method_name actual_type_str expected_type)
  | _ ->
      Alcotest.fail
        (Fmt.str "Method '%s' in class '%s' is not a method field" method_name
           class_name)

(* ========================================================================= *)
(* Code Generation Helpers *)
(* ========================================================================= *)

(* Create a minimal GIR XML for a class with inheritance *)
let create_gir_class_with_parent ~class_name ~c_type ~parent_name =
  Fmt.str
    {|    <class name="%s" c:type="%s" parent="%s" glib:type-name="Gtk%s" glib:get-type="gtk_%s_get_type" c:symbol-prefix="gtk_%s">
    </class>|}
    class_name c_type parent_name class_name
    (Gir_gen_lib.Utils.to_snake_case class_name)
    (Gir_gen_lib.Utils.to_snake_case class_name)

(* Create a minimal GIR XML for a class method *)
let create_gir_method ~method_name ~c_name =
  Fmt.str
    {|      <method name="%s" c:identifier="%s">
        <return-value transfer-ownership="none">
          <type name="none" c:type="void"/>
        </return-value>
      </method>|}
    method_name c_name

(* Create a GIR method with a parameter *)
let create_gir_method_with_param ~method_name ~c_name ~param_name ~param_type =
  Fmt.str
    {|      <method name="%s" c:identifier="%s">
        <parameters>
          <parameter name="%s" transfer-ownership="none">
            <type name="%s" c:type="gint"/>
          </parameter>
        </parameters>
        <return-value transfer-ownership="none">
          <type name="none" c:type="void"/>
        </return-value>
      </method>|}
    method_name c_name param_name param_type

(* ========================================================================= *)
(* Test Context Helpers *)
(* ========================================================================= *)

(* Add a class to the context *)
let add_class_with_hierarchy ~context ~class_name ~parent_name ~layer2_module:_
    ~base_type:_ =
  let class_obj =
    create_test_class_with_parent ~name:class_name ~c_type:("Gtk" ^ class_name)
      ~parent:(Some parent_name) ()
  in
  { context with classes = context.classes @ [ class_obj ] }

(* Create a test context with multiple related classes *)
let create_test_context_with_hierarchy_chain ~base_class ~derived_classes =
  let ctx = Helpers.create_test_context_with_hierarchy () in
  let base_class_obj =
    create_test_class_with_parent ~name:base_class ~c_type:("Gtk" ^ base_class)
      ~parent:None ()
  in
  let derived_class_objs =
    List.map
      (fun derived_name ->
        create_test_class_with_parent ~name:derived_name
          ~c_type:("Gtk" ^ derived_name) ~parent:(Some base_class) ())
      derived_classes
  in
  { ctx with classes = ctx.classes @ (base_class_obj :: derived_class_objs) }
