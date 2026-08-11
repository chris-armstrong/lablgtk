(** GValue conversion code generation for property getters and setters.

    Generates the C statements that read from / write to a [GValue] for a
    property, dispatching on the property's type category (enum, integer,
    string, boxed, object, variant, ...). *)

module GValue : sig
  type property_gvalue_info = {
    base_type : string;  (** C type with any trailing pointer stripped. *)
    base_lower : string;  (** Lowercased GIR type name. *)
    has_pointer : bool;  (** Whether the C type carries a pointer suffix. *)
    pointer_like : bool;
        (** True for pointers and known pointer builtins ([gpointer],
            [gconstpointer]). *)
    record_info : (Types.gir_record * bool * bool) option;
        (** Resolved record, whether the lookup was a pointer type, and whether
            the record is boxed, when the type names a record. *)
    class_info : Types.gir_class option;
        (** Resolved class, when the type names a class. *)
    is_enum : bool;  (** Whether the GIR type is an enum. *)
    is_bitfield : bool;  (** Whether the GIR type is a bitfield. *)
    stack_allocated : bool;
        (** True when the value can live on the C stack (enums, bitfields,
            non-pointer builtins). *)
  }
  (** Result of analyzing a property's GIR type, used to drive GValue
      conversion. *)

  val analyze_property_type :
    ctx:Types.generation_context -> Types.gir_type -> property_gvalue_info
  (** [analyze_property_type ~ctx gir_type] inspects [gir_type] and returns the
      [property_gvalue_info] describing how its values are represented in C and
      in GValues.

      @param ctx generation context (type mappings, records, classes)
      @param gir_type the property's GIR type
      @return the analysis record described in {!property_gvalue_info} *)

  val generate_gvalue_getter_assignment :
    ml_name:string ->
    prop:Types.gir_property ->
    c_type_name:string ->
    prop_info:property_gvalue_info ->
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
    ml_name:string -> prop_info:property_gvalue_info -> string
  (** [generate_gvalue_setter_assignment ~ml_name ~prop_info] generates the C
      statement that stores the property value into a [GValue].

      @param ml_name OCaml variable name used in the generated code
      @param prop_info analysis of the property's GIR type
      @return the C assignment statement *)
end
