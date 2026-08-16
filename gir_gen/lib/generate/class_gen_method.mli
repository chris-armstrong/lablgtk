(** Method generation for layer 2 classes. *)

val generate_method_wrappers :
  ctx:Types.generation_context ->
  property_method_names:string list ->
  property_base_names:string list ->
  module_name:string ->
  seen:Common.StringSet.t ->
  current_layer2_module:string ->
  same_cluster_classes:string list ->
  conflicting_methods:Common.StringSet.t ->
  entity_kind:Filtering.entity_kind ->
  Types.gir_method ->
  string * Common.StringSet.t
(** [generate_method_wrappers ... meth] generates the implementation of a single
    method wrapper for a layer 2 class. [property_method_names] are the OCaml
    names of the property accessors (used to avoid collisions); [seen] is the
    set of already-emitted method names; [conflicting_methods] are method names
    that conflict with parent signatures; [entity_kind] is forwarded to the skip
    filter. Returns the generated code and the updated [seen] set. *)

val generate_method_signatures :
  ctx:Types.generation_context ->
  property_method_names:string list ->
  property_base_names:string list ->
  seen:Common.StringSet.t ->
  current_layer2_module:string ->
  same_cluster_classes:string list ->
  conflicting_methods:Common.StringSet.t ->
  entity_kind:Filtering.entity_kind ->
  Types.gir_method ->
  string * Common.StringSet.t
(** [generate_method_signatures ... meth] generates the type signature of a
    single method for a layer 2 class type definition. Parameters and return
    value are as for [generate_method_wrappers]. *)
