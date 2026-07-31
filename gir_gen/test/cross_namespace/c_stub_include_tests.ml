(* Cross-namespace tests - Stage 5: Update C Stub File Header Include

   Tests that generated C stub files include the library-specific `<ns>_decls.h`
   header. This ensures that
   each library's C stubs have access to the correct type converters. *)

open C_validation

(* Helper: Create a context for testing C stub header generation *)
let create_test_context ~namespace =
  let ns =
    Type_factory.make_gir_namespace ~namespace_name:namespace
      ~namespace_version:"4.0"
      ~namespace_shared_library:("lib" ^ namespace ^ "-4.so.1")
      ~namespace_c_identifier_prefixes:namespace
      ~namespace_c_symbol_prefixes:(String.lowercase_ascii namespace)
      ()
  in
  Type_factory.make_generation_context ~namespace:ns
    ~repository:(Type_factory.make_gir_repository ())
    ()

(* Stage 5 Test: C stub file includes library-specific decls header.
   When generating C stubs for a namespace, the file should include
   `<ns>_decls.h`. *)
let test_c_stub_includes_namespace_decls () =
  (* Create context for Gtk namespace *)
  let ctx = create_test_context ~namespace:"Gtk" in

  (* Generate C file header *)
  let header_content =
    Gir_gen_lib.Generate.C_stub_helpers.generate_c_file_header ~ctx ()
  in

  Helpers.log_generated_c_code
    "c_stub_header.c (Stage 5 namespace decls include test)" header_content;

  (* Verify the namespace-specific header is included using AST-based validation *)
  assert_local_include_exists header_content "gtk_decls.h"

(* Stage 5 Test: C stub file includes correct header for Gdk namespace. *)
let test_c_stub_includes_gdk_decls () =
  (* Create context for Gdk namespace *)
  let ctx = create_test_context ~namespace:"Gdk" in

  (* Generate C file header *)
  let header_content =
    Gir_gen_lib.Generate.C_stub_helpers.generate_c_file_header ~ctx ()
  in

  (* Verify gdk_decls.h is included *)
  assert_local_include_exists header_content "gdk_decls.h"

(* Stage 5 Test: C stub file includes correct header for Gio namespace. *)
let test_c_stub_includes_gio_decls () =
  (* Create context for Gio namespace *)
  let ctx = create_test_context ~namespace:"Gio" in

  (* Generate C file header *)
  let header_content =
    Gir_gen_lib.Generate.C_stub_helpers.generate_c_file_header ~ctx ()
  in

  (* Verify gio_decls.h is included *)
  assert_local_include_exists header_content "gio_decls.h"

(* Stage 5 Test: C stub file uses lowercase namespace in header include.
   The include should be `#include "gtk_decls.h"` not `#include "Gtk_decls.h"`. *)
let test_c_stub_uses_lowercase_namespace () =
  (* Create context with mixed-case namespace *)
  let ctx = create_test_context ~namespace:"Gtk" in

  (* Generate C file header *)
  let header_content =
    Gir_gen_lib.Generate.C_stub_helpers.generate_c_file_header ~ctx ()
  in

  (* Verify lowercase is used using AST-based validation *)
  assert_local_include_exists header_content "gtk_decls.h";

  (* Verify uppercase is NOT used using AST-based validation *)
  assert_local_include_not_exists header_content "Gtk_decls.h"

(* Stage 5 Test: Namespace is derived from context correctly.
   The namespace should come from ctx.namespace.namespace_name. *)
let test_namespace_derived_from_context () =
  (* Test multiple namespaces to verify correct derivation *)
  let test_namespaces = [ "Gtk"; "Gdk"; "Gio"; "Gsk"; "Pango" ] in
  List.iter
    (fun ns ->
      let ctx = create_test_context ~namespace:ns in
      let header_content =
        Gir_gen_lib.Generate.C_stub_helpers.generate_c_file_header ~ctx ()
      in
      let expected_header = String.lowercase_ascii ns ^ "_decls.h" in
      assert_local_include_exists header_content expected_header)
    test_namespaces

let tests =
  [
    Alcotest.test_case
      "C stub file includes namespace-specific decls header (Stage 5)" `Quick
      test_c_stub_includes_namespace_decls;
    Alcotest.test_case "C stub file includes gdk_decls.h (Stage 5)" `Quick
      test_c_stub_includes_gdk_decls;
    Alcotest.test_case "C stub file includes gio_decls.h (Stage 5)" `Quick
      test_c_stub_includes_gio_decls;
    Alcotest.test_case "C stub uses lowercase namespace (Stage 5)" `Quick
      test_c_stub_uses_lowercase_namespace;
    Alcotest.test_case "Namespace derived from context (Stage 5)" `Quick
      test_namespace_derived_from_context;
  ]
