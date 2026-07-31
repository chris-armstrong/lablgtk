(* Constructor Wrapper Tests - End-to-end testing of constructor wrapper generation *)

open Type_factory

let create_test_context = Helpers.create_test_context_with_hierarchy

let find_let_binding_or_fail ast name =
  Helpers.expect_some
    (Printf.sprintf "Let binding '%s' not found" name)
    (Ml_ast_helpers.find_let_binding ast name)
    Fun.id

let find_val_or_fail ast name =
  Helpers.expect_some
    (Printf.sprintf "Val declaration '%s' not found" name)
    (Ml_ast_helpers.find_value_declaration_sig ast name)
    Fun.id

(* ========================================================================= *)
(* Test 1: Zero-param constructor                                           *)
(* ========================================================================= *)

let test_zero_param_constructor () =
  let ctx = create_test_context () in
  let ctor =
    make_gir_constructor ~ctor_name:"new" ~c_identifier:"gtk_button_new" ()
  in
  let button_class =
    make_gir_class ~class_name:"Button" ~c_type:"GtkButton"
      ~constructors:[ ctor ] ()
  in
  let ctx = { ctx with classes = button_class :: ctx.classes } in

  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[] ~properties:[] ~signals:[] ~constructors:[ ctor ]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in
  let ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Should generate: let new_ () : button_t = new button (Button.new_ ()) *)
  let _binding = find_let_binding_or_fail ast "new_" in
  Ml_ast_helpers.assert_let_binding_calls_function ast "Button.new_" "new_"

(* ========================================================================= *)
(* Test 2: Single string param constructor                                   *)
(* ========================================================================= *)

let test_single_string_param_constructor () =
  let ctx = create_test_context () in
  let param = make_string_param ~param_name:"label" () in
  let ctor =
    make_gir_constructor ~ctor_name:"new_with_label"
      ~c_identifier:"gtk_button_new_with_label" ~ctor_parameters:[ param ] ()
  in
  let button_class =
    make_gir_class ~class_name:"Button" ~c_type:"GtkButton"
      ~constructors:[ ctor ] ()
  in
  let ctx = { ctx with classes = button_class :: ctx.classes } in

  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[] ~properties:[] ~signals:[] ~constructors:[ ctor ]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in
  let ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Should generate: let new_with_label (label : string) : button_t = ... *)
  let _binding = find_let_binding_or_fail ast "new_with_label" in
  Ml_ast_helpers.assert_let_binding_calls_function ast "Button.new_with_label"
    "new_with_label"

(* ========================================================================= *)
(* Test 3: Class-typed param constructor (unwrapping)                        *)
(* ========================================================================= *)

let test_class_typed_param_constructor () =
  let ctx = create_test_context () in
  let param = make_widget_param ~param_name:"child" () in
  let ctor =
    make_gir_constructor ~ctor_name:"new_with_child"
      ~c_identifier:"gtk_box_new_with_child" ~ctor_parameters:[ param ] ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx ~class_name:"Box"
      ~c_type:"GtkBox" ~parent_chain:[ "Widget" ] ~methods:[] ~properties:[]
      ~signals:[] ~constructors:[ ctor ]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in
  let ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Should contain unwrapping: let child = child#as_widget in *)
  Ml_ast_helpers.assert_let_binding_sends_method ast "as_widget"
    "new_with_child"

(* ========================================================================= *)
(* Test 4: Nullable class param (Option.map unwrapping)                      *)
(* ========================================================================= *)

let test_nullable_class_param_constructor () =
  let ctx = create_test_context () in
  let param = make_widget_param ~param_name:"child" ~nullable:true () in
  let ctor =
    make_gir_constructor ~ctor_name:"new_with_child"
      ~c_identifier:"gtk_box_new_with_child" ~ctor_parameters:[ param ] ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx ~class_name:"Box"
      ~c_type:"GtkBox" ~parent_chain:[ "Widget" ] ~methods:[] ~properties:[]
      ~signals:[] ~constructors:[ ctor ]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in
  let ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Should contain: let child = Option.map (fun c -> c#as_widget) child in *)
  Ml_ast_helpers.assert_let_binding_calls_function ast "Option.map"
    "new_with_child";
  Ml_ast_helpers.assert_let_binding_sends_method ast "as_widget"
    "new_with_child"

(* ========================================================================= *)
(* Test 5: Constructor signature (.mli)                                      *)
(* ========================================================================= *)

let test_constructor_signature () =
  let ctx = create_test_context () in
  let param = make_string_param ~param_name:"label" () in
  let ctor_no_params =
    make_gir_constructor ~ctor_name:"new" ~c_identifier:"gtk_button_new" ()
  in
  let ctor_with_param =
    make_gir_constructor ~ctor_name:"new_with_label"
      ~c_identifier:"gtk_button_new_with_label" ~ctor_parameters:[ param ] ()
  in
  let button_class =
    make_gir_class ~class_name:"Button" ~c_type:"GtkButton"
      ~constructors:[ ctor_no_params; ctor_with_param ]
      ()
  in
  let ctx = { ctx with classes = button_class :: ctx.classes } in

  let mli_code =
    Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
      ~class_name:"Button" ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~methods:[] ~properties:[] ~signals:[]
      ~constructors:[ ctor_no_params; ctor_with_param ]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in
  let ast = Ml_ast_helpers.parse_interface mli_code in

  (* Zero-param: val new_ : unit -> button_t *)
  let vd_new = find_val_or_fail ast "new_" in
  let new_type_str = Ml_ast_helpers.core_type_to_string vd_new.pval_type in
  Alcotest.(check string) "zero-param sig" "unit -> button_t" new_type_str;

  (* With param: val new_with_label : string -> button_t *)
  let vd_label = find_val_or_fail ast "new_with_label" in
  let label_type_str = Ml_ast_helpers.core_type_to_string vd_label.pval_type in
  Alcotest.(check string) "string param sig" "string -> button_t" label_type_str

(* ========================================================================= *)
(* Test 6: Combined module constructors                                      *)
(* ========================================================================= *)

let test_combined_module_constructors () =
  let ctx = create_test_context () in
  let ctor =
    make_gir_constructor ~ctor_name:"new" ~c_identifier:"gtk_window_new" ()
  in
  let window_class =
    make_gir_class ~class_name:"Window" ~c_type:"GtkWindow"
      ~constructors:[ ctor ] ()
  in
  let ctx = { ctx with classes = window_class :: ctx.classes } in

  let entity = entity_of_class window_class in

  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_combined_class_module ~ctx
      ~combined_module_name:"Window" ~entities:[ entity ]
      ~parent_chain_for_entity:(fun _ -> [ "Widget" ])
  in
  let ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Constructor wrapper should exist in combined module output *)
  let _binding = find_let_binding_or_fail ast "new_" in
  ()

(* ========================================================================= *)
(* Test 7: Cyclic shim constructors                                          *)
(* ========================================================================= *)

let test_cyclic_shim_constructors () =
  let ctx = create_test_context () in
  let ctor =
    make_gir_constructor ~ctor_name:"new" ~c_identifier:"gtk_window_new" ()
  in
  let window_class =
    make_gir_class ~class_name:"Window" ~c_type:"GtkWindow"
      ~constructors:[ ctor ] ()
  in
  let ctx = { ctx with classes = window_class :: ctx.classes } in

  let entity = entity_of_class window_class in

  let ml_code =
    Gir_gen_lib.Generate.Class_gen.generate_cyclic_shim_module ~ctx ~entity
      ~combined_module_name:"Application_and__window_and__window_group"
      ~g_combined_module_name:"GApplication_and__window_and__window_group"
  in
  let ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Constructor wrapper should exist in shim output *)
  let _binding = find_let_binding_or_fail ast "new_" in
  ()

(* ========================================================================= *)
(* Test Registration                                                          *)
(* ========================================================================= *)

let tests =
  [
    Alcotest.test_case "Zero-param constructor" `Quick
      test_zero_param_constructor;
    Alcotest.test_case "Single string param constructor" `Quick
      test_single_string_param_constructor;
    Alcotest.test_case "Class-typed param unwrapping" `Quick
      test_class_typed_param_constructor;
    Alcotest.test_case "Nullable class param Option.map" `Quick
      test_nullable_class_param_constructor;
    Alcotest.test_case "Constructor signatures (.mli)" `Quick
      test_constructor_signature;
    Alcotest.test_case "Combined module constructors" `Quick
      test_combined_module_constructors;
    Alcotest.test_case "Cyclic shim constructors" `Quick
      test_cyclic_shim_constructors;
  ]
