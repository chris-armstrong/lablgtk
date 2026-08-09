val string_contains : string -> string -> bool
val assert_true : string -> bool -> unit
val expect_some : string -> 'a option -> ('a -> 'b) -> 'b
val assert_some : string -> 'a option -> unit
val assert_some_value : string -> 'a option -> 'a
val assert_head : string -> 'a list -> 'a
val file_exists : string -> bool
val delete_if_exists : string -> unit
val read_file : string -> string
val generated_dir : string -> string
val stub_c_file : string -> string -> string
val g_wrapper_file : string -> string -> string
val ml_file : string -> string -> string
val mli_file : string -> string -> string
val enum_file : string -> string
val enum_ml_file : string -> string
val enum_c_file : string -> string

val wrap_namespace :
  ?namespace_name:string ->
  ?version:string ->
  ?shared_library:string ->
  ?c_prefix:string ->
  ?symbol_prefix:string ->
  string ->
  string

val create_gir_file : string -> string -> unit
val create_filter_file : string -> string list -> unit
val get_tools_dir : unit -> string

type command_result = {
  exit_code : int;
  stdout : string;
  stderr : string;
  log_file : string option;
}

val run_command_with_output : ?log_dir:string option -> string -> command_result
val run_gir_gen : ?filter_file:string -> string -> string -> int
val ensure_output_dir : string -> unit
val gir_data_dir : unit -> string
val create_test_context : unit -> Gir_gen_lib.Types.generation_context

val create_test_context_with_hierarchy :
  unit -> Gir_gen_lib.Types.generation_context

val make_ncr :
  ?packages:string list ->
  ?includes:string list ->
  ?c_includes:string list ->
  string ->
  Gir_gen_lib.Types.cross_reference_entity Gir_gen_lib.Types.StringMap.t ->
  string * Gir_gen_lib.Types.generation_context_namespace_cross_references

val log_generated_c_code : string -> string -> unit

val generate_and_find_c_method :
  ?ctx:Gir_gen_lib.Types.generation_context ->
  ?log_label:string ->
  c_type:string ->
  class_name:'a ->
  Gir_gen_lib.Types.gir_method ->
  C_ast.c_function

val eventcontroller_key_class_xml : string

val run_integration_test :
  gir_content:string ->
  class_names:string list ->
  test_name:string ->
  unit ->
  string
