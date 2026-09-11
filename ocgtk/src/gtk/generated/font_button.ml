(* GENERATED CODE - DO NOT EDIT *)
(* FontButton: FontButton *)

type t = [ `font_button | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_font_button_get_type"

external new_ : unit -> t = "ml_gtk_font_button_new"
(** Create a new FontButton *)

external new_with_font : string -> t = "ml_gtk_font_button_new_with_font"
(** Create a new FontButton *)

(* Methods *)

external set_use_size : t -> bool -> unit = "ml_gtk_font_button_set_use_size"
(** If @use_size is %TRUE, the font name will be written using
the selected size. *)

external set_use_font : t -> bool -> unit = "ml_gtk_font_button_set_use_font"
(** If @use_font is %TRUE, the font name will be written
using the selected font. *)

external set_title : t -> string -> unit = "ml_gtk_font_button_set_title"
(** Sets the title for the font chooser dialog. *)

external set_modal : t -> bool -> unit = "ml_gtk_font_button_set_modal"
(** Sets whether the dialog should be modal. *)

external get_use_size : t -> bool = "ml_gtk_font_button_get_use_size"
(** Returns whether the selected size is used in the label. *)

external get_use_font : t -> bool = "ml_gtk_font_button_get_use_font"
(** Returns whether the selected font is used in the label. *)

external get_title : t -> string = "ml_gtk_font_button_get_title"
(** Retrieves the title of the font chooser dialog. *)

external get_modal : t -> bool = "ml_gtk_font_button_get_modal"
(** Gets whether the dialog is modal. *)

(* Properties *)

let on_activate ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"activate" ~callback
    ~after:(Option.value after ~default:false)

let on_font_set ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"font-set" ~callback
    ~after:(Option.value after ~default:false)
