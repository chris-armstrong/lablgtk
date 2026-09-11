(* GENERATED CODE - DO NOT EDIT *)
(* Application: Application *)

type t = [ `application | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_application_get_type"

external new_ : string option -> Gio_enums.applicationflags -> t
  = "ml_g_application_new"
(** Create a new Application *)

(* Methods *)

external withdraw_notification : t -> string -> unit
  = "ml_g_application_withdraw_notification"
(** Withdraws a notification that was sent with
g_application_send_notification().

This call does nothing if a notification with @id doesn't exist or
the notification was never sent.

This function works even for notifications sent in previous
executions of this application, as long @id is the same as it was for
the sent notification.

Note that notifications are dismissed when the user clicks on one
of the buttons in a notification or triggers its default action, so
there is no need to explicitly withdraw the notification in that case. *)

external unmark_busy : t -> unit = "ml_g_application_unmark_busy"
(** Decreases the busy count of @application.

When the busy count reaches zero, the new state will be propagated
to other processes.

This function must only be called to cancel the effect of a previous
call to g_application_mark_busy(). *)

external unbind_busy_property : t -> [ `object_ ] Gobject.obj -> string -> unit
  = "ml_g_application_unbind_busy_property"
(** Destroys a binding between @property and the busy state of
@application that was previously created with
g_application_bind_busy_property(). *)

external set_version : t -> string -> unit = "ml_g_application_set_version"
(** Sets the version number of @application. This will be used to implement
a `--version` command line argument

The application version can only be modified if @application has not yet
been registered. *)

external set_resource_base_path : t -> string option -> unit
  = "ml_g_application_set_resource_base_path"
(** Sets (or unsets) the base resource path of @application.

The path is used to automatically load various
[application resources][struct@Gio.Resource] such as menu layouts and
action descriptions. The various types of resources will be found at
fixed names relative to the given base path.

By default, the resource base path is determined from the application
ID by prefixing '/' and replacing each '.' with '/'.  This is done at
the time that the #GApplication object is constructed.  Changes to
the application ID after that point will not have an impact on the
resource base path.

As an example, if the application has an ID of "org.example.app" then
the default resource base path will be "/org/example/app".  If this
is a #GtkApplication (and you have not manually changed the path)
then Gtk will then search for the menus of the application at
"/org/example/app/gtk/menus.ui".

See #GResource for more information about adding resources to your
application.

You can disable automatic resource loading functionality by setting
the path to %NULL.

Changing the resource base path once the application is running is
not recommended.  The point at which the resource path is consulted
for forming paths for various purposes is unspecified.  When writing
a sub-class of #GApplication you should either set the
#GApplication:resource-base-path property at construction time, or call
this function during the instance initialization. Alternatively, you
can call this function in the #GApplicationClass.startup virtual function,
before chaining up to the parent implementation. *)

external set_option_context_summary : t -> string option -> unit
  = "ml_g_application_set_option_context_summary"
(** Adds a summary to the @application option context.

See g_option_context_set_summary() for more information. *)

external set_option_context_parameter_string : t -> string option -> unit
  = "ml_g_application_set_option_context_parameter_string"
(** Sets the parameter string to be used by the commandline handling of @application.

This function registers the argument to be passed to g_option_context_new()
when the internal #GOptionContext of @application is created.

See g_option_context_new() for more information about @parameter_string. *)

external set_option_context_description : t -> string option -> unit
  = "ml_g_application_set_option_context_description"
(** Adds a description to the @application option context.

See g_option_context_set_description() for more information. *)

external set_inactivity_timeout : t -> int -> unit
  = "ml_g_application_set_inactivity_timeout"
(** Sets the current inactivity timeout for the application.

    This is the amount of time (in milliseconds) after the last call to
    g_application_release() before the application stops running.

    This call has no side effects of its own. The value set here is only used
    for next time g_application_release() drops the use count to zero. Any
    timeouts currently in progress are not impacted. *)

external set_flags : t -> Gio_enums.applicationflags -> unit
  = "ml_g_application_set_flags"
(** Sets the flags for @application.

The flags can only be modified if @application has not yet been
registered.

See #GApplicationFlags. *)

external set_default : t -> unit = "ml_g_application_set_default"
(** Sets or unsets the default application for the process, as returned
by g_application_get_default().

This function does not take its own reference on @application.  If
@application is destroyed then the default application will revert
back to %NULL. *)

external set_application_id : t -> string option -> unit
  = "ml_g_application_set_application_id"
(** Sets the unique identifier for @application.

The application id can only be modified if @application has not yet
been registered.

If non-%NULL, the application id must be valid.  See
g_application_id_is_valid(). *)

external set_action_group : t -> Action_group.t option -> unit
  = "ml_g_application_set_action_group"
(** This used to be how actions were associated with a #GApplication. Now there
    is #GActionMap for that. *)

external send_notification : t -> string option -> Notification.t -> unit
  = "ml_g_application_send_notification"
(** Sends a notification on behalf of @application to the desktop shell.
There is no guarantee that the notification is displayed immediately,
or even at all.

Notifications may persist after the application exits. It will be
D-Bus-activated when the notification or one of its actions is
activated.

Modifying @notification after this call has no effect. However, the
object can be reused for a later call to this function.

@id may be any string that uniquely identifies the event for the
application. It does not need to be in any special format. For
example, "new-message" might be appropriate for a notification about
new messages.

If a previous notification was sent with the same @id, it will be
replaced with @notification and shown again as if it was a new
notification. This works even for notifications sent from a previous
execution of the application, as long as @id is the same string.

@id may be `NULL`, but it is impossible to replace or withdraw
notifications without an id.

If @notification is no longer relevant, it can be withdrawn with
[method@Gio.Application.withdraw_notification].

It is an error to call this function if @application has no
application ID. *)

external run : t -> int -> string array option -> int = "ml_g_application_run"
(** Runs the application.

This function is intended to be run from main() and its return value
is intended to be returned by main(). Although you are expected to pass
the @argc, @argv parameters from main() to this function, it is possible
to pass %NULL if @argv is not available or commandline handling is not
required.  Note that on Windows, @argc and @argv are ignored, and
g_win32_get_command_line() is called internally (for proper support
of Unicode commandline arguments).

#GApplication will attempt to parse the commandline arguments.  You
can add commandline flags to the list of recognised options by way of
g_application_add_main_option_entries().  After this, the
#GApplication::handle-local-options signal is emitted, from which the
application can inspect the values of its #GOptionEntrys.

#GApplication::handle-local-options is a good place to handle options
such as `--version`, where an immediate reply from the local process is
desired (instead of communicating with an already-running instance).
A #GApplication::handle-local-options handler can stop further processing
by returning a non-negative value, which then becomes the exit status of
the process.

What happens next depends on the flags: if
%G_APPLICATION_HANDLES_COMMAND_LINE was specified then the remaining
commandline arguments are sent to the primary instance, where a
#GApplication::command-line signal is emitted.  Otherwise, the
remaining commandline arguments are assumed to be a list of files.
If there are no files listed, the application is activated via the
#GApplication::activate signal.  If there are one or more files, and
%G_APPLICATION_HANDLES_OPEN was specified then the files are opened
via the #GApplication::open signal.

If you are interested in doing more complicated local handling of the
commandline then you should implement your own #GApplication subclass
and override local_command_line(). In this case, you most likely want
to return %TRUE from your local_command_line() implementation to
suppress the default handling. See
[gapplication-example-cmdline2.c][https://gitlab.gnome.org/GNOME/glib/-/blob/HEAD/gio/tests/gapplication-example-cmdline2.c]
for an example.

If, after the above is done, the use count of the application is zero
then the exit status is returned immediately.  If the use count is
non-zero then the default main context is iterated until the use count
falls to zero, at which point 0 is returned.

If the %G_APPLICATION_IS_SERVICE flag is set, then the service will
run for as much as 10 seconds with a use count of zero while waiting
for the message that caused the activation to arrive.  After that,
if the use count falls to zero the application will exit immediately,
except in the case that g_application_set_inactivity_timeout() is in
use.

This function sets the prgname (g_set_prgname()), if not already set,
to the basename of argv[0].

Much like g_main_loop_run(), this function will acquire the main context
for the duration that the application is running.

Since 2.40, applications that are not explicitly flagged as services
or launchers (ie: neither %G_APPLICATION_IS_SERVICE or
%G_APPLICATION_IS_LAUNCHER are given as flags) will check (from the
default handler for local_command_line) if "--gapplication-service"
was given in the command line.  If this flag is present then normal
commandline processing is interrupted and the
%G_APPLICATION_IS_SERVICE flag is set.  This provides a "compromise"
solution whereby running an application directly from the commandline
will invoke it in the normal way (which can be useful for debugging)
while still allowing applications to be D-Bus activated in service
mode.  The D-Bus service file should invoke the executable with
"--gapplication-service" as the sole commandline argument.  This
approach is suitable for use by most graphical applications but
should not be used from applications like editors that need precise
control over when processes invoked via the commandline will exit and
what their exit status will be. *)

external release : t -> unit = "ml_g_application_release"
(** Decrease the use count of @application.

When the use count reaches zero, the application will stop running.

Never call this function except to cancel the effect of a previous
call to g_application_hold(). *)

external register : t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_application_register"
(** Attempts registration of the application.

This is the point at which the application discovers if it is the
primary instance or merely acting as a remote for an already-existing
primary instance.  This is implemented by attempting to acquire the
application identifier as a unique bus name on the session bus using
GDBus.

If there is no application ID or if %G_APPLICATION_NON_UNIQUE was
given, then this process will always become the primary instance.

Due to the internal architecture of GDBus, method calls can be
dispatched at any time (even if a main loop is not running).  For
this reason, you must ensure that any object paths that you wish to
register are registered before calling this function.

If the application has already been registered then %TRUE is
returned with no work performed.

The #GApplication::startup signal is emitted if registration succeeds
and @application is the primary instance (including the non-unique
case).

In the event of an error (such as @cancellable being cancelled, or a
failure to connect to the session bus), %FALSE is returned and @error
is set appropriately.

Note: the return value of this function is not an indicator that this
instance is or is not the primary instance of the application.  See
g_application_get_is_remote() for that. *)

external quit : t -> unit = "ml_g_application_quit"
(** Immediately quits the application.

    Upon return to the mainloop, g_application_run() will return, calling only
    the 'shutdown' function before doing so.

    The hold count is ignored. Take care if your code has called
    g_application_hold() on the application and is therefore still expecting it
    to exist. (Note that you may have called g_application_hold() indirectly,
    for example through gtk_application_add_window().)

    The result of calling g_application_run() again after it returns is
    unspecified. *)

external open_ :
  t -> App_info_cycle_64c425a0.File.t array -> int -> string -> unit
  = "ml_g_application_open"
(** Opens the given files.

In essence, this results in the #GApplication::open signal being emitted
in the primary instance.

@n_files must be greater than zero.

@hint is simply passed through to the ::open signal.  It is
intended to be used by applications that have multiple modes for
opening files (eg: "view" vs "edit", etc).  Unless you have a need
for this functionality, you should use "".

The application must be registered before calling this function
and it must have the %G_APPLICATION_HANDLES_OPEN flag set. *)

external mark_busy : t -> unit = "ml_g_application_mark_busy"
(** Increases the busy count of @application.

Use this function to indicate that the application is busy, for instance
while a long running operation is pending.

The busy state will be exposed to other processes, so a session shell will
use that information to indicate the state to the user (e.g. with a
spinner).

To cancel the busy indication, use g_application_unmark_busy().

The application must be registered before calling this function. *)

external hold : t -> unit = "ml_g_application_hold"
(** Increases the use count of @application.

Use this function to indicate that the application has a reason to
continue to run.  For example, g_application_hold() is called by GTK
when a toplevel window is on the screen.

To cancel the hold, call g_application_release(). *)

external get_version : t -> string option = "ml_g_application_get_version"
(** Gets the version of @application. *)

external get_resource_base_path : t -> string option
  = "ml_g_application_get_resource_base_path"
(** Gets the resource base path of @application.

See g_application_set_resource_base_path() for more information. *)

external get_is_remote : t -> bool = "ml_g_application_get_is_remote"
(** Checks if @application is remote.

If @application is remote then it means that another instance of
application already exists (the 'primary' instance).  Calls to
perform actions on @application will result in the actions being
performed by the primary instance.

The value of this property cannot be accessed before
g_application_register() has been called.  See
g_application_get_is_registered(). *)

external get_is_registered : t -> bool = "ml_g_application_get_is_registered"
(** Checks if @application is registered.

An application is registered if g_application_register() has been
successfully called. *)

external get_is_busy : t -> bool = "ml_g_application_get_is_busy"
(** Gets the application's current busy state, as set through
    g_application_mark_busy() or g_application_bind_busy_property(). *)

external get_inactivity_timeout : t -> int
  = "ml_g_application_get_inactivity_timeout"
(** Gets the current inactivity timeout for the application.

    This is the amount of time (in milliseconds) after the last call to
    g_application_release() before the application stops running. *)

external get_flags : t -> Gio_enums.applicationflags
  = "ml_g_application_get_flags"
(** Gets the flags for @application.

See #GApplicationFlags. *)

external get_dbus_object_path : t -> string option
  = "ml_g_application_get_dbus_object_path"
(** Gets the D-Bus object path being used by the application, or %NULL.

    If #GApplication is using its D-Bus backend then this function will return
    the D-Bus object path that #GApplication is using. If the application is the
    primary instance then there is an object published at this path. If the
    application is not the primary instance then the result of this function is
    undefined.

    If #GApplication is not using D-Bus then this function will return %NULL.
    This includes the situation where the D-Bus backend would normally be in use
    but we were unable to connect to the bus.

    This function must not be called before the application has been registered.
    See g_application_get_is_registered(). *)

external get_dbus_connection : t -> D_bus_connection.t option
  = "ml_g_application_get_dbus_connection"
(** Gets the #GDBusConnection being used by the application, or %NULL.

    If #GApplication is using its D-Bus backend then this function will return
    the #GDBusConnection being used for uniqueness and communication with the
    desktop environment and other instances of the application.

    If #GApplication is not using D-Bus then this function will return %NULL.
    This includes the situation where the D-Bus backend would normally be in use
    but we were unable to connect to the bus.

    This function must not be called before the application has been registered.
    See g_application_get_is_registered(). *)

external get_application_id : t -> string option
  = "ml_g_application_get_application_id"
(** Gets the unique identifier for @application. *)

external bind_busy_property : t -> [ `object_ ] Gobject.obj -> string -> unit
  = "ml_g_application_bind_busy_property"
(** Marks @application as busy (see g_application_mark_busy()) while
@property on @object is %TRUE.

The binding holds a reference to @application while it is active, but
not to @object. Instead, the binding is destroyed when @object is
finalized. *)

external activate : t -> unit = "ml_g_application_activate"
(** Activates the application.

    In essence, this results in the #GApplication::activate signal being emitted
    in the primary instance.

    The application must be registered before calling this function. *)

(* Properties *)

val on_activate :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_command_line :
  ?after:bool ->
  t ->
  callback:(command_line:Application_command_line.t -> int) ->
  Gobject.Signal.handler_id

val on_name_lost :
  ?after:bool -> t -> callback:(unit -> bool) -> Gobject.Signal.handler_id

val on_shutdown :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_startup :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
