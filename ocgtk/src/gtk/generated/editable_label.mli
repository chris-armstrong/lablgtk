(* GENERATED CODE - DO NOT EDIT *)
(* EditableLabel: EditableLabel *)

type t =
  [ `editable_label | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_editable_label_get_type"

external new_ : string -> t = "ml_gtk_editable_label_new"
(** Create a new EditableLabel *)

(* Methods *)

external stop_editing : t -> bool -> unit = "ml_gtk_editable_label_stop_editing"
(** Switches the label out of “editing mode”.

If @commit is %TRUE, the resulting text is kept as the
[property@Gtk.Editable:text] property value, otherwise the
resulting text is discarded and the label will keep its
previous [property@Gtk.Editable:text] property value. *)

external start_editing : t -> unit = "ml_gtk_editable_label_start_editing"
(** Switches the label into “editing mode”. *)

external get_editing : t -> bool = "ml_gtk_editable_label_get_editing"
(** Returns whether the label is currently in “editing mode”. *)

(* Properties *)
