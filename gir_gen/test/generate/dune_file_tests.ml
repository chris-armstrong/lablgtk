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
      (List.init 200 (fun i -> Fmt.str "ml_s%03d_gen" i)
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

(* ---------- rebatch ------------------------------------------------------- *)

(* Emit a minimal inc file with the given names blocks, in the same layout
   the generator uses: "(names" opener, one "   ml_..." line per name, and a
   standalone "  )" terminator. *)
let emit_names_block names =
  let buf = Buffer.create 128 in
  Buffer.add_string buf " (names\n";
  List.iter (fun n -> Buffer.add_string buf ("   " ^ n ^ "\n")) names;
  Buffer.add_string buf "  )\n";
  Buffer.contents buf

(* Extract the name lists of all (names ...) blocks, in file order. *)
let names_blocks content =
  let lines = String.split_on_char '\n' content in
  let rec go acc = function
    | [] -> List.rev acc
    | line :: rest when String.trim line = "(names" ->
        let rec names acc = function
          | [] -> (List.rev acc, [])
          | l :: r ->
              if String.starts_with ~prefix:"   ml_" l then
                names (String.trim l :: acc) r
              else (List.rev acc, l :: r)
        in
        let ns, rest_after = names [] rest in
        go (ns :: acc) rest_after
    | _ :: rest -> go acc rest
  in
  go [] lines

(* A multi-batch stub list: 159 class stubs plus one enums converter. *)
let multi_batch_stub_names () =
  order_stub_names_for_batching
    (List.init 159 (fun i -> Fmt.str "ml_s%03d_gen" i) @ [ "ml_gtk_enums_gen" ])

(* Rebatching a freshly generated inc file must be byte-identical: the
   rebatch path reuses the generator's own ordering and chunking, so its
   output for the same stub list is exactly what gir_gen would emit. *)
let test_rebatch_fresh_output_is_noop () =
  let ctx = Helpers.create_test_context () in
  let stub_names = multi_batch_stub_names () in
  let content =
    generate_dune_library ~ctx ~lib_name:"Gtk" ~stub_names
      ~repository:ctx.repository
  in
  match rebatch_dune_inc content with
  | Error msg -> Alcotest.fail msg
  | Ok out ->
      Alcotest.(check string)
        "rebatching freshly generated output is a no-op" content out

(* A stale layout with the enums converter at the end of the first block
   must be re-laid so the converter lands first in batch_0. *)
let test_rebatch_moves_enums_to_first_batch () =
  let names = List.init 159 (fun i -> Fmt.str "ml_s%03d_gen" i) in
  let block0 = List.take 78 names @ [ "ml_gtk_enums_gen" ] in
  let block1 = List.drop 78 names in
  let content = emit_names_block block0 ^ emit_names_block block1 in
  match rebatch_dune_inc content with
  | Error msg -> Alcotest.fail msg
  | Ok out -> (
      match names_blocks out with
      | first :: _ -> (
          match first with
          | enums :: _ ->
              Alcotest.(check string)
                "enums converter is first in batch_0" "ml_gtk_enums_gen" enums
          | [] -> Alcotest.fail "batch_0 is empty")
      | [] -> Alcotest.fail "no names blocks in output")

let test_rebatch_no_blocks () =
  match rebatch_dune_inc "(library\n (name foo)\n)" with
  | Error msg ->
      Alcotest.(check bool)
        "error mentions missing names blocks" true
        (String.length msg > 0)
  | Ok _ -> Alcotest.fail "expected an error for a file without names blocks"

(* 81 names in a single block would split into two batches, so the rebatch
   must refuse rather than silently change the batch count. *)
let test_rebatch_batch_count_change () =
  let names = List.init 81 (fun i -> Fmt.str "ml_s%03d_gen" i) in
  let content = emit_names_block names in
  match rebatch_dune_inc content with
  | Error msg ->
      Alcotest.(check bool)
        "error mentions batch count change" true
        (String.length msg > 0)
  | Ok _ -> Alcotest.fail "expected an error for a batch count change"

let tests =
  [
    ("enums files move to front", `Quick, test_enums_files_move_to_front);
    ("non-enums stay alphabetical", `Quick, test_non_enums_stay_alphabetical);
    ("no enums files: just sorted", `Quick, test_no_enums_unchanged);
    ( "chunking puts enums in first batch",
      `Quick,
      test_chunking_puts_enums_in_first_batch );
    ( "rebatch of fresh output is a no-op",
      `Quick,
      test_rebatch_fresh_output_is_noop );
    ( "rebatch moves enums converter to first batch",
      `Quick,
      test_rebatch_moves_enums_to_first_batch );
    ( "rebatch rejects files without names blocks",
      `Quick,
      test_rebatch_no_blocks );
    ( "rebatch rejects batch count changes",
      `Quick,
      test_rebatch_batch_count_change );
  ]
