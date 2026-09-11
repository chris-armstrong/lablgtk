(* GENERATED CODE - DO NOT EDIT *)
(* StackSwitcher: StackSwitcher *)

type t =
  [ `stack_switcher | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_stack_switcher_get_type"

external new_ : unit -> t = "ml_gtk_stack_switcher_new"
(** Create a new StackSwitcher *)

(* Methods *)

external set_stack : t -> Stack.t option -> unit
  = "ml_gtk_stack_switcher_set_stack"
(** Sets the stack to control. *)

external get_stack : t -> Stack.t option = "ml_gtk_stack_switcher_get_stack"
(** Retrieves the stack. *)

(* Properties *)
