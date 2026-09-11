(* GENERATED CODE - DO NOT EDIT *)
(* DisplayManager: DisplayManager *)

type t = [ `display_manager | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gdk_display_manager_get_type"

(* Methods *)

external set_default_display :
  t -> App_launch_context_cycle_de440b34.Display.t -> unit
  = "ml_gdk_display_manager_set_default_display"
(** Sets @display as the default display. *)

external open_display :
  t -> string option -> App_launch_context_cycle_de440b34.Display.t option
  = "ml_gdk_display_manager_open_display"
(** Opens a display. *)

external list_displays : t -> App_launch_context_cycle_de440b34.Display.t list
  = "ml_gdk_display_manager_list_displays"
(** List all currently open displays. *)

external get_default_display :
  t -> App_launch_context_cycle_de440b34.Display.t option
  = "ml_gdk_display_manager_get_default_display"
(** Gets the default `GdkDisplay`. *)

(* Properties *)

let on_display_opened ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let display =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (App_launch_context_cycle_de440b34.Display.gtype ())
        in
        callback ~display)
  in
  Gobject.Signal.connect obj ~name:"display-opened" ~callback:closure
    ~after:(Option.value after ~default:false)
