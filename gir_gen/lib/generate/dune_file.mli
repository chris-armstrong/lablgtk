val stub_batch_size : int
val list_chunks : int -> 'a list -> 'a list list

val pkg_config_name_of_namespace :
  ctx:Types.generation_context -> Types.StringMap.key -> string list

val collect_transitive_packages :
  ctx:Types.generation_context ->
  visited:Types.StringMap.key ContainersLabels.List.t ->
  Types.StringMap.key ->
  string ContainersLabels.List.t

val transitively_includes :
  ctx:Types.generation_context ->
  visited:Types.StringMap.key ContainersLabels.List.t ->
  target:string ->
  Types.StringMap.key ->
  bool

val library_name_of_namespace : string -> string

val emit_pkg_config_rule :
  Buffer.t ->
  cflag_file:string ->
  clink_file:string ->
  all_packages:string list ->
  is_optional:(string -> bool) ->
  unit

val emit_stub_library :
  Buffer.t ->
  name:string ->
  public_name:string option ->
  dep_libraries:string ->
  stub_names:string list ->
  cflag_file:string ->
  clink_file:string ->
  unit

val generate_dune_library :
  ctx:Types.generation_context ->
  lib_name:string ->
  stub_names:string list ->
  repository:Types.gir_repository ->
  string
