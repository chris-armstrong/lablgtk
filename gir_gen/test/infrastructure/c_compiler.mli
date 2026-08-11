(** OCaml-configured C compiler discovery for pipeline tests.

    Pipeline tests that need to invoke a C compiler use this module so they pick
    up the same compiler the OCaml toolchain was built with. *)

val path : unit -> string
(** [path ()] returns the C compiler path reported by [ocamlopt -config] (the
    [c_compiler:] field). The result is cached for the lifetime of the test run.
    Raises [Failure] if [ocamlopt -config] cannot be parsed. *)
