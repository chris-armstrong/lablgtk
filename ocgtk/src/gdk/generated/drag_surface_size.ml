(* GENERATED CODE - DO NOT EDIT *)
(* DragSurfaceSize: DragSurfaceSize *)

type t = [ `drag_surface_size ] Gobject.obj
(** Contains information that is useful to compute the size of a drag surface.
*)

external gtype : unit -> Gobject.Type.t = "ml_gdk_drag_surface_size_get_type"

(* Methods *)

external set_size : t -> int -> int -> unit
  = "ml_gdk_drag_surface_size_set_size"
(** Sets the size the drag surface prefers to be resized to. *)
