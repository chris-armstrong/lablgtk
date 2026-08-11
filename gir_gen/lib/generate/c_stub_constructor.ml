(* C Stub Code Generation - Constructor Support *)

open Containers
open StdLabels
open Types

module Log =
  (val Logs.src_log
         (Logs.Src.create "gir_gen.c_stub_constructor"
            ~doc:"C stub code generation for constructor support"))

(* [generate_constructor_error_decl ~throws] generates error declaration if constructor throws.
   Returns "GError *error = NULL;\n    " if throws=true, otherwise returns empty string. *)
let generate_constructor_error_decl ~throws =
  if throws then "GError *error = NULL;\n    " else ""

(* [generate_constructor_return_stmt ~throws ~val_macro ~var_name] generates return statement
   based on throws flag. If throws=true, generates conditional return handling error.
   Otherwise generates simple CAMLreturn with converted value. *)
let generate_constructor_return_stmt ~throws ~val_macro ~var_name =
  if throws then
    Fmt.str
      "if (error == NULL) CAMLreturn(Res_Ok(%s(%s))); else \
       CAMLreturn(Res_Error(Val_GError(error)));"
      val_macro var_name
  else Fmt.str "CAMLreturn(%s(%s));" val_macro var_name

(* [generate_constructor_c_call_args ~ctx ~ctor_parameters] builds C call arguments
   with nullable handling. For each parameter, looks up type mapping and generates
   appropriate conversion expression. Handles arrays with inline conversion code.
   Returns tuple of (argument_expressions, cleanup_code_list, declarations_buffer). *)
let generate_constructor_c_call_args ~ctx ~ctor_parameters =
  let decls = Buffer.create 1024 in
  let cleanups = ref [] in
  let arg_exprs, _ =
    List.fold_left ctor_parameters ~init:([], 0)
      ~f:(fun (args, idx) (p : gir_param) ->
        let next_idx = idx + 1 in
        let arg_name = Fmt.str "arg%d" next_idx in
        (* Check for GList/GSList types first - they use list conversion, not array *)
        if Gir_type_pred.is_list p.param_type then
          match
            C_stub_list_conv.generate_param_list_conversion ~ctx
              ~ocaml_var:arg_name ~gir_type:p.param_type
          with
          | Some (c_var, conversion_code) ->
              Buffer.add_string decls (Fmt.str "    %s\n" conversion_code);
              let list_kind =
                Option.value
                  (C_stub_list_conv.list_kind_of_type p.param_type)
                  ~default:`GList
              in
              let cleanup =
                C_stub_list_conv.cleanup_for_in_param ~list_kind
                  ~element_unref_fn:"g_object_unref"
                  ~transfer:p.param_type.transfer_ownership c_var
              in
              cleanups := cleanup :: !cleanups;
              (args @ [ c_var ], next_idx)
          | None -> (args @ [ arg_name ], next_idx)
        (* Check if this is a non-list array parameter *)
          else
          match p.param_type.array with
          | Some array_info -> (
              (* Handle array parameter with inline conversion *)
              match
                Type_mappings.find_type_mapping_for_gir_type ~ctx
                  array_info.element_type
              with
              | Some element_mapping ->
                  (* Use element's c:type directly for modifiable local array *)
                  let element_c_type =
                    match array_info.element_type.c_type with
                    | Some ct -> ct
                    | None -> element_mapping.c_type
                  in
                  let nullable = p.nullable || p.param_type.nullable in
                  let conv_code, c_array_var, _length_var, cleanup_code =
                    C_stub_array_conv.Array_conv.generate_array_ml_to_c ~ctx
                      ~var:arg_name ~array_info ~element_mapping ~element_c_type
                      ~transfer_ownership:p.param_type.transfer_ownership
                      ~nullable
                  in
                  Buffer.add_string decls (Fmt.str "    %s\n" conv_code);
                  if String.length cleanup_code > 0 then
                    cleanups := cleanup_code :: !cleanups;
                  (args @ [ c_array_var ], next_idx)
              | None ->
                  failwith
                    (Fmt.str
                       "Array element type '%s' not supported in constructor"
                       array_info.element_type.name))
          | None -> (
              (* Regular parameter - use existing type mapping *)
              match
                Type_mappings.find_type_mapping_for_gir_type ~ctx p.param_type
              with
              | Some mapping ->
                  let param_type =
                    {
                      p.param_type with
                      nullable = p.nullable || p.param_type.nullable;
                    }
                  in
                  let arg_expr =
                    C_stub_helpers.nullable_ml_to_c_expr ~var:arg_name
                      ~gir_type:param_type ~mapping
                  in
                  (args @ [ arg_expr ], next_idx)
              | None ->
                  (* This should never happen now that we filter constructors with unknown types *)
                  (args @ [ arg_name ], next_idx)))
  in
  (arg_exprs, List.rev !cleanups, decls)

(* [build_constructor_params ctor_parameters] builds C parameter declarations and names.
   Returns tuple of (param_count, params_list, param_names_list).
   Handles the zero-parameter case with a unit parameter. *)
let build_constructor_params ctor_parameters =
  match List.length ctor_parameters with
  | 0 -> (1, [ "value unit" ], [ "unit" ])
  | n ->
      let params =
        List.mapi ~f:(fun i _ -> Fmt.str "value arg%d" (i + 1)) ctor_parameters
      in
      let param_names =
        List.mapi ~f:(fun i _ -> Fmt.str "arg%d" (i + 1)) ctor_parameters
      in
      (n, params, param_names)

(* [build_constructor_call c_args throws] constructs the C function call argument string.
   Combines converted C arguments with optional error parameter for throwing constructors.
   Returns the complete argument list as a comma-separated string. *)
let build_constructor_call c_args throws =
  let base_args = String.concat ~sep:", " c_args in
  if throws then String.concat ~sep:", " [ base_args; "&error" ] else base_args

(* [build_constructor_return ~c_type ctor param_count params param_names c_call_args ref_sink_stmt val_macro var_name]
    generates the complete C constructor function including error handling and return logic.
    Handles both the >5 parameter case (using C_stub_multi_param.generate_multi_param_function) and the normal case.
    Returns the complete C function code as a string. *)
let build_constructor_return ~c_type (ctor : gir_constructor) param_count params
    param_names c_call_args ref_sink_stmt val_macro var_name ~array_decls
    ~cleanup_code =
  let c_name = ctor.c_identifier in
  let throws = ctor.throws in
  let error_decl = generate_constructor_error_decl ~throws in
  let return_stmt =
    generate_constructor_return_stmt ~throws ~val_macro ~var_name
  in
  let array_decls_str = Buffer.contents array_decls in
  let cleanup_section =
    if List.length cleanup_code > 0 then
      Fmt.str "\n    %s" (String.concat ~sep:"\n    " cleanup_code)
    else ""
  in

  if param_count > 5 then
    let body_code =
      Fmt.str "%s%s\n%s *%s = %s(%s);%s\n%s\n%s" array_decls_str error_decl
        c_type var_name c_name c_call_args ref_sink_stmt cleanup_section
        return_stmt
    in
    C_stub_multi_param.generate_multi_param_function
      ~ml_name:(Utils.ml_constructor_name ~constructor:ctor)
      ~params ~param_names body_code
  else
    Fmt.str
      "\n\
       CAMLexport CAMLprim value %s(%s)\n\
       {\n\
       CAMLparam%d(%s);\n\
       %s%s\n\
       %s *%s = %s(%s);%s\n\
       %s\n\
       %s\n\
       }"
      (Utils.ml_constructor_name ~constructor:ctor)
      (String.concat ~sep:", " params)
      param_count
      (String.concat ~sep:", " param_names)
      array_decls_str error_decl c_type var_name c_name c_call_args
      ref_sink_stmt cleanup_section return_stmt

(* [generate_c_constructor ~ctx ~c_type ~class_name ctor] generates a C wrapper function
   for a GIR constructor. Handles parameter conversion from OCaml to C types, C constructor
   invocation, ref_sink for GObject types (to handle Floating transfer semantics), and
   conversion of result to OCaml. Supports error handling if constructor throws. Generates
   both native and bytecode (multi-arg) variants when parameter count exceeds 5. Wraps with
   version guards if the class or constructor has a version. Returns the complete C function
   code as a string. *)
let generate_c_constructor ~ctx ~c_type ~class_name:_ (ctor : gir_constructor) =
  let val_macro = Fmt.str "Val_%s" c_type in
  let var_name = "obj" in

  (* Check if this is a GObject constructor - for GObjects, always ref_sink *)
  let ref_sink_stmt =
    (* Try to look up the type mapping for the constructor's return type *)
    let dummy_gir_type =
      {
        name = c_type;
        c_type = Some (c_type ^ "*");
        nullable = false;
        transfer_ownership = Types.TransferNone;
        array = None;
      }
    in
    match Type_mappings.find_type_mapping_for_gir_type ~ctx dummy_gir_type with
    | Some { transfer_strategy = Types.Ts_gobject; _ } ->
        (* GObject constructors always need ref_sink regardless of transfer annotation *)
        Fmt.str "\nif (%s) g_object_ref_sink(%s);" var_name var_name
    | _ -> ""
  in

  (* Build C parameter declarations and names *)
  let param_count, params, param_names =
    build_constructor_params ctor.ctor_parameters
  in

  (* Build C call arguments - handle nullable parameters and arrays *)
  let c_args, cleanup_code, array_decls =
    generate_constructor_c_call_args ~ctx ~ctor_parameters:ctor.ctor_parameters
  in

  (* Build constructor call string with error parameter if needed *)
  let c_call_args = build_constructor_call c_args ctor.throws in

  (* Build the complete constructor function with return handling *)
  let real_stub =
    build_constructor_return ~c_type ctor param_count params param_names
      c_call_args ref_sink_stmt val_macro var_name ~array_decls ~cleanup_code
  in

  (* Note: Version guards should only be emitted at the class level in gir_gen.ml
     If we are here, it means the class has no version but this member does.
     Only emit member-level guard in that case. *)
  real_stub
