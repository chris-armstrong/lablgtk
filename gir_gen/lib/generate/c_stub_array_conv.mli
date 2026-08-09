module Array_conv : sig
  val strip_const : string -> string
  val is_string_array : Types.gir_array -> bool

  val zero_terminated_conversion :
    length_var:string ->
    c_array_var:string ->
    var:string ->
    elem_type_alloc:string ->
    element_tm:Types.type_mapping ->
    is_pointer_array:bool ->
    deref_prefix:string ->
    string

  val non_zero_terminated_conversion :
    length_var:string ->
    c_array_var:string ->
    var:string ->
    elem_type_alloc:string ->
    element_tm:Types.type_mapping ->
    deref_prefix:string ->
    string

  val length_code_explicit : length_var:string -> expr:string -> string

  val length_code_for_zero_terminated_pointer :
    length_var:string -> var:string -> string

  val length_code_for_zero_terminated_nonpointer :
    length_var:string -> var:string -> element_c_type:string -> string

  val length_code_for_string_array : length_var:string -> var:string -> string
  val cleanup_for_string_array : length_var:string -> var:string -> string
  val cleanup_for_pointer_array : var:string -> string

  val length_code_for_array :
    var:string ->
    length_var:string ->
    array_info:Types.gir_array ->
    is_pointer_array:bool ->
    element_c_type:string ->
    string

  val cleanup_code_for_transfer_full :
    array_info:Types.gir_array ->
    is_pointer_array:bool ->
    length_var:string ->
    var:string ->
    string

  val generate_array_ml_to_c :
    ctx:Types.generation_context ->
    var:string ->
    array_info:Types.gir_array ->
    element_mapping:'a ->
    element_c_type:string ->
    transfer_ownership:Types.transfer_ownership ->
    nullable:bool ->
    string * string * string * string

  val is_gptr_array : Types.gir_array -> bool

  val generate_array_c_to_ml :
    ctx:Types.generation_context ->
    var:string ->
    array_info:Types.gir_array ->
    length_expr:string option ->
    element_c_type:string ->
    transfer_ownership:Types.transfer_ownership ->
    ?nullable:bool ->
    unit ->
    string * string * string
end
