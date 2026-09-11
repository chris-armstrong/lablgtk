(* GENERATED CODE - DO NOT EDIT *)
(* DragSurface: DragSurface *)

type t = [ `drag_surface ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_drag_surface_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gdk_drag_surface_from_gobject"

(* Methods *)

external present : t -> int -> int -> bool = "ml_gdk_drag_surface_present"
(** Present @drag_surface. *)
