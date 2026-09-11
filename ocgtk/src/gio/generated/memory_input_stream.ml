(* GENERATED CODE - DO NOT EDIT *)
(* MemoryInputStream: MemoryInputStream *)

type t = [ `memory_input_stream | `input_stream | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_memory_input_stream_get_type"

external new_ : unit -> t = "ml_g_memory_input_stream_new"
(** Create a new MemoryInputStream *)

external new_from_bytes : Glib_bytes.t -> t
  = "ml_g_memory_input_stream_new_from_bytes"
(** Create a new MemoryInputStream *)

(* Methods *)

external add_bytes : t -> Glib_bytes.t -> unit
  = "ml_g_memory_input_stream_add_bytes"
(** Appends @bytes to data that can be read from the input stream. *)
