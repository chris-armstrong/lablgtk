(* Rebatch the generated C stubs inside an existing dune-generated.inc.

    The inc file is a gir_gen artifact: the stub names are listed in batches
    of at most [Dune_file.stub_batch_size]. When the batch ordering rule
    changes (see Dune_file.order_stub_names_for_batching), the inc files can
    be relaid out without regenerating every binding, because the batch
    composition is fully determined by the stub name list, which is itself
    unchanged. This tool reuses the generator's own ordering and chunking
    functions, so its output is byte-identical to what gir_gen would emit
    for the same inputs.

    Usage: regen_stub_batches.exe <dune-generated.inc> [<inc> ...] *)

open Printf

(* A names block inside a batch stanza: lines strictly between "(names" and
   the closing paren (which terminates the last name line). *)
let name_line_re = Str.regexp "^   ml_[a-z0-9_]+_gen)?$"
let is_name_line line = Str.string_match name_line_re line 0

(* [split_names_block lines] expects [lines] to start right after the
   "(names" opener; returns (names, rest_after_block). *)
let rec split_names_block lines acc =
  match lines with
  | [] -> (List.rev acc, [])
  | line :: rest ->
      let trimmed = String.trim line in
      if is_name_line line then
        let name =
          if String.ends_with ~suffix:")" trimmed then
            String.sub trimmed 0 (String.length trimmed - 1)
          else trimmed
        in
        split_names_block rest (name :: acc)
      else (List.rev acc, lines)

let rewrite_inc ~path =
  let content =
    match In_channel.with_open_bin path In_channel.input_all with
    | c -> c
    | exception Sys_error msg ->
        eprintf "regen_stub_batches: %s\n%!" msg;
        exit 1
  in
  let lines = String.split_on_char '\n' content in
  (* Walk the file, collecting every batch stanza's names block. *)
  let rec collect ~in_names ~acc_blocks acc_lines = function
    | [] -> (List.rev acc_lines, List.rev acc_blocks)
    | line :: rest when String.trim line = "(names" ->
        let names, rest_after = split_names_block rest [] in
        collect ~in_names:false
          ~acc_blocks:((List.rev acc_lines, names) :: acc_blocks)
          [] rest_after
    | line :: rest -> collect ~in_names ~acc_blocks (line :: acc_lines) rest
  in
  let _, blocks = collect ~in_names:false ~acc_blocks:[] [] lines in
  if List.is_empty blocks then (
    eprintf "regen_stub_batches: %s: no (names ...) blocks found\n%!" path;
    exit 1);
  (* The concatenated names of all blocks in file order reconstruct the full
     stub list the generator was given. *)
  let all_names = List.concat_map (fun (_, names) -> names) blocks in
  let ordered =
    Gir_gen_lib.Generate.Dune_file.order_stub_names_for_batching all_names
  in
  let batches =
    Gir_gen_lib.Generate.Dune_file.list_chunks
      Gir_gen_lib.Generate.Dune_file.stub_batch_size ordered
  in
  let old_batches = List.map (fun (_, names) -> names) blocks |> List.length in
  if not (Int.equal old_batches (List.length batches)) then (
    eprintf
      "regen_stub_batches: %s: batch count would change (%d -> %d), refusing\n\
       %!"
      path old_batches (List.length batches);
    exit 1);
  (* Re-emit: same stanzas, new name lists. Each names block is closed by
     a standalone ")" line that sits outside the name lines, so the block's
     terminator is preserved simply by continuing after the moved names. *)
  let buf = Buffer.create (String.length content) in
  let batches = Array.of_list batches in
  let block_i = ref 0 in
  let emit_names names =
    List.iter
      (fun name ->
        Buffer.add_string buf "   ";
        Buffer.add_string buf name;
        Buffer.add_char buf '\n')
      names
  in
  let rec go = function
    | [] -> ()
    | line :: rest when String.trim line = "(names" ->
        let _, rest_after = split_names_block rest [] in
        Buffer.add_string buf line;
        Buffer.add_char buf '\n';
        emit_names (Array.get batches !block_i);
        incr block_i;
        go rest_after
    | line :: rest ->
        Buffer.add_string buf line;
        Buffer.add_char buf '\n';
        go rest
  in
  (* [String.split_on_char] leaves a trailing empty element when the file
     ends with a newline; re-add the terminator when emitting instead. *)
  let terminated = String.ends_with ~suffix:"\n" content in
  let lines =
    if terminated then
      match List.rev lines with
      | "" :: rev_rest -> List.rev rev_rest
      | _ -> lines
    else lines
  in
  go lines;
  let out = Buffer.contents buf in
  if String.equal out content then printf "%s: already up to date\n" path
  else begin
    Out_channel.with_open_bin path (fun oc -> Out_channel.output_string oc out);
    printf "%s: rebatched\n" path
  end

let () =
  match Array.to_list Sys.argv with
  | [] | [ _ ] ->
      eprintf "usage: regen_stub_batches.exe <dune-generated.inc> [...]\n%!";
      exit 2
  | _ :: paths -> List.iter (fun path -> rewrite_inc ~path) paths
