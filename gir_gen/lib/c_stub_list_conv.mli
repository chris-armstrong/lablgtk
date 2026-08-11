(** C code generation for [GList]/[GSList] <-> OCaml list conversion.

    Generates the C snippets that convert between GLib [GList]/[GSList]
    containers and OCaml lists, including element conversion, transfer-ownership
    cleanup, and the length/cleanup handling for list parameters and return
    values. *)

type list_kind = [ `GList | `GSList ]
(** The kind of GLib list container. *)

val list_kind_of_type : Types.gir_type -> list_kind option
(** [list_kind_of_type gir_type] returns [`GList] or [`GSList] when [gir_type]
    denotes a [GList]/[GSList] type, and [None] otherwise. *)

val cleanup_for_in_param :
  list_kind:[< `GList | `GSList ] ->
  element_unref_fn:string ->
  transfer:Types.transfer_ownership ->
  string ->
  string
(** [cleanup_for_in_param ~list_kind ~element_unref_fn ~transfer c_var] emits
    the C cleanup for a list [in]-parameter after the wrapped C call. The stub
    built the list from an OCaml value, so it owns the list nodes and frees
    them; for transfer-full/floating the callee took ownership of the elements,
    so each is unreffed with [element_unref_fn] (e.g. ["g_object_unref"] for
    GObjects, ["g_free"] for boxed/string elements) before the list is freed.
    Returns the C cleanup statement(s). *)

val generate_param_list_conversion :
  ctx:Types.generation_context ->
  ocaml_var:string ->
  gir_type:Types.gir_type ->
  (string * string) option
(** [generate_param_list_conversion ~ctx ~ocaml_var ~gir_type] generates the
    conversion of an OCaml list parameter to a [GList]/[GSList]. Returns the C
    variable name holding the converted list paired with the conversion code, or
    [None] when [gir_type] is not a list type. *)

val generate_return_list_conversion :
  ctx:Types.generation_context ->
  c_var:string ->
  gir_type:Types.gir_type ->
  (string * string * string) option
(** [generate_return_list_conversion ~ctx ~c_var ~gir_type] generates the
    conversion of a [GList]/[GSList] return value to an OCaml list. Returns the
    declaration, conversion body and return statement, or [None] when [gir_type]
    is not a list type. *)
