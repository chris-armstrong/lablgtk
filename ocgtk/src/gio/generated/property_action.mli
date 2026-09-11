(* GENERATED CODE - DO NOT EDIT *)
(* PropertyAction: PropertyAction *)

type t = [ `property_action | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_property_action_get_type"

external new_ : string -> [ `object_ ] Gobject.obj -> string -> t
  = "ml_g_property_action_new"
(** Create a new PropertyAction *)

(* Methods *)
(* Properties *)

external get_enabled : t -> bool = "ml_g_property_action_get_enabled"
(** Get property: enabled *)

external get_invert_boolean : t -> bool
  = "ml_g_property_action_get_invert_boolean"
(** Get property: invert-boolean *)

external get_name : t -> string = "ml_g_property_action_get_name"
(** Get property: name *)

external get_parameter_type : t -> Gvariant_type.t
  = "ml_g_property_action_get_parameter_type"
(** Get property: parameter-type *)

external get_state : t -> Gvariant.t = "ml_g_property_action_get_state"
(** Get property: state *)

external get_state_type : t -> Gvariant_type.t
  = "ml_g_property_action_get_state_type"
(** Get property: state-type *)
