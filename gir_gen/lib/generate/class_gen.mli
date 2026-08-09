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
  Stdlib__Set.Make(StdLabels.String).t ->
  'd * Types.gir_method ->
  Stdlib__Set.Make(StdLabels.String).t

val process_child_against_parents :
  ctx:'a ->
  class_name:'b ->
  c_type:'c ->
  ('d * Types.gir_method) list ->
  Stdlib__Set.Make(StdLabels.String).t ->
  Types.gir_method ->
  Stdlib__Set.Make(StdLabels.String).t

val detect_method_conflicts :
  ctx:Types.generation_context ->
  class_name:StdLabels.String.t ->
  c_type:'a ->
  methods:Types.gir_method list ->
  Stdlib__Set.Make(StdLabels.String).t

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
  ctx:Types.generation_context ->
  class_name:StdLabels.String.t ->
  Stdlib__Set.Make(StdLabels.String).t

val generate_property_code :
  ctx:Types.generation_context ->
  class_name:'a ->
  methods:Types.gir_method list ->
  seen:Stdlib__Set.Make(StdLabels.String).t ->
  generate_getter:(Types.gir_property -> string -> string) ->
  generate_setter:(Types.gir_property -> string -> string) ->
  Types.gir_property ->
  string * Stdlib__Set.Make(StdLabels.String).t

val generate_property_methods :
  ctx:Types.generation_context ->
  module_name:string ->
  current_layer2_module:StdLabels.String.t ->
  seen:Stdlib__Set.Make(StdLabels.String).t ->
  same_cluster_classes:'a ->
  Types.gir_property ->
  class_name:'b ->
  methods:Types.gir_method list ->
  string * Stdlib__Set.Make(StdLabels.String).t

val generate_property_signatures :
  ctx:Types.generation_context ->
  class_name:'a ->
  methods:Types.gir_method list ->
  seen:Stdlib__Set.Make(StdLabels.String).t ->
  current_layer2_module:StdLabels.String.t ->
  same_cluster_classes:'b ->
  Types.gir_property ->
  string * Stdlib__Set.Make(StdLabels.String).t

val generate_class_converter_method_sig :
  ctx:Types.generation_context -> class_name:string -> Buffer.t -> unit

val generate_class_converter_method_impl : class_name:string -> Buffer.t -> unit

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

val build_hierarchy_type :
  ctx:Types.generation_context ->
  current_layer2_module:StdLabels.String.t ->
  gir_type:Types.gir_type ->
  is_nullable:bool ->
  string

val build_base_type : is_nullable:bool -> string -> string option

val build_param_type_with_hierarchy :
  ctx:Types.generation_context ->
  same_cluster_classes:'a ->
  current_layer2_module:StdLabels.String.t ->
  Types.gir_param ->
  string

val map_param_sig :
  ctx:Types.generation_context ->
  same_cluster_classes:'a ->
  current_layer2_module:StdLabels.String.t ->
  Types.gir_param ->
  string

val build_class_type :
  ctx:Types.generation_context ->
  current_layer2_module:StdLabels.String.t ->
  same_cluster_classes:'a ->
  Types.gir_param ->
  'b ->
  string

val build_param_type :
  ctx:Types.generation_context ->
  same_cluster_classes:'a ->
  current_layer2_module:StdLabels.String.t ->
  string option list * 'b ->
  'c * Types.gir_param ->
  string option list * 'b

val convert_param_in_string :
  ctx:'a ->
  current_layer2_module:'b ->
  same_cluster_classes:'c ->
  'd ->
  'e ->
  Types.gir_param ->
  'd * 'e

val convert_param_type_in_string :
  ctx:Types.generation_context ->
  current_layer2_module:'a ->
  same_cluster_classes:'b ->
  'c * 'd ->
  'e * Types.gir_param ->
  'c * 'd

val find_accessor_name :
  ctx:Types.generation_context -> Types.gir_param -> string

val generate_hierarchy_param_binding :
  Buffer.t -> string -> Types.gir_param -> string -> unit

val generate_method_wrappers :
  ctx:Types.generation_context ->
  property_method_names:'a ->
  property_base_names:'b ->
  module_name:string ->
  class_name:'c ->
  c_type:'d ->
  seen:StringSet.t ->
  current_layer2_module:StdLabels.String.t ->
  same_cluster_classes:'e ->
  conflicting_methods:StringSet.t ->
  entity_kind:Filtering.entity_kind ->
  Types.gir_method ->
  string * StringSet.t

val generate_signature_content :
  ctx:Types.generation_context ->
  same_cluster_classes:'a ->
  current_layer2_module:StdLabels.String.t ->
  Types.gir_method ->
  bool * string

val generate_method_signatures :
  ctx:Types.generation_context ->
  property_method_names:'a ->
  property_base_names:'b ->
  class_name:'c ->
  c_type:'d ->
  seen:StringSet.t ->
  current_layer2_module:StdLabels.String.t ->
  same_cluster_classes:'e ->
  conflicting_methods:StringSet.t ->
  entity_kind:Filtering.entity_kind ->
  Types.gir_method ->
  string * StringSet.t

val generate_class_module_body :
  ctx:Types.generation_context ->
  buf:Buffer.t ->
  layer1_module_name:string ->
  current_layer2_module:string ->
  class_name:string ->
  class_snake:string ->
  c_type:string ->
  methods:Types.gir_method list ->
  entity_kind:Filtering.entity_kind ->
  properties:Types.gir_property list ->
  signals:Types.gir_signal list ->
  same_cluster_classes:string list ->
  parent_name:string option ->
  unit ->
  unit

val generate_class_signature_body :
  ctx:Types.generation_context ->
  buf:Buffer.t ->
  layer1_module_name:string ->
  current_layer2_module:string ->
  class_name:string ->
  class_snake:string ->
  c_type:string ->
  methods:Types.gir_method list ->
  entity_kind:Filtering.entity_kind ->
  properties:Types.gir_property list ->
  signals:Types.gir_signal list ->
  same_cluster_classes:string list ->
  parent_name:string option ->
  unit ->
  unit

val get_param_layer2_type :
  ctx:Types.generation_context ->
  current_layer2_module:StdLabels.String.t ->
  Types.gir_param ->
  string option

val get_accessor_name :
  ctx:Types.generation_context -> Types.gir_param -> string

val get_constructor_param_type :
  ctx:Types.generation_context ->
  current_layer2_module:StdLabels.String.t ->
  Types.gir_param ->
  string

type constructor_param_info = {
  cp_name : string;
  cp_type : string;
  cp_is_class : bool;
  cp_param : Types.gir_param;
}

val collect_constructor_params :
  ctx:Types.generation_context ->
  current_layer2_module:StdLabels.String.t ->
  Types.gir_constructor ->
  constructor_param_info list

val generate_param_unwrapping :
  ctx:Types.generation_context ->
  buf:Buffer.t ->
  constructor_param_info list ->
  unit

val calculate_return_type :
  class_type_name:string -> Types.gir_constructor -> string

val generate_constructor_impl :
  ctx:Types.generation_context ->
  buf:Buffer.t ->
  class_snake:string ->
  class_type_name:string ->
  current_layer2_module:StdLabels.String.t ->
  layer1_ctor_prefix:string ->
  Types.gir_constructor ->
  unit

val generate_constructor_sig :
  ctx:Types.generation_context ->
  buf:Buffer.t ->
  class_type_name:string ->
  current_layer2_module:StdLabels.String.t ->
  Types.gir_constructor ->
  unit

val generate_class_module :
  ctx:Types.generation_context ->
  class_name:string ->
  c_type:string ->
  parent_chain:string list ->
  methods:Types.gir_method list ->
  entity_kind:Filtering.entity_kind ->
  properties:Types.gir_property list ->
  signals:Types.gir_signal list ->
  constructors:Types.gir_constructor list ->
  string

val generate_class_signature :
  ctx:Types.generation_context ->
  class_name:string ->
  c_type:string ->
  parent_chain:string list ->
  methods:Types.gir_method list ->
  entity_kind:Filtering.entity_kind ->
  properties:Types.gir_property list ->
  signals:Types.gir_signal list ->
  constructors:Types.gir_constructor list ->
  string

val generate_combined_entities :
  ctx:Types.generation_context ->
  combined_module_name:string ->
  entities:Types.entity list ->
  parent_chain_for_entity:(string -> 'a list) ->
  header_text:string ->
  generate_entity:
    (buf:Buffer.t ->
    i:int ->
    class_snake:string ->
    module_name:string ->
    current_layer2_module:string ->
    class_name:string ->
    c_type:string ->
    methods:Types.gir_method list ->
    entity_kind:Filtering.entity_kind ->
    properties:Types.gir_property list ->
    signals:Types.gir_signal list ->
    same_cluster_classes:string list ->
    parent_name:'a option ->
    unit) ->
  string

val generate_combined_class_module :
  ctx:Types.generation_context ->
  combined_module_name:string ->
  entities:Types.entity list ->
  parent_chain_for_entity:(string -> string list) ->
  string

val generate_combined_class_signature :
  ctx:Types.generation_context ->
  combined_module_name:string ->
  entities:Types.entity list ->
  parent_chain_for_entity:(string -> string list) ->
  string

val generate_cyclic_shim_module :
  ctx:Types.generation_context ->
  entity:Types.entity ->
  combined_module_name:string ->
  g_combined_module_name:string ->
  string

val generate_cyclic_shim_signature :
  ctx:Types.generation_context ->
  entity:Types.entity ->
  combined_module_name:string ->
  g_combined_module_name:string ->
  string
