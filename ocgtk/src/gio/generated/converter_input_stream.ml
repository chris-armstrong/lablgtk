(* GENERATED CODE - DO NOT EDIT *)
(* ConverterInputStream: ConverterInputStream *)

type t =
  [ `converter_input_stream | `filter_input_stream | `input_stream | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_converter_input_stream_get_type"

external new_ : Input_stream.t -> Converter.t -> t
  = "ml_g_converter_input_stream_new"
(** Create a new ConverterInputStream *)

(* Methods *)

external get_converter : t -> Converter.t
  = "ml_g_converter_input_stream_get_converter"
(** Gets the #GConverter that is used by @converter_stream. *)

(* Properties *)
