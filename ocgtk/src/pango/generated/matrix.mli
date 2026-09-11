(* GENERATED CODE - DO NOT EDIT *)
(* Matrix: Matrix *)

type t = [ `matrix ] Gobject.obj
(** A `PangoMatrix` specifies a transformation between user-space and device
    coordinates.

    The transformation is given by

    ``` x_device = x_user * matrix->xx + y_user * matrix->xy + matrix->x0;
    y_device = x_user * matrix->yx + y_user * matrix->yy + matrix->y0; ``` *)

external gtype : unit -> Gobject.Type.t = "ml_pango_matrix_get_type"

(* Methods *)

external translate : t -> float -> float -> unit = "ml_pango_matrix_translate"
(** Changes the transformation represented by @matrix to be the
transformation given by first translating by (@tx, @ty)
then applying the original transformation. *)

external transform_rectangle : t -> Rectangle.t -> unit
  = "ml_pango_matrix_transform_rectangle"
(** First transforms @rect using @matrix, then calculates the bounding box
of the transformed rectangle.

This function is useful for example when you want to draw a rotated
@PangoLayout to an image buffer, and want to know how large the image
should be and how much you should shift the layout when rendering.

If you have a rectangle in device units (pixels), use
[method@Pango.Matrix.transform_pixel_rectangle].

If you have the rectangle in Pango units and want to convert to
transformed pixel bounding box, it is more accurate to transform it first
(using this function) and pass the result to pango_extents_to_pixels(),
first argument, for an inclusive rounded rectangle.
However, there are valid reasons that you may want to convert
to pixels first and then transform, for example when the transformed
coordinates may overflow in Pango units (large matrix translation for
example). *)

external transform_point : t -> float -> float -> unit
  = "ml_pango_matrix_transform_point"
(** Transforms the point (@x, @y) by @matrix. *)

external transform_pixel_rectangle : t -> Rectangle.t -> unit
  = "ml_pango_matrix_transform_pixel_rectangle"
(** First transforms the @rect using @matrix, then calculates the bounding box
of the transformed rectangle.

This function is useful for example when you want to draw a rotated
@PangoLayout to an image buffer, and want to know how large the image
should be and how much you should shift the layout when rendering.

For better accuracy, you should use [method@Pango.Matrix.transform_rectangle]
on original rectangle in Pango units and convert to pixels afterward
using [func@extents_to_pixels]'s first argument. *)

external transform_distance : t -> float -> float -> unit
  = "ml_pango_matrix_transform_distance"
(** Transforms the distance vector (@dx,@dy) by @matrix.

This is similar to [method@Pango.Matrix.transform_point],
except that the translation components of the transformation
are ignored. The calculation of the returned vector is as follows:

```
dx2 = dx1 * xx + dy1 * xy;
dy2 = dx1 * yx + dy1 * yy;
```

Affine transformations are position invariant, so the same vector
always transforms to the same vector. If (@x1,@y1) transforms
to (@x2,@y2) then (@x1+@dx1,@y1+@dy1) will transform to
(@x1+@dx2,@y1+@dy2) for all values of @x1 and @x2. *)

external scale : t -> float -> float -> unit = "ml_pango_matrix_scale"
(** Changes the transformation represented by @matrix to be the
transformation given by first scaling by @sx in the X direction
and @sy in the Y direction then applying the original
transformation. *)

external rotate : t -> float -> unit = "ml_pango_matrix_rotate"
(** Changes the transformation represented by @matrix to be the
transformation given by first rotating by @degrees degrees
counter-clockwise then applying the original transformation. *)

external get_slant_ratio : t -> float = "ml_pango_matrix_get_slant_ratio"
(** Gets the slant ratio of a matrix.

    For a simple shear matrix in the form:

    1 λ 0 1

    this is simply λ. *)

external get_font_scale_factors : t -> float * float
  = "ml_pango_matrix_get_font_scale_factors"
(** Calculates the scale factor of a matrix on the width and height of the font.

That is, @xscale is the scale factor in the direction of the X coordinate,
and @yscale is the scale factor in the direction perpendicular to the
vector that the X coordinate is mapped to.

Note that output numbers will always be non-negative. *)

external get_font_scale_factor : t -> float
  = "ml_pango_matrix_get_font_scale_factor"
(** Returns the scale factor of a matrix on the height of the font.

    That is, the scale factor in the direction perpendicular to the vector that
    the X coordinate is mapped to. If the scale in the X coordinate is needed as
    well, use [method@Pango.Matrix.get_font_scale_factors]. *)

external concat : t -> t -> unit = "ml_pango_matrix_concat"
(** Changes the transformation represented by @matrix to be the
transformation given by first applying transformation
given by @new_matrix then applying the original transformation. *)
