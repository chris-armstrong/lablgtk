(* GENERATED CODE - DO NOT EDIT *)
(* ListStore: ListStore *)

type t = [ `list_store | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_list_store_get_type"

external new_ : Gobject.Type.t -> t = "ml_g_list_store_new"
(** Create a new ListStore *)

(* Methods *)

external splice :
  t -> int -> int -> [ `object_ ] Gobject.obj array -> int -> unit
  = "ml_g_list_store_splice"
(** Changes @store by removing @n_removals items and adding @n_additions
items to it. @additions must contain @n_additions items of type
#GListStore:item-type.  %NULL is not permitted.

This function is more efficient than g_list_store_insert() and
g_list_store_remove(), because it only emits
#GListModel::items-changed once for the change.

This function takes a ref on each item in @additions.

The parameters @position and @n_removals must be correct (ie:
@position + @n_removals must be less than or equal to the length of
the list at the time this function is called). *)

external remove_all : t -> unit = "ml_g_list_store_remove_all"
(** Removes all items from @store. *)

external remove : t -> int -> unit = "ml_g_list_store_remove"
(** Removes the item from @store that is at @position. @position must be
smaller than the current length of the list.

Use g_list_store_splice() to remove multiple items at the same time
efficiently. *)

external insert : t -> int -> [ `object_ ] Gobject.obj -> unit
  = "ml_g_list_store_insert"
(** Inserts @item into @store at @position. @item must be of type
#GListStore:item-type or derived from it. @position must be smaller
than the length of the list, or equal to it to append.

This function takes a ref on @item.

Use g_list_store_splice() to insert multiple items at the same time
efficiently. *)

external find : t -> [ `object_ ] Gobject.obj -> bool * int
  = "ml_g_list_store_find"
(** Looks up the given @item in the list store by looping over the items until
the first occurrence of @item. If @item was not found, then @position will
not be set, and this method will return %FALSE.

If you need to compare the two items with a custom comparison function, use
g_list_store_find_with_equal_func() with a custom #GEqualFunc instead. *)

external append : t -> [ `object_ ] Gobject.obj -> unit
  = "ml_g_list_store_append"
(** Appends @item to @store. @item must be of type #GListStore:item-type.

This function takes a ref on @item.

Use g_list_store_splice() to append multiple items at the same time
efficiently. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t = "ml_g_list_store_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_g_list_store_get_n_items"
(** Get property: n-items *)
