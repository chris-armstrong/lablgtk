(* GENERATED CODE - DO NOT EDIT *)
(* Size: Size *)

type t = [ `size ] Gobject.obj
(** A size. *)

external gtype : unit -> Gobject.Type.t = "ml_graphene_size_get_type"

external alloc : unit -> t = "ml_graphene_size_alloc"
(** Create a new Size *)

(* Methods *)

external scale : t -> float -> t = "ml_graphene_size_scale"
(** Scales the components of a #graphene_size_t using the given @factor. *)

external interpolate : t -> t -> float -> t = "ml_graphene_size_interpolate"
(** Linearly interpolates the two given #graphene_size_t using the given
interpolation @factor. *)

external init_from_size : t -> t -> t = "ml_graphene_size_init_from_size"
(** Initializes a #graphene_size_t using the width and height of
the given @src. *)

external init : t -> float -> float -> t = "ml_graphene_size_init"
(** Initializes a #graphene_size_t using the given @width and @height. *)

external equal : t -> t -> bool = "ml_graphene_size_equal"
(** Checks whether the two give #graphene_size_t are equal. *)
