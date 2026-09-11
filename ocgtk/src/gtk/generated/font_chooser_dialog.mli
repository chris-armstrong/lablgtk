(* GENERATED CODE - DO NOT EDIT *)
(* FontChooserDialog: FontChooserDialog *)

type t =
  [ `font_chooser_dialog
  | `dialog
  | `window
  | `widget
  | `initially_unowned
  | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_font_chooser_dialog_get_type"

external new_ :
  string option ->
  Application_and__window_and__window_group.Window.t option ->
  t = "ml_gtk_font_chooser_dialog_new"
(** Create a new FontChooserDialog *)

(* Methods *)
