(* GENERATED CODE - DO NOT EDIT *)
(* CellRendererCombo: CellRendererCombo *)

type t =
  [ `cell_renderer_combo
  | `cell_renderer_text
  | `cell_renderer
  | `initially_unowned
  | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_cell_renderer_combo_get_type"

external new_ : unit -> t = "ml_gtk_cell_renderer_combo_new"
(** Create a new CellRendererCombo *)

(* Methods *)
(* Properties *)

external get_has_entry : t -> bool = "ml_gtk_cell_renderer_combo_get_has_entry"
(** Get property: has-entry *)

external set_has_entry : t -> bool -> unit
  = "ml_gtk_cell_renderer_combo_set_has_entry"
(** Set property: has-entry *)

external get_model : t -> Tree_model.t = "ml_gtk_cell_renderer_combo_get_model"
(** Get property: model *)

external set_model : t -> Tree_model.t -> unit
  = "ml_gtk_cell_renderer_combo_set_model"
(** Set property: model *)

external get_text_column : t -> int
  = "ml_gtk_cell_renderer_combo_get_text_column"
(** Get property: text-column *)

external set_text_column : t -> int -> unit
  = "ml_gtk_cell_renderer_combo_set_text_column"
(** Set property: text-column *)
