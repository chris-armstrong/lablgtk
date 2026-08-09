(* Lightweight C AST for validating generated stub code *)

(* We only need to represent the subset of C that our generator produces *)

type c_type = string
(** A C type name as written in generated code (e.g. ["value"], ["GtkButton*"],
    ["int"]). *)

type c_param = { param_type : c_type; param_name : string }
(** A single C function parameter: its type and its name. *)

(** A C expression: variable, function call, cast, integer/string literal, macro
    (e.g. [CAMLreturn], [Val_*]), address-of ([&expr]) or dereference ([*expr]).
*)
type c_expr =
  | Var of string
  | Call of string * c_expr list (* function_name, arguments *)
  | Cast of c_type * c_expr
  | IntLiteral of int
  | StringLiteral of string
  | Macro of string * c_expr list (* For CAMLreturn, Val_*, etc. *)
  | AddrOf of c_expr (* &expr *)
  | Deref of c_expr (* *expr *)

(** A C statement: variable declaration (type, name, optional initializer),
    assignment, return, expression statement, if/else (condition, then, else),
    or empty. *)
type c_stmt =
  | VarDecl of
      c_type * string * c_expr option (* type, name, optional initializer *)
  | Assign of string * c_expr
  | Return of c_expr
  | ExprStmt of c_expr
  | IfStmt of c_expr * c_stmt list * c_stmt list (* condition, then, else *)
  | Empty

type c_function = {
  return_type : c_type;
  name : string;
  params : c_param list;
  body : c_stmt list;
  has_bytecode_variant : bool;
      (* true if this is part of a native/bytecode pair *)
}
(** A parsed C function: signature plus body statements. [has_bytecode_variant]
    is [true] when the function is part of a native/bytecode pair. *)

type c_file = c_function list

type type_info = {
  variables : (string * c_type) list; (* All declared variables *)
  parameter_types : (string * c_type) list; (* Function parameters *)
  return_expr : c_expr option; (* The expression being returned *)
}
(** Type information extracted from a function: all declared variables,
    parameter types, and the expression being returned (if any). *)

(* Helper functions for AST queries *)

(** Find a function by name in a parsed C file. *)
let find_function functions name =
  List.find_opt (fun f -> f.name = name) functions

let get_function_name f = f.name

(** Return the number of parameters of a function. *)
let get_param_count f = List.length f.params

(** Check whether a statement list contains a [Return] statement. *)
let has_return_stmt stmts =
  List.exists (function Return _ -> true | _ -> false) stmts

let rec find_call_in_expr expr func_name =
  match expr with
  | Call (name, _) when name = func_name -> true
  | Call (_, args) -> List.exists (fun e -> find_call_in_expr e func_name) args
  | Cast (_, e) -> find_call_in_expr e func_name
  | Macro (name, _) when name = func_name -> true
  | Macro (_, args) -> List.exists (fun e -> find_call_in_expr e func_name) args
  | AddrOf e | Deref e -> find_call_in_expr e func_name
  | _ -> false

let calls_function stmts func_name =
  List.exists
    (function
      | ExprStmt expr | Return expr -> find_call_in_expr expr func_name
      | VarDecl (_, _, Some expr) -> find_call_in_expr expr func_name
      | Assign (_, expr) -> find_call_in_expr expr func_name
      | _ -> false)
    stmts

let function_calls_function f func_name = calls_function f.body func_name

(** Extract declared variables, parameter types and the return expression from a
    function. *)
let extract_type_info f =
  (* Collect all variable declarations *)
  let variables =
    List.filter_map
      (function VarDecl (t, name, _) -> Some (name, t) | _ -> None)
      f.body
  in

  (* Get parameter types *)
  let parameter_types =
    List.map (fun p -> (p.param_name, p.param_type)) f.params
  in

  (* Find return expression *)
  let return_expr =
    List.find_map (function Return expr -> Some expr | _ -> None) f.body
  in

  { variables; parameter_types; return_expr }

(* Get the type of a variable (from params or declarations) *)
let get_var_type type_info var_name =
  let all_vars = type_info.parameter_types @ type_info.variables in
  List.assoc_opt var_name all_vars

(* Extract the innermost expression from casts and macros *)
let rec unwrap_expr expr =
  match expr with
  | Cast (_, e) -> unwrap_expr e
  | Macro (_, [ e ]) -> unwrap_expr e
  | AddrOf e | Deref e -> unwrap_expr e
  | e -> e

(* Get the variable name from an expression if it's a simple variable *)
let get_var_from_expr expr =
  match unwrap_expr expr with Var name -> Some name | _ -> None

(** Check whether an expression references the named variable. *)
let rec expr_uses_var expr var_name =
  match expr with
  | Var name -> name = var_name
  | Call (_, args) -> List.exists (fun e -> expr_uses_var e var_name) args
  | Cast (_, e) -> expr_uses_var e var_name
  | Macro (_, args) -> List.exists (fun e -> expr_uses_var e var_name) args
  | AddrOf e | Deref e -> expr_uses_var e var_name
  | _ -> false

(* Get all function calls in an expression *)

(** Return the names of all functions and macros called within an expression. *)
let rec get_function_calls expr =
  match expr with
  | Call (name, args) -> name :: List.concat_map get_function_calls args
  | Cast (_, e) -> get_function_calls e
  | Macro (_, args) -> List.concat_map get_function_calls args
  | AddrOf e | Deref e -> get_function_calls e
  | _ -> []

(* Find which parameters are used in the return expression *)
let params_used_in_return f =
  let type_info = extract_type_info f in
  match type_info.return_expr with
  | None -> []
  | Some expr ->
      List.filter
        (fun (param_name, _) -> expr_uses_var expr param_name)
        type_info.parameter_types

(** Check whether the function declares a variable with the given name. *)
let has_var_decl f var_name =
  List.exists
    (function VarDecl (_, name, _) -> name = var_name | _ -> false)
    f.body

(* Get all variable declarations with their types *)

(** Return all variable declarations in the function body as
    [(name, type, initializer)] triples. *)
let get_var_decls f =
  List.filter_map
    (function VarDecl (t, name, init) -> Some (name, t, init) | _ -> None)
    f.body

(* Get CAMLlocal declarations - these are parsed as ExprStmt macros *)

(** Return the names of all [CAMLlocal*] macro declarations in the function
    body. *)
let get_caml_local_decls f =
  List.filter_map
    (function
      | ExprStmt (Macro (name, _))
        when String.starts_with ~prefix:"CAMLlocal" name ->
          Some name
      | _ -> None)
    f.body

(* Get all local value declarations (VarDecl + CAMLlocal) - count both styles *)
let get_all_local_value_decls f =
  let var_decls = List.length (get_var_decls f) in
  let caml_locals = List.length (get_caml_local_decls f) in
  var_decls + caml_locals

(* Check if function returns a specific type *)
let returns_type f expected_type = f.return_type = expected_type

(** Return the expression of the first [return] statement in the function, or
    [None] if the function has no return statement. *)
let return_expr f =
  List.find_map (function Return expr -> Some expr | _ -> None) f.body
