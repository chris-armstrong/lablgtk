(* GENERATED CODE - DO NOT EDIT *)
(* MediaControls: MediaControls *)

type t =
  [ `media_controls | `widget | `initially_unowned | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_media_controls_get_type"

external new_ : Media_stream.t option -> t = "ml_gtk_media_controls_new"
(** Create a new MediaControls *)

(* Methods *)

external set_media_stream : t -> Media_stream.t option -> unit
  = "ml_gtk_media_controls_set_media_stream"
(** Sets the stream that is controlled by @controls. *)

external get_media_stream : t -> Media_stream.t option
  = "ml_gtk_media_controls_get_media_stream"
(** Gets the media stream managed by @controls or %NULL if none. *)

(* Properties *)
