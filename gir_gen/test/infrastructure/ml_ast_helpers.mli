(* ML AST Helpers - Wrapper around OCaml compiler-libs for parsing and
   inspecting ML/MLI files *)

(** {1 Parsing} *)

val parse_implementation : string -> Ppxlib.Parsetree.structure
(** Parse an OCaml implementation (.ml) source string into its AST.

    [parse_implementation code] parses [code] with the ppxlib frontend.

    @raise Ppxlib.Location.Error if [code] contains a syntax error *)

val parse_interface : string -> Ppxlib.Parsetree.signature
(** Parse an OCaml interface (.mli) source string into its AST.

    [parse_interface code] parses [code] with the ppxlib frontend.

    @raise Ppxlib.Location.Error if [code] contains a syntax error *)

(** {1 Type Declaration Helpers} *)

val find_type_declaration :
  Ppxlib.Parsetree.structure ->
  string ->
  Ppxlib.Parsetree.type_declaration option
(** Find a type declaration by name in an implementation AST.

    [find_type_declaration ast name] returns [Some td] for the first [type ...]
    declaration named [name], or [None] if absent. *)

val find_type_declaration_sig :
  Ppxlib.Parsetree.signature ->
  string ->
  Ppxlib.Parsetree.type_declaration option
(** Find a type declaration by name in an interface AST.

    [find_type_declaration_sig ast name] returns [Some td] for the first
    [type ...] declaration named [name], or [None] if absent. *)

val get_all_type_declarations :
  Ppxlib.Parsetree.structure -> Ppxlib.Parsetree.type_declaration list
(** Return all type declarations in an implementation AST, in order. *)

(** {1 External Declaration Helpers} *)

val find_external :
  Ppxlib.Parsetree.structure ->
  string ->
  Ppxlib.Parsetree.value_description option
(** Find an [external] declaration by name in an implementation AST.

    [find_external ast name] returns [Some vd] for the first external named
    [name], or [None] if absent. *)

val find_external_sig :
  Ppxlib.Parsetree.signature ->
  string ->
  Ppxlib.Parsetree.value_description option
(** Find an [external] declaration by name in an interface AST.

    [find_external_sig ast name] returns [Some vd] for the first external named
    [name] (a [val] with a non-empty primitive list), or [None] if absent. *)

val get_external_c_name : Ppxlib.Parsetree.value_description -> string option
(** Return the C function name of an external declaration.

    [get_external_c_name ext_decl] returns [Some c_name] for the first entry of
    [ext_decl]'s primitive list, or [None] if the list is empty. *)

val get_all_externals :
  Ppxlib.Parsetree.structure -> Ppxlib.Parsetree.value_description list
(** Return all [external] declarations in an implementation AST, in order. *)

(** {1 Value Declaration Helpers} *)

val find_let_binding :
  Ppxlib.Parsetree.structure -> string -> Ppxlib.Parsetree.value_binding option
(** Find a [let] binding by name in an implementation AST.

    [find_let_binding ast name] returns [Some vb] for the first binding whose
    pattern is a variable named [name], or [None] if absent. *)

val find_value_declaration_sig :
  Ppxlib.Parsetree.signature ->
  string ->
  Ppxlib.Parsetree.value_description option
(** Find a [val] declaration by name in an interface AST.

    [find_value_declaration_sig ast name] returns [Some vd] for the first [val]
    named [name], or [None] if absent. *)

val get_all_value_declarations_sig :
  Ppxlib.Parsetree.signature -> (string * Ppxlib.Parsetree.core_type) list
(** Return all [val] declarations in an interface AST as [(name, type)] pairs,
    in order. *)

(** {1 Type Inspection Helpers} *)

val core_type_to_string : Ppxlib.Parsetree.core_type -> string
(** Render a [core_type] as a simplified string.

    [core_type_to_string ct] produces a human-readable representation covering
    the common cases (variables, constructors, tuples, arrows, polymorphic
    variants, classes, aliases); anything unrecognised renders as
    ["<complex type>"]. *)

val get_param_types :
  Ppxlib.Parsetree.core_type -> Ppxlib.Parsetree.core_type list
(** Extract the parameter types of a function type.

    [get_param_types ct] walks the arrow spine of [ct] and returns the parameter
    types in order; returns [[]] if [ct] is not a function type. *)

val get_return_type : Ppxlib.Parsetree.core_type -> Ppxlib.Parsetree.core_type
(** Extract the return type of a function type.

    [get_return_type ct] walks the arrow spine of [ct] and returns the final
    (non-arrow) type; returns [ct] itself if [ct] is not a function type. *)

val is_string_type : Ppxlib.Parsetree.core_type -> bool
(** Check whether a type is [string]. *)

val is_string_option_type : Ppxlib.Parsetree.core_type -> bool
(** Check whether a type is [string option]. *)

val is_result_type_with_ginfo_error : Ppxlib.Parsetree.core_type -> bool
(** Check whether a type is a [result] whose error type is [GError.t].

    [is_result_type_with_ginfo_error ct] returns [true] for types of the form
    [(T, GError.t) result]. *)

val is_unit_type : Ppxlib.Parsetree.core_type -> bool
(** Check whether a type is [unit]. *)

val get_variant_tags : Ppxlib.Parsetree.type_declaration -> string list
(** Extract the tag names of a polymorphic variant type declaration.

    [get_variant_tags type_decl] returns the tags of the declaration's manifest,
    handling both a bare variant and a variant wrapped in a constructor (e.g.
    [type t = [`a | `b] Gobject.obj]). *)

val wraps_gobject_obj : Ppxlib.Parsetree.type_declaration -> bool
(** Check whether a type declaration's manifest is [Gobject.obj _]. *)

(** {1 Class Declaration Helpers} *)

val find_class_declaration :
  Ppxlib.Parsetree.structure ->
  string ->
  Ppxlib.Parsetree.class_declaration option
(** Find a class declaration by name in an implementation AST.

    [find_class_declaration ast name] returns [Some cd] for the first
    [class ...] declaration named [name], or [None] if absent. *)

val find_class_type_declaration :
  Ppxlib.Parsetree.signature ->
  string ->
  Ppxlib.Parsetree.class_type_declaration option
(** Find a class type declaration by name in an interface AST.

    [find_class_type_declaration ast name] searches both [class ...] and
    [class type ...] declarations and returns the first named [name], or [None]
    if absent. *)

val get_class_inherit_clauses : Ppxlib.Parsetree.class_expr -> string list
(** Return the names of the classes inherited by a class expression.

    [get_class_inherit_clauses class_expr] collects the constructor names of all
    [inherit] clauses, recursing through applications, structures and
    parameterised class bodies. *)

val get_class_type_inherit_clauses : Ppxlib.Parsetree.class_type -> string list
(** Return the names of the class types inherited by a class type.

    [get_class_type_inherit_clauses class_type] collects the constructor names
    of all [inherit] clauses in the class type's signature. *)

val find_method_in_class :
  Ppxlib.Parsetree.class_expr -> string -> Ppxlib.Parsetree.class_field option
(** Find a method by name in a class expression.

    [find_method_in_class class_expr method_name] returns [Some cf] for the
    first method field named [method_name], recursing through class structures,
    applications and parameterised bodies; returns [None] if absent. *)

val get_method_type :
  Ppxlib.Parsetree.class_field -> Ppxlib.Parsetree.core_type option
(** Return the type annotation of a method field.

    [get_method_type class_field] returns the declared type for virtual and
    explicitly-typed concrete methods, or [None] when no annotation is
    available. *)

val get_method_body :
  Ppxlib.Parsetree.class_field -> Ppxlib.Parsetree.expression option
(** Return the body expression of a concrete method field.

    [get_method_body class_field] returns [Some body] for a concrete method
    (unwrapping [Pexp_poly]), or [None] for virtual methods. *)

val find_method_in_class_type :
  Ppxlib.Parsetree.class_type ->
  string ->
  Ppxlib.Parsetree.class_type_field option
(** Find a method by name in a class type.

    [find_method_in_class_type class_type method_name] returns [Some ctf] for
    the first method field named [method_name], recursing through signatures and
    arrow types; returns [None] if absent. *)

val get_method_type_from_class_type_field :
  Ppxlib.Parsetree.class_type_field -> Ppxlib.Parsetree.core_type option
(** Return the type annotation of a method field in a class type.

    [get_method_type_from_class_type_field class_type_field] returns the
    method's declared type, or [None] if the field is not a method. *)

(** {1 Hierarchy Type Helpers} *)

val contains_hierarchy_type : Ppxlib.Parsetree.core_type -> bool
(** Recursively check whether a [core_type] contains a hierarchy type.

    [contains_hierarchy_type ct] returns [true] if [ct] mentions a class type
    (e.g. [#Widget]) anywhere, including in constructor arguments, arrows,
    tuples, variants, objects, and aliases. *)

val assert_method_has_hierarchy_param :
  Ppxlib.Parsetree.structure -> string -> string -> unit
(** Assert that a method in a class has a hierarchy-type parameter.

    [assert_method_has_hierarchy_param ast class_name method_name] fails the
    test if the class or method is missing, or if the method's type contains no
    hierarchy type.

    @raise Alcotest.Test_error if the assertion fails *)

(** {1 Function Call Validation Helpers} *)

val contains_function_call : Ppxlib.Parsetree.expression -> string -> bool
(** Recursively check whether an expression contains a call to the named
    function.

    [contains_function_call expr func_name] matches both bare identifiers and
    dotted paths (e.g. [Gobject.Closure.nth]) and descends into applications,
    lets, sequences, conditionals, matches, records, and more. *)

val method_body_calls_function :
  Ppxlib.Parsetree.expression -> string -> string -> bool
(** Check whether a method body calls a specific module-qualified function.

    [method_body_calls_function expr module_name func_name] returns [true] if
    [expr] contains an application of [Module.func] where the module path equals
    [module_name] and the function name equals [func_name]. *)

val assert_let_binding_calls_function :
  Ppxlib.Parsetree.structure -> string -> string -> unit
(** Assert that a [let] binding's body calls the named function.

    [assert_let_binding_calls_function ast func_name binding_name] fails the
    test if the binding is missing or does not call [func_name].

    @raise Alcotest.Test_error if the assertion fails *)

val contains_method_send : Ppxlib.Parsetree.expression -> string -> bool
(** Recursively check whether an expression contains a method send
    ([#method_name]).

    [contains_method_send expr method_name] descends into applications, lets,
    sequences, conditionals, tuples and arrays. *)

val assert_let_binding_sends_method :
  Ppxlib.Parsetree.structure -> string -> string -> unit
(** Assert that a [let] binding's body sends the named method.

    [assert_let_binding_sends_method ast method_name binding_name] fails the
    test if the binding is missing or does not send [#method_name].

    @raise Alcotest.Test_error if the assertion fails *)

(** {1 Method Conflict Detection Helpers} *)

val method_exists_as_definition : Ppxlib.Parsetree.class_expr -> string -> bool
(** Check whether a method exists as an actual definition (virtual or concrete)
    in a class expression. *)

val method_signature_exists : Ppxlib.Parsetree.class_type -> string -> bool
(** Check whether a method signature exists in a class type. *)

(** {1 Class Type Declaration Helpers} *)

val find_class_type_declaration_impl :
  Ppxlib.Parsetree.structure ->
  string ->
  Ppxlib.Parsetree.class_type_declaration option
(** Find a [class type] declaration by name in an implementation AST.

    [find_class_type_declaration_impl ast name] returns [Some ctd] for the first
    [class type ...] declaration named [name], or [None] if absent. *)

val get_class_type_inherit_names :
  Ppxlib.Parsetree.class_type_declaration -> string list
(** Extract the dotted names of the class types inherited by a [class type]
    declaration. *)

val find_class_definition :
  Ppxlib.Parsetree.structure ->
  string ->
  Ppxlib.Parsetree.class_declaration option
(** Find a class definition by name in an implementation AST.

    [find_class_definition ast name] returns [Some cd] for the first [class ...]
    definition named [name], or [None] if absent. *)

val get_class_inherit_names : Ppxlib.Parsetree.class_declaration -> string list
(** Return the dotted names of the classes inherited by a class declaration's
    body. *)

(** {1 Arrow Type Label and Parameter Helpers} *)

val get_arrow_params_with_labels :
  Ppxlib.Parsetree.core_type ->
  (Ppxlib.Asttypes.arg_label * Ppxlib.Parsetree.core_type) list
(** Extract all [(arg_label, core_type)] pairs from a function type, in order.

    [get_arrow_params_with_labels ct] walks the arrow spine of [ct] and stops at
    the final return type. *)

val find_labelled_param :
  Ppxlib.Parsetree.core_type -> string -> Ppxlib.Parsetree.core_type option
(** Find the labelled parameter with the given name in a function type.

    [find_labelled_param ct label] matches both [~label] and [?(label)]
    parameters and returns the parameter's type, or [None] if absent. *)

val has_labelled_param_with_type :
  Ppxlib.Parsetree.core_type -> string -> string -> bool
(** Check whether the labelled parameter [label] exists in a function type with
    a given string representation.

    [has_labelled_param_with_type ct label type_str] compares the parameter's
    {!core_type_to_string} rendering against [type_str]. *)

val has_no_labelled_param : Ppxlib.Parsetree.core_type -> string -> bool
(** Check that no arrow in a function type carries the given label.

    [has_no_labelled_param ct label] returns [true] when [label] does not appear
    as any [~label] or [?(label)] arrow label in [ct]. *)

(** {1 Closure.nth Position Helpers} *)

val no_closure_nth_at_pos_zero : Ppxlib.Parsetree.expression -> bool
(** Return [true] iff no [Gobject.Closure.nth] call in the expression uses
    [~pos:0]. *)

(** {1 Callback Labelled-Arg Helpers} *)

val collect_labelled_args_of_call :
  Ppxlib.Parsetree.expression -> string -> string list
(** Collect all labelled argument names used in applications of [func_name]
    within an expression.

    [collect_labelled_args_of_call expr func_name] returns the list of label
    strings, in the order encountered. *)
