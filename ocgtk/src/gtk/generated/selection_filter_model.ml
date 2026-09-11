(* GENERATED CODE - DO NOT EDIT *)
(* SelectionFilterModel: SelectionFilterModel *)

type t = [ `selection_filter_model | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gtk_selection_filter_model_get_type"

external new_ : Selection_model.t option -> t
  = "ml_gtk_selection_filter_model_new"
(** Create a new SelectionFilterModel *)

(* Methods *)

external set_model : t -> Selection_model.t option -> unit
  = "ml_gtk_selection_filter_model_set_model"
(** Sets the model to be filtered.

Note that GTK makes no effort to ensure that @model conforms to
the item type of @self. It assumes that the caller knows what they
are doing and have set up an appropriate filter to ensure that item
types match. *)

external get_model : t -> Selection_model.t option
  = "ml_gtk_selection_filter_model_get_model"
(** Gets the model currently filtered or %NULL if none. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_selection_filter_model_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_selection_filter_model_get_n_items"
(** Get property: n-items *)
