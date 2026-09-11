(* GENERATED CODE - DO NOT EDIT *)
(* Drag: Drag *)

type t = [ `drag | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_drag_get_type"

(* Methods *)

external set_hotspot : t -> int -> int -> unit = "ml_gdk_drag_set_hotspot"
(** Sets the position of the drag surface that will be kept under the cursor
    hotspot.

    Initially, the hotspot is at the top left corner of the drag surface. *)

external get_surface : t -> App_launch_context_cycle_de440b34.Surface.t
  = "ml_gdk_drag_get_surface"
(** Returns the `GdkSurface` where the drag originates. *)

external get_selected_action : t -> Gdk_enums.dragaction
  = "ml_gdk_drag_get_selected_action"
(** Determines the action chosen by the drag destination. *)

external get_formats : t -> Content_formats.t = "ml_gdk_drag_get_formats"
(** Retrieves the formats supported by this `GdkDrag` object. *)

external get_drag_surface :
  t -> App_launch_context_cycle_de440b34.Surface.t option
  = "ml_gdk_drag_get_drag_surface"
(** Returns the surface on which the drag icon should be rendered
during the drag operation.

Note that the surface may not be available until the drag operation
has begun. GDK will move the surface in accordance with the ongoing
drag operation. The surface is owned by @drag and will be destroyed
when the drag operation is over. *)

external get_display : t -> App_launch_context_cycle_de440b34.Display.t
  = "ml_gdk_drag_get_display"
(** Gets the `GdkDisplay` that the drag object was created for. *)

external get_device : t -> App_launch_context_cycle_de440b34.Device.t
  = "ml_gdk_drag_get_device"
(** Returns the `GdkDevice` associated to the `GdkDrag` object. *)

external get_content : t -> Content_provider.t = "ml_gdk_drag_get_content"
(** Returns the `GdkContentProvider` associated to the `GdkDrag` object. *)

external get_actions : t -> Gdk_enums.dragaction = "ml_gdk_drag_get_actions"
(** Determines the bitmask of possible actions proposed by the source. *)

external drop_done : t -> bool -> unit = "ml_gdk_drag_drop_done"
(** Informs GDK that the drop ended.

Passing %FALSE for @success may trigger a drag cancellation
animation.

This function is called by the drag source, and should be the
last call before dropping the reference to the @drag.

The `GdkDrag` will only take the first [method@Gdk.Drag.drop_done]
call as effective, if this function is called multiple times,
all subsequent calls will be ignored. *)

(* Properties *)

let on_cancel ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let reason =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gdk_enums.dragcancelreason_of_int (Gobject.Value.get_enum_int v)
        in
        callback ~reason)
  in
  Gobject.Signal.connect obj ~name:"cancel" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_dnd_finished ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"dnd-finished" ~callback
    ~after:(Option.value after ~default:false)

let on_drop_performed ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"drop-performed" ~callback
    ~after:(Option.value after ~default:false)
