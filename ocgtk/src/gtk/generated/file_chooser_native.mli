(* GENERATED CODE - DO NOT EDIT *)
(* FileChooserNative: FileChooserNative *)

type t = [ `file_chooser_native | `native_dialog | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_file_chooser_native_get_type"

external new_ :
  string option ->
  Application_and__window_and__window_group.Window.t option ->
  Gtk_enums.filechooseraction ->
  string option ->
  string option ->
  t = "ml_gtk_file_chooser_native_new"
(** Create a new FileChooserNative *)

(* Methods *)

external set_cancel_label : t -> string option -> unit
  = "ml_gtk_file_chooser_native_set_cancel_label"
(** Sets the custom label text for the cancel button.

If characters in @label are preceded by an underscore, they are
underlined. If you need a literal underscore character in a label,
use “__” (two underscores). The first underlined character represents
a keyboard accelerator called a mnemonic.

Pressing Alt and that key should activate the button. *)

external set_accept_label : t -> string option -> unit
  = "ml_gtk_file_chooser_native_set_accept_label"
(** Sets the custom label text for the accept button.

If characters in @label are preceded by an underscore, they are
underlined. If you need a literal underscore character in a label,
use “__” (two underscores). The first underlined character represents
a keyboard accelerator called a mnemonic.

Pressing Alt and that key should activate the button. *)

external get_cancel_label : t -> string option
  = "ml_gtk_file_chooser_native_get_cancel_label"
(** Retrieves the custom label text for the cancel button. *)

external get_accept_label : t -> string option
  = "ml_gtk_file_chooser_native_get_accept_label"
(** Retrieves the custom label text for the accept button. *)

(* Properties *)
