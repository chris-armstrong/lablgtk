(* GENERATED CODE - DO NOT EDIT *)
(* ConverterOutputStream: ConverterOutputStream *)

type t =
  [ `converter_output_stream
  | `filter_output_stream
  | `output_stream
  | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gio_converter_output_stream_get_type"

external new_ : Output_stream.t -> Converter.t -> t
  = "ml_g_converter_output_stream_new"
(** Create a new ConverterOutputStream *)

(* Methods *)

external get_converter : t -> Converter.t
  = "ml_g_converter_output_stream_get_converter"
(** Gets the #GConverter that is used by @converter_stream. *)

(* Properties *)
