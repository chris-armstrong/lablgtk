(* C Stub Code Generation - Method Support *)

open Gen_buffer
open Containers
open StdLabels
open Types

(* Out parameter conversion module - handles conversion from C to OCaml for out/inout parameters *)
module Out_conv = C_stub_method_out

(* Option binding operator for flattening nested Option.bind chains *)
let ( let* ) = Option.bind

(* Assertion-style option extraction for "impossible" None cases *)
let option_get_exn ~message o =
  match o with Some v -> v | None -> failwith message

module Log =
  (val Logs.src_log
         (Logs.Src.create "gir_gen.c_stub_method"
            ~doc:"C stub code generation for method support"))

(* [var_name_for_direction direction idx] generates a unique variable name based on parameter direction.
   Out parameters use "out<N>", InOut use "inout<N>", and In use "arg<N>".
   The index is 0-based but incremented by 1 in the name for human readability. *)
let var_name_for_direction direction idx =
  match direction with
  | Out -> Fmt.str "out%d" (idx + 1)
  | InOut -> Fmt.str "inout%d" (idx + 1)
  | In -> Fmt.str "arg%d" (idx + 1)

(* [declare_fixed_array ~base_type ~var_name ~fixed_size ~acc] generates stack allocation
    for a fixed-size caller-allocated array. Returns updated accumulator with the declaration
    and the array name as argument (array decays to pointer). *)
let declare_fixed_array ~base_type ~var_name ~fixed_size ~acc =
  bprintf acc.C_stub_helpers.decls "%s %s[%d];\n" base_type var_name fixed_size;
  { acc with C_stub_helpers.args = acc.C_stub_helpers.args @ [ var_name ] }

(* [declare_array_out_param ~base_type ~var_name ~acc] generates heap allocation for a regular
    array out parameter. Returns updated accumulator with declaration and address-of argument. *)
let declare_array_out_param ~base_type ~var_name ~acc =
  bprintf acc.C_stub_helpers.decls "%s %s = NULL;\n" base_type var_name;
  {
    acc with
    C_stub_helpers.args = acc.C_stub_helpers.args @ [ Fmt.str "&%s" var_name ];
  }

(* [handle_out_param ~param_index ~base_type ~acc p] processes an out-direction parameter.
    Generates a C variable declaration (as pointer for arrays, as value otherwise) and
    adds the variable's address to the C function arguments list.
    
    For array out parameters: C functions use T** for out parameters (e.g., double** axes in signature).
    We declare T* locally and pass &variable. This way variable[i] accesses T elements directly.
    Since base_type already had one * stripped, we don't add another * for arrays.
    
    For fixed-size caller-allocated arrays: Generate stack allocation `Type var[N];` instead of
    heap allocation, and pass `var` directly (not `&var`) since the array decays to a pointer.
    
    Returns the updated accumulator with new declarations and arguments. *)
let handle_out_param ~param_index ~base_type ~acc (p : gir_param) =
  let var_name = var_name_for_direction Out param_index in
  (* For array out params: base_type already stripped one *, so just use it (it's T*, not T** ).
     For non-array out params: declare as value type. *)
  match p.param_type.array with
  | Some array_info when p.caller_allocates -> (
      (* Caller-allocated array: check for fixed-size stack allocation *)
      match array_info.fixed_size with
      | Some fixed_size ->
          declare_fixed_array ~base_type ~var_name ~fixed_size ~acc
      | None -> declare_array_out_param ~base_type ~var_name ~acc)
  | Some _array_info ->
      (* Regular array out param: declare as "T* var = NULL" and pass &var *)
      declare_array_out_param ~base_type ~var_name ~acc
  | None ->
      (* Non-array out param: declare as value type *)
      bprintf acc.C_stub_helpers.decls "%s %s;\n" base_type var_name;
      {
        acc with
        C_stub_helpers.args =
          acc.C_stub_helpers.args @ [ Fmt.str "&%s" var_name ];
      }

(* [handle_inout_param ~_ctx ~param_index ~base_type ~acc ~tm p] processes an inout-direction parameter.
    Generates a C variable declaration initialized from the OCaml argument using type-specific
    conversion. The variable is added as a pointer reference in the C function arguments.
    
    For record types (non-opaque structs passed as pointers like PangoRectangle ptr):
    - Creates a local stack value: PangoRectangle inout1_val = (dereference PangoRectangle_val(arg))
    - Creates a pointer to it: PangoRectangle ptr inout1 = &inout1_val
    - Passes the pointer (not address-of) to the C function
    
    For primitive types:
    - Declares the value directly: int inout1 = Int_val(arg)
    - Passes address-of to the C function: &inout1
    
    Returns the updated accumulator with declarations, arguments, and updated OCaml index. *)
let handle_inout_param ~ctx ~param_index ~base_type ~acc ~tm (p : gir_param) =
  let ocaml_idx = acc.C_stub_helpers.ocaml_idx + 1 in
  let arg_name = Fmt.str "arg%d" ocaml_idx in
  let var_name = Fmt.str "inout%d" (param_index + 1) in

  (* Check if this is a record type that needs special pointer handling.
     Check both the type_mapping flag (works for cross-namespace) and
     analyze_property_type (works for current namespace). *)
  let is_record_with_pointer =
    match tm with
    | Some mapping when mapping.is_value_type_record -> true
    | _ -> (
        let prop_info =
          C_stub_gvalue.GValue.analyze_property_type ~ctx p.param_type
        in
        match prop_info.record_info with
        | Some (record, _, _) when not record.opaque -> true
        | _ -> false)
  in

  if is_record_with_pointer then begin
    (* For record types: generate value + pointer pattern
       PangoRectangle inout1_val = *PangoRectangle_val(arg1);
       PangoRectangle *inout1 = &inout1_val;
       Pass inout1 (not &inout1) to the C function *)
    let init_expr =
      match tm with
      | Some mapping ->
          let param_type =
            { p.param_type with nullable = p.nullable || p.param_type.nullable }
          in
          C_stub_helpers.nullable_ml_to_c_expr ~var:arg_name
            ~gir_type:param_type ~mapping
      | None -> arg_name
    in
    let val_name = var_name ^ "_val" in
    (* Declare value: dereference the pointer returned by the conversion macro *)
    bprintf acc.decls "%s %s = *%s;\n" base_type val_name init_expr;
    (* Declare pointer to the value *)
    bprintf acc.decls "%s *%s = &%s;\n" base_type var_name val_name;
    {
      C_stub_helpers.ocaml_idx;
      decls = acc.decls;
      args = acc.args @ [ var_name ];
      (* Pass the pointer, not &pointer *)
      cleanups = acc.cleanups;
    }
  end
  else begin
    (* For primitive types: existing behavior *)
    let init_expr =
      match tm with
      | Some mapping ->
          let param_type =
            { p.param_type with nullable = p.nullable || p.param_type.nullable }
          in
          C_stub_helpers.nullable_ml_to_c_expr ~var:arg_name
            ~gir_type:param_type ~mapping
      | None -> arg_name
    in
    bprintf acc.decls "%s %s = %s;\n" base_type var_name init_expr;
    {
      C_stub_helpers.ocaml_idx;
      decls = acc.decls;
      args = acc.args @ [ Fmt.str "&%s" var_name ];
      cleanups = acc.cleanups;
    }
  end

(* [handle_in_array_param ~ctx ~acc ~arg_name ~base_type ~tm p array_info] processes
    an in-direction array parameter. Generates conversion code from OCaml array to C array,
    producing the C variable name and any required cleanup code. Returns a tuple of
    (c_array_var_name, updated_cleanup_code_list) to be used as function arguments. *)
let handle_in_array_param ~ctx ~acc ~arg_name ~base_type ~tm (p : gir_param)
    (array_info : gir_array) =
  match tm with
  | Some mapping ->
      (* Use element's c:type directly for modifiable local array *)
      let element_c_type =
        Out_conv.get_element_c_type ~fallback:base_type array_info
      in
      let nullable = p.nullable || p.param_type.nullable in
      let conv_code, c_array_var, _length_var, cleanup_code =
        C_stub_array_conv.Array_conv.generate_array_ml_to_c ~ctx ~var:arg_name
          ~array_info ~element_mapping:mapping ~element_c_type
          ~transfer_ownership:p.param_type.transfer_ownership ~nullable
      in
      bprintf acc.C_stub_helpers.decls "    %s\n" conv_code;
      let new_cleanups =
        if String.length cleanup_code > 0 then acc.cleanups @ [ cleanup_code ]
        else acc.cleanups
      in
      (c_array_var, new_cleanups)
  | None -> (arg_name, acc.cleanups)

(* [handle_scalar_param ~arg_name ~ocaml_idx ~length_param_map ~p ~tm] processes
    a scalar (non-array) in-direction parameter. Checks if this is a length parameter
    for another array (via length_param_map), and if so substitutes the length variable.
    Otherwise uses type mapping or returns the argument name. *)
let handle_scalar_param ~arg_name ~ocaml_idx ~length_param_map ~p ~tm =
  match List.assoc_opt ocaml_idx length_param_map with
  | Some length_var -> length_var
  | None -> (
      (* Normal parameter handling *)
      match tm with
      | Some mapping ->
          let param_type =
            { p.param_type with nullable = p.nullable || p.param_type.nullable }
          in
          C_stub_helpers.nullable_ml_to_c_expr ~var:arg_name
            ~gir_type:param_type ~mapping
      | None -> arg_name)

(* [handle_in_list_param ~ctx ~acc ~arg_name p] processes an in-direction GList/GSList parameter.
   Generates conversion code from OCaml list to C list. *)
let handle_in_list_param ~ctx ~acc ~arg_name (p : gir_param) =
  match
    C_stub_list_conv.generate_param_list_conversion ~ctx ~ocaml_var:arg_name
      ~gir_type:p.param_type
  with
  | Some (c_var, conversion_code) ->
      bprintf acc.C_stub_helpers.decls "    %s\n" conversion_code;
      (* The list kind (GList vs GSList) drives the free/foreach function; the
         method path frees transfer-full elements with g_free. Shared via
         [C_stub_list_conv.cleanup_for_in_param] to keep the constructor and
         method paths consistent — this also fixes the latent use of
         g_list_free/g_list_foreach on GSList parameters. *)
      let list_kind =
        Option.value
          (C_stub_list_conv.list_kind_of_type p.param_type)
          ~default:`GList
      in
      let cleanup_code =
        C_stub_list_conv.cleanup_for_in_param ~list_kind
          ~element_unref_fn:"g_free" ~transfer:p.param_type.transfer_ownership
          c_var
      in
      (c_var, acc.cleanups @ [ cleanup_code ])
  | None -> (arg_name, acc.cleanups)

(* [handle_in_param ~ctx ~acc ~length_param_map ~base_type ~tm p] processes an in-direction parameter.
   Handles both array and scalar types. For arrays, generates conversion code. For scalars,
   uses type mapping or substitutes length variable from length_param_map. Returns updated
   accumulator with arguments, declarations, and cleanup code. *)
let handle_in_param ~ctx ~acc ~length_param_map ~base_type ~tm (p : gir_param) =
  let ocaml_idx = acc.C_stub_helpers.ocaml_idx + 1 in
  let arg_name = Fmt.str "arg%d" ocaml_idx in
  (* Check for GList/GSList types first *)
  if Gir_type_pred.is_list p.param_type then
    let c_var, new_cleanups = handle_in_list_param ~ctx ~acc ~arg_name p in
    {
      C_stub_helpers.ocaml_idx;
      decls = acc.decls;
      args = acc.args @ [ c_var ];
      cleanups = new_cleanups;
    }
  else
    match p.param_type.array with
    | Some array_info ->
        let arg_expr, new_cleanups =
          handle_in_array_param ~ctx ~acc ~arg_name ~base_type ~tm p array_info
        in
        {
          C_stub_helpers.ocaml_idx;
          decls = acc.decls;
          args = acc.args @ [ arg_expr ];
          cleanups = new_cleanups;
        }
    | None ->
        let arg_expr =
          handle_scalar_param ~arg_name ~ocaml_idx ~length_param_map ~p ~tm
        in
        {
          C_stub_helpers.ocaml_idx;
          decls = acc.decls;
          args = acc.args @ [ arg_expr ];
          cleanups = acc.cleanups;
        }

(* Out parameter conversion functions moved to C_stub_method_out module *)

(* [generate_ref_sink_stmt ~transfer_ownership mapping] generates a ref_sink statement
   for GObject types. Returns a newline + g_object_ref_sink call for TransferNone/Floating
   transfer modes (to ensure proper reference counting). Returns empty string for
   TransferFull/TransferContainer (already owned) or if not a GObject type. *)
let generate_ref_sink_stmt ~transfer_ownership (mapping : Types.type_mapping) =
  match mapping.transfer_strategy with
  | Types.Ts_gobject -> (
      match transfer_ownership with
      | Types.TransferNone | Types.TransferFloating ->
          "\nif (result) g_object_ref_sink(result);"
      | Types.TransferFull | Types.TransferContainer -> "")
  | Types.Ts_boxed get_type_func -> (
      match transfer_ownership with
      | Types.TransferNone ->
          Fmt.str "\nif (result) result = g_boxed_copy(%s(), result);"
            get_type_func
      | Types.TransferFull | Types.TransferContainer | Types.TransferFloating ->
          "")
  | Types.Ts_gvariant -> (
      match transfer_ownership with
      | Types.TransferNone -> "\nif (result) g_variant_ref(result);"
      | Types.TransferFull | Types.TransferContainer | Types.TransferFloating ->
          "")
  | Types.Ts_none -> ""

(* [handle_void_return ~c_name ~args ~out_array_conv_code ~out_array_cleanup_list]
   generates the C call, return statement, and cleanup list for void return functions.
   If out_array_conv_code is non-empty, inserts it after the C call. Returns a tuple of
   (c_call_code, return_statement, cleanup_list). *)
let handle_void_return ~c_name ~args ~out_array_conv_code ~out_conversions
    ~out_array_cleanup_list =
  let c_call_with_conv =
    if String.length out_array_conv_code > 0 then
      Fmt.str "%s(%s);\n%s" c_name args out_array_conv_code
    else Fmt.str "%s(%s);" c_name args
  in
  ( c_call_with_conv,
    C_stub_helpers.build_return_statement ~throws:false None out_conversions,
    out_array_cleanup_list )

(* [handle_array_return ~ctx ~meth ~c_name ~args ~out_array_conv_code ~ret_type
                        ~out_conversions ~out_array_cleanup_list] handles array return types.
   Generates C call with result variable, extracts element C type from array info, converts
   C array to OCaml using generate_array_c_to_ml, and builds return statement with out-parameter
   conversions. Collects all cleanup code (both out-array and return-array cleanup).
   Returns tuple of (c_call_code, return_conversion_statement, cleanup_list). *)
let handle_array_return ~ctx ~(meth : gir_method) ~c_name ~args
    ~out_array_conv_code ~ret_type ~out_conversions ~out_array_cleanup_list =
  let array_info =
    meth.return_type.array
    |> option_get_exn
         ~message:
           "handle_array_return: meth.return_type.array is None - this is a \
            bug in GIR metadata"
  in
  let element_c_type =
    Out_conv.get_element_c_type ~fallback:ret_type array_info
  in
  (* Check if array length comes from an out parameter *)
  let length_expr =
    match array_info.length with
    | Some length_idx -> (
        (* Find the parameter at length_idx *)
        match List.nth_opt meth.parameters length_idx with
        | Some { direction = Out; _ } | Some { direction = InOut; _ } ->
            Some (var_name_for_direction Out length_idx)
        | _ -> None)
    | None -> None
  in
  let conv_code, ml_array_var, array_cleanup =
    C_stub_array_conv.Array_conv.generate_array_c_to_ml ~ctx ~var:"result"
      ~array_info ~length_expr ~element_c_type
      ~transfer_ownership:meth.return_type.transfer_ownership
      ~nullable:meth.return_type.nullable ()
  in
  let c_call_base = Fmt.str "%s result = %s(%s);" ret_type c_name args in
  let c_call =
    if String.length out_array_conv_code > 0 then
      Fmt.str "%s\n%s    %s" c_call_base out_array_conv_code conv_code
    else Fmt.str "%s\n    %s" c_call_base conv_code
  in
  let ret_conv =
    C_stub_helpers.build_return_statement ~throws:meth.throws
      (Some ml_array_var) out_conversions
  in
  let additional_cleanups =
    out_array_cleanup_list
    @ if String.length array_cleanup > 0 then [ array_cleanup ] else []
  in
  (c_call, ret_conv, additional_cleanups)

(* [handle_scalar_return ~ctx ~meth ~c_name ~args ~out_array_conv_code ~ret_type
                       ~mapping ~out_conversions ~out_array_cleanup_list] handles scalar return types.
   Generates C call with result variable, converts result from C to OCaml via nullable_c_to_ml_expr,
   adds ref_sink statement if return type is a GObject (to handle Floating transfer semantics),
   and builds return statement with out-parameter conversions. Appends out-array conversion code
   after C call if present. Returns tuple of (c_call_code, return_conversion_statement, cleanup_list). *)
let handle_scalar_return ~ctx ~(meth : gir_method) ~c_name ~args
    ~out_array_conv_code ~ret_type ~mapping ~out_conversions
    ~out_array_cleanup_list =
  let ml_result =
    C_stub_helpers.nullable_c_to_ml_expr ~ctx ~var:"result"
      ~gir_type:meth.return_type ~mapping ()
  in
  let ref_sink_stmt =
    generate_ref_sink_stmt
      ~transfer_ownership:meth.return_type.transfer_ownership mapping
  in
  let c_call_base =
    Fmt.str "%s result = %s(%s);%s" ret_type c_name args ref_sink_stmt
  in
  let c_call =
    if String.length out_array_conv_code > 0 then
      Fmt.str "%s\n%s" c_call_base out_array_conv_code
    else c_call_base
  in
  ( c_call,
    C_stub_helpers.build_return_statement ~throws:meth.throws (Some ml_result)
      out_conversions,
    out_array_cleanup_list )

(* [handle_list_return ~ctx ~meth ~c_name ~args ~ret_type ~out_array_conv_code
                        ~out_conversions ~out_array_cleanup_list] handles GList/GSList return types.
    Uses the macro-based conversion from C_stub_list_conv. *)
let handle_list_return ~ctx ~(meth : gir_method) ~c_name ~args
    ~out_array_conv_code ~out_conversions:_ ~out_array_cleanup_list =
  match
    C_stub_list_conv.generate_return_list_conversion ~ctx ~c_var:"c_result"
      ~gir_type:meth.return_type
  with
  | None ->
      failwith
        "handle_list_return: generate_return_list_conversion returned None - \
         this is a bug"
  | Some (decls, conv_code, ret_code) ->
      (* Always use GList* for the variable; cast away const when the GIR
         c:type says const GList*.  Val_GList_with uses g_list_last and the
         cleanup uses g_list_free, neither of which accept const GList*. *)
      let c_call_base =
        match meth.return_type.c_type with
        | Some ct when CCString.prefix ~pre:"const " ct ->
            Fmt.str "GList* c_result = (GList*)%s(%s);" c_name args
        | _ -> Fmt.str "GList* c_result = %s(%s);" c_name args
      in
      let c_call =
        if String.length out_array_conv_code > 0 then
          Fmt.str "%s\n    %s\n    %s" decls c_call_base out_array_conv_code
        else Fmt.str "%s\n    %s" decls c_call_base
      in
      let ret_conv =
        if meth.throws then
          Fmt.str
            "if (error == NULL) {\n\
            \        %s\n\
            \        CAMLreturn(Res_Ok(result));\n\
            \    } else CAMLreturn(Res_Error(Val_GError(error)));"
            conv_code
        else Fmt.str "%s\n    %s" conv_code ret_code
      in
      (c_call, ret_conv, out_array_cleanup_list)

(* [handle_non_void_return ~ctx ~meth ~c_name ~args ~ret_type ~out_array_conv_code
                           ~out_conversions ~out_array_cleanup_list] handles non-void return types.
    Dispatches to array, list, or scalar handlers based on return type.
    Raises failwith if no type mapping found for the return type. *)
let handle_non_void_return ~ctx ~(meth : gir_method) ~c_name ~args ~ret_type
    ~out_array_conv_code ~out_conversions ~out_array_cleanup_list =
  (* Check for GList/GSList types first - they need special handling *)
  if Gir_type_pred.is_list meth.return_type then
    handle_list_return ~ctx ~meth ~c_name ~args ~out_array_conv_code
      ~out_conversions ~out_array_cleanup_list
  else
    match
      Type_mappings.find_type_mapping_for_gir_type ~ctx meth.return_type
    with
    | Some mapping ->
        if Option.is_some meth.return_type.array then
          handle_array_return ~ctx ~meth ~c_name ~args ~out_array_conv_code
            ~ret_type ~out_conversions ~out_array_cleanup_list
        else
          handle_scalar_return ~ctx ~meth ~c_name ~args ~out_array_conv_code
            ~ret_type ~mapping ~out_conversions ~out_array_cleanup_list
    | None ->
        (* No type mapping found - fail with clear error *)
        failwith
          (Fmt.str
             "No type mapping found for return type: name='%s' c_type='%s' in \
              method %s. This indicates missing type information in the \
              context or GIR metadata."
             meth.return_type.name
             (Option.value meth.return_type.c_type ~default:"<none>")
             meth.c_identifier)

(* [build_return_conversion ~ctx ~meth ~c_name ~args ~ret_type ~out_array_conv_code
                             ~out_conversions ~out_array_cleanup_list] builds the complete return
   conversion for a method. Dispatches to void, array, or scalar handlers based on return type.
   If no type mapping found for non-void return, raises failwith with diagnostic error message.
   Returns tuple of (c_call_code, return_conversion_statement, cleanup_list). *)
let build_return_conversion ~ctx ~(meth : gir_method) ~c_name ~args ~ret_type
    ~out_array_conv_code ~out_conversions ~out_array_cleanup_list =
  match ret_type with
  | Some "void" | None ->
      handle_void_return ~c_name ~args ~out_array_conv_code ~out_conversions
        ~out_array_cleanup_list
  | Some ret_type ->
      handle_non_void_return ~ctx ~meth ~c_name ~args ~ret_type
        ~out_array_conv_code ~out_conversions ~out_array_cleanup_list

(* [compute_in_param_indices parameters] counts non-Out parameters to get OCaml indices.
    Returns a list of (param, original_index) pairs for all In and InOut parameters. *)
let compute_in_param_indices (parameters : gir_param list) =
  List.fold_left
    ~f:(fun (idx, acc) (p : gir_param) ->
      match p.direction with
      | Out -> (idx, acc)
      | In | InOut -> (idx + 1, (p, idx) :: acc))
    ~init:(0, []) parameters
  |> snd |> List.rev

(* [build_param_to_ocaml_map parameters] builds a map from parameter index to OCaml index
    for non-Out parameters. Returns a list of (param_idx, ocaml_idx) pairs. *)
let build_param_to_ocaml_map (parameters : gir_param list) =
  List.fold_left
    ~f:(fun (param_idx, ocaml_idx, acc) param ->
      match param.direction with
      | Out -> (param_idx + 1, ocaml_idx, acc)
      | In | InOut ->
          (param_idx + 1, ocaml_idx + 1, (param_idx, ocaml_idx) :: acc))
    ~init:(0, 0, []) parameters
  |> fun (_, _, acc) -> List.rev acc

(* [extract_length_mappings in_param_indices param_to_ocaml_map]
    For each array param with a length index, maps the length param's OCaml idx to the length var.
    Returns a list of (length_ocaml_idx, length_var_name) pairs. *)
let extract_length_mappings in_param_indices param_to_ocaml_map =
  List.filter_map
    ~f:(fun (p, ocaml_idx) ->
      let* ai = p.param_type.array in
      let* length_idx = ai.length in
      (* Find the OCaml arg index for the length parameter by lookup *)
      let _, length_ocaml_idx =
        List.find ~f:(fun (idx, _) -> idx = length_idx) param_to_ocaml_map
      in
      let arg_name = Fmt.str "arg%d" (ocaml_idx + 1) in
      Some (length_ocaml_idx, arg_name ^ "_length"))
    in_param_indices

(* [build_length_param_map ~meth] builds a map from OCaml argument index to length variable name
    for array parameters. For each array parameter with a length parameter index, computes the
    corresponding OCaml argument index and maps it to a length variable name. This allows length
    parameters to be substituted with computed array lengths instead of passed as separate arguments.
    Only processes non-Out parameters (those visible in OCaml signature).
    Returns a list of (ocaml_idx, length_var_name) pairs. *)
let build_length_param_map ~(meth : gir_method) =
  let in_param_indices = compute_in_param_indices meth.parameters in
  let param_to_ocaml_map = build_param_to_ocaml_map meth.parameters in
  extract_length_mappings in_param_indices param_to_ocaml_map

(* [build_method_params ~ctx ~meth] processes method parameters to build C declarations,
   arguments, and cleanup code. Handles in/out/inout directions, array conversions,
   and nullable type conversions. Returns a tuple of (out_decls, c_args, param_cleanups). *)
let build_method_params ~ctx ~(meth : gir_method) =
  let length_param_map = build_length_param_map ~meth in

  let init_acc =
    {
      C_stub_helpers.ocaml_idx = 0;
      decls = Buffer.create 128;
      args = [];
      cleanups = [];
    }
  in
  let process_method_param ~ctx ~length_param_map param_index acc p =
    let tm = Type_mappings.find_type_mapping_for_gir_type ~ctx p.param_type in
    let c_type_str = C_stub_helpers.get_c_type_str ~ctx p.param_type in
    (* For array out parameters, c_type_str is the ARRAY type (e.g., "double*").
       For non-array out parameters, c_type_str is the parameter type (e.g., "int").
       We need the element/base type for declarations. *)
    let base_type = C_stub_helpers.base_c_type_of c_type_str in
    let new_acc =
      match p.direction with
      | Out -> handle_out_param ~param_index ~base_type ~acc p
      | InOut -> handle_inout_param ~ctx ~param_index ~base_type ~acc ~tm p
      | In -> handle_in_param ~ctx ~acc ~length_param_map ~base_type ~tm p
    in
    (new_acc, ())
  in
  let final_acc, _ =
    C_stub_helpers.fold_mapi meth.parameters ~init:init_acc
      ~f:(process_method_param ~ctx ~length_param_map)
  in
  (Buffer.contents final_acc.decls, final_acc.args, final_acc.cleanups)

(* [build_method_call ~meth ~c_name ~c_args] builds the C function call code.
   Returns the complete C call string with any necessary conversion code. *)
let build_method_call ~(meth : gir_method) ~c_name ~c_args =
  let args =
    String.concat ~sep:", " c_args ^ if meth.throws then ", &error" else ""
  in
  Fmt.str "%s(%s);" c_name args

(* [build_method_return ~ctx ~meth ~c_name ~c_args] handles return value conversion
   from C to OCaml. Generates conversion code for out-parameters and return values.
   Returns a tuple of (c_call_code, return_conversion_statement, cleanup_list). *)
let build_method_return ~ctx ~(meth : gir_method) ~c_name ~c_args =
  let ret_type = meth.return_type.c_type in
  let out_array_length_map =
    Out_conv.build_out_array_length_map meth.parameters
  in
  let out_array_conversions_buf = Buffer.create 256 in

  (* Collect out parameter conversions using rev_map for results and concat for cleanups *)
  let params_with_idx = List.mapi ~f:(fun i p -> (p, i)) meth.parameters in
  let results_rev, cleanups_rev =
    List.fold_left
      ~f:(fun (results_rev, cleanups_rev) (p, idx) ->
        let result, new_cleanups =
          Out_conv.process_out_param_conversion ~ctx ~out_array_length_map
            ~out_array_conversions_buf ~parameters:meth.parameters (p, idx)
        in
        match result with
        | Some r -> (r :: results_rev, List.rev_append new_cleanups cleanups_rev)
        | None -> (results_rev, List.rev_append new_cleanups cleanups_rev))
      ~init:([], []) params_with_idx
  in
  let out_conversions = List.rev results_rev in
  let out_array_cleanup_list = List.rev cleanups_rev in
  let out_array_conv_code = Buffer.contents out_array_conversions_buf in

  let c_call_code, ret_conv, return_cleanups =
    let args_str =
      String.concat ~sep:", " c_args ^ if meth.throws then ", &error" else ""
    in
    build_return_conversion ~ctx ~meth ~c_name ~args:args_str ~ret_type
      ~out_array_conv_code ~out_conversions ~out_array_cleanup_list
  in
  (c_call_code, ret_conv, return_cleanups)

(* [generate_c_method ~ctx ~c_type meth class_name] generates a C wrapper function for a GIR method.
    Takes self parameter (instance) and processes in/out/inout parameter conversions to/from OCaml.
    Handles C method invocation with proper argument passing, return value conversion (void/array/scalar),
    and post-call cleanup code. Uses length parameter maps for array parameter handling. Supports
    error handling if method throws GError. Generates both native and bytecode (multi-arg) variants
    when parameter count exceeds 5. Wraps with version guards if the class or method has a version.
    Returns the complete C function code as a string. *)
let generate_c_method ~ctx ~c_type (meth : gir_method) (_class_name : string) =
  let c_name = meth.c_identifier in
  let ml_name = Utils.ml_method_name meth in
  let in_params =
    List.filter
      ~f:(fun p -> match p.direction with Out -> false | In | InOut -> true)
      meth.parameters
  in
  let param_count = 1 + List.length in_params in
  let params =
    "value self"
    :: List.mapi ~f:(fun i _ -> Fmt.str "value arg%d" (i + 1)) in_params
  in
  let param_names =
    "self" :: List.mapi ~f:(fun i _ -> Fmt.str "arg%d" (i + 1)) in_params
  in

  let type_val_macro = Fmt.str "%s_val" c_type in
  let self_cast = Fmt.str "%s(self)" type_val_macro in

  (* Build C call - handle nullable parameters *)
  let out_decls, c_args, param_cleanups = build_method_params ~ctx ~meth in
  (* Add self to c_args *)
  let c_args = self_cast :: c_args in

  (* Build return conversion *)
  let locals = Buffer.create 256 in
  if meth.throws then Buffer.add_string locals "GError *error = NULL;\n";
  Buffer.add_string locals out_decls;
  let locals = Buffer.contents locals in
  let c_call, ret_conv, return_cleanups =
    build_method_return ~ctx ~meth ~c_name ~c_args
  in

  (* Emit cleanup code for arrays (both parameter and return cleanups) *)
  let all_cleanups = param_cleanups @ return_cleanups in
  let cleanup_section =
    if List.length all_cleanups > 0 then
      "\n    " ^ String.concat ~sep:"\n    " all_cleanups
    else ""
  in

  (* Generate the real method stub *)
  let real_stub =
    if param_count > 5 then
      let body_code =
        Fmt.str "%s\n%s%s\n%s" locals c_call cleanup_section ret_conv
      in
      C_stub_multi_param.generate_multi_param_function ~ml_name ~params
        ~param_names body_code
    else
      Fmt.str
        "\n\
         CAMLexport CAMLprim value %s(%s)\n\
         {\n\
         CAMLparam%d(%s);\n\
         %s\n\
         %s%s\n\
         %s\n\
         }\n"
        ml_name
        (String.concat ~sep:", " params)
        param_count
        (String.concat ~sep:", " param_names)
        locals c_call cleanup_section ret_conv
  in

  (* Note: Version guards should only be emitted at the class level in gir_gen.ml
     If we are here, it means the class has no version but this member does.
     Only emit member-level guard in that case. *)
  real_stub
