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

let min_value = -2147483648
let max_value = 2147483647

let of_int n =
  if n < min_value || n > max_value then
    invalid_arg
      ("Int32.of_int: " ^ string_of_int n ^ " is out of range ["
     ^ string_of_int min_value ^ ", " ^ string_of_int max_value ^ "]");
  unsafe_of_int n

let to_int (v : t) = (v :> int)
let min_int = unsafe_of_int min_value
let max_int = unsafe_of_int max_value
let minus_one = unsafe_of_int (-1)
