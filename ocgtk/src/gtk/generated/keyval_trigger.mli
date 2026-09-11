(* GENERATED CODE - DO NOT EDIT *)
(* KeyvalTrigger: KeyvalTrigger *)

type t = [ `keyval_trigger | `shortcut_trigger | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_keyval_trigger_get_type"

external new_ : int -> Ocgtk_gdk.Gdk.modifiertype -> t
  = "ml_gtk_keyval_trigger_new"
(** Create a new KeyvalTrigger *)

(* Methods *)

external get_modifiers : t -> Ocgtk_gdk.Gdk.modifiertype
  = "ml_gtk_keyval_trigger_get_modifiers"
(** Gets the modifiers that must be present to succeed
triggering @self. *)

external get_keyval : t -> int = "ml_gtk_keyval_trigger_get_keyval"
(** Gets the keyval that must be pressed to succeed
triggering @self. *)

(* Properties *)
