(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec Menu_link_iter : sig
  type t = [ `menu_link_iter | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gio_menu_link_iter_get_type"

  (* Methods *)

  external next : t -> bool = "ml_g_menu_link_iter_next"
  (** Attempts to advance the iterator to the next (possibly first) link.

      %TRUE is returned on success, or %FALSE if there are no more links.

      You must call this function when you first acquire the iterator to advance
      it to the first link (and determine if the first link exists at all). *)

  external get_value : t -> Menu_model.t = "ml_g_menu_link_iter_get_value"
  (** Gets the linked #GMenuModel at the current iterator position.

      The iterator is not advanced. *)

  external get_name : t -> string = "ml_g_menu_link_iter_get_name"
  (** Gets the name of the link at the current iterator position.

      The iterator is not advanced. *)
end = struct
  type t = [ `menu_link_iter | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gio_menu_link_iter_get_type"

  (* Methods *)

  external next : t -> bool = "ml_g_menu_link_iter_next"
  (** Attempts to advance the iterator to the next (possibly first) link.

      %TRUE is returned on success, or %FALSE if there are no more links.

      You must call this function when you first acquire the iterator to advance
      it to the first link (and determine if the first link exists at all). *)

  external get_value : t -> Menu_model.t = "ml_g_menu_link_iter_get_value"
  (** Gets the linked #GMenuModel at the current iterator position.

      The iterator is not advanced. *)

  external get_name : t -> string = "ml_g_menu_link_iter_get_name"
  (** Gets the name of the link at the current iterator position.

      The iterator is not advanced. *)
end

and Menu_model : sig
  type t = [ `menu_model | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gio_menu_model_get_type"

  (* Methods *)

  external iterate_item_links : t -> int -> Menu_link_iter.t
    = "ml_g_menu_model_iterate_item_links"
  (** Creates a #GMenuLinkIter to iterate over the links of the item at
  position @item_index in @model.

  You must free the iterator with g_object_unref() when you are done. *)

  external iterate_item_attributes : t -> int -> Menu_attribute_iter.t
    = "ml_g_menu_model_iterate_item_attributes"
  (** Creates a #GMenuAttributeIter to iterate over the attributes of
  the item at position @item_index in @model.

  You must free the iterator with g_object_unref() when you are done. *)

  external items_changed : t -> int -> int -> int -> unit
    = "ml_g_menu_model_items_changed"
  (** Requests emission of the #GMenuModel::items-changed signal on @model.

  This function should never be called except by #GMenuModel
  subclasses.  Any other calls to this function will very likely lead
  to a violation of the interface of the model.

  The implementation should update its internal representation of the
  menu before emitting the signal.  The implementation should further
  expect to receive queries about the new state of the menu (and
  particularly added menu items) while signal handlers are running.

  The implementation must dispatch this call directly from a mainloop
  entry and not in response to calls -- particularly those from the
  #GMenuModel API.  Said another way: the menu must not change while
  user code is running without returning to the mainloop. *)

  external is_mutable : t -> bool = "ml_g_menu_model_is_mutable"
  (** Queries if @model is mutable.

  An immutable #GMenuModel will never emit the #GMenuModel::items-changed
  signal. Consumers of the model may make optimisations accordingly. *)

  external get_n_items : t -> int = "ml_g_menu_model_get_n_items"
  (** Query the number of items in @model. *)

  external get_item_link : t -> int -> string -> t option
    = "ml_g_menu_model_get_item_link"
  (** Queries the item at position @item_index in @model for the link
  specified by @link.

  If the link exists, the linked #GMenuModel is returned.  If the link
  does not exist, %NULL is returned. *)

  external get_item_attribute_value :
    t -> int -> string -> Gvariant_type.t option -> Gvariant.t option
    = "ml_g_menu_model_get_item_attribute_value"
  (** Queries the item at position @item_index in @model for the attribute
  specified by @attribute.

  If @expected_type is non-%NULL then it specifies the expected type of
  the attribute.  If it is %NULL then any type will be accepted.

  If the attribute exists and matches @expected_type (or if the
  expected type is unspecified) then the value is returned.

  If the attribute does not exist, or does not match the expected type
  then %NULL is returned. *)

  val on_items_changed :
    ?after:bool ->
    t ->
    callback:(position:int -> removed:int -> added:int -> unit) ->
    Gobject.Signal.handler_id
end = struct
  type t = [ `menu_model | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gio_menu_model_get_type"

  (* Methods *)

  external iterate_item_links : t -> int -> Menu_link_iter.t
    = "ml_g_menu_model_iterate_item_links"
  (** Creates a #GMenuLinkIter to iterate over the links of the item at
  position @item_index in @model.

  You must free the iterator with g_object_unref() when you are done. *)

  external iterate_item_attributes : t -> int -> Menu_attribute_iter.t
    = "ml_g_menu_model_iterate_item_attributes"
  (** Creates a #GMenuAttributeIter to iterate over the attributes of
  the item at position @item_index in @model.

  You must free the iterator with g_object_unref() when you are done. *)

  external items_changed : t -> int -> int -> int -> unit
    = "ml_g_menu_model_items_changed"
  (** Requests emission of the #GMenuModel::items-changed signal on @model.

  This function should never be called except by #GMenuModel
  subclasses.  Any other calls to this function will very likely lead
  to a violation of the interface of the model.

  The implementation should update its internal representation of the
  menu before emitting the signal.  The implementation should further
  expect to receive queries about the new state of the menu (and
  particularly added menu items) while signal handlers are running.

  The implementation must dispatch this call directly from a mainloop
  entry and not in response to calls -- particularly those from the
  #GMenuModel API.  Said another way: the menu must not change while
  user code is running without returning to the mainloop. *)

  external is_mutable : t -> bool = "ml_g_menu_model_is_mutable"
  (** Queries if @model is mutable.

  An immutable #GMenuModel will never emit the #GMenuModel::items-changed
  signal. Consumers of the model may make optimisations accordingly. *)

  external get_n_items : t -> int = "ml_g_menu_model_get_n_items"
  (** Query the number of items in @model. *)

  external get_item_link : t -> int -> string -> t option
    = "ml_g_menu_model_get_item_link"
  (** Queries the item at position @item_index in @model for the link
  specified by @link.

  If the link exists, the linked #GMenuModel is returned.  If the link
  does not exist, %NULL is returned. *)

  external get_item_attribute_value :
    t -> int -> string -> Gvariant_type.t option -> Gvariant.t option
    = "ml_g_menu_model_get_item_attribute_value"
  (** Queries the item at position @item_index in @model for the attribute
  specified by @attribute.

  If @expected_type is non-%NULL then it specifies the expected type of
  the attribute.  If it is %NULL then any type will be accepted.

  If the attribute exists and matches @expected_type (or if the
  expected type is unspecified) then the value is returned.

  If the attribute does not exist, or does not match the expected type
  then %NULL is returned. *)

  let on_items_changed ?after obj ~callback =
    let closure =
      Gobject.Closure.create (fun argv ->
          let position =
            let v = Gobject.Closure.nth argv ~pos:1 in
            Gobject.Value.get_int v
          in
          let removed =
            let v = Gobject.Closure.nth argv ~pos:2 in
            Gobject.Value.get_int v
          in
          let added =
            let v = Gobject.Closure.nth argv ~pos:3 in
            Gobject.Value.get_int v
          in
          callback ~position ~removed ~added)
    in
    Gobject.Signal.connect obj ~name:"items-changed" ~callback:closure
      ~after:(Option.value after ~default:false)
end
