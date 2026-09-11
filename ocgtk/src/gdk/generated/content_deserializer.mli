(* GENERATED CODE - DO NOT EDIT *)
(* ContentDeserializer: ContentDeserializer *)

type t = [ `content_deserializer | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_content_deserializer_get_type"

(* Methods *)

external return_success : t -> unit
  = "ml_gdk_content_deserializer_return_success"
(** Indicate that the deserialization has been successfully completed. *)

external return_error : t -> GError.t -> unit
  = "ml_gdk_content_deserializer_return_error"
(** Indicate that the deserialization has ended with an error.

This function consumes @error. *)

external get_value : t -> Gobject.Value.t
  = "ml_gdk_content_deserializer_get_value"
(** Gets the `GValue` to store the deserialized object in. *)

external get_priority : t -> int = "ml_gdk_content_deserializer_get_priority"
(** Gets the I/O priority for the current operation.

    This is the priority that was passed to
    [func@Gdk.content_deserialize_async]. *)

external get_mime_type : t -> string
  = "ml_gdk_content_deserializer_get_mime_type"
(** Gets the mime type to deserialize from. *)

external get_input_stream : t -> Ocgtk_gio.Gio.Wrappers.Input_stream.t
  = "ml_gdk_content_deserializer_get_input_stream"
(** Gets the input stream for the current operation.

    This is the stream that was passed to [func@Gdk.content_deserialize_async].
*)

external get_gtype : t -> Gobject.Type.t
  = "ml_gdk_content_deserializer_get_gtype"
(** Gets the `GType` to create an instance of. *)

external get_cancellable : t -> Ocgtk_gio.Gio.Wrappers.Cancellable.t option
  = "ml_gdk_content_deserializer_get_cancellable"
(** Gets the cancellable for the current operation.

    This is the `GCancellable` that was passed to
    [func@Gdk.content_deserialize_async]. *)
