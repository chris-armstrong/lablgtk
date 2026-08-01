(* Header pipeline tests — multi-library header generation (Stage 8).
   Tier 2 — pipeline test (see Phase 1.5 of
   docs/plans/completed/test-suite-remediation.md): in-process, multi-module, no
   subprocess invocation of gir_gen.exe.

   Verifies that the complete cross-namespace header system works
   correctly when multiple libraries are generated:

   1. Header generation with cross-references works correctly
   2. Dependency headers are properly included
   3. C compilation patterns work with cross-namespace types
*)

open C_validation
open Gir_gen_lib.Types

(* ========================================================================= *)
(* Shared helpers *)
(* ========================================================================= *)

let make_cr ~cr_name ~cr_c_type cr_kind =
  Type_factory.make_cross_reference_entity ~cr_name
    ~cr_type:(Type_factory.make_cross_reference_type cr_kind)
    ~cr_c_type ()

let make_single_ns_ctx namespace_name cross_references =
  Type_factory.make_generation_context
    ~namespace:
      (Type_factory.make_gir_namespace ~namespace_name ~namespace_version:"4.0"
         ~namespace_shared_library:
           (Fmt.str "lib%s-4.so.1" (String.lowercase_ascii namespace_name))
         ~namespace_c_identifier_prefixes:namespace_name
         ~namespace_c_symbol_prefixes:(String.lowercase_ascii namespace_name)
         ())
    ~cross_references ()

let generate_header ctx =
  Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:[]
    ~gtk_enums:[] ~gtk_bitfields:[] ~records:[] ~interfaces:[] ()

(* ========================================================================= *)
(* Header Pipeline Test Cases *)
(* ========================================================================= *)

(* Stage 8 Test: Header generation with Gdk cross-references *)
let test_header_generation_with_gdk_cross_references () =
  let gdk_map =
    StringMap.add "Texture"
      (make_cr ~cr_name:"Texture" ~cr_c_type:"GdkTexture" `Class)
      StringMap.empty
    |> StringMap.add "Surface"
         (make_cr ~cr_name:"Surface" ~cr_c_type:"GdkSurface" `Class)
  in
  let cross_refs =
    Type_factory.make_cross_reference_map [ Helpers.make_ncr "Gdk" gdk_map ]
  in
  let ctx = make_single_ns_ctx "Gtk" cross_refs in
  let header_content = generate_header ctx in
  assert_header_guard_format header_content "_gtk_decls_h_";
  assert_local_include_exists header_content "generated/gdk_decls.h"

(* Stage 8 Test: Header generation with multiple dependencies *)
let test_header_generation_with_multiple_dependencies () =
  let gdk_map =
    StringMap.add "Texture"
      (make_cr ~cr_name:"Texture" ~cr_c_type:"GdkTexture" `Class)
      StringMap.empty
  in
  let gio_map =
    StringMap.add "File"
      (make_cr ~cr_name:"File" ~cr_c_type:"GFile" `Class)
      StringMap.empty
  in
  let cross_refs =
    Type_factory.make_cross_reference_map
      [ Helpers.make_ncr "Gdk" gdk_map; Helpers.make_ncr "Gio" gio_map ]
  in
  let ctx = make_single_ns_ctx "Gtk" cross_refs in
  let header_content = generate_header ctx in
  assert_local_include_exists header_content "generated/gdk_decls.h";
  assert_local_include_exists header_content "generated/gio_decls.h"

(* Stage 8 Test: Header with no dependencies has no includes *)
let test_header_no_dependencies_no_includes () =
  let ctx = make_single_ns_ctx "Gdk" StringMap.empty in
  let header_content = generate_header ctx in
  (* Verify no cross-namespace dependency includes are present.
     We check specifically that no generated/<ns>_decls.h includes appear,
     since that is the form all dependency includes take. The core header
     (#include "../core/<ns>_core.h") is a structural include, not a dependency,
     so its presence is expected and not checked here. *)
  assert_local_include_not_exists header_content "generated/gtk_decls.h";
  assert_local_include_not_exists header_content "generated/gdk_decls.h";
  assert_local_include_not_exists header_content "generated/gio_decls.h";
  assert_local_include_not_exists header_content "generated/gsk_decls.h"

(* Stage 8 Test: Base namespaces are filtered from dependencies *)
let test_base_namespaces_filtered () =
  let glib_map =
    StringMap.add "Object"
      (make_cr ~cr_name:"Object" ~cr_c_type:"GObject" `Class)
      StringMap.empty
  in
  let cross_refs =
    Type_factory.make_cross_reference_map [ Helpers.make_ncr "GLib" glib_map ]
  in
  let ctx = make_single_ns_ctx "Gtk" cross_refs in
  let header_content = generate_header ctx in
  assert_local_include_not_exists header_content "generated/glib_decls.h"

(* Stage 8 Test: Gsk with Gdk dependency header structure *)
let test_gsk_with_gdk_dependency () =
  let gdk_map =
    StringMap.add "Surface"
      (make_cr ~cr_name:"Renderer" ~cr_c_type:"GdkSurface" `Class)
      StringMap.empty
  in
  let cross_refs =
    Type_factory.make_cross_reference_map [ Helpers.make_ncr "Gdk" gdk_map ]
  in
  let ctx = make_single_ns_ctx "Gsk" cross_refs in
  let header_content = generate_header ctx in
  assert_header_guard_format header_content "_gsk_decls_h_";
  assert_local_include_exists header_content "generated/gdk_decls.h"

(* Stage 8 Test: Complete dependency chain Gtk -> Gsk -> Gdk *)
let test_complete_dependency_chain () =
  let gsk_map =
    StringMap.add "Renderer"
      (make_cr ~cr_name:"Renderer" ~cr_c_type:"GskRenderer" `Class)
      StringMap.empty
  in
  let gdk_map =
    StringMap.add "Texture"
      (make_cr ~cr_name:"Texture" ~cr_c_type:"GdkTexture" `Class)
      StringMap.empty
  in
  let cross_refs =
    Type_factory.make_cross_reference_map
      [ Helpers.make_ncr "Gsk" gsk_map; Helpers.make_ncr "Gdk" gdk_map ]
  in
  let ctx = make_single_ns_ctx "Gtk" cross_refs in
  let header_content = generate_header ctx in
  assert_local_include_exists header_content "generated/gdk_decls.h";
  assert_local_include_exists header_content "generated/gsk_decls.h"

(* ========================================================================= *)
(* Test Suite *)
(* ========================================================================= *)

let tests =
  [
    Alcotest.test_case "Header generation with Gdk cross-references (Stage 8)"
      `Quick test_header_generation_with_gdk_cross_references;
    Alcotest.test_case "Header generation with multiple dependencies (Stage 8)"
      `Quick test_header_generation_with_multiple_dependencies;
    Alcotest.test_case "Header with no dependencies has no includes (Stage 8)"
      `Quick test_header_no_dependencies_no_includes;
    Alcotest.test_case "Base namespaces filtered from dependencies (Stage 8)"
      `Quick test_base_namespaces_filtered;
    Alcotest.test_case "Gsk with Gdk dependency header structure (Stage 8)"
      `Quick test_gsk_with_gdk_dependency;
    Alcotest.test_case "Complete dependency chain Gtk -> Gsk -> Gdk (Stage 8)"
      `Quick test_complete_dependency_chain;
  ]
