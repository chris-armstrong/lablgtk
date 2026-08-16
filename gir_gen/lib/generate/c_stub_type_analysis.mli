(** Type classification helpers for property type introspection.

    Provides the canonical C type-name lists and list helpers used by the
    property GValue conversion generators. *)

module Type_analysis : sig
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
end
