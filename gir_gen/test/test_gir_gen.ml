(* GIR Generator Unit and Pipeline Test Suite
 *
 * Entry point for unit and pipeline tests only — no gir_gen.exe subprocess.
 * Integration tests (spawning gir_gen.exe) live in test_gir_gen_integration.ml.
 *)

let () =
  Alcotest.run "GIR Generator"
    [
      (* Layer 0 — C Stub Generation *)
      ("C Stubs", Generation_tests.tests);
      ("Header Naming", Header_naming_tests.tests);
      ("Header Generation", Header_generation_tests.tests);
      ("C Validation", C_validation_tests.tests);
      ("Nullable", Nullable_tests.tests);
      ("Error Handling", Error_handling_tests.tests);
      ("Out Params", Out_params_tests.tests);
      ("Arrays", Array_tests.tests);
      ("Record Macros", Record_macro_tests.tests);
      ("GList Conversion", List_conv_tests.tests);
      ("Type Conversion", Type_conversion_tests.tests);
      ("C Stub Version Guards", C_stub_version_guard_tests.test_suite);
      (* Layer 1 — ML Generation *)
      ("Type Definitions (ML)", Type_definition_tests.tests);
      ("External Declarations (ML)", External_decl_tests.tests);
      ("Signatures (ML)", Signature_tests.tests);
      (* Constants generation (pure unit) *)
      ("Constant Code", Constant_code_tests.tests);
      (* Layer 2 — Class Generation (pure unit/pipeline) *)
      ("Layer2 Method Wrappers", Method_wrapper_tests.tests);
      ("Constructor Wrappers", Constructor_wrapper_tests.tests);
      ("Signal Wrappers", Signal_wrapper_tests.tests);
      ("Signal Marshaller", Signal_marshaller_tests.tests);
      (* Interface Parsing (pure unit — no gir_gen.exe) *)
      ("Interface Parsing", Parsing_tests.test_suite);
      ("Doc Parsing (M3)", Doc_parsing_tests.test_suite);
      (* Cross-namespace (pure unit/pipeline) *)
      ("C Stub Header Include (Stage 5)", C_stub_include_tests.tests);
      ("classify_type + Array Resolution (Phase 6)", Classify_type_tests.tests);
      ("Dependency Includes (Stage 4)", Dependency_includes_tests.tests);
      ("Dependency Exclusion (Stage 4)", Dependency_exclusion_tests.tests);
      ("No External Enum Decls (Stage 2)", No_external_enum_decls_tests.tests);
      ( "No External Bitfield Decls (Stage 3)",
        No_external_bitfield_decls_tests.tests );
      ("Header Pipeline Tests (Stage 8)", Header_pipeline_tests.tests);
      ("Compilation Tests (Stage 8)", Compilation_tests.tests);
      (* Constant cross-namespace references (pure unit) *)
      ("Constant References", Constant_references_tests.tests);
      (* Override system *)
      ("Override Types", Types_tests.test_suite);
      ("Override Parser", Parser_tests.test_suite);
      ("Override Parser Roundtrip", Parser_tests.test_suite_roundtrip);
      ("Override Apply", Apply_tests.test_suite);
      ("Override Extractor", Extractor_tests.test_suite);
      ("Override Apply (parsed GIR)", Apply_with_parsed_gir_tests.test_suite);
      ("Override Pipeline", Pipeline_tests.test_suite);
      ("Version Guard", Version_guard_tests.test_suite);
      ("Enum Member Version Guards", Enum_member_version_tests.test_suite);
    ]
