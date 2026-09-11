(* GENERATED CODE - DO NOT EDIT *)
(* EmojiChooser: EmojiChooser *)

type t =
  [ `emoji_chooser | `popover | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_emoji_chooser_get_type"

external new_ : unit -> t = "ml_gtk_emoji_chooser_new"
(** Create a new EmojiChooser *)

(* Methods *)
val on_emoji_picked :
  ?after:bool ->
  t ->
  callback:(text:string -> unit) ->
  Gobject.Signal.handler_id
