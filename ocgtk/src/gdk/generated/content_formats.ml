(* GENERATED CODE - DO NOT EDIT *)
(* ContentFormats: ContentFormats *)

type t = [ `content_formats ] Gobject.obj
(** Used to advertise and negotiate the format of content.

    You will encounter `GdkContentFormats` when interacting with objects
    controlling operations that pass data between different widgets, window or
    application, like [class@Gdk.Drag], [class@Gdk.Drop], [class@Gdk.Clipboard]
    or [class@Gdk.ContentProvider].

    GDK supports content in 2 forms: `GType` and mime type. Using `GTypes` is
    meant only for in-process content transfers. Mime types are meant to be used
    for data passing both in-process and out-of-process. The details of how data
    is passed is described in the documentation of the actual implementations.
    To transform between the two forms, [class@Gdk.ContentSerializer] and
    [class@Gdk.ContentDeserializer] are used.

    A `GdkContentFormats` describes a set of possible formats content can be
    exchanged in. It is assumed that this set is ordered. `GTypes` are more
    important than mime types. Order between different `GTypes` or mime types is
    the order they were added in, most important first. Functions that care
    about order, such as [method@Gdk.ContentFormats.union], will describe in
    their documentation how they interpret that order, though in general the
    order of the first argument is considered the primary order of the result,
    followed by the order of further arguments.

    For debugging purposes, the function [method@Gdk.ContentFormats.to_string]
    exists. It will print a comma-separated list of formats from most important
    to least important.

    `GdkContentFormats` is an immutable struct. After creation, you cannot
    change the types it represents. Instead, new `GdkContentFormats` have to be
    created. The [struct@Gdk.ContentFormatsBuilder] structure is meant to help
    in this endeavor. *)

external gtype : unit -> Gobject.Type.t = "ml_gdk_content_formats_get_type"

external new_ : string array option -> int -> t = "ml_gdk_content_formats_new"
(** Create a new ContentFormats *)

external new_for_gtype : Gobject.Type.t -> t
  = "ml_gdk_content_formats_new_for_gtype"
(** Create a new ContentFormats *)

(* Methods *)

external union_serialize_mime_types : t -> t
  = "ml_gdk_content_formats_union_serialize_mime_types"
(** Add mime types for GTypes in @formats for which serializers are
registered. *)

external union_serialize_gtypes : t -> t
  = "ml_gdk_content_formats_union_serialize_gtypes"
(** Add GTypes for the mime types in @formats for which serializers are
registered. *)

external union_deserialize_mime_types : t -> t
  = "ml_gdk_content_formats_union_deserialize_mime_types"
(** Add mime types for GTypes in @formats for which deserializers are
registered. *)

external union_deserialize_gtypes : t -> t
  = "ml_gdk_content_formats_union_deserialize_gtypes"
(** Add GTypes for mime types in @formats for which deserializers are
registered. *)

external union : t -> t -> t = "ml_gdk_content_formats_union"
(** Append all missing types from @second to @first, in the order
they had in @second. *)

external to_string : t -> string = "ml_gdk_content_formats_to_string"
(** Prints the given @formats into a human-readable string.

The resulting string can be parsed with [func@Gdk.ContentFormats.parse].

This is a small wrapper around [method@Gdk.ContentFormats.print]
to help when debugging. *)

external ref : t -> t = "ml_gdk_content_formats_ref"
(** Increases the reference count of a `GdkContentFormats` by one. *)

external match_mime_type : t -> t -> string option
  = "ml_gdk_content_formats_match_mime_type"
(** Finds the first mime type from @first that is also contained
in @second.

If no matching mime type is found, %NULL is returned. *)

external match_gtype : t -> t -> Gobject.Type.t
  = "ml_gdk_content_formats_match_gtype"
(** Finds the first `GType` from @first that is also contained
in @second.

If no matching `GType` is found, %G_TYPE_INVALID is returned. *)

external match_ : t -> t -> bool = "ml_gdk_content_formats_match"
(** Checks if @first and @second have any matching formats. *)

external is_empty : t -> bool = "ml_gdk_content_formats_is_empty"
(** Returns whether the content formats contain any formats. *)

external get_mime_types : t -> string array option * Gsize.t
  = "ml_gdk_content_formats_get_mime_types"
(** Gets the mime types included in @formats.

Note that @formats may not contain any mime types, in particular
when they are empty. In that case %NULL will be returned. *)

external get_gtypes : t -> Gobject.Type.t array option * Gsize.t
  = "ml_gdk_content_formats_get_gtypes"
(** Gets the `GType`s included in @formats.

Note that @formats may not contain any `GType`s, in particular when
they are empty. In that case %NULL will be returned. *)

external contain_mime_type : t -> string -> bool
  = "ml_gdk_content_formats_contain_mime_type"
(** Checks if a given mime type is part of the given @formats. *)

external contain_gtype : t -> Gobject.Type.t -> bool
  = "ml_gdk_content_formats_contain_gtype"
(** Checks if a given `GType` is part of the given @formats. *)
