(* GENERATED CODE - DO NOT EDIT *)
(* PaperSize: PaperSize *)

type t = [ `paper_size ] Gobject.obj
(** `GtkPaperSize` handles paper sizes.

    It uses the standard called
    [PWG 5101.1-2002 PWG: Standard for Media Standardized Names](http://www.pwg.org/standards.html)
    to name the paper sizes (and to get the data for the page sizes). In
    addition to standard paper sizes, `GtkPaperSize` allows to construct custom
    paper sizes with arbitrary dimensions.

    The `GtkPaperSize` object stores not only the dimensions (width and height)
    of a paper size and its name, it also provides default print margins. *)

external gtype : unit -> Gobject.Type.t = "ml_gtk_paper_size_get_type"

external new_ : string option -> t = "ml_gtk_paper_size_new"
(** Create a new PaperSize *)

external new_custom : string -> string -> float -> float -> Gtk_enums.unit -> t
  = "ml_gtk_paper_size_new_custom"
(** Create a new PaperSize *)

external new_from_gvariant : Gvariant.t -> t
  = "ml_gtk_paper_size_new_from_gvariant"
(** Create a new PaperSize *)

external new_from_ipp : string -> float -> float -> t
  = "ml_gtk_paper_size_new_from_ipp"
(** Create a new PaperSize *)

external new_from_ppd : string -> string -> float -> float -> t
  = "ml_gtk_paper_size_new_from_ppd"
(** Create a new PaperSize *)

(* Methods *)

external to_gvariant : t -> Gvariant.t = "ml_gtk_paper_size_to_gvariant"
(** Serialize a paper size to an `a{sv}` variant. *)

external set_size : t -> float -> float -> Gtk_enums.unit -> unit
  = "ml_gtk_paper_size_set_size"
(** Changes the dimensions of a @size to @width x @height. *)

external is_ipp : t -> bool = "ml_gtk_paper_size_is_ipp"
(** Returns %TRUE if @size is an IPP standard paper size. *)

external is_equal : t -> t -> bool = "ml_gtk_paper_size_is_equal"
(** Compares two `GtkPaperSize` objects. *)

external is_custom : t -> bool = "ml_gtk_paper_size_is_custom"
(** Returns %TRUE if @size is not a standard paper size. *)

external get_width : t -> Gtk_enums.unit -> float
  = "ml_gtk_paper_size_get_width"
(** Gets the paper width of the `GtkPaperSize`, in
units of @unit. *)

external get_ppd_name : t -> string = "ml_gtk_paper_size_get_ppd_name"
(** Gets the PPD name of the `GtkPaperSize`, which may be %NULL. *)

external get_name : t -> string = "ml_gtk_paper_size_get_name"
(** Gets the name of the `GtkPaperSize`. *)

external get_height : t -> Gtk_enums.unit -> float
  = "ml_gtk_paper_size_get_height"
(** Gets the paper height of the `GtkPaperSize`, in
units of @unit. *)

external get_display_name : t -> string = "ml_gtk_paper_size_get_display_name"
(** Gets the human-readable name of the `GtkPaperSize`. *)

external get_default_top_margin : t -> Gtk_enums.unit -> float
  = "ml_gtk_paper_size_get_default_top_margin"
(** Gets the default top margin for the `GtkPaperSize`. *)

external get_default_right_margin : t -> Gtk_enums.unit -> float
  = "ml_gtk_paper_size_get_default_right_margin"
(** Gets the default right margin for the `GtkPaperSize`. *)

external get_default_left_margin : t -> Gtk_enums.unit -> float
  = "ml_gtk_paper_size_get_default_left_margin"
(** Gets the default left margin for the `GtkPaperSize`. *)

external get_default_bottom_margin : t -> Gtk_enums.unit -> float
  = "ml_gtk_paper_size_get_default_bottom_margin"
(** Gets the default bottom margin for the `GtkPaperSize`. *)
