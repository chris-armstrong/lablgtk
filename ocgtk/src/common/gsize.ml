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

type t = private int

external unsafe_of_int : int -> t = "%identity"

let of_int n =
  if n < 0 then
    invalid_arg ("Gsize.of_int: value " ^ string_of_int n ^ " is negative")
  else unsafe_of_int n

let to_int (t : t) = (t :> int)
let zero = unsafe_of_int 0
let max_int = unsafe_of_int Stdlib.max_int
let min_value = 0
let max_value = Stdlib.max_int
