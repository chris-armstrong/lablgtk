(* GENERATED CODE - DO NOT EDIT *)
(* ScriptIter: ScriptIter *)

type t = [ `script_iter ] Gobject.obj
(** A `PangoScriptIter` is used to iterate through a string and identify ranges
    in different scripts. *)

external gtype : unit -> Gobject.Type.t = "ml_pango_script_iter_get_type"

external new_ : string -> int -> t = "ml_pango_script_iter_new"
(** Create a new ScriptIter *)

(* Methods *)

external next : t -> bool = "ml_pango_script_iter_next"
(** Advances a `PangoScriptIter` to the next range.

If @iter is already at the end, it is left unchanged
and %FALSE is returned. *)
