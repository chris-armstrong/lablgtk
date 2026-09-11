(* GENERATED CODE - DO NOT EDIT *)
(* AttrList: AttrList *)

type t = [ `attr_list ] Gobject.obj
(** A `PangoAttrList` represents a list of attributes that apply to a section of
    text.

    The attributes in a `PangoAttrList` are, in general, allowed to overlap in
    an arbitrary fashion. However, if the attributes are manipulated only
    through [method@Pango.AttrList.change], the overlap between properties will
    meet stricter criteria.

    Since the `PangoAttrList` structure is stored as a linear list, it is not
    suitable for storing attributes for large amounts of text. In general, you
    should not use a single `PangoAttrList` for more than one paragraph of text.
*)

external gtype : unit -> Gobject.Type.t = "ml_pango_attr_list_get_type"

external new_ : unit -> t = "ml_pango_attr_list_new"
(** Create a new AttrList *)

(* Methods *)

external update : t -> int -> int -> int -> unit = "ml_pango_attr_list_update"
(** Update indices of attributes in @list for a change in the
text they refer to.

The change that this function applies is removing @remove
bytes at position @pos and inserting @add bytes instead.

Attributes that fall entirely in the (@pos, @pos + @remove)
range are removed.

Attributes that start or end inside the (@pos, @pos + @remove)
range are shortened to reflect the removal.

Attributes start and end positions are updated if they are
behind @pos + @remove. *)

external to_string : t -> string = "ml_pango_attr_list_to_string"
(** Serializes a `PangoAttrList` to a string.

    In the resulting string, serialized attributes are separated by newlines or
    commas. Individual attributes are serialized to a string of the form

    [START END] TYPE VALUE

    Where START and END are the indices (with -1 being accepted in place of
    MAXUINT), TYPE is the nickname of the attribute value type, e.g. _weight_ or
    _stretch_, and the value is serialized according to its type:

    Optionally, START and END can be omitted to indicate unlimited extent.

    - enum values as nick or numeric value
    - boolean values as _true_ or _false_
    - integers and floats as numbers
    - strings as string, optionally quoted
    - font features as quoted string
    - PangoLanguage as string
    - PangoFontDescription as serialized by
      [method@Pango.FontDescription.to_string], quoted
    - PangoColor as serialized by [method@Pango.Color.to_string]

    Examples:

    0 10 foreground red, 5 15 weight bold, 0 200 font-desc "Sans 10"

    0 -1 weight 700 0 100 family Times

    weight bold

    To parse the returned value, use [func@Pango.AttrList.from_string].

    Note that shape attributes can not be serialized. *)

external splice : t -> t -> int -> int -> unit = "ml_pango_attr_list_splice"
(** This function opens up a hole in @list, fills it
in with attributes from the left, and then merges
@other on top of the hole.

This operation is equivalent to stretching every attribute
that applies at position @pos in @list by an amount @len,
and then calling [method@Pango.AttrList.change] with a copy
of each attribute in @other in sequence (offset in position
by @pos, and limited in length to @len).

This operation proves useful for, for instance, inserting
a pre-edit string in the middle of an edit buffer.

For backwards compatibility, the function behaves differently
when @len is 0. In this case, the attributes from @other are
not imited to @len, and are just overlayed on top of @list.

This mode is useful for merging two lists of attributes together. *)

external ref : t -> t = "ml_pango_attr_list_ref"
(** Increase the reference count of the given attribute list by one. *)

external insert_before : t -> Attribute.t -> unit
  = "ml_pango_attr_list_insert_before"
(** Insert the given attribute into the `PangoAttrList`.

It will be inserted before all other attributes with a
matching @start_index. *)

external insert : t -> Attribute.t -> unit = "ml_pango_attr_list_insert"
(** Insert the given attribute into the `PangoAttrList`.

It will be inserted after all other attributes with a
matching @start_index. *)

external get_iterator : t -> Attr_iterator.t = "ml_pango_attr_list_get_iterator"
(** Create a iterator initialized to the beginning of the list.

@list must not be modified until this iterator is freed. *)

external get_attributes : t -> Attribute.t list
  = "ml_pango_attr_list_get_attributes"
(** Gets a list of all attributes in @list. *)

external equal : t -> t -> bool = "ml_pango_attr_list_equal"
(** Checks whether @list and @other_list contain the same
attributes and whether those attributes apply to the
same ranges.

Beware that this will return wrong values if any list
contains duplicates. *)

external change : t -> Attribute.t -> unit = "ml_pango_attr_list_change"
(** Insert the given attribute into the `PangoAttrList`.

    It will replace any attributes of the same type on that segment and be
    merged with any adjoining attributes that are identical.

    This function is slower than [method@Pango.AttrList.insert] for creating an
    attribute list in order (potentially much slower for large lists). However,
    [method@Pango.AttrList.insert] is not suitable for continually changing a
    set of attributes since it never removes or combines existing attributes. *)
