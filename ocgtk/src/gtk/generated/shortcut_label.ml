(* GENERATED CODE - DO NOT EDIT *)
(* ShortcutLabel: ShortcutLabel *)

type t =
  [ `shortcut_label | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_shortcut_label_get_type"

external new_ : string -> t = "ml_gtk_shortcut_label_new"
(** Create a new ShortcutLabel *)

(* Methods *)

external set_disabled_text : t -> string -> unit
  = "ml_gtk_shortcut_label_set_disabled_text"
(** Sets the text to be displayed by @self when no accelerator is set. *)

external set_accelerator : t -> string -> unit
  = "ml_gtk_shortcut_label_set_accelerator"
(** Sets the accelerator to be displayed by @self. *)

external get_disabled_text : t -> string option
  = "ml_gtk_shortcut_label_get_disabled_text"
(** Retrieves the text that is displayed when no accelerator is set. *)

external get_accelerator : t -> string option
  = "ml_gtk_shortcut_label_get_accelerator"
(** Retrieves the current accelerator of @self. *)

(* Properties *)
