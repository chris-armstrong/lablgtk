(* GENERATED CODE - DO NOT EDIT *)
(* PropertyExpression: PropertyExpression *)

type t = [ `property_expression | `expression ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_property_expression_get_type"

external new_ : Gobject.Type.t -> Expression.t option -> string -> t
  = "ml_gtk_property_expression_new"
(** Create a new PropertyExpression *)

(* Methods *)

external get_expression : t -> Expression.t option
  = "ml_gtk_property_expression_get_expression"
(** Gets the expression specifying the object of a property expression. *)
