(* GENERATED CODE - DO NOT EDIT *)
(* Notebook: Notebook *)

type t = [ `notebook | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_notebook_get_type"

external new_ : unit -> t = "ml_gtk_notebook_new"
(** Create a new Notebook *)

(* Methods *)

external set_tab_reorderable :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  bool ->
  unit = "ml_gtk_notebook_set_tab_reorderable"
(** Sets whether the notebook tab can be reordered via drag and drop or not. *)

external set_tab_pos : t -> Gtk_enums.positiontype -> unit
  = "ml_gtk_notebook_set_tab_pos"
(** Sets the edge at which the tabs are drawn. *)

external set_tab_label_text :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  string ->
  unit = "ml_gtk_notebook_set_tab_label_text"
(** Creates a new label and sets it as the tab label for the page
containing @child. *)

external set_tab_label :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_notebook_set_tab_label"
(** Changes the tab label for @child.

If %NULL is specified for @tab_label, then the page will
have the label “page N”. *)

external set_tab_detachable :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  bool ->
  unit = "ml_gtk_notebook_set_tab_detachable"
(** Sets whether the tab can be detached from @notebook to another
notebook or widget.

Note that two notebooks must share a common group identifier
(see [method@Gtk.Notebook.set_group_name]) to allow automatic tabs
interchange between them.

If you want a widget to interact with a notebook through DnD
(i.e.: accept dragged tabs from it) it must be set as a drop
destination by adding to it a [class@Gtk.DropTarget] controller that accepts
the GType `GTK_TYPE_NOTEBOOK_PAGE`. The `:value` of said drop target will be
preloaded with a [class@Gtk.NotebookPage] object that corresponds to the
dropped tab, so you can process the value via `::accept` or `::drop` signals.

Note that you should use [method@Gtk.Notebook.detach_tab] instead
of [method@Gtk.Notebook.remove_page] if you want to remove the tab
from the source notebook as part of accepting a drop. Otherwise,
the source notebook will think that the dragged tab was removed
from underneath the ongoing drag operation, and will initiate a
drag cancel animation.

```c
static void
on_drag_data_received (GtkWidget        *widget,
                       GdkDrop          *drop,
                       GtkSelectionData *data,
                       guint             time,
                       gpointer          user_data)
{
  GtkDrag *drag;
  GtkWidget *notebook;
  GtkWidget **child;

  drag = gtk_drop_get_drag (drop);
  notebook = g_object_get_data (drag, "gtk-notebook-drag-origin");
  child = (void*\) gtk_selection_data_get_data (data);

  // process_widget (\*child);

  gtk_notebook_detach_tab (GTK_NOTEBOOK (notebook), *child);
}
```

If you want a notebook to accept drags from other widgets,
you will have to set your own DnD code to do it. *)

external set_show_tabs : t -> bool -> unit = "ml_gtk_notebook_set_show_tabs"
(** Sets whether to show the tabs for the notebook or not. *)

external set_show_border : t -> bool -> unit = "ml_gtk_notebook_set_show_border"
(** Sets whether a bevel will be drawn around the notebook pages.

    This only has a visual effect when the tabs are not shown. *)

external set_scrollable : t -> bool -> unit = "ml_gtk_notebook_set_scrollable"
(** Sets whether the tab label area will have arrows for scrolling if there are
    too many tabs to fit in the area. *)

external set_menu_label_text :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  string ->
  unit = "ml_gtk_notebook_set_menu_label_text"
(** Creates a new label and sets it as the menu label of @child. *)

external set_menu_label :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_notebook_set_menu_label"
(** Changes the menu label for the page containing @child. *)

external set_group_name : t -> string option -> unit
  = "ml_gtk_notebook_set_group_name"
(** Sets a group name for @notebook.

Notebooks with the same name will be able to exchange tabs
via drag and drop. A notebook with a %NULL group name will
not be able to exchange tabs with any other notebook. *)

external set_current_page : t -> int -> unit
  = "ml_gtk_notebook_set_current_page"
(** Switches to the page number @page_num.

Note that due to historical reasons, GtkNotebook refuses
to switch to a page unless the child widget is visible.
Therefore, it is recommended to show child widgets before
adding them to a notebook. *)

external set_action_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Gtk_enums.packtype ->
  unit = "ml_gtk_notebook_set_action_widget"
(** Sets @widget as one of the action widgets.

Depending on the pack type the widget will be placed before
or after the tabs. You can use a `GtkBox` if you need to pack
more than one widget on the same side. *)

external reorder_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int ->
  unit = "ml_gtk_notebook_reorder_child"
(** Reorders the page containing @child, so that it appears in position
@position.

If @position is greater than or equal to the number of children in
the list or negative, @child will be moved to the end of the list. *)

external remove_page : t -> int -> unit = "ml_gtk_notebook_remove_page"
(** Removes a page from the notebook given its index in the notebook. *)

external prev_page : t -> unit = "ml_gtk_notebook_prev_page"
(** Switches to the previous page.

    Nothing happens if the current page is the first page. *)

external prepend_page_menu :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  int = "ml_gtk_notebook_prepend_page_menu"
(** Prepends a page to @notebook, specifying the widget to use as the
label in the popup menu. *)

external prepend_page :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  int = "ml_gtk_notebook_prepend_page"
(** Prepends a page to @notebook. *)

external popup_enable : t -> unit = "ml_gtk_notebook_popup_enable"
(** Enables the popup menu.

    If the user clicks with the right mouse button on the tab labels, a menu
    with all the pages will be popped up. *)

external popup_disable : t -> unit = "ml_gtk_notebook_popup_disable"
(** Disables the popup menu. *)

external page_num :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int = "ml_gtk_notebook_page_num"
(** Finds the index of the page which contains the given child widget. *)

external next_page : t -> unit = "ml_gtk_notebook_next_page"
(** Switches to the next page.

    Nothing happens if the current page is the last page. *)

external insert_page_menu :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  int ->
  int = "ml_gtk_notebook_insert_page_menu"
(** Insert a page into @notebook at the given position, specifying
the widget to use as the label in the popup menu. *)

external insert_page :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  int ->
  int = "ml_gtk_notebook_insert_page"
(** Insert a page into @notebook at the given position. *)

external get_tab_reorderable :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  bool = "ml_gtk_notebook_get_tab_reorderable"
(** Gets whether the tab can be reordered via drag and drop or not. *)

external get_tab_pos : t -> Gtk_enums.positiontype
  = "ml_gtk_notebook_get_tab_pos"
(** Gets the edge at which the tabs are drawn. *)

external get_tab_label_text :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  string option = "ml_gtk_notebook_get_tab_label_text"
(** Retrieves the text of the tab label for the page containing
@child. *)

external get_tab_label :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_notebook_get_tab_label"
(** Returns the tab label widget for the page @child.

%NULL is returned if @child is not in @notebook or
if no tab label has specifically been set for @child. *)

external get_tab_detachable :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  bool = "ml_gtk_notebook_get_tab_detachable"
(** Returns whether the tab contents can be detached from @notebook. *)

external get_show_tabs : t -> bool = "ml_gtk_notebook_get_show_tabs"
(** Returns whether the tabs of the notebook are shown. *)

external get_show_border : t -> bool = "ml_gtk_notebook_get_show_border"
(** Returns whether a bevel will be drawn around the notebook pages. *)

external get_scrollable : t -> bool = "ml_gtk_notebook_get_scrollable"
(** Returns whether the tab label area has arrows for scrolling. *)

external get_pages : t -> Ocgtk_gio.Gio.Wrappers.List_model.t
  = "ml_gtk_notebook_get_pages"
(** Returns a `GListModel` that contains the pages of the notebook.

    This can be used to keep an up-to-date view. The model also implements
    [iface@Gtk.SelectionModel] and can be used to track and modify the visible
    page. *)

external get_page :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Notebook_page.t = "ml_gtk_notebook_get_page"
(** Returns the `GtkNotebookPage` for @child. *)

external get_nth_page :
  t ->
  int ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_notebook_get_nth_page"
(** Returns the child widget contained in page number @page_num. *)

external get_n_pages : t -> int = "ml_gtk_notebook_get_n_pages"
(** Gets the number of pages in a notebook. *)

external get_menu_label_text :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  string option = "ml_gtk_notebook_get_menu_label_text"
(** Retrieves the text of the menu label for the page containing
@child. *)

external get_menu_label :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_notebook_get_menu_label"
(** Retrieves the menu label widget of the page containing @child. *)

external get_group_name : t -> string option = "ml_gtk_notebook_get_group_name"
(** Gets the current group name for @notebook. *)

external get_current_page : t -> int = "ml_gtk_notebook_get_current_page"
(** Returns the page number of the current page. *)

external get_action_widget :
  t ->
  Gtk_enums.packtype ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_notebook_get_action_widget"
(** Gets one of the action widgets.

    See [method@Gtk.Notebook.set_action_widget]. *)

external detach_tab :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_notebook_detach_tab"
(** Removes the child from the notebook.

    This function is very similar to [method@Gtk.Notebook.remove_page], but
    additionally informs the notebook that the removal is happening as part of a
    tab DND operation, which should not be cancelled. *)

external append_page_menu :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  int = "ml_gtk_notebook_append_page_menu"
(** Appends a page to @notebook, specifying the widget to use as the
label in the popup menu. *)

external append_page :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  int = "ml_gtk_notebook_append_page"
(** Appends a page to @notebook. *)

(* Properties *)

external get_enable_popup : t -> bool = "ml_gtk_notebook_get_enable_popup"
(** Get property: enable-popup *)

external set_enable_popup : t -> bool -> unit
  = "ml_gtk_notebook_set_enable_popup"
(** Set property: enable-popup *)

let on_change_current_page ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let page =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_int v
        in
        let result = callback ~page in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"change-current-page" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_create_window ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let page =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
             .Widget
             .gtype ())
        in
        let result = callback ~page in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_object v (gtype ()) x)
  in
  Gobject.Signal.connect obj ~name:"create-window" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_focus_tab ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let tab =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gtk_enums.notebooktab_of_int (Gobject.Value.get_enum_int v)
        in
        let result = callback ~tab in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"focus-tab" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_move_focus_out ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let direction =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gtk_enums.directiontype_of_int (Gobject.Value.get_enum_int v)
        in
        callback ~direction)
  in
  Gobject.Signal.connect obj ~name:"move-focus-out" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_page_added ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let child =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
             .Widget
             .gtype ())
        in
        let page_num =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_uint v
        in
        callback ~child ~page_num)
  in
  Gobject.Signal.connect obj ~name:"page-added" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_page_removed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let child =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
             .Widget
             .gtype ())
        in
        let page_num =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_uint v
        in
        callback ~child ~page_num)
  in
  Gobject.Signal.connect obj ~name:"page-removed" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_page_reordered ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let child =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
             .Widget
             .gtype ())
        in
        let page_num =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_uint v
        in
        callback ~child ~page_num)
  in
  Gobject.Signal.connect obj ~name:"page-reordered" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_reorder_tab ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let direction =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gtk_enums.directiontype_of_int (Gobject.Value.get_enum_int v)
        in
        let move_to_last =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_boolean v
        in
        let result = callback ~direction ~move_to_last in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"reorder-tab" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_select_page ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let move_focus =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_boolean v
        in
        let result = callback ~move_focus in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"select-page" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_switch_page ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let page =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
             .Widget
             .gtype ())
        in
        let page_num =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_uint v
        in
        callback ~page ~page_num)
  in
  Gobject.Signal.connect obj ~name:"switch-page" ~callback:closure
    ~after:(Option.value after ~default:false)
