(** C stub code generation for GObject constructors.

    Generates the C wrapper functions that convert OCaml constructor arguments
    to C, invoke the underlying C constructor, apply ref-sink semantics for
    GObjects, and convert the result back to OCaml, including error handling for
    throwing constructors. *)

val generate_c_constructor :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  Types.gir_constructor ->
  string
(** [generate_c_constructor ~ctx ~c_type ~class_name ctor] generates the
    complete C wrapper function for the GIR constructor [ctor]. Returns the C
    function code as a string. *)
