(* GENERATED CODE - DO NOT EDIT *)
(* Menu: Menu *)

type t = [ `menu | `menu_model | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_menu_get_type"

external new_ : unit -> t = "ml_g_menu_new"
(** Create a new Menu *)

(* Methods *)

external remove_all : t -> unit = "ml_g_menu_remove_all"
(** Removes all items in the menu. *)

external remove : t -> int -> unit = "ml_g_menu_remove"
(** Removes an item from the menu.

@position gives the index of the item to remove.

It is an error if position is not in range the range from 0 to one
less than the number of items in the menu.

It is not possible to remove items by identity since items are added
to the menu simply by copying their links and attributes (ie:
identity of the item itself is not preserved). *)

external prepend_submenu :
  t -> string option -> Menu_link_iter_and__menu_model.Menu_model.t -> unit
  = "ml_g_menu_prepend_submenu"
(** Convenience function for prepending a submenu menu item to the start
of @menu.  Combine g_menu_item_new_submenu() and g_menu_insert_item() for
a more flexible alternative. *)

external prepend_section :
  t -> string option -> Menu_link_iter_and__menu_model.Menu_model.t -> unit
  = "ml_g_menu_prepend_section"
(** Convenience function for prepending a section menu item to the start
of @menu.  Combine g_menu_item_new_section() and g_menu_insert_item() for
a more flexible alternative. *)

external prepend_item : t -> Menu_item.t -> unit = "ml_g_menu_prepend_item"
(** Prepends @item to the start of @menu.

See g_menu_insert_item() for more information. *)

external prepend : t -> string option -> string option -> unit
  = "ml_g_menu_prepend"
(** Convenience function for prepending a normal menu item to the start
of @menu.  Combine g_menu_item_new() and g_menu_insert_item() for a more
flexible alternative. *)

external insert_submenu :
  t ->
  int ->
  string option ->
  Menu_link_iter_and__menu_model.Menu_model.t ->
  unit = "ml_g_menu_insert_submenu"
(** Convenience function for inserting a submenu menu item into @menu.
Combine g_menu_item_new_submenu() and g_menu_insert_item() for a more
flexible alternative. *)

external insert_section :
  t ->
  int ->
  string option ->
  Menu_link_iter_and__menu_model.Menu_model.t ->
  unit = "ml_g_menu_insert_section"
(** Convenience function for inserting a section menu item into @menu.
Combine g_menu_item_new_section() and g_menu_insert_item() for a more
flexible alternative. *)

external insert_item : t -> int -> Menu_item.t -> unit = "ml_g_menu_insert_item"
(** Inserts @item into @menu.

The "insertion" is actually done by copying all of the attribute and
link values of @item and using them to form a new item within @menu.
As such, @item itself is not really inserted, but rather, a menu item
that is exactly the same as the one presently described by @item.

This means that @item is essentially useless after the insertion
occurs.  Any changes you make to it are ignored unless it is inserted
again (at which point its updated values will be copied).

You should probably just free @item once you're done.

There are many convenience functions to take care of common cases.
See g_menu_insert(), g_menu_insert_section() and
g_menu_insert_submenu() as well as "prepend" and "append" variants of
each of these functions. *)

external insert : t -> int -> string option -> string option -> unit
  = "ml_g_menu_insert"
(** Convenience function for inserting a normal menu item into @menu.
Combine g_menu_item_new() and g_menu_insert_item() for a more flexible
alternative. *)

external freeze : t -> unit = "ml_g_menu_freeze"
(** Marks @menu as frozen.

After the menu is frozen, it is an error to attempt to make any
changes to it.  In effect this means that the #GMenu API must no
longer be used.

This function causes g_menu_model_is_mutable() to begin returning
%FALSE, which has some positive performance implications. *)

external append_submenu :
  t -> string option -> Menu_link_iter_and__menu_model.Menu_model.t -> unit
  = "ml_g_menu_append_submenu"
(** Convenience function for appending a submenu menu item to the end of
@menu.  Combine g_menu_item_new_submenu() and g_menu_insert_item() for a
more flexible alternative. *)

external append_section :
  t -> string option -> Menu_link_iter_and__menu_model.Menu_model.t -> unit
  = "ml_g_menu_append_section"
(** Convenience function for appending a section menu item to the end of
@menu.  Combine g_menu_item_new_section() and g_menu_insert_item() for a
more flexible alternative. *)

external append_item : t -> Menu_item.t -> unit = "ml_g_menu_append_item"
(** Appends @item to the end of @menu.

See g_menu_insert_item() for more information. *)

external append : t -> string option -> string option -> unit
  = "ml_g_menu_append"
(** Convenience function for appending a normal menu item to the end of
@menu.  Combine g_menu_item_new() and g_menu_insert_item() for a more
flexible alternative. *)
