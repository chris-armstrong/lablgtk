(* GENERATED CODE - DO NOT EDIT *)
(* Emblem: Emblem *)

type t = [ `emblem | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_emblem_get_type"

external new_ : Icon.t -> t = "ml_g_emblem_new"
(** Create a new Emblem *)

external new_with_origin : Icon.t -> Gio_enums.emblemorigin -> t
  = "ml_g_emblem_new_with_origin"
(** Create a new Emblem *)

(* Methods *)

external get_origin : t -> Gio_enums.emblemorigin = "ml_g_emblem_get_origin"
(** Gets the origin of the emblem. *)

external get_icon : t -> Icon.t = "ml_g_emblem_get_icon"
(** Gives back the icon from @emblem. *)

(* Properties *)
