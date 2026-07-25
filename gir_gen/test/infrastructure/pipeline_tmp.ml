(** Per-test temp directory for pipeline tests.

    Pipeline tests must place all temp files under [pipeline_tmp/<test-name>/]
    rather than [/tmp]. When run via [dune runtest] the working directory is the
    test stanza's run directory under [_build/<context>/], so the
    [pipeline_tmp/] tree lives inside the build tree and is removed by
    [dune clean]. This avoids host pollution and concurrent-run collisions.

    See [docs/plans/completed/test-suite-remediation.md] § Phase 1.5 for the
    principle. *)

let root = "pipeline_tmp"

let mkdir_p path =
  try Unix.mkdir path 0o755 with Unix.Unix_error (Unix.EEXIST, _, _) -> ()

let make_dir test_name =
  mkdir_p root;
  let dir = Filename.concat root test_name in
  mkdir_p dir;
  dir

let write_file ~test_name ~filename content =
  let dir = make_dir test_name in
  let path = Filename.concat dir filename in
  let oc = open_out path in
  output_string oc content;
  close_out oc;
  path
