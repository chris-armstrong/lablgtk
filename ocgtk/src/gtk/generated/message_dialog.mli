(* GENERATED CODE - DO NOT EDIT *)
(* MessageDialog: MessageDialog *)

type t =
  [ `message_dialog
  | `dialog
  | `window
  | `widget
  | `initially_unowned
  | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_message_dialog_get_type"

(* Methods *)

external set_markup : t -> string -> unit = "ml_gtk_message_dialog_set_markup"
(** Sets the text of the message dialog. *)

external get_message_area :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t = "ml_gtk_message_dialog_get_message_area"
(** Returns the message area of the dialog.

    This is the box where the dialog’s primary and secondary labels are packed.
    You can add your own extra content to that box and it will appear below
    those labels. See [method@Gtk.Dialog.get_content_area] for the corresponding
    function in the parent [class@Gtk.Dialog]. *)

(* Properties *)

external get_message_type : t -> Gtk_enums.messagetype
  = "ml_gtk_message_dialog_get_message_type"
(** Get property: message-type *)

external set_message_type : t -> Gtk_enums.messagetype -> unit
  = "ml_gtk_message_dialog_set_message_type"
(** Set property: message-type *)

external get_secondary_text : t -> string
  = "ml_gtk_message_dialog_get_secondary_text"
(** Get property: secondary-text *)

external set_secondary_text : t -> string -> unit
  = "ml_gtk_message_dialog_set_secondary_text"
(** Set property: secondary-text *)

external get_secondary_use_markup : t -> bool
  = "ml_gtk_message_dialog_get_secondary_use_markup"
(** Get property: secondary-use-markup *)

external set_secondary_use_markup : t -> bool -> unit
  = "ml_gtk_message_dialog_set_secondary_use_markup"
(** Set property: secondary-use-markup *)

external get_text : t -> string = "ml_gtk_message_dialog_get_text"
(** Get property: text *)

external set_text : t -> string -> unit = "ml_gtk_message_dialog_set_text"
(** Set property: text *)

external get_use_markup : t -> bool = "ml_gtk_message_dialog_get_use_markup"
(** Get property: use-markup *)

external set_use_markup : t -> bool -> unit
  = "ml_gtk_message_dialog_set_use_markup"
(** Set property: use-markup *)
