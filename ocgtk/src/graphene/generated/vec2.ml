(* GENERATED CODE - DO NOT EDIT *)
(* Vec2: Vec2 *)

type t = [ `vec2 ] Gobject.obj
(** A structure capable of holding a vector with two dimensions, x and y.

    The contents of the #graphene_vec2_t structure are private and should never
    be accessed directly. *)

external gtype : unit -> Gobject.Type.t = "ml_graphene_vec2_get_type"

external alloc : unit -> t = "ml_graphene_vec2_alloc"
(** Create a new Vec2 *)

(* Methods *)

external to_float : t -> float array = "ml_graphene_vec2_to_float"
(** Stores the components of @v into an array. *)

external subtract : t -> t -> t = "ml_graphene_vec2_subtract"
(** Subtracts from each component of the first operand @a the
corresponding component of the second operand @b and places
each result into the components of @res. *)

external scale : t -> float -> t = "ml_graphene_vec2_scale"
(** Multiplies all components of the given vector with the given scalar @factor. *)

external normalize : t -> t = "ml_graphene_vec2_normalize"
(** Computes the normalized vector for the given vector @v. *)

external negate : t -> t = "ml_graphene_vec2_negate"
(** Negates the given #graphene_vec2_t. *)

external near : t -> t -> float -> bool = "ml_graphene_vec2_near"
(** Compares the two given #graphene_vec2_t vectors and checks
whether their values are within the given @epsilon. *)

external multiply : t -> t -> t = "ml_graphene_vec2_multiply"
(** Multiplies each component of the two passed vectors and places
each result into the components of @res. *)

external min : t -> t -> t = "ml_graphene_vec2_min"
(** Compares the two given vectors and places the minimum
values of each component into @res. *)

external max : t -> t -> t = "ml_graphene_vec2_max"
(** Compares the two given vectors and places the maximum
values of each component into @res. *)

external length : t -> float = "ml_graphene_vec2_length"
(** Computes the length of the given vector. *)

external interpolate : t -> t -> float -> t = "ml_graphene_vec2_interpolate"
(** Linearly interpolates @v1 and @v2 using the given @factor. *)

external init_from_vec2 : t -> t -> t = "ml_graphene_vec2_init_from_vec2"
(** Copies the contents of @src into @v. *)

external init_from_float : t -> float array -> t
  = "ml_graphene_vec2_init_from_float"
(** Initializes @v with the contents of the given array. *)

external init : t -> float -> float -> t = "ml_graphene_vec2_init"
(** Initializes a #graphene_vec2_t using the given values.

    This function can be called multiple times. *)

external get_y : t -> float = "ml_graphene_vec2_get_y"
(** Retrieves the Y component of the #graphene_vec2_t. *)

external get_x : t -> float = "ml_graphene_vec2_get_x"
(** Retrieves the X component of the #graphene_vec2_t. *)

external equal : t -> t -> bool = "ml_graphene_vec2_equal"
(** Checks whether the two given #graphene_vec2_t are equal. *)

external dot : t -> t -> float = "ml_graphene_vec2_dot"
(** Computes the dot product of the two given vectors. *)

external divide : t -> t -> t = "ml_graphene_vec2_divide"
(** Divides each component of the first operand @a by the corresponding
component of the second operand @b, and places the results into the
vector @res. *)

external add : t -> t -> t = "ml_graphene_vec2_add"
(** Adds each component of the two passed vectors and places
each result into the components of @res. *)
