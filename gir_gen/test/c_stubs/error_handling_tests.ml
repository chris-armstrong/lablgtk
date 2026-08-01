(* Error Handling Tests (throws=true) *)

open Type_factory

(* =================================================================== *)
(* Methods under test *)
(* =================================================================== *)

let generate_c_constructor =
  Gir_gen_lib.Generate.C_stub_constructor.generate_c_constructor

(* ========================================================================= *)
(* Error Handling Tests *)
(* ========================================================================= *)

let test_method_with_throws_declares_error () =
  let meth =
    make_gir_method ~method_name:"save_to_file"
      ~c_identifier:"gtk_widget_save_to_file" ~return_type:gboolean_type
      ~parameters:[ make_string_param ~param_name:"filename" () ]
      ~throws:true ()
  in
  let func =
    Helpers.generate_and_find_c_method
      ~log_label:"method with throws declares error" ~c_type:"GtkWidget"
      ~class_name:"Widget" meth
  in
  Alcotest.(check bool)
    "Declares GError variable" true
    (C_ast.has_var_decl func "error")

let test_error_handling_uses_res_ok () =
  let meth =
    make_gir_method ~method_name:"load_file"
      ~c_identifier:"gtk_widget_load_file" ~return_type:gboolean_type
      ~parameters:[ make_string_param ~param_name:"filename" () ]
      ~throws:true ()
  in
  let func =
    Helpers.generate_and_find_c_method ~log_label:"error handling uses res ok"
      ~c_type:"GtkWidget" ~class_name:"Widget" meth
  in
  Alcotest.(check bool)
    "Returns result type" true
    (C_validation.returns_result_type func)

let test_error_passed_by_reference () =
  let meth =
    make_gir_method ~method_name:"save" ~c_identifier:"gtk_widget_save"
      ~return_type:gboolean_type ~throws:true ()
  in
  let func =
    Helpers.generate_and_find_c_method ~log_label:"error passed by reference"
      ~c_type:"GtkWidget" ~class_name:"Widget" meth
  in
  Alcotest.(check bool)
    "Error passed by reference" true
    (C_validation.out_param_passed_by_ref func "error" "gtk_widget_save")

let test_error_initialized_to_null () =
  let meth =
    make_gir_method ~method_name:"open" ~c_identifier:"gtk_widget_open"
      ~return_type:gboolean_type ~throws:true ()
  in
  let func =
    Helpers.generate_and_find_c_method ~log_label:"error initialized to null"
      ~c_type:"GtkWidget" ~class_name:"Widget" meth
  in
  let var_decls = C_ast.get_var_decls func in
  Alcotest.(check bool)
    "Error variable declared" true
    (List.exists
       (fun (name, var_type, _) ->
         name = "error" && String.contains var_type 'G')
       var_decls)

let test_has_complete_error_handling () =
  let meth =
    make_gir_method ~method_name:"process" ~c_identifier:"gtk_widget_process"
      ~return_type:gboolean_type ~throws:true ()
  in
  let func =
    Helpers.generate_and_find_c_method ~log_label:"has complete error handling"
      ~c_type:"GtkWidget" ~class_name:"Widget" meth
  in
  Alcotest.(check bool)
    "Has complete error handling" true
    (C_validation.has_error_handling func)

let test_constructor_with_throws () =
  let ctx = Helpers.create_test_context () in
  let ctor =
    make_gir_constructor ~ctor_name:"new_from_file"
      ~c_identifier:"gtk_widget_new_from_file"
      ~ctor_parameters:[ make_string_param ~param_name:"filename" () ]
      ~throws:true ()
  in
  let c_code =
    generate_c_constructor ~ctx ~c_type:"GtkWidget" ~class_name:"Widget" ctor
  in
  Helpers.log_generated_c_code "constructor with throws" c_code;
  let functions = C_parser.parse_c_code c_code in
  let func =
    Helpers.assert_some_value "ml_gtk_widget_new_from_file"
      (C_ast.find_function functions "ml_gtk_widget_new_from_file")
  in
  Alcotest.(check bool)
    "Constructor with throws has error handling" true
    (C_validation.has_error_handling func)

(* ========================================================================= *)
(* Test Suite *)
(* ========================================================================= *)

let tests =
  [
    Alcotest.test_case "Method with throws declares GError" `Quick
      test_method_with_throws_declares_error;
    Alcotest.test_case "Error handling uses Res_Ok/Res_Error" `Quick
      test_error_handling_uses_res_ok;
    Alcotest.test_case "Error passed by reference" `Quick
      test_error_passed_by_reference;
    Alcotest.test_case "Error initialized to NULL" `Quick
      test_error_initialized_to_null;
    Alcotest.test_case "Complete error handling infrastructure" `Quick
      test_has_complete_error_handling;
    Alcotest.test_case "Constructor with throws" `Quick
      test_constructor_with_throws;
  ]
