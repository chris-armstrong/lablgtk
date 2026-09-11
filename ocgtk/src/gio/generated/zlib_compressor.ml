(* GENERATED CODE - DO NOT EDIT *)
(* ZlibCompressor: ZlibCompressor *)

type t = [ `zlib_compressor | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_zlib_compressor_get_type"

external new_ : Gio_enums.zlibcompressorformat -> int -> t
  = "ml_g_zlib_compressor_new"
(** Create a new ZlibCompressor *)

(* Methods *)

external set_os : t -> int -> unit = "ml_g_zlib_compressor_set_os"
(** Sets the [property@Gio.ZlibCompressor:os] property.

Note: it is an error to call this function while a compression is in
progress; it may only be called immediately after creation of @compressor,
or after resetting it with [method@Gio.Converter.reset]. *)

external set_file_info : t -> File_info.t option -> unit
  = "ml_g_zlib_compressor_set_file_info"
(** Sets the [property@Gio.ZlibCompressor:file-info] property.

Note: it is an error to call this function while a compression is in
progress; it may only be called immediately after creation of @compressor,
or after resetting it with [method@Gio.Converter.reset]. *)

external get_os : t -> int = "ml_g_zlib_compressor_get_os"
(** Gets the [property@Gio.ZlibCompressor:os] property. *)

external get_file_info : t -> File_info.t option
  = "ml_g_zlib_compressor_get_file_info"
(** Gets the [property@Gio.ZlibCompressor:file-info] property. *)

(* Properties *)

external get_format : t -> Gio_enums.zlibcompressorformat
  = "ml_g_zlib_compressor_get_format"
(** Get property: format *)

external get_level : t -> int = "ml_g_zlib_compressor_get_level"
(** Get property: level *)
