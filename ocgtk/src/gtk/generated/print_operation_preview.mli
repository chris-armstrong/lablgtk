(* GENERATED CODE - DO NOT EDIT *)
(* PrintOperationPreview: PrintOperationPreview *)

type t = [ `print_operation_preview ] Gobject.obj

external gtype : unit -> Gobject.Type.t
  = "ml_gtk_print_operation_preview_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gtk_print_operation_preview_from_gobject"

(* Methods *)

external render_page : t -> int -> unit
  = "ml_gtk_print_operation_preview_render_page"
(** Renders a page to the preview.

This is using the print context that was passed to the
[signal@Gtk.PrintOperation::preview] handler together
with @preview.

A custom print preview should use this function to render
the currently selected page.

Note that this function requires a suitable cairo context to
be associated with the print context. *)

external is_selected : t -> int -> bool
  = "ml_gtk_print_operation_preview_is_selected"
(** Returns whether the given page is included in the set of pages that have
    been selected for printing. *)

external end_preview : t -> unit = "ml_gtk_print_operation_preview_end_preview"
(** Ends a preview.

    This function must be called to finish a custom print preview. *)

val on_got_page_size :
  ?after:bool ->
  t ->
  callback:(context:Print_context.t -> page_setup:Page_setup.t -> unit) ->
  Gobject.Signal.handler_id

val on_ready :
  ?after:bool ->
  t ->
  callback:(context:Print_context.t -> unit) ->
  Gobject.Signal.handler_id
