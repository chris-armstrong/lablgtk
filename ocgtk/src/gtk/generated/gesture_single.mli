(* GENERATED CODE - DO NOT EDIT *)
(* GestureSingle: GestureSingle *)

type t =
  [ `gesture_single | `gesture | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_gesture_single_get_type"

(* Methods *)

external set_touch_only : t -> bool -> unit
  = "ml_gtk_gesture_single_set_touch_only"
(** Sets whether to handle only touch events.

If @touch_only is %TRUE, @gesture will only handle events of type
%GDK_TOUCH_BEGIN, %GDK_TOUCH_UPDATE or %GDK_TOUCH_END. If %FALSE,
mouse events will be handled too. *)

external set_exclusive : t -> bool -> unit
  = "ml_gtk_gesture_single_set_exclusive"
(** Sets whether @gesture is exclusive.

An exclusive gesture will only handle pointer and "pointer emulated"
touch events, so at any given time, there is only one sequence able
to interact with those. *)

external set_button : t -> int -> unit = "ml_gtk_gesture_single_set_button"
(** Sets the button number @gesture listens to.

If non-0, every button press from a different button
number will be ignored. Touch events implicitly match
with button 1. *)

external get_touch_only : t -> bool = "ml_gtk_gesture_single_get_touch_only"
(** Returns %TRUE if the gesture is only triggered by touch events. *)

external get_exclusive : t -> bool = "ml_gtk_gesture_single_get_exclusive"
(** Gets whether a gesture is exclusive.

    For more information, see [method@Gtk.GestureSingle.set_exclusive]. *)

external get_current_sequence :
  t -> Ocgtk_gdk.Gdk.Wrappers.Event_sequence.t option
  = "ml_gtk_gesture_single_get_current_sequence"
(** Returns the event sequence currently interacting with @gesture.

This is only meaningful if [method@Gtk.Gesture.is_active]
returns %TRUE. *)

external get_current_button : t -> int
  = "ml_gtk_gesture_single_get_current_button"
(** Returns the button number currently interacting
with @gesture, or 0 if there is none. *)

external get_button : t -> int = "ml_gtk_gesture_single_get_button"
(** Returns the button number @gesture listens for.

If this is 0, the gesture reacts to any button press. *)

(* Properties *)
