(* GENERATED CODE - DO NOT EDIT *)
(* SubprocessLauncher: SubprocessLauncher *)

type t = [ `subprocess_launcher | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_subprocess_launcher_get_type"

external new_ : Gio_enums.subprocessflags -> t = "ml_g_subprocess_launcher_new"
(** Create a new SubprocessLauncher *)

(* Methods *)

external unsetenv : t -> string -> unit = "ml_g_subprocess_launcher_unsetenv"
(** Removes the environment variable @variable from the environment of
processes launched from this launcher.

On UNIX, the variable's name can be an arbitrary byte string not
containing '='. On Windows, it should be in UTF-8. *)

external take_stdout_fd : t -> int -> unit
  = "ml_g_subprocess_launcher_take_stdout_fd"
(** Sets the file descriptor to use as the stdout for spawned processes.

If @fd is -1 then any previously given fd is unset.

Note that the default behaviour is to pass stdout through to the
stdout of the parent process.

The passed @fd is noted but will not be touched in the current
process.  It is therefore necessary that it be kept open by the
caller until the subprocess is spawned.  The file descriptor will
also not be explicitly closed on the child side, so it must be marked
O_CLOEXEC if that's what you want.

You may not set a stdout fd if a stdout file path is already set or
if the launcher flags contain any flags directing stdout elsewhere.

This feature is only available on UNIX. *)

external take_stdin_fd : t -> int -> unit
  = "ml_g_subprocess_launcher_take_stdin_fd"
(** Sets the file descriptor to use as the stdin for spawned processes.

If @fd is -1 then any previously given fd is unset.

Note that if your intention is to have the stdin of the calling
process inherited by the child then %G_SUBPROCESS_FLAGS_STDIN_INHERIT
is a better way to go about doing that.

The passed @fd is noted but will not be touched in the current
process.  It is therefore necessary that it be kept open by the
caller until the subprocess is spawned.  The file descriptor will
also not be explicitly closed on the child side, so it must be marked
O_CLOEXEC if that's what you want.

You may not set a stdin fd if a stdin file path is already set or if
the launcher flags contain any flags directing stdin elsewhere.

This feature is only available on UNIX. *)

external take_stderr_fd : t -> int -> unit
  = "ml_g_subprocess_launcher_take_stderr_fd"
(** Sets the file descriptor to use as the stderr for spawned processes.

If @fd is -1 then any previously given fd is unset.

Note that the default behaviour is to pass stderr through to the
stderr of the parent process.

The passed @fd belongs to the #GSubprocessLauncher.  It will be
automatically closed when the launcher is finalized.  The file
descriptor will also be closed on the child side when executing the
spawned process.

You may not set a stderr fd if a stderr file path is already set or
if the launcher flags contain any flags directing stderr elsewhere.

This feature is only available on UNIX. *)

external take_fd : t -> int -> int -> unit = "ml_g_subprocess_launcher_take_fd"
(** Transfer an arbitrary file descriptor from parent process to the
child.  This function takes ownership of the @source_fd; it will be closed
in the parent when @self is freed.

By default, all file descriptors from the parent will be closed.
This function allows you to create (for example) a custom `pipe()` or
`socketpair()` before launching the process, and choose the target
descriptor in the child.

An example use case is GNUPG, which has a command line argument
`--passphrase-fd` providing a file descriptor number where it expects
the passphrase to be written. *)

external spawnv : t -> string array -> (Subprocess.t, GError.t) result
  = "ml_g_subprocess_launcher_spawnv"
(** Creates a #GSubprocess given a provided array of arguments. *)

external setenv : t -> string -> string -> bool -> unit
  = "ml_g_subprocess_launcher_setenv"
(** Sets the environment variable @variable in the environment of
processes launched from this launcher.

On UNIX, both the variable's name and value can be arbitrary byte
strings, except that the variable's name cannot contain '='.
On Windows, they should be in UTF-8. *)

external set_stdout_file_path : t -> string option -> unit
  = "ml_g_subprocess_launcher_set_stdout_file_path"
(** Sets the file path to use as the stdout for spawned processes.

If @path is %NULL then any previously given path is unset.

The file will be created or truncated when the process is spawned, as
would be the case if using '>' at the shell.

You may not set a stdout file path if a stdout fd is already set or
if the launcher flags contain any flags directing stdout elsewhere.

This feature is only available on UNIX. *)

external set_stdin_file_path : t -> string option -> unit
  = "ml_g_subprocess_launcher_set_stdin_file_path"
(** Sets the file path to use as the stdin for spawned processes.

If @path is %NULL then any previously given path is unset.

The file must exist or spawning the process will fail.

You may not set a stdin file path if a stdin fd is already set or if
the launcher flags contain any flags directing stdin elsewhere.

This feature is only available on UNIX. *)

external set_stderr_file_path : t -> string option -> unit
  = "ml_g_subprocess_launcher_set_stderr_file_path"
(** Sets the file path to use as the stderr for spawned processes.

If @path is %NULL then any previously given path is unset.

The file will be created or truncated when the process is spawned, as
would be the case if using '2>' at the shell.

If you want to send both stdout and stderr to the same file then use
%G_SUBPROCESS_FLAGS_STDERR_MERGE.

You may not set a stderr file path if a stderr fd is already set or
if the launcher flags contain any flags directing stderr elsewhere.

This feature is only available on UNIX. *)

external set_flags : t -> Gio_enums.subprocessflags -> unit
  = "ml_g_subprocess_launcher_set_flags"
(** Sets the flags on the launcher.

    The default flags are %G_SUBPROCESS_FLAGS_NONE.

    You may not set flags that specify conflicting options for how to handle a
    particular stdio stream (eg: specifying both %G_SUBPROCESS_FLAGS_STDIN_PIPE
    and %G_SUBPROCESS_FLAGS_STDIN_INHERIT).

    You may also not set a flag that conflicts with a previous call to a
    function like g_subprocess_launcher_set_stdin_file_path() or
    g_subprocess_launcher_take_stdout_fd(). *)

external set_environ : t -> string array -> unit
  = "ml_g_subprocess_launcher_set_environ"
(** Replace the entire environment of processes launched from this launcher with
    the given 'environ' variable.

    Typically you will build this variable by using g_listenv() to copy the
    process 'environ' and using the functions g_environ_setenv(),
    g_environ_unsetenv(), etc.

    As an alternative, you can use g_subprocess_launcher_setenv(),
    g_subprocess_launcher_unsetenv(), etc.

    Pass an empty array to set an empty environment. Pass %NULL to inherit the
    parent process’ environment. As of GLib 2.54, the parent process’
    environment will be copied when g_subprocess_launcher_set_environ() is
    called. Previously, it was copied when the subprocess was executed. This
    means the copied environment may now be modified (using
    g_subprocess_launcher_setenv(), etc.) before launching the subprocess.

    On UNIX, all strings in this array can be arbitrary byte strings. On
    Windows, they should be in UTF-8. *)

external set_cwd : t -> string -> unit = "ml_g_subprocess_launcher_set_cwd"
(** Sets the current working directory that processes will be launched with.

    By default processes are launched with the current working directory of the
    launching process at the time of launch. *)

external getenv : t -> string -> string option
  = "ml_g_subprocess_launcher_getenv"
(** Returns the value of the environment variable @variable in the
environment of processes launched from this launcher.

On UNIX, the returned string can be an arbitrary byte string.
On Windows, it will be UTF-8. *)

external close : t -> unit = "ml_g_subprocess_launcher_close"
(** Closes all the file descriptors previously passed to the object with
    g_subprocess_launcher_take_fd(), g_subprocess_launcher_take_stderr_fd(),
    etc.

    After calling this method, any subsequent calls to
    g_subprocess_launcher_spawn() or g_subprocess_launcher_spawnv() will return
    %G_IO_ERROR_CLOSED. This method is idempotent if called more than once.

    This function is called automatically when the #GSubprocessLauncher is
    disposed, but is provided separately so that garbage collected language
    bindings can call it earlier to guarantee when FDs are closed. *)

(* Properties *)
