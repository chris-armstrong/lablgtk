(** C stub code generation for GObject methods.

    Generates the C wrapper functions that convert OCaml method arguments
    (including arrays, lists, out/inout parameters and nullable values) to C,
    invoke the underlying C function, and convert the return value and out
    parameters back to OCaml, including GError handling for throwing methods. *)

val generate_c_method :
  ctx:Types.generation_context ->
  c_type:string ->
  Types.gir_method ->
  string ->
  string
(** [generate_c_method ~ctx ~c_type meth class_name] generates the complete C
    wrapper function for the GIR method [meth].

    @param ctx generation context (type mappings, classes)
    @param c_type C type name of the class/record the method belongs to
    @param meth the method to generate
    @param class_name GIR class name
    @return the C function code as a string *)
