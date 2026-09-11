(* GENERATED CODE - DO NOT EDIT *)
(* CellRendererPixbuf: CellRendererPixbuf *)

type t =
  [ `cell_renderer_pixbuf | `cell_renderer | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_cell_renderer_pixbuf_get_type"

external new_ : unit -> t = "ml_gtk_cell_renderer_pixbuf_new"
(** Create a new CellRendererPixbuf *)

(* Methods *)
(* Properties *)

external get_gicon : t -> Ocgtk_gio.Gio.Wrappers.Icon.t
  = "ml_gtk_cell_renderer_pixbuf_get_gicon"
(** Get property: gicon *)

external set_gicon : t -> Ocgtk_gio.Gio.Wrappers.Icon.t -> unit
  = "ml_gtk_cell_renderer_pixbuf_set_gicon"
(** Set property: gicon *)

external get_icon_name : t -> string
  = "ml_gtk_cell_renderer_pixbuf_get_icon_name"
(** Get property: icon-name *)

external set_icon_name : t -> string -> unit
  = "ml_gtk_cell_renderer_pixbuf_set_icon_name"
(** Set property: icon-name *)

external get_icon_size : t -> Gtk_enums.iconsize
  = "ml_gtk_cell_renderer_pixbuf_get_icon_size"
(** Get property: icon-size *)

external set_icon_size : t -> Gtk_enums.iconsize -> unit
  = "ml_gtk_cell_renderer_pixbuf_set_icon_size"
(** Set property: icon-size *)

external set_pixbuf : t -> Ocgtk_gdkpixbuf.GdkPixbuf.Wrappers.Pixbuf.t -> unit
  = "ml_gtk_cell_renderer_pixbuf_set_pixbuf"
(** Set property: pixbuf *)

external get_pixbuf_expander_closed :
  t -> Ocgtk_gdkpixbuf.GdkPixbuf.Wrappers.Pixbuf.t
  = "ml_gtk_cell_renderer_pixbuf_get_pixbuf_expander_closed"
(** Get property: pixbuf-expander-closed *)

external set_pixbuf_expander_closed :
  t -> Ocgtk_gdkpixbuf.GdkPixbuf.Wrappers.Pixbuf.t -> unit
  = "ml_gtk_cell_renderer_pixbuf_set_pixbuf_expander_closed"
(** Set property: pixbuf-expander-closed *)

external get_pixbuf_expander_open :
  t -> Ocgtk_gdkpixbuf.GdkPixbuf.Wrappers.Pixbuf.t
  = "ml_gtk_cell_renderer_pixbuf_get_pixbuf_expander_open"
(** Get property: pixbuf-expander-open *)

external set_pixbuf_expander_open :
  t -> Ocgtk_gdkpixbuf.GdkPixbuf.Wrappers.Pixbuf.t -> unit
  = "ml_gtk_cell_renderer_pixbuf_set_pixbuf_expander_open"
(** Set property: pixbuf-expander-open *)

external get_texture : t -> Ocgtk_gdk.Gdk.Wrappers.Texture.t
  = "ml_gtk_cell_renderer_pixbuf_get_texture"
(** Get property: texture *)

external set_texture : t -> Ocgtk_gdk.Gdk.Wrappers.Texture.t -> unit
  = "ml_gtk_cell_renderer_pixbuf_set_texture"
(** Set property: texture *)
