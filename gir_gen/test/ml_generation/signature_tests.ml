(* Signature Tests - Validates .mli and .ml consistency and method specifications *)

open Ppxlib.Parsetree

let create_test_context = Helpers.create_test_context

(* Helper to get external/val from signature *)
let find_val_in_sig (ast : Parsetree.signature) (name : string) :
    Parsetree.value_description option =
  List.find_map
    (fun item ->
      match item.Parsetree.psig_desc with
      | Parsetree.Psig_value vd when vd.pval_name.txt = name -> Some vd
      | _ -> None)
    ast

(* ========================================================================= *)
(* Test: Type Declaration Consistency *)
(* ========================================================================= *)

let test_type_declaration_consistency () =
  let ctx = create_test_context () in

  (* Generate both .mli and .ml *)
  let mli_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Interface ~class_name:"Button" ~class_doc:None
      ~c_type:"GtkButton" ~parent_chain:[ "Widget" ] ~constructors:None
      ~methods:[] ~properties:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Button" ~class_doc:None
      ~c_type:"GtkButton" ~parent_chain:[ "Widget" ] ~constructors:None
      ~methods:[] ~properties:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let mli_ast = Ml_ast_helpers.parse_interface mli_code in
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Both should have type t *)
  Ml_validation.assert_type_exists_sig mli_ast "t";
  Ml_validation.assert_type_exists ml_ast "t"

(* ========================================================================= *)
(* Test: Constructor Signature Matches *)
(* ========================================================================= *)

let test_constructor_signature_matches () =
  let ctx = create_test_context () in

  let ctor =
    Type_factory.make_gir_constructor ~ctor_name:"new_with_label"
      ~c_identifier:"gtk_button_new_with_label"
      ~ctor_parameters:[ Type_factory.make_string_param ~param_name:"label" () ]
      ()
  in

  let mli_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Interface ~class_name:"Button" ~class_doc:None
      ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~constructors:(Some [ ctor ]) ~methods:[] ~properties:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Button" ~class_doc:None
      ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~constructors:(Some [ ctor ]) ~methods:[] ~properties:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let mli_ast = Ml_ast_helpers.parse_interface mli_code in
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Both should have the external *)
  let mli_ext = Ml_ast_helpers.find_external_sig mli_ast "new_with_label" in
  let ml_ext = Ml_ast_helpers.find_external ml_ast "new_with_label" in

  Alcotest.(check bool)
    ".mli should have new_with_label" true (Option.is_some mli_ext);
  Alcotest.(check bool)
    ".ml should have new_with_label" true (Option.is_some ml_ext);

  (* Check signatures match *)
  match (mli_ext, ml_ext) with
  | Some mli_vd, Some ml_vd ->
      let mli_type_str = Ml_ast_helpers.core_type_to_string mli_vd.pval_type in
      let ml_type_str = Ml_ast_helpers.core_type_to_string ml_vd.pval_type in
      Alcotest.(check string) "Signatures should match" mli_type_str ml_type_str
  | _ -> Alcotest.fail "Both should have the external"

(* ========================================================================= *)
(* Test: Method Signature Matches *)
(* ========================================================================= *)

let test_method_signature_matches () =
  let ctx = create_test_context () in

  let meth =
    Type_factory.make_gir_method ~method_name:"set_label"
      ~c_identifier:"gtk_button_set_label" ~return_type:Type_factory.void_type
      ~parameters:[ Type_factory.make_string_param ~param_name:"label" () ]
      ()
  in

  let mli_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Interface ~class_name:"Button" ~class_doc:None
      ~c_type:"GtkButton" ~parent_chain:[ "Widget" ] ~constructors:None
      ~methods:[ meth ] ~properties:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Button" ~class_doc:None
      ~c_type:"GtkButton" ~parent_chain:[ "Widget" ] ~constructors:None
      ~methods:[ meth ] ~properties:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let mli_ast = Ml_ast_helpers.parse_interface mli_code in
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Both should have set_label *)
  let mli_ext = Ml_ast_helpers.find_external_sig mli_ast "set_label" in
  let ml_ext = Ml_ast_helpers.find_external ml_ast "set_label" in

  Alcotest.(check bool)
    ".mli should have set_label" true (Option.is_some mli_ext);
  Alcotest.(check bool) ".ml should have set_label" true (Option.is_some ml_ext);

  (* Check signatures match *)
  match (mli_ext, ml_ext) with
  | Some mli_vd, Some ml_vd ->
      let mli_type_str = Ml_ast_helpers.core_type_to_string mli_vd.pval_type in
      let ml_type_str = Ml_ast_helpers.core_type_to_string ml_vd.pval_type in
      Alcotest.(check string)
        "Method signatures should match" mli_type_str ml_type_str
  | _ -> Alcotest.fail "Both should have the method"

(* ========================================================================= *)
(* Test: Multiple Methods All Match *)
(* ========================================================================= *)

let test_multiple_methods_match () =
  let ctx = create_test_context () in

  let methods =
    [
      Type_factory.make_gir_method ~method_name:"set_label"
        ~c_identifier:"gtk_button_set_label" ~return_type:Type_factory.void_type
        ~parameters:[ Type_factory.make_string_param ~param_name:"label" () ]
        ();
      Type_factory.make_string_method ~method_name:"get_label"
        ~c_identifier:"gtk_button_get_label" ();
    ]
  in

  let mli_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Interface ~class_name:"Button" ~class_doc:None
      ~c_type:"GtkButton" ~parent_chain:[ "Widget" ] ~constructors:None ~methods
      ~properties:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let ml_code =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Implementation ~class_name:"Button" ~class_doc:None
      ~c_type:"GtkButton" ~parent_chain:[ "Widget" ] ~constructors:None ~methods
      ~properties:[] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in

  let mli_ast = Ml_ast_helpers.parse_interface mli_code in
  let ml_ast = Ml_ast_helpers.parse_implementation ml_code in

  (* Check each method exists and matches in both *)
  let method_names = [ "set_label"; "get_label" ] in

  List.iter
    (fun name ->
      let mli_ext = Ml_ast_helpers.find_external_sig mli_ast name in
      let ml_ext = Ml_ast_helpers.find_external ml_ast name in

      Alcotest.(check bool)
        (Printf.sprintf ".mli should have %s" name)
        true (Option.is_some mli_ext);
      Alcotest.(check bool)
        (Printf.sprintf ".ml should have %s" name)
        true (Option.is_some ml_ext);

      (* Check signatures match *)
      match (mli_ext, ml_ext) with
      | Some mli_vd, Some ml_vd ->
          let mli_type_str =
            Ml_ast_helpers.core_type_to_string mli_vd.pval_type
          in
          let ml_type_str =
            Ml_ast_helpers.core_type_to_string ml_vd.pval_type
          in
          Alcotest.(check string)
            (Printf.sprintf "%s signatures should match" name)
            mli_type_str ml_type_str
      | _ -> Alcotest.fail (Printf.sprintf "Both should have %s" name))
    method_names

(* ========================================================================= *)
(* Test Suite Registration *)
(* ========================================================================= *)

let tests =
  [
    Alcotest.test_case "Type declaration consistency" `Quick
      test_type_declaration_consistency;
    Alcotest.test_case "Constructor signature matches" `Quick
      test_constructor_signature_matches;
    Alcotest.test_case "Method signature matches" `Quick
      test_method_signature_matches;
    Alcotest.test_case "Multiple methods all match" `Quick
      test_multiple_methods_match;
  ]
