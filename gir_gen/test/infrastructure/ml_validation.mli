(* ML Validation Helpers - High-level validation functions for ML AST testing *)

(** {1 Type Declaration Validations} *)

val assert_polymorphic_variant : Ppxlib.Parsetree.type_declaration -> unit
(** Assert that a type declaration is a polymorphic variant.

    @raise Alcotest.Test_error if the assertion fails *)

val assert_has_variant_tag : Ppxlib.Parsetree.type_declaration -> string -> unit
(** Assert that a type declaration has a specific polymorphic variant tag.

    [assert_has_variant_tag type_decl tag] fails the test if [tag] is not among
    the declaration's variant tags.

    @raise Alcotest.Test_error if the assertion fails *)

val assert_wraps_gobject_obj : Ppxlib.Parsetree.type_declaration -> unit
(** Assert that a type declaration wraps [Gobject.obj].

    @raise Alcotest.Test_error if the assertion fails *)

val assert_abstract_type : Ppxlib.Parsetree.type_declaration -> unit
(** Assert that a type declaration is abstract (has no manifest).

    @raise Alcotest.Test_error if the assertion fails *)

(** {1 External Declaration Validations} *)

val is_optional_string_param : Ppxlib.Parsetree.value_description -> int -> bool
(** Check whether a specific parameter (by index) of an external is
    [string option].

    [is_optional_string_param ext_decl param_idx] returns [false] if the
    parameter index is out of range. *)

val returns_unit : Ppxlib.Parsetree.value_description -> bool
(** Check whether an external returns [unit]. *)

val returns_string : Ppxlib.Parsetree.value_description -> bool
(** Check whether an external returns [string]. *)

val returns_string_option : Ppxlib.Parsetree.value_description -> bool
(** Check whether an external returns [string option]. *)

val assert_external_c_name :
  Ppxlib.Parsetree.value_description -> string -> unit
(** Assert that an external has the expected C name.

    [assert_external_c_name ext_decl expected_c_name] fails the test if the
    external has no C name or the name differs.

    @raise Alcotest.Test_error if the assertion fails *)

val assert_param_count : Ppxlib.Parsetree.value_description -> int -> unit
(** Assert that an external has the expected number of parameters.

    @raise Alcotest.Test_error if the assertion fails *)

(** {1 Function Signature Validations} *)

val assert_function_signature :
  Ppxlib.Parsetree.core_type ->
  expected_params:string list ->
  expected_return:string ->
  unit
(** Assert that a function type has the expected parameter types and return
    type.

    [assert_function_signature func_type ~expected_params ~expected_return]
    compares the parameter count, each parameter's string representation and the
    return type's string representation against the expectations.

    @raise Alcotest.Test_error if the assertion fails *)

val assert_param_type :
  Ppxlib.Parsetree.value_description -> int -> string -> unit
(** Assert the type of a parameter at a specific index of an external.

    [assert_param_type ext_decl param_idx expected_type] compares the
    parameter's string representation against [expected_type].

    @raise Alcotest.Test_error if the assertion fails *)

val assert_return_type : Ppxlib.Parsetree.value_description -> string -> unit
(** Assert the return type of an external.

    [assert_return_type ext_decl expected_type] compares the return type's
    string representation against [expected_type].

    @raise Alcotest.Test_error if the assertion fails *)

(** {1 Type Compatibility Checks} *)

val assert_types_compatible :
  Ppxlib.Parsetree.core_type -> Ppxlib.Parsetree.core_type -> unit
(** Assert that two types have identical string representations.

    [assert_types_compatible sig_type impl_type] compares the
    {!Ml_ast_helpers.core_type_to_string} renderings of the signature and
    implementation types, failing the test if they differ.

    @raise Alcotest.Test_error if the assertion fails *)

(** {1 Convenience Assertions} *)

val assert_type_exists : Ppxlib.Parsetree.structure -> string -> unit
(** Assert that a type is defined in an implementation AST.

    [assert_type_exists ast type_name] fails the test if no [type ...]
    declaration named [type_name] exists, listing the available types.

    @raise Alcotest.Test_error if the assertion fails *)

val assert_external_exists : Ppxlib.Parsetree.structure -> string -> unit
(** Assert that an external is defined in an implementation AST.

    [assert_external_exists ast external_name] fails the test if no external
    named [external_name] exists, listing the available externals.

    @raise Alcotest.Test_error if the assertion fails *)

val assert_type_exists_sig : Ppxlib.Parsetree.signature -> string -> unit
(** Assert that a type is defined in an interface AST.

    @raise Alcotest.Test_error if the assertion fails *)

val assert_value_exists : Ppxlib.Parsetree.structure -> string -> unit
(** Assert that a value (a [let] binding or an external) exists in an
    implementation AST.

    @raise Alcotest.Test_error if the assertion fails *)

val assert_value_exists_sig : Ppxlib.Parsetree.signature -> string -> unit
(** Assert that a value ([val] or external) exists in an interface AST.

    [assert_value_exists_sig ast value_name] fails the test if no value named
    [value_name] exists, listing the available values.

    @raise Alcotest.Test_error if the assertion fails *)

val assert_no_value_matching_sig :
  Ppxlib.Parsetree.signature -> (string -> bool) -> string -> unit
(** Assert that no value whose name satisfies [pred] exists in an interface AST.

    [assert_no_value_matching_sig ast pred label] fails the test if such a value
    is found, reporting it via [label].

    @raise Alcotest.Test_error if the assertion fails *)

val assert_type_has_variant_tag_sig :
  Ppxlib.Parsetree.signature -> string -> string -> unit
(** Assert that a type in an interface AST has a specific polymorphic variant
    tag.

    [assert_type_has_variant_tag_sig ast type_name tag] fails the test if the
    type is missing or does not have [tag].

    @raise Alcotest.Test_error if the assertion fails *)

(** {1 Class Type Inheritance Validations} *)

val assert_class_type_inherits :
  Ppxlib.Parsetree.structure -> class_type:string -> parent:string -> unit
(** Assert that a class type in an implementation AST inherits from a given
    parent.

    [assert_class_type_inherits ast ~class_type ~parent] fails the test if the
    class type is missing or does not inherit [parent] (an exact dotted name,
    e.g. ["GMyIface.my_iface_t"]).

    @raise Alcotest.Test_error if the assertion fails *)

val assert_class_type_not_inherits_prefix :
  Ppxlib.Parsetree.structure ->
  class_type:string ->
  parent_prefix:string ->
  unit
(** Assert that a class type in an implementation AST does NOT inherit anything
    with the given prefix.

    [assert_class_type_not_inherits_prefix ast ~class_type ~parent_prefix] fails
    the test if the class type inherits a name starting with [parent_prefix]
    (e.g. ["GMyIface"]).

    @raise Alcotest.Test_error if the assertion fails *)

val assert_class_impl_inherits :
  Ppxlib.Parsetree.structure ->
  class_name:string ->
  parent_class_name:string ->
  unit
(** Assert that a class in an implementation AST inherits from a given class.

    [assert_class_impl_inherits ast ~class_name ~parent_class_name] checks the
    inherit clauses in the class body and fails the test if the class is missing
    or does not inherit [parent_class_name].

    @raise Alcotest.Test_error if the assertion fails *)
