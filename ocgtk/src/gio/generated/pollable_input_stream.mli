(* GENERATED CODE - DO NOT EDIT *)
(* PollableInputStream: PollableInputStream *)

type t = [ `pollable_input_stream ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_pollable_input_stream_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_pollable_input_stream_from_gobject"

(* Methods *)

external is_readable : t -> bool = "ml_g_pollable_input_stream_is_readable"
(** Checks if @stream can be read.

Note that some stream types may not be able to implement this 100%
reliably, and it is possible that a call to g_input_stream_read()
after this returns %TRUE would still block. To guarantee
non-blocking behavior, you should always use
g_pollable_input_stream_read_nonblocking(), which will return a
%G_IO_ERROR_WOULD_BLOCK error rather than blocking.

The behaviour of this method is undefined if
g_pollable_input_stream_can_poll() returns %FALSE for @stream. *)

external can_poll : t -> bool = "ml_g_pollable_input_stream_can_poll"
(** Checks if @stream is actually pollable. Some classes may implement
#GPollableInputStream but have only certain instances of that class
be pollable. If this method returns %FALSE, then the behavior of
other #GPollableInputStream methods is undefined.

For any given stream, the value returned by this method is constant;
a stream cannot switch from pollable to non-pollable or vice versa. *)
