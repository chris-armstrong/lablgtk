(* GENERATED CODE - DO NOT EDIT *)
(* TextTag: TextTag *)

type t = [ `text_tag | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_text_tag_get_type"

external new_ : string option -> t = "ml_gtk_text_tag_new"
(** Create a new TextTag *)

(* Methods *)

external set_priority : t -> int -> unit = "ml_gtk_text_tag_set_priority"
(** Sets the priority of a `GtkTextTag`.

    Valid priorities start at 0 and go to one less than
    [method@Gtk.TextTagTable.get_size]. Each tag in a table has a unique
    priority; setting the priority of one tag shifts the priorities of all the
    other tags in the table to maintain a unique priority for each tag.

    Higher priority tags “win” if two tags both set the same text attribute.
    When adding a tag to a tag table, it will be assigned the highest priority
    in the table by default; so normally the precedence of a set of tags is the
    order in which they were added to the table, or created with
    [method@Gtk.TextBuffer.create_tag], which adds the tag to the buffer’s table
    automatically. *)

external get_priority : t -> int = "ml_gtk_text_tag_get_priority"
(** Get the tag priority. *)

external changed : t -> bool -> unit = "ml_gtk_text_tag_changed"
(** Emits the [signal@Gtk.TextTagTable::tag-changed] signal on the
    `GtkTextTagTable` where the tag is included.

    The signal is already emitted when setting a `GtkTextTag` property. This
    function is useful for a `GtkTextTag` subclass. *)

(* Properties *)

external get_accumulative_margin : t -> bool
  = "ml_gtk_text_tag_get_accumulative_margin"
(** Get property: accumulative-margin *)

external set_accumulative_margin : t -> bool -> unit
  = "ml_gtk_text_tag_set_accumulative_margin"
(** Set property: accumulative-margin *)

external get_allow_breaks : t -> bool = "ml_gtk_text_tag_get_allow_breaks"
(** Get property: allow-breaks *)

external set_allow_breaks : t -> bool -> unit
  = "ml_gtk_text_tag_set_allow_breaks"
(** Set property: allow-breaks *)

external get_allow_breaks_set : t -> bool
  = "ml_gtk_text_tag_get_allow_breaks_set"
(** Get property: allow-breaks-set *)

external set_allow_breaks_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_allow_breaks_set"
(** Set property: allow-breaks-set *)

external set_background : t -> string -> unit = "ml_gtk_text_tag_set_background"
(** Set property: background *)

external get_background_full_height : t -> bool
  = "ml_gtk_text_tag_get_background_full_height"
(** Get property: background-full-height *)

external set_background_full_height : t -> bool -> unit
  = "ml_gtk_text_tag_set_background_full_height"
(** Set property: background-full-height *)

external get_background_full_height_set : t -> bool
  = "ml_gtk_text_tag_get_background_full_height_set"
(** Get property: background-full-height-set *)

external set_background_full_height_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_background_full_height_set"
(** Set property: background-full-height-set *)

external get_background_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t
  = "ml_gtk_text_tag_get_background_rgba"
(** Get property: background-rgba *)

external set_background_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t -> unit
  = "ml_gtk_text_tag_set_background_rgba"
(** Set property: background-rgba *)

external get_background_set : t -> bool = "ml_gtk_text_tag_get_background_set"
(** Get property: background-set *)

external set_background_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_background_set"
(** Set property: background-set *)

external get_direction : t -> Gtk_enums.textdirection
  = "ml_gtk_text_tag_get_direction"
(** Get property: direction *)

external set_direction : t -> Gtk_enums.textdirection -> unit
  = "ml_gtk_text_tag_set_direction"
(** Set property: direction *)

external get_editable : t -> bool = "ml_gtk_text_tag_get_editable"
(** Get property: editable *)

external set_editable : t -> bool -> unit = "ml_gtk_text_tag_set_editable"
(** Set property: editable *)

external get_editable_set : t -> bool = "ml_gtk_text_tag_get_editable_set"
(** Get property: editable-set *)

external set_editable_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_editable_set"
(** Set property: editable-set *)

external get_fallback : t -> bool = "ml_gtk_text_tag_get_fallback"
(** Get property: fallback *)

external set_fallback : t -> bool -> unit = "ml_gtk_text_tag_set_fallback"
(** Set property: fallback *)

external get_fallback_set : t -> bool = "ml_gtk_text_tag_get_fallback_set"
(** Get property: fallback-set *)

external set_fallback_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_fallback_set"
(** Set property: fallback-set *)

external get_family : t -> string = "ml_gtk_text_tag_get_family"
(** Get property: family *)

external set_family : t -> string -> unit = "ml_gtk_text_tag_set_family"
(** Set property: family *)

external get_family_set : t -> bool = "ml_gtk_text_tag_get_family_set"
(** Get property: family-set *)

external set_family_set : t -> bool -> unit = "ml_gtk_text_tag_set_family_set"
(** Set property: family-set *)

external get_font : t -> string = "ml_gtk_text_tag_get_font"
(** Get property: font *)

external set_font : t -> string -> unit = "ml_gtk_text_tag_set_font"
(** Set property: font *)

external get_font_desc : t -> Ocgtk_pango.Pango.Wrappers.Font_description.t
  = "ml_gtk_text_tag_get_font_desc"
(** Get property: font-desc *)

external set_font_desc :
  t -> Ocgtk_pango.Pango.Wrappers.Font_description.t -> unit
  = "ml_gtk_text_tag_set_font_desc"
(** Set property: font-desc *)

external get_font_features : t -> string = "ml_gtk_text_tag_get_font_features"
(** Get property: font-features *)

external set_font_features : t -> string -> unit
  = "ml_gtk_text_tag_set_font_features"
(** Set property: font-features *)

external get_font_features_set : t -> bool
  = "ml_gtk_text_tag_get_font_features_set"
(** Get property: font-features-set *)

external set_font_features_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_font_features_set"
(** Set property: font-features-set *)

external set_foreground : t -> string -> unit = "ml_gtk_text_tag_set_foreground"
(** Set property: foreground *)

external get_foreground_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t
  = "ml_gtk_text_tag_get_foreground_rgba"
(** Get property: foreground-rgba *)

external set_foreground_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t -> unit
  = "ml_gtk_text_tag_set_foreground_rgba"
(** Set property: foreground-rgba *)

external get_foreground_set : t -> bool = "ml_gtk_text_tag_get_foreground_set"
(** Get property: foreground-set *)

external set_foreground_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_foreground_set"
(** Set property: foreground-set *)

external get_indent : t -> int = "ml_gtk_text_tag_get_indent"
(** Get property: indent *)

external set_indent : t -> int -> unit = "ml_gtk_text_tag_set_indent"
(** Set property: indent *)

external get_indent_set : t -> bool = "ml_gtk_text_tag_get_indent_set"
(** Get property: indent-set *)

external set_indent_set : t -> bool -> unit = "ml_gtk_text_tag_set_indent_set"
(** Set property: indent-set *)

external get_insert_hyphens : t -> bool = "ml_gtk_text_tag_get_insert_hyphens"
(** Get property: insert-hyphens *)

external set_insert_hyphens : t -> bool -> unit
  = "ml_gtk_text_tag_set_insert_hyphens"
(** Set property: insert-hyphens *)

external get_insert_hyphens_set : t -> bool
  = "ml_gtk_text_tag_get_insert_hyphens_set"
(** Get property: insert-hyphens-set *)

external set_insert_hyphens_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_insert_hyphens_set"
(** Set property: insert-hyphens-set *)

external get_invisible : t -> bool = "ml_gtk_text_tag_get_invisible"
(** Get property: invisible *)

external set_invisible : t -> bool -> unit = "ml_gtk_text_tag_set_invisible"
(** Set property: invisible *)

external get_invisible_set : t -> bool = "ml_gtk_text_tag_get_invisible_set"
(** Get property: invisible-set *)

external set_invisible_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_invisible_set"
(** Set property: invisible-set *)

external get_justification : t -> Gtk_enums.justification
  = "ml_gtk_text_tag_get_justification"
(** Get property: justification *)

external set_justification : t -> Gtk_enums.justification -> unit
  = "ml_gtk_text_tag_set_justification"
(** Set property: justification *)

external get_justification_set : t -> bool
  = "ml_gtk_text_tag_get_justification_set"
(** Get property: justification-set *)

external set_justification_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_justification_set"
(** Set property: justification-set *)

external get_language : t -> string = "ml_gtk_text_tag_get_language"
(** Get property: language *)

external set_language : t -> string -> unit = "ml_gtk_text_tag_set_language"
(** Set property: language *)

external get_language_set : t -> bool = "ml_gtk_text_tag_get_language_set"
(** Get property: language-set *)

external set_language_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_language_set"
(** Set property: language-set *)

external get_left_margin : t -> int = "ml_gtk_text_tag_get_left_margin"
(** Get property: left-margin *)

external set_left_margin : t -> int -> unit = "ml_gtk_text_tag_set_left_margin"
(** Set property: left-margin *)

external get_left_margin_set : t -> bool = "ml_gtk_text_tag_get_left_margin_set"
(** Get property: left-margin-set *)

external set_left_margin_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_left_margin_set"
(** Set property: left-margin-set *)

external get_letter_spacing : t -> int = "ml_gtk_text_tag_get_letter_spacing"
(** Get property: letter-spacing *)

external set_letter_spacing : t -> int -> unit
  = "ml_gtk_text_tag_set_letter_spacing"
(** Set property: letter-spacing *)

external get_letter_spacing_set : t -> bool
  = "ml_gtk_text_tag_get_letter_spacing_set"
(** Get property: letter-spacing-set *)

external set_letter_spacing_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_letter_spacing_set"
(** Set property: letter-spacing-set *)

external get_line_height : t -> float = "ml_gtk_text_tag_get_line_height"
(** Get property: line-height *)

external set_line_height : t -> float -> unit
  = "ml_gtk_text_tag_set_line_height"
(** Set property: line-height *)

external get_line_height_set : t -> bool = "ml_gtk_text_tag_get_line_height_set"
(** Get property: line-height-set *)

external set_line_height_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_line_height_set"
(** Set property: line-height-set *)

external get_name : t -> string = "ml_gtk_text_tag_get_name"
(** Get property: name *)

external get_overline : t -> Ocgtk_pango.Pango.overline
  = "ml_gtk_text_tag_get_overline"
(** Get property: overline *)

external set_overline : t -> Ocgtk_pango.Pango.overline -> unit
  = "ml_gtk_text_tag_set_overline"
(** Set property: overline *)

external get_overline_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t
  = "ml_gtk_text_tag_get_overline_rgba"
(** Get property: overline-rgba *)

external set_overline_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t -> unit
  = "ml_gtk_text_tag_set_overline_rgba"
(** Set property: overline-rgba *)

external get_overline_rgba_set : t -> bool
  = "ml_gtk_text_tag_get_overline_rgba_set"
(** Get property: overline-rgba-set *)

external set_overline_rgba_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_overline_rgba_set"
(** Set property: overline-rgba-set *)

external get_overline_set : t -> bool = "ml_gtk_text_tag_get_overline_set"
(** Get property: overline-set *)

external set_overline_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_overline_set"
(** Set property: overline-set *)

external set_paragraph_background : t -> string -> unit
  = "ml_gtk_text_tag_set_paragraph_background"
(** Set property: paragraph-background *)

external get_paragraph_background_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t
  = "ml_gtk_text_tag_get_paragraph_background_rgba"
(** Get property: paragraph-background-rgba *)

external set_paragraph_background_rgba :
  t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t -> unit
  = "ml_gtk_text_tag_set_paragraph_background_rgba"
(** Set property: paragraph-background-rgba *)

external get_paragraph_background_set : t -> bool
  = "ml_gtk_text_tag_get_paragraph_background_set"
(** Get property: paragraph-background-set *)

external set_paragraph_background_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_paragraph_background_set"
(** Set property: paragraph-background-set *)

external get_pixels_above_lines : t -> int
  = "ml_gtk_text_tag_get_pixels_above_lines"
(** Get property: pixels-above-lines *)

external set_pixels_above_lines : t -> int -> unit
  = "ml_gtk_text_tag_set_pixels_above_lines"
(** Set property: pixels-above-lines *)

external get_pixels_above_lines_set : t -> bool
  = "ml_gtk_text_tag_get_pixels_above_lines_set"
(** Get property: pixels-above-lines-set *)

external set_pixels_above_lines_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_pixels_above_lines_set"
(** Set property: pixels-above-lines-set *)

external get_pixels_below_lines : t -> int
  = "ml_gtk_text_tag_get_pixels_below_lines"
(** Get property: pixels-below-lines *)

external set_pixels_below_lines : t -> int -> unit
  = "ml_gtk_text_tag_set_pixels_below_lines"
(** Set property: pixels-below-lines *)

external get_pixels_below_lines_set : t -> bool
  = "ml_gtk_text_tag_get_pixels_below_lines_set"
(** Get property: pixels-below-lines-set *)

external set_pixels_below_lines_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_pixels_below_lines_set"
(** Set property: pixels-below-lines-set *)

external get_pixels_inside_wrap : t -> int
  = "ml_gtk_text_tag_get_pixels_inside_wrap"
(** Get property: pixels-inside-wrap *)

external set_pixels_inside_wrap : t -> int -> unit
  = "ml_gtk_text_tag_set_pixels_inside_wrap"
(** Set property: pixels-inside-wrap *)

external get_pixels_inside_wrap_set : t -> bool
  = "ml_gtk_text_tag_get_pixels_inside_wrap_set"
(** Get property: pixels-inside-wrap-set *)

external set_pixels_inside_wrap_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_pixels_inside_wrap_set"
(** Set property: pixels-inside-wrap-set *)

external get_right_margin : t -> int = "ml_gtk_text_tag_get_right_margin"
(** Get property: right-margin *)

external set_right_margin : t -> int -> unit
  = "ml_gtk_text_tag_set_right_margin"
(** Set property: right-margin *)

external get_right_margin_set : t -> bool
  = "ml_gtk_text_tag_get_right_margin_set"
(** Get property: right-margin-set *)

external set_right_margin_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_right_margin_set"
(** Set property: right-margin-set *)

external get_rise : t -> int = "ml_gtk_text_tag_get_rise"
(** Get property: rise *)

external set_rise : t -> int -> unit = "ml_gtk_text_tag_set_rise"
(** Set property: rise *)

external get_rise_set : t -> bool = "ml_gtk_text_tag_get_rise_set"
(** Get property: rise-set *)

external set_rise_set : t -> bool -> unit = "ml_gtk_text_tag_set_rise_set"
(** Set property: rise-set *)

external get_scale : t -> float = "ml_gtk_text_tag_get_scale"
(** Get property: scale *)

external set_scale : t -> float -> unit = "ml_gtk_text_tag_set_scale"
(** Set property: scale *)

external get_scale_set : t -> bool = "ml_gtk_text_tag_get_scale_set"
(** Get property: scale-set *)

external set_scale_set : t -> bool -> unit = "ml_gtk_text_tag_set_scale_set"
(** Set property: scale-set *)

external get_sentence : t -> bool = "ml_gtk_text_tag_get_sentence"
(** Get property: sentence *)

external set_sentence : t -> bool -> unit = "ml_gtk_text_tag_set_sentence"
(** Set property: sentence *)

external get_sentence_set : t -> bool = "ml_gtk_text_tag_get_sentence_set"
(** Get property: sentence-set *)

external set_sentence_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_sentence_set"
(** Set property: sentence-set *)

external get_show_spaces : t -> Ocgtk_pango.Pango.showflags
  = "ml_gtk_text_tag_get_show_spaces"
(** Get property: show-spaces *)

external set_show_spaces : t -> Ocgtk_pango.Pango.showflags -> unit
  = "ml_gtk_text_tag_set_show_spaces"
(** Set property: show-spaces *)

external get_show_spaces_set : t -> bool = "ml_gtk_text_tag_get_show_spaces_set"
(** Get property: show-spaces-set *)

external set_show_spaces_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_show_spaces_set"
(** Set property: show-spaces-set *)

external get_size : t -> int = "ml_gtk_text_tag_get_size"
(** Get property: size *)

external set_size : t -> int -> unit = "ml_gtk_text_tag_set_size"
(** Set property: size *)

external get_size_points : t -> float = "ml_gtk_text_tag_get_size_points"
(** Get property: size-points *)

external set_size_points : t -> float -> unit
  = "ml_gtk_text_tag_set_size_points"
(** Set property: size-points *)

external get_size_set : t -> bool = "ml_gtk_text_tag_get_size_set"
(** Get property: size-set *)

external set_size_set : t -> bool -> unit = "ml_gtk_text_tag_set_size_set"
(** Set property: size-set *)

external get_stretch : t -> Ocgtk_pango.Pango.stretch
  = "ml_gtk_text_tag_get_stretch"
(** Get property: stretch *)

external set_stretch : t -> Ocgtk_pango.Pango.stretch -> unit
  = "ml_gtk_text_tag_set_stretch"
(** Set property: stretch *)

external get_stretch_set : t -> bool = "ml_gtk_text_tag_get_stretch_set"
(** Get property: stretch-set *)

external set_stretch_set : t -> bool -> unit = "ml_gtk_text_tag_set_stretch_set"
(** Set property: stretch-set *)

external get_strikethrough : t -> bool = "ml_gtk_text_tag_get_strikethrough"
(** Get property: strikethrough *)

external set_strikethrough : t -> bool -> unit
  = "ml_gtk_text_tag_set_strikethrough"
(** Set property: strikethrough *)

external get_strikethrough_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t
  = "ml_gtk_text_tag_get_strikethrough_rgba"
(** Get property: strikethrough-rgba *)

external set_strikethrough_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t -> unit
  = "ml_gtk_text_tag_set_strikethrough_rgba"
(** Set property: strikethrough-rgba *)

external get_strikethrough_rgba_set : t -> bool
  = "ml_gtk_text_tag_get_strikethrough_rgba_set"
(** Get property: strikethrough-rgba-set *)

external set_strikethrough_rgba_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_strikethrough_rgba_set"
(** Set property: strikethrough-rgba-set *)

external get_strikethrough_set : t -> bool
  = "ml_gtk_text_tag_get_strikethrough_set"
(** Get property: strikethrough-set *)

external set_strikethrough_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_strikethrough_set"
(** Set property: strikethrough-set *)

external get_style : t -> Ocgtk_pango.Pango.style = "ml_gtk_text_tag_get_style"
(** Get property: style *)

external set_style : t -> Ocgtk_pango.Pango.style -> unit
  = "ml_gtk_text_tag_set_style"
(** Set property: style *)

external get_style_set : t -> bool = "ml_gtk_text_tag_get_style_set"
(** Get property: style-set *)

external set_style_set : t -> bool -> unit = "ml_gtk_text_tag_set_style_set"
(** Set property: style-set *)

external get_tabs : t -> Ocgtk_pango.Pango.Wrappers.Tab_array.t
  = "ml_gtk_text_tag_get_tabs"
(** Get property: tabs *)

external set_tabs : t -> Ocgtk_pango.Pango.Wrappers.Tab_array.t -> unit
  = "ml_gtk_text_tag_set_tabs"
(** Set property: tabs *)

external get_tabs_set : t -> bool = "ml_gtk_text_tag_get_tabs_set"
(** Get property: tabs-set *)

external set_tabs_set : t -> bool -> unit = "ml_gtk_text_tag_set_tabs_set"
(** Set property: tabs-set *)

external get_text_transform : t -> Ocgtk_pango.Pango.texttransform
  = "ml_gtk_text_tag_get_text_transform"
(** Get property: text-transform *)

external set_text_transform : t -> Ocgtk_pango.Pango.texttransform -> unit
  = "ml_gtk_text_tag_set_text_transform"
(** Set property: text-transform *)

external get_text_transform_set : t -> bool
  = "ml_gtk_text_tag_get_text_transform_set"
(** Get property: text-transform-set *)

external set_text_transform_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_text_transform_set"
(** Set property: text-transform-set *)

external get_underline : t -> Ocgtk_pango.Pango.underline
  = "ml_gtk_text_tag_get_underline"
(** Get property: underline *)

external set_underline : t -> Ocgtk_pango.Pango.underline -> unit
  = "ml_gtk_text_tag_set_underline"
(** Set property: underline *)

external get_underline_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t
  = "ml_gtk_text_tag_get_underline_rgba"
(** Get property: underline-rgba *)

external set_underline_rgba : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t -> unit
  = "ml_gtk_text_tag_set_underline_rgba"
(** Set property: underline-rgba *)

external get_underline_rgba_set : t -> bool
  = "ml_gtk_text_tag_get_underline_rgba_set"
(** Get property: underline-rgba-set *)

external set_underline_rgba_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_underline_rgba_set"
(** Set property: underline-rgba-set *)

external get_underline_set : t -> bool = "ml_gtk_text_tag_get_underline_set"
(** Get property: underline-set *)

external set_underline_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_underline_set"
(** Set property: underline-set *)

external get_variant : t -> Ocgtk_pango.Pango.variant
  = "ml_gtk_text_tag_get_variant"
(** Get property: variant *)

external set_variant : t -> Ocgtk_pango.Pango.variant -> unit
  = "ml_gtk_text_tag_set_variant"
(** Set property: variant *)

external get_variant_set : t -> bool = "ml_gtk_text_tag_get_variant_set"
(** Get property: variant-set *)

external set_variant_set : t -> bool -> unit = "ml_gtk_text_tag_set_variant_set"
(** Set property: variant-set *)

external get_weight : t -> int = "ml_gtk_text_tag_get_weight"
(** Get property: weight *)

external set_weight : t -> int -> unit = "ml_gtk_text_tag_set_weight"
(** Set property: weight *)

external get_weight_set : t -> bool = "ml_gtk_text_tag_get_weight_set"
(** Get property: weight-set *)

external set_weight_set : t -> bool -> unit = "ml_gtk_text_tag_set_weight_set"
(** Set property: weight-set *)

external get_word : t -> bool = "ml_gtk_text_tag_get_word"
(** Get property: word *)

external set_word : t -> bool -> unit = "ml_gtk_text_tag_set_word"
(** Set property: word *)

external get_word_set : t -> bool = "ml_gtk_text_tag_get_word_set"
(** Get property: word-set *)

external set_word_set : t -> bool -> unit = "ml_gtk_text_tag_set_word_set"
(** Set property: word-set *)

external get_wrap_mode : t -> Gtk_enums.wrapmode
  = "ml_gtk_text_tag_get_wrap_mode"
(** Get property: wrap-mode *)

external set_wrap_mode : t -> Gtk_enums.wrapmode -> unit
  = "ml_gtk_text_tag_set_wrap_mode"
(** Set property: wrap-mode *)

external get_wrap_mode_set : t -> bool = "ml_gtk_text_tag_get_wrap_mode_set"
(** Get property: wrap-mode-set *)

external set_wrap_mode_set : t -> bool -> unit
  = "ml_gtk_text_tag_set_wrap_mode_set"
(** Set property: wrap-mode-set *)
