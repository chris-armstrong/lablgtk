(* Cross-namespace tests - Stage 4: Generate Dependency Header Includes
   Part 2: Exclusion of base namespaces

   Tests that GLib, GModule, and GObject are NOT included as dependencies
   in generated header files. These are base libraries that don't need
   explicit header inclusion. *)

open C_validation

(* Helper: Create a context with cross-references to base namespaces *)
let create_context_with_base_namespace_refs () =
  let open Gir_gen_lib.Types in
  (* Create cross_references map including base namespaces *)
  let glib_cr =
    Type_factory.make_cross_reference_entity ~cr_name:"Object"
      ~cr_type:(Type_factory.make_cross_reference_type `Class)
      ~cr_c_type:"GObject" ()
  in
  let gobject_cr =
    Type_factory.make_cross_reference_entity ~cr_name:"Object"
      ~cr_type:(Type_factory.make_cross_reference_type `Class)
      ~cr_c_type:"GObject" ()
  in
  let gmodule_cr =
    Type_factory.make_cross_reference_entity ~cr_name:"Module"
      ~cr_type:(Type_factory.make_cross_reference_type `Class)
      ~cr_c_type:"GModule" ()
  in
  let gdk_cr =
    Type_factory.make_cross_reference_entity ~cr_name:"Texture"
      ~cr_type:(Type_factory.make_cross_reference_type `Class)
      ~cr_c_type:"GdkTexture" ()
  in

  let glib_map = StringMap.add "Object" glib_cr StringMap.empty in
  let gobject_map = StringMap.add "Object" gobject_cr StringMap.empty in
  let gmodule_map = StringMap.add "Module" gmodule_cr StringMap.empty in
  let gdk_map = StringMap.add "Texture" gdk_cr StringMap.empty in

  let cross_references =
    StringMap.empty
    |> StringMap.add "GLib" (snd (Helpers.make_ncr "GLib" glib_map))
    |> StringMap.add "GObject" (snd (Helpers.make_ncr "GObject" gobject_map))
    |> StringMap.add "GModule" (snd (Helpers.make_ncr "GModule" gmodule_map))
    |> StringMap.add "Gdk" (snd (Helpers.make_ncr "Gdk" gdk_map))
  in

  let ns =
    Type_factory.make_gir_namespace ~namespace_name:"Gtk"
      ~namespace_version:"4.0" ~namespace_shared_library:"libgtk-4.so.1"
      ~namespace_c_identifier_prefixes:"Gtk" ~namespace_c_symbol_prefixes:"gtk"
      ()
  in
  Type_factory.make_generation_context ~namespace:ns
    ~repository:(Type_factory.make_gir_repository ())
    ~cross_references ()

(* Stage 4 Test: GLib is NOT included as a dependency.
   GLib is a base library that doesn't need explicit header inclusion. *)
let test_glib_not_included_as_dependency () =
  let ctx = create_context_with_base_namespace_refs () in

  (* Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:ctx.enums ~gtk_bitfields:ctx.bitfields ~records:[]
      ~interfaces:[] ()
  in

  Helpers.log_generated_c_code "gtk_decls.h (Stage 4 exclusion test)"
    header_content;

  (* Verify GLib header is NOT included using AST-based validation *)
  assert_local_include_not_exists header_content "generated/glib_decls.h"

(* Stage 4 Test: GModule is NOT included as a dependency.
   GModule is a base library that doesn't need explicit header inclusion. *)
let test_gmodule_not_included_as_dependency () =
  let ctx = create_context_with_base_namespace_refs () in

  (* Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:ctx.enums ~gtk_bitfields:ctx.bitfields ~records:[]
      ~interfaces:[] ()
  in

  (* Verify GModule header is NOT included using AST-based validation *)
  assert_local_include_not_exists header_content "generated/gmodule_decls.h"

(* Stage 4 Test: GObject is NOT included as a dependency.
   GObject is a base library that doesn't need explicit header inclusion. *)
let test_gobject_not_included_as_dependency () =
  let ctx = create_context_with_base_namespace_refs () in

  (* Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:ctx.enums ~gtk_bitfields:ctx.bitfields ~records:[]
      ~interfaces:[] ()
  in

  (* Verify GObject header is NOT included using AST-based validation *)
  assert_local_include_not_exists header_content "generated/gobject_decls.h"

(* Stage 4 Test: Non-base namespaces ARE included.
   Gdk should be included even though GLib/GObject/GModule are excluded. *)
let test_non_base_namespaces_are_included () =
  let ctx = create_context_with_base_namespace_refs () in

  (* Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:ctx.enums ~gtk_bitfields:ctx.bitfields ~records:[]
      ~interfaces:[] ()
  in

  (* Verify Gdk header IS included using AST-based validation *)
  assert_local_include_exists header_content "generated/gdk_decls.h"

(* Stage 4 Test: Helper function filters base namespaces correctly.
   get_dependency_namespaces should exclude GLib, GModule, GObject. *)
let test_get_dependency_namespaces_filters_base_namespaces () =
  let open Gir_gen_lib.Types in
  (* Create cross_references with base and non-base namespaces *)
  let dummy_cr =
    {
      cr_name = "Test";
      cr_type = Crt_Class { parent = None; implements = [] };
      cr_c_type = "Test";
    }
  in
  let dummy_map = StringMap.add "Test" dummy_cr StringMap.empty in

  let cross_refs =
    StringMap.empty
    |> StringMap.add "GLib" (snd (Helpers.make_ncr "GLib" dummy_map))
    |> StringMap.add "GObject" (snd (Helpers.make_ncr "GObject" dummy_map))
    |> StringMap.add "GModule" (snd (Helpers.make_ncr "GModule" dummy_map))
    |> StringMap.add "Gdk" (snd (Helpers.make_ncr "Gdk" dummy_map))
    |> StringMap.add "Gio" (snd (Helpers.make_ncr "Gio" dummy_map))
  in

  (* Get dependency namespaces *)
  let deps =
    Gir_gen_lib.Generate.C_stubs.get_dependency_namespaces cross_refs
  in

  (* Should contain Gdk and Gio but NOT GLib, GObject, GModule *)
  Alcotest.(check int) "Should have exactly 2 dependencies" 2 (List.length deps);
  Alcotest.(check bool) "Should contain Gdk" true (List.mem "Gdk" deps);
  Alcotest.(check bool) "Should contain Gio" true (List.mem "Gio" deps);
  Alcotest.(check bool) "Should NOT contain GLib" false (List.mem "GLib" deps);
  Alcotest.(check bool)
    "Should NOT contain GObject" false (List.mem "GObject" deps);
  Alcotest.(check bool)
    "Should NOT contain GModule" false (List.mem "GModule" deps)

let tests =
  [
    Alcotest.test_case "GLib not included as dependency (Stage 4)" `Quick
      test_glib_not_included_as_dependency;
    Alcotest.test_case "GModule not included as dependency (Stage 4)" `Quick
      test_gmodule_not_included_as_dependency;
    Alcotest.test_case "GObject not included as dependency (Stage 4)" `Quick
      test_gobject_not_included_as_dependency;
    Alcotest.test_case "Non-base namespaces are included (Stage 4)" `Quick
      test_non_base_namespaces_are_included;
    Alcotest.test_case
      "get_dependency_namespaces filters base namespaces (Stage 4)" `Quick
      test_get_dependency_namespaces_filters_base_namespaces;
  ]
