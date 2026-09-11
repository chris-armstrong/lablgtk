(* Shared test helpers for GIR generator test suite *)

(* ========================================================================= *)
(* Alcotest Assertion Helpers *)
(* ========================================================================= *)

(** [string_contains s sub] returns [true] iff [sub] appears as a substring of
    [s]. Only use when AST-based validation is not available — e.g. checking C
    preprocessor directives ([#if]/[#endif]) or loop-body structure that the
    C_parser does not model. Always add an inline comment explaining why. *)
let string_contains s sub =
  try
    ignore (Re.Str.search_forward (Re.Str.regexp_string sub) s 0);
    true
  with Not_found -> false

let assert_true msg cond = Alcotest.(check bool) msg true cond

(** [expect_some label opt f] calls [f] with the contents of [opt] when it is
    [Some], or fails the test with [label] when it is [None]. Replaces the
    common [match ... with Some x -> ... | None -> Alcotest.fail label]
    boilerplate. *)
let expect_some label opt f =
  match opt with Some x -> f x | None -> Alcotest.fail label

(** [assert_some label opt] asserts that [opt] is [Some _] without inspecting
    the wrapped value. Shorthand for existence checks. *)
let assert_some label opt =
  match opt with Some _ -> () | None -> Alcotest.fail label

(** [assert_some_value label opt] returns the contents of [opt], failing the
    test with [label] when it is [None]. Replaces [Option.get opt] in tests
    where the value is expected to be present, with a labelled failure instead
    of an [Assert_failure]. *)
let assert_some_value label opt =
  match opt with Some x -> x | None -> Alcotest.fail label

(** [assert_head label lst] returns the first element of [lst], failing the test
    with [label] when [lst] is empty. Replaces [List.hd lst] in tests with a
    labelled failure instead of [Failure]. *)
let assert_head label = function x :: _ -> x | [] -> Alcotest.fail label

(* ========================================================================= *)
(* File Utilities *)
(* ========================================================================= *)

let file_exists path =
  try
    let _ = Unix.stat path in
    true
  with Unix.Unix_error _ -> false

let delete_if_exists path = try Unix.unlink path with Unix.Unix_error _ -> ()

let read_file filename =
  let ic = open_in filename in
  let len = in_channel_length ic in
  let buf = Bytes.create len in
  really_input ic buf 0 len;
  close_in ic;
  Bytes.to_string buf

let generated_dir output_dir = Filename.concat output_dir "generated"

let stub_c_file output_dir class_name =
  Filename.concat (generated_dir output_dir)
    (Fmt.str "ml_%s_gen.c" (Gir_gen_lib.Utils.to_snake_case class_name))

let g_wrapper_file output_dir class_name =
  Filename.concat (generated_dir output_dir)
    (Fmt.str "g%s.ml" (Gir_gen_lib.Utils.module_name_of_class class_name))

let ml_file output_dir module_name =
  Filename.concat (generated_dir output_dir) (module_name ^ ".ml")

let mli_file output_dir module_name =
  Filename.concat (generated_dir output_dir) (module_name ^ ".mli")

let enum_file output_dir =
  Filename.concat (generated_dir output_dir) "gtk_enums.mli"

let enum_ml_file output_dir =
  Filename.concat (generated_dir output_dir) "gtk_enums.ml"

let enum_c_file output_dir =
  Filename.concat (generated_dir output_dir) "ml_gtk_enums_gen.c"

(* ========================================================================= *)
(* GIR XML Generation *)
(* ========================================================================= *)

(* Wrap namespace content in standard GIR repository/namespace XML boilerplate *)
let wrap_namespace ?(namespace_name = "Gtk") ?(version = "1.0")
    ?(shared_library = "libgtk-4.so.1") ?(c_prefix = "Gtk")
    ?(symbol_prefix = "gtk") content =
  Fmt.str
    {|<?xml version="1.0"?>
<repository version="1.2"
            xmlns="http://www.gtk.org/introspection/core/1.0"
            xmlns:c="http://www.gtk.org/introspection/c/1.0"
            xmlns:glib="http://www.gtk.org/introspection/glib/1.0">
  <namespace name="%s" version="%s" shared-library="%s" c:identifier-prefixes="%s" c:symbol-prefixes="%s">
%s
  </namespace>
</repository>
|}
    namespace_name version shared_library c_prefix symbol_prefix content

(* Create a GIR file from content (will be wrapped with repository/namespace) *)
let create_gir_file filename content =
  let oc = open_out filename in
  output_string oc content;
  close_out oc

(* Create a filter file with class names *)
let create_filter_file filename class_names =
  let oc = open_out filename in
  output_string oc "# Test filter\n";
  List.iter (fun name -> output_string oc (name ^ "\n")) class_names;
  close_out oc

(* ========================================================================= *)
(* Test Execution Helpers *)
(* ========================================================================= *)

let get_tools_dir () =
  (* When run with 'dune runtest', argv[0] might just be the basename.
     In that case, use the current working directory to find the tools dir. *)
  let test_dir = Filename.dirname Sys.argv.(0) in

  (* If argv[0] is just a basename (dirname is "."), use cwd instead *)
  if test_dir = "." then
    (* We're in _build/default/src/tools/test_gir_gen, go up one level *)
    let cwd = Sys.getcwd () in
    Filename.dirname cwd
  else
    (* We have a full path, go up one level from the test directory *)
    Filename.dirname test_dir

(* Command execution result with captured output *)
type command_result = {
  exit_code : int;
  stdout : string;
  stderr : string;
  log_file : string option;
}

(* Execute command with captured stdout/stderr *)
let run_command_with_output ?(log_dir = None) cmd =
  let tmp_stdout = Filename.temp_file "test_stdout_" ".txt" in
  let tmp_stderr = Filename.temp_file "test_stderr_" ".txt" in

  (* Redirect stdout and stderr to temp files *)
  let cmd_with_redirect = Fmt.str "%s > %s 2> %s" cmd tmp_stdout tmp_stderr in

  let exit_code = Sys.command cmd_with_redirect in
  let stdout = read_file tmp_stdout in
  let stderr = read_file tmp_stderr in

  (* Optionally save to permanent log file *)
  let log_file =
    match log_dir with
    | Some dir ->
        (* Ensure log directory exists *)
        (try Unix.mkdir dir 0o755 with Unix.Unix_error _ -> ());
        let timestamp = string_of_float (Unix.time ()) in
        let prefix = Fmt.str "test_%s_" timestamp in
        let log_path = Filename.temp_file ~temp_dir:dir prefix ".log" in
        let oc = open_out log_path in
        output_string oc (Fmt.str "Command: %s\n\n" cmd);
        output_string oc (Fmt.str "Exit code: %d\n\n" exit_code);
        output_string oc (Fmt.str "=== STDOUT ===\n%s\n\n" stdout);
        output_string oc (Fmt.str "=== STDERR ===\n%s\n" stderr);
        close_out oc;
        Some log_path
    | None -> None
  in

  (* Clean up temp files *)
  Unix.unlink tmp_stdout;
  Unix.unlink tmp_stderr;

  { exit_code; stdout; stderr; log_file }

let run_gir_gen ?filter_file gir_file output_dir =
  let tools_dir = get_tools_dir () in
  let filter_arg =
    match filter_file with Some f -> Fmt.str "-f %s " f | None -> ""
  in
  let cmd =
    Fmt.str "%s/bin/gir_gen.exe generate %s%s %s" tools_dir filter_arg gir_file
      output_dir
  in
  let result =
    run_command_with_output ~log_dir:(Some "/tmp/gir_gen_test_logs") cmd
  in

  if result.exit_code <> 0 then begin
    (* Show preview of stderr (first 20 lines) in test output *)
    let stderr_lines = String.split_on_char '\n' result.stderr in
    let preview_lines =
      let rec take n lst =
        match (n, lst) with
        | 0, _ | _, [] -> []
        | n, x :: xs -> x :: take (n - 1) xs
      in
      take 20 stderr_lines
    in
    let error_preview = String.concat "\n" preview_lines in
    let log_info =
      match result.log_file with
      | Some path -> Fmt.str "\n\nFull log saved to: %s" path
      | None -> ""
    in
    Alcotest.fail
      (Fmt.str "gir_gen command failed (exit code %d)\n\nStderr preview:\n%s%s"
         result.exit_code error_preview log_info)
  end;

  result.exit_code

let ensure_output_dir dir =
  try Unix.mkdir dir 0o755 with Unix.Unix_error _ -> ()

(** Return the path to the bundled GIR data directory. Reads [GIR_DATA_DIR]
    environment variable (set by the dune test stanza). Fails immediately if the
    variable is not set. *)
let gir_data_dir () =
  match Sys.getenv_opt "GIR_DATA_DIR" with
  | Some d -> d
  | None -> failwith "GIR_DATA_DIR environment variable is not set"

(* ========================================================================= *)
(* Test Context Creation *)
(* ========================================================================= *)

(* Create a minimal generation context for testing C stub generation *)
let create_test_context () =
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

  let repository =
    {
      repository_c_includes = [];
      repository_includes = [];
      repository_packages = [];
    }
  in

  (* Add Widget class to context so type mappings work *)
  let widget_class =
    {
      class_name = "Widget";
      c_type = "GtkWidget";
      glib_get_type = Some "gtk_widget_get_type";
      parent = None;
      implements = [];
      introspectable = true;
      constructors = [];
      methods = [];
      properties = [];
      signals = [];
      class_doc = None;
      version = None;
      os = None;
    }
  in

  (* Add GInetAddress class for GPtrArray tests *)
  let inet_address_class =
    {
      class_name = "InetAddress";
      c_type = "GInetAddress";
      glib_get_type = None;
      parent = None;
      implements = [];
      introspectable = true;
      constructors = [];
      methods = [];
      properties = [];
      signals = [];
      class_doc = None;
      version = None;
      os = None;
    }
  in

  (* Add GTlsCertificate class for GPtrArray tests *)
  let tls_certificate_class =
    {
      class_name = "TlsCertificate";
      c_type = "GTlsCertificate";
      glib_get_type = None;
      parent = None;
      implements = [];
      introspectable = true;
      constructors = [];
      methods = [];
      properties = [];
      signals = [];
      class_doc = None;
      version = None;
      os = None;
    }
  in

  (* Add GdkEvent class for GPtrArray tests *)
  let gdk_event_class =
    {
      class_name = "Event";
      c_type = "GdkEvent";
      glib_get_type = None;
      parent = None;
      implements = [];
      introspectable = true;
      constructors = [];
      methods = [];
      properties = [];
      signals = [];
      class_doc = None;
      version = None;
      os = None;
    }
  in

  (* Add TextDirection enum to context *)
  let text_direction_enum =
    {
      enum_name = "TextDirection";
      enum_c_type = "GtkTextDirection";
      members = [];
      enum_doc = None;
      enum_version = None;
      enum_os = None;
      functions = [];
    }
  in

  (* Add GdkTimeCoord record for GPtrArray tests *)
  let gdk_time_coord_record =
    {
      record_name = "GdkTimeCoord";
      c_type = "GdkTimeCoord";
      glib_type_name = None;
      glib_get_type = None;
      introspectable = true;
      opaque = false;
      disguised = false;
      c_symbol_prefix = None;
      is_gtype_struct_for = None;
      fields = [];
      constructors = [];
      methods = [];
      functions = [];
      record_doc = None;
      version = None;
      os = None;
    }
  in

  (* Add GtkBuildableParseContext record for GPtrArray tests *)
  let buildable_parse_context_record =
    {
      record_name = "GtkBuildableParseContext";
      c_type = "GtkBuildableParseContext";
      glib_type_name = None;
      glib_get_type = None;
      introspectable = true;
      opaque = true;
      disguised = false;
      c_symbol_prefix = None;
      is_gtype_struct_for = None;
      fields = [];
      constructors = [];
      methods = [];
      functions = [];
      record_doc = None;
      version = None;
      os = None;
    }
  in

  {
    namespace;
    repository;
    classes =
      [
        widget_class; inet_address_class; tls_certificate_class; gdk_event_class;
      ];
    interfaces = [];
    enums = [ text_direction_enum ];
    bitfields = [];
    records = [ gdk_time_coord_record; buildable_parse_context_record ];
    constants = [];
    module_groups = Hashtbl.create 0;
    current_cycle_classes = [];
    cross_references = StringMap.empty;
  }

let create_test_context_with_hierarchy () = create_test_context ()

(* ========================================================================= *)
(* C Code Inspection Helpers *)
(* ========================================================================= *)

(* Create a cross-reference namespace entry from an entity map *)
let make_ncr ?(packages = []) ?(includes = []) ?(c_includes = []) namespace_name
    entities =
  let open Gir_gen_lib.Types in
  ( namespace_name,
    {
      ncr_namespace_name = namespace_name;
      ncr_namespace_packages = packages;
      ncr_namespace_includes = includes;
      ncr_namespace_c_includes = c_includes;
      ncr_entities = entities;
    } )

(* Log generated C code to test output for debugging *)
let log_generated_c_code test_name c_code =
  Fmt.pr "\n========================================\n";
  Fmt.pr "Generated C Code for: %s\n" test_name;
  Fmt.pr "========================================\n";
  Fmt.pr "%s\n" c_code;
  Fmt.pr "========================================\n\n"

(* ========================================================================= *)
(* C Stub Generation Helpers *)
(* ========================================================================= *)

(** [generate_and_find_c_method ?ctx ?log_label ~c_type ~class_name meth]
    generates the C stub for [meth] against [c_type]/[class_name], parses the
    result, and returns the primary generated function (the one whose name is
    ["ml_" ^ meth.c_identifier]). Fails the test if the function is not found in
    the output. Pass [~log_label] to echo the generated C to stdout for
    debugging. Pass [~ctx] to override the default test context. *)
let generate_and_find_c_method ?(ctx = create_test_context ()) ?log_label
    ~c_type ~class_name (meth : Gir_gen_lib.Types.gir_method) =
  let c_code =
    Gir_gen_lib.Generate.C_stub_method.generate_c_method ~ctx ~c_type meth
      class_name
  in
  Option.iter (fun label -> log_generated_c_code label c_code) log_label;
  let functions = C_parser.parse_c_code c_code in
  let fn_name = "ml_" ^ meth.c_identifier in
  match
    List.find_opt
      (fun (f : C_ast.c_function) -> String.equal f.name fn_name)
      functions
  with
  | Some f -> f
  | None ->
      Alcotest.fail
        (Fmt.str
           "generate_and_find_c_method: expected function '%s' not found in \
            generated code"
           fn_name)

(* ========================================================================= *)
(* Shared GIR XML Snippets *)
(* ========================================================================= *)

(** Minimal EventControllerKey class stub used as a namespace filler in
    integration tests that need at least one class in the GIR namespace. *)
let eventcontroller_key_class_xml =
  {|    <class name="EventControllerKey" c:type="GtkEventControllerKey" parent="EventController">
      <constructor name="new" c:identifier="gtk_event_controller_key_new"/>
    </class>|}

(* ========================================================================= *)
(* Integration Test Harness *)
(* ========================================================================= *)

(** [run_integration_test ~gir_content ~class_names ~test_name ()] runs
    [gir_gen] on [gir_content] and asserts it exits successfully.

    [gir_content] is written to [/tmp/test_<test_name>.gir]. When [class_names]
    is non-empty a filter file is created at [/tmp/test_<test_name>_filter.conf]
    and passed to [gir_gen]. Returns the output directory path. *)
let run_integration_test ~gir_content ~class_names ~test_name () =
  let test_gir = Fmt.str "/tmp/test_%s.gir" test_name in
  let output_dir = Fmt.str "/tmp/test_%s_output" test_name in
  create_gir_file test_gir gir_content;
  ensure_output_dir output_dir;
  let exit_code =
    match class_names with
    | [] -> run_gir_gen test_gir output_dir
    | _ ->
        let test_filter = Fmt.str "/tmp/test_%s_filter.conf" test_name in
        create_filter_file test_filter class_names;
        run_gir_gen ~filter_file:test_filter test_gir output_dir
  in
  assert_true "Generator should exit successfully" (exit_code = 0);
  output_dir
