(* GENERATED CODE - DO NOT EDIT *)
(* CellAreaBox: CellAreaBox *)

type t =
  [ `cell_area_box | `cell_area | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_cell_area_box_get_type"

external new_ : unit -> t = "ml_gtk_cell_area_box_new"
(** Create a new CellAreaBox *)

(* Methods *)

external set_spacing : t -> int -> unit = "ml_gtk_cell_area_box_set_spacing"
(** Sets the spacing to add between cell renderers in @box. *)

external pack_start : t -> Cell_renderer.t -> bool -> bool -> bool -> unit
  = "ml_gtk_cell_area_box_pack_start"
(** Adds @renderer to @box, packed with reference to the start of @box.

The @renderer is packed after any other `GtkCellRenderer` packed
with reference to the start of @box. *)

external pack_end : t -> Cell_renderer.t -> bool -> bool -> bool -> unit
  = "ml_gtk_cell_area_box_pack_end"
(** Adds @renderer to @box, packed with reference to the end of @box.

The @renderer is packed after (away from end of) any other
`GtkCellRenderer` packed with reference to the end of @box. *)

external get_spacing : t -> int = "ml_gtk_cell_area_box_get_spacing"
(** Gets the spacing added between cell renderers. *)

(* Properties *)
