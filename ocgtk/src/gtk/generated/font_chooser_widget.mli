(* GENERATED CODE - DO NOT EDIT *)
(* FontChooserWidget: FontChooserWidget *)

type t =
  [ `font_chooser_widget | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_font_chooser_widget_get_type"

external new_ : unit -> t = "ml_gtk_font_chooser_widget_new"
(** Create a new FontChooserWidget *)

(* Methods *)
(* Properties *)

external get_tweak_action : t -> Ocgtk_gio.Gio.Wrappers.Action.t
  = "ml_gtk_font_chooser_widget_get_tweak_action"
(** Get property: tweak-action *)
