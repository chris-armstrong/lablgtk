(* GENERATED CODE - DO NOT EDIT *)
(* Constraint: Constraint *)

type t = [ `constraint_ | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_constraint_get_type"

external new_ :
  Constraint_target.t option ->
  Gtk_enums.constraintattribute ->
  Gtk_enums.constraintrelation ->
  Constraint_target.t option ->
  Gtk_enums.constraintattribute ->
  float ->
  float ->
  int ->
  t = "ml_gtk_constraint_new_bytecode" "ml_gtk_constraint_new_native"
(** Create a new Constraint *)

external new_constant :
  Constraint_target.t option ->
  Gtk_enums.constraintattribute ->
  Gtk_enums.constraintrelation ->
  float ->
  int ->
  t = "ml_gtk_constraint_new_constant"
(** Create a new Constraint *)

(* Methods *)

external is_required : t -> bool = "ml_gtk_constraint_is_required"
(** Checks whether the constraint is a required relation for solving the
    constraint layout. *)

external is_constant : t -> bool = "ml_gtk_constraint_is_constant"
(** Checks whether the constraint describes a relation between an attribute on
    the [property@Gtk.Constraint:target] and a constant value. *)

external is_attached : t -> bool = "ml_gtk_constraint_is_attached"
(** Checks whether the constraint is attached to a [class@Gtk.ConstraintLayout],
    and it is contributing to the layout. *)

external get_target_attribute : t -> Gtk_enums.constraintattribute
  = "ml_gtk_constraint_get_target_attribute"
(** Retrieves the attribute of the target to be set by the constraint. *)

external get_target : t -> Constraint_target.t option
  = "ml_gtk_constraint_get_target"
(** Retrieves the [iface@Gtk.ConstraintTarget] used as the target for the
    constraint.

    If the targe is set to `NULL` at creation, the constraint will use the
    widget using the [class@Gtk.ConstraintLayout] as the target. *)

external get_strength : t -> int = "ml_gtk_constraint_get_strength"
(** Retrieves the strength of the constraint. *)

external get_source_attribute : t -> Gtk_enums.constraintattribute
  = "ml_gtk_constraint_get_source_attribute"
(** Retrieves the attribute of the source to be read by the constraint. *)

external get_source : t -> Constraint_target.t option
  = "ml_gtk_constraint_get_source"
(** Retrieves the [iface@Gtk.ConstraintTarget] used as the source for the
    constraint.

    If the source is set to `NULL` at creation, the constraint will use the
    widget using the [class@Gtk.ConstraintLayout] as the source. *)

external get_relation : t -> Gtk_enums.constraintrelation
  = "ml_gtk_constraint_get_relation"
(** The order relation between the terms of the constraint. *)

external get_multiplier : t -> float = "ml_gtk_constraint_get_multiplier"
(** Retrieves the multiplication factor applied to the source attribute's value.
*)

external get_constant : t -> float = "ml_gtk_constraint_get_constant"
(** Retrieves the constant factor added to the source attributes' value. *)

(* Properties *)
