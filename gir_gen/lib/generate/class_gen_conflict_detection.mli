(* Method conflict detection for class generation. *)

val sanitize_name : string -> string
(** Sanitize a class/enum name into a valid OCaml identifier. *)

val detect_method_conflicts :
  ctx:Types.generation_context ->
  class_name:string ->
  methods:Types.gir_method list ->
  Common.StringSet.t
(** Return the set of OCaml method names of [methods] that conflict with methods
    inherited from the parent chain. *)

val parent_chain_provides_interface :
  ctx:Types.generation_context -> class_name:string -> string -> bool
(** Return true when any class in the transitive parent chain of [class_name]
    lists [iface_name] in its implements. *)

val collect_inherited_method_names :
  ctx:Types.generation_context -> class_name:string -> Common.StringSet.t
(** Collect all OCaml method names inherited from ancestors: methods, property
    accessors, and methods of implemented interfaces. *)
