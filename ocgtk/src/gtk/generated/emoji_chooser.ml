(* GENERATED CODE - DO NOT EDIT *)
(* EmojiChooser: EmojiChooser *)

type t =
  [ `emoji_chooser | `popover | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external new_ : unit -> t = "ml_gtk_emoji_chooser_new"
(** Create a new EmojiChooser *)

(* Methods *)
let on_emoji_picked ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let text =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_string_exn v
        in
        callback ~text)
  in
  Gobject.Signal.connect obj ~name:"emoji-picked" ~callback:closure
    ~after:(Option.value after ~default:false)
