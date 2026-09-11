(* GENERATED CODE - DO NOT EDIT *)
(* MediaFile: MediaFile *)

type t = [ `media_file | `media_stream | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_media_file_get_type"

external new_ : unit -> t = "ml_gtk_media_file_new"
(** Create a new MediaFile *)

external new_for_file : Ocgtk_gio.Gio.Wrappers.File.t -> t
  = "ml_gtk_media_file_new_for_file"
(** Create a new MediaFile *)

external new_for_filename : string -> t = "ml_gtk_media_file_new_for_filename"
(** Create a new MediaFile *)

external new_for_input_stream : Ocgtk_gio.Gio.Wrappers.Input_stream.t -> t
  = "ml_gtk_media_file_new_for_input_stream"
(** Create a new MediaFile *)

external new_for_resource : string -> t = "ml_gtk_media_file_new_for_resource"
(** Create a new MediaFile *)

(* Methods *)

external set_resource : t -> string option -> unit
  = "ml_gtk_media_file_set_resource"
(** Sets the `GtkMediaFile` to play the given resource.

This is a utility function that converts the given @resource_path
to a `GFile` and calls [method@Gtk.MediaFile.set_file]. *)

external set_input_stream :
  t -> Ocgtk_gio.Gio.Wrappers.Input_stream.t option -> unit
  = "ml_gtk_media_file_set_input_stream"
(** Sets the `GtkMediaFile` to play the given stream.

If anything is still playing, stop playing it.

Full control about the @stream is assumed for the duration of
playback. The stream will not be closed. *)

external set_filename : t -> string option -> unit
  = "ml_gtk_media_file_set_filename"
(** Sets the `GtkMediaFile` to play the given file.

This is a utility function that converts the given @filename
to a `GFile` and calls [method@Gtk.MediaFile.set_file]. *)

external set_file : t -> Ocgtk_gio.Gio.Wrappers.File.t option -> unit
  = "ml_gtk_media_file_set_file"
(** Sets the `GtkMediaFile` to play the given file.

    If any file is still playing, stop playing it. *)

external get_input_stream : t -> Ocgtk_gio.Gio.Wrappers.Input_stream.t option
  = "ml_gtk_media_file_get_input_stream"
(** Returns the stream that @self is currently playing from.

When @self is not playing or not playing from a stream,
%NULL is returned. *)

external get_file : t -> Ocgtk_gio.Gio.Wrappers.File.t option
  = "ml_gtk_media_file_get_file"
(** Returns the file that @self is currently playing from.

When @self is not playing or not playing from a file,
%NULL is returned. *)

external clear : t -> unit = "ml_gtk_media_file_clear"
(** Resets the media file to be empty. *)

(* Properties *)
