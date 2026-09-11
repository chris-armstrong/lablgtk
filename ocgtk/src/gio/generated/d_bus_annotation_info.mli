(* GENERATED CODE - DO NOT EDIT *)
(* DBusAnnotationInfo: DBusAnnotationInfo *)

type t = [ `d_bus_annotation_info ] Gobject.obj
(** Information about an annotation. *)

external gtype : unit -> Gobject.Type.t
  = "ml_gio_d_bus_annotation_info_get_type"

(* Methods *)

external ref : t -> t = "ml_g_dbus_annotation_info_ref"
(** If @info is statically allocated does nothing. Otherwise increases
the reference count. *)
