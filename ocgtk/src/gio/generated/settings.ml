(* GENERATED CODE - DO NOT EDIT *)
(* Settings: Settings *)

type t = [ `settings | `object_ ] Gobject.obj

external new_ : string -> t = "ml_g_settings_new"
(** Create a new Settings *)

external new_with_path : string -> string -> t = "ml_g_settings_new_with_path"
(** Create a new Settings *)

(* Methods *)

external set_value : t -> string -> Gvariant.t -> bool
  = "ml_g_settings_set_value"
(** Sets @key in @settings to @value.

It is a programmer error to give a @key that isn’t contained in the
schema for @settings or for @value to have the incorrect type, per
the schema.

If @value is floating then this function consumes the reference. *)

external set_uint64 : t -> string -> UInt64.t -> bool
  = "ml_g_settings_set_uint64"
(** Sets @key in @settings to @value.

A convenience variant of [method@Gio.Settings.set] for 64-bit unsigned
integers.

It is a programmer error to give a @key that isn’t specified as
having a `t` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external set_uint : t -> string -> int -> bool = "ml_g_settings_set_uint"
(** Sets @key in @settings to @value.

A convenience variant of [method@Gio.Settings.set] for 32-bit unsigned
integers.

It is a programmer error to give a @key that isn’t specified as
having a `u` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external set_strv : t -> string -> string array option -> bool
  = "ml_g_settings_set_strv"
(** Sets @key in @settings to @value.

A convenience variant of [method@Gio.Settings.set] for string arrays.  If
@value is `NULL`, then @key is set to be the empty array.

It is a programmer error to give a @key that isn’t specified as
having an `as` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external set_string : t -> string -> string -> bool = "ml_g_settings_set_string"
(** Sets @key in @settings to @value.

A convenience variant of [method@Gio.Settings.set] for strings.

It is a programmer error to give a @key that isn’t specified as
having an `s` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external set_int64 : t -> string -> int64 -> bool = "ml_g_settings_set_int64"
(** Sets @key in @settings to @value.

A convenience variant of [method@Gio.Settings.set] for 64-bit integers.

It is a programmer error to give a @key that isn’t specified as
having an `x` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external set_int : t -> string -> int -> bool = "ml_g_settings_set_int"
(** Sets @key in @settings to @value.

A convenience variant of [method@Gio.Settings.set] for 32-bit integers.

It is a programmer error to give a @key that isn’t specified as
having an `i` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external set_flags : t -> string -> int -> bool = "ml_g_settings_set_flags"
(** Looks up the flags type nicks for the bits specified by @value, puts
them in an array of strings and writes the array to @key, within
@settings.

It is a programmer error to give a @key that isn’t contained in the
schema for @settings or is not marked as a flags type, or for @value
to contain any bits that are not value for the named type.

After performing the write, accessing @key directly with
[method@Gio.Settings.get_strv] will return an array of ‘nicks’; one for each
bit in @value. *)

external set_enum : t -> string -> int -> bool = "ml_g_settings_set_enum"
(** Looks up the enumerated type nick for @value and writes it to @key,
within @settings.

It is a programmer error to give a @key that isn’t contained in the
schema for @settings or is not marked as an enumerated type, or for
@value not to be a valid value for the named type.

After performing the write, accessing @key directly with
[method@Gio.Settings.get_string] will return the ‘nick’ associated with
@value. *)

external set_double : t -> string -> float -> bool = "ml_g_settings_set_double"
(** Sets @key in @settings to @value.

A convenience variant of [method@Gio.Settings.set] for doubles.

It is a programmer error to give a @key that isn’t specified as
having a `d` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external set_boolean : t -> string -> bool -> bool = "ml_g_settings_set_boolean"
(** Sets @key in @settings to @value.

A convenience variant of [method@Gio.Settings.set] for booleans.

It is a programmer error to give a @key that isn’t specified as
having a `b` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external revert : t -> unit = "ml_g_settings_revert"
(** Reverts all unapplied changes to the settings.

This function does nothing unless @settings is in
[‘delay-apply’ mode](class.Settings.html#delay-apply-mode).  In the normal
case settings are always applied immediately.

Change notifications will be emitted for affected keys. *)

external reset : t -> string -> unit = "ml_g_settings_reset"
(** Resets @key to its default value.

This call resets the key, as much as possible, to its default value.
That might be the value specified in the schema or the one set by the
administrator. *)

external range_check : t -> string -> Gvariant.t -> bool
  = "ml_g_settings_range_check"
(** Checks if the given @value is of the correct type and within the
permitted range for @key. *)

external list_keys : t -> string array = "ml_g_settings_list_keys"
(** Introspects the list of keys on @settings.

You should probably not be calling this function from ‘normal’ code
(since you should already know what keys are in your schema).  This
function is intended for introspection reasons.

You should free the return value with [func@GLib.strfreev] when you are done
with it. *)

external list_children : t -> string array = "ml_g_settings_list_children"
(** Gets the list of children on @settings.

The list is exactly the list of strings for which it is not an error
to call [method@Gio.Settings.get_child].

There is little reason to call this function from ‘normal’ code, since
you should already know what children are in your schema. This function
may still be useful there for introspection reasons, however.

You should free the return value with [func@GLib.strfreev] when you are done
with it. *)

external is_writable : t -> string -> bool = "ml_g_settings_is_writable"
(** Finds out if a key can be written. *)

external get_value : t -> string -> Gvariant.t = "ml_g_settings_get_value"
(** Gets the value that is stored in @settings for @key.

It is a programmer error to give a @key that isn’t contained in the
schema for @settings. *)

external get_user_value : t -> string -> Gvariant.t option
  = "ml_g_settings_get_user_value"
(** Checks the ‘user value’ of a key, if there is one.

The user value of a key is the last value that was set by the user.

After calling [method@Gio.Settings.reset] this function should always return
`NULL` (assuming something is not wrong with the system
configuration).

It is possible that [method@Gio.Settings.get_value] will return a different
value than this function.  This can happen in the case that the user
set a value for a key that was subsequently locked down by the system
administrator — this function will return the user’s old value.

This function may be useful for adding a ‘reset’ option to a UI or
for providing indication that a particular value has been changed.

It is a programmer error to give a @key that isn’t contained in the
schema for @settings. *)

external get_uint64 : t -> string -> UInt64.t = "ml_g_settings_get_uint64"
(** Gets the value that is stored at @key in @settings.

A convenience variant of [method@Gio.Settings.get] for 64-bit unsigned
integers.

It is a programmer error to give a @key that isn’t specified as
having a `t` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external get_uint : t -> string -> int = "ml_g_settings_get_uint"
(** Gets the value that is stored at @key in @settings.

A convenience variant of [method@Gio.Settings.get] for 32-bit unsigned
integers.

It is a programmer error to give a @key that isn’t specified as
having a `u` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external get_strv : t -> string -> string array = "ml_g_settings_get_strv"
(** A convenience variant of [method@Gio.Settings.get] for string arrays.

It is a programmer error to give a @key that isn’t specified as
having an `as` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external get_string : t -> string -> string = "ml_g_settings_get_string"
(** Gets the value that is stored at @key in @settings.

A convenience variant of [method@Gio.Settings.get] for strings.

It is a programmer error to give a @key that isn’t specified as
having an `s` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external get_range : t -> string -> Gvariant.t = "ml_g_settings_get_range"
(** Queries the range of a key. *)

external get_int64 : t -> string -> int64 = "ml_g_settings_get_int64"
(** Gets the value that is stored at @key in @settings.

A convenience variant of [method@Gio.Settings.get] for 64-bit integers.

It is a programmer error to give a @key that isn’t specified as
having an `x` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external get_int : t -> string -> int = "ml_g_settings_get_int"
(** Gets the value that is stored at @key in @settings.

A convenience variant of [method@Gio.Settings.get] for 32-bit integers.

It is a programmer error to give a @key that isn’t specified as
having an `i` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external get_has_unapplied : t -> bool = "ml_g_settings_get_has_unapplied"
(** Returns whether the [class@Gio.Settings] object has any unapplied changes.

    This can only be the case if it is in
    [‘delay-apply’ mode](class.Settings.html#delay-apply-mode). *)

external get_flags : t -> string -> int = "ml_g_settings_get_flags"
(** Gets the value that is stored in @settings for @key and converts it
to the flags value that it represents.

In order to use this function the type of the value must be an array
of strings and it must be marked in the schema file as a flags type.

It is a programmer error to give a @key that isn’t contained in the
schema for @settings or is not marked as a flags type.

If the value stored in the configuration database is not a valid
value for the flags type then this function will return the default
value. *)

external get_enum : t -> string -> int = "ml_g_settings_get_enum"
(** Gets the value that is stored in @settings for @key and converts it
to the enum value that it represents.

In order to use this function the type of the value must be a string
and it must be marked in the schema file as an enumerated type.

It is a programmer error to give a @key that isn’t contained in the
schema for @settings or is not marked as an enumerated type.

If the value stored in the configuration database is not a valid
value for the enumerated type then this function will return the
default value. *)

external get_double : t -> string -> float = "ml_g_settings_get_double"
(** Gets the value that is stored at @key in @settings.

A convenience variant of [method@Gio.Settings.get] for doubles.

It is a programmer error to give a @key that isn’t specified as
having a `d` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external get_default_value : t -> string -> Gvariant.t option
  = "ml_g_settings_get_default_value"
(** Gets the ‘default value’ of a key.

This is the value that would be read if [method@Gio.Settings.reset] were to be
called on the key.

Note that this may be a different value than returned by
[method@Gio.SettingsSchemaKey.get_default_value] if the system administrator
has provided a default value.

Comparing the return values of [method@Gio.Settings.get_default_value] and
[method@Gio.Settings.get_value] is not sufficient for determining if a value
has been set because the user may have explicitly set the value to
something that happens to be equal to the default.  The difference
here is that if the default changes in the future, the user’s key
will still be set.

This function may be useful for adding an indication to a UI of what
the default value was before the user set it.

It is a programmer error to give a @key that isn’t contained in the
schema for @settings. *)

external get_child : t -> string -> t = "ml_g_settings_get_child"
(** Creates a child settings object which has a base path of
`base-path/name`, where `base-path` is the base path of
@settings and `name` is as specified by the caller.

The schema for the child settings object must have been declared
in the schema of @settings using a `<child>` element.

The created child settings object will inherit the
[property@Gio.Settings:delay-apply] mode from @settings. *)

external get_boolean : t -> string -> bool = "ml_g_settings_get_boolean"
(** Gets the value that is stored at @key in @settings.

A convenience variant of [method@Gio.Settings.get] for booleans.

It is a programmer error to give a @key that isn’t specified as
having a `b` type in the schema for @settings (see [struct@GLib.VariantType]). *)

external delay : t -> unit = "ml_g_settings_delay"
(** Changes the [class@Gio.Settings] object into
[‘delay-apply’ mode](class.Settings.html#delay-apply-mode).

In this
mode, changes to @settings are not immediately propagated to the
backend, but kept locally until [method@Gio.Settings.apply] is called. *)

external create_action : t -> string -> Action.t = "ml_g_settings_create_action"
(** Creates a [iface@Gio.Action] corresponding to a given [class@Gio.Settings]
    key.

    The action has the same name as the key.

    The value of the key becomes the state of the action and the action is
    enabled when the key is writable. Changing the state of the action results
    in the key being written to. Changes to the value or writability of the key
    cause appropriate change notifications to be emitted for the action.

    For boolean-valued keys, action activations take no parameter and result in
    the toggling of the value. For all other types, activations take the new
    value for the key (which must have the correct type). *)

external bind_writable :
  t -> string -> [ `object_ ] Gobject.obj -> string -> bool -> unit
  = "ml_g_settings_bind_writable"
(** Create a binding between the writability of @key in the
@settings object and the property @property of @object.

The property must be boolean; `sensitive` or `visible`
properties of widgets are the most likely candidates.

Writable bindings are always uni-directional; changes of the
writability of the setting will be propagated to the object
property, not the other way.

When the @inverted argument is true, the binding inverts the
value as it passes from the setting to the object, i.e. @property
will be set to true if the key is not writable.

Note that the lifecycle of the binding is tied to @object,
and that you can have only one binding per object property.
If you bind the same property twice on the same object, the second
binding overrides the first one. *)

external bind :
  t ->
  string ->
  [ `object_ ] Gobject.obj ->
  string ->
  Gio_enums.settingsbindflags ->
  unit = "ml_g_settings_bind"
(** Create a binding between the @key in the @settings object
and the property @property of @object.

The binding uses the default GIO mapping functions to map
between the settings and property values. These functions
handle booleans, numeric types and string types in a
straightforward way. Use [method@Gio.Settings.bind_with_mapping] if
you need a custom mapping, or map between types that are not
supported by the default mapping functions.

Unless the @flags include [flags@Gio.SettingsBindFlags.NO_SENSITIVITY], this
function also establishes a binding between the writability of
@key and the `sensitive` property of @object (if @object has
a boolean property by that name). See [method@Gio.Settings.bind_writable]
for more details about writable bindings.

Note that the lifecycle of the binding is tied to @object,
and that you can have only one binding per object property.
If you bind the same property twice on the same object, the second
binding overrides the first one. *)

external apply : t -> unit = "ml_g_settings_apply"
(** Applies any changes that have been made to the settings.

This function does nothing unless @settings is in
[‘delay-apply’ mode](class.Settings.html#delay-apply-mode).  In the normal
case settings are always applied immediately. *)

(* Properties *)

external get_delay_apply : t -> bool = "ml_g_settings_get_delay_apply"
(** Get property: delay-apply *)

external get_path : t -> string = "ml_g_settings_get_path"
(** Get property: path *)

external get_schema : t -> string = "ml_g_settings_get_schema"
(** Get property: schema *)

external get_schema_id : t -> string = "ml_g_settings_get_schema_id"
(** Get property: schema-id *)

external get_settings_schema : t -> Settings_schema.t
  = "ml_g_settings_get_settings_schema"
(** Get property: settings-schema *)

let on_changed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let key =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_string_exn v
        in
        callback ~key)
  in
  Gobject.Signal.connect obj ~name:"changed" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_writable_change_event ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let key =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_uint v
        in
        let result = callback ~key in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"writable-change-event" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_writable_changed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let key =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_string_exn v
        in
        callback ~key)
  in
  Gobject.Signal.connect obj ~name:"writable-changed" ~callback:closure
    ~after:(Option.value after ~default:false)
