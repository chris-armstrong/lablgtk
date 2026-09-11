(* GENERATED CODE - DO NOT EDIT *)
(* Coverage: Coverage *)

type t = [ `coverage | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_pango_coverage_get_type"

external new_ : unit -> t = "ml_pango_coverage_new"
(** Create a new Coverage *)

(* Methods *)

external unref : t -> unit = "ml_pango_coverage_unref"
(** Decrease the reference count on the `PangoCoverage` by one.

    If the result is zero, free the coverage and all associated memory. *)

external set : t -> int -> Pango_enums.coveragelevel -> unit
  = "ml_pango_coverage_set"
(** Modify a particular index within @coverage *)

external ref : t -> t = "ml_pango_coverage_ref"
(** Increase the reference count on the `PangoCoverage` by one. *)

external max : t -> t -> unit = "ml_pango_coverage_max"
(** Set the coverage for each index in @coverage to be the max (better)
value of the current coverage for the index and the coverage for
the corresponding index in @other. *)

external get : t -> int -> Pango_enums.coveragelevel = "ml_pango_coverage_get"
(** Determine whether a particular index is covered by @coverage. *)

external copy : t -> t = "ml_pango_coverage_copy"
(** Copy an existing `PangoCoverage`. *)
