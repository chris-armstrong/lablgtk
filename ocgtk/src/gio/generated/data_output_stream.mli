(* GENERATED CODE - DO NOT EDIT *)
(* DataOutputStream: DataOutputStream *)

type t =
  [ `data_output_stream | `filter_output_stream | `output_stream | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_data_output_stream_get_type"

external new_ : Output_stream.t -> t = "ml_g_data_output_stream_new"
(** Create a new DataOutputStream *)

(* Methods *)

external set_byte_order : t -> Gio_enums.datastreambyteorder -> unit
  = "ml_g_data_output_stream_set_byte_order"
(** Sets the byte order of the data output stream to @order. *)

external put_uint64 :
  t -> UInt64.t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_data_output_stream_put_uint64"
(** Puts an unsigned 64-bit integer into the stream. *)

external put_uint32 :
  t -> UInt32.t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_data_output_stream_put_uint32"
(** Puts an unsigned 32-bit integer into the stream. *)

external put_uint16 :
  t -> UInt16.t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_data_output_stream_put_uint16"
(** Puts an unsigned 16-bit integer into the output stream. *)

external put_string :
  t -> string -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_data_output_stream_put_string"
(** Puts a string into the output stream. *)

external put_int64 :
  t -> int64 -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_data_output_stream_put_int64"
(** Puts a signed 64-bit integer into the stream. *)

external put_int32 :
  t -> Int32.t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_data_output_stream_put_int32"
(** Puts a signed 32-bit integer into the output stream. *)

external put_int16 :
  t -> Int16.t -> Cancellable.t option -> (bool, GError.t) result
  = "ml_g_data_output_stream_put_int16"
(** Puts a signed 16-bit integer into the output stream. *)

external get_byte_order : t -> Gio_enums.datastreambyteorder
  = "ml_g_data_output_stream_get_byte_order"
(** Gets the byte order for the stream. *)

(* Properties *)
