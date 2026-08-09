(* Lightweight C parser for generated stub code *)

open C_ast

(* Simple regex-based parser for our generated C patterns *)

let strip str = String.trim str

(* Parse a C type from a string (handles pointers) *)
let parse_c_type type_str = strip type_str

(* Extract function signature: "value func_name(value arg1, value arg2)" *)
(* Only match if the line looks like a function definition, not a call *)
let parse_function_signature line =
  let line_stripped = strip line in

  (* Skip lines that look like function calls (contain 'return', assignments, etc.) *)
  if
    String.contains line_stripped ';'
    || String.contains line_stripped '='
    || Re.Str.string_match (Re.Str.regexp ".*return ") line_stripped 0
  then None
  else
    let pattern =
      Re.Str.regexp
        {|^\([a-zA-Z_][a-zA-Z0-9_* ]*\) \([a-zA-Z_][a-zA-Z0-9_]*\)(\([^)]*\))$|}
    in
    if Re.Str.string_match pattern line_stripped 0 then
      let return_type = strip (Re.Str.matched_group 1 line_stripped) in
      let name = strip (Re.Str.matched_group 2 line_stripped) in
      let params_str = strip (Re.Str.matched_group 3 line_stripped) in

      (* Parse parameters *)
      let params =
        if params_str = "" || params_str = "void" then []
        else
          String.split_on_char ',' params_str
          |> List.map strip
          |> List.filter_map (fun param_str ->
              (* Match "type name" pattern *)
              let parts =
                String.split_on_char ' ' param_str |> List.filter (( <> ) "")
              in
              match List.rev parts with
              | name :: rest_rev ->
                  let param_type = String.concat " " (List.rev rest_rev) in
                  Some { param_type; param_name = name }
              | [] -> None)
      in
      Some (return_type, name, params)
    else None

(* Parse a simple expression (variable, literal, function call, macro) *)
let rec parse_expr str =
  let str = strip str in

  (* Handle string literals *)
  if String.length str > 0 && str.[0] = '"' then StringLiteral str
    (* Handle integer literals *)
  else if String.length str > 0 && str.[0] >= '0' && str.[0] <= '9' then
    match int_of_string_opt str with Some n -> IntLiteral n | None -> Var str
    (* Handle NULL *)
  else if str = "NULL" then IntLiteral 0 (* Handle &variable *)
  else if String.length str > 1 && str.[0] = '&' then
    AddrOf (parse_expr (String.sub str 1 (String.length str - 1)))
    (* Handle *variable *)
  else if String.length str > 1 && str.[0] = '*' then
    Deref (parse_expr (String.sub str 1 (String.length str - 1)))
    (* Handle casts: (type)expr *)
  else if String.contains str '(' && String.contains str ')' then
    let paren_start = String.index str '(' in
    if paren_start = 0 then
      (* Could be a cast or function call *)
      try
        let paren_end = String.index str ')' in
        let inside = String.sub str 1 (paren_end - 1) in
        let rest =
          String.sub str (paren_end + 1) (String.length str - paren_end - 1)
        in

        (* Check if it looks like a function call (has another '(' after ')') *)
        if String.contains rest '(' then
          (* It's a function call *)
          parse_function_call str
        else if rest <> "" then
          (* It's a cast *)
          Cast (parse_c_type inside, parse_expr rest)
        else
          (* Just parentheses around expression *)
          parse_expr inside
      with Not_found -> Var str
    else
      (* Function call or macro *)
      parse_function_call str
  else
    (* Simple variable *)
    Var str

and parse_function_call str =
  let str = strip str in
  try
    let paren_idx = String.index str '(' in
    let func_name = strip (String.sub str 0 paren_idx) in

    (* Find matching closing paren *)
    let rec find_matching_paren s start depth =
      if start >= String.length s then raise Not_found
      else
        match s.[start] with
        | '(' -> find_matching_paren s (start + 1) (depth + 1)
        | ')' ->
            if depth = 1 then start
            else find_matching_paren s (start + 1) (depth - 1)
        | _ -> find_matching_paren s (start + 1) depth
    in

    let paren_end = find_matching_paren str paren_idx 0 in
    let args_str = String.sub str (paren_idx + 1) (paren_end - paren_idx - 1) in

    (* Parse arguments (simple split by comma for now) *)
    let args =
      if strip args_str = "" then []
      else
        String.split_on_char ',' args_str
        |> List.map (fun arg -> parse_expr (strip arg))
    in

    (* Check if it's a known macro *)
    if
      String.starts_with ~prefix:"CAMLreturn" func_name
      || String.starts_with ~prefix:"Val_" func_name
      || String.starts_with ~prefix:"Res_" func_name
      || String.ends_with ~suffix:"_val" func_name
    then Macro (func_name, args)
    else Call (func_name, args)
  with Not_found -> Var str

(* Helper to separate pointer stars from variable names *)
let separate_pointer_from_name name =
  let rec count_stars s idx =
    if idx >= String.length s then idx
    else if s.[idx] = '*' then count_stars s (idx + 1)
    else idx
  in
  let star_count = count_stars name 0 in
  if star_count > 0 then
    let stars = String.make star_count '*' in
    let actual_name =
      String.sub name star_count (String.length name - star_count)
    in
    (stars, actual_name)
  else ("", name)

(* Helper to separate array dimension from variable name.
   "out1[8]" -> ("out1", "[8]") *)
let separate_array_from_name name =
  try
    let bracket_idx = String.index name '[' in
    let actual_name = String.sub name 0 bracket_idx in
    let array_dim =
      String.sub name bracket_idx (String.length name - bracket_idx)
    in
    (actual_name, Some array_dim)
  with Not_found -> (name, None)

(* Parse a variable declaration: "Type name = value;" or "Type name[N];" or "Type name;" *)
let parse_var_decl line =
  let line = strip line in

  (* Remove trailing semicolon *)
  let line =
    if String.ends_with ~suffix:";" line then
      String.sub line 0 (String.length line - 1)
    else line
  in

  (* Check for assignment *)
  if String.contains line '=' then
    let parts = String.split_on_char '=' line in
    match parts with
    | [ left; right ] -> (
        let left = strip left in
        let right = strip right in
        (* Parse left side as "type name" *)
        let words = String.split_on_char ' ' left |> List.filter (( <> ) "") in
        match List.rev words with
        | name :: rest_rev ->
            let stars, actual_name_with_array =
              separate_pointer_from_name name
            in
            let actual_name, array_dim =
              separate_array_from_name actual_name_with_array
            in
            (* Include array dimension in type if present *)
            let var_type =
              String.concat " " (List.rev rest_rev)
              ^ stars
              ^ match array_dim with Some d -> d | None -> ""
            in
            Some (VarDecl (var_type, actual_name, Some (parse_expr right)))
        | [] -> None)
    | _ -> None
  else
    (* No assignment - could be simple decl or array decl *)
    let words = String.split_on_char ' ' line |> List.filter (( <> ) "") in
    match List.rev words with
    | name :: rest_rev ->
        let stars, actual_name_with_array = separate_pointer_from_name name in
        let actual_name, array_dim =
          separate_array_from_name actual_name_with_array
        in
        (* Include array dimension in type if present *)
        let var_type =
          String.concat " " (List.rev rest_rev)
          ^ stars
          ^ match array_dim with Some d -> d | None -> ""
        in
        Some (VarDecl (var_type, actual_name, None))
    | [] -> None

(* Parse an assignment: "var = value;" *)
let parse_assignment line =
  let line = strip line in

  (* Remove trailing semicolon *)
  let line =
    if String.ends_with ~suffix:";" line then
      String.sub line 0 (String.length line - 1)
    else line
  in

  if String.contains line '=' then
    let parts = String.split_on_char '=' line in
    match parts with
    | [ left; right ] -> Some (Assign (strip left, parse_expr (strip right)))
    | _ -> None
  else None

(* Check if a line contains a return statement *)
let has_return line =
  let line = strip line in
  String.length line >= 6
  && (String.sub line 0 6 = "return"
     || Re.Str.string_match (Re.Str.regexp "CAMLreturn") line 0)

(* Parse a return statement *)
let parse_return line =
  let line = strip line in

  (* Remove trailing semicolon *)
  let line =
    if String.ends_with ~suffix:";" line then
      String.sub line 0 (String.length line - 1)
    else line
  in

  if Re.Str.string_match (Re.Str.regexp "CAMLreturn(\\(.*\\))") line 0 then
    let expr_str = Re.Str.matched_group 1 line in
    Some (Return (Macro ("CAMLreturn", [ parse_expr expr_str ])))
  else if Re.Str.string_match (Re.Str.regexp "return \\(.*\\)") line 0 then
    let expr_str = Re.Str.matched_group 1 line in
    Some (Return (parse_expr expr_str))
  else None

(* Parse condition from if statement: "if (condition)" -> "condition" *)
let parse_condition str =
  let str = strip str in
  if Re.Str.string_match (Re.Str.regexp "if *(\\(.*\\))") str 0 then
    let cond = Re.Str.matched_group 1 str in
    Some (parse_expr cond)
  else None

(* Parse a single-line if/else statement *)
let rec parse_if_else line =
  let line = strip line in

  (* Match: if (condition) statement; else statement; *)
  (* We need to find the 'else' keyword that's not inside parentheses *)
  let rec find_else_pos str pos depth =
    if pos >= String.length str then None
    else if pos + 4 <= String.length str then
      let c = str.[pos] in
      match c with
      | '(' -> find_else_pos str (pos + 1) (depth + 1)
      | ')' -> find_else_pos str (pos + 1) (depth - 1)
      | 'e' when depth = 0 && String.sub str pos 4 = "else" ->
          (* Check if it's a word boundary *)
          let is_start =
            pos = 0
            || not
                 (String.contains
                    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_"
                    str.[pos - 1])
          in
          let is_end =
            pos + 4 >= String.length str
            || not
                 (String.contains
                    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_"
                    str.[pos + 4])
          in
          if is_start && is_end then Some pos
          else find_else_pos str (pos + 1) depth
      | _ -> find_else_pos str (pos + 1) depth
    else find_else_pos str (pos + 1) depth
  in

  if
    String.starts_with ~prefix:"if " line
    || String.starts_with ~prefix:"if(" line
  then
    (* Find the end of the condition *)
    try
      let cond_start = String.index line '(' in
      let rec find_matching_paren s start depth =
        if start >= String.length s then raise Not_found
        else
          match s.[start] with
          | '(' -> find_matching_paren s (start + 1) (depth + 1)
          | ')' ->
              if depth = 1 then start
              else find_matching_paren s (start + 1) (depth - 1)
          | _ -> find_matching_paren s (start + 1) depth
      in
      let cond_end = find_matching_paren line cond_start 0 in
      let condition_str = String.sub line 0 (cond_end + 1) in
      let rest =
        strip
          (String.sub line (cond_end + 1) (String.length line - cond_end - 1))
      in

      match parse_condition condition_str with
      | None -> None
      | Some cond -> (
          (* Check if there's an else clause *)
          match find_else_pos rest 0 0 with
          | Some else_pos ->
              (* Split into then and else parts *)
              let then_part = strip (String.sub rest 0 else_pos) in
              let else_part =
                strip
                  (String.sub rest (else_pos + 4)
                     (String.length rest - else_pos - 4))
              in

              (* Remove trailing semicolons from each part *)
              let then_part =
                if String.ends_with ~suffix:";" then_part then
                  String.sub then_part 0 (String.length then_part - 1) |> strip
                else then_part
              in
              let else_part =
                if String.ends_with ~suffix:";" else_part then
                  String.sub else_part 0 (String.length else_part - 1) |> strip
                else else_part
              in

              (* Parse the then and else statements *)
              let then_stmt =
                match parse_statement then_part with
                | Some stmt -> [ stmt ]
                | None -> []
              in
              let else_stmt =
                match parse_statement else_part with
                | Some stmt -> [ stmt ]
                | None -> []
              in

              Some (IfStmt (cond, then_stmt, else_stmt))
          | None ->
              (* No else clause - just if *)
              let then_part = strip rest in
              let then_part =
                if String.ends_with ~suffix:";" then_part then
                  String.sub then_part 0 (String.length then_part - 1) |> strip
                else then_part
              in

              let then_stmt =
                match parse_statement then_part with
                | Some stmt -> [ stmt ]
                | None -> []
              in

              Some (IfStmt (cond, then_stmt, [])))
    with Not_found -> None
  else None

(* Parse a single statement from a line *)
and parse_statement line =
  let line_stripped = strip line in

  if line_stripped = "" || line_stripped = "{" || line_stripped = "}" then
    Some Empty
  else if
    String.starts_with ~prefix:"if " line_stripped
    || String.starts_with ~prefix:"if(" line_stripped
  then parse_if_else line_stripped
  else if has_return line_stripped then parse_return line_stripped
  else if String.contains line_stripped '=' then
    (* Could be var decl or assignment *)
    (* Use heuristics to detect variable declarations:
       - Type name followed by variable name followed by '='
       - Type names typically start with uppercase or are common types
       - But exclude known function/macro names that start with uppercase *)
    let words =
      String.split_on_char ' ' line_stripped |> List.filter (( <> ) "")
    in
    let known_uppercase_functions =
      [ "Store_field"; "CAMLlocal"; "CAMLparam"; "CAMLreturn"; "CAMLxparam" ]
    in
    let looks_like_type_name s =
      (* Type names often start with uppercase (PangoRectangle, GtkWidget)
         or are common C types (int, char, void, etc.)
         But not known function names like Store_field
         Note: s might include trailing ( from function calls, so check prefix *)
      String.length s > 0
      &&
      let base_name =
        try String.sub s 0 (String.index s '(') with Not_found -> s
      in
      (not (List.mem base_name known_uppercase_functions))
      && ((s.[0] >= 'A' && s.[0] <= 'Z')
         ||
         (* Starts with uppercase *)
         List.mem s
           [
             "value";
             "int";
             "char";
             "void";
             "GError";
             "gboolean";
             "gint";
             "const";
             "guint";
             "float";
             "double";
           ])
    in
    match words with
    | first :: _ when looks_like_type_name first -> parse_var_decl line_stripped
    | _ :: second :: _ when String.equal second "*" ->
        (* Pointer type: "Type *name = ..." *)
        parse_var_decl line_stripped
    | _ :: "const" :: _ :: _ when String.contains line_stripped '=' ->
        (* const type: "const Type name = ..." *)
        parse_var_decl line_stripped
    | _ -> parse_assignment line_stripped
  else if String.contains line_stripped ' ' then
    (* Might be a variable declaration without initialization *)
    let words =
      String.split_on_char ' ' line_stripped |> List.filter (( <> ) "")
    in
    let known_uppercase_functions =
      [ "Store_field"; "CAMLlocal"; "CAMLparam"; "CAMLreturn"; "CAMLxparam" ]
    in
    let looks_like_type_name s =
      String.length s > 0
      &&
      let base_name =
        try String.sub s 0 (String.index s '(') with Not_found -> s
      in
      (not (List.mem base_name known_uppercase_functions))
      && ((s.[0] >= 'A' && s.[0] <= 'Z')
         || String.ends_with ~suffix:"_t" s
         ||
         (* C typedef convention: graphene_vec3_t, etc. *)
         List.mem s
           [
             "value";
             "int";
             "char";
             "void";
             "GError";
             "gboolean";
             "gint";
             "const";
             "guint";
             "float";
             "double";
           ])
    in
    match words with
    | first :: _ :: _ when looks_like_type_name first ->
        parse_var_decl line_stripped
    | _ ->
        (* Expression statement *)
        Some (ExprStmt (parse_expr line_stripped))
  else
    (* Simple expression *)
    Some (ExprStmt (parse_expr line_stripped))

(* Parse a complete C file into our AST *)

(** Parse a complete C source string into a list of functions, flagging
    native/bytecode pairs. *)
let parse_c_code code =
  let lines = String.split_on_char '\n' code in

  (* Simple state machine to track function boundaries *)
  let rec parse_functions lines current_func funcs =
    match lines with
    | [] -> (
        match current_func with
        | Some (ret_type, name, params, body) ->
            let f =
              {
                return_type = ret_type;
                name;
                params;
                body;
                has_bytecode_variant = false;
              }
            in
            f :: funcs
        | None -> funcs)
    | line :: rest -> (
        let line_stripped = strip line in
        (* Strip trailing "{" that appears on same line as function signature
           (e.g., enum converter functions: "value Val_Foo(Bar val) {") *)
        let line_for_sig =
          if
            String.length line_stripped > 0
            && line_stripped.[String.length line_stripped - 1] = '{'
          then
            String.sub line_stripped 0 (String.length line_stripped - 1)
            |> strip
          else line_stripped
        in

        (* Check if this is a function signature line *)
        match parse_function_signature line_for_sig with
        | Some (ret_type, name, params) ->
            (* Save previous function if any *)
            let funcs =
              match current_func with
              | Some (old_ret, old_name, old_params, old_body) ->
                  let f =
                    {
                      return_type = old_ret;
                      name = old_name;
                      params = old_params;
                      body = old_body;
                      has_bytecode_variant = false;
                    }
                  in
                  f :: funcs
              | None -> funcs
            in
            (* Start new function *)
            parse_functions rest (Some (ret_type, name, params, [])) funcs
        | None -> (
            (* Check for function body content *)
            match current_func with
            | Some (ret_type, name, params, body) ->
                (* Parse the statement *)
                let new_stmt = parse_statement line_stripped in

                let new_body =
                  match new_stmt with
                  | Some stmt -> body @ [ stmt ]
                  | None -> body
                in

                parse_functions rest
                  (Some (ret_type, name, params, new_body))
                  funcs
            | None -> parse_functions rest None funcs))
  in

  let functions = parse_functions lines None [] |> List.rev in

  (* Post-process to detect bytecode/native pairs *)
  let functions =
    List.map
      (fun f ->
        let has_bytecode =
          List.exists
            (fun other ->
              other.name = f.name ^ "_bytecode"
              || String.ends_with ~suffix:"_native" f.name
                 && other.name
                    = Re.Str.replace_first (Re.Str.regexp "_native$")
                        "_bytecode" f.name)
            functions
        in
        { f with has_bytecode_variant = has_bytecode })
      functions
  in

  functions

(* Helper: check if function calls another function *)
let function_calls_in_code func_code target_name =
  String.split_on_char '\n' func_code
  |> List.exists (fun line ->
      let line = strip line in
      String.contains line '('
      && (Re.Str.string_match (Re.Str.regexp (target_name ^ "(")) line 0
         || Re.Str.string_match
              (Re.Str.regexp (".* " ^ target_name ^ "("))
              line 0))
