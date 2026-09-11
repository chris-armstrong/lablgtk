(* GENERATED CODE - DO NOT EDIT *)
(* Rectangle: Rectangle *)

type t = [ `rectangle ] Gobject.obj
(** Represents a rectangle.

    `GdkRectangle` is identical to `cairo_rectangle_t`. Together with Cairo’s
    `cairo_region_t` data type, these are the central types for representing
    sets of pixels.

    The intersection of two rectangles can be computed with
    [method@Gdk.Rectangle.intersect]; to find the union of two rectangles use
    [method@Gdk.Rectangle.union].

    The `cairo_region_t` type provided by Cairo is usually used for managing
    non-rectangular clipping of graphical operations.

    The Graphene library has a number of other data types for regions and
    volumes in 2D and 3D. *)

external gtype : unit -> Gobject.Type.t = "ml_gdk_rectangle_get_type"

(* Methods *)

external union : t -> t -> t = "ml_gdk_rectangle_union"
(** Calculates the union of two rectangles.

The union of rectangles @src1 and @src2 is the smallest rectangle which
includes both @src1 and @src2 within it. It is allowed for @dest to be
the same as either @src1 or @src2.

Note that this function does not ignore 'empty' rectangles (ie. with
zero width or height). *)

external intersect : t -> t -> bool * t = "ml_gdk_rectangle_intersect"
(** Calculates the intersection of two rectangles.

It is allowed for @dest to be the same as either @src1 or @src2.
If the rectangles do not intersect, @dest’s width and height is set
to 0 and its x and y values are undefined. If you are only interested
in whether the rectangles intersect, but not in the intersecting area
itself, pass %NULL for @dest. *)

external equal : t -> t -> bool = "ml_gdk_rectangle_equal"
(** Checks if the two given rectangles are equal. *)

external contains_point : t -> int -> int -> bool
  = "ml_gdk_rectangle_contains_point"
(** Returns %TRUE if @rect contains the point described by @x and @y. *)
