(* GENERATED CODE - DO NOT EDIT *)
(* Icon: Icon *)

type t = [ `icon ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_icon_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gio_icon_from_gobject"

(* Methods *)

external to_string : t -> string option = "ml_g_icon_to_string"
(** Generates a textual representation of @icon that can be used for
serialization such as when passing @icon to a different process or
saving it to persistent storage. Use g_icon_new_for_string() to
get @icon back from the returned string.

The encoding of the returned string is proprietary to #GIcon except
in the following two cases

- If @icon is a #GFileIcon, the returned string is a native path
  (such as `/path/to/my icon.png`) without escaping
  if the #GFile for @icon is a native file.  If the file is not
  native, the returned string is the result of g_file_get_uri()
  (such as `sftp://path/to/my%20icon.png`).

- If @icon is a #GThemedIcon with exactly one name and no fallbacks,
  the encoding is simply the name (such as `network-server`). *)

external serialize : t -> Gvariant.t option = "ml_g_icon_serialize"
(** Serializes a #GIcon into a #GVariant. An equivalent #GIcon can be retrieved
    back by calling g_icon_deserialize() on the returned value. As serialization
    will avoid using raw icon data when possible, it only makes sense to
    transfer the #GVariant between processes on the same machine, (as opposed to
    over the network), and within the same file system namespace. *)

external hash : t -> int = "ml_g_icon_hash"
(** Gets a hash for an icon. *)

external equal : t -> t option -> bool = "ml_g_icon_equal"
(** Checks if two icons are equal. *)
