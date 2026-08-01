(* Shared buffer-printing helper for code generation.

   [Printf.bprintf] has no direct [Fmt] equivalent: [Format.fprintf] on a
   [formatter_of_buffer] does not auto-flush, so the buffer would stay empty.
   This flushes explicitly via [Format.kfprintf]'s continuation. Open this
   module ([open Gen_buffer]) where [bprintf] is used. *)

let bprintf buf fmt =
  Format.kfprintf
    (fun fmtr -> Format.pp_print_flush fmtr ())
    (Format.formatter_of_buffer buf)
    fmt
