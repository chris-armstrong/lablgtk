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

(** Interface to GLib functions (GTK4 / GLib 2.66+)

    This module provides access to GLib functionality used by GTK4:
    - Main event loop
    - Timeout and idle callbacks
    - Character set conversion (UTF-8)
    - String utilities *)

type unichar = int
(** Unicode character (UTF-32 code point) *)

type unistring = unichar array
(** Array of Unicode characters *)

exception GError of string
(** Exception raised for GLib errors *)

(** {2 Main Event Loop} *)

(** The Main Event Loop
    @see <https://docs.gtk.org/glib/main-loop.html> GLib Main Loop *)
module Main : sig
  type t
  (** Main loop handle *)

  val create : bool -> t
  (** [create is_running] creates a new main loop. If [is_running] is [true],
      the loop is immediately marked as running. *)

  val run : t -> unit
  (** [run loop] runs the main loop until {!quit} is called. *)

  val iteration : bool -> bool
  (** [iteration may_block] runs a single iteration of the main context. If
      [may_block] is [true], the iteration can block waiting for events. Returns
      [true] if events were processed. *)

  val pending : unit -> bool
  (** Returns [true] if events are pending in the main loop *)

  val is_running : t -> bool
  (** [is_running loop] returns [true] if the loop is currently running *)

  val quit : t -> unit
  (** [quit loop] stops a running main loop *)

  val destroy : t -> unit
  (** [destroy loop] decrements the reference count on the loop. When the
      reference count drops to zero, the loop is freed. *)
end

(** Priority levels for timeouts and idle callbacks *)
val int_of_priority :
  [< `HIGH | `DEFAULT | `HIGH_IDLE | `DEFAULT_IDLE | `LOW ] -> int
(** Convert priority variant to integer value *)

(** {2 Timeout Callbacks} *)

(** Timeout callbacks - functions called after a specified time
    @see <https://docs.gtk.org/glib/func.timeout_add.html> g_timeout_add *)
module Timeout : sig
  type id
  (** Timeout source ID *)

  val add : ?prio:int -> ms:int -> callback:(unit -> bool) -> unit -> id
  (** [add ?prio ~ms ~callback ()] adds a timeout function called every [ms]
      milliseconds. [callback] should return [true] to keep being called, or
      [false] to be removed. [prio] defaults to [G_PRIORITY_DEFAULT]. *)

  val remove : id -> unit
  (** [remove id] removes the timeout with the given ID *)
end

(** {2 Idle Callbacks} *)

(** Idle callbacks - functions called when the main loop is idle
    @see <https://docs.gtk.org/glib/func.idle_add.html> g_idle_add *)
module Idle : sig
  type id
  (** Idle source ID *)

  val add : ?prio:int -> (unit -> bool) -> id
  (** [add ?prio callback] adds a function to be called whenever there are no
      higher-priority events pending in the main loop. [callback] should return
      [true] to keep being called, or [false] to be removed. [prio] defaults to
      [G_PRIORITY_DEFAULT_IDLE]. *)

  val remove : id -> unit
  (** [remove id] removes the idle callback with the given ID *)
end

(** {2 Character Set Conversion} *)

(** Character Set Conversion
    @see <https://docs.gtk.org/glib/convert.html> Character Set Conversion *)
module Convert : sig
  type error =
    | NO_CONVERSION  (** Conversion between character sets not supported *)
    | ILLEGAL_SEQUENCE  (** Invalid byte sequence in conversion input *)
    | FAILED  (** Conversion failed for some reason *)
    | PARTIAL_INPUT  (** Partial character sequence at end of input *)
    | BAD_URI  (** URI is invalid *)
    | NOT_ABSOLUTE_PATH  (** Pathname is not an absolute path *)

  exception Error of error * string
  (** Exception raised when conversion fails *)

  val convert : string -> to_codeset:string -> from_codeset:string -> string
  (** [convert str ~to_codeset ~from_codeset] converts [str] from [from_codeset]
      to [to_codeset].
      @raise Error if conversion fails *)

  val locale_to_utf8 : string -> string
  (** [locale_to_utf8 str] converts [str] from the current locale's encoding to
      UTF-8. If the locale is already UTF-8, validates and returns the string
      unmodified.
      @raise Error if conversion fails or string is invalid *)

  val locale_from_utf8 : string -> string
  (** [locale_from_utf8 str] converts [str] from UTF-8 to the current locale's
      encoding. If the locale is already UTF-8, validates and returns the string
      unmodified.
      @raise Error if conversion fails or string is invalid UTF-8 *)

  val filename_to_utf8 : string -> string
  (** [filename_to_utf8 filename] converts a filename from the filesystem
      encoding to UTF-8.
      @raise Error if conversion fails *)

  val filename_from_utf8 : string -> string
  (** [filename_from_utf8 filename] converts a filename from UTF-8 to the
      filesystem encoding.
      @raise Error if conversion fails *)

  val get_charset : unit -> bool * string
  (** [get_charset ()] returns [(is_utf8, charset)] where [is_utf8] is [true] if
      the current locale uses UTF-8 encoding, and [charset] is the name of the
      character set. *)
end

(** {2 UTF-8 String Utilities} *)

(** UTF-8 String Utilities
    @see <https://docs.gtk.org/glib/utf8.html> Unicode Manipulation *)
module Utf8 : sig
  val validate : string -> bool
  (** [validate str] returns [true] if [str] is valid UTF-8 *)
end

(** {2 Application and Program Names} *)

val get_prgname : unit -> string option
(** Get the name of the program. This is typically argv[0]. Returns [None] if
    the program name has not been set. *)

val set_prgname : string -> unit
(** Set the name of the program. This name should not be localized. *)

val get_application_name : unit -> string option
(** Get the human-readable application name for display in the UI. Returns
    [None] if the application name has not been set. *)

val set_application_name : string -> unit
(** Set a human-readable name for the application. This name should be localized
    if possible and is intended for display to the user. *)
