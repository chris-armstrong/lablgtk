(**************************************************************************)
(*                ocgtk - OCaml bindings for GTK4                         *)
(*                                                                        *)
(*    This program is free software; you can redistribute it              *)
(*    and/or modify it under the terms of the GNU Library General         *)
(*    Public License version 2, as published by the                       *)
(*    Free Software Foundation with the exception described in file       *)
(*    COPYING which comes with the library.                               *)
(*                                                                        *)
(*    Based on lablgtk3 (https://github.com/garrigue/lablgtk)             *)
(*                                                                        *)
(**************************************************************************)

(** GLib.Bytes - Immutable reference-counted byte buffer

    GBytes wraps an immutable block of memory with reference counting. Used for
    texture data, file contents, serialized data, etc. *)

type t
(** Opaque GBytes type - backed by GBytes* with g_bytes_unref finalizer *)

external create : string -> t = "ml_g_bytes_new"
(** Create a GBytes from an OCaml string (copies the data) *)

external of_bigstring
  :  (char, Bigarray.int8_unsigned_elt, Bigarray.c_layout) Bigarray.Array1.t
  -> t
  = "ml_g_bytes_new_from_bigarray"
(** Create a GBytes directly from a Bigarray (e.g. a Bigstring), skipping the
    intermediate OCaml string that [create] requires. One copy total (into
    the new GBytes); the returned value shares no memory with the bigarray
    and has no lifetime coupling to it -- the bigarray may be freed
    immediately after this call returns. *)

external to_string : t -> string = "ml_g_bytes_get_data_as_string"
(** Copy the GBytes data into a new OCaml string *)

external size : t -> int = "ml_g_bytes_get_size"
(** Get the size of the byte buffer *)
