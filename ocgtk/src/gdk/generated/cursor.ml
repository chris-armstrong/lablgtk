(* GENERATED CODE - DO NOT EDIT *)
(* Cursor: Cursor *)

type t = [ `cursor | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_cursor_get_type"

external new_from_name : string -> t option -> t = "ml_gdk_cursor_new_from_name"
(** Create a new Cursor *)

external new_from_texture : Texture.t -> int -> int -> t option -> t
  = "ml_gdk_cursor_new_from_texture"
(** Create a new Cursor *)

(* Methods *)

external get_texture : t -> Texture.t option = "ml_gdk_cursor_get_texture"
(** Returns the texture for the cursor.

    If the cursor is a named cursor, %NULL will be returned. *)

external get_name : t -> string option = "ml_gdk_cursor_get_name"
(** Returns the name of the cursor.

    If the cursor is not a named cursor, %NULL will be returned. *)

external get_hotspot_y : t -> int = "ml_gdk_cursor_get_hotspot_y"
(** Returns the vertical offset of the hotspot.

    The hotspot indicates the pixel that will be directly above the cursor.

    Note that named cursors may have a nonzero hotspot, but this function will
    only return the hotspot position for cursors created with
    [ctor@Gdk.Cursor.new_from_texture]. *)

external get_hotspot_x : t -> int = "ml_gdk_cursor_get_hotspot_x"
(** Returns the horizontal offset of the hotspot.

    The hotspot indicates the pixel that will be directly above the cursor.

    Note that named cursors may have a nonzero hotspot, but this function will
    only return the hotspot position for cursors created with
    [ctor@Gdk.Cursor.new_from_texture]. *)

external get_fallback : t -> t option = "ml_gdk_cursor_get_fallback"
(** Returns the fallback for this @cursor.

The fallback will be used if this cursor is not available on a given
`GdkDisplay`. For named cursors, this can happen when using nonstandard
names or when using an incomplete cursor theme. For textured cursors,
this can happen when the texture is too large or when the `GdkDisplay`
it is used on does not support textured cursors. *)

(* Properties *)
