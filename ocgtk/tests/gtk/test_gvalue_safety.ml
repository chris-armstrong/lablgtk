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
      a NULL string to [None] (and [get_string_exn] raises on it), and
      [Value.get_boxed] returns a gir_record custom block even though it is
      typed ['a obj];
    - [Gobject.get_ref_count] observable semantics.

    Only public [Gobject] / [Gtk] APIs are used. *)

open Alcotest
module Value = Gobject.Value
module Type = Gobject.Type
module Property = Gobject.Property
module Widget = Ocgtk_gtk.Gtk.Wrappers.Widget
module Wrappers = Ocgtk_gtk.Gtk.Wrappers

(* Mirrors the OCGTK_KIND_* enum in value_kinds.h: the block kind returned
    by get_boxed must be the gir_record one, not a GObject block. *)
let kind_gir_record = 2

external classify_int : 'a -> int = "caml_ocgtk_classify"

let require_gtk = Gtk_test_helpers.require_gtk

external plain_record_new : unit -> 'a Gobject.obj = "ml_test_plain_record_new"

external gdk_rectangle_get_type : unit -> Gobject.g_type
  = "ml_gdk_rectangle_get_type"

external gdk_rectangle_create : int -> int -> int -> int -> 'a Gobject.obj
  = "ml_test_gdk_rectangle_create"

module Rectangle = Ocgtk_gdk.Gdk.Wrappers.Rectangle

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

(** {2 Typed setter validation} *)

(** GLib's typed setters only trip a [g_return_if_fail (G_VALUE_HOLDS_...)] on a
    wrong-typed GValue — a critical on stderr, and a silent no-op from OCaml's
    perspective. The setters must reject wrong-typed GValues with
    [Invalid_argument], mirroring the getters. *)
let test_wrong_typed_setters_raise () =
  let str_value = Value.create Type.string in
  check_raises "set_int on a string-typed GValue"
    (Invalid_argument "g_value_set_int: not an int") (fun () ->
      Value.set_int str_value 42);
  check_raises "set_uint on a string-typed GValue"
    (Invalid_argument "g_value_set_uint: not a uint") (fun () ->
      Value.set_uint str_value 42);
  check_raises "set_boolean on a string-typed GValue"
    (Invalid_argument "g_value_set_boolean: not a boolean") (fun () ->
      Value.set_boolean str_value true);
  check_raises "set_string on an int-typed GValue"
    (Invalid_argument "g_value_set_string: not a string") (fun () ->
      let int_value = Value.create Type.int_ in
      Value.set_string_exn int_value "nope");
  check_raises "set_float on a string-typed GValue"
    (Invalid_argument "g_value_set_float: not a float") (fun () ->
      Value.set_float str_value 1.5);
  check_raises "set_double on a string-typed GValue"
    (Invalid_argument "g_value_set_double: not a double") (fun () ->
      Value.set_double str_value 1.5);
  check_raises "set_object on an int-typed GValue"
    (Invalid_argument "g_value_set_object: not an object") (fun () ->
      let int_value = Value.create Type.int_ in
      Value.set_object_exn int_value (Wrappers.Button.new_ ()))

(** Matched-type setters keep round-tripping. *)
let test_matched_setters_round_trip () =
  let v = Value.create Type.int_ in
  Value.set_int v 42;
  check int "int round-trip" 42 (Value.get_int v);
  let v = Value.create Type.uint in
  Value.set_uint v 7;
  check int "uint round-trip" 7 (Value.get_uint v);
  let v = Value.create Type.boolean in
  Value.set_boolean v true;
  check bool "boolean round-trip" true (Value.get_boolean v);
  let v = Value.create Type.string in
  Value.set_string_exn v "hello";
  check string "string round-trip" "hello" (Value.get_string_exn v);
  let v = Value.create Type.float_ in
  Value.set_float v 1.5;
  check bool "float round-trip" true (Float.equal (Value.get_float v) 1.5);
  let v = Value.create Type.double in
  Value.set_double v 2.25;
  check bool "double round-trip" true (Float.equal (Value.get_double v) 2.25)

(** [g_value_set_object] silently rejects objects incompatible with the GValue's
    type; surface that as [Invalid_argument] too. *)
let test_set_object_rejects_incompatible_object_type () =
  let btn = Wrappers.Button.new_ () in
  let v = Value.create (Gobject.get_type btn) in
  check_raises "set_object with an incompatible concrete type"
    (Invalid_argument "g_value_set_object: object type incompatible with GValue")
    (fun () -> Value.set_object_exn v (Wrappers.Box.new_ `HORIZONTAL 0))

let test_set_object_round_trips () =
  let btn = Wrappers.Button.new_ () in
  let v = Value.create (Gobject.get_type btn) in
  Value.set_object_exn v btn;
  check bool "object round-trip keeps identity" true
    (Gobject.same (Value.get_object_exn v) btn);
  Value.set_object v None;
  match Value.get_object v with
  | None -> ()
  | Some _ -> fail "set_object None should clear the GValue"

(** {2 Property error surfacing} *)

(** A missing property name only makes [g_object_get_property] log a critical
    and leave the GValue untouched — the OCaml caller sees success and later
    trips over the untouched value. [Property.get_value]/[set_value] must raise
    [Invalid_argument] mentioning the property name instead. *)
let test_property_get_missing_name_raises () =
  let btn = Wrappers.Button.new_ () in
  let v = Value.create_empty () in
  expect_invalid_argument ~label:"get_value on unknown property raises"
    ~needle:"no-such-property" (fun () ->
      Property.get_value btn ~name:"no-such-property" v)

let test_property_set_missing_name_raises () =
  let btn = Wrappers.Button.new_ () in
  let v = Value.create Type.string in
  expect_invalid_argument ~label:"set_value on unknown property raises"
    ~needle:"no-such-property" (fun () ->
      Value.set_string_exn v "hello";
      Property.set_value btn ~name:"no-such-property" v)

(** The positive path keeps working: get and set a real property. *)
let test_property_get_set_round_trip () =
  let btn = Wrappers.Button.new_ () in
  let v = Value.create Type.string in
  Value.set_string_exn v "set-through-gvalue";
  Property.set_value btn ~name:"label" v;
  let out = Value.create Type.string in
  Property.get_value btn ~name:"label" out;
  check string "property round-trips through GValues" "set-through-gvalue"
    (Value.get_string_exn out)

(** {2 Documented runtime facts} *)

(** [g_value_get_string] is nullable in GLib; the binding surfaces that as
    [None] via [get_string]. A fresh button's [label] property is NULL, so
    getting it must yield [None] — the documented mapping, not an error. *)
let test_get_string_returns_none_on_null () =
  let btn = Wrappers.Button.new_ () in
  let v = Value.create Type.string in
  Property.get_value btn ~name:"label" v;
  check (option string) "NULL string property reads as None" None
    (Value.get_string v)

(** The [_exn] form is for GIR args declared non-nullable: a NULL that violates
    that contract must raise [Failure] instead of silently returning [""]. *)
let test_get_string_exn_raises_on_null () =
  let btn = Wrappers.Button.new_ () in
  let v = Value.create Type.string in
  Property.get_value btn ~name:"label" v;
  check_raises "get_string_exn on a NULL string property"
    (Failure "g_value_get_string: NULL string") (fun () ->
      ignore (Value.get_string_exn v))

(** [set_string None] writes NULL via [g_value_set_string(gv, NULL)]; the value
    must read back as [None]. *)
let test_set_string_none_writes_null () =
  let v = Value.create Type.string in
  Value.set_string v None;
  check (option string) "set_string None writes NULL" None (Value.get_string v);
  Value.set_string v (Some "x");
  check (option string) "set_string (Some x) round-trips" (Some "x")
    (Value.get_string v)

(** [get_boxed] is typed ['a obj] for call-site ascription with generated record
    types, but the runtime representation is a gir_record custom block
    (ocgtk_gir_record_ops) — never a GObject block. Pin the classification so
    accidental misuse (passing the result where a real GObject is expected)
    stays diagnosable. *)
let test_get_boxed_returns_gir_record_block () =
  let gtype = gdk_rectangle_get_type () in
  let v = Value.create gtype in
  Value.set_boxed v (gdk_rectangle_create 1 2 3 4);
  let result = (Value.get_boxed v : Rectangle.t) in
  check int "get_boxed result classifies as gir_record" kind_gir_record
    (classify_int result)

(** [get_boxed_checked] validates the GValue's boxed GType against the caller's
    expected type before returning the gir_record block. *)
let test_get_boxed_checked_accepts_matching_gtype () =
  let gtype = gdk_rectangle_get_type () in
  let v = Value.create gtype in
  let original = gdk_rectangle_create 10 20 30 40 in
  Value.set_boxed v original;
  let result = (Value.get_boxed_checked v gtype : Rectangle.t) in
  check bool "matching GType accepted" true (Rectangle.equal result original)

let test_get_boxed_checked_rejects_mismatched_gtype () =
  let gtype = gdk_rectangle_get_type () in
  let v = Value.create gtype in
  Value.set_boxed v (gdk_rectangle_create 1 2 3 4);
  let tree_path_type = Type.from_name "GtkTreePath" in
  expect_invalid_argument ~label:"get_boxed_checked rejects a mismatched GType"
    ~needle:"g_value_get_boxed_checked" (fun () ->
      ignore (Value.get_boxed_checked v tree_path_type))

let test_get_boxed_checked_rejects_non_boxed () =
  let v = Value.create Type.int_ in
  Value.set_int v 42;
  expect_invalid_argument ~label:"get_boxed_checked rejects a non-boxed GValue"
    ~needle:"g_value_get_boxed_checked" (fun () ->
      ignore (Value.get_boxed_checked v (gdk_rectangle_get_type ())))

(** [Gobject.get_ref_count] reads the GObject struct field directly (GLib has no
    public accessor); pin its observable semantics: a freshly created object has
    at least one reference and a container takes its own. *)
let test_get_ref_count_tracks_ownership () =
  let box = Wrappers.Box.new_ `HORIZONTAL 0 in
  let child = Wrappers.Button.new_ () in
  let base = Gobject.get_ref_count child in
  check bool "fresh object holds at least one reference" true (base >= 1);
  Wrappers.Box.append box (child :> Widget.t);
  check int "container append adds one reference" (base + 1)
    (Gobject.get_ref_count child)

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
      ( "setter_validation",
        [
          Alcotest.test_case "wrong-typed setters raise Invalid_argument" `Quick
            (require_gtk test_wrong_typed_setters_raise);
          Alcotest.test_case "matched setters round-trip" `Quick
            (require_gtk test_matched_setters_round_trip);
          Alcotest.test_case "set_object rejects an incompatible object type"
            `Quick
            (require_gtk test_set_object_rejects_incompatible_object_type);
          Alcotest.test_case "set_object round-trip and clear" `Quick
            (require_gtk test_set_object_round_trips);
        ] );
      ( "property_errors",
        [
          Alcotest.test_case "get_value on unknown property raises" `Quick
            (require_gtk test_property_get_missing_name_raises);
          Alcotest.test_case "set_value on unknown property raises" `Quick
            (require_gtk test_property_set_missing_name_raises);
          Alcotest.test_case "property get/set round-trip" `Quick
            (require_gtk test_property_get_set_round_trip);
        ] );
      ( "runtime_facts",
        [
          Alcotest.test_case "get_string returns None on NULL" `Quick
            (require_gtk test_get_string_returns_none_on_null);
          Alcotest.test_case "get_string_exn raises on NULL" `Quick
            (require_gtk test_get_string_exn_raises_on_null);
          Alcotest.test_case "set_string None writes NULL" `Quick
            (require_gtk test_set_string_none_writes_null);
          Alcotest.test_case "get_boxed returns a gir_record block" `Quick
            (require_gtk test_get_boxed_returns_gir_record_block);
          Alcotest.test_case "get_boxed_checked accepts a matching GType" `Quick
            (require_gtk test_get_boxed_checked_accepts_matching_gtype);
          Alcotest.test_case "get_boxed_checked rejects a mismatched GType"
            `Quick
            (require_gtk test_get_boxed_checked_rejects_mismatched_gtype);
          Alcotest.test_case "get_boxed_checked rejects a non-boxed GValue"
            `Quick
            (require_gtk test_get_boxed_checked_rejects_non_boxed);
          Alcotest.test_case "get_ref_count tracks ownership" `Quick
            (require_gtk test_get_ref_count_tracks_ownership);
        ] );
    ]
