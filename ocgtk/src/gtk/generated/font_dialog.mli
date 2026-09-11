(* GENERATED CODE - DO NOT EDIT *)
(* FontDialog: FontDialog *)

type t = [ `font_dialog | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_font_dialog_get_type"

external new_ : unit -> t = "ml_gtk_font_dialog_new"
(** Create a new FontDialog *)

(* Methods *)

external set_title : t -> string -> unit = "ml_gtk_font_dialog_set_title"
(** Sets the title that will be shown on the font chooser dialog. *)

external set_modal : t -> bool -> unit = "ml_gtk_font_dialog_set_modal"
(** Sets whether the font chooser dialog blocks interaction with the parent
    window while it is presented. *)

external set_language : t -> Ocgtk_pango.Pango.Wrappers.Language.t -> unit
  = "ml_gtk_font_dialog_set_language"
(** Sets the language for which font features are applied. *)

external set_font_map :
  t -> Ocgtk_pango.Pango.Wrappers.Font_map.t option -> unit
  = "ml_gtk_font_dialog_set_font_map"
(** Sets the fontmap from which fonts are selected.

If @fontmap is `NULL`, the default fontmap is used. *)

external set_filter : t -> Filter.t option -> unit
  = "ml_gtk_font_dialog_set_filter"
(** Adds a filter that decides which fonts to display in the font chooser
    dialog.

    The filter must be able to handle both `PangoFontFamily` and `PangoFontFace`
    objects. *)

external get_title : t -> string = "ml_gtk_font_dialog_get_title"
(** Returns the title that will be shown on the font chooser dialog. *)

external get_modal : t -> bool = "ml_gtk_font_dialog_get_modal"
(** Returns whether the font chooser dialog blocks interaction with the parent
    window while it is presented. *)

external get_language : t -> Ocgtk_pango.Pango.Wrappers.Language.t option
  = "ml_gtk_font_dialog_get_language"
(** Returns the language for which font features are applied. *)

external get_font_map : t -> Ocgtk_pango.Pango.Wrappers.Font_map.t option
  = "ml_gtk_font_dialog_get_font_map"
(** Returns the fontmap from which fonts are selected, or `NULL` for the default
    fontmap. *)

external get_filter : t -> Filter.t option = "ml_gtk_font_dialog_get_filter"
(** Returns the filter that decides which fonts to display in the font chooser
    dialog. *)

external choose_font_finish :
  t ->
  Ocgtk_gio.Gio.Wrappers.Async_result.t ->
  (Ocgtk_pango.Pango.Wrappers.Font_description.t, GError.t) result
  = "ml_gtk_font_dialog_choose_font_finish"
(** Finishes the [method@Gtk.FontDialog.choose_font] call.

    Note that this function returns a [error@Gtk.DialogError.DISMISSED] error if
    the user cancels the dialog. *)

external choose_family_finish :
  t ->
  Ocgtk_gio.Gio.Wrappers.Async_result.t ->
  (Ocgtk_pango.Pango.Wrappers.Font_family.t, GError.t) result
  = "ml_gtk_font_dialog_choose_family_finish"
(** Finishes the [method@Gtk.FontDialog.choose_family] call.

    Note that this function returns a [error@Gtk.DialogError.DISMISSED] error if
    the user cancels the dialog. *)

external choose_face_finish :
  t ->
  Ocgtk_gio.Gio.Wrappers.Async_result.t ->
  (Ocgtk_pango.Pango.Wrappers.Font_face.t, GError.t) result
  = "ml_gtk_font_dialog_choose_face_finish"
(** Finishes the [method@Gtk.FontDialog.choose_face] call.

    Note that this function returns a [error@Gtk.DialogError.DISMISSED] error if
    the user cancels the dialog. *)

(* Properties *)
