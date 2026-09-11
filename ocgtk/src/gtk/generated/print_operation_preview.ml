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

let on_got_page_size ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let context =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Print_context.gtype ())
        in
        let page_setup =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_object_exn v (Page_setup.gtype ())
        in
        callback ~context ~page_setup)
  in
  Gobject.Signal.connect obj ~name:"got-page-size" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_ready ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let context =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Print_context.gtype ())
        in
        callback ~context)
  in
  Gobject.Signal.connect obj ~name:"ready" ~callback:closure
    ~after:(Option.value after ~default:false)
