(* GENERATED CODE - DO NOT EDIT *)
(* AccessibleList: AccessibleList *)

type t = [ `accessible_list ] Gobject.obj
(** Wraps a list of references to [iface@Gtk.Accessible] objects. *)

external gtype : unit -> Gobject.Type.t = "ml_gtk_accessible_list_get_type"

external new_from_array :
  At_context_and__accessible.Accessible.t array -> Gsize.t -> t
  = "ml_gtk_accessible_list_new_from_array"
(** Create a new AccessibleList *)

external new_from_list : At_context_and__accessible.Accessible.t list -> t
  = "ml_gtk_accessible_list_new_from_list"
(** Create a new AccessibleList *)

(* Methods *)

external get_objects : t -> At_context_and__accessible.Accessible.t list
  = "ml_gtk_accessible_list_get_objects"
(** Gets the list of objects this boxed type holds. *)
