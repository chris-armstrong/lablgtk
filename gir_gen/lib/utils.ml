(* Utility Functions for GIR Code Generator *)

open StdLabels

let stripLeadingNumbers name =
  if String.length name = 0 then name
  else
    match name.[0] with
    | '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' ->
        {js|x|js} ^ name
    | _ -> name

(* Convert CamelCase to snake_case *)
let uppercaseStartRe = Re.Str.regexp "^\\([A-Z]*\\)\\(.*\\)$"

let uppercaseRe =
  Re.Str.regexp "\\([A-Z][A-Z0-9]+[A-Z]\\|[A-Z]+\\)\\([^A-Z]*\\)"

(** Convert a CamelCase name to snake_case, e.g. "TextView" -> "text_view".
    Leading digits are prefixed with "x" to make valid OCaml identifiers. *)
let to_snake_case name =
  let start_pos = ref 0 in
  let name_len = String.length name in
  let components : string list ref = ref [] in

  while !start_pos < name_len do
    try
      let next_pos = Re.Str.search_forward uppercaseRe name !start_pos in
      if not (Int.equal next_pos !start_pos) then begin
        (*first section not uppercase - add first section as_is*)
        let len = next_pos - !start_pos in
        let group = String.sub ~pos:!start_pos ~len name in
        components := group :: !components;
        start_pos := next_pos
      end;

      let upperpart = Re.Str.matched_group 1 name in
      let lowerpart = Re.Str.matched_group 2 name in
      if String.length upperpart > 1 then (
        (* sequence of uppercase characters - convert all but one to their own group *)
        let group_len = String.length upperpart - 1 in
        let group =
          Re.Str.string_before upperpart group_len |> String.lowercase_ascii
        in
        components := group :: !components;
        start_pos := !start_pos + group_len)
      else
        (* one uppercase followed by some not-upper *)
        let group_len = String.length lowerpart + 1 in
        let group = String.lowercase_ascii upperpart ^ lowerpart in
        components := group :: !components;
        start_pos := !start_pos + group_len
    with Stdlib.Not_found ->
      components := Re.Str.string_after name !start_pos :: !components;
      start_pos := name_len + 1
  done;
  !components |> List.rev |> String.concat ~sep:"_" |> stripLeadingNumbers

(** Sanitize a GIR documentation string so it cannot terminate an OCaml comment
    early: escapes "*)" and "(*" sequences. *)
let sanitize_doc s =
  (* Prevent premature comment termination when GIR doc contains "*\)" or "(\*" *)
  (* Insert backslash BETWEEN the characters to break the sequence: *\) becomes *\\) and (\* becomes (\\* *)
  Re.replace (Re.compile (Re.str "*)")) ~all:true ~f:(fun _ -> "*\\)") s
  |> Re.replace (Re.compile (Re.str "(*")) ~all:true ~f:(fun _ -> "(\\*")

(* let b = Buffer.create (String.length s + 10) in
  for i = 0 to String.length s - 1 do
    let c = String.get s i in
    if i > 0 && c >= 'A' && c <= 'Z' then
      Buffer.add_char b '_';
    Buffer.add_char b (Char.lowercase_ascii c)
  done;
  Buffer.contents b *)

(* Get attribute value from XML attributes list *)
let get_attr name attrs =
  let glib_ns = "http://www.gtk.org/introspection/glib/1.0" in
  try List.assoc ("", name) attrs |> fun x -> Some x
  with Not_found -> (
    (* Try with c: namespace *)
    try
      List.assoc
        ( "http://www.gtk.org/introspection/c/1.0",
          String.sub ~pos:2 ~len:(String.length name - 2) name )
        attrs
      |> fun x -> Some x
    with Not_found -> (
      (* Try with glib namespace (used for signals and annotations) *)
      try List.assoc (glib_ns, name) attrs |> fun x -> Some x
      with Not_found -> None))

(** Parse a boolean attribute value. [default] is used for empty or missing
    attributes; any other value raises [Failure]. *)
let parse_bool ?(default = false) attr =
  match attr with
  | Some "true" | Some "1" -> true
  | Some "false" | Some "0" -> false
  | Some "" -> default
  | Some x -> failwith (Fmt.str "Invalid boolean attribute value: %s" x)
  | None -> default

(** Check whether a GIR type represents a void/unit return type. In GIR XML,
    void returns can be represented as:
    - name="void" (synthesized by parser in some cases)
    - name="none" (actual GIR data for void returns)
    - c:type="void" This helper centralizes the check to ensure consistency
      across the codebase. *)
let is_void_return_type (gir_type : Types.gir_type) : bool =
  let name = String.lowercase_ascii gir_type.name in
  let c_type =
    Option.value ~default:"" gir_type.c_type |> String.lowercase_ascii
  in
  String.equal name "void" || String.equal name "none"
  || String.equal c_type "void"

(* Extract namespace from C type name (e.g., "GtkAlign" -> "Gtk", "GdkGravity" -> "Gdk") *)
let extract_namespace_from_c_type c_type =
  let prefixes =
    [
      "Gtk";
      "Gdk";
      "Pango";
      "Gio";
      "GLib";
      "GObject";
      "Graphene";
      "GdkPixbuf";
      "Gsk";
    ]
  in
  List.find_opt
    ~f:(fun prefix ->
      String.length c_type >= String.length prefix
      && String.equal
           (String.sub c_type ~pos:0 ~len:(String.length prefix))
           prefix)
    prefixes

(** Normalize a GIR class name for comparisons: strips a leading namespace
    ("Gtk.") and the "Gtk" prefix, e.g. "GtkTextView" -> "TextView". *)
let normalize_class_name name =
  let without_namespace =
    try
      let dot_idx = String.rindex name '.' in
      String.sub name ~pos:(dot_idx + 1) ~len:(String.length name - dot_idx - 1)
    with Not_found -> name
  in
  if
    String.length without_namespace > 3
    && String.equal (String.sub without_namespace ~pos:0 ~len:3) "Gtk"
    &&
    (* Avoid stripping short names like "Gtl" accidentally *)
    let c = String.get without_namespace 3 in
    Char.uppercase_ascii c = c
  then
    String.sub without_namespace ~pos:3
      ~len:(String.length without_namespace - 3)
  else without_namespace

(** Convert a class name to the expected OCaml module name (file name
    capitalized), e.g. "TextView" -> "Text_view". *)
let module_name_of_class class_name =
  class_name |> to_snake_case |> String.capitalize_ascii

(** Convert an internal namespace name to a dune-compliant module name (used
    within the same namespace). Dune lowercases all characters after the first,
    so "GdkPixbuf" becomes "Gdkpixbuf". This is needed because dune
    automatically derives module names from filenames, and the build system
    enforces this capitalization convention. *)
let internal_namespace_to_module_name (namespace : string) : string =
  if String.length namespace = 0 then namespace
  else
    let first = String.capitalize_ascii (String.sub namespace ~pos:0 ~len:1) in
    let rest =
      String.lowercase_ascii
        (String.sub namespace ~pos:1 ~len:(String.length namespace - 1))
    in
    first ^ rest

(** Convert a namespace name to the dune library wrapper name. This is the
    lowercase form used for filenames and dune library names. e.g., "Cairo" ->
    "ocgtk_cairo", "PangoCairo" -> "ocgtk_pangocairo" *)
let library_wrapper_name (namespace : string) : string =
  "ocgtk_" ^ String.lowercase_ascii namespace

(** Convert a namespace name to a fully-qualified module path for external
    references. The wrapper module re-exports the library module as a submodule,
    so the path is [Ocgtk_<ns>.<Ns>]. e.g., "Cairo" -> "Ocgtk_cairo.Cairo",
    "Gdk" -> "Ocgtk_gdk.Gdk", "GdkPixbuf" -> "Ocgtk_gdkpixbuf.GdkPixbuf" *)
let external_namespace_to_module_name (namespace : string) : string =
  String.capitalize_ascii (library_wrapper_name namespace)
  ^ "."
  ^ String.capitalize_ascii namespace

(* Get the name of the enums module (FIXME: doesn't handle cross-namespace enums) *)
let enums_module_name (ctx : Types.generation_context) (_ : Types.gir_enum) =
  internal_namespace_to_module_name ctx.namespace.namespace_name ^ "_enums"

(* Get the name of the bitfields module (FIXME: doesn't handle cross-namespace enums) *)
let bitfields_module_name (ctx : Types.generation_context)
    (_ : Types.gir_bitfield) =
  internal_namespace_to_module_name ctx.namespace.namespace_name ^ "_enums"

(** Read a filter file and return the list of class names to generate. Empty
    lines and lines starting with "#" are skipped; only the first word of each
    line is kept. Returns [] if the file does not exist. *)
let read_filter_file filename =
  if not (Sys.file_exists filename) then []
  else
    let ic = open_in filename in
    let rec read_lines acc =
      try
        let line = input_line ic in
        let trimmed = String.trim line in
        (* Skip empty lines and comments *)
        if
          String.equal trimmed ""
          || (String.length trimmed > 0 && trimmed.[0] = '#')
        then read_lines acc
        else
          (* Extract class name (first word) *)
          let class_name =
            try
              let space_idx = String.index trimmed ' ' in
              String.sub trimmed ~pos:0 ~len:space_idx
            with Not_found -> trimmed
          in
          read_lines (class_name :: acc)
      with End_of_file ->
        close_in ic;
        List.rev acc
    in
    read_lines []

let reserved_identifiers =
  [
    "and";
    "as";
    "assert";
    "begin";
    "class";
    "constraint";
    "do";
    "done";
    "downto";
    "else";
    "end";
    "exception";
    "external";
    "false";
    "for";
    "fun";
    "function";
    "functor";
    "if";
    "in";
    "include";
    "inherit";
    "initializer";
    "land";
    "lazy";
    "let";
    "lor";
    "lsl";
    "lsr";
    "lxor";
    "match";
    "method";
    "mod";
    "module";
    "mutable";
    "new";
    "nonrec";
    "object";
    "of";
    "open";
    "or";
    "private";
    "rec";
    "sig";
    "struct";
    "then";
    "to";
    "true";
    "try";
    "type";
    "val";
    "virtual";
    "when";
    "while";
    "with";
  ]

(** Append "_" to an OCaml reserved word so it can be used as an identifier,
    e.g. "end" -> "end_". *)
let sanitize_identifier id =
  if List.mem id ~set:reserved_identifiers then id ^ "_" else id

(** Sanitize a property name: escape reserved words, replace "-" with "_", and
    convert to snake_case. *)
let sanitize_property_name name =
  name |> sanitize_identifier
  |> String.map ~f:(function '-' -> '_' | c -> c)
  |> to_snake_case

(** Convert a method name to a valid OCaml function name. *)
let ocaml_function_name (method_name : string) =
  method_name |> to_snake_case |> sanitize_identifier

let kebab_to_snake = String.map ~f:(function '-' -> '_' | c -> c)

(** Convert a method identifier to a valid OCaml method name. See
    [ocaml_function_name]. *)
let ocaml_method_name method_identifier = ocaml_function_name method_identifier

(** Calculate a property name without sanitizing the identifier (get_/set_
    prefixes are added by callers). *)
let ocaml_property_name name = name |> kebab_to_snake |> to_snake_case

(** Convert a parameter name to a valid OCaml identifier. *)
let ocaml_parameter_name name =
  name |> kebab_to_snake |> to_snake_case |> sanitize_identifier

(** Convert a class name to its OCaml name, e.g. "GtkTextView" -> "text_view".
*)
let ocaml_class_name cn =
  cn |> normalize_class_name |> kebab_to_snake |> to_snake_case
  |> sanitize_identifier

(** Convert an interface name to its OCaml name (same as classes). *)
let ocaml_interface_name cn =
  (* this is the same as classes *)
  ocaml_class_name cn

(** Convert a record name to its OCaml name (same as classes). *)
let ocaml_record_name cn =
  (* this is the same as classes *)
  ocaml_class_name cn

(** Extract ML prefix from generation context namespace *)
let extract_ml_prefix (ctx : Types.generation_context) : string =
  let namespace_prefix = ctx.namespace.namespace_c_identifier_prefixes in
  "ml_" ^ String.lowercase_ascii namespace_prefix ^ "_"

(** Convert a GLib type name (e.g. "GtkEditable") to a GType macro constant
    (e.g. "GTK_TYPE_EDITABLE"). *)
let gtype_macro_of_type_name type_name =
  let screaming = type_name |> to_snake_case |> String.uppercase_ascii in
  (* Insert _TYPE_ after the first word (namespace prefix) *)
  match String.index_opt screaming '_' with
  | None -> screaming (* no underscore — use as-is *)
  | Some i ->
      let prefix = String.sub screaming ~pos:0 ~len:i in
      let rest =
        String.sub screaming ~pos:(i + 1) ~len:(String.length screaming - i - 1)
      in
      prefix ^ "_TYPE_" ^ rest

(** Convert a GLib type name (e.g. "GtkEditable") to its GObject cast macro
    (e.g. "GTK_EDITABLE"). *)
let cast_macro_of_type_name type_name =
  type_name |> to_snake_case |> String.uppercase_ascii

(** Convert a constructor name to a valid OCaml identifier. *)
let ocaml_constructor_name (ctor : Types.gir_constructor) =
  ctor.ctor_name |> kebab_to_snake |> to_snake_case |> sanitize_identifier

(* The c_identifier already contains the library prefix (e.g., "gtk_widget_new"),
   so we just prepend "ml_" to create the C binding name *)

(** Build the C binding name for a constructor by prepending "ml_" to its
    c_identifier. *)
let ml_constructor_name
    ~constructor:({ c_identifier; _ } : Types.gir_constructor) =
  "ml_" ^ c_identifier

(* The c_identifier already contains the library prefix (e.g., "gtk_widget_show"),
   so we just prepend "ml_" to create the C binding name *)

(** Build the C binding name for a method by prepending "ml_" to its
    c_identifier. *)
let ml_method_name ({ c_identifier; _ } : Types.gir_method) =
  "ml_" ^ c_identifier

(** Build the C binding name for a property getter, e.g.
    "ml_gtk_widget_get_visible". *)
let ml_property_name ~ctx ~class_name (prop : Types.gir_property) =
  let prop_name_cleaned =
    String.map ~f:(function '-' -> '_' | c -> c) prop.prop_name
  in
  let prop_snake = to_snake_case prop_name_cleaned in
  let class_snake = to_snake_case class_name in
  Fmt.str "%s%s_get_%s" (extract_ml_prefix ctx) class_snake prop_snake

(** Build the C binding name for a property setter, e.g.
    "ml_gtk_widget_set_visible". *)
let ml_property_setter_name ~ctx ~class_name (prop : Types.gir_property) =
  let prop_name_cleaned =
    String.map ~f:(function '-' -> '_' | c -> c) prop.prop_name
  in
  let prop_snake = to_snake_case prop_name_cleaned in
  let class_snake = to_snake_case class_name in
  Fmt.str "%s%s_set_%s" (extract_ml_prefix ctx) class_snake prop_snake

(** Convert a bitfield name to its OCaml name (lowercased). *)
let ocaml_bitfield_name (bitfield : Types.gir_bitfield) =
  String.lowercase_ascii bitfield.bitfield_name

(** Convert an enum name to its OCaml name (lowercased). *)
let ocaml_enum_name (enum : Types.gir_enum) =
  String.lowercase_ascii enum.enum_name

(** Layer 2 module name for a class: "G" ^ Module_name. e.g., "Button" ->
    "GButton", "Window" -> "GWindow" *)
let layer2_module_name class_name = "G" ^ module_name_of_class class_name

(** Layer 2 module filename (lowercase first char): "g" ^ Module_name. e.g.,
    "Button" -> "gButton", "Window" -> "gWindow" *)
let layer2_module_filename class_name = "g" ^ module_name_of_class class_name

(** Class type name with _t suffix from a class name. e.g., "Button" ->
    "button_t", "TextView" -> "text_view_t" *)
let class_type_name class_name = ocaml_class_name class_name ^ "_t"

(** Layer 1 accessor method name. e.g., "Button" -> "as_button", "TextView" ->
    "as_text_view" *)
let accessor_name class_name = "as_" ^ ocaml_class_name class_name

(** Split a qualified GIR name into (namespace, name). Unqualified names are
    assumed to belong to the context's namespace. Raises [Failure] if the name
    has more than one "." separator. *)
let name_to_parts ~(ctx : Types.generation_context) name =
  match Re.Str.split (Re.Str.regexp_string ".") name with
  | [ ns; name ] -> (ns, name)
  | [ name ] -> (ctx.namespace.namespace_name, name)
  | _ -> failwith "Unable to parse name correctly"
