(* GENERATED CODE - DO NOT EDIT *)
(* RenderNode: RenderNode *)

type t = [ `render_node ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gsk_render_node_get_type"

(* Methods *)

external write_to_file : t -> string -> (bool, GError.t) result
  = "ml_gsk_render_node_write_to_file"
(** This function is equivalent to calling [method@Gsk.RenderNode.serialize]
    followed by [func@GLib.file_set_contents].

    See those two functions for details on the arguments.

    It is mostly intended for use inside a debugger to quickly dump a render
    node to a file for later inspection. *)

external unref : t -> unit = "ml_gsk_render_node_unref"
(** Releases a reference on the given `GskRenderNode`.

If the reference was the last, the resources associated to the @node are
freed. *)

external serialize : t -> Glib_bytes.t = "ml_gsk_render_node_serialize"
(** Serializes the @node for later deserialization via
gsk_render_node_deserialize(). No guarantees are made about the format
used other than that the same version of GTK will be able to deserialize
the result of a call to gsk_render_node_serialize() and
gsk_render_node_deserialize() will correctly reject files it cannot open
that were created with previous versions of GTK.

The intended use of this functions is testing, benchmarking and debugging.
The format is not meant as a permanent storage format. *)

external ref : t -> t = "ml_gsk_render_node_ref"
(** Acquires a reference on the given `GskRenderNode`. *)

external get_opaque_rect : t -> bool * Ocgtk_graphene.Graphene.Wrappers.Rect.t
  = "ml_gsk_render_node_get_opaque_rect"
(** Gets an opaque rectangle inside the node that GTK can determine to be fully
    opaque.

    There is no guarantee that this is indeed the largest opaque rectangle or
    that regions outside the rectangle are not opaque. This function is a best
    effort with that goal.

    The rectangle will be fully contained in the bounds of the node. *)

external get_node_type : t -> Gsk_enums.rendernodetype
  = "ml_gsk_render_node_get_node_type"
(** Returns the type of the render node. *)

external get_bounds : t -> Ocgtk_graphene.Graphene.Wrappers.Rect.t
  = "ml_gsk_render_node_get_bounds"
(** Retrieves the boundaries of the @node.

The node will not draw outside of its boundaries. *)

external draw : t -> Ocgtk_cairo.Cairo.Wrappers.Context.t -> unit
  = "ml_gsk_render_node_draw"
(** Draws the contents of a render node on a cairo context.

    Typically, you'll use this function to implement fallback rendering of
    render nodes on an intermediate Cairo context, instead of using the drawing
    context associated to a [class@Gdk.Surface]'s rendering buffer.

    For advanced nodes that cannot be supported using Cairo, in particular for
    nodes doing 3D operations, this function may fail. *)
