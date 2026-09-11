(* GENERATED CODE - DO NOT EDIT *)
(* NoSelection: NoSelection *)

type t = [ `no_selection | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_no_selection_get_type"

external new_ : Ocgtk_gio.Gio.Wrappers.List_model.t option -> t
  = "ml_gtk_no_selection_new"
(** Create a new NoSelection *)

(* Methods *)

external set_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option -> unit
  = "ml_gtk_no_selection_set_model"
(** Sets the model that @self should wrap.

If @model is %NULL, this model will be empty. *)

external get_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option
  = "ml_gtk_no_selection_get_model"
(** Gets the model that @self is wrapping. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_no_selection_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_no_selection_get_n_items"
(** Get property: n-items *)
