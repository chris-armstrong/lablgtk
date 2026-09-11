(* GENERATED CODE - DO NOT EDIT *)
(* SliceListModel: SliceListModel *)

type t = [ `slice_list_model | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_slice_list_model_get_type"

external new_ : Ocgtk_gio.Gio.Wrappers.List_model.t option -> int -> int -> t
  = "ml_gtk_slice_list_model_new"
(** Create a new SliceListModel *)

(* Methods *)

external set_size : t -> int -> unit = "ml_gtk_slice_list_model_set_size"
(** Sets the maximum size. @self will never have more items
than @size.

It can however have fewer items if the offset is too large
or the model sliced from doesn't have enough items. *)

external set_offset : t -> int -> unit = "ml_gtk_slice_list_model_set_offset"
(** Sets the offset into the original model for this slice.

If the offset is too large for the sliced model,
@self will end up empty. *)

external set_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option -> unit
  = "ml_gtk_slice_list_model_set_model"
(** Sets the model to show a slice of.

The model's item type must conform to @self's item type. *)

external get_size : t -> int = "ml_gtk_slice_list_model_get_size"
(** Gets the size set via gtk_slice_list_model_set_size(). *)

external get_offset : t -> int = "ml_gtk_slice_list_model_get_offset"
(** Gets the offset set via gtk_slice_list_model_set_offset(). *)

external get_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option
  = "ml_gtk_slice_list_model_get_model"
(** Gets the model that is currently being used or %NULL if none. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_slice_list_model_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_slice_list_model_get_n_items"
(** Get property: n-items *)
