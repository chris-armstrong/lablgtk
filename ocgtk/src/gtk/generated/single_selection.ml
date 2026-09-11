(* GENERATED CODE - DO NOT EDIT *)
(* SingleSelection: SingleSelection *)

type t = [ `single_selection | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_single_selection_get_type"

external new_ : Ocgtk_gio.Gio.Wrappers.List_model.t option -> t
  = "ml_gtk_single_selection_new"
(** Create a new SingleSelection *)

(* Methods *)

external set_selected : t -> int -> unit
  = "ml_gtk_single_selection_set_selected"
(** Selects the item at the given position.

If the list does not have an item at @position or
%GTK_INVALID_LIST_POSITION is given, the behavior depends on the
value of the [property@Gtk.SingleSelection:autoselect] property:
If it is set, no change will occur and the old item will stay
selected. If it is unset, the selection will be unset and no item
will be selected. This also applies if [property@Gtk.SingleSelection:can-unselect]
is set to %FALSE. *)

external set_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option -> unit
  = "ml_gtk_single_selection_set_model"
(** Sets the model that @self should wrap.

If @model is %NULL, @self will be empty. *)

external set_can_unselect : t -> bool -> unit
  = "ml_gtk_single_selection_set_can_unselect"
(** If %TRUE, unselecting the current item via
    gtk_selection_model_unselect_item() is supported.

    Note that setting [property@Gtk.SingleSelection:autoselect] will cause
    unselecting to not work, so it practically makes no sense to set both at the
    same time. *)

external set_autoselect : t -> bool -> unit
  = "ml_gtk_single_selection_set_autoselect"
(** Enables or disables autoselect.

If @autoselect is %TRUE, @self will enforce that an item is always
selected. It will select a new item when the currently selected
item is deleted and it will disallow unselecting the current item. *)

external get_selected_item : t -> [ `object_ ] Gobject.obj option
  = "ml_gtk_single_selection_get_selected_item"
(** Gets the selected item.

    If no item is selected, %NULL is returned. *)

external get_selected : t -> int = "ml_gtk_single_selection_get_selected"
(** Gets the position of the selected item.

    If no item is selected, %GTK_INVALID_LIST_POSITION is returned. *)

external get_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option
  = "ml_gtk_single_selection_get_model"
(** Gets the model that @self is wrapping. *)

external get_can_unselect : t -> bool
  = "ml_gtk_single_selection_get_can_unselect"
(** If %TRUE, gtk_selection_model_unselect_item() is supported and allows
    unselecting the selected item. *)

external get_autoselect : t -> bool = "ml_gtk_single_selection_get_autoselect"
(** Checks if autoselect has been enabled or disabled via
    gtk_single_selection_set_autoselect(). *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_single_selection_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_single_selection_get_n_items"
(** Get property: n-items *)
