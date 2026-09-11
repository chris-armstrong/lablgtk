(* GENERATED CODE - DO NOT EDIT *)
(* Converter: Converter *)

type t = [ `converter ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_converter_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gio_converter_from_gobject"

(* Methods *)

external reset : t -> unit = "ml_g_converter_reset"
(** Resets all internal state in the converter, making it behave as if it was
    just created. If the converter has any internal state that would produce
    output then that output is lost. *)

external convert_bytes : t -> Glib_bytes.t -> (Glib_bytes.t, GError.t) result
  = "ml_g_converter_convert_bytes"
(** Applies @converter to the data in @bytes. *)
