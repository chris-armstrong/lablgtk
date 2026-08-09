(* Type Mappings for GIR Code Generator *)

val type_mappings : (string * Types.type_mapping) list
(** Hardcoded type mappings for built-in / primitive types (integers, strings,
    etc.), keyed by GIR type name. Consulted as a fallback when a type is not
    found in the current namespace or in cross-references. *)

val normalize_c_pointer_type : string -> string
(** Strip "const" qualifiers and trailing whitespace from a C pointer type
    string, e.g. ["const gchar*"] -> ["gchar*"]. *)

val lookup_class :
  classes:Types.gir_class list -> lookup_str:string -> Types.gir_class option
(** Find a class mapping in the current namespace by name or C type.

    @param classes classes to search
    @param lookup_str GIR name or C type name (with or without "*" suffix)
    @return the matching class, if any *)

val is_boxed_record : Types.gir_record -> bool
(** Check whether a record is a GObject boxed type: it has a [glib:get-type] or
    [glib:type-name] and is not disguised. *)

val lookup_record :
  records:Types.gir_record list ->
  lookup_str:string ->
  (Types.gir_record * bool * bool) option
(** Find a record mapping in the current namespace by name or C type.

    @param records records to search
    @param lookup_str GIR name or C type name
    @return
      the matching record, whether the lookup string was a pointer type, and
      whether the record is boxed, if found *)

val calculate_class_or_interface_or_record_module_name :
  ctx:Types.generation_context -> name:string -> string
(** Compute the Layer 1 module path for a class, interface, or record name,
    taking cyclic module groups into account. *)

(** The kind of a GIR type, as determined by [classify_type]. *)
type type_kind =
  | Tk_Enum
  | Tk_Bitfield
  | Tk_Class
  | Tk_Interface
  | Tk_Record
  | Tk_Primitive
  | Tk_Unknown

val classify_type : ctx:Types.generation_context -> Types.gir_type -> type_kind
(** Classify a GIR type as an enum, bitfield, class, interface, record,
    primitive, or unknown, searching the current namespace, cross-references,
    and hardcoded mappings in that order. *)

val find_type_mapping_for_gir_type :
  ctx:Types.generation_context -> Types.gir_type -> Types.type_mapping option
(** Resolve a GIR type to a full type mapping, handling lists, arrays, and plain
    types. Returns [None] if the type cannot be resolved.

    @param ctx generation context
    @param gir_type the GIR type to resolve
    @return the type mapping, or [None] if the type is unknown *)

val simplify_self_reference : class_name:string -> ocaml_type:string -> string
(** Simplify type references that refer to the current module's own type.
    Converts patterns like ["CurrentModule.t"] or ["CurrentModule.t option"] to
    ["t"] or ["t option"]. Handles common type wrappers like "option" and
    "array", and combinations.

    @param class_name name of the class being generated
    @param ocaml_type the OCaml type expression to simplify
    @return the simplified type expression *)
