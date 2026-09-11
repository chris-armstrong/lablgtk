(* GENERATED CODE - DO NOT EDIT *)
(* IOStream: IOStream *)

type t = [ `io_stream | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_io_stream_get_type"

(* Methods *)

external set_pending : t -> (bool, GError.t) result
  = "ml_g_io_stream_set_pending"
(** Sets @stream to have actions pending. If the pending flag is
already set or @stream is closed, it will return %FALSE and set
@error. *)

external is_closed : t -> bool = "ml_g_io_stream_is_closed"
(** Checks if a stream is closed. *)

external has_pending : t -> bool = "ml_g_io_stream_has_pending"
(** Checks if a stream has pending actions. *)

external get_output_stream : t -> Output_stream.t
  = "ml_g_io_stream_get_output_stream"
(** Gets the output stream for this object. This is used for writing. *)

external get_input_stream : t -> Input_stream.t
  = "ml_g_io_stream_get_input_stream"
(** Gets the input stream for this object. This is used for reading. *)

external close_finish : t -> Async_result.t -> (bool, GError.t) result
  = "ml_g_io_stream_close_finish"
(** Closes a stream. *)

external close : t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_io_stream_close"
(** Closes the stream, releasing resources related to it. This will also
close the individual input and output streams, if they are not already
closed.

Once the stream is closed, all other operations will return
%G_IO_ERROR_CLOSED. Closing a stream multiple times will not
return an error.

Closing a stream will automatically flush any outstanding buffers
in the stream.

Streams will be automatically closed when the last reference
is dropped, but you might want to call this function to make sure
resources are released as early as possible.

Some streams might keep the backing store of the stream (e.g. a file
descriptor) open after the stream is closed. See the documentation for
the individual stream for details.

On failure the first error that happened will be reported, but the
close operation will finish as much as possible. A stream that failed
to close will still return %G_IO_ERROR_CLOSED for all operations.
Still, it is important to check and report the error to the user,
otherwise there might be a loss of data as all data might not be written.

If @cancellable is not NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned.
Cancelling a close will still leave the stream closed, but some streams
can use a faster close that doesn't block to e.g. check errors.

The default implementation of this method just calls close on the
individual input/output streams. *)

external clear_pending : t -> unit = "ml_g_io_stream_clear_pending"
(** Clears the pending flag on @stream. *)

(* Properties *)
