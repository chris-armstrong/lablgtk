(* GENERATED CODE - DO NOT EDIT *)
(* SectionModel: SectionModel *)

type t = [ `section_model ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_section_model_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gtk_section_model_from_gobject"

(* Methods *)

external sections_changed : t -> int -> int -> unit
  = "ml_gtk_section_model_sections_changed"
(** This function emits the [signal@Gtk.SectionModel::sections-changed] signal
    to notify about changes to sections.

    It must cover all positions that used to be a section start or that are now
    a section start. It does not have to cover all positions for which the
    section has changed.

    The [signal@Gio.ListModel::items-changed] implies the effect of the
    [signal@Gtk.SectionModel::sections-changed] signal for all the items it
    covers.

    It is recommended that when changes to the items cause section changes in a
    larger range, that the larger range is included in the emission of the
    [signal@Gio.ListModel::items-changed] instead of emitting two signals. *)

external get_section : t -> int -> int * int
  = "ml_gtk_section_model_get_section"
(** Query the section that covers the given position. The number of items in the
    section can be computed by `out_end - out_start`.

    If the position is larger than the number of items, a single range from
    n_items to G_MAXUINT will be returned. *)

val on_sections_changed :
  ?after:bool ->
  t ->
  callback:(position:int -> n_items:int -> unit) ->
  Gobject.Signal.handler_id
