(** Method generation for layer 2 classes. *)

val generate_method_wrappers :
  ctx:Types.generation_context ->
  property_method_names:string list ->
  property_base_names:string list ->
  module_name:string ->
  class_name:string ->
  c_type:string ->
  seen:Common.StringSet.t ->
  current_layer2_module:string ->
  same_cluster_classes:string list ->
  conflicting_methods:Common.StringSet.t ->
  entity_kind:Filtering.entity_kind ->
  Types.gir_method ->
  string * Common.StringSet.t
(** Generate the implementation of a single method wrapper for a layer 2 class.

    Parameters:
    - ctx: generation context
    - property_method_names: OCaml names of the property accessors, used to
      avoid collisions with method names
    - property_base_names: base names of the property accessors
    - module_name: layer 1 module name for the class
    - class_name: GIR class name
    - c_type: C type name of the class
    - seen: set of already-emitted method names
    - current_layer2_module: layer 2 module being generated
    - same_cluster_classes: classes in the same cyclic cluster
    - conflicting_methods: method names that conflict with parent signatures
    - entity_kind: entity kind, forwarded to the skip filter
    - meth: the GIR method

    Returns: the generated code and the updated [seen] set. *)

val generate_method_signatures :
  ctx:Types.generation_context ->
  property_method_names:string list ->
  property_base_names:string list ->
  class_name:string ->
  c_type:string ->
  seen:Common.StringSet.t ->
  current_layer2_module:string ->
  same_cluster_classes:string list ->
  conflicting_methods:Common.StringSet.t ->
  entity_kind:Filtering.entity_kind ->
  Types.gir_method ->
  string * Common.StringSet.t
(** Generate the type signature of a single method for a layer 2 class type
    definition.

    Parameters and return value are as for [generate_method_wrappers]. *)
