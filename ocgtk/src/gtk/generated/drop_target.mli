(* GENERATED CODE - DO NOT EDIT *)
(* DropTarget: DropTarget *)

type t = [ `drop_target | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_drop_target_get_type"

external new_ : Gobject.Type.t -> Ocgtk_gdk.Gdk.dragaction -> t
  = "ml_gtk_drop_target_new"
(** Create a new DropTarget *)

(* Methods *)

external set_preload : t -> bool -> unit = "ml_gtk_drop_target_set_preload"
(** Sets whether data should be preloaded on hover. *)

external set_gtypes : t -> Gobject.Type.t array option -> Gsize.t -> unit
  = "ml_gtk_drop_target_set_gtypes"
(** Sets the supported `GType`s for this drop target. *)

external set_actions : t -> Ocgtk_gdk.Gdk.dragaction -> unit
  = "ml_gtk_drop_target_set_actions"
(** Sets the actions that this drop target supports. *)

external reject : t -> unit = "ml_gtk_drop_target_reject"
(** Rejects the ongoing drop operation.

    If no drop operation is ongoing, i.e when
    [property@Gtk.DropTarget:current-drop] is %NULL, this function does nothing.

    This function should be used when delaying the decision on whether to accept
    a drag or not until after reading the data. *)

external get_value : t -> Gobject.Value.t option
  = "ml_gtk_drop_target_get_value"
(** Gets the current drop data, as a `GValue`. *)

external get_preload : t -> bool = "ml_gtk_drop_target_get_preload"
(** Gets whether data should be preloaded on hover. *)

external get_gtypes : t -> Gobject.Type.t array option * Gsize.t
  = "ml_gtk_drop_target_get_gtypes"
(** Gets the list of supported `GType`s that can be dropped on the target.

    If no types have been set, `NULL` will be returned. *)

external get_formats : t -> Ocgtk_gdk.Gdk.Wrappers.Content_formats.t option
  = "ml_gtk_drop_target_get_formats"
(** Gets the data formats that this drop target accepts.

    If the result is %NULL, all formats are expected to be supported. *)

external get_drop : t -> Ocgtk_gdk.Gdk.Wrappers.Drop.t option
  = "ml_gtk_drop_target_get_drop"
(** Gets the currently handled drop operation.

    If no drop operation is going on, %NULL is returned. *)

external get_current_drop : t -> Ocgtk_gdk.Gdk.Wrappers.Drop.t option
  = "ml_gtk_drop_target_get_current_drop"
(** Gets the currently handled drop operation.

    If no drop operation is going on, %NULL is returned. *)

external get_actions : t -> Ocgtk_gdk.Gdk.dragaction
  = "ml_gtk_drop_target_get_actions"
(** Gets the actions that this drop target supports. *)

(* Properties *)

val on_accept :
  ?after:bool ->
  t ->
  callback:(drop:Ocgtk_gdk.Gdk.Wrappers.Drop.t -> bool) ->
  Gobject.Signal.handler_id

val on_drop :
  ?after:bool ->
  t ->
  callback:(value:Gobject.Value.t -> x:float -> y:float -> bool) ->
  Gobject.Signal.handler_id

val on_enter :
  ?after:bool ->
  t ->
  callback:(x:float -> y:float -> Ocgtk_gdk.Gdk_enums.dragaction) ->
  Gobject.Signal.handler_id

val on_leave :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_motion :
  ?after:bool ->
  t ->
  callback:(x:float -> y:float -> Ocgtk_gdk.Gdk_enums.dragaction) ->
  Gobject.Signal.handler_id
