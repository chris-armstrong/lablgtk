(* Utilities for class generation. *)

val get_qualified_module_name : ctx:Types.generation_context -> string -> string
(** Return the fully qualified module name for a class, accounting for cyclic
    module groups: classes in a cyclic group are addressed as
    [CombinedModule.ClassName], all others by their plain module name. *)
