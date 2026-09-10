(* GENERATED CODE - DO NOT EDIT *)
(* EntryCompletion: EntryCompletion *)

type t = [ `entry_completion | `object_ ] Gobject.obj

external new_ : unit -> t = "ml_gtk_entry_completion_new"
(** Create a new EntryCompletion *)

external new_with_area :
  Cell_area_and__cell_area_context_and__cell_layout.Cell_area.t -> t
  = "ml_gtk_entry_completion_new_with_area"
(** Create a new EntryCompletion *)

(* Methods *)

external set_text_column : t -> int -> unit
  = "ml_gtk_entry_completion_set_text_column"
(** Convenience function for setting up the most used case of this code: a
completion list with just strings.

This function will set up @completion
to have a list displaying all (and just) strings in the completion list,
and to get those strings from @column in the model of @completion.

This functions creates and adds a `GtkCellRendererText` for the selected
column. If you need to set the text column, but don't want the cell
renderer, use g_object_set() to set the
[property@Gtk.EntryCompletion:text-column] property directly. *)

external set_popup_single_match : t -> bool -> unit
  = "ml_gtk_entry_completion_set_popup_single_match"
(** Sets whether the completion popup window will appear even if there is only a
    single match.

    You may want to set this to %FALSE if you are using
    [property@Gtk.EntryCompletion:inline-completion]. *)

external set_popup_set_width : t -> bool -> unit
  = "ml_gtk_entry_completion_set_popup_set_width"
(** Sets whether the completion popup window will be resized to be the same
    width as the entry. *)

external set_popup_completion : t -> bool -> unit
  = "ml_gtk_entry_completion_set_popup_completion"
(** Sets whether the completions should be presented in a popup window. *)

external set_model : t -> Tree_model.t option -> unit
  = "ml_gtk_entry_completion_set_model"
(** Sets the model for a `GtkEntryCompletion`.

If @completion already has a model set, it will remove it
before setting the new model. If model is %NULL, then it
will unset the model. *)

external set_minimum_key_length : t -> int -> unit
  = "ml_gtk_entry_completion_set_minimum_key_length"
(** Requires the length of the search key for @completion to be at least
@length.

This is useful for long lists, where completing using a small
key takes a lot of time and will come up with meaningless results anyway
(ie, a too large dataset). *)

external set_inline_selection : t -> bool -> unit
  = "ml_gtk_entry_completion_set_inline_selection"
(** Sets whether it is possible to cycle through the possible completions inside
    the entry. *)

external set_inline_completion : t -> bool -> unit
  = "ml_gtk_entry_completion_set_inline_completion"
(** Sets whether the common prefix of the possible completions should be
    automatically inserted in the entry. *)

external insert_prefix : t -> unit = "ml_gtk_entry_completion_insert_prefix"
(** Requests a prefix insertion. *)

external get_text_column : t -> int = "ml_gtk_entry_completion_get_text_column"
(** Returns the column in the model of @completion to get strings from. *)

external get_popup_single_match : t -> bool
  = "ml_gtk_entry_completion_get_popup_single_match"
(** Returns whether the completion popup window will appear even if there is
    only a single match. *)

external get_popup_set_width : t -> bool
  = "ml_gtk_entry_completion_get_popup_set_width"
(** Returns whether the completion popup window will be resized to the width of
    the entry. *)

external get_popup_completion : t -> bool
  = "ml_gtk_entry_completion_get_popup_completion"
(** Returns whether the completions should be presented in a popup window. *)

external get_model : t -> Tree_model.t option
  = "ml_gtk_entry_completion_get_model"
(** Returns the model the `GtkEntryCompletion` is using as data source.

    Returns %NULL if the model is unset. *)

external get_minimum_key_length : t -> int
  = "ml_gtk_entry_completion_get_minimum_key_length"
(** Returns the minimum key length as set for @completion. *)

external get_inline_selection : t -> bool
  = "ml_gtk_entry_completion_get_inline_selection"
(** Returns %TRUE if inline-selection mode is turned on. *)

external get_inline_completion : t -> bool
  = "ml_gtk_entry_completion_get_inline_completion"
(** Returns whether the common prefix of the possible completions should be
    automatically inserted in the entry. *)

external get_entry :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t = "ml_gtk_entry_completion_get_entry"
(** Gets the entry @completion has been attached to. *)

external get_completion_prefix : t -> string option
  = "ml_gtk_entry_completion_get_completion_prefix"
(** Get the original text entered by the user that triggered the completion or
    %NULL if there’s no completion ongoing. *)

external compute_prefix : t -> string -> string option
  = "ml_gtk_entry_completion_compute_prefix"
(** Computes the common prefix that is shared by all rows in @completion
that start with @key.

If no row matches @key, %NULL will be returned.
Note that a text column must have been set for this function to work,
see [method@Gtk.EntryCompletion.set_text_column] for details. *)

external complete : t -> unit = "ml_gtk_entry_completion_complete"
(** Requests a completion operation, or in other words a refiltering of the
    current list with completions, using the current key.

    The completion list view will be updated accordingly. *)

(* Properties *)

external get_cell_area :
  t -> Cell_area_and__cell_area_context_and__cell_layout.Cell_area.t
  = "ml_gtk_entry_completion_get_cell_area"
(** Get property: cell-area *)

let on_insert_prefix ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let prefix =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_string_exn v
        in
        let result = callback ~prefix in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"insert-prefix" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_no_matches ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"no-matches" ~callback
    ~after:(Option.value after ~default:false)
