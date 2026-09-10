(* GENERATED CODE - DO NOT EDIT *)
(* LevelBar: LevelBar *)

type t = [ `level_bar | `widget | `initially_unowned | `object_ ] Gobject.obj

external new_ : unit -> t = "ml_gtk_level_bar_new"
(** Create a new LevelBar *)

external new_for_interval : float -> float -> t
  = "ml_gtk_level_bar_new_for_interval"
(** Create a new LevelBar *)

(* Methods *)

external set_value : t -> float -> unit = "ml_gtk_level_bar_set_value"
(** Sets the value of the `GtkLevelBar`. *)

external set_mode : t -> Gtk_enums.levelbarmode -> unit
  = "ml_gtk_level_bar_set_mode"
(** Sets the `mode` of the `GtkLevelBar`. *)

external set_min_value : t -> float -> unit = "ml_gtk_level_bar_set_min_value"
(** Sets the `min-value` of the `GtkLevelBar`.

    You probably want to update preexisting level offsets after calling this
    function. *)

external set_max_value : t -> float -> unit = "ml_gtk_level_bar_set_max_value"
(** Sets the `max-value` of the `GtkLevelBar`.

    You probably want to update preexisting level offsets after calling this
    function. *)

external set_inverted : t -> bool -> unit = "ml_gtk_level_bar_set_inverted"
(** Sets whether the `GtkLevelBar` is inverted. *)

external remove_offset_value : t -> string option -> unit
  = "ml_gtk_level_bar_remove_offset_value"
(** Removes an offset marker from a `GtkLevelBar`.

    The marker must have been previously added with
    [method@Gtk.LevelBar.add_offset_value]. *)

external get_value : t -> float = "ml_gtk_level_bar_get_value"
(** Returns the `value` of the `GtkLevelBar`. *)

external get_offset_value : t -> string option -> bool * float
  = "ml_gtk_level_bar_get_offset_value"
(** Fetches the value specified for the offset marker @name in @self. *)

external get_mode : t -> Gtk_enums.levelbarmode = "ml_gtk_level_bar_get_mode"
(** Returns the `mode` of the `GtkLevelBar`. *)

external get_min_value : t -> float = "ml_gtk_level_bar_get_min_value"
(** Returns the `min-value` of the `GtkLevelBar`. *)

external get_max_value : t -> float = "ml_gtk_level_bar_get_max_value"
(** Returns the `max-value` of the `GtkLevelBar`. *)

external get_inverted : t -> bool = "ml_gtk_level_bar_get_inverted"
(** Returns whether the levelbar is inverted. *)

external add_offset_value : t -> string -> float -> unit
  = "ml_gtk_level_bar_add_offset_value"
(** Adds a new offset marker on @self at the position specified by @value.

When the bar value is in the interval topped by @value (or between @value
and [property@Gtk.LevelBar:max-value] in case the offset is the last one
on the bar) a style class named `level-`@name will be applied
when rendering the level bar fill.

If another offset marker named @name exists, its value will be
replaced by @value. *)

(* Properties *)

let on_offset_changed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let name =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_string_exn v
        in
        callback ~name)
  in
  Gobject.Signal.connect obj ~name:"offset-changed" ~callback:closure
    ~after:(Option.value after ~default:false)
