(* GENERATED CODE - DO NOT EDIT *)
(* DropControllerMotion: DropControllerMotion *)

type t = [ `drop_controller_motion | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gtk_drop_controller_motion_get_type"

external new_ : unit -> t = "ml_gtk_drop_controller_motion_new"
(** Create a new DropControllerMotion *)

(* Methods *)

external is_pointer : t -> bool = "ml_gtk_drop_controller_motion_is_pointer"
(** Returns if a Drag-and-Drop operation is within the widget
@self, not one of its children. *)

external get_drop : t -> Ocgtk_gdk.Gdk.Wrappers.Drop.t option
  = "ml_gtk_drop_controller_motion_get_drop"
(** Returns the `GdkDrop` of a current Drag-and-Drop operation
over the widget of @self. *)

external contains_pointer : t -> bool
  = "ml_gtk_drop_controller_motion_contains_pointer"
(** Returns if a Drag-and-Drop operation is within the widget
@self or one of its children. *)

(* Properties *)

val on_enter :
  ?after:bool ->
  t ->
  callback:(x:float -> y:float -> unit) ->
  Gobject.Signal.handler_id

val on_leave :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_motion :
  ?after:bool ->
  t ->
  callback:(x:float -> y:float -> unit) ->
  Gobject.Signal.handler_id
