(** High-level class generation (Step 3): orchestration of layer 2 class
    modules, class signatures, combined cyclic modules, and cyclic shims. *)

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
(** [generate_class_module ...] generates the full layer 2 class module (class
    type definition, class implementation, and constructor wrappers) as a
    string. [parent_chain] is the transitive parent chain, immediate parent
    first; [entity_kind] is forwarded to the skip filter. *)

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
(** [generate_class_signature ...] generates the layer 2 class signature (class
    type definition, class declaration, and constructor wrapper signatures) as a
    string. Parameters are as for [generate_class_module]. *)

val generate_combined_class_module :
  ctx:Types.generation_context ->
  combined_module_name:string ->
  entities:Types.entity list ->
  parent_chain_for_entity:(string -> string list) ->
  string
(** [generate_combined_class_module ...] generates a combined class module for
    cyclic dependencies: mutually recursive class types and implementations,
    followed by constructor wrappers for each entity. [parent_chain_for_entity]
    returns the parent chain for a given entity name. *)

val generate_combined_class_signature :
  ctx:Types.generation_context ->
  combined_module_name:string ->
  entities:Types.entity list ->
  parent_chain_for_entity:(string -> string list) ->
  string
(** [generate_combined_class_signature ...] generates a combined class signature
    for cyclic dependencies: mutually recursive class type definitions and class
    declarations, followed by constructor wrapper signatures for each entity.
    Parameters are as for [generate_combined_class_module]. *)

val generate_cyclic_shim_module :
  ctx:Types.generation_context ->
  entity:Types.entity ->
  combined_module_name:string ->
  g_combined_module_name:string ->
  string
(** [generate_cyclic_shim_module ...] generates a shim module that re-exports a
    class from a combined cyclic module, plus constructor wrappers. *)

val generate_cyclic_shim_signature :
  ctx:Types.generation_context ->
  entity:Types.entity ->
  combined_module_name:string ->
  g_combined_module_name:string ->
  string
(** [generate_cyclic_shim_signature ...] generates a shim signature that
    re-exports a class from a combined cyclic module, plus constructor wrapper
    signatures. Parameters are as for [generate_cyclic_shim_module]. *)
