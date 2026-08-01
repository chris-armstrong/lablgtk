(* Regression test: recompute signal coverage from live GIR files and compare
   against the checked-in baseline. Any classification change that alters the
   coverage counts will be caught here.

   To update the baseline after a legitimate classification change, run
   [scripts/update-signal-corpus-baseline.sh] from the repo root. *)

let namespace_files =
  [
    ("Gtk", "Gtk-4.0.gir");
    ("Gdk", "Gdk-4.0.gir");
    ("Gio", "Gio-2.0.gir");
    ("Pango", "Pango-1.0.gir");
    ("Gsk", "Gsk-4.0.gir");
    ("GdkPixbuf", "GdkPixbuf-2.0.gir");
    ("Graphene", "Graphene-1.0.gir");
  ]

(* All reference files copied alongside the baseline by the dune rules in
   [gir_gen/test/corpus/dune]. The full list matches what
   [scripts/generate-bindings.sh] feeds the real generator, so coverage is
   computed under the same cross-namespace knowledge as production. *)
let reference_basenames =
  [
    "cairo-references.sexp";
    "gio-references.sexp";
    "gdk-references.sexp";
    "graphene-references.sexp";
    "gdkpixbuf-references.sexp";
    "pango-references.sexp";
    "gsk-references.sexp";
    "pangocairo-references.sexp";
    "gtk-references.sexp";
  ]

let corpus_dir () =
  Filename.concat (Filename.dirname Sys.executable_name) "corpus"

let load_baseline () : Signal_corpus.signal_coverage list =
  let baseline_path =
    Filename.concat (corpus_dir ()) "signal_corpus_baseline.sexp"
  in
  let sexp = Sexplib.Sexp.load_sexp baseline_path in
  Sexplib.Conv.list_of_sexp Signal_corpus.signal_coverage_of_sexp sexp

let reference_files () =
  List.map (Filename.concat (corpus_dir ())) reference_basenames

let compare_namespace baseline_coverages gir_dir reference_files
    (namespace_name, gir_file) =
  let live_cov =
    Signal_corpus.coverage_of_file ~reference_files
      (Filename.concat gir_dir gir_file)
  in
  let baseline_cov =
    List.find_opt
      (fun (cov : Signal_corpus.signal_coverage) ->
        String.equal cov.namespace namespace_name)
      baseline_coverages
  in
  match baseline_cov with
  | None -> [ Fmt.str "%s: no baseline coverage found" namespace_name ]
  | Some baseline_coverage -> (
      match Signal_corpus.compare_coverage baseline_coverage live_cov with
      | Ok () -> []
      | Error reasons ->
          List.map (fun r -> Fmt.str "%s: %s" namespace_name r) reasons)

let compute_live_coverages gir_dir reference_files =
  List.map
    (fun (_, gir_file) ->
      Signal_corpus.coverage_of_file ~reference_files
        (Filename.concat gir_dir gir_file))
    namespace_files

let write_baseline path coverages =
  let sexp =
    Sexplib.Conv.sexp_of_list Signal_corpus.sexp_of_signal_coverage coverages
  in
  let oc = open_out path in
  Fun.protect
    ~finally:(fun () -> close_out oc)
    (fun () ->
      output_string oc (Sexplib.Sexp.to_string_hum sexp);
      output_char oc '\n')

let test_baseline_regression () =
  let gir_dir = Helpers.gir_data_dir () in
  let reference_files = reference_files () in
  match Sys.getenv_opt "SIGNAL_CORPUS_BLESS" with
  | Some bless_path when String.length bless_path > 0 ->
      (* Bless mode: write live coverage to the supplied path and pass. Used
         by scripts/update-signal-corpus-baseline.sh after intentional
         classification changes. *)
      let coverages = compute_live_coverages gir_dir reference_files in
      write_baseline bless_path coverages;
      Fmt.pr "Wrote refreshed signal corpus baseline to %s\n" bless_path
  | _ -> (
      let baseline_coverages = load_baseline () in
      let mismatches =
        List.concat_map
          (compare_namespace baseline_coverages gir_dir reference_files)
          namespace_files
      in
      match mismatches with
      | [] -> ()
      | _ ->
          Alcotest.failf "live coverage differs from baseline:\n%s"
            (String.concat "\n" mismatches))

let tests =
  [
    Alcotest.test_case "live coverage matches baseline for all 7 namespaces"
      `Slow test_baseline_regression;
  ]
