(** C stub code generation — top-level orchestration.

    Entry points used by the [gir_gen] CLI to emit the shared declarations
    header and the per-namespace dependency plumbing. *)

val base_namespaces : string list
(** Namespaces that are never treated as cross-namespace dependencies (["GLib"],
    ["GModule"], ["GObject"], ["HarfBuzz"]). *)

val get_dependency_namespaces : string list -> string list
(** [get_dependency_namespaces namespace_names] returns the subset of
    [namespace_names] that are treated as cross-namespace dependencies: every
    name except {!base_namespaces}, sorted and deduplicated. Callers pass the
    keys of the cross-references map (only the keys are needed). Returns the
    sorted, unique dependency namespace names. *)

val generate_decls_header :
  ctx:Types.generation_context ->
  classes:Types.gir_class list ->
  interfaces:Types.gir_interface list ->
  gtk_enums:Types.gir_enum list ->
  gtk_bitfields:Types.gir_bitfield list ->
  records:Types.gir_record list ->
  ?header_overrides:Override_types.header_override list ->
  unit ->
  string
(** [generate_decls_header ~ctx ~classes ~interfaces ~gtk_enums ~gtk_bitfields
     ~records ?header_overrides ()] generates the shared [<ns>_decls.h] header:
    include guards, repository C includes (optionally OS-guarded via
    [header_overrides]), dependency header includes, forward declarations for
    classes, interfaces, records, enums and bitfields, and the
    [ML_DECL_CONST_STRING] macro. Returns the complete header file contents. *)
