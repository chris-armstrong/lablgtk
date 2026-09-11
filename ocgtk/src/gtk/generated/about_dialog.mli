(* GENERATED CODE - DO NOT EDIT *)
(* AboutDialog: AboutDialog *)

type t =
  [ `about_dialog | `window | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_about_dialog_get_type"

external new_ : unit -> t = "ml_gtk_about_dialog_new"
(** Create a new AboutDialog *)

(* Methods *)

external set_wrap_license : t -> bool -> unit
  = "ml_gtk_about_dialog_set_wrap_license"
(** Sets whether the license text in the about dialog should be automatically
    wrapped. *)

external set_website_label : t -> string -> unit
  = "ml_gtk_about_dialog_set_website_label"
(** Sets the label to be used for the website link. *)

external set_website : t -> string option -> unit
  = "ml_gtk_about_dialog_set_website"
(** Sets the URL to use for the website link. *)

external set_version : t -> string option -> unit
  = "ml_gtk_about_dialog_set_version"
(** Sets the version string to display in the about dialog. *)

external set_translator_credits : t -> string option -> unit
  = "ml_gtk_about_dialog_set_translator_credits"
(** Sets the translator credits string which is displayed in the credits page.

    The intended use for this string is to display the translator of the
    language which is currently used in the user interface. Using `gettext()`, a
    simple way to achieve that is to mark the string for translation:

    ```c GtkWidget *about = gtk_about_dialog_new ();
    gtk_about_dialog_set_translator_credits (GTK_ABOUT_DIALOG (about),
    _("translator-credits")); ```

    It is a good idea to use the customary `msgid` “translator-credits” for this
    purpose, since translators will already know the purpose of that `msgid`,
    and since `GtkAboutDialog` will detect if “translator-credits” is
    untranslated and omit translator credits. *)

external set_system_information : t -> string option -> unit
  = "ml_gtk_about_dialog_set_system_information"
(** Sets the system information to be displayed in the about dialog.

    If `system_information` is `NULL`, the system information page is hidden.

    See [property@Gtk.AboutDialog:system-information]. *)

external set_program_name : t -> string option -> unit
  = "ml_gtk_about_dialog_set_program_name"
(** Sets the name to display in the about dialog.

    If `name` is not set, the string returned by `g_get_application_name()` is
    used. *)

external set_logo_icon_name : t -> string option -> unit
  = "ml_gtk_about_dialog_set_logo_icon_name"
(** Sets the icon name to be displayed as logo in the about dialog. *)

external set_logo : t -> Ocgtk_gdk.Gdk.Wrappers.Paintable.t option -> unit
  = "ml_gtk_about_dialog_set_logo"
(** Sets the logo in the about dialog. *)

external set_license : t -> string option -> unit
  = "ml_gtk_about_dialog_set_license"
(** Sets the license information to be displayed in the about dialog.

    If `license` is `NULL`, the license page is hidden. *)

external set_documenters : t -> string array -> unit
  = "ml_gtk_about_dialog_set_documenters"
(** Sets the names of the documenters which are displayed in the "Credits" page.
*)

external set_copyright : t -> string option -> unit
  = "ml_gtk_about_dialog_set_copyright"
(** Sets the copyright string to display in the about dialog.

    This should be a short string of one or two lines. *)

external set_comments : t -> string option -> unit
  = "ml_gtk_about_dialog_set_comments"
(** Sets the comments string to display in the about dialog.

    This should be a short string of one or two lines. *)

external set_authors : t -> string array -> unit
  = "ml_gtk_about_dialog_set_authors"
(** Sets the names of the authors which are displayed in the "Credits" page of
    the about dialog. *)

external set_artists : t -> string array -> unit
  = "ml_gtk_about_dialog_set_artists"
(** Sets the names of the artists to be displayed in the "Credits" page. *)

external get_wrap_license : t -> bool = "ml_gtk_about_dialog_get_wrap_license"
(** Returns whether the license text in the about dialog is automatically
    wrapped. *)

external get_website_label : t -> string option
  = "ml_gtk_about_dialog_get_website_label"
(** Returns the label used for the website link. *)

external get_website : t -> string option = "ml_gtk_about_dialog_get_website"
(** Returns the website URL. *)

external get_version : t -> string option = "ml_gtk_about_dialog_get_version"
(** Returns the version string. *)

external get_translator_credits : t -> string option
  = "ml_gtk_about_dialog_get_translator_credits"
(** Returns the translator credits string which is displayed in the credits
    page. *)

external get_system_information : t -> string option
  = "ml_gtk_about_dialog_get_system_information"
(** Returns the system information that is shown in the about dialog. *)

external get_program_name : t -> string option
  = "ml_gtk_about_dialog_get_program_name"
(** Returns the program name displayed in the about dialog. *)

external get_logo_icon_name : t -> string option
  = "ml_gtk_about_dialog_get_logo_icon_name"
(** Returns the icon name displayed as logo in the about dialog. *)

external get_logo : t -> Ocgtk_gdk.Gdk.Wrappers.Paintable.t option
  = "ml_gtk_about_dialog_get_logo"
(** Returns the paintable displayed as logo in the about dialog. *)

external get_license : t -> string option = "ml_gtk_about_dialog_get_license"
(** Returns the license information. *)

external get_documenters : t -> string array
  = "ml_gtk_about_dialog_get_documenters"
(** Returns the name of the documenters which are displayed in the credits page.
*)

external get_copyright : t -> string option
  = "ml_gtk_about_dialog_get_copyright"
(** Returns the copyright string. *)

external get_comments : t -> string option = "ml_gtk_about_dialog_get_comments"
(** Returns the comments string. *)

external get_authors : t -> string array = "ml_gtk_about_dialog_get_authors"
(** Returns the names of the authors which are displayed in the credits page. *)

external get_artists : t -> string array = "ml_gtk_about_dialog_get_artists"
(** Returns the names of the artists which are displayed in the credits page. *)

external add_credit_section : t -> string -> string array -> unit
  = "ml_gtk_about_dialog_add_credit_section"
(** Creates a new section in the "Credits" page. *)

(* Properties *)

val on_activate_link :
  ?after:bool -> t -> callback:(uri:string -> bool) -> Gobject.Signal.handler_id
