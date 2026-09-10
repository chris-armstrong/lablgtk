(* GENERATED CODE - DO NOT EDIT *)
(* FileChooserWidget: FileChooserWidget *)

type t =
  [ `file_chooser_widget | `widget | `initially_unowned | `object_ ] Gobject.obj

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

let on_desktop_folder ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"desktop-folder" ~callback
    ~after:(Option.value after ~default:false)

let on_down_folder ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"down-folder" ~callback
    ~after:(Option.value after ~default:false)

let on_home_folder ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"home-folder" ~callback
    ~after:(Option.value after ~default:false)

let on_location_popup ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let path =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_string_exn v
        in
        callback ~path)
  in
  Gobject.Signal.connect obj ~name:"location-popup" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_location_popup_on_paste ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"location-popup-on-paste" ~callback
    ~after:(Option.value after ~default:false)

let on_location_toggle_popup ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"location-toggle-popup" ~callback
    ~after:(Option.value after ~default:false)

let on_places_shortcut ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"places-shortcut" ~callback
    ~after:(Option.value after ~default:false)

let on_quick_bookmark ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let bookmark_index =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_int v
        in
        callback ~bookmark_index)
  in
  Gobject.Signal.connect obj ~name:"quick-bookmark" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_recent_shortcut ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"recent-shortcut" ~callback
    ~after:(Option.value after ~default:false)

let on_search_shortcut ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"search-shortcut" ~callback
    ~after:(Option.value after ~default:false)

let on_show_hidden ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"show-hidden" ~callback
    ~after:(Option.value after ~default:false)

let on_up_folder ?after obj ~callback =
  Gobject.Signal.connect_simple obj ~name:"up-folder" ~callback
    ~after:(Option.value after ~default:false)
