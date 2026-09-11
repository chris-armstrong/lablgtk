(* GENERATED CODE - DO NOT EDIT *)
(* ContentFormatsBuilder: ContentFormatsBuilder *)

type t = [ `content_formats_builder ] Gobject.obj
(** Creates `GdkContentFormats` objects. *)

external gtype : unit -> Gobject.Type.t
  = "ml_gdk_content_formats_builder_get_type"

external new_ : unit -> t = "ml_gdk_content_formats_builder_new"
(** Create a new ContentFormatsBuilder *)

(* Methods *)

external to_formats : t -> Content_formats.t
  = "ml_gdk_content_formats_builder_to_formats"
(** Creates a new `GdkContentFormats` from the given @builder.

The given `GdkContentFormatsBuilder` is reset once this function returns;
you cannot call this function multiple times on the same @builder instance.

This function is intended primarily for bindings. C code should use
[method@Gdk.ContentFormatsBuilder.free_to_formats]. *)

external ref : t -> t = "ml_gdk_content_formats_builder_ref"
(** Acquires a reference on the given @builder.

This function is intended primarily for bindings.
`GdkContentFormatsBuilder` objects should not be kept around. *)

external add_mime_type : t -> string -> unit
  = "ml_gdk_content_formats_builder_add_mime_type"
(** Appends @mime_type to @builder if it has not already been added. *)

external add_gtype : t -> Gobject.Type.t -> unit
  = "ml_gdk_content_formats_builder_add_gtype"
(** Appends @type to @builder if it has not already been added. *)

external add_formats : t -> Content_formats.t -> unit
  = "ml_gdk_content_formats_builder_add_formats"
(** Appends all formats from @formats to @builder, skipping those that
already exist. *)
