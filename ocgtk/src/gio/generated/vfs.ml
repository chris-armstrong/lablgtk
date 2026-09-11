(* GENERATED CODE - DO NOT EDIT *)
(* Vfs: Vfs *)

type t = [ `vfs | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_vfs_get_type"

(* Methods *)

external unregister_uri_scheme : t -> string -> bool
  = "ml_g_vfs_unregister_uri_scheme"
(** Unregisters the URI handler for @scheme previously registered with
g_vfs_register_uri_scheme(). *)

external parse_name : t -> string -> App_info_cycle_64c425a0.File.t
  = "ml_g_vfs_parse_name"
(** This operation never fails, but the returned object might
not support any I/O operations if the @parse_name cannot
be parsed by the #GVfs module. *)

external is_active : t -> bool = "ml_g_vfs_is_active"
(** Checks if the VFS is active. *)

external get_supported_uri_schemes : t -> string array
  = "ml_g_vfs_get_supported_uri_schemes"
(** Gets a list of URI schemes supported by @vfs. *)

external get_file_for_uri : t -> string -> App_info_cycle_64c425a0.File.t
  = "ml_g_vfs_get_file_for_uri"
(** Gets a #GFile for @uri.

This operation never fails, but the returned object
might not support any I/O operation if the URI
is malformed or if the URI scheme is not supported. *)

external get_file_for_path : t -> string -> App_info_cycle_64c425a0.File.t
  = "ml_g_vfs_get_file_for_path"
(** Gets a #GFile for @path. *)
