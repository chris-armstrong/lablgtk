(* Class-specific type resolution functions
   This module contains layer 2 type resolution: resolve_ocaml_type, resolve_layer2_class_ref,
   and class_gen-specific logic for polymorphic types and structural types.
 *)

open StdLabels
open Types

(* Use Class_gen_helpers for shared functions
   Note: open StdLabels is needed here despite Class_gen_helpers having it,
   because opens don't propagate through include *)
include Class_gen_helpers

(** Qualify a layer 2 class type name (with _t suffix) with the module prefix
    when the class is from a different module. *)
let qualify_layer2_class_type ~current_layer2_module lc =
  if String.equal current_layer2_module lc.class_module then lc.class_type
  else lc.class_module ^ "." ^ lc.class_type

(** Like qualify_layer2_class but returns the bare class name (no _t suffix)
    for use in [new] expressions. *)
let qualify_layer2_class_name ~current_layer2_module lc =
  if String.equal current_layer2_module lc.class_module then lc.class_ml_name
  else lc.class_module ^ "." ^ lc.class_ml_name

let find_layer2_class_for_type ~ctx gir_type =
  match Type_mappings.find_type_mapping_for_gir_type ~ctx gir_type with
  | Some { layer2_class = Some lc; _ } -> Some lc
  | _ -> None

(** Resolve a GIR type to its layer 2 class type reference (with _t suffix).
    Returns the fully qualified type reference if found, or None if no mapping
    exists. If the class is in the current module, returns just the type name.
*)
let resolve_layer2_class_ref ~ctx ~current_layer2_module ~(gir_type : gir_type)
    =
  find_layer2_class_for_type ~ctx gir_type
  |> Option.map (qualify_layer2_class_type ~current_layer2_module)

(** Like resolve_layer2_class_ref but returns the class name (without _t
    suffix), for use in [new] expressions. *)
let resolve_layer2_class_name ~ctx ~current_layer2_module ~(gir_type : gir_type)
    =
  find_layer2_class_for_type ~ctx gir_type
  |> Option.map (qualify_layer2_class_name ~current_layer2_module)

(** Resolve a GIR type to its OCaml type string. Returns the OCaml type
    representation with proper nullable handling. Returns None if no type
    mapping exists. *)
let resolve_ocaml_type ~ctx ~current_layer2_module ~(gir_type : gir_type) =
  let qualify = qualify_layer2_class_type ~current_layer2_module in
  let list_l2_type =
    if Gir_type_pred.is_list gir_type then
      match gir_type.array with
      | Some arr ->
        (match find_layer2_class_for_type ~ctx arr.element_type with
         | Some lc -> Some (qualify lc ^ " list")
         | None -> None)
      | None -> None
    else None
  in
  let base_type =
    match list_l2_type with
    | Some t -> Some t
    | None -> (
      match find_layer2_class_for_type ~ctx gir_type with
      | Some lc -> Some (qualify lc)
      | None ->
        (match Type_mappings.find_type_mapping_for_gir_type ~ctx gir_type with
         | Some mapping -> Some mapping.ocaml_type
         | None -> None))
  in
  match base_type with
  | Some base when gir_type.nullable -> Some (base ^ " option")
  | _ -> base_type

let map_param_sig ~ctx ~same_cluster_classes:_ ~current_layer2_module p =
  (* Regular type *)
  let gir_type =
    { p.param_type with nullable = p.nullable || p.param_type.nullable }
  in
  resolve_ocaml_type ~ctx ~current_layer2_module ~gir_type |> Option.get

(* No longer needed - class types are used directly without # prefix.
   Kept as identity function for API compatibility. *)
let convert_to_partial_object_type ~ctx:_ ~current_layer2_module:_
    ~same_cluster_classes:_ ~param_info:_ type_str =
  type_str
