(** Enum and bitfield code generation.

    Emits the OCaml type definitions and converter functions for GIR enums and
    bitfields, plus the C converter functions used by the generated stubs. *)

val generate_ocaml_enum : Types.gir_enum -> string
(** [generate_ocaml_enum enum] generates the OCaml polymorphic-variant type
    definition for [enum] together with [<name>_of_int] / [<name>_to_int] val
    declarations. *)

val generate_ocaml_bitfield : Types.gir_bitfield -> string
(** [generate_ocaml_bitfield bitfield] generates the OCaml polymorphic-variant
    flag type and list type for [bitfield] together with [<name>_of_int] /
    [<name>_to_int] val declarations. *)

val generate_c_enum_converters :
  namespace:string -> class_version:string option -> Types.gir_enum -> string
(** [generate_c_enum_converters ~namespace ~class_version enum] generates the C
    functions converting between the enum's C value and an OCaml variant tag
    ([Val_<ns><Enum>] and [<ns><Enum>_val]). [class_version] is the entity-level
    version for the outer guard, if any. Members with a version are wrapped in C
    preprocessor guards. Returns the C source, or [""] when the enum has no
    members. *)

val generate_c_bitfield_converters :
  namespace:string ->
  class_version:string option ->
  Types.gir_bitfield ->
  string
(** [generate_c_bitfield_converters ~namespace ~class_version bitfield]
    generates the C functions converting between the bitfield's C flags value
    and an OCaml list of variant tags ([Val_<ns><Bitfield>] and
    [<ns><Bitfield>_val]). [class_version] is the entity-level version for the
    outer guard, if any. Flags with a version are wrapped in C preprocessor
    guards. Returns the C source, or [""] when the bitfield has no flags. *)

val generate_ocaml_enum_impl : Types.gir_enum -> string
(** [generate_ocaml_enum_impl enum] generates the pure-OCaml implementation of
    [<name>_of_int] and [<name>_to_int] for [enum]. [<name>_of_int] raises
    [Failure] on unknown integer values; members with duplicate values emit a
    single arm (first occurrence wins). Returns the OCaml implementation source,
    or [""] when the enum has no members. *)

val generate_ocaml_bitfield_impl : Types.gir_bitfield -> string
(** [generate_ocaml_bitfield_impl bitfield] generates the pure-OCaml
    implementation of [<name>_of_int] and [<name>_to_int] for [bitfield].
    [<name>_of_int] tests each known bit and accumulates the matching tags;
    [<name>_to_int] folds the tag list with [lor]. Returns the OCaml
    implementation source, or [""] when the bitfield has no flags. *)
