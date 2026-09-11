(* GENERATED CODE - DO NOT EDIT *)
(* FlattenListModel: FlattenListModel *)

type t = [ `flatten_list_model | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_flatten_list_model_get_type"

external new_ : Ocgtk_gio.Gio.Wrappers.List_model.t option -> t
  = "ml_gtk_flatten_list_model_new"
(** Create a new FlattenListModel *)

(* Methods *)

external set_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option -> unit
  = "ml_gtk_flatten_list_model_set_model"
(** Sets a new model to be flattened. *)

external get_model_for_item :
  t -> int -> Ocgtk_gio.Gio.Wrappers.List_model.t option
  = "ml_gtk_flatten_list_model_get_model_for_item"
(** Returns the model containing the item at the given position. *)

external get_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option
  = "ml_gtk_flatten_list_model_get_model"
(** Gets the model set via gtk_flatten_list_model_set_model(). *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_flatten_list_model_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_flatten_list_model_get_n_items"
(** Get property: n-items *)
