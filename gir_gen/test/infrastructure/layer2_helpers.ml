(* Layer 2 Test Infrastructure - Helpers for testing class hierarchies and inheritance *)

open Gir_gen_lib.Types

(* ========================================================================= *)
(* Signal Creation Helpers *)
(* ========================================================================= *)

(** [create_test_signal ~name] builds a minimal GIR signal with a void return
    type and no parameters. *)
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

(* ========================================================================= *)
(* Class Inheritance Validation Helpers *)
(* ========================================================================= *)

(** [validate_class_inherits ~structure ~class_name ~parent_class] fails the
    test unless the class [class_name] in [structure] inherits from
    [parent_class]. *)
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

(** [validate_class_type_inherits ~signature ~class_name ~parent_class_type]
    fails the test unless the class type [class_name] in [signature] inherits
    from [parent_class_type]. *)
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

(** [validate_method_type_annotation ~structure ~class_name ~method_name
     ~expected_type] fails the test unless the method [method_name] of class
    [class_name] in [structure] carries the type annotation [expected_type]. *)
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

(** [validate_method_type_annotation_sig ~signature ~class_name ~method_name
     ~expected_type] fails the test unless the method [method_name] of class
    [class_name] in [signature] carries the type annotation [expected_type]. *)
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
