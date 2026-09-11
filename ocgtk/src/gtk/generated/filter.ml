(* GENERATED CODE - DO NOT EDIT *)
(* Filter: Filter *)

type t = [ `filter | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_filter_get_type"

(* Methods *)

external match_ : t -> [ `object_ ] Gobject.obj -> bool = "ml_gtk_filter_match"
(** Checks if the given @item is matched by the filter or not. *)

external get_strictness : t -> Gtk_enums.filtermatch
  = "ml_gtk_filter_get_strictness"
(** Gets the known strictness of a filter.

    If the strictness is not known, [enum@Gtk.FilterMatch.some] is returned.

    This value may change after emission of the [signal@Gtk.Filter::changed]
    signal.

    This function is meant purely for optimization purposes. Filters can choose
    to omit implementing it, but `GtkFilterListModel` uses it. *)

external changed : t -> Gtk_enums.filterchange -> unit = "ml_gtk_filter_changed"
(** Notifies all users of the filter that it has changed.

This emits the [signal@Gtk.Filter::changed] signal. Users
of the filter should then check items again via
[method@Gtk.Filter.match].

Depending on the @change parameter, not all items need to
be changed, but only some. Refer to the [enum@Gtk.FilterChange]
documentation for details.

This function is intended for implementers of `GtkFilter`
subclasses and should not be called from other functions. *)

let on_changed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let change =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gtk_enums.filterchange_of_int (Gobject.Value.get_enum_int v)
        in
        callback ~change)
  in
  Gobject.Signal.connect obj ~name:"changed" ~callback:closure
    ~after:(Option.value after ~default:false)
