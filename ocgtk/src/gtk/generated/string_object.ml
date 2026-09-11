(* GENERATED CODE - DO NOT EDIT *)
(* StringObject: StringObject *)

type t = [ `string_object | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_string_object_get_type"

external new_ : string -> t = "ml_gtk_string_object_new"
(** Create a new StringObject *)

(* Methods *)

external get_string : t -> string = "ml_gtk_string_object_get_string"
(** Returns the string contained in a `GtkStringObject`. *)

(* Properties *)
