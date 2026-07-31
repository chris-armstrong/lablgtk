(* Tests for Override_types construction and equality. *)

open Gir_gen_lib.Override_types
open Override_factory

let test_override_action_ignore () =
  let a = Ignore in
  match a with Ignore -> () | Set_version _ -> Alcotest.fail "Expected Ignore"

let test_override_action_version () =
  let a = Set_version (make_version_spec ~version:"4.10" ()) in
  match a with
  | Set_version vs -> Alcotest.(check string) "version" "4.10" vs.vs_version
  | Ignore -> Alcotest.fail "Expected Set_version"

let test_override_action_eq () =
  let v410 = make_version_spec ~version:"4.10" () in
  let v412 = make_version_spec ~version:"4.12" () in
  Alcotest.(check bool) "ignore eq" true (equal_override_action Ignore Ignore);
  Alcotest.(check bool)
    "version eq" true
    (equal_override_action (Set_version v410) (Set_version v410));
  Alcotest.(check bool)
    "version neq" false
    (equal_override_action (Set_version v410) (Set_version v412));
  Alcotest.(check bool)
    "ignore neq version" false
    (equal_override_action Ignore (Set_version v410))

let test_component_override_construction () =
  let c = ignore_component ~name:"foo" in
  Alcotest.(check string) "name" "foo" c.component_name;
  Alcotest.(check bool)
    "action" true
    (Option.equal equal_override_action c.action (Some Ignore))

let test_component_override_eq () =
  let c1 = ignore_component ~name:"foo" in
  let c2 = ignore_component ~name:"foo" in
  let c3 = ignore_component ~name:"bar" in
  Alcotest.(check bool) "eq" true (equal_component_override c1 c2);
  Alcotest.(check bool) "neq" false (equal_component_override c1 c3)

let test_class_override_construction () =
  let c =
    make_class_override ~name:"Widget" ~action:(Some Ignore)
      ~methods:[ ignore_component ~name:"foo" ]
      ()
  in
  Alcotest.(check string) "name" "Widget" c.class_name;
  Alcotest.(check int) "methods" 1 (List.length c.methods);
  Alcotest.(check bool) "action" true (Option.is_some c.class_action)

let test_interface_override_construction () =
  let i =
    make_interface_override ~name:"Actionable"
      ~properties:[ version_component ~name:"action_name" ~version:"4.12" () ]
      ()
  in
  Alcotest.(check string) "name" "Actionable" i.interface_name;
  Alcotest.(check int) "properties" 1 (List.length i.properties)

let test_record_override_construction () =
  let r =
    make_record_override ~name:"TextIter"
      ~fields:[ ignore_component ~name:"user_data" ]
      ()
  in
  Alcotest.(check string) "name" "TextIter" r.record_name;
  Alcotest.(check int) "fields" 1 (List.length r.fields)

let test_enum_override_construction () =
  let e =
    make_enum_override ~name:"RGBA" ~members:[ ignore_component ~name:"RED" ] ()
  in
  Alcotest.(check string) "name" "RGBA" e.enum_name;
  Alcotest.(check int) "members" 1 (List.length e.members)

let test_bitfield_override_construction () =
  let b =
    make_bitfield_override ~name:"StateFlags"
      ~action:(Some (Set_version (make_version_spec ~version:"4.10" ())))
      ~flags:[ ignore_component ~name:"ACTIVE" ]
      ()
  in
  Alcotest.(check string) "name" "StateFlags" b.bitfield_name;
  Alcotest.(check int) "flags" 1 (List.length b.flags)

let test_library_overrides_construction () =
  let ov =
    make_library_overrides ~name:"Gtk"
      ~functions:[ ignore_component ~name:"gtk_show_uri" ]
      ()
  in
  Alcotest.(check string) "library" "Gtk" ov.library_name;
  Alcotest.(check int) "functions" 1 (List.length ov.functions)

let test_library_overrides_eq () =
  let ov1 =
    make_library_overrides ~name:"Gtk"
      ~classes:[ make_class_override ~name:"Widget" ~action:(Some Ignore) () ]
      ()
  in
  let ov2 = ov1 in
  let ov3 = { ov1 with library_name = "Gdk" } in
  Alcotest.(check bool) "eq" true (equal_library_overrides ov1 ov2);
  Alcotest.(check bool) "neq" false (equal_library_overrides ov1 ov3)

let test_suite =
  [
    ("override_action_ignore", `Quick, test_override_action_ignore);
    ("override_action_version", `Quick, test_override_action_version);
    ("override_action_eq", `Quick, test_override_action_eq);
    ( "component_override_construction",
      `Quick,
      test_component_override_construction );
    ("component_override_eq", `Quick, test_component_override_eq);
    ("class_override_construction", `Quick, test_class_override_construction);
    ( "interface_override_construction",
      `Quick,
      test_interface_override_construction );
    ("record_override_construction", `Quick, test_record_override_construction);
    ("enum_override_construction", `Quick, test_enum_override_construction);
    ( "bitfield_override_construction",
      `Quick,
      test_bitfield_override_construction );
    ( "library_overrides_construction",
      `Quick,
      test_library_overrides_construction );
    ("library_overrides_eq", `Quick, test_library_overrides_eq);
  ]
