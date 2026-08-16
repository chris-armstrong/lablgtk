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
(** [generate_property_methods ... prop] generates the getter/setter method
    implementations for [prop]. [methods] are the class's methods (used to avoid
    collisions); [seen] is the set of already-emitted method names;
    [same_cluster_classes] are classes in the same cyclic cluster. Returns the
    generated code and the updated [seen] set. *)

val generate_property_signatures :
  ctx:Types.generation_context ->
  class_name:string ->
  methods:Types.gir_method list ->
  seen:Common.StringSet.t ->
  current_layer2_module:string ->
  same_cluster_classes:string list ->
  Types.gir_property ->
  string * Common.StringSet.t
(** [generate_property_signatures ... prop] generates the getter/setter type
    signatures for [prop]. Parameters and return value are as for
    [generate_property_methods]. *)
