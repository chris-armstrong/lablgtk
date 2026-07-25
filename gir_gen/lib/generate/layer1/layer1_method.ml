(* Layer 1 Method - Method generation for OCaml interfaces *)

open StdLabels
open Printf
open Types

(** Check if a method should be generated in the interface. Delegates to the
    shared [Filtering.should_skip_method_binding] so that layer 0 (C stubs) and
    layer 1 (OCaml externals) agree on what is emitted. [entity_kind] is
    forwarded so the predicate folds in the record copy/free/unref filter
    in one place. *)
let should_generate_method ~ctx ~entity_kind (meth : gir_method) =
  not (Filtering.should_skip_method_binding ~ctx ~entity_kind meth)

(** Build the OCaml method signature type string *)
let build_method_signature ~ctx ~class_name (meth : gir_method) =
  let param_types =
    List.filter_map
      ~f:(Layer1_helpers.convert_method_param_to_ocaml_type ~ctx ~class_name)
      meth.parameters
  in

  let ret_type_ocaml =
    if Utils.is_void_return_type meth.return_type then "unit"
    else
      Layer1_helpers.map_gir_type_to_ocaml ~ctx ~class_name
        ~gir_type:meth.return_type ~is_nullable:meth.return_type.nullable
  in

  let out_types =
    List.filter_map
      ~f:(Layer1_helpers.convert_out_param_to_ocaml_type ~ctx ~class_name)
      meth.parameters
  in

  let final_ret_type =
    Layer1_helpers.combine_return_and_out_types ret_type_ocaml out_types
  in
  let final_ret_type =
    if meth.throws then sprintf "(%s, GError.t) result" final_ret_type
    else final_ret_type
  in
  String.concat ~sep:" -> " ([ "t" ] @ param_types @ [ final_ret_type ])

(** Format an external method declaration with bytecode/native support for >5
    parameters *)
let format_method_external ~buf ~ocaml_name ~ml_name ~param_count ~full_type =
  bprintf buf "%s"
    (Layer1_helpers.format_external ~ocaml_name ~signature:full_type ~ml_name
       ~param_count)

(** Generate a single method declaration and write it to the buffer *)
let generate_method_decl ~ctx ~class_name ~c_type ~c_symbol_prefix ~entity_kind
    ~buf (meth : gir_method) =
  let ml_name = Utils.ml_method_name ~class_name meth in
  let ocaml_name =
    Utils.ocaml_function_name ~class_name ~c_type ?c_symbol_prefix
      meth.method_name
  in
  let in_params =
    List.filter ~f:(fun p -> Gir_type_pred.Gir_direction.is_in p.direction) meth.parameters
  in
  let param_count = 1 + List.length in_params in

  if should_generate_method ~ctx ~entity_kind meth then begin
    (match meth.doc with
    | Some doc -> bprintf buf "(** %s *)\n" (Utils.sanitize_doc doc)
    | None -> ());

    let full_type = build_method_signature ~ctx ~class_name meth in
    format_method_external ~buf ~ocaml_name ~ml_name ~param_count ~full_type
  end
