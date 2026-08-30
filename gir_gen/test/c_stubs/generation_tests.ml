(* C Stub Generation Tests - validates generated C code using lightweight parser *)

open Type_factory
open C_validation

(* ========================================================================= *)
(* Lightweight Parser Helper Functions *)
(* ========================================================================= *)

(* Parse C code string and return our AST *)
let parse_c_string c_code = C_parser.parse_c_code c_code

(* ========================================================================= *)
(* Header Guard Parsing for AST-Based Validation *)
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

(* Find a header guard by name pattern *)
let find_header_guard guards suffix =
  List.find_opt (fun g -> String.ends_with ~suffix g.guard_name) guards

(* Check if header contains old naming pattern *)
let contains_old_naming header_content =
  let guards = parse_header_guards header_content in
  List.exists
    (fun g ->
      String.ends_with ~suffix:"_generated_forward_decls_h_" g.guard_name
      || String.ends_with ~suffix:"_generated_forward_decls_h" g.guard_name)
    guards

(* Find a function by name *)
let find_function functions name = C_ast.find_function functions name

(* Check if a function exists *)
let assert_function_exists functions name =
  if Option.is_none (find_function functions name) then
    let available = List.map (fun f -> f.C_ast.name) functions in
    Alcotest.fail
      (Fmt.str "Function '%s' not found. Available: %s" name
         (String.concat ", " available))

(* Get function name *)
let get_function_name f = f.C_ast.name

(* Count parameters *)
let count_function_params f = C_ast.get_param_count f

(* Check if function has return statement *)
let has_return_statement f = C_ast.has_return_stmt f.C_ast.body

(* ========================================================================= *)
(* Test Context Setup *)
(* ========================================================================= *)

(* Use the shared helper from Helpers module *)
let create_test_context = Helpers.create_test_context

(* ========================================================================= *)
(* Constructor Generation Tests *)
(* ========================================================================= *)

let test_simple_constructor () =
  let ctx = create_test_context () in
  let ctor =
    make_gir_constructor ~ctor_name:"new" ~c_identifier:"gtk_button_new" ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_constructor.generate_c_constructor ~ctx
      ~c_type:"GtkButton" ~class_name:"Button" ctor
  in

  (* Parse the generated C code *)
  let functions = parse_c_string c_code in

  (* Should have exactly one function *)
  Alcotest.(check int) "Should generate one function" 1 (List.length functions);

  (* Function should be named ml_gtk_button_new *)
  assert_function_exists functions "ml_gtk_button_new";

  (* Function should have a return statement *)
  let func =
    Helpers.assert_some_value "ml_gtk_button_new"
      (find_function functions "ml_gtk_button_new")
  in
  Alcotest.(check bool)
    "Should have return statement" true
    (has_return_statement func)

let test_constructor_with_params () =
  let ctx = create_test_context () in
  let ctor =
    make_gir_constructor ~ctor_name:"new_with_label"
      ~c_identifier:"gtk_button_new_with_label"
      ~ctor_parameters:[ make_string_param ~param_name:"label" () ]
      ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_constructor.generate_c_constructor ~ctx
      ~c_type:"GtkButton" ~class_name:"Button" ctor
  in

  let functions = parse_c_string c_code in

  assert_function_exists functions "ml_gtk_button_new_with_label";

  let func =
    Helpers.assert_some_value "ml_gtk_button_new_with_label"
      (find_function functions "ml_gtk_button_new_with_label")
  in
  let param_count = count_function_params func in

  (* Should have 1 parameter (label) *)
  Alcotest.(check int) "Should have 1 parameter" 1 param_count

let test_constructor_many_params () =
  let ctx = create_test_context () in

  (* Create constructor with 6 parameters to trigger bytecode/native split *)
  let params =
    List.init 6 (fun i ->
        make_int_param ~param_name:(Fmt.str "arg%d" (i + 1)) ())
  in

  let ctor =
    make_gir_constructor ~ctor_name:"new_complex"
      ~c_identifier:"gtk_widget_new_complex" ~ctor_parameters:params ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_constructor.generate_c_constructor ~ctx
      ~c_type:"GtkWidget" ~class_name:"Widget" ctor
  in

  let functions = parse_c_string c_code in

  (* Should generate 2 functions: _native and _bytecode *)
  Alcotest.(check int)
    "Should generate 2 functions (native + bytecode)" 2 (List.length functions);

  assert_function_exists functions "ml_gtk_widget_new_complex_native";
  assert_function_exists functions "ml_gtk_widget_new_complex_bytecode"

(* ========================================================================= *)
(* Method Generation Tests *)
(* ========================================================================= *)

let test_simple_method () =
  let meth =
    make_gir_method ~method_name:"set_label"
      ~c_identifier:"gtk_button_set_label" ~return_type:void_type
      ~parameters:[ make_string_param ~param_name:"label" () ]
      ()
  in

  let func =
    Helpers.generate_and_find_c_method ~c_type:"GtkButton" ~class_name:"Button"
      meth
  in
  let param_count = count_function_params func in

  (* Should have 2 parameters: self + label *)
  Alcotest.(check int) "Should have 2 parameters (self + label)" 2 param_count

let test_method_with_return_value () =
  let meth =
    make_gir_method ~method_name:"get_label"
      ~c_identifier:"gtk_button_get_label" ~return_type:utf8_type ()
  in

  let func =
    Helpers.generate_and_find_c_method ~c_type:"GtkButton" ~class_name:"Button"
      meth
  in

  (* Should have a return statement *)
  Alcotest.(check bool)
    "Should have return statement" true
    (has_return_statement func)

let test_method_many_params () =
  let ctx = create_test_context () in

  (* Create method with 6 parameters to trigger bytecode/native split *)
  (* Note: methods have implicit 'self' parameter, so 6 in-parameters = 7 total *)
  let params =
    List.init 6 (fun i ->
        make_int_param ~param_name:(Fmt.str "arg%d" (i + 1)) ())
  in

  let meth =
    make_gir_method ~method_name:"process_many"
      ~c_identifier:"gtk_widget_process_many" ~return_type:void_type
      ~parameters:params ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_method.generate_c_method ~ctx
      ~c_type:"GtkWidget" meth "Widget"
  in

  let functions = parse_c_string c_code in

  (* Should generate 2 functions: _native and _bytecode *)
  Alcotest.(check int)
    "Should generate 2 functions (native + bytecode)" 2 (List.length functions);

  assert_function_exists functions "ml_gtk_widget_process_many_native";
  assert_function_exists functions "ml_gtk_widget_process_many_bytecode"

let test_method_camlxparam_chunking () =
  let ctx = create_test_context () in

  (* Create method with 11 parameters to test CAMLxparam chunking *)
  (* OCaml runtime only has CAMLparam0-5 and CAMLxparam0-5, so 11 params need chunking *)
  (* With self, that's 12 total params: CAMLparam5 + CAMLxparam5 + CAMLxparam2 *)
  let params =
    List.init 11 (fun i ->
        make_int_param ~param_name:(Fmt.str "arg%d" (i + 1)) ())
  in

  let meth =
    make_gir_method ~method_name:"process_eleven"
      ~c_identifier:"gtk_widget_process_eleven" ~return_type:void_type
      ~parameters:params ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_method.generate_c_method ~ctx
      ~c_type:"GtkWidget" meth "Widget"
  in

  let functions = parse_c_string c_code in

  (* Should generate 2 functions: _native and _bytecode *)
  Alcotest.(check int)
    "Should generate 2 functions (native + bytecode)" 2 (List.length functions);

  assert_function_exists functions "ml_gtk_widget_process_eleven_native";
  assert_function_exists functions "ml_gtk_widget_process_eleven_bytecode";

  (* Verify CAMLxparam chunking - should NOT contain CAMLxparam6 or higher *)
  let has_high_camlxparam = c_code_has_camlxparam_n_or_higher c_code 6 in
  Alcotest.(check bool)
    "Should NOT contain CAMLxparam6 or higher" false has_high_camlxparam;

  (* Verify correct chunking: CAMLparam5 + CAMLxparam5 + CAMLxparam2 *)
  (* For 12 params (self + 11): first 5 go in CAMLparam5, next 5 in CAMLxparam5, last 2 in CAMLxparam2 *)
  Alcotest.(check bool)
    "Contains CAMLparam5" true
    (c_code_has_caml_param c_code "CAMLparam5");
  Alcotest.(check bool)
    "Contains CAMLxparam5" true
    (c_code_has_caml_param c_code "CAMLxparam5");
  Alcotest.(check bool)
    "Contains CAMLxparam2" true
    (c_code_has_caml_param c_code "CAMLxparam2")

(* ========================================================================= *)
(* Type Validation Tests *)
(* ========================================================================= *)

let test_constructor_type_conversion () =
  let ctx = create_test_context () in
  let ctor =
    make_gir_constructor ~ctor_name:"new" ~c_identifier:"gtk_button_new" ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_constructor.generate_c_constructor ~ctx
      ~c_type:"GtkButton" ~class_name:"Button" ctor
  in

  let functions = parse_c_string c_code in
  let func =
    Helpers.assert_some_value "ml_gtk_button_new"
      (find_function functions "ml_gtk_button_new")
  in

  (* Should use Val_GtkButton macro for return conversion *)
  Alcotest.(check bool)
    "Uses correct return conversion macro" true
    (C_validation.validates_gtk_constructor func "GtkButton")

let test_method_calls_c_function () =
  let meth =
    make_gir_method ~method_name:"set_label"
      ~c_identifier:"gtk_button_set_label" ~return_type:void_type
      ~parameters:[ make_string_param ~param_name:"label" () ]
      ()
  in

  let func =
    Helpers.generate_and_find_c_method ~c_type:"GtkButton" ~class_name:"Button"
      meth
  in

  (* Should call gtk_button_set_label *)
  Alcotest.(check bool)
    "Calls underlying C function" true
    (C_validation.calls_c_function func "gtk_button_set_label")

let test_variable_declarations () =
  let ctx = create_test_context () in
  let ctor =
    make_gir_constructor ~ctor_name:"new" ~c_identifier:"gtk_button_new" ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_constructor.generate_c_constructor ~ctx
      ~c_type:"GtkButton" ~class_name:"Button" ctor
  in

  let functions = parse_c_string c_code in
  let func =
    Helpers.assert_some_value "ml_gtk_button_new"
      (find_function functions "ml_gtk_button_new")
  in

  (* Extract variable declarations *)
  let var_decls = C_ast.get_var_decls func in

  (* Should declare 'obj' variable of type GtkButton* *)
  Alcotest.(check bool)
    "Declares obj variable" true
    (List.exists
       (fun (name, var_type, _) ->
         name = "obj" && String.starts_with ~prefix:"GtkButton" var_type)
       var_decls)

let test_parameter_flow_to_return () =
  let ctx = create_test_context () in
  let ctor =
    make_gir_constructor ~ctor_name:"new" ~c_identifier:"gtk_button_new" ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_constructor.generate_c_constructor ~ctx
      ~c_type:"GtkButton" ~class_name:"Button" ctor
  in

  let functions = parse_c_string c_code in
  let func =
    Helpers.assert_some_value "ml_gtk_button_new"
      (find_function functions "ml_gtk_button_new")
  in

  (* Check that 'obj' variable flows to return value *)
  let type_info = C_ast.extract_type_info func in
  Helpers.expect_some "No return expression found" type_info.return_expr
  @@ fun expr ->
  (* The return should involve 'obj' *)
  Alcotest.(check bool)
    "Return expression uses obj variable" true
    (C_ast.expr_uses_var expr "obj")

let test_bytecode_calls_native () =
  let ctx = create_test_context () in

  let params =
    List.init 6 (fun i ->
        make_int_param ~param_name:(Fmt.str "arg%d" (i + 1)) ())
  in

  let ctor =
    make_gir_constructor ~ctor_name:"new_complex"
      ~c_identifier:"gtk_widget_new_complex" ~ctor_parameters:params ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_constructor.generate_c_constructor ~ctx
      ~c_type:"GtkWidget" ~class_name:"Widget" ctor
  in

  let functions = parse_c_string c_code in

  (* Verify bytecode/native pair is correct *)
  Alcotest.(check bool)
    "Bytecode/native pair properly structured" true
    (C_validation.validates_bytecode_native_pair functions
       "ml_gtk_widget_new_complex")

(* ========================================================================= *)
(* Record Type Tests *)
(* ========================================================================= *)

let test_non_opaque_record_return () =
  let ctx = Helpers.create_test_context () in

  (* Add a non-opaque record to the context *)
  let test_record =
    make_gir_record ~record_name:"TestRecord" ~c_type:"GtkTestRecord"
      ~glib_type_name:"GtkTestRecord" ~glib_get_type:"gtk_test_record_get_type"
      ~opaque:false ~disguised:false
      ~fields:
        [ make_gir_record_field ~field_name:"width" ~field_type:gint_type () ]
      ()
  in

  let ctx = { ctx with records = [ test_record ] } in

  let return_type =
    make_gir_type ~name:"TestRecord" ~c_type:"GtkTestRecord*" ()
  in
  let meth =
    make_gir_method ~method_name:"get_record"
      ~c_identifier:"gtk_widget_get_record" ~return_type ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_method.generate_c_method ~ctx
      ~c_type:"GtkWidget" meth "Widget"
  in

  Helpers.log_generated_c_code "non-opaque record return" c_code;

  let functions = parse_c_string c_code in
  let func =
    Helpers.assert_some_value "ml_gtk_widget_get_record"
      (find_function functions "ml_gtk_widget_get_record")
  in

  (* Should use Val_GtkTestRecord for return conversion *)
  Alcotest.(check bool)
    "Uses Val_GtkTestRecord conversion" true
    (C_validation.validates_gtk_constructor func "GtkTestRecord")

let test_non_opaque_record_parameter () =
  let ctx = Helpers.create_test_context () in

  let test_record =
    make_gir_record ~record_name:"TestRecord" ~c_type:"GtkTestRecord"
      ~glib_type_name:"GtkTestRecord" ~glib_get_type:"gtk_test_record_get_type"
      ~opaque:false ~disguised:false
      ~fields:
        [ make_gir_record_field ~field_name:"width" ~field_type:gint_type () ]
      ()
  in

  let ctx = { ctx with records = [ test_record ] } in

  let record_param_type =
    make_gir_type ~name:"TestRecord" ~c_type:"GtkTestRecord*" ()
  in
  let meth =
    make_gir_method ~method_name:"set_record"
      ~c_identifier:"gtk_widget_set_record" ~return_type:void_type
      ~parameters:
        [ make_gir_param ~param_name:"record" ~param_type:record_param_type () ]
      ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_method.generate_c_method ~ctx
      ~c_type:"GtkWidget" meth "Widget"
  in

  Helpers.log_generated_c_code "non-opaque record parameter" c_code;

  let functions = parse_c_string c_code in
  let func =
    Helpers.assert_some_value "ml_gtk_widget_set_record"
      (find_function functions "ml_gtk_widget_set_record")
  in

  (* Should have 2 params: self + record *)
  Alcotest.(check int) "Has 2 parameters" 2 (C_ast.get_param_count func);

  (* Should call the C function *)
  Alcotest.(check bool)
    "Calls C function" true
    (C_validation.calls_c_function func "gtk_widget_set_record")

let test_opaque_record_return () =
  let ctx = Helpers.create_test_context () in

  (* Add an opaque record to the context *)
  let opaque_record =
    make_gir_record ~record_name:"OpaqueRec" ~c_type:"GtkOpaqueRec" ~opaque:true
      ~disguised:true ()
  in

  let ctx = { ctx with records = [ opaque_record ] } in

  let return_type =
    make_gir_type ~name:"OpaqueRec" ~c_type:"GtkOpaqueRec*" ()
  in
  let meth =
    make_gir_method ~method_name:"get_opaque"
      ~c_identifier:"gtk_widget_get_opaque" ~return_type ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_method.generate_c_method ~ctx
      ~c_type:"GtkWidget" meth "Widget"
  in

  Helpers.log_generated_c_code "opaque record return" c_code;

  let functions = parse_c_string c_code in
  let func =
    Helpers.assert_some_value "ml_gtk_widget_get_opaque"
      (find_function functions "ml_gtk_widget_get_opaque")
  in

  (* Should use Val_GtkOpaqueRec for return conversion *)
  Alcotest.(check bool)
    "Uses Val_GtkOpaqueRec conversion" true
    (C_validation.validates_gtk_constructor func "GtkOpaqueRec")

let test_opaque_record_parameter () =
  let ctx = Helpers.create_test_context () in

  let opaque_record =
    make_gir_record ~record_name:"OpaqueRec" ~c_type:"GtkOpaqueRec" ~opaque:true
      ~disguised:true ()
  in

  let ctx = { ctx with records = [ opaque_record ] } in

  let opaque_param_type =
    make_gir_type ~name:"OpaqueRec" ~c_type:"GtkOpaqueRec*" ()
  in
  let meth =
    make_gir_method ~method_name:"set_opaque"
      ~c_identifier:"gtk_widget_set_opaque" ~return_type:void_type
      ~parameters:
        [ make_gir_param ~param_name:"opaque" ~param_type:opaque_param_type () ]
      ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_method.generate_c_method ~ctx
      ~c_type:"GtkWidget" meth "Widget"
  in

  Helpers.log_generated_c_code "opaque record parameter" c_code;

  let functions = parse_c_string c_code in
  let func =
    Helpers.assert_some_value "ml_gtk_widget_set_opaque"
      (find_function functions "ml_gtk_widget_set_opaque")
  in

  (* Should have 2 params: self + opaque *)
  Alcotest.(check int) "Has 2 parameters" 2 (C_ast.get_param_count func);

  (* Should call the C function *)
  Alcotest.(check bool)
    "Calls C function" true
    (C_validation.calls_c_function func "gtk_widget_set_opaque")

let test_nullable_record_return () =
  let ctx = Helpers.create_test_context () in

  let test_record =
    make_gir_record ~record_name:"TestRecord" ~c_type:"GtkTestRecord"
      ~glib_type_name:"GtkTestRecord" ~glib_get_type:"gtk_test_record_get_type"
      ~opaque:false ~disguised:false
      ~fields:
        [ make_gir_record_field ~field_name:"width" ~field_type:gint_type () ]
      ()
  in

  let ctx = { ctx with records = [ test_record ] } in

  let return_type =
    make_gir_type ~name:"TestRecord" ~c_type:"GtkTestRecord*" ~nullable:true ()
  in
  let meth =
    make_gir_method ~method_name:"get_nullable_record"
      ~c_identifier:"gtk_widget_get_nullable_record" ~return_type ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_method.generate_c_method ~ctx
      ~c_type:"GtkWidget" meth "Widget"
  in

  Helpers.log_generated_c_code "nullable record return" c_code;

  let functions = parse_c_string c_code in
  let func =
    Helpers.assert_some_value "ml_gtk_widget_get_nullable_record"
      (find_function functions "ml_gtk_widget_get_nullable_record")
  in

  (* Should have return statement *)
  Alcotest.(check bool)
    "Has return statement" true
    (C_ast.has_return_stmt func.C_ast.body)

let test_nullable_record_parameter () =
  let ctx = Helpers.create_test_context () in

  let test_record =
    make_gir_record ~record_name:"TestRecord" ~c_type:"GtkTestRecord"
      ~glib_type_name:"GtkTestRecord" ~glib_get_type:"gtk_test_record_get_type"
      ~opaque:false ~disguised:false
      ~fields:
        [ make_gir_record_field ~field_name:"width" ~field_type:gint_type () ]
      ()
  in

  let ctx = { ctx with records = [ test_record ] } in

  let record_param_type =
    make_gir_type ~name:"TestRecord" ~c_type:"GtkTestRecord*" ~nullable:true ()
  in
  let meth =
    make_gir_method ~method_name:"set_nullable_record"
      ~c_identifier:"gtk_widget_set_nullable_record" ~return_type:void_type
      ~parameters:
        [
          make_gir_param ~param_name:"record" ~param_type:record_param_type
            ~nullable:true ();
        ]
      ()
  in

  let c_code =
    Gir_gen_lib.Generate.C_stub_method.generate_c_method ~ctx
      ~c_type:"GtkWidget" meth "Widget"
  in

  Helpers.log_generated_c_code "nullable record parameter" c_code;

  let functions = parse_c_string c_code in
  let func =
    Helpers.assert_some_value "ml_gtk_widget_set_nullable_record"
      (find_function functions "ml_gtk_widget_set_nullable_record")
  in

  (* Should have 2 params: self + record *)
  Alcotest.(check int) "Has 2 parameters" 2 (C_ast.get_param_count func);

  (* Should call the C function *)
  Alcotest.(check bool)
    "Calls C function" true
    (C_validation.calls_c_function func "gtk_widget_set_nullable_record")

(* ========================================================================= *)
(* Header File Naming Tests (Stage 1: Phase 2) *)
(* ========================================================================= *)

let test_header_file_naming () =
  let ctx = create_test_context () in
  let ns_name =
    String.lowercase_ascii ctx.Gir_gen_lib.Types.namespace.namespace_name
  in
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:[] ~gtk_bitfields:[] ~records:[] ~interfaces:[] ()
  in

  (* Parse header guards using AST-based validation *)
  let guards = parse_header_guards header_content in
  let expected_suffix = "_decls_h_" in

  (* Find the guard for this namespace *)
  let guard_opt = find_header_guard guards expected_suffix in

  (* Verify header guard exists with correct structure *)
  ( Helpers.expect_some
      (Fmt.str "Header guard with suffix '%s' not found" expected_suffix)
      guard_opt
  @@ fun guard ->
    (* Verify guard name format: _<ns>_decls_h_ *)
    let expected_guard_name = Fmt.str "_%s_decls_h_" ns_name in
    Alcotest.(check string)
      "Header guard name uses _ns_decls_h_ format" expected_guard_name
      guard.guard_name;

    (* Verify guard has all required directives *)
    Alcotest.(check bool) "Header has #ifndef" true guard.has_ifndef;
    Alcotest.(check bool) "Header has #define" true guard.has_define;
    Alcotest.(check bool) "Header has #endif" true guard.has_endif );

  (* Verify old naming pattern is NOT used *)
  Alcotest.(check bool)
    "Old header guard naming not used" false
    (contains_old_naming header_content)

let test_header_guard_format () =
  let ctx = create_test_context () in
  let ns_name = ctx.Gir_gen_lib.Types.namespace.namespace_name in
  let ns_lower = String.lowercase_ascii ns_name in

  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~classes:ctx.classes
      ~gtk_enums:[] ~gtk_bitfields:[] ~records:[] ~interfaces:[] ()
  in

  (* Parse header guards using AST-based validation *)
  let guards = parse_header_guards header_content in
  let expected_guard_name = Fmt.str "_%s_decls_h_" ns_lower in

  (* Find the guard matching expected pattern *)
  let guard_opt =
    List.find_opt (fun g -> g.guard_name = expected_guard_name) guards
  in

  Helpers.expect_some
    (Fmt.str "Header guard '%s' not found" expected_guard_name)
    guard_opt
  @@ fun guard ->
  (* Verify guard has complete structure *)
  Alcotest.(check bool) "Header guard has #ifndef" true guard.has_ifndef;
  Alcotest.(check bool) "Header guard has #define" true guard.has_define;
  Alcotest.(check bool) "Header guard has #endif" true guard.has_endif

(* Transfer-none boxed record return emits g_boxed_copy to take ownership.
   Without this, the finalizer calls g_boxed_free on a borrowed pointer. *)
let test_boxed_record_transfer_none_emits_g_boxed_copy () =
  let ctx = Helpers.create_test_context () in
  let test_record =
    make_gir_record ~record_name:"TestRecord" ~c_type:"GtkTestRecord"
      ~glib_get_type:"gtk_test_record_get_type" ~opaque:true ()
  in
  let ctx = { ctx with records = [ test_record ] } in
  let return_type =
    make_gir_type ~name:"TestRecord" ~c_type:"GtkTestRecord*"
      ~transfer_ownership:TransferNone ()
  in
  let meth =
    make_gir_method ~method_name:"get_record"
      ~c_identifier:"gtk_widget_get_record" ~return_type ()
  in
  let c_code =
    Gir_gen_lib.Generate.C_stub_method.generate_c_method ~ctx
      ~c_type:"GtkWidget" meth "Widget"
  in
  Helpers.log_generated_c_code "boxed record transfer-none" c_code;
  Alcotest.(check bool)
    "Transfer-none boxed record emits g_boxed_copy" true
    (Helpers.string_contains c_code "g_boxed_copy")

let test_boxed_record_transfer_full_no_g_boxed_copy () =
  let ctx = Helpers.create_test_context () in
  let test_record =
    make_gir_record ~record_name:"TestRecord" ~c_type:"GtkTestRecord"
      ~glib_get_type:"gtk_test_record_get_type" ~opaque:true ()
  in
  let ctx = { ctx with records = [ test_record ] } in
  let return_type =
    make_gir_type ~name:"TestRecord" ~c_type:"GtkTestRecord*"
      ~transfer_ownership:TransferFull ()
  in
  let meth =
    make_gir_method ~method_name:"get_record"
      ~c_identifier:"gtk_widget_get_record" ~return_type ()
  in
  let c_code =
    Gir_gen_lib.Generate.C_stub_method.generate_c_method ~ctx
      ~c_type:"GtkWidget" meth "Widget"
  in
  Helpers.log_generated_c_code "boxed record transfer-full" c_code;
  Alcotest.(check bool)
    "Transfer-full boxed record does not emit g_boxed_copy" false
    (Helpers.string_contains c_code "g_boxed_copy")

(* ========================================================================= *)
(* Test Suite *)
(* ========================================================================= *)

let tests =
  [
    (* Constructor tests *)
    Alcotest.test_case "Simple constructor (0 params)" `Quick
      test_simple_constructor;
    Alcotest.test_case "Constructor with parameters" `Quick
      test_constructor_with_params;
    Alcotest.test_case "Constructor with 6+ params (bytecode/native split)"
      `Quick test_constructor_many_params;
    (* Method tests *)
    Alcotest.test_case "Simple method (void return)" `Quick test_simple_method;
    Alcotest.test_case "Method with return value" `Quick
      test_method_with_return_value;
    Alcotest.test_case "Method with 6+ params (bytecode/native split)" `Quick
      test_method_many_params;
    Alcotest.test_case "Method with 11 params (CAMLxparam chunking)" `Quick
      test_method_camlxparam_chunking;
    (* Type validation tests *)
    Alcotest.test_case "Constructor uses correct type conversion" `Quick
      test_constructor_type_conversion;
    Alcotest.test_case "Method calls underlying C function" `Quick
      test_method_calls_c_function;
    Alcotest.test_case "Variable declarations are parsed" `Quick
      test_variable_declarations;
    Alcotest.test_case "Parameter flow to return value" `Quick
      test_parameter_flow_to_return;
    Alcotest.test_case "Bytecode calls native function" `Quick
      test_bytecode_calls_native;
    (* Record type tests *)
    Alcotest.test_case "Non-opaque record return type" `Quick
      test_non_opaque_record_return;
    Alcotest.test_case "Non-opaque record parameter" `Quick
      test_non_opaque_record_parameter;
    Alcotest.test_case "Opaque record return type" `Quick
      test_opaque_record_return;
    Alcotest.test_case "Opaque record parameter" `Quick
      test_opaque_record_parameter;
    Alcotest.test_case "Nullable record return type" `Quick
      test_nullable_record_return;
    Alcotest.test_case "Nullable record parameter" `Quick
      test_nullable_record_parameter;
    Alcotest.test_case "Boxed record transfer-none emits g_boxed_copy" `Quick
      test_boxed_record_transfer_none_emits_g_boxed_copy;
    Alcotest.test_case "Boxed record transfer-full does not emit g_boxed_copy"
      `Quick test_boxed_record_transfer_full_no_g_boxed_copy;
    (* Header file naming tests (Stage 1: Phase 2) *)
    Alcotest.test_case "Header file uses <ns>_decls.h naming" `Quick
      test_header_file_naming;
    Alcotest.test_case "Header guard uses _<ns>_decls_h_ format" `Quick
      test_header_guard_format;
  ]
