(* Constant Code Generation *)

open Types

val generate_constants_files :
  ctx:generation_context -> namespace:string -> output_dir:string -> unit
(** Generate both <ns>_constants.mli and <ns>_constants.ml under [output_dir]
    for the constants carried by [ctx]. Does nothing when there are no
    constants, so namespaces without constants produce no constants module. *)

val generate_constants_interface :
  namespace:string -> gir_constant list -> string
(** Generate the .mli file content for the constants of a namespace. Returns
    just the file header when [constants] is empty. *)

val generate_constants_implementation :
  namespace:string -> gir_constant list -> string
(** Generate the .ml file content for the constants of a namespace. Returns just
    the file header when [constants] is empty. *)
