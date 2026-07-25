(* Tests apply_overrides against a parser-fed GIR (rather than synthetic
 * in-memory records). Tier 2 — pipeline test (see Phase 1.5 of
 * docs/plans/completed/test-suite-remediation.md).
 *
 * For full multi-module pipeline coverage (parser → apply_overrides →
 * generation_context), see pipeline_tests.ml in this directory.
 *)

open Gir_gen_lib.Override_types
open Override_factory

(* Programmatic overrides: ignore Button, ignore Widget.create *)
let test_overrides =
  make_library_overrides ~name:"Gtk"
    ~classes:
      [
        make_class_override ~action:(Some Ignore) ~name:"Button" ();
        make_class_override ~name:"Widget"
          ~methods:[ ignore_component ~name:"create" ]
          ();
      ]
    ()

let test_apply_with_parsed_gir_ignore_class_and_method () =
  let tmp = Fixtures.write_synthetic_gir ~test_name:"apply_with_parsed_gir" in
  let _repository, _namespace, classes, interfaces, enums, bitfields, records, _
      =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file tmp []
  in
  let result =
    Gir_gen_lib.Override_apply.apply_overrides ~overrides:test_overrides
      ~classes ~interfaces ~enums ~bitfields ~records ~functions:[]
  in

  (* Button should be absent from classes *)
  let button_present =
    List.exists
      (fun (c : Gir_gen_lib.Types.gir_class) ->
        String.equal c.class_name "Button")
      result.classes
  in
  Alcotest.(check bool) "Button absent from classes" false button_present;

  (* Button should appear in ignored_entities *)
  let button_ignored =
    List.exists (fun s -> String.equal s "Button") result.ignored_entities
  in
  Alcotest.(check bool) "Button in ignored_entities" true button_ignored;

  (* Widget should still be present *)
  let widget_opt =
    List.find_opt
      (fun (c : Gir_gen_lib.Types.gir_class) ->
        String.equal c.class_name "Widget")
      result.classes
  in
  Alcotest.(check bool)
    "Widget present in classes" true
    (Option.is_some widget_opt);

  (* Widget.create should be absent from Widget's methods *)
  let widget = Option.get widget_opt in
  let create_present =
    List.exists
      (fun (m : Gir_gen_lib.Types.gir_method) ->
        String.equal m.method_name "create")
      widget.methods
  in
  Alcotest.(check bool) "Widget.create absent from methods" false create_present;

  (* Widget.show should still be present *)
  let show_present =
    List.exists
      (fun (m : Gir_gen_lib.Types.gir_method) ->
        String.equal m.method_name "show")
      widget.methods
  in
  Alcotest.(check bool) "Widget.show present in methods" true show_present;

  (* No warnings — all override names exist in the parsed GIR *)
  Alcotest.(check int) "no warnings" 0 (List.length result.warnings)

let test_suite =
  [
    ( "apply_overrides against parsed GIR: ignore class and method",
      `Quick,
      test_apply_with_parsed_gir_ignore_class_and_method );
  ]
