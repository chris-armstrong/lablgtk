(* Unit tests for Constant_code — the pure-OCaml <ns>_constants emitter.

Covers: snake_case naming, type mapping per GIR value type, value
serialization (string escaping, float ".0" suffix, bool passthrough, int
as-is), OCamldoc + @since emission, the no-doc version-only fallback, and
skip-with-warning for unmappable types. All assertions are over the string
returned by [generate_constants_interface] / [generate_constants_implementation].

String-substring checks are used (via [Helpers.string_contains]) rather than
AST validation because the output is OCaml source text with no in-repo parser;
this is the established pattern for generator-output tests in this suite. *)

open Gir_gen_lib.Generate.Constant_code

let ns = "Gtk"

(* ---------- type fixtures --------------------------------------------- *)

let utf8_type =
  Type_factory.make_gir_type ~name:"utf8" ~c_type:"const gchar*" ()

let gint_type = Type_factory.make_gir_type ~name:"gint" ~c_type:"gint" ()
let guint_type = Type_factory.make_gir_type ~name:"guint" ~c_type:"guint" ()

let gdouble_type =
  Type_factory.make_gir_type ~name:"gdouble" ~c_type:"gdouble" ()

let gboolean_type =
  Type_factory.make_gir_type ~name:"gboolean" ~c_type:"gboolean" ()

let glyph_type =
  Type_factory.make_gir_type ~name:"Glyph" ~c_type:"PangoGlyph" ()

let gint32_type = Type_factory.make_gir_type ~name:"gint32" ~c_type:"gint32" ()
let gint64_type = Type_factory.make_gir_type ~name:"gint64" ~c_type:"gint64" ()

let guint32_type =
  Type_factory.make_gir_type ~name:"guint32" ~c_type:"guint32" ()

let guint64_type =
  Type_factory.make_gir_type ~name:"guint64" ~c_type:"guint64" ()

let gsize_type = Type_factory.make_gir_type ~name:"gsize" ~c_type:"gsize" ()

let unknown_type =
  Type_factory.make_gir_type ~name:"SomeWeirdRecord" ~c_type:"SomeWeirdRecord*"
    ()

(* ---------- record builder -------------------------------------------- *)

let mk ~name ~c_type ~value ~value_type ?doc ?version () =
  Type_factory.make_gir_constant ~constant_name:name ~constant_c_type:c_type
    ~value ~value_type ?constant_doc:doc ?version ()

(* ---------- assertion helpers ----------------------------------------- *)

let has msg s sub =
  Alcotest.(check bool) msg true (Helpers.string_contains s sub)

let lacks msg s sub =
  Alcotest.(check bool) msg false (Helpers.string_contains s sub)

(* ---------- naming ---------------------------------------------------- *)

let test_naming_lowercases () =
  let c =
    mk ~name:"ACCESSIBLE_ATTRIBUTE_BACKGROUND"
      ~c_type:"GTK_ACCESSIBLE_ATTRIBUTE_BACKGROUND" ~value:"bg-color"
      ~value_type:utf8_type ()
  in
  has "lowercased name in mli"
    (generate_constants_interface ~namespace:ns [ c ])
    "val accessible_attribute_background : string"

let test_naming_mixed_case () =
  (* GIR names can be mixed-case (e.g. KEY_BackSpace); lowercasing the whole
     identifier keeps it a valid OCaml name. *)
  let c =
    mk ~name:"KEY_BackSpace" ~c_type:"KEY_BackSpace" ~value:"65288"
      ~value_type:gint_type ()
  in
  has "lowercased mixed-case name in ml"
    (generate_constants_implementation ~namespace:ns [ c ])
    "let key_backspace = 65288"

(* ---------- type mapping per value kind -------------------------------- *)

let test_type_mapping () =
  List.iter
    (fun (label, vt, ocaml_type) ->
      let c =
        mk
          ~name:(String.uppercase_ascii label)
          ~c_type:label ~value:"0" ~value_type:vt ()
      in
      has
        ("type " ^ label ^ " -> " ^ ocaml_type)
        (generate_constants_interface ~namespace:ns [ c ])
        (Printf.sprintf "val %s : %s" (String.lowercase_ascii label) ocaml_type))
    [
      ("gint", gint_type, "int");
      ("guint", guint_type, "int");
      ("gdouble", gdouble_type, "float");
      ("gboolean", gboolean_type, "bool");
      ("glyph", glyph_type, "int");
      ("utf8", utf8_type, "string");
      ("gint32", gint32_type, "Int32.t");
      ("gint64", gint64_type, "int64");
      ("guint32", guint32_type, "UInt32.t");
      ("guint64", guint64_type, "UInt64.t");
      ("gsize", gsize_type, "Gsize.t");
    ]

(* ---------- value serialization --------------------------------------- *)

let test_string_escaping () =
  (* %S escapes both the double-quote and the backslash. *)
  let c =
    mk ~name:"BG_COLOR" ~c_type:"BG_COLOR" ~value:"a\"b\\c"
      ~value_type:utf8_type ()
  in
  has "escaped string literal"
    (generate_constants_implementation ~namespace:ns [ c ])
    "let bg_color = \"a\\\"b\\\\c\""

let test_float_dot_zero_suffix () =
  let c =
    mk ~name:"PI" ~c_type:"GRAPHENE_PI" ~value:"3" ~value_type:gdouble_type ()
  in
  has "integer-valued float gets .0"
    (generate_constants_implementation ~namespace:ns [ c ])
    "let pi = 3.0"

let test_float_with_decimal_unchanged () =
  let c =
    mk ~name:"PI_2" ~c_type:"GRAPHENE_PI_2" ~value:"1.5707"
      ~value_type:gdouble_type ()
  in
  has "float with decimal kept as-is"
    (generate_constants_implementation ~namespace:ns [ c ])
    "let pi_2 = 1.5707"

let test_bool_passthrough () =
  let c =
    mk ~name:"TRUE_FLAG" ~c_type:"TRUE_FLAG" ~value:"true"
      ~value_type:gboolean_type ()
  in
  has "bool value passed through"
    (generate_constants_implementation ~namespace:ns [ c ])
    "let true_flag = true"

let test_int_as_is () =
  let c =
    mk ~name:"PRIORITY" ~c_type:"PRIORITY" ~value:"100" ~value_type:gint_type ()
  in
  has "int value as-is"
    (generate_constants_implementation ~namespace:ns [ c ])
    "let priority = 100"

(* Wide/unsigned integer types resolve to their own module via
   Type_mappings.type_mappings and serialize with the right literal or
   construction form. None of these occur in the current GIR, but the
   generator must emit valid OCaml if they ever do. *)
let test_wide_integer_serialization () =
  let check ?(value = "100") name vt needle =
    let c =
      mk
        ~name:(String.uppercase_ascii name)
        ~c_type:name ~value ~value_type:vt ()
    in
    has
      (name ^ " serializes correctly")
      (generate_constants_implementation ~namespace:ns [ c ])
      needle
  in
  check "gint32" gint32_type "let gint32 = 100l";
  check "gint64" gint64_type "let gint64 = 100L";
  check "guint32" guint32_type "let guint32 = UInt32.of_int 100";
  check "guint64" guint64_type "let guint64 = UInt64.of_int 100";
  check "gsize" gsize_type "let gsize = Gsize.of_int 100"

(* ---------- doc + @since emission ------------------------------------- *)

let test_doc_with_since () =
  let c =
    mk ~name:"BG" ~c_type:"BG" ~value:"x" ~value_type:utf8_type
      ~doc:"Background color." ~version:"4.14" ()
  in
  let mli = generate_constants_interface ~namespace:ns [ c ] in
  has "doc text" mli "(** Background color.";
  has "@since tag" mli "@since 4.14 *)";
  has "val line" mli "val bg : string"

let test_doc_without_version () =
  let c =
    mk ~name:"BG" ~c_type:"BG" ~value:"x" ~value_type:utf8_type
      ~doc:"Background color." ()
  in
  let mli = generate_constants_interface ~namespace:ns [ c ] in
  has "doc with no @since" mli "(** Background color. *)";
  lacks "no @since when version absent" mli "@since"

let test_version_only_fallback () =
  (* No doc, but a version: emit a minimal [c_type] @since line. *)
  let c =
    mk ~name:"BG" ~c_type:"GTK_BG" ~value:"x" ~value_type:utf8_type
      ~version:"4.14" ()
  in
  let mli = generate_constants_interface ~namespace:ns [ c ] in
  has "version-only fallback doc" mli "(** [GTK_BG] @since 4.14 *)"

let test_no_doc_no_version () =
  let c = mk ~name:"BG" ~c_type:"BG" ~value:"x" ~value_type:utf8_type () in
  let mli = generate_constants_interface ~namespace:ns [ c ] in
  lacks "no doc line" mli "(**";
  has "val still emitted" mli "val bg : string"

(* ---------- skip-with-warning for unmappable types -------------------- *)

let test_unmappable_skipped_in_mli () =
  let good =
    mk ~name:"KEEP" ~c_type:"KEEP" ~value:"1" ~value_type:gint_type ()
  in
  let bad =
    mk ~name:"DROP" ~c_type:"DROP" ~value:"x" ~value_type:unknown_type ()
  in
  let mli = generate_constants_interface ~namespace:ns [ good; bad ] in
  has "mappable constant kept" mli "val keep : int";
  lacks "unmappable constant dropped" mli "val drop";
  lacks "unmappable name absent" mli "drop"

let test_unmappable_skipped_in_ml () =
  let bad =
    mk ~name:"DROP" ~c_type:"DROP" ~value:"x" ~value_type:unknown_type ()
  in
  lacks "unmappable not bound in ml"
    (generate_constants_implementation ~namespace:ns [ bad ])
    "let drop"

(* ---------- empty list ------------------------------------------------ *)

let test_empty_interface () =
  let mli = generate_constants_interface ~namespace:ns [] in
  has "header present" mli "(* GENERATED CODE - DO NOT EDIT *)";
  has "namespace banner" mli "(* Gtk Constants *)";
  lacks "no val when empty" mli "val "

let test_empty_implementation () =
  let ml = generate_constants_implementation ~namespace:ns [] in
  has "header present" ml "(* GENERATED CODE - DO NOT EDIT *)";
  lacks "no binding when empty" ml "let "

let test_header_namespace () =
  has "banner uses given namespace"
    (generate_constants_interface ~namespace:"Pango" [])
    "(* Pango Constants *)"

(* ---------- suite ----------------------------------------------------- *)

let tests =
  [
    ("naming lowercases", `Quick, test_naming_lowercases);
    ("naming mixed case", `Quick, test_naming_mixed_case);
    ("type mapping per value kind", `Quick, test_type_mapping);
    ("string escaping", `Quick, test_string_escaping);
    ("float .0 suffix", `Quick, test_float_dot_zero_suffix);
    ("float with decimal unchanged", `Quick, test_float_with_decimal_unchanged);
    ("bool passthrough", `Quick, test_bool_passthrough);
    ("int as-is", `Quick, test_int_as_is);
    ("wide integer serialization", `Quick, test_wide_integer_serialization);
    ("doc with @since", `Quick, test_doc_with_since);
    ("doc without version", `Quick, test_doc_without_version);
    ("version-only fallback", `Quick, test_version_only_fallback);
    ("no doc no version", `Quick, test_no_doc_no_version);
    ("unmappable skipped (mli)", `Quick, test_unmappable_skipped_in_mli);
    ("unmappable skipped (ml)", `Quick, test_unmappable_skipped_in_ml);
    ("empty interface", `Quick, test_empty_interface);
    ("empty implementation", `Quick, test_empty_implementation);
    ("header namespace", `Quick, test_header_namespace);
  ]
