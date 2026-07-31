(* Signal corpus: classify every signal in a GIR file and return outcomes.
   Used by regression tests to detect unintended changes in signal
   classification behaviour. *)

type classification_outcome =
  | Supported of { class_or_iface : string; signal_name : string }
  | Unsupported of {
      class_or_iface : string;
      signal_name : string;
      reason : string;
    }

type signal_coverage = {
  namespace : string;
  total_signals : int;
  supported : int;
  unsupported : int;
  by_reason : (string * int) list;
}
[@@deriving sexp]

val load_reference_files :
  string list ->
  Gir_gen_lib.Types.generation_context_namespace_cross_references
  Gir_gen_lib.Types.StringMap.t
(** Parse a list of [*-references.sexp] files (produced by [gir_gen references])
    into the [cross_references] map shape consumed by [generation_context]. *)

val classify_signals_of_file :
  ?reference_files:string list -> string -> classification_outcome list
(** [reference_files] supplies cross-namespace knowledge so types from other
    namespaces classify accurately. When empty (the default), cross-namespace
    types fall off to [Tk_Unknown] — keep the empty form only for synthetic
    single-namespace unit tests. *)

val coverage_of_namespace :
  string -> classification_outcome list -> signal_coverage

val coverage_of_file : ?reference_files:string list -> string -> signal_coverage

val compare_coverage :
  signal_coverage -> signal_coverage -> (unit, string list) result

val count_supported : classification_outcome list -> int
val tests : unit Alcotest.test_case list
