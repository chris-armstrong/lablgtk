(* GENERATED CODE - DO NOT EDIT *)
(* MenuAttributeIter: MenuAttributeIter *)

type t = [ `menu_attribute_iter | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_menu_attribute_iter_get_type"

(* Methods *)

external next : t -> bool = "ml_g_menu_attribute_iter_next"
(** Attempts to advance the iterator to the next (possibly first) attribute.

    %TRUE is returned on success, or %FALSE if there are no more attributes.

    You must call this function when you first acquire the iterator to advance
    it to the first attribute (and determine if the first attribute exists at
    all). *)

external get_value : t -> Gvariant.t = "ml_g_menu_attribute_iter_get_value"
(** Gets the value of the attribute at the current iterator position.

    The iterator is not advanced. *)

external get_name : t -> string = "ml_g_menu_attribute_iter_get_name"
(** Gets the name of the attribute at the current iterator position, as a
    string.

    The iterator is not advanced. *)
