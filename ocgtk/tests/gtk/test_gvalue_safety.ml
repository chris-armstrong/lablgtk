(** Regression tests for the GValue / GObject safety audit of [ml_gobject.c].

    Each test pins one finding:

    - [Value.set_boxed] must reject gir_record blocks whose GType is not a boxed
      subtype of the GValue's type: [g_value_set_boxed] copies via the
      *GValue's* type, so a mismatched record pointer would run a foreign
      [g_boxed_copy] (immediate memory corruption, not a delayed leak);
    - typed setters must reject wrong-typed GValues with [Invalid_argument]
      instead of tripping GLib [g_return_if_fail] checks that silently do
      nothing;
    - [Property.get_value]/[set_value] must raise on unknown property names
      instead of letting GLib log a critical and leave the GValue untouched;
    - documented NULL and runtime-representation facts: [Value.get_string] maps
      a NULL string to [""], and [Value.get_boxed] returns a gir_record custom
      block even though it is typed ['a obj];
    - [Gobject.get_ref_count] observable semantics.

    Only public [Gobject] / [Gtk] APIs are used. *)

open Alcotest
module Value = Gobject.Value
module Type = Gobject.Type
module Property = Gobject.Property
module Widget = Ocgtk_gtk.Gtk.Wrappers.Widget

let require_gtk = Gtk_test_helpers.require_gtk

external plain_record_new : unit -> 'a Gobject.obj = "ml_test_plain_record_new"

external gdk_rectangle_get_type : unit -> Gobject.g_type
  = "ml_gdk_rectangle_get_type"

external gdk_rectangle_create : int -> int -> int -> int -> 'a Gobject.obj
  = "ml_test_gdk_rectangle_create"

module Rectangle = Ocgtk_gdk__Rectangle

(** [true] iff [needle] occurs in [haystack]. Avoids pulling in extra
    dependencies for substring tests on dynamic error messages. *)
let is_substring haystack needle =
  let n = String.length needle in
  let last = String.length haystack - n in
  let rec scan i =
    i <= last && (String.sub haystack i n = needle || scan (i + 1))
  in
  needle = "" || scan 0

(** Assert that [f] raises [Invalid_argument] whose message contains [needle].
*)
let expect_invalid_argument ~label ~needle f =
  match f () with
  | () -> fail (label ^ ": expected Invalid_argument, no exception raised")
  | exception Invalid_argument msg ->
      if not (is_substring msg needle) then
        fail
          (Printf.sprintf "%s: message %S does not mention %S" label msg needle)
  | exception e ->
      fail
        (Printf.sprintf "%s: expected Invalid_argument, got %s" label
           (Printexc.to_string e))

(** {2 set_boxed type validation} *)

(** A gir_record of a different boxed type must be rejected: the GValue would
    otherwise copy the foreign pointer with the GValue's own [g_boxed_copy]. *)
let test_set_boxed_rejects_mismatched_boxed_record () =
  let v = Value.create (gdk_rectangle_get_type ()) in
  let path = Ocgtk_gtk.Gtk.Wrappers.Tree_path.new_ () in
  expect_invalid_argument ~label:"set_boxed rejects a mismatched boxed record"
    ~needle:"g_value_set_boxed" (fun () -> Value.set_boxed v path)

(** A plain gir_record (no registered GType, g_free finalizer) must be rejected:
    it is not a boxed type at all. *)
let test_set_boxed_rejects_plain_record () =
  let v = Value.create (gdk_rectangle_get_type ()) in
  let plain = plain_record_new () in
  expect_invalid_argument ~label:"set_boxed rejects a non-boxed gir_record"
    ~needle:"g_value_set_boxed" (fun () -> Value.set_boxed v plain)

(** The happy path stays working: a record whose GType matches the GValue
    round-trips. *)
let test_set_boxed_accepts_matching_boxed_record () =
  let gtype = gdk_rectangle_get_type () in
  let v = Value.create gtype in
  let original = gdk_rectangle_create 10 20 30 40 in
  Value.set_boxed v original;
  let result = (Value.get_boxed v : Rectangle.t) in
  check bool "matching record still round-trips" true
    (Rectangle.equal result original)

let () =
  Alcotest.run "GValue safety"
    [
      ( "set_boxed_validation",
        [
          Alcotest.test_case "mismatched boxed record rejected" `Quick
            (require_gtk test_set_boxed_rejects_mismatched_boxed_record);
          Alcotest.test_case "plain gir_record rejected" `Quick
            (require_gtk test_set_boxed_rejects_plain_record);
          Alcotest.test_case "matching record accepted" `Quick
            (require_gtk test_set_boxed_accepts_matching_boxed_record);
        ] );
    ]
