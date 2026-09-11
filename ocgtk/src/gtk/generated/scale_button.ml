(* GENERATED CODE - DO NOT EDIT *)
(* ScaleButton: ScaleButton *)

type t = [ `scale_button | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_scale_button_get_type"

external new_ : float -> float -> float -> string array option -> t
  = "ml_gtk_scale_button_new"
(** Create a new ScaleButton *)

(* Methods *)

external set_value : t -> float -> unit = "ml_gtk_scale_button_set_value"
(** Sets the current value of the scale.

    If the value is outside the minimum or maximum range values, it will be
    clamped to fit inside them.

    The scale button emits the [signal@Gtk.ScaleButton::value-changed] signal if
    the value changes. *)

external set_icons : t -> string array -> unit = "ml_gtk_scale_button_set_icons"
(** Sets the icons to be used by the scale button. *)

external set_has_frame : t -> bool -> unit = "ml_gtk_scale_button_set_has_frame"
(** Sets the style of the button. *)

external set_adjustment : t -> Adjustment.t -> unit
  = "ml_gtk_scale_button_set_adjustment"
(** Sets the `GtkAdjustment` to be used as a model for the `GtkScaleButton`’s
    scale.

    See [method@Gtk.Range.set_adjustment] for details. *)

external get_value : t -> float = "ml_gtk_scale_button_get_value"
(** Gets the current value of the scale button. *)

external get_popup :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t = "ml_gtk_scale_button_get_popup"
(** Retrieves the popup of the `GtkScaleButton`. *)

external get_plus_button : t -> Button.t = "ml_gtk_scale_button_get_plus_button"
(** Retrieves the plus button of the `GtkScaleButton.` *)

external get_minus_button : t -> Button.t
  = "ml_gtk_scale_button_get_minus_button"
(** Retrieves the minus button of the `GtkScaleButton`. *)

external get_has_frame : t -> bool = "ml_gtk_scale_button_get_has_frame"
(** Returns whether the button has a frame. *)

external get_adjustment : t -> Adjustment.t
  = "ml_gtk_scale_button_get_adjustment"
(** Gets the `GtkAdjustment` associated with the `GtkScaleButton`’s scale.

    See [method@Gtk.Range.get_adjustment] for details. *)

external get_active : t -> bool = "ml_gtk_scale_button_get_active"
(** Queries a `GtkScaleButton` and returns its current state.

    Returns %TRUE if the scale button is pressed in and %FALSE if it is raised.
*)

(* Properties *)

let on_popdown ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"popdown" ~callback
    ~after:(Option.value after ~default:false)

let on_popup ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"popup" ~callback
    ~after:(Option.value after ~default:false)

let on_value_changed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let value =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_double v
        in
        callback ~value)
  in
  Gobject.Signal.connect obj ~name:"value-changed" ~callback:closure
    ~after:(Option.value after ~default:false)
