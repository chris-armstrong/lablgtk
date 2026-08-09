(* Layer 1 Helpers - Shared utilities for OCaml interface generation *)

open StdLabels
open Gen_buffer
open Types

(** Mode for generating code output *)
type output_mode =
  | Interface  (** Generate .mli interface file *)
  | Implementation  (** Generate .ml implementation file *)

(** Return the normalized class name and the polymorphic-variant hierarchy type
    [[`tag | ...] Gobject.obj] for the class and its parent chain. *)
let detect_class_hierarchy_names ~ctx:(_ : Types.generation_context) ~class_name
    ~parent_chain () =
  let normalized_class = Utils.normalize_class_name class_name in
  let parent_chain =
    (* parent_chain is ordered immediate parent -> root *)
    List.map ~f:Utils.normalize_class_name parent_chain
  in
  let self_tag =
    Utils.to_snake_case normalized_class |> Utils.sanitize_identifier
  in
  let parent_tags =
    List.filter_map parent_chain ~f:(fun p ->
        let tag = Utils.to_snake_case p |> Utils.sanitize_identifier in
        if String.equal tag self_tag then None else Some tag)
  in
  (* Deduplicate while preserving order *)
  let seen = Hashtbl.create 8 in
  let unique_tags =
    List.filter parent_tags ~f:(fun tag ->
        if Hashtbl.mem seen tag then false
        else begin
          Hashtbl.replace seen tag ();
          true
        end)
  in
  let all_variants = List.map (self_tag :: unique_tags) ~f:(fun t -> "`" ^ t) in
  let variants = String.concat ~sep:" | " all_variants in
  (class_name, Fmt.str "[%s] Gobject.obj" variants)

(** Indent content with 2 spaces, preserving empty lines *)
let print_indent contents buf =
  let lines = String.split_on_char ~sep:'\n' contents in
  (* Indent the content *)
  List.iter
    ~f:(fun line ->
      if String.trim line <> "" then bprintf buf "  %s\n" line
      else bprintf buf "\n")
    lines

(** Combine return type and output parameters into final type *)
let combine_return_and_out_types ret_type out_types =
  match (ret_type, out_types) with
  | "unit", [] -> "unit"
  | "unit", [ single ] -> single
  | "unit", lst -> String.concat ~sep:" * " lst
  | ret, [] -> ret
  | ret, lst -> String.concat ~sep:" * " (ret :: lst)

(** Check if any method handles the given property *)
let method_handles_property prop_name methods =
  List.exists
    ~f:(fun m ->
      m.set_property
      |> Option.map (String.equal prop_name)
      |> Option.value ~default:false
      || m.get_property
         |> Option.map (String.equal prop_name)
         |> Option.value ~default:false)
    methods

(** Map a GIR type to its OCaml representation with self-reference
    simplification. Returns "unit" for unknown types with a warning to stderr.
*)
let map_gir_type_to_ocaml ~ctx ~class_name ~gir_type ~is_nullable =
  match Type_mappings.find_type_mapping_for_gir_type ~ctx gir_type with
  | Some mapping ->
      let simplified_type =
        Type_mappings.simplify_self_reference ~class_name
          ~ocaml_type:mapping.ocaml_type
      in
      if is_nullable then Fmt.str "%s option" simplified_type
      else simplified_type
  | None ->
      Fmt.epr "Warning: Unknown type: name=%s type=%s\n" gir_type.name
        gir_type.name;
      "unit"

(** Convert a constructor parameter to its OCaml type representation *)
let map_constructor_param ~ctx ~class_name p =
  map_gir_type_to_ocaml ~ctx ~class_name ~gir_type:p.param_type
    ~is_nullable:p.nullable

(** Convert a method parameter to its OCaml type representation *)
let convert_method_param_to_ocaml_type ~ctx ~class_name p =
  match p.direction with
  | Out -> None
  | In | InOut ->
      Some
        (map_gir_type_to_ocaml ~ctx ~class_name ~gir_type:p.param_type
           ~is_nullable:p.nullable)

(** Convert an out parameter to its OCaml type representation *)
let convert_out_param_to_ocaml_type ~ctx ~class_name p =
  match p.direction with
  | Out ->
      Some
        (map_gir_type_to_ocaml ~ctx ~class_name ~gir_type:p.param_type
           ~is_nullable:p.nullable)
  | In | InOut -> None

(** [format_external ~ocaml_name ~signature ~ml_name ~param_count] formats an
    OCaml [external] declaration. For more than 5 parameters it splits the
    native and bytecode variants (the OCaml runtime's [CAMLparam5] limit means
    >5-parameter wrappers need a separate bytecode entry point); otherwise it
    emits a single external. Shared by the method and constructor layer-1
    emitters to avoid the byte-for-byte duplication that previously lived in
    both modules. *)
let format_external ~ocaml_name ~signature ~ml_name ~param_count =
  if param_count > 5 then
    Fmt.str "external %s : %s = \"%s_bytecode\" \"%s_native\"\n\n" ocaml_name
      signature ml_name ml_name
  else Fmt.str "external %s : %s = \"%s\"\n\n" ocaml_name signature ml_name

(** [property_naming ~prop ~type_mapping] computes the snake-cased property name
    and its OCaml type expression (option-wrapped when nullable), which the
    property getter and setter external emitters both need. *)
let property_naming ~(prop : gir_property) ~(type_mapping : type_mapping) =
  let prop_name_cleaned =
    String.map ~f:(function '-' -> '_' | c -> c) prop.prop_name
  in
  let prop_snake = Utils.to_snake_case prop_name_cleaned in
  let prop_ocaml_type =
    if prop.prop_type.nullable then Fmt.str "%s option" type_mapping.ocaml_type
    else type_mapping.ocaml_type
  in
  (prop_snake, prop_ocaml_type)
