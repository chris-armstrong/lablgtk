(* Top-level library module generation: emits the `<Ns>.ml/.mli` that
   re-exports every class/interface/record (including cyclic combined modules)
   and the enum/bitfield type aliases for one namespace. *)

open Types

val generate_library_module : ctx:generation_context -> string * string
(** Generate both the .ml and .mli content for a namespace's top-level library
    module, returned as [(ml, mli)]. *)
