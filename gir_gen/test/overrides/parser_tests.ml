(* Tests for Gir_gen_lib.Override_parser. *)

open Gir_gen_lib.Override_types
module Os_filter = Gir_gen_lib.Os_filter

let parse_ok content =
  match Gir_gen_lib.Override_parser.parse_overrides_from_string content with
  | Ok ov -> ov
  | Error e ->
      Alcotest.fail
        (Fmt.str "Parse failed: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let parse_err content =
  match Gir_gen_lib.Override_parser.parse_overrides_from_string content with
  | Ok _ -> Alcotest.fail "Expected parse error but got Ok"
  | Error e -> e

let hd_exn msg = function [] -> Alcotest.fail msg | x :: _ -> x

let find_exn msg pred list =
  match List.find_opt pred list with None -> Alcotest.fail msg | Some x -> x

let test_minimal () =
  let ov = parse_ok "(overrides (library \"Gtk\"))" in
  Alcotest.(check string) "library" "Gtk" ov.library_name;
  Alcotest.(check int) "classes" 0 (List.length ov.classes);
  Alcotest.(check int) "functions" 0 (List.length ov.functions)

let test_no_library () =
  let ov = parse_ok "(overrides)" in
  Alcotest.(check string) "library" "" ov.library_name

let test_class_ignore () =
  let ov = parse_ok "(overrides (library \"Gtk\") (class Widget (ignore)))" in
  Alcotest.(check int) "classes" 1 (List.length ov.classes);
  let c = hd_exn "Expected one class" ov.classes in
  Alcotest.(check string) "name" "Widget" c.class_name;
  Alcotest.(check bool) "action" true (Option.is_some c.class_action);
  match c.class_action with
  | Some Ignore -> ()
  | _ -> Alcotest.fail "Expected Some Ignore"

let test_class_with_method_overrides () =
  let ov =
    parse_ok
      "(overrides (library \"Gtk\") (class Widget (method create (ignore)) \
       (method notify_destroy (version \"4.53\"))))"
  in
  Alcotest.(check int) "classes" 1 (List.length ov.classes);
  let c = hd_exn "Expected one class" ov.classes in
  Alcotest.(check int) "methods" 2 (List.length c.methods);
  let m1 =
    find_exn "Expected method 'create'"
      (fun m -> String.equal m.component_name "create")
      c.methods
  in
  let m2 =
    find_exn "Expected method 'notify_destroy'"
      (fun m -> String.equal m.component_name "notify_destroy")
      c.methods
  in
  Alcotest.(check bool)
    "create ignored" true
    (Option.equal equal_override_action m1.action (Some Ignore));
  Alcotest.(check bool)
    "notify_destroy version" true
    (Option.equal equal_override_action m2.action
       (Some (Set_version { vs_version = "4.53"; vs_namespace = None })))

let test_class_with_constructor_and_property () =
  let ov =
    parse_ok
      "(overrides (library \"Gtk\") (class Button (constructor new (ignore)) \
       (property sensitive (version \"4.10\"))))"
  in
  let c = hd_exn "Expected one class" ov.classes in
  Alcotest.(check int) "constructors" 1 (List.length c.constructors);
  Alcotest.(check int) "properties" 1 (List.length c.properties);
  let ctor = hd_exn "Expected one constructor" c.constructors in
  let prop = hd_exn "Expected one property" c.properties in
  Alcotest.(check string) "ctor name" "new" ctor.component_name;
  Alcotest.(check string) "prop name" "sensitive" prop.component_name

let test_class_with_signal () =
  let ov =
    parse_ok
      "(overrides (library \"Gtk\") (class Widget (signal destroy (ignore))))"
  in
  let c = hd_exn "Expected one class" ov.classes in
  Alcotest.(check int) "signals" 1 (List.length c.signals)

let test_interface_override () =
  let ov =
    parse_ok
      "(overrides (library \"Gtk\") (interface Actionable (method \
       get_action_name (ignore)) (property action_name (version \"4.12\"))))"
  in
  Alcotest.(check int) "interfaces" 1 (List.length ov.interfaces);
  let i = hd_exn "Expected one interface" ov.interfaces in
  Alcotest.(check string) "name" "Actionable" i.interface_name;
  Alcotest.(check int) "methods" 1 (List.length i.methods);
  Alcotest.(check int) "properties" 1 (List.length i.properties)

let test_record_override () =
  let ov =
    parse_ok
      "(overrides (library \"Gtk\") (record TextIter (field user_data \
       (ignore)) (field start (version \"4.14\")) (constructor new (ignore)) \
       (method get_text (version \"4.14\")) (function get_slice (ignore))))"
  in
  Alcotest.(check int) "records" 1 (List.length ov.records);
  let r = hd_exn "Expected one record" ov.records in
  Alcotest.(check string) "name" "TextIter" r.record_name;
  Alcotest.(check int) "fields" 2 (List.length r.fields);
  Alcotest.(check int) "constructors" 1 (List.length r.constructors);
  Alcotest.(check int) "methods" 1 (List.length r.methods);
  Alcotest.(check int) "functions" 1 (List.length r.functions)

let test_enum_override () =
  let ov =
    parse_ok
      "(overrides (library \"Gtk\") (enumeration RGBA (member RED (ignore)) \
       (member GREEN (version \"4.14\")) (function parse (ignore))))"
  in
  Alcotest.(check int) "enums" 1 (List.length ov.enums);
  let e = hd_exn "Expected one enum" ov.enums in
  Alcotest.(check string) "name" "RGBA" e.enum_name;
  Alcotest.(check int) "members" 2 (List.length e.members);
  Alcotest.(check int) "functions" 1 (List.length e.functions)

let test_bitfield_override () =
  let ov =
    parse_ok
      "(overrides (library \"Gtk\") (bitfield StateFlags (member ACTIVE \
       (ignore)) (member BACKDROP (version \"4.14\"))))"
  in
  Alcotest.(check int) "bitfields" 1 (List.length ov.bitfields);
  let b = hd_exn "Expected one bitfield" ov.bitfields in
  Alcotest.(check string) "name" "StateFlags" b.bitfield_name;
  Alcotest.(check int) "flags" 2 (List.length b.flags)

let test_standalone_function () =
  let ov =
    parse_ok "(overrides (library \"Gtk\") (function gtk_show_uri (ignore)))"
  in
  Alcotest.(check int) "functions" 1 (List.length ov.functions);
  let f = hd_exn "Expected one function" ov.functions in
  Alcotest.(check string) "name" "gtk_show_uri" f.component_name

let test_multiple_entities () =
  let ov =
    parse_ok
      "(overrides (library \"Gtk\") (class Widget (ignore)) (class Button \
       (ignore)) (interface Actionable (ignore)))"
  in
  Alcotest.(check int) "classes" 2 (List.length ov.classes);
  Alcotest.(check int) "interfaces" 1 (List.length ov.interfaces)

let test_class_ignore_precedence () =
  let ov =
    parse_ok
      "(overrides (library \"Gtk\") (class Widget (ignore) (method foo \
       (ignore))))"
  in
  let c = hd_exn "Expected one class" ov.classes in
  Alcotest.(check bool) "class ignored" true (Option.is_some c.class_action);
  Alcotest.(check int) "methods still parsed" 1 (List.length c.methods)

let test_duplicate_class () =
  let err =
    parse_err
      "(overrides (library \"Gtk\") (class Widget (ignore)) (class Widget \
       (ignore)))"
  in
  match err with
  | Duplicate_entity { kind; name } ->
      Alcotest.(check string) "kind" "class" kind;
      Alcotest.(check string) "name" "Widget" name
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Duplicate_entity, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_duplicate_interface () =
  let err =
    parse_err
      "(overrides (library \"Gtk\") (interface Actionable (ignore)) (interface \
       Actionable (ignore)))"
  in
  match err with
  | Duplicate_entity { kind; name } ->
      Alcotest.(check string) "kind" "interface" kind;
      Alcotest.(check string) "name" "Actionable" name
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Duplicate_entity, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_duplicate_function () =
  let err =
    parse_err
      "(overrides (library \"Gtk\") (function gtk_show_uri (ignore)) (function \
       gtk_show_uri (ignore)))"
  in
  match err with
  | Duplicate_entity { kind; name } ->
      Alcotest.(check string) "kind" "function" kind;
      Alcotest.(check string) "name" "gtk_show_uri" name
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Duplicate_entity, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_unknown_entity () =
  let err = parse_err "(overrides (library \"Gtk\") (widget Foo (ignore)))" in
  match err with
  | Unknown_entity_kind kind -> Alcotest.(check string) "kind" "widget" kind
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Unknown_entity_kind, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_bare_name_member_in_enum () =
  (* (foo (version "X.Y")) is missing the "member" keyword — should error *)
  let err =
    parse_err
      "(overrides (library \"Gtk\") (enumeration StateFlags (foo (version \
       \"4.14\"))))"
  in
  match err with
  | Unknown_component_kind { entity_name; kind; _ } ->
      Alcotest.(check string) "entity" "StateFlags" entity_name;
      Alcotest.(check string) "kind" "foo" kind
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Unknown_component_kind, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_bare_name_member_in_bitfield () =
  let err =
    parse_err
      "(overrides (library \"Gtk\") (bitfield StateFlags (focused (version \
       \"4.16\"))))"
  in
  match err with
  | Unknown_component_kind { entity_name; kind; _ } ->
      Alcotest.(check string) "entity" "StateFlags" entity_name;
      Alcotest.(check string) "kind" "focused" kind
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Unknown_component_kind, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_wrong_kind_in_class () =
  (* "field" is not valid inside a class body *)
  let err =
    parse_err
      "(overrides (library \"Gtk\") (class Widget (field foo (ignore))))"
  in
  match err with
  | Unknown_component_kind { entity_name; kind; _ } ->
      Alcotest.(check string) "entity" "Widget" entity_name;
      Alcotest.(check string) "kind" "field" kind
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Unknown_component_kind, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_wrong_kind_in_record () =
  (* "signal" is not valid inside a record body *)
  let err =
    parse_err
      "(overrides (library \"Gtk\") (record TextIter (signal changed \
       (ignore))))"
  in
  match err with
  | Unknown_component_kind { entity_name; kind; _ } ->
      Alcotest.(check string) "entity" "TextIter" entity_name;
      Alcotest.(check string) "kind" "signal" kind
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Unknown_component_kind, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_invalid_version () =
  let err =
    parse_err
      "(overrides (library \"Gtk\") (class Widget (method foo (version \
       \"bad\"))))"
  in
  match err with
  | Invalid_version { name; version; _ } ->
      Alcotest.(check string) "name" "foo" name;
      Alcotest.(check string) "version" "bad" version
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Invalid_version, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_malformed_sexp () =
  let err = parse_err "(((" in
  match err with
  | Invalid_format _ -> ()
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Invalid_format, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_not_overrides_form () =
  let err = parse_err "(class Widget (ignore))" in
  match err with
  | Invalid_format { message; _ } ->
      Alcotest.(check bool) "mentions overrides" true (String.length message > 0)
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Invalid_format, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_bad_component_action () =
  let err =
    parse_err
      "(overrides (library \"Gtk\") (class Widget (method foo (rename bar))))"
  in
  match err with
  | Invalid_format _ -> ()
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Invalid_format, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_empty_class () =
  let ov = parse_ok "(overrides (library \"Gtk\") (class Widget))" in
  let c = hd_exn "Expected one class" ov.classes in
  Alcotest.(check string) "name" "Widget" c.class_name;
  Alcotest.(check bool) "no action" true (Option.is_none c.class_action)

let test_many_components () =
  let ov =
    parse_ok
      "(overrides (library \"Gtk\") (class Widget (constructor new (ignore)) \
       (constructor new_with_label (version \"4.10\")) (method foo (ignore)) \
       (method bar (version \"4.12\")) (property visible (ignore)) (property \
       sensitive (version \"4.10\")) (signal destroy (ignore)) (signal show \
       (version \"4.8\"))))"
  in
  let c = hd_exn "Expected one class" ov.classes in
  Alcotest.(check int) "constructors" 2 (List.length c.constructors);
  Alcotest.(check int) "methods" 2 (List.length c.methods);
  Alcotest.(check int) "properties" 2 (List.length c.properties);
  Alcotest.(check int) "signals" 2 (List.length c.signals)

let roundtrip original =
  let sexp = sexp_of_library_overrides original in
  let sexp_str = Sexplib.Sexp.to_string sexp in
  let roundtripped =
    library_overrides_of_sexp (Sexplib.Sexp.of_string sexp_str)
  in
  Alcotest.(check bool)
    "roundtrip equality" true
    (equal_library_overrides original roundtripped)

let test_roundtrip_minimal () =
  let original = parse_ok "(overrides (library \"Gtk\"))" in
  roundtrip original

let test_roundtrip_class_ignore () =
  let original =
    parse_ok "(overrides (library \"Gtk\") (class Widget (ignore)))"
  in
  roundtrip original

let test_roundtrip_class_components () =
  let original =
    parse_ok
      "(overrides (library \"Gtk\") (class Widget (constructor new (ignore)) \
       (constructor new_with_label (version \"4.10\")) (method foo (ignore)) \
       (method bar (version \"4.12\")) (property visible (ignore)) (property \
       sensitive (version \"4.10\")) (signal destroy (ignore)) (signal show \
       (version \"4.8\"))))"
  in
  roundtrip original

let test_roundtrip_interface () =
  let original =
    parse_ok
      "(overrides (library \"Gtk\") (interface Actionable (method \
       get_action_name (ignore)) (property action_name (version \"4.12\")) \
       (signal activated (ignore))))"
  in
  roundtrip original

let test_roundtrip_record () =
  let original =
    parse_ok
      "(overrides (library \"Gtk\") (record TextIter (field user_data \
       (ignore)) (field start (version \"4.14\")) (constructor new (ignore)) \
       (method get_text (version \"4.14\")) (function get_slice (ignore))))"
  in
  roundtrip original

let test_roundtrip_enum () =
  let original =
    parse_ok
      "(overrides (library \"Gtk\") (enumeration RGBA (member RED (ignore)) \
       (member GREEN (version \"4.14\")) (function parse (ignore))))"
  in
  roundtrip original

let test_roundtrip_bitfield () =
  let original =
    parse_ok
      "(overrides (library \"Gtk\") (bitfield StateFlags (member ACTIVE \
       (ignore)) (member BACKDROP (version \"4.14\"))))"
  in
  roundtrip original

let test_roundtrip_standalone_function () =
  let original =
    parse_ok "(overrides (library \"Gtk\") (function gtk_show_uri (ignore)))"
  in
  roundtrip original

let test_roundtrip_complex () =
  let original =
    parse_ok
      "(overrides (library \"Gtk\") (class Widget (ignore) (constructor new \
       (ignore)) (method show (version \"4.8\")) (property visible (ignore)) \
       (signal destroy (ignore))) (class Button (method clicked (version \
       \"4.10\")) (property label (ignore))) (interface Actionable (method \
       get_action_name (version \"4.12\")) (property action_name (ignore))) \
       (record TextIter (field user_data (ignore)) (constructor new (ignore)) \
       (method get_text (version \"4.14\")) (function slice (ignore))) \
       (enumeration Align (member START (ignore)) (member END (version \
       \"4.0\")) (function from_string (ignore))) (bitfield StateFlags (member \
       ACTIVE (ignore)) (member FOCUSED (version \"4.2\"))) (function gtk_init \
       (ignore)) (function gtk_main (version \"4.0\")))"
  in
  roundtrip original

(* ---- Multi-OS and not_os tests ---- *)

let test_single_os_on_method () =
  let ov =
    parse_ok
      "(overrides (library \"Gio\") (class App (method get_pid (os \
       \"linux\"))))"
  in
  let c = hd_exn "Expected one class" ov.classes in
  let m = hd_exn "Expected one method" c.methods in
  Alcotest.(check string) "method name" "get_pid" m.component_name;
  match m.os with
  | Some (Os_filter.Os_only [ "linux" ]) -> ()
  | _ -> Alcotest.fail "Expected Os_only [\"linux\"]"

let test_multi_os_on_method () =
  let ov =
    parse_ok
      "(overrides (library \"Gio\") (class App (method get_pid (os \"linux\") \
       (os \"macos\"))))"
  in
  let c = hd_exn "Expected one class" ov.classes in
  let m = hd_exn "Expected one method" c.methods in
  match m.os with
  | Some (Os_filter.Os_only [ "linux"; "macos" ]) -> ()
  | _ -> Alcotest.fail "Expected Os_only [\"linux\"; \"macos\"]"

let test_not_os_single () =
  let ov =
    parse_ok
      "(overrides (library \"Gio\") (class App (method get_pid (not_os \
       \"windows\"))))"
  in
  let c = hd_exn "Expected one class" ov.classes in
  let m = hd_exn "Expected one method" c.methods in
  match m.os with
  | Some (Os_filter.Os_except [ "windows" ]) -> ()
  | _ -> Alcotest.fail "Expected Os_except [\"windows\"]"

let test_not_os_multiple () =
  let ov =
    parse_ok
      "(overrides (library \"Gio\") (class App (method get_pid (not_os \
       \"windows\") (not_os \"macos\"))))"
  in
  let c = hd_exn "Expected one class" ov.classes in
  let m = hd_exn "Expected one method" c.methods in
  match m.os with
  | Some (Os_filter.Os_except [ "windows"; "macos" ]) -> ()
  | _ -> Alcotest.fail "Expected Os_except [\"windows\"; \"macos\"]"

let test_entity_level_multi_os () =
  let ov =
    parse_ok
      "(overrides (library \"Gio\") (class App (os \"linux\") (os \"freebsd\") \
       (method get_pid (ignore))))"
  in
  let c = hd_exn "Expected one class" ov.classes in
  match c.class_os with
  | Some (Os_filter.Os_only [ "linux"; "freebsd" ]) -> ()
  | _ -> Alcotest.fail "Expected Os_only [\"linux\"; \"freebsd\"] on class"

let test_entity_level_not_os () =
  let ov =
    parse_ok
      "(overrides (library \"Gio\") (class App (not_os \"windows\") (method \
       get_pid (ignore))))"
  in
  let c = hd_exn "Expected one class" ov.classes in
  match c.class_os with
  | Some (Os_filter.Os_except [ "windows" ]) -> ()
  | _ -> Alcotest.fail "Expected Os_except [\"windows\"] on class"

let test_mix_os_and_not_os_on_component () =
  let err =
    parse_err
      "(overrides (library \"Gio\") (class App (method get_pid (os \"linux\") \
       (not_os \"windows\"))))"
  in
  match err with
  | Invalid_format _ -> ()
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Invalid_format, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_mix_os_and_not_os_on_entity () =
  let err =
    parse_err
      "(overrides (library \"Gio\") (class App (os \"linux\") (not_os \
       \"windows\")))"
  in
  match err with
  | Invalid_format _ -> ()
  | e ->
      Alcotest.fail
        (Fmt.str "Expected Invalid_format, got: %s"
           (Gir_gen_lib.Override_parser.format_error e))

let test_suite_roundtrip =
  [
    ("minimal", `Quick, test_roundtrip_minimal);
    ("class_ignore", `Quick, test_roundtrip_class_ignore);
    ("class_components", `Quick, test_roundtrip_class_components);
    ("interface", `Quick, test_roundtrip_interface);
    ("record", `Quick, test_roundtrip_record);
    ("enum", `Quick, test_roundtrip_enum);
    ("bitfield", `Quick, test_roundtrip_bitfield);
    ("standalone_function", `Quick, test_roundtrip_standalone_function);
    ("complex", `Quick, test_roundtrip_complex);
  ]

let test_suite =
  [
    ("minimal", `Quick, test_minimal);
    ("no_library", `Quick, test_no_library);
    ("class_ignore", `Quick, test_class_ignore);
    ("class_with_method_overrides", `Quick, test_class_with_method_overrides);
    ( "class_with_constructor_and_property",
      `Quick,
      test_class_with_constructor_and_property );
    ("class_with_signal", `Quick, test_class_with_signal);
    ("interface_override", `Quick, test_interface_override);
    ("record_override", `Quick, test_record_override);
    ("enum_override", `Quick, test_enum_override);
    ("bitfield_override", `Quick, test_bitfield_override);
    ("standalone_function", `Quick, test_standalone_function);
    ("multiple_entities", `Quick, test_multiple_entities);
    ("class_ignore_precedence", `Quick, test_class_ignore_precedence);
    ("duplicate_class", `Quick, test_duplicate_class);
    ("duplicate_interface", `Quick, test_duplicate_interface);
    ("duplicate_function", `Quick, test_duplicate_function);
    ("unknown_entity", `Quick, test_unknown_entity);
    ("bare_name_member_in_enum", `Quick, test_bare_name_member_in_enum);
    ("bare_name_member_in_bitfield", `Quick, test_bare_name_member_in_bitfield);
    ("wrong_kind_in_class", `Quick, test_wrong_kind_in_class);
    ("wrong_kind_in_record", `Quick, test_wrong_kind_in_record);
    ("invalid_version", `Quick, test_invalid_version);
    ("malformed_sexp", `Quick, test_malformed_sexp);
    ("not_overrides_form", `Quick, test_not_overrides_form);
    ("bad_component_action", `Quick, test_bad_component_action);
    ("empty_class", `Quick, test_empty_class);
    ("many_components", `Quick, test_many_components);
    ("single_os_on_method", `Quick, test_single_os_on_method);
    ("multi_os_on_method", `Quick, test_multi_os_on_method);
    ("not_os_single", `Quick, test_not_os_single);
    ("not_os_multiple", `Quick, test_not_os_multiple);
    ("entity_level_multi_os", `Quick, test_entity_level_multi_os);
    ("entity_level_not_os", `Quick, test_entity_level_not_os);
    ( "mix_os_and_not_os_on_component",
      `Quick,
      test_mix_os_and_not_os_on_component );
    ("mix_os_and_not_os_on_entity", `Quick, test_mix_os_and_not_os_on_entity);
  ]
