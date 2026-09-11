(* GENERATED CODE - DO NOT EDIT *)
(* Item: Item *)

type t = [ `item ] Gobject.obj
(** The `PangoItem` structure stores information about a segment of text.

    You typically obtain `PangoItems` by itemizing a piece of text with
    [func@itemize]. *)

external gtype : unit -> Gobject.Type.t = "ml_pango_item_get_type"

external new_ : unit -> t = "ml_pango_item_new"
(** Create a new Item *)

(* Methods *)

external split : t -> int -> int -> t = "ml_pango_item_split"
(** Modifies @orig to cover only the text after @split_index, and
returns a new item that covers the text before @split_index that
used to be in @orig.

You can think of @split_index as the length of the returned item.
@split_index may not be 0, and it may not be greater than or equal
to the length of @orig (that is, there must be at least one byte
assigned to each item, you can't create a zero-length item).
@split_offset is the length of the first item in chars, and must be
provided because the text used to generate the item isn't available,
so `pango_item_split()` can't count the char length of the split items
itself. *)

external get_char_offset : t -> int = "ml_pango_item_get_char_offset"
(** Returns the character offset of the item from the beginning of the itemized
    text.

    If the item has not been obtained from Pango's itemization machinery, then
    the character offset is not available. In that case, this function returns
    -1. *)

external apply_attrs : t -> Attr_iterator.t -> unit
  = "ml_pango_item_apply_attrs"
(** Add attributes to a `PangoItem`.

The idea is that you have attributes that don't affect itemization,
such as font features, so you filter them out using
[method@Pango.AttrList.filter], itemize your text, then reapply the
attributes to the resulting items using this function.

The @iter should be positioned before the range of the item,
and will be advanced past it. This function is meant to be called
in a loop over the items resulting from itemization, while passing
the iter to each call. *)
