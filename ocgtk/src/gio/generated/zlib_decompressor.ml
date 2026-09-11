(* GENERATED CODE - DO NOT EDIT *)
(* ZlibDecompressor: ZlibDecompressor *)

type t = [ `zlib_decompressor | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_zlib_decompressor_get_type"

external new_ : Gio_enums.zlibcompressorformat -> t
  = "ml_g_zlib_decompressor_new"
(** Create a new ZlibDecompressor *)

(* Methods *)

external get_file_info : t -> File_info.t option
  = "ml_g_zlib_decompressor_get_file_info"
(** Gets the [property@Gio.ZlibDecompressor:file-info] property. *)

(* Properties *)

external get_format : t -> Gio_enums.zlibcompressorformat
  = "ml_g_zlib_decompressor_get_format"
(** Get property: format *)
