(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec Layout : sig
  type t = [ `layout | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_pango_layout_get_type"

  external new_ : Context_and__font_and__font_map_and__fontset.Context.t -> t
    = "ml_pango_layout_new"
  (** Create a new Layout *)

  (* Methods *)

  external xy_to_index : t -> int -> int -> bool * int * int
    = "ml_pango_layout_xy_to_index"
  (** Converts from X and Y position within a layout to the byte index to the
      character at that logical position.

      If the Y position is not inside the layout, the closest position is chosen
      (the position will be clamped inside the layout). If the X position is not
      within the layout, then the start or the end of the line is chosen as
      described for [method@Pango.LayoutLine.x_to_index]. If either the X or Y
      positions were not inside the layout, then the function returns %FALSE; on
      an exact hit, it returns %TRUE. *)

  external write_to_file :
    t -> Pango_enums.layoutserializeflags -> string -> (bool, GError.t) result
    = "ml_pango_layout_write_to_file"
  (** A convenience method to serialize a layout to a file.

      It is equivalent to calling [method@Pango.Layout.serialize] followed by
      [func@GLib.file_set_contents].

      See those two functions for details on the arguments.

      It is mostly intended for use inside a debugger to quickly dump a layout
      to a file for later inspection. *)

  external set_wrap : t -> Pango_enums.wrapmode -> unit
    = "ml_pango_layout_set_wrap"
  (** Sets the wrap mode.

      The wrap mode only has effect if a width is set on the layout with
      [method@Pango.Layout.set_width]. To turn off wrapping, set the width to
      -1.

      The default value is %PANGO_WRAP_WORD. *)

  external set_width : t -> int -> unit = "ml_pango_layout_set_width"
  (** Sets the width to which the lines of the `PangoLayout` should wrap or get
      ellipsized.

      The default value is -1: no width set. *)

  external set_text : t -> string -> int -> unit = "ml_pango_layout_set_text"
  (** Sets the text of the layout.

  This function validates @text and renders invalid UTF-8
  with a placeholder glyph.

  Note that if you have used [method@Pango.Layout.set_markup] or
  [method@Pango.Layout.set_markup_with_accel] on @layout before, you
  may want to call [method@Pango.Layout.set_attributes] to clear the
  attributes set on the layout from the markup as this function does
  not clear attributes. *)

  external set_tabs : t -> Tab_array.t option -> unit
    = "ml_pango_layout_set_tabs"
  (** Sets the tabs to use for @layout, overriding the default tabs.

  `PangoLayout` will place content at the next tab position
  whenever it meets a Tab character (U+0009).

  By default, tabs are every 8 spaces. If @tabs is %NULL, the
  default tabs are reinstated. @tabs is copied into the layout;
  you must free your copy of @tabs yourself.

  Note that tabs and justification conflict with each other:
  Justification will move content away from its tab-aligned
  positions. The same is true for alignments other than
  %PANGO_ALIGN_LEFT. *)

  external set_spacing : t -> int -> unit = "ml_pango_layout_set_spacing"
  (** Sets the amount of spacing in Pango units between
  the lines of the layout.

  When placing lines with spacing, Pango arranges things so that

      line2.top = line1.bottom + spacing

  The default value is 0.

  Note: Since 1.44, Pango is using the line height (as determined
  by the font) for placing lines when the line spacing factor is set
  to a non-zero value with [method@Pango.Layout.set_line_spacing].
  In that case, the @spacing set with this function is ignored.

  Note: for semantics that are closer to the CSS line-height
  property, see [func@Pango.attr_line_height_new]. *)

  external set_single_paragraph_mode : t -> bool -> unit
    = "ml_pango_layout_set_single_paragraph_mode"
  (** Sets the single paragraph mode of @layout.

  If @setting is %TRUE, do not treat newlines and similar characters
  as paragraph separators; instead, keep all text in a single paragraph,
  and display a glyph for paragraph separator characters. Used when
  you want to allow editing of newlines on a single text line.

  The default value is %FALSE. *)

  external set_markup_with_accel : t -> string -> int -> int -> int
    = "ml_pango_layout_set_markup_with_accel"
  (** Sets the layout text and attribute list from marked-up text.

  See [Pango Markup](pango_markup.html)).

  Replaces the current text and attribute list.

  If @accel_marker is nonzero, the given character will mark the
  character following it as an accelerator. For example, @accel_marker
  might be an ampersand or underscore. All characters marked
  as an accelerator will receive a %PANGO_UNDERLINE_LOW attribute,
  and the first character so marked will be returned in @accel_char.
  Two @accel_marker characters following each other produce a single
  literal @accel_marker character. *)

  external set_markup : t -> string -> int -> unit
    = "ml_pango_layout_set_markup"
  (** Sets the layout text and attribute list from marked-up text.

      See [Pango Markup](pango_markup.html)).

      Replaces the current text and attribute list.

      This is the same as [method@Pango.Layout.set_markup_with_accel], but the
      markup text isn't scanned for accelerators. *)

  external set_line_spacing : t -> float -> unit
    = "ml_pango_layout_set_line_spacing"
  (** Sets a factor for line spacing.

  Typical values are: 0, 1, 1.5, 2. The default values is 0.

  If @factor is non-zero, lines are placed so that

      baseline2 = baseline1 + factor * height2

  where height2 is the line height of the second line
  (as determined by the font(s)). In this case, the spacing
  set with [method@Pango.Layout.set_spacing] is ignored.

  If @factor is zero (the default), spacing is applied as before.

  Note: for semantics that are closer to the CSS line-height
  property, see [func@Pango.attr_line_height_new]. *)

  external set_justify_last_line : t -> bool -> unit
    = "ml_pango_layout_set_justify_last_line"
  (** Sets whether the last line should be stretched to fill the entire width of
      the layout.

      This only has an effect if [method@Pango.Layout.set_justify] has been
      called as well.

      The default value is %FALSE. *)

  external set_justify : t -> bool -> unit = "ml_pango_layout_set_justify"
  (** Sets whether each complete line should be stretched to fill the entire
      width of the layout.

      Stretching is typically done by adding whitespace, but for some scripts
      (such as Arabic), the justification may be done in more complex ways, like
      extending the characters.

      Note that this setting is not implemented and so is ignored in Pango older
      than 1.18.

      Note that tabs and justification conflict with each other: Justification
      will move content away from its tab-aligned positions.

      The default value is %FALSE.

      Also see [method@Pango.Layout.set_justify_last_line]. *)

  external set_indent : t -> int -> unit = "ml_pango_layout_set_indent"
  (** Sets the width in Pango units to indent each paragraph.

  A negative value of @indent will produce a hanging indentation.
  That is, the first line will have the full width, and subsequent
  lines will be indented by the absolute value of @indent.

  The indent setting is ignored if layout alignment is set to
  %PANGO_ALIGN_CENTER.

  The default value is 0. *)

  external set_height : t -> int -> unit = "ml_pango_layout_set_height"
  (** Sets the height to which the `PangoLayout` should be ellipsized at.

  There are two different behaviors, based on whether @height is positive
  or negative.

  If @height is positive, it will be the maximum height of the layout. Only
  lines would be shown that would fit, and if there is any text omitted,
  an ellipsis added. At least one line is included in each paragraph regardless
  of how small the height value is. A value of zero will render exactly one
  line for the entire layout.

  If @height is negative, it will be the (negative of) maximum number of lines
  per paragraph. That is, the total number of lines shown may well be more than
  this value if the layout contains multiple paragraphs of text.
  The default value of -1 means that the first line of each paragraph is ellipsized.
  This behavior may be changed in the future to act per layout instead of per
  paragraph. File a bug against pango at
  [https://gitlab.gnome.org/gnome/pango](https://gitlab.gnome.org/gnome/pango)
  if your code relies on this behavior.

  Height setting only has effect if a positive width is set on
  @layout and ellipsization mode of @layout is not %PANGO_ELLIPSIZE_NONE.
  The behavior is undefined if a height other than -1 is set and
  ellipsization mode is set to %PANGO_ELLIPSIZE_NONE, and may change in the
  future. *)

  external set_font_description : t -> Font_description.t option -> unit
    = "ml_pango_layout_set_font_description"
  (** Sets the default font description for the layout.

      If no font description is set on the layout, the font description from the
      layout's context is used. *)

  external set_ellipsize : t -> Pango_enums.ellipsizemode -> unit
    = "ml_pango_layout_set_ellipsize"
  (** Sets the type of ellipsization being performed for @layout.

  Depending on the ellipsization mode @ellipsize text is
  removed from the start, middle, or end of text so they
  fit within the width and height of layout set with
  [method@Pango.Layout.set_width] and [method@Pango.Layout.set_height].

  If the layout contains characters such as newlines that
  force it to be layed out in multiple paragraphs, then whether
  each paragraph is ellipsized separately or the entire layout
  is ellipsized as a whole depends on the set height of the layout.

  The default value is %PANGO_ELLIPSIZE_NONE.

  See [method@Pango.Layout.set_height] for details. *)

  external set_auto_dir : t -> bool -> unit = "ml_pango_layout_set_auto_dir"
  (** Sets whether to calculate the base direction
  for the layout according to its contents.

  When this flag is on (the default), then paragraphs in @layout that
  begin with strong right-to-left characters (Arabic and Hebrew principally),
  will have right-to-left layout, paragraphs with letters from other scripts
  will have left-to-right layout. Paragraphs with only neutral characters
  get their direction from the surrounding paragraphs.

  When %FALSE, the choice between left-to-right and right-to-left
  layout is done according to the base direction of the layout's
  `PangoContext`. (See [method@Pango.Context.set_base_dir]).

  When the auto-computed direction of a paragraph differs from the
  base direction of the context, the interpretation of
  %PANGO_ALIGN_LEFT and %PANGO_ALIGN_RIGHT are swapped. *)

  external set_attributes : t -> Attr_list.t option -> unit
    = "ml_pango_layout_set_attributes"
  (** Sets the text attributes for a layout object.

  References @attrs, so the caller can unref its reference. *)

  external set_alignment : t -> Pango_enums.alignment -> unit
    = "ml_pango_layout_set_alignment"
  (** Sets the alignment for the layout: how partial lines are positioned within
      the horizontal space available.

      The default alignment is %PANGO_ALIGN_LEFT. *)

  external serialize : t -> Pango_enums.layoutserializeflags -> Glib_bytes.t
    = "ml_pango_layout_serialize"
  (** Serializes the @layout for later deserialization via [func@Pango.Layout.deserialize].

  There are no guarantees about the format of the output across different
  versions of Pango and [func@Pango.Layout.deserialize] will reject data
  that it cannot parse.

  The intended use of this function is testing, benchmarking and debugging.
  The format is not meant as a permanent storage format. *)

  external move_cursor_visually : t -> bool -> int -> int -> int -> int * int
    = "ml_pango_layout_move_cursor_visually"
  (** Computes a new cursor position from an old position and a direction.

  If @direction is positive, then the new position will cause the strong
  or weak cursor to be displayed one position to right of where it was
  with the old cursor position. If @direction is negative, it will be
  moved to the left.

  In the presence of bidirectional text, the correspondence between
  logical and visual order will depend on the direction of the current
  run, and there may be jumps when the cursor is moved off of the end
  of a run.

  Motion here is in cursor positions, not in characters, so a single
  call to this function may move the cursor over multiple characters
  when multiple characters combine to form a single grapheme. *)

  external is_wrapped : t -> bool = "ml_pango_layout_is_wrapped"
  (** Queries whether the layout had to wrap any paragraphs.

  This returns %TRUE if a positive width is set on @layout,
  and there are paragraphs exceeding the layout width that have
  to be wrapped. *)

  external is_ellipsized : t -> bool = "ml_pango_layout_is_ellipsized"
  (** Queries whether the layout had to ellipsize any paragraphs.

  This returns %TRUE if the ellipsization mode for @layout
  is not %PANGO_ELLIPSIZE_NONE, a positive width is set on @layout,
  and there are paragraphs exceeding that width that have to be
  ellipsized. *)

  external index_to_pos : t -> int -> Rectangle.t
    = "ml_pango_layout_index_to_pos"
  (** Converts from an index within a `PangoLayout` to the onscreen position
      corresponding to the grapheme at that index.

      The returns is represented as rectangle. Note that `pos->x` is always the
      leading edge of the grapheme and `pos->x + pos->width` the trailing edge
      of the grapheme. If the directionality of the grapheme is right-to-left,
      then `pos->width` will be negative. *)

  external index_to_line_x : t -> int -> bool -> int * int
    = "ml_pango_layout_index_to_line_x"
  (** Converts from byte @index_ within the @layout to line and X position.

  The X position is measured from the left edge of the line. *)

  external get_wrap : t -> Pango_enums.wrapmode = "ml_pango_layout_get_wrap"
  (** Gets the wrap mode for the layout.

      Use [method@Pango.Layout.is_wrapped] to query whether any paragraphs were
      actually wrapped. *)

  external get_width : t -> int = "ml_pango_layout_get_width"
  (** Gets the width to which the lines of the `PangoLayout` should wrap. *)

  external get_unknown_glyphs_count : t -> int
    = "ml_pango_layout_get_unknown_glyphs_count"
  (** Counts the number of unknown glyphs in @layout.

  This function can be used to determine if there are any fonts
  available to render all characters in a certain string, or when
  used in combination with %PANGO_ATTR_FALLBACK, to check if a
  certain font supports all the characters in the string. *)

  external get_text : t -> string = "ml_pango_layout_get_text"
  (** Gets the text in the layout.

      The returned text should not be freed or modified. *)

  external get_tabs : t -> Tab_array.t option = "ml_pango_layout_get_tabs"
  (** Gets the current `PangoTabArray` used by this layout.

      If no `PangoTabArray` has been set, then the default tabs are in use and
      %NULL is returned. Default tabs are every 8 spaces.

      The return value should be freed with [method@Pango.TabArray.free]. *)

  external get_spacing : t -> int = "ml_pango_layout_get_spacing"
  (** Gets the amount of spacing between the lines of the layout. *)

  external get_size : t -> int * int = "ml_pango_layout_get_size"
  (** Determines the logical width and height of a `PangoLayout` in Pango units.

      This is simply a convenience function around
      [method@Pango.Layout.get_extents]. *)

  external get_single_paragraph_mode : t -> bool
    = "ml_pango_layout_get_single_paragraph_mode"
  (** Obtains whether @layout is in single paragraph mode.

  See [method@Pango.Layout.set_single_paragraph_mode]. *)

  external get_serial : t -> int = "ml_pango_layout_get_serial"
  (** Returns the current serial number of @layout.

  The serial number is initialized to an small number larger than zero
  when a new layout is created and is increased whenever the layout is
  changed using any of the setter functions, or the `PangoContext` it
  uses has changed. The serial may wrap, but will never have the value 0.
  Since it can wrap, never compare it with "less than", always use "not equals".

  This can be used to automatically detect changes to a `PangoLayout`,
  and is useful for example to decide whether a layout needs redrawing.
  To force the serial to be increased, use
  [method@Pango.Layout.context_changed]. *)

  external get_pixel_size : t -> int * int = "ml_pango_layout_get_pixel_size"
  (** Determines the logical width and height of a `PangoLayout` in device
      units.

      [method@Pango.Layout.get_size] returns the width and height scaled by
      %PANGO_SCALE. This is simply a convenience function around
      [method@Pango.Layout.get_pixel_extents]. *)

  external get_pixel_extents : t -> Rectangle.t * Rectangle.t
    = "ml_pango_layout_get_pixel_extents"
  (** Computes the logical and ink extents of @layout in device units.

  This function just calls [method@Pango.Layout.get_extents] followed by
  two [func@extents_to_pixels] calls, rounding @ink_rect and @logical_rect
  such that the rounded rectangles fully contain the unrounded one (that is,
  passes them as first argument to [func@Pango.extents_to_pixels]). *)

  external get_log_attrs_readonly : t -> Log_attr.t array * int
    = "ml_pango_layout_get_log_attrs_readonly"
  (** Retrieves an array of logical attributes for each character in
  the @layout.

  This is a faster alternative to [method@Pango.Layout.get_log_attrs].
  The returned array is part of @layout and must not be modified.
  Modifying the layout will invalidate the returned array.

  The number of attributes returned in @n_attrs will be one more
  than the total number of characters in the layout, since there
  need to be attributes corresponding to both the position before
  the first character and the position after the last character. *)

  external get_log_attrs : t -> Log_attr.t array * int
    = "ml_pango_layout_get_log_attrs"
  (** Retrieves an array of logical attributes for each character in
  the @layout. *)

  external get_lines_readonly : t -> Layout_line.t list
    = "ml_pango_layout_get_lines_readonly"
  (** Returns the lines of the @layout as a list.

  This is a faster alternative to [method@Pango.Layout.get_lines],
  but the user is not expected to modify the contents of the lines
  (glyphs, glyph widths, etc.). *)

  external get_lines : t -> Layout_line.t list = "ml_pango_layout_get_lines"
  (** Returns the lines of the @layout as a list.

  Use the faster [method@Pango.Layout.get_lines_readonly] if you do not
  plan to modify the contents of the lines (glyphs, glyph widths, etc.). *)

  external get_line_spacing : t -> float = "ml_pango_layout_get_line_spacing"
  (** Gets the line spacing factor of @layout.

  See [method@Pango.Layout.set_line_spacing]. *)

  external get_line_readonly : t -> int -> Layout_line.t option
    = "ml_pango_layout_get_line_readonly"
  (** Retrieves a particular line from a `PangoLayout`.

      This is a faster alternative to [method@Pango.Layout.get_line], but the
      user is not expected to modify the contents of the line (glyphs, glyph
      widths, etc.). *)

  external get_line_count : t -> int = "ml_pango_layout_get_line_count"
  (** Retrieves the count of lines for the @layout. *)

  external get_line : t -> int -> Layout_line.t option
    = "ml_pango_layout_get_line"
  (** Retrieves a particular line from a `PangoLayout`.

      Use the faster [method@Pango.Layout.get_line_readonly] if you do not plan
      to modify the contents of the line (glyphs, glyph widths, etc.). *)

  external get_justify_last_line : t -> bool
    = "ml_pango_layout_get_justify_last_line"
  (** Gets whether the last line should be stretched to fill the entire width of
      the layout. *)

  external get_justify : t -> bool = "ml_pango_layout_get_justify"
  (** Gets whether each complete line should be stretched to fill the entire
      width of the layout. *)

  external get_iter : t -> Layout_iter.t = "ml_pango_layout_get_iter"
  (** Returns an iterator to iterate over the visual extents of the layout. *)

  external get_indent : t -> int = "ml_pango_layout_get_indent"
  (** Gets the paragraph indent width in Pango units.

      A negative value indicates a hanging indentation. *)

  external get_height : t -> int = "ml_pango_layout_get_height"
  (** Gets the height of layout used for ellipsization.

      See [method@Pango.Layout.set_height] for details. *)

  external get_font_description : t -> Font_description.t option
    = "ml_pango_layout_get_font_description"
  (** Gets the font description for the layout, if any. *)

  external get_extents : t -> Rectangle.t * Rectangle.t
    = "ml_pango_layout_get_extents"
  (** Computes the logical and ink extents of @layout.

  Logical extents are usually what you want for positioning things. Note
  that both extents may have non-zero x and y. You may want to use those
  to offset where you render the layout. Not doing that is a very typical
  bug that shows up as right-to-left layouts not being correctly positioned
  in a layout with a set width.

  The extents are given in layout coordinates and in Pango units; layout
  coordinates begin at the top left corner of the layout. *)

  external get_ellipsize : t -> Pango_enums.ellipsizemode
    = "ml_pango_layout_get_ellipsize"
  (** Gets the type of ellipsization being performed for @layout.

  See [method@Pango.Layout.set_ellipsize].

  Use [method@Pango.Layout.is_ellipsized] to query whether any
  paragraphs were actually ellipsized. *)

  external get_direction : t -> int -> Pango_enums.direction
    = "ml_pango_layout_get_direction"
  (** Gets the text direction at the given character position in @layout. *)

  external get_cursor_pos : t -> int -> Rectangle.t * Rectangle.t
    = "ml_pango_layout_get_cursor_pos"
  (** Given an index within a layout, determines the positions that of the
      strong and weak cursors if the insertion point is at that index.

      The position of each cursor is stored as a zero-width rectangle with the
      height of the run extents.

      <picture> <source srcset="cursor-positions-dark.png"
      media="(prefers-color-scheme: dark)"> <img alt="Cursor positions"
      src="cursor-positions-light.png"> </picture>

      The strong cursor location is the location where characters of the
      directionality equal to the base direction of the layout are inserted. The
      weak cursor location is the location where characters of the
      directionality opposite to the base direction of the layout are inserted.

      The following example shows text with both a strong and a weak cursor.

      <picture> <source srcset="split-cursor-dark.png"
      media="(prefers-color-scheme: dark)"> <img alt="Strong and weak cursors"
      src="split-cursor-light.png"> </picture>

      The strong cursor has a little arrow pointing to the right, the weak
      cursor to the left. Typing a 'c' in this situation will insert the
      character after the 'b', and typing another Hebrew character, like 'ג',
      will insert it at the end. *)

  external get_context :
    t -> Context_and__font_and__font_map_and__fontset.Context.t
    = "ml_pango_layout_get_context"
  (** Retrieves the `PangoContext` used for this layout. *)

  external get_character_count : t -> int
    = "ml_pango_layout_get_character_count"
  (** Returns the number of Unicode characters in the
  the text of @layout. *)

  external get_caret_pos : t -> int -> Rectangle.t * Rectangle.t
    = "ml_pango_layout_get_caret_pos"
  (** Given an index within a layout, determines the positions that of the
      strong and weak cursors if the insertion point is at that index.

      This is a variant of [method@Pango.Layout.get_cursor_pos] that applies
      font metric information about caret slope and offset to the positions it
      returns.

      <picture> <source srcset="caret-metrics-dark.png"
      media="(prefers-color-scheme: dark)"> <img alt="Caret metrics"
      src="caret-metrics-light.png"> </picture> *)

  external get_baseline : t -> int = "ml_pango_layout_get_baseline"
  (** Gets the Y position of baseline of the first line in @layout. *)

  external get_auto_dir : t -> bool = "ml_pango_layout_get_auto_dir"
  (** Gets whether to calculate the base direction for the layout according to
      its contents.

      See [method@Pango.Layout.set_auto_dir]. *)

  external get_attributes : t -> Attr_list.t option
    = "ml_pango_layout_get_attributes"
  (** Gets the attribute list for the layout, if any. *)

  external get_alignment : t -> Pango_enums.alignment
    = "ml_pango_layout_get_alignment"
  (** Gets the alignment for the layout: how partial lines are positioned within
      the horizontal space available. *)

  external copy : t -> t = "ml_pango_layout_copy"
  (** Creates a deep copy-by-value of the layout.

      The attribute list, tab array, and text from the original layout are all
      copied by value. *)

  external context_changed : t -> unit = "ml_pango_layout_context_changed"
  (** Forces recomputation of any state in the `PangoLayout` that might depend
      on the layout's context.

      This function should be called if you make changes to the context
      subsequent to creating the layout. *)
end

and Layout_iter : sig
  type t = [ `layout_iter ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_pango_layout_iter_get_type"

  (* Methods *)

  external next_run : t -> bool = "ml_pango_layout_iter_next_run"
  (** Moves @iter forward to the next run in visual order.

  If @iter was already at the end of the layout, returns %FALSE. *)

  external next_line : t -> bool = "ml_pango_layout_iter_next_line"
  (** Moves @iter forward to the start of the next line.

  If @iter is already on the last line, returns %FALSE. *)

  external next_cluster : t -> bool = "ml_pango_layout_iter_next_cluster"
  (** Moves @iter forward to the next cluster in visual order.

  If @iter was already at the end of the layout, returns %FALSE. *)

  external next_char : t -> bool = "ml_pango_layout_iter_next_char"
  (** Moves @iter forward to the next character in visual order.

  If @iter was already at the end of the layout, returns %FALSE. *)

  external get_run_extents : t -> Rectangle.t * Rectangle.t
    = "ml_pango_layout_iter_get_run_extents"
  (** Gets the extents of the current run in layout coordinates.

      Layout coordinates have the origin at the top left of the entire layout.
  *)

  external get_run_baseline : t -> int = "ml_pango_layout_iter_get_run_baseline"
  (** Gets the Y position of the current run's baseline, in layout coordinates.

      Layout coordinates have the origin at the top left of the entire layout.

      The run baseline can be different from the line baseline, for example due
      to superscript or subscript positioning. *)

  external get_line_yrange : t -> int * int
    = "ml_pango_layout_iter_get_line_yrange"
  (** Divides the vertical space in the `PangoLayout` being iterated over
      between the lines in the layout, and returns the space belonging to the
      current line.

      A line's range includes the line's logical extents. plus half of the
      spacing above and below the line, if [method@Pango.Layout.set_spacing] has
      been called to set layout spacing. The Y positions are in layout
      coordinates (origin at top left of the entire layout).

      Note: Since 1.44, Pango uses line heights for placing lines, and there may
      be gaps between the ranges returned by this function. *)

  external get_line_readonly : t -> Layout_line.t option
    = "ml_pango_layout_iter_get_line_readonly"
  (** Gets the current line for read-only access.

      This is a faster alternative to [method@Pango.LayoutIter.get_line], but
      the user is not expected to modify the contents of the line (glyphs, glyph
      widths, etc.). *)

  external get_line_extents : t -> Rectangle.t * Rectangle.t
    = "ml_pango_layout_iter_get_line_extents"
  (** Obtains the extents of the current line.

      Extents are in layout coordinates (origin is the top-left corner of the
      entire `PangoLayout`). Thus the extents returned by this function will be
      the same width/height but not at the same x/y as the extents returned from
      [method@Pango.LayoutLine.get_extents]. *)

  external get_line : t -> Layout_line.t option
    = "ml_pango_layout_iter_get_line"
  (** Gets the current line.

      Use the faster [method@Pango.LayoutIter.get_line_readonly] if you do not
      plan to modify the contents of the line (glyphs, glyph widths, etc.). *)

  external get_layout_extents : t -> Rectangle.t * Rectangle.t
    = "ml_pango_layout_iter_get_layout_extents"
  (** Obtains the extents of the `PangoLayout` being iterated over. *)

  external get_layout : t -> Layout.t option = "ml_pango_layout_iter_get_layout"
  (** Gets the layout associated with a `PangoLayoutIter`. *)

  external get_index : t -> int = "ml_pango_layout_iter_get_index"
  (** Gets the current byte index.

      Note that iterating forward by char moves in visual order, not logical
      order, so indexes may not be sequential. Also, the index may be equal to
      the length of the text in the layout, if on the %NULL run (see
      [method@Pango.LayoutIter.get_run]). *)

  external get_cluster_extents : t -> Rectangle.t * Rectangle.t
    = "ml_pango_layout_iter_get_cluster_extents"
  (** Gets the extents of the current cluster, in layout coordinates.

      Layout coordinates have the origin at the top left of the entire layout.
  *)

  external get_char_extents : t -> Rectangle.t
    = "ml_pango_layout_iter_get_char_extents"
  (** Gets the extents of the current character, in layout coordinates.

      Layout coordinates have the origin at the top left of the entire layout.

      Only logical extents can sensibly be obtained for characters; ink extents
      make sense only down to the level of clusters. *)

  external get_baseline : t -> int = "ml_pango_layout_iter_get_baseline"
  (** Gets the Y position of the current line's baseline, in layout coordinates.

      Layout coordinates have the origin at the top left of the entire layout.
  *)

  external at_last_line : t -> bool = "ml_pango_layout_iter_at_last_line"
  (** Determines whether @iter is on the last line of the layout. *)
end
