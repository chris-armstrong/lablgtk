(** Out-parameter conversion for C stub generation.

    Converts out/inout method parameters from C to OCaml for the return
    statement, including array out-parameters with length-parameter lookup. *)

val get_element_c_type : fallback:string -> Types.gir_array -> string
(** [get_element_c_type ~fallback array_info] returns the C type of the array
    elements, falling back to [fallback] when the GIR metadata carries no
    element [c_type].

    @param fallback C type used when the element type is unspecified
    @param array_info GIR metadata for the array
    @return the element C type *)

val process_out_param_conversion :
  ctx:Types.generation_context ->
  out_array_length_map:(int * int) list ->
  out_array_conversions_buf:Buffer.t ->
  parameters:Types.gir_param list ->
  Types.gir_param * int ->
  string option * string list
(** [process_out_param_conversion ~ctx ~out_array_length_map
     ~out_array_conversions_buf ~parameters (p, idx)] converts a single out or
    inout parameter to its OCaml value expression. In-direction parameters are
    skipped. Array out-parameters append their conversion code to
    [out_array_conversions_buf]. Returns the optional OCaml value expression
    paired with the cleanup code list.

    @param ctx generation context (type mappings)
    @param out_array_length_map
      maps array parameter index to its length parameter index
    @param out_array_conversions_buf buffer receiving array conversion code
    @param parameters all method parameters (for length lookups)
    @param p the parameter to convert
    @param idx the parameter's index
    @return
      [(Some expr, cleanups)] for out/inout parameters, [(None, [])] for in
      parameters *)

val build_out_array_length_map : Types.gir_param list -> (int * int) list
(** [build_out_array_length_map parameters] maps each out/inout array parameter
    index to the index of its length parameter, for use in
    {!process_out_param_conversion}.

    @param parameters the method's parameters
    @return [(array_param_idx, length_param_idx)] pairs *)
