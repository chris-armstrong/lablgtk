(** Runtime tests for the closure-marshal path in [ml_closure_marshal].

    Exercises multi-param dispatch, enum/flags dispatch, return copy-back,
    exception escape, and GC interaction via the [Gobject_test_helpers] helpers.
*)

open Alcotest
module Closure = Gobject.Closure
module Value = Gobject.Value
module Helpers = Gobject_test_helpers

(** {2 M1: multi-param dispatch with bool return (true)} *)

let test_mixed_params_bool_return_true () =
  let btn_obj = Ocgtk_gtk.Gtk.Wrappers.Button.new_ () in
  let int_captured = ref 0 in
  let str_captured = ref "" in
  let obj_captured = ref None in
  let closure =
    Closure.create (fun argv ->
        int_captured := Value.get_int (Closure.nth argv ~pos:0);
        str_captured := Value.get_string (Closure.nth argv ~pos:1);
        obj_captured := Value.get_object (Closure.nth argv ~pos:2);
        Value.set_boolean (Closure.result argv) true)
  in
  let result =
    Helpers.invoke_closure_mixed_return_bool closure 42 "hello" (Some btn_obj)
  in
  check bool "return value is true" true result;
  check int "int arg captured" 42 !int_captured;
  check string "string arg captured" "hello" !str_captured;
  check bool "obj arg captured as Some" true
    (match !obj_captured with Some _ -> true | None -> false)

(** {2 M2: multi-param dispatch with bool return (false)} *)

let test_mixed_params_bool_return_false () =
  let btn_obj = Ocgtk_gtk.Gtk.Wrappers.Button.new_ () in
  let closure =
    Closure.create (fun argv -> Value.set_boolean (Closure.result argv) false)
  in
  let result =
    Helpers.invoke_closure_mixed_return_bool closure 99 "world" (Some btn_obj)
  in
  check bool "return value is false" false result

(** {2 M3: void return with 0 params} *)

let test_void_return_0_params () =
  let called = ref false in
  let closure = Closure.create (fun _argv -> called := true) in
  Helpers.invoke_closure_void closure;
  check bool "closure was invoked" true !called

(** {2 M5: nullable GObject param} *)

let test_null_gobject_param () =
  let obj_captured = ref None in
  let closure =
    Closure.create (fun argv ->
        obj_captured := Value.get_object (Closure.nth argv ~pos:2);
        Value.set_boolean (Closure.result argv) true)
  in
  let result = Helpers.invoke_closure_mixed_return_bool closure 0 "" None in
  check bool "return value is true" true result;
  check bool "null object passed as None" true
    (match !obj_captured with None -> true | Some _ -> false)

(** {2 M5b: non-null GObject param preserves identity} *)

let test_non_null_gobject_param () =
  let btn_obj = Ocgtk_gtk.Gtk.Wrappers.Button.new_ () in
  let obj_captured = ref None in
  let closure =
    Closure.create (fun argv ->
        obj_captured := Value.get_object (Closure.nth argv ~pos:2);
        Value.set_boolean (Closure.result argv) true)
  in
  let result =
    Helpers.invoke_closure_mixed_return_bool closure 0 "test" (Some btn_obj)
  in
  check bool "return value is true" true result;
  check bool "non-null object received as Some" true
    (match !obj_captured with Some _ -> true | None -> false);
  check bool "object identity preserved via Gobject.same" true
    (match !obj_captured with
    | Some obj -> Gobject.same obj btn_obj
    | None -> false)

(** {2 M4: exception escape} *)

let test_exception_escape () =
  Helpers.reset_closure_exception_flag ();
  let closure =
    Closure.create (fun _argv -> raise (Failure "test exception"))
  in
  Helpers.invoke_closure_void closure;
  check bool "exception flag is set after escape" true
    (Helpers.check_closure_exception_flag ())

(** {2 M8: int return copy-back} *)

let test_int_return () =
  let closure =
    Closure.create (fun argv -> Value.set_int (Closure.result argv) 99)
  in
  let result = Helpers.invoke_closure_return_int closure in
  check int "int return is 99" 99 result

(** {2 M9: flags dispatch} *)

type test_flags = A | B | AB

let test_flags_of_int n =
  let flags = ref [] in
  if n land 1 <> 0 then flags := A :: !flags;
  if n land 2 <> 0 then flags := B :: !flags;
  (* Bit pattern 3 means bits 0 and 1 are set, representing A and B *)
  if n land 3 = 3 then flags := AB :: !flags;
  List.sort Stdlib.compare !flags

let test_flags_dispatch () =
  let flags_captured = ref [] in
  let closure =
    Closure.create (fun argv ->
        flags_captured :=
          test_flags_of_int (Value.get_flags_int (Closure.nth argv ~pos:0));
        Value.set_boolean (Closure.result argv) true)
  in
  let result = Helpers.invoke_closure_flags_return_bool closure 3 in
  check bool "return value is true" true result;
  let expected = List.sort Stdlib.compare [ A; B; AB ] in
  check int "flags list length" (List.length expected)
    (List.length !flags_captured)

(** {2 M6: GC safety} *)

let test_gc_safety () =
  let errors = ref 0 in
  let closures =
    Array.init 50 (fun i ->
        let expected = i + 1 in
        Closure.create (fun argv ->
            Value.set_int (Closure.result argv) expected))
  in
  Array.iteri
    (fun i closure ->
      let result = Helpers.invoke_closure_return_int closure in
      let expected = i + 1 in
      if Int.equal result expected |> not then errors := !errors + 1;
      if (i + 1) mod 10 = 0 then Gc.minor ())
    closures;
  Gc.minor ();
  Array.iteri
    (fun i closure ->
      let result = Helpers.invoke_closure_return_int closure in
      let expected = i + 1 in
      if Int.equal result expected |> not then errors := !errors + 1)
    closures;
  check int "no errors during GC" 0 !errors

(** {2 M10: argv snapshot is GC-safe and self-contained} *)

(* Module-level so a captured [argv] stays GC-rooted past the invocation that
   produced it; a scope-local ref would not be reliably live once the callback
   returns. *)
let argv_holder : Closure.argv option ref = ref None
let make_button () = Ocgtk_gtk.Gtk.Wrappers.Button.new_ ()

(** The marshaller must hand the callback an [argv] whose fields are all
    well-formed OCaml values. A raw C [param_values] pointer stored in a scanned
    block field is misread by a major GC as a heap block header and chased into
    the C stack, so forcing collections while [argv] is live must be safe, and
    the parameters must still read back intact afterwards. The object param
    carries its concrete derived GType (not plain [G_TYPE_OBJECT]) precisely
    because large dynamic type ids are what makes the misread header harmful. *)
let test_argv_survives_gc_in_callback () =
  let btn = make_button () in
  let int_captured = ref 0 in
  let obj_ok = ref false in
  let closure =
    Closure.create (fun argv ->
        Gc.full_major ();
        for _ = 1 to 2_000 do
          ignore (String.length (String.make 16 'x'))
        done;
        Gc.full_major ();
        Gc.minor ();
        int_captured := Value.get_int (Closure.nth argv ~pos:0);
        (obj_ok :=
           match Value.get_object (Closure.nth argv ~pos:1) with
           | Some obj -> Gobject.same obj btn
           | None -> false);
        Value.set_int (Closure.result argv) 0)
  in
  for _ = 1 to 5 do
    Helpers.invoke_closure_int_object closure 42 btn
  done;
  check int "int param intact after in-callback major GC" 42 !int_captured;
  check bool "object param intact after in-callback major GC" true !obj_ok

(** [argv] is a self-contained snapshot: the GValue copies it carries are owned
    by OCaml, so retaining [argv] beyond the callback must work even though the
    marshaller's borrowed [param_values] array is dead by then. The follow-up
    invocation scribbles the same C stack region where that borrowed array used
    to live. *)
let test_argv_retained_after_invocation () =
  argv_holder := None;
  let btn = make_button () in
  let capture = Closure.create (fun argv -> argv_holder := Some argv) in
  Helpers.invoke_closure_int_object capture 42 btn;
  Helpers.invoke_closure_two_ints (Closure.create (fun _argv -> ())) 1111 2222;
  Gc.full_major ();
  match !argv_holder with
  | None -> fail "argv was not captured"
  | Some argv -> (
      check int "retained argv keeps its param count" 2 argv.nargs;
      check int "retained argv int param intact" 42
        (Value.get_int (Closure.nth argv ~pos:0));
      match Value.get_object (Closure.nth argv ~pos:1) with
      | Some obj ->
          check bool "retained argv object param intact" true
            (Gobject.same obj btn)
      | None -> fail "retained argv lost its object param")

let require_gtk = Gtk_test_helpers.require_gtk

let () =
  run "Signal Marshalling"
    [
      ( "multi_param",
        [
          test_case "mixed params bool return true" `Quick
            (require_gtk test_mixed_params_bool_return_true);
          test_case "mixed params bool return false" `Quick
            (require_gtk test_mixed_params_bool_return_false);
        ] );
      ( "void_and_nullable",
        [
          test_case "void return 0 params" `Quick
            (require_gtk test_void_return_0_params);
          test_case "null gobject param" `Quick
            (require_gtk test_null_gobject_param);
          test_case "non-null gobject param preserves identity" `Quick
            (require_gtk test_non_null_gobject_param);
        ] );
      ( "exception",
        [
          test_case "exception escape sets flag" `Quick
            (require_gtk test_exception_escape);
        ] );
      ( "flags",
        [ test_case "flags dispatch" `Quick (require_gtk test_flags_dispatch) ]
      );
      ( "int_return",
        [
          test_case "int return copy-back" `Quick (require_gtk test_int_return);
        ] );
      ("gc", [ test_case "gc safety" `Quick (require_gtk test_gc_safety) ]);
      ( "argv_snapshot",
        [
          test_case "argv survives major GC inside the callback" `Quick
            (require_gtk test_argv_survives_gc_in_callback);
          test_case "argv remains readable after the invocation returns" `Quick
            (require_gtk test_argv_retained_after_invocation);
        ] );
    ]
