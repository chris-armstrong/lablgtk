(* GENERATED CODE - DO NOT EDIT *)
(* CssSection: CssSection *)

type t = [ `css_section ] Gobject.obj
(** Defines a part of a CSS document.

    Because sections are nested into one another, you can use
    [method@CssSection.get_parent] to get the containing region. *)

external gtype : unit -> Gobject.Type.t = "ml_gtk_css_section_get_type"

external new_ :
  Ocgtk_gio.Gio.Wrappers.File.t option -> Css_location.t -> Css_location.t -> t
  = "ml_gtk_css_section_new"
(** Create a new CssSection *)

external new_with_bytes :
  Ocgtk_gio.Gio.Wrappers.File.t option ->
  Glib_bytes.t option ->
  Css_location.t ->
  Css_location.t ->
  t = "ml_gtk_css_section_new_with_bytes"
(** Create a new CssSection *)

(* Methods *)

external to_string : t -> string = "ml_gtk_css_section_to_string"
(** Prints the section into a human-readable text form using
    [method@Gtk.CssSection.print]. *)

external ref : t -> t = "ml_gtk_css_section_ref"
(** Increments the reference count on `section`. *)

external get_start_location : t -> Css_location.t
  = "ml_gtk_css_section_get_start_location"
(** Returns the location in the CSS document where this section starts. *)

external get_parent : t -> t option = "ml_gtk_css_section_get_parent"
(** Gets the parent section for the given `section`.

    The parent section is the section that contains this `section`. A special
    case are sections of type `GTK_CSS_SECTION_DOCUMENT`. Their parent will
    either be `NULL` if they are the original CSS document that was loaded by
    [method@Gtk.CssProvider.load_from_file] or a section of type
    `GTK_CSS_SECTION_IMPORT` if it was loaded with an `@import` rule from a
    different file. *)

external get_file : t -> Ocgtk_gio.Gio.Wrappers.File.t option
  = "ml_gtk_css_section_get_file"
(** Gets the file that @section was parsed from.

If no such file exists, for example because the CSS was loaded via
[method@Gtk.CssProvider.load_from_data], then `NULL` is returned. *)

external get_end_location : t -> Css_location.t
  = "ml_gtk_css_section_get_end_location"
(** Returns the location in the CSS document where this section ends. *)

external get_bytes : t -> Glib_bytes.t option = "ml_gtk_css_section_get_bytes"
(** Gets the bytes that @section was parsed from. *)
