(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec Euler : sig
  type t = [ `euler ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_euler_alloc"
  (** Create a new Euler *)

  (* Methods *)

  external to_vec3 : t -> Vec3_and__vec4.Vec3.t = "ml_graphene_euler_to_vec3"
  (** Retrieves the angles of a #graphene_euler_t and initializes a
      #graphene_vec3_t with them. *)

  external to_quaternion : t -> Quaternion.t = "ml_graphene_euler_to_quaternion"
  (** Converts a #graphene_euler_t into a #graphene_quaternion_t. *)

  external to_matrix : t -> Matrix.t = "ml_graphene_euler_to_matrix"
  (** Converts a #graphene_euler_t into a transformation matrix expressing
  the extrinsic composition of rotations described by the Euler angles.

  The rotations are applied over the reference frame axes in the order
  associated with the #graphene_euler_t; for instance, if the order
  used to initialize @e is %GRAPHENE_EULER_ORDER_XYZ:

   * the first rotation moves the body around the X axis with
     an angle φ
   * the second rotation moves the body around the Y axis with
     an angle of ϑ
   * the third rotation moves the body around the Z axis with
     an angle of ψ

  The rotation sign convention is right-handed, to preserve compatibility
  between Euler-based, quaternion-based, and angle-axis-based rotations. *)

  external reorder : t -> Graphene_enums.eulerorder -> t
    = "ml_graphene_euler_reorder"
  (** Reorders a #graphene_euler_t using @order.

  This function is equivalent to creating a #graphene_quaternion_t from the
  given #graphene_euler_t, and then converting the quaternion into another
  #graphene_euler_t. *)

  external init_with_order :
    t -> float -> float -> float -> Graphene_enums.eulerorder -> t
    = "ml_graphene_euler_init_with_order"
  (** Initializes a #graphene_euler_t with the given angles and @order. *)

  external init_from_vec3 :
    t -> Vec3_and__vec4.Vec3.t option -> Graphene_enums.eulerorder -> t
    = "ml_graphene_euler_init_from_vec3"
  (** Initializes a #graphene_euler_t using the angles contained in a
  #graphene_vec3_t.

  If the #graphene_vec3_t @v is %NULL, the #graphene_euler_t will be
  initialized with all angles set to 0. *)

  external init_from_radians :
    t -> float -> float -> float -> Graphene_enums.eulerorder -> t
    = "ml_graphene_euler_init_from_radians"
  (** Initializes a #graphene_euler_t using the given angles and order of
      rotation. *)

  external init_from_quaternion :
    t -> Quaternion.t option -> Graphene_enums.eulerorder -> t
    = "ml_graphene_euler_init_from_quaternion"
  (** Initializes a #graphene_euler_t using the given normalized quaternion.

  If the #graphene_quaternion_t @q is %NULL, the #graphene_euler_t will
  be initialized with all angles set to 0. *)

  external init_from_matrix :
    t -> Matrix.t option -> Graphene_enums.eulerorder -> t
    = "ml_graphene_euler_init_from_matrix"
  (** Initializes a #graphene_euler_t using the given rotation matrix.

  If the #graphene_matrix_t @m is %NULL, the #graphene_euler_t will
  be initialized with all angles set to 0. *)

  external init_from_euler : t -> t option -> t
    = "ml_graphene_euler_init_from_euler"
  (** Initializes a #graphene_euler_t using the angles and order of
  another #graphene_euler_t.

  If the #graphene_euler_t @src is %NULL, this function is equivalent
  to calling graphene_euler_init() with all angles set to 0. *)

  external init : t -> float -> float -> float -> t = "ml_graphene_euler_init"
  (** Initializes a #graphene_euler_t using the given angles.

      The order of the rotations is %GRAPHENE_EULER_ORDER_DEFAULT. *)

  external get_z : t -> float = "ml_graphene_euler_get_z"
  (** Retrieves the rotation angle on the Z axis, in degrees. *)

  external get_y : t -> float = "ml_graphene_euler_get_y"
  (** Retrieves the rotation angle on the Y axis, in degrees. *)

  external get_x : t -> float = "ml_graphene_euler_get_x"
  (** Retrieves the rotation angle on the X axis, in degrees. *)

  external get_order : t -> Graphene_enums.eulerorder
    = "ml_graphene_euler_get_order"
  (** Retrieves the order used to apply the rotations described in the
      #graphene_euler_t structure, when converting to and from other structures,
      like #graphene_quaternion_t and #graphene_matrix_t.

      This function does not return the %GRAPHENE_EULER_ORDER_DEFAULT
      enumeration value; it will return the effective order of rotation instead.
  *)

  external get_gamma : t -> float = "ml_graphene_euler_get_gamma"
  (** Retrieves the third component of the Euler angle vector, depending on the
      order of rotation.

      See also: graphene_euler_get_z() *)

  external get_beta : t -> float = "ml_graphene_euler_get_beta"
  (** Retrieves the second component of the Euler angle vector, depending on the
      order of rotation.

      See also: graphene_euler_get_y() *)

  external get_alpha : t -> float = "ml_graphene_euler_get_alpha"
  (** Retrieves the first component of the Euler angle vector, depending on the
      order of rotation.

      See also: graphene_euler_get_x() *)

  external equal : t -> t -> bool = "ml_graphene_euler_equal"
  (** Checks if two #graphene_euler_t are equal. *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_euler_get_type"
end = struct
  type t = [ `euler ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_euler_alloc"
  (** Create a new Euler *)

  (* Methods *)

  external to_vec3 : t -> Vec3_and__vec4.Vec3.t = "ml_graphene_euler_to_vec3"
  (** Retrieves the angles of a #graphene_euler_t and initializes a
      #graphene_vec3_t with them. *)

  external to_quaternion : t -> Quaternion.t = "ml_graphene_euler_to_quaternion"
  (** Converts a #graphene_euler_t into a #graphene_quaternion_t. *)

  external to_matrix : t -> Matrix.t = "ml_graphene_euler_to_matrix"
  (** Converts a #graphene_euler_t into a transformation matrix expressing
  the extrinsic composition of rotations described by the Euler angles.

  The rotations are applied over the reference frame axes in the order
  associated with the #graphene_euler_t; for instance, if the order
  used to initialize @e is %GRAPHENE_EULER_ORDER_XYZ:

   * the first rotation moves the body around the X axis with
     an angle φ
   * the second rotation moves the body around the Y axis with
     an angle of ϑ
   * the third rotation moves the body around the Z axis with
     an angle of ψ

  The rotation sign convention is right-handed, to preserve compatibility
  between Euler-based, quaternion-based, and angle-axis-based rotations. *)

  external reorder : t -> Graphene_enums.eulerorder -> t
    = "ml_graphene_euler_reorder"
  (** Reorders a #graphene_euler_t using @order.

  This function is equivalent to creating a #graphene_quaternion_t from the
  given #graphene_euler_t, and then converting the quaternion into another
  #graphene_euler_t. *)

  external init_with_order :
    t -> float -> float -> float -> Graphene_enums.eulerorder -> t
    = "ml_graphene_euler_init_with_order"
  (** Initializes a #graphene_euler_t with the given angles and @order. *)

  external init_from_vec3 :
    t -> Vec3_and__vec4.Vec3.t option -> Graphene_enums.eulerorder -> t
    = "ml_graphene_euler_init_from_vec3"
  (** Initializes a #graphene_euler_t using the angles contained in a
  #graphene_vec3_t.

  If the #graphene_vec3_t @v is %NULL, the #graphene_euler_t will be
  initialized with all angles set to 0. *)

  external init_from_radians :
    t -> float -> float -> float -> Graphene_enums.eulerorder -> t
    = "ml_graphene_euler_init_from_radians"
  (** Initializes a #graphene_euler_t using the given angles and order of
      rotation. *)

  external init_from_quaternion :
    t -> Quaternion.t option -> Graphene_enums.eulerorder -> t
    = "ml_graphene_euler_init_from_quaternion"
  (** Initializes a #graphene_euler_t using the given normalized quaternion.

  If the #graphene_quaternion_t @q is %NULL, the #graphene_euler_t will
  be initialized with all angles set to 0. *)

  external init_from_matrix :
    t -> Matrix.t option -> Graphene_enums.eulerorder -> t
    = "ml_graphene_euler_init_from_matrix"
  (** Initializes a #graphene_euler_t using the given rotation matrix.

  If the #graphene_matrix_t @m is %NULL, the #graphene_euler_t will
  be initialized with all angles set to 0. *)

  external init_from_euler : t -> t option -> t
    = "ml_graphene_euler_init_from_euler"
  (** Initializes a #graphene_euler_t using the angles and order of
  another #graphene_euler_t.

  If the #graphene_euler_t @src is %NULL, this function is equivalent
  to calling graphene_euler_init() with all angles set to 0. *)

  external init : t -> float -> float -> float -> t = "ml_graphene_euler_init"
  (** Initializes a #graphene_euler_t using the given angles.

      The order of the rotations is %GRAPHENE_EULER_ORDER_DEFAULT. *)

  external get_z : t -> float = "ml_graphene_euler_get_z"
  (** Retrieves the rotation angle on the Z axis, in degrees. *)

  external get_y : t -> float = "ml_graphene_euler_get_y"
  (** Retrieves the rotation angle on the Y axis, in degrees. *)

  external get_x : t -> float = "ml_graphene_euler_get_x"
  (** Retrieves the rotation angle on the X axis, in degrees. *)

  external get_order : t -> Graphene_enums.eulerorder
    = "ml_graphene_euler_get_order"
  (** Retrieves the order used to apply the rotations described in the
      #graphene_euler_t structure, when converting to and from other structures,
      like #graphene_quaternion_t and #graphene_matrix_t.

      This function does not return the %GRAPHENE_EULER_ORDER_DEFAULT
      enumeration value; it will return the effective order of rotation instead.
  *)

  external get_gamma : t -> float = "ml_graphene_euler_get_gamma"
  (** Retrieves the third component of the Euler angle vector, depending on the
      order of rotation.

      See also: graphene_euler_get_z() *)

  external get_beta : t -> float = "ml_graphene_euler_get_beta"
  (** Retrieves the second component of the Euler angle vector, depending on the
      order of rotation.

      See also: graphene_euler_get_y() *)

  external get_alpha : t -> float = "ml_graphene_euler_get_alpha"
  (** Retrieves the first component of the Euler angle vector, depending on the
      order of rotation.

      See also: graphene_euler_get_x() *)

  external equal : t -> t -> bool = "ml_graphene_euler_equal"
  (** Checks if two #graphene_euler_t are equal. *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_euler_get_type"
end

and Matrix : sig
  type t = [ `matrix ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_matrix_alloc"
  (** Create a new Matrix *)

  (* Methods *)

  external untransform_point : t -> Point.t -> Rect.t -> bool * Point.t
    = "ml_graphene_matrix_untransform_point"
  (** Undoes the transformation of a #graphene_point_t using the
  given matrix, within the given axis aligned rectangular @bounds. *)

  external untransform_bounds : t -> Rect.t -> Rect.t -> Rect.t
    = "ml_graphene_matrix_untransform_bounds"
  (** Undoes the transformation on the corners of a #graphene_rect_t using the
  given matrix, within the given axis aligned rectangular @bounds. *)

  external unproject_point3d : t -> t -> Point3_d.t -> Point3_d.t
    = "ml_graphene_matrix_unproject_point3d"
  (** Unprojects the given @point using the @projection matrix and
  a @modelview matrix. *)

  external transpose : t -> t = "ml_graphene_matrix_transpose"
  (** Transposes the given matrix. *)

  external translate : t -> Point3_d.t -> unit = "ml_graphene_matrix_translate"
  (** Adds a translation transformation to @m using the coordinates
  of the given #graphene_point3d_t.

  This is the equivalent of calling graphene_matrix_init_translate() and
  then multiplying @m with the translation matrix. *)

  external transform_vec4 : t -> Vec3_and__vec4.Vec4.t -> Vec3_and__vec4.Vec4.t
    = "ml_graphene_matrix_transform_vec4"
  (** Transforms the given #graphene_vec4_t using the matrix @m.

  See also: graphene_simd4x4f_vec4_mul() *)

  external transform_vec3 : t -> Vec3_and__vec4.Vec3.t -> Vec3_and__vec4.Vec3.t
    = "ml_graphene_matrix_transform_vec3"
  (** Transforms the given #graphene_vec3_t using the matrix @m.

  This function will multiply the X, Y, and Z row vectors of the matrix @m
  with the corresponding components of the vector @v. The W row vector will
  be ignored.

  See also: graphene_simd4x4f_vec3_mul() *)

  external transform_sphere :
    t -> Box_and__sphere.Sphere.t -> Box_and__sphere.Sphere.t
    = "ml_graphene_matrix_transform_sphere"
  (** Transforms a #graphene_sphere_t using the given matrix @m. The
  result is the bounding sphere containing the transformed sphere. *)

  external transform_rect : t -> Rect.t -> Quad.t
    = "ml_graphene_matrix_transform_rect"
  (** Transforms each corner of a #graphene_rect_t using the given matrix @m.

  The result is a coplanar quadrilateral.

  See also: graphene_matrix_transform_point() *)

  external transform_ray : t -> Ray.t -> Ray.t
    = "ml_graphene_matrix_transform_ray"
  (** Transform a #graphene_ray_t using the given matrix @m. *)

  external transform_point3d : t -> Point3_d.t -> Point3_d.t
    = "ml_graphene_matrix_transform_point3d"
  (** Transforms the given #graphene_point3d_t using the matrix @m.

  Unlike graphene_matrix_transform_vec3(), this function will take into
  account the fourth row vector of the #graphene_matrix_t when computing
  the dot product of each row vector of the matrix.

  See also: graphene_simd4x4f_point3_mul() *)

  external transform_point : t -> Point.t -> Point.t
    = "ml_graphene_matrix_transform_point"
  (** Transforms the given #graphene_point_t using the matrix @m.

  Unlike graphene_matrix_transform_vec3(), this function will take into
  account the fourth row vector of the #graphene_matrix_t when computing
  the dot product of each row vector of the matrix.

  See also: graphene_simd4x4f_point3_mul() *)

  external transform_box : t -> Box_and__sphere.Box.t -> Box_and__sphere.Box.t
    = "ml_graphene_matrix_transform_box"
  (** Transforms the vertices of a #graphene_box_t using the given matrix @m.

  The result is the axis aligned bounding box containing the transformed
  vertices. *)

  external transform_bounds : t -> Rect.t -> Rect.t
    = "ml_graphene_matrix_transform_bounds"
  (** Transforms each corner of a #graphene_rect_t using the given matrix @m.

  The result is the axis aligned bounding rectangle containing the coplanar
  quadrilateral.

  See also: graphene_matrix_transform_point() *)

  external to_float : t -> float array = "ml_graphene_matrix_to_float"
  (** Converts a #graphene_matrix_t to an array of floating point values. *)

  external to_2d : t -> bool * float * float * float * float * float * float
    = "ml_graphene_matrix_to_2d"
  (** Converts a #graphene_matrix_t to an affine transformation matrix, if the
      given matrix is compatible.

      The returned values have the following layout:

      |[<!-- language="plain" --> ⎛ xx  yx ⎞   ⎛  a   b  0 ⎞ ⎜ xy  yy ⎟ = ⎜  c  
        d  0 ⎟ ⎝ x0  y0 ⎠   ⎝ tx  ty  1 ⎠ ]|

      This function can be used to convert between a #graphene_matrix_t and an
      affine matrix type from other libraries. *)

  external skew_yz : t -> float -> unit = "ml_graphene_matrix_skew_yz"
  (** Adds a skew of @factor on the Y and Z axis to the given matrix. *)

  external skew_xz : t -> float -> unit = "ml_graphene_matrix_skew_xz"
  (** Adds a skew of @factor on the X and Z axis to the given matrix. *)

  external skew_xy : t -> float -> unit = "ml_graphene_matrix_skew_xy"
  (** Adds a skew of @factor on the X and Y axis to the given matrix. *)

  external scale : t -> float -> float -> float -> unit
    = "ml_graphene_matrix_scale"
  (** Adds a scaling transformation to @m, using the three
  given factors.

  This is the equivalent of calling graphene_matrix_init_scale() and then
  multiplying the matrix @m with the scale matrix. *)

  external rotate_z : t -> float -> unit = "ml_graphene_matrix_rotate_z"
  (** Adds a rotation transformation around the Z axis to @m, using
  the given @angle.

  See also: graphene_matrix_rotate() *)

  external rotate_y : t -> float -> unit = "ml_graphene_matrix_rotate_y"
  (** Adds a rotation transformation around the Y axis to @m, using
  the given @angle.

  See also: graphene_matrix_rotate() *)

  external rotate_x : t -> float -> unit = "ml_graphene_matrix_rotate_x"
  (** Adds a rotation transformation around the X axis to @m, using
  the given @angle.

  See also: graphene_matrix_rotate() *)

  external rotate_quaternion : t -> Quaternion.t -> unit
    = "ml_graphene_matrix_rotate_quaternion"
  (** Adds a rotation transformation to @m, using the given
  #graphene_quaternion_t.

  This is the equivalent of calling graphene_quaternion_to_matrix() and
  then multiplying @m with the rotation matrix. *)

  external rotate_euler : t -> Euler.t -> unit
    = "ml_graphene_matrix_rotate_euler"
  (** Adds a rotation transformation to @m, using the given
  #graphene_euler_t. *)

  external rotate : t -> float -> Vec3_and__vec4.Vec3.t -> unit
    = "ml_graphene_matrix_rotate"
  (** Adds a rotation transformation to @m, using the given @angle
  and @axis vector.

  This is the equivalent of calling graphene_matrix_init_rotate() and
  then multiplying the matrix @m with the rotation matrix. *)

  external project_rect_bounds : t -> Rect.t -> Rect.t
    = "ml_graphene_matrix_project_rect_bounds"
  (** Projects a #graphene_rect_t using the given matrix.

      The resulting rectangle is the axis aligned bounding rectangle capable of
      fully containing the projected rectangle. *)

  external project_rect : t -> Rect.t -> Quad.t
    = "ml_graphene_matrix_project_rect"
  (** Projects all corners of a #graphene_rect_t using the given matrix.

      See also: graphene_matrix_project_point() *)

  external project_point : t -> Point.t -> Point.t
    = "ml_graphene_matrix_project_point"
  (** Projects a #graphene_point_t using the matrix @m. *)

  external print : t -> unit = "ml_graphene_matrix_print"
  (** Prints the contents of a matrix to the standard error stream.

      This function is only useful for debugging; there are no guarantees made
      on the format of the output. *)

  external perspective : t -> float -> t = "ml_graphene_matrix_perspective"
  (** Applies a perspective of @depth to the matrix. *)

  external normalize : t -> t = "ml_graphene_matrix_normalize"
  (** Normalizes the given #graphene_matrix_t. *)

  external near : t -> t -> float -> bool = "ml_graphene_matrix_near"
  (** Compares the two given #graphene_matrix_t matrices and checks
  whether their values are within the given @epsilon of each
  other. *)

  external multiply : t -> t -> t = "ml_graphene_matrix_multiply"
  (** Multiplies two #graphene_matrix_t.

  Matrix multiplication is not commutative in general; the order of the factors matters.
  The product of this multiplication is (@a × @b) *)

  external is_singular : t -> bool = "ml_graphene_matrix_is_singular"
  (** Checks whether a matrix is singular. *)

  external is_identity : t -> bool = "ml_graphene_matrix_is_identity"
  (** Checks whether the given #graphene_matrix_t is the identity matrix. *)

  external is_backface_visible : t -> bool
    = "ml_graphene_matrix_is_backface_visible"
  (** Checks whether a #graphene_matrix_t has a visible back face. *)

  external is_2d : t -> bool = "ml_graphene_matrix_is_2d"
  (** Checks whether the given #graphene_matrix_t is compatible with an a 2D
      affine transformation matrix. *)

  external inverse : t -> bool * t = "ml_graphene_matrix_inverse"
  (** Inverts the given matrix. *)

  external interpolate : t -> t -> float -> t = "ml_graphene_matrix_interpolate"
  (** Linearly interpolates the two given #graphene_matrix_t by interpolating
      the decomposed transformations separately.

      If either matrix cannot be reduced to their transformations then the
      interpolation cannot be performed, and this function will return an
      identity matrix. *)

  external init_translate : t -> Point3_d.t -> t
    = "ml_graphene_matrix_init_translate"
  (** Initializes a #graphene_matrix_t with a translation to the given
      coordinates. *)

  external init_skew : t -> float -> float -> t = "ml_graphene_matrix_init_skew"
  (** Initializes a #graphene_matrix_t with a skew transformation with the given
      factors. *)

  external init_scale : t -> float -> float -> float -> t
    = "ml_graphene_matrix_init_scale"
  (** Initializes a #graphene_matrix_t with the given scaling factors. *)

  external init_rotate : t -> float -> Vec3_and__vec4.Vec3.t -> t
    = "ml_graphene_matrix_init_rotate"
  (** Initializes @m to represent a rotation of @angle degrees on
  the axis represented by the @axis vector. *)

  external init_perspective : t -> float -> float -> float -> float -> t
    = "ml_graphene_matrix_init_perspective"
  (** Initializes a #graphene_matrix_t with a perspective projection. *)

  external init_ortho :
    t -> float -> float -> float -> float -> float -> float -> t
    = "ml_graphene_matrix_init_ortho_bytecode"
      "ml_graphene_matrix_init_ortho_native"
  (** Initializes a #graphene_matrix_t with an orthographic projection. *)

  external init_look_at :
    t ->
    Vec3_and__vec4.Vec3.t ->
    Vec3_and__vec4.Vec3.t ->
    Vec3_and__vec4.Vec3.t ->
    t = "ml_graphene_matrix_init_look_at"
  (** Initializes a #graphene_matrix_t so that it positions the "camera"
  at the given @eye coordinates towards an object at the @center
  coordinates. The top of the camera is aligned to the direction
  of the @up vector.

  Before the transform, the camera is assumed to be placed at the
  origin, looking towards the negative Z axis, with the top side of
  the camera facing in the direction of the Y axis and the right
  side in the direction of the X axis.

  In theory, one could use @m to transform a model of such a camera
  into world-space. However, it is more common to use the inverse of
  @m to transform another object from world coordinates to the view
  coordinates of the camera. Typically you would then apply the
  camera projection transform to get from view to screen
  coordinates. *)

  external init_identity : t -> t = "ml_graphene_matrix_init_identity"
  (** Initializes a #graphene_matrix_t with the identity matrix. *)

  external init_frustum :
    t -> float -> float -> float -> float -> float -> float -> t
    = "ml_graphene_matrix_init_frustum_bytecode"
      "ml_graphene_matrix_init_frustum_native"
  (** Initializes a #graphene_matrix_t compatible with #graphene_frustum_t.

      See also: graphene_frustum_init_from_matrix() *)

  external init_from_vec4 :
    t ->
    Vec3_and__vec4.Vec4.t ->
    Vec3_and__vec4.Vec4.t ->
    Vec3_and__vec4.Vec4.t ->
    Vec3_and__vec4.Vec4.t ->
    t = "ml_graphene_matrix_init_from_vec4"
  (** Initializes a #graphene_matrix_t with the given four row vectors. *)

  external init_from_matrix : t -> t -> t
    = "ml_graphene_matrix_init_from_matrix"
  (** Initializes a #graphene_matrix_t using the values of the given matrix. *)

  external init_from_float : t -> float array -> t
    = "ml_graphene_matrix_init_from_float"
  (** Initializes a #graphene_matrix_t with the given array of floating point
      values. *)

  external init_from_2d :
    t -> float -> float -> float -> float -> float -> float -> t
    = "ml_graphene_matrix_init_from_2d_bytecode"
      "ml_graphene_matrix_init_from_2d_native"
  (** Initializes a #graphene_matrix_t from the values of an affine
      transformation matrix.

      The arguments map to the following matrix layout:

      |[<!-- language="plain" --> ⎛ xx  yx ⎞   ⎛  a   b  0 ⎞ ⎜ xy  yy ⎟ = ⎜  c  
        d  0 ⎟ ⎝ x0  y0 ⎠   ⎝ tx  ty  1 ⎠ ]|

      This function can be used to convert between an affine matrix type from
      other libraries and a #graphene_matrix_t. *)

  external get_z_translation : t -> float
    = "ml_graphene_matrix_get_z_translation"
  (** Retrieves the translation component on the Z axis from @m. *)

  external get_z_scale : t -> float = "ml_graphene_matrix_get_z_scale"
  (** Retrieves the scaling factor on the Z axis in @m. *)

  external get_y_translation : t -> float
    = "ml_graphene_matrix_get_y_translation"
  (** Retrieves the translation component on the Y axis from @m. *)

  external get_y_scale : t -> float = "ml_graphene_matrix_get_y_scale"
  (** Retrieves the scaling factor on the Y axis in @m. *)

  external get_x_translation : t -> float
    = "ml_graphene_matrix_get_x_translation"
  (** Retrieves the translation component on the X axis from @m. *)

  external get_x_scale : t -> float = "ml_graphene_matrix_get_x_scale"
  (** Retrieves the scaling factor on the X axis in @m. *)

  external get_value : t -> int -> int -> float = "ml_graphene_matrix_get_value"
  (** Retrieves the value at the given @row and @col index. *)

  external get_row : t -> int -> Vec3_and__vec4.Vec4.t
    = "ml_graphene_matrix_get_row"
  (** Retrieves the given row vector at @index_ inside a matrix. *)

  external equal_fast : t -> t -> bool = "ml_graphene_matrix_equal_fast"
  (** Checks whether the two given #graphene_matrix_t matrices are byte-by-byte
      equal.

      While this function is faster than graphene_matrix_equal(), it can also
      return false negatives, so it should be used in conjuction with either
      graphene_matrix_equal() or graphene_matrix_near(). For instance:

      |[<!-- language="C" --> if (graphene_matrix_equal_fast (a, b)) { //
        matrices are definitely the same } else { if (graphene_matrix_equal (a,
        b)) // matrices contain the same values within an epsilon of FLT_EPSILON
        else if (graphene_matrix_near (a, b, 0.0001)) // matrices contain the
        same values within an epsilon of 0.0001 else // matrices are not equal }
        ]| *)

  external equal : t -> t -> bool = "ml_graphene_matrix_equal"
  (** Checks whether the two given #graphene_matrix_t matrices are equal. *)

  external determinant : t -> float = "ml_graphene_matrix_determinant"
  (** Computes the determinant of the given matrix. *)

  external decompose :
    t ->
    bool
    * Vec3_and__vec4.Vec3.t
    * Vec3_and__vec4.Vec3.t
    * Quaternion.t
    * Vec3_and__vec4.Vec3.t
    * Vec3_and__vec4.Vec4.t = "ml_graphene_matrix_decompose"
  (** Decomposes a transformation matrix into its component transformations.

      The algorithm for decomposing a matrix is taken from the
      [CSS3 Transforms specification](http://dev.w3.org/csswg/css-transforms/);
      specifically, the decomposition code is based on the equivalent code
      published in "Graphics Gems II", edited by Jim Arvo, and
      [available online](http://web.archive.org/web/20150512160205/http://tog.acm.org/resources/GraphicsGems/gemsii/unmatrix.c).
  *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_matrix_get_type"
end = struct
  type t = [ `matrix ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_matrix_alloc"
  (** Create a new Matrix *)

  (* Methods *)

  external untransform_point : t -> Point.t -> Rect.t -> bool * Point.t
    = "ml_graphene_matrix_untransform_point"
  (** Undoes the transformation of a #graphene_point_t using the
  given matrix, within the given axis aligned rectangular @bounds. *)

  external untransform_bounds : t -> Rect.t -> Rect.t -> Rect.t
    = "ml_graphene_matrix_untransform_bounds"
  (** Undoes the transformation on the corners of a #graphene_rect_t using the
  given matrix, within the given axis aligned rectangular @bounds. *)

  external unproject_point3d : t -> t -> Point3_d.t -> Point3_d.t
    = "ml_graphene_matrix_unproject_point3d"
  (** Unprojects the given @point using the @projection matrix and
  a @modelview matrix. *)

  external transpose : t -> t = "ml_graphene_matrix_transpose"
  (** Transposes the given matrix. *)

  external translate : t -> Point3_d.t -> unit = "ml_graphene_matrix_translate"
  (** Adds a translation transformation to @m using the coordinates
  of the given #graphene_point3d_t.

  This is the equivalent of calling graphene_matrix_init_translate() and
  then multiplying @m with the translation matrix. *)

  external transform_vec4 : t -> Vec3_and__vec4.Vec4.t -> Vec3_and__vec4.Vec4.t
    = "ml_graphene_matrix_transform_vec4"
  (** Transforms the given #graphene_vec4_t using the matrix @m.

  See also: graphene_simd4x4f_vec4_mul() *)

  external transform_vec3 : t -> Vec3_and__vec4.Vec3.t -> Vec3_and__vec4.Vec3.t
    = "ml_graphene_matrix_transform_vec3"
  (** Transforms the given #graphene_vec3_t using the matrix @m.

  This function will multiply the X, Y, and Z row vectors of the matrix @m
  with the corresponding components of the vector @v. The W row vector will
  be ignored.

  See also: graphene_simd4x4f_vec3_mul() *)

  external transform_sphere :
    t -> Box_and__sphere.Sphere.t -> Box_and__sphere.Sphere.t
    = "ml_graphene_matrix_transform_sphere"
  (** Transforms a #graphene_sphere_t using the given matrix @m. The
  result is the bounding sphere containing the transformed sphere. *)

  external transform_rect : t -> Rect.t -> Quad.t
    = "ml_graphene_matrix_transform_rect"
  (** Transforms each corner of a #graphene_rect_t using the given matrix @m.

  The result is a coplanar quadrilateral.

  See also: graphene_matrix_transform_point() *)

  external transform_ray : t -> Ray.t -> Ray.t
    = "ml_graphene_matrix_transform_ray"
  (** Transform a #graphene_ray_t using the given matrix @m. *)

  external transform_point3d : t -> Point3_d.t -> Point3_d.t
    = "ml_graphene_matrix_transform_point3d"
  (** Transforms the given #graphene_point3d_t using the matrix @m.

  Unlike graphene_matrix_transform_vec3(), this function will take into
  account the fourth row vector of the #graphene_matrix_t when computing
  the dot product of each row vector of the matrix.

  See also: graphene_simd4x4f_point3_mul() *)

  external transform_point : t -> Point.t -> Point.t
    = "ml_graphene_matrix_transform_point"
  (** Transforms the given #graphene_point_t using the matrix @m.

  Unlike graphene_matrix_transform_vec3(), this function will take into
  account the fourth row vector of the #graphene_matrix_t when computing
  the dot product of each row vector of the matrix.

  See also: graphene_simd4x4f_point3_mul() *)

  external transform_box : t -> Box_and__sphere.Box.t -> Box_and__sphere.Box.t
    = "ml_graphene_matrix_transform_box"
  (** Transforms the vertices of a #graphene_box_t using the given matrix @m.

  The result is the axis aligned bounding box containing the transformed
  vertices. *)

  external transform_bounds : t -> Rect.t -> Rect.t
    = "ml_graphene_matrix_transform_bounds"
  (** Transforms each corner of a #graphene_rect_t using the given matrix @m.

  The result is the axis aligned bounding rectangle containing the coplanar
  quadrilateral.

  See also: graphene_matrix_transform_point() *)

  external to_float : t -> float array = "ml_graphene_matrix_to_float"
  (** Converts a #graphene_matrix_t to an array of floating point values. *)

  external to_2d : t -> bool * float * float * float * float * float * float
    = "ml_graphene_matrix_to_2d"
  (** Converts a #graphene_matrix_t to an affine transformation matrix, if the
      given matrix is compatible.

      The returned values have the following layout:

      |[<!-- language="plain" --> ⎛ xx  yx ⎞   ⎛  a   b  0 ⎞ ⎜ xy  yy ⎟ = ⎜  c  
        d  0 ⎟ ⎝ x0  y0 ⎠   ⎝ tx  ty  1 ⎠ ]|

      This function can be used to convert between a #graphene_matrix_t and an
      affine matrix type from other libraries. *)

  external skew_yz : t -> float -> unit = "ml_graphene_matrix_skew_yz"
  (** Adds a skew of @factor on the Y and Z axis to the given matrix. *)

  external skew_xz : t -> float -> unit = "ml_graphene_matrix_skew_xz"
  (** Adds a skew of @factor on the X and Z axis to the given matrix. *)

  external skew_xy : t -> float -> unit = "ml_graphene_matrix_skew_xy"
  (** Adds a skew of @factor on the X and Y axis to the given matrix. *)

  external scale : t -> float -> float -> float -> unit
    = "ml_graphene_matrix_scale"
  (** Adds a scaling transformation to @m, using the three
  given factors.

  This is the equivalent of calling graphene_matrix_init_scale() and then
  multiplying the matrix @m with the scale matrix. *)

  external rotate_z : t -> float -> unit = "ml_graphene_matrix_rotate_z"
  (** Adds a rotation transformation around the Z axis to @m, using
  the given @angle.

  See also: graphene_matrix_rotate() *)

  external rotate_y : t -> float -> unit = "ml_graphene_matrix_rotate_y"
  (** Adds a rotation transformation around the Y axis to @m, using
  the given @angle.

  See also: graphene_matrix_rotate() *)

  external rotate_x : t -> float -> unit = "ml_graphene_matrix_rotate_x"
  (** Adds a rotation transformation around the X axis to @m, using
  the given @angle.

  See also: graphene_matrix_rotate() *)

  external rotate_quaternion : t -> Quaternion.t -> unit
    = "ml_graphene_matrix_rotate_quaternion"
  (** Adds a rotation transformation to @m, using the given
  #graphene_quaternion_t.

  This is the equivalent of calling graphene_quaternion_to_matrix() and
  then multiplying @m with the rotation matrix. *)

  external rotate_euler : t -> Euler.t -> unit
    = "ml_graphene_matrix_rotate_euler"
  (** Adds a rotation transformation to @m, using the given
  #graphene_euler_t. *)

  external rotate : t -> float -> Vec3_and__vec4.Vec3.t -> unit
    = "ml_graphene_matrix_rotate"
  (** Adds a rotation transformation to @m, using the given @angle
  and @axis vector.

  This is the equivalent of calling graphene_matrix_init_rotate() and
  then multiplying the matrix @m with the rotation matrix. *)

  external project_rect_bounds : t -> Rect.t -> Rect.t
    = "ml_graphene_matrix_project_rect_bounds"
  (** Projects a #graphene_rect_t using the given matrix.

      The resulting rectangle is the axis aligned bounding rectangle capable of
      fully containing the projected rectangle. *)

  external project_rect : t -> Rect.t -> Quad.t
    = "ml_graphene_matrix_project_rect"
  (** Projects all corners of a #graphene_rect_t using the given matrix.

      See also: graphene_matrix_project_point() *)

  external project_point : t -> Point.t -> Point.t
    = "ml_graphene_matrix_project_point"
  (** Projects a #graphene_point_t using the matrix @m. *)

  external print : t -> unit = "ml_graphene_matrix_print"
  (** Prints the contents of a matrix to the standard error stream.

      This function is only useful for debugging; there are no guarantees made
      on the format of the output. *)

  external perspective : t -> float -> t = "ml_graphene_matrix_perspective"
  (** Applies a perspective of @depth to the matrix. *)

  external normalize : t -> t = "ml_graphene_matrix_normalize"
  (** Normalizes the given #graphene_matrix_t. *)

  external near : t -> t -> float -> bool = "ml_graphene_matrix_near"
  (** Compares the two given #graphene_matrix_t matrices and checks
  whether their values are within the given @epsilon of each
  other. *)

  external multiply : t -> t -> t = "ml_graphene_matrix_multiply"
  (** Multiplies two #graphene_matrix_t.

  Matrix multiplication is not commutative in general; the order of the factors matters.
  The product of this multiplication is (@a × @b) *)

  external is_singular : t -> bool = "ml_graphene_matrix_is_singular"
  (** Checks whether a matrix is singular. *)

  external is_identity : t -> bool = "ml_graphene_matrix_is_identity"
  (** Checks whether the given #graphene_matrix_t is the identity matrix. *)

  external is_backface_visible : t -> bool
    = "ml_graphene_matrix_is_backface_visible"
  (** Checks whether a #graphene_matrix_t has a visible back face. *)

  external is_2d : t -> bool = "ml_graphene_matrix_is_2d"
  (** Checks whether the given #graphene_matrix_t is compatible with an a 2D
      affine transformation matrix. *)

  external inverse : t -> bool * t = "ml_graphene_matrix_inverse"
  (** Inverts the given matrix. *)

  external interpolate : t -> t -> float -> t = "ml_graphene_matrix_interpolate"
  (** Linearly interpolates the two given #graphene_matrix_t by interpolating
      the decomposed transformations separately.

      If either matrix cannot be reduced to their transformations then the
      interpolation cannot be performed, and this function will return an
      identity matrix. *)

  external init_translate : t -> Point3_d.t -> t
    = "ml_graphene_matrix_init_translate"
  (** Initializes a #graphene_matrix_t with a translation to the given
      coordinates. *)

  external init_skew : t -> float -> float -> t = "ml_graphene_matrix_init_skew"
  (** Initializes a #graphene_matrix_t with a skew transformation with the given
      factors. *)

  external init_scale : t -> float -> float -> float -> t
    = "ml_graphene_matrix_init_scale"
  (** Initializes a #graphene_matrix_t with the given scaling factors. *)

  external init_rotate : t -> float -> Vec3_and__vec4.Vec3.t -> t
    = "ml_graphene_matrix_init_rotate"
  (** Initializes @m to represent a rotation of @angle degrees on
  the axis represented by the @axis vector. *)

  external init_perspective : t -> float -> float -> float -> float -> t
    = "ml_graphene_matrix_init_perspective"
  (** Initializes a #graphene_matrix_t with a perspective projection. *)

  external init_ortho :
    t -> float -> float -> float -> float -> float -> float -> t
    = "ml_graphene_matrix_init_ortho_bytecode"
      "ml_graphene_matrix_init_ortho_native"
  (** Initializes a #graphene_matrix_t with an orthographic projection. *)

  external init_look_at :
    t ->
    Vec3_and__vec4.Vec3.t ->
    Vec3_and__vec4.Vec3.t ->
    Vec3_and__vec4.Vec3.t ->
    t = "ml_graphene_matrix_init_look_at"
  (** Initializes a #graphene_matrix_t so that it positions the "camera"
  at the given @eye coordinates towards an object at the @center
  coordinates. The top of the camera is aligned to the direction
  of the @up vector.

  Before the transform, the camera is assumed to be placed at the
  origin, looking towards the negative Z axis, with the top side of
  the camera facing in the direction of the Y axis and the right
  side in the direction of the X axis.

  In theory, one could use @m to transform a model of such a camera
  into world-space. However, it is more common to use the inverse of
  @m to transform another object from world coordinates to the view
  coordinates of the camera. Typically you would then apply the
  camera projection transform to get from view to screen
  coordinates. *)

  external init_identity : t -> t = "ml_graphene_matrix_init_identity"
  (** Initializes a #graphene_matrix_t with the identity matrix. *)

  external init_frustum :
    t -> float -> float -> float -> float -> float -> float -> t
    = "ml_graphene_matrix_init_frustum_bytecode"
      "ml_graphene_matrix_init_frustum_native"
  (** Initializes a #graphene_matrix_t compatible with #graphene_frustum_t.

      See also: graphene_frustum_init_from_matrix() *)

  external init_from_vec4 :
    t ->
    Vec3_and__vec4.Vec4.t ->
    Vec3_and__vec4.Vec4.t ->
    Vec3_and__vec4.Vec4.t ->
    Vec3_and__vec4.Vec4.t ->
    t = "ml_graphene_matrix_init_from_vec4"
  (** Initializes a #graphene_matrix_t with the given four row vectors. *)

  external init_from_matrix : t -> t -> t
    = "ml_graphene_matrix_init_from_matrix"
  (** Initializes a #graphene_matrix_t using the values of the given matrix. *)

  external init_from_float : t -> float array -> t
    = "ml_graphene_matrix_init_from_float"
  (** Initializes a #graphene_matrix_t with the given array of floating point
      values. *)

  external init_from_2d :
    t -> float -> float -> float -> float -> float -> float -> t
    = "ml_graphene_matrix_init_from_2d_bytecode"
      "ml_graphene_matrix_init_from_2d_native"
  (** Initializes a #graphene_matrix_t from the values of an affine
      transformation matrix.

      The arguments map to the following matrix layout:

      |[<!-- language="plain" --> ⎛ xx  yx ⎞   ⎛  a   b  0 ⎞ ⎜ xy  yy ⎟ = ⎜  c  
        d  0 ⎟ ⎝ x0  y0 ⎠   ⎝ tx  ty  1 ⎠ ]|

      This function can be used to convert between an affine matrix type from
      other libraries and a #graphene_matrix_t. *)

  external get_z_translation : t -> float
    = "ml_graphene_matrix_get_z_translation"
  (** Retrieves the translation component on the Z axis from @m. *)

  external get_z_scale : t -> float = "ml_graphene_matrix_get_z_scale"
  (** Retrieves the scaling factor on the Z axis in @m. *)

  external get_y_translation : t -> float
    = "ml_graphene_matrix_get_y_translation"
  (** Retrieves the translation component on the Y axis from @m. *)

  external get_y_scale : t -> float = "ml_graphene_matrix_get_y_scale"
  (** Retrieves the scaling factor on the Y axis in @m. *)

  external get_x_translation : t -> float
    = "ml_graphene_matrix_get_x_translation"
  (** Retrieves the translation component on the X axis from @m. *)

  external get_x_scale : t -> float = "ml_graphene_matrix_get_x_scale"
  (** Retrieves the scaling factor on the X axis in @m. *)

  external get_value : t -> int -> int -> float = "ml_graphene_matrix_get_value"
  (** Retrieves the value at the given @row and @col index. *)

  external get_row : t -> int -> Vec3_and__vec4.Vec4.t
    = "ml_graphene_matrix_get_row"
  (** Retrieves the given row vector at @index_ inside a matrix. *)

  external equal_fast : t -> t -> bool = "ml_graphene_matrix_equal_fast"
  (** Checks whether the two given #graphene_matrix_t matrices are byte-by-byte
      equal.

      While this function is faster than graphene_matrix_equal(), it can also
      return false negatives, so it should be used in conjuction with either
      graphene_matrix_equal() or graphene_matrix_near(). For instance:

      |[<!-- language="C" --> if (graphene_matrix_equal_fast (a, b)) { //
        matrices are definitely the same } else { if (graphene_matrix_equal (a,
        b)) // matrices contain the same values within an epsilon of FLT_EPSILON
        else if (graphene_matrix_near (a, b, 0.0001)) // matrices contain the
        same values within an epsilon of 0.0001 else // matrices are not equal }
        ]| *)

  external equal : t -> t -> bool = "ml_graphene_matrix_equal"
  (** Checks whether the two given #graphene_matrix_t matrices are equal. *)

  external determinant : t -> float = "ml_graphene_matrix_determinant"
  (** Computes the determinant of the given matrix. *)

  external decompose :
    t ->
    bool
    * Vec3_and__vec4.Vec3.t
    * Vec3_and__vec4.Vec3.t
    * Quaternion.t
    * Vec3_and__vec4.Vec3.t
    * Vec3_and__vec4.Vec4.t = "ml_graphene_matrix_decompose"
  (** Decomposes a transformation matrix into its component transformations.

      The algorithm for decomposing a matrix is taken from the
      [CSS3 Transforms specification](http://dev.w3.org/csswg/css-transforms/);
      specifically, the decomposition code is based on the equivalent code
      published in "Graphics Gems II", edited by Jim Arvo, and
      [available online](http://web.archive.org/web/20150512160205/http://tog.acm.org/resources/GraphicsGems/gemsii/unmatrix.c).
  *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_matrix_get_type"
end

and Plane : sig
  type t = [ `plane ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_plane_alloc"
  (** Create a new Plane *)

  (* Methods *)

  external transform : t -> Matrix.t -> Matrix.t option -> t
    = "ml_graphene_plane_transform"
  (** Transforms a #graphene_plane_t @p using the given @matrix
  and @normal_matrix.

  If @normal_matrix is %NULL, a transformation matrix for the plane
  normal will be computed from @matrix. If you are transforming
  multiple planes using the same @matrix it's recommended to compute
  the normal matrix beforehand to avoid incurring in the cost of
  recomputing it every time. *)

  external normalize : t -> t = "ml_graphene_plane_normalize"
  (** Normalizes the vector of the given #graphene_plane_t, and adjusts the
      constant accordingly. *)

  external negate : t -> t = "ml_graphene_plane_negate"
  (** Negates the normal vector and constant of a #graphene_plane_t, effectively
      mirroring the plane across the origin. *)

  external init_from_vec4 : t -> Vec3_and__vec4.Vec4.t -> t
    = "ml_graphene_plane_init_from_vec4"
  (** Initializes the given #graphene_plane_t using the components of the given
      #graphene_vec4_t vector. *)

  external init_from_points : t -> Point3_d.t -> Point3_d.t -> Point3_d.t -> t
    = "ml_graphene_plane_init_from_points"
  (** Initializes the given #graphene_plane_t using the 3 provided co-planar
      points.

      The winding order is counter-clockwise, and determines which direction the
      normal vector will point. *)

  external init_from_point : t -> Vec3_and__vec4.Vec3.t -> Point3_d.t -> t
    = "ml_graphene_plane_init_from_point"
  (** Initializes the given #graphene_plane_t using the given normal vector and
      an arbitrary co-planar point. *)

  external init_from_plane : t -> t -> t = "ml_graphene_plane_init_from_plane"
  (** Initializes the given #graphene_plane_t using the normal vector and
      constant of another #graphene_plane_t. *)

  external init : t -> Vec3_and__vec4.Vec3.t option -> float -> t
    = "ml_graphene_plane_init"
  (** Initializes the given #graphene_plane_t using the given @normal vector
  and @constant values. *)

  external get_normal : t -> Vec3_and__vec4.Vec3.t
    = "ml_graphene_plane_get_normal"
  (** Retrieves the normal vector pointing towards the origin of the given
      #graphene_plane_t. *)

  external get_constant : t -> float = "ml_graphene_plane_get_constant"
  (** Retrieves the distance along the normal vector of the given
      #graphene_plane_t from the origin. *)

  external equal : t -> t -> bool = "ml_graphene_plane_equal"
  (** Checks whether the two given #graphene_plane_t are equal. *)

  external distance : t -> Point3_d.t -> float = "ml_graphene_plane_distance"
  (** Computes the distance of @point from a #graphene_plane_t. *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_plane_get_type"
end = struct
  type t = [ `plane ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_plane_alloc"
  (** Create a new Plane *)

  (* Methods *)

  external transform : t -> Matrix.t -> Matrix.t option -> t
    = "ml_graphene_plane_transform"
  (** Transforms a #graphene_plane_t @p using the given @matrix
  and @normal_matrix.

  If @normal_matrix is %NULL, a transformation matrix for the plane
  normal will be computed from @matrix. If you are transforming
  multiple planes using the same @matrix it's recommended to compute
  the normal matrix beforehand to avoid incurring in the cost of
  recomputing it every time. *)

  external normalize : t -> t = "ml_graphene_plane_normalize"
  (** Normalizes the vector of the given #graphene_plane_t, and adjusts the
      constant accordingly. *)

  external negate : t -> t = "ml_graphene_plane_negate"
  (** Negates the normal vector and constant of a #graphene_plane_t, effectively
      mirroring the plane across the origin. *)

  external init_from_vec4 : t -> Vec3_and__vec4.Vec4.t -> t
    = "ml_graphene_plane_init_from_vec4"
  (** Initializes the given #graphene_plane_t using the components of the given
      #graphene_vec4_t vector. *)

  external init_from_points : t -> Point3_d.t -> Point3_d.t -> Point3_d.t -> t
    = "ml_graphene_plane_init_from_points"
  (** Initializes the given #graphene_plane_t using the 3 provided co-planar
      points.

      The winding order is counter-clockwise, and determines which direction the
      normal vector will point. *)

  external init_from_point : t -> Vec3_and__vec4.Vec3.t -> Point3_d.t -> t
    = "ml_graphene_plane_init_from_point"
  (** Initializes the given #graphene_plane_t using the given normal vector and
      an arbitrary co-planar point. *)

  external init_from_plane : t -> t -> t = "ml_graphene_plane_init_from_plane"
  (** Initializes the given #graphene_plane_t using the normal vector and
      constant of another #graphene_plane_t. *)

  external init : t -> Vec3_and__vec4.Vec3.t option -> float -> t
    = "ml_graphene_plane_init"
  (** Initializes the given #graphene_plane_t using the given @normal vector
  and @constant values. *)

  external get_normal : t -> Vec3_and__vec4.Vec3.t
    = "ml_graphene_plane_get_normal"
  (** Retrieves the normal vector pointing towards the origin of the given
      #graphene_plane_t. *)

  external get_constant : t -> float = "ml_graphene_plane_get_constant"
  (** Retrieves the distance along the normal vector of the given
      #graphene_plane_t from the origin. *)

  external equal : t -> t -> bool = "ml_graphene_plane_equal"
  (** Checks whether the two given #graphene_plane_t are equal. *)

  external distance : t -> Point3_d.t -> float = "ml_graphene_plane_distance"
  (** Computes the distance of @point from a #graphene_plane_t. *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_plane_get_type"
end

and Quaternion : sig
  type t = [ `quaternion ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_quaternion_alloc"
  (** Create a new Quaternion *)

  (* Methods *)

  external to_vec4 : t -> Vec3_and__vec4.Vec4.t
    = "ml_graphene_quaternion_to_vec4"
  (** Copies the components of a #graphene_quaternion_t into a #graphene_vec4_t.
  *)

  external to_radians : t -> float * float * float
    = "ml_graphene_quaternion_to_radians"
  (** Converts a #graphene_quaternion_t to its corresponding rotations on the
      [Euler angles](http://en.wikipedia.org/wiki/Euler_angles) on each axis. *)

  external to_matrix : t -> Matrix.t = "ml_graphene_quaternion_to_matrix"
  (** Converts a quaternion into a transformation matrix expressing the rotation
      defined by the #graphene_quaternion_t. *)

  external to_angles : t -> float * float * float
    = "ml_graphene_quaternion_to_angles"
  (** Converts a #graphene_quaternion_t to its corresponding rotations on the
      [Euler angles](http://en.wikipedia.org/wiki/Euler_angles) on each axis. *)

  external to_angle_vec3 : t -> float * Vec3_and__vec4.Vec3.t
    = "ml_graphene_quaternion_to_angle_vec3"
  (** Converts a quaternion into an @angle, @axis pair. *)

  external slerp : t -> t -> float -> t = "ml_graphene_quaternion_slerp"
  (** Interpolates between the two given quaternions using a spherical
  linear interpolation, or [SLERP](http://en.wikipedia.org/wiki/Slerp),
  using the given interpolation @factor. *)

  external scale : t -> float -> t = "ml_graphene_quaternion_scale"
  (** Scales all the elements of a #graphene_quaternion_t @q using
  the given scalar factor. *)

  external normalize : t -> t = "ml_graphene_quaternion_normalize"
  (** Normalizes a #graphene_quaternion_t. *)

  external multiply : t -> t -> t = "ml_graphene_quaternion_multiply"
  (** Multiplies two #graphene_quaternion_t @a and @b. *)

  external invert : t -> t = "ml_graphene_quaternion_invert"
  (** Inverts a #graphene_quaternion_t, and returns the conjugate
  quaternion of @q. *)

  external init_identity : t -> t = "ml_graphene_quaternion_init_identity"
  (** Initializes a #graphene_quaternion_t using the identity transformation. *)

  external init_from_vec4 : t -> Vec3_and__vec4.Vec4.t -> t
    = "ml_graphene_quaternion_init_from_vec4"
  (** Initializes a #graphene_quaternion_t with the values from @src. *)

  external init_from_radians : t -> float -> float -> float -> t
    = "ml_graphene_quaternion_init_from_radians"
  (** Initializes a #graphene_quaternion_t using the values of the
      [Euler angles](http://en.wikipedia.org/wiki/Euler_angles) on each axis.

      See also: graphene_quaternion_init_from_euler() *)

  external init_from_quaternion : t -> t -> t
    = "ml_graphene_quaternion_init_from_quaternion"
  (** Initializes a #graphene_quaternion_t with the values from @src. *)

  external init_from_matrix : t -> Matrix.t -> t
    = "ml_graphene_quaternion_init_from_matrix"
  (** Initializes a #graphene_quaternion_t using the rotation components of a
      transformation matrix. *)

  external init_from_euler : t -> Euler.t -> t
    = "ml_graphene_quaternion_init_from_euler"
  (** Initializes a #graphene_quaternion_t using the given #graphene_euler_t. *)

  external init_from_angles : t -> float -> float -> float -> t
    = "ml_graphene_quaternion_init_from_angles"
  (** Initializes a #graphene_quaternion_t using the values of the
      [Euler angles](http://en.wikipedia.org/wiki/Euler_angles) on each axis.

      See also: graphene_quaternion_init_from_euler() *)

  external init_from_angle_vec3 : t -> float -> Vec3_and__vec4.Vec3.t -> t
    = "ml_graphene_quaternion_init_from_angle_vec3"
  (** Initializes a #graphene_quaternion_t using an @angle on a
  specific @axis. *)

  external init : t -> float -> float -> float -> float -> t
    = "ml_graphene_quaternion_init"
  (** Initializes a #graphene_quaternion_t using the given four values. *)

  external equal : t -> t -> bool = "ml_graphene_quaternion_equal"
  (** Checks whether the given quaternions are equal. *)

  external dot : t -> t -> float = "ml_graphene_quaternion_dot"
  (** Computes the dot product of two #graphene_quaternion_t. *)

  external add : t -> t -> t = "ml_graphene_quaternion_add"
  (** Adds two #graphene_quaternion_t @a and @b. *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_quaternion_get_type"
end = struct
  type t = [ `quaternion ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_quaternion_alloc"
  (** Create a new Quaternion *)

  (* Methods *)

  external to_vec4 : t -> Vec3_and__vec4.Vec4.t
    = "ml_graphene_quaternion_to_vec4"
  (** Copies the components of a #graphene_quaternion_t into a #graphene_vec4_t.
  *)

  external to_radians : t -> float * float * float
    = "ml_graphene_quaternion_to_radians"
  (** Converts a #graphene_quaternion_t to its corresponding rotations on the
      [Euler angles](http://en.wikipedia.org/wiki/Euler_angles) on each axis. *)

  external to_matrix : t -> Matrix.t = "ml_graphene_quaternion_to_matrix"
  (** Converts a quaternion into a transformation matrix expressing the rotation
      defined by the #graphene_quaternion_t. *)

  external to_angles : t -> float * float * float
    = "ml_graphene_quaternion_to_angles"
  (** Converts a #graphene_quaternion_t to its corresponding rotations on the
      [Euler angles](http://en.wikipedia.org/wiki/Euler_angles) on each axis. *)

  external to_angle_vec3 : t -> float * Vec3_and__vec4.Vec3.t
    = "ml_graphene_quaternion_to_angle_vec3"
  (** Converts a quaternion into an @angle, @axis pair. *)

  external slerp : t -> t -> float -> t = "ml_graphene_quaternion_slerp"
  (** Interpolates between the two given quaternions using a spherical
  linear interpolation, or [SLERP](http://en.wikipedia.org/wiki/Slerp),
  using the given interpolation @factor. *)

  external scale : t -> float -> t = "ml_graphene_quaternion_scale"
  (** Scales all the elements of a #graphene_quaternion_t @q using
  the given scalar factor. *)

  external normalize : t -> t = "ml_graphene_quaternion_normalize"
  (** Normalizes a #graphene_quaternion_t. *)

  external multiply : t -> t -> t = "ml_graphene_quaternion_multiply"
  (** Multiplies two #graphene_quaternion_t @a and @b. *)

  external invert : t -> t = "ml_graphene_quaternion_invert"
  (** Inverts a #graphene_quaternion_t, and returns the conjugate
  quaternion of @q. *)

  external init_identity : t -> t = "ml_graphene_quaternion_init_identity"
  (** Initializes a #graphene_quaternion_t using the identity transformation. *)

  external init_from_vec4 : t -> Vec3_and__vec4.Vec4.t -> t
    = "ml_graphene_quaternion_init_from_vec4"
  (** Initializes a #graphene_quaternion_t with the values from @src. *)

  external init_from_radians : t -> float -> float -> float -> t
    = "ml_graphene_quaternion_init_from_radians"
  (** Initializes a #graphene_quaternion_t using the values of the
      [Euler angles](http://en.wikipedia.org/wiki/Euler_angles) on each axis.

      See also: graphene_quaternion_init_from_euler() *)

  external init_from_quaternion : t -> t -> t
    = "ml_graphene_quaternion_init_from_quaternion"
  (** Initializes a #graphene_quaternion_t with the values from @src. *)

  external init_from_matrix : t -> Matrix.t -> t
    = "ml_graphene_quaternion_init_from_matrix"
  (** Initializes a #graphene_quaternion_t using the rotation components of a
      transformation matrix. *)

  external init_from_euler : t -> Euler.t -> t
    = "ml_graphene_quaternion_init_from_euler"
  (** Initializes a #graphene_quaternion_t using the given #graphene_euler_t. *)

  external init_from_angles : t -> float -> float -> float -> t
    = "ml_graphene_quaternion_init_from_angles"
  (** Initializes a #graphene_quaternion_t using the values of the
      [Euler angles](http://en.wikipedia.org/wiki/Euler_angles) on each axis.

      See also: graphene_quaternion_init_from_euler() *)

  external init_from_angle_vec3 : t -> float -> Vec3_and__vec4.Vec3.t -> t
    = "ml_graphene_quaternion_init_from_angle_vec3"
  (** Initializes a #graphene_quaternion_t using an @angle on a
  specific @axis. *)

  external init : t -> float -> float -> float -> float -> t
    = "ml_graphene_quaternion_init"
  (** Initializes a #graphene_quaternion_t using the given four values. *)

  external equal : t -> t -> bool = "ml_graphene_quaternion_equal"
  (** Checks whether the given quaternions are equal. *)

  external dot : t -> t -> float = "ml_graphene_quaternion_dot"
  (** Computes the dot product of two #graphene_quaternion_t. *)

  external add : t -> t -> t = "ml_graphene_quaternion_add"
  (** Adds two #graphene_quaternion_t @a and @b. *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_quaternion_get_type"
end

and Ray : sig
  type t = [ `ray ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_ray_alloc"
  (** Create a new Ray *)

  (* Methods *)

  external intersects_triangle : t -> Triangle.t -> bool
    = "ml_graphene_ray_intersects_triangle"
  (** Checks whether the given #graphene_ray_t @r intersects the
  given #graphene_triangle_t @b.

  See also: graphene_ray_intersect_triangle() *)

  external intersects_sphere : t -> Box_and__sphere.Sphere.t -> bool
    = "ml_graphene_ray_intersects_sphere"
  (** Checks if the given #graphene_ray_t @r intersects the
  given #graphene_sphere_t @s.

  See also: graphene_ray_intersect_sphere() *)

  external intersects_box : t -> Box_and__sphere.Box.t -> bool
    = "ml_graphene_ray_intersects_box"
  (** Checks whether the given #graphene_ray_t @r intersects the
  given #graphene_box_t @b.

  See also: graphene_ray_intersect_box() *)

  external intersect_triangle :
    t -> Triangle.t -> Graphene_enums.rayintersectionkind * float
    = "ml_graphene_ray_intersect_triangle"
  (** Intersects the given #graphene_ray_t @r with the given
  #graphene_triangle_t @t. *)

  external intersect_sphere :
    t -> Box_and__sphere.Sphere.t -> Graphene_enums.rayintersectionkind * float
    = "ml_graphene_ray_intersect_sphere"
  (** Intersects the given #graphene_ray_t @r with the given
  #graphene_sphere_t @s. *)

  external intersect_box :
    t -> Box_and__sphere.Box.t -> Graphene_enums.rayintersectionkind * float
    = "ml_graphene_ray_intersect_box"
  (** Intersects the given #graphene_ray_t @r with the given
  #graphene_box_t @b. *)

  external init_from_vec3 :
    t -> Vec3_and__vec4.Vec3.t option -> Vec3_and__vec4.Vec3.t option -> t
    = "ml_graphene_ray_init_from_vec3"
  (** Initializes the given #graphene_ray_t using the given vectors. *)

  external init_from_ray : t -> t -> t = "ml_graphene_ray_init_from_ray"
  (** Initializes the given #graphene_ray_t using the origin and direction
      values of another #graphene_ray_t. *)

  external init : t -> Point3_d.t option -> Vec3_and__vec4.Vec3.t option -> t
    = "ml_graphene_ray_init"
  (** Initializes the given #graphene_ray_t using the given @origin
  and @direction values. *)

  external get_position_at : t -> float -> Point3_d.t
    = "ml_graphene_ray_get_position_at"
  (** Retrieves the coordinates of a point at the distance @t along the
  given #graphene_ray_t. *)

  external get_origin : t -> Point3_d.t = "ml_graphene_ray_get_origin"
  (** Retrieves the origin of the given #graphene_ray_t. *)

  external get_distance_to_point : t -> Point3_d.t -> float
    = "ml_graphene_ray_get_distance_to_point"
  (** Computes the distance of the closest approach between the
  given #graphene_ray_t @r and the point @p.

  The closest approach to a ray from a point is the distance
  between the point and the projection of the point on the
  ray itself. *)

  external get_distance_to_plane : t -> Plane.t -> float
    = "ml_graphene_ray_get_distance_to_plane"
  (** Computes the distance of the origin of the given #graphene_ray_t from the
      given plane.

      If the ray does not intersect the plane, this function returns `INFINITY`.
  *)

  external get_direction : t -> Vec3_and__vec4.Vec3.t
    = "ml_graphene_ray_get_direction"
  (** Retrieves the direction of the given #graphene_ray_t. *)

  external get_closest_point_to_point : t -> Point3_d.t -> Point3_d.t
    = "ml_graphene_ray_get_closest_point_to_point"
  (** Computes the point on the given #graphene_ray_t that is closest to the
  given point @p. *)

  external equal : t -> t -> bool = "ml_graphene_ray_equal"
  (** Checks whether the two given #graphene_ray_t are equal. *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_ray_get_type"
end = struct
  type t = [ `ray ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_ray_alloc"
  (** Create a new Ray *)

  (* Methods *)

  external intersects_triangle : t -> Triangle.t -> bool
    = "ml_graphene_ray_intersects_triangle"
  (** Checks whether the given #graphene_ray_t @r intersects the
  given #graphene_triangle_t @b.

  See also: graphene_ray_intersect_triangle() *)

  external intersects_sphere : t -> Box_and__sphere.Sphere.t -> bool
    = "ml_graphene_ray_intersects_sphere"
  (** Checks if the given #graphene_ray_t @r intersects the
  given #graphene_sphere_t @s.

  See also: graphene_ray_intersect_sphere() *)

  external intersects_box : t -> Box_and__sphere.Box.t -> bool
    = "ml_graphene_ray_intersects_box"
  (** Checks whether the given #graphene_ray_t @r intersects the
  given #graphene_box_t @b.

  See also: graphene_ray_intersect_box() *)

  external intersect_triangle :
    t -> Triangle.t -> Graphene_enums.rayintersectionkind * float
    = "ml_graphene_ray_intersect_triangle"
  (** Intersects the given #graphene_ray_t @r with the given
  #graphene_triangle_t @t. *)

  external intersect_sphere :
    t -> Box_and__sphere.Sphere.t -> Graphene_enums.rayintersectionkind * float
    = "ml_graphene_ray_intersect_sphere"
  (** Intersects the given #graphene_ray_t @r with the given
  #graphene_sphere_t @s. *)

  external intersect_box :
    t -> Box_and__sphere.Box.t -> Graphene_enums.rayintersectionkind * float
    = "ml_graphene_ray_intersect_box"
  (** Intersects the given #graphene_ray_t @r with the given
  #graphene_box_t @b. *)

  external init_from_vec3 :
    t -> Vec3_and__vec4.Vec3.t option -> Vec3_and__vec4.Vec3.t option -> t
    = "ml_graphene_ray_init_from_vec3"
  (** Initializes the given #graphene_ray_t using the given vectors. *)

  external init_from_ray : t -> t -> t = "ml_graphene_ray_init_from_ray"
  (** Initializes the given #graphene_ray_t using the origin and direction
      values of another #graphene_ray_t. *)

  external init : t -> Point3_d.t option -> Vec3_and__vec4.Vec3.t option -> t
    = "ml_graphene_ray_init"
  (** Initializes the given #graphene_ray_t using the given @origin
  and @direction values. *)

  external get_position_at : t -> float -> Point3_d.t
    = "ml_graphene_ray_get_position_at"
  (** Retrieves the coordinates of a point at the distance @t along the
  given #graphene_ray_t. *)

  external get_origin : t -> Point3_d.t = "ml_graphene_ray_get_origin"
  (** Retrieves the origin of the given #graphene_ray_t. *)

  external get_distance_to_point : t -> Point3_d.t -> float
    = "ml_graphene_ray_get_distance_to_point"
  (** Computes the distance of the closest approach between the
  given #graphene_ray_t @r and the point @p.

  The closest approach to a ray from a point is the distance
  between the point and the projection of the point on the
  ray itself. *)

  external get_distance_to_plane : t -> Plane.t -> float
    = "ml_graphene_ray_get_distance_to_plane"
  (** Computes the distance of the origin of the given #graphene_ray_t from the
      given plane.

      If the ray does not intersect the plane, this function returns `INFINITY`.
  *)

  external get_direction : t -> Vec3_and__vec4.Vec3.t
    = "ml_graphene_ray_get_direction"
  (** Retrieves the direction of the given #graphene_ray_t. *)

  external get_closest_point_to_point : t -> Point3_d.t -> Point3_d.t
    = "ml_graphene_ray_get_closest_point_to_point"
  (** Computes the point on the given #graphene_ray_t that is closest to the
  given point @p. *)

  external equal : t -> t -> bool = "ml_graphene_ray_equal"
  (** Checks whether the two given #graphene_ray_t are equal. *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_ray_get_type"
end

and Triangle : sig
  type t = [ `triangle ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_triangle_alloc"
  (** Create a new Triangle *)

  (* Methods *)

  external init_from_vec3 :
    t ->
    Vec3_and__vec4.Vec3.t option ->
    Vec3_and__vec4.Vec3.t option ->
    Vec3_and__vec4.Vec3.t option ->
    t = "ml_graphene_triangle_init_from_vec3"
  (** Initializes a #graphene_triangle_t using the three given vectors. *)

  external init_from_point3d :
    t -> Point3_d.t option -> Point3_d.t option -> Point3_d.t option -> t
    = "ml_graphene_triangle_init_from_point3d"
  (** Initializes a #graphene_triangle_t using the three given 3D points. *)

  external init_from_float : t -> float array -> float array -> float array -> t
    = "ml_graphene_triangle_init_from_float"
  (** Initializes a #graphene_triangle_t using the three given arrays of
      floating point values, each representing the coordinates of a point in 3D
      space. *)

  external get_vertices :
    t -> Vec3_and__vec4.Vec3.t * Vec3_and__vec4.Vec3.t * Vec3_and__vec4.Vec3.t
    = "ml_graphene_triangle_get_vertices"
  (** Retrieves the three vertices of the given #graphene_triangle_t. *)

  external get_uv :
    t -> Point3_d.t option -> Vec2.t -> Vec2.t -> Vec2.t -> bool * Vec2.t
    = "ml_graphene_triangle_get_uv"
  (** Computes the UV coordinates of the given point @p.

  The point @p must lie on the same plane as the triangle @t; if the point
  is not coplanar, the result of this function is undefined. If @p is %NULL,
  the point will be set in (0, 0, 0).

  The UV coordinates will be placed in the @res vector:

   - `res.x = u`
   - `res.y = v`

  See also: graphene_triangle_get_barycoords() *)

  external get_points : t -> Point3_d.t * Point3_d.t * Point3_d.t
    = "ml_graphene_triangle_get_points"
  (** Retrieves the three vertices of the given #graphene_triangle_t and returns
      their coordinates as #graphene_point3d_t. *)

  external get_plane : t -> Plane.t = "ml_graphene_triangle_get_plane"
  (** Computes the plane based on the vertices of the given
      #graphene_triangle_t. *)

  external get_normal : t -> Vec3_and__vec4.Vec3.t
    = "ml_graphene_triangle_get_normal"
  (** Computes the normal vector of the given #graphene_triangle_t. *)

  external get_midpoint : t -> Point3_d.t = "ml_graphene_triangle_get_midpoint"
  (** Computes the coordinates of the midpoint of the given
      #graphene_triangle_t.

      The midpoint G is the
      [centroid](https://en.wikipedia.org/wiki/Centroid#Triangle_centroid) of
      the triangle, i.e. the intersection of its medians. *)

  external get_bounding_box : t -> Box_and__sphere.Box.t
    = "ml_graphene_triangle_get_bounding_box"
  (** Computes the bounding box of the given #graphene_triangle_t. *)

  external get_barycoords : t -> Point3_d.t option -> bool * Vec2.t
    = "ml_graphene_triangle_get_barycoords"
  (** Computes the [barycentric coordinates](http://en.wikipedia.org/wiki/Barycentric_coordinate_system)
  of the given point @p.

  The point @p must lie on the same plane as the triangle @t; if the
  point is not coplanar, the result of this function is undefined.

  If we place the origin in the coordinates of the triangle's A point,
  the barycentric coordinates are `u`, which is on the AC vector; and `v`
  which is on the AB vector:

  ![](triangle-barycentric.png)

  The returned #graphene_vec2_t contains the following values, in order:

   - `res.x = u`
   - `res.y = v` *)

  external get_area : t -> float = "ml_graphene_triangle_get_area"
  (** Computes the area of the given #graphene_triangle_t. *)

  external equal : t -> t -> bool = "ml_graphene_triangle_equal"
  (** Checks whether the two given #graphene_triangle_t are equal. *)

  external contains_point : t -> Point3_d.t -> bool
    = "ml_graphene_triangle_contains_point"
  (** Checks whether the given triangle @t contains the point @p. *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_triangle_get_type"
end = struct
  type t = [ `triangle ] Gobject.obj

  external alloc : unit -> t = "ml_graphene_triangle_alloc"
  (** Create a new Triangle *)

  (* Methods *)

  external init_from_vec3 :
    t ->
    Vec3_and__vec4.Vec3.t option ->
    Vec3_and__vec4.Vec3.t option ->
    Vec3_and__vec4.Vec3.t option ->
    t = "ml_graphene_triangle_init_from_vec3"
  (** Initializes a #graphene_triangle_t using the three given vectors. *)

  external init_from_point3d :
    t -> Point3_d.t option -> Point3_d.t option -> Point3_d.t option -> t
    = "ml_graphene_triangle_init_from_point3d"
  (** Initializes a #graphene_triangle_t using the three given 3D points. *)

  external init_from_float : t -> float array -> float array -> float array -> t
    = "ml_graphene_triangle_init_from_float"
  (** Initializes a #graphene_triangle_t using the three given arrays of
      floating point values, each representing the coordinates of a point in 3D
      space. *)

  external get_vertices :
    t -> Vec3_and__vec4.Vec3.t * Vec3_and__vec4.Vec3.t * Vec3_and__vec4.Vec3.t
    = "ml_graphene_triangle_get_vertices"
  (** Retrieves the three vertices of the given #graphene_triangle_t. *)

  external get_uv :
    t -> Point3_d.t option -> Vec2.t -> Vec2.t -> Vec2.t -> bool * Vec2.t
    = "ml_graphene_triangle_get_uv"
  (** Computes the UV coordinates of the given point @p.

  The point @p must lie on the same plane as the triangle @t; if the point
  is not coplanar, the result of this function is undefined. If @p is %NULL,
  the point will be set in (0, 0, 0).

  The UV coordinates will be placed in the @res vector:

   - `res.x = u`
   - `res.y = v`

  See also: graphene_triangle_get_barycoords() *)

  external get_points : t -> Point3_d.t * Point3_d.t * Point3_d.t
    = "ml_graphene_triangle_get_points"
  (** Retrieves the three vertices of the given #graphene_triangle_t and returns
      their coordinates as #graphene_point3d_t. *)

  external get_plane : t -> Plane.t = "ml_graphene_triangle_get_plane"
  (** Computes the plane based on the vertices of the given
      #graphene_triangle_t. *)

  external get_normal : t -> Vec3_and__vec4.Vec3.t
    = "ml_graphene_triangle_get_normal"
  (** Computes the normal vector of the given #graphene_triangle_t. *)

  external get_midpoint : t -> Point3_d.t = "ml_graphene_triangle_get_midpoint"
  (** Computes the coordinates of the midpoint of the given
      #graphene_triangle_t.

      The midpoint G is the
      [centroid](https://en.wikipedia.org/wiki/Centroid#Triangle_centroid) of
      the triangle, i.e. the intersection of its medians. *)

  external get_bounding_box : t -> Box_and__sphere.Box.t
    = "ml_graphene_triangle_get_bounding_box"
  (** Computes the bounding box of the given #graphene_triangle_t. *)

  external get_barycoords : t -> Point3_d.t option -> bool * Vec2.t
    = "ml_graphene_triangle_get_barycoords"
  (** Computes the [barycentric coordinates](http://en.wikipedia.org/wiki/Barycentric_coordinate_system)
  of the given point @p.

  The point @p must lie on the same plane as the triangle @t; if the
  point is not coplanar, the result of this function is undefined.

  If we place the origin in the coordinates of the triangle's A point,
  the barycentric coordinates are `u`, which is on the AC vector; and `v`
  which is on the AB vector:

  ![](triangle-barycentric.png)

  The returned #graphene_vec2_t contains the following values, in order:

   - `res.x = u`
   - `res.y = v` *)

  external get_area : t -> float = "ml_graphene_triangle_get_area"
  (** Computes the area of the given #graphene_triangle_t. *)

  external equal : t -> t -> bool = "ml_graphene_triangle_equal"
  (** Checks whether the two given #graphene_triangle_t are equal. *)

  external contains_point : t -> Point3_d.t -> bool
    = "ml_graphene_triangle_contains_point"
  (** Checks whether the given triangle @t contains the point @p. *)

  external get_type : unit -> Gobject.Type.t = "ml_graphene_triangle_get_type"
end
