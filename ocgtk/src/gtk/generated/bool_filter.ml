(* GENERATED CODE - DO NOT EDIT *)
(* BoolFilter: BoolFilter *)

type t = [ `bool_filter | `filter | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_bool_filter_get_type"

external new_ : Expression.t option -> t = "ml_gtk_bool_filter_new"
(** Create a new BoolFilter *)

(* Methods *)

external set_invert : t -> bool -> unit = "ml_gtk_bool_filter_set_invert"
(** Sets whether the filter should invert the expression. *)

external set_expression : t -> Expression.t option -> unit
  = "ml_gtk_bool_filter_set_expression"
(** Sets the expression that the filter uses to check if items should be
    filtered.

    The expression must have a value type of `G_TYPE_BOOLEAN`. *)

external get_invert : t -> bool = "ml_gtk_bool_filter_get_invert"
(** Returns whether the filter inverts the expression. *)

external get_expression : t -> Expression.t option
  = "ml_gtk_bool_filter_get_expression"
(** Gets the expression that the filter evaluates for each item. *)

(* Properties *)
