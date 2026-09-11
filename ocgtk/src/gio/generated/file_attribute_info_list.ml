(* GENERATED CODE - DO NOT EDIT *)
(* FileAttributeInfoList: FileAttributeInfoList *)

type t = [ `file_attribute_info_list ] Gobject.obj
(** Acts as a lightweight registry for possible valid file attributes. The
    registry stores Key-Value pair formats as #GFileAttributeInfos. *)

external gtype : unit -> Gobject.Type.t
  = "ml_gio_file_attribute_info_list_get_type"

external new_ : unit -> t = "ml_g_file_attribute_info_list_new"
(** Create a new FileAttributeInfoList *)

(* Methods *)

external ref : t -> t = "ml_g_file_attribute_info_list_ref"
(** References a file attribute info list. *)

external lookup : t -> string -> File_attribute_info.t
  = "ml_g_file_attribute_info_list_lookup"
(** Gets the file attribute with the name @name from @list. *)

external dup : t -> t = "ml_g_file_attribute_info_list_dup"
(** Makes a duplicate of a file attribute info list. *)

external add :
  t ->
  string ->
  Gio_enums.fileattributetype ->
  Gio_enums.fileattributeinfoflags ->
  unit = "ml_g_file_attribute_info_list_add"
(** Adds a new attribute with @name to the @list, setting
its @type and @flags. *)
