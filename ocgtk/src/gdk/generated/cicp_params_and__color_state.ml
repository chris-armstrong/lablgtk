(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec Cicp_params : sig
  type t = [ `cicp_params | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gdk_cicp_params_get_type"

  external new_ : unit -> t = "ml_gdk_cicp_params_new"
  (** Create a new CicpParams *)

  (* Methods *)

  external set_transfer_function : t -> int -> unit
    = "ml_gdk_cicp_params_set_transfer_function"
  (** Sets the transfer-function property of @self. *)

  external set_range : t -> Gdk_enums.cicprange -> unit
    = "ml_gdk_cicp_params_set_range"
  (** Sets the range property of @self *)

  external set_matrix_coefficients : t -> int -> unit
    = "ml_gdk_cicp_params_set_matrix_coefficients"
  (** @self a `GdkCicpParams`
  Sets the matrix-coefficients property of @self. *)

  external set_color_primaries : t -> int -> unit
    = "ml_gdk_cicp_params_set_color_primaries"
  (** Sets the color-primaries property of @self. *)

  external get_transfer_function : t -> int
    = "ml_gdk_cicp_params_get_transfer_function"
  (** Gets the transfer-function property of @self. *)

  external get_range : t -> Gdk_enums.cicprange = "ml_gdk_cicp_params_get_range"
  (** Gets the range property of @self. *)

  external get_matrix_coefficients : t -> int
    = "ml_gdk_cicp_params_get_matrix_coefficients"
  (** Gets the matrix-coefficients property of @self. *)

  external get_color_primaries : t -> int
    = "ml_gdk_cicp_params_get_color_primaries"
  (** Returns the value of the color-primaries property
  of @self. *)

  external build_color_state : t -> (Color_state.t, GError.t) result
    = "ml_gdk_cicp_params_build_color_state"
  (** Creates a new `GdkColorState` object for the cicp parameters in @self.

  Note that this may fail if the cicp parameters in @self are not
  supported by GTK. In that case, `NULL` is returned, and @error is set
  with an error message that can be presented to the user. *)

  (* Properties *)
end = struct
  type t = [ `cicp_params | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gdk_cicp_params_get_type"

  external new_ : unit -> t = "ml_gdk_cicp_params_new"
  (** Create a new CicpParams *)

  (* Methods *)

  external set_transfer_function : t -> int -> unit
    = "ml_gdk_cicp_params_set_transfer_function"
  (** Sets the transfer-function property of @self. *)

  external set_range : t -> Gdk_enums.cicprange -> unit
    = "ml_gdk_cicp_params_set_range"
  (** Sets the range property of @self *)

  external set_matrix_coefficients : t -> int -> unit
    = "ml_gdk_cicp_params_set_matrix_coefficients"
  (** @self a `GdkCicpParams`
  Sets the matrix-coefficients property of @self. *)

  external set_color_primaries : t -> int -> unit
    = "ml_gdk_cicp_params_set_color_primaries"
  (** Sets the color-primaries property of @self. *)

  external get_transfer_function : t -> int
    = "ml_gdk_cicp_params_get_transfer_function"
  (** Gets the transfer-function property of @self. *)

  external get_range : t -> Gdk_enums.cicprange = "ml_gdk_cicp_params_get_range"
  (** Gets the range property of @self. *)

  external get_matrix_coefficients : t -> int
    = "ml_gdk_cicp_params_get_matrix_coefficients"
  (** Gets the matrix-coefficients property of @self. *)

  external get_color_primaries : t -> int
    = "ml_gdk_cicp_params_get_color_primaries"
  (** Returns the value of the color-primaries property
  of @self. *)

  external build_color_state : t -> (Color_state.t, GError.t) result
    = "ml_gdk_cicp_params_build_color_state"
  (** Creates a new `GdkColorState` object for the cicp parameters in @self.

  Note that this may fail if the cicp parameters in @self are not
  supported by GTK. In that case, `NULL` is returned, and @error is set
  with an error message that can be presented to the user. *)

  (* Properties *)
end

and Color_state : sig
  type t = [ `color_state ] Gobject.obj

  (* Methods *)

  external ref : t -> t = "ml_gdk_color_state_ref"
  (** Increase the reference count of @self. *)

  external equivalent : t -> t -> bool = "ml_gdk_color_state_equivalent"
  (** Compares two `GdkColorStates` for equivalence.

      Two objects that represent the same color state should be equivalent, even
      though they may not be equal in the sense of
      [method@Gdk.ColorState.equal]. *)

  external equal : t -> t -> bool = "ml_gdk_color_state_equal"
  (** Compares two `GdkColorStates` for equality.

      Note that this function is not guaranteed to be perfect and two objects
      describing the same color state may compare not equal. However, different
      color states will never compare equal. *)

  external create_cicp_params : t -> Cicp_params.t option
    = "ml_gdk_color_state_create_cicp_params"
  (** Create a [class@Gdk.CicpParams] representing the colorstate.

      It is not guaranteed that every `GdkColorState` can be represented with
      Cicp parameters. If that is the case, this function returns `NULL`. *)

  external get_type : unit -> Gobject.Type.t = "ml_gdk_color_state_get_type"
end = struct
  type t = [ `color_state ] Gobject.obj

  (* Methods *)

  external ref : t -> t = "ml_gdk_color_state_ref"
  (** Increase the reference count of @self. *)

  external equivalent : t -> t -> bool = "ml_gdk_color_state_equivalent"
  (** Compares two `GdkColorStates` for equivalence.

      Two objects that represent the same color state should be equivalent, even
      though they may not be equal in the sense of
      [method@Gdk.ColorState.equal]. *)

  external equal : t -> t -> bool = "ml_gdk_color_state_equal"
  (** Compares two `GdkColorStates` for equality.

      Note that this function is not guaranteed to be perfect and two objects
      describing the same color state may compare not equal. However, different
      color states will never compare equal. *)

  external create_cicp_params : t -> Cicp_params.t option
    = "ml_gdk_color_state_create_cicp_params"
  (** Create a [class@Gdk.CicpParams] representing the colorstate.

      It is not guaranteed that every `GdkColorState` can be represented with
      Cicp parameters. If that is the case, this function returns `NULL`. *)

  external get_type : unit -> Gobject.Type.t = "ml_gdk_color_state_get_type"
end
