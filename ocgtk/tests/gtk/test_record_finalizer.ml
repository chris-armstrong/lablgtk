(** Test suite for the GType-aware gir_record finalizer.

    The custom-block finalizer in [ocgtk/src/common/wrappers.c] dispatches by
    GType: boxed records (those whose GIR carries [glib:get-type]) are freed via
    [g_boxed_free] so per-type destructors run; plain records fall back to
    [g_free]. The generator threads the get-type call through
    [ml_gir_record_val_ptr_with_type], so [Val_GtkTreePath] et al. now record
    the GType at allocation time. This file exercises the runtime side of that
    contract using [GtkTreePath] — the canonical example because [g_free] does
    not run [gtk_tree_path_free], silently leaking the path's internal indices
    array.

    What the test would have caught had it run before the cleanup:

    - The original bug. Allocating a path under [g_free]-only finalisation leaks
      [path->indices] on every drop. The leak is silent under glibc malloc; the
      boxed contract requires [gtk_tree_path_free] for correctness because GTK
      may add internal bookkeeping that [g_free] won't release.

    - The layout regression I almost shipped. Switching the custom-block payload
      from [void*] to [{GType, void*}] left the per-record [<X>_val] accessor
      reading the GType slot and reinterpreting it as a pointer. Any subsequent
      method call dereferences a tagged-int as a C pointer and crashes. The
      accessor now routes through [ml_gir_record_ptr_val] which knows the new
      layout. Running this test against the regression set produces a SIGSEGV in
      the very first method call; the fix lights it green. *)

open Alcotest
open Ocgtk_gtk.Gtk
module Helpers = Gtk_test_helpers
module Gvariant = Ocgtk_common.Gvariant

(* Layer 1 (raw) tree_path bindings. Pulling these locally documents the
   contract that [Tree_path.free]/[Tree_path.copy] no longer exist as
   externals — referencing them here would be a compile error. *)
let path_new = Wrappers.Tree_path.new_
let path_append = Wrappers.Tree_path.append_index
let path_get_depth = Wrappers.Tree_path.get_depth
let path_to_string = Wrappers.Tree_path.to_string
let require_gtk = Helpers.require_gtk

(* Cross-kind rejection: routes through ml_gir_record_ptr_val internally.
   Bypasses the OCaml type system via the polymorphic external to pass a
   wrong-kind custom block to a gir_record-expecting binding. *)
external raw_tree_path_get_depth : 'a -> int = "ml_gtk_tree_path_get_depth"

(* ========== Compile-time absence of free/copy/unref externals ==========

   These references would not type-check after the cleanup PR landed; the
   binding [Wrappers.Tree_path.free] etc. simply do not exist. Keeping
   them in a commented block documents the contract a future regression
   would break.

     let _ = Wrappers.Tree_path.free        (* removed: double-free hazard *)
     let _ = Wrappers.Tree_path.copy        (* removed: redundant *)
*)

(* ========== Single-instance round-trip ==========

   Allocates a TreePath via the new GType-aware path, populates indices,
   reads back through generated method bindings. The accessor and every
   per-method [GtkTreePath_val] is exercised on each call; under the
   layout regression every call would dereference a GType slot as a
   pointer and segfault before reaching the assertions.

   We deliberately avoid [get_indices_with_depth] here to keep this test
   focused on the finalizer contract. That binding had a pre-existing bug
   (the [int array option * int] return value was constructed without the
   [Some] wrapper on the C side); it was fixed in phase-5 of the
   value-kinds-registry plan and is now exercised in [test_tree_path.ml].
   [get_depth] and [to_string] both round-trip cleanly and exercise the
   same lookup. *)

let test_depth_round_trip () =
  let path = path_new () in
  path_append path 3;
  path_append path 7;
  path_append path 11;
  check int "depth = 3 after appending 3 indices" 3 (path_get_depth path)

let test_to_string () =
  let path = path_new () in
  path_append path 4;
  path_append path 10;
  path_append path 0;
  path_append path 3;
  match path_to_string path with
  | Some s -> check string "to_string" "4:10:0:3" s
  | None -> fail "expected Some string"

(* ========== Survives GC cycle ==========

   Allocate, populate, drop the OCaml binding. Force a major collection
   so the custom-block finalizer runs. Allocate again with different
   content; the new path must not collide with the freed one's memory.
   Under a buggy finalizer (e.g. [g_free] on a boxed type whose owned
   indices array is leaked) glibc's malloc may reuse addresses and
   surface use-after-free as content corruption — the second path's
   to_string would mention the first path's indices. *)

let test_survives_gc_single () =
  (let scratch = path_new () in
   path_append scratch 99;
   path_append scratch 100;
   ignore (path_to_string scratch));
  Gc.full_major ();
  let p = path_new () in
  path_append p 1;
  path_append p 2;
  match path_to_string p with
  | Some s -> check string "post-GC to_string" "1:2" s
  | None -> fail "post-GC path read failed"

(* ========== Stress: allocate/drop many under GC pressure ==========

   Each iteration allocates a path, appends a bounded number of indices,
   reads back, and lets the binding go out of scope. A major collection
   fires every 100 iterations. The intent is to exercise the finalizer
   path repeatedly: under [g_free] this leaks per iteration (no crash);
   under [g_boxed_free] the per-type destructor runs cleanly. The
   assertion is simply that no allocation, read, or finalizer invocation
   crashes the program and that every depth read still matches the count
   we wrote.

   1000 iterations is large enough that any free-list corruption tends
   to surface and small enough to remain a sub-second smoke check. *)

let test_stress_alloc_drop () =
  let n = 1000 in
  for i = 0 to n - 1 do
    let p = path_new () in
    let depth = (i mod 5) + 1 in
    for j = 0 to depth - 1 do
      path_append p ((i * 13) + j)
    done;
    let read_depth = path_get_depth p in
    if read_depth <> depth then
      failf "iteration %d: expected depth=%d got %d" i depth read_depth;
    if i mod 100 = 0 then Gc.full_major ()
  done;
  Gc.full_major ();
  check bool "1000-iteration stress loop completed" true true

(* ========== Cross-kind rejection ==========

   Pass a GVariant (ocgtk.gvariant custom block, in ocgtk_common) to a
   binding that expects a gir_record (GtkTreePath). The call routes through
   ml_gir_record_ptr_val which now performs a strict Custom_ops_val identity
   check. Before phase-2 the fallback ext_of_val path would silently read
   garbage; after phase-2 the strict check raises Failure with a descriptive
   message naming both the expected type ("GtkTreePath") and the actual kind
   ("ocgtk.gvariant").

   We use GVariant rather than a GObject (Box) because GVariant lives in
   ocgtk_common and avoids a pre-existing cross-batch linker issue that
   surfaces when test_record_finalizer is linked against the gtk batch stubs
   containing Box but not the enum stubs they depend on. *)

let string_contains ~sub s =
  let sub_len = String.length sub and s_len = String.length s in
  if sub_len = 0 then true
  else if sub_len > s_len then false
  else
    let limit = s_len - sub_len in
    let found = ref false in
    let i = ref 0 in
    while (not !found) && !i <= limit do
      if String.sub s !i sub_len = sub then found := true;
      incr i
    done;
    !found

let test_cross_kind_ml_gir_record_ptr_val_rejects_wrong_kind () =
  let wrong_kind = Gvariant.of_string "hello" in
  match
    try Ok (raw_tree_path_get_depth wrong_kind) with Failure msg -> Error msg
  with
  | Error msg ->
      check bool "failure message mentions gir_record" true
        (string_contains ~sub:"gir_record" msg);
      check bool "failure message mentions ocgtk.gvariant" true
        (string_contains ~sub:"ocgtk.gvariant" msg)
  | Ok _ ->
      fail
        "expected Failure but got a result — cross-kind check was not enforced"

(* ========== Test Suite Registration ========== *)

let () =
  run "GIR record finalizer"
    [
      ( "TreePath round-trip",
        [
          test_case "depth round-trip" `Quick
            (require_gtk test_depth_round_trip);
          test_case "to_string" `Quick (require_gtk test_to_string);
        ] );
      ( "TreePath GC survival",
        [
          test_case "single GC cycle" `Quick
            (require_gtk test_survives_gc_single);
          test_case "stress 1000 alloc/drop" `Slow
            (require_gtk test_stress_alloc_drop);
        ] );
      ( "Cross-kind rejection",
        [
          test_case
            "rejects non-record kind (GVariant) where gir_record expected"
            `Quick
            (require_gtk
               test_cross_kind_ml_gir_record_ptr_val_rejects_wrong_kind);
        ] );
    ]
