(* Lightweight C AST for validating generated stub code *)

(** {1 C AST Types} *)

type c_type = string
(** A C type name as written in generated code (e.g. ["value"], ["GtkButton*"],
    ["int"]). *)

type c_param = { param_type : c_type; param_name : string }
(** A single C function parameter: its type and its name. *)

type c_expr =
  | Var of string
  | Call of string * c_expr list
  | Cast of c_type * c_expr
  | IntLiteral of int
  | StringLiteral of string
  | Macro of string * c_expr list
  | AddrOf of c_expr
  | Deref of c_expr
      (** A C expression: variable, function call, cast, integer/string literal,
          macro (e.g. [CAMLreturn], [Val_*]), address-of ([&expr]) or
          dereference ([*expr]). *)

type c_stmt =
  | VarDecl of c_type * string * c_expr option
  | Assign of string * c_expr
  | Return of c_expr
  | ExprStmt of c_expr
  | IfStmt of c_expr * c_stmt list * c_stmt list
  | Empty
      (** A C statement: variable declaration (type, name, optional
          initializer), assignment, return, expression statement, if/else
          (condition, then, else), or empty. *)

type c_function = {
  return_type : c_type;
  name : string;
  params : c_param list;
  body : c_stmt list;
  has_bytecode_variant : bool;
}
(** A parsed C function: signature plus body statements. [has_bytecode_variant]
    is [true] when the function is part of a native/bytecode pair. *)

type c_file = c_function list
(** A parsed C file: a list of functions in source order. *)

type type_info = {
  variables : (string * c_type) list;
  parameter_types : (string * c_type) list;
  return_expr : c_expr option;
}
(** Type information extracted from a function: all declared variables,
    parameter types, and the expression being returned (if any). *)

(** {1 Function Queries} *)

val find_function : c_function list -> string -> c_function option
(** Find a function by name in a parsed C file.

    [find_function functions name] returns [Some f] for the first function whose
    name is [name], or [None] if no such function exists. *)

val get_function_name : c_function -> string
(** Return the name of a function. *)

val get_param_count : c_function -> int
(** Return the number of parameters of a function. *)

val has_return_stmt : c_stmt list -> bool
(** Check whether a statement list contains a [Return] statement. *)

val function_calls_function : c_function -> string -> bool
(** Check whether a function's body calls the named function, directly or inside
    nested expressions. *)

val extract_type_info : c_function -> type_info
(** Extract declared variables, parameter types and the return expression from a
    function. *)

val expr_uses_var : c_expr -> string -> bool
(** Check whether an expression references the named variable. *)

val get_function_calls : c_expr -> string list
(** Return the names of all functions and macros called within an expression. *)

val has_var_decl : c_function -> string -> bool
(** Check whether the function declares a variable with the given name. *)

val get_var_decls : c_function -> (string * c_type * c_expr option) list
(** Return all variable declarations in the function body as
    [(name, type, initializer)] triples. *)

val return_expr : c_function -> c_expr option
(** Return the expression of the first [return] statement in the function, or
    [None] if the function has no return statement. *)
