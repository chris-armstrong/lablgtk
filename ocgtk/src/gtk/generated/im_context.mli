(* GENERATED CODE - DO NOT EDIT *)
(* IMContext: IMContext *)

type t = [ `im_context | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_im_context_get_type"

(* Methods *)

external set_use_preedit : t -> bool -> unit
  = "ml_gtk_im_context_set_use_preedit"
(** Sets whether the IM context should use the preedit string
to display feedback.

If @use_preedit is %FALSE (default is %TRUE), then the IM context
may use some other method to display feedback, such as displaying
it in a child of the root window. *)

external set_surrounding_with_selection :
  t -> string -> int -> int -> int -> unit
  = "ml_gtk_im_context_set_surrounding_with_selection"
(** Sets surrounding context around the insertion point and preedit string. This
    function is expected to be called in response to the
    [signal@Gtk.IMContext::retrieve_surrounding] signal, and will likely have no
    effect if called at other times. *)

external set_surrounding : t -> string -> int -> int -> unit
  = "ml_gtk_im_context_set_surrounding"
(** Sets surrounding context around the insertion point and preedit string.

    This function is expected to be called in response to the
    [signal@Gtk.IMContext::retrieve-surrounding] signal, and will likely have no
    effect if called at other times. *)

external set_cursor_location : t -> Ocgtk_gdk.Gdk.Wrappers.Rectangle.t -> unit
  = "ml_gtk_im_context_set_cursor_location"
(** Notify the input method that a change in cursor position has been made.

    The location is relative to the client widget. *)

external set_client_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_im_context_set_client_widget"
(** Set the client widget for the input context.

    This is the `GtkWidget` holding the input focus. This widget is used in
    order to correctly position status windows, and may also be used for
    purposes internal to the input method. *)

external reset : t -> unit = "ml_gtk_im_context_reset"
(** Notify the input method that a change such as a change in cursor position
    has been made.

    This will typically cause the input method to clear the preedit state. *)

external focus_out : t -> unit = "ml_gtk_im_context_focus_out"
(** Notify the input method that the widget to which this input context
    corresponds has lost focus.

    The input method may, for example, change the displayed feedback or reset
    the contexts state to reflect this change. *)

external focus_in : t -> unit = "ml_gtk_im_context_focus_in"
(** Notify the input method that the widget to which this input context
    corresponds has gained focus.

    The input method may, for example, change the displayed feedback to reflect
    this change. *)

external filter_keypress : t -> Ocgtk_gdk.Gdk.Wrappers.Event.t -> bool
  = "ml_gtk_im_context_filter_keypress"
(** Allow an input method to internally handle key press and release events.

    If this function returns %TRUE, then no further processing should be done
    for this key event. *)

external filter_key :
  t ->
  bool ->
  Ocgtk_gdk.Gdk.Wrappers.Surface.t ->
  Ocgtk_gdk.Gdk.Wrappers.Device.t ->
  UInt32.t ->
  int ->
  Ocgtk_gdk.Gdk.modifiertype ->
  int ->
  bool
  = "ml_gtk_im_context_filter_key_bytecode"
    "ml_gtk_im_context_filter_key_native"
(** Allow an input method to forward key press and release events to another
    input method without necessarily having a `GdkEvent` available. *)

external delete_surrounding : t -> int -> int -> bool
  = "ml_gtk_im_context_delete_surrounding"
(** Asks the widget that the input context is attached to delete
characters around the cursor position by emitting the
`::delete_surrounding` signal.

Note that @offset and @n_chars are in characters not in bytes
which differs from the usage other places in `GtkIMContext`.

In order to use this function, you should first call
[method@Gtk.IMContext.get_surrounding] to get the current context,
and call this function immediately afterwards to make sure that you
know what you are deleting. You should also account for the fact
that even if the signal was handled, the input context might not
have deleted all the characters that were requested to be deleted.

This function is used by an input method that wants to make
substitutions in the existing text in response to new input.
It is not useful for applications. *)

external activate_osk : t -> Ocgtk_gdk.Gdk.Wrappers.Event.t option -> bool
  = "ml_gtk_im_context_activate_osk"
(** Requests the platform to show an on-screen keyboard for user input.

    This method will return %TRUE if this request was actually performed to the
    platform, other environmental factors may result in an on-screen keyboard
    effectively not showing up. *)

(* Properties *)

external get_input_hints : t -> Gtk_enums.inputhints
  = "ml_gtk_im_context_get_input_hints"
(** Get property: input-hints *)

external set_input_hints : t -> Gtk_enums.inputhints -> unit
  = "ml_gtk_im_context_set_input_hints"
(** Set property: input-hints *)

external get_input_purpose : t -> Gtk_enums.inputpurpose
  = "ml_gtk_im_context_get_input_purpose"
(** Get property: input-purpose *)

external set_input_purpose : t -> Gtk_enums.inputpurpose -> unit
  = "ml_gtk_im_context_set_input_purpose"
(** Set property: input-purpose *)

val on_commit :
  ?after:bool -> t -> callback:(str:string -> unit) -> Gobject.Signal.handler_id

val on_delete_surrounding :
  ?after:bool ->
  t ->
  callback:(offset:int -> n_chars:int -> bool) ->
  Gobject.Signal.handler_id

val on_preedit_changed :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_preedit_end :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_preedit_start :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_retrieve_surrounding :
  ?after:bool -> t -> callback:(unit -> bool) -> Gobject.Signal.handler_id
