(* GENERATED CODE - DO NOT EDIT *)
(* PollableOutputStream: PollableOutputStream *)

type t = [ `pollable_output_stream ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_pollable_output_stream_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_pollable_output_stream_from_gobject"

(* Methods *)

external writev_nonblocking :
  t ->
  Output_vector.t array ->
  Gsize.t ->
  Cancellable.t option ->
  (Gio_enums.pollablereturn * Gsize.t, GError.t) result
  = "ml_g_pollable_output_stream_writev_nonblocking"
(** Attempts to write the bytes contained in the @n_vectors @vectors to @stream,
as with g_output_stream_writev(). If @stream is not currently writable,
this will immediately return %@G_POLLABLE_RETURN_WOULD_BLOCK, and you can
use g_pollable_output_stream_create_source() to create a #GSource
that will be triggered when @stream is writable. @error will *not* be
set in that case.

Note that since this method never blocks, you cannot actually
use @cancellable to cancel it. However, it will return an error
if @cancellable has already been cancelled when you call, which
may happen if you call this method after a source triggers due
to having been cancelled.

Also note that if %G_POLLABLE_RETURN_WOULD_BLOCK is returned some underlying
transports like D/TLS require that you re-send the same @vectors and
@n_vectors in the next write call.

The behaviour of this method is undefined if
g_pollable_output_stream_can_poll() returns %FALSE for @stream. *)

external is_writable : t -> bool = "ml_g_pollable_output_stream_is_writable"
(** Checks if @stream can be written.

Note that some stream types may not be able to implement this 100%
reliably, and it is possible that a call to g_output_stream_write()
after this returns %TRUE would still block. To guarantee
non-blocking behavior, you should always use
g_pollable_output_stream_write_nonblocking(), which will return a
%G_IO_ERROR_WOULD_BLOCK error rather than blocking.

The behaviour of this method is undefined if
g_pollable_output_stream_can_poll() returns %FALSE for @stream. *)

external can_poll : t -> bool = "ml_g_pollable_output_stream_can_poll"
(** Checks if @stream is actually pollable. Some classes may implement
#GPollableOutputStream but have only certain instances of that
class be pollable. If this method returns %FALSE, then the behavior
of other #GPollableOutputStream methods is undefined.

For any given stream, the value returned by this method is constant;
a stream cannot switch from pollable to non-pollable or vice versa. *)
