(* Unit tests for Gobject.same and the polymorphic equality / hash that
   the ocgtk_gobject_ops custom block now installs. *)

open Alcotest
open Ocgtk_gtk.Gtk
module Helpers = Gtk_test_helpers

let require_gtk = Helpers.require_gtk

(* Distinct GObject pointers — neither identity check should succeed. *)
let test_distinct_objects_not_same () =
  let a = Wrappers.Button.new_ () in
  let b = Wrappers.Button.new_ () in
  check bool "Gobject.same false on distinct objects" false (Gobject.same a b);
  check bool "(=) false on distinct objects" false (Stdlib.( = ) a b)

(* Round-trip the same GObject through a GValue twice. Each get_object
   call allocates a fresh OCaml custom block, so the two extracted
   handles are distinct OCaml values that wrap the same C pointer. *)
let extract_twice : string -> 'a Gobject.obj -> 'a Gobject.obj * 'a Gobject.obj
    =
 fun label obj ->
  let gtype = Gobject.get_type obj in
  let v = Gobject.Value.create gtype in
  Gobject.Value.set_object v gtype (Some obj);
  let a = Gobject.Value.get_object v gtype in
  let b = Gobject.Value.get_object v gtype in
  match (a, b) with
  | Some a, Some b -> (a, b)
  | None, _ | _, None ->
      Alcotest.failf "extract_twice: get_object returned None for non-NULL %s"
        label

let test_same_pointer_is_same () =
  let btn = Wrappers.Button.new_ () in
  let a, b = extract_twice "Button" btn in
  check bool "Gobject.same true on round-tripped pointer" true
    (Gobject.same a b);
  check bool "(=) true on round-tripped pointer" true (Stdlib.( = ) a b)

(* Round-tripped handles must NOT be physically equal — that's the
   whole reason same/(=) exist. Guards against a future refactor that
   accidentally interns the wrapper. *)
let test_same_pointer_not_physically_equal () =
  let btn = Wrappers.Button.new_ () in
  let a, b = extract_twice "Button" btn in
  check bool "(==) false on round-tripped pointer (distinct blocks)" false
    (a == b)

(* Hashtbl keyed on Gobject.obj relies on the custom hash function.
   A get_object handle and the original button must lookup to the same
   bucket and the equality check must succeed. *)
let test_hashtbl_lookup () =
  let btn = Wrappers.Button.new_ () in
  let tbl = Hashtbl.create 4 in
  Hashtbl.add tbl btn "primary";
  let v = Gobject.Value.create (Gobject.get_type btn) in
  Gobject.Value.set_object v (Gobject.get_type btn) (Some btn);
  let extracted =
    match Gobject.Value.get_object v (Gobject.get_type btn) with
    | Some x -> x
    | None -> Alcotest.fail "extracted None"
  in
  check (option string) "Hashtbl finds original key via extracted handle"
    (Some "primary")
    (Hashtbl.find_opt tbl extracted)

let () =
  run "Gobject equality"
    [
      ( "identity",
        [
          test_case "distinct objects" `Quick
            (require_gtk test_distinct_objects_not_same);
          test_case "same pointer is same" `Quick
            (require_gtk test_same_pointer_is_same);
          test_case "same pointer not physically equal" `Quick
            (require_gtk test_same_pointer_not_physically_equal);
        ] );
      ( "hashtbl",
        [
          test_case "lookup via round-tripped key" `Quick
            (require_gtk test_hashtbl_lookup);
        ] );
    ]
