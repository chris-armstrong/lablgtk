(** C code generation for C array <-> OCaml array conversion.

    Generates the C snippets that convert between C arrays (including
    [GPtrArray]) and OCaml arrays for parameters and return values, handling
    length computation, zero-termination, nullable values and transfer-ownership
    cleanup. *)

module Array_conv : sig
  val is_string_array : Types.gir_array -> bool
  (** Check if an array contains string elements. *)

  val is_string_type : string option -> bool
  (** Check if a C type is a string type. *)

  val generate_array_ml_to_c :
    ctx:Types.generation_context ->
    var:string ->
    array_info:Types.gir_array ->
    element_mapping:Types.type_mapping ->
    element_c_type:string ->
    transfer_ownership:Types.transfer_ownership ->
    nullable:bool ->
    string * string * string * string
  (** [generate_array_ml_to_c ~ctx ~var ~array_info ~element_mapping
       ~element_c_type ~transfer_ownership ~nullable] generates the conversion
      of an OCaml array parameter to a C array. Returns
      [(conversion_code, c_array_var, length_var, cleanup_code)]. *)

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
  (** [generate_array_c_to_ml ~ctx ~var ~array_info ~length_expr ~element_c_type
       ~transfer_ownership ?nullable ()] generates the conversion of a C array
      return value to an OCaml array. When [nullable] is [true] (default
      [false]) the C pointer may be [NULL] and the generated code wraps the
      result in [Val_none]/[Val_some]. Returns
      [(conversion_code, ml_array_var_or_opt_var, cleanup_code)]. *)
end
