(* GENERATED CODE - DO NOT EDIT *)
(* BookmarkList: BookmarkList *)

type t = [ `bookmark_list | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_bookmark_list_get_type"

external new_ : string option -> string option -> t = "ml_gtk_bookmark_list_new"
(** Create a new BookmarkList *)

(* Methods *)

external set_io_priority : t -> int -> unit
  = "ml_gtk_bookmark_list_set_io_priority"
(** Sets the IO priority to use while loading files.

    The default IO priority is %G_PRIORITY_DEFAULT. *)

external set_attributes : t -> string option -> unit
  = "ml_gtk_bookmark_list_set_attributes"
(** Sets the @attributes to be enumerated and starts the enumeration.

If @attributes is %NULL, no attributes will be queried, but a list
of `GFileInfo`s will still be created. *)

external is_loading : t -> bool = "ml_gtk_bookmark_list_is_loading"
(** Returns %TRUE if the files are currently being loaded.

Files will be added to @self from time to time while loading is
going on. The order in which are added is undefined and may change
in between runs. *)

external get_io_priority : t -> int = "ml_gtk_bookmark_list_get_io_priority"
(** Gets the IO priority to use while loading file. *)

external get_filename : t -> string = "ml_gtk_bookmark_list_get_filename"
(** Returns the filename of the bookmark file that this list is loading. *)

external get_attributes : t -> string option
  = "ml_gtk_bookmark_list_get_attributes"
(** Gets the attributes queried on the children. *)

(* Properties *)

external get_item_type : t -> Gobject.Type.t
  = "ml_gtk_bookmark_list_get_item_type"
(** Get property: item-type *)

external get_n_items : t -> int = "ml_gtk_bookmark_list_get_n_items"
(** Get property: n-items *)
