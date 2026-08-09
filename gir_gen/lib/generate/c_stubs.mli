val include_header_for_namespace : string -> string

type property_gvalue_info =
  C_stub_type_analysis.Type_analysis.property_gvalue_info

val get_c_type_str : ctx:Types.generation_context -> Types.gir_type -> string

val analyze_property_type :
  ctx:Types.generation_context -> Types.gir_type -> property_gvalue_info

val is_copy_method : Types.gir_method -> bool
val is_free_method : Types.gir_method -> bool
val is_copy_or_free : Types.gir_method -> bool

val fold_mapi :
  f:(int -> 'a -> 'b -> 'a * 'c) -> init:'a -> 'b list -> 'a * 'c list

val list_contains : value:string -> string list -> bool
val is_string_type : string option -> bool

val generate_array_ml_to_c :
  ctx:Types.generation_context ->
  var:string ->
  array_info:Types.gir_array ->
  element_mapping:Types.type_mapping ->
  element_c_type:string ->
  transfer_ownership:Types.transfer_ownership ->
  nullable:bool ->
  string * string * string * string

val generate_array_c_to_ml :
  ctx:Types.generation_context ->
  var:string ->
  array_info:Types.gir_array ->
  length_expr:string option ->
  element_c_type:string ->
  transfer_ownership:Types.transfer_ownership ->
  ?nullable:bool ->
  unit ->
  string * string * string

val is_string_array : Types.gir_array -> bool

val generate_gvalue_getter_assignment :
  ml_name:string ->
  prop:Types.gir_property ->
  c_type_name:string ->
  prop_info:property_gvalue_info ->
  string

val generate_gvalue_setter_assignment :
  ml_name:string -> prop_info:property_gvalue_info -> string

val generate_c_file_header :
  ctx:Types.generation_context -> ?class_name:string -> unit -> string

val base_c_type_of : string -> string

val build_return_statement :
  throws:bool -> string option -> string list -> string

val generate_constructors :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  buf:Buffer.t ->
  generator:
    (ctx:Types.generation_context ->
    c_type:string ->
    class_name:string ->
    Types.gir_constructor ->
    string) ->
  Types.gir_constructor list ->
  unit

val generate_methods :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  buf:Buffer.t ->
  generator:
    (ctx:Types.generation_context ->
    c_type:string ->
    Types.gir_method ->
    string ->
    string) ->
  entity_kind:Filtering.entity_kind ->
  Types.gir_method list ->
  unit

val default_type_mapping : Types.type_mapping

type param_acc = C_stub_helpers.param_acc = {
  ocaml_idx : int;
  decls : Buffer.t;
  args : string list;
  cleanups : string list;
}

val nullable_c_to_ml_expr :
  ctx:Types.generation_context ->
  var:string ->
  gir_type:Types.gir_type ->
  mapping:Types.type_mapping ->
  ?direction:Types.gir_direction ->
  unit ->
  string

val nullable_ml_to_c_expr :
  var:string -> gir_type:Types.gir_type -> mapping:Types.type_mapping -> string

val generate_forward_decl_section :
  buf:Buffer.t ->
  items:'a list ->
  section_comment:string ->
  generate_one:('a -> unit) ->
  ?deduplicate:bool ->
  unit ->
  unit

val namespace_display_name : string -> string
val format_version_for_message : Version_guard.version -> string

val emit_fallback_constructor_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  c_identifier:string ->
  version:Version_guard.version ->
  Types.gir_constructor ->
  string

val emit_fallback_method_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  c_identifier:string ->
  version:Version_guard.version ->
  Types.gir_method ->
  string

val emit_fallback_property_getter_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  version:Version_guard.version ->
  Types.gir_property ->
  string

val emit_fallback_property_setter_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  version:Version_guard.version ->
  Types.gir_property ->
  string

val emit_fallback_record_method_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  version:Version_guard.version ->
  Types.gir_method ->
  string

val emit_with_member_guard :
  ctx:Types.generation_context ->
  ?version_namespace:string option ->
  class_version:string option ->
  member_version:string option ->
  fallback:(Version_guard.version -> string) ->
  stub:string ->
  Buffer.t ->
  unit

val os_to_c_guard_open : Os_filter.t -> string
val os_to_c_guard_close : Os_filter.t -> string
val os_display_name : Os_filter.t -> string

val emit_with_os_guard :
  os:Os_filter.t option ->
  failwith_stub:string ->
  stub:string ->
  Buffer.t ->
  unit

val emit_os_fallback_constructor_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  c_identifier:string ->
  os:Os_filter.t ->
  Types.gir_constructor ->
  string

val emit_os_fallback_method_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  c_identifier:string ->
  os:Os_filter.t ->
  Types.gir_method ->
  string

val emit_os_fallback_property_getter_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  os:Os_filter.t ->
  Types.gir_property ->
  string

val emit_os_fallback_property_setter_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  os:Os_filter.t ->
  Types.gir_property ->
  string

val generate_multi_param_function :
  ml_name:string ->
  params:string list ->
  param_names:string list ->
  string ->
  string

val generate_c_property_getter :
  ctx:Types.generation_context ->
  c_type:string ->
  Types.gir_property ->
  string ->
  string

val generate_c_property_setter :
  ctx:Types.generation_context ->
  c_type:string ->
  Types.gir_property ->
  string ->
  string

val has_copy_method : Types.gir_record -> bool
val is_value_like_record : Types.gir_record -> bool

val generate_record_c_code :
  ctx:Types.generation_context -> Types.gir_record -> string

val base_namespaces : string list
val get_dependency_namespaces : 'a Types.StringMap.t -> StdLabels.String.t list
val generate_dependency_includes : string list -> string

val generate_decls_header :
  ctx:Types.generation_context ->
  classes:Types.gir_class list ->
  interfaces:Types.gir_interface list ->
  gtk_enums:Types.gir_enum list ->
  gtk_bitfields:Types.gir_bitfield list ->
  records:Types.gir_record list ->
  ?header_overrides:Override_types.header_override list ->
  unit ->
  string
