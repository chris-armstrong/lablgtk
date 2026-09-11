(* GENERATED CODE - DO NOT EDIT *)
(* PasswordEntry: PasswordEntry *)

type t =
  [ `password_entry | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_password_entry_get_type"

external new_ : unit -> t = "ml_gtk_password_entry_new"
(** Create a new PasswordEntry *)

(* Methods *)

external set_show_peek_icon : t -> bool -> unit
  = "ml_gtk_password_entry_set_show_peek_icon"
(** Sets whether the entry should have a clickable icon to reveal the contents.

    Setting this to %FALSE also hides the text again. *)

external set_extra_menu :
  t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option -> unit
  = "ml_gtk_password_entry_set_extra_menu"
(** Sets a menu model to add when constructing
the context menu for @entry. *)

external get_show_peek_icon : t -> bool
  = "ml_gtk_password_entry_get_show_peek_icon"
(** Returns whether the entry is showing an icon to reveal the contents. *)

external get_extra_menu : t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option
  = "ml_gtk_password_entry_get_extra_menu"
(** Gets the menu model set with gtk_password_entry_set_extra_menu(). *)

(* Properties *)

external get_activates_default : t -> bool
  = "ml_gtk_password_entry_get_activates_default"
(** Get property: activates-default *)

external set_activates_default : t -> bool -> unit
  = "ml_gtk_password_entry_set_activates_default"
(** Set property: activates-default *)

external get_placeholder_text : t -> string
  = "ml_gtk_password_entry_get_placeholder_text"
(** Get property: placeholder-text *)

external set_placeholder_text : t -> string -> unit
  = "ml_gtk_password_entry_set_placeholder_text"
(** Set property: placeholder-text *)

val on_activate :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
