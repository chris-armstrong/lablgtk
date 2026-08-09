val or_else : (unit -> 'a option) -> 'a option -> 'a option

val calculate_layer2_class :
  class_module:string -> class_name:string -> Types.ocaml_class

val map_cross_reference_to_type_mapping :
  ctx:'a ->
  namespace:string ->
  Types.cross_reference_entity ->
  Types.type_mapping

val type_mappings : (string * Types.type_mapping) list
val normalize_c_pointer_type : string -> string

val lookup_class :
  classes:Types.gir_class list ->
  lookup_str:StdLabels.String.t ->
  Types.gir_class option

val lookup_interface :
  interfaces:Types.gir_interface list ->
  lookup_str:StdLabels.String.t ->
  Types.gir_interface option

val is_boxed_record : Types.gir_record -> bool

val lookup_record :
  records:Types.gir_record list ->
  lookup_str:StdLabels.String.t ->
  (Types.gir_record * bool * bool) option

val calculate_class_or_interface_or_record_module_name :
  ctx:Types.generation_context -> name:string -> string

val find_class_mapping :
  ctx:Types.generation_context ->
  lookup_str:StdLabels.String.t ->
  Types.type_mapping Containers.Option.t

val find_interface_mapping :
  ctx:Types.generation_context ->
  lookup_str:StdLabels.String.t ->
  Types.type_mapping Containers.Option.t

val find_record_mapping :
  ctx:Types.generation_context ->
  lookup_str:StdLabels.String.t ->
  Types.type_mapping Containers.Option.t

val find_enum_mapping :
  ctx:Types.generation_context ->
  lookup_str:StdLabels.String.t ->
  Types.type_mapping Containers.Option.t

val find_bitfield_mapping :
  ctx:Types.generation_context ->
  lookup_str:StdLabels.String.t ->
  Types.type_mapping Containers.Option.t

type type_kind =
  | Tk_Enum
  | Tk_Bitfield
  | Tk_Class
  | Tk_Interface
  | Tk_Record
  | Tk_Primitive
  | Tk_Unknown

val classify_type : ctx:Types.generation_context -> Types.gir_type -> type_kind
val ( let* ) : 'a option -> ('a -> 'b option) -> 'b option

val find_type_mapping_for_gir_type :
  ctx:Types.generation_context ->
  Types.gir_type ->
  Types.type_mapping Containers.Option.t

val list_c_type_of_gir_type : Types.gir_type -> string option -> string

val build_container_mapping :
  element_mapping:Types.type_mapping ->
  container_suffix:string ->
  c_type:string ->
  marker:string ->
  Types.type_mapping

val handle_list_type :
  ctx:Types.generation_context ->
  Types.gir_type ->
  Types.type_mapping Containers.Option.t

val handle_array_type :
  ctx:Types.generation_context ->
  Types.gir_type ->
  Types.type_mapping Containers.Option.t

val normal_type_lookup :
  ctx:Types.generation_context ->
  Types.gir_type ->
  Types.type_mapping Containers.Option.t

val simplify_self_reference :
  class_name:string -> ocaml_type:StdLabels.String.t -> string
