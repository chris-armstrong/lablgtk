(* GENERATED CODE - DO NOT EDIT *)
(* DatagramBased: DatagramBased *)

type t = [ `datagram_based ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_datagram_based_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_datagram_based_from_gobject"

(* Methods *)

external send_messages :
  t ->
  Output_message.t array ->
  int ->
  int ->
  int64 ->
  Cancellable.t option ->
  (int, GError.t) result
  = "ml_g_datagram_based_send_messages_bytecode"
    "ml_g_datagram_based_send_messages_native"
(** Send one or more data messages from @datagram_based in one go.

@messages must point to an array of #GOutputMessage structs and
@num_messages must be the length of this array. Each #GOutputMessage
contains an address to send the data to, and a pointer to an array of
#GOutputVector structs to describe the buffers that the data to be sent
for each message will be gathered from.

@flags modify how the message is sent. The commonly available arguments
for this are available in the #GSocketMsgFlags enum, but the
values there are the same as the system values, and the flags
are passed in as-is, so you can pass in system-specific flags too.

The other members of #GOutputMessage are treated as described in its
documentation.

If @timeout is negative the call will block until @num_messages have been
sent, @cancellable is cancelled, or an error occurs.

If @timeout is 0 the call will send up to @num_messages without blocking,
or will return %G_IO_ERROR_WOULD_BLOCK if there is no space to send messages.

If @timeout is positive the call will block on the same conditions as if
@timeout were negative. If the timeout is reached before any messages are
sent, %G_IO_ERROR_TIMED_OUT is returned, otherwise it will return the number
of messages sent before timing out.

To be notified when messages can be sent, wait for the %G_IO_OUT condition.
Note though that you may still receive %G_IO_ERROR_WOULD_BLOCK from
g_datagram_based_send_messages() even if you were previously notified of a
%G_IO_OUT condition. (On Windows in particular, this is very common due to
the way the underlying APIs work.)

If the connection is shut down or closed (by calling g_socket_close() or
g_socket_shutdown() with @shutdown_write set, if it’s a #GSocket, for
example), all calls to this function will return %G_IO_ERROR_CLOSED.

On error -1 is returned and @error is set accordingly. An error will only
be returned if zero messages could be sent; otherwise the number of messages
successfully sent before the error will be returned. If @cancellable is
cancelled, %G_IO_ERROR_CANCELLED is returned as with any other error. *)

external receive_messages :
  t ->
  Input_message.t array ->
  int ->
  int ->
  int64 ->
  Cancellable.t option ->
  (int, GError.t) result
  = "ml_g_datagram_based_receive_messages_bytecode"
    "ml_g_datagram_based_receive_messages_native"
(** Receive one or more data messages from @datagram_based in one go.

@messages must point to an array of #GInputMessage structs and
@num_messages must be the length of this array. Each #GInputMessage
contains a pointer to an array of #GInputVector structs describing the
buffers that the data received in each message will be written to.

@flags modify how all messages are received. The commonly available
arguments for this are available in the #GSocketMsgFlags enum, but the
values there are the same as the system values, and the flags
are passed in as-is, so you can pass in system-specific flags too. These
flags affect the overall receive operation. Flags affecting individual
messages are returned in #GInputMessage.flags.

The other members of #GInputMessage are treated as described in its
documentation.

If @timeout is negative the call will block until @num_messages have been
received, the connection is closed remotely (EOS), @cancellable is cancelled,
or an error occurs.

If @timeout is 0 the call will return up to @num_messages without blocking,
or %G_IO_ERROR_WOULD_BLOCK if no messages are queued in the operating system
to be received.

If @timeout is positive the call will block on the same conditions as if
@timeout were negative. If the timeout is reached
before any messages are received, %G_IO_ERROR_TIMED_OUT is returned,
otherwise it will return the number of messages received before timing out.
(Note: This is effectively the behaviour of `MSG_WAITFORONE` with
recvmmsg().)

To be notified when messages are available, wait for the %G_IO_IN condition.
Note though that you may still receive %G_IO_ERROR_WOULD_BLOCK from
g_datagram_based_receive_messages() even if you were previously notified of a
%G_IO_IN condition.

If the remote peer closes the connection, any messages queued in the
underlying receive buffer will be returned, and subsequent calls to
g_datagram_based_receive_messages() will return 0 (with no error set).

If the connection is shut down or closed (by calling g_socket_close() or
g_socket_shutdown() with @shutdown_read set, if it’s a #GSocket, for
example), all calls to this function will return %G_IO_ERROR_CLOSED.

On error -1 is returned and @error is set accordingly. An error will only
be returned if zero messages could be received; otherwise the number of
messages successfully received before the error will be returned. If
@cancellable is cancelled, %G_IO_ERROR_CANCELLED is returned as with any
other error. *)
