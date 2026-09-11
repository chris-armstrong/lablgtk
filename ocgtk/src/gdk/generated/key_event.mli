(* GENERATED CODE - DO NOT EDIT *)
(* KeyEvent: KeyEvent *)

type t = [ `key_event | `event ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_key_event_get_type"

(* Methods *)

external matches : t -> int -> Gdk_enums.modifiertype -> Gdk_enums.keymatch
  = "ml_gdk_key_event_matches"
(** Matches a key event against a keyval and modifiers.

    This is typically used to trigger keyboard shortcuts such as Ctrl-C.

    Partial matches are possible where the combination matches if the currently
    active group is ignored.

    Note that we ignore Caps Lock for matching. *)

external is_modifier : t -> bool = "ml_gdk_key_event_is_modifier"
(** Extracts whether the key event is for a modifier key. *)

external get_match : t -> bool * int * Gdk_enums.modifiertype
  = "ml_gdk_key_event_get_match"
(** Gets a keyval and modifier combination that will match the event.

    See [method@Gdk.KeyEvent.matches]. *)

external get_level : t -> int = "ml_gdk_key_event_get_level"
(** Extracts the shift level from a key event. *)

external get_layout : t -> int = "ml_gdk_key_event_get_layout"
(** Extracts the layout from a key event. *)

external get_keyval : t -> int = "ml_gdk_key_event_get_keyval"
(** Extracts the keyval from a key event. *)

external get_keycode : t -> int = "ml_gdk_key_event_get_keycode"
(** Extracts the keycode from a key event. *)

external get_consumed_modifiers : t -> Gdk_enums.modifiertype
  = "ml_gdk_key_event_get_consumed_modifiers"
(** Extracts the consumed modifiers from a key event. *)
