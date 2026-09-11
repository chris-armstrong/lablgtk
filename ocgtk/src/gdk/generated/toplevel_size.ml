(* GENERATED CODE - DO NOT EDIT *)
(* ToplevelSize: ToplevelSize *)

type t = [ `toplevel_size ] Gobject.obj
(** Contains information that is useful to compute the size of a toplevel. *)

external gtype : unit -> Gobject.Type.t = "ml_gdk_toplevel_size_get_type"

(* Methods *)

external set_size : t -> int -> int -> unit = "ml_gdk_toplevel_size_set_size"
(** Sets the size the toplevel prefers to be resized to.

    The size should be within the bounds (see
    [method@Gdk.ToplevelSize.get_bounds]). The set size should be considered as
    a hint, and should not be assumed to be respected by the windowing system,
    or backend. *)

external set_shadow_width : t -> int -> int -> int -> int -> unit
  = "ml_gdk_toplevel_size_set_shadow_width"
(** Sets the shadows size of the toplevel.

    The shadow width corresponds to the part of the computed surface size that
    would consist of the shadow margin surrounding the window, would there be
    any.

    Shadow width should only be set if
    [method@Gtk.Display.supports_shadow_width] is %TRUE. *)

external set_min_size : t -> int -> int -> unit
  = "ml_gdk_toplevel_size_set_min_size"
(** Sets the minimum size of the toplevel.

    The minimum size corresponds to the limitations the toplevel can be shrunk
    to, without resulting in incorrect painting. A user of a `GdkToplevel`
    should calculate these given both the existing size, and the bounds
    retrieved from the `GdkToplevelSize` object.

    The minimum size should be within the bounds (see
    [method@Gdk.ToplevelSize.get_bounds]). *)

external get_bounds : t -> int * int = "ml_gdk_toplevel_size_get_bounds"
(** Retrieves the bounds the toplevel is placed within.

    The bounds represent the largest size a toplevel may have while still being
    able to fit within some type of boundary. Depending on the backend, this may
    be equivalent to the dimensions of the work area or the monitor on which the
    window is being presented on, or something else that limits the way a
    toplevel can be presented. *)
