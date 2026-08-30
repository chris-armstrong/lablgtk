(* High-level class generation (Step 3) - Main orchestration module *)

[@@@warning "-32"]

open StdLabels
open Gen_buffer
open Types

(* Re-export Common module and helper functions *)
include Common

(* Re-export all helpers for convenience *)
include Class_gen_helpers
include Class_gen_conflict_detection
include Class_gen_property
include Class_gen_converter
include Class_gen_method
include Class_gen_body

(** Helper: Determine if a parameter is a class type and get its Layer 2 type *)
let get_param_layer2_type ~ctx ~current_layer2_module (param : gir_param) =
  match Type_mappings.find_type_mapping_for_gir_type ~ctx param.param_type with
  | Some { layer2_class = Some _; _ } ->
      (* This is a class type; resolve its Layer 2 type *)
      let gir_type =
        {
          param.param_type with
          nullable = param.nullable || param.param_type.nullable;
        }
      in
      Class_gen_type_resolution.resolve_ocaml_type ~ctx ~current_layer2_module
        ~gir_type
  | _ ->
      (* Not a class type; return None *)
      None

(** Helper: Get the accessor name for unwrapping a Layer 2 class parameter *)
let get_accessor_name ~ctx (param : gir_param) =
  match Type_mappings.find_type_mapping_for_gir_type ~ctx param.param_type with
  | Some { layer2_class = Some layer2_class; _ } ->
      layer2_class.class_layer1_accessor
  | _ -> "as_" ^ Utils.ocaml_class_name param.param_type.name

(** Helper: Generate parameter type for constructor wrapper (Layer 2 for
    classes, Layer 1 otherwise) *)
let get_constructor_param_type ~ctx ~current_layer2_module (param : gir_param) =
  match get_param_layer2_type ~ctx ~current_layer2_module param with
  | Some layer2_type -> layer2_type
  | None ->
      Layer1.Layer1_helpers.map_constructor_param ~ctx ~class_name:"" param

type constructor_param_info = {
  cp_name : string;
  cp_type : string;
  cp_is_class : bool;
  cp_param : gir_param;
}
(** Collected info about a single constructor parameter *)

(** Collect parameter info for a constructor *)
let collect_constructor_params ~ctx ~current_layer2_module
    (ctor : gir_constructor) =
  List.map ctor.ctor_parameters ~f:(fun param ->
      let cp_name = Utils.ocaml_parameter_name param.param_name in
      let cp_type =
        get_constructor_param_type ~ctx ~current_layer2_module param
      in
      let cp_is_class =
        get_param_layer2_type ~ctx ~current_layer2_module param
        |> Option.is_some
      in
      { cp_name; cp_type; cp_is_class; cp_param = param })

(** Generate parameter unwrapping let-bindings for class-typed params *)
let generate_param_unwrapping ~ctx ~buf params =
  List.iter params ~f:(fun pi ->
      if pi.cp_is_class then begin
        let accessor = get_accessor_name ~ctx pi.cp_param in
        if pi.cp_param.nullable || pi.cp_param.param_type.nullable then
          bprintf buf "  let %s = Option.map (fun c -> c#%s) %s in\n" pi.cp_name
            accessor pi.cp_name
        else bprintf buf "  let %s = %s#%s in\n" pi.cp_name pi.cp_name accessor
      end)

let calculate_return_type ~class_type_name ctor =
  let return_type =
    match ctor.throws with
    | true -> Fmt.str "(%s, GError.t) result" class_type_name
    | false -> class_type_name
  in
  return_type

(** Generate a constructor wrapper implementation *)
let generate_constructor_impl ~ctx ~buf ~class_snake ~class_type_name
    ~current_layer2_module ~layer1_ctor_prefix (ctor : gir_constructor) =
  if not (Filtering.should_generate_constructor ~ctx ctor) then ()
  else
    let ocaml_ctor_name = Utils.ocaml_constructor_name ~class_name:"" ctor in
    let params = collect_constructor_params ~ctx ~current_layer2_module ctor in
    let return_type = calculate_return_type ~class_type_name ctor in
    match params with
    | [] ->
        bprintf buf "let %s () : %s =\n" ocaml_ctor_name return_type;
        bprintf buf "  new %s (%s.%s ())\n\n" class_snake layer1_ctor_prefix
          ocaml_ctor_name
    | _ ->
        let sig_str =
          String.concat ~sep:" "
            (List.map params ~f:(fun pi ->
                 Fmt.str "(%s : %s)" pi.cp_name pi.cp_type))
        in
        bprintf buf "let %s %s : %s =\n" ocaml_ctor_name sig_str return_type;
        generate_param_unwrapping ~ctx ~buf params;
        let call_str =
          String.concat ~sep:" " (List.map params ~f:(fun pi -> pi.cp_name))
        in
        bprintf buf "  let obj_ = %s.%s %s in\n" layer1_ctor_prefix
          ocaml_ctor_name call_str;
        if ctor.throws then
          bprintf buf "Result.map (fun obj_ ->  new %s obj_) obj_\n\n"
            class_snake
        else bprintf buf "  new %s obj_\n\n" class_snake

(** Generate a constructor wrapper signature *)
let generate_constructor_sig ~ctx ~buf ~class_type_name ~current_layer2_module
    (ctor : gir_constructor) =
  if not (Layer1.Layer1_constructor.should_generate_constructor ~ctx ctor) then
    ()
  else
    let ocaml_ctor_name = Utils.ocaml_constructor_name ~class_name:"" ctor in
    let params = collect_constructor_params ~ctx ~current_layer2_module ctor in
    let return_type = calculate_return_type ~class_type_name ctor in
    match params with
    | [] -> bprintf buf "val %s : unit -> %s\n" ocaml_ctor_name return_type
    | _ ->
        let sig_str =
          String.concat ~sep:""
            (List.map params ~f:(fun pi -> Fmt.str "%s -> " pi.cp_type))
        in
        bprintf buf "val %s : %s%s\n" ocaml_ctor_name sig_str return_type

(** Generate a class module (implementation) *)
let generate_class_module ~ctx ~class_name ~c_type ~parent_chain ~methods
    ~entity_kind ~properties ~signals ~constructors =
  let buf = Buffer.create 2048 in
  let module_names = get_module_names ~ctx class_name in
  let class_snake = sanitize_name class_name in
  let class_type_name = Utils.class_type_name class_name in
  let parent_name = match parent_chain with p :: _ -> Some p | [] -> None in

  (* Class type definition *)
  bprintf buf "class type %s = object\n" class_type_name;

  generate_class_signature_body ~ctx ~buf
    ~layer1_module_name:module_names.layer1
    ~current_layer2_module:module_names.layer2 ~class_name ~class_snake ~c_type
    ~methods ~entity_kind ~properties ~signals
    ~same_cluster_classes:[ class_name ] ~parent_name ();

  bprintf buf "end\n\n";

  (* Class implementation *)
  bprintf buf "(* High-level class for %s *)\n" class_name;
  bprintf buf "class %s (obj : %s.t) : %s = object (self)\n" class_snake
    module_names.layer1 class_type_name;

  generate_class_module_body ~ctx ~buf ~layer1_module_name:module_names.layer1
    ~current_layer2_module:module_names.layer2 ~class_name ~class_snake ~c_type
    ~methods ~entity_kind ~properties ~signals
    ~same_cluster_classes:[ class_name ] ~parent_name ();

  bprintf buf "end\n\n";

  (* Constructor wrappers *)
  List.iter constructors
    ~f:
      (generate_constructor_impl ~ctx ~buf ~class_snake ~class_type_name
         ~current_layer2_module:module_names.layer2
         ~layer1_ctor_prefix:module_names.layer1);

  Buffer.contents buf

(** Generate a class signature *)
let generate_class_signature ~ctx ~class_name ~c_type ~parent_chain ~methods
    ~entity_kind ~properties ~signals ~constructors =
  let buf = Buffer.create 1024 in
  let module_names = get_module_names ~ctx class_name in
  let class_snake = sanitize_name class_name in
  let class_type_name = Utils.class_type_name class_name in
  let parent_name = match parent_chain with p :: _ -> Some p | [] -> None in

  (* Class type definition *)
  bprintf buf "class type %s = object\n" class_type_name;

  generate_class_signature_body ~ctx ~buf
    ~layer1_module_name:module_names.layer1
    ~current_layer2_module:module_names.layer2 ~class_name ~class_snake ~c_type
    ~methods ~entity_kind ~properties ~signals
    ~same_cluster_classes:[ class_name ] ~parent_name ();

  bprintf buf "end\n\n";

  (* Class declaration referencing the class type *)
  bprintf buf "class %s : %s.t -> %s\n\n" class_snake module_names.layer1
    class_type_name;

  (* Constructor wrappers *)
  List.iter constructors
    ~f:
      (generate_constructor_sig ~ctx ~buf ~class_type_name
         ~current_layer2_module:module_names.layer2);

  Buffer.contents buf

(** Common helper for generating combined class entities (both impl and sig) *)
let generate_combined_entities ~ctx ~combined_module_name ~entities
    ~parent_chain_for_entity ~header_text ~generate_entity =
  let buf = Buffer.create 4096 in
  bprintf buf "%s\n" header_text;

  let current_layer2_module = "G" ^ combined_module_name in
  let sorted_entities =
    List.sort ~cmp:(fun e1 e2 -> String.compare e1.name e2.name) entities
  in
  let same_cluster_classes = List.map sorted_entities ~f:(fun e -> e.name) in

  List.iteri
    ~f:(fun i entity ->
      let parent_chain = parent_chain_for_entity entity.name in
      let parent_name =
        match parent_chain with p :: _ -> Some p | [] -> None
      in
      let module_name =
        Class_utils.get_qualified_module_name ~ctx entity.name
      in
      let class_snake = sanitize_name entity.name in
      generate_entity ~buf ~i ~class_snake ~module_name ~current_layer2_module
        ~class_name:entity.name ~c_type:entity.c_type ~methods:entity.methods
        ~entity_kind:(Filtering.entity_kind_of_entity entity)
        ~properties:entity.properties ~signals:entity.signals
        ~same_cluster_classes ~parent_name)
    sorted_entities;

  Buffer.contents buf

(** Generate combined class modules for cyclic dependencies *)
let generate_combined_class_module ~ctx ~combined_module_name ~entities
    ~parent_chain_for_entity =
  let buf = Buffer.create 4096 in
  bprintf buf
    "(* GENERATED CODE - DO NOT EDIT *)\n\
     (* Combined classes for cyclic dependencies *)\n";

  (* Pass 1: class type definitions *)
  let generate_class_type ~buf ~i ~class_snake ~module_name:_
      ~current_layer2_module ~class_name ~c_type ~methods ~entity_kind
      ~properties ~signals ~same_cluster_classes ~parent_name =
    let class_type_name = Utils.class_type_name class_name in
    if i = 0 then bprintf buf "class type %s = object\n" class_type_name
    else bprintf buf "\nand %s = object\n" class_type_name;

    generate_class_signature_body ~ctx ~buf
      ~layer1_module_name:
        (Class_utils.get_qualified_module_name ~ctx class_name)
      ~current_layer2_module ~class_name ~class_snake ~c_type ~methods
      ~entity_kind ~properties ~signals ~same_cluster_classes ~parent_name ();

    bprintf buf "end\n"
  in

  let class_types_text =
    generate_combined_entities ~ctx ~combined_module_name ~entities
      ~parent_chain_for_entity ~header_text:""
      ~generate_entity:generate_class_type
  in
  Buffer.add_string buf class_types_text;
  bprintf buf "\n";

  (* Pass 2: class implementations *)
  let generate_class_impl ~buf ~i ~class_snake ~module_name
      ~current_layer2_module ~class_name ~c_type ~methods ~entity_kind
      ~properties ~signals ~same_cluster_classes ~parent_name =
    let class_type_name = Utils.class_type_name class_name in
    if i = 0 then
      bprintf buf "class %s (obj : %s.t) : %s = object (self)\n" class_snake
        module_name class_type_name
    else
      bprintf buf "\nand %s (obj : %s.t) : %s = object (self)\n" class_snake
        module_name class_type_name;

    generate_class_module_body ~ctx ~buf ~layer1_module_name:module_name
      ~current_layer2_module ~class_name ~class_snake ~c_type ~methods
      ~entity_kind ~properties ~signals ~same_cluster_classes ~parent_name ();

    bprintf buf "end\n"
  in

  let classes_text =
    generate_combined_entities ~ctx ~combined_module_name ~entities
      ~parent_chain_for_entity ~header_text:""
      ~generate_entity:generate_class_impl
  in
  Buffer.add_string buf classes_text;

  (* Constructor wrappers for each entity *)
  let current_layer2_module = "G" ^ combined_module_name in
  List.iter entities ~f:(fun entity ->
      let class_snake = sanitize_name entity.name in
      let class_type_name = Utils.class_type_name entity.name in
      let module_name =
        Class_utils.get_qualified_module_name ~ctx entity.name
      in
      List.iter entity.constructors
        ~f:
          (generate_constructor_impl ~ctx ~buf ~class_snake ~class_type_name
             ~current_layer2_module ~layer1_ctor_prefix:module_name));

  Buffer.contents buf

(** Generate combined class signatures for cyclic dependencies *)
let generate_combined_class_signature ~ctx ~combined_module_name ~entities
    ~parent_chain_for_entity =
  let buf = Buffer.create 4096 in

  (* Pass 1: class type definitions *)
  let generate_class_type ~buf ~i ~class_snake ~module_name:_
      ~current_layer2_module ~class_name ~c_type ~methods ~entity_kind
      ~properties ~signals ~same_cluster_classes ~parent_name =
    let class_type_name = Utils.class_type_name class_name in
    if i = 0 then bprintf buf "class type %s = object\n" class_type_name
    else bprintf buf "\nand %s = object\n" class_type_name;

    generate_class_signature_body ~ctx ~buf
      ~layer1_module_name:
        (Class_utils.get_qualified_module_name ~ctx class_name)
      ~current_layer2_module ~class_name ~class_snake ~c_type ~methods
      ~entity_kind ~properties ~signals ~same_cluster_classes ~parent_name ();

    bprintf buf "end\n"
  in

  let class_types_text =
    generate_combined_entities ~ctx ~combined_module_name ~entities
      ~parent_chain_for_entity ~header_text:""
      ~generate_entity:generate_class_type
  in
  Buffer.add_string buf class_types_text;
  bprintf buf "\n";

  (* Pass 2: class declarations referencing class types *)
  let generate_class_decl ~buf ~i ~class_snake ~module_name
      ~current_layer2_module:_ ~class_name ~c_type:_ ~methods:_ ~entity_kind:_
      ~properties:_ ~signals:_ ~same_cluster_classes:_ ~parent_name:_ =
    let class_type_name = Utils.class_type_name class_name in
    if i = 0 then
      bprintf buf "class %s : %s.t -> %s\n" class_snake module_name
        class_type_name
    else
      bprintf buf "\nand %s : %s.t -> %s\n" class_snake module_name
        class_type_name
  in

  let class_decls_text =
    generate_combined_entities ~ctx ~combined_module_name ~entities
      ~parent_chain_for_entity ~header_text:""
      ~generate_entity:generate_class_decl
  in
  Buffer.add_string buf class_decls_text;

  (* Constructor wrappers for each entity *)
  let current_layer2_module = "G" ^ combined_module_name in
  List.iter entities ~f:(fun entity ->
      let class_type_name = Utils.class_type_name entity.name in
      List.iter entity.constructors
        ~f:
          (generate_constructor_sig ~ctx ~buf ~class_type_name
             ~current_layer2_module));

  Buffer.contents buf

(** Generate cyclic shim module (implementation) *)
let generate_cyclic_shim_module ~ctx ~entity ~combined_module_name
    ~g_combined_module_name =
  let buf = Buffer.create 512 in

  (* Get the layer 1 module name for this entity *)
  let layer1_module_name = Utils.module_name_of_class entity.name in

  (* Generate the entity's lowercase name (e.g., "window" from "Window") *)
  let entity_snake = sanitize_name entity.name in

  (* Use the shim module as current_layer2_module so sibling types in the same
     cycle get qualified through the combined module, not left unqualified *)
  let current_layer2_module = Utils.layer2_module_name entity.name in
  let entity_type_name = Utils.class_type_name entity.name in

  bprintf buf "(* GENERATED CODE - DO NOT EDIT *)\n";
  bprintf buf "(* Shim module for %s from cyclic group %s *)\n\n" entity.name
    combined_module_name;
  bprintf buf "class type %s = %s.%s\n\n" entity_type_name
    g_combined_module_name entity_type_name;
  bprintf buf "class %s = %s.%s\n" entity_snake g_combined_module_name
    entity_snake;

  (* Constructor wrappers *)
  let layer1_ctor_prefix =
    Fmt.str "%s.%s" combined_module_name layer1_module_name
  in
  List.iter entity.constructors
    ~f:
      (generate_constructor_impl ~ctx ~buf ~class_snake:entity_snake
         ~class_type_name:entity_type_name ~current_layer2_module
         ~layer1_ctor_prefix);

  Buffer.contents buf

(** Generate cyclic shim signature *)
let generate_cyclic_shim_signature ~ctx ~entity ~combined_module_name
    ~g_combined_module_name =
  let buf = Buffer.create 512 in

  (* Get the layer 1 module name for this entity *)
  let layer1_module_name = Utils.module_name_of_class entity.name in

  (* Generate the entity's lowercase name (e.g., "window" from "Window") *)
  let entity_snake = sanitize_name entity.name in
  let entity_type_name = Utils.class_type_name entity.name in

  (* Use the shim module as current_layer2_module so sibling types get qualified *)
  let current_layer2_module = Utils.layer2_module_name entity.name in

  bprintf buf "(* GENERATED CODE - DO NOT EDIT *)\n";
  bprintf buf "(* Shim module for %s from cyclic group %s *)\n\n" entity.name
    combined_module_name;
  bprintf buf "class type %s = %s.%s\n\n" entity_type_name
    g_combined_module_name entity_type_name;
  bprintf buf "class %s : %s.%s.t -> %s\n" entity_snake combined_module_name
    layer1_module_name entity_type_name;

  (* Constructor wrapper signatures *)
  List.iter entity.constructors
    ~f:
      (generate_constructor_sig ~ctx ~buf ~class_type_name:entity_type_name
         ~current_layer2_module);
  bprintf buf "\n";

  Buffer.contents buf
