(* GENERATED CODE - DO NOT EDIT *)
(* SortListModel: SortListModel *)

type t = [ `sort_list_model | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_sort_list_model_get_type"

external new_ :
  Ocgtk_gio.Gio.Wrappers.List_model.t option -> Sorter.t option -> t
  = "ml_gtk_sort_list_model_new"
(** Create a new SortListModel *)

(* Methods *)

external set_sorter : t -> Sorter.t option -> unit
  = "ml_gtk_sort_list_model_set_sorter"
(** Sets a new sorter on @self. *)

external set_section_sorter : t -> Sorter.t option -> unit
  = "ml_gtk_sort_list_model_set_section_sorter"
(** Sets a new section sorter on @self. *)

external set_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option -> unit
  = "ml_gtk_sort_list_model_set_model"
(** Sets the model to be sorted.

The @model's item type must conform to the item type of @self. *)

external set_incremental : t -> bool -> unit
  = "ml_gtk_sort_list_model_set_incremental"
(** Sets the sort model to do an incremental sort.

    When incremental sorting is enabled, the `GtkSortListModel` will not do a
    complete sort immediately, but will instead queue an idle handler that
    incrementally sorts the items towards their correct position. This of course
    means that items do not instantly appear in the right place. It also means
    that the total sorting time is a lot slower.

    When your filter blocks the UI while sorting, you might consider turning
    this on. Depending on your model and sorters, this may become interesting
    around 10,000 to 100,000 items.

    By default, incremental sorting is disabled.

    See [method@Gtk.SortListModel.get_pending] for progress information about an
    ongoing incremental sorting operation. *)

external get_sorter : t -> Sorter.t option = "ml_gtk_sort_list_model_get_sorter"
(** Gets the sorter that is used to sort @self. *)

external get_section_sorter : t -> Sorter.t option
  = "ml_gtk_sort_list_model_get_section_sorter"
(** Gets the section sorter that is used to sort items of @self into
sections. *)

external get_pending : t -> int = "ml_gtk_sort_list_model_get_pending"
(** Estimates progress of an ongoing sorting operation.

    The estimate is the number of items that would still need to be sorted to
    finish the sorting operation if this was a linear algorithm. So this number
    is not related to how many items are already correctly sorted.

    If you want to estimate the progress, you can use code like this: ```c
    pending = gtk_sort_list_model_get_pending (self); model =
    gtk_sort_list_model_get_model (self); progress = 1.0 - pending / (double)
    MAX (1, g_list_model_get_n_items (model)); ```

    If no sort operation is ongoing - in particular when
    [property@Gtk.SortListModel:incremental] is %FALSE - this function returns
    0. *)

external get_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option
  = "ml_gtk_sort_list_model_get_model"
(** Gets the model currently sorted or %NULL if none. *)

external get_incremental : t -> bool = "ml_gtk_sort_list_model_get_incremental"
(** Returns whether incremental sorting is enabled.

    See [method@Gtk.SortListModel.set_incremental]. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_sort_list_model_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_sort_list_model_get_n_items"
(** Get property: n-items *)
