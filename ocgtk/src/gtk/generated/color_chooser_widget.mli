(* GENERATED CODE - DO NOT EDIT *)
(* ColorChooserWidget: ColorChooserWidget *)

type t =
  [ `color_chooser_widget | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_color_chooser_widget_get_type"

external new_ : unit -> t = "ml_gtk_color_chooser_widget_new"
(** Create a new ColorChooserWidget *)

(* Methods *)
(* Properties *)

external get_show_editor : t -> bool
  = "ml_gtk_color_chooser_widget_get_show_editor"
(** Get property: show-editor *)

external set_show_editor : t -> bool -> unit
  = "ml_gtk_color_chooser_widget_set_show_editor"
(** Set property: show-editor *)
