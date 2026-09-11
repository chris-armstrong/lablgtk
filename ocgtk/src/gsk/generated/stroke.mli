(* GENERATED CODE - DO NOT EDIT *)
(* Stroke: Stroke *)

type t = [ `stroke ] Gobject.obj
(** Collects the parameters that are needed when stroking a path. *)

external gtype : unit -> Gobject.Type.t = "ml_gsk_stroke_get_type"

external new_ : float -> t = "ml_gsk_stroke_new"
(** Create a new Stroke *)

(* Methods *)

external to_cairo : t -> Ocgtk_cairo.Cairo.Wrappers.Context.t -> unit
  = "ml_gsk_stroke_to_cairo"
(** A helper function that sets the stroke parameters of a cairo context from a
    `GskStroke`. *)

external set_miter_limit : t -> float -> unit = "ml_gsk_stroke_set_miter_limit"
(** Sets the miter limit to be used when stroking.

    The miter limit is the distance from the corner where sharp turns of joins
    get cut off.

    The limit is specfied in units of line width and must be non-negative.

    For joins of type [enum@Gsk.LineJoin.miter] that exceed the miter limit, the
    join gets rendered as if it was of type [enum@Gsk.LineJoin.bevel]. *)

external set_line_width : t -> float -> unit = "ml_gsk_stroke_set_line_width"
(** Sets the line width to be used when stroking.

    The line width must be >= 0. *)

external set_line_join : t -> Gsk_enums.linejoin -> unit
  = "ml_gsk_stroke_set_line_join"
(** Sets the line join to be used when stroking.

    See [enum@Gsk.LineJoin] for details. *)

external set_line_cap : t -> Gsk_enums.linecap -> unit
  = "ml_gsk_stroke_set_line_cap"
(** Sets the line cap to be used when stroking.

    See [enum@Gsk.LineCap] for details. *)

external set_dash_offset : t -> float -> unit = "ml_gsk_stroke_set_dash_offset"
(** Sets the offset into the dash pattern where dashing should begin.

    This is an offset into the length of the path, not an index into the array
    values of the dash array.

    See [method@Gsk.Stroke.set_dash] for more details on dashing. *)

external set_dash : t -> float array option -> Gsize.t -> unit
  = "ml_gsk_stroke_set_dash"
(** Sets the dash pattern to use.

A dash pattern is specified by an array of alternating non-negative
values. Each value provides the length of alternate "on" and "off"
portions of the stroke.

Each "on" segment will have caps applied as if the segment were a
separate contour. In particular, it is valid to use an "on" length
of 0 with [enum@Gsk.LineCap.round] or [enum@Gsk.LineCap.square]
to draw dots or squares along a path.

If @n_dash is 0, if all elements in @dash are 0, or if there are
negative values in @dash, then dashing is disabled.

If @n_dash is 1, an alternating "on" and "off" pattern with the
single dash length provided is assumed.

If @n_dash is uneven, the dash array will be used with the first
element in @dash defining an "on" or "off" in alternating passes
through the array.

You can specify a starting offset into the dash with
[method@Gsk.Stroke.set_dash_offset]. *)

external get_miter_limit : t -> float = "ml_gsk_stroke_get_miter_limit"
(** Gets the miter limit. *)

external get_line_width : t -> float = "ml_gsk_stroke_get_line_width"
(** Gets the line width used. *)

external get_line_join : t -> Gsk_enums.linejoin = "ml_gsk_stroke_get_line_join"
(** Gets the line join used.

    See [enum@Gsk.LineJoin] for details. *)

external get_line_cap : t -> Gsk_enums.linecap = "ml_gsk_stroke_get_line_cap"
(** Gets the line cap used.

    See [enum@Gsk.LineCap] for details. *)

external get_dash_offset : t -> float = "ml_gsk_stroke_get_dash_offset"
(** Gets the dash offset. *)

external get_dash : t -> float array option * Gsize.t = "ml_gsk_stroke_get_dash"
(** Gets the dash array in use. *)
