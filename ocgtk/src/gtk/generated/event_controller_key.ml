(* GENERATED CODE - DO NOT EDIT *)
(* EventControllerKey: EventControllerKey *)

type t = [ `event_controller_key | `event_controller | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_event_controller_key_get_type"

external new_ : unit -> t = "ml_gtk_event_controller_key_new"
(** Create a new EventControllerKey *)

(* Methods *)

external set_im_context : t -> Im_context.t option -> unit
  = "ml_gtk_event_controller_key_set_im_context"
(** Sets the input method context of the key @controller. *)

external get_im_context : t -> Im_context.t option
  = "ml_gtk_event_controller_key_get_im_context"
(** Gets the input method context of the key @controller. *)

external get_group : t -> int = "ml_gtk_event_controller_key_get_group"
(** Gets the key group of the current event of this @controller.

See [method@Gdk.KeyEvent.get_layout]. *)

external forward :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  bool = "ml_gtk_event_controller_key_forward"
(** Forwards the current event of this @controller to a @widget.

This function can only be used in handlers for the
[signal@Gtk.EventControllerKey::key-pressed],
[signal@Gtk.EventControllerKey::key-released]
or [signal@Gtk.EventControllerKey::modifiers] signals. *)

let on_im_update ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"im-update" ~callback
    ~after:(Option.value after ~default:false)

let on_key_pressed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let keyval =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_uint v
        in
        let keycode =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_uint v
        in
        let state =
          let v = Gobject.Closure.nth argv ~pos:3 in
          Ocgtk_gdk.Gdk_enums.modifiertype_of_int
            (Gobject.Value.get_flags_int v)
        in
        let result = callback ~keyval ~keycode ~state in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"key-pressed" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_key_released ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let keyval =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_uint v
        in
        let keycode =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_uint v
        in
        let state =
          let v = Gobject.Closure.nth argv ~pos:3 in
          Ocgtk_gdk.Gdk_enums.modifiertype_of_int
            (Gobject.Value.get_flags_int v)
        in
        callback ~keyval ~keycode ~state)
  in
  Gobject.Signal.connect obj ~name:"key-released" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_modifiers ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let state =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Ocgtk_gdk.Gdk_enums.modifiertype_of_int
            (Gobject.Value.get_flags_int v)
        in
        let result = callback ~state in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"modifiers" ~callback:closure
    ~after:(Option.value after ~default:false)
