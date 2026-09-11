(* GENERATED CODE - DO NOT EDIT *)
(* PadEvent: PadEvent *)

type t = [ `pad_event | `event ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_pad_event_get_type"

(* Methods *)

external get_group_mode : t -> int * int = "ml_gdk_pad_event_get_group_mode"
(** Extracts group and mode information from a pad event. *)

external get_button : t -> int = "ml_gdk_pad_event_get_button"
(** Extracts information about the pressed button from a pad event. *)

external get_axis_value : t -> int * float = "ml_gdk_pad_event_get_axis_value"
(** Extracts the information from a pad strip or ring event. *)
