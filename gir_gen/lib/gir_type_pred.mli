module Gir_direction : sig
  type t = Types.gir_direction = In | Out | InOut

  val is_in : t -> bool
  (** [is_in d] is [true] if [d] is [In] or [InOut] (i.e. the parameter receives
      a value from the caller). *)

  val is_in_only : t -> bool
  (** [is_in_only d] is [true] if [d] is [In] but NOT [InOut] (pure input only).
  *)

  val has_output : t -> bool
  (** [has_output d] is [true] if [d] is [Out] or [InOut] (i.e. the parameter
      produces a value for the caller). *)
end

(** {b Container-name predicates.}

    These are the single source of the [GLib.List], [GLib.SList], and
    [GLib.HashTable] literals — every other module checks container membership
    through here instead of spelling the strings, so a rename or new container
    type is one edit. The string-level predicates are exposed for the GIR
    parser, which works with raw [type_name] strings before a [gir_type] is
    built. *)

val is_glist_name : string -> bool
(** [is_glist_name n] is [true] if [n] is ["GLib.List"]. *)

val is_gslist_name : string -> bool
(** [is_gslist_name n] is [true] if [n] is ["GLib.SList"]. *)

val is_hash_table_name : string -> bool
(** [is_hash_table_name n] is [true] if [n] is ["GLib.HashTable"]. *)

val is_glist : Types.gir_type -> bool
(** [is_glist gt] is [true] if [gt] represents a [GLib.List]. *)

val is_gslist : Types.gir_type -> bool
(** [is_gslist gt] is [true] if [gt] represents a [GLib.SList]. *)

val is_list : Types.gir_type -> bool
(** [is_list gt] is [true] if [gt] represents a [GLib.List] or [GLib.SList]. *)

val is_hash_table_array : Types.gir_array -> bool
(** [is_hash_table_array arr] is [true] if [arr.array_name] is
    [Some "GLib.HashTable"]. Use this for array-container checks (e.g. in
    array-support filtering); use [is_hash_table] for [gir_type]-level checks.
*)
