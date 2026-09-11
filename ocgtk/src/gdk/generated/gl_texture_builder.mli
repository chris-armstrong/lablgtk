(* GENERATED CODE - DO NOT EDIT *)
(* GLTextureBuilder: GLTextureBuilder *)

type t = [ `gl_texture_builder | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_gl_texture_builder_get_type"

external new_ : unit -> t = "ml_gdk_gl_texture_builder_new"
(** Create a new GLTextureBuilder *)

(* Methods *)

external set_width : t -> int -> unit = "ml_gdk_gl_texture_builder_set_width"
(** Sets the width of the texture.

    The width must be set before calling [method@Gdk.GLTextureBuilder.build]. *)

external set_update_texture : t -> Texture.t option -> unit
  = "ml_gdk_gl_texture_builder_set_update_texture"
(** Sets the texture to be updated by this texture. See
    [method@Gdk.GLTextureBuilder.set_update_region] for an explanation. *)

external set_update_region :
  t -> Ocgtk_cairo.Cairo.Wrappers.Region.t option -> unit
  = "ml_gdk_gl_texture_builder_set_update_region"
(** Sets the region to be updated by this texture. Together with
    [property@Gdk.GLTextureBuilder:update-texture] this describes an update of a
    previous texture.

    When rendering animations of large textures, it is possible that consecutive
    textures are only updating contents in parts of the texture. It is then
    possible to describe this update via these two properties, so that GTK can
    avoid rerendering parts that did not change.

    An example would be a screen recording where only the mouse pointer moves.
*)

external set_id : t -> int -> unit = "ml_gdk_gl_texture_builder_set_id"
(** Sets the texture id of the texture. The texture id must remain unmodified
    until the texture was finalized. See [method@Gdk.GLTextureBuilder.build] for
    a longer discussion.

    The id must be set before calling [method@Gdk.GLTextureBuilder.build]. *)

external set_height : t -> int -> unit = "ml_gdk_gl_texture_builder_set_height"
(** Sets the height of the texture.

    The height must be set before calling [method@Gdk.GLTextureBuilder.build].
*)

external set_has_mipmap : t -> bool -> unit
  = "ml_gdk_gl_texture_builder_set_has_mipmap"
(** Sets whether the texture has a mipmap. This allows the renderer and other
    users of the generated texture to use a higher quality downscaling.

    Typically, the `glGenerateMipmap` function is used to generate a mimap. *)

external set_format : t -> Gdk_enums.memoryformat -> unit
  = "ml_gdk_gl_texture_builder_set_format"
(** Sets the format of the texture. The default is
    `GDK_MEMORY_R8G8B8A8_PREMULTIPLIED`.

    The format is the preferred format the texture data should be downloaded to.
    The format must be supported by the GL version of
    [property@Gdk.GLTextureBuilder:context].

    GDK's texture download code assumes that the format corresponds to the
    storage parameters of the GL texture in an obvious way. For example, a
    format of `GDK_MEMORY_R16G16B16A16_PREMULTIPLIED` is expected to be stored
    as `GL_RGBA16` texture, and `GDK_MEMORY_G8A8` is expected to be stored as
    `GL_RG8` texture.

    Setting the right format is particularly useful when using high bit depth
    textures to preserve the bit depth, to set the correct value for
    unpremultiplied textures and to make sure opaque textures are treated as
    such.

    Non-RGBA textures need to have swizzling parameters set up properly to be
    usable in GSK's shaders. *)

external set_context :
  t -> App_launch_context_cycle_de440b34.Gl_context.t option -> unit
  = "ml_gdk_gl_texture_builder_set_context"
(** Sets the context to be used for the texture. This is the context that owns
    the texture.

    The context must be set before calling [method@Gdk.GLTextureBuilder.build].
*)

external set_color_state :
  t -> Cicp_params_and__color_state.Color_state.t -> unit
  = "ml_gdk_gl_texture_builder_set_color_state"
(** Sets the color state for the texture.

    By default, the sRGB colorstate is used. If you don't know what colorstates
    are, this is probably the right thing. *)

external get_width : t -> int = "ml_gdk_gl_texture_builder_get_width"
(** Gets the width previously set via gdk_gl_texture_builder_set_width() or 0 if
    the width wasn't set. *)

external get_update_texture : t -> Texture.t option
  = "ml_gdk_gl_texture_builder_get_update_texture"
(** Gets the texture previously set via
    gdk_gl_texture_builder_set_update_texture() or %NULL if none was set. *)

external get_update_region : t -> Ocgtk_cairo.Cairo.Wrappers.Region.t option
  = "ml_gdk_gl_texture_builder_get_update_region"
(** Gets the region previously set via
    gdk_gl_texture_builder_set_update_region() or %NULL if none was set. *)

external get_id : t -> int = "ml_gdk_gl_texture_builder_get_id"
(** Gets the texture id previously set via gdk_gl_texture_builder_set_id() or 0
    if the id wasn't set. *)

external get_height : t -> int = "ml_gdk_gl_texture_builder_get_height"
(** Gets the height previously set via gdk_gl_texture_builder_set_height() or 0
    if the height wasn't set. *)

external get_has_mipmap : t -> bool = "ml_gdk_gl_texture_builder_get_has_mipmap"
(** Gets whether the texture has a mipmap. *)

external get_format : t -> Gdk_enums.memoryformat
  = "ml_gdk_gl_texture_builder_get_format"
(** Gets the format previously set via gdk_gl_texture_builder_set_format(). *)

external get_context :
  t -> App_launch_context_cycle_de440b34.Gl_context.t option
  = "ml_gdk_gl_texture_builder_get_context"
(** Gets the context previously set via gdk_gl_texture_builder_set_context() or
    %NULL if none was set. *)

external get_color_state : t -> Cicp_params_and__color_state.Color_state.t
  = "ml_gdk_gl_texture_builder_get_color_state"
(** Gets the color state previously set via
    gdk_gl_texture_builder_set_color_state(). *)

(* Properties *)
