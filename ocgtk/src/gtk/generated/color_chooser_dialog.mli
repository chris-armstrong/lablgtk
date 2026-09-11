(* GENERATED CODE - DO NOT EDIT *)
(* ColorChooserDialog: ColorChooserDialog *)

type t =
  [ `color_chooser_dialog
  | `dialog
  | `window
  | `widget
  | `initially_unowned
  | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_color_chooser_dialog_get_type"

external new_ :
  string option ->
  Application_and__window_and__window_group.Window.t option ->
  t = "ml_gtk_color_chooser_dialog_new"
(** Create a new ColorChooserDialog *)

(* Methods *)
(* Properties *)

external get_show_editor : t -> bool
  = "ml_gtk_color_chooser_dialog_get_show_editor"
(** Get property: show-editor *)

external set_show_editor : t -> bool -> unit
  = "ml_gtk_color_chooser_dialog_set_show_editor"
(** Set property: show-editor *)
