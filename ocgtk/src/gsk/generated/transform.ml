(* GENERATED CODE - DO NOT EDIT *)
(* Transform: Transform *)

type t = [ `transform ] Gobject.obj
(** Describes a 3D transform.

    Unlike `graphene_matrix_t`, `GskTransform` retains the steps in how a
    transform was constructed, and allows inspecting them. It is modeled after
    the way CSS describes transforms.

    `GskTransform` objects are immutable and cannot be changed after creation.
    This means code can safely expose them as properties of objects without
    having to worry about others changing them. *)

external gtype : unit -> Gobject.Type.t = "ml_gsk_transform_get_type"

external new_ : unit -> t = "ml_gsk_transform_new"
(** Create a new Transform *)

(* Methods *)

external translate_3d :
  t -> Ocgtk_graphene.Graphene.Wrappers.Point3_d.t -> t option
  = "ml_gsk_transform_translate_3d"
(** Translates @next by @point.

This function consumes @next. Use [method@Gsk.Transform.ref] first
if you want to keep it around. *)

external translate : t -> Ocgtk_graphene.Graphene.Wrappers.Point.t -> t option
  = "ml_gsk_transform_translate"
(** Translates @next in 2-dimensional space by @point.

This function consumes @next. Use [method@Gsk.Transform.ref] first
if you want to keep it around. *)

external transform_point :
  t ->
  Ocgtk_graphene.Graphene.Wrappers.Point.t ->
  Ocgtk_graphene.Graphene.Wrappers.Point.t = "ml_gsk_transform_transform_point"
(** Transforms a point using the given transform. *)

external transform_bounds :
  t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t ->
  Ocgtk_graphene.Graphene.Wrappers.Rect.t = "ml_gsk_transform_transform_bounds"
(** Transforms a rectangle using the given transform.

    The result is the bounding box containing the coplanar quad. *)

external transform : t -> t option -> t option = "ml_gsk_transform_transform"
(** Applies all the operations from @other to @next.

This function consumes @next. Use [method@Gsk.Transform.ref] first
if you want to keep it around. *)

external to_translate : t -> float * float = "ml_gsk_transform_to_translate"
(** Converts a transform to a translation operation.

@self must be a 2D transformation. If you are not
sure, use

    gsk_transform_get_category() >= GSK_TRANSFORM_CATEGORY_2D_TRANSLATE

to check. *)

external to_string : t -> string = "ml_gsk_transform_to_string"
(** Converts the transform into a human-readable string.

    The resulting string can be parsed with [func@Gsk.Transform.parse].

    This is a wrapper around [method@Gsk.Transform.print]. *)

external to_matrix : t -> Ocgtk_graphene.Graphene.Wrappers.Matrix.t
  = "ml_gsk_transform_to_matrix"
(** Computes the 4x4 matrix for the transform.

The previous value of @out_matrix will be ignored. *)

external to_affine : t -> float * float * float * float
  = "ml_gsk_transform_to_affine"
(** Converts a transform to 2D affine transformation factors.

To recreate an equivalent transform from the factors returned
by this function, use

    gsk_transform_scale (
        gsk_transform_translate (
            NULL,
            &GRAPHENE_POINT_T (dx, dy)),
        sx, sy)

@self must be a 2D affine transformation. If you are not
sure, use

    gsk_transform_get_category() >= GSK_TRANSFORM_CATEGORY_2D_AFFINE

to check. *)

external to_2d_components :
  t -> float * float * float * float * float * float * float
  = "ml_gsk_transform_to_2d_components"
(** Converts a transform to 2D transformation factors.

To recreate an equivalent transform from the factors returned
by this function, use

    gsk_transform_skew (
        gsk_transform_scale (
            gsk_transform_rotate (
                gsk_transform_translate (NULL, &GRAPHENE_POINT_INIT (dx, dy)),
                angle),
            scale_x, scale_y),
        skew_x, skew_y)

@self must be a 2D transformation. If you are not sure, use

    gsk_transform_get_category() >= GSK_TRANSFORM_CATEGORY_2D

to check. *)

external to_2d : t -> float * float * float * float * float * float
  = "ml_gsk_transform_to_2d"
(** Converts a transform to a 2D transformation matrix.

@self must be a 2D transformation. If you are not
sure, use

    gsk_transform_get_category() >= GSK_TRANSFORM_CATEGORY_2D

to check.

The returned values are a subset of the full 4x4 matrix that
is computed by [method@Gsk.Transform.to_matrix] and have the
following layout:

```
  | xx yx |   |  a  b  0 |
  | xy yy | = |  c  d  0 |
  | dx dy |   | tx ty  1 |
```

This function can be used to convert between a `GskTransform`
and a matrix type from other 2D drawing libraries, in particular
Cairo. *)

external skew : t -> float -> float -> t option = "ml_gsk_transform_skew"
(** Applies a skew transform.

This function consumes @next. Use [method@Gsk.Transform.ref] first
if you want to keep it around. *)

external scale_3d : t -> float -> float -> float -> t option
  = "ml_gsk_transform_scale_3d"
(** Scales @next by the given factors.

This function consumes @next. Use [method@Gsk.Transform.ref] first
if you want to keep it around. *)

external scale : t -> float -> float -> t option = "ml_gsk_transform_scale"
(** Scales @next in 2-dimensional space by the given factors.

Use [method@Gsk.Transform.scale_3d] to scale in all 3 dimensions.

This function consumes @next. Use [method@Gsk.Transform.ref] first
if you want to keep it around. *)

external rotate_3d :
  t -> float -> Ocgtk_graphene.Graphene.Wrappers.Vec3.t -> t option
  = "ml_gsk_transform_rotate_3d"
(** Rotates @next @angle degrees around @axis.

For a rotation in 2D space, use [method@Gsk.Transform.rotate]

This function consumes @next. Use [method@Gsk.Transform.ref] first
if you want to keep it around. *)

external rotate : t -> float -> t option = "ml_gsk_transform_rotate"
(** Rotates @next by an angle around the Z axis.

The rotation happens around the origin point of (0, 0).

This function consumes @next. Use [method@Gsk.Transform.ref] first
if you want to keep it around. *)

external ref : t -> t option = "ml_gsk_transform_ref"
(** Acquires a reference on the given transform. *)

external perspective : t -> float -> t = "ml_gsk_transform_perspective"
(** Applies a perspective projection transform.

This transform scales points in X and Y based on their Z value,
scaling points with positive Z values away from the origin, and
those with negative Z values towards the origin. Points
on the z=0 plane are unchanged.

This function consumes @next. Use [method@Gsk.Transform.ref] first
if you want to keep it around. *)

external matrix_2d :
  t -> float -> float -> float -> float -> float -> float -> t option
  = "ml_gsk_transform_matrix_2d_bytecode" "ml_gsk_transform_matrix_2d_native"
(** Multiplies @next with the matrix [ xx yx x0; xy yy y0; 0 0 1 ].

The result of calling [method@Gsk.Transform.to_2d] on the returned
[struct@Gsk.Transform] should match the input passed to this
function.

This function consumes @next. Use [method@Gsk.Transform.ref] first
if you want to keep it around. *)

external matrix : t -> Ocgtk_graphene.Graphene.Wrappers.Matrix.t -> t
  = "ml_gsk_transform_matrix"
(** Multiplies @next with the given @matrix.

This function consumes @next. Use [method@Gsk.Transform.ref] first
if you want to keep it around. *)

external invert : t -> t option = "ml_gsk_transform_invert"
(** Inverts the given transform.

If @self is not invertible, `NULL` is returned.
Note that inverting `NULL` also returns `NULL`, which is
the correct inverse of `NULL`. If you need to differentiate
between those cases, you should check @self is not `NULL`
before calling this function.

This function consumes @self. Use [method@Gsk.Transform.ref] first
if you want to keep it around. *)

external get_category : t -> Gsk_enums.transformcategory
  = "ml_gsk_transform_get_category"
(** Returns the category this transform belongs to. *)

external equal : t -> t option -> bool = "ml_gsk_transform_equal"
(** Checks two transforms for equality. *)
