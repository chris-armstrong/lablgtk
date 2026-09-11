(* GENERATED CODE - DO NOT EDIT *)
(* ConstantExpression: ConstantExpression *)

type t = [ `constant_expression | `expression ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_constant_expression_get_type"

external new_for_value : Gobject.Value.t -> t
  = "ml_gtk_constant_expression_new_for_value"
(** Create a new ConstantExpression *)

(* Methods *)

external get_value : t -> Gobject.Value.t
  = "ml_gtk_constant_expression_get_value"
(** Gets the value that a constant expression evaluates to. *)
