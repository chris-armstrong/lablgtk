(* GENERATED CODE - DO NOT EDIT *)
(* StackPage: StackPage *)

type t = [ `stack_page | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_stack_page_get_type"

(* Methods *)

external set_visible : t -> bool -> unit = "ml_gtk_stack_page_set_visible"
(** Sets whether @page is visible in its `GtkStack`. *)

external set_use_underline : t -> bool -> unit
  = "ml_gtk_stack_page_set_use_underline"
(** Sets whether underlines in the page title indicate mnemonics. *)

external set_title : t -> string -> unit = "ml_gtk_stack_page_set_title"
(** Sets the page title. *)

external set_needs_attention : t -> bool -> unit
  = "ml_gtk_stack_page_set_needs_attention"
(** Sets whether the page is marked as “needs attention”. *)

external set_name : t -> string -> unit = "ml_gtk_stack_page_set_name"
(** Sets the name of the page. *)

external set_icon_name : t -> string -> unit = "ml_gtk_stack_page_set_icon_name"
(** Sets the icon name of the page. *)

external get_visible : t -> bool = "ml_gtk_stack_page_get_visible"
(** Returns whether @page is visible in its `GtkStack`.

This is independent from the [property@Gtk.Widget:visible]
property of its widget. *)

external get_use_underline : t -> bool = "ml_gtk_stack_page_get_use_underline"
(** Gets whether underlines in the page title indicate mnemonics. *)

external get_title : t -> string option = "ml_gtk_stack_page_get_title"
(** Gets the page title. *)

external get_needs_attention : t -> bool
  = "ml_gtk_stack_page_get_needs_attention"
(** Returns whether the page is marked as “needs attention”. *)

external get_name : t -> string option = "ml_gtk_stack_page_get_name"
(** Returns the name of the page. *)

external get_icon_name : t -> string option = "ml_gtk_stack_page_get_icon_name"
(** Returns the icon name of the page. *)

external get_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t = "ml_gtk_stack_page_get_child"
(** Returns the stack child to which @self belongs. *)

(* Properties *)
