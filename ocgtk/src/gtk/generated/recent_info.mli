(* GENERATED CODE - DO NOT EDIT *)
(* RecentInfo: RecentInfo *)

type t = [ `recent_info ] Gobject.obj
(** Contains the metadata associated with an item in the recently used files
    list. *)

external gtype : unit -> Gobject.Type.t = "ml_gtk_recent_info_get_type"

(* Methods *)

external ref : t -> t = "ml_gtk_recent_info_ref"
(** Increases the reference count of @recent_info by one. *)

external match_ : t -> t -> bool = "ml_gtk_recent_info_match"
(** Checks whether two `GtkRecentInfo` point to the same resource. *)

external last_application : t -> string = "ml_gtk_recent_info_last_application"
(** Gets the name of the last application that have registered the
recently used resource represented by @info. *)

external is_local : t -> bool = "ml_gtk_recent_info_is_local"
(** Checks whether the resource is local or not by looking at the scheme of its
    URI. *)

external has_group : t -> string -> bool = "ml_gtk_recent_info_has_group"
(** Checks whether @group_name appears inside the groups
registered for the recently used item @info. *)

external has_application : t -> string -> bool
  = "ml_gtk_recent_info_has_application"
(** Checks whether an application registered this resource using @app_name. *)

external get_uri_display : t -> string option
  = "ml_gtk_recent_info_get_uri_display"
(** Gets a displayable version of the resource’s URI.

    If the resource is local, it returns a local path; if the resource is not
    local, it returns the UTF-8 encoded content of
    [method@Gtk.RecentInfo.get_uri]. *)

external get_uri : t -> string = "ml_gtk_recent_info_get_uri"
(** Gets the URI of the resource. *)

external get_short_name : t -> string = "ml_gtk_recent_info_get_short_name"
(** Computes a valid UTF-8 string that can be used as the name of the item in a
    menu or list.

    For example, calling this function on an item that refers to
    “file:///foo/bar.txt” will yield “bar.txt”. *)

external get_private_hint : t -> bool = "ml_gtk_recent_info_get_private_hint"
(** Gets the value of the “private” flag.

    Resources in the recently used list that have this flag set to %TRUE should
    only be displayed by the applications that have registered them. *)

external get_mime_type : t -> string = "ml_gtk_recent_info_get_mime_type"
(** Gets the MIME type of the resource. *)

external get_groups : t -> string array * Gsize.t
  = "ml_gtk_recent_info_get_groups"
(** Returns all groups registered for the recently used item @info.

The array of returned group names will be %NULL terminated, so
length might optionally be %NULL. *)

external get_gicon : t -> Ocgtk_gio.Gio.Wrappers.Icon.t option
  = "ml_gtk_recent_info_get_gicon"
(** Retrieves the icon associated to the resource MIME type. *)

external get_display_name : t -> string = "ml_gtk_recent_info_get_display_name"
(** Gets the name of the resource.

    If none has been defined, the basename of the resource is obtained. *)

external get_description : t -> string = "ml_gtk_recent_info_get_description"
(** Gets the (short) description of the resource. *)

external get_applications : t -> string array * Gsize.t
  = "ml_gtk_recent_info_get_applications"
(** Retrieves the list of applications that have registered this resource. *)

external get_age : t -> int = "ml_gtk_recent_info_get_age"
(** Gets the number of days elapsed since the last update
of the resource pointed by @info. *)

external exists : t -> bool = "ml_gtk_recent_info_exists"
(** Checks whether the resource pointed by @info still exists.
At the moment this check is done only on resources pointing
to local files. *)

external create_app_info :
  t ->
  string option ->
  (Ocgtk_gio.Gio.Wrappers.App_info.t option, GError.t) result
  = "ml_gtk_recent_info_create_app_info"
(** Creates a `GAppInfo` for the specified `GtkRecentInfo`

In case of error, @error will be set either with a
%GTK_RECENT_MANAGER_ERROR or a %G_IO_ERROR *)
