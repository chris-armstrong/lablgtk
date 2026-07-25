(* Layer 1 Property - Property generation for OCaml interfaces *)

open Printf
open Types

(** Check if the type mapping exists for this property *)
let has_property_type_mapping ~ctx (prop : gir_property) =
  Option.is_some
    (Type_mappings.find_type_mapping_for_gir_type ~ctx prop.prop_type)

(** Check if a property getter should be generated *)
let should_generate_property_getter (prop : gir_property) = prop.readable

(** Check if a property setter should be generated *)
let should_generate_property_setter (prop : gir_property) =
  prop.writable && not prop.construct_only

(** Generate a property getter external declaration *)
let generate_property_getter ~ctx ~class_name ~buf (prop : gir_property)
    type_mapping =
  let prop_snake, prop_ocaml_type =
    Layer1_helpers.property_naming ~prop ~type_mapping
  in
  let getter_name = sprintf "get_%s" prop_snake in
  let c_getter = Utils.ml_property_name ~ctx ~class_name prop in
  bprintf buf "(** Get property: %s *)\n" prop.prop_name;
  bprintf buf "external %s : t -> %s = \"%s\"\n\n" getter_name prop_ocaml_type
    c_getter

(** Generate a property setter external declaration *)
let generate_property_setter ~ctx ~class_name ~buf (prop : gir_property)
    type_mapping =
  let prop_snake, prop_ocaml_type =
    Layer1_helpers.property_naming ~prop ~type_mapping
  in
  let setter_name = sprintf "set_%s" prop_snake in
  let c_setter = Utils.ml_property_setter_name ~ctx ~class_name prop in
  bprintf buf "(** Set property: %s *)\n" prop.prop_name;
  bprintf buf "external %s : t -> %s -> unit = \"%s\"\n\n" setter_name
    prop_ocaml_type c_setter

(** Generate a single property's getter and/or setter declarations. Delegates to
    the shared [Filtering.should_generate_property] so that layer 0 (C stubs)
    and layer 1 (OCaml externals) agree on what is emitted. *)
let generate_property_decl ~ctx ~class_name ~buf ~methods (prop : gir_property)
    =
  if Filtering.should_generate_property ~ctx ~class_name ~methods prop then
    match Type_mappings.find_type_mapping_for_gir_type ~ctx prop.prop_type with
    | Some type_mapping ->
        if should_generate_property_getter prop then
          generate_property_getter ~ctx ~class_name ~buf prop type_mapping;
        if should_generate_property_setter prop then
          generate_property_setter ~ctx ~class_name ~buf prop type_mapping
    | None -> ()
