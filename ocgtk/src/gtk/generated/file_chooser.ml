(* GENERATED CODE - DO NOT EDIT *)
(* FileChooser: FileChooser *)

type t = [ `file_chooser ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_file_chooser_get_type"
external from_gobject : 'a Gobject.obj -> t = "ml_gtk_file_chooser_from_gobject"

(* Methods *)

external set_select_multiple : t -> bool -> unit
  = "ml_gtk_file_chooser_set_select_multiple"
(** Sets whether multiple files can be selected in the file chooser.

    This is only relevant if the action is set to be
    %GTK_FILE_CHOOSER_ACTION_OPEN or %GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER. *)

external set_filter : t -> File_filter.t -> unit
  = "ml_gtk_file_chooser_set_filter"
(** Sets the current filter.

    Only the files that pass the filter will be displayed. If the
    user-selectable list of filters is non-empty, then the filter should be one
    of the filters in that list.

    Setting the current filter when the list of filters is empty is useful if
    you want to restrict the displayed set of files without letting the user
    change it. *)

external set_file :
  t -> Ocgtk_gio.Gio.Wrappers.File.t -> (bool, GError.t) result
  = "ml_gtk_file_chooser_set_file"
(** Sets @file as the current filename for the file chooser.

This includes changing to the file’s parent folder and actually selecting
the file in list. If the @chooser is in %GTK_FILE_CHOOSER_ACTION_SAVE mode,
the file’s base name will also appear in the dialog’s file name entry.

If the file name isn’t in the current folder of @chooser, then the current
folder of @chooser will be changed to the folder containing @file.

Note that the file must exist, or nothing will be done except
for the directory change.

If you are implementing a save dialog, you should use this function if
you already have a file name to which the user may save; for example,
when the user opens an existing file and then does “Save As…”. If you
don’t have a file name already — for example, if the user just created
a new file and is saving it for the first time, do not call this function.

Instead, use something similar to this:

```c
static void
prepare_file_chooser (GtkFileChooser *chooser,
                      GFile          *existing_file)
{
  gboolean document_is_new = (existing_file == NULL);

  if (document_is_new)
    {
      GFile *default_file_for_saving = g_file_new_for_path ("./out.txt");
      // the user just created a new document
      gtk_file_chooser_set_current_folder (chooser, default_file_for_saving, NULL);
      gtk_file_chooser_set_current_name (chooser, "Untitled document");
      g_object_unref (default_file_for_saving);
    }
  else
    {
      // the user edited an existing document
      gtk_file_chooser_set_file (chooser, existing_file, NULL);
    }
}
``` *)

external set_current_name : t -> string -> unit
  = "ml_gtk_file_chooser_set_current_name"
(** Sets the current name in the file selector, as if entered
by the user.

Note that the name passed in here is a UTF-8 string rather
than a filename. This function is meant for such uses as a
suggested name in a “Save As...” dialog.  You can pass
“Untitled.doc” or a similarly suitable suggestion for the @name.

If you want to preselect a particular existing file, you should
use [method@Gtk.FileChooser.set_file] instead.

Please see the documentation for those functions for an example
of using [method@Gtk.FileChooser.set_current_name] as well. *)

external set_current_folder :
  t -> Ocgtk_gio.Gio.Wrappers.File.t option -> (bool, GError.t) result
  = "ml_gtk_file_chooser_set_current_folder"
(** Sets the current folder for @chooser from a `GFile`. *)

external set_create_folders : t -> bool -> unit
  = "ml_gtk_file_chooser_set_create_folders"
(** Sets whether file chooser will offer to create new folders.

    This is only relevant if the action is not set to be
    %GTK_FILE_CHOOSER_ACTION_OPEN. *)

external set_choice : t -> string -> string -> unit
  = "ml_gtk_file_chooser_set_choice"
(** Selects an option in a 'choice' that has been added with
    gtk_file_chooser_add_choice().

    For a boolean choice, the possible options are "true" and "false". *)

external set_action : t -> Gtk_enums.filechooseraction -> unit
  = "ml_gtk_file_chooser_set_action"
(** Sets the type of operation that the chooser is performing.

    The user interface is adapted to suit the selected action.

    For example, an option to create a new folder might be shown if the action
    is %GTK_FILE_CHOOSER_ACTION_SAVE but not if the action is
    %GTK_FILE_CHOOSER_ACTION_OPEN. *)

external remove_shortcut_folder :
  t -> Ocgtk_gio.Gio.Wrappers.File.t -> (bool, GError.t) result
  = "ml_gtk_file_chooser_remove_shortcut_folder"
(** Removes a folder from the shortcut folders in a file chooser. *)

external remove_filter : t -> File_filter.t -> unit
  = "ml_gtk_file_chooser_remove_filter"
(** Removes @filter from the list of filters that the user can select between. *)

external remove_choice : t -> string -> unit
  = "ml_gtk_file_chooser_remove_choice"
(** Removes a 'choice' that has been added with gtk_file_chooser_add_choice().
*)

external get_shortcut_folders : t -> Ocgtk_gio.Gio.Wrappers.List_model.t
  = "ml_gtk_file_chooser_get_shortcut_folders"
(** Queries the list of shortcut folders in the file chooser.

You should not modify the returned list model. Future changes to
@chooser may or may not affect the returned model. *)

external get_select_multiple : t -> bool
  = "ml_gtk_file_chooser_get_select_multiple"
(** Gets whether multiple files can be selected in the file chooser. *)

external get_filters : t -> Ocgtk_gio.Gio.Wrappers.List_model.t
  = "ml_gtk_file_chooser_get_filters"
(** Gets the current set of user-selectable filters, as a list model.

See [method@Gtk.FileChooser.add_filter] and
[method@Gtk.FileChooser.remove_filter] for changing individual filters.

You should not modify the returned list model. Future changes to
@chooser may or may not affect the returned model. *)

external get_filter : t -> File_filter.t option
  = "ml_gtk_file_chooser_get_filter"
(** Gets the current filter. *)

external get_files : t -> Ocgtk_gio.Gio.Wrappers.List_model.t
  = "ml_gtk_file_chooser_get_files"
(** Lists all the selected files and subfolders in the current folder
of @chooser as `GFile`. *)

external get_file : t -> Ocgtk_gio.Gio.Wrappers.File.t option
  = "ml_gtk_file_chooser_get_file"
(** Gets the `GFile` for the currently selected file in the file selector.

    If multiple files are selected, one of the files will be returned at random.

    If the file chooser is in folder mode, this function returns the selected
    folder. *)

external get_current_name : t -> string option
  = "ml_gtk_file_chooser_get_current_name"
(** Gets the current name in the file selector, as entered by the user.

    This is meant to be used in save dialogs, to get the currently typed
    filename when the file itself does not exist yet. *)

external get_current_folder : t -> Ocgtk_gio.Gio.Wrappers.File.t option
  = "ml_gtk_file_chooser_get_current_folder"
(** Gets the current folder of @chooser as `GFile`. *)

external get_create_folders : t -> bool
  = "ml_gtk_file_chooser_get_create_folders"
(** Gets whether file chooser will offer to create new folders. *)

external get_choice : t -> string -> string option
  = "ml_gtk_file_chooser_get_choice"
(** Gets the currently selected option in the 'choice' with the given ID. *)

external get_action : t -> Gtk_enums.filechooseraction
  = "ml_gtk_file_chooser_get_action"
(** Gets the type of operation that the file chooser is performing. *)

external add_shortcut_folder :
  t -> Ocgtk_gio.Gio.Wrappers.File.t -> (bool, GError.t) result
  = "ml_gtk_file_chooser_add_shortcut_folder"
(** Adds a folder to be displayed with the shortcut folders in a file chooser.
*)

external add_filter : t -> File_filter.t -> unit
  = "ml_gtk_file_chooser_add_filter"
(** Adds @filter to the list of filters that the user can select between.

When a filter is selected, only files that are passed by that
filter are displayed.

Note that the @chooser takes ownership of the filter if it is floating,
so you have to ref and sink it if you want to keep a reference. *)

external add_choice :
  t -> string -> string -> string array option -> string array option -> unit
  = "ml_gtk_file_chooser_add_choice"
(** Adds a 'choice' to the file chooser.

    This is typically implemented as a combobox or, for boolean choices, as a
    checkbutton. You can select a value using
    [method@Gtk.FileChooser.set_choice] before the dialog is shown, and you can
    obtain the user-selected value in the [signal@Gtk.Dialog::response] signal
    handler using [method@Gtk.FileChooser.get_choice]. *)

(* Properties *)
