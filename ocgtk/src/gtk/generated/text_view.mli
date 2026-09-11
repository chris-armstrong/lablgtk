(* GENERATED CODE - DO NOT EDIT *)
(* TextView: TextView *)

type t = [ `text_view | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_text_view_get_type"

external new_ : unit -> t = "ml_gtk_text_view_new"
(** Create a new TextView *)

external new_with_buffer :
  Text_buffer_and__text_iter_and__text_mark.Text_buffer.t -> t
  = "ml_gtk_text_view_new_with_buffer"
(** Create a new TextView *)

(* Methods *)

external window_to_buffer_coords :
  t -> Gtk_enums.textwindowtype -> int -> int -> int * int
  = "ml_gtk_text_view_window_to_buffer_coords"
(** Converts coordinates on the window identified by @win to buffer
coordinates. *)

external starts_display_line :
  t -> Text_buffer_and__text_iter_and__text_mark.Text_iter.t -> bool
  = "ml_gtk_text_view_starts_display_line"
(** Determines whether @iter is at the start of a display line.

See [method@Gtk.TextView.forward_display_line] for an
explanation of display lines vs. paragraphs. *)

external set_wrap_mode : t -> Gtk_enums.wrapmode -> unit
  = "ml_gtk_text_view_set_wrap_mode"
(** Sets the line wrapping for the view. *)

external set_top_margin : t -> int -> unit = "ml_gtk_text_view_set_top_margin"
(** Sets the top margin for text in @text_view.

Note that this function is confusingly named.
In CSS terms, the value set here is padding. *)

external set_tabs : t -> Ocgtk_pango.Pango.Wrappers.Tab_array.t -> unit
  = "ml_gtk_text_view_set_tabs"
(** Sets the default tab stops for paragraphs in @text_view.

Tags in the buffer may override the default. *)

external set_right_margin : t -> int -> unit
  = "ml_gtk_text_view_set_right_margin"
(** Sets the default right margin for text in the text view.

    Tags in the buffer may override the default.

    Note that this function is confusingly named. In CSS terms, the value set
    here is padding. *)

external set_pixels_inside_wrap : t -> int -> unit
  = "ml_gtk_text_view_set_pixels_inside_wrap"
(** Sets the default number of pixels of blank space to leave between
display/wrapped lines within a paragraph.

May be overridden by tags in @text_view’s buffer. *)

external set_pixels_below_lines : t -> int -> unit
  = "ml_gtk_text_view_set_pixels_below_lines"
(** Sets the default number of pixels of blank space
to put below paragraphs in @text_view.

May be overridden by tags applied to @text_view’s buffer. *)

external set_pixels_above_lines : t -> int -> unit
  = "ml_gtk_text_view_set_pixels_above_lines"
(** Sets the default number of blank pixels above paragraphs in @text_view.

Tags in the buffer for @text_view may override the defaults. *)

external set_overwrite : t -> bool -> unit = "ml_gtk_text_view_set_overwrite"
(** Changes the `GtkTextView` overwrite mode. *)

external set_monospace : t -> bool -> unit = "ml_gtk_text_view_set_monospace"
(** Sets whether the `GtkTextView` should display text in monospace styling. *)

external set_left_margin : t -> int -> unit = "ml_gtk_text_view_set_left_margin"
(** Sets the default left margin for text in @text_view.

Tags in the buffer may override the default.

Note that this function is confusingly named.
In CSS terms, the value set here is padding. *)

external set_justification : t -> Gtk_enums.justification -> unit
  = "ml_gtk_text_view_set_justification"
(** Sets the default justification of text in @text_view.

Tags in the view’s buffer may override the default. *)

external set_input_purpose : t -> Gtk_enums.inputpurpose -> unit
  = "ml_gtk_text_view_set_input_purpose"
(** Sets the `input-purpose` of the `GtkTextView`.

    The `input-purpose` can be used by on-screen keyboards and other input
    methods to adjust their behaviour. *)

external set_input_hints : t -> Gtk_enums.inputhints -> unit
  = "ml_gtk_text_view_set_input_hints"
(** Sets the `input-hints` of the `GtkTextView`.

    The `input-hints` allow input methods to fine-tune their behaviour. *)

external set_indent : t -> int -> unit = "ml_gtk_text_view_set_indent"
(** Sets the default indentation for paragraphs in @text_view.

Tags in the buffer may override the default. *)

external set_gutter :
  t ->
  Gtk_enums.textwindowtype ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_text_view_set_gutter"
(** Places @widget into the gutter specified by @win.

@win must be one of %GTK_TEXT_WINDOW_LEFT, %GTK_TEXT_WINDOW_RIGHT,
%GTK_TEXT_WINDOW_TOP, or %GTK_TEXT_WINDOW_BOTTOM. *)

external set_extra_menu :
  t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option -> unit
  = "ml_gtk_text_view_set_extra_menu"
(** Sets a menu model to add when constructing the context
menu for @text_view.

You can pass %NULL to remove a previously set extra menu. *)

external set_editable : t -> bool -> unit = "ml_gtk_text_view_set_editable"
(** Sets the default editability of the `GtkTextView`.

    You can override this default setting with tags in the buffer, using the
    “editable” attribute of tags. *)

external set_cursor_visible : t -> bool -> unit
  = "ml_gtk_text_view_set_cursor_visible"
(** Toggles whether the insertion point should be displayed.

    A buffer with no editable text probably shouldn’t have a visible cursor, so
    you may want to turn the cursor off.

    Note that this property may be overridden by the
    [property@Gtk.Settings:gtk-keynav-use-caret] setting. *)

external set_buffer :
  t -> Text_buffer_and__text_iter_and__text_mark.Text_buffer.t option -> unit
  = "ml_gtk_text_view_set_buffer"
(** Sets @buffer as the buffer being displayed by @text_view.

The previous buffer displayed by the text view is unreferenced, and
a reference is added to @buffer. If you owned a reference to @buffer
before passing it to this function, you must remove that reference
yourself; `GtkTextView` will not “adopt” it. *)

external set_bottom_margin : t -> int -> unit
  = "ml_gtk_text_view_set_bottom_margin"
(** Sets the bottom margin for text in @text_view.

Note that this function is confusingly named.
In CSS terms, the value set here is padding. *)

external set_accepts_tab : t -> bool -> unit
  = "ml_gtk_text_view_set_accepts_tab"
(** Sets the behavior of the text widget when the <kbd>Tab</kbd> key is pressed.

If @accepts_tab is %TRUE, a tab character is inserted. If @accepts_tab
is %FALSE the keyboard focus is moved to the next widget in the focus
chain.

Focus can always be moved using <kbd>Ctrl</kbd>+<kbd>Tab</kbd>. *)

external scroll_to_mark :
  t ->
  Text_buffer_and__text_iter_and__text_mark.Text_mark.t ->
  float ->
  bool ->
  float ->
  float ->
  unit
  = "ml_gtk_text_view_scroll_to_mark_bytecode"
    "ml_gtk_text_view_scroll_to_mark_native"
(** Scrolls @text_view so that @mark is on the screen in the position
indicated by @xalign and @yalign.

An alignment of 0.0 indicates left or top, 1.0 indicates right or
bottom, 0.5 means center. If @use_align is %FALSE, the text scrolls
the minimal distance to get the mark onscreen, possibly not scrolling
at all. The effective screen for purposes of this function is reduced
by a margin of size @within_margin. *)

external scroll_to_iter :
  t ->
  Text_buffer_and__text_iter_and__text_mark.Text_iter.t ->
  float ->
  bool ->
  float ->
  float ->
  bool
  = "ml_gtk_text_view_scroll_to_iter_bytecode"
    "ml_gtk_text_view_scroll_to_iter_native"
(** Scrolls @text_view so that @iter is on the screen in the position
indicated by @xalign and @yalign.

An alignment of 0.0 indicates left or top, 1.0 indicates right or
bottom, 0.5 means center. If @use_align is %FALSE, the text scrolls
the minimal distance to get the mark onscreen, possibly not scrolling
at all. The effective screen for purposes of this function is reduced
by a margin of size @within_margin.

Note that this function uses the currently-computed height of the
lines in the text buffer. Line heights are computed in an idle
handler; so this function may not have the desired effect if it’s
called before the height computations. To avoid oddness, consider
using [method@Gtk.TextView.scroll_to_mark] which saves a point to be
scrolled to after line validation. *)

external scroll_mark_onscreen :
  t -> Text_buffer_and__text_iter_and__text_mark.Text_mark.t -> unit
  = "ml_gtk_text_view_scroll_mark_onscreen"
(** Scrolls @text_view the minimum distance such that @mark is contained
within the visible area of the widget. *)

external reset_im_context : t -> unit = "ml_gtk_text_view_reset_im_context"
(** Reset the input method context of the text view if needed.

    This can be necessary in the case where modifying the buffer would confuse
    on-going input method behavior. *)

external reset_cursor_blink : t -> unit = "ml_gtk_text_view_reset_cursor_blink"
(** Ensures that the cursor is shown.

    This also resets the time that it will stay blinking (or visible, in case
    blinking is disabled).

    This function should be called in response to user input (e.g. from derived
    classes that override the textview's event handlers). *)

external remove :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_text_view_remove"
(** Removes a child widget from @text_view. *)

external place_cursor_onscreen : t -> bool
  = "ml_gtk_text_view_place_cursor_onscreen"
(** Moves the cursor to the currently visible region of the buffer. *)

external move_visually :
  t -> Text_buffer_and__text_iter_and__text_mark.Text_iter.t -> int -> bool
  = "ml_gtk_text_view_move_visually"
(** Move the iterator a given number of characters visually, treating
it as the strong cursor position.

If @count is positive, then the new strong cursor position will
be @count positions to the right of the old cursor position.
If @count is negative then the new strong cursor position will
be @count positions to the left of the old cursor position.

In the presence of bi-directional text, the correspondence
between logical and visual order will depend on the direction
of the current run, and there may be jumps when the cursor
is moved off of the end of a run. *)

external move_overlay :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int ->
  int ->
  unit = "ml_gtk_text_view_move_overlay"
(** Updates the position of a child.

    See [method@Gtk.TextView.add_overlay]. *)

external move_mark_onscreen :
  t -> Text_buffer_and__text_iter_and__text_mark.Text_mark.t -> bool
  = "ml_gtk_text_view_move_mark_onscreen"
(** Moves a mark within the buffer so that it's located within the
    currently-visible text area. *)

external im_context_filter_keypress :
  t -> Ocgtk_gdk.Gdk.Wrappers.Event.t -> bool
  = "ml_gtk_text_view_im_context_filter_keypress"
(** Allow the `GtkTextView` input method to internally handle key press
and release events.

If this function returns %TRUE, then no further processing should be
done for this key event. See [method@Gtk.IMContext.filter_keypress].

Note that you are expected to call this function from your handler
when overriding key event handling. This is needed in the case when
you need to insert your own key handling between the input method
and the default key event handling of the `GtkTextView`.

```c
static gboolean
gtk_foo_bar_key_press_event (GtkWidget *widget,
                             GdkEvent  *event)
{
  guint keyval;

  gdk_event_get_keyval ((GdkEvent*\)event, &keyval);

  if (keyval == GDK_KEY_Return || keyval == GDK_KEY_KP_Enter)
    {
      if (gtk_text_view_im_context_filter_keypress (GTK_TEXT_VIEW (widget), event))
        return TRUE;
    }

  // Do some stuff

  return GTK_WIDGET_CLASS (gtk_foo_bar_parent_class)->key_press_event (widget, event);
}
``` *)

external get_wrap_mode : t -> Gtk_enums.wrapmode
  = "ml_gtk_text_view_get_wrap_mode"
(** Gets the line wrapping for the view. *)

external get_visible_rect : t -> Ocgtk_gdk.Gdk.Wrappers.Rectangle.t
  = "ml_gtk_text_view_get_visible_rect"
(** Fills @visible_rect with the currently-visible
region of the buffer, in buffer coordinates.

Convert to window coordinates with
[method@Gtk.TextView.buffer_to_window_coords]. *)

external get_visible_offset : t -> float option * float option
  = "ml_gtk_text_view_get_visible_offset"
(** Gets the X,Y offset in buffer coordinates of the top-left corner of the
    textview's text contents.

    This allows for more-precise positioning than what is provided by
    [method@Gtk.TextView.get_visible_rect] as you can discover what device pixel
    is being quantized for text positioning.

    You might want this when making ulterior widgets align with quantized device
    pixels of the textview contents such as line numbers. *)

external get_top_margin : t -> int = "ml_gtk_text_view_get_top_margin"
(** Gets the top margin for text in the @text_view. *)

external get_tabs : t -> Ocgtk_pango.Pango.Wrappers.Tab_array.t option
  = "ml_gtk_text_view_get_tabs"
(** Gets the default tabs for @text_view.

Tags in the buffer may override the defaults. The returned array
will be %NULL if “standard” (8-space) tabs are used. Free the
return value with [method@Pango.TabArray.free]. *)

external get_rtl_context : t -> Ocgtk_pango.Pango.Wrappers.Context.t
  = "ml_gtk_text_view_get_rtl_context"
(** Gets the `PangoContext` that is used for rendering RTL directed text
    layouts.

    The context may be replaced when CSS changes occur. *)

external get_right_margin : t -> int = "ml_gtk_text_view_get_right_margin"
(** Gets the default right margin for text in @text_view.

Tags in the buffer may override the default. *)

external get_pixels_inside_wrap : t -> int
  = "ml_gtk_text_view_get_pixels_inside_wrap"
(** Gets the default number of pixels to put between wrapped lines inside a
    paragraph. *)

external get_pixels_below_lines : t -> int
  = "ml_gtk_text_view_get_pixels_below_lines"
(** Gets the default number of pixels to put below paragraphs.

    The line space is the sum of the value returned by this function and the
    value returned by [method@Gtk.TextView.get_pixels_above_lines]. *)

external get_pixels_above_lines : t -> int
  = "ml_gtk_text_view_get_pixels_above_lines"
(** Gets the default number of pixels to put above paragraphs.

    Adding this function with [method@Gtk.TextView.get_pixels_below_lines] is
    equal to the line space between each paragraph. *)

external get_overwrite : t -> bool = "ml_gtk_text_view_get_overwrite"
(** Returns whether the `GtkTextView` is in overwrite mode or not. *)

external get_monospace : t -> bool = "ml_gtk_text_view_get_monospace"
(** Gets whether the `GtkTextView` uses monospace styling. *)

external get_ltr_context : t -> Ocgtk_pango.Pango.Wrappers.Context.t
  = "ml_gtk_text_view_get_ltr_context"
(** Gets the `PangoContext` that is used for rendering LTR directed text
    layouts.

    The context may be replaced when CSS changes occur. *)

external get_line_yrange :
  t -> Text_buffer_and__text_iter_and__text_mark.Text_iter.t -> int * int
  = "ml_gtk_text_view_get_line_yrange"
(** Gets the y coordinate of the top of the line containing @iter,
and the height of the line.

The coordinate is a buffer coordinate; convert to window
coordinates with [method@Gtk.TextView.buffer_to_window_coords]. *)

external get_line_at_y :
  t -> int -> Text_buffer_and__text_iter_and__text_mark.Text_iter.t * int
  = "ml_gtk_text_view_get_line_at_y"
(** Gets the `GtkTextIter` at the start of the line containing
the coordinate @y.

@y is in buffer coordinates, convert from window coordinates with
[method@Gtk.TextView.window_to_buffer_coords]. If non-%NULL,
@line_top will be filled with the coordinate of the top edge
of the line. *)

external get_left_margin : t -> int = "ml_gtk_text_view_get_left_margin"
(** Gets the default left margin size of paragraphs in the @text_view.

Tags in the buffer may override the default. *)

external get_justification : t -> Gtk_enums.justification
  = "ml_gtk_text_view_get_justification"
(** Gets the default justification of paragraphs in @text_view.

Tags in the buffer may override the default. *)

external get_iter_location :
  t ->
  Text_buffer_and__text_iter_and__text_mark.Text_iter.t ->
  Ocgtk_gdk.Gdk.Wrappers.Rectangle.t = "ml_gtk_text_view_get_iter_location"
(** Gets a rectangle which roughly contains the character at @iter.

The rectangle position is in buffer coordinates; use
[method@Gtk.TextView.buffer_to_window_coords] to convert these
coordinates to coordinates for one of the windows in the text view. *)

external get_iter_at_position :
  t ->
  int ->
  int ->
  bool * Text_buffer_and__text_iter_and__text_mark.Text_iter.t * int
  = "ml_gtk_text_view_get_iter_at_position"
(** Retrieves the iterator pointing to the character at buffer
coordinates @x and @y.

Buffer coordinates are coordinates for the entire buffer, not just
the currently-displayed portion. If you have coordinates from an event,
you have to convert those to buffer coordinates with
[method@Gtk.TextView.window_to_buffer_coords].

Note that this is different from [method@Gtk.TextView.get_iter_at_location],
which returns cursor locations, i.e. positions between characters. *)

external get_iter_at_location :
  t ->
  int ->
  int ->
  bool * Text_buffer_and__text_iter_and__text_mark.Text_iter.t
  = "ml_gtk_text_view_get_iter_at_location"
(** Retrieves the iterator at buffer coordinates @x and @y.

Buffer coordinates are coordinates for the entire buffer, not just
the currently-displayed portion. If you have coordinates from an
event, you have to convert those to buffer coordinates with
[method@Gtk.TextView.window_to_buffer_coords]. *)

external get_input_purpose : t -> Gtk_enums.inputpurpose
  = "ml_gtk_text_view_get_input_purpose"
(** Gets the `input-purpose` of the `GtkTextView`. *)

external get_input_hints : t -> Gtk_enums.inputhints
  = "ml_gtk_text_view_get_input_hints"
(** Gets the `input-hints` of the `GtkTextView`. *)

external get_indent : t -> int = "ml_gtk_text_view_get_indent"
(** Gets the default indentation of paragraphs in @text_view.

Tags in the view’s buffer may override the default.
The indentation may be negative. *)

external get_gutter :
  t ->
  Gtk_enums.textwindowtype ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_text_view_get_gutter"
(** Gets a `GtkWidget` that has previously been set as gutter.

See [method@Gtk.TextView.set_gutter].

@win must be one of %GTK_TEXT_WINDOW_LEFT, %GTK_TEXT_WINDOW_RIGHT,
%GTK_TEXT_WINDOW_TOP, or %GTK_TEXT_WINDOW_BOTTOM. *)

external get_extra_menu : t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t
  = "ml_gtk_text_view_get_extra_menu"
(** Gets the menu model that gets added to the context menu or %NULL if none has
    been set. *)

external get_editable : t -> bool = "ml_gtk_text_view_get_editable"
(** Returns the default editability of the `GtkTextView`.

    Tags in the buffer may override this setting for some ranges of text. *)

external get_cursor_visible : t -> bool = "ml_gtk_text_view_get_cursor_visible"
(** Find out whether the cursor should be displayed. *)

external get_cursor_locations :
  t ->
  Text_buffer_and__text_iter_and__text_mark.Text_iter.t option ->
  Ocgtk_gdk.Gdk.Wrappers.Rectangle.t * Ocgtk_gdk.Gdk.Wrappers.Rectangle.t
  = "ml_gtk_text_view_get_cursor_locations"
(** Determine the positions of the strong and weak cursors if the
insertion point is at @iter.

The position of each cursor is stored as a zero-width rectangle.
The strong cursor location is the location where characters of
the directionality equal to the base direction of the paragraph
are inserted. The weak cursor location is the location where
characters of the directionality opposite to the base direction
of the paragraph are inserted.

If @iter is %NULL, the actual cursor position is used.

Note that if @iter happens to be the actual cursor position, and
there is currently an IM preedit sequence being entered, the
returned locations will be adjusted to account for the preedit
cursor’s offset within the preedit sequence.

The rectangle position is in buffer coordinates; use
[method@Gtk.TextView.buffer_to_window_coords] to convert these
coordinates to coordinates for one of the windows in the text view. *)

external get_buffer :
  t -> Text_buffer_and__text_iter_and__text_mark.Text_buffer.t
  = "ml_gtk_text_view_get_buffer"
(** Returns the `GtkTextBuffer` being displayed by this text view.

    The reference count on the buffer is not incremented; the caller of this
    function won’t own a new reference. *)

external get_bottom_margin : t -> int = "ml_gtk_text_view_get_bottom_margin"
(** Gets the bottom margin for text in the @text_view. *)

external get_accepts_tab : t -> bool = "ml_gtk_text_view_get_accepts_tab"
(** Returns whether pressing the <kbd>Tab</kbd> key inserts a tab characters.

    See [method@Gtk.TextView.set_accepts_tab]. *)

external forward_display_line_end :
  t -> Text_buffer_and__text_iter_and__text_mark.Text_iter.t -> bool
  = "ml_gtk_text_view_forward_display_line_end"
(** Moves the given @iter forward to the next display line end.

A display line is different from a paragraph. Paragraphs are
separated by newlines or other paragraph separator characters.
Display lines are created by line-wrapping a paragraph. If
wrapping is turned off, display lines and paragraphs will be the
same. Display lines are divided differently for each view, since
they depend on the view’s width; paragraphs are the same in all
views, since they depend on the contents of the `GtkTextBuffer`. *)

external forward_display_line :
  t -> Text_buffer_and__text_iter_and__text_mark.Text_iter.t -> bool
  = "ml_gtk_text_view_forward_display_line"
(** Moves the given @iter forward by one display (wrapped) line.

A display line is different from a paragraph. Paragraphs are
separated by newlines or other paragraph separator characters.
Display lines are created by line-wrapping a paragraph. If
wrapping is turned off, display lines and paragraphs will be the
same. Display lines are divided differently for each view, since
they depend on the view’s width; paragraphs are the same in all
views, since they depend on the contents of the `GtkTextBuffer`. *)

external buffer_to_window_coords :
  t -> Gtk_enums.textwindowtype -> int -> int -> int * int
  = "ml_gtk_text_view_buffer_to_window_coords"
(** Converts buffer coordinates to window coordinates. *)

external backward_display_line_start :
  t -> Text_buffer_and__text_iter_and__text_mark.Text_iter.t -> bool
  = "ml_gtk_text_view_backward_display_line_start"
(** Moves the given @iter backward to the next display line start.

A display line is different from a paragraph. Paragraphs are
separated by newlines or other paragraph separator characters.
Display lines are created by line-wrapping a paragraph. If
wrapping is turned off, display lines and paragraphs will be the
same. Display lines are divided differently for each view, since
they depend on the view’s width; paragraphs are the same in all
views, since they depend on the contents of the `GtkTextBuffer`. *)

external backward_display_line :
  t -> Text_buffer_and__text_iter_and__text_mark.Text_iter.t -> bool
  = "ml_gtk_text_view_backward_display_line"
(** Moves the given @iter backward by one display (wrapped) line.

A display line is different from a paragraph. Paragraphs are
separated by newlines or other paragraph separator characters.
Display lines are created by line-wrapping a paragraph. If
wrapping is turned off, display lines and paragraphs will be the
same. Display lines are divided differently for each view, since
they depend on the view’s width; paragraphs are the same in all
views, since they depend on the contents of the `GtkTextBuffer`. *)

external add_overlay :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int ->
  int ->
  unit = "ml_gtk_text_view_add_overlay"
(** Adds @child at a fixed coordinate in the `GtkTextView`'s text window.

The @xpos and @ypos must be in buffer coordinates (see
[method@Gtk.TextView.get_iter_location] to convert to
buffer coordinates).

@child will scroll with the text view.

If instead you want a widget that will not move with the
`GtkTextView` contents see `GtkOverlay`. *)

external add_child_at_anchor :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Text_child_anchor.t ->
  unit = "ml_gtk_text_view_add_child_at_anchor"
(** Adds a child widget in the text buffer, at the given @anchor. *)

(* Properties *)

external get_im_module : t -> string = "ml_gtk_text_view_get_im_module"
(** Get property: im-module *)

external set_im_module : t -> string -> unit = "ml_gtk_text_view_set_im_module"
(** Set property: im-module *)

val on_backspace :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_copy_clipboard :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_cut_clipboard :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_delete_from_cursor :
  ?after:bool ->
  t ->
  callback:(type_:Gtk_enums.deletetype -> count:int -> unit) ->
  Gobject.Signal.handler_id

val on_insert_at_cursor :
  ?after:bool ->
  t ->
  callback:(string:string -> unit) ->
  Gobject.Signal.handler_id

val on_insert_emoji :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_move_cursor :
  ?after:bool ->
  t ->
  callback:
    (step:Gtk_enums.movementstep -> count:int -> extend_selection:bool -> unit) ->
  Gobject.Signal.handler_id

val on_move_viewport :
  ?after:bool ->
  t ->
  callback:(step:Gtk_enums.scrollstep -> count:int -> unit) ->
  Gobject.Signal.handler_id

val on_paste_clipboard :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_preedit_changed :
  ?after:bool ->
  t ->
  callback:(preedit:string -> unit) ->
  Gobject.Signal.handler_id

val on_select_all :
  ?after:bool ->
  t ->
  callback:(select:bool -> unit) ->
  Gobject.Signal.handler_id

val on_set_anchor :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_toggle_cursor_visible :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_toggle_overwrite :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
