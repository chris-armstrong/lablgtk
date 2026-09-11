(* GENERATED CODE - DO NOT EDIT *)
(* StackSidebar: StackSidebar *)

type t =
  [ `stack_sidebar | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_stack_sidebar_get_type"

external new_ : unit -> t = "ml_gtk_stack_sidebar_new"
(** Create a new StackSidebar *)

(* Methods *)

external set_stack : t -> Stack.t -> unit = "ml_gtk_stack_sidebar_set_stack"
(** Set the `GtkStack` associated with this `GtkStackSidebar`.

    The sidebar widget will automatically update according to the order and
    items within the given `GtkStack`. *)

external get_stack : t -> Stack.t option = "ml_gtk_stack_sidebar_get_stack"
(** Retrieves the stack. *)

(* Properties *)
