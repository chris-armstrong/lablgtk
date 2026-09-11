(* GENERATED CODE - DO NOT EDIT *)
(* TextureDownloader: TextureDownloader *)

type t = [ `texture_downloader ] Gobject.obj
(** Used to download the contents of a [class@Gdk.Texture].

    It is intended to be created as a short-term object for a single download,
    but can be used for multiple downloads of different textures or with
    different settings.

    `GdkTextureDownloader` can be used to convert data between different
    formats. Create a `GdkTexture` for the existing format and then download it
    in a different format. *)

external gtype : unit -> Gobject.Type.t = "ml_gdk_texture_downloader_get_type"

external new_ : Texture.t -> t = "ml_gdk_texture_downloader_new"
(** Create a new TextureDownloader *)

(* Methods *)

external set_texture : t -> Texture.t -> unit
  = "ml_gdk_texture_downloader_set_texture"
(** Changes the texture the downloader will download. *)

external set_format : t -> Gdk_enums.memoryformat -> unit
  = "ml_gdk_texture_downloader_set_format"
(** Sets the format the downloader will download.

    By default, GDK_MEMORY_DEFAULT is set. *)

external set_color_state :
  t -> Cicp_params_and__color_state.Color_state.t -> unit
  = "ml_gdk_texture_downloader_set_color_state"
(** Sets the color state the downloader will convert the data to.

    By default, the sRGB colorstate returned by [func@ColorState.get_srgb] is
    used. *)

external get_texture : t -> Texture.t = "ml_gdk_texture_downloader_get_texture"
(** Gets the texture that the downloader will download. *)

external get_format : t -> Gdk_enums.memoryformat
  = "ml_gdk_texture_downloader_get_format"
(** Gets the format that the data will be downloaded in. *)

external get_color_state : t -> Cicp_params_and__color_state.Color_state.t
  = "ml_gdk_texture_downloader_get_color_state"
(** Gets the color state that the data will be downloaded in. *)

external download_bytes_with_planes :
  t -> Glib_bytes.t * Gsize.t array * Gsize.t array
  = "ml_gdk_texture_downloader_download_bytes_with_planes"
(** Downloads the given texture pixels into a `GBytes`. The offsets and strides
    of the resulting buffer will be stored in the respective values.

    If the format does have less than 4 planes, the remaining offsets and
    strides will be set to `0`. *)

external download_bytes : t -> Glib_bytes.t * Gsize.t
  = "ml_gdk_texture_downloader_download_bytes"
(** Downloads the given texture pixels into a `GBytes`. The rowstride will be
    stored in the stride value.

    This function will abort if it tries to download a large texture and fails
    to allocate memory. If you think that may happen, you should handle memory
    allocation yourself and use [method@Gdk.TextureDownloader.download_into]
    once allocation succeeded.

    This function cannot be used with a multiplanar format. Use
    [method@Gdk.TextureDownloader.download_bytes_with_planes] for that purpose.
*)
