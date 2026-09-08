(* Unit tests for Dune_file — stub-batch layout.

    The generated C stubs are split into batch libraries because of the
    Windows command-line length limit. OCaml's native linker emits the -cclib
    archive flags in the reverse of the order the libraries are listed, so the
    first-listed batch (batch_0) is scanned *last* by ld. Batch_0 must
    therefore hold the leaf converter files (ml_<ns>_enums_gen) that every
    class stub file depends on: with alphabetical chunking they land mid
    sequence, and any executable that pulls only batch_0 class stubs (e.g. a
    test using Button/Box but no Widget/Window) fails to link because the
    enums archive was scanned before anything referenced it.

    These tests pin the ordering invariant: enums converters first, everything
    else alphabetical, chunking stable. *)

open Gir_gen_lib.Generate.Dune_file

let check_string_list msg expected actual =
  Alcotest.(check (list string)) msg expected actual

(* ---------- ordering ---------------------------------------------------- *)

let test_enums_files_move_to_front () =
  check_string_list "enums converter files are listed first"
    [ "ml_gdk_enums_gen"; "ml_gtk_enums_gen"; "ml_box_gen"; "ml_button_gen" ]
    (order_stub_names_for_batching
       ([ "ml_box_gen"; "ml_gtk_enums_gen"; "ml_button_gen" ]
       @ [ "ml_gdk_enums_gen" ]))

let test_non_enums_stay_alphabetical () =
  check_string_list "non-enums files remain sorted"
    [ "ml_gtk_enums_gen"; "ml_aaa_gen"; "ml_bbb_gen"; "ml_zzz_gen" ]
    (order_stub_names_for_batching
       [ "ml_zzz_gen"; "ml_bbb_gen"; "ml_aaa_gen"; "ml_gtk_enums_gen" ])

let test_no_enums_unchanged () =
  check_string_list "without enums files the list is just sorted"
    [ "ml_aaa_gen"; "ml_bbb_gen" ]
    (order_stub_names_for_batching [ "ml_bbb_gen"; "ml_aaa_gen" ])

(* ---------- chunking invariant ------------------------------------------- *)

(* Every enums converter must land in the first chunk: batch_0 is the
   last-scanned archive at link time, so converters placed anywhere else can
   leave dangling references from later-scanned batches. *)
let test_chunking_puts_enums_in_first_batch () =
  let names =
    order_stub_names_for_batching
      (List.init 200 (fun i -> Printf.sprintf "ml_s%03d_gen" i)
      @ [ "ml_gtk_enums_gen" ])
  in
  let contains_enums batch =
    List.exists (String.equal "ml_gtk_enums_gen") batch
  in
  match list_chunks stub_batch_size names with
  | [] -> Alcotest.fail "no batches produced"
  | first :: rest ->
      Alcotest.(check bool)
        "enums converter is in batch_0" true (contains_enums first);
      Alcotest.(check bool)
        "enums converter only in batch_0" false
        (List.exists contains_enums rest)

let tests =
  [
    ("enums files move to front", `Quick, test_enums_files_move_to_front);
    ("non-enums stay alphabetical", `Quick, test_non_enums_stay_alphabetical);
    ("no enums files: just sorted", `Quick, test_no_enums_unchanged);
    ( "chunking puts enums in first batch",
      `Quick,
      test_chunking_puts_enums_in_first_batch );
  ]
