(* GENERATED CODE - DO NOT EDIT *)
(* NumericSorter: NumericSorter *)

type t = [ `numeric_sorter | `sorter | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_numeric_sorter_get_type"

external new_ : Expression.t option -> t = "ml_gtk_numeric_sorter_new"
(** Create a new NumericSorter *)

(* Methods *)

external set_sort_order : t -> Gtk_enums.sorttype -> unit
  = "ml_gtk_numeric_sorter_set_sort_order"
(** Sets whether to sort smaller numbers before larger ones. *)

external set_expression : t -> Expression.t option -> unit
  = "ml_gtk_numeric_sorter_set_expression"
(** Sets the expression that is evaluated to obtain numbers from items.

Unless an expression is set on @self, the sorter will always
compare items as invalid.

The expression must have a return type that can be compared
numerically, such as %G_TYPE_INT or %G_TYPE_DOUBLE. *)

external get_sort_order : t -> Gtk_enums.sorttype
  = "ml_gtk_numeric_sorter_get_sort_order"
(** Gets whether this sorter will sort smaller numbers first. *)

external get_expression : t -> Expression.t option
  = "ml_gtk_numeric_sorter_get_expression"
(** Gets the expression that is evaluated to obtain numbers from items. *)

(* Properties *)
