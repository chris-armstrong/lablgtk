(* GENERATED CODE - DO NOT EDIT *)
(* CellRendererSpin: CellRendererSpin *)

type t =
  [ `cell_renderer_spin
  | `cell_renderer_text
  | `cell_renderer
  | `initially_unowned
  | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_cell_renderer_spin_get_type"

external new_ : unit -> t = "ml_gtk_cell_renderer_spin_new"
(** Create a new CellRendererSpin *)

(* Methods *)
(* Properties *)

external get_adjustment : t -> Adjustment.t
  = "ml_gtk_cell_renderer_spin_get_adjustment"
(** Get property: adjustment *)

external set_adjustment : t -> Adjustment.t -> unit
  = "ml_gtk_cell_renderer_spin_set_adjustment"
(** Set property: adjustment *)

external get_climb_rate : t -> float
  = "ml_gtk_cell_renderer_spin_get_climb_rate"
(** Get property: climb-rate *)

external set_climb_rate : t -> float -> unit
  = "ml_gtk_cell_renderer_spin_set_climb_rate"
(** Set property: climb-rate *)

external get_digits : t -> int = "ml_gtk_cell_renderer_spin_get_digits"
(** Get property: digits *)

external set_digits : t -> int -> unit = "ml_gtk_cell_renderer_spin_set_digits"
(** Set property: digits *)
