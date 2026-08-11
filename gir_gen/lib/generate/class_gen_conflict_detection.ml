(* Method conflict detection for class generation *)

open StdLabels
open Types
module StringSet = Common.StringSet

type module_names = Common.module_names
type property_filters = Common.property_filters

(** Sanitize a class/enum name into a valid OCaml identifier. *)
let sanitize_name s =
  s
  |> String.map ~f:(function '-' -> '_' | c -> c)
  |> Utils.to_snake_case |> Utils.sanitize_identifier

(** Compute the sanitized OCaml method name for a GIR method. *)
let ocaml_method_name (meth : gir_method) =
  Utils.ocaml_method_name meth.method_name |> sanitize_name

(** Build a comparable signature string for a method (name, parameter types,
    return type). *)
let method_signature_for_comparison (meth : gir_method) : string =
  (* Create a comparable signature from parameter types *)
  let param_sig =
    List.map meth.parameters ~f:(fun p -> p.param_type.name)
    |> String.concat ~sep:","
  in
  Fmt.str "%s(%s)->%s" meth.method_name param_sig meth.return_type.name

(** Return all methods of the class with the given name, or [] if absent. *)
let get_class_methods ~ctx class_name : gir_method list =
  match
    List.find_opt
      ~f:(fun cls -> String.equal cls.class_name class_name)
      ctx.classes
  with
  | Some cls -> cls.methods
  | None -> []

(** Return the parent class name of the given class, if any. *)
let get_parent_name_opt ~ctx class_name : string option =
  match
    List.find_opt
      ~f:(fun cls -> String.equal cls.class_name class_name)
      ctx.classes
  with
  | None -> None
  | Some cls -> cls.parent

(** Build the transitive parent chain of a class, immediate parent first. *)
let rec build_parent_chain ~ctx class_name : string list =
  match get_parent_name_opt ~ctx class_name with
  | None -> []
  | Some parent -> parent :: build_parent_chain ~ctx parent

(** Map a parent class to its [(parent_name, method)] pairs. *)
let map_parent_methods_to_pairs ~ctx parent_name =
  let methods = get_class_methods ~ctx parent_name in
  List.map methods ~f:(fun meth -> (parent_name, meth))

(** Collect all methods from the parent chain as [(parent_name, method)] pairs.
*)
let get_parent_methods ~ctx ~parent_chain : (string * gir_method) list =
  List.concat_map parent_chain ~f:(map_parent_methods_to_pairs ~ctx)

(** Return true when two methods map to the same OCaml name but have different
    signatures. *)
let methods_have_signature_conflict meth1 meth2 =
  let name1 = ocaml_method_name meth1 in
  let name2 = ocaml_method_name meth2 in

  (* Same name but different signatures *)
  if String.equal name1 name2 then
    let sig1 = method_signature_for_comparison meth1 in
    let sig2 = method_signature_for_comparison meth2 in
    not (String.equal sig1 sig2)
  else false

(** Add the child method's OCaml name to [acc] when it conflicts with the given
    parent method. *)
let check_parent_conflict child_meth acc (_parent_name, parent_meth) =
  if methods_have_signature_conflict child_meth parent_meth then
    let ocaml_name = ocaml_method_name child_meth in
    StringSet.add ocaml_name acc
  else acc

(** Fold [check_parent_conflict] over all parent methods for one child method.
*)
let process_child_against_parents parent_methods acc child_meth =
  List.fold_left parent_methods ~init:acc ~f:(check_parent_conflict child_meth)

(** Return the set of OCaml method names of [methods] that conflict with methods
    inherited from the parent chain. *)
let detect_method_conflicts ~ctx ~class_name ~methods : StringSet.t =
  let parent_chain = build_parent_chain ~ctx class_name in
  let parent_methods = get_parent_methods ~ctx ~parent_chain in
  List.fold_left ~init:StringSet.empty
    ~f:(process_child_against_parents parent_methods)
    methods

(** Return all properties of the class with the given name, or [] if absent. *)
let get_class_properties ~ctx class_name : gir_property list =
  match
    List.find_opt
      ~f:(fun cls -> String.equal cls.class_name class_name)
      ctx.classes
  with
  | Some cls -> cls.properties
  | None -> []

(** OCaml method names generated for a property: the getter, plus the setter
    when the property is writable. *)
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
        List.fold_left methods ~init:acc ~f:(fun acc meth ->
            StringSet.add (ocaml_method_name meth) acc))
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
                StringSet.add (ocaml_method_name meth) acc))
  in
  names
