(* GENERATED CODE - DO NOT EDIT *)
(* AppChooserWidget: AppChooserWidget *)

type t =
  [ `app_chooser_widget | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_app_chooser_widget_get_type"

external new_ : string -> t = "ml_gtk_app_chooser_widget_new"
(** Create a new AppChooserWidget *)

(* Methods *)

external set_show_recommended : t -> bool -> unit
  = "ml_gtk_app_chooser_widget_set_show_recommended"
(** Sets whether the app chooser should show recommended applications for the
    content type in a separate section. *)

external set_show_other : t -> bool -> unit
  = "ml_gtk_app_chooser_widget_set_show_other"
(** Sets whether the app chooser should show applications which are unrelated to
    the content type. *)

external set_show_fallback : t -> bool -> unit
  = "ml_gtk_app_chooser_widget_set_show_fallback"
(** Sets whether the app chooser should show related applications for the
    content type in a separate section. *)

external set_show_default : t -> bool -> unit
  = "ml_gtk_app_chooser_widget_set_show_default"
(** Sets whether the app chooser should show the default handler for the content
    type in a separate section. *)

external set_show_all : t -> bool -> unit
  = "ml_gtk_app_chooser_widget_set_show_all"
(** Sets whether the app chooser should show all applications in a flat list. *)

external set_default_text : t -> string -> unit
  = "ml_gtk_app_chooser_widget_set_default_text"
(** Sets the text that is shown if there are not applications that can handle
    the content type. *)

external get_show_recommended : t -> bool
  = "ml_gtk_app_chooser_widget_get_show_recommended"
(** Gets whether the app chooser should show recommended applications for the
    content type in a separate section. *)

external get_show_other : t -> bool = "ml_gtk_app_chooser_widget_get_show_other"
(** Gets whether the app chooser should show applications which are unrelated to
    the content type. *)

external get_show_fallback : t -> bool
  = "ml_gtk_app_chooser_widget_get_show_fallback"
(** Gets whether the app chooser should show related applications for the
    content type in a separate section. *)

external get_show_default : t -> bool
  = "ml_gtk_app_chooser_widget_get_show_default"
(** Gets whether the app chooser should show the default handler for the content
    type in a separate section. *)

external get_show_all : t -> bool = "ml_gtk_app_chooser_widget_get_show_all"
(** Gets whether the app chooser should show all applications in a flat list. *)

external get_default_text : t -> string option
  = "ml_gtk_app_chooser_widget_get_default_text"
(** Returns the text that is shown if there are not applications that can handle
    the content type. *)

(* Properties *)

let on_application_activated ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let application =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (Ocgtk_gio.Gio.Wrappers.App_info.gtype ())
        in
        callback ~application)
  in
  Gobject.Signal.connect obj ~name:"application-activated" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_application_selected ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let application =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v
            (Ocgtk_gio.Gio.Wrappers.App_info.gtype ())
        in
        callback ~application)
  in
  Gobject.Signal.connect obj ~name:"application-selected" ~callback:closure
    ~after:(Option.value after ~default:false)
