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

  val list_contains :
    value:StdLabels.String.t -> StdLabels.String.t list -> bool

  val ends_with : suffix:StdLabels.String.t -> string -> bool

  val fold_mapi :
    f:(int -> 'a -> 'b -> 'a * 'c) -> init:'a -> 'b list -> 'a * 'c list

  val string_base_types : string list
  val int32_types : string list
  val uint32_types : string list
  val int64_types : string list
  val uint64_types : string list
  val long_types : string list
  val ulong_types : string list
  val ssize_types : string list
  val size_types : string list
  val float_types : string list
  val double_types : string list
  val pointer_types : string list
  val all_stack_allocated_builtins : string list
  val is_string_type : string option -> bool

  val analyze_property_type :
    ctx:Types.generation_context -> Types.gir_type -> property_gvalue_info
end
