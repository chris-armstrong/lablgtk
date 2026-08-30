val parse_implementation :
  string -> Ppxlib_ast__Import.Js.Ast.Parsetree.structure

val parse_interface : string -> Ppxlib_ast__Import.Js.Ast.Parsetree.signature

val find_type_declaration :
  Ppxlib.Parsetree.structure ->
  string ->
  Ppxlib.Parsetree.type_declaration option

val find_type_declaration_sig :
  Ppxlib.Parsetree.signature ->
  string ->
  Ppxlib.Parsetree.type_declaration option

val get_all_type_declarations :
  Ppxlib.Parsetree.structure -> Ppxlib.Parsetree.type_declaration list

val find_external :
  Ppxlib.Parsetree.structure ->
  string ->
  Ppxlib.Parsetree.value_description option

val find_external_sig :
  Ppxlib.Parsetree.signature ->
  string ->
  Ppxlib.Parsetree.value_description option

val get_external_c_name : Ppxlib.Parsetree.value_description -> string option

val get_all_externals :
  Ppxlib.Parsetree.structure -> Ppxlib.Parsetree.value_description list

val find_let_binding :
  Ppxlib.Parsetree.structure -> string -> Ppxlib.Parsetree.value_binding option

val find_value_declaration_sig :
  Ppxlib.Parsetree.signature ->
  string ->
  Ppxlib.Parsetree.value_description option

val get_all_value_declarations_sig :
  Ppxlib.Parsetree.signature -> (string * Ppxlib.Parsetree.core_type) list

val longident_loc_to_string : Ppxlib.Longident.t Ppxlib.Asttypes.loc -> string
val core_type_to_string : Ppxlib.Parsetree.core_type -> string

val get_param_types :
  Ppxlib.Parsetree.core_type -> Ppxlib.Parsetree.core_type list

val get_return_type : Ppxlib.Parsetree.core_type -> Ppxlib.Parsetree.core_type
val is_option_type : Ppxlib.Parsetree.core_type -> bool
val is_unit_type : Ppxlib.Parsetree.core_type -> bool
val is_string_type : Ppxlib.Parsetree.core_type -> bool
val is_string_option_type : Ppxlib.Parsetree.core_type -> bool
val is_result_type_with_ginfo_error : Ppxlib.Parsetree.core_type -> bool
val get_variant_tags : Ppxlib.Parsetree.type_declaration -> string list
val wraps_gobject_obj : Ppxlib.Parsetree.type_declaration -> bool
val is_polymorphic_variant : Ppxlib.Parsetree.type_declaration -> bool
val is_abstract_type : Ppxlib.Parsetree.type_declaration -> bool

val find_class_declaration :
  Ppxlib.Parsetree.structure ->
  string ->
  Ppxlib.Parsetree.class_declaration option

val find_class_type_declaration :
  Ppxlib.Parsetree.signature ->
  string ->
  Ppxlib.Parsetree.class_type_declaration option

val get_class_inherit_clauses : Ppxlib.Parsetree.class_expr -> string list
val get_class_type_inherit_clauses : Ppxlib.Parsetree.class_type -> string list

val find_method_in_class :
  Ppxlib.Parsetree.class_expr -> string -> Ppxlib.Parsetree.class_field option

val get_method_type :
  Ppxlib.Parsetree.class_field -> Ppxlib.Parsetree.core_type option

val get_method_body :
  Ppxlib.Parsetree.class_field -> Ppxlib.Parsetree.expression option

val find_method_in_class_type :
  Ppxlib.Parsetree.class_type ->
  string ->
  Ppxlib.Parsetree.class_type_field option

val get_method_type_from_class_type_field :
  Ppxlib.Parsetree.class_type_field -> Ppxlib.Parsetree.core_type option

val class_expr_to_string : Ppxlib.Parsetree.class_expr -> string
val longident_is_hierarchy_type : Ppxlib.Longident.t -> bool

val longident_loc_is_hierarchy_type :
  Ppxlib.Longident.t Ppxlib.Asttypes.loc -> bool

val contains_hierarchy_type : Ppxlib.Parsetree.core_type -> bool
val has_hierarchy_parameter : Ppxlib.Parsetree.class_field -> bool

val assert_method_has_hierarchy_param :
  Ppxlib.Parsetree.structure -> string -> string -> unit

val contains_structural_type : Ppxlib.Parsetree.core_type -> bool
val has_structural_type_parameter : Ppxlib.Parsetree.class_field -> bool

val method_param_has_structural_type_with_field :
  Ppxlib.Parsetree.class_field -> string -> bool

val assert_method_has_structural_type_param :
  Ppxlib.Parsetree.structure -> string -> string -> unit

val assert_method_has_structural_field :
  Ppxlib.Parsetree.structure -> string -> string -> string -> unit

val longident_to_string : Ppxlib.Longident.t -> string
val contains_function_call : Ppxlib.Parsetree.expression -> string -> bool

val method_body_calls_function :
  Ppxlib.Parsetree.expression -> string -> string -> bool

val assert_let_binding_calls_function :
  Ppxlib.Parsetree.structure -> string -> string -> unit

val contains_method_send : Ppxlib.Parsetree.expression -> string -> bool

val assert_let_binding_sends_method :
  Ppxlib.Parsetree.structure -> string -> string -> unit

val method_exists_as_definition : Ppxlib.Parsetree.class_expr -> string -> bool
val method_signature_exists : Ppxlib.Parsetree.class_type -> string -> bool
val find_all_methods_in_class : Ppxlib.Parsetree.class_expr -> string list
val method_mentioned_in_comment : string -> string -> bool

val validate_method_is_commented_out :
  class_expr:Ppxlib.Parsetree.class_expr ->
  class_code:string ->
  method_name:string ->
  unit

val validate_method_is_generated :
  class_expr:Ppxlib.Parsetree.class_expr -> method_name:string -> unit

val longident_to_string_phase4 : Ppxlib.Longident.t -> string
val class_type_constr_name : Ppxlib.Parsetree.class_type -> string option

val find_class_type_declaration_impl :
  Ppxlib.Parsetree.structure ->
  string ->
  Ppxlib.Parsetree.class_type_declaration option

val find_class_type_declaration_sig2 :
  Ppxlib.Parsetree.signature ->
  string ->
  Ppxlib.Parsetree.class_type_declaration option

val get_class_type_inherit_names :
  Ppxlib.Parsetree.class_type_declaration -> string list

val find_class_definition :
  Ppxlib.Parsetree.structure ->
  string ->
  Ppxlib.Parsetree.class_declaration option

val collect_class_expr_inherits : Ppxlib.Parsetree.class_expr -> string list
val get_class_inherit_names : Ppxlib.Parsetree.class_declaration -> string list

val get_arrow_params_with_labels :
  Ppxlib.Parsetree.core_type ->
  (Ppxlib.Asttypes.arg_label * Ppxlib.Parsetree.core_type) list

val find_labelled_param :
  Ppxlib.Parsetree.core_type -> string -> Ppxlib.Parsetree.core_type option

val has_labelled_param_with_type :
  Ppxlib.Parsetree.core_type -> string -> string -> bool

val has_no_labelled_param : Ppxlib.Parsetree.core_type -> string -> bool
val collect_closure_nth_positions : Ppxlib.Parsetree.expression -> int list
val no_closure_nth_at_pos_zero : Ppxlib.Parsetree.expression -> bool

val collect_labelled_args_of_call :
  Ppxlib.Parsetree.expression -> string -> string list
