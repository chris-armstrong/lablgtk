(* External Declaration Tests - Validates external function declarations in generated ML *)

let create_test_context = Helpers.create_test_context

(* ========================================================================= *)
(* Test: Method with Multiple Parameters *)
(* ========================================================================= *)

let test_method_multiple_params () =
  let ctx = create_test_context () in

  let meth =
    Type_factory.make_gir_method ~method_name:"set_range"
      ~c_identifier:"gtk_adjustment_set_range"
      ~return_type:Type_factory.void_type
      ~parameters:
        [
          Type_factory.make_gir_param ~param_name:"lower"
            ~param_type:Type_factory.gdouble_type ();
          Type_factory.make_gir_param ~param_name:"upper"
            ~param_type:Type_factory.gdouble_type ();
        ]
      ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Adjustment" ~class_doc:None
      ~c_type:"GtkAdjustment" ~parent_chain:[ "Widget" ] ~constructors:None
      ~methods:[ meth ] ~properties:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ast = Ml_ast_helpers.parse_implementation ml_code in

  Ml_validation.assert_external_exists ast "set_range";
  let ext = Option.get (Ml_ast_helpers.find_external ast "set_range") in

  (* Should have 3 parameters: self + lower + upper *)
  Ml_validation.assert_param_count ext 3;

  (* Validate parameter types *)
  Ml_validation.assert_param_type ext 0 "t";
  (* self *)
  Ml_validation.assert_param_type ext 1 "float";
  (* lower *)
  Ml_validation.assert_param_type ext 2 "float";

  (* upper *)

  (* Validate return type *)
  Ml_validation.assert_return_type ext "unit"

(* ========================================================================= *)
(* Test: Method with Object Parameter *)
(* ========================================================================= *)

let test_method_with_object_param () =
  let ctx = create_test_context () in

  let meth =
    Type_factory.make_gir_method ~method_name:"set_child"
      ~c_identifier:"gtk_window_set_child" ~return_type:Type_factory.void_type
      ~parameters:
        [
          Type_factory.make_gir_param ~param_name:"child"
            ~param_type:Type_factory.widget_type ();
        ]
      ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Window" ~class_doc:None
      ~c_type:"GtkWindow" ~parent_chain:[ "Widget" ] ~constructors:None
      ~methods:[ meth ] ~properties:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ast = Ml_ast_helpers.parse_implementation ml_code in

  Ml_validation.assert_external_exists ast "set_child";
  let ext = Option.get (Ml_ast_helpers.find_external ast "set_child") in

  (* Should have 2 parameters: self + child *)
  Ml_validation.assert_param_count ext 2;

  (* Validate parameter types *)
  Ml_validation.assert_param_type ext 0 "t";
  (* self *)
  Ml_validation.assert_param_type ext 1 "Widget.t";

  (* child *)

  (* Validate return type *)
  Ml_validation.assert_return_type ext "unit"

(* ========================================================================= *)
(* Test: Method with Boolean Parameter *)
(* ========================================================================= *)

let test_method_with_bool_param () =
  let ctx = create_test_context () in

  let meth =
    Type_factory.make_gir_method ~method_name:"set_visible"
      ~c_identifier:"gtk_widget_set_visible" ~return_type:Type_factory.void_type
      ~parameters:[ Type_factory.make_bool_param ~param_name:"visible" () ]
      ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Widget" ~class_doc:None
      ~c_type:"GtkWidget" ~parent_chain:[] ~constructors:None ~methods:[ meth ]
      ~properties:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ast = Ml_ast_helpers.parse_implementation ml_code in

  Ml_validation.assert_external_exists ast "set_visible";
  let ext = Option.get (Ml_ast_helpers.find_external ast "set_visible") in

  Ml_validation.assert_param_count ext 2;
  Ml_validation.assert_external_c_name ext "ml_gtk_widget_set_visible";

  (* Validate parameter types *)
  Ml_validation.assert_param_type ext 0 "t";
  (* self *)
  Ml_validation.assert_param_type ext 1 "bool";

  (* visible *)

  (* Validate return type *)
  Ml_validation.assert_return_type ext "unit"

(* ========================================================================= *)
(* Test: Method with Integer Return *)
(* ========================================================================= *)

let test_method_with_int_return () =
  let ctx = create_test_context () in

  let meth =
    Type_factory.make_int_method ~method_name:"get_width"
      ~c_identifier:"gtk_widget_get_width" ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Widget" ~class_doc:None
      ~c_type:"GtkWidget" ~parent_chain:[] ~constructors:None ~methods:[ meth ]
      ~properties:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ast = Ml_ast_helpers.parse_implementation ml_code in

  Ml_validation.assert_external_exists ast "get_width";
  let ext = Option.get (Ml_ast_helpers.find_external ast "get_width") in

  (* Check it has 1 parameter (self only) *)
  Ml_validation.assert_param_count ext 1;

  (* Validate parameter types *)
  Ml_validation.assert_param_type ext 0 "t";

  (* self *)

  (* Validate return type *)
  Ml_validation.assert_return_type ext "int"

(* ========================================================================= *)
(* Test: Constructor with Multiple Parameters *)
(* ========================================================================= *)

let test_constructor_with_multiple_params () =
  let ctx = create_test_context () in

  let ctor =
    Type_factory.make_gir_constructor ~ctor_name:"new_with_label_and_mnemonic"
      ~c_identifier:"gtk_button_new_with_label_and_mnemonic"
      ~ctor_parameters:
        [
          Type_factory.make_string_param ~param_name:"label" ();
          Type_factory.make_bool_param ~param_name:"use_mnemonic" ();
        ]
      ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Button" ~class_doc:None
      ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~constructors:(Some [ ctor ]) ~methods:[] ~properties:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ast = Ml_ast_helpers.parse_implementation ml_code in

  Ml_validation.assert_external_exists ast "new_with_label_and_mnemonic";
  let ext =
    Option.get (Ml_ast_helpers.find_external ast "new_with_label_and_mnemonic")
  in

  (* Constructors don't have self parameter, should have 2 params *)
  Ml_validation.assert_param_count ext 2;

  (* Validate parameter types *)
  Ml_validation.assert_param_type ext 0 "string";
  (* label *)
  Ml_validation.assert_param_type ext 1 "bool";

  (* use_mnemonic *)

  (* Validate return type *)
  Ml_validation.assert_return_type ext "t"

(* ========================================================================= *)
(* Test: Method with Nullable Object Parameter *)
(* ========================================================================= *)

let test_method_with_nullable_object () =
  let ctx = create_test_context () in

  let meth =
    Type_factory.make_gir_method ~method_name:"set_parent"
      ~c_identifier:"gtk_widget_set_parent" ~return_type:Type_factory.void_type
      ~parameters:
        [
          Type_factory.make_gir_param ~param_name:"parent"
            ~param_type:
              (Type_factory.make_gir_type ~name:"Widget" ~c_type:"GtkWidget*"
                 ~nullable:true ())
            ~nullable:true ();
        ]
      ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Widget" ~class_doc:None
      ~c_type:"GtkWidget" ~parent_chain:[] ~constructors:None ~methods:[ meth ]
      ~properties:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ast = Ml_ast_helpers.parse_implementation ml_code in

  Ml_validation.assert_external_exists ast "set_parent";
  let ext = Option.get (Ml_ast_helpers.find_external ast "set_parent") in

  Ml_validation.assert_param_count ext 2;

  (* Validate parameter types *)
  Ml_validation.assert_param_type ext 0 "t";
  (* self *)
  Ml_validation.assert_param_type ext 1 "t option";

  (* nullable parent - same type as self *)

  (* Validate return type *)
  Ml_validation.assert_return_type ext "unit"

(* ========================================================================= *)
(* Test: Property Getter Method *)
(* ========================================================================= *)

let test_property_getter () =
  let ctx = create_test_context () in

  let meth =
    Type_factory.make_gir_method ~method_name:"get_label"
      ~c_identifier:"gtk_button_get_label" ~return_type:Type_factory.utf8_type
      ~get_property:"label" ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Button" ~class_doc:None
      ~c_type:"GtkButton" ~parent_chain:[ "Widget" ] ~constructors:None
      ~methods:[ meth ] ~properties:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ast = Ml_ast_helpers.parse_implementation ml_code in

  Ml_validation.assert_external_exists ast "get_label";
  let ext = Option.get (Ml_ast_helpers.find_external ast "get_label") in

  (* Should have 1 parameter (self) *)
  Ml_validation.assert_param_count ext 1;

  (* Validate parameter and return types *)
  Ml_validation.assert_param_type ext 0 "t";
  (* self *)
  Ml_validation.assert_return_type ext "string"

(* ========================================================================= *)
(* Test: Property Setter Method *)
(* ========================================================================= *)

let test_property_setter () =
  let ctx = create_test_context () in

  let meth =
    Type_factory.make_gir_method ~method_name:"set_label"
      ~c_identifier:"gtk_button_set_label" ~return_type:Type_factory.void_type
      ~parameters:[ Type_factory.make_string_param ~param_name:"label" () ]
      ~set_property:"label" ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Button" ~class_doc:None
      ~c_type:"GtkButton" ~parent_chain:[ "Widget" ] ~constructors:None
      ~methods:[ meth ] ~properties:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ast = Ml_ast_helpers.parse_implementation ml_code in

  Ml_validation.assert_external_exists ast "set_label";
  let ext = Option.get (Ml_ast_helpers.find_external ast "set_label") in

  (* Should have 2 parameters (self + label) *)
  Ml_validation.assert_param_count ext 2;

  (* Validate parameter and return types *)
  Ml_validation.assert_param_type ext 0 "t";
  (* self *)
  Ml_validation.assert_param_type ext 1 "string";
  (* label *)
  Ml_validation.assert_return_type ext "unit"

(* ========================================================================= *)
(* Test: Property Getter with Nullable Return *)
(* ========================================================================= *)

let test_property_getter_nullable () =
  let ctx = create_test_context () in

  let meth =
    Type_factory.make_gir_method ~method_name:"get_tooltip_text"
      ~c_identifier:"gtk_widget_get_tooltip_text"
      ~return_type:
        (Type_factory.make_gir_type ~name:"utf8" ~c_type:"gchar*" ~nullable:true
           ())
      ~get_property:"tooltip-text" ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Widget" ~class_doc:None
      ~c_type:"GtkWidget" ~parent_chain:[] ~constructors:None ~methods:[ meth ]
      ~properties:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ast = Ml_ast_helpers.parse_implementation ml_code in

  Ml_validation.assert_external_exists ast "get_tooltip_text";
  let ext = Option.get (Ml_ast_helpers.find_external ast "get_tooltip_text") in

  (* Validate parameter and return types *)
  Ml_validation.assert_param_count ext 1;
  Ml_validation.assert_param_type ext 0 "t";
  Ml_validation.assert_return_type ext "string option"

(* ========================================================================= *)
(* Test Suite Registration *)
(* ========================================================================= *)

let tests =
  [
    Alcotest.test_case "Method with multiple parameters" `Quick
      test_method_multiple_params;
    Alcotest.test_case "Method with object parameter" `Quick
      test_method_with_object_param;
    Alcotest.test_case "Method with boolean parameter" `Quick
      test_method_with_bool_param;
    Alcotest.test_case "Method with integer return" `Quick
      test_method_with_int_return;
    Alcotest.test_case "Constructor with multiple parameters" `Quick
      test_constructor_with_multiple_params;
    Alcotest.test_case "Method with nullable object" `Quick
      test_method_with_nullable_object;
    Alcotest.test_case "Property getter method" `Quick test_property_getter;
    Alcotest.test_case "Property setter method" `Quick test_property_setter;
    Alcotest.test_case "Property getter with nullable return" `Quick
      test_property_getter_nullable;
  ]
