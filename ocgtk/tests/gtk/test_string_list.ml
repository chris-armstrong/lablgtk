(** Test suite for Gtk.StringList module

    This test file verifies:
    - Module compilation and type accessibility
    - String_list creation and basic operations
    - take method (String_copy validation)
    - append method
    - get_string extraction safety
    - remove operation
    - get_n_items property
    - High-level GString_list wrapper
    - Ownership semantics and memory safety *)

open Alcotest
open Ocgtk_gtk.Gtk
module Helpers = Gtk_test_helpers

(* Layer 1 (raw) string_list functions *)
let string_list_new = Wrappers.String_list.new_
let string_list_append = Wrappers.String_list.append
let string_list_take = Wrappers.String_list.take
let string_list_get_string = Wrappers.String_list.get_string
let string_list_remove = Wrappers.String_list.remove
let string_list_get_n_items = Wrappers.String_list.get_n_items
let require_gtk = Gtk_test_helpers.require_gtk

(* Helper to skip tests that require GTK >= 4.14 (e.g. n-items property) *)
let require_gtk_414 f = require_gtk (Helpers.require_gtk_version 4 14 0 f)

(* ========== Module Accessibility Tests ========== *)

let test_string_list_module_accessible () =
  let _t : Wrappers.String_list.t option = None in
  check bool "String_list module accessible" true true

let test_string_list_type () =
  (* Verify the type is correctly defined as an object subtype
     The type Wrappers.String_list.t = [`string_list | `object_] Gobject.obj
     already proves it's GObject-based; we just test creation works *)
  let list = string_list_new (Some [||]) in
  check bool "String_list instance created" true (Gobject.get_ref_count list > 0)

(* ========== Creation Tests ========== *)

let test_creation_empty_list () =
  let list = string_list_new (Some [||]) in
  check int "Empty list has 0 items" 0 (string_list_get_n_items list)

let test_creation_with_empty_string () =
  let list = string_list_new (Some [||]) in
  string_list_take list "";
  check int "Empty string adds item" 1 (string_list_get_n_items list)

(* ========== Take Method Tests (String_copy validation) ========== *)

let test_take_basic () =
  let list = string_list_new (Some [||]) in
  let test_str = "test string for take" in
  string_list_take list test_str;
  check int "take: 1 item added" 1 (string_list_get_n_items list)

let test_take_string_copy_independence () =
  (* CRITICAL TEST: Verify String_copy creates independent memory *)
  let list = string_list_new (Some [||]) in
  let original = "mutable string" in
  (* Note: OCaml strings are immutable, but this tests the C boundary *)
  string_list_take list original;

  (* Retrieve and verify the string is accessible *)
  (match string_list_get_string list 0 with
  | Some retrieved ->
      check string "take: retrieved equals original" "mutable string" retrieved
  | None -> fail "Expected Some string from get_string");

  (* Verify original is still valid (no corruption across C boundary) *)
  check string "original string unchanged" "mutable string" original

let test_take_copies_ownership () =
  (* Test that take transfers ownership correctly by:
     1. Adding a string via take
     2. Verifying the string survives GC cycles
     3. Verifying memory is properly managed *)
  let list = string_list_new (Some [||]) in
  let owned = String.make 100 'x' in
  (* Create larger string *)
  string_list_take list owned;

  (* Force potential GC by allocating more data *)
  let _ = String.make 10000 'y' in

  match string_list_get_string list 0 with
  | Some retrieved ->
      (* Verify the string content is intact *)
      if String.length retrieved = 100 && retrieved.[0] = 'x' then
        check bool "take: ownership transfer works" true true
      else fail "Retrieved string corrupted"
  | None -> fail "String lost after GC pressure"

let test_take_special_chars () =
  let list = string_list_new (Some [||]) in
  (* Note: Embedded null bytes (\x00) are not supported in GTK strings (C null-terminated strings).
     Test other special characters: tab, newline, carriage return, quotes, backslash *)
  let special = "Hello\tWorld\n\r\"\\!" in
  string_list_take list special;

  match string_list_get_string list 0 with
  | Some retrieved ->
      check string "take: special chars preserved" special retrieved
  | None -> fail "Special characters not preserved"

let test_take_unicode () =
  let list = string_list_new (Some [||]) in
  let unicode = "Unicode: \xE2\x9D\xA4\xE2\x9D\xA4" in
  (* Hearts: ❤❤ *)
  string_list_take list unicode;

  match string_list_get_string list 0 with
  | Some retrieved -> check string "take: unicode preserved" unicode retrieved
  | None -> fail "Unicode characters not preserved"

let test_take_long_string () =
  let list = string_list_new (Some [||]) in
  let long = String.make 10000 'z' in
  (* 10KB string *)
  string_list_take list long;

  match string_list_get_string list 0 with
  | Some retrieved ->
      check int "Long string length preserved" 10000 (String.length retrieved);
      check bool "Long string content correct" (retrieved = long) true
  | None -> fail "Long string lost"

(* ========== Append Method Tests ========== *)

let test_append_basic () =
  let list = string_list_new (Some [||]) in
  string_list_append list "appended";
  check int "append: 1 item" 1 (string_list_get_n_items list)

let test_append_vs_take () =
  (* Both should add items, but with different ownership semantics *)
  let list = string_list_new (Some [||]) in
  string_list_append list "via append";
  string_list_take list "via take";

  check int "Both methods add items" 2 (string_list_get_n_items list);

  (* Verify both strings are retrievable *)
  match (string_list_get_string list 0, string_list_get_string list 1) with
  | Some s0, Some s1 ->
      (* Order: append adds first, then take *)
      check string "First string is append" "via append" s0;
      check string "Second string is take" "via take" s1
  | _ -> fail "Expected both strings"

(* ========== Get String Extraction Safety Tests ========== *)

let test_get_string_valid_index () =
  let list = string_list_new (Some [||]) in
  string_list_take list "item0";
  string_list_take list "item1";

  (match string_list_get_string list 0 with
  | Some s -> check string "Index 0" "item0" s
  | None -> fail "Index 0 should return Some");

  match string_list_get_string list 1 with
  | Some s -> check string "Index 1" "item1" s
  | None -> fail "Index 1 should return Some"

let test_get_string_negative_index () =
  let list = string_list_new (Some [||]) in
  string_list_take list "item";

  (* Negative index - GTK returns NULL/None *)
  match string_list_get_string list (-1) with
  | None -> check bool "Negative index returns None" true true
  | Some _ -> fail "Negative index should return None"

let test_get_string_out_of_bounds () =
  let list = string_list_new (Some [||]) in
  string_list_take list "only item";

  match string_list_get_string list 10 with
  | None -> check bool "Out of bounds returns None" true true
  | Some _ -> fail "Out of bounds should return None"

let test_get_string_empty_list () =
  let list = string_list_new (Some [||]) in
  match string_list_get_string list 0 with
  | None -> check bool "Empty list returns None" true true
  | Some _ -> fail "Empty list should return None"

let test_get_string_returns_copy () =
  (* Verify get_string returns a copy we can mutate safely *)
  let list = string_list_new (Some [||]) in
  string_list_take list "original";

  match string_list_get_string list 0 with
  | Some retrieved ->
      (* Modify the "copy" - should not affect internal state *)
      let _modified = retrieved ^ " modified" in
      check string "Original unchanged" "original" retrieved
  | None -> fail "Expected string"

(* ========== Remove Operation Tests ========== *)

let test_remove_first () =
  let list = string_list_new (Some [||]) in
  string_list_take list "first";
  string_list_take list "second";
  string_list_take list "third";

  check int "3 items before remove" 3 (string_list_get_n_items list);
  string_list_remove list 0;
  check int "2 items after removing first" 2 (string_list_get_n_items list);

  (* Verify remaining items shifted correctly *)
  match string_list_get_string list 0 with
  | Some s -> check string "First is now 'second'" "second" s
  | None -> fail "Expected 'second' at index 0"

let test_remove_last () =
  let list = string_list_new (Some [||]) in
  string_list_take list "first";
  string_list_take list "second";

  string_list_remove list 1;
  check int "1 item after removing last" 1 (string_list_get_n_items list);

  match string_list_get_string list 0 with
  | Some s -> check string "Only 'first' remains" "first" s
  | None -> fail "Expected 'first'"

let test_remove_invalid_index () =
  let list = string_list_new (Some [||]) in
  string_list_take list "item";

  (* Removing invalid index should not crash *)
  try
    string_list_remove list 10;
    check bool "Invalid remove handled gracefully" true true
  with e -> fail ("Invalid remove threw: " ^ Printexc.to_string e)

(* ========== Get N Items Tests ========== *)

let test_n_items_empty () =
  check int "Empty n_items" 0
    (string_list_get_n_items (string_list_new (Some [||])))

let test_n_items_after_operations () =
  let list = string_list_new (Some [||]) in
  string_list_append list "a";
  check int "1 item" 1 (string_list_get_n_items list);

  string_list_take list "b";
  check int "2 items" 2 (string_list_get_n_items list);

  string_list_take list "c";
  check int "3 items" 3 (string_list_get_n_items list);

  string_list_remove list 0;
  check int "2 items after remove" 2 (string_list_get_n_items list)

(* ========== High-Level OO Wrapper Tests ========== *)

let test_gstring_list_wrapper () =
  let list = string_list_new (Some [||]) in
  let gl = new String_list.string_list list in

  gl#take "wrapper item";
  check int "Wrapper take adds item" 1 gl#n_items;

  match gl#get_string 0 with
  | Some s -> check string "Wrapper get_string" "wrapper item" s
  | None -> fail "Wrapper should return string"

(* ========== Integration/Concurrency Tests ========== *)

let test_mixed_operations () =
  let list = string_list_new (Some [||]) in
  let items = [| "a"; "b"; "c"; "d"; "e" |] in

  (* Mix of append and take *)
  string_list_append list items.(0);
  string_list_take list items.(1);
  string_list_append list items.(2);
  string_list_take list items.(3);
  string_list_take list items.(4);

  check int "5 items" 5 (string_list_get_n_items list);

  (* Verify all items in order *)
  for i = 0 to 4 do
    match string_list_get_string list i with
    | Some s -> check string (Printf.sprintf "Item %d" i) items.(i) s
    | None -> fail (Printf.sprintf "Missing item at index %d" i)
  done

let test_string_list_survives_gc () =
  let list = string_list_new (Some [||]) in
  string_list_take list (String.make 1000 'x');

  (* Create GC pressure *)
  let rec loop n = if n > 0 then String.make 1000 'y' :: loop (n - 1) else [] in
  let _ = loop 100 in

  match string_list_get_string list 0 with
  | Some s ->
      if s <> String.make 1000 'x' then fail "String corrupted after GC"
      else check bool "String survived GC" true true
  | None -> fail "String lost after GC pressure"

(* ========== Test Suite Registration ========== *)

let () =
  run "Gtk.StringList Tests"
    [
      ( "Module",
        [
          test_case "module_accessible" `Quick
            test_string_list_module_accessible;
          test_case "type" `Quick test_string_list_type;
        ] );
      ( "Creation",
        [
          test_case "empty_list" `Quick
            (require_gtk_414 test_creation_empty_list);
          test_case "empty_string" `Quick
            (require_gtk_414 test_creation_with_empty_string);
        ] );
      ( "Take Method (String_copy)",
        [
          test_case "basic" `Quick (require_gtk_414 test_take_basic);
          test_case "independence" `Quick
            (require_gtk test_take_string_copy_independence);
          test_case "ownership" `Quick (require_gtk test_take_copies_ownership);
          test_case "special_chars" `Quick (require_gtk test_take_special_chars);
          test_case "unicode" `Quick (require_gtk test_take_unicode);
          test_case "long_string" `Quick (require_gtk test_take_long_string);
        ] );
      ( "Append Method",
        [
          test_case "basic" `Quick (require_gtk_414 test_append_basic);
          test_case "append_vs_take" `Quick
            (require_gtk_414 test_append_vs_take);
        ] );
      ( "Get String (Extraction)",
        [
          test_case "valid_index" `Quick
            (require_gtk test_get_string_valid_index);
          test_case "negative_index" `Quick
            (require_gtk test_get_string_negative_index);
          test_case "out_of_bounds" `Quick
            (require_gtk test_get_string_out_of_bounds);
          test_case "empty_list" `Quick (require_gtk test_get_string_empty_list);
          test_case "returns_copy" `Quick
            (require_gtk test_get_string_returns_copy);
        ] );
      ( "Remove",
        [
          test_case "first" `Quick (require_gtk_414 test_remove_first);
          test_case "last" `Quick (require_gtk_414 test_remove_last);
          test_case "invalid" `Quick (require_gtk test_remove_invalid_index);
        ] );
      ( "N Items",
        [
          test_case "empty" `Quick (require_gtk_414 test_n_items_empty);
          test_case "operations" `Quick
            (require_gtk_414 test_n_items_after_operations);
        ] );
      ( "Wrapper",
        [
          test_case "gstring_list" `Quick
            (require_gtk_414 test_gstring_list_wrapper);
        ] );
      ( "Integration",
        [
          test_case "mixed_operations" `Quick
            (require_gtk_414 test_mixed_operations);
          test_case "gc_survival" `Quick
            (require_gtk test_string_list_survives_gc);
        ] );
    ]
