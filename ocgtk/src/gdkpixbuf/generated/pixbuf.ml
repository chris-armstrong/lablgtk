(* GENERATED CODE - DO NOT EDIT *)
(* Pixbuf: Pixbuf *)

type t = [ `pixbuf | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_pixbuf_pixbuf_get_type"

external new_ : Gdkpixbuf_enums.colorspace -> bool -> int -> int -> int -> t
  = "ml_gdk_pixbuf_new"
(** Create a new Pixbuf *)

external new_from_bytes :
  Glib_bytes.t ->
  Gdkpixbuf_enums.colorspace ->
  bool ->
  int ->
  int ->
  int ->
  int ->
  t
  = "ml_gdk_pixbuf_new_from_bytes_bytecode"
    "ml_gdk_pixbuf_new_from_bytes_native"
(** Create a new Pixbuf *)

external new_from_file : string -> (t, GError.t) result
  = "ml_gdk_pixbuf_new_from_file"
(** Create a new Pixbuf *)

external new_from_file_at_scale :
  string -> int -> int -> bool -> (t, GError.t) result
  = "ml_gdk_pixbuf_new_from_file_at_scale"
(** Create a new Pixbuf *)

external new_from_file_at_size : string -> int -> int -> (t, GError.t) result
  = "ml_gdk_pixbuf_new_from_file_at_size"
(** Create a new Pixbuf *)

external new_from_resource : string -> (t, GError.t) result
  = "ml_gdk_pixbuf_new_from_resource"
(** Create a new Pixbuf *)

external new_from_resource_at_scale :
  string -> int -> int -> bool -> (t, GError.t) result
  = "ml_gdk_pixbuf_new_from_resource_at_scale"
(** Create a new Pixbuf *)

external new_from_stream :
  Ocgtk_gio.Gio.Wrappers.Input_stream.t ->
  Ocgtk_gio.Gio.Wrappers.Cancellable.t option ->
  (t, GError.t) result = "ml_gdk_pixbuf_new_from_stream"
(** Create a new Pixbuf *)

external new_from_stream_at_scale :
  Ocgtk_gio.Gio.Wrappers.Input_stream.t ->
  int ->
  int ->
  bool ->
  Ocgtk_gio.Gio.Wrappers.Cancellable.t option ->
  (t, GError.t) result = "ml_gdk_pixbuf_new_from_stream_at_scale"
(** Create a new Pixbuf *)

external new_from_stream_finish :
  Ocgtk_gio.Gio.Wrappers.Async_result.t -> (t, GError.t) result
  = "ml_gdk_pixbuf_new_from_stream_finish"
(** Create a new Pixbuf *)

external new_from_xpm_data : string array -> t
  = "ml_gdk_pixbuf_new_from_xpm_data"
(** Create a new Pixbuf *)

(* Methods *)

external set_option : t -> string -> string -> bool = "ml_gdk_pixbuf_set_option"
(** Attaches a key/value pair as an option to a `GdkPixbuf`.

    If `key` already exists in the list of options attached to the `pixbuf`, the
    new value is ignored and `FALSE` is returned. *)

external scale_simple :
  t -> int -> int -> Gdkpixbuf_enums.interptype -> t option
  = "ml_gdk_pixbuf_scale_simple"
(** Create a new pixbuf containing a copy of `src` scaled to `dest_width` x
    `dest_height`.

    This function leaves `src` unaffected.

    The `interp_type` should be `GDK_INTERP_NEAREST` if you want maximum speed
    (but when scaling down `GDK_INTERP_NEAREST` is usually unusably ugly). The
    default `interp_type` should be `GDK_INTERP_BILINEAR` which offers
    reasonable quality and speed.

    You can scale a sub-portion of `src` by creating a sub-pixbuf pointing into
    `src`; see [method@GdkPixbuf.Pixbuf.new_subpixbuf].

    If `dest_width` and `dest_height` are equal to the width and height of
    `src`, this function will return an unscaled copy of `src`.

    For more complicated scaling/alpha blending see
    [method@GdkPixbuf.Pixbuf.scale] and [method@GdkPixbuf.Pixbuf.composite]. *)

external scale :
  t ->
  t ->
  int ->
  int ->
  int ->
  int ->
  float ->
  float ->
  float ->
  float ->
  Gdkpixbuf_enums.interptype ->
  unit = "ml_gdk_pixbuf_scale_bytecode" "ml_gdk_pixbuf_scale_native"
(** Creates a transformation of the source image @src by scaling by
@scale_x and @scale_y then translating by @offset_x and @offset_y,
then renders the rectangle (@dest_x, @dest_y, @dest_width,
@dest_height) of the resulting image onto the destination image
replacing the previous contents.

Try to use gdk_pixbuf_scale_simple() first; this function is
the industrial-strength power tool you can fall back to, if
gdk_pixbuf_scale_simple() isn't powerful enough.

If the source rectangle overlaps the destination rectangle on the
same pixbuf, it will be overwritten during the scaling which
results in rendering artifacts. *)

external savev :
  t ->
  string ->
  string ->
  string array option ->
  string array option ->
  (bool, GError.t) result = "ml_gdk_pixbuf_savev"
(** Vector version of `gdk_pixbuf_save()`.

Saves pixbuf to a file in `type`, which is currently "jpeg", "png", "tiff", "ico" or "bmp".

If @error is set, `FALSE` will be returned.

See [method@GdkPixbuf.Pixbuf.save] for more details. *)

external save_to_streamv :
  t ->
  Ocgtk_gio.Gio.Wrappers.Output_stream.t ->
  string ->
  string array option ->
  string array option ->
  Ocgtk_gio.Gio.Wrappers.Cancellable.t option ->
  (bool, GError.t) result
  = "ml_gdk_pixbuf_save_to_streamv_bytecode"
    "ml_gdk_pixbuf_save_to_streamv_native"
(** Saves `pixbuf` to an output stream.

    Supported file formats are currently "jpeg", "tiff", "png", "ico" or "bmp".

    See [method@GdkPixbuf.Pixbuf.save_to_stream] for more details. *)

external saturate_and_pixelate : t -> t -> float -> bool -> unit
  = "ml_gdk_pixbuf_saturate_and_pixelate"
(** Modifies saturation and optionally pixelates `src`, placing the result in
    `dest`.

    The `src` and `dest` pixbufs must have the same image format, size, and
    rowstride.

    The `src` and `dest` arguments may be the same pixbuf with no ill effects.

    If `saturation` is 1.0 then saturation is not changed. If it's less than
    1.0, saturation is reduced (the image turns toward grayscale); if greater
    than 1.0, saturation is increased (the image gets more vivid colors).

    If `pixelate` is `TRUE`, then pixels are faded in a checkerboard pattern to
    create a pixelated image. *)

external rotate_simple : t -> Gdkpixbuf_enums.pixbufrotation -> t option
  = "ml_gdk_pixbuf_rotate_simple"
(** Rotates a pixbuf by a multiple of 90 degrees, and returns the result in a
    new pixbuf.

    If `angle` is 0, this function will return a copy of `src`. *)

external remove_option : t -> string -> bool = "ml_gdk_pixbuf_remove_option"
(** Removes the key/value pair option attached to a `GdkPixbuf`. *)

external read_pixel_bytes : t -> Glib_bytes.t = "ml_gdk_pixbuf_read_pixel_bytes"
(** Provides a #GBytes buffer containing the raw pixel data; the data must not
    be modified.

    This function allows skipping the implicit copy that must be made if
    gdk_pixbuf_get_pixels() is called on a read-only pixbuf. *)

external new_subpixbuf : t -> int -> int -> int -> int -> t
  = "ml_gdk_pixbuf_new_subpixbuf"
(** Creates a new pixbuf which represents a sub-region of `src_pixbuf`.

    The new pixbuf shares its pixels with the original pixbuf, so writing to one
    affects both. The new pixbuf holds a reference to `src_pixbuf`, so
    `src_pixbuf` will not be finalized until the new pixbuf is finalized.

    Note that if `src_pixbuf` is read-only, this function will force it to be
    mutable. *)

external get_width : t -> int = "ml_gdk_pixbuf_get_width"
(** Queries the width of a pixbuf. *)

external get_rowstride : t -> int = "ml_gdk_pixbuf_get_rowstride"
(** Queries the rowstride of a pixbuf, which is the number of bytes between the
    start of a row and the start of the next row. *)

external get_option : t -> string -> string option = "ml_gdk_pixbuf_get_option"
(** Looks up @key in the list of options that may have been attached to the
@pixbuf when it was loaded, or that may have been attached by another
function using gdk_pixbuf_set_option().

For instance, the ANI loader provides "Title" and "Artist" options.
The ICO, XBM, and XPM loaders provide "x_hot" and "y_hot" hot-spot
options for cursor definitions. The PNG loader provides the tEXt ancillary
chunk key/value pairs as options. Since 2.12, the TIFF and JPEG loaders
return an "orientation" option string that corresponds to the embedded
TIFF/Exif orientation tag (if present). Since 2.32, the TIFF loader sets
the "multipage" option string to "yes" when a multi-page TIFF is loaded.
Since 2.32 the JPEG and PNG loaders set "x-dpi" and "y-dpi" if the file
contains image density information in dots per inch.
Since 2.36.6, the JPEG loader sets the "comment" option with the comment
EXIF tag. *)

external get_n_channels : t -> int = "ml_gdk_pixbuf_get_n_channels"
(** Queries the number of channels of a pixbuf. *)

external get_height : t -> int = "ml_gdk_pixbuf_get_height"
(** Queries the height of a pixbuf. *)

external get_has_alpha : t -> bool = "ml_gdk_pixbuf_get_has_alpha"
(** Queries whether a pixbuf has an alpha channel (opacity information). *)

external get_colorspace : t -> Gdkpixbuf_enums.colorspace
  = "ml_gdk_pixbuf_get_colorspace"
(** Queries the color space of a pixbuf. *)

external get_byte_length : t -> Gsize.t = "ml_gdk_pixbuf_get_byte_length"
(** Returns the length of the pixel data, in bytes. *)

external get_bits_per_sample : t -> int = "ml_gdk_pixbuf_get_bits_per_sample"
(** Queries the number of bits per color sample in a pixbuf. *)

external flip : t -> bool -> t option = "ml_gdk_pixbuf_flip"
(** Flips a pixbuf horizontally or vertically and returns the result in a new
    pixbuf. *)

external fill : t -> UInt32.t -> unit = "ml_gdk_pixbuf_fill"
(** Clears a pixbuf to the given RGBA value, converting the RGBA value into the
    pixbuf's pixel format.

    The alpha component will be ignored if the pixbuf doesn't have an alpha
    channel. *)

external copy_options : t -> t -> bool = "ml_gdk_pixbuf_copy_options"
(** Copies the key/value pair options attached to a `GdkPixbuf` to another
    `GdkPixbuf`.

    This is useful to keep original metadata after having manipulated a file.
    However be careful to remove metadata which you've already applied, such as
    the "orientation" option after rotating the image. *)

external copy_area : t -> int -> int -> int -> int -> t -> int -> int -> unit
  = "ml_gdk_pixbuf_copy_area_bytecode" "ml_gdk_pixbuf_copy_area_native"
(** Copies a rectangular area from `src_pixbuf` to `dest_pixbuf`.

    Conversion of pixbuf formats is done automatically.

    If the source rectangle overlaps the destination rectangle on the same
    pixbuf, it will be overwritten during the copy operation. Therefore, you can
    not use this function to scroll a pixbuf. *)

external copy : t -> t option = "ml_gdk_pixbuf_copy"
(** Creates a new `GdkPixbuf` with a copy of the information in the specified
    `pixbuf`.

    Note that this does not copy the options set on the original `GdkPixbuf`,
    use gdk_pixbuf_copy_options() for this. *)

external composite_color_simple :
  t ->
  int ->
  int ->
  Gdkpixbuf_enums.interptype ->
  int ->
  int ->
  UInt32.t ->
  UInt32.t ->
  t option
  = "ml_gdk_pixbuf_composite_color_simple_bytecode"
    "ml_gdk_pixbuf_composite_color_simple_native"
(** Creates a new pixbuf by scaling `src` to `dest_width` x `dest_height` and
    alpha blending the result with a checkboard of colors `color1` and `color2`.
*)

external composite_color :
  t ->
  t ->
  int ->
  int ->
  int ->
  int ->
  float ->
  float ->
  float ->
  float ->
  Gdkpixbuf_enums.interptype ->
  int ->
  int ->
  int ->
  int ->
  UInt32.t ->
  UInt32.t ->
  unit
  = "ml_gdk_pixbuf_composite_color_bytecode"
    "ml_gdk_pixbuf_composite_color_native"
(** Creates a transformation of the source image @src by scaling by
@scale_x and @scale_y then translating by @offset_x and @offset_y,
then alpha blends the rectangle (@dest_x ,@dest_y, @dest_width,
@dest_height) of the resulting image with a checkboard of the
colors @color1 and @color2 and renders it onto the destination
image.

If the source image has no alpha channel, and @overall_alpha is 255, a fast
path is used which omits the alpha blending and just performs the scaling.

See gdk_pixbuf_composite_color_simple() for a simpler variant of this
function suitable for many tasks. *)

external composite :
  t ->
  t ->
  int ->
  int ->
  int ->
  int ->
  float ->
  float ->
  float ->
  float ->
  Gdkpixbuf_enums.interptype ->
  int ->
  unit = "ml_gdk_pixbuf_composite_bytecode" "ml_gdk_pixbuf_composite_native"
(** Creates a transformation of the source image @src by scaling by
@scale_x and @scale_y then translating by @offset_x and @offset_y.

This gives an image in the coordinates of the destination pixbuf.
The rectangle (@dest_x, @dest_y, @dest_width, @dest_height)
is then alpha blended onto the corresponding rectangle of the
original destination image.

When the destination rectangle contains parts not in the source
image, the data at the edges of the source image is replicated
to infinity.

![](composite.png) *)

external apply_embedded_orientation : t -> t option
  = "ml_gdk_pixbuf_apply_embedded_orientation"
(** Takes an existing pixbuf and checks for the presence of an associated
    "orientation" option.

    The orientation option may be provided by the JPEG loader (which reads the
    exif orientation tag) or the TIFF loader (which reads the TIFF orientation
    tag, and compensates it for the partial transforms performed by libtiff).

    If an orientation option/tag is present, the appropriate transform will be
    performed so that the pixbuf is oriented correctly. *)

(* Properties *)

external get_pixel_bytes : t -> Glib_bytes.t = "ml_gdk_pixbuf_get_pixel_bytes"
(** Get property: pixel-bytes *)
