class type simple_action_t = object
  inherit GAction.action_t

  method on_activate :
    ?after:bool ->
    callback:(parameter:Gvariant.t option -> unit) ->
    unit ->
    Gobject.Signal.handler_id

  method on_change_state :
    ?after:bool ->
    callback:(value:Gvariant.t -> unit) ->
    unit ->
    Gobject.Signal.handler_id

  method set_enabled : bool -> unit
  method set_state : Gvariant.t -> unit
  method set_state_hint : Gvariant.t option -> unit
  method name : string
  method parameter_type : Gvariant_type.t
  method state_type : Gvariant_type.t
  method as_simple_action : Simple_action.t
end

(* High-level class for SimpleAction *)
class simple_action (obj : Simple_action.t) : simple_action_t =
  object (self)
    inherit GAction.action (Action.from_gobject obj)

    method on_activate ?(after = false) ~callback () =
      Simple_action.on_activate ~after self#as_simple_action ~callback

    method on_change_state ?(after = false) ~callback () =
      Simple_action.on_change_state ~after self#as_simple_action ~callback

    method set_enabled : bool -> unit =
      fun enabled -> Simple_action.set_enabled obj enabled

    method set_state : Gvariant.t -> unit =
      fun value -> Simple_action.set_state obj value

    method set_state_hint : Gvariant.t option -> unit =
      fun state_hint -> Simple_action.set_state_hint obj state_hint

    method name = Simple_action.get_name obj
    method parameter_type = Simple_action.get_parameter_type obj
    method state_type = Simple_action.get_state_type obj
    method as_simple_action = obj
  end

let new_ (name : string) (parameter_type : Gvariant_type.t option) :
    simple_action_t =
  let obj_ = Simple_action.new_ name parameter_type in
  new simple_action obj_

let new_stateful (name : string) (parameter_type : Gvariant_type.t option)
    (state : Gvariant.t) : simple_action_t =
  let obj_ = Simple_action.new_stateful name parameter_type state in
  new simple_action obj_
