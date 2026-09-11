(* GENERATED CODE - DO NOT EDIT *)
(* GlyphString: GlyphString *)

type t = [ `glyph_string ] Gobject.obj
(** A `PangoGlyphString` is used to store strings of glyphs with geometry and
    visual attribute information.

    The storage for the glyph information is owned by the structure which
    simplifies memory management. *)

external gtype : unit -> Gobject.Type.t = "ml_pango_glyph_string_get_type"

external new_ : unit -> t = "ml_pango_glyph_string_new"
(** Create a new GlyphString *)

(* Methods *)

external x_to_index : t -> string -> int -> Analysis.t -> int -> int * int
  = "ml_pango_glyph_string_x_to_index"
(** Convert from x offset to character position.

    Character positions are computed by dividing up each cluster into equal
    portions. In scripts where positioning within a cluster is not allowed (such
    as Thai), the returned value may not be a valid cursor position; the caller
    must combine the result with the logical attributes for the text to compute
    the valid cursor position. *)

external set_size : t -> int -> unit = "ml_pango_glyph_string_set_size"
(** Resize a glyph string to the given length. *)

external index_to_x_full :
  t -> string -> int -> Analysis.t -> Log_attr.t option -> int -> bool -> int
  = "ml_pango_glyph_string_index_to_x_full_bytecode"
    "ml_pango_glyph_string_index_to_x_full_native"
(** Converts from character position to x position.

    This variant of [method@Pango.GlyphString.index_to_x] additionally accepts a
    `PangoLogAttr` array. The grapheme boundary information in it can be used to
    disambiguate positioning inside some complex clusters. *)

external index_to_x : t -> string -> int -> Analysis.t -> int -> bool -> int
  = "ml_pango_glyph_string_index_to_x_bytecode"
    "ml_pango_glyph_string_index_to_x_native"
(** Converts from character position to x position.

    The X position is measured from the left edge of the run. Character
    positions are obtained using font metrics for ligatures where available, and
    computed by dividing up each cluster into equal portions, otherwise.

    <picture> <source srcset="glyphstring-positions-dark.png"
    media="(prefers-color-scheme: dark)"> <img alt="Glyph positions"
    src="glyphstring-positions-light.png"> </picture> *)

external get_width : t -> int = "ml_pango_glyph_string_get_width"
(** Computes the logical width of the glyph string.

This can also be computed using [method@Pango.GlyphString.extents].
However, since this only computes the width, it's much faster. This
is in fact only a convenience function that computes the sum of
@geometry.width for each glyph in the @glyphs. *)

external extents_range :
  t ->
  int ->
  int ->
  Context_and__font_and__font_map_and__fontset.Font.t ->
  Rectangle.t * Rectangle.t = "ml_pango_glyph_string_extents_range"
(** Computes the extents of a sub-portion of a glyph string.

    The extents are relative to the start of the glyph string range (the origin
    of their coordinate system is at the start of the range, not at the start of
    the entire glyph string). *)

external extents :
  t ->
  Context_and__font_and__font_map_and__fontset.Font.t ->
  Rectangle.t * Rectangle.t = "ml_pango_glyph_string_extents"
(** Compute the logical and ink extents of a glyph string.

    See the documentation for [method@Pango.Font.get_glyph_extents] for details
    about the interpretation of the rectangles.

    Examples of logical (red) and ink (green) rects:

    ![](rects1.png) ![](rects2.png) *)
