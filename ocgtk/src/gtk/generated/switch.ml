(* GENERATED CODE - DO NOT EDIT *)
(* Switch: Switch *)

type t = [ `switch | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_switch_get_type"

external new_ : unit -> t = "ml_gtk_switch_new"
(** Create a new Switch *)

(* Methods *)

external set_state : t -> bool -> unit = "ml_gtk_switch_set_state"
(** Sets the underlying state of the `GtkSwitch`.

    This function is typically called from a [signal@Gtk.Switch::state-set]
    signal handler in order to set up delayed state changes.

    See [signal@Gtk.Switch::state-set] for details. *)

external set_active : t -> bool -> unit = "ml_gtk_switch_set_active"
(** Changes the state of @self to the desired one. *)

external get_state : t -> bool = "ml_gtk_switch_get_state"
(** Gets the underlying state of the `GtkSwitch`. *)

external get_active : t -> bool = "ml_gtk_switch_get_active"
(** Gets whether the `GtkSwitch` is in its “on” or “off” state. *)

(* Properties *)

let on_activate ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"activate" ~callback
    ~after:(Option.value after ~default:false)

let on_state_set ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let state =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_boolean v
        in
        let result = callback ~state in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"state-set" ~callback:closure
    ~after:(Option.value after ~default:false)
