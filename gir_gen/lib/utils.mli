val strip_leading_numbers : string -> string
val uppercase_start_re : Re.Str.regexp
val uppercase_re : Re.Str.regexp
val to_snake_case : string -> string
val sanitize_doc : string -> string
val get_attr : string -> ((string * string) * 'a) list -> 'a option
val parse_bool : ?default:bool -> string option -> bool
val is_void_return_type : Types.gir_type -> bool
val extract_namespace_from_c_type : string -> StdLabels.String.t option
val normalize_class_name : string -> string
val module_name_of_class : string -> string
val internal_namespace_to_module_name : string -> string
val library_wrapper_name : string -> string
val external_namespace_to_module_name : string -> string
val enums_module_name : Types.generation_context -> Types.gir_enum -> string

val bitfields_module_name :
  Types.generation_context -> Types.gir_bitfield -> string

val read_filter_file : string -> string list
val reserved_identifiers : string list
val sanitize_identifier : string -> string
val sanitize_property_name : string -> string

val ocaml_function_name :
  class_name:'a -> ?c_type:'b -> ?c_symbol_prefix:'c -> string -> string

val kebab_to_snake : string -> string

val ocaml_method_name :
  class_name:'a -> ?c_type:'b -> ?c_symbol_prefix:'c -> string -> string

val ocaml_property_name : string -> string
val ocaml_parameter_name : string -> string
val ocaml_class_name : string -> string
val ocaml_interface_name : string -> string
val ocaml_record_name : string -> string
val extract_ml_prefix : Types.generation_context -> string
val gtype_macro_of_type_name : string -> string
val cast_macro_of_type_name : string -> string
val ocaml_constructor_name : class_name:'a -> Types.gir_constructor -> string

val ml_constructor_name :
  class_name:'a -> constructor:Types.gir_constructor -> string

val ml_method_name : class_name:'a -> Types.gir_method -> string

val ml_property_name :
  ctx:Types.generation_context ->
  class_name:string ->
  Types.gir_property ->
  string

val ml_property_setter_name :
  ctx:Types.generation_context ->
  class_name:string ->
  Types.gir_property ->
  string

val ocaml_bitfield_name : Types.gir_bitfield -> string
val ocaml_enum_name : Types.gir_enum -> string
val layer2_module_name : string -> string
val layer2_module_filename : string -> string
val class_type_name : string -> string
val accessor_name : string -> string
val name_to_parts : ctx:Types.generation_context -> string -> string * string
