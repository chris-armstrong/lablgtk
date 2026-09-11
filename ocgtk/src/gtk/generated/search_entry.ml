(* GENERATED CODE - DO NOT EDIT *)
(* SearchEntry: SearchEntry *)

type t = [ `search_entry | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_search_entry_get_type"

external new_ : unit -> t = "ml_gtk_search_entry_new"
(** Create a new SearchEntry *)

(* Methods *)

external set_search_delay : t -> int -> unit
  = "ml_gtk_search_entry_set_search_delay"
(** Set the delay to be used between the last keypress and the
    [signal@Gtk.SearchEntry::search-changed] signal being emitted. *)

external set_placeholder_text : t -> string option -> unit
  = "ml_gtk_search_entry_set_placeholder_text"
(** Sets the placeholder text associated with @entry. *)

external set_key_capture_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option ->
  unit = "ml_gtk_search_entry_set_key_capture_widget"
(** Sets @widget as the widget that @entry will capture key
events from.

Key events are consumed by the search entry to start or
continue a search.

If the entry is part of a `GtkSearchBar`, it is preferable
to call [method@Gtk.SearchBar.set_key_capture_widget] instead,
which will reveal the entry in addition to triggering the
search entry.

Note that despite the name of this function, the events
are only 'captured' in the bubble phase, which means that
editable child widgets of @widget will receive text input
before it gets captured. If that is not desired, you can
capture and forward the events yourself with
[method@Gtk.EventControllerKey.forward]. *)

external set_input_purpose : t -> Gtk_enums.inputpurpose -> unit
  = "ml_gtk_search_entry_set_input_purpose"
(** Sets the input purpose of @entry. *)

external set_input_hints : t -> Gtk_enums.inputhints -> unit
  = "ml_gtk_search_entry_set_input_hints"
(** Sets the input hints for @entry. *)

external get_search_delay : t -> int = "ml_gtk_search_entry_get_search_delay"
(** Get the delay to be used between the last keypress and the
    [signal@Gtk.SearchEntry::search-changed] signal being emitted. *)

external get_placeholder_text : t -> string option
  = "ml_gtk_search_entry_get_placeholder_text"
(** Gets the placeholder text associated with @entry. *)

external get_key_capture_widget :
  t ->
  Event_controller_and__layout_child_and__layout_manager_and__root_and__tooltip_and__widget
  .Widget
  .t
  option = "ml_gtk_search_entry_get_key_capture_widget"
(** Gets the widget that @entry is capturing key events from. *)

external get_input_purpose : t -> Gtk_enums.inputpurpose
  = "ml_gtk_search_entry_get_input_purpose"
(** Gets the input purpose of @entry. *)

external get_input_hints : t -> Gtk_enums.inputhints
  = "ml_gtk_search_entry_get_input_hints"
(** Gets the input purpose for @entry. *)

(* Properties *)

external get_activates_default : t -> bool
  = "ml_gtk_search_entry_get_activates_default"
(** Get property: activates-default *)

external set_activates_default : t -> bool -> unit
  = "ml_gtk_search_entry_set_activates_default"
(** Set property: activates-default *)

let on_activate ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"activate" ~callback
    ~after:(Option.value after ~default:false)

let on_next_match ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"next-match" ~callback
    ~after:(Option.value after ~default:false)

let on_previous_match ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"previous-match" ~callback
    ~after:(Option.value after ~default:false)

let on_search_changed ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"search-changed" ~callback
    ~after:(Option.value after ~default:false)

let on_search_started ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"search-started" ~callback
    ~after:(Option.value after ~default:false)

let on_stop_search ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"stop-search" ~callback
    ~after:(Option.value after ~default:false)
