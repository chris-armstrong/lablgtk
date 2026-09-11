(* GENERATED CODE - DO NOT EDIT *)
(* AppChooserButton: AppChooserButton *)

type t =
  [ `app_chooser_button | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_app_chooser_button_get_type"

external new_ : string -> t = "ml_gtk_app_chooser_button_new"
(** Create a new AppChooserButton *)

(* Methods *)

external set_show_dialog_item : t -> bool -> unit
  = "ml_gtk_app_chooser_button_set_show_dialog_item"
(** Sets whether the dropdown menu of this button should show an entry to
    trigger a `GtkAppChooserDialog`. *)

external set_show_default_item : t -> bool -> unit
  = "ml_gtk_app_chooser_button_set_show_default_item"
(** Sets whether the dropdown menu of this button should show the default
    application for the given content type at top. *)

external set_modal : t -> bool -> unit = "ml_gtk_app_chooser_button_set_modal"
(** Sets whether the dialog should be modal. *)

external set_heading : t -> string -> unit
  = "ml_gtk_app_chooser_button_set_heading"
(** Sets the text to display at the top of the dialog.

    If the heading is not set, the dialog displays a default text. *)

external set_active_custom_item : t -> string -> unit
  = "ml_gtk_app_chooser_button_set_active_custom_item"
(** Selects a custom item.

    See [method@Gtk.AppChooserButton.append_custom_item].

    Use [method@Gtk.AppChooser.refresh] to bring the selection to its initial
    state. *)

external get_show_dialog_item : t -> bool
  = "ml_gtk_app_chooser_button_get_show_dialog_item"
(** Returns whether the dropdown menu shows an item for a `GtkAppChooserDialog`.
*)

external get_show_default_item : t -> bool
  = "ml_gtk_app_chooser_button_get_show_default_item"
(** Returns whether the dropdown menu should show the default application at the
    top. *)

external get_modal : t -> bool = "ml_gtk_app_chooser_button_get_modal"
(** Gets whether the dialog is modal. *)

external get_heading : t -> string option
  = "ml_gtk_app_chooser_button_get_heading"
(** Returns the text to display at the top of the dialog. *)

external append_separator : t -> unit
  = "ml_gtk_app_chooser_button_append_separator"
(** Appends a separator to the list of applications that is shown in the popup.
*)

external append_custom_item :
  t -> string -> string -> Ocgtk_gio.Gio.Wrappers.Icon.t -> unit
  = "ml_gtk_app_chooser_button_append_custom_item"
(** Appends a custom item to the list of applications that is shown in the
    popup.

    The item name must be unique per-widget. Clients can use the provided name
    as a detail for the [signal@Gtk.AppChooserButton::custom-item-activated]
    signal, to add a callback for the activation of a particular custom item in
    the list.

    See also [method@Gtk.AppChooserButton.append_separator]. *)

(* Properties *)

let on_activate ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"activate" ~callback
    ~after:(Option.value after ~default:false)

let on_changed ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"changed" ~callback
    ~after:(Option.value after ~default:false)

let on_custom_item_activated ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let item_name =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_string v
        in
        callback ~item_name)
  in
  Gobject.Signal.connect obj ~name:"custom-item-activated" ~callback:closure
    ~after:(Option.value after ~default:false)
