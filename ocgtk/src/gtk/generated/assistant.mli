(* GENERATED CODE - DO NOT EDIT *)
(* Assistant: Assistant *)

type t =
  [ `assistant | `window | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_assistant_get_type"

external new_ : unit -> t = "ml_gtk_assistant_new"
(** Create a new Assistant *)

(* Methods *)

external update_buttons_state : t -> unit
  = "ml_gtk_assistant_update_buttons_state"
(** Forces @assistant to recompute the buttons state.

GTK automatically takes care of this in most situations,
e.g. when the user goes to a different page, or when the
visibility or completeness of a page changes.

One situation where it can be necessary to call this
function is when changing a value on the current page
affects the future page flow of the assistant. *)

external set_page_type :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Gtk_enums.assistantpagetype ->
  unit = "ml_gtk_assistant_set_page_type"
(** Sets the page type for @page.

The page type determines the page behavior in the @assistant. *)

external set_page_title :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  string ->
  unit = "ml_gtk_assistant_set_page_title"
(** Sets a title for @page.

The title is displayed in the header area of the assistant
when @page is the current page. *)

external set_page_complete :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  bool ->
  unit = "ml_gtk_assistant_set_page_complete"
(** Sets whether @page contents are complete.

This will make @assistant update the buttons state
to be able to continue the task. *)

external set_current_page : t -> int -> unit
  = "ml_gtk_assistant_set_current_page"
(** Switches the page to @page_num.

Note that this will only be necessary in custom buttons,
as the @assistant flow can be set with
gtk_assistant_set_forward_page_func(). *)

external remove_page : t -> int -> unit = "ml_gtk_assistant_remove_page"
(** Removes the @page_num’s page from @assistant. *)

external remove_action_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_assistant_remove_action_widget"
(** Removes a widget from the action area of a `GtkAssistant`. *)

external previous_page : t -> unit = "ml_gtk_assistant_previous_page"
(** Navigate to the previous visited page.

    It is a programming error to call this function when no previous page is
    available.

    This function is for use when creating pages of the
    %GTK_ASSISTANT_PAGE_CUSTOM type. *)

external prepend_page :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int = "ml_gtk_assistant_prepend_page"
(** Prepends a page to the @assistant. *)

external next_page : t -> unit = "ml_gtk_assistant_next_page"
(** Navigate to the next page.

    It is a programming error to call this function when there is no next page.

    This function is for use when creating pages of the
    %GTK_ASSISTANT_PAGE_CUSTOM type. *)

external insert_page :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int ->
  int = "ml_gtk_assistant_insert_page"
(** Inserts a page in the @assistant at a given position. *)

external get_pages : t -> Ocgtk_gio.Gio.Wrappers.List_model.t
  = "ml_gtk_assistant_get_pages"
(** Gets a list model of the assistant pages. *)

external get_page_type :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Gtk_enums.assistantpagetype = "ml_gtk_assistant_get_page_type"
(** Gets the page type of @page. *)

external get_page_title :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  string = "ml_gtk_assistant_get_page_title"
(** Gets the title for @page. *)

external get_page_complete :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  bool = "ml_gtk_assistant_get_page_complete"
(** Gets whether @page is complete. *)

external get_page :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  Assistant_page.t = "ml_gtk_assistant_get_page"
(** Returns the `GtkAssistantPage` object for @child. *)

external get_nth_page :
  t ->
  int ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_assistant_get_nth_page"
(** Returns the child widget contained in page number @page_num. *)

external get_n_pages : t -> int = "ml_gtk_assistant_get_n_pages"
(** Returns the number of pages in the @assistant *)

external get_current_page : t -> int = "ml_gtk_assistant_get_current_page"
(** Returns the page number of the current page. *)

external commit : t -> unit = "ml_gtk_assistant_commit"
(** Erases the visited page history.

    GTK will then hide the back button on the current page, and removes the
    cancel button from subsequent pages.

    Use this when the information provided up to the current page is hereafter
    deemed permanent and cannot be modified or undone. For example, showing a
    progress page to track a long-running, unreversible operation after the user
    has clicked apply on a confirmation page. *)

external append_page :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  int = "ml_gtk_assistant_append_page"
(** Appends a page to the @assistant. *)

external add_action_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t ->
  unit = "ml_gtk_assistant_add_action_widget"
(** Adds a widget to the action area of a `GtkAssistant`. *)

(* Properties *)

external get_use_header_bar : t -> int = "ml_gtk_assistant_get_use_header_bar"
(** Get property: use-header-bar *)

val on_apply :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_cancel :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_close :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_escape :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_prepare :
  ?after:bool ->
  t ->
  callback:
    (page:
       Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
       .Widget
       .t ->
    unit) ->
  Gobject.Signal.handler_id
