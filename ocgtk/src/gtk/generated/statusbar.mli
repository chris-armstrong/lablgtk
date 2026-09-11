(* GENERATED CODE - DO NOT EDIT *)
(* Statusbar: Statusbar *)

type t = [ `statusbar | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_statusbar_get_type"

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

val on_text_popped :
  ?after:bool ->
  t ->
  callback:(context_id:int -> text:string -> unit) ->
  Gobject.Signal.handler_id

val on_text_pushed :
  ?after:bool ->
  t ->
  callback:(context_id:int -> text:string -> unit) ->
  Gobject.Signal.handler_id
