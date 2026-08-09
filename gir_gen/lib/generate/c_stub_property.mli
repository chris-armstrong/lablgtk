module Log : Logs.LOG

type property_wrapper_template = {
  header : string;
  locals : string;
  obj_decl : string;
  pspec_find : string;
  pspec_check : string;
  gvalue_init : string;
  operation : string;
  gvalue_unset : string;
  footer : string;
}

val generate_property_wrapper :
  ctx:Types.generation_context ->
  c_type:string ->
  Types.gir_property ->
  string ->
  is_getter:bool ->
  c_to_ml_expr:string ->
  ml_to_c_expr:string ->
  gvalue_assignment:string ->
  result_expr:string ->
  caml_params:string ->
  caml_locals:string ->
  string

val generate_c_property_getter_impl :
  ctx:Types.generation_context ->
  c_type:string ->
  Types.gir_property ->
  string ->
  string

val generate_c_property_setter_impl :
  ctx:Types.generation_context ->
  c_type:string ->
  Types.gir_property ->
  string ->
  string

val generate_c_property_getter :
  ctx:Types.generation_context ->
  c_type:string ->
  Types.gir_property ->
  string ->
  string

val generate_c_property_setter :
  ctx:Types.generation_context ->
  c_type:string ->
  Types.gir_property ->
  string ->
  string
