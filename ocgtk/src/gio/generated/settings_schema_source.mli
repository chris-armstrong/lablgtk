(* GENERATED CODE - DO NOT EDIT *)
(* SettingsSchemaSource: SettingsSchemaSource *)

type t = [ `settings_schema_source ] Gobject.obj
(** This is an opaque structure type. You may not access it directly. *)

external gtype : unit -> Gobject.Type.t
  = "ml_gio_settings_schema_source_get_type"

external new_from_directory : string -> t option -> bool -> (t, GError.t) result
  = "ml_g_settings_schema_source_new_from_directory"
(** Create a new SettingsSchemaSource *)

(* Methods *)

external ref : t -> t = "ml_g_settings_schema_source_ref"
(** Increase the reference count of @source, returning a new reference. *)

external lookup : t -> string -> bool -> Settings_schema.t option
  = "ml_g_settings_schema_source_lookup"
(** Looks up a schema with the identifier @schema_id in @source.

This function is not required for normal uses of #GSettings but it
may be useful to authors of plugin management systems or to those who
want to introspect the content of schemas.

If the schema isn't found directly in @source and @recursive is %TRUE
then the parent sources will also be checked.

If the schema isn't found, %NULL is returned. *)
