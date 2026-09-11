(* GENERATED CODE - DO NOT EDIT *)
(* DropTargetAsync: DropTargetAsync *)

type t = [ `drop_target_async | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_drop_target_async_get_type"

external new_ :
  Ocgtk_gdk.Gdk.Wrappers.Content_formats.t option ->
  Ocgtk_gdk.Gdk.dragaction ->
  t = "ml_gtk_drop_target_async_new"
(** Create a new DropTargetAsync *)

(* Methods *)

external set_formats :
  t -> Ocgtk_gdk.Gdk.Wrappers.Content_formats.t option -> unit
  = "ml_gtk_drop_target_async_set_formats"
(** Sets the data formats that this drop target will accept. *)

external set_actions : t -> Ocgtk_gdk.Gdk.dragaction -> unit
  = "ml_gtk_drop_target_async_set_actions"
(** Sets the actions that this drop target supports. *)

external reject_drop : t -> Ocgtk_gdk.Gdk.Wrappers.Drop.t -> unit
  = "ml_gtk_drop_target_async_reject_drop"
(** Sets the @drop as not accepted on this drag site.

This function should be used when delaying the decision
on whether to accept a drag or not until after reading
the data. *)

external get_formats : t -> Ocgtk_gdk.Gdk.Wrappers.Content_formats.t option
  = "ml_gtk_drop_target_async_get_formats"
(** Gets the data formats that this drop target accepts.

    If the result is %NULL, all formats are expected to be supported. *)

external get_actions : t -> Ocgtk_gdk.Gdk.dragaction
  = "ml_gtk_drop_target_async_get_actions"
(** Gets the actions that this drop target supports. *)

(* Properties *)

val on_accept :
  ?after:bool ->
  t ->
  callback:(drop:Ocgtk_gdk.Gdk.Wrappers.Drop.t -> bool) ->
  Gobject.Signal.handler_id

val on_drag_enter :
  ?after:bool ->
  t ->
  callback:
    (drop:Ocgtk_gdk.Gdk.Wrappers.Drop.t ->
    x:float ->
    y:float ->
    Ocgtk_gdk.Gdk_enums.dragaction) ->
  Gobject.Signal.handler_id

val on_drag_leave :
  ?after:bool ->
  t ->
  callback:(drop:Ocgtk_gdk.Gdk.Wrappers.Drop.t -> unit) ->
  Gobject.Signal.handler_id

val on_drag_motion :
  ?after:bool ->
  t ->
  callback:
    (drop:Ocgtk_gdk.Gdk.Wrappers.Drop.t ->
    x:float ->
    y:float ->
    Ocgtk_gdk.Gdk_enums.dragaction) ->
  Gobject.Signal.handler_id

val on_drop :
  ?after:bool ->
  t ->
  callback:(drop:Ocgtk_gdk.Gdk.Wrappers.Drop.t -> x:float -> y:float -> bool) ->
  Gobject.Signal.handler_id
