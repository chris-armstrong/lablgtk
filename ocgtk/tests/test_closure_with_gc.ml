(* Test closure behavior with explicit GC - for understanding limits *)

open Alcotest

(** Create 100 closures without explicit GC between iterations — verifies the
    default finalizer path works. *)
let test_without_gc () =
  let counter = ref 0 in
  for _i = 1 to 100 do
    let closure = Gobject.Closure.create (fun _argv -> incr counter) in
    Gobject_test_helpers.invoke_closure_void closure
  done;
  check int "counter reached 100 without GC" 100 !counter

(** Create 10 closures with [Gc.minor()] after each invocation — exercises the
    finalizer path under GC pressure. *)
let test_with_minor_gc () =
  let counter = ref 0 in
  for _i = 1 to 10 do
    let closure = Gobject.Closure.create (fun _argv -> incr counter) in
    Gobject_test_helpers.invoke_closure_void closure;
    Gc.minor ()
  done;
  check int "counter reached 10 with Gc.minor after each" 10 !counter

(** Create 50 closures with [Gc.minor()] every 10 iterations. *)
let test_with_delayed_gc () =
  let counter = ref 0 in
  for i = 1 to 50 do
    let closure = Gobject.Closure.create (fun _argv -> incr counter) in
    Gobject_test_helpers.invoke_closure_void closure;
    if i mod 10 = 0 then Gc.minor ()
  done;
  check int "counter reached 50 with Gc.minor every 10" 50 !counter

(** Regression test: [ml_closure_marshal] used to store the marshaller's raw C
    [GValue *param_values] straight into field 2 of the GC-scanned [argv]
    record. Once a handler allocated, [argv] was promoted to the major heap
    with that naked pointer intact, and the next major mark slice followed
    it — reading a header from the C stack and then scanning the
    [GValue] words as OCaml values. A [GValue]'s [g_type] word is a small even
    integer for the fundamental types ([G_TYPE_UINT] = [0x1c]), so the marker
    treated it as a heap pointer and died reading [Hd_val(0x1c)] at [0x14].

    [Gc.full_major] is mandatory here and [Gc.minor] cannot substitute: the
    minor collector never follows a pointer outside the minor heap, so the
    three tests above are structurally blind to this class of bug. The
    corruption only becomes observable once the block is promoted and the
    *major* marker walks it. *)
let test_argv_survives_major_gc () =
  let first = ref 0 and second = ref 0 in
  let closure =
    Gobject.Closure.create (fun argv ->
        (* Allocating before the collection is what gets [argv] promoted. *)
        first := !first + Gobject.Value.get_int (Gobject.Closure.nth argv ~pos:0);
        Gc.full_major ();
        (* Read again afterwards: [argv] must still be usable, and the C-side
           root has kept it live across the whole mark phase. *)
        second :=
          !second + Gobject.Value.get_int (Gobject.Closure.nth argv ~pos:1))
  in
  for i = 1 to 50 do
    Gobject_test_helpers.invoke_closure_two_ints closure i (i * 2)
  done;
  check int "first param summed across 50 emissions" 1275 !first;
  check int "second param summed across 50 emissions" 2550 !second

let () =
  run "Closure + GC Interaction Test"
    [
      ( "gc",
        [
          test_case "100 closures without explicit GC" `Quick test_without_gc;
          test_case "10 closures with Gc.minor after each" `Quick
            test_with_minor_gc;
          test_case "50 closures with Gc.minor every 10" `Quick
            test_with_delayed_gc;
          test_case "argv survives Gc.full_major inside the handler" `Quick
            test_argv_survives_major_gc;
        ] );
    ]
