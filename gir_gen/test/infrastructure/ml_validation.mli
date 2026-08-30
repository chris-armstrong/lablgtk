val assert_polymorphic_variant : Ppxlib.Parsetree.type_declaration -> unit
val assert_has_variant_tag : Ppxlib.Parsetree.type_declaration -> string -> unit
val assert_wraps_gobject_obj : Ppxlib.Parsetree.type_declaration -> unit
val assert_abstract_type : Ppxlib.Parsetree.type_declaration -> unit
val is_optional_string_param : Ppxlib.Parsetree.value_description -> int -> bool
val returns_unit : Ppxlib.Parsetree.value_description -> bool
val returns_string : Ppxlib.Parsetree.value_description -> bool
val returns_string_option : Ppxlib.Parsetree.value_description -> bool

val assert_external_c_name :
  Ppxlib.Parsetree.value_description -> string -> unit

val assert_param_count : Ppxlib.Parsetree.value_description -> int -> unit

val assert_function_signature :
  Ppxlib.Parsetree.core_type ->
  expected_params:string list ->
  expected_return:string ->
  unit

val assert_types_compatible :
  Ppxlib.Parsetree.core_type -> Ppxlib.Parsetree.core_type -> unit

val assert_type_exists : Ppxlib.Parsetree.structure -> string -> unit
val assert_external_exists : Ppxlib.Parsetree.structure -> string -> unit
val assert_type_exists_sig : Ppxlib.Parsetree.signature -> string -> unit

val assert_param_type :
  Ppxlib.Parsetree.value_description -> int -> string -> unit

val assert_return_type : Ppxlib.Parsetree.value_description -> string -> unit
val assert_value_exists : Ppxlib.Parsetree.structure -> string -> unit
val assert_value_exists_sig : Ppxlib.Parsetree.signature -> string -> unit

val assert_no_value_matching_sig :
  Ppxlib.Parsetree.signature -> (string -> bool) -> string -> unit

val assert_type_has_variant_tag_sig :
  Ppxlib.Parsetree.signature -> string -> string -> unit

val assert_class_type_inherits :
  Ppxlib.Parsetree.structure -> class_type:string -> parent:string -> unit

val assert_class_type_not_inherits_prefix :
  Ppxlib.Parsetree.structure ->
  class_type:string ->
  parent_prefix:string ->
  unit

val assert_class_impl_inherits :
  Ppxlib.Parsetree.structure ->
  class_name:string ->
  parent_class_name:string ->
  unit
