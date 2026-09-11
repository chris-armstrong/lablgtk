(* GENERATED CODE - DO NOT EDIT *)
(* ListBase: ListBase *)

type t = [ `list_base | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_list_base_get_type"

(* Methods *)
(* Properties *)

external get_orientation : t -> Gtk_enums.orientation
  = "ml_gtk_list_base_get_orientation"
(** Get property: orientation *)

external set_orientation : t -> Gtk_enums.orientation -> unit
  = "ml_gtk_list_base_set_orientation"
(** Set property: orientation *)
