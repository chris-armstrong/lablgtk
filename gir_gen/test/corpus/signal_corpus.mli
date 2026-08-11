(* Signal corpus: classify every signal in a GIR file and return outcomes.
   Used by regression tests to detect unintended changes in signal
   classification behaviour. *)

type signal_coverage = {
  namespace : string;
  total_signals : int;
  supported : int;
  unsupported : int;
  by_reason : (string * int) list;
}
[@@deriving sexp]

val coverage_of_file : ?reference_files:string list -> string -> signal_coverage

val compare_coverage :
  signal_coverage -> signal_coverage -> (unit, string list) result

val tests : unit Alcotest.test_case list
(** Regression test cases for signal classification and coverage reporting,
    including classification of the real Gtk GIR file and coverage-comparison
    roundtrips. *)
