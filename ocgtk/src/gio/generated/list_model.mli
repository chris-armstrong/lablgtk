(* GENERATED CODE - DO NOT EDIT *)
(* ListModel: ListModel *)

type t = [ `list_model ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_list_model_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gio_list_model_from_gobject"

(* Methods *)

external items_changed : t -> int -> int -> int -> unit
  = "ml_g_list_model_items_changed"
(** Emits the #GListModel::items-changed signal on @list.

This function should only be called by classes implementing
#GListModel. It has to be called after the internal representation
of @list has been updated, because handlers connected to this signal
might query the new state of the list.

Implementations must only make changes to the model (as visible to
its consumer) in places that will not cause problems for that
consumer.  For models that are driven directly by a write API (such
as #GListStore), changes can be reported in response to uses of that
API.  For models that represent remote data, changes should only be
made from a fresh mainloop dispatch.  It is particularly not
permitted to make changes in response to a call to the #GListModel
consumer API.

Stated another way: in general, it is assumed that code making a
series of accesses to the model via the API, without returning to the
mainloop, and without calling other code, will continue to view the
same contents of the model. *)

external get_object : t -> int -> [ `object_ ] Gobject.obj option
  = "ml_g_list_model_get_object"
(** Get the item at @position.

If @position is greater than the number of items in @list, %NULL is
returned.

%NULL is never returned for an index that is smaller than the length
of the list.

This function is meant to be used by language bindings in place
of g_list_model_get_item().

See also: g_list_model_get_n_items() *)

external get_n_items : t -> int = "ml_g_list_model_get_n_items"
(** Gets the number of items in @list.

Depending on the model implementation, calling this function may be
less efficient than iterating the list with increasing values for
@position until g_list_model_get_item() returns %NULL. *)

external get_item_type : t -> Gobject.Type.t = "ml_g_list_model_get_item_type"
(** Gets the type of the items in @list.

All items returned from g_list_model_get_item() are of the type
returned by this function, or a subtype, or if the type is an
interface, they are an implementation of that interface.

The item type of a #GListModel can not change during the life of the
model. *)

val on_items_changed :
  ?after:bool ->
  t ->
  callback:(position:int -> removed:int -> added:int -> unit) ->
  Gobject.Signal.handler_id
