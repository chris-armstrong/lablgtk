(* Tests for Override_extractor and parse_doc_text integration *)

(* --- extract_since_version tests --- *)

let test_since_plain () =
  match Gir_gen_lib.Override_extractor.extract_since_version "Since 2.26" with
  | Some "2.26" -> ()
  | other ->
      Alcotest.fail
        (Fmt.str "Expected Some \"2.26\", got %s"
           (match other with Some s -> "Some \"" ^ s ^ "\"" | None -> "None"))

let test_since_colon () =
  match Gir_gen_lib.Override_extractor.extract_since_version "Since: 2.74" with
  | Some "2.74" -> ()
  | other ->
      Alcotest.fail
        (Fmt.str "Expected Some \"2.74\", got %s"
           (match other with Some s -> "Some \"" ^ s ^ "\"" | None -> "None"))

let test_since_in_parens () =
  match
    Gir_gen_lib.Override_extractor.extract_since_version
      "Some text (Since: 1.16)."
  with
  | Some "1.16" -> ()
  | other ->
      Alcotest.fail
        (Fmt.str "Expected Some \"1.16\", got %s"
           (match other with Some s -> "Some \"" ^ s ^ "\"" | None -> "None"))

let test_since_three_part () =
  match Gir_gen_lib.Override_extractor.extract_since_version "Since 4.14.0" with
  | Some "4.14.0" -> ()
  | other ->
      Alcotest.fail
        (Fmt.str "Expected Some \"4.14.0\", got %s"
           (match other with Some s -> "Some \"" ^ s ^ "\"" | None -> "None"))

let test_since_end_of_multiline () =
  let doc = "A long description.\n\nSome more text.\nSince 1.50" in
  match Gir_gen_lib.Override_extractor.extract_since_version doc with
  | Some "1.50" -> ()
  | other ->
      Alcotest.fail
        (Fmt.str "Expected Some \"1.50\", got %s"
           (match other with Some s -> "Some \"" ^ s ^ "\"" | None -> "None"))

let test_since_none () =
  match
    Gir_gen_lib.Override_extractor.extract_since_version "No version info here."
  with
  | None -> ()
  | Some s -> Alcotest.fail (Fmt.str "Expected None, got Some \"%s\"" s)

let test_since_empty () =
  match Gir_gen_lib.Override_extractor.extract_since_version "" with
  | None -> ()
  | Some s -> Alcotest.fail (Fmt.str "Expected None, got Some \"%s\"" s)

(* --- parse_doc_text integration tests via GIR parser ---
   We test parse_doc_text indirectly by checking that parsing a minimal
   GIR XML with <member><doc>...</doc></member> populates member_doc. *)

let ns_attrs =
  {|name="Test" version="1.0" shared-library="libtest.so" c:identifier-prefixes="Test" c:symbol-prefixes="test"|}

let minimal_gir_with_enum_doc =
  Fmt.str
    {|<?xml version="1.0"?>
<repository version="1.2"
  xmlns="http://www.gtk.org/introspection/core/1.0"
  xmlns:c="http://www.gtk.org/introspection/c/1.0"
  xmlns:glib="http://www.gtk.org/introspection/glib/1.0">
  <namespace %s>
    <enumeration name="TestEnum" c:type="TestEnum">
      <member name="value_a" value="0" c:identifier="TEST_VALUE_A">
        <doc xml:space="preserve">The first value. Since 4.10</doc>
      </member>
      <member name="value_b" value="1" c:identifier="TEST_VALUE_B">
        <doc xml:space="preserve">No version here.</doc>
      </member>
      <member name="value_c" value="2" c:identifier="TEST_VALUE_C">
      </member>
    </enumeration>
  </namespace>
</repository>|}
    ns_attrs

let minimal_gir_with_doc_nested_elements =
  Fmt.str
    {|<?xml version="1.0"?>
<repository version="1.2"
  xmlns="http://www.gtk.org/introspection/core/1.0"
  xmlns:c="http://www.gtk.org/introspection/c/1.0"
  xmlns:glib="http://www.gtk.org/introspection/glib/1.0">
  <namespace %s>
    <enumeration name="TestEnum" c:type="TestEnum">
      <member name="value_a" value="0" c:identifier="TEST_VALUE_A">
        <doc xml:space="preserve">See <link href="foo">the docs</link>. Since: 2.30</doc>
      </member>
    </enumeration>
  </namespace>
</repository>|}
    ns_attrs

let minimal_gir_with_record_field_doc =
  Fmt.str
    {|<?xml version="1.0"?>
<repository version="1.2"
  xmlns="http://www.gtk.org/introspection/core/1.0"
  xmlns:c="http://www.gtk.org/introspection/c/1.0"
  xmlns:glib="http://www.gtk.org/introspection/glib/1.0">
  <namespace %s>
    <record name="TestRecord" c:type="TestRecord">
      <field name="x" readable="1" writable="0">
        <doc xml:space="preserve">The x coordinate. Since 1.20</doc>
        <type name="gdouble" c:type="gdouble"/>
      </field>
      <field name="y" readable="1" writable="0">
        <type name="gdouble" c:type="gdouble"/>
      </field>
    </record>
  </namespace>
</repository>|}
    ns_attrs

let minimal_gir_with_bitfield_doc =
  Fmt.str
    {|<?xml version="1.0"?>
<repository version="1.2"
  xmlns="http://www.gtk.org/introspection/core/1.0"
  xmlns:c="http://www.gtk.org/introspection/c/1.0"
  xmlns:glib="http://www.gtk.org/introspection/glib/1.0">
  <namespace %s>
    <bitfield name="TestFlags" c:type="TestFlags">
      <member name="flag_a" value="1" c:identifier="TEST_FLAG_A">
        <doc xml:space="preserve">Flag A. Since 3.12</doc>
      </member>
      <member name="flag_b" value="2" c:identifier="TEST_FLAG_B">
      </member>
    </bitfield>
  </namespace>
</repository>|}
    ns_attrs

let write_temp_gir content =
  let tmp = Filename.temp_file "test_gir_doc" ".gir" in
  let oc = open_out tmp in
  output_string oc content;
  close_out oc;
  tmp

let parse_gir content =
  let tmp = write_temp_gir content in
  let result = Gir_gen_lib.Parse.Gir_parser.parse_gir_file tmp [] in
  Sys.remove tmp;
  result

let test_enum_member_doc_plain () =
  let _repo, _ns, _classes, _ifaces, enums, _bitfields, _records, _ =
    parse_gir minimal_gir_with_enum_doc
  in
  match enums with
  | [ enm ] ->
      let members = enm.Gir_gen_lib.Types.members in
      (* Members come out in reverse order *)
      let find name =
        Helpers.expect_some
          (Fmt.str "Member %s not found" name)
          (List.find_opt
             (fun m -> m.Gir_gen_lib.Types.member_name = name)
             members)
          Fun.id
      in
      let a = find "value_a" in
      let b = find "value_b" in
      let c = find "value_c" in
      Alcotest.(check (option string))
        "value_a doc" (Some "The first value. Since 4.10") a.member_doc;
      Alcotest.(check (option string))
        "value_b doc" (Some "No version here.") b.member_doc;
      Alcotest.(check (option string)) "value_c doc" None c.member_doc
  | other ->
      Alcotest.fail (Fmt.str "Expected 1 enum, got %d" (List.length other))

let test_enum_member_doc_with_nested_elements () =
  (* parse_doc_text should skip nested XML elements (like <link>) and
     collect only the surrounding text *)
  let _repo, _ns, _classes, _ifaces, enums, _bitfields, _records, _ =
    parse_gir minimal_gir_with_doc_nested_elements
  in
  match enums with
  | [ enm ] -> (
      let members = enm.Gir_gen_lib.Types.members in
      let a =
        Helpers.expect_some "Member value_a not found"
          (List.find_opt
             (fun m -> m.Gir_gen_lib.Types.member_name = "value_a")
             members)
          Fun.id
      in
      (* The doc text should contain "See " and ". Since: 2.30" but not the link content *)
      Helpers.expect_some "Expected Some doc, got None"
        a.Gir_gen_lib.Types.member_doc
      @@ fun doc ->
      (* Should contain Since version *)
      match Gir_gen_lib.Override_extractor.extract_since_version doc with
      | Some "2.30" -> ()
      | other ->
          Alcotest.fail
            (Fmt.str "Expected Since 2.30 from doc, got %s"
               (match other with
               | Some s -> "Some \"" ^ s ^ "\""
               | None -> "None")))
  | other ->
      Alcotest.fail (Fmt.str "Expected 1 enum, got %d" (List.length other))

let test_bitfield_flag_doc () =
  let _repo, _ns, _classes, _ifaces, _enums, bitfields, _records, _ =
    parse_gir minimal_gir_with_bitfield_doc
  in
  match bitfields with
  | [ bf ] ->
      let flags = bf.Gir_gen_lib.Types.flags in
      let find name =
        Helpers.expect_some
          (Fmt.str "Flag %s not found" name)
          (List.find_opt (fun f -> f.Gir_gen_lib.Types.flag_name = name) flags)
          Fun.id
      in
      let a = find "flag_a" in
      let b = find "flag_b" in
      Alcotest.(check (option string))
        "flag_a doc" (Some "Flag A. Since 3.12") a.flag_doc;
      Alcotest.(check (option string)) "flag_b doc" None b.flag_doc
  | other ->
      Alcotest.fail (Fmt.str "Expected 1 bitfield, got %d" (List.length other))

let test_record_field_doc () =
  let _repo, _ns, _classes, _ifaces, _enums, _bitfields, records, _ =
    parse_gir minimal_gir_with_record_field_doc
  in
  match records with
  | [ rec_ ] ->
      let fields = rec_.Gir_gen_lib.Types.fields in
      let find name =
        Helpers.expect_some
          (Fmt.str "Field %s not found" name)
          (List.find_opt
             (fun f -> f.Gir_gen_lib.Types.field_name = name)
             fields)
          Fun.id
      in
      let x = find "x" in
      let y = find "y" in
      Alcotest.(check (option string))
        "x field doc" (Some "The x coordinate. Since 1.20") x.field_doc;
      Alcotest.(check (option string)) "y field doc" None y.field_doc
  | other ->
      Alcotest.fail (Fmt.str "Expected 1 record, got %d" (List.length other))

let test_suite =
  [
    ("since_plain", `Quick, test_since_plain);
    ("since_colon", `Quick, test_since_colon);
    ("since_in_parens", `Quick, test_since_in_parens);
    ("since_three_part", `Quick, test_since_three_part);
    ("since_end_of_multiline", `Quick, test_since_end_of_multiline);
    ("since_none", `Quick, test_since_none);
    ("since_empty", `Quick, test_since_empty);
    ("enum_member_doc_plain", `Quick, test_enum_member_doc_plain);
    ( "enum_member_doc_with_nested_elements",
      `Quick,
      test_enum_member_doc_with_nested_elements );
    ("bitfield_flag_doc", `Quick, test_bitfield_flag_doc);
    ("record_field_doc", `Quick, test_record_field_doc);
  ]
