(* GENERATED CODE - DO NOT EDIT *)
(* ListView: ListView *)

type t =
  [ `list_view | `list_base | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_list_view_get_type"

external new_ : Selection_model.t option -> List_item_factory.t option -> t
  = "ml_gtk_list_view_new"
(** Create a new ListView *)

(* Methods *)

external set_tab_behavior : t -> Gtk_enums.listtabbehavior -> unit
  = "ml_gtk_list_view_set_tab_behavior"
(** Sets the <kbd>Tab</kbd> key behavior.

    This influences how the <kbd>Tab</kbd> and <kbd>Shift</kbd>+<kbd>Tab</kbd>
    keys move the focus in the listview. *)

external set_single_click_activate : t -> bool -> unit
  = "ml_gtk_list_view_set_single_click_activate"
(** Sets whether rows should be activated on single click and selected on hover.
*)

external set_show_separators : t -> bool -> unit
  = "ml_gtk_list_view_set_show_separators"
(** Sets whether the listview should show separators between rows. *)

external set_model : t -> Selection_model.t option -> unit
  = "ml_gtk_list_view_set_model"
(** Sets the model to use.

    This must be a [iface@Gtk.SelectionModel] to use. *)

external set_header_factory : t -> List_item_factory.t option -> unit
  = "ml_gtk_list_view_set_header_factory"
(** Sets the `GtkListItemFactory` to use for populating the
    [class@Gtk.ListHeader] objects used in section headers.

    If this factory is set to `NULL`, the list will not show section headers. *)

external set_factory : t -> List_item_factory.t option -> unit
  = "ml_gtk_list_view_set_factory"
(** Sets the `GtkListItemFactory` to use for populating list items. *)

external set_enable_rubberband : t -> bool -> unit
  = "ml_gtk_list_view_set_enable_rubberband"
(** Sets whether selections can be changed by dragging with the mouse. *)

external scroll_to :
  t -> int -> Gtk_enums.listscrollflags -> Scroll_info.t option -> unit
  = "ml_gtk_list_view_scroll_to"
(** Scrolls to the item at the given position and performs the actions
specified in @flags.

This function works no matter if the listview is shown or focused.
If it isn't, then the changes will take effect once that happens. *)

external get_tab_behavior : t -> Gtk_enums.listtabbehavior
  = "ml_gtk_list_view_get_tab_behavior"
(** Gets the behavior set for the <kbd>Tab</kbd> key. *)

external get_single_click_activate : t -> bool
  = "ml_gtk_list_view_get_single_click_activate"
(** Returns whether rows will be activated on single click and selected on
    hover. *)

external get_show_separators : t -> bool
  = "ml_gtk_list_view_get_show_separators"
(** Returns whether the listview should show separators between rows. *)

external get_model : t -> Selection_model.t option
  = "ml_gtk_list_view_get_model"
(** Gets the model that's currently used to read the items displayed. *)

external get_header_factory : t -> List_item_factory.t option
  = "ml_gtk_list_view_get_header_factory"
(** Gets the factory that's currently used to populate section headers. *)

external get_factory : t -> List_item_factory.t option
  = "ml_gtk_list_view_get_factory"
(** Gets the factory that's currently used to populate list items. *)

external get_enable_rubberband : t -> bool
  = "ml_gtk_list_view_get_enable_rubberband"
(** Returns whether rows can be selected by dragging with the mouse. *)

(* Properties *)

let on_activate ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let position =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_uint v
        in
        callback ~position)
  in
  Gobject.Signal.connect obj ~name:"activate" ~callback:closure
    ~after:(Option.value after ~default:false)
