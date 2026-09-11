(* GENERATED CODE - DO NOT EDIT *)
(* EmblemedIcon: EmblemedIcon *)

type t = [ `emblemed_icon | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_emblemed_icon_get_type"

external new_ : Icon.t -> Emblem.t option -> t = "ml_g_emblemed_icon_new"
(** Create a new EmblemedIcon *)

(* Methods *)

external get_icon : t -> Icon.t = "ml_g_emblemed_icon_get_icon"
(** Gets the main icon for @emblemed. *)

external get_emblems : t -> Emblem.t list = "ml_g_emblemed_icon_get_emblems"
(** Gets the list of emblems for the @icon. *)

external clear_emblems : t -> unit = "ml_g_emblemed_icon_clear_emblems"
(** Removes all the emblems from @icon. *)

external add_emblem : t -> Emblem.t -> unit = "ml_g_emblemed_icon_add_emblem"
(** Adds @emblem to the #GList of #GEmblems. *)

(* Properties *)

external get_gicon : t -> Icon.t = "ml_g_emblemed_icon_get_gicon"
(** Get property: gicon *)
