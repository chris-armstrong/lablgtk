(* GENERATED CODE - DO NOT EDIT *)
(* LinkButton: LinkButton *)

type t =
  [ `link_button | `button | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_link_button_get_type"

external new_ : string -> t = "ml_gtk_link_button_new"
(** Create a new LinkButton *)

external new_with_label : string -> string option -> t
  = "ml_gtk_link_button_new_with_label"
(** Create a new LinkButton *)

(* Methods *)

external set_visited : t -> bool -> unit = "ml_gtk_link_button_set_visited"
(** Sets the “visited” state of the `GtkLinkButton`.

    See [method@Gtk.LinkButton.get_visited] for more details. *)

external set_uri : t -> string -> unit = "ml_gtk_link_button_set_uri"
(** Sets @uri as the URI where the `GtkLinkButton` points.

As a side-effect this unsets the “visited” state of the button. *)

external get_visited : t -> bool = "ml_gtk_link_button_get_visited"
(** Retrieves the “visited” state of the `GtkLinkButton`.

    The button becomes visited when it is clicked. If the URI is changed on the
    button, the “visited” state is unset again.

    The state may also be changed using [method@Gtk.LinkButton.set_visited]. *)

external get_uri : t -> string = "ml_gtk_link_button_get_uri"
(** Retrieves the URI of the `GtkLinkButton`. *)

(* Properties *)

val on_activate_link :
  ?after:bool -> t -> callback:(unit -> bool) -> Gobject.Signal.handler_id
