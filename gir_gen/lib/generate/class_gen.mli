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
(** Generate the full layer 2 class module (class type definition, class
    implementation, and constructor wrappers) as a string.

    Parameters:
    - ctx: generation context
    - class_name: GIR class name
    - c_type: C type name of the class
    - parent_chain: transitive parent chain, immediate parent first
    - methods: the class's methods
    - entity_kind: entity kind, forwarded to the skip filter
    - properties: the class's properties
    - signals: the class's signals
    - constructors: the class's constructors

    Returns: the generated OCaml source code. *)

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
(** Generate the layer 2 class signature (class type definition, class
    declaration, and constructor wrapper signatures) as a string.

    Parameters are as for [generate_class_module].

    Returns: the generated OCaml source code. *)

val generate_combined_class_module :
  ctx:Types.generation_context ->
  combined_module_name:string ->
  entities:Types.entity list ->
  parent_chain_for_entity:(string -> string list) ->
  string
(** Generate a combined class module for cyclic dependencies: mutually recursive
    class types and implementations, followed by constructor wrappers for each
    entity.

    Parameters:
    - ctx: generation context
    - combined_module_name: name of the combined module (e.g. "GtkWindow")
    - entities: the entities in the cycle
    - parent_chain_for_entity: function returning the parent chain for each
      entity name

    Returns: the generated OCaml source code. *)

val generate_combined_class_signature :
  ctx:Types.generation_context ->
  combined_module_name:string ->
  entities:Types.entity list ->
  parent_chain_for_entity:(string -> string list) ->
  string
(** Generate a combined class signature for cyclic dependencies: mutually
    recursive class type definitions and class declarations, followed by
    constructor wrapper signatures for each entity.

    Parameters are as for [generate_combined_class_module].

    Returns: the generated OCaml source code. *)

val generate_cyclic_shim_module :
  ctx:Types.generation_context ->
  entity:Types.entity ->
  combined_module_name:string ->
  g_combined_module_name:string ->
  string
(** Generate a shim module that re-exports a class from a combined cyclic
    module, plus constructor wrappers.

    Parameters:
    - ctx: generation context
    - entity: the entity to re-export
    - combined_module_name: name of the combined module
    - g_combined_module_name: name of the generated combined module

    Returns: the generated OCaml source code. *)

val generate_cyclic_shim_signature :
  ctx:Types.generation_context ->
  entity:Types.entity ->
  combined_module_name:string ->
  g_combined_module_name:string ->
  string
(** Generate a shim signature that re-exports a class from a combined cyclic
    module, plus constructor wrapper signatures.

    Parameters are as for [generate_cyclic_shim_module].

    Returns: the generated OCaml source code. *)
