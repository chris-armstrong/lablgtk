(* GENERATED CODE - DO NOT EDIT *)
(* Color: Color *)

type t = [ `color ] Gobject.obj
(** The `PangoColor` structure is used to represent a color in an uncalibrated
    RGB color-space. *)

external gtype : unit -> Gobject.Type.t = "ml_pango_color_get_type"

(* Methods *)

external to_string : t -> string = "ml_pango_color_to_string"
(** Returns a textual specification of @color.

The string is in the hexadecimal form `#rrrrggggbbbb`,
where `r`, `g` and `b` are hex digits representing the
red, green, and blue components respectively. *)

external parse_with_alpha : t -> string -> bool * UInt16.t
  = "ml_pango_color_parse_with_alpha"
(** Fill in the fields of a color from a string specification.

The string can either one of a large set of standard names.
(Taken from the CSS Color [specification](https://www.w3.org/TR/css-color-4/#named-colors),
or it can be a hexadecimal value in the form `#rgb`,
`#rrggbb`, `#rrrgggbbb` or `#rrrrggggbbbb` where `r`, `g`
and `b` are hex digits of the red, green, and blue components
of the color, respectively. (White in the four forms is
`#fff`, `#ffffff`, `#fffffffff` and `#ffffffffffff`.)

Additionally, parse strings of the form `#rgba`, `#rrggbbaa`,
`#rrrrggggbbbbaaaa`, if @alpha is not %NULL, and set @alpha
to the value specified by the hex digits for `a`. If no alpha
component is found in @spec, @alpha is set to 0xffff (for a
solid color). *)

external parse : t -> string -> bool = "ml_pango_color_parse"
(** Fill in the fields of a color from a string specification.

    The string can either one of a large set of standard names. (Taken from the
    CSS Color [specification](https://www.w3.org/TR/css-color-4/#named-colors),
    or it can be a value in the form `#rgb`, `#rrggbb`, `#rrrgggbbb` or
    `#rrrrggggbbbb`, where `r`, `g` and `b` are hex digits of the red, green,
    and blue components of the color, respectively. (White in the four forms is
    `#fff`, `#ffffff`, `#fffffffff` and `#ffffffffffff`.) *)
