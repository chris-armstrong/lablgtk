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
(** [generate_ml_interface ... ()] generates a complete OCaml interface or
    implementation module. [output_mode] selects [.mli] vs [.ml]; [parent_chain]
    is the list of parent class names; [entity_kind] is forwarded to the central
    [Filtering.should_skip_method_binding] so the record copy/free/unref filter
    is folded in with varargs/unsupported-arrays etc. (it does not affect the
    type-declaration shape). [signals] defaults to [[]] for backward
    compatibility. Returns the generated OCaml source code. *)

val generate_combined_ml_modules :
  ctx:Types.generation_context ->
  output_mode:output_mode ->
  entities:Types.entity list ->
  parent_chain_for_entity:(string -> string list) ->
  ?from_gobject_c_name_for_entity:(Types.entity -> string option) ->
  unit ->
  string
(** [generate_combined_ml_modules ... ()] generates combined OCaml modules for
    cyclic dependencies: mutually recursive ['module rec'] declarations when
    multiple classes have circular type dependencies (e.g. LayoutManager and
    Widget). [parent_chain_for_entity] returns the parent chain for a given
    entity name; [from_gobject_c_name_for_entity] returns the C function name
    for the from_gobject external for a given entity, or [None] if not
    applicable (each entity is queried independently so only interfaces with a
    [glib_type_name] emit the external). Returns the generated OCaml source code
    with ['module rec'] declarations. *)
