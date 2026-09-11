(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec Application : sig
  type t = [ `application | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_application_get_type"

  external new_ : string option -> Ocgtk_gio.Gio.applicationflags -> t
    = "ml_gtk_application_new"
  (** Create a new Application *)

  (* Methods *)

  external uninhibit : t -> int -> unit = "ml_gtk_application_uninhibit"
  (** Removes an inhibitor that has been previously established.

      See [method@Gtk.Application.inhibit].

      Inhibitors are also cleared when the application exits. *)

  external set_menubar : t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option -> unit
    = "ml_gtk_application_set_menubar"
  (** Sets or unsets the menubar for windows of the application.

      This is a menubar in the traditional sense.

      This can only be done in the primary instance of the application, after it
      has been registered. [vfunc@GIO.Application.startup] is a good place to
      call this.

      Depending on the desktop environment, this may appear at the top of each
      window, or at the top of the screen. In some environments, if both the
      application menu and the menubar are set, the application menu will be
      presented as if it were the first item of the menubar. Other environments
      treat the two as completely separate — for example, the application menu
      may be rendered by the desktop shell while the menubar (if set) remains in
      each individual window.

      Use the base `GActionMap` interface to add actions, to respond to the user
      selecting these menu items. *)

  external set_accels_for_action : t -> string -> string array -> unit
    = "ml_gtk_application_set_accels_for_action"
  (** Sets zero or more keyboard accelerators that will trigger the
  given action.

  The first item in @accels will be the primary accelerator,
  which may be displayed in the UI.

  To remove all accelerators for an action, use an empty,
  zero-terminated array for @accels.

  For the @detailed_action_name, see [func@Gio.Action.parse_detailed_name]
  and [Gio.Action.print_detailed_name]. *)

  external remove_window : t -> Window.t -> unit
    = "ml_gtk_application_remove_window"
  (** Remove a window from the application.

      If the window belongs to the application then this call is equivalent to
      setting the [property@Gtk.Window:application] property of the window to
      `NULL`.

      The application may stop running as a result of a call to this function,
      if the window was the last window of the application. *)

  external list_action_descriptions : t -> string array
    = "ml_gtk_application_list_action_descriptions"
  (** Lists the detailed action names which have associated accelerators.

      See [method@Gtk.Application.set_accels_for_action]. *)

  external inhibit :
    t ->
    Window.t option ->
    Gtk_enums.applicationinhibitflags ->
    string option ->
    int = "ml_gtk_application_inhibit"
  (** Informs the session manager that certain types of actions should be
  inhibited.

  This is not guaranteed to work on all platforms and for all types of
  actions.

  Applications should invoke this method when they begin an operation
  that should not be interrupted, such as creating a CD or DVD. The
  types of actions that may be blocked are specified by the @flags
  parameter. When the application completes the operation it should
  call [method@Gtk.Application.uninhibit] to remove the inhibitor. Note
  that an application can have multiple inhibitors, and all of them must
  be individually removed. Inhibitors are also cleared when the
  application exits.

  Applications should not expect that they will always be able to block
  the action. In most cases, users will be given the option to force
  the action to take place.

  The @reason message should be short and to the point.

  If a window is given, the session manager may point the user to
  this window to find out more about why the action is inhibited.

  The cookie that is returned by this function  should be used as an
  argument to [method@Gtk.Application.uninhibit] in order to remove
  the request. *)

  external get_windows : t -> Window.t list = "ml_gtk_application_get_windows"
  (** Gets a list of the window associated with the application.

      The list is sorted by most recently focused window, such that the first
      element is the currently focused window. (Useful for choosing a parent for
      a transient window.)

      The list that is returned should not be modified in any way. It will only
      remain valid until the next focus change or window creation or deletion.
  *)

  external get_window_by_id : t -> int -> Window.t option
    = "ml_gtk_application_get_window_by_id"
  (** Returns the window with the given ID.

      The ID of a `GtkApplicationWindow` can be retrieved with
      [method@Gtk.ApplicationWindow.get_id]. *)

  external get_menubar : t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option
    = "ml_gtk_application_get_menubar"
  (** Returns the menu model for the menu bar of the application. *)

  external get_menu_by_id : t -> string -> Ocgtk_gio.Gio.Wrappers.Menu.t option
    = "ml_gtk_application_get_menu_by_id"
  (** Gets a menu from automatically loaded resources.

      See
      [the section on Automatic resources](class.Application.html#automatic-resources)
      for more information. *)

  external get_active_window : t -> Window.t option
    = "ml_gtk_application_get_active_window"
  (** Gets the “active” window for the application.

      The active window is the one that was most recently focused (within the
      application). This window may not have the focus at the moment if another
      application has it — this is just the most recently-focused window within
      this application. *)

  external get_actions_for_accel : t -> string -> string array
    = "ml_gtk_application_get_actions_for_accel"
  (** Returns the list of actions (possibly empty) that the accelerator maps to.

      Each item in the list is a detailed action name in the usual form.

      This might be useful to discover if an accel already exists in order to
      prevent installation of a conflicting accelerator (from an accelerator
      editor or a plugin system, for example). Note that having more than one
      action per accelerator may not be a bad thing and might make sense in
      cases where the actions never appear in the same context.

      In case there are no actions for a given accelerator, an empty array is
      returned. `NULL` is never returned.

      It is a programmer error to pass an invalid accelerator string.

      If you are unsure, check it with [func@Gtk.accelerator_parse] first. *)

  external get_accels_for_action : t -> string -> string array
    = "ml_gtk_application_get_accels_for_action"
  (** Gets the accelerators that are currently associated with the given action.
  *)

  external add_window : t -> Window.t -> unit = "ml_gtk_application_add_window"
  (** Adds a window to the application.

  This call can only happen after the application has started;
  typically, you should add new application windows in response
  to the emission of the [signal@GIO.Application::activate] signal.

  This call is equivalent to setting the [property@Gtk.Window:application]
  property of the window to @application.

  Normally, the connection between the application and the window
  will remain until the window is destroyed, but you can explicitly
  remove it with [method@Gtk.Application.remove_window].

  GTK will keep the application running as long as it has any windows. *)

  (* Properties *)

  external get_register_session : t -> bool
    = "ml_gtk_application_get_register_session"
  (** Get property: register-session *)

  external set_register_session : t -> bool -> unit
    = "ml_gtk_application_set_register_session"
  (** Set property: register-session *)

  external get_screensaver_active : t -> bool
    = "ml_gtk_application_get_screensaver_active"
  (** Get property: screensaver-active *)

  val on_query_end :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_window_added :
    ?after:bool ->
    t ->
    callback:(window:Window.t -> unit) ->
    Gobject.Signal.handler_id

  val on_window_removed :
    ?after:bool ->
    t ->
    callback:(window:Window.t -> unit) ->
    Gobject.Signal.handler_id
end

and Window : sig
  type t = [ `window | `widget | `initially_unowned | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_window_get_type"

  external new_ : unit -> t = "ml_gtk_window_new"
  (** Create a new Window *)

  (* Methods *)

  external unminimize : t -> unit = "ml_gtk_window_unminimize"
  (** Asks to unminimize the window.

      Note that you shouldn’t assume the window is definitely unminimized
      afterward, because the windowing system might not support this
      functionality; other entities (e.g. the user or the window manager) could
      minimize it again, or there may not be a window manager in which case
      minimization isn’t possible, etc.

      You can track result of this operation via the
      [property@Gdk.Toplevel:state] property. *)

  external unmaximize : t -> unit = "ml_gtk_window_unmaximize"
  (** Asks to unmaximize the window.

      Note that you shouldn’t assume the window is definitely unmaximized
      afterward, because other entities (e.g. the user or window manager)
      maximize it again, and not all window managers honor requests to
      unmaximize.

      If a window is not explicitly maximized or unmaximized before it is shown,
      the initial state is at the window managers discretion. For example, it
      might decide to maximize a window that almost fills the screen.

      You can track the result of this operation via the
      [property@Gdk.Toplevel:state] property, or by listening to notifications
      on the [property@Gtk.Window:maximized] property. *)

  external unfullscreen : t -> unit = "ml_gtk_window_unfullscreen"
  (** Asks to remove the fullscreen state for the window, and return to its
      previous state.

      Note that you shouldn’t assume the window is definitely not fullscreen
      afterward, because other entities (e.g. the user or window manager) could
      fullscreen it again, and not all window managers honor requests to
      unfullscreen windows; normally the window will end up restored to its
      normal state. Just don’t write code that crashes if not.

      If a window is not explicitly fullscreened or unfullscreened before it is
      shown, the initial state is at the window managers discretion.

      You can track the result of this operation via the
      [property@Gdk.Toplevel:state] property, or by listening to notifications
      of the [property@Gtk.Window:fullscreened] property. *)

  external set_transient_for : t -> t option -> unit
    = "ml_gtk_window_set_transient_for"
  (** Sets a transient parent for the window.

  Dialog windows should be set transient for the main application
  window they were spawned from. This allows window managers to e.g.
  keep the dialog on top of the main window, or center the dialog
  over the main window. [ctor@Gtk.Dialog.new_with_buttons] and other
  convenience functions in GTK will sometimes call this function on
  your behalf.

  Passing `NULL` for @parent unsets the current transient window.

  On Windows, this function puts the child window on top of the parent,
  much as the window manager would have done on X. *)

  external set_titlebar :
    t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t
    option ->
    unit = "ml_gtk_window_set_titlebar"
  (** Sets a custom titlebar for the window.

      A typical widget used here is [class@Gtk.HeaderBar], as it provides
      various features expected of a titlebar while allowing the addition of
      child widgets to it.

      If you set a custom titlebar, GTK will do its best to convince the window
      manager not to put its own titlebar on the window. Depending on the
      system, this function may not work for a window that is already visible,
      so you set the titlebar before calling [method@Gtk.Widget.show]. *)

  external set_title : t -> string option -> unit = "ml_gtk_window_set_title"
  (** Sets the title of the window.

      The title of a window will be displayed in its title bar; on the X Window
      System, the title bar is rendered by the window manager so exactly how the
      title appears to users may vary according to a user’s exact configuration.
      The title should help a user distinguish this window from other windows
      they may have open. A good title might include the application name and
      current document filename, for example.

      Passing `NULL` does the same as setting the title to an empty string. *)

  external set_startup_id : t -> string -> unit = "ml_gtk_window_set_startup_id"
  (** Sets the startup notification ID.

      Startup notification identifiers are used by desktop environment to track
      application startup, to provide user feedback and other features. This
      function changes the corresponding property on the underlying
      `GdkSurface`.

      Normally, startup identifier is managed automatically and you should only
      use this function in special cases like transferring focus from other
      processes. You should use this function before calling
      [method@Gtk.Window.present] or any equivalent function generating a window
      map event.

      This function is only useful on Wayland or X11, not with other GDK
      backends. *)

  external set_resizable : t -> bool -> unit = "ml_gtk_window_set_resizable"
  (** Sets whether the user can resize a window.

      Windows are user resizable by default. *)

  external set_modal : t -> bool -> unit = "ml_gtk_window_set_modal"
  (** Sets a window modal or non-modal.

      Modal windows prevent interaction with other windows in the same
      application. To keep modal dialogs on top of main application windows, use
      [method@Gtk.Window.set_transient_for] to make the dialog transient for the
      parent; most window managers will then disallow lowering the dialog below
      the parent. *)

  external set_mnemonics_visible : t -> bool -> unit
    = "ml_gtk_window_set_mnemonics_visible"
  (** Sets whether mnemonics are supposed to be visible.

      This property is maintained by GTK based on user input, and should not be
      set by applications. *)

  external set_icon_name : t -> string option -> unit
    = "ml_gtk_window_set_icon_name"
  (** Sets the icon for the window from a named themed icon.

      See the docs for [class@Gtk.IconTheme] for more details. On some
      platforms, the window icon is not used at all.

      Note that this has nothing to do with the WM_ICON_NAME property which is
      mentioned in the ICCCM. *)

  external set_hide_on_close : t -> bool -> unit
    = "ml_gtk_window_set_hide_on_close"
  (** Sets whether clicking the close button will hide the window instead of
      destroying it. *)

  external set_handle_menubar_accel : t -> bool -> unit
    = "ml_gtk_window_set_handle_menubar_accel"
  (** Sets whether this window should react to <kbd>F10</kbd> presses by
      activating a menubar it contains. *)

  external set_gravity : t -> Gtk_enums.windowgravity -> unit
    = "ml_gtk_window_set_gravity"
  (** Sets the gravity that is used when changing the window size
      programmatically. *)

  external set_focus_visible : t -> bool -> unit
    = "ml_gtk_window_set_focus_visible"
  (** Sets whether “focus rectangles” are supposed to be visible.

      This property is maintained by GTK based on user input, and should not be
      set by applications. *)

  external set_focus :
    t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t
    option ->
    unit = "ml_gtk_window_set_focus"
  (** Sets the focus widget.

  If @focus is not the current focus widget, and is focusable,
  sets it as the focus widget for the window. If @focus is %NULL,
  unsets the focus widget for this window. To set the focus to a
  particular widget in the toplevel, it is usually more convenient
  to use [method@Gtk.Widget.grab_focus] instead of this function. *)

  external set_display : t -> Ocgtk_gdk.Gdk.Wrappers.Display.t -> unit
    = "ml_gtk_window_set_display"
  (** Sets the display where the window is displayed.

      If the window is already mapped, it will be unmapped, and then remapped on
      the new display. *)

  external set_destroy_with_parent : t -> bool -> unit
    = "ml_gtk_window_set_destroy_with_parent"
  (** Sets whether to destroy the window when the transient parent is destroyed.

      This is useful for dialogs that shouldn’t persist beyond the lifetime of
      the main window they are associated with, for example. *)

  external set_deletable : t -> bool -> unit = "ml_gtk_window_set_deletable"
  (** Sets whether the window should be deletable.

      By default, windows have a close button in the window frame. Some window
      managers allow GTK to disable this button. If you set the deletable
      property to false using this function, GTK will do its best to convince
      the window manager not to show a close button. Depending on the system,
      this function may not have any effect when called on a window that is
      already visible, so you should call it before calling
      [method@Gtk.Widget.show].

      On Windows, this function always works, since there’s no window manager
      policy involved. *)

  external set_default_widget :
    t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t
    option ->
    unit = "ml_gtk_window_set_default_widget"
  (** Sets the default widget.

      The default widget is the widget that is activated when the user presses
      <kbd>Enter</kbd> in a dialog (for example). *)

  external set_default_size : t -> int -> int -> unit
    = "ml_gtk_window_set_default_size"
  (** Sets the default size of a window.

      The default size of a window is the size that will be used if no other
      constraints apply.

      The default size will be updated whenever the window is resized to reflect
      the new size, unless the window is forced to a size, like when it is
      maximized or fullscreened.

      If the window’s minimum size request is larger than the default, the
      default will be ignored.

      Setting the default size to a value <= 0 will cause it to be ignored and
      the natural size request will be used instead. It is possible to do this
      while the window is showing to "reset" it to its initial size.

      Unlike [method@Gtk.Widget.set_size_request], which sets a size request for
      a widget and thus would keep users from shrinking the window, this
      function only sets the initial size, just as if the user had resized the
      window themselves. Users can still shrink the window again as they
      normally would. Setting a default size of -1 means to use the “natural”
      default size (the size request of the window).

      If you use this function to reestablish a previously saved window size,
      note that the appropriate size to save is the one returned by
      [method@Gtk.Window.get_default_size]. Using the window allocation directly
      will not work in all circumstances and can lead to growing or shrinking
      windows. *)

  external set_decorated : t -> bool -> unit = "ml_gtk_window_set_decorated"
  (** Sets whether the window should be decorated.

      By default, windows are decorated with a title bar, resize controls, etc.
      Some window managers allow GTK to disable these decorations, creating a
      borderless window. If you set the decorated property to false using this
      function, GTK will do its best to convince the window manager not to
      decorate the window. Depending on the system, this function may not have
      any effect when called on a window that is already visible, so you should
      call it before calling [method@Gtk.Widget.show].

      On Windows, this function always works, since there’s no window manager
      policy involved. *)

  external set_child :
    t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t
    option ->
    unit = "ml_gtk_window_set_child"
  (** Sets the child widget of the window. *)

  external set_application : t -> Application.t option -> unit
    = "ml_gtk_window_set_application"
  (** Sets or unsets the application object associated with the window.

  The application will be kept alive for at least as long as it has
  any windows associated with it (see [method@Gio.Application.hold]
  for a way to keep it alive without windows).

  Normally, the connection between the application and the window will
  remain until the window is destroyed, but you can explicitly remove
  it by setting the @application to %NULL.

  This is equivalent to calling [method@Gtk.Application.remove_window]
  and/or [method@Gtk.Application.add_window] on the old/new applications
  as relevant. *)

  external present_with_time : t -> UInt32.t -> unit
    = "ml_gtk_window_present_with_time"
  (** Presents a window to the user in response to an user interaction.

      See [method@Gtk.Window.present] for more details.

      The timestamp should be gathered when the window was requested to be shown
      (when clicking a link for example), rather than once the window is ready
      to be shown. *)

  external present : t -> unit = "ml_gtk_window_present"
  (** Presents a window to the user.

  This may mean raising the window in the stacking order,
  unminimizing it, moving it to the current desktop and/or
  giving it the keyboard focus (possibly dependent on the user’s
  platform, window manager and preferences).

  If @window is hidden, this function also makes it visible. *)

  external minimize : t -> unit = "ml_gtk_window_minimize"
  (** Asks to minimize the window.

      Note that you shouldn’t assume the window is definitely minimized
      afterward, because the windowing system might not support this
      functionality; other entities (e.g. the user or the window manager) could
      unminimize it again, or there may not be a window manager in which case
      minimization isn’t possible, etc.

      It’s permitted to call this function before showing a window, in which
      case the window will be minimized before it ever appears onscreen.

      You can track result of this operation via the
      [property@Gdk.Toplevel:state] property. *)

  external maximize : t -> unit = "ml_gtk_window_maximize"
  (** Asks to maximize the window, so that it fills the screen.

      Note that you shouldn’t assume the window is definitely maximized
      afterward, because other entities (e.g. the user or window manager) could
      unmaximize it again, and not all window managers support maximization.

      It’s permitted to call this function before showing a window, in which
      case the window will be maximized when it appears onscreen initially.

      If a window is not explicitly maximized or unmaximized before it is shown,
      the initial state is at the window managers discretion. For example, it
      might decide to maximize a window that almost fills the screen.

      You can track the result of this operation via the
      [property@Gdk.Toplevel:state] property, or by listening to notifications
      on the [property@Gtk.Window:maximized] property. *)

  external is_suspended : t -> bool = "ml_gtk_window_is_suspended"
  (** Retrieves the current suspended state of the window.

      A window being suspended means it's currently not visible to the user, for
      example by being on a inactive workspace, minimized, obstructed. *)

  external is_maximized : t -> bool = "ml_gtk_window_is_maximized"
  (** Retrieves the current maximized state of the window.

      Note that since maximization is ultimately handled by the window manager
      and happens asynchronously to an application request, you shouldn’t assume
      the return value of this function changing immediately (or at all), as an
      effect of calling [method@Gtk.Window.maximize] or
      [method@Gtk.Window.unmaximize].

      If the window isn't yet mapped, the value returned will whether the
      initial requested state is maximized. *)

  external is_fullscreen : t -> bool = "ml_gtk_window_is_fullscreen"
  (** Retrieves the current fullscreen state of the window.

      Note that since fullscreening is ultimately handled by the window manager
      and happens asynchronously to an application request, you shouldn’t assume
      the return value of this function changing immediately (or at all), as an
      effect of calling [method@Gtk.Window.fullscreen] or
      [method@Gtk.Window.unfullscreen].

      If the window isn't yet mapped, the value returned will whether the
      initial requested state is fullscreen. *)

  external is_active : t -> bool = "ml_gtk_window_is_active"
  (** Returns whether the window is part of the current active toplevel.

      The active toplevel is the window receiving keystrokes.

      The return value is %TRUE if the window is active toplevel itself. You
      might use this function if you wanted to draw a widget differently in an
      active window from a widget in an inactive window. *)

  external has_group : t -> bool = "ml_gtk_window_has_group"
  (** Returns whether the window has an explicit window group. *)

  external get_transient_for : t -> t option = "ml_gtk_window_get_transient_for"
  (** Fetches the transient parent for this window. *)

  external get_titlebar :
    t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t
    option = "ml_gtk_window_get_titlebar"
  (** Returns the titlebar that has been set with
      [method@Gtk.Window.set_titlebar]. *)

  external get_title : t -> string option = "ml_gtk_window_get_title"
  (** Retrieves the title of the window. *)

  external get_resizable : t -> bool = "ml_gtk_window_get_resizable"
  (** Gets whether the user can resize the window. *)

  external get_modal : t -> bool = "ml_gtk_window_get_modal"
  (** Returns whether the window is modal. *)

  external get_mnemonics_visible : t -> bool
    = "ml_gtk_window_get_mnemonics_visible"
  (** Gets whether mnemonics are supposed to be visible. *)

  external get_icon_name : t -> string option = "ml_gtk_window_get_icon_name"
  (** Returns the name of the themed icon for the window. *)

  external get_hide_on_close : t -> bool = "ml_gtk_window_get_hide_on_close"
  (** Returns whether the window will be hidden instead of destroyed when the
      close button is clicked. *)

  external get_handle_menubar_accel : t -> bool
    = "ml_gtk_window_get_handle_menubar_accel"
  (** Returns whether this window reacts to <kbd>F10</kbd> presses by activating
      a menubar it contains. *)

  external get_group : t -> Window_group.t = "ml_gtk_window_get_group"
  (** Returns the group for the window.

      If the window has no group, then the default group is returned. *)

  external get_gravity : t -> Gtk_enums.windowgravity
    = "ml_gtk_window_get_gravity"
  (** Returns the gravity that is used when changing the window size
      programmatically. *)

  external get_focus_visible : t -> bool = "ml_gtk_window_get_focus_visible"
  (** Gets whether “focus rectangles” are supposed to be visible. *)

  external get_focus :
    t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t
    option = "ml_gtk_window_get_focus"
  (** Retrieves the current focused widget within the window.

      Note that this is the widget that would have the focus if the toplevel
      window focused; if the toplevel window is not focused then
      `gtk_widget_has_focus (widget)` will not be false for the widget. *)

  external get_destroy_with_parent : t -> bool
    = "ml_gtk_window_get_destroy_with_parent"
  (** Returns whether the window will be destroyed with its transient parent. *)

  external get_deletable : t -> bool = "ml_gtk_window_get_deletable"
  (** Returns whether the window has been set to have a close button. *)

  external get_default_widget :
    t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t
    option = "ml_gtk_window_get_default_widget"
  (** Returns the default widget for @window. *)

  external get_default_size : t -> int * int = "ml_gtk_window_get_default_size"
  (** Gets the default size of the window.

      A value of 0 for the width or height indicates that a default size has not
      been explicitly set for that dimension, so the “natural” size of the
      window will be used.

      This function is the recommended way for
      [saving window state across restarts of applications](https://developer.gnome.org/documentation/tutorials/save-state.html).
  *)

  external get_decorated : t -> bool = "ml_gtk_window_get_decorated"
  (** Returns whether the window has been set to have decorations. *)

  external get_child :
    t ->
    Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
    .Widget
    .t
    option = "ml_gtk_window_get_child"
  (** Gets the child widget of the window. *)

  external get_application : t -> Application.t option
    = "ml_gtk_window_get_application"
  (** Gets the application object associated with the window. *)

  external fullscreen_on_monitor : t -> Ocgtk_gdk.Gdk.Wrappers.Monitor.t -> unit
    = "ml_gtk_window_fullscreen_on_monitor"
  (** Asks to place the window in the fullscreen state on the given monitor.

      Note that you shouldn't assume the window is definitely fullscreen
      afterward, or that the windowing system allows fullscreen windows on any
      given monitor.

      You can track the result of this operation via the
      [property@Gdk.Toplevel:state] property, or by listening to notifications
      of the [property@Gtk.Window:fullscreened] property. *)

  external fullscreen : t -> unit = "ml_gtk_window_fullscreen"
  (** Asks to place the window in the fullscreen state.

      Note that you shouldn’t assume the window is definitely fullscreen
      afterward, because other entities (e.g. the user or window manager)
      unfullscreen it again, and not all window managers honor requests to
      fullscreen windows.

      If a window is not explicitly fullscreened or unfullscreened before it is
      shown, the initial state is at the window managers discretion.

      You can track the result of this operation via the
      [property@Gdk.Toplevel:state] property, or by listening to notifications
      of the [property@Gtk.Window:fullscreened] property. *)

  external destroy : t -> unit = "ml_gtk_window_destroy"
  (** Drops the internal reference GTK holds on toplevel windows. *)

  external close : t -> unit = "ml_gtk_window_close"
  (** Requests that the window is closed.

      This is similar to what happens when a window manager close button is
      clicked.

      This function can be used with close buttons in custom titlebars. *)

  (* Properties *)

  external get_default_height : t -> int = "ml_gtk_window_get_default_height"
  (** Get property: default-height *)

  external set_default_height : t -> int -> unit
    = "ml_gtk_window_set_default_height"
  (** Set property: default-height *)

  external get_default_width : t -> int = "ml_gtk_window_get_default_width"
  (** Get property: default-width *)

  external set_default_width : t -> int -> unit
    = "ml_gtk_window_set_default_width"
  (** Set property: default-width *)

  val on_activate_default :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_activate_focus :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_close_request :
    ?after:bool -> t -> callback:(unit -> bool) -> Gobject.Signal.handler_id

  val on_enable_debugging :
    ?after:bool ->
    t ->
    callback:(toggle:bool -> bool) ->
    Gobject.Signal.handler_id

  val on_keys_changed :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
end

and Window_group : sig
  type t = [ `window_group | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_window_group_get_type"

  external new_ : unit -> t = "ml_gtk_window_group_new"
  (** Create a new WindowGroup *)

  (* Methods *)

  external remove_window : t -> Window.t -> unit
    = "ml_gtk_window_group_remove_window"
  (** Removes a window from a `GtkWindowGroup`. *)

  external list_windows : t -> Window.t list
    = "ml_gtk_window_group_list_windows"
  (** Returns a list of the `GtkWindows` that belong to @window_group. *)

  external add_window : t -> Window.t -> unit = "ml_gtk_window_group_add_window"
  (** Adds a window to a `GtkWindowGroup`. *)
end
