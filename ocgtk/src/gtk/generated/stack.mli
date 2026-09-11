(* GENERATED CODE - DO NOT EDIT *)
(* Stack: Stack *)

type t = [ `stack | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_stack_get_type"

external new_ : unit -> t = "ml_gtk_stack_new"
(** Create a new Stack *)

(* Methods *)

external set_visible_child_name : t -> string -> unit
  = "ml_gtk_stack_set_visible_child_name"
(** Makes the child with the given name visible.

If @child is different from the currently visible child,
the transition between the two will be animated with the
current transition type of @stack.

Note that the child widget has to be visible itself
(see [method@Gtk.Widget.show]) in order to become the visible
child of @stack. *)

external set_visible_child_full :
  t -> string -> Gtk_enums.stacktransitiontype -> unit
  = "ml_gtk_stack_set_visible_child_full"
(** Makes the child with the given name visible.

Note that the child widget has to be visible itself
(see [method@Gtk.Widget.show]) in order to become the visible
child of @stack. *)

external set_visible_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_stack_set_visible_child"
(** Makes @child the visible child of @stack.

If @child is different from the currently visible child,
the transition between the two will be animated with the
current transition type of @stack.

Note that the @child widget has to be visible itself
(see [method@Gtk.Widget.show]) in order to become the visible
child of @stack. *)

external set_vhomogeneous : t -> bool -> unit = "ml_gtk_stack_set_vhomogeneous"
(** Sets the `GtkStack` to be vertically homogeneous or not.

    If it is homogeneous, the `GtkStack` will request the same height for all
    its children. If it isn't, the stack may change height when a different
    child becomes visible. *)

external set_transition_type : t -> Gtk_enums.stacktransitiontype -> unit
  = "ml_gtk_stack_set_transition_type"
(** Sets the type of animation that will be used for
transitions between pages in @stack.

Available types include various kinds of fades and slides.

The transition type can be changed without problems
at runtime, so it is possible to change the animation
based on the page that is about to become current. *)

external set_transition_duration : t -> int -> unit
  = "ml_gtk_stack_set_transition_duration"
(** Sets the duration that transitions between pages in @stack
will take. *)

external set_interpolate_size : t -> bool -> unit
  = "ml_gtk_stack_set_interpolate_size"
(** Sets whether or not @stack will interpolate its size when
changing the visible child.

If the [property@Gtk.Stack:interpolate-size] property is set
to %TRUE, @stack will interpolate its size between the current
one and the one it'll take after changing the visible child,
according to the set transition duration. *)

external set_hhomogeneous : t -> bool -> unit = "ml_gtk_stack_set_hhomogeneous"
(** Sets the `GtkStack` to be horizontally homogeneous or not.

    If it is homogeneous, the `GtkStack` will request the same width for all its
    children. If it isn't, the stack may change width when a different child
    becomes visible. *)

external remove :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_stack_remove"
(** Removes a child widget from @stack. *)

external get_visible_child_name : t -> string option
  = "ml_gtk_stack_get_visible_child_name"
(** Returns the name of the currently visible child of @stack.

Returns %NULL if there is no visible child. *)

external get_visible_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_stack_get_visible_child"
(** Gets the currently visible child of @stack.

Returns %NULL if there are no visible children. *)

external get_vhomogeneous : t -> bool = "ml_gtk_stack_get_vhomogeneous"
(** Gets whether @stack is vertically homogeneous. *)

external get_transition_type : t -> Gtk_enums.stacktransitiontype
  = "ml_gtk_stack_get_transition_type"
(** Gets the type of animation that will be used
for transitions between pages in @stack. *)

external get_transition_running : t -> bool
  = "ml_gtk_stack_get_transition_running"
(** Returns whether the @stack is currently in a transition from one page to
another. *)

external get_transition_duration : t -> int
  = "ml_gtk_stack_get_transition_duration"
(** Returns the amount of time (in milliseconds) that
transitions between pages in @stack will take. *)

external get_pages : t -> Selection_model.t = "ml_gtk_stack_get_pages"
(** Returns a `GListModel` that contains the pages of the stack.

    This can be used to keep an up-to-date view. The model also implements
    [iface@Gtk.SelectionModel] and can be used to track and modify the visible
    page. *)

external get_page :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Stack_page.t = "ml_gtk_stack_get_page"
(** Returns the `GtkStackPage` object for @child. *)

external get_interpolate_size : t -> bool = "ml_gtk_stack_get_interpolate_size"
(** Returns whether the `GtkStack` is set up to interpolate between the sizes of
    children on page switch. *)

external get_hhomogeneous : t -> bool = "ml_gtk_stack_get_hhomogeneous"
(** Gets whether @stack is horizontally homogeneous. *)

external get_child_by_name :
  t ->
  string ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_stack_get_child_by_name"
(** Finds the child with the name given as the argument.

    Returns %NULL if there is no child with this name. *)

external add_titled :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  string option ->
  string ->
  Stack_page.t = "ml_gtk_stack_add_titled"
(** Adds a child to @stack.

The child is identified by the @name. The @title
will be used by `GtkStackSwitcher` to represent
@child in a tab bar, so it should be short. *)

external add_named :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  string option ->
  Stack_page.t = "ml_gtk_stack_add_named"
(** Adds a child to @stack.

The child is identified by the @name. *)

external add_child :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Stack_page.t = "ml_gtk_stack_add_child"
(** Adds a child to @stack. *)

(* Properties *)
