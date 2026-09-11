(* GENERATED CODE - DO NOT EDIT *)
(* FilterInputStream: FilterInputStream *)

type t = [ `filter_input_stream | `input_stream | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_filter_input_stream_get_type"

(* Methods *)

external set_close_base_stream : t -> bool -> unit
  = "ml_g_filter_input_stream_set_close_base_stream"
(** Sets whether the base stream will be closed when @stream is closed. *)

external get_close_base_stream : t -> bool
  = "ml_g_filter_input_stream_get_close_base_stream"
(** Returns whether the base stream will be closed when @stream is
closed. *)

external get_base_stream : t -> Input_stream.t
  = "ml_g_filter_input_stream_get_base_stream"
(** Gets the base stream for the filter stream. *)

(* Properties *)
