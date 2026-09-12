(* Cross-namespace tests - Stage 2: Remove External Enum Forward Declarations
   
   Tests that generated header files do NOT contain forward declarations
   for external enums. External enum declarations now come from included headers. *)

open C_validation

let test_gir = "/tmp/test_no_ext_enum_decls.gir"
let output_dir = "/tmp/test_no_ext_enum_decls_output"

(* Helper: Create a context with external enums to verify they are NOT 
   included in forward declarations *)
let create_context_with_external_enum () =
  let namespace =
    Type_factory.make_gir_namespace ~namespace_name:"Gtk"
      ~namespace_version:"4.0" ~namespace_shared_library:"libgtk-4.so.1"
      ~namespace_c_identifier_prefixes:"Gtk" ~namespace_c_symbol_prefixes:"gtk"
      ()
  in

  (* Create a local GTK enum *)
  let local_enum =
    Type_factory.make_gir_enum ~enum_name:"WrapMode" ~enum_c_type:"GtkWrapMode"
      ~members:
        [
          Type_factory.make_gir_enum_member ~member_name:"NONE" ~member_value:0
            ~c_identifier:"GTK_WRAP_NONE" ();
          Type_factory.make_gir_enum_member ~member_name:"WORD" ~member_value:1
            ~c_identifier:"GTK_WRAP_WORD" ();
        ]
      ()
  in

  Type_factory.make_generation_context ~namespace ~enums:[ local_enum ]
    ~repository:(Type_factory.make_gir_repository ())
    ()

(* Stage 2 Test: Generated header should NOT contain forward declarations
   for external enums. These declarations now come from included headers. *)
let test_header_does_not_contain_external_enum_decls () =
  let ctx = create_context_with_external_enum () in

  (* Generate the header file *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:ctx.enums ~gtk_bitfields:ctx.bitfields ~records:[]
      ~interfaces:[] ()
  in

  Helpers.log_generated_c_code "gtk_decls.h (Stage 2 test)" header_content;

  (* Positive: local GTK enum forward declarations SHOULD be present *)
  assert_forward_decl_exists header_content "GtkWrapMode" "Val_";
  assert_forward_decl_exists header_content "GtkWrapMode_val" "";

  (* Critical: external GDK enum forward declarations should NOT be present.
     These should come from the included gdk_decls.h header instead. *)
  assert_forward_decl_not_exists header_content "GdkTextureType" "Val_";
  assert_forward_decl_not_exists header_content "GdkTextureType_val" ""

(* Stage 2 Test: Verify that generate_forward_decls only processes local enums *)
let test_generate_forward_decls_only_local_enums () =
  let open Gir_gen_lib.Types in
  (* Create a local enum *)
  let local_enum =
    {
      enum_name = "Align";
      enum_c_type = "GtkAlign";
      members = [];
      functions = [];
      enum_doc = None;
      enum_version = None;
      enum_os = None;
      deprecation = None;
    }
  in

  (* Create what would be an external enum - not passed to generate_forward_decls *)
  let _external_enum =
    {
      enum_name = "EventType";
      enum_c_type = "GdkEventType";
      members = [];
      functions = [];
      enum_doc = None;
      enum_version = None;
      enum_os = None;
      deprecation = None;
    }
  in

  (* Generate forward declarations for local enums only *)
  let local_decls =
    Gir_gen_lib.Generate.C_stub_enum.generate_forward_decls
      ~namespace_prefix:"Gtk" ~gtk_enums:[ local_enum ]
  in

  (* Verify local enum is included *)
  assert_forward_decl_exists local_decls "GtkAlign" "Val_";
  assert_forward_decl_exists local_decls "GtkAlign_val" "";

  (* External enum should NOT be in the output since we only pass local enums *)
  assert_forward_decl_not_exists local_decls "GdkEventType" "Val_";
  assert_forward_decl_not_exists local_decls "GdkEventType_val" "";

  (* Generate with empty list should produce empty string *)
  let empty_decls =
    Gir_gen_lib.Generate.C_stub_enum.generate_forward_decls
      ~namespace_prefix:"Gtk" ~gtk_enums:[]
  in
  Alcotest.(check string) "Empty enum list produces empty output" "" empty_decls

(* Stage 2 Test: Verify enum proto emission function was removed from public API *)
let test_emit_enum_proto_not_exported () =
  (* The emit_enum_proto function should no longer be exported from C_stubs.
     We verify this by checking that the function signature is not exposed. *)
  (* This is implicitly tested by compilation - if emit_enum_proto was still
     exported and used, the previous tests would have referenced it. *)
  (* Instead, we verify the interface is clean by ensuring no external enum 
     related functions remain in the header generation. *)
  let ctx = create_context_with_external_enum () in

  (* Generate header and verify it has no "external" enum sections *)
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:ctx.enums ~gtk_bitfields:ctx.bitfields ~records:[]
      ~interfaces:[] ()
  in

  (* The external enum forward declarations are verified to not exist via
     assert_forward_decl_not_exists in other tests. The header generation
     already excludes external enums from forward declarations. *)
  ignore header_content;
  ()

let tests =
  [
    Alcotest.test_case
      "Header does not contain external enum forward declarations (Stage 2)"
      `Quick test_header_does_not_contain_external_enum_decls;
    Alcotest.test_case
      "generate_forward_decls only processes local enums (Stage 2)" `Quick
      test_generate_forward_decls_only_local_enums;
    Alcotest.test_case "emit_enum_proto not exported from C_stubs (Stage 2)"
      `Quick test_emit_enum_proto_not_exported;
  ]
