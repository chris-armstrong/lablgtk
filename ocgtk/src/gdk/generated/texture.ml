(* GENERATED CODE - DO NOT EDIT *)
(* Texture: Texture *)

type t = [ `texture | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_texture_get_type"

external new_for_pixbuf : Ocgtk_gdkpixbuf.GdkPixbuf.Wrappers.Pixbuf.t -> t
  = "ml_gdk_texture_new_for_pixbuf"
(** Create a new Texture *)

external new_from_bytes : Glib_bytes.t -> (t, GError.t) result
  = "ml_gdk_texture_new_from_bytes"
(** Create a new Texture *)

external new_from_file : Ocgtk_gio.Gio.Wrappers.File.t -> (t, GError.t) result
  = "ml_gdk_texture_new_from_file"
(** Create a new Texture *)

external new_from_filename : string -> (t, GError.t) result
  = "ml_gdk_texture_new_from_filename"
(** Create a new Texture *)

external new_from_resource : string -> t = "ml_gdk_texture_new_from_resource"
(** Create a new Texture *)

(* Methods *)

external save_to_tiff_bytes : t -> Glib_bytes.t
  = "ml_gdk_texture_save_to_tiff_bytes"
(** Store the given @texture in memory as a TIFF file.

Use [ctor@Gdk.Texture.new_from_bytes] to read it back.

This function is intended to store a representation of the
texture's data that is as accurate as possible. This is
particularly relevant when working with high dynamic range
images and floating-point texture data.

If that is not your concern and you are interested in a
smaller size and a more portable format, you might want to
use [method@Gdk.Texture.save_to_png_bytes]. *)

external save_to_tiff : t -> string -> bool = "ml_gdk_texture_save_to_tiff"
(** Store the given @texture to the @filename as a TIFF file.

GTK will attempt to store data without loss. *)

external save_to_png_bytes : t -> Glib_bytes.t
  = "ml_gdk_texture_save_to_png_bytes"
(** Store the given @texture in memory as a PNG file.

Use [ctor@Gdk.Texture.new_from_bytes] to read it back.

If you want to serialize a texture, this is a convenient and
portable way to do that.

If you need more control over the generated image, such as
attaching metadata, you should look into an image handling
library such as the libglycin library.

If you are dealing with high dynamic range float data, you
might also want to consider [method@Gdk.Texture.save_to_tiff_bytes]
instead. *)

external save_to_png : t -> string -> bool = "ml_gdk_texture_save_to_png"
(** Store the given @texture to the @filename as a PNG file.

This is a utility function intended for debugging and testing.
If you want more control over formats, proper error handling or
want to store to a [iface@Gio.File] or other location, you might
want to use [method@Gdk.Texture.save_to_png_bytes] or look into
the libglycin library. *)

external get_width : t -> int = "ml_gdk_texture_get_width"
(** Returns the width of @texture, in pixels. *)

external get_height : t -> int = "ml_gdk_texture_get_height"
(** Returns the height of the @texture, in pixels. *)

external get_format : t -> Gdk_enums.memoryformat = "ml_gdk_texture_get_format"
(** Gets the memory format most closely associated with the data of the texture.

    Note that it may not be an exact match for texture data stored on the GPU or
    with compression.

    The format can give an indication about the bit depth and opacity of the
    texture and is useful to determine the best format for downloading the
    texture. *)

external get_color_state : t -> Cicp_params_and__color_state.Color_state.t
  = "ml_gdk_texture_get_color_state"
(** Returns the color state associated with the texture. *)

(* Properties *)
