(* ML Validation Helpers - High-level validation functions for ML AST testing *)

open Ppxlib
open Ppxlib.Parsetree

(* ========================================================================= *)
(* Type Declaration Validations *)
(* ========================================================================= *)

(* Assert that a type declaration is a polymorphic variant *)
let assert_polymorphic_variant (type_decl : type_declaration) =
  if not (Ml_ast_helpers.is_polymorphic_variant type_decl) then
    Alcotest.fail
      (Fmt.str "Expected type '%s' to be a polymorphic variant"
         type_decl.ptype_name.txt)

(* Assert that a type declaration has a specific variant tag *)

(** Assert that a type declaration has a specific polymorphic variant tag. *)
let assert_has_variant_tag (type_decl : type_declaration) (tag : string) =
  let tags = Ml_ast_helpers.get_variant_tags type_decl in
  if not (List.mem tag tags) then
    Alcotest.fail
      (Fmt.str "Expected type '%s' to have variant tag '%s', found tags: [%s]"
         type_decl.ptype_name.txt tag (String.concat "; " tags))

(* Assert that a type declaration wraps Gobject.obj *)

(** Assert that a type declaration wraps [Gobject.obj]. *)
let assert_wraps_gobject_obj (type_decl : type_declaration) =
  if not (Ml_ast_helpers.wraps_gobject_obj type_decl) then
    Alcotest.fail
      (Fmt.str "Expected type '%s' to wrap Gobject.obj" type_decl.ptype_name.txt)

(* Assert that a type is abstract (no manifest) *)
let assert_abstract_type (type_decl : type_declaration) =
  if not (Ml_ast_helpers.is_abstract_type type_decl) then
    Alcotest.fail
      (Fmt.str "Expected type '%s' to be abstract (no manifest)"
         type_decl.ptype_name.txt)

(* ========================================================================= *)
(* External Declaration Validations *)
(* ========================================================================= *)

(* Check if a specific parameter (by index) of an external is string option *)

(** Check whether a specific parameter (by index) of an external is
    [string option]. *)
let is_optional_string_param (ext_decl : value_description) (param_idx : int) :
    bool =
  let params = Ml_ast_helpers.get_param_types ext_decl.pval_type in
  match List.nth_opt params param_idx with
  | Some param_type -> Ml_ast_helpers.is_string_option_type param_type
  | None -> false

(* Check if an external returns unit *)

(** Check whether an external returns [unit]. *)
let returns_unit (ext_decl : value_description) : bool =
  let return_type = Ml_ast_helpers.get_return_type ext_decl.pval_type in
  Ml_ast_helpers.is_unit_type return_type

(* Check if an external returns string *)

(** Check whether an external returns [string]. *)
let returns_string (ext_decl : value_description) : bool =
  let return_type = Ml_ast_helpers.get_return_type ext_decl.pval_type in
  Ml_ast_helpers.is_string_type return_type

(* Check if an external returns string option *)

(** Check whether an external returns [string option]. *)
let returns_string_option (ext_decl : value_description) : bool =
  let return_type = Ml_ast_helpers.get_return_type ext_decl.pval_type in
  Ml_ast_helpers.is_string_option_type return_type

(* Assert external has expected C name *)

(** Assert that an external has the expected C name. *)
let assert_external_c_name (ext_decl : value_description)
    (expected_c_name : string) =
  Helpers.expect_some
    (Fmt.str "External '%s' has no C name" ext_decl.pval_name.txt)
    (Ml_ast_helpers.get_external_c_name ext_decl)
  @@ fun c_name ->
  if c_name <> expected_c_name then
    Alcotest.fail
      (Fmt.str "Expected external '%s' to have C name '%s', got '%s'"
         ext_decl.pval_name.txt expected_c_name c_name)

(* Assert external has expected number of parameters *)

(** Assert that an external has the expected number of parameters. *)
let assert_param_count (ext_decl : value_description) (expected_count : int) =
  let params = Ml_ast_helpers.get_param_types ext_decl.pval_type in
  let actual_count = List.length params in
  if actual_count <> expected_count then
    Alcotest.fail
      (Fmt.str "Expected external '%s' to have %d parameters, got %d"
         ext_decl.pval_name.txt expected_count actual_count)

(* ========================================================================= *)
(* Function Signature Validations *)
(* ========================================================================= *)

(* Assert that a function/external has a specific signature pattern *)
let assert_function_signature (func_type : core_type)
    ~(expected_params : string list) ~(expected_return : string) =
  let param_types = Ml_ast_helpers.get_param_types func_type in
  let actual_return = Ml_ast_helpers.get_return_type func_type in

  (* Check parameter count *)
  let expected_count = List.length expected_params in
  let actual_count = List.length param_types in
  if actual_count <> expected_count then
    Alcotest.fail
      (Fmt.str "Expected %d parameters, got %d" expected_count actual_count);

  (* Check each parameter type *)
  List.iter2
    (fun expected_param actual_param_type ->
      let actual_param_str =
        Ml_ast_helpers.core_type_to_string actual_param_type
      in
      if actual_param_str <> expected_param then
        Alcotest.fail
          (Fmt.str "Expected parameter type '%s', got '%s'" expected_param
             actual_param_str))
    expected_params param_types;

  (* Check return type *)
  let actual_return_str = Ml_ast_helpers.core_type_to_string actual_return in
  if actual_return_str <> expected_return then
    Alcotest.fail
      (Fmt.str "Expected return type '%s', got '%s'" expected_return
         actual_return_str)

(* ========================================================================= *)
(* Type Compatibility Checks *)
(* ========================================================================= *)

(* Check if two types are compatible (for .mli vs .ml consistency) *)
let assert_types_compatible (sig_type : core_type) (impl_type : core_type) =
  let sig_str = Ml_ast_helpers.core_type_to_string sig_type in
  let impl_str = Ml_ast_helpers.core_type_to_string impl_type in
  if sig_str <> impl_str then
    Alcotest.fail
      (Fmt.str "Type mismatch: signature has '%s', implementation has '%s'"
         sig_str impl_str)

(* ========================================================================= *)
(* Convenience Assertions *)
(* ========================================================================= *)

(* Assert that a type is defined in the AST *)

(** Assert that a type is defined in an implementation AST. *)
let assert_type_exists (ast : structure) (type_name : string) =
  if Option.is_none (Ml_ast_helpers.find_type_declaration ast type_name) then
    let available_types =
      Ml_ast_helpers.get_all_type_declarations ast
      |> List.map (fun td -> td.ptype_name.txt)
      |> String.concat ", "
    in
    Alcotest.fail
      (Fmt.str "Type '%s' not found. Available types: [%s]" type_name
         available_types)

(* Assert that an external is defined in the AST *)

(** Assert that an external is defined in an implementation AST. *)
let assert_external_exists (ast : structure) (external_name : string) =
  if Option.is_none (Ml_ast_helpers.find_external ast external_name) then
    let available_externals =
      Ml_ast_helpers.get_all_externals ast
      |> List.map (fun vd -> vd.pval_name.txt)
      |> String.concat ", "
    in
    Alcotest.fail
      (Fmt.str "External '%s' not found. Available externals: [%s]"
         external_name available_externals)

(* Assert that a type is defined in a signature AST *)

(** Assert that a type is defined in an interface AST. *)
let assert_type_exists_sig (ast : signature) (type_name : string) =
  Helpers.assert_some
    (Fmt.str "Type '%s' not found in signature" type_name)
    (Ml_ast_helpers.find_type_declaration_sig ast type_name)

(* Assert parameter type at specific index *)

(** Assert the type of a parameter at a specific index of an external. *)
let assert_param_type (ext_decl : value_description) (param_idx : int)
    (expected_type : string) =
  let params = Ml_ast_helpers.get_param_types ext_decl.pval_type in
  Helpers.expect_some
    (Fmt.str "Parameter %d not found in '%s' (has %d params)" param_idx
       ext_decl.pval_name.txt (List.length params))
    (List.nth_opt params param_idx)
  @@ fun param_type ->
  let actual_type = Ml_ast_helpers.core_type_to_string param_type in
  if actual_type <> expected_type then
    Alcotest.fail
      (Fmt.str "Expected parameter %d of '%s' to be '%s', got '%s'" param_idx
         ext_decl.pval_name.txt expected_type actual_type)

(* Assert return type *)

(** Assert the return type of an external. *)
let assert_return_type (ext_decl : value_description) (expected_type : string) =
  let return_type = Ml_ast_helpers.get_return_type ext_decl.pval_type in
  let actual_type = Ml_ast_helpers.core_type_to_string return_type in
  if actual_type <> expected_type then
    Alcotest.fail
      (Fmt.str "Expected '%s' to return '%s', got '%s'" ext_decl.pval_name.txt
         expected_type actual_type)

(* Assert that a value (let binding or external) exists in implementation *)

(** Assert that a value (a [let] binding or an external) exists in an
    implementation AST. *)
let assert_value_exists (ast : structure) (value_name : string) =
  if
    Option.is_none (Ml_ast_helpers.find_let_binding ast value_name)
    && Option.is_none (Ml_ast_helpers.find_external ast value_name)
  then
    Alcotest.fail (Fmt.str "Value '%s' not found in implementation" value_name)

(* Assert that a value (val or external) exists in a signature (.mli) AST *)

(** Assert that a value ([val] or external) exists in an interface AST. *)
let assert_value_exists_sig (ast : signature) (value_name : string) =
  if Option.is_none (Ml_ast_helpers.find_value_declaration_sig ast value_name)
  then
    let available =
      Ml_ast_helpers.get_all_value_declarations_sig ast
      |> List.map fst |> String.concat ", "
    in
    Alcotest.fail
      (Fmt.str "Value '%s' not found in signature. Available: [%s]" value_name
         available)

(* Assert that no value whose name satisfies [pred] exists in the signature *)

(** Assert that no value whose name satisfies [pred] exists in an interface AST.
*)
let assert_no_value_matching_sig (ast : signature) (pred : string -> bool)
    (label : string) =
  let all = Ml_ast_helpers.get_all_value_declarations_sig ast |> List.map fst in
  match List.find_opt pred all with
  | Some name ->
      Alcotest.fail
        (Fmt.str "Expected no value matching '%s', but found '%s'" label name)
  | None -> ()

(* Assert that a type in a signature has a specific polymorphic variant tag *)

(** Assert that a type in an interface AST has a specific polymorphic variant
    tag. *)
let assert_type_has_variant_tag_sig (ast : signature) (type_name : string)
    (tag : string) =
  Helpers.expect_some
    (Fmt.str "Type '%s' not found in signature" type_name)
    (Ml_ast_helpers.find_type_declaration_sig ast type_name)
  @@ fun type_decl ->
  let tags = Ml_ast_helpers.get_variant_tags type_decl in
  if not (List.mem tag tags) then
    Alcotest.fail
      (Fmt.str
         "Expected type '%s' in signature to have variant tag '%s', found: [%s]"
         type_name tag (String.concat "; " tags))

(* ========================================================================= *)
(* Class Type Inheritance Validations                                         *)
(* ========================================================================= *)

(** Assert that class type [class_type_name] in implementation [ast] inherits
    from [parent_name] (exact dotted name, e.g. "GMyIface.my_iface_t"). *)
let assert_class_type_inherits (ast : structure) ~class_type ~parent =
  Helpers.expect_some
    (Fmt.str "class type '%s' not found in implementation" class_type)
    (Ml_ast_helpers.find_class_type_declaration_impl ast class_type)
  @@ fun ctd ->
  let inherits = Ml_ast_helpers.get_class_type_inherit_names ctd in
  if not (List.mem parent inherits) then
    Alcotest.failf "class type '%s' does not inherit '%s'; inherited: [%s]"
      class_type parent
      (String.concat "; " inherits)

(** Assert that class type [class_type_name] does NOT inherit anything with the
    given [parent_prefix] (e.g. "GMyIface"). *)
let assert_class_type_not_inherits_prefix (ast : structure) ~class_type
    ~parent_prefix =
  Helpers.expect_some
    (Fmt.str "class type '%s' not found in implementation" class_type)
    (Ml_ast_helpers.find_class_type_declaration_impl ast class_type)
  @@ fun ctd ->
  let inherits = Ml_ast_helpers.get_class_type_inherit_names ctd in
  let offender =
    List.find_opt
      (fun inh ->
        String.length inh >= String.length parent_prefix
        && String.sub inh 0 (String.length parent_prefix) = parent_prefix)
      inherits
  in
  match offender with
  | Some bad ->
      Alcotest.failf "class type '%s' should NOT inherit '%s' (prefix '%s')"
        class_type bad parent_prefix
  | None -> ()

(** Assert that class [class_name] in implementation [ast] inherits from a class
    whose name (fully qualified) equals [parent_class_name] — this checks the
    inherit in the object body (implementation inherit). *)
let assert_class_impl_inherits (ast : structure) ~class_name ~parent_class_name
    =
  Helpers.expect_some
    (Fmt.str "class '%s' not found in implementation" class_name)
    (Ml_ast_helpers.find_class_definition ast class_name)
  @@ fun cd ->
  let inherits = Ml_ast_helpers.get_class_inherit_names cd in
  if not (List.mem parent_class_name inherits) then
    Alcotest.failf "class '%s' does not inherit '%s'; inherited: [%s]"
      class_name parent_class_name
      (String.concat "; " inherits)
