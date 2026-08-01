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

let min_value = 0
let max_value = 4294967295

let of_int n =
  if n < min_value || n > max_value then
    invalid_arg
      (Printf.sprintf "UInt32.of_int: %d is out of range [%d, %d]" n min_value
         max_value);
  unsafe_of_int n

let to_int (v : t) = (v :> int)
let min_int = unsafe_of_int min_value
let max_int = unsafe_of_int max_value
let zero = unsafe_of_int 0

let of_string s =
  match int_of_string_opt s with
  | Some n -> of_int n
  | None -> failwith "UInt32.of_string: not a valid integer"

let to_string (v : t) = string_of_int (v :> int)
let of_int64 x = of_int (Int64.to_int x land max_value)
let to_int64 (v : t) = Int64.of_int (v :> int)
