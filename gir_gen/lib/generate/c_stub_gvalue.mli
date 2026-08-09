(** GValue conversion code generation for property getters and setters.

    Generates the C statements that read from / write to a [GValue] for a
    property, dispatching on the property's type category (enum, integer,
    string, boxed, object, variant, ...). *)

module GValue : sig
  val generate_gvalue_getter_assignment :
    ml_name:string ->
    prop:Types.gir_property ->
    c_type_name:string ->
    prop_info:C_stub_type_analysis.Type_analysis.property_gvalue_info ->
    string
  (** [generate_gvalue_getter_assignment ~ml_name ~prop ~c_type_name ~prop_info]
      generates the C statement that extracts the property value from a [GValue]
      into [prop_value].

      @param ml_name OCaml variable name used in the generated code
      @param prop the property being read
      @param c_type_name C type name of the property value
      @param prop_info analysis of the property's GIR type
      @return the C assignment statement *)

  val generate_gvalue_setter_assignment :
    ml_name:string ->
    prop:unit ->
    prop_info:C_stub_type_analysis.Type_analysis.property_gvalue_info ->
    string
  (** [generate_gvalue_setter_assignment ~ml_name ~prop ~prop_info] generates
      the C statement that stores the property value into a [GValue]. The [prop]
      argument is unused (kept for signature symmetry with the getter).

      @param ml_name OCaml variable name used in the generated code
      @param prop unused placeholder
      @param prop_info analysis of the property's GIR type
      @return the C assignment statement *)
end
