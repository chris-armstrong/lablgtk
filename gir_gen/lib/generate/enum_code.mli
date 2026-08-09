val variant_name_of_member : string -> string

val emit_member_branch :
  namespace:string ->
  class_version:string option ->
  member_version:string option ->
  fallback_line:string option ->
  branch:string ->
  Buffer.t ->
  unit

val generate_ocaml_enum : Types.gir_enum -> string
val generate_ocaml_bitfield : Types.gir_bitfield -> string

val generate_c_enum_converters :
  namespace:string -> class_version:string option -> Types.gir_enum -> string

val generate_c_bitfield_converters :
  namespace:string ->
  class_version:string option ->
  Types.gir_bitfield ->
  string

val generate_ocaml_enum_impl : Types.gir_enum -> string
val generate_ocaml_bitfield_impl : Types.gir_bitfield -> string
