(* Parser tests - directly test GIR XML parsing *)

open Helpers
open Gir_gen_lib.Types

(* ========================================================================= *)
(* Parser Helper Functions *)
(* ========================================================================= *)

(* Parse a GIR XML string and return parsed components *)
let parse_gir_string xml_content =
  let temp_file = Filename.temp_file "test_parser_" ".gir" in
  create_gir_file temp_file xml_content;
  let result = Gir_gen_lib.Parse.Gir_parser.parse_gir_file temp_file [] in
  Unix.unlink temp_file;
  result

(* Helper to check if a list contains an element matching a predicate *)
let list_contains ~pred lst = List.exists pred lst

(* ========================================================================= *)
(* Class Parsing Tests *)
(* ========================================================================= *)

let test_parse_simple_class () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Button" c:type="GtkButton" parent="Widget">
      <doc>A button widget</doc>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in

  Alcotest.(check int) "Should parse one class" 1 (List.length classes);

  let button = List.hd classes in
  Alcotest.(check string)
    "Class name should be Button" "Button" button.class_name;
  Alcotest.(check string) "C type should be GtkButton" "GtkButton" button.c_type;
  Alcotest.(check (option string))
    "Parent should be Widget" (Some "Widget") button.parent;
  (* Note: The parser currently does not parse class-level documentation *)
  Alcotest.(check (option string))
    "Doc is not parsed for classes" None button.class_doc

let test_parse_class_without_ctype () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="CustomWidget" parent="Widget">
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in

  Alcotest.(check int) "Should parse one class" 1 (List.length classes);

  let widget = List.hd classes in
  (* When c:type is missing, parser should generate it as "Gtk" + name *)
  Alcotest.(check string)
    "C type should default to GtkCustomWidget" "GtkCustomWidget" widget.c_type

let test_parse_class_with_constructors () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Button" c:type="GtkButton" parent="Widget">
      <constructor name="new" c:identifier="gtk_button_new">
        <doc>Creates a new button</doc>
        <return-value>
          <type name="Widget" c:type="GtkWidget*"/>
        </return-value>
      </constructor>
      <constructor name="new_with_label" c:identifier="gtk_button_new_with_label">
        <return-value>
          <type name="Widget" c:type="GtkWidget*"/>
        </return-value>
        <parameters>
          <parameter name="label">
            <type name="utf8" c:type="const gchar*"/>
          </parameter>
        </parameters>
      </constructor>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let button = List.hd classes in

  Alcotest.(check int)
    "Should have 2 constructors" 2
    (List.length button.constructors);

  let ctor_new = List.find (fun c -> c.ctor_name = "new") button.constructors in
  Alcotest.(check string)
    "Constructor c_identifier" "gtk_button_new" ctor_new.c_identifier;
  Alcotest.(check (option string))
    "Constructor doc" (Some "Creates a new button") ctor_new.ctor_doc;
  Alcotest.(check int)
    "Constructor has no params" 0
    (List.length ctor_new.ctor_parameters);

  let ctor_with_label =
    List.find (fun c -> c.ctor_name = "new_with_label") button.constructors
  in
  Alcotest.(check int)
    "Constructor has 1 param" 1
    (List.length ctor_with_label.ctor_parameters);

  let param = List.hd ctor_with_label.ctor_parameters in
  Alcotest.(check string) "Param name" "label" param.param_name;
  Alcotest.(check string) "Param type name" "utf8" param.param_type.name

let test_parse_class_with_methods () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Button" c:type="GtkButton" parent="Widget">
      <method name="set_label" c:identifier="gtk_button_set_label">
        <doc>Sets the label</doc>
        <return-value>
          <type name="none" c:type="void"/>
        </return-value>
        <parameters>
          <parameter name="label">
            <type name="utf8" c:type="const gchar*"/>
          </parameter>
        </parameters>
      </method>
      <method name="get_label" c:identifier="gtk_button_get_label">
        <return-value>
          <type name="utf8" c:type="const gchar*"/>
        </return-value>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let button = List.hd classes in

  Alcotest.(check int) "Should have 2 methods" 2 (List.length button.methods);

  let set_label =
    List.find (fun m -> m.method_name = "set_label") button.methods
  in
  Alcotest.(check string)
    "Method c_identifier" "gtk_button_set_label" set_label.c_identifier;
  Alcotest.(check (option string))
    "Method doc" (Some "Sets the label") set_label.doc;
  Alcotest.(check string) "Return type" "none" set_label.return_type.name;
  Alcotest.(check int) "Has 1 parameter" 1 (List.length set_label.parameters);

  let get_label =
    List.find (fun m -> m.method_name = "get_label") button.methods
  in
  Alcotest.(check string)
    "Return type is utf8" "utf8" get_label.return_type.name;
  Alcotest.(check int) "Has no parameters" 0 (List.length get_label.parameters)

let test_parse_class_with_properties () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Button" c:type="GtkButton" parent="Widget">
      <property name="label" writable="1" readable="1">
        <doc>The button label</doc>
        <type name="utf8" c:type="gchar*"/>
      </property>
      <property name="use-underline" writable="1" readable="1" construct-only="1">
        <type name="gboolean" c:type="gboolean"/>
      </property>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let button = List.hd classes in

  Alcotest.(check int)
    "Should have 2 properties" 2
    (List.length button.properties);

  let label_prop =
    List.find (fun p -> p.prop_name = "label") button.properties
  in
  Alcotest.(check bool) "Property is readable" true label_prop.readable;
  Alcotest.(check bool) "Property is writable" true label_prop.writable;
  Alcotest.(check bool)
    "Property is not construct-only" false label_prop.construct_only;
  Alcotest.(check string) "Property type" "utf8" label_prop.prop_type.name;
  (* Note: The parser currently does not parse property documentation *)
  Alcotest.(check (option string))
    "Property doc is not parsed" None label_prop.prop_doc;

  let underline_prop =
    List.find (fun p -> p.prop_name = "use-underline") button.properties
  in
  Alcotest.(check bool)
    "Property is construct-only" true underline_prop.construct_only

let signal_run_when_to_string : signal_run_when option -> string = function
  | None -> "none"
  | Some RunFirst -> "first"
  | Some RunLast -> "last"
  | Some RunCleanup -> "cleanup"

let check_run_when label expected actual =
  Alcotest.(check string)
    label
    (signal_run_when_to_string expected)
    (signal_run_when_to_string actual)

let test_parse_class_with_signals () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Button" c:type="GtkButton" parent="Widget">
      <glib:signal name="clicked" when="first">
        <doc>Emitted when clicked</doc>
        <return-value transfer-ownership="none">
          <type name="none" c:type="void"/>
        </return-value>
        <parameters/>
      </glib:signal>
      <glib:signal name="activate" when="last">
        <return-value transfer-ownership="none">
          <type name="none" c:type="void"/>
        </return-value>
        <parameters>
          <parameter name="data">
            <type name="gpointer" c:type="gpointer"/>
          </parameter>
        </parameters>
      </glib:signal>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let button = List.hd classes in

  Alcotest.(check int) "Should have 2 signals" 2 (List.length button.signals);

  let clicked = List.find (fun s -> s.signal_name = "clicked") button.signals in
  Alcotest.(check string) "Signal return type" "none" clicked.return_type.name;
  Alcotest.(check int)
    "Signal has no parameters" 0
    (List.length clicked.sig_parameters);
  check_run_when "clicked run_when is first" (Some RunFirst) clicked.run_when;

  let activate =
    List.find (fun s -> s.signal_name = "activate") button.signals
  in
  Alcotest.(check int)
    "Signal has 1 parameter" 1
    (List.length activate.sig_parameters);
  check_run_when "activate run_when is last" (Some RunLast) activate.run_when

let test_parse_signal_flags () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Widget" c:type="GtkWidget">
      <glib:signal name="default-flags">
        <return-value transfer-ownership="none">
          <type name="none" c:type="void"/>
        </return-value>
      </glib:signal>
      <glib:signal name="cleanup-signal" when="cleanup">
        <return-value transfer-ownership="none">
          <type name="none" c:type="void"/>
        </return-value>
      </glib:signal>
      <glib:signal name="full-flags" when="last" action="1" no-recurse="1"
                   no-hooks="1">
        <return-value transfer-ownership="none">
          <type name="none" c:type="void"/>
        </return-value>
      </glib:signal>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let widget = List.hd classes in

  let default_flags =
    List.find (fun s -> s.signal_name = "default-flags") widget.signals
  in
  check_run_when "omitted when= -> None" None default_flags.run_when;
  Alcotest.(check bool) "default action is false" false default_flags.action;
  Alcotest.(check bool)
    "default no_recurse is false" false default_flags.no_recurse;
  Alcotest.(check bool) "default no_hooks is false" false default_flags.no_hooks;

  let cleanup =
    List.find (fun s -> s.signal_name = "cleanup-signal") widget.signals
  in
  check_run_when "when=cleanup parses" (Some RunCleanup) cleanup.run_when;

  let full = List.find (fun s -> s.signal_name = "full-flags") widget.signals in
  check_run_when "when=last parses" (Some RunLast) full.run_when;
  Alcotest.(check bool) "action=1 parses" true full.action;
  Alcotest.(check bool) "no-recurse=1 parses" true full.no_recurse;
  Alcotest.(check bool) "no-hooks=1 parses" true full.no_hooks

(* ========================================================================= *)
(* Interface Parsing Tests *)
(* ========================================================================= *)

let test_parse_interface () =
  let gir_xml =
    wrap_namespace
      {|
    <interface name="Editable" c:type="GtkEditable" c:symbol-prefix="editable">
      <method name="get_text" c:identifier="gtk_editable_get_text">
        <return-value>
          <type name="utf8" c:type="const gchar*"/>
        </return-value>
      </method>
      <property name="text" readable="1" writable="1">
        <type name="utf8" c:type="gchar*"/>
      </property>
    </interface>
  |}
  in

  let _, _, _, interfaces, _, _, _, _ = parse_gir_string gir_xml in

  Alcotest.(check int) "Should parse one interface" 1 (List.length interfaces);

  let editable = List.hd interfaces in
  Alcotest.(check string) "Interface name" "Editable" editable.interface_name;
  Alcotest.(check string) "Interface c_type" "GtkEditable" editable.c_type;
  Alcotest.(check int) "Interface has 1 method" 1 (List.length editable.methods);
  Alcotest.(check int)
    "Interface has 1 property" 1
    (List.length editable.properties)

let test_parse_interface_without_ctype () =
  let gir_xml =
    wrap_namespace
      {|
    <interface name="CustomInterface" c:symbol-prefix="custom">
    </interface>
  |}
  in

  let _, _, _, interfaces, _, _, _, _ = parse_gir_string gir_xml in
  let iface = List.hd interfaces in

  (* When c:type is missing, parser should generate it as "Gtk" + name *)
  Alcotest.(check string)
    "C type should default" "GtkCustomInterface" iface.c_type

(* ========================================================================= *)
(* Enum Parsing Tests *)
(* ========================================================================= *)

let test_parse_enum () =
  let gir_xml =
    wrap_namespace
      {|
    <enumeration name="Orientation" c:type="GtkOrientation">
      <doc>Orientation enum</doc>
      <member name="horizontal" value="0" c:identifier="GTK_ORIENTATION_HORIZONTAL">
        <doc>Horizontal orientation</doc>
      </member>
      <member name="vertical" value="1" c:identifier="GTK_ORIENTATION_VERTICAL">
        <doc>Vertical orientation</doc>
      </member>
    </enumeration>
  |}
  in

  let _, _, _, _, enums, _, _, _ = parse_gir_string gir_xml in

  Alcotest.(check int) "Should parse one enum" 1 (List.length enums);

  let orientation = List.hd enums in
  Alcotest.(check string) "Enum name" "Orientation" orientation.enum_name;
  Alcotest.(check string) "Enum c_type" "GtkOrientation" orientation.enum_c_type;
  Alcotest.(check int) "Enum has 2 members" 2 (List.length orientation.members);

  let horizontal =
    List.find (fun m -> m.member_name = "horizontal") orientation.members
  in
  Alcotest.(check int) "Member value" 0 horizontal.member_value;
  Alcotest.(check string)
    "Member c_identifier" "GTK_ORIENTATION_HORIZONTAL" horizontal.c_identifier

let test_parse_enum_missing_ctype () =
  let gir_xml =
    wrap_namespace
      {|
    <enumeration name="TestEnum">
      <member name="value1" value="0" c:identifier="TEST_VALUE1"/>
    </enumeration>
  |}
  in

  let _, _, _, _, enums, _, _, _ = parse_gir_string gir_xml in

  (* Enum without c:type should be skipped *)
  Alcotest.(check int) "Should skip enum without c:type" 0 (List.length enums)

(* Regression: a <function> inside an <enumeration> must not drop the
   <member>s that follow it, and the function itself must be parsed via the
   [parse_functions] callback. This exercises the recursive-fold-with-callback
   shape of [parse_enumeration]. *)
let test_parse_enum_with_function_and_members () =
  let gir_xml =
    wrap_namespace
      {|
    <enumeration name="Orientation" c:type="GtkOrientation">
      <member name="horizontal" value="0" c:identifier="GTK_ORIENTATION_HORIZONTAL"/>
      <function name="to_string" c:identifier="gtk_orientation_to_string">
        <return-value><type name="utf8" c:type="gchar*"/></return-value>
      </function>
      <member name="vertical" value="1" c:identifier="GTK_ORIENTATION_VERTICAL"/>
    </enumeration>
  |}
  in
  let _, _, _, _, enums, _, _, _ = parse_gir_string gir_xml in
  let orientation = List.hd enums in
  Alcotest.(check int)
    "both members survive the <function>" 2
    (List.length orientation.members);
  Alcotest.(check int)
    "enum function parsed" 1
    (List.length orientation.functions);
  let member_names =
    List.map (fun (m : gir_enum_member) -> m.member_name) orientation.members
  in
  Alcotest.(check (list string))
    "member order preserved"
    [ "horizontal"; "vertical" ]
    member_names

(* ========================================================================= *)
(* Constant Parsing Tests *)
(* ========================================================================= *)

(* Parse a single <constant> and assert every field of [gir_constant]. *)
let test_parse_constant_utf8 () =
  let gir_xml =
    wrap_namespace
      {|
    <constant name="ACCESSIBLE_ATTRIBUTE_BACKGROUND" value="bg-color"
              c:type="GTK_ACCESSIBLE_ATTRIBUTE_BACKGROUND" version="4.14">
      <doc xml:space="preserve">Background color attribute.</doc>
      <type name="utf8" c:type="gchar*"/>
    </constant>
  |}
  in

  let _, _, _, _, _, _, _, constants = parse_gir_string gir_xml in

  Alcotest.(check int) "one constant parsed" 1 (List.length constants);

  let c = List.hd constants in
  Alcotest.(check string)
    "name" "ACCESSIBLE_ATTRIBUTE_BACKGROUND" c.constant_name;
  Alcotest.(check string)
    "c_type" "GTK_ACCESSIBLE_ATTRIBUTE_BACKGROUND" c.constant_c_type;
  Alcotest.(check string) "value" "bg-color" c.value;
  Alcotest.(check string) "value type name" "utf8" c.value_type.name;
  Alcotest.(check (option string))
    "value c_type" (Some "gchar*") c.value_type.c_type;
  Alcotest.(check (option string))
    "doc" (Some "Background color attribute.") c.constant_doc;
  Alcotest.(check (option string)) "version" (Some "4.14") c.version

(* Exercise each observed GIR value type so the parser records the right
   [value_type.name] for the downstream type mapper. *)
let test_parse_constant_value_types () =
  let one ~type_name xml_type =
    let gir_xml =
      wrap_namespace
        (Fmt.str
           {|<constant name="C" value="0" c:type="C">
      %s
    </constant>|}
           xml_type)
    in
    let _, _, _, _, _, _, _, constants = parse_gir_string gir_xml in
    Alcotest.(check int) (type_name ^ " parsed") 1 (List.length constants);
    let c = List.hd constants in
    Alcotest.(check string)
      (type_name ^ " value_type.name")
      type_name c.value_type.name
  in
  one ~type_name:"gint" {|<type name="gint" c:type="gint"/>|};
  one ~type_name:"guint" {|<type name="guint" c:type="guint"/>|};
  one ~type_name:"gdouble" {|<type name="gdouble" c:type="gdouble"/>|};
  one ~type_name:"gboolean" {|<type name="gboolean" c:type="gboolean"/>|};
  one ~type_name:"Glyph" {|<type name="Glyph" c:type="PangoGlyph"/>|}

(* A constant with no doc and no version still parses, with both as [None]. *)
let test_parse_constant_minimal () =
  let gir_xml =
    wrap_namespace
      {|
    <constant name="SIMPLE" value="42" c:type="SIMPLE">
      <type name="gint" c:type="gint"/>
    </constant>
  |}
  in

  let _, _, _, _, _, _, _, constants = parse_gir_string gir_xml in
  Alcotest.(check int) "one constant" 1 (List.length constants);
  let c = List.hd constants in
  Alcotest.(check (option string)) "no doc" None c.constant_doc;
  Alcotest.(check (option string)) "no version" None c.version;
  Alcotest.(check bool) "introspectable default" true c.introspectable

(* A <constant> missing the required c:type is skipped (parser returns None). *)
let test_parse_constant_missing_ctype () =
  let gir_xml =
    wrap_namespace
      {|
    <constant name="NO_CTYPE" value="1">
      <type name="gint" c:type="gint"/>
    </constant>
  |}
  in

  let _, _, _, _, _, _, _, constants = parse_gir_string gir_xml in
  Alcotest.(check int)
    "constant without c:type skipped" 0 (List.length constants)

(* A <constant> whose <type> has no name falls back to "void" for value_type. *)
let test_parse_constant_type_without_name () =
  let gir_xml =
    wrap_namespace
      {|
    <constant name="C" value="1" c:type="C">
      <type c:type="gchar*"/>
    </constant>
  |}
  in

  let _, _, _, _, _, _, _, constants = parse_gir_string gir_xml in
  let c = List.hd constants in
  Alcotest.(check string) "type name defaults to void" "void" c.value_type.name

(* Regression: an unknown child element before <type> must not cause the
   parser to drop <type> (or any later sibling). This is the bug class the
   fold-based parser eliminates: the sibling-advance loop is owned by
   [fold_element], not by each branch, so a branch cannot forget to advance. *)
let test_parse_constant_with_unknown_child () =
  let gir_xml =
    wrap_namespace
      {|
    <constant name="C" value="x" c:type="C">
      <annotation source="future"/>
      <type name="utf8" c:type="gchar*"/>
    </constant>
  |}
  in
  let _, _, _, _, _, _, _, constants = parse_gir_string gir_xml in
  Alcotest.(check int) "one constant" 1 (List.length constants);
  let c = List.hd constants in
  Alcotest.(check string)
    "value_type.name survives unknown sibling" "utf8" c.value_type.name;
  Alcotest.(check (option string))
    "value c_type survives" (Some "gchar*") c.value_type.c_type

(* ========================================================================= *)
(* Bitfield Parsing Tests *)
(* ========================================================================= *)

let test_parse_bitfield () =
  let gir_xml =
    wrap_namespace
      {|
    <bitfield name="StateFlags" c:type="GtkStateFlags">
      <member name="normal" value="0" c:identifier="GTK_STATE_FLAG_NORMAL"/>
      <member name="active" value="1" c:identifier="GTK_STATE_FLAG_ACTIVE"/>
      <member name="prelight" value="2" c:identifier="GTK_STATE_FLAG_PRELIGHT"/>
      <member name="selected" value="4" c:identifier="GTK_STATE_FLAG_SELECTED"/>
    </bitfield>
  |}
  in

  let _, _, _, _, _, bitfields, _, _ = parse_gir_string gir_xml in

  Alcotest.(check int) "Should parse one bitfield" 1 (List.length bitfields);

  let state_flags = List.hd bitfields in
  Alcotest.(check string) "Bitfield name" "StateFlags" state_flags.bitfield_name;
  Alcotest.(check string)
    "Bitfield c_type" "GtkStateFlags" state_flags.bitfield_c_type;
  Alcotest.(check int) "Bitfield has 4 flags" 4 (List.length state_flags.flags);

  let selected =
    List.find (fun f -> f.flag_name = "selected") state_flags.flags
  in
  Alcotest.(check int) "Flag value" 4 selected.flag_value;
  Alcotest.(check string)
    "Flag c_identifier" "GTK_STATE_FLAG_SELECTED" selected.flag_c_identifier

(* Regression: an unknown child element between <member>s must not cause the
   parser to drop the following members. *)
let test_parse_bitfield_with_unknown_child () =
  let gir_xml =
    wrap_namespace
      {|
    <bitfield name="StateFlags" c:type="GtkStateFlags">
      <member name="normal" value="0" c:identifier="GTK_STATE_FLAG_NORMAL"/>
      <annotation source="future"/>
      <member name="active" value="1" c:identifier="GTK_STATE_FLAG_ACTIVE"/>
    </bitfield>
  |}
  in
  let _, _, _, _, _, bitfields, _, _ = parse_gir_string gir_xml in
  let state_flags = List.hd bitfields in
  Alcotest.(check int)
    "both members survive unknown sibling" 2
    (List.length state_flags.flags);
  let names = List.map (fun f -> f.flag_name) state_flags.flags in
  Alcotest.(check (list string))
    "member order preserved" [ "normal"; "active" ] names

(* Regression: an unknown child inside a <member> before <doc> must not cause
   the <doc> to be dropped. *)
let test_parse_bitfield_member_with_unknown_child () =
  let gir_xml =
    wrap_namespace
      {|
    <bitfield name="StateFlags" c:type="GtkStateFlags">
      <member name="normal" value="0" c:identifier="GTK_STATE_FLAG_NORMAL">
        <annotation source="future"/>
        <doc>Normal state</doc>
      </member>
    </bitfield>
  |}
  in
  let _, _, _, _, _, bitfields, _, _ = parse_gir_string gir_xml in
  let state_flags = List.hd bitfields in
  let normal = List.hd state_flags.flags in
  Alcotest.(check (option string))
    "member doc survives unknown sibling" (Some "Normal state") normal.flag_doc

(* ========================================================================= *)
(* Record Parsing Tests *)
(* ========================================================================= *)

let test_parse_record () =
  let gir_xml =
    wrap_namespace
      {|
    <record name="Rectangle" c:type="GtkRectangle" glib:type-name="GtkRectangle" glib:get-type="gtk_rectangle_get_type">
      <doc>A rectangle structure</doc>
      <field name="x" readable="1" writable="1">
        <type name="gint" c:type="gint"/>
      </field>
      <field name="y" readable="1" writable="1">
        <type name="gint" c:type="gint"/>
      </field>
      <method name="contains_point" c:identifier="gtk_rectangle_contains_point">
        <return-value>
          <type name="gboolean" c:type="gboolean"/>
        </return-value>
        <parameters>
          <parameter name="x">
            <type name="gint" c:type="gint"/>
          </parameter>
          <parameter name="y">
            <type name="gint" c:type="gint"/>
          </parameter>
        </parameters>
      </method>
    </record>
  |}
  in

  let _, _, _, _, _, _, records, _ = parse_gir_string gir_xml in

  Alcotest.(check int) "Should parse one record" 1 (List.length records);

  let rectangle = List.hd records in
  Alcotest.(check string) "Record name" "Rectangle" rectangle.record_name;
  Alcotest.(check string) "Record c_type" "GtkRectangle" rectangle.c_type;
  Alcotest.(check (option string))
    "Record glib_type_name" (Some "GtkRectangle") rectangle.glib_type_name;
  Alcotest.(check (option string))
    "Record glib_get_type" (Some "gtk_rectangle_get_type")
    rectangle.glib_get_type;
  Alcotest.(check int) "Record has 2 fields" 2 (List.length rectangle.fields);
  Alcotest.(check int) "Record has 1 method" 1 (List.length rectangle.methods);

  let x_field = List.find (fun f -> f.field_name = "x") rectangle.fields in
  Alcotest.(check bool) "Field is readable" true x_field.readable;
  Alcotest.(check bool) "Field is writable" true x_field.writable

let test_parse_opaque_record () =
  let gir_xml =
    wrap_namespace
      {|
    <record name="OpaqueData" c:type="GtkOpaqueData" opaque="1">
    </record>
  |}
  in

  let _, _, _, _, _, _, records, _ = parse_gir_string gir_xml in
  let opaque = List.hd records in

  Alcotest.(check bool) "Record should be opaque" true opaque.opaque

(* Regression: a <function> inside a <record> must not cause the parser to
   drop the siblings that follow it. The hand-written [parse_record_contents]
   loop historically forgot to recurse after the <function> branch, so every
   child after a <function> was silently dropped (or worse, reinterpreted as
   top-level by [parse_document]). The fold-based parser advances
   automatically, so this cannot happen. *)
let test_parse_record_function_then_method () =
  let gir_xml =
    wrap_namespace
      {|
    <record name="R" c:type="R">
      <method name="before" c:identifier="r_before">
        <return-value><type name="none" c:type="void"/></return-value>
      </method>
      <function name="f" c:identifier="r_f">
        <return-value><type name="none" c:type="void"/></return-value>
      </function>
      <method name="after" c:identifier="r_after">
        <return-value><type name="none" c:type="void"/></return-value>
      </method>
    </record>
  |}
  in
  let _, _, _, _, _, _, records, _ = parse_gir_string gir_xml in
  Alcotest.(check int) "one record" 1 (List.length records);
  let r = List.hd records in
  Alcotest.(check int)
    "both methods survive the <function>" 2 (List.length r.methods);
  Alcotest.(check int) "function parsed" 1 (List.length r.functions);
  let method_names =
    List.map (fun (m : gir_method) -> m.method_name) r.methods
  in
  Alcotest.(check (list string))
    "method order preserved" [ "before"; "after" ] method_names

(* ========================================================================= *)
(* Parameter Parsing Tests *)
(* ========================================================================= *)

let test_parse_nullable_parameters () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Widget" c:type="GtkWidget">
      <method name="set_parent" c:identifier="gtk_widget_set_parent">
        <return-value>
          <type name="none" c:type="void"/>
        </return-value>
        <parameters>
          <parameter name="parent" nullable="1">
            <type name="Widget" c:type="GtkWidget*"/>
          </parameter>
        </parameters>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let widget = List.hd classes in
  let method_ = List.hd widget.methods in
  let param = List.hd method_.parameters in

  Alcotest.(check bool) "Parameter should be nullable" true param.nullable

let test_parse_parameter_directions () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Widget" c:type="GtkWidget">
      <method name="get_size" c:identifier="gtk_widget_get_size">
        <return-value>
          <type name="none" c:type="void"/>
        </return-value>
        <parameters>
          <parameter name="width" direction="out">
            <type name="gint" c:type="gint*"/>
          </parameter>
          <parameter name="height" direction="out">
            <type name="gint" c:type="gint*"/>
          </parameter>
        </parameters>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let widget = List.hd classes in
  let method_ = List.hd widget.methods in

  Alcotest.(check int)
    "Should have 2 out parameters" 2
    (List.length method_.parameters);

  let width = List.find (fun p -> p.param_name = "width") method_.parameters in
  Alcotest.(check bool)
    "Width is out parameter"
    (width.direction = Gir_gen_lib.Types.Out)
    true

let test_parse_throws_attribute () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="File" c:type="GtkFile">
      <constructor name="new_for_path" c:identifier="gtk_file_new_for_path" throws="1">
        <return-value>
          <type name="File" c:type="GtkFile*"/>
        </return-value>
        <parameters>
          <parameter name="path">
            <type name="utf8" c:type="const gchar*"/>
          </parameter>
        </parameters>
      </constructor>
      <method name="read" c:identifier="gtk_file_read" throws="1">
        <return-value>
          <type name="utf8" c:type="gchar*"/>
        </return-value>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let file = List.hd classes in

  let ctor = List.hd file.constructors in
  Alcotest.(check bool) "Constructor throws" true ctor.throws;

  let method_ = List.hd file.methods in
  Alcotest.(check bool) "Method throws" true method_.throws

(* ========================================================================= *)
(* Type Parsing Tests *)
(* ========================================================================= *)

let test_parse_type_with_ctype () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Label" c:type="GtkLabel">
      <method name="set_text" c:identifier="gtk_label_set_text">
        <return-value>
          <type name="none" c:type="void"/>
        </return-value>
        <parameters>
          <parameter name="text">
            <type name="utf8" c:type="const gchar*"/>
          </parameter>
        </parameters>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let label = List.hd classes in
  let method_ = List.hd label.methods in
  let param = List.hd method_.parameters in

  Alcotest.(check string) "Type name" "utf8" param.param_type.name;
  Alcotest.(check (option string))
    "Type c:type" (Some "const gchar*") param.param_type.c_type

let test_parse_type_without_ctype () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="CustomWidget" c:type="GtkCustomWidget">
      <method name="do_something" c:identifier="gtk_custom_widget_do_something">
        <return-value>
          <type name="none"/>
        </return-value>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let widget = List.hd classes in
  let method_ = List.hd widget.methods in

  Alcotest.(check string) "Return type name" "none" method_.return_type.name;
  Alcotest.(check (option string))
    "Return type c:type should be None" None method_.return_type.c_type

(* ========================================================================= *)
(* Namespace Parsing Tests *)
(* ========================================================================= *)

let test_parse_namespace () =
  let gir_xml =
    wrap_namespace ~namespace_name:"CustomLib" ~version:"2.0"
      ~shared_library:"libcustom-2.0.so" ~c_prefix:"Custom"
      ~symbol_prefix:"custom"
      {|
    <class name="Widget" c:type="CustomWidget">
    </class>
  |}
  in

  let _, namespace, _, _, _, _, _, _ = parse_gir_string gir_xml in

  Alcotest.(check string) "Namespace name" "CustomLib" namespace.namespace_name;
  Alcotest.(check string) "Namespace version" "2.0" namespace.namespace_version;
  Alcotest.(check string)
    "Shared library" "libcustom-2.0.so" namespace.namespace_shared_library;
  Alcotest.(check string)
    "C identifier prefixes" "Custom" namespace.namespace_c_identifier_prefixes;
  Alcotest.(check string)
    "C symbol prefixes" "custom" namespace.namespace_c_symbol_prefixes

(* ========================================================================= *)
(* Edge Cases and Missing Values *)
(* ========================================================================= *)

let test_parse_empty_class () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="EmptyWidget" c:type="GtkEmptyWidget">
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let empty = List.hd classes in

  Alcotest.(check int) "No constructors" 0 (List.length empty.constructors);
  Alcotest.(check int) "No methods" 0 (List.length empty.methods);
  Alcotest.(check int) "No properties" 0 (List.length empty.properties);
  Alcotest.(check int) "No signals" 0 (List.length empty.signals)

let test_parse_multiple_classes () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Button" c:type="GtkButton">
    </class>
    <class name="Label" c:type="GtkLabel">
    </class>
    <class name="Entry" c:type="GtkEntry">
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in

  Alcotest.(check int) "Should parse 3 classes" 3 (List.length classes);

  assert_true "Should contain Button"
    (list_contains ~pred:(fun c -> c.class_name = "Button") classes);
  assert_true "Should contain Label"
    (list_contains ~pred:(fun c -> c.class_name = "Label") classes);
  assert_true "Should contain Entry"
    (list_contains ~pred:(fun c -> c.class_name = "Entry") classes)

let test_parse_mixed_types () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Button" c:type="GtkButton">
    </class>
    <interface name="Editable" c:type="GtkEditable" c:symbol-prefix="editable">
    </interface>
    <enumeration name="Orientation" c:type="GtkOrientation">
      <member name="horizontal" value="0" c:identifier="GTK_ORIENTATION_HORIZONTAL"/>
    </enumeration>
    <bitfield name="StateFlags" c:type="GtkStateFlags">
      <member name="normal" value="0" c:identifier="GTK_STATE_FLAG_NORMAL"/>
    </bitfield>
    <record name="Rectangle" c:type="GtkRectangle">
    </record>
  |}
  in

  let _, _, classes, interfaces, enums, bitfields, records, _ =
    parse_gir_string gir_xml
  in

  Alcotest.(check int) "Should have 1 class" 1 (List.length classes);
  Alcotest.(check int) "Should have 1 interface" 1 (List.length interfaces);
  Alcotest.(check int) "Should have 1 enum" 1 (List.length enums);
  Alcotest.(check int) "Should have 1 bitfield" 1 (List.length bitfields);
  Alcotest.(check int) "Should have 1 record" 1 (List.length records)

let test_parse_method_with_many_parameters () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="TestClass" c:type="GtkTestClass">
      <method name="complex_method" c:identifier="gtk_test_class_complex_method">
        <return-value>
          <type name="gboolean" c:type="gboolean"/>
        </return-value>
        <parameters>
          <parameter name="p1"><type name="gint" c:type="gint"/></parameter>
          <parameter name="p2"><type name="gint" c:type="gint"/></parameter>
          <parameter name="p3"><type name="gint" c:type="gint"/></parameter>
          <parameter name="p4"><type name="gint" c:type="gint"/></parameter>
          <parameter name="p5"><type name="gint" c:type="gint"/></parameter>
          <parameter name="p6"><type name="gint" c:type="gint"/></parameter>
          <parameter name="p7"><type name="gint" c:type="gint"/></parameter>
          <parameter name="p8"><type name="gint" c:type="gint"/></parameter>
        </parameters>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let test_class = List.hd classes in
  let method_ = List.hd test_class.methods in

  Alcotest.(check int)
    "Should parse all 8 parameters" 8
    (List.length method_.parameters);

  (* Verify all parameters are correctly parsed *)
  for i = 1 to 8 do
    let param_name = Fmt.str "p%d" i in
    assert_true
      (Fmt.str "Should have parameter %s" param_name)
      (list_contains
         ~pred:(fun p -> p.param_name = param_name)
         method_.parameters)
  done

(* ========================================================================= *)
(* Array Parsing Tests *)
(* ========================================================================= *)

let test_parse_array_return_type () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Container" c:type="GtkContainer">
      <method name="get_children" c:identifier="gtk_container_get_children">
        <return-value transfer-ownership="container">
          <array c:type="GList*" zero-terminated="0">
            <type name="Widget" c:type="GtkWidget*"/>
          </array>
        </return-value>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let container = List.hd classes in
  let method_ = List.hd container.methods in

  Alcotest.(check string)
    "Return type name is array" "array" method_.return_type.name;
  Alcotest.(check bool)
    "Return type has array info"
    (Option.is_some method_.return_type.array)
    true;

  expect_some "Array info should be present" method_.return_type.array
  @@ fun array_info ->
  Alcotest.(check bool)
    "Array is not zero-terminated" false array_info.zero_terminated;
  Alcotest.(check string)
    "Array element type" "Widget" array_info.element_type.name;
  Alcotest.(check (option string))
    "Array element c:type" (Some "GtkWidget*") array_info.element_type.c_type;
  Alcotest.(check (option int))
    "Array has no length parameter" None array_info.length;
  Alcotest.(check (option int))
    "Array has no fixed size" None array_info.fixed_size

let test_parse_array_with_length () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="List" c:type="GtkList">
      <method name="get_items" c:identifier="gtk_list_get_items">
        <return-value transfer-ownership="full">
          <array length="0" c:type="gchar**">
            <type name="utf8" c:type="gchar*"/>
          </array>
        </return-value>
        <parameters>
          <parameter name="n_items" direction="out">
            <type name="gint" c:type="gint*"/>
          </parameter>
        </parameters>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let list_class = List.hd classes in
  let method_ = List.hd list_class.methods in

  expect_some "Array info should be present" method_.return_type.array
  @@ fun array_info ->
  Alcotest.(check (option int))
    "Array length points to parameter 0" (Some 0) array_info.length;
  Alcotest.(check string)
    "Element type is utf8" "utf8" array_info.element_type.name

let test_parse_array_zero_terminated () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="StringArray" c:type="GtkStringArray">
      <method name="get_strings" c:identifier="gtk_string_array_get_strings">
        <return-value transfer-ownership="none">
          <array zero-terminated="1" c:type="gchar**">
            <type name="utf8" c:type="gchar*"/>
          </array>
        </return-value>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let string_array = List.hd classes in
  let method_ = List.hd string_array.methods in

  expect_some "Array info should be present" method_.return_type.array
  @@ fun array_info ->
  Alcotest.(check bool)
    "Array is zero-terminated" true array_info.zero_terminated;
  Alcotest.(check (option int))
    "No explicit length parameter" None array_info.length

let test_parse_array_fixed_size () =
  let gir_xml =
    wrap_namespace
      {|
    <record name="Point3D" c:type="GtkPoint3D">
      <field name="coordinates" readable="1" writable="1">
        <array fixed-size="3" c:type="gdouble[3]">
          <type name="gdouble" c:type="gdouble"/>
        </array>
      </field>
    </record>
  |}
  in

  let _, _, _, _, _, _, records, _ = parse_gir_string gir_xml in
  let point = List.hd records in
  let field = List.hd point.fields in

  expect_some "Field type should be present" field.field_type
  @@ fun field_type ->
  expect_some "Array info should be present" field_type.array
  @@ fun array_info ->
  Alcotest.(check (option int))
    "Array has fixed size 3" (Some 3) array_info.fixed_size;
  Alcotest.(check string)
    "Element type is gdouble" "gdouble" array_info.element_type.name;
  Alcotest.(check (option string))
    "Element c:type is gdouble" (Some "gdouble") array_info.element_type.c_type

let test_parse_array_parameter () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="List" c:type="GtkList">
      <method name="set_items" c:identifier="gtk_list_set_items">
        <return-value>
          <type name="none" c:type="void"/>
        </return-value>
        <parameters>
          <parameter name="items">
            <array length="1" zero-terminated="0" c:type="gchar**">
              <type name="utf8" c:type="gchar*"/>
            </array>
          </parameter>
          <parameter name="n_items">
            <type name="gint" c:type="gint"/>
          </parameter>
        </parameters>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let list_class = List.hd classes in
  let method_ = List.hd list_class.methods in
  let items_param =
    List.find (fun p -> p.param_name = "items") method_.parameters
  in

  Alcotest.(check string)
    "Parameter type name is array" "array" items_param.param_type.name;

  expect_some "Array info should be present in parameter"
    items_param.param_type.array
  @@ fun array_info ->
  Alcotest.(check (option int))
    "Array length is parameter 1" (Some 1) array_info.length;
  Alcotest.(check bool)
    "Array is not zero-terminated" false array_info.zero_terminated;
  Alcotest.(check string)
    "Element type is utf8" "utf8" array_info.element_type.name

let test_parse_array_property () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Model" c:type="GtkModel">
      <property name="items" readable="1" writable="1">
        <array zero-terminated="1">
          <type name="utf8" c:type="gchar*"/>
        </array>
      </property>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let model = List.hd classes in
  let prop = List.hd model.properties in

  Alcotest.(check string)
    "Property type name is array" "array" prop.prop_type.name;

  expect_some "Array info should be present in property" prop.prop_type.array
  @@ fun array_info ->
  Alcotest.(check bool)
    "Array is zero-terminated" true array_info.zero_terminated;
  Alcotest.(check string)
    "Element type is utf8" "utf8" array_info.element_type.name

let test_parse_array_without_attributes () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="SimpleArray" c:type="GtkSimpleArray">
      <method name="get_values" c:identifier="gtk_simple_array_get_values">
        <return-value>
          <array>
            <type name="gint" c:type="gint"/>
          </array>
        </return-value>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let simple_array = List.hd classes in
  let method_ = List.hd simple_array.methods in

  expect_some "Array info should be present" method_.return_type.array
  @@ fun array_info ->
  Alcotest.(check bool)
    "Array is not zero-terminated by default" false array_info.zero_terminated;
  Alcotest.(check (option int)) "No length parameter" None array_info.length;
  Alcotest.(check (option int)) "No fixed size" None array_info.fixed_size;
  Alcotest.(check string)
    "Element type is gint" "gint" array_info.element_type.name

let test_parse_nested_array_type () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Matrix" c:type="GtkMatrix">
      <method name="get_data" c:identifier="gtk_matrix_get_data">
        <return-value transfer-ownership="none">
          <array length="0" c:type="gint*">
            <type name="gint" c:type="gint"/>
          </array>
        </return-value>
        <parameters>
          <parameter name="length" direction="out">
            <type name="gint" c:type="gint*"/>
          </parameter>
        </parameters>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let matrix = List.hd classes in
  let method_ = List.hd matrix.methods in

  Alcotest.(check string)
    "Return type is array" "array" method_.return_type.name;
  Alcotest.(check (option string))
    "Array c:type" (Some "gint*") method_.return_type.c_type;

  expect_some "Array info should be present" method_.return_type.array
  @@ fun array_info ->
  Alcotest.(check (option int))
    "Length parameter is 0" (Some 0) array_info.length;
  Alcotest.(check string)
    "Element type name" "gint" array_info.element_type.name;
  Alcotest.(check (option string))
    "Element c:type" (Some "gint") array_info.element_type.c_type

(* ========================================================================= *)
(* Nested Type Element Parsing Tests - for GList/GSList support *)
(* ========================================================================= *)

let test_parse_glist_return_type () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Application" c:type="GtkApplication">
      <method name="get_windows" c:identifier="gtk_application_get_windows">
        <return-value transfer-ownership="none">
          <type name="GLib.List" c:type="GList*">
            <type name="Window" c:type="GtkWindow*"/>
          </type>
        </return-value>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let app = List.hd classes in
  let method_ = List.hd app.methods in

  Alcotest.(check string)
    "Return type is GLib.List" "GLib.List" method_.return_type.name;
  Alcotest.(check (option string))
    "C type is GList*" (Some "GList*") method_.return_type.c_type;
  Alcotest.(check bool)
    "Return type has array info for element"
    (Option.is_some method_.return_type.array)
    true;

  expect_some "Array info should be present for GList element"
    method_.return_type.array
  @@ fun array_info ->
  Alcotest.(check string)
    "Element type name is Window" "Window" array_info.element_type.name;
  Alcotest.(check (option string))
    "Element c:type is GtkWindow*" (Some "GtkWindow*")
    array_info.element_type.c_type;
  Alcotest.(check (option string))
    "Array name is GLib.List" (Some "GLib.List") array_info.array_name

let test_parse_gslist_parameter () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="SizeGroup" c:type="GtkSizeGroup">
      <method name="get_widgets" c:identifier="gtk_size_group_get_widgets">
        <return-value transfer-ownership="none">
          <type name="GLib.SList" c:type="GSList*">
            <type name="Widget" c:type="GtkWidget*"/>
          </type>
        </return-value>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let size_group = List.hd classes in
  let method_ = List.hd size_group.methods in

  Alcotest.(check string)
    "Return type is GLib.SList" "GLib.SList" method_.return_type.name;
  Alcotest.(check (option string))
    "C type is GSList*" (Some "GSList*") method_.return_type.c_type;

  expect_some "Array info should be present for GSList element"
    method_.return_type.array
  @@ fun array_info ->
  Alcotest.(check string)
    "Element type name is Widget" "Widget" array_info.element_type.name;
  Alcotest.(check (option string))
    "Element c:type is GtkWidget*" (Some "GtkWidget*")
    array_info.element_type.c_type

let test_parse_generic_type_without_nested () =
  let gir_xml =
    wrap_namespace
      {|
    <class name="Widget" c:type="GtkWidget">
      <method name="get_parent" c:identifier="gtk_widget_get_parent">
        <return-value transfer-ownership="none">
          <type name="Widget" c:type="GtkWidget*"/>
        </return-value>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let widget = List.hd classes in
  let method_ = List.hd widget.methods in

  Alcotest.(check string)
    "Return type is Widget" "Widget" method_.return_type.name;
  Alcotest.(check (option string))
    "C type is GtkWidget*" (Some "GtkWidget*") method_.return_type.c_type;
  Alcotest.(check bool)
    "Return type has no array info for simple type"
    (Option.is_none method_.return_type.array)
    true

(* Test cross-namespace element type parsing *)
let test_parse_glist_with_cross_namespace_element () =
  let gir_xml =
    wrap_namespace ~namespace_name:"Gdk"
      {|
    <class name="FileList" c:type="GdkFileList">
      <constructor name="new_from_list" c:identifier="gdk_file_list_new_from_list">
        <return-value transfer-ownership="full">
          <type name="FileList" c:type="GdkFileList*"/>
        </return-value>
        <parameters>
          <parameter name="files" transfer-ownership="none">
            <type name="GLib.SList" c:type="GSList*">
              <type name="Gio.File"/>
            </type>
          </parameter>
        </parameters>
      </constructor>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let file_list = List.hd classes in
  let ctor = List.hd file_list.constructors in
  let files_param = List.hd ctor.ctor_parameters in

  Alcotest.(check string)
    "Parameter type is GLib.SList" "GLib.SList" files_param.param_type.name;
  Alcotest.(check bool)
    "Parameter has array info"
    (Option.is_some files_param.param_type.array)
    true;

  expect_some "Array info should be present for cross-namespace element"
    files_param.param_type.array
  @@ fun array_info ->
  Alcotest.(check string)
    "Element type name is Gio.File" "Gio.File" array_info.element_type.name;
  Alcotest.(check (option string))
    "Element c:type is None (not provided)" None array_info.element_type.c_type

(* Test same-namespace element type parsing *)
let test_parse_glist_with_same_namespace_element () =
  let gir_xml =
    wrap_namespace ~namespace_name:"Gdk"
      {|
    <class name="Texture" c:type="GdkTexture">
    </class>
    <class name="Toplevel" c:type="GdkToplevel">
      <method name="set_icon_list" c:identifier="gdk_toplevel_set_icon_list">
        <return-value transfer-ownership="none">
          <type name="none" c:type="void"/>
        </return-value>
        <parameters>
          <parameter name="surfaces" transfer-ownership="none">
            <type name="GLib.List" c:type="GList*">
              <type name="Texture"/>
            </type>
          </parameter>
        </parameters>
      </method>
    </class>
  |}
  in

  let _, _, classes, _, _, _, _, _ = parse_gir_string gir_xml in
  let toplevel = List.find (fun c -> c.class_name = "Toplevel") classes in
  let method_ = List.hd toplevel.methods in
  let surfaces_param = List.hd method_.parameters in

  Alcotest.(check string)
    "Parameter name is surfaces" "surfaces" surfaces_param.param_name;
  Alcotest.(check string)
    "Parameter type is GLib.List" "GLib.List" surfaces_param.param_type.name;

  expect_some "Array info should be present for same-namespace element"
    surfaces_param.param_type.array
  @@ fun array_info ->
  Alcotest.(check string)
    "Element type name is Texture" "Texture" array_info.element_type.name

(* ========================================================================= *)
(* Test Suite *)
(* ========================================================================= *)

let tests =
  [
    (* Class tests *)
    Alcotest.test_case "Parse simple class" `Quick test_parse_simple_class;
    Alcotest.test_case "Parse class without c:type" `Quick
      test_parse_class_without_ctype;
    Alcotest.test_case "Parse class with constructors" `Quick
      test_parse_class_with_constructors;
    Alcotest.test_case "Parse class with methods" `Quick
      test_parse_class_with_methods;
    Alcotest.test_case "Parse class with properties" `Quick
      test_parse_class_with_properties;
    Alcotest.test_case "Parse class with signals" `Quick
      test_parse_class_with_signals;
    Alcotest.test_case "Parse signal flag attributes" `Quick
      test_parse_signal_flags;
    (* Interface tests *)
    Alcotest.test_case "Parse interface" `Quick test_parse_interface;
    Alcotest.test_case "Parse interface without c:type" `Quick
      test_parse_interface_without_ctype;
    (* Enum tests *)
    Alcotest.test_case "Parse enum" `Quick test_parse_enum;
    Alcotest.test_case "Parse enum missing c:type" `Quick
      test_parse_enum_missing_ctype;
    Alcotest.test_case "Parse enum with function and members" `Quick
      test_parse_enum_with_function_and_members;
    (* Bitfield tests *)
    Alcotest.test_case "Parse bitfield" `Quick test_parse_bitfield;
    Alcotest.test_case "Parse bitfield with unknown child" `Quick
      test_parse_bitfield_with_unknown_child;
    Alcotest.test_case "Parse bitfield member with unknown child" `Quick
      test_parse_bitfield_member_with_unknown_child;
    (* Constant tests *)
    Alcotest.test_case "Parse constant (utf8)" `Quick test_parse_constant_utf8;
    Alcotest.test_case "Parse constant value types" `Quick
      test_parse_constant_value_types;
    Alcotest.test_case "Parse constant minimal" `Quick
      test_parse_constant_minimal;
    Alcotest.test_case "Parse constant missing c:type" `Quick
      test_parse_constant_missing_ctype;
    Alcotest.test_case "Parse constant type without name" `Quick
      test_parse_constant_type_without_name;
    Alcotest.test_case "Parse constant with unknown child" `Quick
      test_parse_constant_with_unknown_child;
    (* Record tests *)
    Alcotest.test_case "Parse record" `Quick test_parse_record;
    Alcotest.test_case "Parse opaque record" `Quick test_parse_opaque_record;
    Alcotest.test_case "Parse record function-then-method" `Quick
      test_parse_record_function_then_method;
    (* Parameter tests *)
    Alcotest.test_case "Parse nullable parameters" `Quick
      test_parse_nullable_parameters;
    Alcotest.test_case "Parse parameter directions" `Quick
      test_parse_parameter_directions;
    Alcotest.test_case "Parse throws attribute" `Quick
      test_parse_throws_attribute;
    (* Type tests *)
    Alcotest.test_case "Parse type with c:type" `Quick
      test_parse_type_with_ctype;
    Alcotest.test_case "Parse type without c:type" `Quick
      test_parse_type_without_ctype;
    (* Namespace tests *)
    Alcotest.test_case "Parse namespace" `Quick test_parse_namespace;
    (* Edge cases *)
    Alcotest.test_case "Parse empty class" `Quick test_parse_empty_class;
    Alcotest.test_case "Parse multiple classes" `Quick
      test_parse_multiple_classes;
    Alcotest.test_case "Parse mixed types" `Quick test_parse_mixed_types;
    Alcotest.test_case "Parse method with many parameters" `Quick
      test_parse_method_with_many_parameters;
    (* Array parsing tests *)
    Alcotest.test_case "Parse array return type" `Quick
      test_parse_array_return_type;
    Alcotest.test_case "Parse array with length parameter" `Quick
      test_parse_array_with_length;
    Alcotest.test_case "Parse zero-terminated array" `Quick
      test_parse_array_zero_terminated;
    Alcotest.test_case "Parse fixed-size array" `Quick
      test_parse_array_fixed_size;
    Alcotest.test_case "Parse array parameter" `Quick test_parse_array_parameter;
    Alcotest.test_case "Parse array property" `Quick test_parse_array_property;
    Alcotest.test_case "Parse array without attributes" `Quick
      test_parse_array_without_attributes;
    Alcotest.test_case "Parse nested array type" `Quick
      test_parse_nested_array_type;
    (* Nested type element tests for GList/GSList *)
    Alcotest.test_case "Parse GList return type with element" `Quick
      test_parse_glist_return_type;
    Alcotest.test_case "Parse GSList return type with element" `Quick
      test_parse_gslist_parameter;
    Alcotest.test_case "Parse simple type without nested element" `Quick
      test_parse_generic_type_without_nested;
    (* Cross-namespace and same-namespace element type tests *)
    Alcotest.test_case "Parse GList with cross-namespace element (Gio.File)"
      `Quick test_parse_glist_with_cross_namespace_element;
    Alcotest.test_case "Parse GList with same-namespace element (Texture)"
      `Quick test_parse_glist_with_same_namespace_element;
  ]
