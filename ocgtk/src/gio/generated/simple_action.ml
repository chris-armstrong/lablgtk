(* GENERATED CODE - DO NOT EDIT *)
(* SimpleAction: SimpleAction *)

type t = [ `simple_action | `object_ ] Gobject.obj

external new_ : string -> Gvariant_type.t option -> t = "ml_g_simple_action_new"
(** Create a new SimpleAction *)

external new_stateful : string -> Gvariant_type.t option -> Gvariant.t -> t
  = "ml_g_simple_action_new_stateful"
(** Create a new SimpleAction *)

(* Methods *)

external set_state_hint : t -> Gvariant.t option -> unit
  = "ml_g_simple_action_set_state_hint"
(** Sets the state hint for the action.

    See g_action_get_state_hint() for more information about action state hints.
*)

external set_state : t -> Gvariant.t -> unit = "ml_g_simple_action_set_state"
(** Sets the state of the action.

This directly updates the 'state' property to the given value.

This should only be called by the implementor of the action.  Users
of the action should not attempt to directly modify the 'state'
property.  Instead, they should call g_action_change_state() to
request the change.

If the @value GVariant is floating, it is consumed. *)

external set_enabled : t -> bool -> unit = "ml_g_simple_action_set_enabled"
(** Sets the action as enabled or not.

    An action must be enabled in order to be activated or in order to have its
    state changed from outside callers.

    This should only be called by the implementor of the action. Users of the
    action should not attempt to modify its enabled flag. *)

(* Properties *)

external get_name : t -> string = "ml_g_simple_action_get_name"
(** Get property: name *)

external get_parameter_type : t -> Gvariant_type.t
  = "ml_g_simple_action_get_parameter_type"
(** Get property: parameter-type *)

external get_state_type : t -> Gvariant_type.t
  = "ml_g_simple_action_get_state_type"
(** Get property: state-type *)

let on_activate ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let parameter =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_variant_opt v
        in
        callback ~parameter)
  in
  Gobject.Signal.connect obj ~name:"activate" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_change_state ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let value =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_variant v
        in
        callback ~value)
  in
  Gobject.Signal.connect obj ~name:"change-state" ~callback:closure
    ~after:(Option.value after ~default:false)
