(* GENERATED CODE - DO NOT EDIT *)
(* RGBA: RGBA *)

type t = [ `rgb_a ] Gobject.obj
(** Represents a color, in a way that is compatible with cairo’s notion of
    color.

    `GdkRGBA` is a convenient way to pass colors around. It’s based on cairo’s
    way to deal with colors and mirrors its behavior. All values are in the
    range from 0.0 to 1.0 inclusive. So the color (0.0, 0.0, 0.0, 0.0)
    represents transparent black and (1.0, 1.0, 1.0, 1.0) is opaque white. Other
    values will be clamped to this range when drawing. *)

external gtype : unit -> Gobject.Type.t = "ml_gdk_rgb_a_get_type"

(* Methods *)

external to_string : t -> string = "ml_gdk_rgba_to_string"
(** Returns a textual specification of @rgba in the form
`rgb(r,g,b)` or `rgba(r,g,b,a)`, where “r”, “g”, “b” and
“a” represent the red, green, blue and alpha values
respectively. “r”, “g”, and “b” are represented as integers
in the range 0 to 255, and “a” is represented as a floating
point value in the range 0 to 1.

These string forms are string forms that are supported by
the CSS3 colors module, and can be parsed by [method@Gdk.RGBA.parse].

Note that this string representation may lose some precision,
since “r”, “g” and “b” are represented as 8-bit integers. If
this is a concern, you should use a different representation. *)

external parse : t -> string -> bool = "ml_gdk_rgba_parse"
(** Parses a textual representation of a color.

    The string can be either one of:

    - A standard name (Taken from the CSS specification).
    - A hexadecimal value in the form “\#rgb”, “\#rrggbb”, “\#rrrgggbbb” or
      ”\#rrrrggggbbbb”
    - A hexadecimal value in the form “\#rgba”, “\#rrggbbaa”, or
      ”\#rrrrggggbbbbaaaa”
    - A RGB color in the form “rgb(r,g,b)” (In this case the color will have
      full opacity)
    - A RGBA color in the form “rgba(r,g,b,a)”
    - A HSL color in the form "hsl(hue, saturation, lightness)"
    - A HSLA color in the form "hsla(hue, saturation, lightness, alpha)"

    Where “r”, “g”, “b” and “a” are respectively the red, green, blue and alpha
    color values. In the last two cases, “r”, “g”, and “b” are either integers
    in the range 0 to 255 or percentage values in the range 0% to 100%, and a is
    a floating point value in the range 0 to 1. *)

external is_opaque : t -> bool = "ml_gdk_rgba_is_opaque"
(** Checks if an @rgba value is opaque.

That is, drawing with the value will not retain any results
from previous contents. *)

external is_clear : t -> bool = "ml_gdk_rgba_is_clear"
(** Checks if an @rgba value is transparent.

That is, drawing with the value would not produce any change. *)

external hash : t -> int = "ml_gdk_rgba_hash"
(** A hash function suitable for using for a hash table that stores `GdkRGBA`s.
*)

external equal : t -> t -> bool = "ml_gdk_rgba_equal"
(** Compares two `GdkRGBA` colors. *)
