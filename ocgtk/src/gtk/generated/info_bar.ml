(* GENERATED CODE - DO NOT EDIT *)
(* InfoBar: InfoBar *)

type t = [ `info_bar | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_info_bar_get_type"

external new_ : unit -> t = "ml_gtk_info_bar_new"
(** Create a new InfoBar *)

(* Methods *)

external set_show_close_button : t -> bool -> unit
  = "ml_gtk_info_bar_set_show_close_button"
(** If true, a standard close button is shown.

    When clicked it emits the response %GTK_RESPONSE_CLOSE. *)

external set_revealed : t -> bool -> unit = "ml_gtk_info_bar_set_revealed"
(** Sets whether the `GtkInfoBar` is revealed.

Changing this will make @info_bar reveal or conceal
itself via a sliding transition.

Note: this does not show or hide @info_bar in the
[property@Gtk.Widget:visible] sense, so revealing has no effect
if [property@Gtk.Widget:visible] is %FALSE. *)

external set_response_sensitive : t -> int -> bool -> unit
  = "ml_gtk_info_bar_set_response_sensitive"
(** Sets the sensitivity of action widgets for @response_id.

Calls `gtk_widget_set_sensitive (widget, setting)` for each
widget in the info bars’s action area with the given @response_id.
A convenient way to sensitize/desensitize buttons. *)

external set_message_type : t -> Gtk_enums.messagetype -> unit
  = "ml_gtk_info_bar_set_message_type"
(** Sets the message type of the message area.

    GTK uses this type to determine how the message is displayed. *)

external set_default_response : t -> int -> unit
  = "ml_gtk_info_bar_set_default_response"
(** Sets the last widget in the info bar’s action area with
the given response_id as the default widget for the dialog.

Pressing “Enter” normally activates the default widget.

Note that this function currently requires @info_bar to
be added to a widget hierarchy. *)

external response : t -> int -> unit = "ml_gtk_info_bar_response"
(** Emits the “response” signal with the given @response_id. *)

external remove_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_info_bar_remove_child"
(** Removes a widget from the content area of the info bar. *)

external remove_action_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_info_bar_remove_action_widget"
(** Removes a widget from the action area of @info_bar.

The widget must have been put there by a call to
[method@Gtk.InfoBar.add_action_widget] or [method@Gtk.InfoBar.add_button]. *)

external get_show_close_button : t -> bool
  = "ml_gtk_info_bar_get_show_close_button"
(** Returns whether the widget will display a standard close button. *)

external get_revealed : t -> bool = "ml_gtk_info_bar_get_revealed"
(** Returns whether the info bar is currently revealed. *)

external get_message_type : t -> Gtk_enums.messagetype
  = "ml_gtk_info_bar_get_message_type"
(** Returns the message type of the message area. *)

external add_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_info_bar_add_child"
(** Adds a widget to the content area of the info bar. *)

external add_button : t -> string -> int -> Button.t
  = "ml_gtk_info_bar_add_button"
(** Adds a button with the given text.

    Clicking the button will emit the [signal@Gtk.InfoBar::response] signal with
    the given response_id. The button is appended to the end of the info bar's
    action area. The button widget is returned, but usually you don't need it.
*)

external add_action_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int ->
  unit = "ml_gtk_info_bar_add_action_widget"
(** Add an activatable widget to the action area of a `GtkInfoBar`.

    This also connects a signal handler that will emit the
    [signal@Gtk.InfoBar::response] signal on the message area when the widget is
    activated. The widget is appended to the end of the message areas action
    area. *)

(* Properties *)

let on_close ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"close" ~callback
    ~after:(Option.value after ~default:false)

let on_response ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let response_id =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_int v
        in
        callback ~response_id)
  in
  Gobject.Signal.connect obj ~name:"response" ~callback:closure
    ~after:(Option.value after ~default:false)
