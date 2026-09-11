(* GENERATED CODE - DO NOT EDIT *)
(* StyleProvider: StyleProvider *)

type t = [ `style_provider ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_style_provider_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gtk_style_provider_from_gobject"

(* Methods *)
let on_gtk_private_changed ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"gtk-private-changed" ~callback
    ~after:(Option.value after ~default:false)
