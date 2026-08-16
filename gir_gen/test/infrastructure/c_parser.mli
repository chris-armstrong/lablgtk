(* Lightweight C parser for validating generated stub code *)

val parse_c_code : string -> C_ast.c_function list
(** Parse C source text into the lightweight {!C_ast} function list. *)
