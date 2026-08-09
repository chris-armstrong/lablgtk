module StringSet = Common.StringSet

type module_names = Common.module_names
type property_filters = Common.property_filters

val sanitize_name : string -> string
val ocaml_method_name : class_name:'a -> c_type:'b -> Types.gir_method -> string
val method_signature_for_comparison : Types.gir_method -> string

val get_class_methods :
  ctx:Types.generation_context -> StdLabels.String.t -> Types.gir_method list

val get_parent_name_opt :
  ctx:Types.generation_context -> StdLabels.String.t -> string option

val build_parent_chain :
  ctx:Types.generation_context -> StdLabels.String.t -> string list

val map_parent_methods_to_pairs :
  ctx:Types.generation_context ->
  StdLabels.String.t ->
  (StdLabels.String.t * Types.gir_method) list

val get_parent_methods :
  ctx:Types.generation_context ->
  parent_chain:StdLabels.String.t list ->
  (string * Types.gir_method) list

val methods_have_signature_conflict :
  ctx:'a ->
  class_name:'b ->
  c_type:'c ->
  Types.gir_method ->
  Types.gir_method ->
  bool

val check_parent_conflict :
  ctx:'a ->
  class_name:'b ->
  c_type:'c ->
  Types.gir_method ->
  StringSet.t ->
  'd * Types.gir_method ->
  StringSet.t

val process_child_against_parents :
  ctx:'a ->
  class_name:'b ->
  c_type:'c ->
  ('d * Types.gir_method) list ->
  StringSet.t ->
  Types.gir_method ->
  StringSet.t

val detect_method_conflicts :
  ctx:Types.generation_context ->
  class_name:StdLabels.String.t ->
  c_type:'a ->
  methods:Types.gir_method list ->
  StringSet.t

val get_class_properties :
  ctx:Types.generation_context -> StdLabels.String.t -> Types.gir_property list

val property_method_names : Types.gir_property -> string list

val lookup_cross_ns_class :
  ctx:Types.generation_context -> string -> Types.cross_reference_type option

val bare_name : string -> string

val iface_names_match :
  iface_name:StdLabels.String.t -> StdLabels.String.t -> bool

val cross_ns_class_provides_interface :
  ctx:Types.generation_context ->
  depth:int ->
  ns:string ->
  string ->
  StdLabels.String.t ->
  bool

val parent_chain_provides_interface :
  ctx:Types.generation_context ->
  class_name:StdLabels.String.t ->
  StdLabels.String.t ->
  bool

val collect_inherited_method_names :
  ctx:Types.generation_context -> class_name:StdLabels.String.t -> StringSet.t
