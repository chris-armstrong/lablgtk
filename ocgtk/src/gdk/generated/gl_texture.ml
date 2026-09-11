(* GENERATED CODE - DO NOT EDIT *)
(* GLTexture: GLTexture *)

type t = [ `gl_texture | `texture | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_gl_texture_get_type"

(* Methods *)

external release : t -> unit = "ml_gdk_gl_texture_release"
(** Releases the GL resources held by a `GdkGLTexture`.

    The texture contents are still available via the
    [method@Gdk.Texture.download] function, after this function has been called.
*)
