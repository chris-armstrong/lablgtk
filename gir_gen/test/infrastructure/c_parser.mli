(* Lightweight C parser for validating generated stub code *)

val parse_c_code : string -> C_ast.c_function list
