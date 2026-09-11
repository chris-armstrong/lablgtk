(* GENERATED CODE - DO NOT EDIT *)
(* ColorDialog: ColorDialog *)

type t = [ `color_dialog | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_color_dialog_get_type"

external new_ : unit -> t = "ml_gtk_color_dialog_new"
(** Create a new ColorDialog *)

(* Methods *)

external set_with_alpha : t -> bool -> unit
  = "ml_gtk_color_dialog_set_with_alpha"
(** Sets whether colors may have alpha. *)

external set_title : t -> string -> unit = "ml_gtk_color_dialog_set_title"
(** Sets the title that will be shown on the color chooser dialog. *)

external set_modal : t -> bool -> unit = "ml_gtk_color_dialog_set_modal"
(** Sets whether the color chooser dialog blocks interaction with the parent
    window while it is presented. *)

external get_with_alpha : t -> bool = "ml_gtk_color_dialog_get_with_alpha"
(** Returns whether colors may have alpha. *)

external get_title : t -> string = "ml_gtk_color_dialog_get_title"
(** Returns the title that will be shown on the color chooser dialog. *)

external get_modal : t -> bool = "ml_gtk_color_dialog_get_modal"
(** Returns whether the color chooser dialog blocks interaction with the parent
    window while it is presented. *)

external choose_rgba_finish :
  t ->
  Ocgtk_gio.Gio.Wrappers.Async_result.t ->
  (Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t, GError.t) result
  = "ml_gtk_color_dialog_choose_rgba_finish"
(** Finishes the [method@Gtk.ColorDialog.choose_rgba] call

    Note that this function returns a [error@Gtk.DialogError.DISMISSED] error if
    the user cancels the dialog. *)

(* Properties *)
