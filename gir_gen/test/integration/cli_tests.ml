(* CLI interface tests *)

open Helpers

(* ========================================================================= *)
(* Test Cases *)
(* ========================================================================= *)

(* Use --help=plain to force cmdliner's plain renderer. The default
   `auto` format may emit ANSI escape sequences (bold/underline) around
   identifiers when stdout isn't a TTY but TERM is set — on macOS/opam-ci
   this wrapping has broken substring matches for `--filter` in the past. *)
let test_help_output () =
  let tools_dir = get_tools_dir () in
  let cmd = Fmt.str "%s/bin/gir_gen.exe generate --help=plain 2>&1" tools_dir in
  let ic = Unix.open_process_in cmd in
  let output = Buffer.create 1024 in
  (try
     while true do
       Buffer.add_string output (input_line ic);
       Buffer.add_char output '\n'
     done
   with End_of_file -> ());
  let _ = Unix.close_process_in ic in
  let help_text = Buffer.contents output in
  let text_has s =
    let hl = String.length help_text and nl = String.length s in
    try
      for i = 0 to hl - nl do
        if String.sub help_text i nl = s then raise Exit
      done;
      false
    with Exit -> true
  in
  assert_true "Help should mention filter option" (text_has "--filter");
  assert_true "Help should mention GIR_FILE argument" (text_has "GIR_FILE");
  assert_true "Help should show examples" (text_has "EXAMPLES")

(* Run gir_gen rebatch on a temp inc file with a stale batch layout and
   check it re-lays the batches in place. *)
let test_rebatch_command () =
  let tools_dir = get_tools_dir () in
  let tmp_dir = Filename.temp_file "rebatch_test" "" in
  Unix.unlink tmp_dir;
  Unix.mkdir tmp_dir 0o755;
  let inc_path = Filename.concat tmp_dir "dune-generated.inc" in
  (* Stale layout: enums converter at the end of the first block. *)
  let names = List.init 159 (fun i -> Fmt.str "ml_s%03d_gen" i) in
  let block0 = List.take 78 names @ [ "ml_gtk_enums_gen" ] in
  let block1 = List.drop 78 names in
  let emit_block names =
    let buf = Buffer.create 128 in
    Buffer.add_string buf " (names\n";
    List.iter (fun n -> Buffer.add_string buf ("   " ^ n ^ "\n")) names;
    Buffer.add_string buf "  )\n";
    Buffer.contents buf
  in
  let oc = open_out inc_path in
  output_string oc (emit_block block0 ^ emit_block block1);
  close_out oc;
  let cmd = Fmt.str "%s/bin/gir_gen.exe rebatch %s" tools_dir inc_path in
  let result = run_command_with_output cmd in
  assert_true "rebatch should succeed" (result.exit_code = 0);
  let out = read_file inc_path in
  (* The enums converter must now be the first name in batch_0. *)
  let first_name_line =
    match String.split_on_char '\n' out with
    | _ :: rest -> (
        match List.find_opt (String.starts_with ~prefix:"   ml_") rest with
        | Some l -> l
        | None -> "")
    | [] -> ""
  in
  assert_true "enums converter first in batch_0"
    (String.equal first_name_line "   ml_gtk_enums_gen");
  Unix.unlink inc_path;
  Unix.rmdir tmp_dir

(* ========================================================================= *)
(* Test Suite *)
(* ========================================================================= *)

let tests =
  [
    Alcotest.test_case "Help output" `Quick test_help_output;
    Alcotest.test_case "Rebatch command" `Quick test_rebatch_command;
  ]
