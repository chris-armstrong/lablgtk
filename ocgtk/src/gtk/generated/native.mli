(* GENERATED CODE - DO NOT EDIT *)
(* Native: Native *)

type t = [ `native ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_native_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gtk_native_from_gobject"

(* Methods *)

external unrealize : t -> unit = "ml_gtk_native_unrealize"
(** Unrealizes a `GtkNative`.

    This should only be used by subclasses. *)

external realize : t -> unit = "ml_gtk_native_realize"
(** Realizes a `GtkNative`.

    This should only be used by subclasses. *)

external get_surface_transform : t -> float * float
  = "ml_gtk_native_get_surface_transform"
(** Retrieves the surface transform of @self.

This is the translation from @self's surface coordinates into
@self's widget coordinates. *)

external get_surface : t -> Ocgtk_gdk.Gdk.Wrappers.Surface.t option
  = "ml_gtk_native_get_surface"
(** Returns the surface of this `GtkNative`. *)

external get_renderer : t -> Ocgtk_gsk.Gsk.Wrappers.Renderer.t option
  = "ml_gtk_native_get_renderer"
(** Returns the renderer that is used for this `GtkNative`. *)
