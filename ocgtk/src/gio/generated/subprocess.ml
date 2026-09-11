(* GENERATED CODE - DO NOT EDIT *)
(* Subprocess: Subprocess *)

type t = [ `subprocess | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_subprocess_get_type"

external newv :
  string array -> Gio_enums.subprocessflags -> (t, GError.t) result
  = "ml_g_subprocess_newv"
(** Create a new Subprocess *)

(* Methods *)

external wait_finish : t -> Async_result.t -> (bool, GError.t) result
  = "ml_g_subprocess_wait_finish"
(** Collects the result of a previous call to g_subprocess_wait_async(). *)

external wait_check_finish : t -> Async_result.t -> (bool, GError.t) result
  = "ml_g_subprocess_wait_check_finish"
(** Collects the result of a previous call to g_subprocess_wait_check_async().
*)

external wait_check : t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_subprocess_wait_check"
(** Combines g_subprocess_wait() with g_spawn_check_wait_status(). *)

external wait : t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_subprocess_wait"
(** Synchronously wait for the subprocess to terminate.

After the process terminates you can query its exit status with
functions such as g_subprocess_get_if_exited() and
g_subprocess_get_exit_status().

This function does not fail in the case of the subprocess having
abnormal termination.  See g_subprocess_wait_check() for that.

Cancelling @cancellable doesn't kill the subprocess.  Call
g_subprocess_force_exit() if it is desirable. *)

external send_signal : t -> int -> unit = "ml_g_subprocess_send_signal"
(** Sends the UNIX signal @signal_num to the subprocess, if it is still
running.

This API is race-free.  If the subprocess has terminated, it will not
be signalled.

This API is not available on Windows. *)

external get_term_sig : t -> int = "ml_g_subprocess_get_term_sig"
(** Get the signal number that caused the subprocess to terminate, given that it
    terminated due to a signal.

    This is equivalent to the system WTERMSIG macro.

    It is an error to call this function before g_subprocess_wait() and unless
    g_subprocess_get_if_signaled() returned %TRUE. *)

external get_successful : t -> bool = "ml_g_subprocess_get_successful"
(** Checks if the process was "successful". A process is considered successful
    if it exited cleanly with an exit status of 0, either by way of the exit()
    system call or return from main().

    It is an error to call this function before g_subprocess_wait() has
    returned. *)

external get_stdout_pipe : t -> Input_stream.t option
  = "ml_g_subprocess_get_stdout_pipe"
(** Gets the #GInputStream from which to read the stdout output of
@subprocess.

The process must have been created with %G_SUBPROCESS_FLAGS_STDOUT_PIPE,
otherwise %NULL will be returned. *)

external get_stdin_pipe : t -> Output_stream.t option
  = "ml_g_subprocess_get_stdin_pipe"
(** Gets the #GOutputStream that you can write to in order to give data
to the stdin of @subprocess.

The process must have been created with %G_SUBPROCESS_FLAGS_STDIN_PIPE and
not %G_SUBPROCESS_FLAGS_STDIN_INHERIT, otherwise %NULL will be returned. *)

external get_stderr_pipe : t -> Input_stream.t option
  = "ml_g_subprocess_get_stderr_pipe"
(** Gets the #GInputStream from which to read the stderr output of
@subprocess.

The process must have been created with %G_SUBPROCESS_FLAGS_STDERR_PIPE,
otherwise %NULL will be returned. *)

external get_status : t -> int = "ml_g_subprocess_get_status"
(** Gets the raw status code of the process, as from waitpid().

    This value has no particular meaning, but it can be used with the macros
    defined by the system headers such as WIFEXITED. It can also be used with
    g_spawn_check_wait_status().

    It is more likely that you want to use g_subprocess_get_if_exited() followed
    by g_subprocess_get_exit_status().

    It is an error to call this function before g_subprocess_wait() has
    returned. *)

external get_if_signaled : t -> bool = "ml_g_subprocess_get_if_signaled"
(** Check if the given subprocess terminated in response to a signal.

    This is equivalent to the system WIFSIGNALED macro.

    It is an error to call this function before g_subprocess_wait() has
    returned. *)

external get_if_exited : t -> bool = "ml_g_subprocess_get_if_exited"
(** Check if the given subprocess exited normally (ie: by way of exit() or
    return from main()).

    This is equivalent to the system WIFEXITED macro.

    It is an error to call this function before g_subprocess_wait() has
    returned. *)

external get_identifier : t -> string option = "ml_g_subprocess_get_identifier"
(** On UNIX, returns the process ID as a decimal string. On Windows, returns the
    result of GetProcessId() also as a string. If the subprocess has terminated,
    this will return %NULL. *)

external get_exit_status : t -> int = "ml_g_subprocess_get_exit_status"
(** Check the exit status of the subprocess, given that it exited normally. This
    is the value passed to the exit() system call or the return value from main.

    This is equivalent to the system WEXITSTATUS macro.

    It is an error to call this function before g_subprocess_wait() and unless
    g_subprocess_get_if_exited() returned %TRUE. *)

external force_exit : t -> unit = "ml_g_subprocess_force_exit"
(** Use an operating-system specific method to attempt an immediate, forceful
    termination of the process. There is no mechanism to determine whether or
    not the request itself was successful; however, you can use
    g_subprocess_wait() to monitor the status of the process after calling this
    function.

    On Unix, this function sends %SIGKILL. *)

(* Properties *)
