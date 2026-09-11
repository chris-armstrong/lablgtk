(* GENERATED CODE - DO NOT EDIT *)
(* DataInputStream: DataInputStream *)

type t =
  [ `data_input_stream
  | `buffered_input_stream
  | `filter_input_stream
  | `input_stream
  | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_data_input_stream_get_type"

external new_ : Input_stream.t -> t = "ml_g_data_input_stream_new"
(** Create a new DataInputStream *)

(* Methods *)

external set_newline_type : t -> Gio_enums.datastreamnewlinetype -> unit
  = "ml_g_data_input_stream_set_newline_type"
(** Sets the newline type for the @stream.

Note that using G_DATA_STREAM_NEWLINE_TYPE_ANY is slightly unsafe. If a read
chunk ends in "CR" we must read an additional byte to know if this is "CR" or
"CR LF", and this might block if there is no more data available. *)

external set_byte_order : t -> Gio_enums.datastreambyteorder -> unit
  = "ml_g_data_input_stream_set_byte_order"
(** This function sets the byte order for the given @stream. All subsequent
reads from the @stream will be read in the given @order. *)

external read_upto_finish :
  t -> Async_result.t -> (string * Gsize.t, GError.t) result
  = "ml_g_data_input_stream_read_upto_finish"
(** Finish an asynchronous call started by
    g_data_input_stream_read_upto_async().

    Note that this function does not consume the stop character. You have to use
    g_data_input_stream_read_byte() to get it before calling
    g_data_input_stream_read_upto_async() again.

    The returned string will always be nul-terminated on success. *)

external read_upto :
  t ->
  string ->
  int ->
  Cancellable.t option ->
  (string * Gsize.t, GError.t) result = "ml_g_data_input_stream_read_upto"
(** Reads a string from the data input stream, up to the first
occurrence of any of the stop characters.

In contrast to g_data_input_stream_read_until(), this function
does not consume the stop character. You have to use
g_data_input_stream_read_byte() to get it before calling
g_data_input_stream_read_upto() again.

Note that @stop_chars may contain '\0' if @stop_chars_len is
specified.

The returned string will always be nul-terminated on success. *)

external read_until_finish :
  t -> Async_result.t -> (string * Gsize.t, GError.t) result
  = "ml_g_data_input_stream_read_until_finish"
(** Finish an asynchronous call started by
    g_data_input_stream_read_until_async(). *)

external read_until :
  t -> string -> Cancellable.t option -> (string * Gsize.t, GError.t) result
  = "ml_g_data_input_stream_read_until"
(** Reads a string from the data input stream, up to the first occurrence of any
    of the stop characters.

    Note that, in contrast to g_data_input_stream_read_until_async(), this
    function consumes the stop character that it finds.

    Don't use this function in new code. Its functionality is inconsistent with
    g_data_input_stream_read_until_async(). Both functions will be marked as
    deprecated in a future release. Use g_data_input_stream_read_upto() instead,
    but note that that function does not consume the stop character. *)

external read_uint64 : t -> Cancellable.t option -> (UInt64.t, GError.t) result
  = "ml_g_data_input_stream_read_uint64"
(** Reads an unsigned 64-bit/8-byte value from @stream.

In order to get the correct byte order for this read operation,
see g_data_input_stream_get_byte_order().

If @cancellable is not %NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

external read_uint32 : t -> Cancellable.t option -> (UInt32.t, GError.t) result
  = "ml_g_data_input_stream_read_uint32"
(** Reads an unsigned 32-bit/4-byte value from @stream.

In order to get the correct byte order for this read operation,
see g_data_input_stream_get_byte_order() and g_data_input_stream_set_byte_order().

If @cancellable is not %NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

external read_uint16 : t -> Cancellable.t option -> (UInt16.t, GError.t) result
  = "ml_g_data_input_stream_read_uint16"
(** Reads an unsigned 16-bit/2-byte value from @stream.

In order to get the correct byte order for this read operation,
see g_data_input_stream_get_byte_order() and g_data_input_stream_set_byte_order(). *)

external read_line_utf8 :
  t -> Cancellable.t option -> (string option * Gsize.t, GError.t) result
  = "ml_g_data_input_stream_read_line_utf8"
(** Reads a UTF-8 encoded line from the data input stream.

If @cancellable is not %NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

external read_line_finish_utf8 :
  t -> Async_result.t -> (string option * Gsize.t, GError.t) result
  = "ml_g_data_input_stream_read_line_finish_utf8"
(** Finish an asynchronous call started by
    g_data_input_stream_read_line_async(). *)

external read_int64 : t -> Cancellable.t option -> (int64, GError.t) result
  = "ml_g_data_input_stream_read_int64"
(** Reads a 64-bit/8-byte value from @stream.

In order to get the correct byte order for this read operation,
see g_data_input_stream_get_byte_order() and g_data_input_stream_set_byte_order().

If @cancellable is not %NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

external read_int32 : t -> Cancellable.t option -> (Int32.t, GError.t) result
  = "ml_g_data_input_stream_read_int32"
(** Reads a signed 32-bit/4-byte value from @stream.

In order to get the correct byte order for this read operation,
see g_data_input_stream_get_byte_order() and g_data_input_stream_set_byte_order().

If @cancellable is not %NULL, then the operation can be cancelled by
triggering the cancellable object from another thread. If the operation
was cancelled, the error %G_IO_ERROR_CANCELLED will be returned. *)

external read_int16 : t -> Cancellable.t option -> (Int16.t, GError.t) result
  = "ml_g_data_input_stream_read_int16"
(** Reads a 16-bit/2-byte value from @stream.

In order to get the correct byte order for this read operation,
see g_data_input_stream_get_byte_order() and g_data_input_stream_set_byte_order(). *)

external get_newline_type : t -> Gio_enums.datastreamnewlinetype
  = "ml_g_data_input_stream_get_newline_type"
(** Gets the current newline type for the @stream. *)

external get_byte_order : t -> Gio_enums.datastreambyteorder
  = "ml_g_data_input_stream_get_byte_order"
(** Gets the byte order for the data input stream. *)

(* Properties *)
