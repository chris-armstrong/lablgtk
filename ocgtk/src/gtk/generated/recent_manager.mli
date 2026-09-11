(* GENERATED CODE - DO NOT EDIT *)
(* RecentManager: RecentManager *)

type t = [ `recent_manager | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_recent_manager_get_type"

external new_ : unit -> t = "ml_gtk_recent_manager_new"
(** Create a new RecentManager *)

(* Methods *)

external remove_item : t -> string -> (bool, GError.t) result
  = "ml_gtk_recent_manager_remove_item"
(** Removes a resource pointed by @uri from the recently used resources
list handled by a recent manager. *)

external purge_items : t -> (int, GError.t) result
  = "ml_gtk_recent_manager_purge_items"
(** Purges every item from the recently used resources list. *)

external move_item : t -> string -> string option -> (bool, GError.t) result
  = "ml_gtk_recent_manager_move_item"
(** Changes the location of a recently used resource from @uri to @new_uri.

Please note that this function will not affect the resource pointed
by the URIs, but only the URI used in the recently used resources list. *)

external lookup_item : t -> string -> (Recent_info.t option, GError.t) result
  = "ml_gtk_recent_manager_lookup_item"
(** Searches for a URI inside the recently used resources list, and returns a
    `GtkRecentInfo` containing information about the resource like its MIME
    type, or its display name. *)

external has_item : t -> string -> bool = "ml_gtk_recent_manager_has_item"
(** Checks whether there is a recently used resource registered
with @uri inside the recent manager. *)

external get_items : t -> Recent_info.t list = "ml_gtk_recent_manager_get_items"
(** Gets the list of recently used resources. *)

external add_item : t -> string -> bool = "ml_gtk_recent_manager_add_item"
(** Adds a new resource, pointed by @uri, into the recently used
resources list.

This function automatically retrieves some of the needed
metadata and setting other metadata to common default values;
it then feeds the data to [method@Gtk.RecentManager.add_full].

See [method@Gtk.RecentManager.add_full] if you want to explicitly
define the metadata for the resource pointed by @uri. *)

external add_full : t -> string -> Recent_data.t -> bool
  = "ml_gtk_recent_manager_add_full"
(** Adds a new resource, pointed by @uri, into the recently used
resources list, using the metadata specified inside the
`GtkRecentData` passed in @recent_data.

The passed URI will be used to identify this resource inside the
list.

In order to register the new recently used resource, metadata about
the resource must be passed as well as the URI; the metadata is
stored in a `GtkRecentData`, which must contain the MIME
type of the resource pointed by the URI; the name of the application
that is registering the item, and a command line to be used when
launching the item.

Optionally, a `GtkRecentData` might contain a UTF-8 string
to be used when viewing the item instead of the last component of
the URI; a short description of the item; whether the item should
be considered private - that is, should be displayed only by the
applications that have registered it. *)

(* Properties *)

external get_filename : t -> string = "ml_gtk_recent_manager_get_filename"
(** Get property: filename *)

external get_size : t -> int = "ml_gtk_recent_manager_get_size"
(** Get property: size *)

val on_changed :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
