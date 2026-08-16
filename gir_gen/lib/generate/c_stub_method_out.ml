(* C Stub Code Generation - Out Parameter Conversion *)

open Gen_buffer

(** This module provides out-parameter conversion functions for C stub
    generation. Handles conversion of output and inout parameters from C to
    OCaml representations for method return values. *)

open Containers
open StdLabels
open Types

(* Option binding operator for flattening nested Option.bind chains *)
let ( let* ) = Option.bind

(* Assertion-style option extraction for "impossible" None cases *)
let option_get_exn ~message o =
  match o with Some v -> v | None -> failwith message

module Log =
  (val Logs.src_log
         (Logs.Src.create "gir_gen.c_stub_method_out"
            ~doc:"C stub code generation for out parameter conversion"))

(* [get_element_c_type ~fallback array_info] extracts the C type of array elements.
   Returns the element_type's c_type if present, otherwise uses the fallback value.
   This is used to determine the base type for array element conversions. *)
let get_element_c_type ~fallback (array_info : gir_array) =
  array_info.element_type.c_type |> Option.value ~default:fallback

(* [safe_nth_opt parameters idx] safely accesses list element with bounds checking.
   Returns Some element if index is valid, None otherwise with a warning log.
   Used for GIR data validation to detect malformed/inconsistent index references. *)
let safe_nth_opt parameters idx =
  match List.nth_opt parameters idx with
  | Some v -> Some v
  | None ->
      Log.warn (fun m ->
          m "Invalid length param index %d (parameters length: %d)" idx
            (List.length parameters));
      None

(* [var_name_for_direction direction idx] generates a unique variable name based on parameter direction.
   Out parameters use "out<N>", InOut use "inout<N>", and In use "arg<N>".
   The index is 0-based but incremented by 1 in the name for human readability. *)
let var_name_for_direction direction idx =
  match direction with
  | Out -> Fmt.str "out%d" (idx + 1)
  | InOut -> Fmt.str "inout%d" (idx + 1)
  | In -> Fmt.str "arg%d" (idx + 1)

(* [convert_out_array ~ctx ~out_array_length_map ~out_array_conversions_buf
                 ~parameters ~idx ~var_name p array_info] converts
     an out-direction array parameter from C to OCaml. Looks up the array length from
     out_array_length_map (which maps parameter indices to length parameter indices) and
     uses type mapping for conversion. Appends conversion code to the buffer.
     Returns a tuple of (optional OCaml array variable name, cleanup code list). *)
let convert_out_array ~ctx ~out_array_length_map ~out_array_conversions_buf
    ~parameters ~idx ~var_name (p : gir_param) (array_info : gir_array) =
  let element_c_type_from_gir =
    match array_info.element_type.c_type with
    | Some ct -> ct
    | None ->
        Type_mappings.find_type_mapping_for_gir_type ~ctx
          array_info.element_type
        |> Option.map (fun (tm : type_mapping) -> tm.c_type)
        |> Option.value ~default:"void"
  in
  (* For out parameters, we declare the variable as T* (not T** ), so the actual
      array element type is T (not T* ). Strip one level of pointer from the GIR type. *)
  let element_c_type = C_stub_helpers.base_c_type_of element_c_type_from_gir in

  let length_expr =
    let* length_idx = List.assoc_opt idx out_array_length_map in
    let* param = safe_nth_opt parameters length_idx in
    Some (var_name_for_direction param.direction length_idx)
  in
  let* _mapping =
    Type_mappings.find_type_mapping_for_gir_type ~ctx p.param_type
  in
  let conv_code, ml_array_var, cleanup_code =
    C_stub_array_conv.Array_conv.generate_array_c_to_ml ~ctx ~var:var_name
      ~array_info ~length_expr ~element_c_type
      ~transfer_ownership:p.param_type.transfer_ownership ()
  in
  bprintf out_array_conversions_buf "    %s\n" conv_code;
  let cleanups =
    if String.length cleanup_code > 0 then [ cleanup_code ] else []
  in
  Some (Some ml_array_var, cleanups)

(* [convert_out_scalar ~ctx ~_idx ~var_name p] converts a scalar out-parameter from C to OCaml.
   Strips pointer suffix from the type (e.g., "GObject*" -> "GObject") and uses type mapping
   for conversion via nullable_c_to_ml_expr. Returns an optional OCaml value expression,
   or None if no type mapping is found for the parameter type. *)
let convert_out_scalar ~ctx ~_idx ~var_name (p : gir_param) =
  let base_gir_type =
    p.param_type.c_type
    |> Option.map (fun c_type ->
        let stripped = C_stub_helpers.base_c_type_of c_type in
        if String.equal stripped c_type then p.param_type
        else { p.param_type with c_type = Some stripped })
    |> Option.value ~default:p.param_type
  in
  Type_mappings.find_type_mapping_for_gir_type ~ctx base_gir_type
  |> Option.map (fun mapping ->
      C_stub_helpers.nullable_c_to_ml_expr ~ctx ~var:var_name
        ~gir_type:base_gir_type ~mapping ~direction:p.direction ())

(* [process_out_param_conversion ~ctx ~out_array_length_map ~out_array_conversions_buf
                               ~parameters (p, idx)] processes a single out or inout
     parameter for conversion to OCaml. In-direction parameters return None without processing.
     Out and InOut parameters generate conversion code and return the OCaml value expression.
     For arrays, uses array conversion logic; for scalars, uses scalar conversion.
     Returns a tuple of (optional OCaml value expression, cleanup code list). *)
let process_out_param_conversion ~ctx ~out_array_length_map
    ~out_array_conversions_buf ~parameters (p, idx) =
  match p.direction with
  | In -> (None, [])
  | Out | InOut -> (
      let var_name = var_name_for_direction p.direction idx in
      match p.param_type.array with
      | Some array_info ->
          let result, cleanups =
            convert_out_array ~ctx ~out_array_length_map
              ~out_array_conversions_buf ~parameters ~idx ~var_name p array_info
            |> Option.value ~default:(None, [])
          in
          (result, cleanups)
      | None ->
          let result = convert_out_scalar ~ctx ~_idx:idx ~var_name p in
          (result, []))

(* [build_out_array_length_map parameters] builds a map from array parameter index to its length
   parameter index for out/inout direction parameters. For each Out or InOut parameter with array type,
   extracts the length parameter index from array_info and creates a mapping. Used to look up which
   parameter holds the array length when converting out-parameter arrays from C to OCaml.
   Returns a list of (array_param_idx, length_param_idx) pairs. *)
let build_out_array_length_map parameters =
  List.fold_left
    ~f:(fun acc (p, idx) ->
      match (p.direction, p.param_type.array) with
      | (Out | InOut), Some array_info ->
          array_info.length
          |> Option.map (fun length_idx -> (idx, length_idx) :: acc)
          |> Option.value ~default:acc
      | _ -> acc)
    ~init:[]
    (List.mapi ~f:(fun i p -> (p, i)) parameters)
