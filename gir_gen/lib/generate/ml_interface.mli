(** OCaml Interface (.mli) Generation Layer 1 OCaml interface generation for
    GIR-based bindings. Generates type-safe OCaml interfaces and implementations
    from GObject Introspection (GIR) data with support for:
    - Type declarations with hierarchy-aware variants
    - Constructor, method, and property external bindings
    - Cyclic module generation for inter-dependent classes *)

(** Mode for generating code output *)
type output_mode =
  | Interface  (** Generate .mli interface file *)
  | Implementation  (** Generate .ml implementation file *)

val generate_ml_interface :
  ctx:Types.generation_context ->
  output_mode:output_mode ->
  class_name:string ->
  class_doc:string option ->
  c_type:string ->
  parent_chain:string list ->
  constructors:Types.gir_constructor list option ->
  methods:Types.gir_method list ->
  properties:Types.gir_property list ->
  ?c_symbol_prefix:string ->
  entity_kind:Filtering.entity_kind ->
  ?from_gobject_c_name:string ->
  ?signals:Types.gir_signal list ->
  ?glib_get_type:string ->
  unit ->
  string
(** Generate a complete OCaml interface or implementation module. Handles
    hierarchical type detection, method generation, property bindings, and
    hierarchy accessor methods for GTK class hierarchies.

    Parameters:
    - ctx: Generation context with type mappings and hierarchy info
    - output_mode: Whether to generate interface (.mli) or implementation (.ml)
    - class_name: Name of the class being generated
    - class_doc: Optional documentation string for the class
    - c_type: C type name (e.g., "GtkWidget")
    - parent_chain: List of parent class names for hierarchy
    - constructors: Optional list of constructors to generate
    - methods: List of methods to generate
    - properties: List of properties to generate
    - c_symbol_prefix: Optional C symbol prefix for this class
    - entity_kind: [Filtering.entity_kind] tag identifying whether the entity is
      a Class, Interface, or Record. Forwarded to the central
      [Filtering.should_skip_method_binding] so the record copy/free/unref
      filter is folded into the same answer as varargs/unsupported-arrays etc.
      Does NOT affect the type-declaration shape — records and classes both emit
      [[ \`tag... ] Gobject.obj].
    - from_gobject_c_name: Optional C function name for the from_gobject
      external
    - signals: Optional list of GIR signals to emit as [val on_<sig>] /
      [let on_<sig>] bindings. Defaults to [] for backward compatibility.

    Returns: Generated OCaml source code as a string *)

val generate_combined_ml_modules :
  ctx:Types.generation_context ->
  output_mode:output_mode ->
  entities:Types.entity list ->
  parent_chain_for_entity:(string -> string list) ->
  ?from_gobject_c_name_for_entity:(Types.entity -> string option) ->
  unit ->
  string
(** Generate combined OCaml modules for cyclic dependencies. Creates mutually
    recursive 'module rec' declarations when multiple classes have circular type
    dependencies (e.g., LayoutManager and Widget).

    Parameters:
    - ctx: Generation context with type mappings and hierarchy info
    - output_mode: Whether to generate interface (.mli) or implementation (.ml)
    - entities: List of entities to include in the combined module
    - parent_chain_for_entity: Function returning parent chain for each entity
      name
    - from_gobject_c_name_for_entity: Function returning the C function name for
      the from_gobject external for a given entity, or None if not applicable.
      Each entity in the cycle is queried independently so that only interfaces
      with a glib_type_name emit the external.

    Returns: Generated OCaml source code with 'module rec' declarations *)
