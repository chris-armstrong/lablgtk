(* GENERATED CODE - DO NOT EDIT *)
(* CairoNode: CairoNode *)

type t = [ `cairo_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_cairo_node_get_type"

external new_ : Ocgtk_graphene.Graphene.Wrappers.Rect.t -> t
  = "ml_gsk_cairo_node_new"
(** Create a new CairoNode *)

(* Methods *)

external get_surface : t -> Ocgtk_cairo.Cairo.Wrappers.Surface.t
  = "ml_gsk_cairo_node_get_surface"
(** Retrieves the Cairo surface used by the render node. *)

external get_draw_context : t -> Ocgtk_cairo.Cairo.Wrappers.Context.t
  = "ml_gsk_cairo_node_get_draw_context"
(** Creates a Cairo context for drawing using the surface associated
to the render node.

If no surface exists yet, a surface will be created optimized for
rendering to @renderer. *)
