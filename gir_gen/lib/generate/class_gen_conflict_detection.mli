(* Method conflict detection for class generation. *)

module StringSet = Common.StringSet

type module_names = Common.module_names
type property_filters = Common.property_filters

val sanitize_name : string -> string
(** Sanitize a class/enum name into a valid OCaml identifier. *)

val ocaml_method_name : class_name:'a -> c_type:'b -> Types.gir_method -> string
(** Compute the sanitized OCaml method name for a GIR method. *)

val method_signature_for_comparison : Types.gir_method -> string
(** Build a comparable signature string for a method (name, parameter types,
    return type). *)

val get_class_methods :
  ctx:Types.generation_context -> string -> Types.gir_method list
(** Return all methods of the class with the given name, or [] if absent. *)

val get_parent_name_opt :
  ctx:Types.generation_context -> string -> string option
(** Return the parent class name of the given class, if any. *)

val build_parent_chain : ctx:Types.generation_context -> string -> string list
(** Build the transitive parent chain of a class, immediate parent first. *)

val map_parent_methods_to_pairs :
  ctx:Types.generation_context -> string -> (string * Types.gir_method) list
(** Map a parent class to its [(parent_name, method)] pairs. *)

val get_parent_methods :
  ctx:Types.generation_context ->
  parent_chain:string list ->
  (string * Types.gir_method) list
(** Collect all methods from the parent chain as [(parent_name, method)] pairs.
*)

val methods_have_signature_conflict :
  ctx:'a ->
  class_name:'b ->
  c_type:'c ->
  Types.gir_method ->
  Types.gir_method ->
  bool
(** Return true when two methods map to the same OCaml name but have different
    signatures. [ctx] is unused. *)

val check_parent_conflict :
  ctx:'a ->
  class_name:'b ->
  c_type:'c ->
  Types.gir_method ->
  StringSet.t ->
  'd * Types.gir_method ->
  StringSet.t
(** Add the child method's OCaml name to [acc] when it conflicts with the given
    parent method. *)

val process_child_against_parents :
  ctx:'a ->
  class_name:'b ->
  c_type:'c ->
  ('d * Types.gir_method) list ->
  StringSet.t ->
  Types.gir_method ->
  StringSet.t
(** Fold [check_parent_conflict] over all parent methods for one child method.
*)

val detect_method_conflicts :
  ctx:Types.generation_context ->
  class_name:StdLabels.String.t ->
  c_type:'a ->
  methods:Types.gir_method list ->
  StringSet.t
(** Return the set of OCaml method names of [methods] that conflict with methods
    inherited from the parent chain. *)

val get_class_properties :
  ctx:Types.generation_context -> string -> Types.gir_property list
(** Return all properties of the class with the given name, or [] if absent. *)

val property_method_names : Types.gir_property -> string list
(** OCaml method names generated for a property: the getter, plus the setter
    when the property is writable. *)

val lookup_cross_ns_class :
  ctx:Types.generation_context -> string -> Types.cross_reference_type option
(** Look up a cross-namespace class entry by "Namespace.Name" in the
    cross-references map. *)

val bare_name : string -> string
(** Strip the namespace qualifier from a name, e.g. "Gio.ActionGroup" ->
    "ActionGroup". *)

val iface_names_match : iface_name:string -> string -> bool
(** Return true when [iface_name] and [candidate] refer to the same interface,
    comparing bare names to handle mixed qualified/unqualified forms. *)

val cross_ns_class_provides_interface :
  ctx:Types.generation_context ->
  depth:int ->
  ns:string ->
  string ->
  string ->
  bool
(** Return true when the cross-namespace class [qualified_class_name] (or any of
    its ancestors) provides [iface_name]. Depth-limited to avoid loops on
    malformed data. *)

val parent_chain_provides_interface :
  ctx:Types.generation_context -> class_name:string -> string -> bool
(** Return true when any class in the transitive parent chain of [class_name]
    lists [iface_name] in its implements. *)

val collect_inherited_method_names :
  ctx:Types.generation_context -> class_name:string -> StringSet.t
(** Collect all OCaml method names inherited from ancestors: methods, property
    accessors, and methods of implemented interfaces. *)
