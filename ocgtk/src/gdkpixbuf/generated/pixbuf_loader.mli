(* GENERATED CODE - DO NOT EDIT *)
(* PixbufLoader: PixbufLoader *)

type t = [ `pixbuf_loader | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_pixbuf_pixbuf_loader_get_type"

external new_ : unit -> t = "ml_gdk_pixbuf_loader_new"
(** Create a new PixbufLoader *)

external new_with_mime_type : string -> (t, GError.t) result
  = "ml_gdk_pixbuf_loader_new_with_mime_type"
(** Create a new PixbufLoader *)

external new_with_type : string -> (t, GError.t) result
  = "ml_gdk_pixbuf_loader_new_with_type"
(** Create a new PixbufLoader *)

(* Methods *)

external write_bytes : t -> Glib_bytes.t -> (bool, GError.t) result
  = "ml_gdk_pixbuf_loader_write_bytes"
(** Parses the next contents of the given image buffer. *)

external set_size : t -> int -> int -> unit = "ml_gdk_pixbuf_loader_set_size"
(** Causes the image to be scaled while it is loaded.

    The desired image size can be determined relative to the original size of
    the image by calling gdk_pixbuf_loader_set_size() from a signal handler for
    the ::size-prepared signal.

    Attempts to set the desired image size are ignored after the emission of the
    ::size-prepared signal. *)

external get_pixbuf : t -> Pixbuf.t option = "ml_gdk_pixbuf_loader_get_pixbuf"
(** Queries the #GdkPixbuf that a pixbuf loader is currently creating.

    In general it only makes sense to call this function after the
    [signal@GdkPixbuf.PixbufLoader::area-prepared] signal has been emitted by
    the loader; this means that enough data has been read to know the size of
    the image that will be allocated.

    If the loader has not received enough data via gdk_pixbuf_loader_write(),
    then this function returns `NULL`.

    The returned pixbuf will be the same in all future calls to the loader, so
    if you want to keep using it, you should acquire a reference to it.

    Additionally, if the loader is an animation, it will return the "static
    image" of the animation (see gdk_pixbuf_animation_get_static_image()). *)

external get_format : t -> Pixbuf_format.t option
  = "ml_gdk_pixbuf_loader_get_format"
(** Obtains the available information about the format of the currently loading
    image file. *)

external get_animation : t -> Pixbuf_animation.t option
  = "ml_gdk_pixbuf_loader_get_animation"
(** Queries the #GdkPixbufAnimation that a pixbuf loader is currently creating.

    In general it only makes sense to call this function after the
    [signal@GdkPixbuf.PixbufLoader::area-prepared] signal has been emitted by
    the loader.

    If the loader doesn't have enough bytes yet, and hasn't emitted the
    `area-prepared` signal, this function will return `NULL`. *)

external close : t -> (bool, GError.t) result = "ml_gdk_pixbuf_loader_close"
(** Informs a pixbuf loader that no further writes with
    gdk_pixbuf_loader_write() will occur, so that it can free its internal
    loading structures.

    This function also tries to parse any data that hasn't yet been parsed; if
    the remaining data is partial or corrupt, an error will be returned.

    If `FALSE` is returned, `error` will be set to an error from the
    `GDK_PIXBUF_ERROR` or `G_FILE_ERROR` domains.

    If you're just cancelling a load rather than expecting it to be finished,
    passing `NULL` for `error` to ignore it is reasonable.

    Remember that this function does not release a reference on the loader, so
    you will need to explicitly release any reference you hold. *)

val on_area_prepared :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_area_updated :
  ?after:bool ->
  t ->
  callback:(x:int -> y:int -> width:int -> height:int -> unit) ->
  Gobject.Signal.handler_id

val on_closed :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_size_prepared :
  ?after:bool ->
  t ->
  callback:(width:int -> height:int -> unit) ->
  Gobject.Signal.handler_id
