(* Signal corpus: classify every signal in a GIR file and return outcomes.
   Used by regression tests to detect unintended changes in signal
   classification behaviour. *)

type signal_coverage = {
  namespace : string;  (** Namespace name, e.g. ["Gtk"]. *)
  total_signals : int;  (** Total number of signals in the namespace. *)
  supported : int;  (** Number of signals ocgtk can bind. *)
  unsupported : int;  (** Number of signals ocgtk cannot bind. *)
  by_reason : (string * int) list;
      (** Unsupported-signal counts keyed by reason string. *)
}
[@@deriving sexp]

val coverage_of_file : ?reference_files:string list -> string -> signal_coverage

val compare_coverage :
  signal_coverage -> signal_coverage -> (unit, string list) result

val tests : unit Alcotest.test_case list
(** Regression test cases for signal classification and coverage reporting,
    including classification of the real Gtk GIR file and coverage-comparison
    roundtrips. *)
