(* Helper functions extracted from class_gen.ml (Phase 1) *)

open StdLabels
open Types

(* Use Common.StringSet for type compatibility across modules *)
include Common

(* Helper types and functions *)

type module_names = { layer1 : string; layer2 : string }
type property_filters = { method_names : string list; base_names : string list }

(** Convert a GIR class name to its OCaml class name (e.g. "GtkWidget" ->
    "widget"). *)
let sanitize_name = Utils.ocaml_class_name

(* Helper: extract a value from an [option], failing with a descriptive error
   when [None]. Shared by the class_gen modules for unresolved GIR types. *)
let require_type ~location ~gir_type_name (type_opt : string option) : string =
  match type_opt with
  | Some t -> t
  | None ->
      failwith
        ("Gir_gen.class_gen: " ^ location ^ ": unresolved type " ^ gir_type_name)

(** Compute the layer 1 and layer 2 module names for a class. *)
let get_module_names ~ctx class_name =
  let layer1 = Class_utils.get_qualified_module_name ~ctx class_name in
  { layer1; layer2 = Utils.layer2_module_name class_name }

(** Compute the property method-name and base-name filters for a class. *)
let get_property_filters ~ctx ~class_name ~methods properties =
  {
    method_names =
      Filtering.property_method_names ~ctx ~class_name ~methods properties;
    base_names =
      Filtering.property_base_names ~ctx ~class_name ~methods properties;
  }

(* Helper to check if a class name is in the same cluster *)
let is_same_cluster_class ~same_cluster_classes class_name =
  List.mem class_name ~set:same_cluster_classes

(* Helper to generate class type reference for same-cluster class references *)
let structural_type_for_class ~ctx:_ class_name =
  Utils.class_type_name class_name

(** Compute the sanitized OCaml method name for a GIR method. *)
let ocaml_method_name ~class_name:_ ~c_type:_ (meth : gir_method) =
  Utils.ocaml_method_name meth.method_name |> sanitize_name

(** Return true when the type string contains a type-variable wildcard (e.g.
    "'a" in "_ Gdk.event"). *)
let has_type_variable type_str =
  (* Check if the type contains an type-variable wildcard (like "_ Gdk.event") *)
  let parts = Re.Str.split (Re.Str.regexp "[ \t]+") type_str in
  List.exists ~f:(fun part -> part = "'a") parts

let gir_type_of_name name =
  {
    Types.name;
    c_type = None;
    nullable = false;
    transfer_ownership = TransferNone;
    array = None;
  }

(** Resolve a parent class name to a [gir_type], returning [None] when the
    parent is absent or belongs to the same cyclic cluster. *)
let resolve_parent_gir_type ~same_cluster_classes ~parent_name =
  match parent_name with
  | None -> None
  | Some parent ->
      if List.exists ~f:(String.equal parent) same_cluster_classes then None
      else Some (gir_type_of_name parent)

(* Helper to determine if a method should be skipped during generation. The
   [entity_kind] is forwarded to the central
   [Filtering.should_skip_method_binding] so the record copy/free/unref
   filter is folded into the same answer. *)
let should_skip_method ~ctx ~entity_kind (meth : gir_method) =
  let has_out_param =
    List.exists meth.parameters ~f:(fun p ->
        Gir_type_pred.Gir_direction.has_output p.direction)
  in
  let should_skip_binding =
    Filtering.should_skip_method_binding ~ctx ~entity_kind meth
  in
  should_skip_binding || has_out_param
