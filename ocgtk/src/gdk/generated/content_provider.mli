(* GENERATED CODE - DO NOT EDIT *)
(* ContentProvider: ContentProvider *)

type t = [ `content_provider | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_content_provider_get_type"

external new_for_bytes : string -> Glib_bytes.t -> t
  = "ml_gdk_content_provider_new_for_bytes"
(** Create a new ContentProvider *)

external new_for_value : Gobject.Value.t -> t
  = "ml_gdk_content_provider_new_for_value"
(** Create a new ContentProvider *)

external new_union : t array option -> Gsize.t -> t
  = "ml_gdk_content_provider_new_union"
(** Create a new ContentProvider *)

(* Methods *)

external write_mime_type_finish :
  t -> Ocgtk_gio.Gio.Wrappers.Async_result.t -> (bool, GError.t) result
  = "ml_gdk_content_provider_write_mime_type_finish"
(** Finishes an asynchronous write operation.

    See [method@Gdk.ContentProvider.write_mime_type_async]. *)

external ref_storable_formats : t -> Content_formats.t
  = "ml_gdk_content_provider_ref_storable_formats"
(** Gets the formats that the provider suggests other applications to store the
    data in.

    An example of such an application would be a clipboard manager.

    This can be assumed to be a subset of
    [method@Gdk.ContentProvider.ref_formats]. *)

external ref_formats : t -> Content_formats.t
  = "ml_gdk_content_provider_ref_formats"
(** Gets the formats that the provider can provide its current contents in. *)

external get_value : t -> (bool * Gobject.Value.t, GError.t) result
  = "ml_gdk_content_provider_get_value"
(** Gets the contents of @provider stored in @value.

The @value will have been initialized to the `GType` the value should be
provided in. This given `GType` does not need to be listed in the formats
returned by [method@Gdk.ContentProvider.ref_formats]. However, if the
given `GType` is not supported, this operation can fail and
`G_IO_ERROR_NOT_SUPPORTED` will be reported. *)

external content_changed : t -> unit = "ml_gdk_content_provider_content_changed"
(** Emits the ::content-changed signal. *)

(* Properties *)

val on_content_changed :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
