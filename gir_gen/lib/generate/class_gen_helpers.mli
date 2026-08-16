(** Shared helpers for the class generation modules.

    The [module_names] and [property_filters] record types live in [Common]; the
    functions below return them as [Common.module_names] /
    [Common.property_filters] rather than re-declaring the types here. *)

module StringSet = Common.StringSet
(** Set of strings, shared across the class generation modules so that
    [StringSet.t] values are interchangeable between them. *)

val require_type :
  location:string -> gir_type_name:string -> string option -> string
(** [require_type ~location ~gir_type_name type_opt] returns the resolved type
    string, or fails with a descriptive error when [type_opt] is [None].
    [location] and [gir_type_name] are used in the error message.

    @raise Failure when [type_opt] is [None]. *)

val get_module_names :
  ctx:Types.generation_context -> string -> Common.module_names
(** [get_module_names ~ctx class_name] computes the layer 1 and layer 2 module
    names for [class_name]. *)

val get_property_filters :
  ctx:Types.generation_context ->
  class_name:string ->
  methods:Types.gir_method list ->
  Types.gir_property list ->
  Common.property_filters
(** [get_property_filters ~ctx ~class_name ~methods properties] computes the
    property method-name and base-name filters for [class_name], using [methods]
    to avoid collisions. *)

val has_type_variable : string -> bool
(** Return true when the type string contains a type-variable wildcard (e.g.
    "'a" in "_ Gdk.event"). *)

val resolve_parent_gir_type :
  same_cluster_classes:string list ->
  parent_name:string option ->
  Types.gir_type option
(** [resolve_parent_gir_type ~same_cluster_classes ~parent_name] returns the
    parent's [gir_type], or [None] when the parent is absent or belongs to the
    same cyclic cluster. *)

val should_skip_method :
  ctx:Types.generation_context ->
  entity_kind:Filtering.entity_kind ->
  Types.gir_method ->
  bool
(** [should_skip_method ~ctx ~entity_kind meth] returns [true] when [meth]
    should be skipped: either the central [Filtering.should_skip_method_binding]
    answer is [true], or [meth] has an output parameter. *)
