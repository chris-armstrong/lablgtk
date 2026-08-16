(* Cross-namespace tests - Stage 4: Generate Dependency Header Includes

   Tests that generated header files contain #include directives for dependency
   namespaces' header files. This allows dependent libraries to access type
   converters from their dependencies. *)

open C_validation

(* Helper: Create a context with cross-references to verify that dependency
     headers are included *)
let create_context_with_cross_references ~namespace ~deps =
  (* Create per-namespace entries in the outer cross_references map,
     matching the structure that get_dependency_namespaces expects *)
  let cross_references =
    List.fold_left
      (fun acc dep_ns ->
        let cr =
          Type_factory.make_cross_reference_entity ~cr_name:"TestClass"
            ~cr_type:(Type_factory.make_cross_reference_type `Class)
            ~cr_c_type:(dep_ns ^ "TestClass") ()
        in
        let entities =
          Gir_gen_lib.Types.StringMap.add "TestClass" cr
            Gir_gen_lib.Types.StringMap.empty
        in
        Gir_gen_lib.Types.StringMap.add dep_ns
          (snd (Helpers.make_ncr dep_ns entities))
          acc)
      Gir_gen_lib.Types.StringMap.empty deps
  in
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
    ~cross_references ()

(* Stage 4 Test: Header includes dependency headers for cross-namespace types.
     When generating gtk_decls.h with Gdk and Gio as dependencies,
     the header should include generated/gdk_decls.h and generated/gio_decls.h.
     
     Note: Headers are included as "generated/<ns>_decls.h" because OCaml automatically
     passes -I path/to/<library> when you depend on a library, so the full path
     resolves to path/to/<library>/generated/<ns>_decls.h *)
let test_header_includes_dependency_headers () =
  (* Create context simulating Gtk with Gdk and Gio dependencies *)
  let ctx =
    create_context_with_cross_references ~namespace:"Gtk" ~deps:[ "Gdk"; "Gio" ]
  in

  (* Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:[]
      ~gtk_enums:[] ~gtk_bitfields:[] ~records:[] ~interfaces:[] ()
  in

  Helpers.log_generated_c_code "gtk_decls.h (Stage 4 dependency includes test)"
    header_content;

  (* Verify dependency headers are included using AST-based validation *)
  C_validation.assert_local_include_exists header_content
    "generated/gdk_decls.h";
  C_validation.assert_local_include_exists header_content
    "generated/gio_decls.h"

(* Stage 4 Test: Dependency headers are sorted alphabetically.
    This ensures consistent output across runs. *)
let test_dependency_headers_sorted_alphabetically () =
  (* Create context with dependencies in non-alphabetical order *)
  let ctx =
    create_context_with_cross_references ~namespace:"Gtk"
      ~deps:[ "Gsk"; "Gdk"; "Gio" ]
  in

  (* Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:[]
      ~gtk_enums:[] ~gtk_bitfields:[] ~records:[] ~interfaces:[] ()
  in

  (* Find positions of includes in the output using AST-based validation *)
  let gdk_pos =
    try
      Re.Str.search_forward
        (Re.Str.regexp_string {|#include "generated/gdk_decls.h"|})
        header_content 0
    with Not_found ->
      Alcotest.fail "generated/gdk_decls.h not found in header"
  in
  let gio_pos =
    try
      Re.Str.search_forward
        (Re.Str.regexp_string {|#include "generated/gio_decls.h"|})
        header_content 0
    with Not_found ->
      Alcotest.fail "generated/gio_decls.h not found in header"
  in
  let gsk_pos =
    try
      Re.Str.search_forward
        (Re.Str.regexp_string {|#include "generated/gsk_decls.h"|})
        header_content 0
    with Not_found ->
      Alcotest.fail "generated/gsk_decls.h not found in header"
  in

  (* Verify alphabetical order: Gdk < Gio < Gsk *)
  if not (gdk_pos < gio_pos && gio_pos < gsk_pos) then
    Alcotest.fail
      "Dependency headers should be sorted alphabetically (Gdk < Gio < Gsk)"

(* Stage 4 Test: Header uses lowercase namespace in include filename.
     The include directive should be #include "generated/gdk_decls.h" not #include "generated/Gdk_decls.h". *)
let test_include_uses_lowercase_namespace () =
  (* Create context with mixed-case namespace *)
  let ctx =
    create_context_with_cross_references ~namespace:"Gtk" ~deps:[ "Gdk" ]
  in

  (* Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:[]
      ~gtk_enums:[] ~gtk_bitfields:[] ~records:[] ~interfaces:[] ()
  in

  (* Verify lowercase is used using AST-based validation *)
  assert_local_include_exists header_content "generated/gdk_decls.h";

  (* Verify uppercase is NOT used using AST-based validation *)
  assert_local_include_not_exists header_content "generated/Gdk_decls.h"

(* Stage 4 Test: Helper function get_dependency_namespaces works correctly.
    Extracts unique namespace names from cross_references map. *)
let test_get_dependency_namespaces_extracts_unique_namespaces () =
  let open Gir_gen_lib.Types in
  (* Create cross_references map with duplicate namespaces *)
  let cr1 =
    Type_factory.make_cross_reference_entity ~cr_name:"Class1"
      ~cr_type:(Type_factory.make_cross_reference_type `Class)
      ~cr_c_type:"GdkClass1" ()
  in
  let cr2 =
    Type_factory.make_cross_reference_entity ~cr_name:"Class2"
      ~cr_type:(Type_factory.make_cross_reference_type `Class)
      ~cr_c_type:"GdkClass2" ()
  in
  let gdk_map =
    StringMap.add "Class1" cr1 StringMap.empty |> StringMap.add "Class2" cr2
  in
  let cross_refs = StringMap.add "Gdk" gdk_map StringMap.empty in

  (* Get dependency namespaces *)
  let deps =
    Gir_gen_lib.Generate.C_stubs.get_dependency_namespaces
      (StringMap.fold (fun ns _ acc -> ns :: acc) cross_refs [])
  in

  (* Should contain Gdk exactly once *)
  Alcotest.(check int) "Should have exactly 1 dependency" 1 (List.length deps);
  match deps with
  | [] -> Alcotest.fail "Expected at least one dependency"
  | first :: _ -> Alcotest.(check string) "Dependency should be Gdk" "Gdk" first

(* Stage 4 Test: No dependency headers when cross_references is empty.
     When there are no cross-namespace types, no #include directives should be generated. *)
let test_no_includes_when_no_dependencies () =
  (* Create context with no cross-references *)
  let ctx = create_context_with_cross_references ~namespace:"Gtk" ~deps:[] in

  (* Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:[]
      ~gtk_enums:[] ~gtk_bitfields:[] ~records:[] ~interfaces:[] ()
  in

  (* Verify no cross-namespace dependency includes are present.
     We check specifically that no generated/<ns>_decls.h includes appear,
     since that is the form all dependency includes take. The core header
     (#include "../core/<ns>_core.h") is a structural include, not a dependency,
     so its presence is expected and not checked here. *)
  assert_local_include_not_exists header_content "generated/gdk_decls.h";
  assert_local_include_not_exists header_content "generated/gio_decls.h";
  assert_local_include_not_exists header_content "generated/gsk_decls.h"

let tests =
  [
    Alcotest.test_case
      "Header includes dependency headers for cross-namespace types (Stage 4)"
      `Quick test_header_includes_dependency_headers;
    Alcotest.test_case "Dependency headers sorted alphabetically (Stage 4)"
      `Quick test_dependency_headers_sorted_alphabetically;
    Alcotest.test_case "Include uses lowercase namespace (Stage 4)" `Quick
      test_include_uses_lowercase_namespace;
    Alcotest.test_case
      "get_dependency_namespaces extracts unique namespaces (Stage 4)" `Quick
      test_get_dependency_namespaces_extracts_unique_namespaces;
    Alcotest.test_case "No includes when no dependencies (Stage 4)" `Quick
      test_no_includes_when_no_dependencies;
  ]
