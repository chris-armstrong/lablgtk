(* GENERATED CODE - DO NOT EDIT *)
(* SelectionModel: SelectionModel *)

type t = [ `selection_model ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_selection_model_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gtk_selection_model_from_gobject"

(* Methods *)

external unselect_range : t -> int -> int -> bool
  = "ml_gtk_selection_model_unselect_range"
(** Requests to unselect a range of items in the model. *)

external unselect_item : t -> int -> bool
  = "ml_gtk_selection_model_unselect_item"
(** Requests to unselect an item in the model. *)

external unselect_all : t -> bool = "ml_gtk_selection_model_unselect_all"
(** Requests to unselect all items in the model. *)

external set_selection : t -> Bitset.t -> Bitset.t -> bool
  = "ml_gtk_selection_model_set_selection"
(** Make selection changes.

This is the most advanced selection updating method that allows
the most fine-grained control over selection changes. If you can,
you should try the simpler versions, as implementations are more
likely to implement support for those.

Requests that the selection state of all positions set in @mask
be updated to the respective value in the @selected bitmask.

In pseudocode, it would look something like this:

```c
for (i = 0; i < n_items; i++)
  {
    // don't change values not in the mask
    if (!gtk_bitset_contains (mask, i))
      continue;

    if (gtk_bitset_contains (selected, i))
      select_item (i);
    else
      unselect_item (i);
  }

gtk_selection_model_selection_changed (model,
                                       first_changed_item,
                                       n_changed_items);
```

@mask and @selected must not be modified. They may refer to the
same bitset, which would mean that every item in the set should
be selected. *)

external selection_changed : t -> int -> int -> unit
  = "ml_gtk_selection_model_selection_changed"
(** Helper function for implementations of `GtkSelectionModel`.

    Call this when the selection changes to emit the
    [signal@Gtk.SelectionModel::selection-changed] signal. *)

external select_range : t -> int -> int -> bool -> bool
  = "ml_gtk_selection_model_select_range"
(** Requests to select a range of items in the model. *)

external select_item : t -> int -> bool -> bool
  = "ml_gtk_selection_model_select_item"
(** Requests to select an item in the model. *)

external select_all : t -> bool = "ml_gtk_selection_model_select_all"
(** Requests to select all items in the model. *)

external is_selected : t -> int -> bool = "ml_gtk_selection_model_is_selected"
(** Checks if the given item is selected. *)

external get_selection_in_range : t -> int -> int -> Bitset.t
  = "ml_gtk_selection_model_get_selection_in_range"
(** Gets the set of selected items in a range.

    This function is an optimization for
    [method@Gtk.SelectionModel.get_selection] when you are only interested in
    part of the model's selected state. A common use case is in response to the
    [signal@Gtk.SelectionModel::selection-changed] signal. *)

external get_selection : t -> Bitset.t = "ml_gtk_selection_model_get_selection"
(** Gets the set containing all currently selected items in the model.

    This function may be slow, so if you are only interested in single item,
    consider using [method@Gtk.SelectionModel.is_selected] or if you are only
    interested in a few, consider
    [method@Gtk.SelectionModel.get_selection_in_range]. *)

let on_selection_changed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let position =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_uint v
        in
        let n_items =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_uint v
        in
        callback ~position ~n_items)
  in
  Gobject.Signal.connect obj ~name:"selection-changed" ~callback:closure
    ~after:(Option.value after ~default:false)
