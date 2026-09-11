(* GENERATED CODE - DO NOT EDIT *)
(* StringFilter: StringFilter *)

type t = [ `string_filter | `filter | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_string_filter_get_type"

external new_ : Expression.t option -> t = "ml_gtk_string_filter_new"
(** Create a new StringFilter *)

(* Methods *)

external set_search : t -> string option -> unit
  = "ml_gtk_string_filter_set_search"
(** Sets the string to search for. *)

external set_match_mode : t -> Gtk_enums.stringfiltermatchmode -> unit
  = "ml_gtk_string_filter_set_match_mode"
(** Sets the match mode for the filter. *)

external set_ignore_case : t -> bool -> unit
  = "ml_gtk_string_filter_set_ignore_case"
(** Sets whether the filter ignores case differences. *)

external set_expression : t -> Expression.t option -> unit
  = "ml_gtk_string_filter_set_expression"
(** Sets the expression that the string filter uses to obtain strings from
    items.

    The expression must have a value type of `G_TYPE_STRING`. *)

external get_search : t -> string option = "ml_gtk_string_filter_get_search"
(** Gets the search term. *)

external get_match_mode : t -> Gtk_enums.stringfiltermatchmode
  = "ml_gtk_string_filter_get_match_mode"
(** Returns the match mode that the filter is using. *)

external get_ignore_case : t -> bool = "ml_gtk_string_filter_get_ignore_case"
(** Returns whether the filter ignores case differences. *)

external get_expression : t -> Expression.t option
  = "ml_gtk_string_filter_get_expression"
(** Gets the expression that the string filter uses to obtain strings from
    items. *)

(* Properties *)
