module Log : Logs.LOG

val generate_constructor_error_decl : throws:bool -> string

val generate_constructor_return_stmt :
  throws:bool -> val_macro:string -> var_name:string -> string

val generate_constructor_c_call_args :
  ctx:Types.generation_context ->
  ctor_parameters:Types.gir_param list ->
  string list * string list * Buffer.t

val build_constructor_params : 'a list -> int * string list * string list
val build_constructor_call : string list -> bool -> string

val build_constructor_return :
  c_type:string ->
  class_name:'a ->
  Types.gir_constructor ->
  int ->
  string list ->
  string list ->
  string ->
  string ->
  string ->
  string ->
  array_decls:Buffer.t ->
  cleanup_code:string list ->
  string

val generate_c_constructor :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:'a ->
  Types.gir_constructor ->
  string
