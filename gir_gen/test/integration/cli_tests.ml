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

(* ========================================================================= *)
(* Test Suite *)
(* ========================================================================= *)

let tests = [ Alcotest.test_case "Help output" `Quick test_help_output ]
