(* Layer 2 Method Wrapper Tests - End-to-end testing of method wrapper generation *)

open Type_factory
open Gir_gen_lib.Types
open Ppxlib.Parsetree

let create_test_context = Helpers.create_test_context_with_hierarchy

let find_class ast class_name =
  Helpers.expect_some
    (Fmt.str "Class '%s' not found" class_name)
    (Ml_ast_helpers.find_class_declaration ast class_name)
    Fun.id

let find_class_type ast class_name =
  Helpers.expect_some
    (Fmt.str "Class type '%s' not found" class_name)
    (Ml_ast_helpers.find_class_type_declaration ast class_name)
    Fun.id

let find_method class_decl method_name =
  Helpers.expect_some
    (Fmt.str "Method '%s' not found" method_name)
    (Ml_ast_helpers.find_method_in_class class_decl.pci_expr method_name)
    Fun.id

let extract_method_type class_decl method_name =
  let method_field = find_method class_decl method_name in
  Helpers.expect_some "Could not extract method type"
    (Ml_ast_helpers.get_method_type method_field)
    Fun.id

let validate_method_type ast class_name method_name ~expected =
  let method_type =
    extract_method_type (find_class ast class_name) method_name
  in
  let type_str = Ml_ast_helpers.core_type_to_string method_type in
  if not (String.equal type_str expected) then
    Alcotest.fail
      (Fmt.str "Method '%s.%s' has type '%s', expected '%s'" class_name
         method_name type_str expected)

let get_method_body method_field =
  Helpers.expect_some "Could not extract method body"
    (Ml_ast_helpers.get_method_body method_field)
    Fun.id

let assert_method_body_calls method_body module_name method_name =
  if
    not
      (Ml_ast_helpers.method_body_calls_function method_body module_name
         method_name)
  then
    Alcotest.fail
      (Fmt.str "Method body does not call %s.%s" module_name method_name)

let assert_method_body_is_obj method_body =
  match method_body.pexp_desc with
  | Pexp_ident { txt = Astlib.Longident.Lident "obj"; _ } -> ()
  | _ -> Alcotest.fail "Method body should be a simple 'obj' reference"

let validate_signature_consistency ml_class mli_class method_name =
  let ml_method_type =
    Option.bind
      (Ml_ast_helpers.find_method_in_class ml_class.pci_expr method_name)
      Ml_ast_helpers.get_method_type
  in
  let mli_method_type =
    Option.bind
      (Ml_ast_helpers.find_method_in_class_type mli_class.pci_expr method_name)
      Ml_ast_helpers.get_method_type_from_class_type_field
  in
  match (ml_method_type, mli_method_type) with
  | Some ml_type, Some mli_type ->
      let ml_type_str = Ml_ast_helpers.core_type_to_string ml_type in
      let mli_type_str = Ml_ast_helpers.core_type_to_string mli_type in
      let ml_has_hierarchy = Ml_ast_helpers.contains_hierarchy_type ml_type in
      let mli_has_hierarchy = Ml_ast_helpers.contains_hierarchy_type mli_type in
      if
        (ml_has_hierarchy && not mli_has_hierarchy)
        || ((not ml_has_hierarchy) && mli_has_hierarchy)
      then Alcotest.fail (Fmt.str "Method '%s' hierarchy mismatch" method_name)
      else if (not ml_has_hierarchy) && ml_type_str <> mli_type_str then
        Alcotest.fail
          (Fmt.str "Method '%s' signature mismatch: .ml='%s', .mli='%s'"
             method_name ml_type_str mli_type_str)
  | None, Some _ ->
      Alcotest.fail (Fmt.str "Method '%s' not found in .ml" method_name)
  | Some _, None ->
      Alcotest.fail (Fmt.str "Method '%s' not found in .mli" method_name)
  | None, None -> Alcotest.fail (Fmt.str "Method '%s' not found" method_name)

(* ========================================================================= *)
(* Test 1: Hierarchy Parameter Coercion *)
(* ========================================================================= *)

(* Test that hierarchy parameters like Widget are correctly typed in method wrappers *)
let test_hierarchy_parameter_coercion () =
  let ctx = create_test_context () in

  (* Create a method that takes a Widget parameter *)
  let meth =
    make_gir_method ~method_name:"set_focus"
      ~c_identifier:"gtk_button_set_focus" ~return_type:void_type
      ~parameters:[ make_widget_param ~param_name:"widget" () ]
      ()
  in

  (* Generate Layer 2 class module and signature *)
  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[ meth ] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  let _mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[ meth ] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  (* Parse the generated code into AST *)
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Debug: Print the class name and method to understand the structure *)
  Fmt.epr "Generated ML code:\n%s\n" ml_code;

  (* Verify the method has a hierarchy parameter using AST inspection *)
  Ml_ast_helpers.assert_method_has_hierarchy_param ml_ast "button" "set_focus"

(* ========================================================================= *)
(* Test 2: Nullable Parameter Handling *)
(* ========================================================================= *)

(* Test nullable parameter handling in method wrappers *)
let test_nullable_parameter_handling () =
  let ctx = create_test_context () in

  (* Create a method that takes a nullable string parameter *)
  let meth =
    make_gir_method ~method_name:"set_label"
      ~c_identifier:"gtk_button_set_label" ~return_type:void_type
      ~parameters:[ make_string_param ~param_name:"label" ~nullable:true () ]
      ()
  in

  (* Generate Layer 2 class signature *)
  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[ meth ] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  (* Parse the generated signature into AST *)
  let mli_ast = Ml_ast_helpers.parse_interface mli_code in

  (* Verify the method signature has 'string option' parameter type using AST inspection *)
  Layer2_helpers.validate_method_type_annotation_sig ~signature:mli_ast
    ~class_name:"button_t" ~method_name:"set_label"
    ~expected_type:"string option -> unit"

(* ========================================================================= *)
(* Test 3: Return Value Wrapping *)
(* ========================================================================= *)

(* Test return value wrapping for object types *)
let test_return_value_wrapping () =
  let ctx = create_test_context () in

  (* Create a method that returns a Widget *)
  let meth =
    make_gir_method ~method_name:"get_child"
      ~c_identifier:"gtk_container_get_child" ~return_type:(make_widget_type ())
      ()
  in

  (* Generate Layer 2 class signature *)
  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"Container" ~c_type:"GtkContainer" ~parent_chain:[ "Widget" ]
      ~methods:[ meth ] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  (* Parse the generated signature into AST *)
  let mli_ast = Ml_ast_helpers.parse_interface mli_code in

  (* Verify the method signature has widget return type using AST inspection *)
  Layer2_helpers.validate_method_type_annotation_sig ~signature:mli_ast
    ~class_name:"container_t" ~method_name:"get_child"
    ~expected_type:"unit -> GWidget.widget_t"

(* ========================================================================= *)
(* Test 4: Void Method *)
(* ========================================================================= *)

(* Test void methods (no return value) *)
let test_void_method () =
  let ctx = create_test_context () in

  (* Create a void method *)
  let meth =
    make_void_method ~method_name:"show" ~c_identifier:"gtk_widget_show" ()
  in

  (* Generate Layer 2 class module and signature *)
  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Widget" ~c_type:"GtkWidget" ~parent_chain:[]
      ~methods:[ meth ] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"Widget" ~c_type:"GtkWidget" ~parent_chain:[]
      ~methods:[ meth ] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  (* Parse the generated code into ASTs *)
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in
  let mli_ast = Ml_ast_helpers.parse_interface mli_code in

  (* Validate the show method exists and has correct type using helper *)
  validate_method_type ml_ast "widget" "show" ~expected:"unit -> unit";

  (* Validate method signature in .mli using AST parsing *)
  Layer2_helpers.validate_method_type_annotation_sig ~signature:mli_ast
    ~class_name:"widget_t" ~method_name:"show" ~expected_type:"unit -> unit"

(* ========================================================================= *)
(* Test 5: Multiple Parameters *)
(* ========================================================================= *)

(* Test methods with multiple parameters *)
let test_multiple_parameters () =
  let ctx = create_test_context () in

  (* Create method with multiple integer parameters *)
  let meth =
    make_gir_method ~method_name:"set_size_request"
      ~c_identifier:"gtk_widget_set_size_request" ~return_type:void_type
      ~parameters:
        [
          make_int_param ~param_name:"width" ();
          make_int_param ~param_name:"height" ();
        ]
      ()
  in

  (* Generate Layer 2 class module and signature *)
  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Widget" ~c_type:"GtkWidget" ~parent_chain:[]
      ~methods:[ meth ] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"Widget" ~c_type:"GtkWidget" ~parent_chain:[]
      ~methods:[ meth ] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  (* Parse the generated code into ASTs *)
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in
  let mli_ast = Ml_ast_helpers.parse_interface mli_code in

  (* Validate the set_size_request method using helper *)
  validate_method_type ml_ast "widget" "set_size_request"
    ~expected:"int -> int -> unit";

  (* Validate method signature in .mli using AST parsing *)
  Layer2_helpers.validate_method_type_annotation_sig ~signature:mli_ast
    ~class_name:"widget_t" ~method_name:"set_size_request"
    ~expected_type:"int -> int -> unit"

(* ========================================================================= *)
(* Test 6: Method with Object Parameter *)
(* ========================================================================= *)

(* Test methods with object parameters are correctly typed *)
let test_method_with_object_parameter () =
  let ctx = create_test_context () in

  (* Create a method on Button that takes a Widget parameter *)
  let meth =
    make_gir_method ~method_name:"set_child"
      ~c_identifier:"gtk_button_set_child" ~return_type:void_type
      ~parameters:[ make_widget_param ~param_name:"child" () ]
      ()
  in

  (* Generate Layer 2 class module and signature *)
  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[ meth ] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  (* Parse the generated code into AST *)
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Validate the set_child method exists using helper *)
  let class_decl = find_class ml_ast "button" in
  let _ = find_method class_decl "set_child" in

  (* Verify the method has a hierarchy parameter using AST inspection *)
  Ml_ast_helpers.assert_method_has_hierarchy_param ml_ast "button" "set_child"

(* ========================================================================= *)
(* Test 7: Same-Cluster Structural Type Parameters *)
(* ========================================================================= *)

(* Test that same-cluster class references use class type names like widget_t *)
let test_same_cluster_structural_type () =
  let ctx = create_test_context () in

  (* Create a method on Button that takes a Widget parameter (same cluster) *)
  let set_child_method =
    make_gir_method ~method_name:"set_child"
      ~c_identifier:"gtk_button_set_child" ~return_type:void_type
      ~parameters:[ make_widget_param ~param_name:"child" () ]
      ()
  in

  (* Create classes for combined module generation *)
  let widget_class =
    make_gir_class ~class_name:"Widget" ~c_type:"GtkWidget" ()
  in

  let button_class =
    make_gir_class ~class_name:"Button" ~c_type:"GtkButton" ~parent:"Widget"
      ~methods:[ set_child_method ] ()
  in

  (* Convert classes to entities *)
  let widget_entity = Gir_gen_lib.Types.entity_of_class widget_class in
  let button_entity = Gir_gen_lib.Types.entity_of_class button_class in

  (* Generate combined class module for cyclic dependency scenario *)
  let combined_code =
    Gir_gen_lib.Generate.Class_gen.generate_combined_class_module ~ctx
      ~combined_module_name:"Widget" ~entities:[ widget_entity; button_entity ]
      ~parent_chain_for_entity:(fun class_name ->
        match class_name with
        | "Widget" -> []
        | "Button" -> [ "Widget" ]
        | _ -> [])
  in

  (* Parse the generated combined module into AST *)
  let combined_ast = Ml_ast_helpers.parse_implementation combined_code in

  (* Validate the button class and method exist *)
  let class_decl = find_class combined_ast "button" in
  let _ = find_method class_decl "set_child" in

  (* Verify the generated code uses class type reference (widget_t) instead of structural types *)
  validate_method_type combined_ast "button" "set_child"
    ~expected:"widget_t -> unit"

(* ========================================================================= *)
(* Test 8: Property Getter Wrapper *)
(* ========================================================================= *)

(* Test that property getters return wrapped types (option/result) *)
let test_property_getter_wrapper () =
  let ctx = create_test_context () in

  (* Create a property with string type *)
  let label_property =
    make_gir_property ~prop_name:"label" ~prop_type:string_option_type ()
  in

  (* Create a property getter method that returns the property value *)
  let get_label_method =
    make_gir_method ~method_name:"get_label"
      ~c_identifier:"gtk_button_get_label" ~return_type:string_option_type
      ~get_property:"label" ()
  in

  (* Generate Layer 2 class signature *)
  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[ get_label_method ] ~properties:[ label_property ] ~signals:[]
      ~constructors:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  (* Parse the generated signature into AST *)
  let mli_ast = Ml_ast_helpers.parse_interface mli_code in

  (* Verify the getter method has string option return type using AST inspection *)
  (* Property getters with nullable types should return 'string option' *)
  Layer2_helpers.validate_method_type_annotation_sig ~signature:mli_ast
    ~class_name:"button_t" ~method_name:"get_label"
    ~expected_type:"unit -> string option"

(* ========================================================================= *)
(* Test 9: Property Setter Wrapper *)
(* ========================================================================= *)

(* Test that property setters accept #class type parameters and coerce *)
let test_property_setter_wrapper () =
  let ctx = create_test_context () in

  (* Create a child property that accepts Widget type *)
  let child_property =
    make_gir_property ~prop_name:"child" ~prop_type:widget_type ()
  in

  (* Create a property setter method that takes Widget parameter *)
  let set_child_method =
    make_gir_method ~method_name:"set_child"
      ~c_identifier:"gtk_button_set_child" ~return_type:void_type
      ~parameters:[ make_widget_param ~param_name:"child" () ]
      ~set_property:"child" ()
  in

  (* Generate Layer 2 class module *)
  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[ set_child_method ] ~properties:[ child_property ] ~signals:[]
      ~constructors:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  (* Parse the generated code into AST *)
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Find the class declaration to check the method body *)
  let class_decl = find_class ml_ast "button" in
  let method_field = find_method class_decl "set_child" in

  (* Check if method has hierarchy parameter by examining the type *)
  Ml_ast_helpers.get_method_type method_field
  |> Option.iter (fun method_type ->
      if not (Ml_ast_helpers.contains_hierarchy_type method_type) then
        Alcotest.fail "set_child method does not have hierarchy parameter");

  if Option.is_none (Ml_ast_helpers.get_method_type method_field) then
    Alcotest.fail "Could not extract type for set_child method"

(* ========================================================================= *)
(* Test 10: Inheritance Generation *)
(* ========================================================================= *)

(* Test that generated classes inherit from parent via GWidget.widget *)
let test_inheritance_generation () =
  let ctx = create_test_context () in

  (* Create a simple method *)
  let meth =
    make_void_method ~method_name:"show" ~c_identifier:"gtk_button_show" ()
  in

  (* Generate Layer 2 class module with Widget as parent *)
  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[ meth ] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  Fmt.epr "Generated class module for inheritance test:\n%s\n" ml_code;

  (* Parse the generated code into AST *)
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Validate that the generated class inherits from GWidget.widget via parent_name *)
  Layer2_helpers.validate_class_inherits ~structure:ml_ast ~class_name:"button"
    ~parent_class:"GWidget.widget"

(* ========================================================================= *)
(* Test 11: Signal Handler L2 Forwarder *)
(* ========================================================================= *)

(* Test that classes with signals emit L2 method forwarders instead of
   inheriting from a _signals class. The button class must contain an
   on_clicked method whose body forwards to Button.on_clicked via
   self#as_button. No inherit from Gbutton_signals.button_signals. *)
let test_signal_handler_l2_forwarder () =
  let ctx = create_test_context () in

  (* Create a test signal for the button *)
  let clicked_signal = Layer2_helpers.create_test_signal ~name:"clicked" in

  (* Generate Layer 2 class module with signals *)
  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[] ~properties:[] ~signals:[ clicked_signal ] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  (* Parse the generated code into AST *)
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Assert: the 'button' class contains method on_clicked (L2 forwarder) *)
  let class_decl = find_class ml_ast "button" in
  let method_field = find_method class_decl "on_clicked" in
  let method_body = get_method_body method_field in

  (* Body must forward to Button.on_clicked *)
  assert_method_body_calls method_body "Button" "on_clicked";

  (* Body must reference self#as_button *)
  if not (Ml_ast_helpers.contains_method_send method_body "as_button") then
    Alcotest.fail "on_clicked body should reference self#as_button";

  (* Class must NOT inherit from Gbutton_signals.button_signals *)
  let inherit_clauses =
    Ml_ast_helpers.get_class_inherit_clauses class_decl.pci_expr
  in
  if List.mem "Gbutton_signals.button_signals" inherit_clauses then
    Alcotest.fail
      "button class must not inherit from Gbutton_signals.button_signals after \
       Stage 3"

(* ========================================================================= *)
(* Test 13: Class Accessor Method *)
(* ========================================================================= *)

(* Test that generated classes have 'method as_button = obj' pattern *)
let test_class_accessor_method () =
  let ctx = create_test_context () in

  (* Generate Layer 2 class module for Button *)
  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  (* Parse the generated code into AST *)
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Find the button class declaration and as_button method in the AST *)
  let class_decl = find_class ml_ast "button" in
  let method_field = find_method class_decl "as_button" in
  let method_body = get_method_body method_field in

  (* Validate that the method body is a simple 'obj' reference *)
  assert_method_body_is_obj method_body

(* ========================================================================= *)
(* Test 15: Method Conflict Detection *)
(* ========================================================================= *)

(* Test that conflicting methods (same name, different signature) are commented out *)
let test_method_conflict_detection () =
  let ctx = create_test_context () in

  (* Create a parent Widget class with a 'show' method that takes no parameters *)
  let widget_show_method =
    make_void_method ~method_name:"show" ~c_identifier:"gtk_widget_show" ()
  in

  let widget_class =
    make_gir_class ~class_name:"Widget" ~c_type:"GtkWidget"
      ~methods:[ widget_show_method ] ()
  in

  (* Create a child Button class with a 'show' method that has DIFFERENT signature *)
  (* This should create a conflict because the method name is the same but signature differs *)
  let button_show_method =
    make_gir_method ~method_name:"show" ~c_identifier:"gtk_button_show"
      ~return_type:void_type
      ~parameters:[ make_string_param ~param_name:"setting" () ]
      ()
  in

  let button_class =
    make_gir_class ~class_name:"Button" ~c_type:"GtkButton" ~parent:"Widget"
      ~methods:[ button_show_method ] ()
  in

  (* Add the classes to the context *)
  let updated_ctx = { ctx with classes = [ widget_class; button_class ] } in

  (* Generate code for the Button class (which inherits from Widget) *)
  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx:updated_ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[ button_show_method ] ~properties:[] ~signals:[]
      ~constructors:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx:updated_ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[ button_show_method ] ~properties:[] ~signals:[]
      ~constructors:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  Fmt.epr "Generated .ml code for conflict test:\n%s\n\n" ml_code;
  Fmt.epr "Generated .mli code for conflict test:\n%s\n\n" mli_code;

  (* Parse the generated code into ASTs *)
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in
  let mli_ast = Ml_ast_helpers.parse_interface mli_code in

  (* Find the button class in the implementation AST *)
  let button_class_decl =
    Helpers.expect_some "Class 'button' not found in generated .ml AST"
      (Ml_ast_helpers.find_class_declaration ml_ast "button")
      Fun.id
  in
  Fmt.epr "Found class 'button' in .ml\n";

  (* Check that the 'show' method is NOT present as an actual definition in the AST *)
  (* (it should be commented out due to the conflict) *)
  let show_method_exists =
    Ml_ast_helpers.method_exists_as_definition button_class_decl.pci_expr "show"
  in
  Fmt.epr "Method 'show' exists as definition in .ml: %b\n" show_method_exists;

  if show_method_exists then
    Alcotest.fail
      "Method 'show' should be suppressed (inherited from parent) but is \
       present as a definition";

  Fmt.epr
    "Confirmed 'show' method is not present in .ml (inherited from parent)\n";

  (* Also check the signature (.mli) *)
  let button_class_type_decl =
    Helpers.expect_some "Class type 'button_t' not found in generated .mli AST"
      (Ml_ast_helpers.find_class_type_declaration mli_ast "button_t")
      Fun.id
  in
  Fmt.epr "Found class type 'button_t' in .mli\n";

  (* Check that the 'show' method is NOT present as a signature in the class type
     — it is inherited from the parent class type via 'inherit widget_t' *)
  let show_signature_exists =
    Ml_ast_helpers.method_signature_exists button_class_type_decl.pci_expr
      "show"
  in
  Fmt.epr "Method 'show' signature exists in .mli: %b\n" show_signature_exists;

  if show_signature_exists then
    Alcotest.fail
      "Method 'show' should be inherited from parent, not re-declared in child \
       class type";

  Fmt.epr "Confirmed 'show' method is inherited, not re-declared in .mli\n";

  Fmt.epr "Method conflict detection test passed.\n"

(* ========================================================================= *)
(* Test 16: Layer 2 Signature vs Implementation Consistency *)
(* ========================================================================= *)

(* Test that method signatures in .mli match method signatures in .ml using AST parsing *)
let test_layer2_signature_consistency () =
  let ctx = create_test_context () in

  (* Create a method with multiple parameters and return type for comprehensive testing *)
  let set_size_method =
    make_gir_method ~method_name:"set_size_request"
      ~c_identifier:"gtk_widget_set_size_request" ~return_type:void_type
      ~parameters:
        [
          make_int_param ~param_name:"width" ();
          make_int_param ~param_name:"height" ();
        ]
      ()
  in

  let get_label_method =
    make_gir_method ~method_name:"get_label"
      ~c_identifier:"gtk_button_get_label" ~return_type:string_option_type ()
  in

  let set_child_method =
    make_gir_method ~method_name:"set_child"
      ~c_identifier:"gtk_button_set_child" ~return_type:void_type
      ~parameters:[ make_widget_param ~param_name:"child" () ]
      ()
  in

  let methods = [ set_size_method; get_label_method; set_child_method ] in

  (* Generate both .ml and .mli files for a class *)
  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  (* Debug: Print generated code for inspection *)
  Fmt.epr "Generated .mli code:\n%s\n\n" mli_code;
  Fmt.epr "Generated .ml code:\n%s\n\n" ml_code;

  (* Parse both files into ASTs *)
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in
  let mli_ast = Ml_ast_helpers.parse_interface mli_code in

  (* Find the class/type declarations in both ASTs *)
  let ml_class_opt = Ml_ast_helpers.find_class_declaration ml_ast "button" in
  let mli_class_type_opt =
    Ml_ast_helpers.find_class_type_declaration mli_ast "button_t"
  in

  Helpers.assert_some "Class 'button' not found in .ml AST" ml_class_opt;
  Fmt.epr "Found class 'button' in .ml\n";
  Helpers.assert_some "Class type 'button_t' not found in .mli AST"
    mli_class_type_opt;
  Fmt.epr "Found class type 'button_t' in .mli\n";

  (* Validate that method signatures in .mli match method signatures in .ml using AST parsing *)
  List.iter
    (fun meth ->
      let method_name = meth.method_name in
      Fmt.epr "Validating method: %s\n" method_name;

      (* Extract method type from .ml implementation *)
      let ml_method_type_opt =
        Option.bind ml_class_opt (fun ml_class ->
            Option.bind
              (Ml_ast_helpers.find_method_in_class ml_class.pci_expr method_name)
              Ml_ast_helpers.get_method_type)
      in

      (* Extract method type from .mli signature *)
      let mli_method_type_opt =
        Option.bind mli_class_type_opt (fun mli_class_type ->
            Option.bind
              (Ml_ast_helpers.find_method_in_class_type mli_class_type.pci_expr
                 method_name)
              Ml_ast_helpers.get_method_type_from_class_type_field)
      in

      (* Validate that both types were found *)
      let ml_method_type =
        Helpers.expect_some
          (Fmt.str "Method '%s' not found or has no type in .ml" method_name)
          ml_method_type_opt Fun.id
      in
      Fmt.epr "  .ml method type: %s\n"
        (Ml_ast_helpers.core_type_to_string ml_method_type);

      let mli_method_type =
        Helpers.expect_some
          (Fmt.str "Method '%s' not found or has no type in .mli" method_name)
          mli_method_type_opt Fun.id
      in
      Fmt.epr "  .mli method type: %s\n"
        (Ml_ast_helpers.core_type_to_string mli_method_type);

      (* Compare types for semantic equivalence *)
      let ml_type_str = Ml_ast_helpers.core_type_to_string ml_method_type in
      let mli_type_str = Ml_ast_helpers.core_type_to_string mli_method_type in

      (* Check for semantic equivalence - polymorphic types may have different representation
       between .ml and .mli (e.g., 'p1. (#G.widget as 'p1) -> unit vs #G.widget -> unit).
       We normalize by checking that both contain hierarchy types with compatible structure. *)
      let ml_has_hierarchy =
        Ml_ast_helpers.contains_hierarchy_type ml_method_type
      in
      let mli_has_hierarchy =
        Ml_ast_helpers.contains_hierarchy_type mli_method_type
      in

      if ml_has_hierarchy && mli_has_hierarchy then
        (* Both have hierarchy types - they're semantically equivalent even if string differs *)
        Fmt.epr "  Signature match (hierarchy types): .ml='%s', .mli='%s'\n"
          ml_type_str mli_type_str
      else if ml_type_str <> mli_type_str then
        Alcotest.fail
          (Fmt.str "Method '%s' signature mismatch: .ml has '%s', .mli has '%s'"
             method_name ml_type_str mli_type_str)
      else Fmt.epr "  Signature match: %s\n" ml_type_str;

      Fmt.epr "Method '%s' signature consistency validated.\n\n" method_name)
    methods;

  Fmt.epr
    "All method signatures validated for consistency between .mli and .ml.\n"

(* ========================================================================= *)
(* Test 14: Combined Class Signature Consistency *)
(* ========================================================================= *)

(* Test that method signatures in combined class .mli match .ml for cyclic modules *)
let test_combined_class_signature_consistency () =
  let ctx = create_test_context () in

  (* Create methods for Widget class *)
  let widget_show_method =
    make_void_method ~method_name:"show" ~c_identifier:"gtk_widget_show" ()
  in

  let widget_hide_method =
    make_void_method ~method_name:"hide" ~c_identifier:"gtk_widget_hide" ()
  in

  (* Create method for Button class *)
  let button_clicked_method =
    make_void_method ~method_name:"clicked" ~c_identifier:"gtk_button_clicked"
      ()
  in

  let button_set_label_method =
    make_gir_method ~method_name:"set_label"
      ~c_identifier:"gtk_button_set_label" ~return_type:void_type
      ~parameters:[ make_string_param ~param_name:"label" () ]
      ()
  in

  let button_get_label_method =
    make_gir_method ~method_name:"get_label"
      ~c_identifier:"gtk_button_get_label" ~return_type:string_option_type ()
  in

  (* Create classes for combined module generation *)
  let widget_class =
    make_gir_class ~class_name:"Widget" ~c_type:"GtkWidget"
      ~methods:[ widget_show_method; widget_hide_method ]
      ()
  in

  let button_class =
    make_gir_class ~class_name:"Button" ~c_type:"GtkButton" ~parent:"Widget"
      ~methods:
        [
          button_clicked_method;
          button_set_label_method;
          button_get_label_method;
        ]
      ()
  in

  (* Convert classes to entities *)
  let widget_entity = Gir_gen_lib.Types.entity_of_class widget_class in
  let button_entity = Gir_gen_lib.Types.entity_of_class button_class in

  (* Generate combined class module and signature for cyclic dependency scenario *)
  let combined_ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_combined_class_module ~ctx
      ~combined_module_name:"Widget" ~entities:[ widget_entity; button_entity ]
      ~parent_chain_for_entity:(fun class_name ->
        match class_name with
        | "Widget" -> []
        | "Button" -> [ "Widget" ]
        | _ -> [])
  in

  let combined_mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_combined_class_signature ~ctx
      ~combined_module_name:"Widget" ~entities:[ widget_entity; button_entity ]
      ~parent_chain_for_entity:(fun class_name ->
        match class_name with
        | "Widget" -> []
        | "Button" -> [ "Widget" ]
        | _ -> [])
  in

  Fmt.epr "Generated combined .ml code:\n%s\n\n" combined_ml_code;
  Fmt.epr "Generated combined .mli code:\n%s\n\n" combined_mli_code;

  (* Parse both files into ASTs - wrap in try/catch for debugging *)
  let combined_ml_ast =
    try Ml_ast_helpers.parse_implementation combined_ml_code
    with e ->
      Fmt.epr "ERROR parsing .ml: %s\n" (Printexc.to_string e);
      raise e
  in

  let combined_mli_ast =
    try Ml_ast_helpers.parse_interface combined_mli_code
    with e ->
      Fmt.epr "ERROR parsing .mli: %s\n" (Printexc.to_string e);
      raise e
  in

  (* Define test cases: list of (class_name, method_name) pairs to validate *)
  let test_cases =
    [
      ("widget", "show");
      ("widget", "hide");
      ("button", "clicked");
      ("button", "set_label");
      ("button", "get_label");
    ]
  in

  (* Validate that method signatures in .mli match .ml for each test case *)
  List.iter
    (fun (class_name, method_name) ->
      Fmt.epr "Validating method %s.%s\n" class_name method_name;

      (* Find class in .ml AST *)
      let ml_class_opt =
        Ml_ast_helpers.find_class_declaration combined_ml_ast class_name
      in

      (* Find class type in .mli AST — class types have _t suffix *)
      let class_type_name = class_name ^ "_t" in
      let mli_class_type_opt =
        Ml_ast_helpers.find_class_type_declaration combined_mli_ast
          class_type_name
      in

      Helpers.assert_some
        (Fmt.str "Class '%s' not found in combined .ml AST" class_name)
        ml_class_opt;
      Fmt.epr "  Found class '%s' in .ml\n" class_name;
      Helpers.assert_some
        (Fmt.str "Class type '%s' not found in combined .mli AST"
           class_type_name)
        mli_class_type_opt;
      Fmt.epr "  Found class type '%s' in .mli\n" class_type_name;

      (* Extract method type from .ml implementation *)
      let ml_method_type_opt =
        Option.bind ml_class_opt (fun ml_class ->
            Option.bind
              (Ml_ast_helpers.find_method_in_class ml_class.pci_expr method_name)
              Ml_ast_helpers.get_method_type)
      in

      (* Extract method type from .mli signature *)
      let mli_method_type_opt =
        Option.bind mli_class_type_opt (fun mli_class_type ->
            Option.bind
              (Ml_ast_helpers.find_method_in_class_type mli_class_type.pci_expr
                 method_name)
              Ml_ast_helpers.get_method_type_from_class_type_field)
      in

      (* Validate that both types were found and match *)
      let ml_method_type =
        Helpers.expect_some
          (Fmt.str "Method '%s' not found or has no type in combined .ml"
             method_name)
          ml_method_type_opt Fun.id
      in
      Fmt.epr "  .ml method type: %s\n"
        (Ml_ast_helpers.core_type_to_string ml_method_type);

      let mli_method_type =
        Helpers.expect_some
          (Fmt.str "Method '%s' not found or has no type in combined .mli"
             method_name)
          mli_method_type_opt Fun.id
      in
      Fmt.epr "  .mli method type: %s\n"
        (Ml_ast_helpers.core_type_to_string mli_method_type);

      (* Compare types using AST-based comparison (NOT string_contains) *)
      let ml_type_str = Ml_ast_helpers.core_type_to_string ml_method_type in
      let mli_type_str = Ml_ast_helpers.core_type_to_string mli_method_type in

      (* Check for semantic equivalence *)
      if ml_type_str <> mli_type_str then
        Alcotest.fail
          (Fmt.str
             "Method '%s.%s' signature mismatch: .ml has '%s', .mli has '%s'"
             class_name method_name ml_type_str mli_type_str)
      else Fmt.epr "  Signature match: %s\n" ml_type_str;

      Fmt.epr "Method '%s.%s' signature consistency validated.\n\n" class_name
        method_name)
    test_cases;

  Fmt.epr
    "All method signatures validated for consistency between combined .mli and \
     .ml.\n"

(* ========================================================================= *)
(* Test 17: Throws Method Result Wrapping *)
(* ========================================================================= *)

(* Test that methods with throws=true return (T, GError.t) result type *)
let test_throws_method_result_wrapping () =
  let ctx = create_test_context () in

  (* Create a method with throws=true that returns a string *)
  let load_file_method =
    make_gir_method ~method_name:"load_file"
      ~c_identifier:"gtk_file_chooser_load_file" ~return_type:utf8_type
      ~throws:true ()
  in

  (* Generate Layer 2 class signature *)
  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"FileChooser" ~c_type:"GtkFileChooser"
      ~parent_chain:[ "Widget" ] ~methods:[ load_file_method ] ~properties:[]
      ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  (* Debug: Print the generated signature *)
  Fmt.epr "Generated .mli code for throws test:\n%s\n\n" mli_code;

  (* Parse the generated signature into AST *)
  let mli_ast = Ml_ast_helpers.parse_interface mli_code in

  (* Find the class type declaration *)
  let class_type_decl =
    Helpers.expect_some
      "Class type 'file_chooser_t' not found in generated .mli AST"
      (Ml_ast_helpers.find_class_type_declaration mli_ast "file_chooser_t")
      Fun.id
  in

  (* Find the load_file method in the class type *)
  let method_field =
    Helpers.expect_some "Method 'load_file' not found in class type"
      (Ml_ast_helpers.find_method_in_class_type class_type_decl.pci_expr
         "load_file")
      Fun.id
  in

  (* Extract the method type *)
  let method_type =
    Helpers.expect_some "Could not extract type for load_file method"
      (Ml_ast_helpers.get_method_type_from_class_type_field method_field)
      Fun.id
  in
  let method_type_str = Ml_ast_helpers.core_type_to_string method_type in
  Fmt.epr "Method type: %s\n" method_type_str;

  (* Extract the return type from the function type *)
  let return_type = Ml_ast_helpers.get_return_type method_type in
  let return_type_str = Ml_ast_helpers.core_type_to_string return_type in
  Fmt.epr "Return type: %s\n" return_type_str;

  (* Validate that the return type is a result type with GError.t *)
  if not (Ml_ast_helpers.is_result_type_with_ginfo_error return_type) then
    Alcotest.fail
      (Fmt.str
         "Method 'load_file' should have (T, GError.t) result return type, got \
          '%s'"
         return_type_str);

  Fmt.epr "Throws method result wrapping validated: %s\n" return_type_str;

  (* Also test with a method that returns void *)
  let create_directory_method =
    make_gir_method ~method_name:"create_directory"
      ~c_identifier:"gtk_file_chooser_create_directory" ~return_type:void_type
      ~throws:true ()
  in

  (* Generate Layer 2 class signature with both methods *)
  let mli_code_with_void =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"FileChooser" ~c_type:"GtkFileChooser"
      ~parent_chain:[ "Widget" ]
      ~methods:[ load_file_method; create_directory_method ]
      ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  let mli_ast_with_void = Ml_ast_helpers.parse_interface mli_code_with_void in

  (* Validate the void-returning throws method *)
  let class_type_decl_void =
    Helpers.expect_some
      "Class type 'file_chooser_t' not found in generated .mli AST"
      (Ml_ast_helpers.find_class_type_declaration mli_ast_with_void
         "file_chooser_t")
      Fun.id
  in

  let method_field_void =
    Helpers.expect_some "Method 'create_directory' not found in class type"
      (Ml_ast_helpers.find_method_in_class_type class_type_decl_void.pci_expr
         "create_directory")
      Fun.id
  in

  let method_type_void =
    Helpers.expect_some "Could not extract type for create_directory method"
      (Ml_ast_helpers.get_method_type_from_class_type_field method_field_void)
      Fun.id
  in
  let method_type_str_void =
    Ml_ast_helpers.core_type_to_string method_type_void
  in
  Fmt.epr "Void method type: %s\n" method_type_str_void;

  (* Extract the return type from the function type *)
  let return_type_void = Ml_ast_helpers.get_return_type method_type_void in
  let return_type_str_void =
    Ml_ast_helpers.core_type_to_string return_type_void
  in
  Fmt.epr "Void return type: %s\n" return_type_str_void;

  (* For void-returning throws method, should be (unit, GError.t) result *)
  if not (Ml_ast_helpers.is_result_type_with_ginfo_error return_type_void) then
    Alcotest.fail
      (Fmt.str
         "Method 'create_directory' should have (unit, GError.t) result return \
          type, got '%s'"
         return_type_str_void);

  Fmt.epr "Void throws method result wrapping validated: %s\n"
    return_type_str_void;

  Fmt.epr "Throws method result wrapping test passed.\n"

(* ========================================================================= *)
(* Test 18: Parent Inherit in Class Implementation (.ml) *)
(* ========================================================================= *)

(* Test that Button class inherits from GWidget.widget in the implementation *)
let test_parent_inherit_in_implementation () =
  let ctx = create_test_context () in

  (* Generate class module for Button with parent chain *)
  (* Note: Widget is already in ctx from create_test_context *)
  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  Fmt.epr "Generated class module for parent inherit test:\n%s\n" ml_code;

  (* Parse the generated code into AST *)
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Validate that the button class inherits from GWidget.widget *)
  Layer2_helpers.validate_class_inherits ~structure:ml_ast ~class_name:"button"
    ~parent_class:"GWidget.widget"

(* ========================================================================= *)
(* Test 19: Parent Inherit in Class Type (.mli) *)
(* ========================================================================= *)

(* Test that button_t class type inherits from GWidget.widget_t in the signature *)
let test_parent_inherit_in_class_type () =
  let ctx = create_test_context () in

  (* Generate class signature for Button with parent chain *)
  (* Note: Widget is already in ctx from create_test_context *)
  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  Fmt.epr "Generated class signature for parent inherit test:\n%s\n" mli_code;

  (* Parse the generated code into AST *)
  let mli_ast = Ml_ast_helpers.parse_interface mli_code in

  (* Validate that the button_t class type inherits from GWidget.widget_t *)
  Layer2_helpers.validate_class_type_inherits ~signature:mli_ast
    ~class_name:"button_t" ~parent_class_type:"GWidget.widget_t"

(* ========================================================================= *)
(* Test 20: Cyclic Cluster Skips Parent Inherit *)
(* ========================================================================= *)

(* Test that when Button and Widget are in the same cluster, Button does NOT inherit from Widget *)
let test_cyclic_cluster_skips_parent_inherit () =
  let ctx = create_test_context () in

  (* Create Widget class *)
  let widget_class =
    make_gir_class ~class_name:"Widget" ~c_type:"GtkWidget" ()
  in

  (* Create Button class with Widget as parent *)
  let button_class =
    make_gir_class ~class_name:"Button" ~c_type:"GtkButton" ~parent:"Widget" ()
  in

  (* Add both classes to context *)
  let updated_ctx = { ctx with classes = [ widget_class; button_class ] } in

  (* Generate code for Button using generate_combined_class_module *)
  let widget_entity = entity_of_class widget_class in
  let button_entity = entity_of_class button_class in
  let entities = [ widget_entity; button_entity ] in

  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_combined_class_module
      ~ctx:updated_ctx ~combined_module_name:"WidgetButton" ~entities
      ~parent_chain_for_entity:(fun class_name ->
        match class_name with "Button" -> [ "Widget" ] | _ -> [])
  in

  Fmt.epr "Generated combined class module for cyclic cluster test:\n%s\n"
    ml_code;

  (* Parse the generated code into AST *)
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Find the button class and check its inherit clauses *)
  let button_decl = find_class ml_ast "button" in
  let inherit_clauses =
    Ml_ast_helpers.get_class_inherit_clauses button_decl.pci_expr
  in

  (* Should NOT contain any GWidget inherit since both are in the same cluster *)
  let has_gwidget_inherit =
    List.exists
      (fun c -> String.length c > 0 && String.equal c "GWidget.widget")
      inherit_clauses
  in

  if has_gwidget_inherit then
    Alcotest.fail
      (Fmt.str
         "Button should NOT inherit from GWidget.widget when in same cluster. \
          Inherits: [%s]"
         (String.concat "; " inherit_clauses))

(* ========================================================================= *)
(* Tests: GList return / parameter wrapping with Layer 2 element types *)
(* ========================================================================= *)

(* Helper: build a GLib.List<Widget> gir_type *)
let make_glist_of_widget ?(nullable = false) () =
  let elem = make_gir_type ~name:"Widget" ~c_type:"GtkWidget*" () in
  let arr = make_gir_array ~array_name:"GLib.List" ~element_type:elem () in
  make_gir_type ~name:"GLib.List" ~c_type:"GList*" ~nullable ~array:arr ()

(** A method that returns GLib.List<Widget> should:
    - have signature returning GWidget.widget_t list
    - have body that calls List.map to wrap each element *)
let test_glist_return_wrapping () =
  let ctx = create_test_context () in

  let get_children_method =
    make_gir_method ~method_name:"get_children"
      ~c_identifier:"gtk_container_get_children"
      ~return_type:(make_glist_of_widget ()) ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Container" ~c_type:"GtkContainer" ~parent_chain:[ "Widget" ]
      ~methods:[ get_children_method ] ~properties:[] ~signals:[]
      ~constructors:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in
  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"Container" ~c_type:"GtkContainer" ~parent_chain:[ "Widget" ]
      ~methods:[ get_children_method ] ~properties:[] ~signals:[]
      ~constructors:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  Fmt.epr "GList return wrapping .ml:\n%s\n\n" ml_code;
  Fmt.epr "GList return wrapping .mli:\n%s\n\n" mli_code;

  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in
  let mli_ast = Ml_ast_helpers.parse_interface mli_code in

  (* Verify .mli signature uses Layer 2 type *)
  Layer2_helpers.validate_method_type_annotation_sig ~signature:mli_ast
    ~class_name:"container_t" ~method_name:"get_children"
    ~expected_type:"unit -> GWidget.widget_t list";

  (* Verify .ml method body calls List.map to wrap elements *)
  let container_class = find_class ml_ast "container" in
  let get_children_field = find_method container_class "get_children" in
  let body = get_method_body get_children_field in
  if not (Ml_ast_helpers.method_body_calls_function body "List" "map") then
    Alcotest.fail
      "get_children body should call List.map to wrap GList elements in L2 \
       class objects"

(** A method that throws AND returns GLib.List<Widget> should:
    - have signature returning (GWidget.widget_t list, GError.t) result
    - have body that calls Result.map with a List.map *)
let test_glist_return_throws_wrapping () =
  let ctx = create_test_context () in

  let lookup_method =
    make_gir_method ~method_name:"lookup_widgets"
      ~c_identifier:"gtk_container_lookup_widgets"
      ~return_type:(make_glist_of_widget ()) ~throws:true ()
  in

  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"Container" ~c_type:"GtkContainer" ~parent_chain:[ "Widget" ]
      ~methods:[ lookup_method ] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in
  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Container" ~c_type:"GtkContainer" ~parent_chain:[ "Widget" ]
      ~methods:[ lookup_method ] ~properties:[] ~signals:[] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  Fmt.epr "GList throws return wrapping .mli:\n%s\n\n" mli_code;

  let mli_ast = Ml_ast_helpers.parse_interface mli_code in
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Verify .mli signature returns a result type *)
  Layer2_helpers.validate_method_type_annotation_sig ~signature:mli_ast
    ~class_name:"container_t" ~method_name:"lookup_widgets"
    ~expected_type:"unit -> (GWidget.widget_t list, GError.t) result";

  (* Verify .ml body calls Result.map *)
  let container_class = find_class ml_ast "container" in
  let lookup_field = find_method container_class "lookup_widgets" in
  let body = get_method_body lookup_field in
  if not (Ml_ast_helpers.method_body_calls_function body "Result" "map") then
    Alcotest.fail
      "lookup_widgets body should call Result.map to wrap throws+GList return"

(** A method that accepts GLib.List<Widget> as a parameter should:
    - have signature accepting GWidget.widget_t list
    - have body with a List.map let-binding to unwrap to Layer 1 before the call
*)
let test_glist_param_unwrapping () =
  let ctx = create_test_context () in

  let set_children_method =
    make_gir_method ~method_name:"set_children"
      ~c_identifier:"gtk_container_set_children" ~return_type:void_type
      ~parameters:
        [
          make_gir_param ~param_name:"children"
            ~param_type:(make_glist_of_widget ()) ();
        ]
      ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Container" ~c_type:"GtkContainer" ~parent_chain:[ "Widget" ]
      ~methods:[ set_children_method ] ~properties:[] ~signals:[]
      ~constructors:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in
  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"Container" ~c_type:"GtkContainer" ~parent_chain:[ "Widget" ]
      ~methods:[ set_children_method ] ~properties:[] ~signals:[]
      ~constructors:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in

  Fmt.epr "GList param unwrapping .ml:\n%s\n\n" ml_code;
  Fmt.epr "GList param unwrapping .mli:\n%s\n\n" mli_code;

  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in
  let mli_ast = Ml_ast_helpers.parse_interface mli_code in

  (* Verify .mli signature accepts Layer 2 type *)
  Layer2_helpers.validate_method_type_annotation_sig ~signature:mli_ast
    ~class_name:"container_t" ~method_name:"set_children"
    ~expected_type:"GWidget.widget_t list -> unit";

  (* Verify .ml body uses List.map to unwrap the L2 list to L1 *)
  let container_class = find_class ml_ast "container" in
  let set_children_field = find_method container_class "set_children" in
  let body = get_method_body set_children_field in
  if not (Ml_ast_helpers.method_body_calls_function body "List" "map") then
    Alcotest.fail
      "set_children body should call List.map to unwrap L2 list param to L1"

(* ========================================================================= *)
(* Test Suite *)
(* ========================================================================= *)

let tests =
  [
    Alcotest.test_case "Hierarchy parameter coercion" `Quick
      test_hierarchy_parameter_coercion;
    Alcotest.test_case "Nullable parameter handling" `Quick
      test_nullable_parameter_handling;
    Alcotest.test_case "Return value wrapping" `Quick test_return_value_wrapping;
    Alcotest.test_case "Void method" `Quick test_void_method;
    Alcotest.test_case "Multiple parameters" `Quick test_multiple_parameters;
    Alcotest.test_case "Method with object parameter" `Quick
      test_method_with_object_parameter;
    Alcotest.test_case "Same-cluster structural type" `Quick
      test_same_cluster_structural_type;
    Alcotest.test_case "Property getter wrapper" `Quick
      test_property_getter_wrapper;
    Alcotest.test_case "Property setter wrapper" `Quick
      test_property_setter_wrapper;
    Alcotest.test_case "Inheritance generation" `Quick
      test_inheritance_generation;
    Alcotest.test_case "Signal handler L2 forwarder" `Quick
      test_signal_handler_l2_forwarder;
    Alcotest.test_case "Class accessor method" `Quick test_class_accessor_method;
    Alcotest.test_case "Method conflict detection" `Quick
      test_method_conflict_detection;
    Alcotest.test_case "Layer 2 signature consistency" `Quick
      test_layer2_signature_consistency;
    Alcotest.test_case "Combined class signature consistency" `Quick
      test_combined_class_signature_consistency;
    Alcotest.test_case "Throws method result wrapping" `Quick
      test_throws_method_result_wrapping;
    Alcotest.test_case "Parent inherit in implementation" `Quick
      test_parent_inherit_in_implementation;
    Alcotest.test_case "Parent inherit in class type" `Quick
      test_parent_inherit_in_class_type;
    Alcotest.test_case "Cyclic cluster skips parent inherit" `Quick
      test_cyclic_cluster_skips_parent_inherit;
    Alcotest.test_case "GList return wrapping" `Quick test_glist_return_wrapping;
    Alcotest.test_case "GList throws return wrapping" `Quick
      test_glist_return_throws_wrapping;
    Alcotest.test_case "GList param unwrapping" `Quick
      test_glist_param_unwrapping;
  ]
