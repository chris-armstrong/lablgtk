(** Multi-parameter C wrapper generation.

    Generates the native ([CAMLparam5] + [CAMLxparamN] chunks) and bytecode
    ([argv] forwarding) variants of a C stub function when it has more than 5
    parameters. Shared by the method and constructor C-stub generators. *)

val generate_multi_param_function :
  ml_name:string ->
  params:string list ->
  param_names:string list ->
  string ->
  string
(** [generate_multi_param_function ~ml_name ~params ~param_names body_code]
    generates both native and bytecode C wrapper variants for functions with
    more than 5 parameters (native uses [CAMLparam5] + [CAMLxparamN] chunks;
    bytecode forwards [argv] to the native variant). *)
