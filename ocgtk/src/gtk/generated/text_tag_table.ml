(* GENERATED CODE - DO NOT EDIT *)
(* TextTagTable: TextTagTable *)

type t = [ `text_tag_table | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_text_tag_table_get_type"

external new_ : unit -> t = "ml_gtk_text_tag_table_new"
(** Create a new TextTagTable *)

(* Methods *)

external remove : t -> Text_tag.t -> unit = "ml_gtk_text_tag_table_remove"
(** Remove a tag from the table.

If a `GtkTextBuffer` has @table as its tag table, the tag is
removed from the buffer. The table’s reference to the tag is
removed, so the tag will end up destroyed if you don’t have
a reference to it. *)

external lookup : t -> string -> Text_tag.t option
  = "ml_gtk_text_tag_table_lookup"
(** Look up a named tag. *)

external get_size : t -> int = "ml_gtk_text_tag_table_get_size"
(** Returns the size of the table (number of tags) *)

external add : t -> Text_tag.t -> bool = "ml_gtk_text_tag_table_add"
(** Add a tag to the table.

The tag is assigned the highest priority in the table.

@tag must not be in a tag table already, and may not have
the same name as an already-added tag. *)

let on_tag_added ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let tag =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Text_tag.gtype ())
        in
        callback ~tag)
  in
  Gobject.Signal.connect obj ~name:"tag-added" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_tag_changed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let tag =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Text_tag.gtype ())
        in
        let size_changed =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_boolean v
        in
        callback ~tag ~size_changed)
  in
  Gobject.Signal.connect obj ~name:"tag-changed" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_tag_removed ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let tag =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_object_exn v (Text_tag.gtype ())
        in
        callback ~tag)
  in
  Gobject.Signal.connect obj ~name:"tag-removed" ~callback:closure
    ~after:(Option.value after ~default:false)
