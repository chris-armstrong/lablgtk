(* GENERATED CODE - DO NOT EDIT *)
(* TabArray: TabArray *)

type t = [ `tab_array ] Gobject.obj
(** A `PangoTabArray` contains an array of tab stops.

    `PangoTabArray` can be used to set tab stops in a `PangoLayout`. Each tab
    stop has an alignment, a position, and optionally a character to use as
    decimal point. *)

external gtype : unit -> Gobject.Type.t = "ml_pango_tab_array_get_type"

external new_ : int -> bool -> t = "ml_pango_tab_array_new"
(** Create a new TabArray *)

(* Methods *)

external to_string : t -> string = "ml_pango_tab_array_to_string"
(** Serializes a `PangoTabArray` to a string.

    In the resulting string, serialized tabs are separated by newlines or
    commas.

    Individual tabs are serialized to a string of the form

    [ALIGNMENT:]POSITION[:DECIMAL_POINT]

    Where ALIGNMENT is one of _left_, _right_, _center_ or _decimal_, and
    POSITION is the position of the tab, optionally followed by the unit _px_.
    If ALIGNMENT is omitted, it defaults to _left_. If ALIGNMENT is _decimal_,
    the DECIMAL_POINT character may be specified as a Unicode codepoint.

    Note that all tabs in the array must use the same unit.

    A typical example:

    100px 200px center:300px right:400px *)

external sort : t -> unit = "ml_pango_tab_array_sort"
(** Utility function to ensure that the tab stops are in increasing order. *)

external set_tab : t -> int -> Pango_enums.tabalign -> int -> unit
  = "ml_pango_tab_array_set_tab"
(** Sets the alignment and location of a tab stop. *)

external set_positions_in_pixels : t -> bool -> unit
  = "ml_pango_tab_array_set_positions_in_pixels"
(** Sets whether positions in this array are specified in pixels. *)

external set_decimal_point : t -> int -> int -> unit
  = "ml_pango_tab_array_set_decimal_point"
(** Sets the Unicode character to use as decimal point.

    This is only relevant for tabs with %PANGO_TAB_DECIMAL alignment, which
    align content at the first occurrence of the decimal point character.

    By default, Pango uses the decimal point according to the current locale. *)

external resize : t -> int -> unit = "ml_pango_tab_array_resize"
(** Resizes a tab array.

    You must subsequently initialize any tabs that were added as a result of
    growing the array. *)

external get_tab : t -> int -> Pango_enums.tabalign * int
  = "ml_pango_tab_array_get_tab"
(** Gets the alignment and position of a tab stop. *)

external get_size : t -> int = "ml_pango_tab_array_get_size"
(** Gets the number of tab stops in @tab_array. *)

external get_positions_in_pixels : t -> bool
  = "ml_pango_tab_array_get_positions_in_pixels"
(** Returns %TRUE if the tab positions are in pixels, %FALSE if they are in
    Pango units. *)

external get_decimal_point : t -> int -> int
  = "ml_pango_tab_array_get_decimal_point"
(** Gets the Unicode character to use as decimal point.

    This is only relevant for tabs with %PANGO_TAB_DECIMAL alignment, which
    align content at the first occurrence of the decimal point character.

    The default value of 0 means that Pango will use the decimal point according
    to the current locale. *)
