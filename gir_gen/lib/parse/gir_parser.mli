(* GIR XML parser: turns a `.gir` file into the AST in {!Types}. *)

open Types

val parse_gir_file :
  string ->
  string list ->
  gir_repository
  * gir_namespace
  * gir_class list
  * gir_interface list
  * gir_enum list
  * gir_bitfield list
  * gir_record list
  * gir_constant list
(** Parse a GIR file and return the repository, namespace, and every parsed
    entity.

    [filter_classes], when non-empty, restricts class parsing to the named
    classes. The references pipeline passes an empty list to parse every
    namespace cheaply. *)

val parse_gir_enums_only : string -> gir_enum list * gir_bitfield list
(** Parse only enums and bitfields from a GIR file, for external namespaces
    whose classes and interfaces are never generated. *)
