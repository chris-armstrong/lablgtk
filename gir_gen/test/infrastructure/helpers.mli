(* Shared test helpers for the GIR generator test suite *)

(** {1 Alcotest Assertion Helpers} *)

val string_contains : string -> string -> bool
(** [string_contains s sub] returns [true] iff [sub] appears as a substring of
    [s]. Used for checks the C parser cannot model, e.g. preprocessor directives
    or loop-body structure. *)

val assert_true : string -> bool -> unit
(** [assert_true msg cond] fails the current test with [msg] unless [cond] is
    [true]. *)

val expect_some : string -> 'a option -> ('a -> 'b) -> 'b
(** [expect_some label opt f] applies [f] to the contents of [opt] when it is
    [Some], or fails the test with [label] when it is [None]. *)

val assert_some : string -> 'a option -> unit
(** [assert_some label opt] asserts that [opt] is [Some _] without inspecting
    the wrapped value. *)

val assert_some_value : string -> 'a option -> 'a
(** [assert_some_value label opt] returns the contents of [opt], failing the
    test with [label] when it is [None]. *)

val assert_head : string -> 'a list -> 'a
(** [assert_head label lst] returns the first element of [lst], failing the test
    with [label] when [lst] is empty. *)

(** {1 File Utilities} *)

val file_exists : string -> bool
(** [file_exists path] returns [true] iff [path] exists on disk. *)

val read_file : string -> string
(** [read_file filename] returns the full contents of [filename]. *)

val generated_dir : string -> string
(** [generated_dir output_dir] returns the ["generated"] subdirectory of
    [output_dir]. *)

val stub_c_file : string -> string -> string
(** [stub_c_file output_dir class_name] returns the path of the generated C stub
    file for [class_name] under [output_dir]. *)

val g_wrapper_file : string -> string -> string
(** [g_wrapper_file output_dir class_name] returns the path of the generated
    [g<class_name>.ml] wrapper file under [output_dir]. *)

val mli_file : string -> string -> string
(** [mli_file output_dir module_name] returns the path of the generated
    [<module_name>.mli] file under [output_dir]. *)

val enum_file : string -> string
(** [enum_file output_dir] returns the path of the generated [gtk_enums.mli]
    file under [output_dir]. *)

val enum_ml_file : string -> string
(** [enum_ml_file output_dir] returns the path of the generated [gtk_enums.ml]
    file under [output_dir]. *)

val enum_c_file : string -> string
(** [enum_c_file output_dir] returns the path of the generated
    [ml_gtk_enums_gen.c] file under [output_dir]. *)

(** {1 GIR XML Generation} *)

val wrap_namespace :
  ?namespace_name:string ->
  ?version:string ->
  ?shared_library:string ->
  ?c_prefix:string ->
  ?symbol_prefix:string ->
  string ->
  string
(** [wrap_namespace ?namespace_name ?version ?shared_library ?c_prefix
     ?symbol_prefix content] wraps [content] in standard GIR
    repository/namespace XML boilerplate. Defaults to a Gtk 4.0 namespace. *)

val create_gir_file : string -> string -> unit
(** [create_gir_file filename content] writes [content] to [filename]. *)

(** {1 Test Execution Helpers} *)

val get_tools_dir : unit -> string
(** [get_tools_dir ()] returns the directory containing the built [gir_gen.exe]
    binary. *)

val run_gir_gen : ?filter_file:string -> string -> string -> int
(** [run_gir_gen ?filter_file gir_file output_dir] runs [gir_gen.exe generate]
    on [gir_file] into [output_dir], optionally restricted by [filter_file].
    Fails the test with a stderr preview when the command exits non-zero.
    @return the exit code of the command. *)

val ensure_output_dir : string -> unit
(** [ensure_output_dir dir] creates [dir] if it does not already exist. *)

val gir_data_dir : unit -> string
(** [gir_data_dir ()] returns the path to the bundled GIR data directory, read
    from the [GIR_DATA_DIR] environment variable set by the dune test stanza.
    Fails if the variable is not set. *)

(** {1 Test Context Creation} *)

val create_test_context : unit -> Gir_gen_lib.Types.generation_context
(** [create_test_context ()] builds a minimal [Gtk] generation context with the
    well-known classes, enum and records used by the test suite. *)

val create_test_context_with_hierarchy :
  unit -> Gir_gen_lib.Types.generation_context
(** [create_test_context_with_hierarchy ()] is an alias for
    [create_test_context ()] kept for call sites that exercise class
    hierarchies. *)

(** {1 C Code Inspection Helpers} *)

val make_ncr :
  ?packages:string list ->
  ?includes:string list ->
  ?c_includes:string list ->
  string ->
  Gir_gen_lib.Types.cross_reference_entity Gir_gen_lib.Types.StringMap.t ->
  string * Gir_gen_lib.Types.generation_context_namespace_cross_references
(** [make_ncr ?packages ?includes ?c_includes namespace_name entities] builds a
    cross-reference namespace entry for [namespace_name] from an entity map.
    @return
      [(namespace_name, ncr)] pairs suitable for
      [Type_factory.make_cross_reference_map]. *)

val log_generated_c_code : string -> string -> unit
(** [log_generated_c_code test_name c_code] prints [c_code] to stdout under a
    [test_name] banner, for debugging generated C. *)

(** {1 C Stub Generation Helpers} *)

val generate_and_find_c_method :
  ?ctx:Gir_gen_lib.Types.generation_context ->
  ?log_label:string ->
  c_type:string ->
  class_name:string ->
  Gir_gen_lib.Types.gir_method ->
  C_ast.c_function
(** [generate_and_find_c_method ?ctx ?log_label ~c_type ~class_name meth]
    generates the C stub for [meth] against [c_type]/[class_name], parses the
    result, and returns the primary generated function (the one named
    ["ml_" ^ meth.c_identifier]). Fails the test if the function is not found.
    Pass [~log_label] to echo the generated C to stdout. *)

(** {1 Shared GIR XML Snippets} *)

val eventcontroller_key_class_xml : string
(** Minimal [EventControllerKey] class stub used as a namespace filler in
    integration tests that need at least one class in the GIR namespace. *)

(** {1 Integration Test Harness} *)

val run_integration_test :
  gir_content:string ->
  class_names:string list ->
  test_name:string ->
  unit ->
  string
(** [run_integration_test ~gir_content ~class_names ~test_name ()] runs
    [gir_gen] on [gir_content] and asserts it exits successfully. When
    [class_names] is non-empty a filter file is created and passed to [gir_gen].
    @return the output directory path. *)
