(* GENERATED CODE - DO NOT EDIT *)
(* SimpleAsyncResult: SimpleAsyncResult *)

type t = [ `simple_async_result | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_simple_async_result_get_type"

(* Methods *)

external set_op_res_gssize : t -> int -> unit
  = "ml_g_simple_async_result_set_op_res_gssize"
(** Sets the operation result within the asynchronous result to
the given @op_res. *)

external set_op_res_gboolean : t -> bool -> unit
  = "ml_g_simple_async_result_set_op_res_gboolean"
(** Sets the operation result to a boolean within the asynchronous result. *)

external set_handle_cancellation : t -> bool -> unit
  = "ml_g_simple_async_result_set_handle_cancellation"
(** Sets whether to handle cancellation within the asynchronous operation.

    This function has nothing to do with
    g_simple_async_result_set_check_cancellable(). It only refers to the
    #GCancellable passed to g_simple_async_result_run_in_thread(). *)

external set_from_error : t -> GError.t -> unit
  = "ml_g_simple_async_result_set_from_error"
(** Sets the result from a #GError. *)

external set_check_cancellable : t -> Cancellable.t option -> unit
  = "ml_g_simple_async_result_set_check_cancellable"
(** Sets a #GCancellable to check before dispatching results.

    This function has one very specific purpose: the provided cancellable is
    checked at the time of g_simple_async_result_propagate_error() If it is
    cancelled, these functions will return an "Operation was cancelled" error
    (%G_IO_ERROR_CANCELLED).

    Implementors of cancellable asynchronous functions should use this in order
    to provide a guarantee to their callers that cancelling an async operation
    will reliably result in an error being returned for that operation (even if
    a positive result for the operation has already been sent as an idle to the
    main context to be dispatched).

    The checking described above is done regardless of any call to the unrelated
    g_simple_async_result_set_handle_cancellation() function. *)

external propagate_error : t -> (bool, GError.t) result
  = "ml_g_simple_async_result_propagate_error"
(** Propagates an error from within the simple asynchronous result to
a given destination.

If the #GCancellable given to a prior call to
g_simple_async_result_set_check_cancellable() is cancelled then this
function will return %TRUE with @dest set appropriately. *)

external get_op_res_gssize : t -> int
  = "ml_g_simple_async_result_get_op_res_gssize"
(** Gets a gssize from the asynchronous result. *)

external get_op_res_gboolean : t -> bool
  = "ml_g_simple_async_result_get_op_res_gboolean"
(** Gets the operation result boolean from within the asynchronous result. *)

external complete_in_idle : t -> unit
  = "ml_g_simple_async_result_complete_in_idle"
(** Completes an asynchronous function in an idle handler in the
thread-default main context (see [method@GLib.MainContext.push_thread_default])
of the thread that @simple was initially created in
(and re-pushes that context around the invocation of the callback).

Calling this function takes a reference to @simple for as long as
is needed to complete the call. *)

external complete : t -> unit = "ml_g_simple_async_result_complete"
(** Completes an asynchronous I/O job immediately. Must be called in
the thread where the asynchronous result was to be delivered, as it
invokes the callback directly. If you are in a different thread use
g_simple_async_result_complete_in_idle().

Calling this function takes a reference to @simple for as long as
is needed to complete the call. *)
