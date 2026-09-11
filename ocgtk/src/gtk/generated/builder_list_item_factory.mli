(* GENERATED CODE - DO NOT EDIT *)
(* BuilderListItemFactory: BuilderListItemFactory *)

type t =
  [ `builder_list_item_factory | `list_item_factory | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gtk_builder_list_item_factory_get_type"

external new_from_bytes : Builder_scope.t option -> Glib_bytes.t -> t
  = "ml_gtk_builder_list_item_factory_new_from_bytes"
(** Create a new BuilderListItemFactory *)

external new_from_resource : Builder_scope.t option -> string -> t
  = "ml_gtk_builder_list_item_factory_new_from_resource"
(** Create a new BuilderListItemFactory *)

(* Methods *)

external get_scope : t -> Builder_scope.t option
  = "ml_gtk_builder_list_item_factory_get_scope"
(** Gets the scope used when constructing listitems. *)

external get_resource : t -> string option
  = "ml_gtk_builder_list_item_factory_get_resource"
(** If the data references a resource, gets the path of that resource. *)

external get_bytes : t -> Glib_bytes.t
  = "ml_gtk_builder_list_item_factory_get_bytes"
(** Gets the data used as the `GtkBuilder` UI template for constructing
    listitems. *)

(* Properties *)
