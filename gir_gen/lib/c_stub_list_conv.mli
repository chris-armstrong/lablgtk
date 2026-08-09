type list_kind = [ `GList | `GSList ]

val list_kind_of_type : Types.gir_type -> list_kind option
val c_type_of_list_kind : [< `GList | `GSList ] -> string

val element_converter_name :
  ctx:Types.generation_context -> Types.gir_type -> string option

val generate_list_cleanup :
  ctx:Types.generation_context ->
  kind:list_kind ->
  var:string ->
  xfer:Types.transfer_ownership ->
  elem_type:Types.gir_type ->
  string

val cleanup_for_in_param :
  list_kind:[< `GList | `GSList ] ->
  element_unref_fn:string ->
  transfer:Types.transfer_ownership ->
  string ->
  string

val generate_list_c_to_ml :
  ctx:Types.generation_context ->
  var:string ->
  elem_type:Types.gir_type ->
  kind:list_kind ->
  xfer:Types.transfer_ownership ->
  string * string * string

val generate_list_ml_to_c :
  ctx:Types.generation_context ->
  var:string ->
  elem_type:Types.gir_type ->
  kind:list_kind ->
  xfer:Types.transfer_ownership ->
  string

val generate_return_list_conversion :
  ctx:Types.generation_context ->
  c_var:string ->
  gir_type:Types.gir_type ->
  (string * string * string) option

val generate_param_list_conversion :
  ctx:Types.generation_context ->
  ocaml_var:string ->
  gir_type:Types.gir_type ->
  (string * string) option
