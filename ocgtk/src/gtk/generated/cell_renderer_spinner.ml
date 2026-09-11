(* GENERATED CODE - DO NOT EDIT *)
(* CellRendererSpinner: CellRendererSpinner *)

type t =
  [ `cell_renderer_spinner | `cell_renderer | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gtk_cell_renderer_spinner_get_type"

external new_ : unit -> t = "ml_gtk_cell_renderer_spinner_new"
(** Create a new CellRendererSpinner *)

(* Methods *)
(* Properties *)

external get_active : t -> bool = "ml_gtk_cell_renderer_spinner_get_active"
(** Get property: active *)

external set_active : t -> bool -> unit
  = "ml_gtk_cell_renderer_spinner_set_active"
(** Set property: active *)

external get_pulse : t -> int = "ml_gtk_cell_renderer_spinner_get_pulse"
(** Get property: pulse *)

external set_pulse : t -> int -> unit = "ml_gtk_cell_renderer_spinner_set_pulse"
(** Set property: pulse *)

external get_size : t -> Gtk_enums.iconsize
  = "ml_gtk_cell_renderer_spinner_get_size"
(** Get property: size *)

external set_size : t -> Gtk_enums.iconsize -> unit
  = "ml_gtk_cell_renderer_spinner_set_size"
(** Set property: size *)
