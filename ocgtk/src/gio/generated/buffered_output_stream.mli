(* GENERATED CODE - DO NOT EDIT *)
(* BufferedOutputStream: BufferedOutputStream *)

type t =
  [ `buffered_output_stream | `filter_output_stream | `output_stream | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_buffered_output_stream_get_type"

external new_ : Output_stream.t -> t = "ml_g_buffered_output_stream_new"
(** Create a new BufferedOutputStream *)

external new_sized : Output_stream.t -> Gsize.t -> t
  = "ml_g_buffered_output_stream_new_sized"
(** Create a new BufferedOutputStream *)

(* Methods *)

external set_buffer_size : t -> Gsize.t -> unit
  = "ml_g_buffered_output_stream_set_buffer_size"
(** Sets the size of the internal buffer to @size. *)

external set_auto_grow : t -> bool -> unit
  = "ml_g_buffered_output_stream_set_auto_grow"
(** Sets whether or not the @stream's buffer should automatically grow.
If @auto_grow is true, then each write will just make the buffer
larger, and you must manually flush the buffer to actually write out
the data to the underlying stream. *)

external get_buffer_size : t -> Gsize.t
  = "ml_g_buffered_output_stream_get_buffer_size"
(** Gets the size of the buffer in the @stream. *)

external get_auto_grow : t -> bool = "ml_g_buffered_output_stream_get_auto_grow"
(** Checks if the buffer automatically grows as data is added. *)

(* Properties *)
