(* GENERATED CODE - DO NOT EDIT *)
(* FileList: FileList *)

type t = [ `file_list ] Gobject.obj
(** An opaque type representing a list of files. *)

external gtype : unit -> Gobject.Type.t = "ml_gdk_file_list_get_type"

external new_from_array : Ocgtk_gio.Gio.Wrappers.File.t array -> Gsize.t -> t
  = "ml_gdk_file_list_new_from_array"
(** Create a new FileList *)

external new_from_list : Ocgtk_gio.Gio.Wrappers.File.t list -> t
  = "ml_gdk_file_list_new_from_list"
(** Create a new FileList *)

(* Methods *)

external get_files : t -> Ocgtk_gio.Gio.Wrappers.File.t list
  = "ml_gdk_file_list_get_files"
(** Retrieves the list of files inside a `GdkFileList`.

    This function is meant for language bindings. *)
