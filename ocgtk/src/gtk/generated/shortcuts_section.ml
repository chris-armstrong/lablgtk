(* GENERATED CODE - DO NOT EDIT *)
(* ShortcutsSection: ShortcutsSection *)

type t =
  [ `shortcuts_section | `box | `widget | `initially_unowned | `object_ ]
  Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_shortcuts_section_get_type"

(* Methods *)

external add_group : t -> Shortcuts_group.t -> unit
  = "ml_gtk_shortcuts_section_add_group"
(** Adds a group to the shortcuts section.

    This is the programmatic equivalent to using [class@Gtk.Builder] and a
    `<child>` tag to add the child.

    Adding children with the `GtkBox` API is not appropriate, as
    `GtkShortcutsSection` manages its children internally. *)

(* Properties *)

external get_max_height : t -> int = "ml_gtk_shortcuts_section_get_max_height"
(** Get property: max-height *)

external set_max_height : t -> int -> unit
  = "ml_gtk_shortcuts_section_set_max_height"
(** Set property: max-height *)

external get_section_name : t -> string
  = "ml_gtk_shortcuts_section_get_section_name"
(** Get property: section-name *)

external set_section_name : t -> string -> unit
  = "ml_gtk_shortcuts_section_set_section_name"
(** Set property: section-name *)

external get_title : t -> string = "ml_gtk_shortcuts_section_get_title"
(** Get property: title *)

external set_title : t -> string -> unit = "ml_gtk_shortcuts_section_set_title"
(** Set property: title *)

external get_view_name : t -> string = "ml_gtk_shortcuts_section_get_view_name"
(** Get property: view-name *)

external set_view_name : t -> string -> unit
  = "ml_gtk_shortcuts_section_set_view_name"
(** Set property: view-name *)

let on_change_current_page ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let offset =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_int v
        in
        let result = callback ~offset in
        let v = Gobject.Closure.result argv in
        let x = result in
        Gobject.Value.set_boolean v x)
  in
  Gobject.Signal.connect obj ~name:"change-current-page" ~callback:closure
    ~after:(Option.value after ~default:false)
