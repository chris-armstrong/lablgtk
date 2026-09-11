(* GENERATED CODE - DO NOT EDIT *)
(* FilterListModel: FilterListModel *)

type t = [ `filter_list_model | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_filter_list_model_get_type"

external new_ :
  Ocgtk_gio.Gio.Wrappers.List_model.t option -> Filter.t option -> t
  = "ml_gtk_filter_list_model_new"
(** Create a new FilterListModel *)

(* Methods *)

external set_watch_items : t -> bool -> unit
  = "ml_gtk_filter_list_model_set_watch_items"
(** Sets the filter model to monitor properties of its items.

    This allows implementations of [class@Gtk.Filter] that support expression
    watching to react to property changes. This property has no effect if the
    current filter doesn't support watching items.

    By default, watching items is disabled. *)

external set_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option -> unit
  = "ml_gtk_filter_list_model_set_model"
(** Sets the model to be filtered.

Note that GTK makes no effort to ensure that @model conforms to
the item type of @self. It assumes that the caller knows what they
are doing and have set up an appropriate filter to ensure that item
types match. *)

external set_incremental : t -> bool -> unit
  = "ml_gtk_filter_list_model_set_incremental"
(** Sets the filter model to do an incremental sort.

    When incremental filtering is enabled, the `GtkFilterListModel` will not run
    filters immediately, but will instead queue an idle handler that
    incrementally filters the items and adds them to the list. This of course
    means that items are not instantly added to the list, but only appear
    incrementally.

    When your filter blocks the UI while filtering, you might consider turning
    this on. Depending on your model and filters, this may become interesting
    around 10,000 to 100,000 items.

    By default, incremental filtering is disabled.

    See [method@Gtk.FilterListModel.get_pending] for progress information about
    an ongoing incremental filtering operation. *)

external set_filter : t -> Filter.t option -> unit
  = "ml_gtk_filter_list_model_set_filter"
(** Sets the filter used to filter items. *)

external get_watch_items : t -> bool
  = "ml_gtk_filter_list_model_get_watch_items"
(** Returns whether watching items is enabled.

    See [method@Gtk.FilterListModel.set_watch_items]. *)

external get_pending : t -> int = "ml_gtk_filter_list_model_get_pending"
(** Returns the number of items that have not been filtered yet.

You can use this value to check if @self is busy filtering by
comparing the return value to 0 or you can compute the percentage
of the filter remaining by dividing the return value by the total
number of items in the underlying model:

```c
pending = gtk_filter_list_model_get_pending (self);
model = gtk_filter_list_model_get_model (self);
percentage = pending / (double) g_list_model_get_n_items (model);
```

If no filter operation is ongoing - in particular when
[property@Gtk.FilterListModel:incremental] is %FALSE - this
function returns 0. *)

external get_model : t -> Ocgtk_gio.Gio.Wrappers.List_model.t option
  = "ml_gtk_filter_list_model_get_model"
(** Gets the model currently filtered or %NULL if none. *)

external get_incremental : t -> bool
  = "ml_gtk_filter_list_model_get_incremental"
(** Returns whether incremental filtering is enabled.

    See [method@Gtk.FilterListModel.set_incremental]. *)

external get_filter : t -> Filter.t option
  = "ml_gtk_filter_list_model_get_filter"
(** Gets the `GtkFilter` currently set on @self. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_filter_list_model_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_filter_list_model_get_n_items"
(** Get property: n-items *)
