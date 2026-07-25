(* Tests for Gir_gen_lib.Override_apply. *)

open Gir_gen_lib.Override_types
open Override_factory

(* Helpers *)

let hd_exn msg = function [] -> Alcotest.fail msg | x :: _ -> x

let find_exn msg pred list =
  match List.find_opt pred list with None -> Alcotest.fail msg | Some x -> x

(* Minimal GIR data constructors for testing — thin wrappers around Type_factory *)

let make_method ~name ~version =
  Type_factory.make_gir_method ~method_name:name
    ~c_identifier:("gtk_test_" ^ name) ~return_type:Type_factory.void_type
    ?version ()

let make_constructor ~name ~version =
  Type_factory.make_gir_constructor ~ctor_name:name
    ~c_identifier:("gtk_test_" ^ name) ?version ()

let make_property ~name ~version =
  Type_factory.make_gir_property ~prop_name:name
    ~prop_type:Type_factory.gboolean_type ?version ()

let make_signal ~name ~version =
  Type_factory.make_void_signal ~signal_name:name ?version ()

let make_class ~name ~version ~methods ~constructors ~properties ~signals =
  Type_factory.make_gir_class ~class_name:name ~c_type:("Gtk" ^ name) ~methods
    ~constructors ~properties ~signals ?version ()

let make_interface ~name ~version ~methods ~properties ~signals =
  Type_factory.make_gir_interface ~interface_name:name ~c_type:("Gtk" ^ name)
    ~c_symbol_prefix:(String.lowercase_ascii name)
    ~methods ~properties ~signals ?version ()

let make_record_field ~name ~version =
  {
    (Type_factory.make_gir_record_field ~field_name:name ~writable:true ()) with
    field_version = version;
  }

let make_record ~name ~version ~fields ~constructors ~methods ~functions =
  Type_factory.make_gir_record ~record_name:name ~c_type:("Gtk" ^ name) ~fields
    ~constructors ~methods ~functions ?version ()

let make_enum_member ~name ~version =
  {
    (Type_factory.make_gir_enum_member ~member_name:name
       ~c_identifier:("GTK_TEST_" ^ name) ())
    with
    member_version = version;
  }

let make_enum ~name ~version ~members ~functions =
  Type_factory.make_gir_enum ~enum_name:name ~enum_c_type:("Gtk" ^ name)
    ~members ~functions ?enum_version:version ()

let make_bitfield_member ~name ~version =
  {
    (Type_factory.make_gir_bitfield_member ~flag_name:name
       ~flag_c_identifier:("GTK_TEST_" ^ name) ~flag_value:1 ())
    with
    flag_version = version;
  }

let make_bitfield ~name ~version ~flags =
  Type_factory.make_gir_bitfield ~bitfield_name:name
    ~bitfield_c_type:("Gtk" ^ name) ~flags ?bitfield_version:version ()

let make_function ~name ~version =
  Type_factory.make_gir_function ~function_name:name
    ~c_identifier:("gtk_test_" ^ name) ~return_type:Type_factory.void_type
    ?version ()

(* Tests: Class overrides *)

let test_class_ignore () =
  let cls =
    make_class ~name:"Widget" ~version:None ~methods:[] ~constructors:[]
      ~properties:[] ~signals:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~classes:[ make_class_override ~action:(Some Ignore) ~name:"Widget" () ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[ cls ]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  Alcotest.(check int) "classes filtered" 0 (List.length result.classes);
  Alcotest.(check int) "ignored" 1 (List.length result.ignored_entities);
  let ignored = hd_exn "Expected ignored entity" result.ignored_entities in
  Alcotest.(check string) "ignored name" "Widget" ignored

let test_class_ignore_preserves_surviving () =
  let cls1 =
    make_class ~name:"Widget" ~version:None ~methods:[] ~constructors:[]
      ~properties:[] ~signals:[]
  in
  let cls2 =
    make_class ~name:"Button" ~version:None ~methods:[] ~constructors:[]
      ~properties:[] ~signals:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~classes:[ make_class_override ~action:(Some Ignore) ~name:"Widget" () ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides
      ~classes:[ cls1; cls2 ] ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[]
      ~functions:[]
  in
  Alcotest.(check int) "one surviving" 1 (List.length result.classes);
  let surviving = hd_exn "Expected surviving class" result.classes in
  Alcotest.(check string) "surviving name" "Button" surviving.class_name

let test_method_ignore () =
  let cls =
    make_class ~name:"Widget" ~version:None
      ~methods:
        [
          make_method ~name:"show" ~version:None;
          make_method ~name:"hide" ~version:None;
        ]
      ~constructors:[] ~properties:[] ~signals:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~classes:
        [
          make_class_override ~name:"Widget"
            ~methods:[ ignore_component ~name:"show" ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[ cls ]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  let surviving_cls = hd_exn "Expected one class" result.classes in
  Alcotest.(check int)
    "one method remaining" 1
    (List.length surviving_cls.methods);
  let remaining = hd_exn "Expected one method" surviving_cls.methods in
  Alcotest.(check string) "remaining method" "hide" remaining.method_name

let test_method_version_override () =
  let cls =
    make_class ~name:"Widget" ~version:None
      ~methods:[ make_method ~name:"show" ~version:None ]
      ~constructors:[] ~properties:[] ~signals:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~classes:
        [
          make_class_override ~name:"Widget"
            ~methods:[ version_component ~name:"show" ~version:"4.10" () ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[ cls ]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  let surviving_cls = hd_exn "Expected one class" result.classes in
  let m = hd_exn "Expected one method" surviving_cls.methods in
  Alcotest.(check bool) "version set" true (m.version = Some "4.10")

let test_method_version_replaces_existing () =
  let cls =
    make_class ~name:"Widget" ~version:None
      ~methods:[ make_method ~name:"show" ~version:(Some "4.8") ]
      ~constructors:[] ~properties:[] ~signals:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~classes:
        [
          make_class_override ~name:"Widget"
            ~methods:[ version_component ~name:"show" ~version:"4.12" () ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[ cls ]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  let surviving_cls = hd_exn "Expected one class" result.classes in
  let m = hd_exn "Expected one method" surviving_cls.methods in
  Alcotest.(check bool) "version replaced" true (m.version = Some "4.12")

let test_constructor_ignore () =
  let cls =
    make_class ~name:"Widget" ~version:None ~methods:[]
      ~constructors:[ make_constructor ~name:"new" ~version:None ]
      ~properties:[] ~signals:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~classes:
        [
          make_class_override ~name:"Widget"
            ~constructors:[ ignore_component ~name:"new" ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[ cls ]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  let surviving_cls = hd_exn "Expected one class" result.classes in
  Alcotest.(check int)
    "no constructors" 0
    (List.length surviving_cls.constructors)

let test_property_version_override () =
  let cls =
    make_class ~name:"Widget" ~version:None ~methods:[] ~constructors:[]
      ~properties:[ make_property ~name:"sensitive" ~version:None ]
      ~signals:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~classes:
        [
          make_class_override ~name:"Widget"
            ~properties:
              [ version_component ~name:"sensitive" ~version:"4.10" () ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[ cls ]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  let surviving_cls = hd_exn "Expected one class" result.classes in
  let p = hd_exn "Expected one property" surviving_cls.properties in
  Alcotest.(check bool) "prop version" true (p.version = Some "4.10")

let test_signal_ignore () =
  let cls =
    make_class ~name:"Widget" ~version:None ~methods:[] ~constructors:[]
      ~properties:[]
      ~signals:[ make_signal ~name:"destroy" ~version:None ]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~classes:
        [
          make_class_override ~name:"Widget"
            ~signals:[ ignore_component ~name:"destroy" ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[ cls ]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  let surviving_cls = hd_exn "Expected one class" result.classes in
  Alcotest.(check int) "no signals" 0 (List.length surviving_cls.signals)

(* Tests: Interface overrides *)

let test_interface_method_ignore () =
  let intf =
    make_interface ~name:"Actionable" ~version:None
      ~methods:
        [
          make_method ~name:"get_action_name" ~version:None;
          make_method ~name:"set_action_name" ~version:None;
        ]
      ~properties:[] ~signals:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~interfaces:
        [
          make_interface_override ~name:"Actionable"
            ~methods:[ ignore_component ~name:"get_action_name" ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[]
      ~interfaces:[ intf ] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  let surviving = hd_exn "Expected one interface" result.interfaces in
  Alcotest.(check int) "one method" 1 (List.length surviving.methods);
  let m = hd_exn "Expected one method" surviving.methods in
  Alcotest.(check string) "remaining method" "set_action_name" m.method_name

let test_interface_ignore () =
  let intf =
    make_interface ~name:"Actionable" ~version:None ~methods:[] ~properties:[]
      ~signals:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~interfaces:
        [ make_interface_override ~name:"Actionable" ~action:(Some Ignore) () ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[]
      ~interfaces:[ intf ] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  Alcotest.(check int) "no interfaces" 0 (List.length result.interfaces)

(* Tests: Record overrides *)

let test_record_field_ignore () =
  let rec_ =
    make_record ~name:"TextIter" ~version:None
      ~fields:
        [
          make_record_field ~name:"user_data" ~version:None;
          make_record_field ~name:"start" ~version:None;
        ]
      ~constructors:[] ~methods:[] ~functions:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~records:
        [
          make_record_override ~name:"TextIter"
            ~fields:[ ignore_component ~name:"user_data" ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[ rec_ ] ~functions:[]
  in
  let surviving = hd_exn "Expected one record" result.records in
  Alcotest.(check int) "one field" 1 (List.length surviving.fields);
  let f = hd_exn "Expected one field" surviving.fields in
  Alcotest.(check string) "remaining field" "start" f.field_name

let test_record_field_version_override () =
  let rec_ =
    make_record ~name:"TextIter" ~version:None
      ~fields:[ make_record_field ~name:"start" ~version:None ]
      ~constructors:[] ~methods:[] ~functions:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~records:
        [
          make_record_override ~name:"TextIter"
            ~fields:[ version_component ~name:"start" ~version:"4.14" () ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[ rec_ ] ~functions:[]
  in
  let surviving = hd_exn "Expected one record" result.records in
  let f = hd_exn "Expected one field" surviving.fields in
  Alcotest.(check bool) "field version" true (f.field_version = Some "4.14")

let test_record_ignore () =
  let rec_ =
    make_record ~name:"PrintBackend" ~version:None ~fields:[] ~constructors:[]
      ~methods:[] ~functions:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~records:
        [ make_record_override ~name:"PrintBackend" ~action:(Some Ignore) () ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[ rec_ ] ~functions:[]
  in
  Alcotest.(check int) "no records" 0 (List.length result.records)

(* Tests: Enum overrides *)

let test_enum_member_ignore () =
  let enm =
    make_enum ~name:"RGBA" ~version:None
      ~members:
        [
          make_enum_member ~name:"RED" ~version:None;
          make_enum_member ~name:"GREEN" ~version:None;
        ]
      ~functions:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~enums:
        [
          make_enum_override ~name:"RGBA"
            ~members:[ ignore_component ~name:"RED" ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[]
      ~interfaces:[] ~enums:[ enm ] ~bitfields:[] ~records:[] ~functions:[]
  in
  let surviving = hd_exn "Expected one enum" result.enums in
  Alcotest.(check int) "one member" 1 (List.length surviving.members);
  let m = hd_exn "Expected one member" surviving.members in
  Alcotest.(check string) "remaining member" "GREEN" m.member_name

let test_enum_member_version_override () =
  let enm =
    make_enum ~name:"RGBA" ~version:None
      ~members:[ make_enum_member ~name:"RED" ~version:None ]
      ~functions:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~enums:
        [
          make_enum_override ~name:"RGBA"
            ~members:[ version_component ~name:"RED" ~version:"4.14" () ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[]
      ~interfaces:[] ~enums:[ enm ] ~bitfields:[] ~records:[] ~functions:[]
  in
  let surviving = hd_exn "Expected one enum" result.enums in
  let m = hd_exn "Expected one member" surviving.members in
  Alcotest.(check bool) "member version" true (m.member_version = Some "4.14")

let test_enum_ignore () =
  let enm = make_enum ~name:"License" ~version:None ~members:[] ~functions:[] in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~enums:[ make_enum_override ~name:"License" ~action:(Some Ignore) () ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[]
      ~interfaces:[] ~enums:[ enm ] ~bitfields:[] ~records:[] ~functions:[]
  in
  Alcotest.(check int) "no enums" 0 (List.length result.enums)

(* Tests: Bitfield overrides *)

let test_bitfield_member_ignore () =
  let bf =
    make_bitfield ~name:"StateFlags" ~version:None
      ~flags:
        [
          make_bitfield_member ~name:"ACTIVE" ~version:None;
          make_bitfield_member ~name:"NORMAL" ~version:None;
        ]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~bitfields:
        [
          make_bitfield_override ~name:"StateFlags"
            ~flags:[ ignore_component ~name:"ACTIVE" ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[]
      ~interfaces:[] ~enums:[] ~bitfields:[ bf ] ~records:[] ~functions:[]
  in
  let surviving = hd_exn "Expected one bitfield" result.bitfields in
  Alcotest.(check int) "one flag" 1 (List.length surviving.flags);
  let f = hd_exn "Expected one flag" surviving.flags in
  Alcotest.(check string) "remaining flag" "NORMAL" f.flag_name

let test_bitfield_member_version_override () =
  let bf =
    make_bitfield ~name:"StateFlags" ~version:None
      ~flags:[ make_bitfield_member ~name:"ACTIVE" ~version:None ]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~bitfields:
        [
          make_bitfield_override ~name:"StateFlags"
            ~flags:[ version_component ~name:"ACTIVE" ~version:"4.14" () ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[]
      ~interfaces:[] ~enums:[] ~bitfields:[ bf ] ~records:[] ~functions:[]
  in
  let surviving = hd_exn "Expected one bitfield" result.bitfields in
  let f = hd_exn "Expected one flag" surviving.flags in
  Alcotest.(check bool) "flag version" true (f.flag_version = Some "4.14")

(* Tests: Standalone function overrides *)

let test_function_ignore () =
  let fn = make_function ~name:"gtk_show_uri" ~version:None in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~functions:[ ignore_component ~name:"gtk_show_uri" ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[] ~functions:[ fn ]
  in
  Alcotest.(check int) "no functions" 0 (List.length result.functions)

(* Tests: Empty overrides *)

let test_empty_overrides_no_changes () =
  let cls =
    make_class ~name:"Widget" ~version:None
      ~methods:[ make_method ~name:"show" ~version:None ]
      ~constructors:[] ~properties:[] ~signals:[]
  in
  let intf =
    make_interface ~name:"Actionable" ~version:None ~methods:[] ~properties:[]
      ~signals:[]
  in
  let overrides = make_empty_library_overrides ~name:"Gtk" in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[ cls ]
      ~interfaces:[ intf ] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  Alcotest.(check int) "classes unchanged" 1 (List.length result.classes);
  Alcotest.(check int) "interfaces unchanged" 1 (List.length result.interfaces);
  Alcotest.(check int) "no ignored" 0 (List.length result.ignored_entities);
  Alcotest.(check int) "no warnings" 0 (List.length result.warnings)

(* Tests: Warnings for unknown names *)

let test_unknown_class_warning () =
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~classes:
        [ make_class_override ~action:(Some Ignore) ~name:"NonExistent" () ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  Alcotest.(check int) "no classes" 0 (List.length result.classes);
  Alcotest.(check bool) "has warning" true (List.length result.warnings > 0);
  let w = hd_exn "Expected warning" result.warnings in
  Alcotest.(check bool)
    "mentions unknown class" true
    (String.length w > 0 && String.contains w 'c')

let test_unknown_component_warning () =
  let cls =
    make_class ~name:"Widget" ~version:None
      ~methods:[ make_method ~name:"show" ~version:None ]
      ~constructors:[] ~properties:[] ~signals:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~classes:
        [
          make_class_override ~name:"Widget"
            ~methods:[ ignore_component ~name:"nonexistent_method" ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[ cls ]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  Alcotest.(check int) "class kept" 1 (List.length result.classes);
  Alcotest.(check bool) "has warning" true (List.length result.warnings > 0)

let test_class_ignore_no_component_warnings () =
  (* When a class is ignored, component overrides under it should be silently
     skipped — no warnings for unknown components on an ignored class. *)
  let cls =
    make_class ~name:"Widget" ~version:None ~methods:[] ~constructors:[]
      ~properties:[] ~signals:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~classes:
        [
          make_class_override ~action:(Some Ignore) ~name:"Widget"
            ~methods:[ ignore_component ~name:"nonexistent" ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes:[ cls ]
      ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[] ~functions:[]
  in
  Alcotest.(check int) "no classes" 0 (List.length result.classes);
  Alcotest.(check int) "no warnings" 0 (List.length result.warnings)

(* Tests: Combined overrides *)

let test_combined_class_and_component () =
  let cls1 =
    make_class ~name:"Widget" ~version:None
      ~methods:[ make_method ~name:"show" ~version:None ]
      ~constructors:[] ~properties:[] ~signals:[]
  in
  let cls2 =
    make_class ~name:"Button" ~version:None
      ~methods:
        [
          make_method ~name:"clicked" ~version:None;
          make_method ~name:"activate" ~version:None;
        ]
      ~constructors:[] ~properties:[] ~signals:[]
  in
  let overrides =
    make_library_overrides ~name:"Gtk"
      ~classes:
        [
          make_class_override ~action:(Some Ignore) ~name:"Widget" ();
          make_class_override ~name:"Button"
            ~methods:[ ignore_component ~name:"activate" ]
            ();
        ]
      ()
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides
      ~classes:[ cls1; cls2 ] ~interfaces:[] ~enums:[] ~bitfields:[] ~records:[]
      ~functions:[]
  in
  Alcotest.(check int) "one class" 1 (List.length result.classes);
  let surviving = hd_exn "Expected Button" result.classes in
  Alcotest.(check string) "surviving class" "Button" surviving.class_name;
  Alcotest.(check int) "one method" 1 (List.length surviving.methods);
  let m = hd_exn "Expected one method" surviving.methods in
  Alcotest.(check string) "remaining method" "clicked" m.method_name

let test_suite =
  [
    ("class ignore", `Quick, test_class_ignore);
    ( "class ignore preserves surviving",
      `Quick,
      test_class_ignore_preserves_surviving );
    ("method ignore", `Quick, test_method_ignore);
    ("method version override", `Quick, test_method_version_override);
    ( "method version replaces existing",
      `Quick,
      test_method_version_replaces_existing );
    ("constructor ignore", `Quick, test_constructor_ignore);
    ("property version override", `Quick, test_property_version_override);
    ("signal ignore", `Quick, test_signal_ignore);
    ("interface method ignore", `Quick, test_interface_method_ignore);
    ("interface ignore", `Quick, test_interface_ignore);
    ("record field ignore", `Quick, test_record_field_ignore);
    ("record field version override", `Quick, test_record_field_version_override);
    ("record ignore", `Quick, test_record_ignore);
    ("enum member ignore", `Quick, test_enum_member_ignore);
    ("enum member version override", `Quick, test_enum_member_version_override);
    ("enum ignore", `Quick, test_enum_ignore);
    ("bitfield member ignore", `Quick, test_bitfield_member_ignore);
    ( "bitfield member version override",
      `Quick,
      test_bitfield_member_version_override );
    ("standalone function ignore", `Quick, test_function_ignore);
    ("empty overrides no changes", `Quick, test_empty_overrides_no_changes);
    ("unknown class warning", `Quick, test_unknown_class_warning);
    ("unknown component warning", `Quick, test_unknown_component_warning);
    ( "class ignore no component warnings",
      `Quick,
      test_class_ignore_no_component_warnings );
    ("combined class and component", `Quick, test_combined_class_and_component);
  ]
