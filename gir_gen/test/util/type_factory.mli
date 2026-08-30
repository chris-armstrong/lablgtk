val entity_of_class : Gir_gen_lib.Types.gir_class -> Gir_gen_lib.Types.entity

val make_return_type :
  name:string ->
  c_type:string option ->
  ?nullable:bool ->
  ?transfer_ownership:Gir_gen_lib.Types.transfer_ownership ->
  ?array:Gir_gen_lib.Types.gir_array ->
  unit ->
  Gir_gen_lib.Types.gir_type

val make_gir_type :
  name:string ->
  ?c_type:string ->
  ?nullable:bool ->
  ?transfer_ownership:Gir_gen_lib.Types.transfer_ownership ->
  ?array:Gir_gen_lib.Types.gir_array ->
  unit ->
  Gir_gen_lib.Types.gir_type

val make_gir_array :
  ?length:int ->
  ?zero_terminated:bool ->
  ?fixed_size:int ->
  ?array_name:string ->
  element_type:Gir_gen_lib.Types.gir_type ->
  unit ->
  Gir_gen_lib.Types.gir_array

val make_gir_param :
  param_name:string ->
  param_type:Gir_gen_lib.Types.gir_type ->
  ?direction:Gir_gen_lib.Types.gir_direction ->
  ?nullable:bool ->
  ?varargs:bool ->
  ?caller_allocates:bool ->
  unit ->
  Gir_gen_lib.Types.gir_param

val make_gir_method :
  method_name:string ->
  c_identifier:string ->
  return_type:Gir_gen_lib.Types.gir_type ->
  ?parameters:Gir_gen_lib.Types.gir_param list ->
  ?doc:string ->
  ?throws:bool ->
  ?introspectable:bool ->
  ?get_property:string ->
  ?set_property:string ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_method

val make_gir_function :
  function_name:string ->
  c_identifier:string ->
  return_type:Gir_gen_lib.Types.gir_type ->
  ?parameters:Gir_gen_lib.Types.gir_param list ->
  ?doc:string ->
  ?throws:bool ->
  ?introspectable:bool ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_function

val make_gir_signal :
  signal_name:string ->
  return_type:Gir_gen_lib.Types.gir_type ->
  ?sig_parameters:Gir_gen_lib.Types.gir_param list ->
  ?doc:string ->
  ?version:string ->
  ?run_when:Gir_gen_lib.Types.signal_run_when ->
  ?action:bool ->
  ?no_recurse:bool ->
  ?no_hooks:bool ->
  unit ->
  Gir_gen_lib.Types.gir_signal

val make_gir_constructor :
  ctor_name:string ->
  c_identifier:string ->
  ?ctor_parameters:Gir_gen_lib.Types.gir_param list ->
  ?ctor_doc:string ->
  ?throws:bool ->
  ?ctor_introspectable:bool ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_constructor

val make_gir_property :
  prop_name:string ->
  prop_type:Gir_gen_lib.Types.gir_type ->
  ?readable:bool ->
  ?writable:bool ->
  ?construct_only:bool ->
  ?prop_doc:string ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_property

val make_gir_record_field :
  field_name:string ->
  ?field_type:Gir_gen_lib.Types.gir_type ->
  ?readable:bool ->
  ?writable:bool ->
  ?field_doc:string ->
  unit ->
  Gir_gen_lib.Types.gir_record_field

val make_gir_record :
  ?record_name:string ->
  ?c_type:string ->
  ?glib_type_name:string ->
  ?glib_get_type:string ->
  ?opaque:bool ->
  ?disguised:bool ->
  ?introspectable:bool ->
  ?c_symbol_prefix:string ->
  ?is_gtype_struct_for:string ->
  ?fields:Gir_gen_lib.Types.gir_record_field list ->
  ?constructors:Gir_gen_lib.Types.gir_constructor list ->
  ?methods:Gir_gen_lib.Types.gir_method list ->
  ?functions:Gir_gen_lib.Types.gir_function list ->
  ?record_doc:string ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_record

val make_gir_enum_member :
  ?member_name:string ->
  ?member_value:int ->
  ?c_identifier:string ->
  ?member_doc:string ->
  unit ->
  Gir_gen_lib.Types.gir_enum_member

val make_gir_enum :
  ?enum_name:string ->
  ?enum_c_type:string ->
  ?members:Gir_gen_lib.Types.gir_enum_member list ->
  ?functions:Gir_gen_lib.Types.gir_function list ->
  ?enum_doc:string ->
  ?enum_version:string ->
  unit ->
  Gir_gen_lib.Types.gir_enum

val make_gir_bitfield_member :
  ?flag_name:string ->
  ?flag_value:int ->
  ?flag_c_identifier:string ->
  ?flag_doc:string ->
  unit ->
  Gir_gen_lib.Types.gir_bitfield_member

val make_gir_bitfield :
  ?bitfield_name:string ->
  ?bitfield_c_type:string ->
  ?flags:Gir_gen_lib.Types.gir_bitfield_member list ->
  ?bitfield_doc:string ->
  ?bitfield_version:string ->
  unit ->
  Gir_gen_lib.Types.gir_bitfield

val make_gir_constant :
  ?constant_name:string ->
  ?constant_c_type:string ->
  ?value:string ->
  ?value_type:Gir_gen_lib.Types.gir_type ->
  ?constant_doc:string ->
  ?version:string ->
  ?introspectable:bool ->
  unit ->
  Gir_gen_lib.Types.gir_constant

val make_gir_class :
  ?class_name:string ->
  ?c_type:string ->
  ?parent:string ->
  ?implements:string list ->
  ?introspectable:bool ->
  ?constructors:Gir_gen_lib.Types.gir_constructor list ->
  ?methods:Gir_gen_lib.Types.gir_method list ->
  ?properties:Gir_gen_lib.Types.gir_property list ->
  ?signals:Gir_gen_lib.Types.gir_signal list ->
  ?class_doc:string ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_class

val make_gir_interface :
  ?interface_name:string ->
  ?c_type:string ->
  ?c_symbol_prefix:string ->
  ?glib_type_name:string option ->
  ?glib_get_type:string option ->
  ?prerequisites:string list ->
  ?introspectable:bool ->
  ?methods:Gir_gen_lib.Types.gir_method list ->
  ?properties:Gir_gen_lib.Types.gir_property list ->
  ?signals:Gir_gen_lib.Types.gir_signal list ->
  ?interface_doc:string ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_interface

val make_entity :
  ?kind:Gir_gen_lib.Types.entity_kind ->
  ?name:string ->
  ?c_type:string ->
  ?doc:string ->
  ?parent:string ->
  ?implements:string list ->
  ?constructors:Gir_gen_lib.Types.gir_constructor list ->
  ?methods:Gir_gen_lib.Types.gir_method list ->
  ?properties:Gir_gen_lib.Types.gir_property list ->
  ?signals:Gir_gen_lib.Types.gir_signal list ->
  ?version:string ->
  ?os:Gir_gen_lib.Os_filter.t option ->
  unit ->
  Gir_gen_lib.Types.entity

val make_ocaml_class :
  ?class_module:string ->
  ?class_type:string ->
  ?class_ml_name:string ->
  ?class_layer1_accessor:string ->
  unit ->
  Gir_gen_lib.Types.ocaml_class

val make_type_mapping :
  ocaml_type:string ->
  c_type:string ->
  c_to_ml:string ->
  ml_to_c:string ->
  ?layer2_class:Gir_gen_lib.Types.ocaml_class ->
  ?is_value_type_record:bool ->
  ?transfer_strategy:Gir_gen_lib.Types.transfer_strategy ->
  unit ->
  Gir_gen_lib.Types.type_mapping

val make_gir_namespace :
  ?namespace_name:string ->
  ?namespace_version:string ->
  ?namespace_shared_library:string ->
  ?namespace_c_identifier_prefixes:string ->
  ?namespace_c_symbol_prefixes:string ->
  unit ->
  Gir_gen_lib.Types.gir_namespace

val make_gir_include :
  ?include_name:string ->
  ?include_version:string ->
  unit ->
  Gir_gen_lib.Types.gir_include

val make_gir_repository :
  ?repository_includes:Gir_gen_lib.Types.gir_include list ->
  ?repository_c_includes:string list ->
  ?repository_packages:string list ->
  unit ->
  Gir_gen_lib.Types.gir_repository

val make_cross_reference_type :
  ?parent:string ->
  [< `Bitfield | `Class | `Constant | `Enum | `Interface | `Record of bool ] ->
  Gir_gen_lib.Types.cross_reference_type

val make_cross_reference_entity :
  ?cr_name:string ->
  ?cr_type:Gir_gen_lib.Types.cross_reference_type ->
  ?cr_c_type:string ->
  unit ->
  Gir_gen_lib.Types.cross_reference_entity

val make_cross_reference_namespace :
  ?cr_namespace_name:string ->
  ?cr_namespace_packages:string list ->
  ?cr_namespace_includes:string list ->
  ?cr_namespace_c_includes:string list ->
  ?cr_entities:Gir_gen_lib.Types.cross_reference_entity list ->
  unit ->
  Gir_gen_lib.Types.cross_reference_namespace

val make_cross_reference_map :
  (Gir_gen_lib.Types.StringMap.key * 'a) list ->
  'a Gir_gen_lib.Types.StringMap.t

val make_generation_context :
  ?namespace:Gir_gen_lib.Types.gir_namespace ->
  ?repository:Gir_gen_lib.Types.gir_repository ->
  ?classes:Gir_gen_lib.Types.gir_class list ->
  ?interfaces:Gir_gen_lib.Types.gir_interface list ->
  ?enums:Gir_gen_lib.Types.gir_enum list ->
  ?bitfields:Gir_gen_lib.Types.gir_bitfield list ->
  ?records:Gir_gen_lib.Types.gir_record list ->
  ?constants:Gir_gen_lib.Types.gir_constant list ->
  ?module_groups:(string * string) list ->
  ?current_cycle_classes:string list ->
  ?cross_references:
    Gir_gen_lib.Types.generation_context_namespace_cross_references
    Gir_gen_lib.Types.StringMap.t ->
  unit ->
  Gir_gen_lib.Types.generation_context

val void_type : Gir_gen_lib.Types.gir_type
val utf8_type : Gir_gen_lib.Types.gir_type
val gint_type : Gir_gen_lib.Types.gir_type
val guint_type : Gir_gen_lib.Types.gir_type
val gdouble_type : Gir_gen_lib.Types.gir_type
val gboolean_type : Gir_gen_lib.Types.gir_type
val make_widget_type : ?nullable:bool -> unit -> Gir_gen_lib.Types.gir_type
val widget_type : Gir_gen_lib.Types.gir_type
val window_type : Gir_gen_lib.Types.gir_type
val button_type : Gir_gen_lib.Types.gir_type
val string_option_type : Gir_gen_lib.Types.gir_type

val make_void_method :
  method_name:string ->
  c_identifier:string ->
  ?parameters:Gir_gen_lib.Types.gir_param list ->
  ?throws:bool ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_method

val make_string_method :
  method_name:string ->
  c_identifier:string ->
  ?parameters:Gir_gen_lib.Types.gir_param list ->
  ?throws:bool ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_method

val make_bool_method :
  method_name:string ->
  c_identifier:string ->
  ?parameters:Gir_gen_lib.Types.gir_param list ->
  ?throws:bool ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_method

val make_int_method :
  method_name:string ->
  c_identifier:string ->
  ?parameters:Gir_gen_lib.Types.gir_param list ->
  ?throws:bool ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_method

val make_string_param :
  param_name:string -> ?nullable:bool -> unit -> Gir_gen_lib.Types.gir_param

val make_int_param :
  param_name:string -> ?nullable:bool -> unit -> Gir_gen_lib.Types.gir_param

val make_uint_param :
  param_name:string -> ?nullable:bool -> unit -> Gir_gen_lib.Types.gir_param

val make_bool_param :
  param_name:string -> ?nullable:bool -> unit -> Gir_gen_lib.Types.gir_param

val make_object_param :
  param_name:string ->
  type_name:string ->
  c_type:string ->
  ?nullable:bool ->
  unit ->
  Gir_gen_lib.Types.gir_param

val make_widget_param :
  param_name:string -> ?nullable:bool -> unit -> Gir_gen_lib.Types.gir_param

val make_void_constructor :
  ctor_name:string ->
  c_identifier:string ->
  ?ctor_parameters:Gir_gen_lib.Types.gir_param list ->
  ?throws:bool ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_constructor

val make_void_signal :
  signal_name:string ->
  ?sig_parameters:Gir_gen_lib.Types.gir_param list ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_signal
