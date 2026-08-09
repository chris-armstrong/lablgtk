val strip : string -> string
val parse_c_type : string -> string

val parse_function_signature :
  string -> (string * string * C_ast.c_param list) option

val parse_expr : string -> C_ast.c_expr
val parse_function_call : string -> C_ast.c_expr
val separate_pointer_from_name : string -> string * string
val separate_array_from_name : string -> string * string option
val parse_var_decl : string -> C_ast.c_stmt option
val parse_assignment : string -> C_ast.c_stmt option
val has_return : string -> bool
val parse_return : string -> C_ast.c_stmt option
val parse_condition : string -> C_ast.c_expr option
val parse_if_else : string -> C_ast.c_stmt option
val parse_statement : string -> C_ast.c_stmt option
val parse_c_code : string -> C_ast.c_function list
val function_calls_in_code : string -> string -> bool
