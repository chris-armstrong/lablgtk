(* GENERATED CODE - DO NOT EDIT *)
(* PathBuilder: PathBuilder *)

type t = [ `path_builder ] Gobject.obj
(** Constructs `GskPath` objects.

A path is constructed like this:

```c
GskPath *
construct_path (void)
{
  GskPathBuilder *builder;

  builder = gsk_path_builder_new ();

  // add contours to the path here

  return gsk_path_builder_free_to_path (builder);
```

Adding contours to the path can be done in two ways.
The easiest option is to use the `gsk_path_builder_add_*` group
of functions that add predefined contours to the current path,
either common shapes like [method@Gsk.PathBuilder.add_circle]
or by adding from other paths like [method@Gsk.PathBuilder.add_path].

The `gsk_path_builder_add_*` methods always add complete contours,
and do not use or modify the current point.

The other option is to define each line and curve manually with
the `gsk_path_builder_*_to` group of functions. You start with
a call to [method@Gsk.PathBuilder.move_to] to set the starting point
and then use multiple calls to any of the drawing functions to
move the pen along the plane. Once you are done, you can call
[method@Gsk.PathBuilder.close] to close the path by connecting it
back with a line to the starting point.

This is similar to how paths are drawn in Cairo.

Note that `GskPathBuilder` will reduce the degree of added Bézier
curves as much as possible, to simplify rendering. *)

external gtype : unit -> Gobject.Type.t = "ml_gsk_path_builder_get_type"

external new_ : unit -> t = "ml_gsk_path_builder_new"
(** Create a new PathBuilder *)

(* Methods *)

external to_path : t -> Path_and__path_measure_and__path_point.Path.t
  = "ml_gsk_path_builder_to_path"
(** Creates a new path from the given builder.

    The given `GskPathBuilder` is reset to the initial state once this function
    returns. Calling this function again on the same builder instance will
    therefore produce an empty path, not a copy of the same path.

    This function is intended primarily for language bindings. C code should use
    [method@Gsk.PathBuilder.free_to_path]. *)

external svg_arc_to :
  t -> float -> float -> float -> bool -> bool -> float -> float -> unit
  = "ml_gsk_path_builder_svg_arc_to_bytecode"
    "ml_gsk_path_builder_svg_arc_to_native"
(** Implements arc-to according to the SVG spec.

A convenience function that implements the
[SVG arc_to](https://www.w3.org/TR/SVG11/paths.html#PathDataEllipticalArcCommands)
functionality.

After this, @x, @y will be the new current point. *)

external rel_svg_arc_to :
  t -> float -> float -> float -> bool -> bool -> float -> float -> unit
  = "ml_gsk_path_builder_rel_svg_arc_to_bytecode"
    "ml_gsk_path_builder_rel_svg_arc_to_native"
(** Implements arc-to according to the SVG spec.

    All coordinates are given relative to the current point.

    This is the relative version of [method@Gsk.PathBuilder.svg_arc_to]. *)

external rel_quad_to : t -> float -> float -> float -> float -> unit
  = "ml_gsk_path_builder_rel_quad_to"
(** Adds a [quadratic Bézier curve](https://en.wikipedia.org/wiki/B%C3%A9zier_curve)
from the current point to @x2, @y2 with @x1, @y1 the control point.

All coordinates are given relative to the current point.

This is the relative version of [method@Gsk.PathBuilder.quad_to]. *)

external rel_move_to : t -> float -> float -> unit
  = "ml_gsk_path_builder_rel_move_to"
(** Starts a new contour by placing the pen at @x, @y
relative to the current point.

This is the relative version of [method@Gsk.PathBuilder.move_to]. *)

external rel_line_to : t -> float -> float -> unit
  = "ml_gsk_path_builder_rel_line_to"
(** Draws a line from the current point to a point offset from it
by @x, @y and makes it the new current point.

This is the relative version of [method@Gsk.PathBuilder.line_to]. *)

external rel_html_arc_to :
  t -> float -> float -> float -> float -> float -> unit
  = "ml_gsk_path_builder_rel_html_arc_to_bytecode"
    "ml_gsk_path_builder_rel_html_arc_to_native"
(** Implements arc-to according to the HTML Canvas spec.

    All coordinates are given relative to the current point.

    This is the relative version of [method@Gsk.PathBuilder.html_arc_to]. *)

external rel_cubic_to :
  t -> float -> float -> float -> float -> float -> float -> unit
  = "ml_gsk_path_builder_rel_cubic_to_bytecode"
    "ml_gsk_path_builder_rel_cubic_to_native"
(** Adds a [cubic Bézier curve](https://en.wikipedia.org/wiki/B%C3%A9zier_curve)
from the current point to @x3, @y3 with @x1, @y1 and @x2, @y2 as the control
points.

All coordinates are given relative to the current point.

This is the relative version of [method@Gsk.PathBuilder.cubic_to]. *)

external rel_conic_to : t -> float -> float -> float -> float -> float -> unit
  = "ml_gsk_path_builder_rel_conic_to_bytecode"
    "ml_gsk_path_builder_rel_conic_to_native"
(** Adds a [conic curve](https://en.wikipedia.org/wiki/Non-uniform_rational_B-spline)
from the current point to @x2, @y2 with the given @weight and @x1, @y1 as the
control point.

All coordinates are given relative to the current point.

This is the relative version of [method@Gsk.PathBuilder.conic_to]. *)

external rel_arc_to : t -> float -> float -> float -> float -> unit
  = "ml_gsk_path_builder_rel_arc_to"
(** Adds an elliptical arc from the current point to @x2, @y2
with @x1, @y1 determining the tangent directions.

All coordinates are given relative to the current point.

This is the relative version of [method@Gsk.PathBuilder.arc_to]. *)

external ref : t -> t = "ml_gsk_path_builder_ref"
(** Acquires a reference on the given builder.

    This function is intended primarily for language bindings. `GskPathBuilder`
    objects should not be kept around. *)

external quad_to : t -> float -> float -> float -> float -> unit
  = "ml_gsk_path_builder_quad_to"
(** Adds a [quadratic Bézier curve](https://en.wikipedia.org/wiki/B%C3%A9zier_curve)
from the current point to @x2, @y2 with @x1, @y1 as the control point.

After this, @x2, @y2 will be the new current point.

<picture>
  <source srcset="quad-dark.png" media="(prefers-color-scheme: dark)">
  <img alt="Quad To" src="quad-light.png">
</picture> *)

external move_to : t -> float -> float -> unit = "ml_gsk_path_builder_move_to"
(** Starts a new contour by placing the pen at @x, @y.

If this function is called twice in succession, the first
call will result in a contour made up of a single point.
The second call will start a new contour. *)

external line_to : t -> float -> float -> unit = "ml_gsk_path_builder_line_to"
(** Draws a line from the current point to @x, @y and makes it
the new current point.

<picture>
  <source srcset="line-dark.png" media="(prefers-color-scheme: dark)">
  <img alt="Line To" src="line-light.png">
</picture> *)

external html_arc_to : t -> float -> float -> float -> float -> float -> unit
  = "ml_gsk_path_builder_html_arc_to_bytecode"
    "ml_gsk_path_builder_html_arc_to_native"
(** Implements arc-to according to the HTML Canvas spec.

A convenience function that implements the
[HTML arc_to](https://html.spec.whatwg.org/multipage/canvas.html#dom-context-2d-arcto-dev)
functionality.

After this, the current point will be the point where
the circle with the given radius touches the line from
@x1, @y1 to @x2, @y2. *)

external get_current_point : t -> Ocgtk_graphene.Graphene.Wrappers.Point.t
  = "ml_gsk_path_builder_get_current_point"
(** Gets the current point.

    The current point is used for relative drawing commands and updated after
    every operation.

    When the builder is created, the default current point is set to `0, 0`.
    Note that this is different from cairo, which starts out without a current
    point. *)

external cubic_to :
  t -> float -> float -> float -> float -> float -> float -> unit
  = "ml_gsk_path_builder_cubic_to_bytecode"
    "ml_gsk_path_builder_cubic_to_native"
(** Adds a [cubic Bézier curve](https://en.wikipedia.org/wiki/B%C3%A9zier_curve)
from the current point to @x3, @y3 with @x1, @y1 and @x2, @y2 as the control
points.

After this, @x3, @y3 will be the new current point.

<picture>
  <source srcset="cubic-dark.png" media="(prefers-color-scheme: dark)">
  <img alt="Cubic To" src="cubic-light.png">
</picture> *)

external conic_to : t -> float -> float -> float -> float -> float -> unit
  = "ml_gsk_path_builder_conic_to_bytecode"
    "ml_gsk_path_builder_conic_to_native"
(** Adds a [conic curve](https://en.wikipedia.org/wiki/Non-uniform_rational_B-spline)
from the current point to @x2, @y2 with the given @weight and @x1, @y1 as the
control point.

The weight determines how strongly the curve is pulled towards the control point.
A conic with weight 1 is identical to a quadratic Bézier curve with the same points.

Conic curves can be used to draw ellipses and circles. They are also known as
rational quadratic Bézier curves.

After this, @x2, @y2 will be the new current point.

<picture>
  <source srcset="conic-dark.png" media="(prefers-color-scheme: dark)">
  <img alt="Conic To" src="conic-light.png">
</picture> *)

external close : t -> unit = "ml_gsk_path_builder_close"
(** Ends the current contour with a line back to the start point.

    Note that this is different from calling [method@Gsk.PathBuilder.line_to]
    with the start point in that the contour will be closed. A closed contour
    behaves differently from an open one. When stroking, its start and end point
    are considered connected, so they will be joined via the line join, and not
    ended with line caps. *)

external arc_to : t -> float -> float -> float -> float -> unit
  = "ml_gsk_path_builder_arc_to"
(** Adds an elliptical arc from the current point to @x2, @y2
with @x1, @y1 determining the tangent directions.

After this, @x2, @y2 will be the new current point.

Note: Two points and their tangents do not determine
a unique ellipse, so GSK just picks one. If you need more
precise control, use [method@Gsk.PathBuilder.conic_to]
or [method@Gsk.PathBuilder.svg_arc_to].

<picture>
  <source srcset="arc-dark.png" media="(prefers-color-scheme: dark)">
  <img alt="Arc To" src="arc-light.png">
</picture> *)

external add_segment :
  t ->
  Path_and__path_measure_and__path_point.Path.t ->
  Path_and__path_measure_and__path_point.Path_point.t ->
  Path_and__path_measure_and__path_point.Path_point.t ->
  unit = "ml_gsk_path_builder_add_segment"
(** Adds a segment of a path to the builder.

If @start is equal to or after @end, the path will first add the
segment from @start to the end of the path, and then add the segment
from the beginning to @end. If the path is closed, these segments
will be connected.

Note that this method always adds a path with the given start point
and end point. To add a closed path, use [method@Gsk.PathBuilder.add_path]. *)

external add_rounded_rect : t -> Rounded_rect.t -> unit
  = "ml_gsk_path_builder_add_rounded_rect"
(** Adds a rounded rectangle as a new contour.

    The path is going around the rectangle in clockwise direction. *)

external add_reverse_path :
  t -> Path_and__path_measure_and__path_point.Path.t -> unit
  = "ml_gsk_path_builder_add_reverse_path"
(** Appends all of @path to the builder, in reverse order. *)

external add_rect : t -> Ocgtk_graphene.Graphene.Wrappers.Rect.t -> unit
  = "ml_gsk_path_builder_add_rect"
(** Adds a rectangle as a new contour.

    The path is going around the rectangle in clockwise direction.

    If the the width or height are 0, the path will be a closed horizontal or
    vertical line. If both are 0, it'll be a closed dot. *)

external add_path : t -> Path_and__path_measure_and__path_point.Path.t -> unit
  = "ml_gsk_path_builder_add_path"
(** Appends all of @path to the builder. *)

external add_layout : t -> Ocgtk_pango.Pango.Wrappers.Layout.t -> unit
  = "ml_gsk_path_builder_add_layout"
(** Adds the outlines for the glyphs in @layout to the builder. *)

external add_circle :
  t -> Ocgtk_graphene.Graphene.Wrappers.Point.t -> float -> unit
  = "ml_gsk_path_builder_add_circle"
(** Adds a circle as a new contour.

The path is going around the circle in clockwise direction.

If @radius is zero, the contour will be a closed point. *)

external add_cairo_path : t -> Ocgtk_cairo.Cairo.Wrappers.Path.t -> unit
  = "ml_gsk_path_builder_add_cairo_path"
(** Adds a Cairo path to the builder.

    You can use cairo_copy_path() to access the path from a Cairo context. *)
