(* GENERATED CODE - DO NOT EDIT *)
(* SimpleIOStream: SimpleIOStream *)

type t = [ `simple_io_stream | `io_stream | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_simple_io_stream_get_type"

external new_ : Input_stream.t -> Output_stream.t -> t
  = "ml_g_simple_io_stream_new"
(** Create a new SimpleIOStream *)

(* Methods *)
(* Properties *)

external get_input_stream : t -> Input_stream.t
  = "ml_g_simple_io_stream_get_input_stream"
(** Get property: input-stream *)

external get_output_stream : t -> Output_stream.t
  = "ml_g_simple_io_stream_get_output_stream"
(** Get property: output-stream *)
