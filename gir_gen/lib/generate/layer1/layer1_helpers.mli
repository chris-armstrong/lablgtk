type output_mode = Interface | Implementation

val detect_class_hierarchy_names :
  ctx:'a ->
  class_name:string ->
  parent_chain:string list ->
  unit ->
  string * string

val print_indent : string -> Buffer.t -> unit
val combine_return_and_out_types : string -> string list -> string

val method_handles_property :
  StdLabels.String.t -> Types.gir_method list -> bool

val map_gir_type_to_ocaml :
  ctx:Types.generation_context ->
  class_name:string ->
  gir_type:Types.gir_type ->
  is_nullable:bool ->
  string

val map_constructor_param :
  ctx:Types.generation_context -> class_name:string -> Types.gir_param -> string

val convert_method_param_to_ocaml_type :
  ctx:Types.generation_context ->
  class_name:string ->
  Types.gir_param ->
  string option

val convert_out_param_to_ocaml_type :
  ctx:Types.generation_context ->
  class_name:string ->
  Types.gir_param ->
  string option

val format_external :
  ocaml_name:string ->
  signature:string ->
  ml_name:string ->
  param_count:int ->
  string

val property_naming :
  prop:Types.gir_property -> type_mapping:Types.type_mapping -> string * string
