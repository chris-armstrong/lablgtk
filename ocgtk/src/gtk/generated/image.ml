(* GENERATED CODE - DO NOT EDIT *)
(* Image: Image *)

type t = [ `image | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_image_get_type"

external new_ : unit -> t = "ml_gtk_image_new"
(** Create a new Image *)

external new_from_file : string -> t = "ml_gtk_image_new_from_file"
(** Create a new Image *)

external new_from_gicon : Ocgtk_gio.Gio.Wrappers.Icon.t -> t
  = "ml_gtk_image_new_from_gicon"
(** Create a new Image *)

external new_from_icon_name : string option -> t
  = "ml_gtk_image_new_from_icon_name"
(** Create a new Image *)

external new_from_paintable : Ocgtk_gdk.Gdk.Wrappers.Paintable.t option -> t
  = "ml_gtk_image_new_from_paintable"
(** Create a new Image *)

external new_from_pixbuf :
  Ocgtk_gdkpixbuf.GdkPixbuf.Wrappers.Pixbuf.t option -> t
  = "ml_gtk_image_new_from_pixbuf"
(** Create a new Image *)

external new_from_resource : string -> t = "ml_gtk_image_new_from_resource"
(** Create a new Image *)

(* Methods *)

external set_pixel_size : t -> int -> unit = "ml_gtk_image_set_pixel_size"
(** Sets the pixel size to use for named icons.

    If the pixel size is set to a value != -1, it is used instead of the icon
    size set by [method@Gtk.Image.set_icon_size]. *)

external set_icon_size : t -> Gtk_enums.iconsize -> unit
  = "ml_gtk_image_set_icon_size"
(** Suggests an icon size to the theme for named icons. *)

external set_from_resource : t -> string option -> unit
  = "ml_gtk_image_set_from_resource"
(** Sets a `GtkImage` to show a resource.

    See [ctor@Gtk.Image.new_from_resource] for details. *)

external set_from_pixbuf :
  t -> Ocgtk_gdkpixbuf.GdkPixbuf.Wrappers.Pixbuf.t option -> unit
  = "ml_gtk_image_set_from_pixbuf"
(** Sets a `GtkImage` to show a `GdkPixbuf`.

    See [ctor@Gtk.Image.new_from_pixbuf] for details.

    Note: This is a helper for [method@Gtk.Image.set_from_paintable], and you
    can't get back the exact pixbuf once this is called, only a paintable. *)

external set_from_paintable :
  t -> Ocgtk_gdk.Gdk.Wrappers.Paintable.t option -> unit
  = "ml_gtk_image_set_from_paintable"
(** Sets a `GtkImage` to show a `GdkPaintable`.

    See [ctor@Gtk.Image.new_from_paintable] for details. *)

external set_from_icon_name : t -> string option -> unit
  = "ml_gtk_image_set_from_icon_name"
(** Sets a `GtkImage` to show a named icon.

    See [ctor@Gtk.Image.new_from_icon_name] for details. *)

external set_from_gicon : t -> Ocgtk_gio.Gio.Wrappers.Icon.t -> unit
  = "ml_gtk_image_set_from_gicon"
(** Sets a `GtkImage` to show a `GIcon`.

    See [ctor@Gtk.Image.new_from_gicon] for details. *)

external set_from_file : t -> string option -> unit
  = "ml_gtk_image_set_from_file"
(** Sets a `GtkImage` to show a file.

    See [ctor@Gtk.Image.new_from_file] for details.

    ::: warning Note that this function should not be used with untrusted data.
    Use a proper image loading framework such as libglycin, which can load many
    image formats into a `GdkTexture`, and then use
    [method@Gtk.Image.set_from_paintable]. *)

external get_storage_type : t -> Gtk_enums.imagetype
  = "ml_gtk_image_get_storage_type"
(** Gets the type of representation being used by the `GtkImage` to store image
    data.

    If the `GtkImage` has no image data, the return value will be
    %GTK_IMAGE_EMPTY. *)

external get_pixel_size : t -> int = "ml_gtk_image_get_pixel_size"
(** Gets the pixel size used for named icons. *)

external get_paintable : t -> Ocgtk_gdk.Gdk.Wrappers.Paintable.t option
  = "ml_gtk_image_get_paintable"
(** Gets the image `GdkPaintable` being displayed by the `GtkImage`.

    The storage type of the image must be %GTK_IMAGE_EMPTY or
    %GTK_IMAGE_PAINTABLE (see [method@Gtk.Image.get_storage_type]). The caller
    of this function does not own a reference to the returned paintable. *)

external get_icon_size : t -> Gtk_enums.iconsize = "ml_gtk_image_get_icon_size"
(** Gets the icon size used by the @image when rendering icons. *)

external get_icon_name : t -> string option = "ml_gtk_image_get_icon_name"
(** Gets the icon name and size being displayed by the `GtkImage`.

    The storage type of the image must be %GTK_IMAGE_EMPTY or
    %GTK_IMAGE_ICON_NAME (see [method@Gtk.Image.get_storage_type]). The returned
    string is owned by the `GtkImage` and should not be freed. *)

external get_gicon : t -> Ocgtk_gio.Gio.Wrappers.Icon.t option
  = "ml_gtk_image_get_gicon"
(** Gets the `GIcon` being displayed by the `GtkImage`.

    The storage type of the image must be %GTK_IMAGE_EMPTY or %GTK_IMAGE_GICON
    (see [method@Gtk.Image.get_storage_type]). The caller of this function does
    not own a reference to the returned `GIcon`. *)

external clear : t -> unit = "ml_gtk_image_clear"
(** Resets the image to be empty. *)

(* Properties *)

external get_use_fallback : t -> bool = "ml_gtk_image_get_use_fallback"
(** Get property: use-fallback *)

external set_use_fallback : t -> bool -> unit = "ml_gtk_image_set_use_fallback"
(** Set property: use-fallback *)
