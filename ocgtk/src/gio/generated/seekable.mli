(* GENERATED CODE - DO NOT EDIT *)
(* Seekable: Seekable *)

type t = [ `seekable ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_seekable_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gio_seekable_from_gobject"

(* Methods *)

external truncate :
  t -> int64 -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_seekable_truncate"
(** Sets the length of the stream to @offset. If the stream was previously
larger than @offset, the extra data is discarded. If the stream was
previously shorter than @offset, it is extended with NUL ('\0') bytes.

If @cancellable is not %NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. If an
operation was partially finished when the operation was cancelled the
partial result will be returned, without an error. *)

external tell : t -> int64 = "ml_g_seekable_tell"
(** Tells the current position within the stream. *)

external can_truncate : t -> bool = "ml_g_seekable_can_truncate"
(** Tests if the length of the stream can be adjusted with
    g_seekable_truncate(). *)

external can_seek : t -> bool = "ml_g_seekable_can_seek"
(** Tests if the stream supports the #GSeekableIface. *)
