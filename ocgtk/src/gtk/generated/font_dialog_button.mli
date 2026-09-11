(* GENERATED CODE - DO NOT EDIT *)
(* FontDialogButton: FontDialogButton *)

type t =
  [ `font_dialog_button | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_font_dialog_button_get_type"

external new_ : Font_dialog.t option -> t = "ml_gtk_font_dialog_button_new"
(** Create a new FontDialogButton *)

(* Methods *)

external set_use_size : t -> bool -> unit
  = "ml_gtk_font_dialog_button_set_use_size"
(** If @use_size is `TRUE`, the font name will be written
using the selected font size. *)

external set_use_font : t -> bool -> unit
  = "ml_gtk_font_dialog_button_set_use_font"
(** If @use_font is `TRUE`, the font name will be written
using the selected font. *)

external set_level : t -> Gtk_enums.fontlevel -> unit
  = "ml_gtk_font_dialog_button_set_level"
(** Sets the level of detail at which this dialog lets the user select fonts. *)

external set_language :
  t -> Ocgtk_pango.Pango.Wrappers.Language.t option -> unit
  = "ml_gtk_font_dialog_button_set_language"
(** Sets the language to use for font features. *)

external set_font_features : t -> string option -> unit
  = "ml_gtk_font_dialog_button_set_font_features"
(** Sets the font features of the button. *)

external set_font_desc :
  t -> Ocgtk_pango.Pango.Wrappers.Font_description.t -> unit
  = "ml_gtk_font_dialog_button_set_font_desc"
(** Sets the font of the button. *)

external set_dialog : t -> Font_dialog.t -> unit
  = "ml_gtk_font_dialog_button_set_dialog"
(** Sets a `GtkFontDialog` object to use for creating the font chooser dialog
    that is presented when the user clicks the button. *)

external get_use_size : t -> bool = "ml_gtk_font_dialog_button_get_use_size"
(** Returns whether the selected font size is used in the label. *)

external get_use_font : t -> bool = "ml_gtk_font_dialog_button_get_use_font"
(** Returns whether the selected font is used in the label. *)

external get_level : t -> Gtk_enums.fontlevel
  = "ml_gtk_font_dialog_button_get_level"
(** Returns the level of detail at which this dialog lets the user select fonts.
*)

external get_language : t -> Ocgtk_pango.Pango.Wrappers.Language.t option
  = "ml_gtk_font_dialog_button_get_language"
(** Returns the language that is used for font features. *)

external get_font_features : t -> string option
  = "ml_gtk_font_dialog_button_get_font_features"
(** Returns the font features of the button.

    This function is what should be used to obtain the font features that were
    chosen by the user. To get informed about changes, listen to
    "notify::font-features".

    Note that the button will only let users choose font features if
    [property@Gtk.FontDialogButton:level] is set to `GTK_FONT_LEVEL_FEATURES`.
*)

external get_font_desc :
  t -> Ocgtk_pango.Pango.Wrappers.Font_description.t option
  = "ml_gtk_font_dialog_button_get_font_desc"
(** Returns the font of the button.

    This function is what should be used to obtain the font that was chosen by
    the user. To get informed about changes, listen to "notify::font-desc". *)

external get_dialog : t -> Font_dialog.t option
  = "ml_gtk_font_dialog_button_get_dialog"
(** Returns the `GtkFontDialog` of @self. *)

(* Properties *)

val on_activate :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
