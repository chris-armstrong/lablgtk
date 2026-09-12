(* Header Naming Tests - Validates header file naming conventions using AST-based validation *)

open Printf
open C_validation

(* ========================================================================= *)
(* Test Helper Functions *)
(* ========================================================================= *)

(* Create a test context with a specific namespace for header naming tests *)
let create_test_context_with_namespace namespace_name =
  let open Gir_gen_lib.Types in
  let namespace =
    {
      namespace_name;
      namespace_version = "4.0";
      namespace_shared_library = "libgtk-4.so.1";
      namespace_c_identifier_prefixes = namespace_name;
      namespace_c_symbol_prefixes = String.lowercase_ascii namespace_name;
    }
  in

  let repository =
    {
      repository_c_includes = [];
      repository_includes = [];
      repository_packages = [];
      repository_doc_format = None;
    }
  in

  {
    namespace;
    repository;
    classes = [];
    interfaces = [];
    enums = [];
    bitfields = [];
    records = [];
    constants = [];
    module_groups = Hashtbl.create 0;
    current_cycle_classes = [];
    cross_references = StringMap.empty;
  }

(* ========================================================================= *)
(* Header File Naming Tests *)
(* ========================================================================= *)

let test_header_file_naming_uses_namespace () =
  (* Arrange: Create context with GTK namespace *)
  let ctx = create_test_context_with_namespace "Gtk" in
  let ns_name =
    String.lowercase_ascii ctx.Gir_gen_lib.Types.namespace.namespace_name
  in

  (* Act: Generate the header file content *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:[] ~gtk_bitfields:[] ~records:[] ~interfaces:[] ()
  in

  (* Assert: Header guard should use namespace-based pattern *)
  let expected_suffix = "_decls_h_" in
  (* Use C_validation to assert header guard format exists *)
  C_validation.assert_header_guard_format header_content expected_suffix;

  (* Verify the guard name specifically contains the namespace *)
  let guards = parse_header_guards header_content in
  let expected_guard_name = sprintf "_%s_decls_h_" ns_name in
  let guard_opt =
    List.find_opt (fun g -> g.guard_name = expected_guard_name) guards
  in

  Helpers.expect_some
    (sprintf "Header guard with namespace-based name '%s' not found"
       expected_guard_name)
    guard_opt
  @@ fun guard ->
  (* Verify it's not using old naming patterns *)
  let has_old_naming =
    String.starts_with ~prefix:"generated_forward_decls" guard.guard_name
    || String.ends_with ~suffix:"generated_forward_decls" guard.guard_name
    || String.starts_with ~prefix:"_generated_forward_decls" guard.guard_name
    || String.ends_with ~suffix:"_generated_forward_decls_" guard.guard_name
  in
  Alcotest.(check bool)
    "Header guard uses new namespace-based naming, not old pattern" false
    has_old_naming

let test_header_guard_uses_correct_format () =
  (* Arrange: Create context with different namespaces to verify format works universally *)
  let test_cases = [ "Gtk"; "Gdk"; "Gsk" ] in

  List.iter
    (fun namespace ->
      let ctx = create_test_context_with_namespace namespace in

      (* Act: Generate header for this namespace *)
      let header_content =
        Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx
          ~classes:ctx.classes ~gtk_enums:[] ~gtk_bitfields:[] ~records:[]
          ~interfaces:[] ()
      in

      (* Assert: Verify header guard uses _<namespace>_decls_h_ format *)
      let guards = parse_header_guards header_content in
      let ns_lower = String.lowercase_ascii namespace in
      let expected_guard_name = sprintf "_%s_decls_h_" ns_lower in

      let guard_opt =
        List.find_opt (fun g -> g.guard_name = expected_guard_name) guards
      in

      Helpers.expect_some
        (let available =
           List.map (fun g -> g.guard_name) guards |> String.concat ", "
         in
         sprintf
           "For namespace '%s': expected guard '%s' not found. Available: [%s]"
           namespace expected_guard_name available)
        guard_opt
      @@ fun guard ->
      (* Verify guard name exactly matches expected format *)
      Alcotest.(check string)
        (sprintf "Header guard for %s uses correct format" namespace)
        expected_guard_name guard.guard_name)
    test_cases

let test_header_guard_has_complete_structure () =
  (* Arrange: Create context and generate header *)
  let ctx = create_test_context_with_namespace "Gtk" in
  let ns_lower = String.lowercase_ascii "Gtk" in
  let expected_guard_name = sprintf "_%s_decls_h_" ns_lower in

  (* Act: Generate the header content *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:[] ~gtk_bitfields:[] ~records:[] ~interfaces:[] ()
  in

  (* Assert: Parse and verify complete guard structure *)
  let guards = parse_header_guards header_content in

  (* Find the expected guard *)
  let guard_opt =
    List.find_opt (fun g -> g.guard_name = expected_guard_name) guards
  in

  match guard_opt with
  | None ->
      let available =
        List.map (fun g -> g.guard_name) guards |> String.concat ", "
      in
      Alcotest.fail
        (sprintf "Header guard '%s' not found. Available: [%s]"
           expected_guard_name available)
  | Some guard ->
      (* Verify all three directives are present *)
      Alcotest.(check bool)
        "Header guard has #ifndef directive" true guard.has_ifndef;
      Alcotest.(check bool)
        "Header guard has #define directive" true guard.has_define;
      Alcotest.(check bool)
        "Header guard has #endif directive" true guard.has_endif;

      (* Verify the guard is complete - all three must be true *)
      let is_complete =
        guard.has_ifndef && guard.has_define && guard.has_endif
      in
      Alcotest.(check bool)
        "Header guard has complete structure (ifndef + define + endif)" true
        is_complete

(* ========================================================================= *)
(* Test Suite *)
(* ========================================================================= *)

let tests =
  [
    Alcotest.test_case "Header file naming uses namespace convention" `Quick
      test_header_file_naming_uses_namespace;
    Alcotest.test_case "Header guard uses _<ns>_decls_h_ format" `Quick
      test_header_guard_uses_correct_format;
    Alcotest.test_case
      "Header guard has complete structure (ifndef/define/endif)" `Quick
      test_header_guard_has_complete_structure;
  ]
