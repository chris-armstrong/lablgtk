(* GENERATED CODE - DO NOT EDIT *)
(* Cancellable: Cancellable *)

type t = [ `cancellable | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_cancellable_get_type"

external new_ : unit -> t = "ml_g_cancellable_new"
(** Create a new Cancellable *)

(* Methods *)

external set_error_if_cancelled : t -> (bool, GError.t) result
  = "ml_g_cancellable_set_error_if_cancelled"
(** If the @cancellable is cancelled, sets the error to notify
that the operation was cancelled. *)

external reset : t -> unit = "ml_g_cancellable_reset"
(** Resets @cancellable to its uncancelled state.

If cancellable is currently in use by any cancellable operation
then the behavior of this function is undefined.

Note that it is generally not a good idea to reuse an existing
cancellable for more operations after it has been cancelled once,
as this function might tempt you to do. The recommended practice
is to drop the reference to a cancellable after cancelling it,
and let it die with the outstanding async operations. You should
create a fresh cancellable for further async operations.

In the event that a [signal@Gio.Cancellable::cancelled] signal handler is currently
running, this call will block until the handler has finished.
Calling this function from a signal handler will therefore result in a
deadlock. *)

external release_fd : t -> unit = "ml_g_cancellable_release_fd"
(** Releases a resources previously allocated by g_cancellable_get_fd()
or g_cancellable_make_pollfd().

For compatibility reasons with older releases, calling this function
is not strictly required, the resources will be automatically freed
when the @cancellable is finalized. However, the @cancellable will
block scarce file descriptors until it is finalized if this function
is not called. This can cause the application to run out of file
descriptors when many #GCancellables are used at the same time.

Note that in the event that a [signal@Gio.Cancellable::cancelled] signal handler is
currently running, this call will block until the handler has finished.
Calling this function from a signal handler will therefore result in a
deadlock. *)

external push_current : t -> unit = "ml_g_cancellable_push_current"
(** Pushes @cancellable onto the cancellable stack. The current
cancellable can then be received using g_cancellable_get_current().

This is useful when implementing cancellable operations in
code that does not allow you to pass down the cancellable object.

This is typically called automatically by e.g. #GFile operations,
so you rarely have to call this yourself. *)

external pop_current : t -> unit = "ml_g_cancellable_pop_current"
(** Pops @cancellable off the cancellable stack (verifying that @cancellable
is on the top of the stack). *)

external is_cancelled : t -> bool = "ml_g_cancellable_is_cancelled"
(** Checks if a cancellable job has been cancelled. *)

external get_fd : t -> int = "ml_g_cancellable_get_fd"
(** Gets the file descriptor for a cancellable job. This can be used to
implement cancellable operations on Unix systems. The returned fd will
turn readable when @cancellable is cancelled.

You are not supposed to read from the fd yourself, just check for
readable status. Reading to unset the readable status is done
with g_cancellable_reset().

After a successful return from this function, you should use
g_cancellable_release_fd() to free up resources allocated for
the returned file descriptor.

See also g_cancellable_make_pollfd(). *)

external disconnect : t -> int -> unit = "ml_g_cancellable_disconnect"
(** Disconnects a handler from a cancellable instance similar to
g_signal_handler_disconnect().  Additionally, in the event that a
signal handler is currently running, this call will block until the
handler has finished.  Calling this function from a
#GCancellable::cancelled signal handler will therefore result in a
deadlock.

This avoids a race condition where a thread cancels at the
same time as the cancellable operation is finished and the
signal handler is removed. See #GCancellable::cancelled for
details on how to use this.

If @cancellable is %NULL or @handler_id is `0` this function does
nothing. *)

external cancel : t -> unit = "ml_g_cancellable_cancel"
(** Will set @cancellable to cancelled, and will emit the
#GCancellable::cancelled signal. (However, see the warning about
race conditions in the documentation for that signal if you are
planning to connect to it.)

This function is thread-safe. In other words, you can safely call
it from a thread other than the one running the operation that was
passed the @cancellable.

If @cancellable is %NULL, this function returns immediately for convenience.

The convention within GIO is that cancelling an asynchronous
operation causes it to complete asynchronously. That is, if you
cancel the operation from the same thread in which it is running,
then the operation's #GAsyncReadyCallback will not be invoked until
the application returns to the main loop.

It is safe (although useless, since it will be a no-op) to call
this function from a [signal@Gio.Cancellable::cancelled] signal handler. *)

val on_cancelled :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
