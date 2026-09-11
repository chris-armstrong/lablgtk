(* GENERATED CODE - DO NOT EDIT *)
(* AppChooserDialog: AppChooserDialog *)

type t =
  [ `app_chooser_dialog
  | `dialog
  | `window
  | `widget
  | `initially_unowned
  | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_app_chooser_dialog_get_type"

external new_ :
  Application_and__window_and__window_group.Window.t option ->
  Gtk_enums.dialogflags ->
  Ocgtk_gio.Gio.Wrappers.File.t ->
  t = "ml_gtk_app_chooser_dialog_new"
(** Create a new AppChooserDialog *)

external new_for_content_type :
  Application_and__window_and__window_group.Window.t option ->
  Gtk_enums.dialogflags ->
  string ->
  t = "ml_gtk_app_chooser_dialog_new_for_content_type"
(** Create a new AppChooserDialog *)

(* Methods *)

external set_heading : t -> string -> unit
  = "ml_gtk_app_chooser_dialog_set_heading"
(** Sets the text to display at the top of the dialog.

    If the heading is not set, the dialog displays a default text. *)

external get_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t = "ml_gtk_app_chooser_dialog_get_widget"
(** Returns the `GtkAppChooserWidget` of this dialog. *)

external get_heading : t -> string option
  = "ml_gtk_app_chooser_dialog_get_heading"
(** Returns the text to display at the top of the dialog. *)

(* Properties *)

external get_gfile : t -> Ocgtk_gio.Gio.Wrappers.File.t
  = "ml_gtk_app_chooser_dialog_get_gfile"
(** Get property: gfile *)
