(* GENERATED CODE - DO NOT EDIT *)
(* MapListModel: MapListModel *)

type t = [ `map_list_model | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_map_list_model_get_type"

(* Methods *)

external set_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option -> unit
  = "ml_gtk_map_list_model_set_model"
(** Sets the model to be mapped.

GTK makes no effort to ensure that @model conforms to the item type
expected by the map function. It assumes that the caller knows what
they are doing and have set up an appropriate map function. *)

external has_map : t -> bool = "ml_gtk_map_list_model_has_map"
(** Checks if a map function is currently set on @self. *)

external get_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option
  = "ml_gtk_map_list_model_get_model"
(** Gets the model that is currently being mapped or %NULL if none. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_map_list_model_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_map_list_model_get_n_items"
(** Get property: n-items *)
