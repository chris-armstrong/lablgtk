(** OCaml-configured C compiler discovery.

    Pipeline tests that compile C code must invoke the same C compiler the OCaml
    toolchain was built with, rather than a hard-coded [cc] or [gcc]. This keeps
    tests portable to FreeBSD and macOS where [gcc] may not exist or may be a
    clang shim with different flags.

    See [docs/plans/completed/test-suite-remediation.md] § Phase 1.5 for the
    principle. *)

(* Cache the result so we only shell out once per test run. *)
let cached : string option ref = ref None

let extract_field field text =
  let prefix = field ^ ":" in
  let plen = String.length prefix in
  let lines = String.split_on_char '\n' text in
  List.find_map
    (fun line ->
      if String.length line >= plen && String.sub line 0 plen = prefix then
        Some (String.trim (String.sub line plen (String.length line - plen)))
      else None)
    lines

let read_all ic =
  let buf = Buffer.create 256 in
  (try
     while true do
       Buffer.add_channel buf ic 4096
     done
   with End_of_file -> ());
  Buffer.contents buf

let discover () =
  let ic = Unix.open_process_in "ocamlopt -config 2>/dev/null" in
  let output = read_all ic in
  let _ = Unix.close_process_in ic in
  match extract_field "c_compiler" output with
  | Some compiler -> compiler
  | None ->
      failwith
        "C_compiler.path: could not parse 'c_compiler:' from 'ocamlopt -config'"

let path () =
  match !cached with
  | Some p -> p
  | None ->
      let p = discover () in
      cached := Some p;
      p
