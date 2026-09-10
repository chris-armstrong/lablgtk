(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec App_info : sig
  type t = [ `app_info ] Gobject.obj

  external from_gobject : 'a Gobject.obj -> t = "ml_gio_app_info_from_gobject"

  (* Methods *)

  external supports_uris : t -> bool = "ml_g_app_info_supports_uris"
  (** Checks if the application supports reading files and directories from
      URIs. *)

  external supports_files : t -> bool = "ml_g_app_info_supports_files"
  (** Checks if the application accepts files as arguments. *)

  external should_show : t -> bool = "ml_g_app_info_should_show"
  (** Checks if the application info should be shown in menus that list
      available applications. *)

  external set_as_last_used_for_type : t -> string -> (bool, GError.t) result
    = "ml_g_app_info_set_as_last_used_for_type"
  (** Sets the application as the last used application for a given type. This
      will make the application appear as first in the list returned by
      [func@Gio.AppInfo.get_recommended_for_type], regardless of the default
      application for that content type. *)

  external set_as_default_for_type : t -> string -> (bool, GError.t) result
    = "ml_g_app_info_set_as_default_for_type"
  (** Sets the application as the default handler for a given type. *)

  external set_as_default_for_extension : t -> string -> (bool, GError.t) result
    = "ml_g_app_info_set_as_default_for_extension"
  (** Sets the application as the default handler for the given file extension.
  *)

  external remove_supports_type : t -> string -> (bool, GError.t) result
    = "ml_g_app_info_remove_supports_type"
  (** Removes a supported type from an application, if possible. *)

  external launch_uris_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_app_info_launch_uris_finish"
  (** Finishes a [method@Gio.AppInfo.launch_uris_async] operation. *)

  external launch_uris :
    t ->
    string list option ->
    App_launch_context.t option ->
    (bool, GError.t) result = "ml_g_app_info_launch_uris"
  (** Launches the application. This passes the @uris to the launched application
  as arguments, using the optional @context to get information
  about the details of the launcher (like what screen it is on).
  On error, @error will be set accordingly. If the application only supports
  one URI per invocation as part of their command-line, multiple instances
  of the application will be spawned.

  To launch the application without arguments pass a `NULL` @uris list.

  Note that even if the launch is successful the application launched
  can fail to start if it runs into problems during startup. There is
  no way to detect this. *)

  external launch :
    t ->
    File.t list option ->
    App_launch_context.t option ->
    (bool, GError.t) result = "ml_g_app_info_launch"
  (** Launches the application. Passes @files to the launched application
  as arguments, using the optional @context to get information
  about the details of the launcher (like what screen it is on).
  On error, @error will be set accordingly.

  To launch the application without arguments pass a `NULL` @files list.

  Note that even if the launch is successful the application launched
  can fail to start if it runs into problems during startup. There is
  no way to detect this.

  Some URIs can be changed when passed through a GFile (for instance
  unsupported URIs with strange formats like mailto:), so if you have
  a textual URI you want to pass in as argument, consider using
  [method@Gio.AppInfo.launch_uris] instead.

  The launched application inherits the environment of the launching
  process, but it can be modified with [method@Gio.AppLaunchContext.setenv]
  and [method@Gio.AppLaunchContext.unsetenv].

  On UNIX, this function sets the `GIO_LAUNCHED_DESKTOP_FILE`
  environment variable with the path of the launched desktop file and
  `GIO_LAUNCHED_DESKTOP_FILE_PID` to the process id of the launched
  process. This can be used to ignore `GIO_LAUNCHED_DESKTOP_FILE`,
  should it be inherited by further processes. The `DISPLAY`,
  `XDG_ACTIVATION_TOKEN` and `DESKTOP_STARTUP_ID` environment
  variables are also set, based on information provided in @context. *)

  external get_supported_types : t -> string array
    = "ml_g_app_info_get_supported_types"
  (** Retrieves the list of content types that @app_info claims to support.
  If this information is not provided by the environment, this function
  will return `NULL`.

  This function does not take in consideration associations added with
  [method@Gio.AppInfo.add_supports_type], but only those exported directly by
  the application. *)

  external get_name : t -> string = "ml_g_app_info_get_name"
  (** Gets the installed name of the application. *)

  external get_id : t -> string option = "ml_g_app_info_get_id"
  (** Gets the ID of an application. An id is a string that identifies the
  application. The exact format of the id is platform dependent. For instance,
  on Unix this is the desktop file id from the xdg menu specification.

  Note that the returned ID may be `NULL`, depending on how the @appinfo has
  been constructed. *)

  external get_icon : t -> Icon.t option = "ml_g_app_info_get_icon"
  (** Gets the icon for the application. *)

  external get_executable : t -> string = "ml_g_app_info_get_executable"
  (** Gets the executable’s name for the installed application.

      This is intended to be used for debugging or labelling what program is
      going to be run. To launch the executable, use [method@Gio.AppInfo.launch]
      and related functions, rather than spawning the return value from this
      function. *)

  external get_display_name : t -> string = "ml_g_app_info_get_display_name"
  (** Gets the display name of the application. The display name is often more
      descriptive to the user than the name itself. *)

  external get_description : t -> string option
    = "ml_g_app_info_get_description"
  (** Gets a human-readable description of an installed application. *)

  external get_commandline : t -> string option
    = "ml_g_app_info_get_commandline"
  (** Gets the commandline with which the application will be started. *)

  external equal : t -> t -> bool = "ml_g_app_info_equal"
  (** Checks if two [iface@Gio.AppInfo]s are equal.

      Note that the check *may not* compare each individual field, and only does
      an identity check. In case detecting changes in the contents is needed,
      program code must additionally compare relevant fields. *)

  external dup : t -> t = "ml_g_app_info_dup"
  (** Creates a duplicate of a [iface@Gio.AppInfo]. *)

  external delete : t -> bool = "ml_g_app_info_delete"
  (** Tries to delete a [iface@Gio.AppInfo].

      On some platforms, there may be a difference between user-defined
      [iface@Gio.AppInfo]s which can be deleted, and system-wide ones which
      cannot. See [method@Gio.AppInfo.can_delete]. *)

  external can_remove_supports_type : t -> bool
    = "ml_g_app_info_can_remove_supports_type"
  (** Checks if a supported content type can be removed from an application. *)

  external can_delete : t -> bool = "ml_g_app_info_can_delete"
  (** Obtains the information whether the [iface@Gio.AppInfo] can be deleted.
      See [method@Gio.AppInfo.delete]. *)

  external add_supports_type : t -> string -> (bool, GError.t) result
    = "ml_g_app_info_add_supports_type"
  (** Adds a content type to the application information to indicate the
      application is capable of opening files with the given content type. *)
end = struct
  type t = [ `app_info ] Gobject.obj

  external from_gobject : 'a Gobject.obj -> t = "ml_gio_app_info_from_gobject"

  (* Methods *)

  external supports_uris : t -> bool = "ml_g_app_info_supports_uris"
  (** Checks if the application supports reading files and directories from
      URIs. *)

  external supports_files : t -> bool = "ml_g_app_info_supports_files"
  (** Checks if the application accepts files as arguments. *)

  external should_show : t -> bool = "ml_g_app_info_should_show"
  (** Checks if the application info should be shown in menus that list
      available applications. *)

  external set_as_last_used_for_type : t -> string -> (bool, GError.t) result
    = "ml_g_app_info_set_as_last_used_for_type"
  (** Sets the application as the last used application for a given type. This
      will make the application appear as first in the list returned by
      [func@Gio.AppInfo.get_recommended_for_type], regardless of the default
      application for that content type. *)

  external set_as_default_for_type : t -> string -> (bool, GError.t) result
    = "ml_g_app_info_set_as_default_for_type"
  (** Sets the application as the default handler for a given type. *)

  external set_as_default_for_extension : t -> string -> (bool, GError.t) result
    = "ml_g_app_info_set_as_default_for_extension"
  (** Sets the application as the default handler for the given file extension.
  *)

  external remove_supports_type : t -> string -> (bool, GError.t) result
    = "ml_g_app_info_remove_supports_type"
  (** Removes a supported type from an application, if possible. *)

  external launch_uris_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_app_info_launch_uris_finish"
  (** Finishes a [method@Gio.AppInfo.launch_uris_async] operation. *)

  external launch_uris :
    t ->
    string list option ->
    App_launch_context.t option ->
    (bool, GError.t) result = "ml_g_app_info_launch_uris"
  (** Launches the application. This passes the @uris to the launched application
  as arguments, using the optional @context to get information
  about the details of the launcher (like what screen it is on).
  On error, @error will be set accordingly. If the application only supports
  one URI per invocation as part of their command-line, multiple instances
  of the application will be spawned.

  To launch the application without arguments pass a `NULL` @uris list.

  Note that even if the launch is successful the application launched
  can fail to start if it runs into problems during startup. There is
  no way to detect this. *)

  external launch :
    t ->
    File.t list option ->
    App_launch_context.t option ->
    (bool, GError.t) result = "ml_g_app_info_launch"
  (** Launches the application. Passes @files to the launched application
  as arguments, using the optional @context to get information
  about the details of the launcher (like what screen it is on).
  On error, @error will be set accordingly.

  To launch the application without arguments pass a `NULL` @files list.

  Note that even if the launch is successful the application launched
  can fail to start if it runs into problems during startup. There is
  no way to detect this.

  Some URIs can be changed when passed through a GFile (for instance
  unsupported URIs with strange formats like mailto:), so if you have
  a textual URI you want to pass in as argument, consider using
  [method@Gio.AppInfo.launch_uris] instead.

  The launched application inherits the environment of the launching
  process, but it can be modified with [method@Gio.AppLaunchContext.setenv]
  and [method@Gio.AppLaunchContext.unsetenv].

  On UNIX, this function sets the `GIO_LAUNCHED_DESKTOP_FILE`
  environment variable with the path of the launched desktop file and
  `GIO_LAUNCHED_DESKTOP_FILE_PID` to the process id of the launched
  process. This can be used to ignore `GIO_LAUNCHED_DESKTOP_FILE`,
  should it be inherited by further processes. The `DISPLAY`,
  `XDG_ACTIVATION_TOKEN` and `DESKTOP_STARTUP_ID` environment
  variables are also set, based on information provided in @context. *)

  external get_supported_types : t -> string array
    = "ml_g_app_info_get_supported_types"
  (** Retrieves the list of content types that @app_info claims to support.
  If this information is not provided by the environment, this function
  will return `NULL`.

  This function does not take in consideration associations added with
  [method@Gio.AppInfo.add_supports_type], but only those exported directly by
  the application. *)

  external get_name : t -> string = "ml_g_app_info_get_name"
  (** Gets the installed name of the application. *)

  external get_id : t -> string option = "ml_g_app_info_get_id"
  (** Gets the ID of an application. An id is a string that identifies the
  application. The exact format of the id is platform dependent. For instance,
  on Unix this is the desktop file id from the xdg menu specification.

  Note that the returned ID may be `NULL`, depending on how the @appinfo has
  been constructed. *)

  external get_icon : t -> Icon.t option = "ml_g_app_info_get_icon"
  (** Gets the icon for the application. *)

  external get_executable : t -> string = "ml_g_app_info_get_executable"
  (** Gets the executable’s name for the installed application.

      This is intended to be used for debugging or labelling what program is
      going to be run. To launch the executable, use [method@Gio.AppInfo.launch]
      and related functions, rather than spawning the return value from this
      function. *)

  external get_display_name : t -> string = "ml_g_app_info_get_display_name"
  (** Gets the display name of the application. The display name is often more
      descriptive to the user than the name itself. *)

  external get_description : t -> string option
    = "ml_g_app_info_get_description"
  (** Gets a human-readable description of an installed application. *)

  external get_commandline : t -> string option
    = "ml_g_app_info_get_commandline"
  (** Gets the commandline with which the application will be started. *)

  external equal : t -> t -> bool = "ml_g_app_info_equal"
  (** Checks if two [iface@Gio.AppInfo]s are equal.

      Note that the check *may not* compare each individual field, and only does
      an identity check. In case detecting changes in the contents is needed,
      program code must additionally compare relevant fields. *)

  external dup : t -> t = "ml_g_app_info_dup"
  (** Creates a duplicate of a [iface@Gio.AppInfo]. *)

  external delete : t -> bool = "ml_g_app_info_delete"
  (** Tries to delete a [iface@Gio.AppInfo].

      On some platforms, there may be a difference between user-defined
      [iface@Gio.AppInfo]s which can be deleted, and system-wide ones which
      cannot. See [method@Gio.AppInfo.can_delete]. *)

  external can_remove_supports_type : t -> bool
    = "ml_g_app_info_can_remove_supports_type"
  (** Checks if a supported content type can be removed from an application. *)

  external can_delete : t -> bool = "ml_g_app_info_can_delete"
  (** Obtains the information whether the [iface@Gio.AppInfo] can be deleted.
      See [method@Gio.AppInfo.delete]. *)

  external add_supports_type : t -> string -> (bool, GError.t) result
    = "ml_g_app_info_add_supports_type"
  (** Adds a content type to the application information to indicate the
      application is capable of opening files with the given content type. *)
end

and App_launch_context : sig
  type t = [ `app_launch_context | `object_ ] Gobject.obj

  external new_ : unit -> t = "ml_g_app_launch_context_new"
  (** Create a new AppLaunchContext *)

  (* Methods *)

  external unsetenv : t -> string -> unit = "ml_g_app_launch_context_unsetenv"
  (** Arranges for @variable to be unset in the child’s environment when @context
  is used to launch an application. *)

  external setenv : t -> string -> string -> unit
    = "ml_g_app_launch_context_setenv"
  (** Arranges for @variable to be set to @value in the child’s environment when
  @context is used to launch an application. *)

  external launch_failed : t -> string -> unit
    = "ml_g_app_launch_context_launch_failed"
  (** Called when an application has failed to launch, so that it can cancel the
      application startup notification started in
      [method@Gio.AppLaunchContext.get_startup_notify_id]. *)

  external get_startup_notify_id :
    t -> App_info.t option -> File.t list option -> string option
    = "ml_g_app_launch_context_get_startup_notify_id"
  (** Initiates startup notification for the application and returns the
  `XDG_ACTIVATION_TOKEN` or `DESKTOP_STARTUP_ID` for the launched operation,
  if supported.

  The returned token may be referred to equivalently as an ‘activation token’
  (using Wayland terminology) or a ‘startup sequence ID’ (using X11 terminology).
  The two [are interoperable](https://gitlab.freedesktop.org/wayland/wayland-protocols/-/blob/main/staging/xdg-activation/x11-interoperation.rst).

  Activation tokens are defined in the [XDG Activation Protocol](https://wayland.app/protocols/xdg-activation-v1),
  and startup notification IDs are defined in the
  [freedesktop.org Startup Notification Protocol](http://standards.freedesktop.org/startup-notification-spec/startup-notification-latest.txt).

  Support for the XDG Activation Protocol was added in GLib 2.76.
  Since GLib 2.82 @info and @files can be `NULL`. If that’s not supported by the backend,
  the returned token will be `NULL`. *)

  external get_environment : t -> string array
    = "ml_g_app_launch_context_get_environment"
  (** Gets the complete environment variable list to be passed to
  the child process when @context is used to launch an application.
  This is a `NULL`-terminated array of strings, where each string has
  the form `KEY=VALUE`. *)

  external get_display : t -> App_info.t -> File.t list -> string option
    = "ml_g_app_launch_context_get_display"
  (** Gets the display string for the @context. This is used to ensure new
  applications are started on the same display as the launching
  application, by setting the `DISPLAY` environment variable. *)

  val on_launch_failed :
    ?after:bool ->
    t ->
    callback:(startup_notify_id:string -> unit) ->
    Gobject.Signal.handler_id

  val on_launch_started :
    ?after:bool ->
    t ->
    callback:(info:App_info.t -> platform_data:Gvariant.t -> unit) ->
    Gobject.Signal.handler_id

  val on_launched :
    ?after:bool ->
    t ->
    callback:(info:App_info.t -> platform_data:Gvariant.t -> unit) ->
    Gobject.Signal.handler_id
end = struct
  type t = [ `app_launch_context | `object_ ] Gobject.obj

  external new_ : unit -> t = "ml_g_app_launch_context_new"
  (** Create a new AppLaunchContext *)

  (* Methods *)

  external unsetenv : t -> string -> unit = "ml_g_app_launch_context_unsetenv"
  (** Arranges for @variable to be unset in the child’s environment when @context
  is used to launch an application. *)

  external setenv : t -> string -> string -> unit
    = "ml_g_app_launch_context_setenv"
  (** Arranges for @variable to be set to @value in the child’s environment when
  @context is used to launch an application. *)

  external launch_failed : t -> string -> unit
    = "ml_g_app_launch_context_launch_failed"
  (** Called when an application has failed to launch, so that it can cancel the
      application startup notification started in
      [method@Gio.AppLaunchContext.get_startup_notify_id]. *)

  external get_startup_notify_id :
    t -> App_info.t option -> File.t list option -> string option
    = "ml_g_app_launch_context_get_startup_notify_id"
  (** Initiates startup notification for the application and returns the
  `XDG_ACTIVATION_TOKEN` or `DESKTOP_STARTUP_ID` for the launched operation,
  if supported.

  The returned token may be referred to equivalently as an ‘activation token’
  (using Wayland terminology) or a ‘startup sequence ID’ (using X11 terminology).
  The two [are interoperable](https://gitlab.freedesktop.org/wayland/wayland-protocols/-/blob/main/staging/xdg-activation/x11-interoperation.rst).

  Activation tokens are defined in the [XDG Activation Protocol](https://wayland.app/protocols/xdg-activation-v1),
  and startup notification IDs are defined in the
  [freedesktop.org Startup Notification Protocol](http://standards.freedesktop.org/startup-notification-spec/startup-notification-latest.txt).

  Support for the XDG Activation Protocol was added in GLib 2.76.
  Since GLib 2.82 @info and @files can be `NULL`. If that’s not supported by the backend,
  the returned token will be `NULL`. *)

  external get_environment : t -> string array
    = "ml_g_app_launch_context_get_environment"
  (** Gets the complete environment variable list to be passed to
  the child process when @context is used to launch an application.
  This is a `NULL`-terminated array of strings, where each string has
  the form `KEY=VALUE`. *)

  external get_display : t -> App_info.t -> File.t list -> string option
    = "ml_g_app_launch_context_get_display"
  (** Gets the display string for the @context. This is used to ensure new
  applications are started on the same display as the launching
  application, by setting the `DISPLAY` environment variable. *)

  let on_launch_failed ?after obj ~callback =
    let closure =
      Gobject.Closure.create (fun argv ->
          let startup_notify_id =
            let v = Gobject.Closure.nth argv ~pos:1 in
            Gobject.Value.get_string_exn v
          in
          callback ~startup_notify_id)
    in
    Gobject.Signal.connect obj ~name:"launch-failed" ~callback:closure
      ~after:(Option.value after ~default:false)

  let on_launch_started ?after obj ~callback =
    let closure =
      Gobject.Closure.create (fun argv ->
          let info =
            let v = Gobject.Closure.nth argv ~pos:1 in
            Gobject.Value.get_object_exn v
          in
          let platform_data =
            let v = Gobject.Closure.nth argv ~pos:2 in
            Gobject.Value.get_variant v
          in
          callback ~info ~platform_data)
    in
    Gobject.Signal.connect obj ~name:"launch-started" ~callback:closure
      ~after:(Option.value after ~default:false)

  let on_launched ?after obj ~callback =
    let closure =
      Gobject.Closure.create (fun argv ->
          let info =
            let v = Gobject.Closure.nth argv ~pos:1 in
            Gobject.Value.get_object_exn v
          in
          let platform_data =
            let v = Gobject.Closure.nth argv ~pos:2 in
            Gobject.Value.get_variant v
          in
          callback ~info ~platform_data)
    in
    Gobject.Signal.connect obj ~name:"launched" ~callback:closure
      ~after:(Option.value after ~default:false)
end

and Drive : sig
  type t = [ `drive ] Gobject.obj

  external from_gobject : 'a Gobject.obj -> t = "ml_gio_drive_from_gobject"

  (* Methods *)

  external stop_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_drive_stop_finish"
  (** Finishes stopping a drive. *)

  external start_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_drive_start_finish"
  (** Finishes starting a drive. *)

  external poll_for_media_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_drive_poll_for_media_finish"
  (** Finishes an operation started with g_drive_poll_for_media() on a drive. *)

  external is_removable : t -> bool = "ml_g_drive_is_removable"
  (** Checks if the #GDrive and/or its media is considered removable by the
      user. See g_drive_is_media_removable(). *)

  external is_media_removable : t -> bool = "ml_g_drive_is_media_removable"
  (** Checks if the @drive supports removable media. *)

  external is_media_check_automatic : t -> bool
    = "ml_g_drive_is_media_check_automatic"
  (** Checks if @drive is capable of automatically detecting media changes. *)

  external has_volumes : t -> bool = "ml_g_drive_has_volumes"
  (** Check if @drive has any mountable volumes. *)

  external has_media : t -> bool = "ml_g_drive_has_media"
  (** Checks if the @drive has media. Note that the OS may not be polling
  the drive for media changes; see g_drive_is_media_check_automatic()
  for more details. *)

  external get_volumes : t -> Volume.t list = "ml_g_drive_get_volumes"
  (** Get a list of mountable volumes for @drive.

  The returned list should be freed with g_list_free(), after
  its elements have been unreffed with g_object_unref(). *)

  external get_symbolic_icon : t -> Icon.t = "ml_g_drive_get_symbolic_icon"
  (** Gets the icon for @drive. *)

  external get_start_stop_type : t -> Gio_enums.drivestartstoptype
    = "ml_g_drive_get_start_stop_type"
  (** Gets a hint about how a drive can be started/stopped. *)

  external get_sort_key : t -> string option = "ml_g_drive_get_sort_key"
  (** Gets the sort key for @drive, if any. *)

  external get_name : t -> string = "ml_g_drive_get_name"
  (** Gets the name of @drive. *)

  external get_identifier : t -> string -> string option
    = "ml_g_drive_get_identifier"
  (** Gets the identifier of the given kind for @drive. The only
  identifier currently available is
  %G_DRIVE_IDENTIFIER_KIND_UNIX_DEVICE. *)

  external get_icon : t -> Icon.t = "ml_g_drive_get_icon"
  (** Gets the icon for @drive. *)

  external enumerate_identifiers : t -> string array
    = "ml_g_drive_enumerate_identifiers"
  (** Gets the kinds of identifiers that @drive has.
  Use g_drive_get_identifier() to obtain the identifiers
  themselves. *)

  external eject_with_operation_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_drive_eject_with_operation_finish"
  (** Finishes ejecting a drive. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external eject_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_drive_eject_finish"
  (** Finishes ejecting a drive. *)

  external can_stop : t -> bool = "ml_g_drive_can_stop"
  (** Checks if a drive can be stopped. *)

  external can_start_degraded : t -> bool = "ml_g_drive_can_start_degraded"
  (** Checks if a drive can be started degraded. *)

  external can_start : t -> bool = "ml_g_drive_can_start"
  (** Checks if a drive can be started. *)

  external can_poll_for_media : t -> bool = "ml_g_drive_can_poll_for_media"
  (** Checks if a drive can be polled for media changes. *)

  external can_eject : t -> bool = "ml_g_drive_can_eject"
  (** Checks if a drive can be ejected. *)

  val on_changed :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_disconnected :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_eject_button :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_stop_button :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
end = struct
  type t = [ `drive ] Gobject.obj

  external from_gobject : 'a Gobject.obj -> t = "ml_gio_drive_from_gobject"

  (* Methods *)

  external stop_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_drive_stop_finish"
  (** Finishes stopping a drive. *)

  external start_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_drive_start_finish"
  (** Finishes starting a drive. *)

  external poll_for_media_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_drive_poll_for_media_finish"
  (** Finishes an operation started with g_drive_poll_for_media() on a drive. *)

  external is_removable : t -> bool = "ml_g_drive_is_removable"
  (** Checks if the #GDrive and/or its media is considered removable by the
      user. See g_drive_is_media_removable(). *)

  external is_media_removable : t -> bool = "ml_g_drive_is_media_removable"
  (** Checks if the @drive supports removable media. *)

  external is_media_check_automatic : t -> bool
    = "ml_g_drive_is_media_check_automatic"
  (** Checks if @drive is capable of automatically detecting media changes. *)

  external has_volumes : t -> bool = "ml_g_drive_has_volumes"
  (** Check if @drive has any mountable volumes. *)

  external has_media : t -> bool = "ml_g_drive_has_media"
  (** Checks if the @drive has media. Note that the OS may not be polling
  the drive for media changes; see g_drive_is_media_check_automatic()
  for more details. *)

  external get_volumes : t -> Volume.t list = "ml_g_drive_get_volumes"
  (** Get a list of mountable volumes for @drive.

  The returned list should be freed with g_list_free(), after
  its elements have been unreffed with g_object_unref(). *)

  external get_symbolic_icon : t -> Icon.t = "ml_g_drive_get_symbolic_icon"
  (** Gets the icon for @drive. *)

  external get_start_stop_type : t -> Gio_enums.drivestartstoptype
    = "ml_g_drive_get_start_stop_type"
  (** Gets a hint about how a drive can be started/stopped. *)

  external get_sort_key : t -> string option = "ml_g_drive_get_sort_key"
  (** Gets the sort key for @drive, if any. *)

  external get_name : t -> string = "ml_g_drive_get_name"
  (** Gets the name of @drive. *)

  external get_identifier : t -> string -> string option
    = "ml_g_drive_get_identifier"
  (** Gets the identifier of the given kind for @drive. The only
  identifier currently available is
  %G_DRIVE_IDENTIFIER_KIND_UNIX_DEVICE. *)

  external get_icon : t -> Icon.t = "ml_g_drive_get_icon"
  (** Gets the icon for @drive. *)

  external enumerate_identifiers : t -> string array
    = "ml_g_drive_enumerate_identifiers"
  (** Gets the kinds of identifiers that @drive has.
  Use g_drive_get_identifier() to obtain the identifiers
  themselves. *)

  external eject_with_operation_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_drive_eject_with_operation_finish"
  (** Finishes ejecting a drive. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external eject_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_drive_eject_finish"
  (** Finishes ejecting a drive. *)

  external can_stop : t -> bool = "ml_g_drive_can_stop"
  (** Checks if a drive can be stopped. *)

  external can_start_degraded : t -> bool = "ml_g_drive_can_start_degraded"
  (** Checks if a drive can be started degraded. *)

  external can_start : t -> bool = "ml_g_drive_can_start"
  (** Checks if a drive can be started. *)

  external can_poll_for_media : t -> bool = "ml_g_drive_can_poll_for_media"
  (** Checks if a drive can be polled for media changes. *)

  external can_eject : t -> bool = "ml_g_drive_can_eject"
  (** Checks if a drive can be ejected. *)

  let on_changed ?after obj ~callback =
    Gobject.Signal.connect_simple obj ~name:"changed" ~callback
      ~after:(Option.value after ~default:false)

  let on_disconnected ?after obj ~callback =
    Gobject.Signal.connect_simple obj ~name:"disconnected" ~callback
      ~after:(Option.value after ~default:false)

  let on_eject_button ?after obj ~callback =
    Gobject.Signal.connect_simple obj ~name:"eject-button" ~callback
      ~after:(Option.value after ~default:false)

  let on_stop_button ?after obj ~callback =
    Gobject.Signal.connect_simple obj ~name:"stop-button" ~callback
      ~after:(Option.value after ~default:false)
end

and File : sig
  type t = [ `file ] Gobject.obj

  external from_gobject : 'a Gobject.obj -> t = "ml_gio_file_from_gobject"

  (* Methods *)

  external unmount_mountable_with_operation_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_unmount_mountable_with_operation_finish"
  (** Finishes an unmount operation, see
      g_file_unmount_mountable_with_operation() for details.

      Finish an asynchronous unmount operation that was started with
      g_file_unmount_mountable_with_operation(). *)

  external unmount_mountable_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_unmount_mountable_finish"
  (** Finishes an unmount operation, see g_file_unmount_mountable() for details.

      Finish an asynchronous unmount operation that was started with
      g_file_unmount_mountable(). *)

  external trash_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_trash_finish"
  (** Finishes an asynchronous file trashing operation, started with
      g_file_trash_async(). *)

  external trash : t -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_file_trash"
  (** Sends @file to the "Trashcan", if possible. This is similar to
  deleting it, but the user can recover it before emptying the trashcan.
  Trashing is disabled for system mounts by default (see
  g_unix_mount_entry_is_system_internal()), so this call can return the
  %G_IO_ERROR_NOT_SUPPORTED error. Since GLib 2.66, the `x-gvfs-notrash` unix
  mount option can be used to disable g_file_trash() support for particular
  mounts, the %G_IO_ERROR_NOT_SUPPORTED error will be returned in that case.
  Since 2.82, the `x-gvfs-trash` unix mount option can be used to enable
  g_file_trash() support for particular system mounts.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external supports_thread_contexts : t -> bool
    = "ml_g_file_supports_thread_contexts"
  (** Checks if @file supports thread-default main contexts
  (see [method@GLib.MainContext.push_thread_default])
  If this returns %FALSE, you cannot perform asynchronous operations on
  @file in a thread that has a thread-default context. *)

  external stop_mountable_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_stop_mountable_finish"
  (** Finishes a stop operation, see g_file_stop_mountable() for details.

      Finish an asynchronous stop operation that was started with
      g_file_stop_mountable(). *)

  external start_mountable_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_start_mountable_finish"
  (** Finishes a start operation. See g_file_start_mountable() for details.

      Finish an asynchronous start operation that was started with
      g_file_start_mountable(). *)

  external set_display_name_finish : t -> Async_result.t -> (t, GError.t) result
    = "ml_g_file_set_display_name_finish"
  (** Finishes setting a display name started with
      g_file_set_display_name_async(). *)

  external set_display_name :
    t -> string -> Cancellable.t option -> (t, GError.t) result
    = "ml_g_file_set_display_name"
  (** Renames @file to the specified display name.

  The display name is converted from UTF-8 to the correct encoding
  for the target filesystem if possible and the @file is renamed to this.

  If you want to implement a rename operation in the user interface the
  edit name (%G_FILE_ATTRIBUTE_STANDARD_EDIT_NAME) should be used as the
  initial value in the rename widget, and then the result after editing
  should be passed to g_file_set_display_name().

  On success the resulting converted filename is returned.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attributes_from_info :
    t ->
    File_info.t ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attributes_from_info"
  (** Tries to set all attributes in the #GFileInfo on the target
  values, not stopping on the first error.

  If there is any error during this operation then @error will
  be set to the first error. Error on particular fields are flagged
  by setting the "status" field in the attribute value to
  %G_FILE_ATTRIBUTE_STATUS_ERROR_SETTING, which means you can
  also detect further errors.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attribute_uint64 :
    t ->
    string ->
    UInt64.t ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attribute_uint64"
  (** Sets @attribute of type %G_FILE_ATTRIBUTE_TYPE_UINT64 to @value.
  If @attribute is of a different type, this operation will fail.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attribute_uint32 :
    t ->
    string ->
    UInt32.t ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attribute_uint32"
  (** Sets @attribute of type %G_FILE_ATTRIBUTE_TYPE_UINT32 to @value.
  If @attribute is of a different type, this operation will fail.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attribute_string :
    t ->
    string ->
    string ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attribute_string"
  (** Sets @attribute of type %G_FILE_ATTRIBUTE_TYPE_STRING to @value.
  If @attribute is of a different type, this operation will fail.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attribute_int64 :
    t ->
    string ->
    int64 ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attribute_int64"
  (** Sets @attribute of type %G_FILE_ATTRIBUTE_TYPE_INT64 to @value.
  If @attribute is of a different type, this operation will fail.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attribute_int32 :
    t ->
    string ->
    Int32.t ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attribute_int32"
  (** Sets @attribute of type %G_FILE_ATTRIBUTE_TYPE_INT32 to @value.
  If @attribute is of a different type, this operation will fail.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attribute_byte_string :
    t ->
    string ->
    string ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attribute_byte_string"
  (** Sets @attribute of type %G_FILE_ATTRIBUTE_TYPE_BYTE_STRING to @value.
  If @attribute is of a different type, this operation will fail,
  returning %FALSE.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external resolve_relative_path : t -> string -> t
    = "ml_g_file_resolve_relative_path"
  (** Resolves a relative path for @file to an absolute path.

  This call does no blocking I/O.

  If the @relative_path is an absolute path name, the resolution
  is done absolutely (without taking @file path as base). *)

  external replace_readwrite_finish :
    t -> Async_result.t -> (File_io_stream.t, GError.t) result
    = "ml_g_file_replace_readwrite_finish"
  (** Finishes an asynchronous file replace operation started with
      g_file_replace_readwrite_async(). *)

  external replace_readwrite :
    t ->
    string option ->
    bool ->
    Gio_enums.filecreateflags ->
    Cancellable.t option ->
    (File_io_stream.t, GError.t) result = "ml_g_file_replace_readwrite"
  (** Returns an output stream for overwriting the file in readwrite mode,
      possibly creating a backup copy of the file first. If the file doesn't
      exist, it will be created.

      For details about the behaviour, see g_file_replace() which does the same
      thing but returns an output stream only.

      Note that in many non-local file cases read and write streams are not
      supported, so make sure you really need to do read and write streaming,
      rather than just opening for reading or writing. *)

  external replace_finish :
    t -> Async_result.t -> (File_output_stream.t, GError.t) result
    = "ml_g_file_replace_finish"
  (** Finishes an asynchronous file replace operation started with
      g_file_replace_async(). *)

  external replace :
    t ->
    string option ->
    bool ->
    Gio_enums.filecreateflags ->
    Cancellable.t option ->
    (File_output_stream.t, GError.t) result = "ml_g_file_replace"
  (** Returns an output stream for overwriting the file, possibly
  creating a backup copy of the file first. If the file doesn't exist,
  it will be created.

  This will try to replace the file in the safest way possible so
  that any errors during the writing will not affect an already
  existing copy of the file. For instance, for local files it
  may write to a temporary file and then atomically rename over
  the destination when the stream is closed.

  By default files created are generally readable by everyone,
  but if you pass %G_FILE_CREATE_PRIVATE in @flags the file
  will be made readable only to the current user, to the level that
  is supported on the target filesystem.

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  If you pass in a non-%NULL @etag value and @file already exists, then
  this value is compared to the current entity tag of the file, and if
  they differ an %G_IO_ERROR_WRONG_ETAG error is returned. This
  generally means that the file has been changed since you last read
  it. You can get the new etag from g_file_output_stream_get_etag()
  after you've finished writing and closed the #GFileOutputStream. When
  you load a new file you can use g_file_input_stream_query_info() to
  get the etag of the file.

  If @make_backup is %TRUE, this function will attempt to make a
  backup of the current file before overwriting it. If this fails
  a %G_IO_ERROR_CANT_CREATE_BACKUP error will be returned. If you
  want to replace anyway, try again with @make_backup set to %FALSE.

  If the file is a directory the %G_IO_ERROR_IS_DIRECTORY error will
  be returned, and if the file is some other form of non-regular file
  then a %G_IO_ERROR_NOT_REGULAR_FILE error will be returned. Some
  file systems don't allow all file names, and may return an
  %G_IO_ERROR_INVALID_FILENAME error, and if the name is to long
  %G_IO_ERROR_FILENAME_TOO_LONG will be returned. Other errors are
  possible too, and depend on what kind of filesystem the file is on. *)

  external read_finish :
    t -> Async_result.t -> (File_input_stream.t, GError.t) result
    = "ml_g_file_read_finish"
  (** Finishes an asynchronous file read operation started with
      g_file_read_async(). *)

  external read :
    t -> Cancellable.t option -> (File_input_stream.t, GError.t) result
    = "ml_g_file_read"
  (** Opens a file for reading. The result is a #GFileInputStream that
  can be used to read the contents of the file.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned.

  If the file does not exist, the %G_IO_ERROR_NOT_FOUND error will be
  returned. If the file is a directory, the %G_IO_ERROR_IS_DIRECTORY
  error will be returned. Other errors are possible too, and depend
  on what kind of filesystem the file is on. *)

  external query_writable_namespaces :
    t -> Cancellable.t option -> (File_attribute_info_list.t, GError.t) result
    = "ml_g_file_query_writable_namespaces"
  (** Obtain the list of attribute namespaces where new attributes
  can be created by a user. An example of this is extended
  attributes (in the "xattr" namespace).

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external query_settable_attributes :
    t -> Cancellable.t option -> (File_attribute_info_list.t, GError.t) result
    = "ml_g_file_query_settable_attributes"
  (** Obtain the list of settable attributes for the file.

  Returns the type and full attribute name of all the attributes
  that can be set on this file. This doesn't mean setting it will
  always succeed though, you might get an access failure, or some
  specific file may not support a specific attribute.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external query_info_finish :
    t -> Async_result.t -> (File_info.t, GError.t) result
    = "ml_g_file_query_info_finish"
  (** Finishes an asynchronous file info query. See g_file_query_info_async().
  *)

  external query_info :
    t ->
    string ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (File_info.t, GError.t) result = "ml_g_file_query_info"
  (** Gets the requested information about specified @file.

  The result is a [class@Gio.FileInfo] object that contains key-value
  attributes (such as the type or size of the file).

  The @attributes value is a string that specifies the file
  attributes that should be gathered. It is not an error if
  it’s not possible to read a particular requested attribute
  from a file — it just won't be set. In particular this means that if a file
  is inaccessible (due to being in a folder with restrictive permissions), for
  example, you can expect the returned [class@Gio.FileInfo] to have very few
  attributes set. You should check whether an attribute is set using
  [method@Gio.FileInfo.has_attribute] before trying to retrieve its value.

  It is guaranteed that if any of the following attributes are listed in
  @attributes, they will always be set in the returned [class@Gio.FileInfo],
  even if the user doesn’t have permissions to access the file:

   - [const@Gio.FILE_ATTRIBUTE_STANDARD_NAME]
   - [const@Gio.FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME]

  @attributes should be a comma-separated list of attributes or attribute
  wildcards. The wildcard `"*"` means all attributes, and a wildcard like
  `"standard::*"` means all attributes in the standard namespace.
  An example attribute query might be `"standard::*,owner::user"`.
  The standard attributes are available as defines, like
  [const@Gio.FILE_ATTRIBUTE_STANDARD_NAME].

  If @cancellable is not `NULL`, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error [error@Gio.IOErrorEnum.CANCELLED] will be
  returned.

  For symlinks, normally the information about the target of the
  symlink is returned, rather than information about the symlink
  itself. However if you pass [flags@Gio.FileQueryInfoFlags.NOFOLLOW_SYMLINKS]
  in @flags the information about the symlink itself will be returned.
  Also, for symlinks that point to non-existing files the information
  about the symlink itself will be returned.

  If the file does not exist, the [error@Gio.IOErrorEnum.NOT_FOUND] error will be
  returned. Other errors are possible too, and depend on what kind of
  file system the file is on. *)

  external query_filesystem_info_finish :
    t -> Async_result.t -> (File_info.t, GError.t) result
    = "ml_g_file_query_filesystem_info_finish"
  (** Finishes an asynchronous filesystem info query. See
      g_file_query_filesystem_info_async(). *)

  external query_filesystem_info :
    t -> string -> Cancellable.t option -> (File_info.t, GError.t) result
    = "ml_g_file_query_filesystem_info"
  (** Similar to g_file_query_info(), but obtains information
  about the filesystem the @file is on, rather than the file itself.
  For instance the amount of space available and the type of
  the filesystem.

  The @attributes value is a string that specifies the attributes
  that should be gathered. It is not an error if it's not possible
  to read a particular requested attribute from a file - it just
  won't be set. @attributes should be a comma-separated list of
  attributes or attribute wildcards. The wildcard "*" means all
  attributes, and a wildcard like "filesystem::*" means all attributes
  in the filesystem namespace. The standard namespace for filesystem
  attributes is "filesystem". Common attributes of interest are
  %G_FILE_ATTRIBUTE_FILESYSTEM_SIZE (the total size of the filesystem
  in bytes), %G_FILE_ATTRIBUTE_FILESYSTEM_FREE (number of bytes available),
  and %G_FILE_ATTRIBUTE_FILESYSTEM_TYPE (type of the filesystem).

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  If the file does not exist, the %G_IO_ERROR_NOT_FOUND error will
  be returned. Other errors are possible too, and depend on what
  kind of filesystem the file is on. *)

  external query_file_type :
    t ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    Gio_enums.filetype = "ml_g_file_query_file_type"
  (** Utility function to inspect the #GFileType of a file. This is implemented
      using g_file_query_info() and as such does blocking I/O.

      The primary use case of this method is to check if a file is a regular
      file, directory, or symlink. *)

  external query_exists : t -> Cancellable.t option -> bool
    = "ml_g_file_query_exists"
  (** Utility function to check if a particular file exists.

      The fallback implementation of this API is using
      [method@Gio.File.query_info] and therefore may do blocking I/O. To
      asynchronously query the existence of a file, use
      [method@Gio.File.query_info_async].

      Note that in many cases it is
      [racy to first check for file existence](https://en.wikipedia.org/wiki/Time_of_check_to_time_of_use)
      and then execute something based on the outcome of that, because the file
      might have been created or removed in between the operations. The general
      approach to handling that is to not check, but just do the operation and
      handle the errors as they come.

      As an example of race-free checking, take the case of reading a file, and
      if it doesn't exist, creating it. There are two racy versions: read it,
      and on error create it; and: check if it exists, if not create it. These
      can both result in two processes creating the file (with perhaps a
      partially written file as the result). The correct approach is to always
      try to create the file with g_file_create() which will either atomically
      create the file or fail with a %G_IO_ERROR_EXISTS error.

      However, in many cases an existence check is useful in a user interface,
      for instance to make a menu item sensitive/insensitive, so that you don't
      have to fool users that something is possible and then just show an error
      dialog. If you do this, you should make sure to also handle the errors
      that can happen due to races when you execute the operation. *)

  external query_default_handler_finish :
    t -> Async_result.t -> (App_info.t, GError.t) result
    = "ml_g_file_query_default_handler_finish"
  (** Finishes a g_file_query_default_handler_async() operation. *)

  external query_default_handler :
    t -> Cancellable.t option -> (App_info.t, GError.t) result
    = "ml_g_file_query_default_handler"
  (** Returns the #GAppInfo that is registered as the default
  application to handle the file specified by @file.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external poll_mountable_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_poll_mountable_finish"
  (** Finishes a poll operation. See g_file_poll_mountable() for details.

      Finish an asynchronous poll operation that was polled with
      g_file_poll_mountable(). *)

  external peek_path : t -> string option = "ml_g_file_peek_path"
  (** Exactly like g_file_get_path(), but caches the result via
      g_object_set_qdata_full(). This is useful for example in C applications
      which mix `g_file_*` APIs with native ones. It also avoids an extra
      duplicated string when possible, so will be generally more efficient.

      This call does no blocking I/O. *)

  external open_readwrite_finish :
    t -> Async_result.t -> (File_io_stream.t, GError.t) result
    = "ml_g_file_open_readwrite_finish"
  (** Finishes an asynchronous file read operation started with
      g_file_open_readwrite_async(). *)

  external open_readwrite :
    t -> Cancellable.t option -> (File_io_stream.t, GError.t) result
    = "ml_g_file_open_readwrite"
  (** Opens an existing file for reading and writing. The result is
  a #GFileIOStream that can be used to read and write the contents
  of the file.

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  If the file does not exist, the %G_IO_ERROR_NOT_FOUND error will
  be returned. If the file is a directory, the %G_IO_ERROR_IS_DIRECTORY
  error will be returned. Other errors are possible too, and depend on
  what kind of filesystem the file is on. Note that in many non-local
  file cases read and write streams are not supported, so make sure you
  really need to do read and write streaming, rather than just opening
  for reading or writing. *)

  external move_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_move_finish"
  (** Finishes an asynchronous file movement, started with g_file_move_async().
  *)

  external mount_mountable_finish : t -> Async_result.t -> (t, GError.t) result
    = "ml_g_file_mount_mountable_finish"
  (** Finishes a mount operation. See g_file_mount_mountable() for details.

      Finish an asynchronous mount operation that was started with
      g_file_mount_mountable(). *)

  external mount_enclosing_volume_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_mount_enclosing_volume_finish"
  (** Finishes a mount operation started by g_file_mount_enclosing_volume(). *)

  external monitor_file :
    t ->
    Gio_enums.filemonitorflags ->
    Cancellable.t option ->
    (File_monitor.t, GError.t) result = "ml_g_file_monitor_file"
  (** Obtains a file monitor for the given file. If no file notification
  mechanism exists, then regular polling of the file is used.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned.

  If @flags contains %G_FILE_MONITOR_WATCH_HARD_LINKS then the monitor
  will also attempt to report changes made to the file via another
  filename (ie, a hard link). Without this flag, you can only rely on
  changes made through the filename contained in @file to be
  reported. Using this flag may result in an increase in resource
  usage, and may not have any effect depending on the #GFileMonitor
  backend and/or filesystem type. *)

  external monitor_directory :
    t ->
    Gio_enums.filemonitorflags ->
    Cancellable.t option ->
    (File_monitor.t, GError.t) result = "ml_g_file_monitor_directory"
  (** Obtains a directory monitor for the given file.
  This may fail if directory monitoring is not supported.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned.

  It does not make sense for @flags to contain
  %G_FILE_MONITOR_WATCH_HARD_LINKS, since hard links can not be made to
  directories.  It is not possible to monitor all the files in a
  directory for changes made via hard links; if you want to do this then
  you must register individual watches with g_file_monitor(). *)

  external monitor :
    t ->
    Gio_enums.filemonitorflags ->
    Cancellable.t option ->
    (File_monitor.t, GError.t) result = "ml_g_file_monitor"
  (** Obtains a file or directory monitor for the given file,
  depending on the type of the file.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external measure_disk_usage_finish :
    t ->
    Async_result.t ->
    (bool * UInt64.t * UInt64.t * UInt64.t, GError.t) result
    = "ml_g_file_measure_disk_usage_finish"
  (** Collects the results from an earlier call to
      g_file_measure_disk_usage_async(). See g_file_measure_disk_usage() for
      more information. *)

  external make_symbolic_link_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_make_symbolic_link_finish"
  (** Finishes an asynchronous symbolic link creation, started with
      g_file_make_symbolic_link_async(). *)

  external make_symbolic_link :
    t -> string -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_file_make_symbolic_link"
  (** Creates a symbolic link named @file which contains the string
  @symlink_value.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external make_directory_with_parents :
    t -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_file_make_directory_with_parents"
  (** Creates a directory and any parent directories that may not
  exist similar to 'mkdir -p'. If the file system does not support
  creating directories, this function will fail, setting @error to
  %G_IO_ERROR_NOT_SUPPORTED. If the directory itself already exists,
  this function will fail setting @error to %G_IO_ERROR_EXISTS, unlike
  the similar g_mkdir_with_parents().

  For a local #GFile the newly created directories will have the default
  (current) ownership and permissions of the current process.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external make_directory_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_make_directory_finish"
  (** Finishes an asynchronous directory creation, started with
      g_file_make_directory_async(). *)

  external make_directory : t -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_file_make_directory"
  (** Creates a directory.

  Note that this will only create a child directory
  of the immediate parent directory of the path or URI given by the #GFile.
  To recursively create directories, see g_file_make_directory_with_parents().

  This function will fail if the parent directory does not exist, setting
  @error to %G_IO_ERROR_NOT_FOUND. If the file system doesn't support
  creating directories, this function will fail, setting @error to
  %G_IO_ERROR_NOT_SUPPORTED. If the directory already exists,
  [error@Gio.IOErrorEnum.EXISTS] will be returned.

  For a local #GFile the newly created directory will have the default
  (current) ownership and permissions of the current process.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external is_native : t -> bool = "ml_g_file_is_native"
  (** Checks to see if a file is native to the platform.

      A native file is one expressed in the platform-native filename format,
      e.g. "C:\Windows" or "/usr/bin/". This does not mean the file is local, as
      it might be on a locally mounted remote filesystem.

      On some systems non-native files may be available using the native
      filesystem via a userspace filesystem (FUSE), in these cases this call
      will return %FALSE, but g_file_get_path() will still return a native path.

      This call does no blocking I/O. *)

  external hash : t -> int = "ml_g_file_hash"
  (** Creates a hash value for a #GFile.

      This call does no blocking I/O. *)

  external has_uri_scheme : t -> string -> bool = "ml_g_file_has_uri_scheme"
  (** Checks to see if a #GFile has a given URI scheme.

      This call does no blocking I/O. *)

  external has_prefix : t -> t -> bool = "ml_g_file_has_prefix"
  (** Checks whether @file has the prefix specified by @prefix.

  In other words, if the names of initial elements of @file's
  pathname match @prefix. Only full pathname elements are matched,
  so a path like /foo is not considered a prefix of /foobar, only
  of /foo/bar.

  A #GFile is not a prefix of itself. If you want to check for
  equality, use g_file_equal().

  This call does no I/O, as it works purely on names. As such it can
  sometimes return %FALSE even if @file is inside a @prefix (from a
  filesystem point of view), because the prefix of @file is an alias
  of @prefix. *)

  external has_parent : t -> t option -> bool = "ml_g_file_has_parent"
  (** Checks if @file has a parent, and optionally, if it is @parent.

  If @parent is %NULL then this function returns %TRUE if @file has any
  parent at all.  If @parent is non-%NULL then %TRUE is only returned
  if @file is an immediate child of @parent. *)

  external get_uri_scheme : t -> string option = "ml_g_file_get_uri_scheme"
  (** Gets the URI scheme for a #GFile. RFC 3986 decodes the scheme as:
      |[ URI = scheme ":" hier-part [ "?" query ] [ "#" fragment ] ]| Common
      schemes include "file", "http", "ftp", etc.

      The scheme can be different from the one used to construct the #GFile, in
      that it might be replaced with one that is logically equivalent to the
      #GFile.

      This call does no blocking I/O. *)

  external get_uri : t -> string = "ml_g_file_get_uri"
  (** Gets the URI for the @file.

  This call does no blocking I/O. *)

  external get_relative_path : t -> t -> string option
    = "ml_g_file_get_relative_path"
  (** Gets the path for @descendant relative to @parent.

  This call does no blocking I/O. *)

  external get_path : t -> string option = "ml_g_file_get_path"
  (** Gets the local pathname for #GFile, if one exists. If non-%NULL, this is
      guaranteed to be an absolute, canonical path. It might contain symlinks.

      This call does no blocking I/O. *)

  external get_parse_name : t -> string = "ml_g_file_get_parse_name"
  (** Gets the parse name of the @file.
  A parse name is a UTF-8 string that describes the
  file such that one can get the #GFile back using
  g_file_parse_name().

  This is generally used to show the #GFile as a nice
  full-pathname kind of string in a user interface,
  like in a location entry.

  For local files with names that can safely be converted
  to UTF-8 the pathname is used, otherwise the IRI is used
  (a form of URI that allows UTF-8 characters unescaped).

  This call does no blocking I/O. *)

  external get_parent : t -> t option = "ml_g_file_get_parent"
  (** Gets the parent directory for the @file.
  If the @file represents the root directory of the
  file system, then %NULL will be returned.

  This call does no blocking I/O. *)

  external get_child_for_display_name : t -> string -> (t, GError.t) result
    = "ml_g_file_get_child_for_display_name"
  (** Gets the child of @file for a given @display_name (i.e. a UTF-8
  version of the name). If this function fails, it returns %NULL
  and @error will be set. This is very useful when constructing a
  #GFile for a new file and the user entered the filename in the
  user interface, for instance when you select a directory and
  type a filename in the file selector.

  This call does no blocking I/O. *)

  external get_child : t -> string -> t = "ml_g_file_get_child"
  (** Gets a child of @file with basename equal to @name.

  Note that the file with that specific name might not exist, but
  you can still have a #GFile that points to it. You can use this
  for instance to create that file.

  This call does no blocking I/O. *)

  external get_basename : t -> string option = "ml_g_file_get_basename"
  (** Gets the base name (the last component of the path) for a given #GFile.

      If called for the top level of a system (such as the filesystem root or a
      uri like sftp://host/) it will return a single directory separator (and on
      Windows, possibly a drive letter).

      The base name is a byte string (not UTF-8). It has no defined encoding or
      rules other than it may not contain zero bytes. If you want to use
      filenames in a user interface you should use the display name that you can
      get by requesting the %G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME attribute
      with g_file_query_info().

      This call does no blocking I/O. *)

  external find_enclosing_mount_finish :
    t -> Async_result.t -> (Mount.t, GError.t) result
    = "ml_g_file_find_enclosing_mount_finish"
  (** Finishes an asynchronous find mount request. See
      g_file_find_enclosing_mount_async(). *)

  external find_enclosing_mount :
    t -> Cancellable.t option -> (Mount.t, GError.t) result
    = "ml_g_file_find_enclosing_mount"
  (** Gets a #GMount for the #GFile.

  #GMount is returned only for user interesting locations, see
  #GVolumeMonitor. If the #GFileIface for @file does not have a #mount,
  @error will be set to %G_IO_ERROR_NOT_FOUND and %NULL #will be returned.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external equal : t -> t -> bool = "ml_g_file_equal"
  (** Checks if the two given #GFiles refer to the same file.

      Note that two #GFiles that differ can still refer to the same file on the
      filesystem due to various forms of filename aliasing.

      This call does no blocking I/O. *)

  external enumerate_children_finish :
    t -> Async_result.t -> (File_enumerator.t, GError.t) result
    = "ml_g_file_enumerate_children_finish"
  (** Finishes an async enumerate children operation. See
      g_file_enumerate_children_async(). *)

  external enumerate_children :
    t ->
    string ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (File_enumerator.t, GError.t) result = "ml_g_file_enumerate_children"
  (** Gets the requested information about the files in a directory.
  The result is a #GFileEnumerator object that will give out
  #GFileInfo objects for all the files in the directory.

  The @attributes value is a string that specifies the file
  attributes that should be gathered. It is not an error if
  it's not possible to read a particular requested attribute
  from a file - it just won't be set. @attributes should
  be a comma-separated list of attributes or attribute wildcards.
  The wildcard "*" means all attributes, and a wildcard like
  "standard::*" means all attributes in the standard namespace.
  An example attribute query be "standard::*,owner::user".
  The standard attributes are available as defines, like
  %G_FILE_ATTRIBUTE_STANDARD_NAME. %G_FILE_ATTRIBUTE_STANDARD_NAME should
  always be specified if you plan to call g_file_enumerator_get_child() or
  g_file_enumerator_iterate() on the returned enumerator.

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  If the file does not exist, the %G_IO_ERROR_NOT_FOUND error will
  be returned. If the file is not a directory, the %G_IO_ERROR_NOT_DIRECTORY
  error will be returned. Other errors are possible too. *)

  external eject_mountable_with_operation_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_eject_mountable_with_operation_finish"
  (** Finishes an asynchronous eject operation started by
      g_file_eject_mountable_with_operation(). *)

  external eject_mountable_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_eject_mountable_finish"
  (** Finishes an asynchronous eject operation started by
      g_file_eject_mountable(). *)

  external dup : t -> t = "ml_g_file_dup"
  (** Duplicates a #GFile handle. This operation does not duplicate the actual
      file or directory represented by the #GFile; see g_file_copy() if
      attempting to copy a file.

      g_file_dup() is useful when a second handle is needed to the same
      underlying file, for use in a separate thread (#GFile is not thread-safe).
      For use within the same thread, use g_object_ref() to increment the
      existing object’s reference count.

      This call does no blocking I/O. *)

  external delete_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_delete_finish"
  (** Finishes deleting a file started with g_file_delete_async(). *)

  external delete : t -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_file_delete"
  (** Deletes a file. If the @file is a directory, it will only be
  deleted if it is empty. This has the same semantics as g_unlink().

  If @file doesn’t exist, %G_IO_ERROR_NOT_FOUND will be returned. This allows
  for deletion to be implemented avoiding
  [time-of-check to time-of-use races](https://en.wikipedia.org/wiki/Time-of-check_to_time-of-use):
  |[
  g_autoptr(GError) local_error = NULL;
  if (!g_file_delete (my_file, my_cancellable, &local_error) &&
      !g_error_matches (local_error, G_IO_ERROR, G_IO_ERROR_NOT_FOUND))
    {
      // deletion failed for some reason other than the file not existing:
      // so report the error
      g_warning ("Failed to delete %s: %s",
                 g_file_peek_path (my_file), local_error->message);
    }
  ]|

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external create_readwrite_finish :
    t -> Async_result.t -> (File_io_stream.t, GError.t) result
    = "ml_g_file_create_readwrite_finish"
  (** Finishes an asynchronous file create operation started with
      g_file_create_readwrite_async(). *)

  external create_readwrite :
    t ->
    Gio_enums.filecreateflags ->
    Cancellable.t option ->
    (File_io_stream.t, GError.t) result = "ml_g_file_create_readwrite"
  (** Creates a new file and returns a stream for reading and
  writing to it. The file must not already exist.

  By default files created are generally readable by everyone,
  but if you pass %G_FILE_CREATE_PRIVATE in @flags the file
  will be made readable only to the current user, to the level
  that is supported on the target filesystem.

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  If a file or directory with this name already exists, the
  %G_IO_ERROR_EXISTS error will be returned. Some file systems don't
  allow all file names, and may return an %G_IO_ERROR_INVALID_FILENAME
  error, and if the name is too long, %G_IO_ERROR_FILENAME_TOO_LONG
  will be returned. Other errors are possible too, and depend on what
  kind of filesystem the file is on.

  Note that in many non-local file cases read and write streams are
  not supported, so make sure you really need to do read and write
  streaming, rather than just opening for reading or writing. *)

  external create_finish :
    t -> Async_result.t -> (File_output_stream.t, GError.t) result
    = "ml_g_file_create_finish"
  (** Finishes an asynchronous file create operation started with
      g_file_create_async(). *)

  external create :
    t ->
    Gio_enums.filecreateflags ->
    Cancellable.t option ->
    (File_output_stream.t, GError.t) result = "ml_g_file_create"
  (** Creates a new file and returns an output stream for writing to it.
  The file must not already exist.

  By default files created are generally readable by everyone,
  but if you pass %G_FILE_CREATE_PRIVATE in @flags the file
  will be made readable only to the current user, to the level
  that is supported on the target filesystem.

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  If a file or directory with this name already exists the
  %G_IO_ERROR_EXISTS error will be returned. Some file systems don't
  allow all file names, and may return an %G_IO_ERROR_INVALID_FILENAME
  error, and if the name is to long %G_IO_ERROR_FILENAME_TOO_LONG will
  be returned. Other errors are possible too, and depend on what kind
  of filesystem the file is on. *)

  external copy_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_copy_finish"
  (** Finishes copying the file started with g_file_copy_async(). *)

  external copy_attributes :
    t ->
    t ->
    Gio_enums.filecopyflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_copy_attributes"
  (** Copies the file attributes from @source to @destination.

  Normally only a subset of the file attributes are copied,
  those that are copies in a normal file copy operation
  (which for instance does not include e.g. owner). However
  if %G_FILE_COPY_ALL_METADATA is specified in @flags, then
  all the metadata that is possible to copy is copied. This
  is useful when implementing move by copy + delete source. *)

  external build_attribute_list_for_copy :
    t ->
    Gio_enums.filecopyflags ->
    Cancellable.t option ->
    (string, GError.t) result = "ml_g_file_build_attribute_list_for_copy"
  (** Prepares the file attribute query string for copying to @file.

  This function prepares an attribute query string to be
  passed to g_file_query_info() to get a list of attributes
  normally copied with the file (see g_file_copy_attributes()
  for the detailed description). This function is used by the
  implementation of g_file_copy_attributes() and is useful
  when one needs to query and set the attributes in two
  stages (e.g., for recursive move of a directory). *)

  external append_to_finish :
    t -> Async_result.t -> (File_output_stream.t, GError.t) result
    = "ml_g_file_append_to_finish"
  (** Finishes an asynchronous file append operation started with
      g_file_append_to_async(). *)

  external append_to :
    t ->
    Gio_enums.filecreateflags ->
    Cancellable.t option ->
    (File_output_stream.t, GError.t) result = "ml_g_file_append_to"
  (** Gets an output stream for appending data to the file.
  If the file doesn't already exist it is created.

  By default files created are generally readable by everyone,
  but if you pass %G_FILE_CREATE_PRIVATE in @flags the file
  will be made readable only to the current user, to the level that
  is supported on the target filesystem.

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  Some file systems don't allow all file names, and may return an
  %G_IO_ERROR_INVALID_FILENAME error. If the file is a directory the
  %G_IO_ERROR_IS_DIRECTORY error will be returned. Other errors are
  possible too, and depend on what kind of filesystem the file is on. *)
end = struct
  type t = [ `file ] Gobject.obj

  external from_gobject : 'a Gobject.obj -> t = "ml_gio_file_from_gobject"

  (* Methods *)

  external unmount_mountable_with_operation_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_unmount_mountable_with_operation_finish"
  (** Finishes an unmount operation, see
      g_file_unmount_mountable_with_operation() for details.

      Finish an asynchronous unmount operation that was started with
      g_file_unmount_mountable_with_operation(). *)

  external unmount_mountable_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_unmount_mountable_finish"
  (** Finishes an unmount operation, see g_file_unmount_mountable() for details.

      Finish an asynchronous unmount operation that was started with
      g_file_unmount_mountable(). *)

  external trash_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_trash_finish"
  (** Finishes an asynchronous file trashing operation, started with
      g_file_trash_async(). *)

  external trash : t -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_file_trash"
  (** Sends @file to the "Trashcan", if possible. This is similar to
  deleting it, but the user can recover it before emptying the trashcan.
  Trashing is disabled for system mounts by default (see
  g_unix_mount_entry_is_system_internal()), so this call can return the
  %G_IO_ERROR_NOT_SUPPORTED error. Since GLib 2.66, the `x-gvfs-notrash` unix
  mount option can be used to disable g_file_trash() support for particular
  mounts, the %G_IO_ERROR_NOT_SUPPORTED error will be returned in that case.
  Since 2.82, the `x-gvfs-trash` unix mount option can be used to enable
  g_file_trash() support for particular system mounts.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external supports_thread_contexts : t -> bool
    = "ml_g_file_supports_thread_contexts"
  (** Checks if @file supports thread-default main contexts
  (see [method@GLib.MainContext.push_thread_default])
  If this returns %FALSE, you cannot perform asynchronous operations on
  @file in a thread that has a thread-default context. *)

  external stop_mountable_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_stop_mountable_finish"
  (** Finishes a stop operation, see g_file_stop_mountable() for details.

      Finish an asynchronous stop operation that was started with
      g_file_stop_mountable(). *)

  external start_mountable_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_start_mountable_finish"
  (** Finishes a start operation. See g_file_start_mountable() for details.

      Finish an asynchronous start operation that was started with
      g_file_start_mountable(). *)

  external set_display_name_finish : t -> Async_result.t -> (t, GError.t) result
    = "ml_g_file_set_display_name_finish"
  (** Finishes setting a display name started with
      g_file_set_display_name_async(). *)

  external set_display_name :
    t -> string -> Cancellable.t option -> (t, GError.t) result
    = "ml_g_file_set_display_name"
  (** Renames @file to the specified display name.

  The display name is converted from UTF-8 to the correct encoding
  for the target filesystem if possible and the @file is renamed to this.

  If you want to implement a rename operation in the user interface the
  edit name (%G_FILE_ATTRIBUTE_STANDARD_EDIT_NAME) should be used as the
  initial value in the rename widget, and then the result after editing
  should be passed to g_file_set_display_name().

  On success the resulting converted filename is returned.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attributes_from_info :
    t ->
    File_info.t ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attributes_from_info"
  (** Tries to set all attributes in the #GFileInfo on the target
  values, not stopping on the first error.

  If there is any error during this operation then @error will
  be set to the first error. Error on particular fields are flagged
  by setting the "status" field in the attribute value to
  %G_FILE_ATTRIBUTE_STATUS_ERROR_SETTING, which means you can
  also detect further errors.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attribute_uint64 :
    t ->
    string ->
    UInt64.t ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attribute_uint64"
  (** Sets @attribute of type %G_FILE_ATTRIBUTE_TYPE_UINT64 to @value.
  If @attribute is of a different type, this operation will fail.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attribute_uint32 :
    t ->
    string ->
    UInt32.t ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attribute_uint32"
  (** Sets @attribute of type %G_FILE_ATTRIBUTE_TYPE_UINT32 to @value.
  If @attribute is of a different type, this operation will fail.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attribute_string :
    t ->
    string ->
    string ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attribute_string"
  (** Sets @attribute of type %G_FILE_ATTRIBUTE_TYPE_STRING to @value.
  If @attribute is of a different type, this operation will fail.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attribute_int64 :
    t ->
    string ->
    int64 ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attribute_int64"
  (** Sets @attribute of type %G_FILE_ATTRIBUTE_TYPE_INT64 to @value.
  If @attribute is of a different type, this operation will fail.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attribute_int32 :
    t ->
    string ->
    Int32.t ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attribute_int32"
  (** Sets @attribute of type %G_FILE_ATTRIBUTE_TYPE_INT32 to @value.
  If @attribute is of a different type, this operation will fail.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external set_attribute_byte_string :
    t ->
    string ->
    string ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_set_attribute_byte_string"
  (** Sets @attribute of type %G_FILE_ATTRIBUTE_TYPE_BYTE_STRING to @value.
  If @attribute is of a different type, this operation will fail,
  returning %FALSE.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external resolve_relative_path : t -> string -> t
    = "ml_g_file_resolve_relative_path"
  (** Resolves a relative path for @file to an absolute path.

  This call does no blocking I/O.

  If the @relative_path is an absolute path name, the resolution
  is done absolutely (without taking @file path as base). *)

  external replace_readwrite_finish :
    t -> Async_result.t -> (File_io_stream.t, GError.t) result
    = "ml_g_file_replace_readwrite_finish"
  (** Finishes an asynchronous file replace operation started with
      g_file_replace_readwrite_async(). *)

  external replace_readwrite :
    t ->
    string option ->
    bool ->
    Gio_enums.filecreateflags ->
    Cancellable.t option ->
    (File_io_stream.t, GError.t) result = "ml_g_file_replace_readwrite"
  (** Returns an output stream for overwriting the file in readwrite mode,
      possibly creating a backup copy of the file first. If the file doesn't
      exist, it will be created.

      For details about the behaviour, see g_file_replace() which does the same
      thing but returns an output stream only.

      Note that in many non-local file cases read and write streams are not
      supported, so make sure you really need to do read and write streaming,
      rather than just opening for reading or writing. *)

  external replace_finish :
    t -> Async_result.t -> (File_output_stream.t, GError.t) result
    = "ml_g_file_replace_finish"
  (** Finishes an asynchronous file replace operation started with
      g_file_replace_async(). *)

  external replace :
    t ->
    string option ->
    bool ->
    Gio_enums.filecreateflags ->
    Cancellable.t option ->
    (File_output_stream.t, GError.t) result = "ml_g_file_replace"
  (** Returns an output stream for overwriting the file, possibly
  creating a backup copy of the file first. If the file doesn't exist,
  it will be created.

  This will try to replace the file in the safest way possible so
  that any errors during the writing will not affect an already
  existing copy of the file. For instance, for local files it
  may write to a temporary file and then atomically rename over
  the destination when the stream is closed.

  By default files created are generally readable by everyone,
  but if you pass %G_FILE_CREATE_PRIVATE in @flags the file
  will be made readable only to the current user, to the level that
  is supported on the target filesystem.

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  If you pass in a non-%NULL @etag value and @file already exists, then
  this value is compared to the current entity tag of the file, and if
  they differ an %G_IO_ERROR_WRONG_ETAG error is returned. This
  generally means that the file has been changed since you last read
  it. You can get the new etag from g_file_output_stream_get_etag()
  after you've finished writing and closed the #GFileOutputStream. When
  you load a new file you can use g_file_input_stream_query_info() to
  get the etag of the file.

  If @make_backup is %TRUE, this function will attempt to make a
  backup of the current file before overwriting it. If this fails
  a %G_IO_ERROR_CANT_CREATE_BACKUP error will be returned. If you
  want to replace anyway, try again with @make_backup set to %FALSE.

  If the file is a directory the %G_IO_ERROR_IS_DIRECTORY error will
  be returned, and if the file is some other form of non-regular file
  then a %G_IO_ERROR_NOT_REGULAR_FILE error will be returned. Some
  file systems don't allow all file names, and may return an
  %G_IO_ERROR_INVALID_FILENAME error, and if the name is to long
  %G_IO_ERROR_FILENAME_TOO_LONG will be returned. Other errors are
  possible too, and depend on what kind of filesystem the file is on. *)

  external read_finish :
    t -> Async_result.t -> (File_input_stream.t, GError.t) result
    = "ml_g_file_read_finish"
  (** Finishes an asynchronous file read operation started with
      g_file_read_async(). *)

  external read :
    t -> Cancellable.t option -> (File_input_stream.t, GError.t) result
    = "ml_g_file_read"
  (** Opens a file for reading. The result is a #GFileInputStream that
  can be used to read the contents of the file.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned.

  If the file does not exist, the %G_IO_ERROR_NOT_FOUND error will be
  returned. If the file is a directory, the %G_IO_ERROR_IS_DIRECTORY
  error will be returned. Other errors are possible too, and depend
  on what kind of filesystem the file is on. *)

  external query_writable_namespaces :
    t -> Cancellable.t option -> (File_attribute_info_list.t, GError.t) result
    = "ml_g_file_query_writable_namespaces"
  (** Obtain the list of attribute namespaces where new attributes
  can be created by a user. An example of this is extended
  attributes (in the "xattr" namespace).

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external query_settable_attributes :
    t -> Cancellable.t option -> (File_attribute_info_list.t, GError.t) result
    = "ml_g_file_query_settable_attributes"
  (** Obtain the list of settable attributes for the file.

  Returns the type and full attribute name of all the attributes
  that can be set on this file. This doesn't mean setting it will
  always succeed though, you might get an access failure, or some
  specific file may not support a specific attribute.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external query_info_finish :
    t -> Async_result.t -> (File_info.t, GError.t) result
    = "ml_g_file_query_info_finish"
  (** Finishes an asynchronous file info query. See g_file_query_info_async().
  *)

  external query_info :
    t ->
    string ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (File_info.t, GError.t) result = "ml_g_file_query_info"
  (** Gets the requested information about specified @file.

  The result is a [class@Gio.FileInfo] object that contains key-value
  attributes (such as the type or size of the file).

  The @attributes value is a string that specifies the file
  attributes that should be gathered. It is not an error if
  it’s not possible to read a particular requested attribute
  from a file — it just won't be set. In particular this means that if a file
  is inaccessible (due to being in a folder with restrictive permissions), for
  example, you can expect the returned [class@Gio.FileInfo] to have very few
  attributes set. You should check whether an attribute is set using
  [method@Gio.FileInfo.has_attribute] before trying to retrieve its value.

  It is guaranteed that if any of the following attributes are listed in
  @attributes, they will always be set in the returned [class@Gio.FileInfo],
  even if the user doesn’t have permissions to access the file:

   - [const@Gio.FILE_ATTRIBUTE_STANDARD_NAME]
   - [const@Gio.FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME]

  @attributes should be a comma-separated list of attributes or attribute
  wildcards. The wildcard `"*"` means all attributes, and a wildcard like
  `"standard::*"` means all attributes in the standard namespace.
  An example attribute query might be `"standard::*,owner::user"`.
  The standard attributes are available as defines, like
  [const@Gio.FILE_ATTRIBUTE_STANDARD_NAME].

  If @cancellable is not `NULL`, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error [error@Gio.IOErrorEnum.CANCELLED] will be
  returned.

  For symlinks, normally the information about the target of the
  symlink is returned, rather than information about the symlink
  itself. However if you pass [flags@Gio.FileQueryInfoFlags.NOFOLLOW_SYMLINKS]
  in @flags the information about the symlink itself will be returned.
  Also, for symlinks that point to non-existing files the information
  about the symlink itself will be returned.

  If the file does not exist, the [error@Gio.IOErrorEnum.NOT_FOUND] error will be
  returned. Other errors are possible too, and depend on what kind of
  file system the file is on. *)

  external query_filesystem_info_finish :
    t -> Async_result.t -> (File_info.t, GError.t) result
    = "ml_g_file_query_filesystem_info_finish"
  (** Finishes an asynchronous filesystem info query. See
      g_file_query_filesystem_info_async(). *)

  external query_filesystem_info :
    t -> string -> Cancellable.t option -> (File_info.t, GError.t) result
    = "ml_g_file_query_filesystem_info"
  (** Similar to g_file_query_info(), but obtains information
  about the filesystem the @file is on, rather than the file itself.
  For instance the amount of space available and the type of
  the filesystem.

  The @attributes value is a string that specifies the attributes
  that should be gathered. It is not an error if it's not possible
  to read a particular requested attribute from a file - it just
  won't be set. @attributes should be a comma-separated list of
  attributes or attribute wildcards. The wildcard "*" means all
  attributes, and a wildcard like "filesystem::*" means all attributes
  in the filesystem namespace. The standard namespace for filesystem
  attributes is "filesystem". Common attributes of interest are
  %G_FILE_ATTRIBUTE_FILESYSTEM_SIZE (the total size of the filesystem
  in bytes), %G_FILE_ATTRIBUTE_FILESYSTEM_FREE (number of bytes available),
  and %G_FILE_ATTRIBUTE_FILESYSTEM_TYPE (type of the filesystem).

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  If the file does not exist, the %G_IO_ERROR_NOT_FOUND error will
  be returned. Other errors are possible too, and depend on what
  kind of filesystem the file is on. *)

  external query_file_type :
    t ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    Gio_enums.filetype = "ml_g_file_query_file_type"
  (** Utility function to inspect the #GFileType of a file. This is implemented
      using g_file_query_info() and as such does blocking I/O.

      The primary use case of this method is to check if a file is a regular
      file, directory, or symlink. *)

  external query_exists : t -> Cancellable.t option -> bool
    = "ml_g_file_query_exists"
  (** Utility function to check if a particular file exists.

      The fallback implementation of this API is using
      [method@Gio.File.query_info] and therefore may do blocking I/O. To
      asynchronously query the existence of a file, use
      [method@Gio.File.query_info_async].

      Note that in many cases it is
      [racy to first check for file existence](https://en.wikipedia.org/wiki/Time_of_check_to_time_of_use)
      and then execute something based on the outcome of that, because the file
      might have been created or removed in between the operations. The general
      approach to handling that is to not check, but just do the operation and
      handle the errors as they come.

      As an example of race-free checking, take the case of reading a file, and
      if it doesn't exist, creating it. There are two racy versions: read it,
      and on error create it; and: check if it exists, if not create it. These
      can both result in two processes creating the file (with perhaps a
      partially written file as the result). The correct approach is to always
      try to create the file with g_file_create() which will either atomically
      create the file or fail with a %G_IO_ERROR_EXISTS error.

      However, in many cases an existence check is useful in a user interface,
      for instance to make a menu item sensitive/insensitive, so that you don't
      have to fool users that something is possible and then just show an error
      dialog. If you do this, you should make sure to also handle the errors
      that can happen due to races when you execute the operation. *)

  external query_default_handler_finish :
    t -> Async_result.t -> (App_info.t, GError.t) result
    = "ml_g_file_query_default_handler_finish"
  (** Finishes a g_file_query_default_handler_async() operation. *)

  external query_default_handler :
    t -> Cancellable.t option -> (App_info.t, GError.t) result
    = "ml_g_file_query_default_handler"
  (** Returns the #GAppInfo that is registered as the default
  application to handle the file specified by @file.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external poll_mountable_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_poll_mountable_finish"
  (** Finishes a poll operation. See g_file_poll_mountable() for details.

      Finish an asynchronous poll operation that was polled with
      g_file_poll_mountable(). *)

  external peek_path : t -> string option = "ml_g_file_peek_path"
  (** Exactly like g_file_get_path(), but caches the result via
      g_object_set_qdata_full(). This is useful for example in C applications
      which mix `g_file_*` APIs with native ones. It also avoids an extra
      duplicated string when possible, so will be generally more efficient.

      This call does no blocking I/O. *)

  external open_readwrite_finish :
    t -> Async_result.t -> (File_io_stream.t, GError.t) result
    = "ml_g_file_open_readwrite_finish"
  (** Finishes an asynchronous file read operation started with
      g_file_open_readwrite_async(). *)

  external open_readwrite :
    t -> Cancellable.t option -> (File_io_stream.t, GError.t) result
    = "ml_g_file_open_readwrite"
  (** Opens an existing file for reading and writing. The result is
  a #GFileIOStream that can be used to read and write the contents
  of the file.

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  If the file does not exist, the %G_IO_ERROR_NOT_FOUND error will
  be returned. If the file is a directory, the %G_IO_ERROR_IS_DIRECTORY
  error will be returned. Other errors are possible too, and depend on
  what kind of filesystem the file is on. Note that in many non-local
  file cases read and write streams are not supported, so make sure you
  really need to do read and write streaming, rather than just opening
  for reading or writing. *)

  external move_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_move_finish"
  (** Finishes an asynchronous file movement, started with g_file_move_async().
  *)

  external mount_mountable_finish : t -> Async_result.t -> (t, GError.t) result
    = "ml_g_file_mount_mountable_finish"
  (** Finishes a mount operation. See g_file_mount_mountable() for details.

      Finish an asynchronous mount operation that was started with
      g_file_mount_mountable(). *)

  external mount_enclosing_volume_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_mount_enclosing_volume_finish"
  (** Finishes a mount operation started by g_file_mount_enclosing_volume(). *)

  external monitor_file :
    t ->
    Gio_enums.filemonitorflags ->
    Cancellable.t option ->
    (File_monitor.t, GError.t) result = "ml_g_file_monitor_file"
  (** Obtains a file monitor for the given file. If no file notification
  mechanism exists, then regular polling of the file is used.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned.

  If @flags contains %G_FILE_MONITOR_WATCH_HARD_LINKS then the monitor
  will also attempt to report changes made to the file via another
  filename (ie, a hard link). Without this flag, you can only rely on
  changes made through the filename contained in @file to be
  reported. Using this flag may result in an increase in resource
  usage, and may not have any effect depending on the #GFileMonitor
  backend and/or filesystem type. *)

  external monitor_directory :
    t ->
    Gio_enums.filemonitorflags ->
    Cancellable.t option ->
    (File_monitor.t, GError.t) result = "ml_g_file_monitor_directory"
  (** Obtains a directory monitor for the given file.
  This may fail if directory monitoring is not supported.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned.

  It does not make sense for @flags to contain
  %G_FILE_MONITOR_WATCH_HARD_LINKS, since hard links can not be made to
  directories.  It is not possible to monitor all the files in a
  directory for changes made via hard links; if you want to do this then
  you must register individual watches with g_file_monitor(). *)

  external monitor :
    t ->
    Gio_enums.filemonitorflags ->
    Cancellable.t option ->
    (File_monitor.t, GError.t) result = "ml_g_file_monitor"
  (** Obtains a file or directory monitor for the given file,
  depending on the type of the file.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external measure_disk_usage_finish :
    t ->
    Async_result.t ->
    (bool * UInt64.t * UInt64.t * UInt64.t, GError.t) result
    = "ml_g_file_measure_disk_usage_finish"
  (** Collects the results from an earlier call to
      g_file_measure_disk_usage_async(). See g_file_measure_disk_usage() for
      more information. *)

  external make_symbolic_link_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_make_symbolic_link_finish"
  (** Finishes an asynchronous symbolic link creation, started with
      g_file_make_symbolic_link_async(). *)

  external make_symbolic_link :
    t -> string -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_file_make_symbolic_link"
  (** Creates a symbolic link named @file which contains the string
  @symlink_value.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external make_directory_with_parents :
    t -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_file_make_directory_with_parents"
  (** Creates a directory and any parent directories that may not
  exist similar to 'mkdir -p'. If the file system does not support
  creating directories, this function will fail, setting @error to
  %G_IO_ERROR_NOT_SUPPORTED. If the directory itself already exists,
  this function will fail setting @error to %G_IO_ERROR_EXISTS, unlike
  the similar g_mkdir_with_parents().

  For a local #GFile the newly created directories will have the default
  (current) ownership and permissions of the current process.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external make_directory_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_make_directory_finish"
  (** Finishes an asynchronous directory creation, started with
      g_file_make_directory_async(). *)

  external make_directory : t -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_file_make_directory"
  (** Creates a directory.

  Note that this will only create a child directory
  of the immediate parent directory of the path or URI given by the #GFile.
  To recursively create directories, see g_file_make_directory_with_parents().

  This function will fail if the parent directory does not exist, setting
  @error to %G_IO_ERROR_NOT_FOUND. If the file system doesn't support
  creating directories, this function will fail, setting @error to
  %G_IO_ERROR_NOT_SUPPORTED. If the directory already exists,
  [error@Gio.IOErrorEnum.EXISTS] will be returned.

  For a local #GFile the newly created directory will have the default
  (current) ownership and permissions of the current process.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external is_native : t -> bool = "ml_g_file_is_native"
  (** Checks to see if a file is native to the platform.

      A native file is one expressed in the platform-native filename format,
      e.g. "C:\Windows" or "/usr/bin/". This does not mean the file is local, as
      it might be on a locally mounted remote filesystem.

      On some systems non-native files may be available using the native
      filesystem via a userspace filesystem (FUSE), in these cases this call
      will return %FALSE, but g_file_get_path() will still return a native path.

      This call does no blocking I/O. *)

  external hash : t -> int = "ml_g_file_hash"
  (** Creates a hash value for a #GFile.

      This call does no blocking I/O. *)

  external has_uri_scheme : t -> string -> bool = "ml_g_file_has_uri_scheme"
  (** Checks to see if a #GFile has a given URI scheme.

      This call does no blocking I/O. *)

  external has_prefix : t -> t -> bool = "ml_g_file_has_prefix"
  (** Checks whether @file has the prefix specified by @prefix.

  In other words, if the names of initial elements of @file's
  pathname match @prefix. Only full pathname elements are matched,
  so a path like /foo is not considered a prefix of /foobar, only
  of /foo/bar.

  A #GFile is not a prefix of itself. If you want to check for
  equality, use g_file_equal().

  This call does no I/O, as it works purely on names. As such it can
  sometimes return %FALSE even if @file is inside a @prefix (from a
  filesystem point of view), because the prefix of @file is an alias
  of @prefix. *)

  external has_parent : t -> t option -> bool = "ml_g_file_has_parent"
  (** Checks if @file has a parent, and optionally, if it is @parent.

  If @parent is %NULL then this function returns %TRUE if @file has any
  parent at all.  If @parent is non-%NULL then %TRUE is only returned
  if @file is an immediate child of @parent. *)

  external get_uri_scheme : t -> string option = "ml_g_file_get_uri_scheme"
  (** Gets the URI scheme for a #GFile. RFC 3986 decodes the scheme as:
      |[ URI = scheme ":" hier-part [ "?" query ] [ "#" fragment ] ]| Common
      schemes include "file", "http", "ftp", etc.

      The scheme can be different from the one used to construct the #GFile, in
      that it might be replaced with one that is logically equivalent to the
      #GFile.

      This call does no blocking I/O. *)

  external get_uri : t -> string = "ml_g_file_get_uri"
  (** Gets the URI for the @file.

  This call does no blocking I/O. *)

  external get_relative_path : t -> t -> string option
    = "ml_g_file_get_relative_path"
  (** Gets the path for @descendant relative to @parent.

  This call does no blocking I/O. *)

  external get_path : t -> string option = "ml_g_file_get_path"
  (** Gets the local pathname for #GFile, if one exists. If non-%NULL, this is
      guaranteed to be an absolute, canonical path. It might contain symlinks.

      This call does no blocking I/O. *)

  external get_parse_name : t -> string = "ml_g_file_get_parse_name"
  (** Gets the parse name of the @file.
  A parse name is a UTF-8 string that describes the
  file such that one can get the #GFile back using
  g_file_parse_name().

  This is generally used to show the #GFile as a nice
  full-pathname kind of string in a user interface,
  like in a location entry.

  For local files with names that can safely be converted
  to UTF-8 the pathname is used, otherwise the IRI is used
  (a form of URI that allows UTF-8 characters unescaped).

  This call does no blocking I/O. *)

  external get_parent : t -> t option = "ml_g_file_get_parent"
  (** Gets the parent directory for the @file.
  If the @file represents the root directory of the
  file system, then %NULL will be returned.

  This call does no blocking I/O. *)

  external get_child_for_display_name : t -> string -> (t, GError.t) result
    = "ml_g_file_get_child_for_display_name"
  (** Gets the child of @file for a given @display_name (i.e. a UTF-8
  version of the name). If this function fails, it returns %NULL
  and @error will be set. This is very useful when constructing a
  #GFile for a new file and the user entered the filename in the
  user interface, for instance when you select a directory and
  type a filename in the file selector.

  This call does no blocking I/O. *)

  external get_child : t -> string -> t = "ml_g_file_get_child"
  (** Gets a child of @file with basename equal to @name.

  Note that the file with that specific name might not exist, but
  you can still have a #GFile that points to it. You can use this
  for instance to create that file.

  This call does no blocking I/O. *)

  external get_basename : t -> string option = "ml_g_file_get_basename"
  (** Gets the base name (the last component of the path) for a given #GFile.

      If called for the top level of a system (such as the filesystem root or a
      uri like sftp://host/) it will return a single directory separator (and on
      Windows, possibly a drive letter).

      The base name is a byte string (not UTF-8). It has no defined encoding or
      rules other than it may not contain zero bytes. If you want to use
      filenames in a user interface you should use the display name that you can
      get by requesting the %G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME attribute
      with g_file_query_info().

      This call does no blocking I/O. *)

  external find_enclosing_mount_finish :
    t -> Async_result.t -> (Mount.t, GError.t) result
    = "ml_g_file_find_enclosing_mount_finish"
  (** Finishes an asynchronous find mount request. See
      g_file_find_enclosing_mount_async(). *)

  external find_enclosing_mount :
    t -> Cancellable.t option -> (Mount.t, GError.t) result
    = "ml_g_file_find_enclosing_mount"
  (** Gets a #GMount for the #GFile.

  #GMount is returned only for user interesting locations, see
  #GVolumeMonitor. If the #GFileIface for @file does not have a #mount,
  @error will be set to %G_IO_ERROR_NOT_FOUND and %NULL #will be returned.

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external equal : t -> t -> bool = "ml_g_file_equal"
  (** Checks if the two given #GFiles refer to the same file.

      Note that two #GFiles that differ can still refer to the same file on the
      filesystem due to various forms of filename aliasing.

      This call does no blocking I/O. *)

  external enumerate_children_finish :
    t -> Async_result.t -> (File_enumerator.t, GError.t) result
    = "ml_g_file_enumerate_children_finish"
  (** Finishes an async enumerate children operation. See
      g_file_enumerate_children_async(). *)

  external enumerate_children :
    t ->
    string ->
    Gio_enums.filequeryinfoflags ->
    Cancellable.t option ->
    (File_enumerator.t, GError.t) result = "ml_g_file_enumerate_children"
  (** Gets the requested information about the files in a directory.
  The result is a #GFileEnumerator object that will give out
  #GFileInfo objects for all the files in the directory.

  The @attributes value is a string that specifies the file
  attributes that should be gathered. It is not an error if
  it's not possible to read a particular requested attribute
  from a file - it just won't be set. @attributes should
  be a comma-separated list of attributes or attribute wildcards.
  The wildcard "*" means all attributes, and a wildcard like
  "standard::*" means all attributes in the standard namespace.
  An example attribute query be "standard::*,owner::user".
  The standard attributes are available as defines, like
  %G_FILE_ATTRIBUTE_STANDARD_NAME. %G_FILE_ATTRIBUTE_STANDARD_NAME should
  always be specified if you plan to call g_file_enumerator_get_child() or
  g_file_enumerator_iterate() on the returned enumerator.

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  If the file does not exist, the %G_IO_ERROR_NOT_FOUND error will
  be returned. If the file is not a directory, the %G_IO_ERROR_NOT_DIRECTORY
  error will be returned. Other errors are possible too. *)

  external eject_mountable_with_operation_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_eject_mountable_with_operation_finish"
  (** Finishes an asynchronous eject operation started by
      g_file_eject_mountable_with_operation(). *)

  external eject_mountable_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_eject_mountable_finish"
  (** Finishes an asynchronous eject operation started by
      g_file_eject_mountable(). *)

  external dup : t -> t = "ml_g_file_dup"
  (** Duplicates a #GFile handle. This operation does not duplicate the actual
      file or directory represented by the #GFile; see g_file_copy() if
      attempting to copy a file.

      g_file_dup() is useful when a second handle is needed to the same
      underlying file, for use in a separate thread (#GFile is not thread-safe).
      For use within the same thread, use g_object_ref() to increment the
      existing object’s reference count.

      This call does no blocking I/O. *)

  external delete_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_delete_finish"
  (** Finishes deleting a file started with g_file_delete_async(). *)

  external delete : t -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_file_delete"
  (** Deletes a file. If the @file is a directory, it will only be
  deleted if it is empty. This has the same semantics as g_unlink().

  If @file doesn’t exist, %G_IO_ERROR_NOT_FOUND will be returned. This allows
  for deletion to be implemented avoiding
  [time-of-check to time-of-use races](https://en.wikipedia.org/wiki/Time-of-check_to_time-of-use):
  |[
  g_autoptr(GError) local_error = NULL;
  if (!g_file_delete (my_file, my_cancellable, &local_error) &&
      !g_error_matches (local_error, G_IO_ERROR, G_IO_ERROR_NOT_FOUND))
    {
      // deletion failed for some reason other than the file not existing:
      // so report the error
      g_warning ("Failed to delete %s: %s",
                 g_file_peek_path (my_file), local_error->message);
    }
  ]|

  If @cancellable is not %NULL, then the operation can be cancelled by
  triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

  external create_readwrite_finish :
    t -> Async_result.t -> (File_io_stream.t, GError.t) result
    = "ml_g_file_create_readwrite_finish"
  (** Finishes an asynchronous file create operation started with
      g_file_create_readwrite_async(). *)

  external create_readwrite :
    t ->
    Gio_enums.filecreateflags ->
    Cancellable.t option ->
    (File_io_stream.t, GError.t) result = "ml_g_file_create_readwrite"
  (** Creates a new file and returns a stream for reading and
  writing to it. The file must not already exist.

  By default files created are generally readable by everyone,
  but if you pass %G_FILE_CREATE_PRIVATE in @flags the file
  will be made readable only to the current user, to the level
  that is supported on the target filesystem.

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  If a file or directory with this name already exists, the
  %G_IO_ERROR_EXISTS error will be returned. Some file systems don't
  allow all file names, and may return an %G_IO_ERROR_INVALID_FILENAME
  error, and if the name is too long, %G_IO_ERROR_FILENAME_TOO_LONG
  will be returned. Other errors are possible too, and depend on what
  kind of filesystem the file is on.

  Note that in many non-local file cases read and write streams are
  not supported, so make sure you really need to do read and write
  streaming, rather than just opening for reading or writing. *)

  external create_finish :
    t -> Async_result.t -> (File_output_stream.t, GError.t) result
    = "ml_g_file_create_finish"
  (** Finishes an asynchronous file create operation started with
      g_file_create_async(). *)

  external create :
    t ->
    Gio_enums.filecreateflags ->
    Cancellable.t option ->
    (File_output_stream.t, GError.t) result = "ml_g_file_create"
  (** Creates a new file and returns an output stream for writing to it.
  The file must not already exist.

  By default files created are generally readable by everyone,
  but if you pass %G_FILE_CREATE_PRIVATE in @flags the file
  will be made readable only to the current user, to the level
  that is supported on the target filesystem.

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  If a file or directory with this name already exists the
  %G_IO_ERROR_EXISTS error will be returned. Some file systems don't
  allow all file names, and may return an %G_IO_ERROR_INVALID_FILENAME
  error, and if the name is to long %G_IO_ERROR_FILENAME_TOO_LONG will
  be returned. Other errors are possible too, and depend on what kind
  of filesystem the file is on. *)

  external copy_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_copy_finish"
  (** Finishes copying the file started with g_file_copy_async(). *)

  external copy_attributes :
    t ->
    t ->
    Gio_enums.filecopyflags ->
    Cancellable.t option ->
    (bool, GError.t) result = "ml_g_file_copy_attributes"
  (** Copies the file attributes from @source to @destination.

  Normally only a subset of the file attributes are copied,
  those that are copies in a normal file copy operation
  (which for instance does not include e.g. owner). However
  if %G_FILE_COPY_ALL_METADATA is specified in @flags, then
  all the metadata that is possible to copy is copied. This
  is useful when implementing move by copy + delete source. *)

  external build_attribute_list_for_copy :
    t ->
    Gio_enums.filecopyflags ->
    Cancellable.t option ->
    (string, GError.t) result = "ml_g_file_build_attribute_list_for_copy"
  (** Prepares the file attribute query string for copying to @file.

  This function prepares an attribute query string to be
  passed to g_file_query_info() to get a list of attributes
  normally copied with the file (see g_file_copy_attributes()
  for the detailed description). This function is used by the
  implementation of g_file_copy_attributes() and is useful
  when one needs to query and set the attributes in two
  stages (e.g., for recursive move of a directory). *)

  external append_to_finish :
    t -> Async_result.t -> (File_output_stream.t, GError.t) result
    = "ml_g_file_append_to_finish"
  (** Finishes an asynchronous file append operation started with
      g_file_append_to_async(). *)

  external append_to :
    t ->
    Gio_enums.filecreateflags ->
    Cancellable.t option ->
    (File_output_stream.t, GError.t) result = "ml_g_file_append_to"
  (** Gets an output stream for appending data to the file.
  If the file doesn't already exist it is created.

  By default files created are generally readable by everyone,
  but if you pass %G_FILE_CREATE_PRIVATE in @flags the file
  will be made readable only to the current user, to the level that
  is supported on the target filesystem.

  If @cancellable is not %NULL, then the operation can be cancelled
  by triggering the cancellable object from another thread. If the
  operation was cancelled, the error %G_IO_ERROR_CANCELLED will be
  returned.

  Some file systems don't allow all file names, and may return an
  %G_IO_ERROR_INVALID_FILENAME error. If the file is a directory the
  %G_IO_ERROR_IS_DIRECTORY error will be returned. Other errors are
  possible too, and depend on what kind of filesystem the file is on. *)
end

and File_enumerator : sig
  type t = [ `file_enumerator | `object_ ] Gobject.obj

  (* Methods *)

  external set_pending : t -> bool -> unit = "ml_g_file_enumerator_set_pending"
  (** Sets the file enumerator as having pending operations. *)

  external next_files_finish :
    t -> Async_result.t -> (File_info.t list, GError.t) result
    = "ml_g_file_enumerator_next_files_finish"
  (** Finishes the asynchronous operation started with
      g_file_enumerator_next_files_async(). *)

  external next_file :
    t -> Cancellable.t option -> (File_info.t option, GError.t) result
    = "ml_g_file_enumerator_next_file"
  (** Returns information for the next file in the enumerated object.
  Will block until the information is available. The #GFileInfo
  returned from this function will contain attributes that match the
  attribute string that was passed when the #GFileEnumerator was created.

  See the documentation of #GFileEnumerator for information about the
  order of returned files.

  On error, returns %NULL and sets @error to the error. If the
  enumerator is at the end, %NULL will be returned and @error will
  be unset. *)

  external is_closed : t -> bool = "ml_g_file_enumerator_is_closed"
  (** Checks if the file enumerator has been closed. *)

  external has_pending : t -> bool = "ml_g_file_enumerator_has_pending"
  (** Checks if the file enumerator has pending operations. *)

  external get_container : t -> File.t = "ml_g_file_enumerator_get_container"
  (** Get the #GFile container which is being enumerated. *)

  external get_child : t -> File_info.t -> File.t
    = "ml_g_file_enumerator_get_child"
  (** Return a new #GFile which refers to the file named by @info in the source
  directory of @enumerator.  This function is primarily intended to be used
  inside loops with g_file_enumerator_next_file().

  To use this, %G_FILE_ATTRIBUTE_STANDARD_NAME must have been listed in the
  attributes list used when creating the #GFileEnumerator.

  This is a convenience method that's equivalent to:
  |[<!-- language="C" -->
    gchar *name = g_file_info_get_name (info);
    GFile *child = g_file_get_child (g_file_enumerator_get_container (enumr),
                                     name);
  ]| *)

  external close_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_enumerator_close_finish"
  (** Finishes closing a file enumerator, started from g_file_enumerator_close_async().

  If the file enumerator was already closed when g_file_enumerator_close_async()
  was called, then this function will report %G_IO_ERROR_CLOSED in @error, and
  return %FALSE. If the file enumerator had pending operation when the close
  operation was started, then this function will report %G_IO_ERROR_PENDING, and
  return %FALSE.  If @cancellable was not %NULL, then the operation may have been
  cancelled by triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be set, and %FALSE will be
  returned. *)

  external close : t -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_file_enumerator_close"
  (** Releases all resources used by this enumerator, making the enumerator
      return %G_IO_ERROR_CLOSED on all calls.

      This will be automatically called when the last reference is dropped, but
      you might want to call this function to make sure resources are released
      as early as possible. *)

  (* Properties *)
end = struct
  type t = [ `file_enumerator | `object_ ] Gobject.obj

  (* Methods *)

  external set_pending : t -> bool -> unit = "ml_g_file_enumerator_set_pending"
  (** Sets the file enumerator as having pending operations. *)

  external next_files_finish :
    t -> Async_result.t -> (File_info.t list, GError.t) result
    = "ml_g_file_enumerator_next_files_finish"
  (** Finishes the asynchronous operation started with
      g_file_enumerator_next_files_async(). *)

  external next_file :
    t -> Cancellable.t option -> (File_info.t option, GError.t) result
    = "ml_g_file_enumerator_next_file"
  (** Returns information for the next file in the enumerated object.
  Will block until the information is available. The #GFileInfo
  returned from this function will contain attributes that match the
  attribute string that was passed when the #GFileEnumerator was created.

  See the documentation of #GFileEnumerator for information about the
  order of returned files.

  On error, returns %NULL and sets @error to the error. If the
  enumerator is at the end, %NULL will be returned and @error will
  be unset. *)

  external is_closed : t -> bool = "ml_g_file_enumerator_is_closed"
  (** Checks if the file enumerator has been closed. *)

  external has_pending : t -> bool = "ml_g_file_enumerator_has_pending"
  (** Checks if the file enumerator has pending operations. *)

  external get_container : t -> File.t = "ml_g_file_enumerator_get_container"
  (** Get the #GFile container which is being enumerated. *)

  external get_child : t -> File_info.t -> File.t
    = "ml_g_file_enumerator_get_child"
  (** Return a new #GFile which refers to the file named by @info in the source
  directory of @enumerator.  This function is primarily intended to be used
  inside loops with g_file_enumerator_next_file().

  To use this, %G_FILE_ATTRIBUTE_STANDARD_NAME must have been listed in the
  attributes list used when creating the #GFileEnumerator.

  This is a convenience method that's equivalent to:
  |[<!-- language="C" -->
    gchar *name = g_file_info_get_name (info);
    GFile *child = g_file_get_child (g_file_enumerator_get_container (enumr),
                                     name);
  ]| *)

  external close_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_file_enumerator_close_finish"
  (** Finishes closing a file enumerator, started from g_file_enumerator_close_async().

  If the file enumerator was already closed when g_file_enumerator_close_async()
  was called, then this function will report %G_IO_ERROR_CLOSED in @error, and
  return %FALSE. If the file enumerator had pending operation when the close
  operation was started, then this function will report %G_IO_ERROR_PENDING, and
  return %FALSE.  If @cancellable was not %NULL, then the operation may have been
  cancelled by triggering the cancellable object from another thread. If the operation
  was cancelled, the error %G_IO_ERROR_CANCELLED will be set, and %FALSE will be
  returned. *)

  external close : t -> Cancellable.t option -> (bool, GError.t) result
    = "ml_g_file_enumerator_close"
  (** Releases all resources used by this enumerator, making the enumerator
      return %G_IO_ERROR_CLOSED on all calls.

      This will be automatically called when the last reference is dropped, but
      you might want to call this function to make sure resources are released
      as early as possible. *)

  (* Properties *)
end

and File_monitor : sig
  type t = [ `file_monitor | `object_ ] Gobject.obj

  (* Methods *)

  external set_rate_limit : t -> int -> unit
    = "ml_g_file_monitor_set_rate_limit"
  (** Sets the rate limit to which the @monitor will report
  consecutive change events to the same file. *)

  external is_cancelled : t -> bool = "ml_g_file_monitor_is_cancelled"
  (** Returns whether the monitor is canceled. *)

  external emit_event :
    t -> File.t -> File.t option -> Gio_enums.filemonitorevent -> unit
    = "ml_g_file_monitor_emit_event"
  (** Emits the #GFileMonitor::changed signal if a change has taken place.
      Should be called from file monitor implementations only.

      Implementations are responsible to call this method from the
      thread-default main context (see
      [method@GLib.MainContext.push_thread_default]) of the thread that the
      monitor was created in. *)

  external cancel : t -> bool = "ml_g_file_monitor_cancel"
  (** Cancels a file monitor. *)

  (* Properties *)

  val on_changed :
    ?after:bool ->
    t ->
    callback:
      (file:File.t ->
      other_file:File.t option ->
      event_type:Gio_enums.filemonitorevent ->
      unit) ->
    Gobject.Signal.handler_id
end = struct
  type t = [ `file_monitor | `object_ ] Gobject.obj

  (* Methods *)

  external set_rate_limit : t -> int -> unit
    = "ml_g_file_monitor_set_rate_limit"
  (** Sets the rate limit to which the @monitor will report
  consecutive change events to the same file. *)

  external is_cancelled : t -> bool = "ml_g_file_monitor_is_cancelled"
  (** Returns whether the monitor is canceled. *)

  external emit_event :
    t -> File.t -> File.t option -> Gio_enums.filemonitorevent -> unit
    = "ml_g_file_monitor_emit_event"
  (** Emits the #GFileMonitor::changed signal if a change has taken place.
      Should be called from file monitor implementations only.

      Implementations are responsible to call this method from the
      thread-default main context (see
      [method@GLib.MainContext.push_thread_default]) of the thread that the
      monitor was created in. *)

  external cancel : t -> bool = "ml_g_file_monitor_cancel"
  (** Cancels a file monitor. *)

  (* Properties *)

  let on_changed ?after obj ~callback =
    let closure =
      Gobject.Closure.create (fun argv ->
          let file =
            let v = Gobject.Closure.nth argv ~pos:1 in
            Gobject.Value.get_object_exn v
          in
          let other_file =
            let v = Gobject.Closure.nth argv ~pos:2 in
            Gobject.Value.get_object v
          in
          let event_type =
            let v = Gobject.Closure.nth argv ~pos:3 in
            Gio_enums.filemonitorevent_of_int (Gobject.Value.get_enum_int v)
          in
          callback ~file ~other_file ~event_type)
    in
    Gobject.Signal.connect obj ~name:"changed" ~callback:closure
      ~after:(Option.value after ~default:false)
end

and Mount : sig
  type t = [ `mount ] Gobject.obj

  external from_gobject : 'a Gobject.obj -> t = "ml_gio_mount_from_gobject"

  (* Methods *)

  external unshadow : t -> unit = "ml_g_mount_unshadow"
  (** Decrements the shadow count on @mount. Usually used by
  #GVolumeMonitor implementations when destroying a shadow mount for
  @mount, see g_mount_is_shadowed() for more information. The caller
  will need to emit the #GMount::changed signal on @mount manually. *)

  external unmount_with_operation_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_mount_unmount_with_operation_finish"
  (** Finishes unmounting a mount. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external unmount_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_mount_unmount_finish"
  (** Finishes unmounting a mount. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external shadow : t -> unit = "ml_g_mount_shadow"
  (** Increments the shadow count on @mount. Usually used by
  #GVolumeMonitor implementations when creating a shadow mount for
  @mount, see g_mount_is_shadowed() for more information. The caller
  will need to emit the #GMount::changed signal on @mount manually. *)

  external remount_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_mount_remount_finish"
  (** Finishes remounting a mount. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external is_shadowed : t -> bool = "ml_g_mount_is_shadowed"
  (** Determines if @mount is shadowed. Applications or libraries should
  avoid displaying @mount in the user interface if it is shadowed.

  A mount is said to be shadowed if there exists one or more user
  visible objects (currently #GMount objects) with a root that is
  inside the root of @mount.

  One application of shadow mounts is when exposing a single file
  system that is used to address several logical volumes. In this
  situation, a #GVolumeMonitor implementation would create two
  #GVolume objects (for example, one for the camera functionality of
  the device and one for a SD card reader on the device) with
  activation URIs `gphoto2://[usb:001,002]/store1/`
  and `gphoto2://[usb:001,002]/store2/`. When the
  underlying mount (with root
  `gphoto2://[usb:001,002]/`) is mounted, said
  #GVolumeMonitor implementation would create two #GMount objects
  (each with their root matching the corresponding volume activation
  root) that would shadow the original mount.

  The proxy monitor in GVfs 2.26 and later, automatically creates and
  manage shadow mounts (and shadows the underlying mount) if the
  activation root on a #GVolume is set. *)

  external guess_content_type_sync :
    t -> bool -> Cancellable.t option -> (string array, GError.t) result
    = "ml_g_mount_guess_content_type_sync"
  (** Tries to guess the type of content stored on @mount. Returns one or
  more textual identifiers of well-known content types (typically
  prefixed with "x-content/"), e.g. x-content/image-dcf for camera
  memory cards. See the
  [shared-mime-info](http://www.freedesktop.org/wiki/Specifications/shared-mime-info-spec)
  specification for more on x-content types.

  This is a synchronous operation and as such may block doing IO;
  see g_mount_guess_content_type() for the asynchronous version. *)

  external guess_content_type_finish :
    t -> Async_result.t -> (string array, GError.t) result
    = "ml_g_mount_guess_content_type_finish"
  (** Finishes guessing content types of @mount. If any errors occurred
  during the operation, @error will be set to contain the errors and
  %FALSE will be returned. In particular, you may get an
  %G_IO_ERROR_NOT_SUPPORTED if the mount does not support content
  guessing. *)

  external get_volume : t -> Volume.t option = "ml_g_mount_get_volume"
  (** Gets the volume for the @mount. *)

  external get_uuid : t -> string option = "ml_g_mount_get_uuid"
  (** Gets the UUID for the @mount. The reference is typically based on
  the file system UUID for the mount in question and should be
  considered an opaque string. Returns %NULL if there is no UUID
  available. *)

  external get_symbolic_icon : t -> Icon.t = "ml_g_mount_get_symbolic_icon"
  (** Gets the symbolic icon for @mount. *)

  external get_sort_key : t -> string option = "ml_g_mount_get_sort_key"
  (** Gets the sort key for @mount, if any. *)

  external get_root : t -> File.t = "ml_g_mount_get_root"
  (** Gets the root directory on @mount. *)

  external get_name : t -> string = "ml_g_mount_get_name"
  (** Gets the name of @mount. *)

  external get_icon : t -> Icon.t = "ml_g_mount_get_icon"
  (** Gets the icon for @mount. *)

  external get_drive : t -> Drive.t option = "ml_g_mount_get_drive"
  (** Gets the drive for the @mount.

  This is a convenience method for getting the #GVolume and then
  using that object to get the #GDrive. *)

  external get_default_location : t -> File.t
    = "ml_g_mount_get_default_location"
  (** Gets the default location of @mount. The default location of the given
  @mount is a path that reflects the main entry point for the user (e.g.
  the home directory, or the root of the volume). *)

  external eject_with_operation_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_mount_eject_with_operation_finish"
  (** Finishes ejecting a mount. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external eject_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_mount_eject_finish"
  (** Finishes ejecting a mount. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external can_unmount : t -> bool = "ml_g_mount_can_unmount"
  (** Checks if @mount can be unmounted. *)

  external can_eject : t -> bool = "ml_g_mount_can_eject"
  (** Checks if @mount can be ejected. *)

  val on_changed :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_pre_unmount :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_unmounted :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
end = struct
  type t = [ `mount ] Gobject.obj

  external from_gobject : 'a Gobject.obj -> t = "ml_gio_mount_from_gobject"

  (* Methods *)

  external unshadow : t -> unit = "ml_g_mount_unshadow"
  (** Decrements the shadow count on @mount. Usually used by
  #GVolumeMonitor implementations when destroying a shadow mount for
  @mount, see g_mount_is_shadowed() for more information. The caller
  will need to emit the #GMount::changed signal on @mount manually. *)

  external unmount_with_operation_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_mount_unmount_with_operation_finish"
  (** Finishes unmounting a mount. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external unmount_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_mount_unmount_finish"
  (** Finishes unmounting a mount. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external shadow : t -> unit = "ml_g_mount_shadow"
  (** Increments the shadow count on @mount. Usually used by
  #GVolumeMonitor implementations when creating a shadow mount for
  @mount, see g_mount_is_shadowed() for more information. The caller
  will need to emit the #GMount::changed signal on @mount manually. *)

  external remount_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_mount_remount_finish"
  (** Finishes remounting a mount. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external is_shadowed : t -> bool = "ml_g_mount_is_shadowed"
  (** Determines if @mount is shadowed. Applications or libraries should
  avoid displaying @mount in the user interface if it is shadowed.

  A mount is said to be shadowed if there exists one or more user
  visible objects (currently #GMount objects) with a root that is
  inside the root of @mount.

  One application of shadow mounts is when exposing a single file
  system that is used to address several logical volumes. In this
  situation, a #GVolumeMonitor implementation would create two
  #GVolume objects (for example, one for the camera functionality of
  the device and one for a SD card reader on the device) with
  activation URIs `gphoto2://[usb:001,002]/store1/`
  and `gphoto2://[usb:001,002]/store2/`. When the
  underlying mount (with root
  `gphoto2://[usb:001,002]/`) is mounted, said
  #GVolumeMonitor implementation would create two #GMount objects
  (each with their root matching the corresponding volume activation
  root) that would shadow the original mount.

  The proxy monitor in GVfs 2.26 and later, automatically creates and
  manage shadow mounts (and shadows the underlying mount) if the
  activation root on a #GVolume is set. *)

  external guess_content_type_sync :
    t -> bool -> Cancellable.t option -> (string array, GError.t) result
    = "ml_g_mount_guess_content_type_sync"
  (** Tries to guess the type of content stored on @mount. Returns one or
  more textual identifiers of well-known content types (typically
  prefixed with "x-content/"), e.g. x-content/image-dcf for camera
  memory cards. See the
  [shared-mime-info](http://www.freedesktop.org/wiki/Specifications/shared-mime-info-spec)
  specification for more on x-content types.

  This is a synchronous operation and as such may block doing IO;
  see g_mount_guess_content_type() for the asynchronous version. *)

  external guess_content_type_finish :
    t -> Async_result.t -> (string array, GError.t) result
    = "ml_g_mount_guess_content_type_finish"
  (** Finishes guessing content types of @mount. If any errors occurred
  during the operation, @error will be set to contain the errors and
  %FALSE will be returned. In particular, you may get an
  %G_IO_ERROR_NOT_SUPPORTED if the mount does not support content
  guessing. *)

  external get_volume : t -> Volume.t option = "ml_g_mount_get_volume"
  (** Gets the volume for the @mount. *)

  external get_uuid : t -> string option = "ml_g_mount_get_uuid"
  (** Gets the UUID for the @mount. The reference is typically based on
  the file system UUID for the mount in question and should be
  considered an opaque string. Returns %NULL if there is no UUID
  available. *)

  external get_symbolic_icon : t -> Icon.t = "ml_g_mount_get_symbolic_icon"
  (** Gets the symbolic icon for @mount. *)

  external get_sort_key : t -> string option = "ml_g_mount_get_sort_key"
  (** Gets the sort key for @mount, if any. *)

  external get_root : t -> File.t = "ml_g_mount_get_root"
  (** Gets the root directory on @mount. *)

  external get_name : t -> string = "ml_g_mount_get_name"
  (** Gets the name of @mount. *)

  external get_icon : t -> Icon.t = "ml_g_mount_get_icon"
  (** Gets the icon for @mount. *)

  external get_drive : t -> Drive.t option = "ml_g_mount_get_drive"
  (** Gets the drive for the @mount.

  This is a convenience method for getting the #GVolume and then
  using that object to get the #GDrive. *)

  external get_default_location : t -> File.t
    = "ml_g_mount_get_default_location"
  (** Gets the default location of @mount. The default location of the given
  @mount is a path that reflects the main entry point for the user (e.g.
  the home directory, or the root of the volume). *)

  external eject_with_operation_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_mount_eject_with_operation_finish"
  (** Finishes ejecting a mount. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external eject_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_mount_eject_finish"
  (** Finishes ejecting a mount. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external can_unmount : t -> bool = "ml_g_mount_can_unmount"
  (** Checks if @mount can be unmounted. *)

  external can_eject : t -> bool = "ml_g_mount_can_eject"
  (** Checks if @mount can be ejected. *)

  let on_changed ?after obj ~callback =
    Gobject.Signal.connect_simple obj ~name:"changed" ~callback
      ~after:(Option.value after ~default:false)

  let on_pre_unmount ?after obj ~callback =
    Gobject.Signal.connect_simple obj ~name:"pre-unmount" ~callback
      ~after:(Option.value after ~default:false)

  let on_unmounted ?after obj ~callback =
    Gobject.Signal.connect_simple obj ~name:"unmounted" ~callback
      ~after:(Option.value after ~default:false)
end

and Volume : sig
  type t = [ `volume ] Gobject.obj

  external from_gobject : 'a Gobject.obj -> t = "ml_gio_volume_from_gobject"

  (* Methods *)

  external should_automount : t -> bool = "ml_g_volume_should_automount"
  (** Returns whether the volume should be automatically mounted. *)

  external mount_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_volume_mount_finish"
  (** Finishes mounting a volume. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned.

  If the mount operation succeeded, g_volume_get_mount() on @volume
  is guaranteed to return the mount right after calling this
  function; there's no need to listen for the 'mount-added' signal on
  #GVolumeMonitor. *)

  external get_uuid : t -> string option = "ml_g_volume_get_uuid"
  (** Gets the UUID for the @volume. The reference is typically based on
  the file system UUID for the volume in question and should be
  considered an opaque string. Returns %NULL if there is no UUID
  available. *)

  external get_symbolic_icon : t -> Icon.t = "ml_g_volume_get_symbolic_icon"
  (** Gets the symbolic icon for @volume. *)

  external get_sort_key : t -> string option = "ml_g_volume_get_sort_key"
  (** Gets the sort key for @volume, if any. *)

  external get_name : t -> string = "ml_g_volume_get_name"
  (** Gets the name of @volume. *)

  external get_mount : t -> Mount.t option = "ml_g_volume_get_mount"
  (** Gets the mount for the @volume. *)

  external get_identifier : t -> string -> string option
    = "ml_g_volume_get_identifier"
  (** Gets the identifier of the given kind for @volume.
  See the [introduction](#volume-identifiers) for more
  information about volume identifiers. *)

  external get_icon : t -> Icon.t = "ml_g_volume_get_icon"
  (** Gets the icon for @volume. *)

  external get_drive : t -> Drive.t option = "ml_g_volume_get_drive"
  (** Gets the drive for the @volume. *)

  external get_activation_root : t -> File.t option
    = "ml_g_volume_get_activation_root"
  (** Gets the activation root for a #GVolume if it is known ahead of
  mount time. Returns %NULL otherwise. If not %NULL and if @volume
  is mounted, then the result of g_mount_get_root() on the
  #GMount object obtained from g_volume_get_mount() will always
  either be equal or a prefix of what this function returns. In
  other words, in code

  |[<!-- language="C" -->
    GMount *mount;
    GFile *mount_root
    GFile *volume_activation_root;

    mount = g_volume_get_mount (volume); // mounted, so never NULL
    mount_root = g_mount_get_root (mount);
    volume_activation_root = g_volume_get_activation_root (volume); // assume not NULL
  ]|
  then the expression
  |[<!-- language="C" -->
    (g_file_has_prefix (volume_activation_root, mount_root) ||
     g_file_equal (volume_activation_root, mount_root))
  ]|
  will always be %TRUE.

  Activation roots are typically used in #GVolumeMonitor
  implementations to find the underlying mount to shadow, see
  g_mount_is_shadowed() for more details. *)

  external enumerate_identifiers : t -> string array
    = "ml_g_volume_enumerate_identifiers"
  (** Gets the kinds of [identifiers](#volume-identifiers) that @volume has.
  Use g_volume_get_identifier() to obtain the identifiers themselves. *)

  external eject_with_operation_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_volume_eject_with_operation_finish"
  (** Finishes ejecting a volume. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external eject_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_volume_eject_finish"
  (** Finishes ejecting a volume. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external can_mount : t -> bool = "ml_g_volume_can_mount"
  (** Checks if a volume can be mounted. *)

  external can_eject : t -> bool = "ml_g_volume_can_eject"
  (** Checks if a volume can be ejected. *)

  val on_changed :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_removed :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
end = struct
  type t = [ `volume ] Gobject.obj

  external from_gobject : 'a Gobject.obj -> t = "ml_gio_volume_from_gobject"

  (* Methods *)

  external should_automount : t -> bool = "ml_g_volume_should_automount"
  (** Returns whether the volume should be automatically mounted. *)

  external mount_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_volume_mount_finish"
  (** Finishes mounting a volume. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned.

  If the mount operation succeeded, g_volume_get_mount() on @volume
  is guaranteed to return the mount right after calling this
  function; there's no need to listen for the 'mount-added' signal on
  #GVolumeMonitor. *)

  external get_uuid : t -> string option = "ml_g_volume_get_uuid"
  (** Gets the UUID for the @volume. The reference is typically based on
  the file system UUID for the volume in question and should be
  considered an opaque string. Returns %NULL if there is no UUID
  available. *)

  external get_symbolic_icon : t -> Icon.t = "ml_g_volume_get_symbolic_icon"
  (** Gets the symbolic icon for @volume. *)

  external get_sort_key : t -> string option = "ml_g_volume_get_sort_key"
  (** Gets the sort key for @volume, if any. *)

  external get_name : t -> string = "ml_g_volume_get_name"
  (** Gets the name of @volume. *)

  external get_mount : t -> Mount.t option = "ml_g_volume_get_mount"
  (** Gets the mount for the @volume. *)

  external get_identifier : t -> string -> string option
    = "ml_g_volume_get_identifier"
  (** Gets the identifier of the given kind for @volume.
  See the [introduction](#volume-identifiers) for more
  information about volume identifiers. *)

  external get_icon : t -> Icon.t = "ml_g_volume_get_icon"
  (** Gets the icon for @volume. *)

  external get_drive : t -> Drive.t option = "ml_g_volume_get_drive"
  (** Gets the drive for the @volume. *)

  external get_activation_root : t -> File.t option
    = "ml_g_volume_get_activation_root"
  (** Gets the activation root for a #GVolume if it is known ahead of
  mount time. Returns %NULL otherwise. If not %NULL and if @volume
  is mounted, then the result of g_mount_get_root() on the
  #GMount object obtained from g_volume_get_mount() will always
  either be equal or a prefix of what this function returns. In
  other words, in code

  |[<!-- language="C" -->
    GMount *mount;
    GFile *mount_root
    GFile *volume_activation_root;

    mount = g_volume_get_mount (volume); // mounted, so never NULL
    mount_root = g_mount_get_root (mount);
    volume_activation_root = g_volume_get_activation_root (volume); // assume not NULL
  ]|
  then the expression
  |[<!-- language="C" -->
    (g_file_has_prefix (volume_activation_root, mount_root) ||
     g_file_equal (volume_activation_root, mount_root))
  ]|
  will always be %TRUE.

  Activation roots are typically used in #GVolumeMonitor
  implementations to find the underlying mount to shadow, see
  g_mount_is_shadowed() for more details. *)

  external enumerate_identifiers : t -> string array
    = "ml_g_volume_enumerate_identifiers"
  (** Gets the kinds of [identifiers](#volume-identifiers) that @volume has.
  Use g_volume_get_identifier() to obtain the identifiers themselves. *)

  external eject_with_operation_finish :
    t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_volume_eject_with_operation_finish"
  (** Finishes ejecting a volume. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external eject_finish : t -> Async_result.t -> (bool, GError.t) result
    = "ml_g_volume_eject_finish"
  (** Finishes ejecting a volume. If any errors occurred during the operation,
  @error will be set to contain the errors and %FALSE will be returned. *)

  external can_mount : t -> bool = "ml_g_volume_can_mount"
  (** Checks if a volume can be mounted. *)

  external can_eject : t -> bool = "ml_g_volume_can_eject"
  (** Checks if a volume can be ejected. *)

  let on_changed ?after obj ~callback =
    Gobject.Signal.connect_simple obj ~name:"changed" ~callback
      ~after:(Option.value after ~default:false)

  let on_removed ?after obj ~callback =
    Gobject.Signal.connect_simple obj ~name:"removed" ~callback
      ~after:(Option.value after ~default:false)
end
