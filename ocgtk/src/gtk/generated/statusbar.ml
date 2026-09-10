(* GENERATED CODE - DO NOT EDIT *)
(* Statusbar: Statusbar *)

type t = [ `statusbar | `widget | `initially_unowned | `object_ ] Gobject.obj

external new_ : unit -> t = "ml_gtk_statusbar_new"
(** Create a new Statusbar *)

(* Methods *)

external remove_all : t -> int -> unit = "ml_gtk_statusbar_remove_all"
(** Forces the removal of all messages from a statusbar's
stack with the exact @context_id. *)

external remove : t -> int -> int -> unit = "ml_gtk_statusbar_remove"
(** Forces the removal of a message from a statusbar’s stack.
The exact @context_id and @message_id must be specified. *)

external push : t -> int -> string -> int = "ml_gtk_statusbar_push"
(** Pushes a new message onto a statusbar’s stack. *)

external pop : t -> int -> unit = "ml_gtk_statusbar_pop"
(** Removes the first message in the `GtkStatusbar`’s stack with the given
    context id.

    Note that this may not change the displayed message, if the message at the
    top of the stack has a different context id. *)

external get_context_id : t -> string -> int = "ml_gtk_statusbar_get_context_id"
(** Returns a new context identifier, given a description of the actual context.

    Note that the description is not shown in the UI. *)

let on_text_popped ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let context_id =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_uint v
        in
        let text =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_string_exn v
        in
        callback ~context_id ~text)
  in
  Gobject.Signal.connect obj ~name:"text-popped" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_text_pushed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let context_id =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_uint v
        in
        let text =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_string_exn v
        in
        callback ~context_id ~text)
  in
  Gobject.Signal.connect obj ~name:"text-pushed" ~callback:closure
    ~after:(Option.value after ~default:false)
