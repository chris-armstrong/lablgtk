(* GENERATED CODE - DO NOT EDIT *)
(* ApplicationCommandLine: ApplicationCommandLine *)

type t = [ `application_command_line | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_application_command_line_get_type"

(* Methods *)

external set_exit_status : t -> int -> unit
  = "ml_g_application_command_line_set_exit_status"
(** Sets the exit status that will be used when the invoking process
exits.

The return value of the #GApplication::command-line signal is
passed to this function when the handler returns.  This is the usual
way of setting the exit status.

In the event that you want the remote invocation to continue running
and want to decide on the exit status in the future, you can use this
call.  For the case of a remote invocation, the remote process will
typically exit when the last reference is dropped on @cmdline.  The
exit status of the remote process will be equal to the last value
that was set with this function.

In the case that the commandline invocation is local, the situation
is slightly more complicated.  If the commandline invocation results
in the mainloop running (ie: because the use-count of the application
increased to a non-zero value) then the application is considered to
have been 'successful' in a certain sense, and the exit status is
always zero.  If the application use count is zero, though, the exit
status of the local #GApplicationCommandLine is used.

This method is a no-op if g_application_command_line_done() has
been called. *)

external printerr_literal : t -> string -> unit
  = "ml_g_application_command_line_printerr_literal"
(** Prints a message using the stderr print handler in the invoking process.

Unlike g_application_command_line_printerr(), @message is not
a `printf()`-style format string. Use this function if @message contains text
you don't have control over, that could include `printf()` escape sequences. *)

external print_literal : t -> string -> unit
  = "ml_g_application_command_line_print_literal"
(** Prints a message using the stdout print handler in the invoking process.

Unlike g_application_command_line_print(), @message is not a `printf()`-style
format string. Use this function if @message contains text you don't have
control over, that could include `printf()` escape sequences. *)

external getenv : t -> string -> string option
  = "ml_g_application_command_line_getenv"
(** Gets the value of a particular environment variable of the command
line invocation, as would be returned by g_getenv().  The strings may
contain non-utf8 data.

The remote application usually does not send an environment.  Use
%G_APPLICATION_SEND_ENVIRONMENT to affect that.  Even with this flag
set it is possible that the environment is still not available (due
to invocation messages from other applications).

The return value should not be modified or freed and is valid for as
long as @cmdline exists. *)

external get_stdin : t -> Input_stream.t option
  = "ml_g_application_command_line_get_stdin"
(** Gets the stdin of the invoking process.

    The #GInputStream can be used to read data passed to the standard input of
    the invoking process. This doesn't work on all platforms. Presently, it is
    only available on UNIX when using a D-Bus daemon capable of passing file
    descriptors. If stdin is not available then %NULL will be returned. In the
    future, support may be expanded to other platforms.

    You must only call this function once per commandline invocation. *)

external get_platform_data : t -> Gvariant.t option
  = "ml_g_application_command_line_get_platform_data"
(** Gets the platform data associated with the invocation of @cmdline.

This is a #GVariant dictionary containing information about the
context in which the invocation occurred.  It typically contains
information like the current working directory and the startup
notification ID.

It comes from an untrusted external process and hence the types of all
values must be validated before being used.

For local invocation, it will be %NULL. *)

external get_is_remote : t -> bool
  = "ml_g_application_command_line_get_is_remote"
(** Determines if @cmdline represents a remote invocation. *)

external get_exit_status : t -> int
  = "ml_g_application_command_line_get_exit_status"
(** Gets the exit status of @cmdline.  See
g_application_command_line_set_exit_status() for more information. *)

external get_environ : t -> string array
  = "ml_g_application_command_line_get_environ"
(** Gets the contents of the 'environ' variable of the command line
invocation, as would be returned by g_get_environ(), ie as a
%NULL-terminated list of strings in the form 'NAME=VALUE'.
The strings may contain non-utf8 data.

The remote application usually does not send an environment.  Use
%G_APPLICATION_SEND_ENVIRONMENT to affect that.  Even with this flag
set it is possible that the environment is still not available (due
to invocation messages from other applications).

The return value should not be modified or freed and is valid for as
long as @cmdline exists.

See g_application_command_line_getenv() if you are only interested
in the value of a single environment variable. *)

external get_cwd : t -> string option = "ml_g_application_command_line_get_cwd"
(** Gets the working directory of the command line invocation.
The string may contain non-utf8 data.

It is possible that the remote application did not send a working
directory, so this may be %NULL.

The return value should not be modified or freed and is valid for as
long as @cmdline exists. *)

external get_arguments : t -> string array * int
  = "ml_g_application_command_line_get_arguments"
(** Gets the list of arguments that was passed on the command line.

    The strings in the array may contain non-UTF-8 data on UNIX (such as
    filenames or arguments given in the system locale) but are always in UTF-8
    on Windows.

    If you wish to use the return value with #GOptionContext, you must use
    g_option_context_parse_strv().

    The return value is %NULL-terminated and should be freed using g_strfreev().
*)

external done_ : t -> unit = "ml_g_application_command_line_done"
(** Signals that command line processing is completed.

    For remote invocation, it causes the invoking process to terminate.

    For local invocation, it does nothing.

    This method should be called in the [signal@Gio.Application::command-line]
    handler, after the exit status is set and all messages are printed.

    After this call, g_application_command_line_set_exit_status() has no effect.
    Subsequent calls to this method are no-ops.

    This method is automatically called when the #GApplicationCommandLine object
    is disposed — so you can omit the call in non-garbage collected languages.
*)

external create_file_for_arg : t -> string -> App_info_cycle_64c425a0.File.t
  = "ml_g_application_command_line_create_file_for_arg"
(** Creates a #GFile corresponding to a filename that was given as part
of the invocation of @cmdline.

This differs from g_file_new_for_commandline_arg() in that it
resolves relative pathnames using the current working directory of
the invoking process rather than the local process. *)

(* Properties *)
