(* GENERATED CODE - DO NOT EDIT *)
(* AsyncInitable: AsyncInitable *)

type t = [ `async_initable ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_async_initable_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gio_async_initable_from_gobject"

(* Methods *)

external new_finish :
  t -> Async_result.t -> ([ `object_ ] Gobject.obj, GError.t) result
  = "ml_g_async_initable_new_finish"
(** Finishes the async construction for the various g_async_initable_new calls,
    returning the created object or %NULL on error. *)

external init_finish : t -> Async_result.t -> (bool, GError.t) result
  = "ml_g_async_initable_init_finish"
(** Finishes asynchronous initialization and returns the result. See
    g_async_initable_init_async(). *)
