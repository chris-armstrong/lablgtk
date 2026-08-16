(* Shared types for the class generation modules. *)

(** Set of strings, shared across the class generation modules so that
    [StringSet.t] values are interchangeable between them. *)
module StringSet :
  Set.S with type elt = string and type t = Set.Make(StdLabels.String).t

type module_names = {
  layer1 : string;  (** Layer 1 module name for the class. *)
  layer2 : string;  (** Layer 2 module name for the class. *)
}
(** Names of the generated layer 1 and layer 2 modules for a class. *)

type property_filters = {
  method_names : string list;
      (** OCaml names of the property accessors, used to avoid collisions. *)
  base_names : string list;  (** Base names of the property accessors. *)
}
(** Method-name and base-name filters used to decide which property accessors to
    generate. *)
