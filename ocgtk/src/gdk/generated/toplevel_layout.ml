(* GENERATED CODE - DO NOT EDIT *)
(* ToplevelLayout: ToplevelLayout *)

type t = [ `toplevel_layout ] Gobject.obj
(** Contains information that is necessary to present a sovereign window on
    screen.

    The `GdkToplevelLayout` struct is necessary for using
    [method@Gdk.Toplevel.present].

    Toplevel surfaces are sovereign windows that can be presented to the user in
    various states (maximized, on all workspaces, etc). *)

external gtype : unit -> Gobject.Type.t = "ml_gdk_toplevel_layout_get_type"

external new_ : unit -> t = "ml_gdk_toplevel_layout_new"
(** Create a new ToplevelLayout *)

(* Methods *)

external set_resizable : t -> bool -> unit
  = "ml_gdk_toplevel_layout_set_resizable"
(** Sets whether the layout should allow the user to resize the surface after it
    has been presented. *)

external set_maximized : t -> bool -> unit
  = "ml_gdk_toplevel_layout_set_maximized"
(** Sets whether the layout should cause the surface to be maximized when
    presented. *)

external set_fullscreen :
  t -> bool -> App_launch_context_cycle_de440b34.Monitor.t option -> unit
  = "ml_gdk_toplevel_layout_set_fullscreen"
(** Sets whether the layout should cause the surface to be fullscreen when
    presented. *)

external ref : t -> t = "ml_gdk_toplevel_layout_ref"
(** Increases the reference count of @layout. *)

external get_resizable : t -> bool = "ml_gdk_toplevel_layout_get_resizable"
(** Returns whether the layout should allow the user to resize the surface. *)

external get_maximized : t -> bool * bool
  = "ml_gdk_toplevel_layout_get_maximized"
(** If the layout specifies whether to the toplevel should go maximized,
the value pointed to by @maximized is set to true if it should go
maximized, or false, if it should go unmaximized. *)

external get_fullscreen_monitor :
  t -> App_launch_context_cycle_de440b34.Monitor.t option
  = "ml_gdk_toplevel_layout_get_fullscreen_monitor"
(** Returns the monitor that the layout is fullscreening the surface on. *)

external get_fullscreen : t -> bool * bool
  = "ml_gdk_toplevel_layout_get_fullscreen"
(** If the layout specifies whether to the toplevel should go fullscreen,
the value pointed to by @fullscreen is set to true if it should go
fullscreen, or false, if it should go unfullscreen. *)

external equal : t -> t -> bool = "ml_gdk_toplevel_layout_equal"
(** Check whether @layout and @other has identical layout properties. *)
