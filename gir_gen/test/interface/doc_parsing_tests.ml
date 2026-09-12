(* Tests for M3 doc parsing: <doc>, <doc-deprecated>, deprecation attributes,
 * and <doc:format> capture into the GIR AST.
 *
 * Synthetic XML uses Helpers.wrap_namespace; real-GIR spot checks use the
 * bundled Gtk-4.0.gir (Helpers.gir_data_dir).
 *
 * Conventions follow parsing_tests.ml.
 *)

open Gir_gen_lib.Types

(* ========================================================================= *)
(* Helpers *)
(* ========================================================================= *)

(** Write [content] to a temp file and return its path. *)
let write_temp_gir content =
  let tmp = Filename.temp_file "test_doc_parsing" ".gir" in
  Helpers.create_gir_file tmp content;
  tmp

(** Wrap namespace content in a minimal GIR repository envelope. *)
let make_gir_xml namespace_content =
  Helpers.wrap_namespace ~version:"4.0" namespace_content

let parse_gir_string content =
  let tmp = write_temp_gir content in
  Fun.protect
    ~finally:(fun () -> Sys.remove tmp)
    (fun () -> Gir_gen_lib.Parse.Gir_parser.parse_gir_file tmp [])

let real_gir_file = Filename.concat (Helpers.gir_data_dir ()) "Gtk-4.0.gir"

let find_class name classes =
  List.find_opt (fun (c : gir_class) -> String.equal c.class_name name) classes

let find_iface name interfaces =
  List.find_opt
    (fun (i : gir_interface) -> String.equal i.interface_name name)
    interfaces

let find_enum name enums =
  List.find_opt (fun (e : gir_enum) -> String.equal e.enum_name name) enums

let find_bitfield name bitfields =
  List.find_opt
    (fun (b : gir_bitfield) -> String.equal b.bitfield_name name)
    bitfields

let find_prop name props =
  List.find_opt (fun (p : gir_property) -> String.equal p.prop_name name) props

let find_method name methods =
  List.find_opt
    (fun (m : gir_method) -> String.equal m.method_name name)
    methods

(** [contains_substring s sub] is [true] when [sub] occurs in [s]. *)
let contains_substring s sub =
  let n = String.length s and m = String.length sub in
  let rec go i =
    if i + m > n then false
    else if String.equal (String.sub s i m) sub then true
    else go (i + 1)
  in
  go 0

(** Check a [gir_deprecation option] field by field (no structural equality on
    custom types). *)
let check_deprecation label expected actual =
  match (expected, actual) with
  | None, None -> Alcotest.(check bool) (label ^ ": none") true true
  | None, Some _ -> Alcotest.(check bool) (label ^ ": expected None") false true
  | Some _expected, None ->
      Alcotest.(check bool) (label ^ ": expected Some") true false
  | Some expected, Some actual -> (
      Alcotest.(check bool)
        (label ^ ": deprecated") expected.deprecated actual.deprecated;
      Alcotest.(check (option string))
        (label ^ ": deprecated_version")
        expected.deprecated_version actual.deprecated_version;
      match (expected.deprecated_doc, actual.deprecated_doc) with
      | None, None -> ()
      | None, Some _ ->
          Alcotest.(check bool) (label ^ ": deprecated_doc None") false true
      | Some _, None ->
          Alcotest.(check bool) (label ^ ": deprecated_doc Some") true false
      | Some expected_doc, Some actual_doc ->
          Alcotest.(check bool)
            (label ^ ": deprecated_doc content")
            true
            (contains_substring actual_doc expected_doc))

(* ========================================================================= *)
(* Synthetic XML: entity-level <doc> capture *)
(* ========================================================================= *)

let class_doc_xml =
  make_gir_xml
    {|
    <class name="Button" c:type="GtkButton" parent="Widget">
      <doc>A button widget</doc>
    </class>
  |}

let test_class_doc () =
  let _, _, classes, _, _, _, _, _ = parse_gir_string class_doc_xml in
  let button =
    Helpers.expect_some "Button not found" (find_class "Button" classes) Fun.id
  in
  Alcotest.(check (option string))
    "class_doc" (Some "A button widget") button.class_doc

let interface_doc_xml =
  make_gir_xml
    {|<interface name="MyIface"
               c:type="GtkMyIface"
               glib:type-name="GtkMyIface"
               glib:get-type="gtk_my_iface_get_type">
      <doc>An interface</doc>
    </interface>|}

let test_interface_doc () =
  let _, _, _, interfaces, _, _, _, _ = parse_gir_string interface_doc_xml in
  let iface =
    Helpers.expect_some "MyIface not found"
      (find_iface "MyIface" interfaces)
      Fun.id
  in
  Alcotest.(check (option string))
    "interface_doc" (Some "An interface") iface.interface_doc

let enum_doc_xml =
  make_gir_xml
    {|<enumeration name="Mode" c:type="GtkMode">
      <doc>A mode</doc>
      <member name="OFF" value="0" c:identifier="GTK_MODE_OFF"/>
      <member name="ON" value="1" c:identifier="GTK_MODE_ON"/>
    </enumeration>|}

let test_enum_doc () =
  let _, _, _, _, enums, _, _, _ = parse_gir_string enum_doc_xml in
  let mode =
    Helpers.expect_some "Mode not found" (find_enum "Mode" enums) Fun.id
  in
  Alcotest.(check (option string)) "enum_doc" (Some "A mode") mode.enum_doc

let bitfield_doc_xml =
  make_gir_xml
    {|<bitfield name="Flags" c:type="GtkFlags">
      <doc>Some flags</doc>
      <member name="A" value="1" c:identifier="GTK_FLAGS_A"/>
    </bitfield>|}

let test_bitfield_doc () =
  let _, _, _, _, _, bitfields, _, _ = parse_gir_string bitfield_doc_xml in
  let flags =
    Helpers.expect_some "Flags not found"
      (find_bitfield "Flags" bitfields)
      Fun.id
  in
  Alcotest.(check (option string))
    "bitfield_doc" (Some "Some flags") flags.bitfield_doc

let property_doc_xml =
  make_gir_xml
    {|<class name="Button" c:type="GtkButton" parent="Widget">
      <property name="label" writable="1" readable="1">
        <doc>The button label</doc>
        <type name="utf8" c:type="gchar*"/>
      </property>
    </class>|}

let test_property_doc () =
  let _, _, classes, _, _, _, _, _ = parse_gir_string property_doc_xml in
  let button =
    Helpers.expect_some "Button not found" (find_class "Button" classes) Fun.id
  in
  let label =
    Helpers.expect_some "label property not found"
      (find_prop "label" button.properties)
      Fun.id
  in
  Alcotest.(check (option string))
    "prop_doc" (Some "The button label") label.prop_doc

(* ========================================================================= *)
(* Synthetic XML: parameter and return-value <doc> *)
(* ========================================================================= *)

let param_and_return_doc_xml =
  make_gir_xml
    {|<class name="Button" c:type="GtkButton" parent="Widget">
      <method name="set_label" c:identifier="gtk_button_set_label">
        <doc>Sets the label</doc>
        <return-value>
          <doc>The previous label</doc>
          <type name="utf8" c:type="gchar*"/>
        </return-value>
        <parameters>
          <parameter name="label" transfer-ownership="none">
            <doc>The new label</doc>
            <type name="utf8" c:type="const gchar*"/>
          </parameter>
        </parameters>
      </method>
    </class>|}

let test_param_doc () =
  let _, _, classes, _, _, _, _, _ =
    parse_gir_string param_and_return_doc_xml
  in
  let button =
    Helpers.expect_some "Button not found" (find_class "Button" classes) Fun.id
  in
  let set_label =
    Helpers.expect_some "set_label not found"
      (find_method "set_label" button.methods)
      Fun.id
  in
  match set_label.parameters with
  | [ param ] ->
      Alcotest.(check (option string))
        "param_doc" (Some "The new label") param.param_doc
  | _ -> Alcotest.fail "expected exactly one parameter"

let test_return_doc () =
  let _, _, classes, _, _, _, _, _ =
    parse_gir_string param_and_return_doc_xml
  in
  let button =
    Helpers.expect_some "Button not found" (find_class "Button" classes) Fun.id
  in
  let set_label =
    Helpers.expect_some "set_label not found"
      (find_method "set_label" button.methods)
      Fun.id
  in
  Alcotest.(check (option string))
    "return_doc" (Some "The previous label") set_label.return_doc

(* ========================================================================= *)
(* Synthetic XML: <doc-deprecated> + deprecation attributes *)
(* ========================================================================= *)

let deprecated_class_xml =
  make_gir_xml
    {|<class name="OldWidget" c:type="GtkOldWidget" parent="Widget"
               deprecated="1" deprecated-version="4.10">
      <doc>An old widget</doc>
      <doc-deprecated>Use NewWidget instead</doc-deprecated>
    </class>|}

let test_class_deprecation () =
  let _, _, classes, _, _, _, _, _ = parse_gir_string deprecated_class_xml in
  let old_widget =
    Helpers.expect_some "OldWidget not found"
      (find_class "OldWidget" classes)
      Fun.id
  in
  check_deprecation "OldWidget deprecation"
    (Some
       {
         deprecated = true;
         deprecated_version = Some "4.10";
         deprecated_doc = Some "Use NewWidget";
       })
    old_widget.deprecation

let deprecated_member_xml =
  make_gir_xml
    {|<enumeration name="Mode" c:type="GtkMode">
      <member name="OFF" value="0" c:identifier="GTK_MODE_OFF"/>
      <member name="ON" value="1" c:identifier="GTK_MODE_ON"
              deprecated="1" deprecated-version="4.10">
        <doc-deprecated>Use OFF instead</doc-deprecated>
      </member>
    </enumeration>|}

let test_member_deprecation () =
  let _, _, _, _, enums, _, _, _ = parse_gir_string deprecated_member_xml in
  let mode =
    Helpers.expect_some "Mode not found" (find_enum "Mode" enums) Fun.id
  in
  let on_member =
    List.find_opt
      (fun (m : gir_enum_member) -> String.equal m.member_name "ON")
      mode.members
  in
  let on = Helpers.expect_some "ON member not found" on_member Fun.id in
  check_deprecation "ON member deprecation"
    (Some
       {
         deprecated = true;
         deprecated_version = Some "4.10";
         deprecated_doc = Some "Use OFF";
       })
    on.deprecation

let non_deprecated_class_xml =
  make_gir_xml
    {|<class name="Fresh" c:type="GtkFresh" parent="Widget">
      <doc>A fresh widget</doc>
    </class>|}

let test_no_deprecation_is_none () =
  let _, _, classes, _, _, _, _, _ =
    parse_gir_string non_deprecated_class_xml
  in
  let fresh =
    Helpers.expect_some "Fresh not found" (find_class "Fresh" classes) Fun.id
  in
  check_deprecation "Fresh deprecation" None fresh.deprecation

let array_param_doc_xml =
  make_gir_xml
    {|<class name="Box" c:type="GtkBox" parent="Widget">
      <method name="set_items" c:identifier="gtk_box_set_items">
        <return-value><type name="none" c:type="void"/></return-value>
        <parameters>
          <parameter name="items" transfer-ownership="none">
            <doc>The items to set</doc>
            <array c:type="GtkWidget**">
              <type name="Widget" c:type="GtkWidget*"/>
            </array>
          </parameter>
        </parameters>
      </method>
    </class>|}

let test_array_param_doc () =
  let _, _, classes, _, _, _, _, _ = parse_gir_string array_param_doc_xml in
  let box =
    Helpers.expect_some "Box not found" (find_class "Box" classes) Fun.id
  in
  let set_items =
    Helpers.expect_some "set_items not found"
      (find_method "set_items" box.methods)
      Fun.id
  in
  match set_items.parameters with
  | [ param ] ->
      Alcotest.(check bool)
        "array param parsed as array" true
        (Option.is_some param.param_type.array);
      Alcotest.(check (option string))
        "param_doc alongside <array>" (Some "The items to set") param.param_doc
  | _ -> Alcotest.fail "expected exactly one parameter"

let deprecated_property_xml =
  make_gir_xml
    {|<class name="OldButton" c:type="GtkOldButton" parent="Widget">
      <property name="urgent" writable="1" readable="1"
                deprecated="1" deprecated-version="4.12">
        <doc>Whether urgent</doc>
        <doc-deprecated>Use the priority property</doc-deprecated>
        <type name="gboolean" c:type="gboolean"/>
      </property>
    </class>|}

let test_property_deprecation () =
  let _, _, classes, _, _, _, _, _ = parse_gir_string deprecated_property_xml in
  let button =
    Helpers.expect_some "OldButton not found"
      (find_class "OldButton" classes)
      Fun.id
  in
  let urgent =
    Helpers.expect_some "urgent property not found"
      (find_prop "urgent" button.properties)
      Fun.id
  in
  check_deprecation "urgent property deprecation"
    (Some
       {
         deprecated = true;
         deprecated_version = Some "4.12";
         deprecated_doc = Some "priority property";
       })
    urgent.deprecation

let deprecated_no_doc_xml =
  make_gir_xml
    {|<class name="Plain" c:type="GtkPlain" parent="Widget"
               deprecated="1" deprecated-version="4.8">
      <doc>A plain widget</doc>
    </class>|}

let test_deprecation_attrs_without_doc () =
  let _, _, classes, _, _, _, _, _ = parse_gir_string deprecated_no_doc_xml in
  let plain =
    Helpers.expect_some "Plain not found" (find_class "Plain" classes) Fun.id
  in
  check_deprecation "Plain deprecation (no doc-deprecated)"
    (Some
       {
         deprecated = true;
         deprecated_version = Some "4.8";
         deprecated_doc = None;
       })
    plain.deprecation

let doc_deprecated_only_xml =
  make_gir_xml
    {|<class name="Hinted" c:type="GtkHinted" parent="Widget">
      <doc-deprecated>Deprecated informally</doc-deprecated>
      <doc>A hinted widget</doc>
    </class>|}

let test_doc_deprecated_without_attrs () =
  let _, _, classes, _, _, _, _, _ = parse_gir_string doc_deprecated_only_xml in
  let hinted =
    Helpers.expect_some "Hinted not found" (find_class "Hinted" classes) Fun.id
  in
  (* <doc-deprecated> precedes <doc> here, also covering either-order
     handling. *)
  Alcotest.(check (option string))
    "class_doc still captured" (Some "A hinted widget") hinted.class_doc;
  check_deprecation "Hinted deprecation (attrs absent)"
    (Some
       {
         deprecated = false;
         deprecated_version = None;
         deprecated_doc = Some "Deprecated informally";
       })
    hinted.deprecation

(* ========================================================================= *)
(* Synthetic XML: <doc:format> *)
(* ========================================================================= *)

(* [wrap_namespace] does not declare the doc namespace prefix, so this case
   writes its own repository envelope. *)
let doc_format_xml =
  {|<?xml version="1.0"?>
<repository version="1.2"
            xmlns="http://www.gtk.org/introspection/core/1.0"
            xmlns:c="http://www.gtk.org/introspection/c/1.0"
            xmlns:doc="http://www.gtk.org/introspection/doc/1.0">
  <doc:format name="gi-docgen"/>
  <namespace name="Gtk" version="4.0" shared-library="libgtk-4.so.1"
             c:identifier-prefixes="Gtk" c:symbol-prefixes="gtk">
  </namespace>
</repository>|}

let test_repository_doc_format () =
  let repo, _, _, _, _, _, _, _ = parse_gir_string doc_format_xml in
  Alcotest.(check (option string))
    "repository_doc_format" (Some "gi-docgen") repo.repository_doc_format

(* ========================================================================= *)
(* Synthetic XML: empty <doc> *)
(* ========================================================================= *)

let empty_doc_class_xml =
  make_gir_xml
    {|<class name="Silent" c:type="GtkSilent" parent="Widget">
      <doc></doc>
    </class>|}

let test_empty_doc_is_none () =
  let _, _, classes, _, _, _, _, _ = parse_gir_string empty_doc_class_xml in
  let silent =
    Helpers.expect_some "Silent not found" (find_class "Silent" classes) Fun.id
  in
  Alcotest.(check (option string)) "empty doc yields None" None silent.class_doc

(* ========================================================================= *)
(* Real GIR: Gtk-4.0.gir spot checks *)
(* ========================================================================= *)

let test_button_class_doc () =
  let _, _, classes, _, _, _, _, _ =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file real_gir_file []
  in
  let button =
    Helpers.expect_some "Button not found" (find_class "Button" classes) Fun.id
  in
  Alcotest.(check bool)
    "Button class_doc non-empty" true
    (match button.class_doc with
    | Some doc -> String.length doc > 0
    | None -> false)

let test_tree_store_class_deprecation () =
  let _, _, classes, _, _, _, _, _ =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file real_gir_file []
  in
  let tree_store =
    Helpers.expect_some "TreeStore not found"
      (find_class "TreeStore" classes)
      Fun.id
  in
  check_deprecation "TreeStore class deprecation"
    (Some
       {
         deprecated = true;
         deprecated_version = Some "4.10";
         deprecated_doc = Some "TreeListModel";
       })
    tree_store.deprecation

let test_calendar_select_day_deprecation () =
  let _, _, classes, _, _, _, _, _ =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file real_gir_file []
  in
  let calendar =
    Helpers.expect_some "Calendar not found"
      (find_class "Calendar" classes)
      Fun.id
  in
  let select_day =
    Helpers.expect_some "select_day not found"
      (find_method "select_day" calendar.methods)
      Fun.id
  in
  check_deprecation "Calendar.select_day deprecation"
    (Some
       {
         deprecated = true;
         deprecated_version = Some "4.20";
         deprecated_doc = Some "set_date";
       })
    select_day.deprecation

let test_orientable_orientation_prop_doc () =
  let _, _, _, interfaces, _, _, _, _ =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file real_gir_file []
  in
  let orientable =
    Helpers.expect_some "Orientable not found"
      (find_iface "Orientable" interfaces)
      Fun.id
  in
  let orientation =
    Helpers.expect_some "orientation property not found"
      (find_prop "orientation" orientable.properties)
      Fun.id
  in
  Alcotest.(check bool)
    "Orientable.orientation prop_doc populated" true
    (match orientation.prop_doc with
    | Some doc -> String.length doc > 0
    | None -> false)

let test_enum_level_doc () =
  let _, _, _, _, enums, _, _, _ =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file real_gir_file []
  in
  let priority =
    Helpers.expect_some "AccessibleAnnouncementPriority not found"
      (find_enum "AccessibleAnnouncementPriority" enums)
      Fun.id
  in
  Alcotest.(check bool)
    "enum-level doc populated" true
    (match priority.enum_doc with
    | Some doc -> String.length doc > 0
    | None -> false)

let test_bitfield_level_doc () =
  let _, _, _, _, _, bitfields, _, _ =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file real_gir_file []
  in
  let inhibit =
    Helpers.expect_some "ApplicationInhibitFlags not found"
      (find_bitfield "ApplicationInhibitFlags" bitfields)
      Fun.id
  in
  Alcotest.(check bool)
    "bitfield-level doc populated" true
    (match inhibit.bitfield_doc with
    | Some doc -> String.length doc > 0
    | None -> false)

(* ========================================================================= *)
(* Real GIR files: <doc:format> per namespace (PRD §3.2 table) *)
(* ========================================================================= *)

let doc_format_expectations =
  [
    ("Gtk-4.0.gir", Some "gi-docgen");
    ("Gio-2.0.gir", Some "gi-docgen");
    ("Gdk-4.0.gir", Some "gi-docgen");
    ("Pango-1.0.gir", Some "gi-docgen");
    ("Gsk-4.0.gir", Some "gi-docgen");
    ("PangoCairo-1.0.gir", Some "gi-docgen");
    ("Graphene-1.0.gir", Some "unknown");
    ("GdkPixbuf-2.0.gir", Some "unknown");
    ("cairo-1.0.gir", None);
  ]

let test_doc_format_all_namespaces () =
  let dir = Helpers.gir_data_dir () in
  List.iter
    (fun (file, expected) ->
      let repo, _, _, _, _, _, _, _ =
        Gir_gen_lib.Parse.Gir_parser.parse_gir_file (Filename.concat dir file)
          []
      in
      Alcotest.(check (option string))
        (Printf.sprintf "doc:format of %s" file)
        expected repo.repository_doc_format)
    doc_format_expectations

(* ========================================================================= *)
(* Test suite *)
(* ========================================================================= *)

let test_suite =
  [
    ("synthetic: class doc", `Quick, test_class_doc);
    ("synthetic: interface doc", `Quick, test_interface_doc);
    ("synthetic: enum doc", `Quick, test_enum_doc);
    ("synthetic: bitfield doc", `Quick, test_bitfield_doc);
    ("synthetic: property doc", `Quick, test_property_doc);
    ("synthetic: param doc", `Quick, test_param_doc);
    ("synthetic: array-typed param doc", `Quick, test_array_param_doc);
    ("synthetic: return-value doc", `Quick, test_return_doc);
    ("synthetic: class deprecation bundle", `Quick, test_class_deprecation);
    ("synthetic: enum member deprecation", `Quick, test_member_deprecation);
    ("synthetic: property deprecation", `Quick, test_property_deprecation);
    ( "synthetic: deprecation attrs without doc-deprecated",
      `Quick,
      test_deprecation_attrs_without_doc );
    ( "synthetic: doc-deprecated without attrs (either order)",
      `Quick,
      test_doc_deprecated_without_attrs );
    ("synthetic: no deprecation is None", `Quick, test_no_deprecation_is_none);
    ("synthetic: doc:format name", `Quick, test_repository_doc_format);
    ("synthetic: empty doc is None", `Quick, test_empty_doc_is_none);
    ("real: Gtk.Button class_doc non-empty", `Slow, test_button_class_doc);
    ( "real: TreeStore class deprecation 4.10",
      `Slow,
      test_tree_store_class_deprecation );
    ( "real: Calendar.select_day deprecation mentions set_date",
      `Slow,
      test_calendar_select_day_deprecation );
    ( "real: Orientable.orientation prop_doc",
      `Slow,
      test_orientable_orientation_prop_doc );
    ("real: enum-level doc populated", `Slow, test_enum_level_doc);
    ("real: bitfield-level doc populated", `Slow, test_bitfield_level_doc);
    ( "real: doc:format across all nine namespaces",
      `Slow,
      test_doc_format_all_namespaces );
  ]
