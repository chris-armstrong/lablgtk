(* GENERATED CODE - DO NOT EDIT *)
(* Quad: Quad *)

type t = [ `quad ] Gobject.obj
(** A 4 vertex quadrilateral, as represented by four #graphene_point_t.

    The contents of a #graphene_quad_t are private and should never be accessed
    directly. *)

external gtype : unit -> Gobject.Type.t = "ml_graphene_quad_get_type"

external alloc : unit -> t = "ml_graphene_quad_alloc"
(** Create a new Quad *)

(* Methods *)

external init_from_rect : t -> Rect.t -> t = "ml_graphene_quad_init_from_rect"
(** Initializes a #graphene_quad_t using the four corners of the given
    #graphene_rect_t. *)

external init_from_points : t -> Point.t array -> t
  = "ml_graphene_quad_init_from_points"
(** Initializes a #graphene_quad_t using an array of points. *)

external init : t -> Point.t -> Point.t -> Point.t -> Point.t -> t
  = "ml_graphene_quad_init"
(** Initializes a #graphene_quad_t with the given points. *)

external get_point : t -> int -> Point.t = "ml_graphene_quad_get_point"
(** Retrieves the point of a #graphene_quad_t at the given index. *)

external contains : t -> Point.t -> bool = "ml_graphene_quad_contains"
(** Checks if the given #graphene_quad_t contains the given #graphene_point_t.
*)

external bounds : t -> Rect.t = "ml_graphene_quad_bounds"
(** Computes the bounding rectangle of @q and places it into @r. *)
