(* GENERATED CODE - DO NOT EDIT *)
(* AlternativeTrigger: AlternativeTrigger *)

type t = [ `alternative_trigger | `shortcut_trigger | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_alternative_trigger_get_type"

external new_ : Shortcut_trigger.t -> Shortcut_trigger.t -> t
  = "ml_gtk_alternative_trigger_new"
(** Create a new AlternativeTrigger *)

(* Methods *)

external get_second : t -> Shortcut_trigger.t
  = "ml_gtk_alternative_trigger_get_second"
(** Gets the second of the two alternative triggers that may
trigger @self.

[method@Gtk.AlternativeTrigger.get_first] will return
the other one. *)

external get_first : t -> Shortcut_trigger.t
  = "ml_gtk_alternative_trigger_get_first"
(** Gets the first of the two alternative triggers that may
trigger @self.

[method@Gtk.AlternativeTrigger.get_second] will return
the other one. *)

(* Properties *)
