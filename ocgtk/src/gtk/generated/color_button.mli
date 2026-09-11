(* GENERATED CODE - DO NOT EDIT *)
(* ColorButton: ColorButton *)

type t = [ `color_button | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_color_button_get_type"

external new_ : unit -> t = "ml_gtk_color_button_new"
(** Create a new ColorButton *)

external new_with_rgba : Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t -> t
  = "ml_gtk_color_button_new_with_rgba"
(** Create a new ColorButton *)

(* Methods *)

external set_title : t -> string -> unit = "ml_gtk_color_button_set_title"
(** Sets the title for the color chooser dialog. *)

external set_modal : t -> bool -> unit = "ml_gtk_color_button_set_modal"
(** Sets whether the dialog should be modal. *)

external get_title : t -> string = "ml_gtk_color_button_get_title"
(** Gets the title of the color chooser dialog. *)

external get_modal : t -> bool = "ml_gtk_color_button_get_modal"
(** Gets whether the dialog is modal. *)

(* Properties *)

external get_show_editor : t -> bool = "ml_gtk_color_button_get_show_editor"
(** Get property: show-editor *)

external set_show_editor : t -> bool -> unit
  = "ml_gtk_color_button_set_show_editor"
(** Set property: show-editor *)

val on_activate :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_color_set :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
