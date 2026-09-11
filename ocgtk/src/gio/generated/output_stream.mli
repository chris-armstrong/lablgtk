(* GENERATED CODE - DO NOT EDIT *)
(* OutputStream: OutputStream *)

type t = [ `output_stream | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_output_stream_get_type"

(* Methods *)

external writev_finish :
  t -> Async_result.t -> (bool * Gsize.t, GError.t) result
  = "ml_g_output_stream_writev_finish"
(** Finishes a stream writev operation. *)

external writev_all_finish :
  t -> Async_result.t -> (bool * Gsize.t, GError.t) result
  = "ml_g_output_stream_writev_all_finish"
(** Finishes an asynchronous stream write operation started with
g_output_stream_writev_all_async().

As a special exception to the normal conventions for functions that
use #GError, if this function returns %FALSE (and sets @error) then
@bytes_written will be set to the number of bytes that were
successfully written before the error was encountered.  This
functionality is only available from C.  If you need it from another
language then you must write your own loop around
g_output_stream_writev_async(). *)

external writev_all :
  t ->
  Output_vector.t array ->
  Gsize.t ->
  Cancellable.t option ->
  (bool * Gsize.t, GError.t) result = "ml_g_output_stream_writev_all"
(** Tries to write the bytes contained in the @n_vectors @vectors into the
stream. Will block during the operation.

This function is similar to g_output_stream_writev(), except it tries to
write as many bytes as requested, only stopping on an error.

On a successful write of all @n_vectors vectors, %TRUE is returned, and
@bytes_written is set to the sum of all the sizes of @vectors.

If there is an error during the operation %FALSE is returned and @error
is set to indicate the error status.

As a special exception to the normal conventions for functions that
use #GError, if this function returns %FALSE (and sets @error) then
@bytes_written will be set to the number of bytes that were
successfully written before the error was encountered.  This
functionality is only available from C. If you need it from another
language then you must write your own loop around
g_output_stream_write().

The content of the individual elements of @vectors might be changed by this
function. *)

external writev :
  t ->
  Output_vector.t array ->
  Gsize.t ->
  Cancellable.t option ->
  (bool * Gsize.t, GError.t) result = "ml_g_output_stream_writev"
(** Tries to write the bytes contained in the @n_vectors @vectors into the
stream. Will block during the operation.

If @n_vectors is 0 or the sum of all bytes in @vectors is 0, returns 0 and
does nothing.

On success, the number of bytes written to the stream is returned.
It is not an error if this is not the same as the requested size, as it
can happen e.g. on a partial I/O error, or if there is not enough
storage in the stream. All writes block until at least one byte
is written or an error occurs; 0 is never returned (unless
@n_vectors is 0 or the sum of all bytes in @vectors is 0).

If @cancellable is not %NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. If an
operation was partially finished when the operation was cancelled the
partial result will be returned, without an error.

Some implementations of g_output_stream_writev() may have limitations on the
aggregate buffer size, and will return %G_IO_ERROR_INVALID_ARGUMENT if these
are exceeded. For example, when writing to a local file on UNIX platforms,
the aggregate buffer size must not exceed %G_MAXSSIZE bytes. *)

external write_finish : t -> Async_result.t -> (int, GError.t) result
  = "ml_g_output_stream_write_finish"
(** Finishes a stream write operation. *)

external write_bytes_finish : t -> Async_result.t -> (int, GError.t) result
  = "ml_g_output_stream_write_bytes_finish"
(** Finishes a stream write-from-#GBytes operation. *)

external write_bytes :
  t -> Glib_bytes.t -> Cancellable.t option -> (int, GError.t) result
  = "ml_g_output_stream_write_bytes"
(** A wrapper function for g_output_stream_write() which takes a #GBytes as
    input. This can be more convenient for use by language bindings or in other
    cases where the refcounted nature of #GBytes is helpful over a bare pointer
    interface.

    However, note that this function may still perform partial writes, just like
    g_output_stream_write(). If that occurs, to continue writing, you will need
    to create a new #GBytes containing just the remaining bytes, using
    g_bytes_new_from_bytes(). Passing the same #GBytes instance multiple times
    potentially can result in duplicated data in the output stream. *)

external write_all_finish :
  t -> Async_result.t -> (bool * Gsize.t, GError.t) result
  = "ml_g_output_stream_write_all_finish"
(** Finishes an asynchronous stream write operation started with
g_output_stream_write_all_async().

As a special exception to the normal conventions for functions that
use #GError, if this function returns %FALSE (and sets @error) then
@bytes_written will be set to the number of bytes that were
successfully written before the error was encountered.  This
functionality is only available from C.  If you need it from another
language then you must write your own loop around
g_output_stream_write_async(). *)

external splice_finish : t -> Async_result.t -> (int, GError.t) result
  = "ml_g_output_stream_splice_finish"
(** Finishes an asynchronous stream splice operation. *)

external splice :
  t ->
  Input_stream.t ->
  Gio_enums.outputstreamspliceflags ->
  Cancellable.t option ->
  (int, GError.t) result = "ml_g_output_stream_splice"
(** Splices an input stream into an output stream. *)

external set_pending : t -> (bool, GError.t) result
  = "ml_g_output_stream_set_pending"
(** Sets @stream to have actions pending. If the pending flag is
already set or @stream is closed, it will return %FALSE and set
@error. *)

external is_closing : t -> bool = "ml_g_output_stream_is_closing"
(** Checks if an output stream is being closed. This can be used inside e.g. a
    flush implementation to see if the flush (or other i/o operation) is called
    from within the closing operation. *)

external is_closed : t -> bool = "ml_g_output_stream_is_closed"
(** Checks if an output stream has already been closed. *)

external has_pending : t -> bool = "ml_g_output_stream_has_pending"
(** Checks if an output stream has pending actions. *)

external flush_finish : t -> Async_result.t -> (bool, GError.t) result
  = "ml_g_output_stream_flush_finish"
(** Finishes flushing an output stream. *)

external flush : t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_output_stream_flush"
(** Forces a write of all user-space buffered data for the given
@stream. Will block during the operation. Closing the stream will
implicitly cause a flush.

This function is optional for inherited classes.

If @cancellable is not %NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

external close_finish : t -> Async_result.t -> (bool, GError.t) result
  = "ml_g_output_stream_close_finish"
(** Closes an output stream. *)

external close : t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_output_stream_close"
(** Closes the stream, releasing resources related to it.

Once the stream is closed, all other operations will return %G_IO_ERROR_CLOSED.
Closing a stream multiple times will not return an error.

Closing a stream will automatically flush any outstanding buffers in the
stream.

Streams will be automatically closed when the last reference
is dropped, but you might want to call this function to make sure
resources are released as early as possible.

Some streams might keep the backing store of the stream (e.g. a file descriptor)
open after the stream is closed. See the documentation for the individual
stream for details.

On failure the first error that happened will be reported, but the close
operation will finish as much as possible. A stream that failed to
close will still return %G_IO_ERROR_CLOSED for all operations. Still, it
is important to check and report the error to the user, otherwise
there might be a loss of data as all data might not be written.

If @cancellable is not %NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned.
Cancelling a close will still leave the stream closed, but there some streams
can use a faster close that doesn't block to e.g. check errors. On
cancellation (as with any error) there is no guarantee that all written
data will reach the target. *)

external clear_pending : t -> unit = "ml_g_output_stream_clear_pending"
(** Clears the pending flag on @stream. *)
