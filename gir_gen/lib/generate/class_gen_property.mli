(** Property generation for layer 2 classes. *)

val generate_property_methods :
  ctx:Types.generation_context ->
  class_name:string ->
  methods:Types.gir_method list ->
  module_name:string ->
  current_layer2_module:string ->
  seen:Common.StringSet.t ->
  same_cluster_classes:string list ->
  Types.gir_property ->
  string * Common.StringSet.t
(** Generate the getter/setter method implementations for a property.

    Parameters:
    - ctx: generation context
    - class_name: GIR class name
    - methods: the class's methods
    - module_name: layer 1 module name for the class
    - current_layer2_module: layer 2 module being generated
    - seen: set of already-emitted method names
    - same_cluster_classes: classes in the same cyclic cluster
    - prop: the GIR property

    Returns: the generated code and the updated [seen] set. *)

val generate_property_signatures :
  ctx:Types.generation_context ->
  class_name:string ->
  methods:Types.gir_method list ->
  seen:Common.StringSet.t ->
  current_layer2_module:string ->
  same_cluster_classes:string list ->
  Types.gir_property ->
  string * Common.StringSet.t
(** Generate the getter/setter type signatures for a property.

    Parameters:
    - ctx: generation context
    - class_name: GIR class name
    - methods: the class's methods
    - seen: set of already-emitted method names
    - current_layer2_module: layer 2 module being generated
    - same_cluster_classes: classes in the same cyclic cluster
    - prop: the GIR property

    Returns: the generated code and the updated [seen] set. *)
