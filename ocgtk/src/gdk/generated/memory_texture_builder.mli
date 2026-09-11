(* GENERATED CODE - DO NOT EDIT *)
(* MemoryTextureBuilder: MemoryTextureBuilder *)

type t = [ `memory_texture_builder | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gdk_memory_texture_builder_get_type"

external new_ : unit -> t = "ml_gdk_memory_texture_builder_new"
(** Create a new MemoryTextureBuilder *)

(* Methods *)

external set_width : t -> int -> unit
  = "ml_gdk_memory_texture_builder_set_width"
(** Sets the width of the texture.

    The width must be set before calling [method@Gdk.MemoryTextureBuilder.build]
    and conform to size requirements of the provided format. *)

external set_update_texture : t -> Texture.t option -> unit
  = "ml_gdk_memory_texture_builder_set_update_texture"
(** Sets the texture to be updated by this texture.

    See [method@Gdk.MemoryTextureBuilder.set_update_region] for an explanation.
*)

external set_update_region :
  t -> Ocgtk_cairo.Cairo.Wrappers.Region.t option -> unit
  = "ml_gdk_memory_texture_builder_set_update_region"
(** Sets the region to be updated by this texture.

    Together with [property@Gdk.MemoryTextureBuilder:update-texture], this
    describes an update of a previous texture.

    When rendering animations of large textures, it is possible that consecutive
    textures are only updating contents in parts of the texture. It is then
    possible to describe this update via these two properties, so that GTK can
    avoid rerendering parts that did not change.

    An example would be a screen recording where only the mouse pointer moves.
*)

external set_stride_for_plane : t -> int -> Gsize.t -> unit
  = "ml_gdk_memory_texture_builder_set_stride_for_plane"
(** Sets the stride of the texture for @plane. *)

external set_stride : t -> Gsize.t -> unit
  = "ml_gdk_memory_texture_builder_set_stride"
(** Sets the rowstride of the bytes used.

    The rowstride must be set before calling
    [method@Gdk.MemoryTextureBuilder.build]. *)

external set_offset : t -> int -> Gsize.t -> unit
  = "ml_gdk_memory_texture_builder_set_offset"
(** Sets the offset of the texture for @plane. *)

external set_height : t -> int -> unit
  = "ml_gdk_memory_texture_builder_set_height"
(** Sets the height of the texture.

    The height must be set before calling
    [method@Gdk.MemoryTextureBuilder.build] and conform to size requirements of
    the provided format. *)

external set_format : t -> Gdk_enums.memoryformat -> unit
  = "ml_gdk_memory_texture_builder_set_format"
(** Sets the format of the bytes.

    The default is `GDK_MEMORY_R8G8B8A8_PREMULTIPLIED`. *)

external set_color_state :
  t -> Cicp_params_and__color_state.Color_state.t -> unit
  = "ml_gdk_memory_texture_builder_set_color_state"
(** Sets the colorstate describing the data.

    By default, the sRGB colorstate is used. If you don't know what colorstates
    are, this is probably the right thing. *)

external set_bytes : t -> Glib_bytes.t option -> unit
  = "ml_gdk_memory_texture_builder_set_bytes"
(** Sets the data to be shown but the texture.

    The bytes must be set before calling
    [method@Gdk.MemoryTextureBuilder.build]. *)

external get_width : t -> int = "ml_gdk_memory_texture_builder_get_width"
(** Gets the width previously set via gdk_memory_texture_builder_set_width() or
    0 if the width wasn't set. *)

external get_update_texture : t -> Texture.t option
  = "ml_gdk_memory_texture_builder_get_update_texture"
(** Gets the texture previously set via
    gdk_memory_texture_builder_set_update_texture() or %NULL if none was set. *)

external get_update_region : t -> Ocgtk_cairo.Cairo.Wrappers.Region.t option
  = "ml_gdk_memory_texture_builder_get_update_region"
(** Gets the region previously set via
    gdk_memory_texture_builder_set_update_region() or %NULL if none was set. *)

external get_stride_for_plane : t -> int -> Gsize.t
  = "ml_gdk_memory_texture_builder_get_stride_for_plane"
(** Gets the stride previously set via
    gdk_memory_texture_builder_set_stride_for_plane(). *)

external get_stride : t -> Gsize.t = "ml_gdk_memory_texture_builder_get_stride"
(** Gets the stride previously set via gdk_memory_texture_builder_set_stride().
*)

external get_offset : t -> int -> Gsize.t
  = "ml_gdk_memory_texture_builder_get_offset"
(** Gets the offset previously set via gdk_memory_texture_builder_set_offset().
*)

external get_height : t -> int = "ml_gdk_memory_texture_builder_get_height"
(** Gets the height previously set via gdk_memory_texture_builder_set_height()
    or 0 if the height wasn't set. *)

external get_format : t -> Gdk_enums.memoryformat
  = "ml_gdk_memory_texture_builder_get_format"
(** Gets the format previously set via gdk_memory_texture_builder_set_format().
*)

external get_color_state : t -> Cicp_params_and__color_state.Color_state.t
  = "ml_gdk_memory_texture_builder_get_color_state"
(** Gets the colorstate previously set via
    gdk_memory_texture_builder_set_color_state(). *)

external get_bytes : t -> Glib_bytes.t option
  = "ml_gdk_memory_texture_builder_get_bytes"
(** Gets the bytes previously set via gdk_memory_texture_builder_set_bytes() or
    %NULL if none was set. *)

external build : t -> Texture.t = "ml_gdk_memory_texture_builder_build"
(** Builds a new `GdkTexture` with the values set up in the builder.

    Note that it is a programming error to call this function if any mandatory
    property has not been set.

    It is possible to call this function multiple times to create multiple
    textures, possibly with changing properties in between. *)

(* Properties *)
