(* GENERATED CODE - DO NOT EDIT *)
(* IconPaintable: IconPaintable *)

type t = [ `icon_paintable | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_icon_paintable_get_type"

external new_for_file : Ocgtk_gio.Gio.Wrappers.File.t -> int -> int -> t
  = "ml_gtk_icon_paintable_new_for_file"
(** Create a new IconPaintable *)

(* Methods *)

external is_symbolic : t -> bool = "ml_gtk_icon_paintable_is_symbolic"
(** Checks if the icon is symbolic or not.

    This currently uses only the file name and not the file contents for
    determining this. This behaviour may change in the future. *)

external get_icon_name : t -> string option
  = "ml_gtk_icon_paintable_get_icon_name"
(** Get the icon name being used for this icon.

    When an icon looked up in the icon theme was not available, the icon theme
    may use fallback icons - either those specified to
    gtk_icon_theme_lookup_icon() or the always-available "image-missing". The
    icon chosen is returned by this function.

    If the icon was created without an icon theme, this function returns %NULL.
*)

external get_file : t -> Ocgtk_gio.Gio.Wrappers.File.t option
  = "ml_gtk_icon_paintable_get_file"
(** Gets the `GFile` that was used to load the icon.

    Returns %NULL if the icon was not loaded from a file. *)

(* Properties *)

external get_scale : t -> int = "ml_gtk_icon_paintable_get_scale"
(** Get property: scale *)

external set_scale : t -> int -> unit = "ml_gtk_icon_paintable_set_scale"
(** Set property: scale *)

external get_size : t -> int = "ml_gtk_icon_paintable_get_size"
(** Get property: size *)

external set_size : t -> int -> unit = "ml_gtk_icon_paintable_set_size"
(** Set property: size *)
