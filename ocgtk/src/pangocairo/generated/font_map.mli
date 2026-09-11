(* GENERATED CODE - DO NOT EDIT *)
(* FontMap: FontMap *)

type t = [ `font_map ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_pango_cairo_font_map_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_pangocairo_font_map_from_gobject"

(* Methods *)

external set_resolution : t -> float -> unit
  = "ml_pango_cairo_font_map_set_resolution"
(** Sets the resolution for the fontmap.

    This is a scale factor between points specified in a `PangoFontDescription`
    and Cairo units. The default value is 96, meaning that a 10 point font will
    be 13 units high. (10 * 96. / 72. = 13.3). *)

external set_default : t -> unit = "ml_pango_cairo_font_map_set_default"
(** Sets a default `PangoCairoFontMap` to use with Cairo.

This can be used to change the Cairo font backend that the
default fontmap uses for example. The old default font map
is unreffed and the new font map referenced.

Note that since Pango 1.32.6, the default fontmap is per-thread.
This function only changes the default fontmap for
the current thread. Default fontmaps of existing threads
are not changed. Default fontmaps of any new threads will
still be created using [func@PangoCairo.FontMap.new].

A value of %NULL for @fontmap will cause the current default
font map to be released and a new default font map to be created
on demand, using [func@PangoCairo.FontMap.new]. *)

external get_resolution : t -> float = "ml_pango_cairo_font_map_get_resolution"
(** Gets the resolution for the fontmap.

    See [method@PangoCairo.FontMap.set_resolution]. *)

external get_font_type : t -> Ocgtk_cairo.Cairo.fonttype
  = "ml_pango_cairo_font_map_get_font_type"
(** Gets the type of Cairo font backend that @fontmap uses. *)
