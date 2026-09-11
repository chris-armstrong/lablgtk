(* GENERATED CODE - DO NOT EDIT *)
(* Toplevel: Toplevel *)

type t = [ `toplevel ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_toplevel_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gdk_toplevel_from_gobject"

(* Methods *)

external titlebar_gesture : t -> Gdk_enums.titlebargesture -> bool
  = "ml_gdk_toplevel_titlebar_gesture"
(** Performs a title bar gesture. *)

external supports_edge_constraints : t -> bool
  = "ml_gdk_toplevel_supports_edge_constraints"
(** Returns whether the desktop environment supports tiled window states. *)

external show_window_menu :
  t -> App_launch_context_cycle_de440b34.Event.t -> bool
  = "ml_gdk_toplevel_show_window_menu"
(** Asks the windowing system to show the window menu.

    The window menu is the menu shown when right-clicking the titlebar on
    traditional windows managed by the window manager. This is useful for
    windows using client-side decorations, activating it with a right-click on
    the window decorations. *)

external set_transient_for :
  t -> App_launch_context_cycle_de440b34.Surface.t -> unit
  = "ml_gdk_toplevel_set_transient_for"
(** Sets a transient-for parent.

Indicates to the window manager that @surface is a transient
dialog associated with the application surface @parent. This
allows the window manager to do things like center @surface
on @parent and keep @surface above @parent.

See [gtk_window_set_transient_for()](../gtk4/method.Window.set_transient_for.html)
if you’re using [GtkWindow](../gtk4/class.Window.html). *)

external set_title : t -> string -> unit = "ml_gdk_toplevel_set_title"
(** Sets the title of a toplevel surface.

    The title maybe be displayed in the titlebar, in lists of windows, etc. *)

external set_startup_id : t -> string -> unit = "ml_gdk_toplevel_set_startup_id"
(** Sets the startup notification ID.

    When using GTK, typically you should use
    [gtk_window_set_startup_id()](../gtk4/method.Window.set_startup_id.html)
    instead of this low-level function. *)

external set_modal : t -> bool -> unit = "ml_gdk_toplevel_set_modal"
(** Sets the toplevel to be modal.

    The application can use this hint to tell the window manager that a certain
    surface has modal behaviour. The window manager can use this information to
    handle modal surfaces in a special way.

    You should only use this on surfaces for which you have previously called
    [method@Gdk.Toplevel.set_transient_for]. *)

external set_icon_list : t -> Texture.t list -> unit
  = "ml_gdk_toplevel_set_icon_list"
(** Sets a list of icons for the surface.

    One of these will be used to represent the surface in iconic form. The icon
    may be shown in window lists or task bars. Which icon size is shown depends
    on the window manager. The window manager can scale the icon but setting
    several size icons can give better image quality.

    Note that some platforms don't support surface icons. *)

external set_gravity : t -> Gdk_enums.gravity -> unit
  = "ml_gdk_toplevel_set_gravity"
(** Sets the gravity that is used when changing the toplevel size
    programmatically. *)

external set_deletable : t -> bool -> unit = "ml_gdk_toplevel_set_deletable"
(** Sets the toplevel to be deletable.

Setting @deletable to %TRUE hints the desktop environment
that it should offer the user a way to close the surface. *)

external set_decorated : t -> bool -> unit = "ml_gdk_toplevel_set_decorated"
(** Sets the toplevel to be decorated.

Setting @decorated to %FALSE hints the desktop environment
that the surface has its own, client-side decorations and
does not need to have window decorations added. *)

external restore_system_shortcuts : t -> unit
  = "ml_gdk_toplevel_restore_system_shortcuts"
(** Restore default system keyboard shortcuts which were previously inhibited.

    This undoes the effect of [method@Gdk.Toplevel.inhibit_system_shortcuts]. *)

external present : t -> Toplevel_layout.t -> unit = "ml_gdk_toplevel_present"
(** Present @toplevel after having processed the `GdkToplevelLayout` rules.

If the toplevel was previously not showing, it will be showed,
otherwise it will change layout according to @layout.

GDK may emit the [signal@Gdk.Toplevel::compute-size] signal to let
the user of this toplevel compute the preferred size of the toplevel
surface.

Presenting is asynchronous and the specified layout parameters are not
guaranteed to be respected. *)

external minimize : t -> bool = "ml_gdk_toplevel_minimize"
(** Asks to minimize the @toplevel.

The windowing system may choose to ignore the request. *)

external lower : t -> bool = "ml_gdk_toplevel_lower"
(** Asks to lower the @toplevel below other windows.

The windowing system may choose to ignore the request. *)

external inhibit_system_shortcuts :
  t -> App_launch_context_cycle_de440b34.Event.t option -> unit
  = "ml_gdk_toplevel_inhibit_system_shortcuts"
(** Requests that the @toplevel inhibit the system shortcuts.

This is asking the desktop environment/windowing system to let all
keyboard events reach the surface, as long as it is focused, instead
of triggering system actions.

If granted, the rerouting remains active until the default shortcuts
processing is restored with [method@Gdk.Toplevel.restore_system_shortcuts],
or the request is revoked by the desktop environment, windowing system
or the user.

A typical use case for this API is remote desktop or virtual machine
viewers which need to inhibit the default system keyboard shortcuts
so that the remote session or virtual host gets those instead of the
local environment.

The windowing system or desktop environment may ask the user to grant
or deny the request or even choose to ignore the request entirely.

The caller can be notified whenever the request is granted or revoked
by listening to the [property@Gdk.Toplevel:shortcuts-inhibited] property. *)

external get_state : t -> Gdk_enums.toplevelstate = "ml_gdk_toplevel_get_state"
(** Gets the bitwise or of the currently active surface state flags, from the
    `GdkToplevelState` enumeration. *)

external get_gravity : t -> Gdk_enums.gravity = "ml_gdk_toplevel_get_gravity"
(** Returns the gravity that is used when changing the toplevel size
    programmatically. *)

external get_capabilities : t -> Gdk_enums.toplevelcapabilities
  = "ml_gdk_toplevel_get_capabilities"
(** The capabilities that are available for this toplevel. *)

external focus : t -> UInt32.t -> unit = "ml_gdk_toplevel_focus"
(** Sets keyboard focus to @surface.

In most cases, [gtk_window_present_with_time()](../gtk4/method.Window.present_with_time.html)
should be used on a [GtkWindow](../gtk4/class.Window.html), rather than
calling this function. *)

external begin_resize :
  t ->
  Gdk_enums.surfaceedge ->
  App_launch_context_cycle_de440b34.Device.t option ->
  int ->
  float ->
  float ->
  UInt32.t ->
  unit
  = "ml_gdk_toplevel_begin_resize_bytecode"
    "ml_gdk_toplevel_begin_resize_native"
(** Begins an interactive resize operation.

    You might use this function to implement a “window resize grip.” *)

external begin_move :
  t ->
  App_launch_context_cycle_de440b34.Device.t ->
  int ->
  float ->
  float ->
  UInt32.t ->
  unit
  = "ml_gdk_toplevel_begin_move_bytecode" "ml_gdk_toplevel_begin_move_native"
(** Begins an interactive move operation.

    You might use this function to implement draggable titlebars. *)

(* Properties *)

external get_fullscreen_mode : t -> Gdk_enums.fullscreenmode
  = "ml_gdk_toplevel_get_fullscreen_mode"
(** Get property: fullscreen-mode *)

external set_fullscreen_mode : t -> Gdk_enums.fullscreenmode -> unit
  = "ml_gdk_toplevel_set_fullscreen_mode"
(** Set property: fullscreen-mode *)

external get_shortcuts_inhibited : t -> bool
  = "ml_gdk_toplevel_get_shortcuts_inhibited"
(** Get property: shortcuts-inhibited *)
