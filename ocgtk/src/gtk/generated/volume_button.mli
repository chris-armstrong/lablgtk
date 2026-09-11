(* GENERATED CODE - DO NOT EDIT *)
(* VolumeButton: VolumeButton *)

type t =
  [ `volume_button | `scale_button | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_volume_button_get_type"

external new_ : unit -> t = "ml_gtk_volume_button_new"
(** Create a new VolumeButton *)

(* Methods *)
(* Properties *)

external get_use_symbolic : t -> bool = "ml_gtk_volume_button_get_use_symbolic"
(** Get property: use-symbolic *)

external set_use_symbolic : t -> bool -> unit
  = "ml_gtk_volume_button_set_use_symbolic"
(** Set property: use-symbolic *)
