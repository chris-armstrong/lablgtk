(* GENERATED CODE - DO NOT EDIT *)
(* ColorNode: ColorNode *)

type t = [ `color_node | `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_color_node_get_type"

external new_ :
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t -> Ocgtk_graphene.Graphene.Wrappers.Rect.t -> t
  = "ml_gsk_color_node_new"
(** Create a new ColorNode *)

(* Methods *)

external get_color : t -> Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t
  = "ml_gsk_color_node_get_color"
(** Retrieves the color of the given @node.

The value returned by this function will not be correct
if the render node was created for a non-sRGB color. *)
