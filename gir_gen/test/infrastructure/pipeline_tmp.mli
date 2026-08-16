(** Per-test temp directory for pipeline tests.

    Pipeline tests must use this module rather than [Filename.temp_file] or
    hard-coded [/tmp] paths. *)

val write_file : test_name:string -> filename:string -> string -> string
(** [write_file ~test_name ~filename content] creates
    [pipeline_tmp/<test_name>/] if needed, writes [content] to
    [<dir>/<filename>], and returns the full path. *)
