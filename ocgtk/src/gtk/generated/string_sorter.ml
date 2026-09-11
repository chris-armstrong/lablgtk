(* GENERATED CODE - DO NOT EDIT *)
(* StringSorter: StringSorter *)

type t = [ `string_sorter | `sorter | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_string_sorter_get_type"

external new_ : Expression.t option -> t = "ml_gtk_string_sorter_new"
(** Create a new StringSorter *)

(* Methods *)

external set_ignore_case : t -> bool -> unit
  = "ml_gtk_string_sorter_set_ignore_case"
(** Sets whether the sorter will ignore case differences. *)

external set_expression : t -> Expression.t option -> unit
  = "ml_gtk_string_sorter_set_expression"
(** Sets the expression that is evaluated to obtain strings from items.

    The expression must have the type %G_TYPE_STRING. *)

external set_collation : t -> Gtk_enums.collation -> unit
  = "ml_gtk_string_sorter_set_collation"
(** Sets the collation method to use for sorting. *)

external get_ignore_case : t -> bool = "ml_gtk_string_sorter_get_ignore_case"
(** Gets whether the sorter ignores case differences. *)

external get_expression : t -> Expression.t option
  = "ml_gtk_string_sorter_get_expression"
(** Gets the expression that is evaluated to obtain strings from items. *)

external get_collation : t -> Gtk_enums.collation
  = "ml_gtk_string_sorter_get_collation"
(** Gets which collation method the sorter uses. *)

(* Properties *)
