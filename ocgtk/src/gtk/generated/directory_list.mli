(* GENERATED CODE - DO NOT EDIT *)
(* DirectoryList: DirectoryList *)

type t = [ `directory_list | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_directory_list_get_type"

external new_ : string option -> Ocgtk_gio.Gio.Wrappers.File.t option -> t
  = "ml_gtk_directory_list_new"
(** Create a new DirectoryList *)

(* Methods *)

external set_monitored : t -> bool -> unit
  = "ml_gtk_directory_list_set_monitored"
(** Sets whether the directory list will monitor the directory for changes.

    If monitoring is enabled, the ::items-changed signal will be emitted when
    the directory contents change.

    When monitoring is turned on after the initial creation of the directory
    list, the directory is reloaded to avoid missing files that appeared between
    the initial loading and when monitoring was turned on. *)

external set_io_priority : t -> int -> unit
  = "ml_gtk_directory_list_set_io_priority"
(** Sets the IO priority to use while loading directories.

Setting the priority while @self is loading will reprioritize the
ongoing load as soon as possible.

The default IO priority is %G_PRIORITY_DEFAULT, which is higher than
the GTK redraw priority. If you are loading a lot of directories in
parallel, lowering it to something like %G_PRIORITY_DEFAULT_IDLE
may increase responsiveness. *)

external set_file : t -> Ocgtk_gio.Gio.Wrappers.File.t option -> unit
  = "ml_gtk_directory_list_set_file"
(** Sets the @file to be enumerated and starts the enumeration.

If @file is %NULL, the result will be an empty list. *)

external set_attributes : t -> string option -> unit
  = "ml_gtk_directory_list_set_attributes"
(** Sets the @attributes to be enumerated and starts the enumeration.

If @attributes is %NULL, the list of file infos will still be created, it will just
not contain any extra attributes. *)

external is_loading : t -> bool = "ml_gtk_directory_list_is_loading"
(** Returns %TRUE if the children enumeration is currently in
progress.

Files will be added to @self from time to time while loading is
going on. The order in which are added is undefined and may change
in between runs. *)

external get_monitored : t -> bool = "ml_gtk_directory_list_get_monitored"
(** Returns whether the directory list is monitoring the directory for changes.
*)

external get_io_priority : t -> int = "ml_gtk_directory_list_get_io_priority"
(** Gets the IO priority set via gtk_directory_list_set_io_priority(). *)

external get_file : t -> Ocgtk_gio.Gio.Wrappers.File.t option
  = "ml_gtk_directory_list_get_file"
(** Gets the file whose children are currently enumerated. *)

external get_error : t -> GError.t option = "ml_gtk_directory_list_get_error"
(** Gets the loading error, if any.

    If an error occurs during the loading process, the loading process will
    finish and this property allows querying the error that happened. This error
    will persist until a file is loaded again.

    An error being set does not mean that no files were loaded, and all
    successfully queried files will remain in the list. *)

external get_attributes : t -> string option
  = "ml_gtk_directory_list_get_attributes"
(** Gets the attributes queried on the children. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_directory_list_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_directory_list_get_n_items"
(** Get property: n-items *)
