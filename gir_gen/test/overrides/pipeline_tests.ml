(* Pipeline tests for the override system (tier 2 — see Phase 1.5 of
 * docs/plans/completed/test-suite-remediation.md).
 *
 * Verifies that override-based filtering propagates correctly through the
 * complete in-process pipeline:
 *   parse GIR → apply overrides → build generation_context
 *   → type-mapping lookups return None for ignored entities
 *
 * Distinct from apply_with_parsed_gir_tests.ml, which only checks the
 * apply_overrides result against a parsed GIR. These tests go one level
 * further and verify that the ctx type-mapping is consistent with the
 * filtering, so that filtering.ml correctly skips methods referencing
 * ignored types.
 *)

open Gir_gen_lib.Types
open Gir_gen_lib.Override_types
open Override_factory

(* ========================================================================= *)
(* Helpers *)
(* ========================================================================= *)

(** Parse the synthetic GIR and apply overrides. Returns the apply_result.
    [test_name] is used to name the per-test pipeline_tmp/ directory. *)
let parse_and_apply ~test_name overrides =
  let tmp = Fixtures.write_synthetic_gir ~test_name in
  let _repository, _namespace, classes, interfaces, enums, bitfields, records, _
      =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file tmp []
  in
  Gir_gen_lib.Override_apply.apply_overrides ~overrides ~classes ~interfaces
    ~enums ~bitfields ~records ~functions:[]

(** Minimal namespace for building a generation_context in tests. *)
let test_namespace : gir_namespace =
  Type_factory.make_gir_namespace ~namespace_name:"Gtk" ~namespace_version:"4.0"
    ~namespace_shared_library:"libgtk-4.so.1"
    ~namespace_c_identifier_prefixes:"Gtk" ~namespace_c_symbol_prefixes:"gtk" ()

let test_repository : gir_repository = Type_factory.make_gir_repository ()

(** Build a generation_context from an apply_result for type-mapping tests. *)
let make_ctx (result : Gir_gen_lib.Override_apply.apply_result) :
    generation_context =
  Type_factory.make_generation_context ~namespace:test_namespace
    ~repository:test_repository ~classes:result.classes
    ~interfaces:result.interfaces ~enums:result.enums
    ~bitfields:result.bitfields ~records:result.records ()

(** A gir_type that references GtkButton* (as returned by a button constructor).
*)
let button_gir_type : gir_type =
  Type_factory.make_gir_type ~name:"Button" ~c_type:"GtkButton*" ()

(** A gir_type that references GtkWidget* (survives override). *)
let widget_gir_type : gir_type =
  Type_factory.make_gir_type ~name:"Widget" ~c_type:"GtkWidget*" ()

(* ========================================================================= *)
(* Overrides used across tests *)
(* ========================================================================= *)

let ignore_button_overrides =
  make_library_overrides ~name:"Gtk"
    ~classes:[ make_class_override ~action:(Some Ignore) ~name:"Button" () ]
    ()

let ignore_create_overrides =
  make_library_overrides ~name:"Gtk"
    ~classes:
      [
        make_class_override ~name:"Widget"
          ~methods:[ ignore_component ~name:"create" ]
          ();
      ]
    ()

let version_widget_overrides =
  make_library_overrides ~name:"Gtk"
    ~classes:
      [
        make_class_override ~name:"Widget"
          ~action:(Some (Set_version (make_version_spec ~version:"4.10" ())))
          ();
      ]
    ()

(* ========================================================================= *)
(* Tests: ctx-level class filtering *)
(* ========================================================================= *)

(** Ignored class must be absent from generation_context.classes so that
    filtering.ml skips methods that reference it via
    find_type_mapping_for_gir_type. *)
let test_ignored_class_absent_from_ctx () =
  let result =
    parse_and_apply ~test_name:"ignored_class_absent_from_ctx"
      ignore_button_overrides
  in
  let ctx = make_ctx result in
  let button_in_ctx =
    List.exists
      (fun (c : gir_class) -> String.equal c.class_name "Button")
      ctx.classes
  in
  Alcotest.(check bool) "Button absent from ctx.classes" false button_in_ctx

(** Type-mapping lookup for the ignored class must return None. This is the key
    integration property: filtering.ml uses find_type_mapping_for_gir_type to
    decide whether to skip a method whose return/parameter type is the ignored
    class. When Button is absent from ctx, the lookup returns None and those
    methods are skipped. *)
let test_type_mapping_returns_none_for_ignored_class () =
  let result =
    parse_and_apply ~test_name:"type_mapping_none_for_ignored_class"
      ignore_button_overrides
  in
  let ctx = make_ctx result in
  let mapping =
    Gir_gen_lib.Type_mappings.find_type_mapping_for_gir_type ~ctx
      button_gir_type
  in
  Alcotest.(check bool)
    "type mapping for GtkButton* is None" true (Option.is_none mapping)

(** Type-mapping lookup for a surviving class must return Some. Verifies that
    the None above is due to the ignore, not a general failure. *)
let test_type_mapping_returns_some_for_surviving_class () =
  let result =
    parse_and_apply ~test_name:"type_mapping_some_for_surviving_class"
      ignore_button_overrides
  in
  let ctx = make_ctx result in
  let mapping =
    Gir_gen_lib.Type_mappings.find_type_mapping_for_gir_type ~ctx
      widget_gir_type
  in
  Alcotest.(check bool)
    "type mapping for GtkWidget* is Some" true (Option.is_some mapping)

(* ========================================================================= *)
(* Tests: ctx-level method filtering *)
(* ========================================================================= *)

(** Ignored method must be absent from the surviving class's method list inside
    the generation_context. This confirms that component-level overrides also
    propagate into the ctx that the generators use. *)
let test_ignored_method_absent_from_ctx () =
  let result =
    parse_and_apply ~test_name:"ignored_method_absent_from_ctx"
      ignore_create_overrides
  in
  let ctx = make_ctx result in
  let widget_opt =
    List.find_opt
      (fun (c : gir_class) -> String.equal c.class_name "Widget")
      ctx.classes
  in
  Helpers.expect_some "Widget absent from ctx (unexpected)" widget_opt
  @@ fun widget ->
  let create_in_ctx =
    List.exists
      (fun (m : gir_method) -> String.equal m.method_name "create")
      widget.methods
  in
  Alcotest.(check bool) "Widget.create absent from ctx" false create_in_ctx;
  let show_in_ctx =
    List.exists
      (fun (m : gir_method) -> String.equal m.method_name "show")
      widget.methods
  in
  Alcotest.(check bool) "Widget.show present in ctx" true show_in_ctx

(* ========================================================================= *)
(* Tests: version override propagation *)
(* ========================================================================= *)

(** Entity-level version override must propagate into the class's version field
    inside the generation_context, which feeds into class-level C #if guards. *)
let test_version_override_propagates_to_ctx () =
  let result =
    parse_and_apply ~test_name:"version_override_propagates_to_ctx"
      version_widget_overrides
  in
  let ctx = make_ctx result in
  let widget_opt =
    List.find_opt
      (fun (c : gir_class) -> String.equal c.class_name "Widget")
      ctx.classes
  in
  Helpers.expect_some "Widget absent from ctx (unexpected)" widget_opt
  @@ fun widget ->
  Alcotest.(check (option string))
    "Widget.version is Some 4.10" (Some "4.10") widget.version

(* ========================================================================= *)
(* Tests: references generation excludes ignored entities *)
(* ========================================================================= *)

(** The references generation path uses the same apply_overrides call. Verify
    that ignored entities are absent from the apply_result used for references,
    mirroring what generate_references does in gir_gen.ml. *)
let test_references_excludes_ignored_class () =
  let result =
    parse_and_apply ~test_name:"references_excludes_ignored_class"
      ignore_button_overrides
  in
  (* References generation uses result.classes directly — Button must be absent *)
  let button_in_refs =
    List.exists
      (fun (c : gir_class) -> String.equal c.class_name "Button")
      result.classes
  in
  Alcotest.(check bool)
    "Button absent from references classes" false button_in_refs;
  (* Widget must still be present for valid references *)
  let widget_in_refs =
    List.exists
      (fun (c : gir_class) -> String.equal c.class_name "Widget")
      result.classes
  in
  Alcotest.(check bool)
    "Widget present in references classes" true widget_in_refs

(** Parse-based integration: parse the override sexp string, apply to GIR, build
    ctx, and check that the ignored class is absent from the type mapping. This
    exercises the full string-parse → apply → ctx path. *)
let test_sexp_parse_to_ctx_integration () =
  let override_sexp =
    {|(overrides
        (library "Gtk")
        (class Button (ignore))
      )|}
  in
  let overrides =
    match
      Gir_gen_lib.Override_parser.parse_overrides_from_string override_sexp
    with
    | Error e ->
        Alcotest.failf "Override parse failed: %s"
          (Gir_gen_lib.Override_parser.format_error e)
    | Ok ov -> ov
  in
  let result =
    parse_and_apply ~test_name:"sexp_parse_to_ctx_integration" overrides
  in
  let ctx = make_ctx result in
  let button_absent =
    not
      (List.exists
         (fun (c : gir_class) -> String.equal c.class_name "Button")
         ctx.classes)
  in
  Alcotest.(check bool)
    "Button absent from ctx after sexp-parsed override" true button_absent;
  let mapping =
    Gir_gen_lib.Type_mappings.find_type_mapping_for_gir_type ~ctx
      button_gir_type
  in
  Alcotest.(check bool)
    "type mapping None for Button after sexp-parsed override" true
    (Option.is_none mapping)

(* ========================================================================= *)
(* Tests: empty overrides do not affect the ctx *)
(* ========================================================================= *)

let test_empty_overrides_preserve_all_classes () =
  let empty_overrides = make_empty_library_overrides ~name:"Gtk" in
  let result =
    parse_and_apply ~test_name:"empty_overrides_preserve_all_classes"
      empty_overrides
  in
  let ctx = make_ctx result in
  let class_count = List.length ctx.classes in
  Alcotest.(check int) "both classes present with empty overrides" 2 class_count;
  let button_mapping =
    Gir_gen_lib.Type_mappings.find_type_mapping_for_gir_type ~ctx
      button_gir_type
  in
  Alcotest.(check bool)
    "Button type mapping present with empty overrides" true
    (Option.is_some button_mapping)

(* ========================================================================= *)
(* Test suite *)
(* ========================================================================= *)

let test_suite =
  [
    ( "integration: ignored class absent from ctx.classes",
      `Quick,
      test_ignored_class_absent_from_ctx );
    ( "integration: type mapping None for ignored class",
      `Quick,
      test_type_mapping_returns_none_for_ignored_class );
    ( "integration: type mapping Some for surviving class",
      `Quick,
      test_type_mapping_returns_some_for_surviving_class );
    ( "integration: ignored method absent from ctx class",
      `Quick,
      test_ignored_method_absent_from_ctx );
    ( "integration: version override propagates into ctx",
      `Quick,
      test_version_override_propagates_to_ctx );
    ( "integration: references generation excludes ignored class",
      `Quick,
      test_references_excludes_ignored_class );
    ( "integration: sexp parse → apply → ctx type mapping",
      `Quick,
      test_sexp_parse_to_ctx_integration );
    ( "integration: empty overrides preserve all classes",
      `Quick,
      test_empty_overrides_preserve_all_classes );
  ]
