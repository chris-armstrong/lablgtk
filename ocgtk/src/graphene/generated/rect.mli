(* GENERATED CODE - DO NOT EDIT *)
(* Rect: Rect *)

type t = [ `rect ] Gobject.obj
(** The location and size of a rectangle region.

    The width and height of a #graphene_rect_t can be negative; for instance, a
    #graphene_rect_t with an origin of [ 0, 0 ] and a size of [ 10, 10 ] is
    equivalent to a #graphene_rect_t with an origin of [ 10, 10 ] and a size of
    [ -10, -10 ].

    Application code can normalize rectangles using graphene_rect_normalize();
    this function will ensure that the width and height of a rectangle are
    positive values. All functions taking a #graphene_rect_t as an argument will
    internally operate on a normalized copy; all functions returning a
    #graphene_rect_t will always return a normalized rectangle. *)

external gtype : unit -> Gobject.Type.t = "ml_graphene_rect_get_type"

(* Methods *)

external union : t -> t -> t = "ml_graphene_rect_union"
(** Computes the union of the two given rectangles.

    ![](rectangle-union.png)

    The union in the image above is the blue outline. *)

external scale : t -> float -> float -> t = "ml_graphene_rect_scale"
(** Scales the size and origin of a rectangle horizontaly by @s_h,
and vertically by @s_v. The result @res is normalized. *)

external round_to_pixel : t -> t = "ml_graphene_rect_round_to_pixel"
(** Rounds the origin and the size of the given rectangle to their nearest
    integer values; the rounding is guaranteed to be large enough to contain the
    original rectangle. *)

external round_extents : t -> t = "ml_graphene_rect_round_extents"
(** Rounds the origin of the given rectangle to its nearest integer value and
    and recompute the size so that the rectangle is large enough to contain all
    the conrners of the original rectangle.

    This function is the equivalent of calling `floor` on the coordinates of the
    origin, and recomputing the size calling `ceil` on the bottom-right
    coordinates.

    If you want to be sure that the rounded rectangle completely covers the area
    that was covered by the original rectangle — i.e. you want to cover the area
    including all its corners — this function will make sure that the size is
    recomputed taking into account the ceiling of the coordinates of the
    bottom-right corner. If the difference between the original coordinates and
    the coordinates of the rounded rectangle is greater than the difference
    between the original size and and the rounded size, then the move of the
    origin would not be compensated by a move in the anti-origin, leaving the
    corners of the original rectangle outside the rounded one. *)

external round : t -> t = "ml_graphene_rect_round"
(** Rounds the origin and size of the given rectangle to their nearest integer
    values; the rounding is guaranteed to be large enough to have an area bigger
    or equal to the original rectangle, but might not fully contain its extents.
    Use graphene_rect_round_extents() in case you need to round to a rectangle
    that covers fully the original one.

    This function is the equivalent of calling `floor` on the coordinates of the
    origin, and `ceil` on the size. *)

external offset_r : t -> float -> float -> t = "ml_graphene_rect_offset_r"
(** Offsets the origin of the given rectangle by @d_x and @d_y.

The size of the rectangle is left unchanged. *)

external offset : t -> float -> float -> t = "ml_graphene_rect_offset"
(** Offsets the origin by @d_x and @d_y.

The size of the rectangle is unchanged. *)

external normalize_r : t -> t = "ml_graphene_rect_normalize_r"
(** Normalizes the passed rectangle.

    This function ensures that the size of the rectangle is made of positive
    values, and that the origin is in the top-left corner of the rectangle. *)

external normalize : t -> t = "ml_graphene_rect_normalize"
(** Normalizes the passed rectangle.

    This function ensures that the size of the rectangle is made of positive
    values, and that the origin is the top-left corner of the rectangle. *)

external intersection : t -> t -> bool * t = "ml_graphene_rect_intersection"
(** Computes the intersection of the two given rectangles.

![](rectangle-intersection.png)

The intersection in the image above is the blue outline.

If the two rectangles do not intersect, @res will contain
a degenerate rectangle with origin in (0, 0) and a size of 0. *)

external interpolate : t -> t -> float -> t = "ml_graphene_rect_interpolate"
(** Linearly interpolates the origin and size of the two given rectangles. *)

external inset_r : t -> float -> float -> t = "ml_graphene_rect_inset_r"
(** Changes the given rectangle to be smaller, or larger depending on the
given inset parameters.

To create an inset rectangle, use positive @d_x or @d_y values; to
create a larger, encompassing rectangle, use negative @d_x or @d_y
values.

The origin of the rectangle is offset by @d_x and @d_y, while the size
is adjusted by `(2 * @d_x, 2 * @d_y)`. If @d_x and @d_y are positive
values, the size of the rectangle is decreased; if @d_x and @d_y are
negative values, the size of the rectangle is increased.

If the size of the resulting inset rectangle has a negative width or
height then the size will be set to zero. *)

external inset : t -> float -> float -> t = "ml_graphene_rect_inset"
(** Changes the given rectangle to be smaller, or larger depending on the
given inset parameters.

To create an inset rectangle, use positive @d_x or @d_y values; to
create a larger, encompassing rectangle, use negative @d_x or @d_y
values.

The origin of the rectangle is offset by @d_x and @d_y, while the size
is adjusted by `(2 * @d_x, 2 * @d_y)`. If @d_x and @d_y are positive
values, the size of the rectangle is decreased; if @d_x and @d_y are
negative values, the size of the rectangle is increased.

If the size of the resulting inset rectangle has a negative width or
height then the size will be set to zero. *)

external init_from_rect : t -> t -> t = "ml_graphene_rect_init_from_rect"
(** Initializes @r using the given @src rectangle.

This function will implicitly normalize the #graphene_rect_t
before returning. *)

external init : t -> float -> float -> float -> float -> t
  = "ml_graphene_rect_init"
(** Initializes the given #graphene_rect_t with the given values.

    This function will implicitly normalize the #graphene_rect_t before
    returning. *)

external get_y : t -> float = "ml_graphene_rect_get_y"
(** Retrieves the normalized Y coordinate of the origin of the given rectangle.
*)

external get_x : t -> float = "ml_graphene_rect_get_x"
(** Retrieves the normalized X coordinate of the origin of the given rectangle.
*)

external get_width : t -> float = "ml_graphene_rect_get_width"
(** Retrieves the normalized width of the given rectangle. *)

external get_vertices : t -> Vec2.t array = "ml_graphene_rect_get_vertices"
(** Computes the four vertices of a #graphene_rect_t. *)

external get_top_right : t -> Point.t = "ml_graphene_rect_get_top_right"
(** Retrieves the coordinates of the top-right corner of the given rectangle. *)

external get_top_left : t -> Point.t = "ml_graphene_rect_get_top_left"
(** Retrieves the coordinates of the top-left corner of the given rectangle. *)

external get_height : t -> float = "ml_graphene_rect_get_height"
(** Retrieves the normalized height of the given rectangle. *)

external get_center : t -> Point.t = "ml_graphene_rect_get_center"
(** Retrieves the coordinates of the center of the given rectangle. *)

external get_bottom_right : t -> Point.t = "ml_graphene_rect_get_bottom_right"
(** Retrieves the coordinates of the bottom-right corner of the given rectangle.
*)

external get_bottom_left : t -> Point.t = "ml_graphene_rect_get_bottom_left"
(** Retrieves the coordinates of the bottom-left corner of the given rectangle.
*)

external get_area : t -> float = "ml_graphene_rect_get_area"
(** Compute the area of given normalized rectangle. *)

external expand : t -> Point.t -> t = "ml_graphene_rect_expand"
(** Expands a #graphene_rect_t to contain the given #graphene_point_t. *)

external equal : t -> t -> bool = "ml_graphene_rect_equal"
(** Checks whether the two given rectangle are equal. *)

external contains_rect : t -> t -> bool = "ml_graphene_rect_contains_rect"
(** Checks whether a #graphene_rect_t fully contains the given rectangle. *)

external contains_point : t -> Point.t -> bool
  = "ml_graphene_rect_contains_point"
(** Checks whether a #graphene_rect_t contains the given coordinates. *)
