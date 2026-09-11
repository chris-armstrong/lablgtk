(* GENERATED CODE - DO NOT EDIT *)
(* Scrollbar: Scrollbar *)

type t = [ `scrollbar | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_scrollbar_get_type"

external new_ : Gtk_enums.orientation -> Adjustment.t option -> t
  = "ml_gtk_scrollbar_new"
(** Create a new Scrollbar *)

(* Methods *)

external set_adjustment : t -> Adjustment.t option -> unit
  = "ml_gtk_scrollbar_set_adjustment"
(** Makes the scrollbar use the given adjustment. *)

external get_adjustment : t -> Adjustment.t = "ml_gtk_scrollbar_get_adjustment"
(** Returns the scrollbar's adjustment. *)

(* Properties *)
