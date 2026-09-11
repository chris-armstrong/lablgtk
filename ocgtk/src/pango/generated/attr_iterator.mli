(* GENERATED CODE - DO NOT EDIT *)
(* AttrIterator: AttrIterator *)

type t = [ `attr_iterator ] Gobject.obj
(** A `PangoAttrIterator` is used to iterate through a `PangoAttrList`.

    A new iterator is created with [method@Pango.AttrList.get_iterator]. Once
    the iterator is created, it can be advanced through the style changes in the
    text using [method@Pango.AttrIterator.next]. At each style change, the range
    of the current style segment and the attributes currently in effect can be
    queried. *)

external gtype : unit -> Gobject.Type.t = "ml_pango_attr_iterator_get_type"

(* Methods *)

external range : t -> int * int = "ml_pango_attr_iterator_range"
(** Get the range of the current segment.

    Note that the stored return values are signed, not unsigned like the values
    in `PangoAttribute`. To deal with this API oversight, stored return values
    that wouldn't fit into a signed integer are clamped to %G_MAXINT. *)

external next : t -> bool = "ml_pango_attr_iterator_next"
(** Advance the iterator until the next change of style. *)

external get_attrs : t -> Attribute.t list = "ml_pango_attr_iterator_get_attrs"
(** Gets a list of all attributes at the current position of the iterator. *)

external get : t -> Pango_enums.attrtype -> Attribute.t option
  = "ml_pango_attr_iterator_get"
(** Find the current attribute of a particular type at the iterator location.

    When multiple attributes of the same type overlap, the attribute whose range
    starts closest to the current location is used. *)

external destroy : t -> unit = "ml_pango_attr_iterator_destroy"
(** Destroy a `PangoAttrIterator` and free all associated memory. *)
