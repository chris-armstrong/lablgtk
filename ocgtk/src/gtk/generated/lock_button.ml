(* GENERATED CODE - DO NOT EDIT *)
(* LockButton: LockButton *)

type t =
  [ `lock_button | `button | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_lock_button_get_type"

external new_ : Ocgtk_gio.Gio.Wrappers.Permission.t option -> t
  = "ml_gtk_lock_button_new"
(** Create a new LockButton *)

(* Methods *)

external set_permission :
  t -> Ocgtk_gio.Gio.Wrappers.Permission.t option -> unit
  = "ml_gtk_lock_button_set_permission"
(** Sets the `GPermission` object that controls @button. *)

external get_permission : t -> Ocgtk_gio.Gio.Wrappers.Permission.t option
  = "ml_gtk_lock_button_get_permission"
(** Obtains the `GPermission` object that controls @button. *)

(* Properties *)

external get_text_lock : t -> string = "ml_gtk_lock_button_get_text_lock"
(** Get property: text-lock *)

external set_text_lock : t -> string -> unit
  = "ml_gtk_lock_button_set_text_lock"
(** Set property: text-lock *)

external get_text_unlock : t -> string = "ml_gtk_lock_button_get_text_unlock"
(** Get property: text-unlock *)

external set_text_unlock : t -> string -> unit
  = "ml_gtk_lock_button_set_text_unlock"
(** Set property: text-unlock *)

external get_tooltip_lock : t -> string = "ml_gtk_lock_button_get_tooltip_lock"
(** Get property: tooltip-lock *)

external set_tooltip_lock : t -> string -> unit
  = "ml_gtk_lock_button_set_tooltip_lock"
(** Set property: tooltip-lock *)

external get_tooltip_not_authorized : t -> string
  = "ml_gtk_lock_button_get_tooltip_not_authorized"
(** Get property: tooltip-not-authorized *)

external set_tooltip_not_authorized : t -> string -> unit
  = "ml_gtk_lock_button_set_tooltip_not_authorized"
(** Set property: tooltip-not-authorized *)

external get_tooltip_unlock : t -> string
  = "ml_gtk_lock_button_get_tooltip_unlock"
(** Get property: tooltip-unlock *)

external set_tooltip_unlock : t -> string -> unit
  = "ml_gtk_lock_button_set_tooltip_unlock"
(** Set property: tooltip-unlock *)
