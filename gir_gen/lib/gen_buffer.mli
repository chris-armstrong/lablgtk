(** Shared buffer-printing helper for code generation.

    [bprintf buf fmt] writes the formatted output to [buf] and flushes, as a
    drop-in for [Printf.bprintf] (which has no [Fmt] equivalent that
    auto-flushes a [Buffer.t]). *)

val bprintf : Buffer.t -> ('a, Format.formatter, unit, unit) format4 -> 'a
