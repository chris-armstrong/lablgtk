(* GENERATED CODE - DO NOT EDIT *)
(* Bitset: Bitset *)

type t = [ `bitset ] Gobject.obj
(** A set of unsigned integers.

    Another name for this data structure is “bitmap”.

    The current implementation is based on
    [roaring bitmaps](https://roaringbitmap.org/).

    A bitset allows adding a set of integers and provides support for set
    operations like unions, intersections and checks for equality or if a value
    is contained in the set. `GtkBitset` also contains various functions to
    query metadata about the bitset, such as the minimum or maximum values or
    its size.

    The fastest way to iterate values in a bitset is [struct@Gtk.BitsetIter].

    The main use case for `GtkBitset` is implementing complex selections for
    [iface@Gtk.SelectionModel]. *)

external gtype : unit -> Gobject.Type.t = "ml_gtk_bitset_get_type"

external new_empty : unit -> t = "ml_gtk_bitset_new_empty"
(** Create a new Bitset *)

external new_range : int -> int -> t = "ml_gtk_bitset_new_range"
(** Create a new Bitset *)

(* Methods *)

external union : t -> t -> unit = "ml_gtk_bitset_union"
(** Sets @self to be the union of @self and @other.

That is, add all values from @other into @self that weren't part of it.

It is allowed for @self and @other to be the same bitset. Nothing will
happen in that case. *)

external subtract : t -> t -> unit = "ml_gtk_bitset_subtract"
(** Sets @self to be the subtraction of @other from @self.

In other words, remove all values from @self that are part of @other.

It is allowed for @self and @other to be the same bitset. The bitset
will be emptied in that case. *)

external splice : t -> int -> int -> int -> unit = "ml_gtk_bitset_splice"
(** This is a support function for `GListModel` handling, by mirroring
the `GlistModel::items-changed` signal.

First, it "cuts" the values from @position to @removed from
the bitset. That is, it removes all those values and shifts
all larger values to the left by @removed places.

Then, it "pastes" new room into the bitset by shifting all values
larger than @position by @added spaces to the right. This frees
up space that can then be filled. *)

external shift_right : t -> int -> unit = "ml_gtk_bitset_shift_right"
(** Shifts all values in @self to the right by @amount.

Values that end up too large to be held in a #guint are discarded. *)

external shift_left : t -> int -> unit = "ml_gtk_bitset_shift_left"
(** Shifts all values in @self to the left by @amount.

Values smaller than @amount are discarded. *)

external remove_rectangle : t -> int -> int -> int -> int -> unit
  = "ml_gtk_bitset_remove_rectangle"
(** Interprets the values as a 2-dimensional boolean grid with the given @stride
and inside that grid, removes a rectangle with the given @width and @height. *)

external remove_range_closed : t -> int -> int -> unit
  = "ml_gtk_bitset_remove_range_closed"
(** Removes the closed range [@first, @last], so @first, @last and all
values in between. @first must be smaller than @last. *)

external remove_range : t -> int -> int -> unit = "ml_gtk_bitset_remove_range"
(** Removes all values from @start (inclusive) to @start + @n_items (exclusive)
in @self. *)

external remove_all : t -> unit = "ml_gtk_bitset_remove_all"
(** Removes all values from the bitset so that it is empty again. *)

external remove : t -> int -> bool = "ml_gtk_bitset_remove"
(** Removes @value from @self if it was part of it before. *)

external ref : t -> t = "ml_gtk_bitset_ref"
(** Acquires a reference on the given `GtkBitset`. *)

external is_empty : t -> bool = "ml_gtk_bitset_is_empty"
(** Check if no value is contained in bitset. *)

external intersect : t -> t -> unit = "ml_gtk_bitset_intersect"
(** Sets @self to be the intersection of @self and @other.

In other words, remove all values from @self that are not part of @other.

It is allowed for @self and @other to be the same bitset. Nothing will
happen in that case. *)

external get_size_in_range : t -> int -> int -> UInt64.t
  = "ml_gtk_bitset_get_size_in_range"
(** Gets the number of values that are part of the set from @first to @last
(inclusive).

Note that this function returns a `guint64`, because when all values are
set, the return value is `G_MAXUINT + 1`. Unless you are sure this cannot
happen (it can't with `GListModel`), be sure to use a 64bit type. *)

external get_size : t -> UInt64.t = "ml_gtk_bitset_get_size"
(** Gets the number of values that were added to the set.

    For example, if the set is empty, 0 is returned.

    Note that this function returns a `guint64`, because when all values are
    set, the return value is `G_MAXUINT + 1`. Unless you are sure this cannot
    happen (it can't with `GListModel`), be sure to use a 64bit type. *)

external get_nth : t -> int -> int = "ml_gtk_bitset_get_nth"
(** Returns the value of the @nth item in self.

If @nth is >= the size of @self, 0 is returned. *)

external get_minimum : t -> int = "ml_gtk_bitset_get_minimum"
(** Returns the smallest value in @self.

If @self is empty, `G_MAXUINT` is returned. *)

external get_maximum : t -> int = "ml_gtk_bitset_get_maximum"
(** Returns the largest value in @self.

If @self is empty, 0 is returned. *)

external equals : t -> t -> bool = "ml_gtk_bitset_equals"
(** Returns %TRUE if @self and @other contain the same values. *)

external difference : t -> t -> unit = "ml_gtk_bitset_difference"
(** Sets @self to be the symmetric difference of @self and @other.

The symmetric difference is set @self to contain all values that
were either contained in @self or in @other, but not in both.
This operation is also called an XOR.

It is allowed for @self and @other to be the same bitset. The bitset
will be emptied in that case. *)

external contains : t -> int -> bool = "ml_gtk_bitset_contains"
(** Checks if the given @value has been added to @self *)

external add_rectangle : t -> int -> int -> int -> int -> unit
  = "ml_gtk_bitset_add_rectangle"
(** Interprets the values as a 2-dimensional boolean grid with the given @stride
and inside that grid, adds a rectangle with the given @width and @height. *)

external add_range_closed : t -> int -> int -> unit
  = "ml_gtk_bitset_add_range_closed"
(** Adds the closed range [@first, @last], so @first, @last and all
values in between. @first must be smaller than @last. *)

external add_range : t -> int -> int -> unit = "ml_gtk_bitset_add_range"
(** Adds all values from @start (inclusive) to @start + @n_items
(exclusive) in @self. *)

external add : t -> int -> bool = "ml_gtk_bitset_add"
(** Adds @value to @self if it wasn't part of it before. *)
