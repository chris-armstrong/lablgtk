(* GENERATED CODE - DO NOT EDIT *)
(* LayoutLine: LayoutLine *)

type t = [ `layout_line ] Gobject.obj
(** A `PangoLayoutLine` represents one of the lines resulting from laying out a
    paragraph via `PangoLayout`.

    `PangoLayoutLine` structures are obtained by calling
    [method@Pango.Layout.get_line] and are only valid until the text,
    attributes, or settings of the parent `PangoLayout` are modified. *)

external gtype : unit -> Gobject.Type.t = "ml_pango_layout_line_get_type"

(* Methods *)

external x_to_index : t -> int -> bool * int * int
  = "ml_pango_layout_line_x_to_index"
(** Converts from x offset to the byte index of the corresponding character
within the text of the layout.

If @x_pos is outside the line, @index_ and @trailing will point to the very
first or very last position in the line. This determination is based on the
resolved direction of the paragraph; for example, if the resolved direction
is right-to-left, then an X position to the right of the line (after it)
results in 0 being stored in @index_ and @trailing. An X position to the
left of the line results in @index_ pointing to the (logical) last grapheme
in the line and @trailing being set to the number of characters in that
grapheme. The reverse is true for a left-to-right line. *)

external ref : t -> t option = "ml_pango_layout_line_ref"
(** Increase the reference count of a `PangoLayoutLine` by one. *)

external is_paragraph_start : t -> bool
  = "ml_pango_layout_line_is_paragraph_start"
(** Returns whether this is the first line of the paragraph. *)

external index_to_x : t -> int -> bool -> int
  = "ml_pango_layout_line_index_to_x"
(** Converts an index within a line to a X position. *)

external get_x_ranges : t -> int -> int -> int array * int
  = "ml_pango_layout_line_get_x_ranges"
(** Gets a list of visual ranges corresponding to a given logical range.

    This list is not necessarily minimal - there may be consecutive ranges which
    are adjacent. The ranges will be sorted from left to right. The ranges are
    with respect to the left edge of the entire layout, not with respect to the
    line. *)

external get_start_index : t -> int = "ml_pango_layout_line_get_start_index"
(** Returns the start index of the line, as byte index into the text of the
    layout. *)

external get_resolved_direction : t -> Pango_enums.direction
  = "ml_pango_layout_line_get_resolved_direction"
(** Returns the resolved direction of the line. *)

external get_pixel_extents : t -> Rectangle.t * Rectangle.t
  = "ml_pango_layout_line_get_pixel_extents"
(** Computes the logical and ink extents of @layout_line in device units.

This function just calls [method@Pango.LayoutLine.get_extents] followed by
two [func@extents_to_pixels] calls, rounding @ink_rect and @logical_rect
such that the rounded rectangles fully contain the unrounded one (that is,
passes them as first argument to [func@extents_to_pixels]). *)

external get_length : t -> int = "ml_pango_layout_line_get_length"
(** Returns the length of the line, in bytes. *)

external get_height : t -> int = "ml_pango_layout_line_get_height"
(** Computes the height of the line, as the maximum of the heights of fonts used
    in this line.

    Note that the actual baseline-to-baseline distance between lines of text is
    influenced by other factors, such as [method@Pango.Layout.set_spacing] and
    [method@Pango.Layout.set_line_spacing]. *)

external get_extents : t -> Rectangle.t * Rectangle.t
  = "ml_pango_layout_line_get_extents"
(** Computes the logical and ink extents of a layout line.

    See [method@Pango.Font.get_glyph_extents] for details about the
    interpretation of the rectangles. *)
