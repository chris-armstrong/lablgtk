(* GENERATED CODE - DO NOT EDIT *)
(* Scrollable: Scrollable *)

type t = [ `scrollable ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_scrollable_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gtk_scrollable_from_gobject"

(* Methods *)

external set_vscroll_policy : t -> Gtk_enums.scrollablepolicy -> unit
  = "ml_gtk_scrollable_set_vscroll_policy"
(** Sets the `GtkScrollablePolicy`.

    The policy determines whether vertical scrolling should start below the
    minimum height or below the natural height. *)

external set_vadjustment : t -> Adjustment.t option -> unit
  = "ml_gtk_scrollable_set_vadjustment"
(** Sets the vertical adjustment of the `GtkScrollable`. *)

external set_hscroll_policy : t -> Gtk_enums.scrollablepolicy -> unit
  = "ml_gtk_scrollable_set_hscroll_policy"
(** Sets the `GtkScrollablePolicy`.

    The policy determines whether horizontal scrolling should start below the
    minimum width or below the natural width. *)

external set_hadjustment : t -> Adjustment.t option -> unit
  = "ml_gtk_scrollable_set_hadjustment"
(** Sets the horizontal adjustment of the `GtkScrollable`. *)

external get_vscroll_policy : t -> Gtk_enums.scrollablepolicy
  = "ml_gtk_scrollable_get_vscroll_policy"
(** Gets the vertical `GtkScrollablePolicy`. *)

external get_vadjustment : t -> Adjustment.t option
  = "ml_gtk_scrollable_get_vadjustment"
(** Retrieves the `GtkAdjustment` used for vertical scrolling. *)

external get_hscroll_policy : t -> Gtk_enums.scrollablepolicy
  = "ml_gtk_scrollable_get_hscroll_policy"
(** Gets the horizontal `GtkScrollablePolicy`. *)

external get_hadjustment : t -> Adjustment.t option
  = "ml_gtk_scrollable_get_hadjustment"
(** Retrieves the `GtkAdjustment` used for horizontal scrolling. *)

external get_border : t -> bool * Border.t = "ml_gtk_scrollable_get_border"
(** Returns the size of a non-scrolling border around the outside of the
    scrollable.

    An example for this would be treeview headers. GTK can use this information
    to display overlaid graphics, like the overshoot indication, at the right
    position. *)

(* Properties *)
