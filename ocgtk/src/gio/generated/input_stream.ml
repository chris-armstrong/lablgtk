(* GENERATED CODE - DO NOT EDIT *)
(* InputStream: InputStream *)

type t = [ `input_stream | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_input_stream_get_type"

(* Methods *)

external skip_finish : t -> Async_result.t -> (int, GError.t) result
  = "ml_g_input_stream_skip_finish"
(** Finishes a stream skip operation. *)

external skip : t -> Gsize.t -> Cancellable.t option -> (int, GError.t) result
  = "ml_g_input_stream_skip"
(** Tries to skip @count bytes from the stream. Will block during the operation.

This is identical to g_input_stream_read(), from a behaviour standpoint,
but the bytes that are skipped are not returned to the user. Some
streams have an implementation that is more efficient than reading the data.

This function is optional for inherited classes, as the default implementation
emulates it using read.

If @cancellable is not %NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. If an
operation was partially finished when the operation was cancelled the
partial result will be returned, without an error. *)

external set_pending : t -> (bool, GError.t) result
  = "ml_g_input_stream_set_pending"
(** Sets @stream to have actions pending. If the pending flag is
already set or @stream is closed, it will return %FALSE and set
@error. *)

external read_finish : t -> Async_result.t -> (int, GError.t) result
  = "ml_g_input_stream_read_finish"
(** Finishes an asynchronous stream read operation. *)

external read_bytes_finish :
  t -> Async_result.t -> (Glib_bytes.t, GError.t) result
  = "ml_g_input_stream_read_bytes_finish"
(** Finishes an asynchronous stream read-into-#GBytes operation. *)

external read_bytes :
  t -> Gsize.t -> Cancellable.t option -> (Glib_bytes.t, GError.t) result
  = "ml_g_input_stream_read_bytes"
(** Like g_input_stream_read(), this tries to read @count bytes from
the stream in a blocking fashion. However, rather than reading into
a user-supplied buffer, this will create a new #GBytes containing
the data that was read. This may be easier to use from language
bindings.

If count is zero, returns a zero-length #GBytes and does nothing. A
value of @count larger than %G_MAXSSIZE will cause a
%G_IO_ERROR_INVALID_ARGUMENT error.

On success, a new #GBytes is returned. It is not an error if the
size of this object is not the same as the requested size, as it
can happen e.g. near the end of a file. A zero-length #GBytes is
returned on end of file (or if @count is zero), but never
otherwise.

If @cancellable is not %NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. If an
operation was partially finished when the operation was cancelled the
partial result will be returned, without an error.

On error %NULL is returned and @error is set accordingly. *)

external read_all_finish :
  t -> Async_result.t -> (bool * Gsize.t, GError.t) result
  = "ml_g_input_stream_read_all_finish"
(** Finishes an asynchronous stream read operation started with
[method@InputStream.read_all_async].

As a special exception to the normal conventions for functions that
use #GError, if this function returns %FALSE (and sets @error) then
@bytes_read will be set to the number of bytes that were successfully
read before the error was encountered.  This functionality is only
available from C.  If you need it from another language then you must
write your own loop around g_input_stream_read_async(). *)

external is_closed : t -> bool = "ml_g_input_stream_is_closed"
(** Checks if an input stream is closed. *)

external has_pending : t -> bool = "ml_g_input_stream_has_pending"
(** Checks if an input stream has pending actions. *)

external close_finish : t -> Async_result.t -> (bool, GError.t) result
  = "ml_g_input_stream_close_finish"
(** Finishes closing a stream asynchronously, started from
    g_input_stream_close_async(). *)

external close : t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_input_stream_close"
(** Closes the stream, releasing resources related to it.

Once the stream is closed, all other operations will return %G_IO_ERROR_CLOSED.
Closing a stream multiple times will not return an error.

Streams will be automatically closed when the last reference
is dropped, but you might want to call this function to make sure
resources are released as early as possible.

Some streams might keep the backing store of the stream (e.g. a file descriptor)
open after the stream is closed. See the documentation for the individual
stream for details.

On failure the first error that happened will be reported, but the close
operation will finish as much as possible. A stream that failed to
close will still return %G_IO_ERROR_CLOSED for all operations. Still, it
is important to check and report the error to the user.

If @cancellable is not %NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned.
Cancelling a close will still leave the stream closed, but some streams
can use a faster close that doesn't block to e.g. check errors. *)

external clear_pending : t -> unit = "ml_g_input_stream_clear_pending"
(** Clears the pending flag on @stream. *)
