(* Method conflict detection for class generation *)

open StdLabels
open Printf
open Types
module StringSet = Common.StringSet

type module_names = Common.module_names
type property_filters = Common.property_filters

(* Helper to sanitize class/enum names *)
let sanitize_name s =
  s
  |> String.map ~f:(function '-' -> '_' | c -> c)
  |> Utils.to_snake_case |> Utils.sanitize_identifier

(* Helper to get OCaml method name for a method *)
let ocaml_method_name ~class_name ~c_type (meth : gir_method) =
  Utils.ocaml_method_name ~class_name ~c_type meth.method_name |> sanitize_name

(* Helper to get method signature for comparison *)
let method_signature_for_comparison (meth : gir_method) : string =
  (* Create a comparable signature from parameter types *)
  let param_sig =
    List.map meth.parameters ~f:(fun p -> p.param_type.name)
    |> String.concat ~sep:","
  in
  sprintf "%s(%s)->%s" meth.method_name param_sig meth.return_type.name

(* Get all methods from a class *)
let get_class_methods ~ctx class_name : gir_method list =
  match
    List.find_opt
      ~f:(fun cls -> String.equal cls.class_name class_name)
      ctx.classes
  with
  | Some cls -> cls.methods
  | None -> []

(* Helper: Get parent name from class if it exists *)
let get_parent_name_opt ~ctx class_name : string option =
  match
    List.find_opt
      ~f:(fun cls -> String.equal cls.class_name class_name)
      ctx.classes
  with
  | None -> None
  | Some cls -> cls.parent

(* Build parent chain for a class *)
let rec build_parent_chain ~ctx class_name : string list =
  match get_parent_name_opt ~ctx class_name with
  | None -> []
  | Some parent -> parent :: build_parent_chain ~ctx parent

(* Helper: Map a parent class to its method pairs *)
let map_parent_methods_to_pairs ~ctx parent_name =
  let methods = get_class_methods ~ctx parent_name in
  List.map methods ~f:(fun meth -> (parent_name, meth))

(* Get all methods from parent chain *)
let get_parent_methods ~ctx ~parent_chain : (string * gir_method) list =
  List.concat_map parent_chain ~f:(map_parent_methods_to_pairs ~ctx)

(* Check if two methods have conflicting signatures *)
let methods_have_signature_conflict ~ctx:_ ~class_name ~c_type meth1 meth2 =
  let name1 = ocaml_method_name ~class_name ~c_type meth1 in
  let name2 = ocaml_method_name ~class_name ~c_type meth2 in

  (* Same name but different signatures *)
  if String.equal name1 name2 then
    let sig1 = method_signature_for_comparison meth1 in
    let sig2 = method_signature_for_comparison meth2 in
    not (String.equal sig1 sig2)
  else false

(* Helper: Check a single parent method for conflict *)
let check_parent_conflict ~ctx ~class_name ~c_type child_meth acc
    (_parent_name, parent_meth) =
  if
    methods_have_signature_conflict ~ctx ~class_name ~c_type child_meth
      parent_meth
  then
    let ocaml_name = ocaml_method_name ~class_name ~c_type child_meth in
    StringSet.add ocaml_name acc
  else acc

(* Helper: Process all parent methods for one child method *)
let process_child_against_parents ~ctx ~class_name ~c_type parent_methods acc
    child_meth =
  List.fold_left parent_methods ~init:acc
    ~f:(check_parent_conflict ~ctx ~class_name ~c_type child_meth)

(* Detect which methods conflict with parent methods *)
let detect_method_conflicts ~ctx ~class_name ~c_type ~methods : StringSet.t =
  let parent_chain = build_parent_chain ~ctx class_name in
  let parent_methods = get_parent_methods ~ctx ~parent_chain in
  List.fold_left ~init:StringSet.empty
    ~f:(process_child_against_parents ~ctx ~class_name ~c_type parent_methods)
    methods

(* Get properties for a class *)
let get_class_properties ~ctx class_name : gir_property list =
  match
    List.find_opt
      ~f:(fun cls -> String.equal cls.class_name class_name)
      ctx.classes
  with
  | Some cls -> cls.properties
  | None -> []

(* Get OCaml method names generated for a property (getter/setter) *)
let property_method_names (prop : gir_property) : string list =
  let prop_snake = Utils.ocaml_property_name prop.prop_name in
  let getter = prop_snake |> Utils.sanitize_identifier in
  let setter = "set_" ^ prop_snake |> Utils.sanitize_identifier in
  if prop.writable && not prop.construct_only then [ getter; setter ]
  else [ getter ]

(** Look up a cross-namespace class entry by "Namespace.Name" in the
    cross-references map. *)
let lookup_cross_ns_class ~ctx qualified_name : cross_reference_type option =
  match String.split_on_char ~sep:'.' qualified_name with
  | [ namespace; name ] ->
      let ncr = StringMap.find_opt namespace ctx.cross_references in
      let entity =
        Option.bind ncr (fun n -> StringMap.find_opt name n.ncr_entities)
      in
      Option.map (fun cr -> cr.cr_type) entity
  | _ -> None

(** Strip namespace qualifier from a name, returning the bare name. e.g.
    "Gio.ActionGroup" -> "ActionGroup", "ActionGroup" -> "ActionGroup" *)
let bare_name qualified =
  match String.split_on_char ~sep:'.' qualified with
  | [ _; bare ] -> bare
  | _ -> qualified

(** Return true if [iface_name] and [candidate] refer to the same interface,
    comparing bare names to handle mixed qualified/unqualified forms. *)
let iface_names_match ~iface_name candidate =
  String.equal (bare_name iface_name) (bare_name candidate)

(** Check whether a cross-namespace class (by "Namespace.Name") or any of its
    ancestors provides [iface_name]. Traverses same-namespace parents within the
    foreign namespace by qualifying them with the current namespace.
    Depth-limited to 100 to avoid loops on malformed data. *)
let rec cross_ns_class_provides_interface ~ctx ~depth ~ns qualified_class_name
    iface_name =
  if depth > 100 then false
  else
    match lookup_cross_ns_class ~ctx qualified_class_name with
    | None
    | Some Crt_Interface
    | Some (Crt_Record _)
    | Some Crt_Enum
    | Some Crt_Bitfield
    | Some Crt_Constant ->
        false
    | Some (Crt_Class { implements; parent }) ->
        let implements_match =
          List.exists ~f:(iface_names_match ~iface_name) implements
        in
        let parent_match =
          match parent with
          | None -> false
          | Some p when String.contains p '.' ->
              cross_ns_class_provides_interface ~ctx ~depth:(depth + 1) ~ns p
                iface_name
          | Some p ->
              (* Same-namespace parent within the foreign namespace — qualify and recurse *)
              cross_ns_class_provides_interface ~ctx ~depth:(depth + 1) ~ns
                (ns ^ "." ^ p)
                iface_name
        in
        implements_match || parent_match

(** Return true if any class in the transitive parent chain of [class_name]
    lists [iface_name] in its implements. Used to detect diamond interface
    inheritance so the child can skip re-emitting an interface already provided
    by a parent, avoiding OCaml warning 7 (method-override).

    Traverses cross-namespace parents via the cross-references map when the
    parent name contains a dot (e.g. "Gio.Application"). *)
let parent_chain_provides_interface ~ctx ~class_name iface_name : bool =
  let parent_chain = build_parent_chain ~ctx class_name in
  List.exists parent_chain ~f:(fun ancestor ->
      if String.contains ancestor '.' then
        let ancestor_ns =
          String.sub ancestor ~pos:0 ~len:(String.index ancestor '.')
        in
        cross_ns_class_provides_interface ~ctx ~depth:0 ~ns:ancestor_ns ancestor
          iface_name
      else
        match
          List.find_opt
            ~f:(fun cls -> String.equal cls.class_name ancestor)
            ctx.classes
        with
        | None -> false
        | Some cls ->
            List.exists cls.implements ~f:(iface_names_match ~iface_name))

(* Collect all OCaml method names inherited from ancestors (methods + properties).
   Used to detect conflicts when inheriting from the parent class type. *)
let collect_inherited_method_names ~ctx ~class_name : StringSet.t =
  let parent_chain = build_parent_chain ~ctx class_name in
  let names = StringSet.empty in
  (* Add method names from all ancestors *)
  let names =
    List.fold_left parent_chain ~init:names ~f:(fun acc parent_name ->
        let methods = get_class_methods ~ctx parent_name in
        let parent_c_type =
          match
            List.find_opt
              ~f:(fun cls -> String.equal cls.class_name parent_name)
              ctx.classes
          with
          | Some cls -> cls.c_type
          | None -> ""
        in
        List.fold_left methods ~init:acc ~f:(fun acc meth ->
            StringSet.add
              (ocaml_method_name ~class_name:parent_name ~c_type:parent_c_type
                 meth)
              acc))
  in
  (* Add property-generated method names from all ancestors *)
  let names =
    List.fold_left parent_chain ~init:names ~f:(fun acc parent_name ->
        let props = get_class_properties ~ctx parent_name in
        List.fold_left props ~init:acc ~f:(fun acc prop ->
            List.fold_left (property_method_names prop) ~init:acc
              ~f:(fun acc n -> StringSet.add n acc)))
  in
  (* Also collect method names from implemented interfaces (interface methods
     are provided via `inherit GIface.iface_t`, so we must not re-emit them) *)
  let class_implements =
    match
      List.find_opt
        ~f:(fun cls -> String.equal cls.class_name class_name)
        ctx.classes
    with
    | Some cls -> cls.implements
    | None -> []
  in
  let names =
    List.fold_left class_implements ~init:names ~f:(fun acc iface_name ->
        match
          List.find_opt
            ~f:(fun iface -> String.equal iface.interface_name iface_name)
            ctx.interfaces
        with
        | None -> acc
        | Some iface ->
            List.fold_left iface.methods ~init:acc ~f:(fun acc meth ->
                StringSet.add
                  (ocaml_method_name ~class_name:iface_name ~c_type:iface.c_type
                     meth)
                  acc))
  in
  names
