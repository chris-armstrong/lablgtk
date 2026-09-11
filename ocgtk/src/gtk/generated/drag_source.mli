(* GENERATED CODE - DO NOT EDIT *)
(* DragSource: DragSource *)

type t =
  [ `drag_source | `gesture_single | `gesture | `event_controller | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_drag_source_get_type"

external new_ : unit -> t = "ml_gtk_drag_source_new"
(** Create a new DragSource *)

(* Methods *)

external set_icon :
  t -> Ocgtk_gdk.Gdk.Wrappers.Paintable.t option -> int -> int -> unit
  = "ml_gtk_drag_source_set_icon"
(** Sets a paintable to use as icon during DND operations.

The hotspot coordinates determine the point on the icon
that gets aligned with the hotspot of the cursor.

If @paintable is %NULL, a default icon is used.

This function can be called before a drag is started, or in
a [signal@Gtk.DragSource::prepare] or
[signal@Gtk.DragSource::drag-begin] signal handler. *)

external set_content :
  t -> Ocgtk_gdk.Gdk.Wrappers.Content_provider.t option -> unit
  = "ml_gtk_drag_source_set_content"
(** Sets a content provider on a `GtkDragSource`.

    When the data is requested in the cause of a DND operation, it will be
    obtained from the content provider.

    This function can be called before a drag is started, or in a handler for
    the [signal@Gtk.DragSource::prepare] signal.

    You may consider setting the content provider back to %NULL in a
    [signal@Gtk.DragSource::drag-end] signal handler. *)

external set_actions : t -> Ocgtk_gdk.Gdk.dragaction -> unit
  = "ml_gtk_drag_source_set_actions"
(** Sets the actions on the `GtkDragSource`.

During a DND operation, the actions are offered to potential
drop targets. If @actions include %GDK_ACTION_MOVE, you need
to listen to the [signal@Gtk.DragSource::drag-end] signal and
handle @delete_data being %TRUE.

This function can be called before a drag is started,
or in a handler for the [signal@Gtk.DragSource::prepare] signal. *)

external get_drag : t -> Ocgtk_gdk.Gdk.Wrappers.Drag.t option
  = "ml_gtk_drag_source_get_drag"
(** Returns the underlying `GdkDrag` object for an ongoing drag. *)

external get_content : t -> Ocgtk_gdk.Gdk.Wrappers.Content_provider.t option
  = "ml_gtk_drag_source_get_content"
(** Gets the current content provider of a `GtkDragSource`. *)

external get_actions : t -> Ocgtk_gdk.Gdk.dragaction
  = "ml_gtk_drag_source_get_actions"
(** Gets the actions that are currently set on the `GtkDragSource`. *)

external drag_cancel : t -> unit = "ml_gtk_drag_source_drag_cancel"
(** Cancels a currently ongoing drag operation. *)

(* Properties *)

val on_drag_begin :
  ?after:bool ->
  t ->
  callback:(drag:Ocgtk_gdk.Gdk.Wrappers.Drag.t -> unit) ->
  Gobject.Signal.handler_id

val on_drag_cancel :
  ?after:bool ->
  t ->
  callback:
    (drag:Ocgtk_gdk.Gdk.Wrappers.Drag.t ->
    reason:Ocgtk_gdk.Gdk_enums.dragcancelreason ->
    bool) ->
  Gobject.Signal.handler_id

val on_drag_end :
  ?after:bool ->
  t ->
  callback:(drag:Ocgtk_gdk.Gdk.Wrappers.Drag.t -> delete_data:bool -> unit) ->
  Gobject.Signal.handler_id

val on_prepare :
  ?after:bool ->
  t ->
  callback:
    (x:float -> y:float -> Ocgtk_gdk.Gdk.Wrappers.Content_provider.t option) ->
  Gobject.Signal.handler_id
