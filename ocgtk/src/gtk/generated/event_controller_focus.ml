(* GENERATED CODE - DO NOT EDIT *)
(* EventControllerFocus: EventControllerFocus *)

type t = [ `event_controller_focus | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gtk_event_controller_focus_get_type"

external new_ : unit -> t = "ml_gtk_event_controller_focus_new"
(** Create a new EventControllerFocus *)

(* Methods *)

external is_focus : t -> bool = "ml_gtk_event_controller_focus_is_focus"
(** Returns %TRUE if focus is within @self, but not one of its children. *)

external contains_focus : t -> bool
  = "ml_gtk_event_controller_focus_contains_focus"
(** Returns %TRUE if focus is within @self or one of its children. *)

(* Properties *)

let on_enter ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"enter" ~callback
    ~after:(Option.value after ~default:false)

let on_leave ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"leave" ~callback
    ~after:(Option.value after ~default:false)
