(* GENERATED CODE - DO NOT EDIT *)
(* Combined modules for cyclic dependencies *)

module rec Text_buffer : sig
  type t = [ `text_buffer | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_text_buffer_get_type"

  external new_ : Text_tag_table.t option -> t = "ml_gtk_text_buffer_new"
  (** Create a new TextBuffer *)

  (* Methods *)

  external undo : t -> unit = "ml_gtk_text_buffer_undo"
  (** Undoes the last undoable action on the buffer, if there is one. *)

  external set_text : t -> string -> int -> unit = "ml_gtk_text_buffer_set_text"
  (** Deletes current contents of @buffer, and inserts @text instead. This is
  automatically marked as an irreversible action in the undo stack. If you
  wish to mark this action as part of a larger undo operation, call
  [method@TextBuffer.delete] and [method@TextBuffer.insert] directly instead.

  If @len is -1, @text must be nul-terminated.
  @text must be valid UTF-8. *)

  external set_modified : t -> bool -> unit = "ml_gtk_text_buffer_set_modified"
  (** Used to keep track of whether the buffer has been modified since the last
      time it was saved.

      Whenever the buffer is saved to disk, call `gtk_text_buffer_set_modified
      (@buffer, FALSE)`. When the buffer is modified, it will automatically
      toggle on the modified bit again. When the modified bit flips, the buffer
      emits the [signal@Gtk.TextBuffer::modified-changed] signal. *)

  external set_max_undo_levels : t -> int -> unit
    = "ml_gtk_text_buffer_set_max_undo_levels"
  (** Sets the maximum number of undo levels to perform.

      If 0, unlimited undo actions may be performed. Note that this may have a
      memory usage impact as it requires storing an additional copy of the
      inserted or removed text within the text buffer. *)

  external set_enable_undo : t -> bool -> unit
    = "ml_gtk_text_buffer_set_enable_undo"
  (** Sets whether or not to enable undoable actions in the text buffer.

      Undoable actions in this context are changes to the text content of the
      buffer. Changes to tags and marks are not tracked.

      If enabled, the user will be able to undo the last number of actions up to
      [method@Gtk.TextBuffer.get_max_undo_levels].

      See [method@Gtk.TextBuffer.begin_irreversible_action] and
      [method@Gtk.TextBuffer.end_irreversible_action] to create changes to the
      buffer that cannot be undone. *)

  external select_range : t -> Text_iter.t -> Text_iter.t -> unit
    = "ml_gtk_text_buffer_select_range"
  (** This function moves the “insert” and “selection_bound” marks
      simultaneously.

      If you move them in two steps with [method@Gtk.TextBuffer.move_mark], you
      will temporarily select a region in between their old and new locations,
      which can be pretty inefficient since the temporarily-selected region will
      force stuff to be recalculated. This function moves them as a unit, which
      can be optimized. *)

  external remove_tag_by_name :
    t -> string -> Text_iter.t -> Text_iter.t -> unit
    = "ml_gtk_text_buffer_remove_tag_by_name"
  (** Emits the “remove-tag” signal.

      Calls [method@Gtk.TextTagTable.lookup] on the buffer’s tag table to get a
      `GtkTextTag`, then calls [method@Gtk.TextBuffer.remove_tag]. *)

  external remove_tag : t -> Text_tag.t -> Text_iter.t -> Text_iter.t -> unit
    = "ml_gtk_text_buffer_remove_tag"
  (** Emits the “remove-tag” signal.

  The default handler for the signal removes all occurrences
  of @tag from the given range. @start and @end don’t have
  to be in order. *)

  external remove_selection_clipboard :
    t -> Ocgtk_gdk.Gdk.Wrappers.Clipboard.t -> unit
    = "ml_gtk_text_buffer_remove_selection_clipboard"
  (** Removes a `GdkClipboard` added with
      [method@Gtk.TextBuffer.add_selection_clipboard] *)

  external remove_commit_notify : t -> int -> unit
    = "ml_gtk_text_buffer_remove_commit_notify"
  (** Removes the `GtkTextBufferCommitNotify` handler previously registered with
      [method@Gtk.TextBuffer.add_commit_notify].

      This may result in the `user_data_destroy` being called that was passed
      when registering the commit notify functions. *)

  external remove_all_tags : t -> Text_iter.t -> Text_iter.t -> unit
    = "ml_gtk_text_buffer_remove_all_tags"
  (** Removes all tags in the range between @start and @end.

  Be careful with this function; it could remove tags added in code
  unrelated to the code you’re currently writing. That is, using this
  function is probably a bad idea if you have two or more unrelated
  code sections that add tags. *)

  external redo : t -> unit = "ml_gtk_text_buffer_redo"
  (** Redoes the next redoable action on the buffer, if there is one. *)

  external place_cursor : t -> Text_iter.t -> unit
    = "ml_gtk_text_buffer_place_cursor"
  (** This function moves the “insert” and “selection_bound” marks
      simultaneously.

      If you move them to the same place in two steps with
      [method@Gtk.TextBuffer.move_mark], you will temporarily select a region in
      between their old and new locations, which can be pretty inefficient since
      the temporarily-selected region will force stuff to be recalculated. This
      function moves them as a unit, which can be optimized. *)

  external paste_clipboard :
    t ->
    Ocgtk_gdk.Gdk.Wrappers.Clipboard.t ->
    Text_iter.t option ->
    bool ->
    unit = "ml_gtk_text_buffer_paste_clipboard"
  (** Pastes the contents of a clipboard.

  If @override_location is %NULL, the pasted text will be inserted
  at the cursor position, or the buffer selection will be replaced
  if the selection is non-empty.

  Note: pasting is asynchronous, that is, we’ll ask for the paste data
  and return, and at some point later after the main loop runs, the paste
  data will be inserted. *)

  external move_mark_by_name : t -> string -> Text_iter.t -> unit
    = "ml_gtk_text_buffer_move_mark_by_name"
  (** Moves the mark named @name (which must exist) to location @where.

  See [method@Gtk.TextBuffer.move_mark] for details. *)

  external move_mark : t -> Text_mark.t -> Text_iter.t -> unit
    = "ml_gtk_text_buffer_move_mark"
  (** Moves @mark to the new location @where.

  Emits the [signal@Gtk.TextBuffer::mark-set] signal
  as notification of the move. *)

  external insert_range_interactive :
    t -> Text_iter.t -> Text_iter.t -> Text_iter.t -> bool -> bool
    = "ml_gtk_text_buffer_insert_range_interactive"
  (** Copies text, tags, and paintables between @start and @end
  and inserts the copy at @iter.

  Same as [method@Gtk.TextBuffer.insert_range], but does nothing
  if the insertion point isn’t editable. The @default_editable
  parameter indicates whether the text is editable at @iter if
  no tags enclosing @iter affect editability. Typically the result
  of [method@Gtk.TextView.get_editable] is appropriate here. *)

  external insert_range : t -> Text_iter.t -> Text_iter.t -> Text_iter.t -> unit
    = "ml_gtk_text_buffer_insert_range"
  (** Copies text, tags, and paintables between @start and @end
  and inserts the copy at @iter.

  The order of @start and @end doesn’t matter.

  Used instead of simply getting/inserting text because it preserves
  images and tags. If @start and @end are in a different buffer from
  @buffer, the two buffers must share the same tag table.

  Implemented via emissions of the ::insert-text and ::apply-tag signals,
  so expect those. *)

  external insert_paintable :
    t -> Text_iter.t -> Ocgtk_gdk.Gdk.Wrappers.Paintable.t -> unit
    = "ml_gtk_text_buffer_insert_paintable"
  (** Inserts an image into the text buffer at @iter.

  The image will be counted as one character in character counts,
  and when obtaining the buffer contents as a string, will be
  represented by the Unicode “object replacement character” 0xFFFC.
  Note that the “slice” variants for obtaining portions of the buffer
  as a string include this character for paintable, but the “text”
  variants do not. e.g. see [method@Gtk.TextBuffer.get_slice] and
  [method@Gtk.TextBuffer.get_text]. *)

  external insert_markup : t -> Text_iter.t -> string -> int -> unit
    = "ml_gtk_text_buffer_insert_markup"
  (** Inserts the text in @markup at position @iter.

  @markup will be inserted in its entirety and must be nul-terminated
  and valid UTF-8. Emits the [signal@Gtk.TextBuffer::insert-text] signal,
  possibly multiple times; insertion actually occurs in the default handler
  for the signal. @iter will point to the end of the inserted text on return. *)

  external insert_interactive_at_cursor : t -> string -> int -> bool -> bool
    = "ml_gtk_text_buffer_insert_interactive_at_cursor"
  (** Inserts @text in @buffer.

  Calls [method@Gtk.TextBuffer.insert_interactive]
  at the cursor position.

  @default_editable indicates the editability of text that doesn't
  have a tag affecting editability applied to it. Typically the
  result of [method@Gtk.TextView.get_editable] is appropriate here. *)

  external insert_interactive :
    t -> Text_iter.t -> string -> int -> bool -> bool
    = "ml_gtk_text_buffer_insert_interactive"
  (** Inserts @text in @buffer.

  Like [method@Gtk.TextBuffer.insert], but the insertion will not occur
  if @iter is at a non-editable location in the buffer. Usually you
  want to prevent insertions at ineditable locations if the insertion
  results from a user action (is interactive).

  @default_editable indicates the editability of text that doesn't
  have a tag affecting editability applied to it. Typically the
  result of [method@Gtk.TextView.get_editable] is appropriate here. *)

  external insert_child_anchor : t -> Text_iter.t -> Text_child_anchor.t -> unit
    = "ml_gtk_text_buffer_insert_child_anchor"
  (** Inserts a child widget anchor into the text buffer at @iter.

  The anchor will be counted as one character in character counts, and
  when obtaining the buffer contents as a string, will be represented
  by the Unicode “object replacement character” 0xFFFC. Note that the
  “slice” variants for obtaining portions of the buffer as a string
  include this character for child anchors, but the “text” variants do
  not. E.g. see [method@Gtk.TextBuffer.get_slice] and
  [method@Gtk.TextBuffer.get_text].

  Consider [method@Gtk.TextBuffer.create_child_anchor] as a more
  convenient alternative to this function. The buffer will add a
  reference to the anchor, so you can unref it after insertion. *)

  external insert_at_cursor : t -> string -> int -> unit
    = "ml_gtk_text_buffer_insert_at_cursor"
  (** Inserts @text in @buffer.

  Simply calls [method@Gtk.TextBuffer.insert],
  using the current cursor position as the insertion point. *)

  external insert : t -> Text_iter.t -> string -> int -> unit
    = "ml_gtk_text_buffer_insert"
  (** Inserts @len bytes of @text at position @iter.

  If @len is -1, @text must be nul-terminated and will be inserted in its
  entirety. Emits the “insert-text” signal; insertion actually occurs
  in the default handler for the signal. @iter is invalidated when
  insertion occurs (because the buffer contents change), but the
  default signal handler revalidates it to point to the end of the
  inserted text. *)

  external get_text : t -> Text_iter.t -> Text_iter.t -> bool -> string
    = "ml_gtk_text_buffer_get_text"
  (** Returns the text in the range [@start,@end).

  Excludes undisplayed text (text marked with tags that set the
  invisibility attribute) if @include_hidden_chars is %FALSE.
  Does not include characters representing embedded images, so
  byte and character indexes into the returned string do not
  correspond to byte and character indexes into the buffer.
  Contrast with [method@Gtk.TextBuffer.get_slice]. *)

  external get_tag_table : t -> Text_tag_table.t
    = "ml_gtk_text_buffer_get_tag_table"
  (** Get the `GtkTextTagTable` associated with this buffer. *)

  external get_start_iter : t -> Text_iter.t
    = "ml_gtk_text_buffer_get_start_iter"
  (** Initialized @iter with the first position in the text buffer.

  This is the same as using [method@Gtk.TextBuffer.get_iter_at_offset]
  to get the iter at character offset 0. *)

  external get_slice : t -> Text_iter.t -> Text_iter.t -> bool -> string
    = "ml_gtk_text_buffer_get_slice"
  (** Returns the text in the range [@start,@end).

  Excludes undisplayed text (text marked with tags that set the
  invisibility attribute) if @include_hidden_chars is %FALSE.
  The returned string includes a 0xFFFC character whenever the
  buffer contains embedded images, so byte and character indexes
  into the returned string do correspond to byte and character
  indexes into the buffer. Contrast with [method@Gtk.TextBuffer.get_text].
  Note that 0xFFFC can occur in normal text as well, so it is not a
  reliable indicator that a paintable or widget is in the buffer. *)

  external get_selection_content :
    t -> Ocgtk_gdk.Gdk.Wrappers.Content_provider.t
    = "ml_gtk_text_buffer_get_selection_content"
  (** Get a content provider for this buffer.

  It can be used to make the content of @buffer available
  in a `GdkClipboard`, see [method@Gdk.Clipboard.set_content]. *)

  external get_selection_bounds : t -> bool * Text_iter.t * Text_iter.t
    = "ml_gtk_text_buffer_get_selection_bounds"
  (** Returns %TRUE if some text is selected; places the bounds
  of the selection in @start and @end.

  If the selection has length 0, then @start and @end are filled
  in with the same value. @start and @end will be in ascending order.
  If @start and @end are %NULL, then they are not filled in, but the
  return value still indicates whether text is selected. *)

  external get_selection_bound : t -> Text_mark.t
    = "ml_gtk_text_buffer_get_selection_bound"
  (** Returns the mark that represents the selection bound.

  Equivalent to calling [method@Gtk.TextBuffer.get_mark]
  to get the mark named “selection_bound”, but very slightly
  more efficient, and involves less typing.

  The currently-selected text in @buffer is the region between the
  “selection_bound” and “insert” marks. If “selection_bound” and
  “insert” are in the same place, then there is no current selection.
  [method@Gtk.TextBuffer.get_selection_bounds] is another convenient
  function for handling the selection, if you just want to know whether
  there’s a selection and what its bounds are. *)

  external get_modified : t -> bool = "ml_gtk_text_buffer_get_modified"
  (** Indicates whether the buffer has been modified since the last call to
      [method@Gtk.TextBuffer.set_modified] set the modification flag to %FALSE.

      Used for example to enable a “save” function in a text editor. *)

  external get_max_undo_levels : t -> int
    = "ml_gtk_text_buffer_get_max_undo_levels"
  (** Gets the maximum number of undo levels to perform.

      If 0, unlimited undo actions may be performed. Note that this may have a
      memory usage impact as it requires storing an additional copy of the
      inserted or removed text within the text buffer. *)

  external get_mark : t -> string -> Text_mark.t option
    = "ml_gtk_text_buffer_get_mark"
  (** Returns the mark named @name in buffer @buffer, or %NULL if no such
  mark exists in the buffer. *)

  external get_line_count : t -> int = "ml_gtk_text_buffer_get_line_count"
  (** Obtains the number of lines in the buffer.

      This value is cached, so the function is very fast. *)

  external get_iter_at_offset : t -> int -> Text_iter.t
    = "ml_gtk_text_buffer_get_iter_at_offset"
  (** Initializes @iter to a position @char_offset chars from the start
  of the entire buffer.

  If @char_offset is -1 or greater than the number
  of characters in the buffer, @iter is initialized to the end iterator,
  the iterator one past the last valid character in the buffer. *)

  external get_iter_at_mark : t -> Text_mark.t -> Text_iter.t
    = "ml_gtk_text_buffer_get_iter_at_mark"
  (** Initializes @iter with the current position of @mark. *)

  external get_iter_at_line_offset : t -> int -> int -> bool * Text_iter.t
    = "ml_gtk_text_buffer_get_iter_at_line_offset"
  (** Obtains an iterator pointing to @char_offset within the given line.

  Note characters, not bytes; UTF-8 may encode one character as multiple
  bytes.

  If @line_number is greater than or equal to the number of lines in the @buffer,
  the end iterator is returned. And if @char_offset is off the
  end of the line, the iterator at the end of the line is returned. *)

  external get_iter_at_line_index : t -> int -> int -> bool * Text_iter.t
    = "ml_gtk_text_buffer_get_iter_at_line_index"
  (** Obtains an iterator pointing to @byte_index within the given line.

  @byte_index must be the start of a UTF-8 character. Note bytes, not
  characters; UTF-8 may encode one character as multiple bytes.

  If @line_number is greater than or equal to the number of lines in the @buffer,
  the end iterator is returned. And if @byte_index is off the
  end of the line, the iterator at the end of the line is returned. *)

  external get_iter_at_line : t -> int -> bool * Text_iter.t
    = "ml_gtk_text_buffer_get_iter_at_line"
  (** Initializes @iter to the start of the given line.

  If @line_number is greater than or equal to the number of lines
  in the @buffer, the end iterator is returned. *)

  external get_iter_at_child_anchor : t -> Text_child_anchor.t -> Text_iter.t
    = "ml_gtk_text_buffer_get_iter_at_child_anchor"
  (** Obtains the location of @anchor within @buffer. *)

  external get_insert : t -> Text_mark.t = "ml_gtk_text_buffer_get_insert"
  (** Returns the mark that represents the cursor (insertion point).

      Equivalent to calling [method@Gtk.TextBuffer.get_mark] to get the mark
      named “insert”, but very slightly more efficient, and involves less
      typing. *)

  external get_has_selection : t -> bool
    = "ml_gtk_text_buffer_get_has_selection"
  (** Indicates whether the buffer has some text currently selected. *)

  external get_end_iter : t -> Text_iter.t = "ml_gtk_text_buffer_get_end_iter"
  (** Initializes @iter with the “end iterator,” one past the last valid
  character in the text buffer.

  If dereferenced with [method@Gtk.TextIter.get_char], the end
  iterator has a character value of 0.
  The entire buffer lies in the range from the first position in
  the buffer (call [method@Gtk.TextBuffer.get_start_iter] to get
  character position 0) to the end iterator. *)

  external get_enable_undo : t -> bool = "ml_gtk_text_buffer_get_enable_undo"
  (** Gets whether the buffer is saving modifications to the buffer to allow for
      undo and redo actions.

      See [method@Gtk.TextBuffer.begin_irreversible_action] and
      [method@Gtk.TextBuffer.end_irreversible_action] to create changes to the
      buffer that cannot be undone. *)

  external get_char_count : t -> int = "ml_gtk_text_buffer_get_char_count"
  (** Gets the number of characters in the buffer.

      Note that characters and bytes are not the same, you can’t e.g. expect the
      contents of the buffer in string form to be this many bytes long.

      The character count is cached, so this function is very fast. *)

  external get_can_undo : t -> bool = "ml_gtk_text_buffer_get_can_undo"
  (** Gets whether there is an undoable action in the history. *)

  external get_can_redo : t -> bool = "ml_gtk_text_buffer_get_can_redo"
  (** Gets whether there is a redoable action in the history. *)

  external get_bounds : t -> Text_iter.t * Text_iter.t
    = "ml_gtk_text_buffer_get_bounds"
  (** Retrieves the first and last iterators in the buffer, i.e. the
  entire buffer lies within the range [@start,@end). *)

  external end_user_action : t -> unit = "ml_gtk_text_buffer_end_user_action"
  (** Ends a user-visible operation.

      Should be paired with a call to [method@Gtk.TextBuffer.begin_user_action].
      See that function for a full explanation. *)

  external end_irreversible_action : t -> unit
    = "ml_gtk_text_buffer_end_irreversible_action"
  (** Denotes the end of an action that may not be undone.

      This will cause any previous operations in the undo/redo queue to be
      cleared.

      This should be called after completing modifications to the text buffer
      after [method@Gtk.TextBuffer.begin_irreversible_action] was called.

      You may nest calls to gtk_text_buffer_begin_irreversible_action() and
      gtk_text_buffer_end_irreversible_action() pairs. *)

  external delete_selection : t -> bool -> bool -> bool
    = "ml_gtk_text_buffer_delete_selection"
  (** Deletes the range between the “insert” and “selection_bound” marks,
  that is, the currently-selected text.

  If @interactive is %TRUE, the editability of the selection will be
  considered (users can’t delete uneditable text). *)

  external delete_mark_by_name : t -> string -> unit
    = "ml_gtk_text_buffer_delete_mark_by_name"
  (** Deletes the mark named @name; the mark must exist.

  See [method@Gtk.TextBuffer.delete_mark] for details. *)

  external delete_mark : t -> Text_mark.t -> unit
    = "ml_gtk_text_buffer_delete_mark"
  (** Deletes @mark, so that it’s no longer located anywhere in the
  buffer.

  Removes the reference the buffer holds to the mark, so if
  you haven’t called g_object_ref() on the mark, it will be freed.
  Even if the mark isn’t freed, most operations on @mark become
  invalid, until it gets added to a buffer again with
  [method@Gtk.TextBuffer.add_mark]. Use [method@Gtk.TextMark.get_deleted]
  to find out if a mark has been removed from its buffer.

  The [signal@Gtk.TextBuffer::mark-deleted] signal will be emitted as
  notification after the mark is deleted. *)

  external delete_interactive : t -> Text_iter.t -> Text_iter.t -> bool -> bool
    = "ml_gtk_text_buffer_delete_interactive"
  (** Deletes all editable text in the given range.

  Calls [method@Gtk.TextBuffer.delete] for each editable
  sub-range of [@start,@end). @start and @end are revalidated
  to point to the location of the last deleted range, or left
  untouched if no text was deleted. *)

  external delete : t -> Text_iter.t -> Text_iter.t -> unit
    = "ml_gtk_text_buffer_delete"
  (** Deletes text between @start and @end.

  The order of @start and @end is not actually relevant;
  gtk_text_buffer_delete() will reorder them.

  This function actually emits the “delete-range” signal, and
  the default handler of that signal deletes the text. Because the
  buffer is modified, all outstanding iterators become invalid after
  calling this function; however, the @start and @end will be
  re-initialized to point to the location where text was deleted. *)

  external cut_clipboard :
    t -> Ocgtk_gdk.Gdk.Wrappers.Clipboard.t -> bool -> unit
    = "ml_gtk_text_buffer_cut_clipboard"
  (** Copies the currently-selected text to a clipboard, then deletes said text
      if it’s editable. *)

  external create_mark :
    t -> string option -> Text_iter.t -> bool -> Text_mark.t
    = "ml_gtk_text_buffer_create_mark"
  (** Creates a mark at position @where.

  If @mark_name is %NULL, the mark is anonymous; otherwise, the mark
  can be retrieved by name using [method@Gtk.TextBuffer.get_mark].
  If a mark has left gravity, and text is inserted at the mark’s
  current location, the mark will be moved to the left of the
  newly-inserted text. If the mark has right gravity
  (@left_gravity = %FALSE), the mark will end up on the right of
  newly-inserted text. The standard left-to-right cursor is a mark
  with right gravity (when you type, the cursor stays on the right
  side of the text you’re typing).

  The caller of this function does not own a
  reference to the returned `GtkTextMark`, so you can ignore the
  return value if you like. Marks are owned by the buffer and go
  away when the buffer does.

  Emits the [signal@Gtk.TextBuffer::mark-set] signal as notification
  of the mark's initial placement. *)

  external create_child_anchor : t -> Text_iter.t -> Text_child_anchor.t
    = "ml_gtk_text_buffer_create_child_anchor"
  (** Creates and inserts a child anchor.

      This is a convenience function which simply creates a child anchor with
      [ctor@Gtk.TextChildAnchor.new] and inserts it into the buffer with
      [method@Gtk.TextBuffer.insert_child_anchor].

      The new anchor is owned by the buffer; no reference count is returned to
      the caller of this function. *)

  external copy_clipboard : t -> Ocgtk_gdk.Gdk.Wrappers.Clipboard.t -> unit
    = "ml_gtk_text_buffer_copy_clipboard"
  (** Copies the currently-selected text to a clipboard. *)

  external begin_user_action : t -> unit
    = "ml_gtk_text_buffer_begin_user_action"
  (** Called to indicate that the buffer operations between here and a call to
      gtk_text_buffer_end_user_action() are part of a single user-visible
      operation.

      The operations between gtk_text_buffer_begin_user_action() and
      gtk_text_buffer_end_user_action() can then be grouped when creating an
      undo stack. `GtkTextBuffer` maintains a count of calls to
      gtk_text_buffer_begin_user_action() that have not been closed with a call
      to gtk_text_buffer_end_user_action(), and emits the “begin-user-action”
      and “end-user-action” signals only for the outermost pair of calls. This
      allows you to build user actions from other user actions.

      The “interactive” buffer mutation functions, such as
      [method@Gtk.TextBuffer.insert_interactive], automatically call begin/end
      user action around the buffer operations they perform, so there's no need
      to add extra calls if you user action consists solely of a single call to
      one of those functions. *)

  external begin_irreversible_action : t -> unit
    = "ml_gtk_text_buffer_begin_irreversible_action"
  (** Denotes the beginning of an action that may not be undone.

      This will cause any previous operations in the undo/redo queue to be
      cleared.

      This should be paired with a call to
      [method@Gtk.TextBuffer.end_irreversible_action] after the irreversible
      action has completed.

      You may nest calls to gtk_text_buffer_begin_irreversible_action() and
      gtk_text_buffer_end_irreversible_action() pairs. *)

  external backspace : t -> Text_iter.t -> bool -> bool -> bool
    = "ml_gtk_text_buffer_backspace"
  (** Performs the appropriate action as if the user hit the delete
  key with the cursor at the position specified by @iter.

  In the normal case a single character will be deleted, but when
  combining accents are involved, more than one character can
  be deleted, and when precomposed character and accent combinations
  are involved, less than one character will be deleted.

  Because the buffer is modified, all outstanding iterators become
  invalid after calling this function; however, the @iter will be
  re-initialized to point to the location where text was deleted. *)

  external apply_tag_by_name : t -> string -> Text_iter.t -> Text_iter.t -> unit
    = "ml_gtk_text_buffer_apply_tag_by_name"
  (** Emits the “apply-tag” signal on @buffer.

  Calls [method@Gtk.TextTagTable.lookup] on the buffer’s
  tag table to get a `GtkTextTag`, then calls
  [method@Gtk.TextBuffer.apply_tag]. *)

  external apply_tag : t -> Text_tag.t -> Text_iter.t -> Text_iter.t -> unit
    = "ml_gtk_text_buffer_apply_tag"
  (** Emits the “apply-tag” signal on @buffer.

  The default handler for the signal applies
  @tag to the given range. @start and @end do
  not have to be in order. *)

  external add_selection_clipboard :
    t -> Ocgtk_gdk.Gdk.Wrappers.Clipboard.t -> unit
    = "ml_gtk_text_buffer_add_selection_clipboard"
  (** Adds @clipboard to the list of clipboards in which the selection
  contents of @buffer are available.

  In most cases, @clipboard will be the `GdkClipboard` returned by
  [method@Gtk.Widget.get_primary_clipboard] for a view of @buffer. *)

  external add_mark : t -> Text_mark.t -> Text_iter.t -> unit
    = "ml_gtk_text_buffer_add_mark"
  (** Adds the mark at position @where.

  The mark must not be added to another buffer, and if its name
  is not %NULL then there must not be another mark in the buffer
  with the same name.

  Emits the [signal@Gtk.TextBuffer::mark-set] signal as notification
  of the mark's initial placement. *)

  (* Properties *)

  external get_cursor_position : t -> int
    = "ml_gtk_text_buffer_get_cursor_position"
  (** Get property: cursor-position *)

  val on_begin_user_action :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_changed :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_end_user_action :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_mark_deleted :
    ?after:bool ->
    t ->
    callback:(mark:Text_mark.t -> unit) ->
    Gobject.Signal.handler_id

  val on_modified_changed :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_paste_done :
    ?after:bool ->
    t ->
    callback:(clipboard:Ocgtk_gdk.Gdk.Wrappers.Clipboard.t -> unit) ->
    Gobject.Signal.handler_id

  val on_redo :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

  val on_undo :
    ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
end

and Text_iter : sig
  type t = [ `text_iter ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_text_iter_get_type"

  (* Methods *)

  external toggles_tag : t -> Text_tag.t option -> bool
    = "ml_gtk_text_iter_toggles_tag"
  (** Gets whether a range with @tag applied to it begins
  or ends at @iter.

  This is equivalent to (gtk_text_iter_starts_tag() ||
  gtk_text_iter_ends_tag()) *)

  external starts_word : t -> bool = "ml_gtk_text_iter_starts_word"
  (** Determines whether @iter begins a natural-language word.

  Word breaks are determined by Pango and should be correct
  for nearly any language. *)

  external starts_tag : t -> Text_tag.t option -> bool
    = "ml_gtk_text_iter_starts_tag"
  (** Returns %TRUE if @tag is toggled on at exactly this point.

  If @tag is %NULL, returns %TRUE if any tag is toggled on at this point.

  Note that if this function returns %TRUE, it means that
  @iter is at the beginning of the tagged range, and that the
  character at @iter is inside the tagged range. In other
  words, unlike [method@Gtk.TextIter.ends_tag], if
  this function returns %TRUE, [method@Gtk.TextIter.has_tag]
  will also return %TRUE for the same parameters. *)

  external starts_sentence : t -> bool = "ml_gtk_text_iter_starts_sentence"
  (** Determines whether @iter begins a sentence.

  Sentence boundaries are determined by Pango and
  should be correct for nearly any language. *)

  external starts_line : t -> bool = "ml_gtk_text_iter_starts_line"
  (** Returns %TRUE if @iter begins a paragraph.

  This is the case if [method@Gtk.TextIter.get_line_offset]
  would return 0. However this function is potentially more
  efficient than [method@Gtk.TextIter.get_line_offset], because
  it doesn’t have to compute the offset, it just has to see
  whether it’s 0. *)

  external set_visible_line_offset : t -> int -> unit
    = "ml_gtk_text_iter_set_visible_line_offset"
  (** Like [method@Gtk.TextIter.set_line_offset], but the offset is in visible
      characters, i.e. text with a tag making it invisible is not counted in the
      offset. *)

  external set_visible_line_index : t -> int -> unit
    = "ml_gtk_text_iter_set_visible_line_index"
  (** Like [method@Gtk.TextIter.set_line_index], but the index is in visible
      bytes, i.e. text with a tag making it invisible is not counted in the
      index. *)

  external set_offset : t -> int -> unit = "ml_gtk_text_iter_set_offset"
  (** Sets @iter to point to @char_offset.

  @char_offset counts from the start
  of the entire text buffer, starting with 0. *)

  external set_line_offset : t -> int -> unit
    = "ml_gtk_text_iter_set_line_offset"
  (** Moves @iter within a line, to a new character (not byte) offset.

  The given character offset must be less than or equal to the number
  of characters in the line; if equal, @iter moves to the start of the
  next line. See [method@Gtk.TextIter.set_line_index] if you have a byte
  index rather than a character offset. *)

  external set_line_index : t -> int -> unit = "ml_gtk_text_iter_set_line_index"
  (** Same as [method@Gtk.TextIter.set_line_offset], but works with a byte
      index. The given byte index must be at the start of a character, it can’t
      be in the middle of a UTF-8 encoded character. *)

  external set_line : t -> int -> unit = "ml_gtk_text_iter_set_line"
  (** Moves iterator @iter to the start of the line @line_number.

  If @line_number is negative or larger than or equal to the number of lines
  in the buffer, moves @iter to the start of the last line in the buffer. *)

  external order : t -> t -> unit = "ml_gtk_text_iter_order"
  (** Swaps the value of @first and @second if @second comes before
  @first in the buffer.

  That is, ensures that @first and @second are in sequence.
  Most text buffer functions that take a range call this
  automatically on your behalf, so there’s no real reason to
  call it yourself in those cases. There are some exceptions,
  such as [method@Gtk.TextIter.in_range], that expect a
  pre-sorted range. *)

  external is_start : t -> bool = "ml_gtk_text_iter_is_start"
  (** Returns %TRUE if @iter is the first iterator in the buffer. *)

  external is_end : t -> bool = "ml_gtk_text_iter_is_end"
  (** Returns %TRUE if @iter is the end iterator.

  This means it is one past the last dereferenceable iterator
  in the buffer. [method@Gtk.TextIter.is_end] is the most efficient
  way to check whether an iterator is the end iterator. *)

  external is_cursor_position : t -> bool
    = "ml_gtk_text_iter_is_cursor_position"
  (** Determine if @iter is at a cursor position.

  See [method@Gtk.TextIter.forward_cursor_position] or
  [struct@Pango.LogAttr] or [func@Pango.break] for details
  on what a cursor position is. *)

  external inside_word : t -> bool = "ml_gtk_text_iter_inside_word"
  (** Determines whether the character pointed by @iter is part of a
  natural-language word (as opposed to say inside some whitespace).

  Word breaks are determined by Pango and should be correct
  for nearly any language.

  Note that if [method@Gtk.TextIter.starts_word] returns %TRUE,
  then this function returns %TRUE too, since @iter points to
  the first character of the word. *)

  external inside_sentence : t -> bool = "ml_gtk_text_iter_inside_sentence"
  (** Determines whether @iter is inside a sentence (as opposed to in
  between two sentences, e.g. after a period and before the first
  letter of the next sentence).

  Sentence boundaries are determined by Pango and should be correct
  for nearly any language. *)

  external in_range : t -> t -> t -> bool = "ml_gtk_text_iter_in_range"
  (** Checks whether @iter falls in the range [@start, @end).

  @start and @end must be in ascending order. *)

  external has_tag : t -> Text_tag.t -> bool = "ml_gtk_text_iter_has_tag"
  (** Returns %TRUE if @iter points to a character that is part
  of a range tagged with @tag.

  See also [method@Gtk.TextIter.starts_tag] and
  [method@Gtk.TextIter.ends_tag]. *)

  external get_visible_text : t -> t -> string
    = "ml_gtk_text_iter_get_visible_text"
  (** Returns visible text in the given range.

      Like [method@Gtk.TextIter.get_text], but invisible text is not included.
      Invisible text is usually invisible because a `GtkTextTag` with the
      “invisible” attribute turned on has been applied to it. *)

  external get_visible_slice : t -> t -> string
    = "ml_gtk_text_iter_get_visible_slice"
  (** Returns visible text in the given range.

      Like [method@Gtk.TextIter.get_slice], but invisible text is not included.
      Invisible text is usually invisible because a `GtkTextTag` with the
      “invisible” attribute turned on has been applied to it. *)

  external get_visible_line_offset : t -> int
    = "ml_gtk_text_iter_get_visible_line_offset"
  (** Returns the offset in characters from the start of the
  line to the given @iter, not counting characters that
  are invisible due to tags with the “invisible” flag
  toggled on. *)

  external get_visible_line_index : t -> int
    = "ml_gtk_text_iter_get_visible_line_index"
  (** Returns the number of bytes from the start of the
  line to the given @iter, not counting bytes that
  are invisible due to tags with the “invisible” flag
  toggled on. *)

  external get_toggled_tags : t -> bool -> Text_tag.t list
    = "ml_gtk_text_iter_get_toggled_tags"
  (** Returns a list of `GtkTextTag` that are toggled on or off at this
  point.

  If @toggled_on is %TRUE, the list contains tags that are
  toggled on. If a tag is toggled on at @iter, then some non-empty
  range of characters following @iter has that tag applied to it.  If
  a tag is toggled off, then some non-empty range following @iter
  does not have the tag applied to it. *)

  external get_text : t -> t -> string = "ml_gtk_text_iter_get_text"
  (** Returns text in the given range.

      If the range contains non-text elements such as images, the character and
      byte offsets in the returned string will not correspond to character and
      byte offsets in the buffer. If you want offsets to correspond, see
      [method@Gtk.TextIter.get_slice]. *)

  external get_tags : t -> Text_tag.t list = "ml_gtk_text_iter_get_tags"
  (** Returns a list of tags that apply to @iter, in ascending order of
  priority.

  The highest-priority tags are last.

  The `GtkTextTag`s in the list don’t have a reference added,
  but you have to free the list itself. *)

  external get_slice : t -> t -> string = "ml_gtk_text_iter_get_slice"
  (** Returns the text in the given range.

      A “slice” is an array of characters encoded in UTF-8 format, including the
      Unicode “unknown” character 0xFFFC for iterable non-character elements in
      the buffer, such as images. Because images are encoded in the slice, byte
      and character offsets in the returned array will correspond to byte
      offsets in the text buffer. Note that 0xFFFC can occur in normal text as
      well, so it is not a reliable indicator that a paintable or widget is in
      the buffer. *)

  external get_paintable : t -> Ocgtk_gdk.Gdk.Wrappers.Paintable.t option
    = "ml_gtk_text_iter_get_paintable"
  (** If the element at @iter is a paintable, the paintable is returned.

  Otherwise, %NULL is returned. *)

  external get_offset : t -> int = "ml_gtk_text_iter_get_offset"
  (** Returns the character offset of an iterator.

      Each character in a `GtkTextBuffer` has an offset, starting with 0 for the
      first character in the buffer. Use
      [method@Gtk.TextBuffer.get_iter_at_offset] to convert an offset back into
      an iterator. *)

  external get_marks : t -> Text_mark.t list = "ml_gtk_text_iter_get_marks"
  (** Returns a list of all `GtkTextMark` at this location.

      Because marks are not iterable (they don’t take up any "space" in the
      buffer, they are just marks in between iterable locations), multiple marks
      can exist in the same place.

      The returned list is not in any meaningful order. *)

  external get_line_offset : t -> int = "ml_gtk_text_iter_get_line_offset"
  (** Returns the character offset of the iterator, counting from the start of a
      newline-terminated line.

      The first character on the line has offset 0. *)

  external get_line_index : t -> int = "ml_gtk_text_iter_get_line_index"
  (** Returns the byte index of the iterator, counting from the start of a
      newline-terminated line.

      Remember that `GtkTextBuffer` encodes text in UTF-8, and that characters
      can require a variable number of bytes to represent. *)

  external get_line : t -> int = "ml_gtk_text_iter_get_line"
  (** Returns the line number containing the iterator.

      Lines in a `GtkTextBuffer` are numbered beginning with 0 for the first
      line in the buffer. *)

  external get_language : t -> Ocgtk_pango.Pango.Wrappers.Language.t
    = "ml_gtk_text_iter_get_language"
  (** Returns the language in effect at @iter.

  If no tags affecting language apply to @iter, the return
  value is identical to that of [func@Gtk.get_default_language]. *)

  external get_child_anchor : t -> Text_child_anchor.t option
    = "ml_gtk_text_iter_get_child_anchor"
  (** If the location at @iter contains a child anchor, the
  anchor is returned.

  Otherwise, %NULL is returned. *)

  external get_chars_in_line : t -> int = "ml_gtk_text_iter_get_chars_in_line"
  (** Returns the number of characters in the line containing @iter,
  including the paragraph delimiters. *)

  external get_char : t -> int = "ml_gtk_text_iter_get_char"
  (** The Unicode character at this iterator is returned.

      Equivalent to operator* on a C++ iterator. If the element at this iterator
      is a non-character element, such as an image embedded in the buffer, the
      Unicode “unknown” character 0xFFFC is returned. If invoked on the end
      iterator, zero is returned; zero is not a valid Unicode character.

      So you can write a loop which ends when this function returns 0. *)

  external get_bytes_in_line : t -> int = "ml_gtk_text_iter_get_bytes_in_line"
  (** Returns the number of bytes in the line containing @iter,
  including the paragraph delimiters. *)

  external get_buffer : t -> Text_buffer.t = "ml_gtk_text_iter_get_buffer"
  (** Returns the `GtkTextBuffer` this iterator is associated with. *)

  external forward_word_ends : t -> int -> bool
    = "ml_gtk_text_iter_forward_word_ends"
  (** Calls [method@Gtk.TextIter.forward_word_end] up to @count times. *)

  external forward_word_end : t -> bool = "ml_gtk_text_iter_forward_word_end"
  (** Moves forward to the next word end.

  If @iter is currently on a word end, moves forward to the
  next one after that.

  Word breaks are determined by Pango and should be correct
  for nearly any language. *)

  external forward_visible_word_ends : t -> int -> bool
    = "ml_gtk_text_iter_forward_visible_word_ends"
  (** Calls [method@Gtk.TextIter.forward_visible_word_end] up to @count times. *)

  external forward_visible_word_end : t -> bool
    = "ml_gtk_text_iter_forward_visible_word_end"
  (** Moves forward to the next visible word end.

  If @iter is currently on a word end, moves forward to the
  next one after that.

  Word breaks are determined by Pango and should be correct
  for nearly any language *)

  external forward_visible_lines : t -> int -> bool
    = "ml_gtk_text_iter_forward_visible_lines"
  (** Moves @count visible lines forward, if possible.

  If @count would move past the start or end of the buffer, moves to
  the start or end of the buffer.

  The return value indicates whether the iterator moved
  onto a dereferenceable position; if the iterator didn’t move, or
  moved onto the end iterator, then %FALSE is returned. If @count is 0,
  the function does nothing and returns %FALSE. If @count is negative,
  moves backward by 0 - @count lines. *)

  external forward_visible_line : t -> bool
    = "ml_gtk_text_iter_forward_visible_line"
  (** Moves @iter to the start of the next visible line.

  Returns %TRUE if there
  was a next line to move to, and %FALSE if @iter was simply moved to
  the end of the buffer and is now not dereferenceable, or if @iter was
  already at the end of the buffer. *)

  external forward_visible_cursor_positions : t -> int -> bool
    = "ml_gtk_text_iter_forward_visible_cursor_positions"
  (** Moves up to @count visible cursor positions.

  See [method@Gtk.TextIter.forward_cursor_position] for details. *)

  external forward_visible_cursor_position : t -> bool
    = "ml_gtk_text_iter_forward_visible_cursor_position"
  (** Moves @iter forward to the next visible cursor position.

  See [method@Gtk.TextIter.forward_cursor_position] for details. *)

  external forward_to_tag_toggle : t -> Text_tag.t option -> bool
    = "ml_gtk_text_iter_forward_to_tag_toggle"
  (** Moves forward to the next toggle (on or off) of the
  @tag, or to the next toggle of any tag if
  @tag is %NULL.

  If no matching tag toggles are found,
  returns %FALSE, otherwise %TRUE. Does not return toggles
  located at @iter, only toggles after @iter. Sets @iter to
  the location of the toggle, or to the end of the buffer
  if no toggle is found. *)

  external forward_to_line_end : t -> bool
    = "ml_gtk_text_iter_forward_to_line_end"
  (** Moves the iterator to point to the paragraph delimiter characters.

  The possible characters are either a newline, a carriage return,
  a carriage return/newline in sequence, or the Unicode paragraph
  separator character.

  If the iterator is already at the paragraph delimiter
  characters, moves to the paragraph delimiter characters for the
  next line. If @iter is on the last line in the buffer, which does
  not end in paragraph delimiters, moves to the end iterator (end of
  the last line), and returns %FALSE. *)

  external forward_to_end : t -> unit = "ml_gtk_text_iter_forward_to_end"
  (** Moves @iter forward to the “end iterator”, which points
  one past the last valid character in the buffer.

  [method@Gtk.TextIter.get_char] called on the end iterator
  returns 0, which is convenient for writing loops. *)

  external forward_sentence_ends : t -> int -> bool
    = "ml_gtk_text_iter_forward_sentence_ends"
  (** Calls [method@Gtk.TextIter.forward_sentence_end] @count times.

  If @count is negative, moves backward instead of forward. *)

  external forward_sentence_end : t -> bool
    = "ml_gtk_text_iter_forward_sentence_end"
  (** Moves forward to the next sentence end.

  If @iter is at the end of a sentence, moves to the next
  end of sentence.

  Sentence boundaries are determined by Pango and should
  be correct for nearly any language. *)

  external forward_search :
    t -> string -> Gtk_enums.textsearchflags -> t option -> bool * t * t
    = "ml_gtk_text_iter_forward_search"
  (** Searches forward for @str.

  Any match is returned by setting @match_start to the first character
  of the match and @match_end to the first character after the match.
  The search will not continue past @limit. Note that a search is a
  linear or O(n) operation, so you may wish to use @limit to avoid
  locking up your UI on large buffers.

  @match_start will never be set to a `GtkTextIter` located before @iter,
  even if there is a possible @match_end after or at @iter. *)

  external forward_lines : t -> int -> bool = "ml_gtk_text_iter_forward_lines"
  (** Moves @count lines forward, if possible.

  If @count would move past the start or end of the buffer, moves to
  the start or end of the buffer.

  The return value indicates whether the iterator moved
  onto a dereferenceable position; if the iterator didn’t move, or
  moved onto the end iterator, then %FALSE is returned. If @count is 0,
  the function does nothing and returns %FALSE. If @count is negative,
  moves backward by 0 - @count lines. *)

  external forward_line : t -> bool = "ml_gtk_text_iter_forward_line"
  (** Moves @iter to the start of the next line.

  If the iter is already on the last line of the buffer,
  moves the iter to the end of the current line. If after
  the operation, the iter is at the end of the buffer and not
  dereferenceable, returns %FALSE. Otherwise, returns %TRUE. *)

  external forward_cursor_positions : t -> int -> bool
    = "ml_gtk_text_iter_forward_cursor_positions"
  (** Moves up to @count cursor positions.

  See [method@Gtk.TextIter.forward_cursor_position] for details. *)

  external forward_cursor_position : t -> bool
    = "ml_gtk_text_iter_forward_cursor_position"
  (** Moves @iter forward by a single cursor position.

  Cursor positions are (unsurprisingly) positions where the
  cursor can appear. Perhaps surprisingly, there may not be
  a cursor position between all characters. The most common
  example for European languages would be a carriage return/newline
  sequence.

  For some Unicode characters, the equivalent of say the letter “a”
  with an accent mark will be represented as two characters, first
  the letter then a "combining mark" that causes the accent to be
  rendered; so the cursor can’t go between those two characters.

  See also the [struct@Pango.LogAttr] struct and the [func@Pango.break]
  function. *)

  external forward_chars : t -> int -> bool = "ml_gtk_text_iter_forward_chars"
  (** Moves @count characters if possible.

  If @count would move past the start or end of the buffer,
  moves to the start or end of the buffer.

  The return value indicates whether the new position of
  @iter is different from its original position, and dereferenceable
  (the last iterator in the buffer is not dereferenceable). If @count
  is 0, the function does nothing and returns %FALSE. *)

  external forward_char : t -> bool = "ml_gtk_text_iter_forward_char"
  (** Moves @iter forward by one character offset.

  Note that images embedded in the buffer occupy 1 character slot, so
  this function may actually move onto an image instead of a character,
  if you have images in your buffer. If @iter is the end iterator or
  one character before it, @iter will now point at the end iterator,
  and this function returns %FALSE for convenience when writing loops. *)

  external equal : t -> t -> bool = "ml_gtk_text_iter_equal"
  (** Tests whether two iterators are equal, using the fastest possible
      mechanism.

      This function is very fast; you can expect it to perform better than e.g.
      getting the character offset for each iterator and comparing the offsets
      yourself. Also, it’s a bit faster than [method@Gtk.TextIter.compare]. *)

  external ends_word : t -> bool = "ml_gtk_text_iter_ends_word"
  (** Determines whether @iter ends a natural-language word.

  Word breaks are determined by Pango and should be correct
  for nearly any language. *)

  external ends_tag : t -> Text_tag.t option -> bool
    = "ml_gtk_text_iter_ends_tag"
  (** Returns %TRUE if @tag is toggled off at exactly this point.

  If @tag is %NULL, returns %TRUE if any tag is toggled off at this point.

  Note that if this function returns %TRUE, it means that
  @iter is at the end of the tagged range, but that the character
  at @iter is outside the tagged range. In other words,
  unlike [method@Gtk.TextIter.starts_tag], if this function
  returns %TRUE, [method@Gtk.TextIter.has_tag] will return
  %FALSE for the same parameters. *)

  external ends_sentence : t -> bool = "ml_gtk_text_iter_ends_sentence"
  (** Determines whether @iter ends a sentence.

  Sentence boundaries are determined by Pango and should
  be correct for nearly any language. *)

  external ends_line : t -> bool = "ml_gtk_text_iter_ends_line"
  (** Returns %TRUE if @iter points to the start of the paragraph
  delimiter characters for a line.

  Delimiters will be either a newline, a carriage return, a carriage
  return followed by a newline, or a Unicode paragraph separator
  character.

  Note that an iterator pointing to the \n of a \r\n pair will not be
  counted as the end of a line, the line ends before the \r. The end
  iterator is considered to be at the end of a line, even though there
  are no paragraph delimiter chars there. *)

  external editable : t -> bool -> bool = "ml_gtk_text_iter_editable"
  (** Returns whether the character at @iter is within an editable region
  of text.

  Non-editable text is “locked” and can’t be changed by the
  user via `GtkTextView`. If no tags applied to this text affect
  editability, @default_setting will be returned.

  You don’t want to use this function to decide whether text can be
  inserted at @iter, because for insertion you don’t want to know
  whether the char at @iter is inside an editable range, you want to
  know whether a new character inserted at @iter would be inside an
  editable range. Use [method@Gtk.TextIter.can_insert] to handle this
  case. *)

  external compare : t -> t -> int = "ml_gtk_text_iter_compare"
  (** A qsort()-style function that returns negative if @lhs is less than
  @rhs, positive if @lhs is greater than @rhs, and 0 if they’re equal.

  Ordering is in character offset order, i.e. the first character
  in the buffer is less than the second character in the buffer. *)

  external can_insert : t -> bool -> bool = "ml_gtk_text_iter_can_insert"
  (** Considering the default editability of the buffer, and tags that
  affect editability, determines whether text inserted at @iter would
  be editable.

  If text inserted at @iter would be editable then the
  user should be allowed to insert text at @iter.
  [method@Gtk.TextBuffer.insert_interactive] uses this function
  to decide whether insertions are allowed at a given position. *)

  external backward_word_starts : t -> int -> bool
    = "ml_gtk_text_iter_backward_word_starts"
  (** Calls [method@Gtk.TextIter.backward_word_start] up to @count times. *)

  external backward_word_start : t -> bool
    = "ml_gtk_text_iter_backward_word_start"
  (** Moves backward to the previous word start.

  If @iter is currently on a word start, moves backward to the
  next one after that.

  Word breaks are determined by Pango and should be correct
  for nearly any language *)

  external backward_visible_word_starts : t -> int -> bool
    = "ml_gtk_text_iter_backward_visible_word_starts"
  (** Calls [method@Gtk.TextIter.backward_visible_word_start] up to @count times. *)

  external backward_visible_word_start : t -> bool
    = "ml_gtk_text_iter_backward_visible_word_start"
  (** Moves backward to the previous visible word start.

  If @iter is currently on a word start, moves backward to the
  next one after that.

  Word breaks are determined by Pango and should be correct
  for nearly any language. *)

  external backward_visible_lines : t -> int -> bool
    = "ml_gtk_text_iter_backward_visible_lines"
  (** Moves @count visible lines backward, if possible.

  If @count would move past the start or end of the buffer, moves to
  the start or end of the buffer.

  The return value indicates whether the iterator moved
  onto a dereferenceable position; if the iterator didn’t move, or
  moved onto the end iterator, then %FALSE is returned. If @count is 0,
  the function does nothing and returns %FALSE. If @count is negative,
  moves forward by 0 - @count lines. *)

  external backward_visible_line : t -> bool
    = "ml_gtk_text_iter_backward_visible_line"
  (** Moves @iter to the start of the previous visible line.

  Returns %TRUE if
  @iter could be moved; i.e. if @iter was at character offset 0, this
  function returns %FALSE. Therefore if @iter was already on line 0,
  but not at the start of the line, @iter is snapped to the start of
  the line and the function returns %TRUE. (Note that this implies that
  in a loop calling this function, the line number may not change on
  every iteration, if your first iteration is on line 0.) *)

  external backward_visible_cursor_positions : t -> int -> bool
    = "ml_gtk_text_iter_backward_visible_cursor_positions"
  (** Moves up to @count visible cursor positions.

  See [method@Gtk.TextIter.backward_cursor_position] for details. *)

  external backward_visible_cursor_position : t -> bool
    = "ml_gtk_text_iter_backward_visible_cursor_position"
  (** Moves @iter backward to the previous visible cursor position.

  See [method@Gtk.TextIter.backward_cursor_position] for details. *)

  external backward_to_tag_toggle : t -> Text_tag.t option -> bool
    = "ml_gtk_text_iter_backward_to_tag_toggle"
  (** Moves backward to the next toggle (on or off) of the
  @tag, or to the next toggle of any tag if
  @tag is %NULL.

  If no matching tag toggles are found,
  returns %FALSE, otherwise %TRUE. Does not return toggles
  located at @iter, only toggles before @iter. Sets @iter
  to the location of the toggle, or the start of the buffer
  if no toggle is found. *)

  external backward_sentence_starts : t -> int -> bool
    = "ml_gtk_text_iter_backward_sentence_starts"
  (** Calls [method@Gtk.TextIter.backward_sentence_start] up to @count times.

  If @count is negative, moves forward instead of backward. *)

  external backward_sentence_start : t -> bool
    = "ml_gtk_text_iter_backward_sentence_start"
  (** Moves backward to the previous sentence start.

  If @iter is already at the start of a sentence, moves backward
  to the next one.

  Sentence boundaries are determined by Pango and should
  be correct for nearly any language. *)

  external backward_search :
    t -> string -> Gtk_enums.textsearchflags -> t option -> bool * t * t
    = "ml_gtk_text_iter_backward_search"
  (** Same as [method@Gtk.TextIter.forward_search], but moves backward.

  @match_end will never be set to a `GtkTextIter` located after @iter,
  even if there is a possible @match_start before or at @iter. *)

  external backward_lines : t -> int -> bool = "ml_gtk_text_iter_backward_lines"
  (** Moves @count lines backward, if possible.

  If @count would move past the start or end of the buffer, moves to
  the start or end of the buffer.

  The return value indicates whether the iterator moved
  onto a dereferenceable position; if the iterator didn’t move, or
  moved onto the end iterator, then %FALSE is returned. If @count is 0,
  the function does nothing and returns %FALSE. If @count is negative,
  moves forward by 0 - @count lines. *)

  external backward_line : t -> bool = "ml_gtk_text_iter_backward_line"
  (** Moves @iter to the start of the previous line.

  Returns %TRUE if @iter could be moved; i.e. if @iter was at
  character offset 0, this function returns %FALSE. Therefore,
  if @iter was already on line 0, but not at the start of the line,
  @iter is snapped to the start of the line and the function returns
  %TRUE. (Note that this implies that
  in a loop calling this function, the line number may not change on
  every iteration, if your first iteration is on line 0.) *)

  external backward_cursor_positions : t -> int -> bool
    = "ml_gtk_text_iter_backward_cursor_positions"
  (** Moves up to @count cursor positions.

  See [method@Gtk.TextIter.forward_cursor_position] for details. *)

  external backward_cursor_position : t -> bool
    = "ml_gtk_text_iter_backward_cursor_position"
  (** Like [method@Gtk.TextIter.forward_cursor_position], but moves backward. *)

  external backward_chars : t -> int -> bool = "ml_gtk_text_iter_backward_chars"
  (** Moves @count characters backward, if possible.

  If @count would move past the start or end of the buffer, moves
  to the start or end of the buffer.

  The return value indicates whether the iterator moved
  onto a dereferenceable position; if the iterator didn’t move, or
  moved onto the end iterator, then %FALSE is returned. If @count is 0,
  the function does nothing and returns %FALSE. *)

  external backward_char : t -> bool = "ml_gtk_text_iter_backward_char"
  (** Moves backward by one character offset.

  Returns %TRUE if movement was possible; if @iter was the first
  in the buffer (character offset 0), this function returns %FALSE
  for convenience when writing loops. *)

  external assign : t -> t -> unit = "ml_gtk_text_iter_assign"
  (** Assigns the value of @other to @iter.

  This function is not useful in applications, because
  iterators can be assigned with `GtkTextIter i = j;`.

  The function is used by language bindings. *)
end

and Text_mark : sig
  type t = [ `text_mark | `object_ ] Gobject.obj

  external gtype : unit -> Gobject.Type.t = "ml_gtk_text_mark_get_type"

  external new_ : string option -> bool -> t = "ml_gtk_text_mark_new"
  (** Create a new TextMark *)

  (* Methods *)

  external set_visible : t -> bool -> unit = "ml_gtk_text_mark_set_visible"
  (** Sets the visibility of @mark.

  The insertion point is normally visible, i.e. you can see it as
  a vertical bar. Also, the text widget uses a visible mark to
  indicate where a drop will occur when dragging-and-dropping text.
  Most other marks are not visible.

  Marks are not visible by default. *)

  external get_visible : t -> bool = "ml_gtk_text_mark_get_visible"
  (** Returns %TRUE if the mark is visible.

      A cursor is displayed for visible marks. *)

  external get_name : t -> string option = "ml_gtk_text_mark_get_name"
  (** Returns the mark name.

      Returns %NULL for anonymous marks. *)

  external get_left_gravity : t -> bool = "ml_gtk_text_mark_get_left_gravity"
  (** Determines whether the mark has left gravity. *)

  external get_deleted : t -> bool = "ml_gtk_text_mark_get_deleted"
  (** Returns %TRUE if the mark has been removed from its buffer.

      See [method@Gtk.TextBuffer.add_mark] for a way to add it to a buffer
      again. *)

  external get_buffer : t -> Text_buffer.t option
    = "ml_gtk_text_mark_get_buffer"
  (** Gets the buffer this mark is located inside.

      Returns %NULL if the mark is deleted. *)

  (* Properties *)
end
