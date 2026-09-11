(* GENERATED CODE - DO NOT EDIT *)
(* CellRendererProgress: CellRendererProgress *)

type t =
  [ `cell_renderer_progress | `cell_renderer | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gtk_cell_renderer_progress_get_type"

external new_ : unit -> t = "ml_gtk_cell_renderer_progress_new"
(** Create a new CellRendererProgress *)

(* Methods *)
(* Properties *)

external get_inverted : t -> bool = "ml_gtk_cell_renderer_progress_get_inverted"
(** Get property: inverted *)

external set_inverted : t -> bool -> unit
  = "ml_gtk_cell_renderer_progress_set_inverted"
(** Set property: inverted *)

external get_pulse : t -> int = "ml_gtk_cell_renderer_progress_get_pulse"
(** Get property: pulse *)

external set_pulse : t -> int -> unit
  = "ml_gtk_cell_renderer_progress_set_pulse"
(** Set property: pulse *)

external get_text : t -> string = "ml_gtk_cell_renderer_progress_get_text"
(** Get property: text *)

external set_text : t -> string -> unit
  = "ml_gtk_cell_renderer_progress_set_text"
(** Set property: text *)

external get_text_xalign : t -> float
  = "ml_gtk_cell_renderer_progress_get_text_xalign"
(** Get property: text-xalign *)

external set_text_xalign : t -> float -> unit
  = "ml_gtk_cell_renderer_progress_set_text_xalign"
(** Set property: text-xalign *)

external get_text_yalign : t -> float
  = "ml_gtk_cell_renderer_progress_get_text_yalign"
(** Get property: text-yalign *)

external set_text_yalign : t -> float -> unit
  = "ml_gtk_cell_renderer_progress_set_text_yalign"
(** Set property: text-yalign *)

external get_value : t -> int = "ml_gtk_cell_renderer_progress_get_value"
(** Get property: value *)

external set_value : t -> int -> unit
  = "ml_gtk_cell_renderer_progress_set_value"
(** Set property: value *)
