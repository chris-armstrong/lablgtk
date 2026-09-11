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

let on_drag_begin ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drag =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Ocgtk_gdk.Gdk.Wrappers.Drag.gtype ())
        in
        callback ~drag)
  in
  Gobject.Signal.connect obj ~name:"drag-begin" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_drag_cancel ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drag =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Ocgtk_gdk.Gdk.Wrappers.Drag.gtype ())
        in
        let reason =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Ocgtk_gdk.Gdk_enums.dragcancelreason_of_int
            (Gobject.Value.get_enum_int v)
        in
        let result = callback ~drag ~reason in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"drag-cancel" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_drag_end ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let drag =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Ocgtk_gdk.Gdk.Wrappers.Drag.gtype ())
        in
        let delete_data =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_boolean v
        in
        callback ~drag ~delete_data)
  in
  Gobject.Signal.connect obj ~name:"drag-end" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_prepare ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let x =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_double v
        in
        let y =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_double v
        in
        let result = callback ~x ~y in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_object v
          (Ocgtk_gdk.Gdk.Wrappers.Content_provider.gtype ())
          x)
  in
  Gobject.Signal.connect obj ~name:"prepare" ~callback:closure
    ~after:(Option.value after ~default:false)
