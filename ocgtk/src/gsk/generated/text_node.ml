(* GENERATED CODE - DO NOT EDIT *)
(* TextNode: TextNode *)

type t = [ `text_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_text_node_get_type"

external new_ :
  Ocgtk_pango.Pango.Wrappers.Font.t ->
  Ocgtk_pango.Pango.Wrappers.Glyph_string.t ->
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t ->
  Ocgtk_graphene.Graphene.Wrappers.Point.t ->
  t = "ml_gsk_text_node_new"
(** Create a new TextNode *)

(* Methods *)

external has_color_glyphs : t -> bool = "ml_gsk_text_node_has_color_glyphs"
(** Checks whether the text @node has color glyphs. *)

external get_offset : t -> Ocgtk_graphene.Graphene.Wrappers.Point.t
  = "ml_gsk_text_node_get_offset"
(** Retrieves the offset applied to the text. *)

external get_num_glyphs : t -> int = "ml_gsk_text_node_get_num_glyphs"
(** Retrieves the number of glyphs in the text node. *)

external get_glyphs : t -> Ocgtk_pango.Pango.Wrappers.Glyph_info.t array * int
  = "ml_gsk_text_node_get_glyphs"
(** Retrieves the glyph information in the @node. *)

external get_font : t -> Ocgtk_pango.Pango.Wrappers.Font.t
  = "ml_gsk_text_node_get_font"
(** Returns the font used by the text @node. *)

external get_color : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t
  = "ml_gsk_text_node_get_color"
(** Retrieves the color used by the text @node.

The value returned by this function will not be correct
if the render node was created for a non-sRGB color. *)
