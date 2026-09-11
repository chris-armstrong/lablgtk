(* GENERATED CODE - DO NOT EDIT *)
(* Fixed: Fixed *)

type t = [ `fixed | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_fixed_get_type"

external new_ : unit -> t = "ml_gtk_fixed_new"
(** Create a new Fixed *)

(* Methods *)

external set_child_transform :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Ocgtk_gsk.Gsk.Wrappers.Transform.t option ->
  unit = "ml_gtk_fixed_set_child_transform"
(** Sets the transformation for @widget.

This is a convenience function that retrieves the
[class@Gtk.FixedLayoutChild] instance associated to
@widget and calls [method@Gtk.FixedLayoutChild.set_transform]. *)

external remove :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_fixed_remove"
(** Removes a child from @fixed. *)

external put :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  float ->
  float ->
  unit = "ml_gtk_fixed_put"
(** Adds a widget to a `GtkFixed` at the given position. *)

external move :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  float ->
  float ->
  unit = "ml_gtk_fixed_move"
(** Sets a translation transformation to the given @x and @y
coordinates to the child @widget of the `GtkFixed`. *)

external get_child_transform :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Ocgtk_gsk.Gsk.Wrappers.Transform.t option = "ml_gtk_fixed_get_child_transform"
(** Retrieves the transformation for @widget set using
gtk_fixed_set_child_transform(). *)

external get_child_position :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  float * float = "ml_gtk_fixed_get_child_position"
(** Retrieves the translation transformation of the given child `GtkWidget` in
    the `GtkFixed`.

    See also: [method@Gtk.Fixed.get_child_transform]. *)
