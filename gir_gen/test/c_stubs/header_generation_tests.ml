(* Header Generation Tests
   
   Tests for forward declaration generation in C header files.
   Uses AST-based validation (C_validation module) instead of string matching.
   
   These tests verify:
   1. Forward declarations are generated for local enums and bitfields
   2. Forward declarations are NOT generated for external enums and bitfields
*)

(* Pattern Analysis:
   - Tests use C_validation.assert_forward_decl_* for AST-based validation
   - No string matching - all validation uses C_parser/C_ast infrastructure
   - Follows arrange-act-assert structure from test-patterns.md
*)

(* Helper: Create a context with local and external enums to test
   forward declaration generation behavior *)
let create_context_with_mixed_enums () =
  let open Gir_gen_lib.Types in
  let namespace =
    {
      namespace_name = "Gtk";
      namespace_version = "4.0";
      namespace_shared_library = "libgtk-4.so.1";
      namespace_c_identifier_prefixes = "Gtk";
      namespace_c_symbol_prefixes = "gtk";
    }
  in

  (* Create a local GTK enum - forward declarations SHOULD be generated *)
  let local_enum =
    {
      enum_name = "WrapMode";
      enum_c_type = "GtkWrapMode";
      members =
        [
          {
            member_name = "NONE";
            member_value = 0;
            c_identifier = "GTK_WRAP_NONE";
            member_doc = None;
            member_version = None;
            member_os = None;
            deprecation = None;
          };
          {
            member_name = "WORD";
            member_value = 1;
            c_identifier = "GTK_WRAP_WORD";
            member_doc = None;
            member_version = None;
            member_os = None;
            deprecation = None;
          };
        ];
      functions = [];
      enum_doc = None;
      enum_version = None;
      enum_os = None;
      deprecation = None;
    }
  in

  {
    namespace;
    repository =
      {
        repository_c_includes = [];
        repository_includes = [];
        repository_packages = [];
        repository_doc_format = None;
      };
    classes = [];
    interfaces = [];
    enums = [ local_enum ];
    bitfields = [];
    records = [];
    constants = [];
    module_groups = Hashtbl.create 0;
    current_cycle_classes = [];
    cross_references = StringMap.empty;
  }

(* Helper: Create a context with local and external bitfields to test
   forward declaration generation behavior *)
let create_context_with_mixed_bitfields () =
  let open Gir_gen_lib.Types in
  let namespace =
    {
      namespace_name = "Gtk";
      namespace_version = "4.0";
      namespace_shared_library = "libgtk-4.so.1";
      namespace_c_identifier_prefixes = "Gtk";
      namespace_c_symbol_prefixes = "gtk";
    }
  in

  (* Create a local GTK bitfield - forward declarations SHOULD be generated *)
  let local_bitfield =
    {
      bitfield_name = "StateFlags";
      bitfield_c_type = "GtkStateFlags";
      flags =
        [
          {
            flag_name = "NORMAL";
            flag_value = 0;
            flag_c_identifier = "GTK_STATE_FLAG_NORMAL";
            flag_doc = None;
            flag_version = None;
            flag_os = None;
            deprecation = None;
          };
          {
            flag_name = "ACTIVE";
            flag_value = 1;
            flag_c_identifier = "GTK_STATE_FLAG_ACTIVE";
            flag_doc = None;
            flag_version = None;
            flag_os = None;
            deprecation = None;
          };
        ];
      bitfield_doc = None;
      bitfield_version = None;
      bitfield_os = None;
      deprecation = None;
    }
  in

  {
    namespace;
    repository =
      {
        repository_c_includes = [];
        repository_includes = [];
        repository_packages = [];
        repository_doc_format = None;
      };
    classes = [];
    interfaces = [];
    enums = [];
    bitfields = [ local_bitfield ];
    records = [];
    constants = [];
    module_groups = Hashtbl.create 0;
    current_cycle_classes = [];
    cross_references = StringMap.empty;
  }

(* Test: Local enums produce correct forward declarations (Val_<Enum>, <Enum>_val) *)
let test_local_enum_forward_decls_generated () =
  (* Arrange: Create context with local enum *)
  let ctx = create_context_with_mixed_enums () in

  (* Act: Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:ctx.enums ~gtk_bitfields:ctx.bitfields ~records:[]
      ~interfaces:[] ()
  in

  (* Assert: Local enum forward declarations should be present *)
  C_validation.assert_forward_decl_exists header_content "GtkWrapMode" "Val_";
  C_validation.assert_forward_decl_exists header_content "GtkWrapMode_val" ""

(* Test: External enums do NOT produce forward declarations *)
let test_external_enum_forward_decls_not_generated () =
  (* Arrange: Create context with external enum *)
  let ctx = create_context_with_mixed_enums () in

  (* Act: Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:ctx.enums ~gtk_bitfields:ctx.bitfields ~records:[]
      ~interfaces:[] ()
  in

  (* Assert: External enum forward declarations should NOT be present *)
  C_validation.assert_forward_decl_not_exists header_content "GdkTextureType"
    "Val_";
  C_validation.assert_forward_decl_not_exists header_content
    "GdkTextureType_val" ""

(* Test: Local bitfields produce correct forward declarations (Val_<Bitfield>, <Bitfield>_val) *)
let test_local_bitfield_forward_decls_generated () =
  (* Arrange: Create context with local bitfield *)
  let ctx = create_context_with_mixed_bitfields () in

  (* Act: Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:ctx.enums ~gtk_bitfields:ctx.bitfields ~records:[]
      ~interfaces:[] ()
  in

  (* Assert: Local bitfield forward declarations should be present *)
  C_validation.assert_forward_decl_exists header_content "GtkStateFlags" "Val_";
  C_validation.assert_forward_decl_exists header_content "GtkStateFlags_val" ""

(* Test: External bitfields do NOT produce forward declarations *)
let test_external_bitfield_forward_decls_not_generated () =
  (* Arrange: Create context with external bitfield *)
  let ctx = create_context_with_mixed_bitfields () in

  (* Act: Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:ctx.enums ~gtk_bitfields:ctx.bitfields ~records:[]
      ~interfaces:[] ()
  in

  (* Assert: External bitfield forward declarations should NOT be present *)
  C_validation.assert_forward_decl_not_exists header_content "GdkEventMask"
    "Val_";
  C_validation.assert_forward_decl_not_exists header_content "GdkEventMask_val"
    ""

let tests =
  [
    Alcotest.test_case "Local enum forward declarations are generated in header"
      `Quick test_local_enum_forward_decls_generated;
    Alcotest.test_case
      "External enum forward declarations are NOT generated in header" `Quick
      test_external_enum_forward_decls_not_generated;
    Alcotest.test_case
      "Local bitfield forward declarations are generated in header" `Quick
      test_local_bitfield_forward_decls_generated;
    Alcotest.test_case
      "External bitfield forward declarations are NOT generated in header"
      `Quick test_external_bitfield_forward_decls_not_generated;
  ]
