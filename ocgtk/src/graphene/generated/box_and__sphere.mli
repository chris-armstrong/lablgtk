(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec Box : sig
  type t = [ `box ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_box_alloc"
  (** Create a new Box *)

  (* Methods *)

  external union : t -> t -> t = "ml_graphene_box_union"
  (** Unions the two given #graphene_box_t. *)

  external intersection : t -> t -> bool * t = "ml_graphene_box_intersection"
  (** Intersects the two given #graphene_box_t.

  If the two boxes do not intersect, @res will contain a degenerate box
  initialized with graphene_box_empty(). *)

  external init_from_vectors : t -> int -> Vec3_and__vec4.Vec3.t array -> t
    = "ml_graphene_box_init_from_vectors"
  (** Initializes the given #graphene_box_t with the given array
  of vertices.

  If @n_vectors is 0, the returned box is initialized with
  graphene_box_empty(). *)

  external init_from_vec3 :
    t -> Vec3_and__vec4.Vec3.t option -> Vec3_and__vec4.Vec3.t option -> t
    = "ml_graphene_box_init_from_vec3"
  (** Initializes the given #graphene_box_t with two vertices stored inside
      #graphene_vec3_t. *)

  external init_from_points : t -> int -> Point3_d.t array -> t
    = "ml_graphene_box_init_from_points"
  (** Initializes the given #graphene_box_t with the given array
  of vertices.

  If @n_points is 0, the returned box is initialized with
  graphene_box_empty(). *)

  external init_from_box : t -> t -> t = "ml_graphene_box_init_from_box"
  (** Initializes the given #graphene_box_t with the vertices of another
      #graphene_box_t. *)

  external init : t -> Point3_d.t option -> Point3_d.t option -> t
    = "ml_graphene_box_init"
  (** Initializes the given #graphene_box_t with two vertices. *)

  external get_width : t -> float = "ml_graphene_box_get_width"
  (** Retrieves the size of the @box on the X axis. *)

  external get_vertices : t -> Vec3_and__vec4.Vec3.t array
    = "ml_graphene_box_get_vertices"
  (** Computes the vertices of the given #graphene_box_t. *)

  external get_size : t -> Vec3_and__vec4.Vec3.t = "ml_graphene_box_get_size"
  (** Retrieves the size of the box on all three axes, and stores
  it into the given @size vector. *)

  external get_min : t -> Point3_d.t = "ml_graphene_box_get_min"
  (** Retrieves the coordinates of the minimum point of the given
      #graphene_box_t. *)

  external get_max : t -> Point3_d.t = "ml_graphene_box_get_max"
  (** Retrieves the coordinates of the maximum point of the given
      #graphene_box_t. *)

  external get_height : t -> float = "ml_graphene_box_get_height"
  (** Retrieves the size of the @box on the Y axis. *)

  external get_depth : t -> float = "ml_graphene_box_get_depth"
  (** Retrieves the size of the @box on the Z axis. *)

  external get_center : t -> Point3_d.t = "ml_graphene_box_get_center"
  (** Retrieves the coordinates of the center of a #graphene_box_t. *)

  external get_bounding_sphere : t -> Sphere.t
    = "ml_graphene_box_get_bounding_sphere"
  (** Computes the bounding #graphene_sphere_t capable of containing the given
      #graphene_box_t. *)

  external expand_vec3 : t -> Vec3_and__vec4.Vec3.t -> t
    = "ml_graphene_box_expand_vec3"
  (** Expands the dimensions of @box to include the coordinates of the
  given vector. *)

  external expand_scalar : t -> float -> t = "ml_graphene_box_expand_scalar"
  (** Expands the dimensions of @box by the given @scalar value.

  If @scalar is positive, the #graphene_box_t will grow; if @scalar is
  negative, the #graphene_box_t will shrink. *)

  external expand : t -> Point3_d.t -> t = "ml_graphene_box_expand"
  (** Expands the dimensions of @box to include the coordinates at @point. *)

  external equal : t -> t -> bool = "ml_graphene_box_equal"
  (** Checks whether the two given boxes are equal. *)

  external contains_point : t -> Point3_d.t -> bool
    = "ml_graphene_box_contains_point"
  (** Checks whether @box contains the given @point. *)

  external contains_box : t -> t -> bool = "ml_graphene_box_contains_box"
  (** Checks whether the #graphene_box_t @a contains the given
  #graphene_box_t @b. *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_box_get_type"
end

and Sphere : sig
  type t = [ `sphere ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_sphere_alloc"
  (** Create a new Sphere *)

  (* Methods *)

  external translate : t -> Point3_d.t -> t = "ml_graphene_sphere_translate"
  (** Translates the center of the given #graphene_sphere_t using the @point
  coordinates as the delta of the translation. *)

  external is_empty : t -> bool = "ml_graphene_sphere_is_empty"
  (** Checks whether the sphere has a zero radius. *)

  external init_from_vectors :
    t -> int -> Vec3_and__vec4.Vec3.t array -> Point3_d.t option -> t
    = "ml_graphene_sphere_init_from_vectors"
  (** Initializes the given #graphene_sphere_t using the given array
  of 3D coordinates so that the sphere includes them.

  The center of the sphere can either be specified, or will be center
  of the 3D volume that encompasses all @vectors. *)

  external init_from_points :
    t -> int -> Point3_d.t array -> Point3_d.t option -> t
    = "ml_graphene_sphere_init_from_points"
  (** Initializes the given #graphene_sphere_t using the given array
  of 3D coordinates so that the sphere includes them.

  The center of the sphere can either be specified, or will be center
  of the 3D volume that encompasses all @points. *)

  external init : t -> Point3_d.t option -> float -> t
    = "ml_graphene_sphere_init"
  (** Initializes the given #graphene_sphere_t with the given @center and @radius. *)

  external get_radius : t -> float = "ml_graphene_sphere_get_radius"
  (** Retrieves the radius of a #graphene_sphere_t. *)

  external get_center : t -> Point3_d.t = "ml_graphene_sphere_get_center"
  (** Retrieves the coordinates of the center of a #graphene_sphere_t. *)

  external get_bounding_box : t -> Box.t = "ml_graphene_sphere_get_bounding_box"
  (** Computes the bounding box capable of containing the given
      #graphene_sphere_t. *)

  external equal : t -> t -> bool = "ml_graphene_sphere_equal"
  (** Checks whether two #graphene_sphere_t are equal. *)

  external distance : t -> Point3_d.t -> float = "ml_graphene_sphere_distance"
  (** Computes the distance of the given @point from the surface of
  a #graphene_sphere_t. *)

  external contains_point : t -> Point3_d.t -> bool
    = "ml_graphene_sphere_contains_point"
  (** Checks whether the given @point is contained in the volume
  of a #graphene_sphere_t. *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_sphere_get_type"
end
