(* GENERATED CODE - DO NOT EDIT *)
(* Task: Task *)

type t = [ `task | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_task_get_type"

(* Methods *)

external set_static_name : t -> string option -> unit
  = "ml_g_task_set_static_name"
(** Sets @task’s name, used in debugging and profiling.

This is a variant of g_task_set_name() that avoids copying @name.

This function is called automatically by [method@Gio.Task.set_source_tag]
unless a name is set. *)

external set_return_on_cancel : t -> bool -> bool
  = "ml_g_task_set_return_on_cancel"
(** Sets or clears @task's return-on-cancel flag. This is only
meaningful for tasks run via g_task_run_in_thread() or
g_task_run_in_thread_sync().

If @return_on_cancel is %TRUE, then cancelling @task's
#GCancellable will immediately cause it to return, as though the
task's #GTaskThreadFunc had called
g_task_return_error_if_cancelled() and then returned.

This allows you to create a cancellable wrapper around an
uninterruptible function. The #GTaskThreadFunc just needs to be
careful that it does not modify any externally-visible state after
it has been cancelled. To do that, the thread should call
g_task_set_return_on_cancel() again to (atomically) set
return-on-cancel %FALSE before making externally-visible changes;
if the task gets cancelled before the return-on-cancel flag could
be changed, g_task_set_return_on_cancel() will indicate this by
returning %FALSE.

You can disable and re-enable this flag multiple times if you wish.
If the task's #GCancellable is cancelled while return-on-cancel is
%FALSE, then calling g_task_set_return_on_cancel() to set it %TRUE
again will cause the task to be cancelled at that point.

If the task's #GCancellable is already cancelled before you call
g_task_run_in_thread()/g_task_run_in_thread_sync(), then the
#GTaskThreadFunc will still be run (for consistency), but the task
will also be completed right away. *)

external set_priority : t -> int -> unit = "ml_g_task_set_priority"
(** Sets @task's priority. If you do not call this, it will default to
%G_PRIORITY_DEFAULT.

This will affect the priority of #GSources created with
g_task_attach_source() and the scheduling of tasks run in threads,
and can also be explicitly retrieved later via
g_task_get_priority(). *)

external set_name : t -> string option -> unit = "ml_g_task_set_name"
(** Sets @task’s name, used in debugging and profiling. The name defaults to
%NULL.

The task name should describe in a human readable way what the task does.
For example, ‘Open file’ or ‘Connect to network host’. It is used to set the
name of the #GSource used for idle completion of the task.

This function may only be called before the @task is first used in a thread
other than the one it was constructed in. *)

external set_check_cancellable : t -> bool -> unit
  = "ml_g_task_set_check_cancellable"
(** Sets or clears @task's check-cancellable flag. If this is %TRUE
(the default), then g_task_propagate_pointer(), etc, and
g_task_had_error() will check the task's #GCancellable first, and
if it has been cancelled, then they will consider the task to have
returned an "Operation was cancelled" error
(%G_IO_ERROR_CANCELLED), regardless of any other error or return
value the task may have had.

If @check_cancellable is %FALSE, then the #GTask will not check the
cancellable itself, and it is up to @task's owner to do this (eg,
via g_task_return_error_if_cancelled()).

If you are using g_task_set_return_on_cancel() as well, then
you must leave check-cancellable set %TRUE. *)

external return_value : t -> Gobject.Value.t option -> unit
  = "ml_g_task_return_value"
(** Sets @task's result to @result (by copying it) and completes the task.

If @result is %NULL then a #GValue of type %G_TYPE_POINTER
with a value of %NULL will be used for the result.

This is a very generic low-level method intended primarily for use
by language bindings; for C code, g_task_return_pointer() and the
like will normally be much easier to use. *)

external return_int : t -> int -> unit = "ml_g_task_return_int"
(** Sets @task's result to @result and completes the task (see
g_task_return_pointer() for more discussion of exactly what this
means). *)

external return_error_if_cancelled : t -> bool
  = "ml_g_task_return_error_if_cancelled"
(** Checks if @task's #GCancellable has been cancelled, and if so, sets
@task's error accordingly and completes the task (see
g_task_return_pointer() for more discussion of exactly what this
means). *)

external return_error : t -> GError.t -> unit = "ml_g_task_return_error"
(** Sets @task's result to @error (which @task assumes ownership of)
and completes the task (see g_task_return_pointer() for more
discussion of exactly what this means).

Note that since the task takes ownership of @error, and since the
task may be completed before returning from g_task_return_error(),
you cannot assume that @error is still valid after calling this.
Call g_error_copy() on the error if you need to keep a local copy
as well.

See also [method@Gio.Task.return_new_error],
[method@Gio.Task.return_new_error_literal]. *)

external return_boolean : t -> bool -> unit = "ml_g_task_return_boolean"
(** Sets @task's result to @result and completes the task (see
g_task_return_pointer() for more discussion of exactly what this
means). *)

external propagate_value : t -> (bool * Gobject.Value.t, GError.t) result
  = "ml_g_task_propagate_value"
(** Gets the result of @task as a #GValue, and transfers ownership of
that value to the caller. As with g_task_return_value(), this is
a generic low-level method; g_task_propagate_pointer() and the like
will usually be more useful for C code.

If the task resulted in an error, or was cancelled, then this will
instead set @error and return %FALSE.

Since this method transfers ownership of the return value (or
error) to the caller, you may only call it once. *)

external propagate_int : t -> (int, GError.t) result = "ml_g_task_propagate_int"
(** Gets the result of @task as an integer (#gssize).

If the task resulted in an error, or was cancelled, then this will
instead return -1 and set @error.

Since this method transfers ownership of the return value (or
error) to the caller, you may only call it once. *)

external propagate_boolean : t -> (bool, GError.t) result
  = "ml_g_task_propagate_boolean"
(** Gets the result of @task as a #gboolean.

If the task resulted in an error, or was cancelled, then this will
instead return %FALSE and set @error.

Since this method transfers ownership of the return value (or
error) to the caller, you may only call it once. *)

external had_error : t -> bool = "ml_g_task_had_error"
(** Tests if @task resulted in an error. *)

external get_source_object : t -> [ `object_ ] Gobject.obj option
  = "ml_g_task_get_source_object"
(** Gets the source object from @task. Like
g_async_result_get_source_object(), but does not ref the object. *)

external get_return_on_cancel : t -> bool = "ml_g_task_get_return_on_cancel"
(** Gets @task's return-on-cancel flag. See
g_task_set_return_on_cancel() for more details. *)

external get_priority : t -> int = "ml_g_task_get_priority"
(** Gets @task's priority *)

external get_name : t -> string option = "ml_g_task_get_name"
(** Gets @task’s name. See g_task_set_name(). *)

external get_completed : t -> bool = "ml_g_task_get_completed"
(** Gets the value of #GTask:completed. This changes from %FALSE to %TRUE after
    the task’s callback is invoked, and will return %FALSE if called from inside
    the callback. *)

external get_check_cancellable : t -> bool = "ml_g_task_get_check_cancellable"
(** Gets @task's check-cancellable flag. See
g_task_set_check_cancellable() for more details. *)

external get_cancellable : t -> Cancellable.t option
  = "ml_g_task_get_cancellable"
(** Gets @task's #GCancellable *)

(* Properties *)
