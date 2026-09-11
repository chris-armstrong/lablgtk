(* GENERATED CODE - DO NOT EDIT *)
(* BytesIcon: BytesIcon *)

type t = [ `bytes_icon | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_bytes_icon_get_type"

external new_ : Glib_bytes.t -> t = "ml_g_bytes_icon_new"
(** Create a new BytesIcon *)

(* Methods *)

external get_bytes : t -> Glib_bytes.t = "ml_g_bytes_icon_get_bytes"
(** Gets the #GBytes associated with the given @icon. *)

(* Properties *)
