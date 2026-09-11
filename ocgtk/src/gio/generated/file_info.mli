(* GENERATED CODE - DO NOT EDIT *)
(* FileInfo: FileInfo *)

type t = [ `file_info | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_file_info_get_type"

external new_ : unit -> t = "ml_g_file_info_new"
(** Create a new FileInfo *)

(* Methods *)

external unset_attribute_mask : t -> unit
  = "ml_g_file_info_unset_attribute_mask"
(** Unsets a mask set by g_file_info_set_attribute_mask(), if one is set. *)

external set_symlink_target : t -> string -> unit
  = "ml_g_file_info_set_symlink_target"
(** Sets the %G_FILE_ATTRIBUTE_STANDARD_SYMLINK_TARGET attribute in the file
    info to the given symlink target. *)

external set_symbolic_icon : t -> Icon.t -> unit
  = "ml_g_file_info_set_symbolic_icon"
(** Sets the symbolic icon for a given #GFileInfo. See
    %G_FILE_ATTRIBUTE_STANDARD_SYMBOLIC_ICON. *)

external set_sort_order : t -> Int32.t -> unit = "ml_g_file_info_set_sort_order"
(** Sets the sort order attribute in the file info structure. See
    %G_FILE_ATTRIBUTE_STANDARD_SORT_ORDER. *)

external set_size : t -> int64 -> unit = "ml_g_file_info_set_size"
(** Sets the %G_FILE_ATTRIBUTE_STANDARD_SIZE attribute in the file info to the
    given size. *)

external set_name : t -> string -> unit = "ml_g_file_info_set_name"
(** Sets the name attribute for the current #GFileInfo. See
    %G_FILE_ATTRIBUTE_STANDARD_NAME. *)

external set_is_symlink : t -> bool -> unit = "ml_g_file_info_set_is_symlink"
(** Sets the "is_symlink" attribute in a #GFileInfo according to @is_symlink.
See %G_FILE_ATTRIBUTE_STANDARD_IS_SYMLINK. *)

external set_is_hidden : t -> bool -> unit = "ml_g_file_info_set_is_hidden"
(** Sets the "is_hidden" attribute in a #GFileInfo according to @is_hidden.
See %G_FILE_ATTRIBUTE_STANDARD_IS_HIDDEN. *)

external set_icon : t -> Icon.t -> unit = "ml_g_file_info_set_icon"
(** Sets the icon for a given #GFileInfo. See %G_FILE_ATTRIBUTE_STANDARD_ICON.
*)

external set_file_type : t -> Gio_enums.filetype -> unit
  = "ml_g_file_info_set_file_type"
(** Sets the file type in a #GFileInfo to @type.
See %G_FILE_ATTRIBUTE_STANDARD_TYPE. *)

external set_edit_name : t -> string -> unit = "ml_g_file_info_set_edit_name"
(** Sets the edit name for the current file. See
    %G_FILE_ATTRIBUTE_STANDARD_EDIT_NAME. *)

external set_display_name : t -> string -> unit
  = "ml_g_file_info_set_display_name"
(** Sets the display name for the current #GFileInfo. See
    %G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME. *)

external set_content_type : t -> string -> unit
  = "ml_g_file_info_set_content_type"
(** Sets the content type attribute for a given #GFileInfo. See
    %G_FILE_ATTRIBUTE_STANDARD_CONTENT_TYPE. *)

external set_attribute_uint64 : t -> string -> UInt64.t -> unit
  = "ml_g_file_info_set_attribute_uint64"
(** Sets the @attribute to contain the given @attr_value,
if possible. *)

external set_attribute_uint32 : t -> string -> UInt32.t -> unit
  = "ml_g_file_info_set_attribute_uint32"
(** Sets the @attribute to contain the given @attr_value,
if possible. *)

external set_attribute_stringv : t -> string -> string array -> unit
  = "ml_g_file_info_set_attribute_stringv"
(** Sets the @attribute to contain the given @attr_value,
if possible.

Sinze: 2.22 *)

external set_attribute_string : t -> string -> string -> unit
  = "ml_g_file_info_set_attribute_string"
(** Sets the @attribute to contain the given @attr_value,
if possible. *)

external set_attribute_status :
  t -> string -> Gio_enums.fileattributestatus -> bool
  = "ml_g_file_info_set_attribute_status"
(** Sets the attribute status for an attribute key. This is only
needed by external code that implement g_file_set_attributes_from_info()
or similar functions.

The attribute must exist in @info for this to work. Otherwise %FALSE
is returned and @info is unchanged. *)

external set_attribute_object : t -> string -> [ `object_ ] Gobject.obj -> unit
  = "ml_g_file_info_set_attribute_object"
(** Sets the @attribute to contain the given @attr_value,
if possible. *)

external set_attribute_mask : t -> File_attribute_matcher.t -> unit
  = "ml_g_file_info_set_attribute_mask"
(** Sets @mask on @info to match specific attribute types. *)

external set_attribute_int64 : t -> string -> int64 -> unit
  = "ml_g_file_info_set_attribute_int64"
(** Sets the @attribute to contain the given @attr_value,
if possible. *)

external set_attribute_int32 : t -> string -> Int32.t -> unit
  = "ml_g_file_info_set_attribute_int32"
(** Sets the @attribute to contain the given @attr_value,
if possible. *)

external set_attribute_file_path : t -> string -> string -> unit
  = "ml_g_file_info_set_attribute_file_path"
(** Sets the @attribute to contain the given @attr_value,
if possible.

This function is meant to be used by language bindings that have specific
handling for Unix paths. *)

external set_attribute_byte_string : t -> string -> string -> unit
  = "ml_g_file_info_set_attribute_byte_string"
(** Sets the @attribute to contain the given @attr_value,
if possible. *)

external set_attribute_boolean : t -> string -> bool -> unit
  = "ml_g_file_info_set_attribute_boolean"
(** Sets the @attribute to contain the given @attr_value,
if possible. *)

external remove_attribute : t -> string -> unit
  = "ml_g_file_info_remove_attribute"
(** Removes all cases of @attribute from @info if it exists. *)

external list_attributes : t -> string option -> string array option
  = "ml_g_file_info_list_attributes"
(** Lists the file info structure's attributes. *)

external has_namespace : t -> string -> bool = "ml_g_file_info_has_namespace"
(** Checks if a file info structure has an attribute in the
specified @name_space. *)

external has_attribute : t -> string -> bool = "ml_g_file_info_has_attribute"
(** Checks if a file info structure has an attribute named @attribute. *)

external get_symlink_target : t -> string option
  = "ml_g_file_info_get_symlink_target"
(** Gets the symlink target for a given #GFileInfo.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_SYMLINK_TARGET. *)

external get_symbolic_icon : t -> Icon.t option
  = "ml_g_file_info_get_symbolic_icon"
(** Gets the symbolic icon for a file.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_SYMBOLIC_ICON. *)

external get_sort_order : t -> Int32.t = "ml_g_file_info_get_sort_order"
(** Gets the value of the sort_order attribute from the #GFileInfo. See
    %G_FILE_ATTRIBUTE_STANDARD_SORT_ORDER.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_SORT_ORDER. *)

external get_size : t -> int64 = "ml_g_file_info_get_size"
(** Gets the file's size (in bytes). The size is retrieved through the value of
    the %G_FILE_ATTRIBUTE_STANDARD_SIZE attribute and is converted from #guint64
    to #goffset before returning the result.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_SIZE. *)

external get_name : t -> string = "ml_g_file_info_get_name"
(** Gets the name for a file. This is guaranteed to always be set.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_NAME. *)

external get_is_symlink : t -> bool = "ml_g_file_info_get_is_symlink"
(** Checks if a file is a symlink.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_IS_SYMLINK. *)

external get_is_hidden : t -> bool = "ml_g_file_info_get_is_hidden"
(** Checks if a file is hidden.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_IS_HIDDEN. *)

external get_is_backup : t -> bool = "ml_g_file_info_get_is_backup"
(** Checks if a file is a backup file.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_IS_BACKUP. *)

external get_icon : t -> Icon.t option = "ml_g_file_info_get_icon"
(** Gets the icon for a file.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_ICON. *)

external get_file_type : t -> Gio_enums.filetype
  = "ml_g_file_info_get_file_type"
(** Gets a file's type (whether it is a regular file, symlink, etc). This is
    different from the file's content type, see g_file_info_get_content_type().

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_TYPE. *)

external get_etag : t -> string option = "ml_g_file_info_get_etag"
(** Gets the [entity tag][iface@Gio.File#entity-tags] for a given #GFileInfo.
    See %G_FILE_ATTRIBUTE_ETAG_VALUE.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_ETAG_VALUE. *)

external get_edit_name : t -> string = "ml_g_file_info_get_edit_name"
(** Gets the edit name for a file.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_EDIT_NAME. *)

external get_display_name : t -> string = "ml_g_file_info_get_display_name"
(** Gets a display name for a file. This is guaranteed to always be set.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME. *)

external get_content_type : t -> string option
  = "ml_g_file_info_get_content_type"
(** Gets the file's content type.

    It is an error to call this if the #GFileInfo does not contain
    %G_FILE_ATTRIBUTE_STANDARD_CONTENT_TYPE. *)

external get_attribute_uint64 : t -> string -> UInt64.t
  = "ml_g_file_info_get_attribute_uint64"
(** Gets a unsigned 64-bit integer contained within the attribute. If the
    attribute does not contain an unsigned 64-bit integer, or is invalid, 0 will
    be returned. *)

external get_attribute_uint32 : t -> string -> UInt32.t
  = "ml_g_file_info_get_attribute_uint32"
(** Gets an unsigned 32-bit integer contained within the attribute. If the
    attribute does not contain an unsigned 32-bit integer, or is invalid, 0 will
    be returned. *)

external get_attribute_type : t -> string -> Gio_enums.fileattributetype
  = "ml_g_file_info_get_attribute_type"
(** Gets the attribute type for an attribute key. *)

external get_attribute_stringv : t -> string -> string array option
  = "ml_g_file_info_get_attribute_stringv"
(** Gets the value of a stringv attribute. If the attribute does not contain a
    stringv, %NULL will be returned. *)

external get_attribute_string : t -> string -> string option
  = "ml_g_file_info_get_attribute_string"
(** Gets the value of a string attribute. If the attribute does not contain a
    string, %NULL will be returned. *)

external get_attribute_status : t -> string -> Gio_enums.fileattributestatus
  = "ml_g_file_info_get_attribute_status"
(** Gets the attribute status for an attribute key. *)

external get_attribute_object : t -> string -> [ `object_ ] Gobject.obj option
  = "ml_g_file_info_get_attribute_object"
(** Gets the value of a #GObject attribute. If the attribute does not contain a
    #GObject, %NULL will be returned. *)

external get_attribute_int64 : t -> string -> int64
  = "ml_g_file_info_get_attribute_int64"
(** Gets a signed 64-bit integer contained within the attribute. If the
    attribute does not contain a signed 64-bit integer, or is invalid, 0 will be
    returned. *)

external get_attribute_int32 : t -> string -> Int32.t
  = "ml_g_file_info_get_attribute_int32"
(** Gets a signed 32-bit integer contained within the attribute. If the
    attribute does not contain a signed 32-bit integer, or is invalid, 0 will be
    returned. *)

external get_attribute_file_path : t -> string -> string option
  = "ml_g_file_info_get_attribute_file_path"
(** Gets the value of a byte string attribute as a file path.

    If the attribute does not contain a byte string, `NULL` will be returned.

    This function is meant to be used by language bindings that have specific
    handling for Unix paths. *)

external get_attribute_byte_string : t -> string -> string option
  = "ml_g_file_info_get_attribute_byte_string"
(** Gets the value of a byte string attribute. If the attribute does not contain
    a byte string, %NULL will be returned. *)

external get_attribute_boolean : t -> string -> bool
  = "ml_g_file_info_get_attribute_boolean"
(** Gets the value of a boolean attribute. If the attribute does not contain a
    boolean value, %FALSE will be returned. *)

external get_attribute_as_string : t -> string -> string option
  = "ml_g_file_info_get_attribute_as_string"
(** Gets the value of an attribute, formatted as a human readable string.

    This escapes things as needed to make the string valid UTF-8 and readable by
    humans. It’s not meant to be a machine readable or reversible escaping
    format.

    To format file name attributes of type
    [enum@Gio.FileAttributeType.BYTE_STRING] for output as UTF-8, use
    [func@GLib.filename_to_utf8] instead: ```c const char
    *trash_orig_path_byte_string; g_autofree char *trash_orig_path_utf8 = NULL;

    trash_orig_path_byte_string = g_file_info_get_attribute_byte_string (info,
    G_FILE_ATTRIBUTE_TRASH_ORIG_PATH); trash_orig_path_utf8 = g_filename_to_utf8
    (trash_orig_path_byte_string, -1, NULL, NULL, NULL); if
    (trash_orig_path_utf8 != NULL) g_message ("Some larger UTF-8 string with
    filename embedded as %s", trash_orig_path_utf8); ``` *)

external dup : t -> t = "ml_g_file_info_dup"
(** Duplicates a file info structure. *)

external copy_into : t -> t -> unit = "ml_g_file_info_copy_into"
(** First clears all of the [GFileAttribute](file-attributes.html#file-attributes) of
@dest_info, and then copies all of the file attributes from @src_info to @dest_info. *)

external clear_status : t -> unit = "ml_g_file_info_clear_status"
(** Clears the status information from @info. *)
