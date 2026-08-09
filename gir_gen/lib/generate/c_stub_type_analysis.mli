(** Type analysis helpers for GObject property type introspection.

    Classifies a GIR type into the information needed to generate GValue
    conversion code for property getters and setters. *)

module Type_analysis : sig
  type property_gvalue_info = {
    base_type : string;
    base_lower : string;
    has_pointer : bool;
    pointer_like : bool;
    record_info : (Types.gir_record * bool * bool) option;
    class_info : Types.gir_class option;
    is_enum : bool;
    is_bitfield : bool;
    stack_allocated : bool;
  }
  (** Result of analyzing a property's GIR type.

      [base_type] is the C type with any trailing pointer stripped; [base_lower]
      is the lowercased GIR type name; [has_pointer] reports whether the C type
      carries a pointer suffix; [pointer_like] is true when the type is a
      pointer or a known pointer builtin ([gpointer], [gconstpointer]);
      [record_info] and [class_info] hold the resolved record/class when the
      type names one; [is_enum] / [is_bitfield] report the GIR type kind;
      [stack_allocated] is true when the value can live on the C stack (enums,
      bitfields and non-pointer builtins). *)

  val list_contains : value:string -> string list -> bool
  (** [list_contains ~value list] returns [true] when [value] is a member of
      [list] (exact string comparison). Used to test a lowercased C type name
      against the builtin type-name lists below. *)

  val fold_mapi :
    f:(int -> 'a -> 'b -> 'a * 'c) -> init:'a -> 'b list -> 'a * 'c list
  (** [fold_mapi ~f ~init list] is a left fold over [list] that also maps each
      element, threading an index (starting at 0) into [f]. Equivalent to
      [List.fold_left_map] with an index argument. Returns the final accumulator
      paired with the mapped element list. *)

  val string_base_types : string list
  (** C type names treated as strings (e.g. ["gchar"], ["utf8"]). *)

  val int32_types : string list
  (** C type names mapped to 32-bit signed integers. *)

  val uint32_types : string list
  (** C type names mapped to 32-bit unsigned integers. *)

  val int64_types : string list
  (** C type names mapped to 64-bit signed integers. *)

  val uint64_types : string list
  (** C type names mapped to 64-bit unsigned integers. *)

  val long_types : string list
  (** C type names mapped to [glong]-style signed long integers. *)

  val ulong_types : string list
  (** C type names mapped to [gulong]-style unsigned long integers. *)

  val ssize_types : string list
  (** C type names mapped to [gssize]-style signed size integers. *)

  val size_types : string list
  (** C type names mapped to [gsize]-style unsigned size integers. *)

  val float_types : string list
  (** C type names mapped to single-precision floats. *)

  val double_types : string list
  (** C type names mapped to double-precision floats. *)

  val analyze_property_type :
    ctx:Types.generation_context -> Types.gir_type -> property_gvalue_info
  (** [analyze_property_type ~ctx gir_type] inspects [gir_type] and returns the
      [property_gvalue_info] describing how its values are represented in C and
      in GValues.

      @param ctx generation context (type mappings, records, classes)
      @param gir_type the property's GIR type
      @return the analysis record described in {!property_gvalue_info} *)
end
