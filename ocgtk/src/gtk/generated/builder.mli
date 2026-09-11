(* GENERATED CODE - DO NOT EDIT *)
(* Builder: Builder *)

type t = [ `builder | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_builder_get_type"

external new_ : unit -> t = "ml_gtk_builder_new"
(** Create a new Builder *)

external new_from_file : string -> t = "ml_gtk_builder_new_from_file"
(** Create a new Builder *)

external new_from_resource : string -> t = "ml_gtk_builder_new_from_resource"
(** Create a new Builder *)

external new_from_string : string -> int -> t = "ml_gtk_builder_new_from_string"
(** Create a new Builder *)

(* Methods *)

external value_from_string_type :
  t -> Gobject.Type.t -> string -> (bool * Gobject.Value.t, GError.t) result
  = "ml_gtk_builder_value_from_string_type"
(** Demarshals a value from a string.

Unlike [method@Gtk.Builder.value_from_string], this function
takes a `GType` instead of `GParamSpec`.

Calls g_value_init() on the @value argument, so it
need not be initialised beforehand.

Upon errors %FALSE will be returned and @error will be
assigned a `GError` from the %GTK_BUILDER_ERROR domain. *)

external set_translation_domain : t -> string option -> unit
  = "ml_gtk_builder_set_translation_domain"
(** Sets the translation domain of @builder. *)

external set_scope : t -> Builder_scope.t option -> unit
  = "ml_gtk_builder_set_scope"
(** Sets the scope the builder should operate in.

If @scope is %NULL, a new [class@Gtk.BuilderCScope] will be created. *)

external set_current_object : t -> [ `object_ ] Gobject.obj option -> unit
  = "ml_gtk_builder_set_current_object"
(** Sets the current object for the @builder.

The current object can be thought of as the `this` object that the
builder is working for and will often be used as the default object
when an object is optional.

[method@Gtk.Widget.init_template] for example will set the current
object to the widget the template is inited for. For functions like
[ctor@Gtk.Builder.new_from_resource], the current object will be %NULL. *)

external get_type_from_name : t -> string -> Gobject.Type.t
  = "ml_gtk_builder_get_type_from_name"
(** Looks up a type by name.

    This is using the virtual function that `GtkBuilder` has for that purpose.
    This is mainly used when implementing the `GtkBuildable` interface on a
    type. *)

external get_translation_domain : t -> string option
  = "ml_gtk_builder_get_translation_domain"
(** Gets the translation domain of @builder. *)

external get_scope : t -> Builder_scope.t = "ml_gtk_builder_get_scope"
(** Gets the scope in use that was set via gtk_builder_set_scope(). *)

external get_objects : t -> [ `object_ ] Gobject.obj list
  = "ml_gtk_builder_get_objects"
(** Gets all objects that have been constructed by @builder.

Note that this function does not increment the reference
counts of the returned objects. *)

external get_object : t -> string -> [ `object_ ] Gobject.obj option
  = "ml_gtk_builder_get_object"
(** Gets the object named @name.

Note that this function does not increment the reference count
of the returned object. *)

external get_current_object : t -> [ `object_ ] Gobject.obj option
  = "ml_gtk_builder_get_current_object"
(** Gets the current object set via gtk_builder_set_current_object(). *)

external extend_with_template :
  t ->
  [ `object_ ] Gobject.obj ->
  Gobject.Type.t ->
  string ->
  int ->
  (bool, GError.t) result = "ml_gtk_builder_extend_with_template"
(** Main private entry point for building composite components from template
    XML.

    Most likely you do not need to call this function in applications as
    templates are handled by `GtkWidget`. *)

external expose_object : t -> string -> [ `object_ ] Gobject.obj -> unit
  = "ml_gtk_builder_expose_object"
(** Add @object to the @builder object pool so it can be
referenced just like any other object built by builder.

Only a single object may be added using @name. However,
it is not an error to expose the same object under multiple
names. `gtk_builder_get_object()` may be used to determine
if an object has already been added with @name. *)

external add_objects_from_string :
  t -> string -> int -> string array -> (bool, GError.t) result
  = "ml_gtk_builder_add_objects_from_string"
(** Parses a string containing a UI definition, building only the
requested objects and merges them with the current contents of
@builder.

Upon errors %FALSE will be returned and @error will be assigned a
`GError` from the %GTK_BUILDER_ERROR or %G_MARKUP_ERROR domain.

If you are adding an object that depends on an object that is not
its child (for instance a `GtkTreeView` that depends on its
`GtkTreeModel`), you have to explicitly list all of them in @object_ids. *)

external add_objects_from_resource :
  t -> string -> string array -> (bool, GError.t) result
  = "ml_gtk_builder_add_objects_from_resource"
(** Parses a resource file containing a UI definition, building
only the requested objects and merges them with the current
contents of @builder.

Upon errors, 0 will be returned and @error will be assigned a
`GError` from the %GTK_BUILDER_ERROR, %G_MARKUP_ERROR or %G_RESOURCE_ERROR
domain.

If you are adding an object that depends on an object that is not
its child (for instance a `GtkTreeView` that depends on its
`GtkTreeModel`), you have to explicitly list all of them in @object_ids. *)

external add_objects_from_file :
  t -> string -> string array -> (bool, GError.t) result
  = "ml_gtk_builder_add_objects_from_file"
(** Parses a file containing a UI definition building only the
requested objects and merges them with the current contents
of @builder.

Upon errors, 0 will be returned and @error will be assigned a
`GError` from the %GTK_BUILDER_ERROR, %G_MARKUP_ERROR or %G_FILE_ERROR
domain.

If you are adding an object that depends on an object that is not
its child (for instance a `GtkTreeView` that depends on its
`GtkTreeModel`), you have to explicitly list all of them in @object_ids. *)

external add_from_string : t -> string -> int -> (bool, GError.t) result
  = "ml_gtk_builder_add_from_string"
(** Parses a string containing a UI definition and merges it
with the current contents of @builder.

This function is useful if you need to call
[method@Gtk.Builder.set_current_object] to add user data to
callbacks before loading `GtkBuilder` UI. Otherwise, you probably
want [ctor@Gtk.Builder.new_from_string] instead.

Upon errors %FALSE will be returned and @error will be assigned a
`GError` from the %GTK_BUILDER_ERROR, %G_MARKUP_ERROR or
%G_VARIANT_PARSE_ERROR domain.

It’s not really reasonable to attempt to handle failures of this
call.  The only reasonable thing to do when an error is detected is
to call g_error(). *)

external add_from_resource : t -> string -> (bool, GError.t) result
  = "ml_gtk_builder_add_from_resource"
(** Parses a resource file containing a UI definition
and merges it with the current contents of @builder.

This function is useful if you need to call
[method@Gtk.Builder.set_current_object] to add user data to
callbacks before loading GtkBuilder UI. Otherwise, you probably
want [ctor@Gtk.Builder.new_from_resource] instead.

If an error occurs, 0 will be returned and @error will be assigned a
`GError` from the %GTK_BUILDER_ERROR, %G_MARKUP_ERROR or %G_RESOURCE_ERROR
domain.

It’s not really reasonable to attempt to handle failures of this
call.  The only reasonable thing to do when an error is detected is
to call g_error(). *)

external add_from_file : t -> string -> (bool, GError.t) result
  = "ml_gtk_builder_add_from_file"
(** Parses a file containing a UI definition and merges it with
the current contents of @builder.

This function is useful if you need to call
[method@Gtk.Builder.set_current_object]) to add user data to
callbacks before loading GtkBuilder UI. Otherwise, you probably
want [ctor@Gtk.Builder.new_from_file] instead.

If an error occurs, 0 will be returned and @error will be assigned a
`GError` from the `GTK_BUILDER_ERROR`, `G_MARKUP_ERROR` or `G_FILE_ERROR`
domains.

It’s not really reasonable to attempt to handle failures of this
call. You should not use this function with untrusted files (ie:
files that are not part of your application). Broken `GtkBuilder`
files can easily crash your program, and it’s possible that memory
was leaked leading up to the reported failure. The only reasonable
thing to do when an error is detected is to call `g_error()`. *)

(* Properties *)
