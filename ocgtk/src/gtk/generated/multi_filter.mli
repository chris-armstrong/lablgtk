(* GENERATED CODE - DO NOT EDIT *)
(* MultiFilter: MultiFilter *)

type t = [ `multi_filter | `filter | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_multi_filter_get_type"

(* Methods *)

external remove : t -> int -> unit = "ml_gtk_multi_filter_remove"
(** Removes a filter.

If @position is larger than the number of filters,
nothing happens. *)

external append : t -> Filter.t -> unit = "ml_gtk_multi_filter_append"
(** Adds a filter. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_multi_filter_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_multi_filter_get_n_items"
(** Get property: n-items *)
