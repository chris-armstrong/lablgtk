(* GENERATED CODE - DO NOT EDIT *)
(* CssProvider: CssProvider *)

type t = [ `css_provider | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_css_provider_get_type"

external new_ : unit -> t = "ml_gtk_css_provider_new"
(** Create a new CssProvider *)

(* Methods *)

external to_string : t -> string = "ml_gtk_css_provider_to_string"
(** Converts the @provider into a string representation in CSS
format.

Using [method@Gtk.CssProvider.load_from_string] with the return
value from this function on a new provider created with
[ctor@Gtk.CssProvider.new] will basically create a duplicate
of this @provider. *)

external load_named : t -> string -> string option -> unit
  = "ml_gtk_css_provider_load_named"
(** Loads a theme from the usual theme paths.

    The actual process of finding the theme might change between releases, but
    it is guaranteed that this function uses the same mechanism to load the
    theme that GTK uses for loading its own theme. *)

external load_from_string : t -> string -> unit
  = "ml_gtk_css_provider_load_from_string"
(** Loads @string into @css_provider.

This clears any previously loaded information. *)

external load_from_resource : t -> string -> unit
  = "ml_gtk_css_provider_load_from_resource"
(** Loads the data contained in the resource at @resource_path into
the @css_provider.

This clears any previously loaded information. *)

external load_from_path : t -> string -> unit
  = "ml_gtk_css_provider_load_from_path"
(** Loads the data contained in @path into @css_provider.

This clears any previously loaded information. *)

external load_from_file : t -> Ocgtk_gio.Gio.Wrappers.File.t -> unit
  = "ml_gtk_css_provider_load_from_file"
(** Loads the data contained in @file into @css_provider.

This clears any previously loaded information. *)

external load_from_data : t -> string -> int -> unit
  = "ml_gtk_css_provider_load_from_data"
(** Loads @data into @css_provider.

This clears any previously loaded information. *)

external load_from_bytes : t -> Glib_bytes.t -> unit
  = "ml_gtk_css_provider_load_from_bytes"
(** Loads @data into @css_provider.

This clears any previously loaded information. *)

(* Properties *)

external get_prefers_color_scheme : t -> Gtk_enums.interfacecolorscheme
  = "ml_gtk_css_provider_get_prefers_color_scheme"
(** Get property: prefers-color-scheme *)

external set_prefers_color_scheme : t -> Gtk_enums.interfacecolorscheme -> unit
  = "ml_gtk_css_provider_set_prefers_color_scheme"
(** Set property: prefers-color-scheme *)

external get_prefers_contrast : t -> Gtk_enums.interfacecontrast
  = "ml_gtk_css_provider_get_prefers_contrast"
(** Get property: prefers-contrast *)

external set_prefers_contrast : t -> Gtk_enums.interfacecontrast -> unit
  = "ml_gtk_css_provider_set_prefers_contrast"
(** Set property: prefers-contrast *)
