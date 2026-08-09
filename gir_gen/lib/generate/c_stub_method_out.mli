val ( let* ) : 'a option -> ('a -> 'b option) -> 'b option
val option_get_exn : message:string -> 'a option -> 'a

module Log : Logs.LOG

val get_element_c_type : fallback:string -> Types.gir_array -> string
val safe_nth_opt : 'a list -> int -> 'a option
val var_name_for_direction : Types.gir_direction -> int -> string

val convert_out_array :
  ctx:Types.generation_context ->
  out_array_length_map:('a * int) list ->
  out_array_conversions_buf:Buffer.t ->
  parameters:Types.gir_param list ->
  idx:'a ->
  var_name:string ->
  Types.gir_param ->
  Types.gir_array ->
  (string option * string list) option

val convert_out_scalar :
  ctx:Types.generation_context ->
  _idx:'a ->
  var_name:string ->
  Types.gir_param ->
  string option

val process_out_param_conversion :
  ctx:Types.generation_context ->
  out_array_length_map:(int * int) list ->
  out_array_conversions_buf:Buffer.t ->
  parameters:Types.gir_param list ->
  Types.gir_param * int ->
  string option * string list

val build_out_array_length_map : Types.gir_param list -> (int * int) list
