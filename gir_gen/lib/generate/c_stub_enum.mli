(** C Stub Code Generation - Enum Support *)

val generate_forward_decls :
  namespace_prefix:string -> gtk_enums:Types.gir_enum list -> string
(** [generate_forward_decls ~namespace_prefix ~gtk_enums] generates forward
    declarations for enum converter functions.

    Note: This function only generates declarations for enums in the current
    namespace. External enum declarations are obtained through header inclusion.

    - [namespace_prefix]: The namespace prefix for GTK enum converters
    - [gtk_enums]: List of GTK enums to generate forward declarations for

    Returns a string containing all forward declarations. *)
