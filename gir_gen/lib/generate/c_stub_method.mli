module Out_conv = C_stub_method_out

val ( let* ) : 'a option -> ('a -> 'b option) -> 'b option
val option_get_exn : message:string -> 'a option -> 'a

module Log : Logs.LOG

val var_name_for_direction : Types.gir_direction -> int -> string

val declare_fixed_array :
  base_type:string ->
  var_name:string ->
  fixed_size:int ->
  acc:C_stub_helpers.param_acc ->
  C_stub_helpers.param_acc

val declare_array_out_param :
  base_type:string ->
  var_name:string ->
  acc:C_stub_helpers.param_acc ->
  C_stub_helpers.param_acc

val handle_out_param :
  param_index:int ->
  base_type:string ->
  acc:C_stub_helpers.param_acc ->
  Types.gir_param ->
  C_stub_helpers.param_acc

val handle_inout_param :
  ctx:Types.generation_context ->
  param_index:int ->
  base_type:string ->
  acc:C_stub_helpers.param_acc ->
  tm:Types.type_mapping option ->
  Types.gir_param ->
  C_stub_helpers.param_acc

val handle_in_array_param :
  ctx:Types.generation_context ->
  acc:C_stub_helpers.param_acc ->
  arg_name:string ->
  base_type:string ->
  tm:Types.type_mapping option ->
  Types.gir_param ->
  Types.gir_array ->
  string * string list

val handle_scalar_param :
  arg_name:string ->
  ocaml_idx:'a ->
  length_param_map:('a * string) list ->
  p:Types.gir_param ->
  tm:Types.type_mapping option ->
  string

val handle_in_list_param :
  ctx:Types.generation_context ->
  acc:C_stub_helpers.param_acc ->
  arg_name:string ->
  Types.gir_param ->
  string * string list

val handle_in_param :
  ctx:Types.generation_context ->
  acc:C_stub_helpers.param_acc ->
  length_param_map:(int * string) list ->
  base_type:string ->
  tm:Types.type_mapping option ->
  Types.gir_param ->
  C_stub_helpers.param_acc

val generate_ref_sink_stmt :
  transfer_ownership:Types.transfer_ownership -> Types.type_mapping -> string

val handle_void_return :
  c_name:string ->
  args:string ->
  out_array_conv_code:string ->
  out_conversions:string list ->
  out_array_cleanup_list:'a ->
  string * string * 'a

val handle_array_return :
  ctx:Types.generation_context ->
  meth:Types.gir_method ->
  c_name:string ->
  args:string ->
  out_array_conv_code:string ->
  ret_type:string ->
  out_conversions:string list ->
  out_array_cleanup_list:string list ->
  string * string * string list

val handle_scalar_return :
  ctx:Types.generation_context ->
  meth:Types.gir_method ->
  c_name:string ->
  args:string ->
  out_array_conv_code:string ->
  ret_type:string ->
  mapping:Types.type_mapping ->
  out_conversions:string list ->
  out_array_cleanup_list:'a ->
  string * string * 'a

val handle_list_return :
  ctx:Types.generation_context ->
  meth:Types.gir_method ->
  c_name:string ->
  args:string ->
  out_array_conv_code:string ->
  out_conversions:'a ->
  out_array_cleanup_list:'b ->
  string * string * 'b

val handle_non_void_return :
  ctx:Types.generation_context ->
  meth:Types.gir_method ->
  c_name:string ->
  args:string ->
  ret_type:string ->
  out_array_conv_code:string ->
  out_conversions:string list ->
  out_array_cleanup_list:string list ->
  string * string * string list

val build_return_conversion :
  ctx:Types.generation_context ->
  meth:Types.gir_method ->
  c_name:string ->
  args:string ->
  ret_type:string option ->
  out_array_conv_code:string ->
  out_conversions:string list ->
  out_array_cleanup_list:string list ->
  string * string * string list

val compute_in_param_indices :
  Types.gir_param list -> (Types.gir_param * int) list

val build_param_to_ocaml_map : Types.gir_param list -> (int * int) list

val extract_length_mappings :
  (Types.gir_param * int) list -> (int * 'a) list -> ('a * string) list

val build_length_param_map : meth:Types.gir_method -> (int * string) list

val build_method_params :
  ctx:Types.generation_context ->
  meth:Types.gir_method ->
  string * string list * string list

val build_method_call :
  meth:Types.gir_method -> c_name:string -> c_args:string list -> string

val build_method_return :
  ctx:Types.generation_context ->
  meth:Types.gir_method ->
  c_name:string ->
  c_args:string list ->
  string * string * string list

val generate_c_method :
  ctx:Types.generation_context ->
  c_type:string ->
  Types.gir_method ->
  'a ->
  string
