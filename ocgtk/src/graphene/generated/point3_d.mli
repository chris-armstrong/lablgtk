(* GENERATED CODE - DO NOT EDIT *)
(* Point3D: Point3D *)

type t = [ `point3_d ] Gobject.obj
(** A point with three components: X, Y, and Z. *)

external gtype : unit -> Gobject.Type.t = "ml_graphene_point3_d_get_type"

external alloc : unit -> t = "ml_graphene_point3d_alloc"
(** Create a new Point3D *)

(* Methods *)

external to_vec3 : t -> Vec3_and__vec4.Vec3.t = "ml_graphene_point3d_to_vec3"
(** Stores the coordinates of a #graphene_point3d_t into a #graphene_vec3_t. *)

external scale : t -> float -> t = "ml_graphene_point3d_scale"
(** Scales the coordinates of the given #graphene_point3d_t by
the given @factor. *)

external normalize_viewport : t -> Rect.t -> float -> float -> t
  = "ml_graphene_point3d_normalize_viewport"
(** Normalizes the coordinates of a #graphene_point3d_t using the given viewport
    and clipping planes.

    The coordinates of the resulting #graphene_point3d_t will be in the
    [ -1, 1 ] range. *)

external normalize : t -> t = "ml_graphene_point3d_normalize"
(** Computes the normalization of the vector represented by the coordinates of
    the given #graphene_point3d_t. *)

external near : t -> t -> float -> bool = "ml_graphene_point3d_near"
(** Checks whether the two points are near each other, within
an @epsilon factor. *)

external length : t -> float = "ml_graphene_point3d_length"
(** Computes the length of the vector represented by the coordinates of the
    given #graphene_point3d_t. *)

external interpolate : t -> t -> float -> t = "ml_graphene_point3d_interpolate"
(** Linearly interpolates each component of @a and @b using the
provided @factor, and places the result in @res. *)

external init_from_vec3 : t -> Vec3_and__vec4.Vec3.t -> t
  = "ml_graphene_point3d_init_from_vec3"
(** Initializes a #graphene_point3d_t using the components of a
    #graphene_vec3_t. *)

external init_from_point : t -> t -> t = "ml_graphene_point3d_init_from_point"
(** Initializes a #graphene_point3d_t using the coordinates of another
    #graphene_point3d_t. *)

external init : t -> float -> float -> float -> t = "ml_graphene_point3d_init"
(** Initializes a #graphene_point3d_t with the given coordinates. *)

external equal : t -> t -> bool = "ml_graphene_point3d_equal"
(** Checks whether two given points are equal. *)

external dot : t -> t -> float = "ml_graphene_point3d_dot"
(** Computes the dot product of the two given #graphene_point3d_t. *)

external distance : t -> t -> float * Vec3_and__vec4.Vec3.t
  = "ml_graphene_point3d_distance"
(** Computes the distance between the two given #graphene_point3d_t. *)

external cross : t -> t -> t = "ml_graphene_point3d_cross"
(** Computes the cross product of the two given #graphene_point3d_t. *)
