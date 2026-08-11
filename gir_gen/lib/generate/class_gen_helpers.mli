(** Shared helpers for the class generation modules. *)

module StringSet = Common.StringSet
(** Set of strings, shared across the class generation modules so that
    [StringSet.t] values are interchangeable between them. *)

type module_names = { layer1 : string; layer2 : string }
(** Names of the generated layer 1 and layer 2 modules for a class. *)

type property_filters = { method_names : string list; base_names : string list }
(** Method-name and base-name filters used to decide which property accessors to
    generate. *)

val require_type :
  location:string -> gir_type_name:string -> string option -> string
(** Extract a resolved OCaml type from an [option], failing with a descriptive
    error when [None].

    Parameters:
    - location: where the resolution was attempted (used in the error message)
    - gir_type_name: the GIR type name being resolved (used in the error
      message)
    - type_opt: the resolved type, if any

    Returns: the resolved type string.

    Raises: [Failure] when [type_opt] is [None]. *)

val get_module_names : ctx:Types.generation_context -> string -> module_names
(** Compute the layer 1 and layer 2 module names for a class.

    Parameters:
    - ctx: generation context
    - class_name: GIR class name

    Returns: the [module_names] record. *)

val get_property_filters :
  ctx:Types.generation_context ->
  class_name:string ->
  methods:Types.gir_method list ->
  Types.gir_property list ->
  property_filters
(** Compute the property method-name and base-name filters for a class.

    Parameters:
    - ctx: generation context
    - class_name: GIR class name
    - methods: the class's methods
    - properties: the class's properties

    Returns: the [property_filters] record. *)

val ocaml_method_name :
  class_name:string -> c_type:string -> Types.gir_method -> string
(** Compute the sanitized OCaml method name for a GIR method.

    Parameters:
    - class_name: GIR class name
    - c_type: C type name of the class
    - meth: the GIR method

    Returns: the sanitized OCaml method name. *)

val has_type_variable : string -> bool
(** Return true when the type string contains a type-variable wildcard (e.g.
    "'a" in "_ Gdk.event"). *)

val resolve_parent_gir_type :
  same_cluster_classes:string list ->
  parent_name:string option ->
  Types.gir_type option
(** Resolve a parent class name to a [gir_type], returning [None] when the
    parent is absent or belongs to the same cyclic cluster.

    Parameters:
    - same_cluster_classes: classes in the same cyclic cluster
    - parent_name: the parent class name, if any

    Returns: the parent's [gir_type], or [None]. *)

val should_skip_method :
  ctx:Types.generation_context ->
  entity_kind:Filtering.entity_kind ->
  Types.gir_method ->
  bool
(** Return true when a method should be skipped during generation: either the
    central [Filtering.should_skip_method_binding] answer or the method has an
    output parameter.

    Parameters:
    - ctx: generation context
    - entity_kind: entity kind, forwarded to the skip filter
    - meth: the GIR method

    Returns: true when the method should be skipped. *)
