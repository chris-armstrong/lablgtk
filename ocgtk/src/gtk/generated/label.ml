(* GENERATED CODE - DO NOT EDIT *)
(* Label: Label *)

type t = [ `label | `widget | `initially_unowned | `object_ ] Gobject.obj

external new_ : string option -> t = "ml_gtk_label_new"
(** Create a new Label *)

external new_with_mnemonic : string option -> t
  = "ml_gtk_label_new_with_mnemonic"
(** Create a new Label *)

(* Methods *)

external set_yalign : t -> float -> unit = "ml_gtk_label_set_yalign"
(** Sets the `yalign` of the label.

    See the [property@Gtk.Label:yalign] property. *)

external set_xalign : t -> float -> unit = "ml_gtk_label_set_xalign"
(** Sets the `xalign` of the label.

    See the [property@Gtk.Label:xalign] property. *)

external set_wrap_mode : t -> Ocgtk_pango.Pango.wrapmode -> unit
  = "ml_gtk_label_set_wrap_mode"
(** Controls how line wrapping is done.

    This only affects the label if line wrapping is on. (See
    [method@Gtk.Label.set_wrap])

    The default is [enum@Pango.WrapMode.word], which means wrap on word
    boundaries.

    For sizing behavior, also consider the
    [property@Gtk.Label:natural-wrap-mode] property. *)

external set_wrap : t -> bool -> unit = "ml_gtk_label_set_wrap"
(** Toggles line wrapping within the label.

    True makes it break lines if text exceeds the widget’s size. false lets the
    text get cut off by the edge of the widget if it exceeds the widget size.

    Note that setting line wrapping to true does not make the label wrap at its
    parent widget’s width, because GTK widgets conceptually can’t make their
    requisition depend on the parent widget’s size. For a label that wraps at a
    specific position, set the label’s width using
    [method@Gtk.Widget.set_size_request]. *)

external set_width_chars : t -> int -> unit = "ml_gtk_label_set_width_chars"
(** Sets the desired width in characters of the label. *)

external set_use_underline : t -> bool -> unit
  = "ml_gtk_label_set_use_underline"
(** Sets whether underlines in the text indicate mnemonics. *)

external set_use_markup : t -> bool -> unit = "ml_gtk_label_set_use_markup"
(** Sets whether the text of the label contains markup.

    See [method@Gtk.Label.set_markup]. *)

external set_text_with_mnemonic : t -> string -> unit
  = "ml_gtk_label_set_text_with_mnemonic"
(** Sets the text for the label, with mnemonics.

If characters in @str are preceded by an underscore, they are underlined
indicating that they represent a keyboard accelerator called a mnemonic.
The mnemonic key can be used to activate another widget, chosen
automatically, or explicitly using [method@Gtk.Label.set_mnemonic_widget]. *)

external set_text : t -> string -> unit = "ml_gtk_label_set_text"
(** Sets the text for the label.

    It overwrites any text that was there before and clears any previously set
    mnemonic accelerators, and sets the [property@Gtk.Label:use-underline] and
    [property@Gtk.Label:use-markup] properties to false.

    Also see [method@Gtk.Label.set_markup]. *)

external set_tabs : t -> Ocgtk_pango.Pango.Wrappers.Tab_array.t option -> unit
  = "ml_gtk_label_set_tabs"
(** Sets tab stops for the label. *)

external set_single_line_mode : t -> bool -> unit
  = "ml_gtk_label_set_single_line_mode"
(** Sets whether the label is in single line mode. *)

external set_selectable : t -> bool -> unit = "ml_gtk_label_set_selectable"
(** Makes text in the label selectable.

    Selectable labels allow the user to select text from the label, for
    copy-and-paste. *)

external set_natural_wrap_mode : t -> Gtk_enums.naturalwrapmode -> unit
  = "ml_gtk_label_set_natural_wrap_mode"
(** Selects the line wrapping for the natural size request.

    This only affects the natural size requested, for the actual wrapping used,
    see the [property@Gtk.Label:wrap-mode] property. *)

external set_mnemonic_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_label_set_mnemonic_widget"
(** Associate the label with its mnemonic target.

    If the label has been set so that it has a mnemonic key (using i.e.
    [method@Gtk.Label.set_markup_with_mnemonic],
    [method@Gtk.Label.set_text_with_mnemonic],
    [ctor@Gtk.Label.new_with_mnemonic] or the [property@Gtk.Label:use_underline]
    property) the label can be associated with a widget that is the target of
    the mnemonic. When the label is inside a widget (like a [class@Gtk.Button]
    or a [class@Gtk.Notebook] tab) it is automatically associated with the
    correct widget, but sometimes (i.e. when the target is a [class@Gtk.Entry]
    next to the label) you need to set it explicitly using this function.

    The target widget will be accelerated by emitting the
    [signal@Gtk.Widget::mnemonic-activate] signal on it. The default handler for
    this signal will activate the widget if there are no mnemonic collisions and
    toggle focus between the colliding widgets otherwise. *)

external set_max_width_chars : t -> int -> unit
  = "ml_gtk_label_set_max_width_chars"
(** Sets the maximum width of the label in characters. *)

external set_markup_with_mnemonic : t -> string -> unit
  = "ml_gtk_label_set_markup_with_mnemonic"
(** Sets the labels text, attributes and mnemonic from markup.

Parses @str which is marked up with Pango markup (see [func@Pango.parse_markup]),
setting the label’s text and attribute list based on the parse results.
If characters in @str are preceded by an underscore, they are underlined
indicating that they represent a keyboard accelerator called a mnemonic.

The mnemonic key can be used to activate another widget, chosen
automatically, or explicitly using [method@Gtk.Label.set_mnemonic_widget]. *)

external set_markup : t -> string -> unit = "ml_gtk_label_set_markup"
(** Sets the labels text and attributes from markup.

The string must be marked up with Pango markup
(see [func@Pango.parse_markup]).

If @str is external data, you may need to escape it
with [func@GLib.markup_escape_text] or [func@GLib.markup_printf_escaped]:

```c
GtkWidget *self = gtk_label_new (NULL);
const char *str = "...";
const char *format = "<span style=\"italic\">\%s</span>";
char *markup;

markup = g_markup_printf_escaped (format, str);
gtk_label_set_markup (GTK_LABEL (self), markup);
g_free (markup);
```

This function sets the [property@Gtk.Label:use-markup] property
to true.

Also see [method@Gtk.Label.set_text]. *)

external set_lines : t -> int -> unit = "ml_gtk_label_set_lines"
(** Sets the number of lines to which an ellipsized, wrapping label should be
    limited.

    This has no effect if the label is not wrapping or ellipsized. Set this to
    -1 if you don’t want to limit the number of lines. *)

external set_label : t -> string -> unit = "ml_gtk_label_set_label"
(** Sets the text of the label.

    The label is interpreted as including embedded underlines and/or Pango
    markup depending on the values of the [property@Gtk.Label:use-underline] and
    [property@Gtk.Label:use-markup] properties. *)

external set_justify : t -> Gtk_enums.justification -> unit
  = "ml_gtk_label_set_justify"
(** Sets the alignment of lines in the label relative to each other.

    This function has no effect on labels containing only a single line.

    [enum@Gtk.Justification.left] is the default value when the widget is first
    created with [ctor@Gtk.Label.new].

    If you instead want to set the alignment of the label as a whole, use
    [method@Gtk.Widget.set_halign] instead. *)

external set_extra_menu :
  t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option -> unit
  = "ml_gtk_label_set_extra_menu"
(** Sets a menu model to add to the context menu of the label. *)

external set_ellipsize : t -> Ocgtk_pango.Pango.ellipsizemode -> unit
  = "ml_gtk_label_set_ellipsize"
(** Sets the mode used to ellipsize the text.

    The text will be ellipsized if there is not enough space to render the
    entire string. *)

external set_attributes :
  t -> Ocgtk_pango.Pango.Wrappers.Attr_list.t option -> unit
  = "ml_gtk_label_set_attributes"
(** Apply attributes to the label text.

    The attributes set with this function will be applied and merged with any
    other attributes previously effected by way of the
    [property@Gtk.Label:use-underline] or [property@Gtk.Label:use-markup]
    properties

    While it is not recommended to mix markup strings with manually set
    attributes, if you must; know that the attributes will be applied to the
    label after the markup string is parsed. *)

external select_region : t -> int -> int -> unit = "ml_gtk_label_select_region"
(** Selects a range of characters in the label, if the label is selectable.

See [method@Gtk.Label.set_selectable]. If the label is not selectable,
this function has no effect. If @start_offset or
@end_offset are -1, then the end of the label will be substituted. *)

external get_yalign : t -> float = "ml_gtk_label_get_yalign"
(** Gets the `yalign` of the label.

    See the [property@Gtk.Label:yalign] property. *)

external get_xalign : t -> float = "ml_gtk_label_get_xalign"
(** Gets the `xalign` of the label.

    See the [property@Gtk.Label:xalign] property. *)

external get_wrap_mode : t -> Ocgtk_pango.Pango.wrapmode
  = "ml_gtk_label_get_wrap_mode"
(** Returns line wrap mode used by the label.

    See [method@Gtk.Label.set_wrap_mode]. *)

external get_wrap : t -> bool = "ml_gtk_label_get_wrap"
(** Returns whether lines in the label are automatically wrapped.

    See [method@Gtk.Label.set_wrap]. *)

external get_width_chars : t -> int = "ml_gtk_label_get_width_chars"
(** Retrieves the desired width of the label in characters.

    See [method@Gtk.Label.set_width_chars]. *)

external get_use_underline : t -> bool = "ml_gtk_label_get_use_underline"
(** Returns whether underlines in the label indicate mnemonics.

    See [method@Gtk.Label.set_use_underline]. *)

external get_use_markup : t -> bool = "ml_gtk_label_get_use_markup"
(** Returns whether the label’s text is interpreted as Pango markup.

    See [method@Gtk.Label.set_use_markup]. *)

external get_text : t -> string = "ml_gtk_label_get_text"
(** Gets the text of the label.

    The returned text is as it appears on screen. This does not include any
    embedded underlines indicating mnemonics or Pango markup. (See
    [method@Gtk.Label.get_label]) *)

external get_tabs : t -> Ocgtk_pango.Pango.Wrappers.Tab_array.t option
  = "ml_gtk_label_get_tabs"
(** Gets the tab stops for the label.

    The returned array will be `NULL` if “standard” (8-space) tabs are used. *)

external get_single_line_mode : t -> bool = "ml_gtk_label_get_single_line_mode"
(** Returns whether the label is in single line mode. *)

external get_selection_bounds : t -> bool * int * int
  = "ml_gtk_label_get_selection_bounds"
(** Gets the selected range of characters in the label.

The returned @start and @end positions are in characters. *)

external get_selectable : t -> bool = "ml_gtk_label_get_selectable"
(** Returns whether the label is selectable. *)

external get_natural_wrap_mode : t -> Gtk_enums.naturalwrapmode
  = "ml_gtk_label_get_natural_wrap_mode"
(** Returns natural line wrap mode used by the label.

    See [method@Gtk.Label.set_natural_wrap_mode]. *)

external get_mnemonic_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_label_get_mnemonic_widget"
(** Retrieves the mnemonic target of this label.

    See [method@Gtk.Label.set_mnemonic_widget]. *)

external get_mnemonic_keyval : t -> int = "ml_gtk_label_get_mnemonic_keyval"
(** Return the mnemonic accelerator.

    If the label has been set so that it has a mnemonic key this function
    returns the keyval used for the mnemonic accelerator. If there is no
    mnemonic set up it returns `GDK_KEY_VoidSymbol`. *)

external get_max_width_chars : t -> int = "ml_gtk_label_get_max_width_chars"
(** Retrieves the maximum width of the label in characters.

    See [method@Gtk.Label.set_width_chars]. *)

external get_lines : t -> int = "ml_gtk_label_get_lines"
(** Gets the number of lines to which an ellipsized, wrapping label should be
    limited.

    See [method@Gtk.Label.set_lines]. *)

external get_layout_offsets : t -> int * int = "ml_gtk_label_get_layout_offsets"
(** Obtains the coordinates where the label will draw its Pango layout.

    The coordinates are useful to convert mouse events into coordinates inside
    the [class@Pango.Layout], e.g. to take some action if some part of the label
    is clicked. Remember when using the [class@Pango.Layout] functions you need
    to convert to and from pixels using `PANGO_PIXELS()` or [const@Pango.SCALE].
*)

external get_layout : t -> Ocgtk_pango.Pango.Wrappers.Layout.t
  = "ml_gtk_label_get_layout"
(** Gets the Pango layout used to display the label.

The layout is useful to e.g. convert text positions to pixel
positions, in combination with [method@Gtk.Label.get_layout_offsets].
The returned layout is owned by the @label so need not be
freed by the caller. The @label is free to recreate its layout
at any time, so it should be considered read-only. *)

external get_label : t -> string = "ml_gtk_label_get_label"
(** Fetches the text from a label.

    The returned text includes any embedded underlines indicating mnemonics and
    Pango markup. (See [method@Gtk.Label.get_text]). *)

external get_justify : t -> Gtk_enums.justification = "ml_gtk_label_get_justify"
(** Returns the justification of the label.

    See [method@Gtk.Label.set_justify]. *)

external get_extra_menu : t -> Ocgtk_gio.Gio.Wrappers.Menu_model.t option
  = "ml_gtk_label_get_extra_menu"
(** Gets the extra menu model of the label.

    See [method@Gtk.Label.set_extra_menu]. *)

external get_ellipsize : t -> Ocgtk_pango.Pango.ellipsizemode
  = "ml_gtk_label_get_ellipsize"
(** Returns the ellipsization mode of the label.

    See [method@Gtk.Label.set_ellipsize]. *)

external get_current_uri : t -> string option = "ml_gtk_label_get_current_uri"
(** Returns the URI for the active link in the label.

    The active link is the one under the mouse pointer or, in a selectable
    label, the link in which the text cursor is currently positioned.

    This function is intended for use in a [signal@Gtk.Label::activate-link]
    handler or for use in a [signal@Gtk.Widget::query-tooltip] handler. *)

external get_attributes : t -> Ocgtk_pango.Pango.Wrappers.Attr_list.t option
  = "ml_gtk_label_get_attributes"
(** Gets the label's attribute list.

    This is the [struct@Pango.AttrList] that was set on the label using
    [method@Gtk.Label.set_attributes], if any. This function does not reflect
    attributes that come from the label's markup (see
    [method@Gtk.Label.set_markup]). If you want to get the effective attributes
    for the label, use `pango_layout_get_attributes (gtk_label_get_layout
    (self))`. *)

(* Properties *)

let on_activate_current_link ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"activate-current-link" ~callback
    ~after:(Option.value after ~default:false)

let on_activate_link ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let uri =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_string_exn v
        in
        let result = callback ~uri in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"activate-link" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_copy_clipboard ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"copy-clipboard" ~callback
    ~after:(Option.value after ~default:false)

let on_move_cursor ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let step =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gtk_enums.movementstep_of_int (Gobject.Value.get_enum_int v)
        in
        let count =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_int v
        in
        let extend_selection =
          let v = Gobject.Closure.nth argv ~pos:3 in
          Gobject.Value.get_boolean v
        in
        callback ~step ~count ~extend_selection)
  in
  Gobject.Signal.connect obj ~name:"move-cursor" ~callback:closure
    ~after:(Option.value after ~default:false)
