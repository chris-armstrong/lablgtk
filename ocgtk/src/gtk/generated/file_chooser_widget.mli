(* GENERATED CODE - DO NOT EDIT *)
(* FileChooserWidget: FileChooserWidget *)

type t =
  [ `file_chooser_widget | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_file_chooser_widget_get_type"

external new_ : Gtk_enums.filechooseraction -> t
  = "ml_gtk_file_chooser_widget_new"
(** Create a new FileChooserWidget *)

(* Methods *)
(* Properties *)

external get_search_mode : t -> bool
  = "ml_gtk_file_chooser_widget_get_search_mode"
(** Get property: search-mode *)

external set_search_mode : t -> bool -> unit
  = "ml_gtk_file_chooser_widget_set_search_mode"
(** Set property: search-mode *)

external get_show_time : t -> bool = "ml_gtk_file_chooser_widget_get_show_time"
(** Get property: show-time *)

external get_subtitle : t -> string = "ml_gtk_file_chooser_widget_get_subtitle"
(** Get property: subtitle *)

val on_desktop_folder :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_down_folder :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_home_folder :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_location_popup :
  ?after:bool ->
  t ->
  callback:(path:string -> unit) ->
  Gobject.Signal.handler_id

val on_location_popup_on_paste :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_location_toggle_popup :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_places_shortcut :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_quick_bookmark :
  ?after:bool ->
  t ->
  callback:(bookmark_index:int -> unit) ->
  Gobject.Signal.handler_id

val on_recent_shortcut :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_search_shortcut :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_show_hidden :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id

val on_up_folder :
  ?after:bool -> t -> callback:(unit -> unit) -> Gobject.Signal.handler_id
