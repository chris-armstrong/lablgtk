(* GENERATED CODE - DO NOT EDIT *)
(* BitsetIter: BitsetIter *)

type t = [ `bitset_iter ] Gobject.obj
(** Iterates over the elements of a [struct@Gtk.Bitset].

    `GtkBitSetIter is an opaque, stack-allocated struct.

    Before a `GtkBitsetIter` can be used, it needs to be initialized with
    [func@Gtk.BitsetIter.init_first], [func@Gtk.BitsetIter.init_last] or
    [func@Gtk.BitsetIter.init_at]. *)

external gtype : unit -> Gobject.Type.t = "ml_gtk_bitset_iter_get_type"

(* Methods *)

external previous : t -> bool * int = "ml_gtk_bitset_iter_previous"
(** Moves @iter to the previous value in the set.

If it was already pointing to the first value in the set,
%FALSE is returned and @iter is invalidated. *)

external next : t -> bool * int = "ml_gtk_bitset_iter_next"
(** Moves @iter to the next value in the set.

If it was already pointing to the last value in the set,
%FALSE is returned and @iter is invalidated. *)

external is_valid : t -> bool = "ml_gtk_bitset_iter_is_valid"
(** Checks if @iter points to a valid value. *)

external get_value : t -> int = "ml_gtk_bitset_iter_get_value"
(** Gets the current value that @iter points to.

If @iter is not valid and [method@Gtk.BitsetIter.is_valid]
returns %FALSE, this function returns 0. *)
