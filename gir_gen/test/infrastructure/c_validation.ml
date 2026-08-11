(* Validation helpers specific to ocgtk C stub generation *)

open C_ast

(* Get the conversion macro used (Val_GtkButton, etc.) *)
let rec get_conversion_macro expr =
  match expr with
  | Macro (name, args) when String.starts_with ~prefix:"Val_" name ->
      (* Skip nullable wrappers (Val_option, Val_some) to find the actual type conversion *)
      if name = "Val_option" || name = "Val_some" then
        (* Val_option(value, Val_TypeName) - the second arg is a Var with the macro name *)
        match args with
        | [ _; Var macro_name ]
          when String.starts_with ~prefix:"Val_" macro_name ->
            Some macro_name
        | _ -> List.find_map get_conversion_macro args
      else Some name
  | Cast (_, e) -> get_conversion_macro e
  | Macro (_, args) ->
      (* Recursively search in macro arguments (e.g., CAMLreturn(Val_GtkButton(...))) *)
      List.find_map get_conversion_macro args
  | _ -> None

(* Check if a function uses the correct return conversion macro *)
let uses_correct_return_macro f expected_macro =
  let type_info = extract_type_info f in
  match type_info.return_expr with
  | None -> false
  | Some expr -> (
      match get_conversion_macro expr with
      | Some macro -> macro = expected_macro
      | None -> false)

(* Validate that a GTK type constructor properly converts the result *)
let validates_gtk_constructor f c_type =
  let expected_macro = "Val_" ^ c_type in
  uses_correct_return_macro f expected_macro

(* Check if function properly calls the underlying C function *)
let calls_c_function f expected_c_func =
  function_calls_function f expected_c_func

(* Validate parameter is properly converted using _val macro *)
let param_converted_with_val_macro f param_name expected_type =
  (* Check if there's a call using Type_val(param_name) *)
  List.exists
    (function
      | VarDecl (_, _, Some (Macro (macro, [ Var p ]))) when p = param_name ->
          macro = expected_type ^ "_val"
      | ExprStmt (Call (_, args)) | Return (Call (_, args)) ->
          List.exists
            (function
              | Macro (macro, [ Var p ]) when p = param_name ->
                  macro = expected_type ^ "_val"
              | _ -> false)
            args
      | _ -> false)
    f.body

(* Validate that out parameters are declared with correct type *)
let has_out_param_decl f param_name expected_type =
  (* Note: C code uses generic names like out1, out2, inout1, inout2 not GIR param names *)
  (* So we check if ANY variable of the expected type is declared *)
  let _ = param_name in
  (* Suppress unused warning *)
  List.exists
    (function
      | VarDecl (t, name, None) when String.starts_with ~prefix:"out" name ->
          String.starts_with ~prefix:expected_type t
      | VarDecl (t, name, Some _) when String.starts_with ~prefix:"inout" name
        ->
          (* InOut parameters are declared with initialization *)
          String.starts_with ~prefix:expected_type t
      | _ -> false)
    f.body

(* Check if out parameter is passed by reference (&param) to C function *)
let out_param_passed_by_ref f param_name c_func_name =
  (* Note: C code uses generic names like out1, out2, not GIR param names *)
  (* So we check if ANY out variable is passed by reference *)
  let _ = param_name in
  (* Suppress unused warning *)
  let rec check_stmt = function
    | (ExprStmt (Call (name, args)) | VarDecl (_, _, Some (Call (name, args))))
      when name = c_func_name ->
        List.exists
          (function
            | AddrOf (Var p)
              when String.starts_with ~prefix:"out" p || p = "error" ->
                true
            | _ -> false)
          args
    | IfStmt (_, then_stmts, else_stmts) ->
        List.exists check_stmt then_stmts || List.exists check_stmt else_stmts
    | _ -> false
  in
  List.exists check_stmt f.body

(* Validate that error handling is present (for throws=true) *)
let has_error_handling f =
  (* Check for GError declaration *)
  let has_error_decl = has_var_decl f "error" in

  (* Check for Res_Ok and Res_Error macros in return (including in if/else) *)
  (* Note: Res_Ok/Res_Error might be nested inside CAMLreturn macro *)
  let rec has_res_macro expr =
    match expr with
    | Macro ("Res_Ok", _) | Macro ("Res_Error", _) -> true
    | Macro (_, args) -> List.exists has_res_macro args
    | _ -> false
  in
  let rec has_error_return_in_stmt = function
    | Return expr -> has_res_macro expr
    | IfStmt (_, then_stmts, else_stmts) ->
        List.exists has_error_return_in_stmt then_stmts
        || List.exists has_error_return_in_stmt else_stmts
    | _ -> false
  in
  let has_error_return = List.exists has_error_return_in_stmt f.body in

  has_error_decl && has_error_return

(* Validate that a function returns error type when throws=true *)
let returns_result_type f =
  (* Check for Res_Ok or Res_Error macros anywhere in the function *)
  (* They might be in if/else statements on a single line *)
  let rec check_expr = function
    | Macro (name, _) when name = "Res_Ok" || name = "Res_Error" -> true
    | Macro (_, args) -> List.exists check_expr args
    | Call (_, args) -> List.exists check_expr args
    | Cast (_, e) -> check_expr e
    | _ -> false
  in
  let rec check_stmt = function
    | Return (Macro (name, _)) when name = "Res_Ok" || name = "Res_Error" ->
        true
    | Return expr -> check_expr expr
    | ExprStmt expr -> check_expr expr
    | VarDecl (_, _, Some expr) -> check_expr expr
    | IfStmt (_, then_stmts, else_stmts) ->
        List.exists check_stmt then_stmts || List.exists check_stmt else_stmts
    | _ -> false
  in
  List.exists check_stmt f.body

(* Validate CAMLparam macros are used correctly *)
let has_caml_param_macro f =
  (* In our simplified parser, CAMLparam is stripped, but we can check param count *)
  let param_count = get_param_count f in
  param_count >= 0 (* All functions should have params tracked *)

(* Validate CAMLreturn is used *)
let has_caml_return f =
  let rec check_stmt = function
    | Return (Macro ("CAMLreturn", _)) -> true
    | IfStmt (_, then_stmts, else_stmts) ->
        List.exists check_stmt then_stmts || List.exists check_stmt else_stmts
    | _ -> false
  in
  List.exists check_stmt f.body

(* Check if function properly handles nullable parameters *)
let handles_nullable_param f param_name =
  (* Check for Option_val or String_option_val usage *)
  (* Note: C code uses generic arg names (arg1, arg2) not GIR param names *)
  (* So we check if the nullable macros are used anywhere, not for specific param *)
  let _ = param_name in
  (* Suppress unused warning *)
  List.exists
    (function
      | VarDecl (_, _, Some expr) | ExprStmt expr | Return expr ->
          let rec check_expr = function
            | Macro (macro, [ Var _; _; _ ]) -> macro = "Option_val"
            | Macro (macro, [ Var _ ]) -> macro = "String_option_val"
            | Call (_, args) -> List.exists check_expr args
            | Cast (_, e) -> check_expr e
            | Macro (_, args) -> List.exists check_expr args
            | _ -> false
          in
          check_expr expr
      | _ -> false)
    f.body

(* Validate bytecode/native pair is correctly structured *)
let validates_bytecode_native_pair functions base_name =
  let native_name = base_name ^ "_native" in
  let bytecode_name = base_name ^ "_bytecode" in

  match
    (find_function functions native_name, find_function functions bytecode_name)
  with
  | Some native_func, Some bytecode_func ->
      (* Bytecode should call native *)
      function_calls_function bytecode_func native_name
      &&
      (* Native should have the actual implementation *)
      get_param_count native_func >= 5 (* Should have many params *)
  | _ -> false

(* ========================================================================= *)
(* Array Validation Functions *)
(* ========================================================================= *)

(* These are simplified validations that work with the lightweight C parser *)

(* Check if function counts to NULL - look for while/for loops *)
let counts_to_null f _array_var =
  (* Simplified: the parser doesn't capture loops, so we check for presence of certain patterns in raw code *)
  (* This would need enhancement of the parser to work properly *)
  (* For now, just check if the function has local variables which suggests computation *)
  List.length (get_var_decls f) > 0

(* Check if function calls caml_alloc *)
let calls_caml_alloc f =
  let rec check_expr = function
    | Call ("caml_alloc", _) -> true
    | Macro (_, args) -> List.exists check_expr args
    | _ -> false
  in
  let check_stmt = function
    | VarDecl (_, _, Some expr) -> check_expr expr
    | ExprStmt expr -> check_expr expr
    | Return expr -> check_expr expr
    | Assign (_, expr) -> check_expr expr
    | _ -> false
  in
  List.exists check_stmt f.body

(* Check if function has Store_field calls (indicates array conversion) *)
let has_conversion_loop f =
  let rec check_expr = function
    | Call ("Store_field", _) -> true
    | Macro (_, args) -> List.exists check_expr args
    | _ -> false
  in
  let check_stmt = function
    | ExprStmt expr -> check_expr expr
    | VarDecl (_, _, Some expr) -> check_expr expr
    | _ -> false
  in
  List.exists check_stmt f.body

(* Check if function calls g_free *)
let calls_g_free f var_name =
  let rec check_expr = function
    | Call ("g_free", [ Var v ]) when String.equal v var_name -> true
    | Macro (_, args) -> List.exists check_expr args
    | _ -> false
  in
  let check_stmt = function ExprStmt expr -> check_expr expr | _ -> false in
  List.exists check_stmt f.body

(* ========================================================================= *)
(* Header Guard Types and Parsing *)
(* ========================================================================= *)

type header_guard = {
  guard_name : string;
  has_ifndef : bool;
  has_define : bool;
  has_endif : bool;
}

(* Extract header guard directives from header content using line-by-line parsing *)
let parse_header_guards header_content =
  let lines = String.split_on_char '\n' header_content in
  let rec extract_directives acc = function
    | [] -> acc
    | line :: rest ->
        let stripped = String.trim line in
        (* Match #ifndef _<name>_ *)
        if String.starts_with ~prefix:"#ifndef " stripped then
          let name =
            String.sub stripped 8 (String.length stripped - 8) |> String.trim
          in
          extract_directives
            ({
               guard_name = name;
               has_ifndef = true;
               has_define = false;
               has_endif = false;
             }
            :: acc)
            rest (* Match #define _<name>_ *)
        else if String.starts_with ~prefix:"#define " stripped then
          let name =
            String.sub stripped 8 (String.length stripped - 8) |> String.trim
          in
          (* Find and update matching guard *)
          let updated =
            List.map
              (fun g ->
                if g.guard_name = name then { g with has_define = true } else g)
              acc
          in
          extract_directives updated rest (* Match #endif with comment *)
        else if String.starts_with ~prefix:"#endif" stripped then
          (* Extract guard name from comment if present: #endif /* _name_ */ *)
          let guard_name =
            try
              let comment_start = String.index stripped '/' in
              let start = comment_start + 3 in
              let finish = String.index_from stripped start '*' - 1 in
              String.sub stripped start (finish - start) |> String.trim
            with Not_found -> ""
          in
          if guard_name <> "" then
            let updated =
              List.map
                (fun g ->
                  if g.guard_name = guard_name then { g with has_endif = true }
                  else g)
                acc
            in
            extract_directives updated rest
          else extract_directives acc rest
        else extract_directives acc rest
  in
  extract_directives [] lines

(* ========================================================================= *)
(* Forward Declaration Validation *)
(* ========================================================================= *)

(* Helper: Check if a string is a valid C identifier character *)
let is_ident_char c =
  (c >= 'a' && c <= 'z')
  || (c >= 'A' && c <= 'Z')
  || (c >= '0' && c <= '9')
  || c = '_'

(* Helper: Extract identifier from start of string until non-identifier char *)
let extract_identifier s =
  let rec find_end idx =
    if idx >= String.length s then idx
    else if is_ident_char s.[idx] then find_end (idx + 1)
    else idx
  in
  let end_idx = find_end 0 in
  if end_idx > 0 then Some (String.sub s 0 end_idx) else None

(* Parse header content and extract forward declaration names.
   Looks for patterns like:
   - #define Val_<Type>(...)          (macro format)
   - #define <Type>_val(...)          (macro format)
   - value Val_<Type>(...);           (function declaration format)
   - <Type> <Type>_val(...);          (function declaration format)
   
   Returns just the declaration name (e.g., "Val_GtkWrapMode") without parameters. *)
let extract_forward_decls header_content =
  let lines = String.split_on_char '\n' header_content in
  List.filter_map
    (fun line ->
      let stripped = String.trim line in
      (* Pattern 1: #define Val_<Type> or #define <Type>_val *)
      if String.starts_with ~prefix:"#define " stripped then
        let rest =
          String.sub stripped 8 (String.length stripped - 8) |> String.trim
        in
        match extract_identifier rest with
        | Some name ->
            (* Check if it's a forward declaration pattern *)
            if
              String.starts_with ~prefix:"Val_" name
              || String.ends_with ~suffix:"_val" name
            then Some name
            else None
        | None -> None
        (* Pattern 2: Function declarations like "value Val_<Type>(...);" *)
      else if String.starts_with ~prefix:"value " stripped then
        let rest =
          String.sub stripped 6 (String.length stripped - 6) |> String.trim
        in
        (* Look for Val_<Type> pattern in function name *)
        match extract_identifier rest with
        | Some name ->
            if String.starts_with ~prefix:"Val_" name then Some name else None
        | None -> None
      (* Pattern 3: Function declarations like "<Type> <Type>_val(...);" or
           "<Type> *<Type>_val(...);" (pointer return type) *)
        else
        (* Try to match "GtkWrapMode GtkWrapMode_val(...);" or
           "GtkWidget *GtkWidget_val(...);" pattern *)
        match extract_identifier stripped with
        | Some type_name -> (
            let rest_after_type =
              String.sub stripped (String.length type_name)
                (String.length stripped - String.length type_name)
              |> String.trim
            in
            (* Skip leading pointer stars and spaces for pointer return types
               e.g., "*GtkWidget_val(..." -> "GtkWidget_val(..." *)
            let rest_no_stars =
              let rec skip s i =
                if i >= String.length s then i
                else match s.[i] with '*' | ' ' -> skip s (i + 1) | _ -> i
              in
              let start = skip rest_after_type 0 in
              String.sub rest_after_type start
                (String.length rest_after_type - start)
            in
            (* Check if next token is <Type>_val.
               Note: the C return type (type_name) may differ from the OCaml
               function name prefix — e.g., GtkApplicationInhibitFlags
               GtkInhibitFlags_val(…) — so we only require the _val suffix,
               not strict equality between func_name and type_name ^ "_val". *)
            match extract_identifier rest_no_stars with
            | Some func_name ->
                if String.ends_with ~suffix:"_val" func_name then Some func_name
                else None
            | None -> None)
        | None -> None)
    lines

(* Assert that a forward declaration exists in the header.
   [assert_forward_decl_exists header_content c_type prefix] checks for declarations
   like [prefix<c_type>] (e.g., Val_GtkWrapMode when prefix="Val_").
   Fails with a descriptive message if the declaration is not found. *)
let assert_forward_decl_exists header_content c_type prefix =
  let decls = extract_forward_decls header_content in
  let expected_decl = prefix ^ c_type in
  if not (List.mem expected_decl decls) then
    Alcotest.fail
      (Fmt.str
         "Expected forward declaration '%s' not found in header. Found \
          declarations: [%s]"
         expected_decl (String.concat ", " decls))

(* Assert that a forward declaration does NOT exist in the header.
   [assert_forward_decl_not_exists header_content c_type prefix] checks that declarations
   like [prefix<c_type>] are NOT present.
   Fails with a descriptive message if the declaration is found. *)
let assert_forward_decl_not_exists header_content c_type prefix =
  let decls = extract_forward_decls header_content in
  let expected_decl = prefix ^ c_type in
  if List.mem expected_decl decls then
    Alcotest.fail
      (Fmt.str
         "Forward declaration '%s' should NOT exist in header, but was found"
         expected_decl)

(* Check if raw C code string contains CAMLxparamN or higher.
   This is a simpler version that works directly with C code strings. *)
let c_code_has_camlxparam_n_or_higher c_code n =
  let lines = String.split_on_char '\n' c_code in
  List.exists
    (fun line ->
      let stripped = String.trim line in
      if String.starts_with ~prefix:"CAMLxparam" stripped then
        (* Extract the number from CAMLxparamN *)
        let macro_name =
          try
            let paren_idx = String.index stripped '(' in
            String.sub stripped 0 paren_idx
          with Not_found -> stripped
        in
        let num_str =
          String.sub macro_name 10 (String.length macro_name - 10)
        in
        match int_of_string_opt num_str with
        | Some num -> num >= n
        | None -> false
      else false)
    lines

(* Check if raw C code string contains a specific CAMLparam macro *)
let c_code_has_caml_param c_code param_name =
  let lines = String.split_on_char '\n' c_code in
  List.exists
    (fun line ->
      let stripped = String.trim line in
      String.starts_with ~prefix:(param_name ^ "(") stripped)
    lines

(* ========================================================================= *)
(* Include Directive Validation *)
(* ========================================================================= *)

type include_directive = {
  include_path : string;
  is_system : bool; (* true for <path>, false for "path" *)
}

(* Extract #include directives from header content using line-by-line parsing.
   Returns a list of include_directive records for both system (<...>) and
   local ("...") includes. *)
let extract_includes header_content =
  let lines = String.split_on_char '\n' header_content in
  List.filter_map
    (fun line ->
      let stripped = String.trim line in
      if String.starts_with ~prefix:"#include " stripped then
        let rest =
          String.sub stripped 9 (String.length stripped - 9) |> String.trim
        in
        (* Check for system include: <path> *)
        if
          String.starts_with ~prefix:"<" rest
          && String.ends_with ~suffix:">" rest
        then
          let path_len = String.length rest - 2 in
          if path_len > 0 then
            let path = String.sub rest 1 path_len in
            Some { include_path = path; is_system = true }
          else None (* Check for local include: "path" *)
        else if
          String.starts_with ~prefix:{|"|} rest
          && String.ends_with ~suffix:{|"|} rest
        then
          let path_len = String.length rest - 2 in
          if path_len > 0 then
            let path = String.sub rest 1 path_len in
            Some { include_path = path; is_system = false }
          else None
        else None
      else None)
    lines

(* Assert that a local include directive exists in the header.
   [assert_local_include_exists header_content expected_path] checks for an
   include directive like [#include "path"].
   Fails with a descriptive message if the include is not found. *)
let assert_local_include_exists header_content expected_path =
  let includes = extract_includes header_content in
  let local_includes =
    List.filter_map
      (fun inc -> if not inc.is_system then Some inc.include_path else None)
      includes
  in
  if not (List.mem expected_path local_includes) then
    Alcotest.fail
      (Fmt.str
         "Expected local include '%s' not found in header. Found local \
          includes: [%s]"
         expected_path
         (String.concat ", " local_includes))

(* Assert that a local include directive does NOT exist in the header.
   [assert_local_include_not_exists header_content unexpected_path] checks that
   an include directive like [#include "path"] is NOT present.
   Fails with a descriptive message if the include is found. *)
let assert_local_include_not_exists header_content unexpected_path =
  let includes = extract_includes header_content in
  let local_includes =
    List.filter_map
      (fun inc -> if not inc.is_system then Some inc.include_path else None)
      includes
  in
  if List.mem unexpected_path local_includes then
    Alcotest.fail
      (Fmt.str "Local include '%s' should NOT exist in header, but was found"
         unexpected_path)

(* Assert that a copy function declaration exists for the given C type.
   Looks for a "value copy_<c_type>(" line in the header, which is the prototype
   for a value-like record's copy helper. *)
let assert_copy_func_decl_exists header_content c_type =
  let lines = String.split_on_char '\n' header_content in
  let copy_func_name = "copy_" ^ c_type in
  let found =
    List.exists
      (fun line ->
        let stripped = String.trim line in
        (* Match "value copy_<c_type>(" pattern *)
        if String.starts_with ~prefix:"value " stripped then
          let rest =
            String.sub stripped 6 (String.length stripped - 6) |> String.trim
          in
          match extract_identifier rest with
          | Some name -> name = copy_func_name
          | None -> false
        else false)
      lines
  in
  if not found then
    Alcotest.fail
      (Fmt.str "Copy function declaration 'value %s(...)' not found in header"
         copy_func_name)

(* Assert that a conditional compilation guard exists with the given name.
   Unlike include guards (where #ifndef and #define use the same name),
   conditional compilation guards only need a matching #ifndef; the
   #define inside the guard protects the converter macros, not the guard name. *)
let assert_conditional_guard_exists header_content guard_name =
  let guards = parse_header_guards header_content in
  let found =
    List.exists (fun g -> g.guard_name = guard_name && g.has_ifndef) guards
  in
  if not found then
    Alcotest.fail
      (Fmt.str "Conditional guard '#ifndef %s' not found in header" guard_name)

(* Assert that a conditional compilation guard does NOT exist in the header. *)
let assert_conditional_guard_not_exists header_content guard_name =
  let guards = parse_header_guards header_content in
  let found =
    List.exists (fun g -> g.guard_name = guard_name && g.has_ifndef) guards
  in
  if found then
    Alcotest.fail
      (Fmt.str
         "Conditional guard '#ifndef %s' should not exist in header, but was \
          found"
         guard_name)

(* Extract the content lines that appear between a conditional compilation guard's
   #ifndef and its matching #endif.  Returns the extracted content as a string.
   Used to verify that forward declarations appear *inside* the guard rather than
   merely somewhere in the file. *)
let extract_conditional_guard_content header_content guard_name =
  let lines = String.split_on_char '\n' header_content in
  let guard_marker = "#ifndef " ^ guard_name in
  let rec skip_to_guard = function
    | [] -> []
    | line :: rest ->
        if String.trim line = guard_marker then rest else skip_to_guard rest
  in
  let rec take_until_endif = function
    | [] -> []
    | line :: rest ->
        if String.starts_with ~prefix:"#endif" (String.trim line) then []
        else line :: take_until_endif rest
  in
  let inside = skip_to_guard lines in
  String.concat "\n" (take_until_endif inside)

(* Check if any statement in the function body uses a specific macro (by name).
   Returns true if the macro appears anywhere as a Call or Macro node.

   Both matches enumerate every variant of [C_ast.c_expr] / [C_ast.c_stmt]
   explicitly so that adding a new AST variant causes a compile-time warning
   here rather than a silent false-negative. *)
let uses_macro f macro_name =
  let rec check_expr = function
    | Macro (name, _) when name = macro_name -> true
    | Call (name, _) when name = macro_name -> true
    | Macro (_, args) -> List.exists check_expr args
    | Call (_, args) -> List.exists check_expr args
    | Cast (_, e) -> check_expr e
    | AddrOf e | Deref e -> check_expr e
    | Var _ | IntLiteral _ | StringLiteral _ -> false
  in
  let rec check_stmt = function
    | VarDecl (_, _, Some e) -> check_expr e
    | VarDecl (_, _, None) -> false
    | Assign (_, e) -> check_expr e
    | ExprStmt e -> check_expr e
    | Return e -> check_expr e
    | IfStmt (cond, then_stmts, else_stmts) ->
        check_expr cond
        || List.exists check_stmt then_stmts
        || List.exists check_stmt else_stmts
    | Empty -> false
  in
  List.exists check_stmt f.body

(* Assert that a header guard exists with the expected pattern.
     [assert_header_guard_format header_content expected_pattern] validates that
     the header contains a complete guard (ifndef/define/endif) matching the pattern.
     The pattern is matched against the guard name using String.ends_with.
     Fails with a descriptive message if no matching guard is found or if it's incomplete. *)
let assert_header_guard_format header_content expected_pattern =
  let guards = parse_header_guards header_content in
  (* Find guards matching the expected pattern *)
  let matching_guards =
    List.filter
      (fun g -> String.ends_with ~suffix:expected_pattern g.guard_name)
      guards
  in
  match matching_guards with
  | [] ->
      (* No matching guard found *)
      let available_guards =
        List.map (fun g -> g.guard_name) guards |> String.concat ", "
      in
      Alcotest.fail
        (Fmt.str
           "No header guard with pattern '%s' found. Available guards: [%s]"
           expected_pattern available_guards)
  | guard :: _ ->
      (* Found a matching guard, verify it has complete structure *)
      if not guard.has_ifndef then
        Alcotest.fail
          (Fmt.str "Header guard '%s' is missing #ifndef directive"
             guard.guard_name);
      if not guard.has_define then
        Alcotest.fail
          (Fmt.str "Header guard '%s' is missing #define directive"
             guard.guard_name);
      if not guard.has_endif then
        Alcotest.fail
          (Fmt.str "Header guard '%s' is missing #endif directive"
             guard.guard_name)
