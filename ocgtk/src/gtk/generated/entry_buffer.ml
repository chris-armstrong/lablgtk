(* GENERATED CODE - DO NOT EDIT *)
(* EntryBuffer: EntryBuffer *)

type t = [ `entry_buffer | `object_ ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_entry_buffer_get_type"

external new_ : string option -> int -> t = "ml_gtk_entry_buffer_new"
(** Create a new EntryBuffer *)

(* Methods *)

external set_text : t -> string -> int -> unit = "ml_gtk_entry_buffer_set_text"
(** Sets the text in the buffer.

This is roughly equivalent to calling
[method@Gtk.EntryBuffer.delete_text] and
[method@Gtk.EntryBuffer.insert_text].

Note that @n_chars is in characters, not in bytes. *)

external set_max_length : t -> int -> unit
  = "ml_gtk_entry_buffer_set_max_length"
(** Sets the maximum allowed length of the contents of the buffer.

    If the current contents are longer than the given length, then they will be
    truncated to fit. *)

external insert_text : t -> int -> string -> int -> int
  = "ml_gtk_entry_buffer_insert_text"
(** Inserts @n_chars characters of @chars into the contents of the
buffer, at position @position.

If @n_chars is negative, then characters from chars will be inserted
until a null-terminator is found. If @position or @n_chars are out of
bounds, or the maximum buffer text length is exceeded, then they are
coerced to sane values.

Note that the position and length are in characters, not in bytes. *)

external get_text : t -> string = "ml_gtk_entry_buffer_get_text"
(** Retrieves the contents of the buffer.

    The memory pointer returned by this call will not change unless this object
    emits a signal, or is finalized. *)

external get_max_length : t -> int = "ml_gtk_entry_buffer_get_max_length"
(** Retrieves the maximum allowed length of the text in @buffer. *)

external get_length : t -> int = "ml_gtk_entry_buffer_get_length"
(** Retrieves the length in characters of the buffer. *)

external get_bytes : t -> Gsize.t = "ml_gtk_entry_buffer_get_bytes"
(** Retrieves the length in bytes of the buffer.

    See [method@Gtk.EntryBuffer.get_length]. *)

external emit_inserted_text : t -> int -> string -> int -> unit
  = "ml_gtk_entry_buffer_emit_inserted_text"
(** Used when subclassing `GtkEntryBuffer`. *)

external emit_deleted_text : t -> int -> int -> unit
  = "ml_gtk_entry_buffer_emit_deleted_text"
(** Used when subclassing `GtkEntryBuffer`. *)

external delete_text : t -> int -> int -> int
  = "ml_gtk_entry_buffer_delete_text"
(** Deletes a sequence of characters from the buffer.

@n_chars characters are deleted starting at @position.
If @n_chars is negative, then all characters until the
end of the text are deleted.

If @position or @n_chars are out of bounds, then they
are coerced to sane values.

Note that the positions are specified in characters,
not bytes. *)

(* Properties *)

let on_deleted_text ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let position =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_uint v
        in
        let n_chars =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_uint v
        in
        callback ~position ~n_chars)
  in
  Gobject.Signal.connect obj ~name:"deleted-text" ~callback:closure
    ~after:(Option.value after ~default:false)

let on_inserted_text ?after obj ~callback =
  let closure =
    Gobject.Closure.create (fun argv ->
        let position =
          let v = Gobject.Closure.nth argv ~pos:1 in
          Gobject.Value.get_uint v
        in
        let chars =
          let v = Gobject.Closure.nth argv ~pos:2 in
          Gobject.Value.get_string v
        in
        let n_chars =
          let v = Gobject.Closure.nth argv ~pos:3 in
          Gobject.Value.get_uint v
        in
        callback ~position ~chars ~n_chars)
  in
  Gobject.Signal.connect obj ~name:"inserted-text" ~callback:closure
    ~after:(Option.value after ~default:false)
