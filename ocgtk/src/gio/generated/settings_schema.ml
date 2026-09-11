(* GENERATED CODE - DO NOT EDIT *)
(* SettingsSchema: SettingsSchema *)

type t = [ `settings_schema ] Gobject.obj
(** The [struct@Gio.SettingsSchemaSource] and `GSettingsSchema` APIs provide a
mechanism for advanced control over the loading of schemas and a
mechanism for introspecting their content.

Plugin loading systems that wish to provide plugins a way to access
settings face the problem of how to make the schemas for these
settings visible to GSettings.  Typically, a plugin will want to ship
the schema along with itself and it won't be installed into the
standard system directories for schemas.

[struct@Gio.SettingsSchemaSource] provides a mechanism for dealing with this
by allowing the creation of a new ‘schema source’ from which schemas can
be acquired.  This schema source can then become part of the metadata
associated with the plugin and queried whenever the plugin requires
access to some settings.

Consider the following example:

```c
typedef struct
{
   …
   GSettingsSchemaSource *schema_source;
   …
} Plugin;

Plugin *
initialise_plugin (const gchar *dir)
{
  Plugin *plugin;

  …

  plugin->schema_source =
    g_settings_schema_source_new_from_directory (dir,
      g_settings_schema_source_get_default (), FALSE, NULL);

  …

  return plugin;
}

…

GSettings *
plugin_get_settings (Plugin      *plugin,
                     const gchar *schema_id)
{
  GSettingsSchema *schema;

  if (schema_id == NULL)
    schema_id = plugin->identifier;

  schema = g_settings_schema_source_lookup (plugin->schema_source,
                                            schema_id, FALSE);

  if (schema == NULL)
    {
      … disable the plugin or abort, etc …
    }

  return g_settings_new_full (schema, NULL, NULL);
}
```

The code above shows how hooks should be added to the code that
initialises (or enables) the plugin to create the schema source and
how an API can be added to the plugin system to provide a convenient
way for the plugin to access its settings, using the schemas that it
ships.

From the standpoint of the plugin, it would need to ensure that it
ships a gschemas.compiled file as part of itself, and then simply do
the following:

```c
{
  GSettings *settings;
  gint some_value;

  settings = plugin_get_settings (self, NULL);
  some_value = g_settings_get_int (settings, "some-value");
  …
}
```

It's also possible that the plugin system expects the schema source
files (ie: `.gschema.xml` files) instead of a `gschemas.compiled` file.
In that case, the plugin loading system must compile the schemas for
itself before attempting to create the settings source. *)

external gtype : unit -> Gobject.Type.t = "ml_gio_settings_schema_get_type"

(* Methods *)

external ref : t -> t = "ml_g_settings_schema_ref"
(** Increase the reference count of @schema, returning a new reference. *)

external list_keys : t -> string array = "ml_g_settings_schema_list_keys"
(** Introspects the list of keys on @schema.

You should probably not be calling this function from "normal" code
(since you should already know what keys are in your schema).  This
function is intended for introspection reasons. *)

external list_children : t -> string array
  = "ml_g_settings_schema_list_children"
(** Gets the list of children in @schema.

You should free the return value with g_strfreev() when you are done
with it. *)

external has_key : t -> string -> bool = "ml_g_settings_schema_has_key"
(** Checks if @schema has a key named @name. *)

external get_path : t -> string option = "ml_g_settings_schema_get_path"
(** Gets the path associated with @schema, or %NULL.

Schemas may be single-instance or relocatable.  Single-instance
schemas correspond to exactly one set of keys in the backend
database: those located at the path returned by this function.

Relocatable schemas can be referenced by other schemas and can
therefore describe multiple sets of keys at different locations.  For
relocatable schemas, this function will return %NULL. *)

external get_key : t -> string -> Settings_schema_key.t
  = "ml_g_settings_schema_get_key"
(** Gets the key named @name from @schema.

It is a programmer error to request a key that does not exist.  See
g_settings_schema_list_keys(). *)

external get_id : t -> string = "ml_g_settings_schema_get_id"
(** Get the ID of @schema. *)
