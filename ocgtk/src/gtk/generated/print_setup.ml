(* GENERATED CODE - DO NOT EDIT *)
(* PrintSetup: PrintSetup *)

type t = [ `print_setup ] Gobject.obj
(** An auxiliary object for printing that allows decoupling the setup from the
    printing.

    A print setup is obtained by calling [method@Gtk.PrintDialog.setup], and can
    later be passed to print functions such as [method@Gtk.PrintDialog.print].

    Print setups can be reused for multiple print calls.

    Applications may wish to store the page_setup and print_settings from the
    print setup and copy them to the PrintDialog if they want to keep using
    them. *)

external gtype : unit -> Gobject.Type.t = "ml_gtk_print_setup_get_type"

(* Methods *)

external ref : t -> t = "ml_gtk_print_setup_ref"
(** Increase the reference count of @setup. *)

external get_print_settings : t -> Print_settings.t
  = "ml_gtk_print_setup_get_print_settings"
(** Returns the print settings of @setup.

They may be different from the `GtkPrintDialog`'s settings
if the user changed them during the setup process. *)

external get_page_setup : t -> Page_setup.t
  = "ml_gtk_print_setup_get_page_setup"
(** Returns the page setup of @setup.

It may be different from the `GtkPrintDialog`'s page setup
if the user changed it during the setup process. *)
