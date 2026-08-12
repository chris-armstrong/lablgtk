(** Apply parsed overrides to GIR data structures.

    Filters out ignored entities and components, and applies version overrides.
    This must be called before building the type-mapping context ([ctx]) so that
    ignored entities are absent from the context — this causes methods that
    reference ignored types to be skipped by existing unknown-type checks. *)

type apply_result = {
  classes : Types.gir_class list;
      (** Classes remaining after overrides (ignored classes filtered out). *)
  interfaces : Types.gir_interface list;
      (** Interfaces remaining after overrides. *)
  enums : Types.gir_enum list;  (** Enums remaining after overrides. *)
  bitfields : Types.gir_bitfield list;
      (** Bitfields remaining after overrides. *)
  records : Types.gir_record list;  (** Records remaining after overrides. *)
  functions : Types.gir_function list;
      (** Standalone namespace-level functions. *)
  ignored_entities : string list;
      (** Names of ignored entities, for logging. *)
  warnings : string list;
      (** Warnings for unknown entity/component names (typos). *)
}
(** Result of applying overrides. *)

val apply_overrides :
  overrides:Override_types.library_overrides ->
  classes:Types.gir_class list ->
  interfaces:Types.gir_interface list ->
  enums:Types.gir_enum list ->
  bitfields:Types.gir_bitfield list ->
  records:Types.gir_record list ->
  functions:Types.gir_function list ->
  apply_result
(** Apply overrides to parsed GIR data. Filters out ignored entities and applies
    version overrides to remaining ones.

    ORDERING: This must be called before building the type-mapping context
    (ctx). Ignored entities must be absent from ctx so that
    [find_type_mapping_for_gir_type] returns [None] for their types, causing
    methods that reference them to be skipped by the existing unknown-type
    checks in filtering.ml. *)
