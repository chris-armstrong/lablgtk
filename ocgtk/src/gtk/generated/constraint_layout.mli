(* GENERATED CODE - DO NOT EDIT *)
(* ConstraintLayout: ConstraintLayout *)

type t = [ `constraint_layout | `layout_manager | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_constraint_layout_get_type"

external new_ : unit -> t = "ml_gtk_constraint_layout_new"
(** Create a new ConstraintLayout *)

(* Methods *)

external remove_guide : t -> Constraint_guide.t -> unit
  = "ml_gtk_constraint_layout_remove_guide"
(** Removes `guide` from the layout manager, so that it no longer influences the
    layout. *)

external remove_constraint : t -> Constraint.t -> unit
  = "ml_gtk_constraint_layout_remove_constraint"
(** Removes `constraint` from the layout manager, so that it no longer
    influences the layout. *)

external remove_all_constraints : t -> unit
  = "ml_gtk_constraint_layout_remove_all_constraints"
(** Removes all constraints from the layout manager. *)

external observe_guides : t -> Ocgtk_gio.Gio.Wrappers.List_model.t
  = "ml_gtk_constraint_layout_observe_guides"
(** Returns a `GListModel` to track the guides that are part of the layout.

    Calling this function will enable extra internal bookkeeping to track guides
    and emit signals on the returned listmodel. It may slow down operations a
    lot.

    Applications should try hard to avoid calling this function because of the
    slowdowns. *)

external observe_constraints : t -> Ocgtk_gio.Gio.Wrappers.List_model.t
  = "ml_gtk_constraint_layout_observe_constraints"
(** Returns a `GListModel` to track the constraints that are part of the layout.

    Calling this function will enable extra internal bookkeeping to track
    constraints and emit signals on the returned listmodel. It may slow down
    operations a lot.

    Applications should try hard to avoid calling this function because of the
    slowdowns. *)

external add_guide : t -> Constraint_guide.t -> unit
  = "ml_gtk_constraint_layout_add_guide"
(** Adds a guide to `layout`.

    A guide can be used as the source or target of constraints, like a widget,
    but it is not visible.

    The `layout` acquires the ownership of `guide` after calling this function.
*)

external add_constraint : t -> Constraint.t -> unit
  = "ml_gtk_constraint_layout_add_constraint"
(** Adds a constraint to the layout manager.

The [property@Gtk.Constraint:source] and [property@Gtk.Constraint:target]
properties of `constraint` can be:

 - set to `NULL` to indicate that the constraint refers to the
   widget using `layout`
 - set to the [class@Gtk.Widget] using `layout`
 - set to a child of the [class@Gtk.Widget] using `layout`
 - set to a [class@Gtk.ConstraintGuide] that is part of `layout`

The @layout acquires the ownership of @constraint after calling
this function. *)
