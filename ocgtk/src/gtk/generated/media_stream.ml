(* GENERATED CODE - DO NOT EDIT *)
(* MediaStream: MediaStream *)

type t = [ `media_stream | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_media_stream_get_type"

(* Methods *)

external update : t -> int64 -> unit = "ml_gtk_media_stream_update"
(** Media stream implementations should regularly call this function to update
    the timestamp reported by the stream.

    It is up to implementations to call this at the frequency they deem
    appropriate.

    The media stream must be prepared when this function is called. *)

external unrealize : t -> Ocgtk_gdk.Gdk.Wrappers.Surface.t -> unit
  = "ml_gtk_media_stream_unrealize"
(** Undoes a previous call to gtk_media_stream_realize().

This causes the stream to release all resources it had
allocated from @surface. *)

external stream_unprepared : t -> unit = "ml_gtk_media_stream_stream_unprepared"
(** Resets a given media stream implementation.

    [method@Gtk.MediaStream.stream_prepared] can then be called again.

    This function will also reset any error state the stream was in. *)

external stream_prepared : t -> bool -> bool -> bool -> int64 -> unit
  = "ml_gtk_media_stream_stream_prepared"
(** Called by `GtkMediaStream` implementations to advertise the stream being
    ready to play and providing details about the stream.

    Note that the arguments are hints. If the stream implementation cannot
    determine the correct values, it is better to err on the side of caution and
    return %TRUE. User interfaces will use those values to determine what
    controls to show.

    This function may not be called again until the stream has been reset via
    [method@Gtk.MediaStream.stream_unprepared]. *)

external stream_ended : t -> unit = "ml_gtk_media_stream_stream_ended"
(** Pauses the media stream and marks it as ended.

    This is a hint only, calls to [method@Gtk.MediaStream.play] may still
    happen.

    The media stream must be prepared when this function is called. *)

external set_volume : t -> float -> unit = "ml_gtk_media_stream_set_volume"
(** Sets the volume of the audio stream.

This function call will work even if the stream is muted.

The given @volume should range from 0.0 for silence to 1.0
for as loud as possible. Values outside of this range will
be clamped to the nearest value.

If the stream has no audio or is muted, calling this function
will still work but it will not have an immediate audible effect.
When the stream is unmuted, the new volume setting will take effect. *)

external set_playing : t -> bool -> unit = "ml_gtk_media_stream_set_playing"
(** Starts or pauses playback of the stream. *)

external set_muted : t -> bool -> unit = "ml_gtk_media_stream_set_muted"
(** Sets whether the audio stream should be muted.

    Muting a stream will cause no audio to be played, but it does not modify the
    volume. This means that muting and then unmuting the stream will restore the
    volume settings.

    If the stream has no audio, calling this function will still work but it
    will not have an audible effect. *)

external set_loop : t -> bool -> unit = "ml_gtk_media_stream_set_loop"
(** Sets whether the stream should loop.

    In this case, it will attempt to restart playback from the beginning instead
    of stopping at the end.

    Not all streams may support looping, in particular non-seekable streams.
    Those streams will ignore the loop setting and just end. *)

external seek_success : t -> unit = "ml_gtk_media_stream_seek_success"
(** Ends a seek operation started via GtkMediaStream.seek() successfully.

    This function will unset the GtkMediaStream:ended property if it was set.

    See [method@Gtk.MediaStream.seek_failed] for the other way of ending a seek.
*)

external seek_failed : t -> unit = "ml_gtk_media_stream_seek_failed"
(** Ends a seek operation started via GtkMediaStream.seek() as a failure.

    This will not cause an error on the stream and will assume that playback
    continues as if no seek had happened.

    See [method@Gtk.MediaStream.seek_success] for the other way of ending a
    seek. *)

external seek : t -> int64 -> unit = "ml_gtk_media_stream_seek"
(** Start a seek operation on @self to @timestamp.

If @timestamp is out of range, it will be clamped.

Seek operations may not finish instantly. While a
seek operation is in process, the [property@Gtk.MediaStream:seeking]
property will be set.

When calling gtk_media_stream_seek() during an
ongoing seek operation, the new seek will override
any pending seek. *)

external realize : t -> Ocgtk_gdk.Gdk.Wrappers.Surface.t -> unit
  = "ml_gtk_media_stream_realize"
(** Called by users to attach the media stream to a `GdkSurface` they manage.

The stream can then access the resources of @surface for its
rendering purposes. In particular, media streams might want to
create a `GdkGLContext` or sync to the `GdkFrameClock`.

Whoever calls this function is responsible for calling
[method@Gtk.MediaStream.unrealize] before either the stream
or @surface get destroyed.

Multiple calls to this function may happen from different
users of the video, even with the same @surface. Each of these
calls must be followed by its own call to
[method@Gtk.MediaStream.unrealize].

It is not required to call this function to make a media stream work. *)

external play : t -> unit = "ml_gtk_media_stream_play"
(** Starts playing the stream.

    If the stream is in error or already playing, do nothing. *)

external pause : t -> unit = "ml_gtk_media_stream_pause"
(** Pauses playback of the stream.

    If the stream is not playing, do nothing. *)

external is_seeking : t -> bool = "ml_gtk_media_stream_is_seeking"
(** Checks if there is currently a seek operation going on. *)

external is_seekable : t -> bool = "ml_gtk_media_stream_is_seekable"
(** Checks if a stream may be seekable.

    This is meant to be a hint. Streams may not allow seeking even if this
    function returns %TRUE. However, if this function returns %FALSE, streams
    are guaranteed to not be seekable and user interfaces may hide controls that
    allow seeking.

    It is allowed to call [method@Gtk.MediaStream.seek] on a non-seekable
    stream, though it will not do anything. *)

external is_prepared : t -> bool = "ml_gtk_media_stream_is_prepared"
(** Returns whether the stream has finished initializing.

    At this point the existence of audio and video is known. *)

external has_video : t -> bool = "ml_gtk_media_stream_has_video"
(** Returns whether the stream has video. *)

external has_audio : t -> bool = "ml_gtk_media_stream_has_audio"
(** Returns whether the stream has audio. *)

external get_volume : t -> float = "ml_gtk_media_stream_get_volume"
(** Returns the volume of the audio for the stream.

    See [method@Gtk.MediaStream.set_volume] for details. *)

external get_timestamp : t -> int64 = "ml_gtk_media_stream_get_timestamp"
(** Returns the current presentation timestamp in microseconds. *)

external get_playing : t -> bool = "ml_gtk_media_stream_get_playing"
(** Return whether the stream is currently playing. *)

external get_muted : t -> bool = "ml_gtk_media_stream_get_muted"
(** Returns whether the audio for the stream is muted.

    See [method@Gtk.MediaStream.set_muted] for details. *)

external get_loop : t -> bool = "ml_gtk_media_stream_get_loop"
(** Returns whether the stream is set to loop.

    See [method@Gtk.MediaStream.set_loop] for details. *)

external get_error : t -> GError.t option = "ml_gtk_media_stream_get_error"
(** If the stream is in an error state, returns the `GError` explaining that
    state.

    Any type of error can be reported here depending on the implementation of
    the media stream.

    A media stream in an error cannot be operated on, calls like
    [method@Gtk.MediaStream.play] or [method@Gtk.MediaStream.seek] will not have
    any effect.

    `GtkMediaStream` itself does not provide a way to unset an error, but
    implementations may provide options. For example, a [class@Gtk.MediaFile]
    will unset errors when a new source is set, e.g. with
    [method@Gtk.MediaFile.set_file]. *)

external get_ended : t -> bool = "ml_gtk_media_stream_get_ended"
(** Returns whether the streams playback is finished. *)

external get_duration : t -> int64 = "ml_gtk_media_stream_get_duration"
(** Gets the duration of the stream.

    If the duration is not known, 0 will be returned. *)

external gerror : t -> GError.t -> unit = "ml_gtk_media_stream_gerror"
(** Sets @self into an error state.

This will pause the stream (you can check for an error
via [method@Gtk.MediaStream.get_error] in your
GtkMediaStream.pause() implementation), abort pending
seeks and mark the stream as prepared.

if the stream is already in an error state, this call
will be ignored and the existing error will be retained.

To unset an error, the stream must be reset via a call to
[method@Gtk.MediaStream.unprepared]. *)

(* Properties *)
