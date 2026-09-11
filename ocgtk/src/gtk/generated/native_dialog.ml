(* GENERATED CODE - DO NOT EDIT *)
(* NativeDialog: NativeDialog *)

type t = [ `native_dialog | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_native_dialog_get_type"

(* Methods *)

external show : t -> unit = "ml_gtk_native_dialog_show"
(** Shows the dialog on the display.

    When the user accepts the state of the dialog the dialog will be
    automatically hidden and the [signal@Gtk.NativeDialog::response] signal will
    be emitted.

    Multiple calls while the dialog is visible will be ignored. *)

external set_transient_for :
  t -> Application_and__window_and__window_group.Window.t option -> unit
  = "ml_gtk_native_dialog_set_transient_for"
(** Dialog windows should be set transient for the main application
window they were spawned from.

This allows window managers to e.g. keep the dialog on top of the
main window, or center the dialog over the main window.

Passing %NULL for @parent unsets the current transient window. *)

external set_title : t -> string -> unit = "ml_gtk_native_dialog_set_title"
(** Sets the title of the `GtkNativeDialog.` *)

external set_modal : t -> bool -> unit = "ml_gtk_native_dialog_set_modal"
(** Sets a dialog modal or non-modal.

    Modal dialogs prevent interaction with other windows in the same
    application. To keep modal dialogs on top of main application windows, use
    [method@Gtk.NativeDialog.set_transient_for] to make the dialog transient for
    the parent; most window managers will then disallow lowering the dialog
    below the parent. *)

external hide : t -> unit = "ml_gtk_native_dialog_hide"
(** Hides the dialog if it is visible, aborting any interaction.

    Once this is called the [signal@Gtk.NativeDialog::response] signal will
    *not* be emitted until after the next call to
    [method@Gtk.NativeDialog.show].

    If the dialog is not visible this does nothing. *)

external get_visible : t -> bool = "ml_gtk_native_dialog_get_visible"
(** Determines whether the dialog is visible. *)

external get_transient_for :
  t -> Application_and__window_and__window_group.Window.t option
  = "ml_gtk_native_dialog_get_transient_for"
(** Fetches the transient parent for this window. *)

external get_title : t -> string option = "ml_gtk_native_dialog_get_title"
(** Gets the title of the `GtkNativeDialog`. *)

external get_modal : t -> bool = "ml_gtk_native_dialog_get_modal"
(** Returns whether the dialog is modal. *)

external destroy : t -> unit = "ml_gtk_native_dialog_destroy"
(** Destroys a dialog.

    When a dialog is destroyed, it will break any references it holds to other
    objects.

    If it is visible it will be hidden and any underlying window system
    resources will be destroyed.

    Note that this does not release any reference to the object (as opposed to
    destroying a `GtkWindow`) because there is no reference from the windowing
    system to the `GtkNativeDialog`. *)

(* Properties *)

let on_response ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let response_id =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_int v
        in
        callback ~response_id)
  in
  Gobject.Signal.connect obj ~name:"response" ~callback:closure
    ~after:(Option.value after ~default:false)
