(* GENERATED CODE - DO NOT EDIT *)
(* Frustum: Frustum *)

type t = [ `frustum ] Gobject.obj
(** A 3D volume delimited by 2D clip planes.

    The contents of the `graphene_frustum_t` are private, and should not be
    modified directly. *)

external gtype : unit -> Gobject.Type.t = "ml_graphene_frustum_get_type"

external alloc : unit -> t = "ml_graphene_frustum_alloc"
(** Create a new Frustum *)

(* Methods *)

external intersects_sphere : t -> Box_and__sphere.Sphere.t -> bool
  = "ml_graphene_frustum_intersects_sphere"
(** Checks whether the given @sphere intersects a plane of
a #graphene_frustum_t. *)

external intersects_box : t -> Box_and__sphere.Box.t -> bool
  = "ml_graphene_frustum_intersects_box"
(** Checks whether the given @box intersects a plane of
a #graphene_frustum_t. *)

external init_from_matrix :
  t ->
  Euler_and__matrix_and__plane_and__quaternion_and__ray_and__triangle.Matrix.t ->
  t = "ml_graphene_frustum_init_from_matrix"
(** Initializes a #graphene_frustum_t using the given @matrix. *)

external init_from_frustum : t -> t -> t
  = "ml_graphene_frustum_init_from_frustum"
(** Initializes the given #graphene_frustum_t using the clipping planes of
    another #graphene_frustum_t. *)

external init :
  t ->
  Euler_and__matrix_and__plane_and__quaternion_and__ray_and__triangle.Plane.t ->
  Euler_and__matrix_and__plane_and__quaternion_and__ray_and__triangle.Plane.t ->
  Euler_and__matrix_and__plane_and__quaternion_and__ray_and__triangle.Plane.t ->
  Euler_and__matrix_and__plane_and__quaternion_and__ray_and__triangle.Plane.t ->
  Euler_and__matrix_and__plane_and__quaternion_and__ray_and__triangle.Plane.t ->
  Euler_and__matrix_and__plane_and__quaternion_and__ray_and__triangle.Plane.t ->
  t = "ml_graphene_frustum_init_bytecode" "ml_graphene_frustum_init_native"
(** Initializes the given #graphene_frustum_t using the provided clipping
    planes. *)

external get_planes :
  t ->
  Euler_and__matrix_and__plane_and__quaternion_and__ray_and__triangle.Plane.t
  array = "ml_graphene_frustum_get_planes"
(** Retrieves the planes that define the given #graphene_frustum_t. *)

external equal : t -> t -> bool = "ml_graphene_frustum_equal"
(** Checks whether the two given #graphene_frustum_t are equal. *)

external contains_point : t -> Point3_d.t -> bool
  = "ml_graphene_frustum_contains_point"
(** Checks whether a point is inside the volume defined by the given
    #graphene_frustum_t. *)
