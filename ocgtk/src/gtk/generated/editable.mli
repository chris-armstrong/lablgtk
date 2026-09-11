(* GENERATED CODE - DO NOT EDIT *)
(* Editable: Editable *)

type t = [ `editable ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_editable_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gtk_editable_from_gobject"

(* Methods *)

external set_width_chars : t -> int -> unit = "ml_gtk_editable_set_width_chars"
(** Changes the size request of the editable to be about the
right size for @n_chars characters.

Note that it changes the size request, the size can still
be affected by how you pack the widget into containers.
If @n_chars is -1, the size reverts to the default size. *)

external set_text : t -> string -> unit = "ml_gtk_editable_set_text"
(** Sets the text in the editable to the given value.

    This is replacing the current contents. *)

external set_position : t -> int -> unit = "ml_gtk_editable_set_position"
(** Sets the cursor position in the editable to the given value.

The cursor is displayed before the character with the given (base 0)
index in the contents of the editable. The value must be less than
or equal to the number of characters in the editable. A value of -1
indicates that the position should be set after the last character
of the editable. Note that @position is in characters, not in bytes. *)

external set_max_width_chars : t -> int -> unit
  = "ml_gtk_editable_set_max_width_chars"
(** Sets the desired maximum width in characters of @editable. *)

external set_enable_undo : t -> bool -> unit = "ml_gtk_editable_set_enable_undo"
(** If enabled, changes to @editable will be saved for undo/redo
actions.

This results in an additional copy of text changes and are not
stored in secure memory. As such, undo is forcefully disabled
when [property@Gtk.Text:visibility] is set to %FALSE. *)

external set_editable : t -> bool -> unit = "ml_gtk_editable_set_editable"
(** Determines if the user can edit the text in the editable widget. *)

external set_alignment : t -> float -> unit = "ml_gtk_editable_set_alignment"
(** Sets the alignment for the contents of the editable.

    This controls the horizontal positioning of the contents when the displayed
    text is shorter than the width of the editable. *)

external select_region : t -> int -> int -> unit
  = "ml_gtk_editable_select_region"
(** Selects a region of text.

The characters that are selected are those characters at positions
from @start_pos up to, but not including @end_pos. If @end_pos is
negative, then the characters selected are those characters from
@start_pos to  the end of the text.

Note that positions are specified in characters, not bytes. *)

external insert_text : t -> string -> int -> int -> unit
  = "ml_gtk_editable_insert_text"
(** Inserts @length bytes of @text into the contents of the
widget, at position @position.

Note that the position is in characters, not in bytes.
The function updates @position to point after the newly
inserted text. *)

external init_delegate : t -> unit = "ml_gtk_editable_init_delegate"
(** Sets up a delegate for `GtkEditable`.

This is assuming that the get_delegate vfunc in the `GtkEditable`
interface has been set up for the @editable's type.

This is a helper function that should be called in instance init,
after creating the delegate object. *)

external get_width_chars : t -> int = "ml_gtk_editable_get_width_chars"
(** Gets the number of characters of space reserved for the contents of the
    editable. *)

external get_text : t -> string = "ml_gtk_editable_get_text"
(** Retrieves the contents of @editable.

The returned string is owned by GTK and must not be modified or freed. *)

external get_selection_bounds : t -> bool * int * int
  = "ml_gtk_editable_get_selection_bounds"
(** Retrieves the selection bound of the editable.

@start_pos will be filled with the start of the selection and
@end_pos with end. If no text was selected both will be identical
and %FALSE will be returned.

Note that positions are specified in characters, not bytes. *)

external get_position : t -> int = "ml_gtk_editable_get_position"
(** Retrieves the current position of the cursor relative to the start of the
    content of the editable.

    Note that this position is in characters, not in bytes. *)

external get_max_width_chars : t -> int = "ml_gtk_editable_get_max_width_chars"
(** Retrieves the desired maximum width of @editable, in characters. *)

external get_enable_undo : t -> bool = "ml_gtk_editable_get_enable_undo"
(** Gets if undo/redo actions are enabled for @editable *)

external get_editable : t -> bool = "ml_gtk_editable_get_editable"
(** Retrieves whether @editable is editable. *)

external get_delegate : t -> t option = "ml_gtk_editable_get_delegate"
(** Gets the `GtkEditable` that @editable is delegating its
implementation to.

Typically, the delegate is a [class@Gtk.Text] widget. *)

external get_chars : t -> int -> int -> string = "ml_gtk_editable_get_chars"
(** Retrieves a sequence of characters.

The characters that are retrieved are those characters at positions
from @start_pos up to, but not including @end_pos. If @end_pos is negative,
then the characters retrieved are those characters from @start_pos to
the end of the text.

Note that positions are specified in characters, not bytes. *)

external get_alignment : t -> float = "ml_gtk_editable_get_alignment"
(** Gets the alignment of the editable. *)

external finish_delegate : t -> unit = "ml_gtk_editable_finish_delegate"
(** Undoes the setup done by [method@Gtk.Editable.init_delegate].

    This is a helper function that should be called from dispose, before
    removing the delegate object. *)

external delete_text : t -> int -> int -> unit = "ml_gtk_editable_delete_text"
(** Deletes a sequence of characters.

The characters that are deleted are those characters at positions
from @start_pos up to, but not including @end_pos. If @end_pos is
negative, then the characters deleted are those from @start_pos to
the end of the text.

Note that the positions are specified in characters, not bytes. *)

external delete_selection : t -> unit = "ml_gtk_editable_delete_selection"
(** Deletes the currently selected text of the editable.

    This call doesn’t do anything if there is no selected text. *)

external delegate_get_accessible_platform_state :
  t -> Gtk_enums.accessibleplatformstate -> bool
  = "ml_gtk_editable_delegate_get_accessible_platform_state"
(** Retrieves the accessible platform state from the editable delegate.

This is an helper function to retrieve the accessible state for
`GtkEditable` interface implementations using a delegate pattern.

You should call this function in your editable widget implementation
of the [vfunc@Gtk.Accessible.get_platform_state] virtual function, for
instance:

```c
static void
accessible_interface_init (GtkAccessibleInterface *iface)
{
  iface->get_platform_state = your_editable_get_accessible_platform_state;
}

static gboolean
your_editable_get_accessible_platform_state (GtkAccessible *accessible,
                                             GtkAccessiblePlatformState state)
{
  return gtk_editable_delegate_get_accessible_platform_state (GTK_EDITABLE (accessible), state);
}
```

Note that the widget which is the delegate *must* be a direct child of
this widget, otherwise your implementation of [vfunc@Gtk.Accessible.get_platform_state]
might not even be called, as the platform change will originate from
the parent of the delegate, and, as a result, will not work properly.

So, if you can't ensure the direct child condition, you should give the
delegate the %GTK_ACCESSIBLE_ROLE_TEXT_BOX role, or you can
change your tree to allow this function to work. *)

(* Properties *)

external get_selection_bound : t -> int = "ml_gtk_editable_get_selection_bound"
(** Get property: selection-bound *)

val on_changed :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_delete_text :
  ?after:bool ->
  t ->
  callback:(start_pos:int -> end_pos:int -> unit) ->
  Gobject.Signal.handler_id
