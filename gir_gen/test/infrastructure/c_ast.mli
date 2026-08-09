type c_type = string
type c_param = { param_type : c_type; param_name : string }

type c_expr =
  | Var of string
  | Call of string * c_expr list
  | Cast of c_type * c_expr
  | IntLiteral of int
  | StringLiteral of string
  | Macro of string * c_expr list
  | AddrOf of c_expr
  | Deref of c_expr

type c_stmt =
  | VarDecl of c_type * string * c_expr option
  | Assign of string * c_expr
  | Return of c_expr
  | ExprStmt of c_expr
  | IfStmt of c_expr * c_stmt list * c_stmt list
  | Empty

type c_function = {
  return_type : c_type;
  name : string;
  params : c_param list;
  body : c_stmt list;
  has_bytecode_variant : bool;
}

type c_file = c_function list

type type_info = {
  variables : (string * c_type) list;
  parameter_types : (string * c_type) list;
  return_expr : c_expr option;
}

val find_function : c_function list -> string -> c_function option
val get_function_name : c_function -> string
val get_param_count : c_function -> int
val has_return_stmt : c_stmt list -> bool
val find_call_in_expr : c_expr -> string -> bool
val calls_function : c_stmt list -> string -> bool
val function_calls_function : c_function -> string -> bool
val extract_type_info : c_function -> type_info
val get_var_type : type_info -> string -> c_type option
val unwrap_expr : c_expr -> c_expr
val get_var_from_expr : c_expr -> string option
val expr_uses_var : c_expr -> string -> bool
val get_function_calls : c_expr -> string list
val params_used_in_return : c_function -> (string * c_type) list
val has_var_decl : c_function -> string -> bool
val get_var_decls : c_function -> (string * c_type * c_expr option) list
val get_caml_local_decls : c_function -> string list
val get_all_local_value_decls : c_function -> int
val returns_type : c_function -> c_type -> bool
val return_expr : c_function -> c_expr option
