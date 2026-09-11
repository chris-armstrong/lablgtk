(* GENERATED CODE - DO NOT EDIT *)
(* Font: Font *)

type t = [ `font ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_pango_cairo_font_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_pangocairo_font_from_gobject"

(* Methods *)

external get_scaled_font : t -> Ocgtk_cairo.Cairo.Wrappers.Scaled_font.t option
  = "ml_pango_cairo_font_get_scaled_font"
(** Gets the `cairo_scaled_font_t` used by @font.
The scaled font can be referenced and kept using
cairo_scaled_font_reference(). *)
