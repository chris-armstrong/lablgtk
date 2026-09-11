(* GENERATED CODE - DO NOT EDIT *)
(* MountOperation: MountOperation *)

type t = [ `mount_operation | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_mount_operation_get_type"

external new_ : Application_and__window_and__window_group.Window.t option -> t
  = "ml_gtk_mount_operation_new"
(** Create a new MountOperation *)

(* Methods *)

external set_parent :
  t -> Application_and__window_and__window_group.Window.t option -> unit
  = "ml_gtk_mount_operation_set_parent"
(** Sets the transient parent for windows shown by the `GtkMountOperation`. *)

external set_display : t -> Ocgtk_gdk.Gdk.Wrappers.Display.t -> unit
  = "ml_gtk_mount_operation_set_display"
(** Sets the display to show windows of the `GtkMountOperation` on. *)

external is_showing : t -> bool = "ml_gtk_mount_operation_is_showing"
(** Returns whether the `GtkMountOperation` is currently displaying a window. *)

external get_parent :
  t -> Application_and__window_and__window_group.Window.t option
  = "ml_gtk_mount_operation_get_parent"
(** Gets the transient parent used by the `GtkMountOperation`. *)

external get_display : t -> Ocgtk_gdk.Gdk.Wrappers.Display.t
  = "ml_gtk_mount_operation_get_display"
(** Gets the display on which windows of the `GtkMountOperation` will be shown.
*)

(* Properties *)
