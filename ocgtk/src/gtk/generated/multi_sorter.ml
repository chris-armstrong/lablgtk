(* GENERATED CODE - DO NOT EDIT *)
(* MultiSorter: MultiSorter *)

type t = [ `multi_sorter | `sorter | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_multi_sorter_get_type"

external new_ : unit -> t = "ml_gtk_multi_sorter_new"
(** Create a new MultiSorter *)

(* Methods *)

external remove : t -> int -> unit = "ml_gtk_multi_sorter_remove"
(** Removes the sorter at the given @position from the list of sorter
used by @self.

If @position is larger than the number of sorters, nothing happens. *)

external append : t -> Sorter.t -> unit = "ml_gtk_multi_sorter_append"
(** Add @sorter to @self to use for sorting at the end.

@self will consult all existing sorters before it will
sort with the given @sorter. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_multi_sorter_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_multi_sorter_get_n_items"
(** Get property: n-items *)
