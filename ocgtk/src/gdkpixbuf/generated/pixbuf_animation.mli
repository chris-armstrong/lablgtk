(* GENERATED CODE - DO NOT EDIT *)
(* PixbufAnimation: PixbufAnimation *)

type t = [ `pixbuf_animation | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gdk_pixbuf_pixbuf_animation_get_type"

external new_from_file : string -> (t, GError.t) result
  = "ml_gdk_pixbuf_animation_new_from_file"
(** Create a new PixbufAnimation *)

external new_from_resource : string -> (t, GError.t) result
  = "ml_gdk_pixbuf_animation_new_from_resource"
(** Create a new PixbufAnimation *)

external new_from_stream :
  Ocgtk_gio.Gio.Wrappers.Input_stream.t ->
  Ocgtk_gio.Gio.Wrappers.Cancellable.t option ->
  (t, GError.t) result = "ml_gdk_pixbuf_animation_new_from_stream"
(** Create a new PixbufAnimation *)

external new_from_stream_finish :
  Ocgtk_gio.Gio.Wrappers.Async_result.t -> (t, GError.t) result
  = "ml_gdk_pixbuf_animation_new_from_stream_finish"
(** Create a new PixbufAnimation *)

(* Methods *)

external is_static_image : t -> bool = "ml_gdk_pixbuf_animation_is_static_image"
(** Checks whether the animation is a static image.

    If you load a file with gdk_pixbuf_animation_new_from_file() and it turns
    out to be a plain, unanimated image, then this function will return `TRUE`.
    Use gdk_pixbuf_animation_get_static_image() to retrieve the image. *)

external get_width : t -> int = "ml_gdk_pixbuf_animation_get_width"
(** Queries the width of the bounding box of a pixbuf animation. *)

external get_static_image : t -> Pixbuf.t
  = "ml_gdk_pixbuf_animation_get_static_image"
(** Retrieves a static image for the animation.

    If an animation is really just a plain image (has only one frame), this
    function returns that image.

    If the animation is an animation, this function returns a reasonable image
    to use as a static unanimated image, which might be the first frame, or
    something more sophisticated depending on the file format.

    If an animation hasn't loaded any frames yet, this function will return
    `NULL`. *)

external get_height : t -> int = "ml_gdk_pixbuf_animation_get_height"
(** Queries the height of the bounding box of a pixbuf animation. *)
