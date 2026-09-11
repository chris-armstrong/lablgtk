(* GENERATED CODE - DO NOT EDIT *)
(* FontChooser: FontChooser *)

type t = [ `font_chooser ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_font_chooser_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gtk_font_chooser_from_gobject"

(* Methods *)

external set_show_preview_entry : t -> bool -> unit
  = "ml_gtk_font_chooser_set_show_preview_entry"
(** Shows or hides the editable preview entry. *)

external set_preview_text : t -> string -> unit
  = "ml_gtk_font_chooser_set_preview_text"
(** Sets the text displayed in the preview area.

The @text is used to show how the selected font looks. *)

external set_level : t -> Gtk_enums.fontchooserlevel -> unit
  = "ml_gtk_font_chooser_set_level"
(** Sets the desired level of granularity for selecting fonts. *)

external set_language : t -> string -> unit = "ml_gtk_font_chooser_set_language"
(** Sets the language to use for font features. *)

external set_font_map :
  t -> Ocgtk_pango.Pango.Wrappers.Font_map.t option -> unit
  = "ml_gtk_font_chooser_set_font_map"
(** Sets a custom font map to use for this font chooser widget.

    A custom font map can be used to present application-specific fonts instead
    of or in addition to the normal system fonts.

    ```c FcConfig *config; PangoFontMap *fontmap;

    config = FcInitLoadConfigAndFonts (); FcConfigAppFontAddFile (config,
    my_app_font_file);

    fontmap = pango_cairo_font_map_new_for_font_type (CAIRO_FONT_TYPE_FT);
    pango_fc_font_map_set_config (PANGO_FC_FONT_MAP (fontmap), config);

    gtk_font_chooser_set_font_map (font_chooser, fontmap); ```

    Note that other GTK widgets will only be able to use the
    application-specific font if it is present in the font map they use:

    ```c context = gtk_widget_get_pango_context (label);
    pango_context_set_font_map (context, fontmap); ``` *)

external set_font_desc :
  t -> Ocgtk_pango.Pango.Wrappers.Font_description.t -> unit
  = "ml_gtk_font_chooser_set_font_desc"
(** Sets the currently-selected font from @font_desc. *)

external set_font : t -> string -> unit = "ml_gtk_font_chooser_set_font"
(** Sets the currently-selected font. *)

external get_show_preview_entry : t -> bool
  = "ml_gtk_font_chooser_get_show_preview_entry"
(** Returns whether the preview entry is shown or not. *)

external get_preview_text : t -> string = "ml_gtk_font_chooser_get_preview_text"
(** Gets the text displayed in the preview area. *)

external get_level : t -> Gtk_enums.fontchooserlevel
  = "ml_gtk_font_chooser_get_level"
(** Returns the current level of granularity for selecting fonts. *)

external get_language : t -> string = "ml_gtk_font_chooser_get_language"
(** Gets the language that is used for font features. *)

external get_font_size : t -> int = "ml_gtk_font_chooser_get_font_size"
(** The selected font size. *)

external get_font_map : t -> Ocgtk_pango.Pango.Wrappers.Font_map.t option
  = "ml_gtk_font_chooser_get_font_map"
(** Gets the custom font map of this font chooser widget, or %NULL if it does
    not have one. *)

external get_font_features : t -> string
  = "ml_gtk_font_chooser_get_font_features"
(** Gets the currently-selected font features.

    The format of the returned string is compatible with the
    [CSS font-feature-settings property](https://www.w3.org/TR/css-fonts-4/#font-rend-desc).
    It can be passed to [func@Pango.AttrFontFeatures.new]. *)

external get_font_family : t -> Ocgtk_pango.Pango.Wrappers.Font_family.t option
  = "ml_gtk_font_chooser_get_font_family"
(** Gets the `PangoFontFamily` representing the selected font family.

    Font families are a collection of font faces.

    If the selected font is not installed, returns %NULL. *)

external get_font_face : t -> Ocgtk_pango.Pango.Wrappers.Font_face.t option
  = "ml_gtk_font_chooser_get_font_face"
(** Gets the `PangoFontFace` representing the selected font group details (i.e.
    family, slant, weight, width, etc).

    If the selected font is not installed, returns %NULL. *)

external get_font_desc :
  t -> Ocgtk_pango.Pango.Wrappers.Font_description.t option
  = "ml_gtk_font_chooser_get_font_desc"
(** Gets the currently-selected font.

    Note that this can be a different string than what you set with
    [method@Gtk.FontChooser.set_font], as the font chooser widget may normalize
    font names and thus return a string with a different structure. For example,
    “Helvetica Italic Bold 12” could be normalized to “Helvetica Bold Italic
    12”.

    Use [method@Pango.FontDescription.equal] if you want to compare two font
    descriptions. *)

external get_font : t -> string option = "ml_gtk_font_chooser_get_font"
(** Gets the currently-selected font name.

    Note that this can be a different string than what you set with
    [method@Gtk.FontChooser.set_font], as the font chooser widget may normalize
    font names and thus return a string with a different structure. For example,
    “Helvetica Italic Bold 12” could be normalized to “Helvetica Bold Italic
    12”.

    Use [method@Pango.FontDescription.equal] if you want to compare two font
    descriptions. *)

(* Properties *)

let on_font_activated ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let fontname =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_string v
        in
        callback ~fontname)
  in
  Gobject.Signal.connect obj ~name:"font-activated" ~callback:closure
    ~after:(Option.value after ~default:false)
