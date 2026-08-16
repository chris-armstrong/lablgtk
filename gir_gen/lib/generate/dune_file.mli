(** Dune file generation for generated C stub libraries.

    Emits the [dune] stanza that builds the generated C stubs for one namespace,
    including the pkg-config rule and (for large namespaces) the batched stub
    libraries behind a public facade. *)

val generate_dune_library :
  ctx:Types.generation_context ->
  lib_name:string ->
  stub_names:string list ->
  repository:Types.gir_repository ->
  string
(** [generate_dune_library ~ctx ~lib_name ~stub_names ~repository] generates the
    dune library stanza for the generated C stubs of namespace [lib_name].

    Collects pkg-config packages transitively (following cross-namespace
    includes), emits the pkg-config rule producing the cflag/clink sexp files,
    and emits either a single stubs library or, when [stub_names] exceeds the
    batch size, one library per batch plus a public facade library. Returns the
    complete dune file contents. *)
