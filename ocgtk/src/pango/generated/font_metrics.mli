(* GENERATED CODE - DO NOT EDIT *)
(* FontMetrics: FontMetrics *)

type t = [ `font_metrics ] Gobject.obj
(** A `PangoFontMetrics` structure holds the overall metric information for a
    font.

    The information in a `PangoFontMetrics` structure may be restricted to a
    script. The fields of this structure are private to implementations of a
    font backend. See the documentation of the corresponding getters for
    documentation of their meaning.

    For an overview of the most important metrics, see:

    <picture> <source srcset="fontmetrics-dark.png"
    media="(prefers-color-scheme: dark)"> <img alt="Font metrics"
    src="fontmetrics-light.png"> </picture> *)

external gtype : unit -> Gobject.Type.t = "ml_pango_font_metrics_get_type"

(* Methods *)

external ref : t -> t option = "ml_pango_font_metrics_ref"
(** Increase the reference count of a font metrics structure by one. *)

external get_underline_thickness : t -> int
  = "ml_pango_font_metrics_get_underline_thickness"
(** Gets the suggested thickness to draw for the underline. *)

external get_underline_position : t -> int
  = "ml_pango_font_metrics_get_underline_position"
(** Gets the suggested position to draw the underline.

    The value returned is the distance *above* the baseline of the top of the
    underline. Since most fonts have underline positions beneath the baseline,
    this value is typically negative. *)

external get_strikethrough_thickness : t -> int
  = "ml_pango_font_metrics_get_strikethrough_thickness"
(** Gets the suggested thickness to draw for the strikethrough. *)

external get_strikethrough_position : t -> int
  = "ml_pango_font_metrics_get_strikethrough_position"
(** Gets the suggested position to draw the strikethrough.

    The value returned is the distance *above* the baseline of the top of the
    strikethrough. *)

external get_height : t -> int = "ml_pango_font_metrics_get_height"
(** Gets the line height from a font metrics structure.

    The line height is the recommended distance between successive baselines in
    wrapped text using this font.

    If the line height is not available, 0 is returned. *)

external get_descent : t -> int = "ml_pango_font_metrics_get_descent"
(** Gets the descent from a font metrics structure.

    The descent is the distance from the baseline to the logical bottom of a
    line of text. (The logical bottom may be above or below the bottom of the
    actual drawn ink. It is necessary to lay out the text to figure where the
    ink will be.) *)

external get_ascent : t -> int = "ml_pango_font_metrics_get_ascent"
(** Gets the ascent from a font metrics structure.

    The ascent is the distance from the baseline to the logical top of a line of
    text. (The logical top may be above or below the top of the actual drawn
    ink. It is necessary to lay out the text to figure where the ink will be.)
*)

external get_approximate_digit_width : t -> int
  = "ml_pango_font_metrics_get_approximate_digit_width"
(** Gets the approximate digit width for a font metrics structure.

    This is merely a representative value useful, for example, for determining
    the initial size for a window. Actual digits in text can be wider or
    narrower than this, though this value is generally somewhat more accurate
    than the result of pango_font_metrics_get_approximate_char_width() for
    digits. *)

external get_approximate_char_width : t -> int
  = "ml_pango_font_metrics_get_approximate_char_width"
(** Gets the approximate character width for a font metrics structure.

    This is merely a representative value useful, for example, for determining
    the initial size for a window. Actual characters in text will be wider and
    narrower than this. *)
