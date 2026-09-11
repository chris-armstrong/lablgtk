(* GENERATED CODE - DO NOT EDIT *)
(* SymbolicPaintable: SymbolicPaintable *)

type t = [ `symbolic_paintable ] Gobject.obj

external gtype : unit -> Gobject.Type.t = "ml_gtk_symbolic_paintable_get_type"

external from_gobject : 'a Gobject.obj -> t
  = "ml_gtk_symbolic_paintable_from_gobject"

(* Methods *)

external snapshot_symbolic :
  t ->
  Ocgtk_gdk.Gdk.Wrappers.Snapshot.t ->
  float ->
  float ->
  Ocgtk_gdk.Gdk.Wrappers.Rgb_a.t array ->
  Gsize.t ->
  unit
  = "ml_gtk_symbolic_paintable_snapshot_symbolic_bytecode"
    "ml_gtk_symbolic_paintable_snapshot_symbolic_native"
(** Snapshots the paintable with the given colors.

    If less than 4 colors are provided, GTK will pad the array with default
    colors. *)
