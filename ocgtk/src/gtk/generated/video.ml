(* GENERATED CODE - DO NOT EDIT *)
(* Video: Video *)

type t = [ `video | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_video_get_type"

external new_ : unit -> t = "ml_gtk_video_new"
(** Create a new Video *)

external new_for_file : Ocgtk_gio.Gio.Wrappers.File.t option -> t
  = "ml_gtk_video_new_for_file"
(** Create a new Video *)

external new_for_filename : string option -> t = "ml_gtk_video_new_for_filename"
(** Create a new Video *)

external new_for_media_stream : Media_stream.t option -> t
  = "ml_gtk_video_new_for_media_stream"
(** Create a new Video *)

external new_for_resource : string option -> t = "ml_gtk_video_new_for_resource"
(** Create a new Video *)

(* Methods *)

external set_resource : t -> string option -> unit = "ml_gtk_video_set_resource"
(** Makes @self play the resource at the given @resource_path.

This is a utility function that calls [method@Gtk.Video.set_file]. *)

external set_media_stream : t -> Media_stream.t option -> unit
  = "ml_gtk_video_set_media_stream"
(** Sets the media stream to be played back.

@self will take full control of managing the media stream. If you
want to manage a media stream yourself, consider using a
[class@Gtk.Picture] for display.

If you want to display a file, consider using [method@Gtk.Video.set_file]
instead. *)

external set_loop : t -> bool -> unit = "ml_gtk_video_set_loop"
(** Sets whether new files loaded by @self should be set to loop. *)

external set_graphics_offload : t -> Gtk_enums.graphicsoffloadenabled -> unit
  = "ml_gtk_video_set_graphics_offload"
(** Sets whether to enable graphics offload.

    See [class@Gtk.GraphicsOffload] for more information on graphics offload. *)

external set_filename : t -> string option -> unit = "ml_gtk_video_set_filename"
(** Makes @self play the given @filename.

This is a utility function that calls gtk_video_set_file(), *)

external set_file : t -> Ocgtk_gio.Gio.Wrappers.File.t option -> unit
  = "ml_gtk_video_set_file"
(** Makes @self play the given @file. *)

external set_autoplay : t -> bool -> unit = "ml_gtk_video_set_autoplay"
(** Sets whether @self automatically starts playback when it
becomes visible or when a new file gets loaded. *)

external get_media_stream : t -> Media_stream.t option
  = "ml_gtk_video_get_media_stream"
(** Gets the media stream managed by @self or %NULL if none. *)

external get_loop : t -> bool = "ml_gtk_video_get_loop"
(** Returns %TRUE if videos have been set to loop. *)

external get_graphics_offload : t -> Gtk_enums.graphicsoffloadenabled
  = "ml_gtk_video_get_graphics_offload"
(** Returns whether graphics offload is enabled.

    See [class@Gtk.GraphicsOffload] for more information on graphics offload. *)

external get_file : t -> Ocgtk_gio.Gio.Wrappers.File.t option
  = "ml_gtk_video_get_file"
(** Gets the file played by @self or %NULL if not playing back
a file. *)

external get_autoplay : t -> bool = "ml_gtk_video_get_autoplay"
(** Returns %TRUE if videos have been set to loop. *)

(* Properties *)
