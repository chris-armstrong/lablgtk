(* GENERATED CODE - DO NOT EDIT *)
(* Renderer: Renderer *)

type t = [ `renderer | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_pango_renderer_get_type"

(* Methods *)

external set_matrix : t -> Matrix.t option -> unit
  = "ml_pango_renderer_set_matrix"
(** Sets the transformation matrix that will be applied when rendering. *)

external set_color : t -> Pango_enums.renderpart -> Color.t option -> unit
  = "ml_pango_renderer_set_color"
(** Sets the color for part of the rendering.

    Also see [method@Pango.Renderer.set_alpha]. *)

external set_alpha : t -> Pango_enums.renderpart -> UInt16.t -> unit
  = "ml_pango_renderer_set_alpha"
(** Sets the alpha for part of the rendering.

Note that the alpha may only be used if a color is
specified for @part as well. *)

external part_changed : t -> Pango_enums.renderpart -> unit
  = "ml_pango_renderer_part_changed"
(** Informs Pango that the way that the rendering is done
for @part has changed.

This should be called if the rendering changes in a way that would
prevent multiple pieces being joined together into one drawing call.
For instance, if a subclass of `PangoRenderer` was to add a stipple
option for drawing underlines, it needs to call

```
pango_renderer_part_changed (render, PANGO_RENDER_PART_UNDERLINE);
```

When the stipple changes or underlines with different stipples
might be joined together. Pango automatically calls this for
changes to colors. (See [method@Pango.Renderer.set_color]) *)

external get_matrix : t -> Matrix.t option = "ml_pango_renderer_get_matrix"
(** Gets the transformation matrix that will be applied when rendering.

    See [method@Pango.Renderer.set_matrix]. *)

external get_layout_line : t -> Layout_line.t option
  = "ml_pango_renderer_get_layout_line"
(** Gets the layout line currently being rendered using @renderer.

Calling this function only makes sense from inside a subclass's
methods, like in its draw_shape vfunc, for example.

The returned layout line should not be modified while still being
rendered. *)

external get_layout : t -> Layout_and__layout_iter.Layout.t option
  = "ml_pango_renderer_get_layout"
(** Gets the layout currently being rendered using @renderer.

Calling this function only makes sense from inside a subclass's
methods, like in its draw_shape vfunc, for example.

The returned layout should not be modified while still being
rendered. *)

external get_color : t -> Pango_enums.renderpart -> Color.t option
  = "ml_pango_renderer_get_color"
(** Gets the current rendering color for the specified part. *)

external get_alpha : t -> Pango_enums.renderpart -> UInt16.t
  = "ml_pango_renderer_get_alpha"
(** Gets the current alpha for the specified part. *)

external draw_trapezoid :
  t ->
  Pango_enums.renderpart ->
  float ->
  float ->
  float ->
  float ->
  float ->
  float ->
  unit
  = "ml_pango_renderer_draw_trapezoid_bytecode"
    "ml_pango_renderer_draw_trapezoid_native"
(** Draws a trapezoid with the parallel sides aligned with the X axis using the
    given `PangoRenderer`; coordinates are in device space. *)

external draw_rectangle :
  t -> Pango_enums.renderpart -> int -> int -> int -> int -> unit
  = "ml_pango_renderer_draw_rectangle_bytecode"
    "ml_pango_renderer_draw_rectangle_native"
(** Draws an axis-aligned rectangle in user space coordinates with the
specified `PangoRenderer`.

This should be called while @renderer is already active.
Use [method@Pango.Renderer.activate] to activate a renderer. *)

external draw_layout_line : t -> Layout_line.t -> int -> int -> unit
  = "ml_pango_renderer_draw_layout_line"
(** Draws @line with the specified `PangoRenderer`.

This draws the glyph items that make up the line, as well as
shapes, backgrounds and lines that are specified by the attributes
of those items. *)

external draw_layout :
  t -> Layout_and__layout_iter.Layout.t -> int -> int -> unit
  = "ml_pango_renderer_draw_layout"
(** Draws @layout with the specified `PangoRenderer`.

This is equivalent to drawing the lines of the layout, at their
respective positions relative to @x, @y. *)

external draw_glyphs :
  t ->
  Context_and__font_and__font_map_and__fontset.Font.t ->
  Glyph_string.t ->
  int ->
  int ->
  unit = "ml_pango_renderer_draw_glyphs"
(** Draws the glyphs in @glyphs with the specified `PangoRenderer`. *)

external draw_glyph_item :
  t -> string option -> Glyph_item.t -> int -> int -> unit
  = "ml_pango_renderer_draw_glyph_item"
(** Draws the glyphs in @glyph_item with the specified `PangoRenderer`,
embedding the text associated with the glyphs in the output if the
output format supports it.

This is useful for rendering text in PDF.

Note that this method does not handle attributes in @glyph_item.
If you want colors, shapes and lines handled automatically according
to those attributes, you need to use pango_renderer_draw_layout_line()
or pango_renderer_draw_layout().

Note that @text is the start of the text for layout, which is then
indexed by `glyph_item->item->offset`.

If @text is %NULL, this simply calls [method@Pango.Renderer.draw_glyphs].

The default implementation of this method simply falls back to
[method@Pango.Renderer.draw_glyphs]. *)

external draw_glyph :
  t ->
  Context_and__font_and__font_map_and__fontset.Font.t ->
  int ->
  float ->
  float ->
  unit = "ml_pango_renderer_draw_glyph"
(** Draws a single glyph with coordinates in device space. *)

external draw_error_underline : t -> int -> int -> int -> int -> unit
  = "ml_pango_renderer_draw_error_underline"
(** Draw a squiggly line that approximately covers the given rectangle
in the style of an underline used to indicate a spelling error.

The width of the underline is rounded to an integer number
of up/down segments and the resulting rectangle is centered
in the original rectangle.

This should be called while @renderer is already active.
Use [method@Pango.Renderer.activate] to activate a renderer. *)

external deactivate : t -> unit = "ml_pango_renderer_deactivate"
(** Cleans up after rendering operations on @renderer.

See docs for [method@Pango.Renderer.activate]. *)

external activate : t -> unit = "ml_pango_renderer_activate"
(** Does initial setup before rendering operations on @renderer.

[method@Pango.Renderer.deactivate] should be called when done drawing.
Calls such as [method@Pango.Renderer.draw_layout] automatically
activate the layout before drawing on it.

Calls to [method@Pango.Renderer.activate] and
[method@Pango.Renderer.deactivate] can be nested and the
renderer will only be initialized and deinitialized once. *)
