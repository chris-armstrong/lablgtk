(* GENERATED CODE - DO NOT EDIT *)
(* Drop: Drop *)

type t = [ `drop | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_drop_get_type"

(* Methods *)

external status : t -> Gdk_enums.dragaction -> Gdk_enums.dragaction -> unit
  = "ml_gdk_drop_status"
(** Selects all actions that are potentially supported by the destination.

When calling this function, do not restrict the passed in actions to
the ones provided by [method@Gdk.Drop.get_actions]. Those actions may
change in the future, even depending on the actions you provide here.

The @preferred action is a hint to the drag-and-drop mechanism about which
action to use when multiple actions are possible.

This function should be called by drag destinations in response to
`GDK_DRAG_ENTER` or `GDK_DRAG_MOTION` events. If the destination does
not yet know the exact actions it supports, it should set any possible
actions first and then later call this function again. *)

external read_value_finish :
  t ->
  Ocgtk_gio.Gio.Wrappers.Async_result.t ->
  (Gobject.Value.t, GError.t) result = "ml_gdk_drop_read_value_finish"
(** Finishes an async drop read.

    See [method@Gdk.Drop.read_value_async]. *)

external get_surface : t -> App_launch_context_cycle_de440b34.Surface.t
  = "ml_gdk_drop_get_surface"
(** Returns the `GdkSurface` performing the drop. *)

external get_formats : t -> Content_formats.t = "ml_gdk_drop_get_formats"
(** Returns the `GdkContentFormats` that the drop offers the data to be read in.
*)

external get_drag : t -> Drag.t option = "ml_gdk_drop_get_drag"
(** If this is an in-app drag-and-drop operation, returns the `GdkDrag` that
    corresponds to this drop.

    If it is not, `NULL` is returned. *)

external get_display : t -> App_launch_context_cycle_de440b34.Display.t
  = "ml_gdk_drop_get_display"
(** Gets the `GdkDisplay` that @self was created for. *)

external get_device : t -> App_launch_context_cycle_de440b34.Device.t
  = "ml_gdk_drop_get_device"
(** Returns the `GdkDevice` performing the drop. *)

external get_actions : t -> Gdk_enums.dragaction = "ml_gdk_drop_get_actions"
(** Returns the possible actions for this `GdkDrop`.

    If this value contains multiple actions - i.e.
    [func@Gdk.DragAction.is_unique] returns false for the result -
    [method@Gdk.Drop.finish] must choose the action to use when accepting the
    drop. This will only happen if you passed `GDK_ACTION_ASK` as one of the
    possible actions in [method@Gdk.Drop.status]. `GDK_ACTION_ASK` itself will
    not be included in the actions returned by this function.

    This value may change over the lifetime of the [class@Gdk.Drop] both as a
    response to source side actions as well as to calls to
    [method@Gdk.Drop.status] or [method@Gdk.Drop.finish]. The source side will
    not change this value anymore once a drop has started. *)

external finish : t -> Gdk_enums.dragaction -> unit = "ml_gdk_drop_finish"
(** Ends the drag operation after a drop.

The @action must be a single action selected from the actions
available via [method@Gdk.Drop.get_actions]. *)

(* Properties *)
