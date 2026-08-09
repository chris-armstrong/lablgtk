module GValue : sig
  type gvalue_type_category =
    | Enum
    | Bitfield
    | Boolean
    | Integer of { c_type_name : string; getter : string }
    | Float of string
    | String
    | Boxed of { c_type : string; is_pointer : bool }
    | Object of string
    | GVariant
    | Pointer
    | Unsupported of string

  val classify_gvalue_type :
    c_type_name:StdLabels.String.t ->
    C_stub_type_analysis.Type_analysis.property_gvalue_info ->
    gvalue_type_category

  val gvalue_type_dispatch :
    c_type_name:'a ->
    gen_enum:(unit -> string) ->
    gen_bitfield:(unit -> string) ->
    gen_boolean:(unit -> string) ->
    gen_integer:(string -> string) ->
    gen_float:(string -> string) ->
    gen_string:(unit -> string) ->
    gen_boxed:(string -> string) ->
    gen_boxed_no_ptr:(string -> string) ->
    gen_object:(string -> string) ->
    gen_gvariant:(unit -> string) ->
    gen_pointer:('a -> string) ->
    gvalue_type_category ->
    string

  val generate_getter_for_category :
    ml_name:'a ->
    prop:'b ->
    c_type_name:string ->
    gvalue_type_category ->
    string

  val getter_to_setter : string -> string

  val generate_setter_for_category :
    ml_name:'a -> c_type_name:'b -> gvalue_type_category -> string

  val generate_gvalue_getter_assignment :
    ml_name:'a ->
    prop:'b ->
    c_type_name:StdLabels.String.t ->
    prop_info:C_stub_type_analysis.Type_analysis.property_gvalue_info ->
    string

  val generate_gvalue_setter_assignment :
    ml_name:'a ->
    prop:'b ->
    prop_info:C_stub_type_analysis.Type_analysis.property_gvalue_info ->
    string
end
