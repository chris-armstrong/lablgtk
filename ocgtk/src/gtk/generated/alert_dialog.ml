(* GENERATED CODE - DO NOT EDIT *)
(* AlertDialog: AlertDialog *)

type t = [ `alert_dialog | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_alert_dialog_get_type"

(* Methods *)

external show :
  t -> Application_and__window_and__window_group.Window.t option -> unit
  = "ml_gtk_alert_dialog_show"
(** Shows the alert to the user.

    This function is a simpler version of [method@Gtk.AlertDialog.choose]
    intended for dialogs with a single button.

    If you want to cancel the dialog or if the alert has more than one button,
    you should use that function instead and provide it with a
    [class@Gio.Cancellable] and callback respectively. *)

external set_modal : t -> bool -> unit = "ml_gtk_alert_dialog_set_modal"
(** Sets whether the alert blocks interaction with the parent window while it is
    presented. *)

external set_message : t -> string -> unit = "ml_gtk_alert_dialog_set_message"
(** Sets the message that will be shown in the alert. *)

external set_detail : t -> string -> unit = "ml_gtk_alert_dialog_set_detail"
(** Sets the detail text that will be shown in the alert. *)

external set_default_button : t -> int -> unit
  = "ml_gtk_alert_dialog_set_default_button"
(** Sets the index of the default button.

    See [property@Gtk.AlertDialog:default-button] for details of how this value
    is used. *)

external set_cancel_button : t -> int -> unit
  = "ml_gtk_alert_dialog_set_cancel_button"
(** Sets the index of the cancel button.

    See [property@Gtk.AlertDialog:cancel-button] for details of how this value
    is used. *)

external set_buttons : t -> string array -> unit
  = "ml_gtk_alert_dialog_set_buttons"
(** Sets the button labels for the alert. *)

external get_modal : t -> bool = "ml_gtk_alert_dialog_get_modal"
(** Returns whether the alert blocks interaction with the parent window while it
    is presented. *)

external get_message : t -> string = "ml_gtk_alert_dialog_get_message"
(** Returns the message that will be shown in the alert. *)

external get_detail : t -> string = "ml_gtk_alert_dialog_get_detail"
(** Returns the detail text that will be shown in the alert. *)

external get_default_button : t -> int
  = "ml_gtk_alert_dialog_get_default_button"
(** Returns the index of the default button. *)

external get_cancel_button : t -> int = "ml_gtk_alert_dialog_get_cancel_button"
(** Returns the index of the cancel button. *)

external get_buttons : t -> string array option
  = "ml_gtk_alert_dialog_get_buttons"
(** Returns the button labels for the alert. *)

external choose_finish :
  t -> Ocgtk_gio.Gio.Wrappers.Async_result.t -> (int, GError.t) result
  = "ml_gtk_alert_dialog_choose_finish"
(** Finishes the [method@Gtk.AlertDialog.choose] call. *)

(* Properties *)
