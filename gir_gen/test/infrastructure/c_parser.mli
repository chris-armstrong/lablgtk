(* Lightweight C parser for validating generated stub code *)

val parse_c_code : string -> C_ast.c_function list
(** Parse a complete C source string into a list of functions.

    [parse_c_code code] splits [code] into lines, recognises function
    signatures, parses each body statement into the {!C_ast} representation, and
    post-processes the result to flag native/bytecode pairs.

    @return the list of parsed functions, in source order. *)

val function_calls_in_code : string -> string -> bool
(** Check whether a C code string calls the named function.

    [function_calls_in_code func_code target_name] returns [true] if any line of
    [func_code] contains a call to [target_name] (matched as [target_name(] or
    [ target_name(]). *)
