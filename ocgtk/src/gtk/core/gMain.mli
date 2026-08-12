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

(** Main event loop and initialization for GTK4 *)

(** {2 Initialization} *)

exception Error of string

val init : ?setlocale:bool -> unit -> string array
(** Initialize GTK.

    This must be called before using any GTK functions. Returns the remaining
    command-line arguments after GTK processes its options.

    @raise Error if initialization fails

    Example:
    {[
    let () =
      let _ = GMain.init () in
      (* ... create widgets ... *)
      GMain.main ()
    ]} *)

(** {2 Main Loop} *)

val main : unit -> unit
(** Start the GTK main event loop. This function blocks until {!quit} is called.
*)

val quit : unit -> unit
(** Exit the main event loop. Typically called from a signal handler or
    callback. *)

val iteration : bool -> bool
(** [iteration block] runs one iteration of the main loop. When [block] is
    [true] it waits for events; when [false] it returns immediately if none are
    pending. Returns [true] if more events are pending. *)

(** {2 Deprecated - Use GtkApplication Instead}

    Note: For new GTK4 applications, GtkApplication is preferred over the main
    loop functions. However, these are provided for:
    - Testing during development
    - Simple examples
    - Migration from GTK3

    Full GtkApplication support is planned for a future release. *)
