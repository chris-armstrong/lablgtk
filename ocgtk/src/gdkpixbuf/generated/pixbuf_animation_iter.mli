(* GENERATED CODE - DO NOT EDIT *)
(* PixbufAnimationIter: PixbufAnimationIter *)

type t = [ `pixbuf_animation_iter | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gdk_pixbuf_pixbuf_animation_iter_get_type"

(* Methods *)

external on_currently_loading_frame : t -> bool
  = "ml_gdk_pixbuf_animation_iter_on_currently_loading_frame"
(** Used to determine how to respond to the area_updated signal on
    #GdkPixbufLoader when loading an animation.

    The `::area_updated` signal is emitted for an area of the frame currently
    streaming in to the loader. So if you're on the currently loading frame, you
    will need to redraw the screen for the updated area. *)

external get_pixbuf : t -> Pixbuf.t = "ml_gdk_pixbuf_animation_iter_get_pixbuf"
(** Gets the current pixbuf which should be displayed.

    The pixbuf might not be the same size as the animation itself
    (gdk_pixbuf_animation_get_width(), gdk_pixbuf_animation_get_height()).

    This pixbuf should be displayed for
    gdk_pixbuf_animation_iter_get_delay_time() milliseconds.

    The caller of this function does not own a reference to the returned pixbuf;
    the returned pixbuf will become invalid when the iterator advances to the
    next frame, which may happen anytime you call
    gdk_pixbuf_animation_iter_advance().

    Copy the pixbuf to keep it (don't just add a reference), as it may get
    recycled as you advance the iterator. *)

external get_delay_time : t -> int
  = "ml_gdk_pixbuf_animation_iter_get_delay_time"
(** Gets the number of milliseconds the current pixbuf should be displayed, or
    -1 if the current pixbuf should be displayed forever.

    The `g_timeout_add()` function conveniently takes a timeout in milliseconds,
    so you can use a timeout to schedule the next update.

    Note that some formats, like GIF, might clamp the timeout values in the
    image file to avoid updates that are just too quick. The minimum timeout for
    GIF images is currently 20 milliseconds. *)
