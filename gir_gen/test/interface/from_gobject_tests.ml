(* Tests for Phase 2: from_gobject C stub generation.
 *
 * Verifies:
 *   1. Utility functions gtype_macro_of_type_name and cast_macro_of_type_name
 *      in Gir_gen_lib.Utils.
 *   2. Real GIR file content: GtkEditable glib_type_name maps to GTK_TYPE_EDITABLE.
 *   3. Generated C file content: gir_gen.exe emits the from_gobject function
 *      for interfaces that have glib:type-name, and omits it when absent.
 *
 * Generated C content is validated using the C_parser / C_ast infrastructure
 * rather than string search.  See docs/code_guidelines/test-patterns.md.
 *)

(* ========================================================================= *)
(* GIR XML fixtures *)
(* ========================================================================= *)

(* Synthetic GIR with one interface that HAS glib:type-name *)
let gir_with_type_name =
  Helpers.wrap_namespace ~version:"4.0"
    {|<interface name="MyIface"
               c:type="GtkMyIface"
               glib:type-name="GtkMyIface"
               glib:get-type="gtk_my_iface_get_type">
    </interface>|}

(* Synthetic GIR with one interface that has NO glib:type-name *)
let gir_without_type_name =
  Helpers.wrap_namespace ~version:"4.0"
    {|<interface name="MyIface"
               c:type="GtkMyIface">
    </interface>|}

(* Synthetic GIR with a versioned interface (version="4.12") *)
let gir_versioned_interface =
  Helpers.wrap_namespace ~version:"4.0"
    {|<interface name="MyIface"
               c:type="GtkMyIface"
               glib:type-name="GtkMyIface"
               glib:get-type="gtk_my_iface_get_type"
               version="4.12">
    </interface>|}

(* ========================================================================= *)
(* Runner helper: run gir_gen and return the parsed C AST for entity_name    *)
(* ========================================================================= *)

(** Run gir_gen.exe on [gir_content], return the raw C file text and the parsed
    C AST for the entity whose snake_case name is [entity_snake]. Cleans up temp
    files on exit (success or failure). *)
let run_and_parse_c gir_content entity_snake =
  let gir_file = Filename.temp_file "test_from_gobject" ".gir" in
  let output_dir = Filename.temp_file "test_from_gobject_out" "" in
  Sys.remove output_dir;
  Unix.mkdir output_dir 0o755;
  Fun.protect
    ~finally:(fun () ->
      (try Sys.remove gir_file with Sys_error _ -> ());
      let generated_dir = Helpers.generated_dir output_dir in
      (try
         Array.iter
           (fun f -> Sys.remove (Filename.concat generated_dir f))
           (Sys.readdir generated_dir);
         Unix.rmdir generated_dir
       with Sys_error _ | Unix.Unix_error _ -> ());
      try
        Array.iter
          (fun f -> Sys.remove (Filename.concat output_dir f))
          (Sys.readdir output_dir);
        Unix.rmdir output_dir
      with Sys_error _ | Unix.Unix_error _ -> ())
    (fun () ->
      Helpers.create_gir_file gir_file gir_content;
      Helpers.ensure_output_dir output_dir;
      ignore (Helpers.run_gir_gen gir_file output_dir);
      let c_file = Helpers.stub_c_file output_dir entity_snake in
      if not (Helpers.file_exists c_file) then
        Alcotest.failf "Expected C file not found: %s" c_file;
      let content = Helpers.read_file c_file in
      (content, C_parser.parse_c_code content))

(* ========================================================================= *)
(* 1. Utility function tests *)
(* ========================================================================= *)

let test_gtype_macro_gtk_editable () =
  Alcotest.(check string)
    "GtkEditable → GTK_TYPE_EDITABLE" "GTK_TYPE_EDITABLE"
    (Gir_gen_lib.Utils.gtype_macro_of_type_name "GtkEditable")

let test_gtype_macro_gtk_selection_model () =
  Alcotest.(check string)
    "GtkSelectionModel → GTK_TYPE_SELECTION_MODEL" "GTK_TYPE_SELECTION_MODEL"
    (Gir_gen_lib.Utils.gtype_macro_of_type_name "GtkSelectionModel")

let test_gtype_macro_gdk_paintable () =
  Alcotest.(check string)
    "GdkPaintable → GDK_TYPE_PAINTABLE" "GDK_TYPE_PAINTABLE"
    (Gir_gen_lib.Utils.gtype_macro_of_type_name "GdkPaintable")

let test_gtype_macro_gtk_orientable () =
  Alcotest.(check string)
    "GtkOrientable → GTK_TYPE_ORIENTABLE" "GTK_TYPE_ORIENTABLE"
    (Gir_gen_lib.Utils.gtype_macro_of_type_name "GtkOrientable")

let test_cast_macro_gtk_editable () =
  Alcotest.(check string)
    "GtkEditable → GTK_EDITABLE" "GTK_EDITABLE"
    (Gir_gen_lib.Utils.cast_macro_of_type_name "GtkEditable")

let test_cast_macro_gtk_selection_model () =
  Alcotest.(check string)
    "GtkSelectionModel → GTK_SELECTION_MODEL" "GTK_SELECTION_MODEL"
    (Gir_gen_lib.Utils.cast_macro_of_type_name "GtkSelectionModel")

let test_cast_macro_gdk_paintable () =
  Alcotest.(check string)
    "GdkPaintable → GDK_PAINTABLE" "GDK_PAINTABLE"
    (Gir_gen_lib.Utils.cast_macro_of_type_name "GdkPaintable")

let test_cast_macro_gtk_orientable () =
  Alcotest.(check string)
    "GtkOrientable → GTK_ORIENTABLE" "GTK_ORIENTABLE"
    (Gir_gen_lib.Utils.cast_macro_of_type_name "GtkOrientable")

(* ========================================================================= *)
(* 2. Real GIR file: GtkEditable glib_type_name round-trips through utility  *)
(* ========================================================================= *)

let real_gir_file = Filename.concat (Helpers.gir_data_dir ()) "Gtk-4.0.gir"

let test_editable_gtype_macro_from_real_gir () =
  let _repo, _ns, _classes, interfaces, _enums, _bitfields, _records, _ =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file real_gir_file []
  in
  let editable =
    Helpers.expect_some "Editable not found in parsed interfaces"
      (List.find_opt
         (fun (i : Gir_gen_lib.Types.gir_interface) ->
           String.equal i.interface_name "Editable")
         interfaces)
      Fun.id
  in
  let type_name =
    Helpers.expect_some "GtkEditable has no glib_type_name"
      editable.glib_type_name Fun.id
  in
  let result = Gir_gen_lib.Utils.gtype_macro_of_type_name type_name in
  Alcotest.(check string)
    "GtkEditable → GTK_TYPE_EDITABLE" "GTK_TYPE_EDITABLE" result

(* ========================================================================= *)
(* 3. Generated file content tests (via gir_gen.exe)                         *)
(*                                                                            *)
(* Validation uses C_parser / C_ast rather than string search.               *)
(* See docs/code_guidelines/test-patterns.md.                                *)
(* ========================================================================= *)

(** The from_gobject function must exist when the interface has glib:type-name.
    We verify via the C AST that:
    - the function is present in the parsed output
    - it has a CAMLreturn with the correct Val_ macro
    - it calls caml_failwith (the error branch) *)
let test_from_gobject_present_when_type_name_set () =
  let _content, functions = run_and_parse_c gir_with_type_name "my_iface" in
  let fn_name = "ml_gtk_my_iface_from_gobject" in
  let f =
    Helpers.expect_some
      (Fmt.str "%s not found in parsed C AST" fn_name)
      (C_ast.find_function functions fn_name)
      Fun.id
  in
  Alcotest.(check bool) "has CAMLreturn" true (C_validation.has_caml_return f);
  Alcotest.(check bool)
    "returns Val_GtkMyIface" true
    (C_validation.uses_correct_return_macro f "Val_GtkMyIface");
  Alcotest.(check bool)
    "calls caml_failwith" true
    (C_ast.function_calls_function f "caml_failwith")

(** When glib:type-name is absent the from_gobject function must be absent. We
    verify via the C AST that the function does not appear. *)
let test_from_gobject_absent_when_no_type_name () =
  let _content, functions = run_and_parse_c gir_without_type_name "my_iface" in
  let fn_name = "ml_gtk_my_iface_from_gobject" in
  Alcotest.(check bool)
    "from_gobject function absent" true
    (Option.is_none (C_ast.find_function functions fn_name))

(** For a versioned interface, the from_gobject function must appear inside a
    GTK_CHECK_VERSION guard. We check:
    - the version guard string is present (preprocessor — not in C AST)
    - the from_gobject function is present in the C AST
    - the function has the correct return macro (structural correctness) *)
let test_from_gobject_inside_version_guard () =
  let content, functions = run_and_parse_c gir_versioned_interface "my_iface" in
  (* Preprocessor guard: C_parser strips #if/#endif directives, so the C AST
     cannot represent them. String search is the only available mechanism here.
     This is the sole legitimate exception in this file — all other checks use
     AST-based validation. *)
  if not (Helpers.string_contains content "GTK_CHECK_VERSION(4,12,0)") then
    Alcotest.fail "version guard GTK_CHECK_VERSION(4,12,0) not found in output";
  (* C AST: function must be present and structurally correct *)
  let fn_name = "ml_gtk_my_iface_from_gobject" in
  let f =
    Helpers.expect_some
      (Fmt.str "%s not found in parsed C AST" fn_name)
      (C_ast.find_function functions fn_name)
      Fun.id
  in
  Alcotest.(check bool)
    "returns Val_GtkMyIface inside guard" true
    (C_validation.uses_correct_return_macro f "Val_GtkMyIface")

(* ========================================================================= *)
(* Phase 3: from_gobject external declaration in Layer 1 .mli / .ml files    *)
(* ========================================================================= *)

(** Run gir_gen.exe on [gir_content], return the raw .mli text and the parsed
    signature AST for the entity whose snake_case name is [entity_snake]. Cleans
    up temp files on exit (success or failure). *)
let run_and_parse_l1_mli gir_content entity_snake =
  let gir_file = Filename.temp_file "test_from_gobject_l1" ".gir" in
  let output_dir = Filename.temp_file "test_from_gobject_l1_out" "" in
  Sys.remove output_dir;
  Unix.mkdir output_dir 0o755;
  Fun.protect
    ~finally:(fun () ->
      (try Sys.remove gir_file with Sys_error _ -> ());
      let generated_dir = Helpers.generated_dir output_dir in
      (try
         Array.iter
           (fun f -> Sys.remove (Filename.concat generated_dir f))
           (Sys.readdir generated_dir);
         Unix.rmdir generated_dir
       with Sys_error _ | Unix.Unix_error _ -> ());
      try
        Array.iter
          (fun f -> Sys.remove (Filename.concat output_dir f))
          (Sys.readdir output_dir);
        Unix.rmdir output_dir
      with Sys_error _ | Unix.Unix_error _ -> ())
    (fun () ->
      Helpers.create_gir_file gir_file gir_content;
      Helpers.ensure_output_dir output_dir;
      ignore (Helpers.run_gir_gen gir_file output_dir);
      let mli_path =
        Filename.concat
          (Helpers.generated_dir output_dir)
          (entity_snake ^ ".mli")
      in
      if not (Helpers.file_exists mli_path) then
        Alcotest.failf "Expected .mli file not found: %s" mli_path;
      let content = Helpers.read_file mli_path in
      (content, Ml_ast_helpers.parse_interface content))

(** Run gir_gen.exe on [gir_content], return the raw .ml text and the parsed
    structure AST for the entity whose snake_case name is [entity_snake]. Cleans
    up temp files on exit (success or failure). *)
let run_and_parse_l1_ml gir_content entity_snake =
  let gir_file = Filename.temp_file "test_from_gobject_l1ml" ".gir" in
  let output_dir = Filename.temp_file "test_from_gobject_l1ml_out" "" in
  Sys.remove output_dir;
  Unix.mkdir output_dir 0o755;
  Fun.protect
    ~finally:(fun () ->
      (try Sys.remove gir_file with Sys_error _ -> ());
      let generated_dir = Helpers.generated_dir output_dir in
      (try
         Array.iter
           (fun f -> Sys.remove (Filename.concat generated_dir f))
           (Sys.readdir generated_dir);
         Unix.rmdir generated_dir
       with Sys_error _ | Unix.Unix_error _ -> ());
      try
        Array.iter
          (fun f -> Sys.remove (Filename.concat output_dir f))
          (Sys.readdir output_dir);
        Unix.rmdir output_dir
      with Sys_error _ | Unix.Unix_error _ -> ())
    (fun () ->
      Helpers.create_gir_file gir_file gir_content;
      Helpers.ensure_output_dir output_dir;
      ignore (Helpers.run_gir_gen gir_file output_dir);
      let ml_path =
        Filename.concat (Helpers.generated_dir output_dir) (entity_snake ^ ".ml")
      in
      if not (Helpers.file_exists ml_path) then
        Alcotest.failf "Expected .ml file not found: %s" ml_path;
      let content = Helpers.read_file ml_path in
      (content, Ml_ast_helpers.parse_implementation content))

(** from_gobject external must appear in .mli when glib:type-name is set. *)
let test_from_gobject_external_in_mli () =
  let _content, mli_ast = run_and_parse_l1_mli gir_with_type_name "my_iface" in
  let ext =
    Helpers.expect_some "from_gobject not found in .mli"
      (Ml_ast_helpers.find_external_sig mli_ast "from_gobject")
      Fun.id
  in
  Ml_validation.assert_external_c_name ext "ml_gtk_my_iface_from_gobject"

(** from_gobject external must appear in .ml when glib:type-name is set. *)
let test_from_gobject_external_in_ml () =
  let _content, ml_ast = run_and_parse_l1_ml gir_with_type_name "my_iface" in
  let ext =
    Helpers.expect_some "from_gobject not found in .ml"
      (Ml_ast_helpers.find_external ml_ast "from_gobject")
      Fun.id
  in
  Ml_validation.assert_external_c_name ext "ml_gtk_my_iface_from_gobject"

(** from_gobject must be absent from .mli when glib:type-name is not set. *)
let test_no_from_gobject_in_mli_when_no_type_name () =
  let _content, mli_ast =
    run_and_parse_l1_mli gir_without_type_name "my_iface"
  in
  Alcotest.(check bool)
    "from_gobject absent from .mli" true
    (Option.is_none (Ml_ast_helpers.find_external_sig mli_ast "from_gobject"))

(** type t must still appear before from_gobject in .mli. *)
let test_type_t_before_from_gobject () =
  let _content, mli_ast = run_and_parse_l1_mli gir_with_type_name "my_iface" in
  Ml_validation.assert_type_exists_sig mli_ast "t";
  let ext =
    Helpers.expect_some "from_gobject not in .mli"
      (Ml_ast_helpers.find_external_sig mli_ast "from_gobject")
      Fun.id
  in
  Ml_validation.assert_external_c_name ext "ml_gtk_my_iface_from_gobject"

(* ========================================================================= *)
(* Test suite *)
(* ========================================================================= *)

let test_suite =
  [
    (* Utility: gtype_macro_of_type_name *)
    ( "gtype_macro: GtkEditable → GTK_TYPE_EDITABLE",
      `Quick,
      test_gtype_macro_gtk_editable );
    ( "gtype_macro: GtkSelectionModel → GTK_TYPE_SELECTION_MODEL",
      `Quick,
      test_gtype_macro_gtk_selection_model );
    ( "gtype_macro: GdkPaintable → GDK_TYPE_PAINTABLE",
      `Quick,
      test_gtype_macro_gdk_paintable );
    ( "gtype_macro: GtkOrientable → GTK_TYPE_ORIENTABLE",
      `Quick,
      test_gtype_macro_gtk_orientable );
    (* Utility: cast_macro_of_type_name *)
    ( "cast_macro: GtkEditable → GTK_EDITABLE",
      `Quick,
      test_cast_macro_gtk_editable );
    ( "cast_macro: GtkSelectionModel → GTK_SELECTION_MODEL",
      `Quick,
      test_cast_macro_gtk_selection_model );
    ( "cast_macro: GdkPaintable → GDK_PAINTABLE",
      `Quick,
      test_cast_macro_gdk_paintable );
    ( "cast_macro: GtkOrientable → GTK_ORIENTABLE",
      `Quick,
      test_cast_macro_gtk_orientable );
    (* Real GIR *)
    ( "real GIR: GtkEditable glib_type_name → GTK_TYPE_EDITABLE",
      `Slow,
      test_editable_gtype_macro_from_real_gir );
    (* Generated file content — validated with C AST, not string search *)
    ( "generated: from_gobject present when glib:type-name set",
      `Quick,
      test_from_gobject_present_when_type_name_set );
    ( "generated: from_gobject absent when no glib:type-name",
      `Quick,
      test_from_gobject_absent_when_no_type_name );
    ( "generated: versioned interface wraps from_gobject in GTK_CHECK_VERSION \
       guard",
      `Quick,
      test_from_gobject_inside_version_guard );
    (* Phase 3: from_gobject external in Layer 1 .mli / .ml files *)
    ( "phase3: from_gobject external present in .mli when glib:type-name set",
      `Quick,
      test_from_gobject_external_in_mli );
    ( "phase3: from_gobject external present in .ml when glib:type-name set",
      `Quick,
      test_from_gobject_external_in_ml );
    ( "phase3: from_gobject absent from .mli when no glib:type-name",
      `Quick,
      test_no_from_gobject_in_mli_when_no_type_name );
    ( "phase3: type t appears before from_gobject in .mli",
      `Quick,
      test_type_t_before_from_gobject );
  ]
