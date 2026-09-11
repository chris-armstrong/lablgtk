(* GENERATED CODE - DO NOT EDIT *)
(* AsyncResult: AsyncResult *)

type t = [ `async_result ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gio_async_result_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gio_async_result_from_gobject"

(* Methods *)

external legacy_propagate_error : t -> (bool, GError.t) result
  = "ml_g_async_result_legacy_propagate_error"
(** If @res is a [class@Gio.SimpleAsyncResult], this is equivalent to
[method@Gio.SimpleAsyncResult.propagate_error]. Otherwise it returns
`FALSE`.

This can be used for legacy error handling in async `*_finish()`
wrapper functions that traditionally handled [class@Gio.SimpleAsyncResult]
error returns themselves rather than calling into the virtual method.
This should not be used in new code; [iface@Gio.AsyncResult] errors that are
set by virtual methods should also be extracted by virtual methods,
to enable subclasses to chain up correctly. *)

external get_source_object : t -> [ `object_ ] Gobject.obj option
  = "ml_g_async_result_get_source_object"
(** Gets the source object from a [iface@Gio.AsyncResult]. *)
