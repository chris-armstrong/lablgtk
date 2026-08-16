(* Shared fixtures for override pipeline tests *)

val write_synthetic_gir : test_name:string -> string
(** [write_synthetic_gir ~test_name] writes the synthetic Gtk GIR fixture to
    [pipeline_tmp/<test_name>/synthetic.gir] and returns its path. *)
