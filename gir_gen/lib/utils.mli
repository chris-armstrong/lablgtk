(* Utility Functions for GIR Code Generator *)

val to_snake_case : string -> string
(** Convert a CamelCase name to snake_case, e.g. "TextView" -> "text_view".
    Leading digits are prefixed with "x" to make valid OCaml identifiers. *)

val sanitize_doc : string -> string
(** Sanitize a GIR documentation string so it cannot terminate an OCaml comment
    early: escapes "*)" and "(*" sequences. *)

val parse_bool : ?default:bool -> string option -> bool
(** [parse_bool ?default attr] parses a boolean attribute value: [true] for
    ["true"]/["1"], [false] for ["false"]/["0"], and [default] for empty or
    missing attributes.

    @raise Failure for any other value. *)

val is_void_return_type : Types.gir_type -> bool
(** Check whether a GIR type represents a void/unit return type. Matches name
    "void"/"none" or c:type "void". *)

val normalize_class_name : string -> string
(** Normalize a GIR class name for comparisons: strips a leading namespace
    ("Gtk.") and the "Gtk" prefix, e.g. "GtkTextView" -> "TextView". *)

val module_name_of_class : string -> string
(** Convert a class name to the expected OCaml module name (file name
    capitalized), e.g. "TextView" -> "Text_view". *)

val internal_namespace_to_module_name : string -> string
(** Convert an internal namespace name to a dune-compliant module name:
    lowercases all characters after the first, e.g. "GdkPixbuf" -> "Gdkpixbuf".
*)

val library_wrapper_name : string -> string
(** Convert a namespace name to the dune library wrapper name, e.g. "Cairo" ->
    "ocgtk_cairo". *)

val external_namespace_to_module_name : string -> string
(** Convert a namespace name to a fully-qualified module path for external
    references, e.g. "Cairo" -> "Ocgtk_cairo.Cairo". *)

val enums_module_name : Types.generation_context -> Types.gir_enum -> string
(** Get the name of the enums module for a namespace, e.g. "Gtk_enums". *)

val bitfields_module_name :
  Types.generation_context -> Types.gir_bitfield -> string
(** Get the name of the bitfields module for a namespace, e.g. "Gtk_enums". *)

val read_filter_file : string -> string list
(** Read a filter file and return the list of class names to generate. Empty
    lines and lines starting with "#" are skipped; only the first word of each
    line is kept. Returns [] if the file does not exist. *)

val sanitize_identifier : string -> string
(** Append "_" to an OCaml reserved word so it can be used as an identifier,
    e.g. "end" -> "end_". *)

val sanitize_property_name : string -> string
(** Sanitize a property name: escape reserved words, replace "-" with "_", and
    convert to snake_case. *)

val ocaml_function_name : string -> string
(** Convert a method name to a valid OCaml function name. *)

val ocaml_method_name : Types.gir_method -> string
(** Convert a GIR method to its OCaml method name: kebab-to-snake, snake_case,
    and reserved-word escaping. Mirrors [ocaml_constructor_name]; see
    [ocaml_function_name] for the string-level equivalent. *)

val ocaml_property_name : string -> string
(** Calculate a property name without sanitizing the identifier (get_/set_
    prefixes are added by callers). *)

val ocaml_parameter_name : string -> string
(** Convert a parameter name to a valid OCaml identifier. *)

val ocaml_class_name : string -> string
(** Convert a class name to its OCaml name, e.g. "GtkTextView" -> "text_view".
*)

val ocaml_interface_name : string -> string
(** Convert an interface name to its OCaml name (same as classes). *)

val ocaml_record_name : string -> string
(** Convert a record name to its OCaml name (same as classes). *)

val gtype_macro_of_type_name : string -> string
(** Convert a GLib type name (e.g. "GtkEditable") to a GType macro constant
    (e.g. "GTK_TYPE_EDITABLE"). *)

val cast_macro_of_type_name : string -> string
(** Convert a GLib type name (e.g. "GtkEditable") to its GObject cast macro
    (e.g. "GTK_EDITABLE"). *)

val ocaml_constructor_name : Types.gir_constructor -> string
(** Convert a constructor name to a valid OCaml identifier. *)

val ml_constructor_name : constructor:Types.gir_constructor -> string
(** Build the C binding name for a constructor by prepending "ml_" to its
    c_identifier. *)

val ml_method_name : Types.gir_method -> string
(** Build the C binding name for a method by prepending "ml_" to its
    c_identifier. *)

val ml_property_name :
  ctx:Types.generation_context ->
  class_name:string ->
  Types.gir_property ->
  string
(** Build the C binding name for a property getter, e.g.
    "ml_gtk_widget_get_visible". *)

val ml_property_setter_name :
  ctx:Types.generation_context ->
  class_name:string ->
  Types.gir_property ->
  string
(** Build the C binding name for a property setter, e.g.
    "ml_gtk_widget_set_visible". *)

val ocaml_bitfield_name : Types.gir_bitfield -> string
(** Convert a bitfield name to its OCaml name (lowercased). *)

val ocaml_enum_name : Types.gir_enum -> string
(** Convert an enum name to its OCaml name (lowercased). *)

val layer2_module_name : string -> string
(** Layer 2 module name for a class: "G" ^ module name, e.g. "Button" ->
    "GButton". *)

val layer2_module_filename : string -> string
(** Layer 2 module filename (lowercase first char), e.g. "Button" -> "gButton".
*)

val class_type_name : string -> string
(** Class type name with _t suffix, e.g. "Button" -> "button_t". *)

val name_to_parts : ctx:Types.generation_context -> string -> string * string
(** [name_to_parts ~ctx name] splits a qualified GIR name into
    [(namespace, name)]. Unqualified names are assumed to belong to [ctx]'s
    namespace.

    @raise Failure if the name has more than one ["."] separator. *)
