module StringSet = Common.StringSet

type module_names = Class_gen_helpers.module_names = {
  layer1 : string;
  layer2 : string;
}

type property_filters = Class_gen_helpers.property_filters = {
  method_names : string list;
  base_names : string list;
}

val sanitize_name : string -> string

val require_type :
  location:string -> gir_type_name:string -> string option -> string

val get_module_names : ctx:Types.generation_context -> string -> module_names

val get_property_filters :
  ctx:Types.generation_context ->
  class_name:string ->
  methods:Types.gir_method list ->
  Types.gir_property list ->
  property_filters

val is_same_cluster_class : same_cluster_classes:'a list -> 'a -> bool
val structural_type_for_class : ctx:'a -> string -> string
val ocaml_method_name : class_name:'a -> c_type:'b -> Types.gir_method -> string
val has_type_variable : string -> bool
val gir_type_of_name : string -> Types.gir_type

val resolve_parent_gir_type :
  same_cluster_classes:StdLabels.String.t list ->
  parent_name:StdLabels.String.t option ->
  Types.gir_type option

val should_skip_method :
  ctx:Types.generation_context ->
  entity_kind:Filtering.entity_kind ->
  Types.gir_method ->
  bool

val qualify_layer2_class_type :
  current_layer2_module:StdLabels.String.t -> Types.ocaml_class -> string

val qualify_layer2_class_name :
  current_layer2_module:StdLabels.String.t -> Types.ocaml_class -> string

val find_layer2_class_for_type :
  ctx:Types.generation_context -> Types.gir_type -> Types.ocaml_class option

val resolve_layer2_class_ref :
  ctx:Types.generation_context ->
  current_layer2_module:StdLabels.String.t ->
  gir_type:Types.gir_type ->
  string option

val resolve_layer2_class_name :
  ctx:Types.generation_context ->
  current_layer2_module:StdLabels.String.t ->
  gir_type:Types.gir_type ->
  string option

val resolve_ocaml_type :
  ctx:Types.generation_context ->
  current_layer2_module:StdLabels.String.t ->
  gir_type:Types.gir_type ->
  string option

val map_param_sig :
  ctx:Types.generation_context ->
  same_cluster_classes:'a ->
  current_layer2_module:StdLabels.String.t ->
  Types.gir_param ->
  string

val convert_to_partial_object_type :
  ctx:'a ->
  current_layer2_module:'b ->
  same_cluster_classes:'c ->
  param_info:'d ->
  'e ->
  'e
