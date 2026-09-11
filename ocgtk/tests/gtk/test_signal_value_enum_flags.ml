(** Runtime test suite for GValue enum/flags/variant/int64 wrappers.

    Tests the [Gobject.Value] get/set functions. Tests that exercise concrete
    GTK/GDK registered GTypes (cases 1–3, 9) are gated with [require_gtk] so
    they skip gracefully when run without a display.

    The generated enum/bitfield decoders live in [Gtk_enums] and [Gdk_enums]
    which are re-exported by the library wrappers [Ocgtk_gtk] and [Ocgtk_gdk];
    the generated Rectangle record decoder is reachable through the public path
    [Ocgtk_gdk.Gdk.Wrappers.Rectangle]. *)

open Alcotest
module Gtk_enums = Ocgtk_gtk.Gtk_enums
module Gdk_enums = Ocgtk_gdk.Gdk_enums
module Gvariant = Ocgtk_common.Gvariant
module Helpers = Gtk_test_helpers
module Rectangle = Ocgtk_gdk.Gdk.Wrappers.Rectangle

let require_gtk = Helpers.require_gtk

(** Typed equality for [Gtk.Orientation] polymorphic variants. *)
let equal_orientation a b =
  match (a, b) with
  | `HORIZONTAL, `HORIZONTAL | `VERTICAL, `VERTICAL -> true
  | _ -> false

(** Typed equality for individual [Gdk.ModifierType] flag variants. Uses
    [modifiertype_to_int] on a singleton list as the canonical encoding. *)
let equal_modifiertype_flag a b =
  Gdk_enums.modifiertype_to_int [ a ] = Gdk_enums.modifiertype_to_int [ b ]

external gtk_orientation_get_type : unit -> Gobject.g_type
  = "ml_gtk_orientation_get_type"
(** Direct binding to [gtk_orientation_get_type] via a thin C wrapper.
    [g_type_from_name] only works after a type has been registered via its
    [_get_type()] function. The wrapper in
    [test_signal_value_enum_flags_stubs.c] converts the raw C [GType] (gulong)
    via [Val_long]. *)

external gdk_rectangle_get_type : unit -> Gobject.g_type
  = "ml_gdk_rectangle_get_type"
(** Direct binding to [gdk_rectangle_get_type] via a thin C stub in
    [test_signal_value_enum_flags_stubs.c]. Converts the raw C [GType] (gulong)
    via [Val_long]. *)

external gdk_rectangle_create : int -> int -> int -> int -> Rectangle.t
  = "ml_gdk_rectangle_create"
(** Create a [GdkRectangle] with the given x, y, width, height fields and wrap
    it as a gir_record custom block. The pointer is heap-allocated with [g_new]
    so the finalizer (which calls [g_boxed_free]) can free it correctly. *)

(** {2 Case 1 — Enum round-trip via decoder} *)

(** Create a GValue typed as GtkOrientation, set it via [set_enum_int] with the
    integer encoding of [\`VERTICAL], read it back with [get_enum_int], and
    decode via [orientation_of_int]. Asserts the round-trip yields [\`VERTICAL].
*)
let test_enum_roundtrip_via_decoder () =
  (* Call gtk_orientation_get_type() directly to ensure registration before
     creating the GValue; g_type_from_name works only after first registration. *)
  let gtype_orientation = gtk_orientation_get_type () in
  let v = Gobject.Value.create gtype_orientation in
  let vert_int = Gtk_enums.orientation_to_int `VERTICAL in
  Gobject.Value.set_enum_int v vert_int;
  let result = Gtk_enums.orientation_of_int (Gobject.Value.get_enum_int v) in
  check
    (testable
       (fun fmt x ->
         Format.fprintf fmt "%s"
           (match x with
           | `HORIZONTAL -> "HORIZONTAL"
           | `VERTICAL -> "VERTICAL"))
       equal_orientation)
    "enum round-trip via decoder yields `VERTICAL" `VERTICAL result

(** {2 Case 2 — Flags round-trip via decoder} *)

(** Create a GValue typed as GdkModifierType, set it with the bitwise encoding
    of [\`SHIFT_MASK; \`CONTROL_MASK], read it back, and decode via
    [modifiertype_of_int]. Asserts both bits are present in the result. *)
let test_flags_roundtrip_via_decoder () =
  let gtype_modifiertype = Gobject.Type.from_name "GdkModifierType" in
  let v = Gobject.Value.create gtype_modifiertype in
  let flags_int =
    Gdk_enums.modifiertype_to_int [ `SHIFT_MASK; `CONTROL_MASK ]
  in
  Gobject.Value.set_flags_int v flags_int;
  let decoded = Gdk_enums.modifiertype_of_int (Gobject.Value.get_flags_int v) in
  check bool "decoded flags contain `SHIFT_MASK" true
    (List.mem `SHIFT_MASK decoded);
  check bool "decoded flags contain `CONTROL_MASK" true
    (List.mem `CONTROL_MASK decoded)

(** {2 Case 3 — Flags empty list} *)

(** Set flags to 0 and verify [modifiertype_of_int 0 = []]. *)
let test_flags_empty_list () =
  let gtype_modifiertype = Gobject.Type.from_name "GdkModifierType" in
  let v = Gobject.Value.create gtype_modifiertype in
  Gobject.Value.set_flags_int v 0;
  let raw = Gobject.Value.get_flags_int v in
  check int "get_flags_int of 0 is 0" 0 raw;
  let decoded = Gdk_enums.modifiertype_of_int 0 in
  check (list pass) "modifiertype_of_int 0 is empty list" [] decoded

(** {2 Case 4 — GVariant round-trip} *)

(** Create a GValue typed as GVariant, set it via [set_variant] with
    [Gvariant.of_string "hello"], read it back with [get_variant], and assert
    [Gvariant.to_string] returns "hello". GVariant is a GLib type; this test
    does not require gtk_init. *)
let test_variant_roundtrip () =
  let gtype_variant = Gobject.Type.from_name "GVariant" in
  let v = Gobject.Value.create gtype_variant in
  let gv = Gvariant.of_string "hello" in
  Gobject.Value.set_variant v gv;
  let retrieved = Gobject.Value.get_variant v in
  let s = Gvariant.to_string retrieved in
  check string "variant round-trip preserves string content" "hello" s

(** {2 Case 5 — Int64 round-trip} *)

(** Create a GValue typed as gint64, set [Int64.max_int] via [set_int64], read
    it back with [get_int64], and assert equality. G_TYPE_INT64 is a GLib
    fundamental type; no gtk_init needed. *)
let test_int64_roundtrip () =
  let gtype_int64 = Gobject.Type.int64 in
  let v = Gobject.Value.create gtype_int64 in
  Gobject.Value.set_int64 v Int64.max_int;
  let result = Gobject.Value.get_int64 v in
  check int64 "int64 round-trip preserves Int64.max_int" Int64.max_int result

(** {2 Case 6 — Enum decoder fails on out-of-range integer} *)

(** Call [orientation_of_int 99] and assert it raises [Failure] with a message
    mentioning "Orientation". *)
let test_enum_decoder_fails_on_out_of_range () =
  check_raises "orientation_of_int 99 raises Failure"
    (Failure "Orientation: unknown int 99") (fun () ->
      ignore (Gtk_enums.orientation_of_int 99))

(** {2 Case 7 — Enum decoder property: of_int o to_int = id} *)

(** For each declared variant of [Gtk.Orientation], assert that
    [orientation_of_int (orientation_to_int v) = v]. *)
let test_enum_of_int_to_int_identity () =
  let orientation_testable =
    testable
      (fun fmt x ->
        Format.fprintf fmt "%s"
          (match x with `HORIZONTAL -> "HORIZONTAL" | `VERTICAL -> "VERTICAL"))
      equal_orientation
  in
  List.iter
    (fun variant ->
      let round_tripped =
        Gtk_enums.orientation_of_int (Gtk_enums.orientation_to_int variant)
      in
      check orientation_testable
        (Printf.sprintf "of_int o to_int = id for %s"
           (match variant with
           | `HORIZONTAL -> "HORIZONTAL"
           | `VERTICAL -> "VERTICAL"))
        variant round_tripped)
    [ `HORIZONTAL; `VERTICAL ]

(** {2 Case 8 — Bitfield decoder property: of_int o to_int preserves set} *)

(** For six subsets of [GdkModifierType], assert that [of_int (to_int s)] is a
    permutation of [s]. Uses [List.sort compare] on both sides to normalise
    order before comparison. *)
let test_bitfield_of_int_to_int_preserves_set () =
  let modifiertype_list_testable =
    testable
      (fun fmt xs ->
        Format.fprintf fmt "[%s]"
          (String.concat "; "
             (List.map
                (function
                  | `NO_MODIFIER_MASK -> "NO_MODIFIER_MASK"
                  | `SHIFT_MASK -> "SHIFT_MASK"
                  | `LOCK_MASK -> "LOCK_MASK"
                  | `CONTROL_MASK -> "CONTROL_MASK"
                  | `ALT_MASK -> "ALT_MASK"
                  | `BUTTON1_MASK -> "BUTTON1_MASK"
                  | `BUTTON2_MASK -> "BUTTON2_MASK"
                  | `BUTTON3_MASK -> "BUTTON3_MASK"
                  | `BUTTON4_MASK -> "BUTTON4_MASK"
                  | `BUTTON5_MASK -> "BUTTON5_MASK"
                  | `SUPER_MASK -> "SUPER_MASK"
                  | `HYPER_MASK -> "HYPER_MASK"
                  | `META_MASK -> "META_MASK")
                xs)))
      (List.equal equal_modifiertype_flag)
  in
  let check_subset label s =
    let encoded = Gdk_enums.modifiertype_to_int s in
    let decoded = Gdk_enums.modifiertype_of_int encoded in
    check modifiertype_list_testable label
      (List.sort Stdlib.compare s)
      (List.sort Stdlib.compare decoded)
  in
  check_subset "empty subset" [];
  check_subset "SHIFT_MASK only" [ `SHIFT_MASK ];
  check_subset "CONTROL_MASK only" [ `CONTROL_MASK ];
  check_subset "SHIFT_MASK + CONTROL_MASK" [ `SHIFT_MASK; `CONTROL_MASK ];
  check_subset "ALT_MASK + BUTTON1_MASK" [ `ALT_MASK; `BUTTON1_MASK ];
  check_subset "SUPER_MASK + HYPER_MASK + META_MASK"
    [ `SUPER_MASK; `HYPER_MASK; `META_MASK ]

(** {2 Case 9 — Negative: wrong GValue type raises Invalid_argument} *)

(** Create a GValue of gint type, set it via [set_int], then call
    [get_flags_int] and assert [Invalid_argument] is raised. The C wrapper
    [ml_g_value_get_flags_int] uses [caml_invalid_argument] on
    G_VALUE_HOLDS_FLAGS failure, so the raised exception is [Invalid_argument],
    not [Failure]. *)
let test_wrong_gvalue_type_raises () =
  let gtype_int = Gobject.Type.int_ in
  let v = Gobject.Value.create gtype_int in
  Gobject.Value.set_int v 5;
  check_raises "get_flags_int on non-flags GValue raises Invalid_argument"
    (Invalid_argument "g_value_get_flags_int: not a flags value") (fun () ->
      ignore (Gobject.Value.get_flags_int v))

(** {2 Case 10 — Version-guarded flag NO_MODIFIER_MASK compile-time check} *)

(** [NO_MODIFIER_MASK] has integer value 0 in the GDK GIR data. Because
    [flags land 0 <> 0] is always false, the flag cannot be round-tripped
    through [modifiertype_of_int]/[modifiertype_to_int] at runtime — this is the
    same semantic as the C generator. We verify instead that the variant tag is
    present in the type at compile time, and that [to_int] of a list containing
    only [\`NO_MODIFIER_MASK] yields 0. *)
let test_version_guarded_no_modifier_mask_compile_time () =
  (* Compile-time check: [`NO_MODIFIER_MASK] must unify with [modifiertype]. *)
  let _witness : Gdk_enums.modifiertype = [ `NO_MODIFIER_MASK ] in
  (* Runtime: to_int of [`NO_MODIFIER_MASK] = fold (0 lor 0) = 0. *)
  let encoded = Gdk_enums.modifiertype_to_int [ `NO_MODIFIER_MASK ] in
  check int "NO_MODIFIER_MASK to_int is 0" 0 encoded

(** {2 Case 11 — Boxed GValue round-trip via gir_record bridge} *)

(** Create a [GdkRectangle] with known fields, store it in a GValue typed as
    [gdk_rectangle_get_type()], read it back via [get_boxed], and compare with
    the original using [Rectangle.equal]. [get_boxed] calls [g_boxed_copy]
    internally, so the returned value is a fresh copy; pointer identity is not
    expected and is not tested. *)
let test_boxed_rectangle_roundtrip () =
  let gtype_rect = gdk_rectangle_get_type () in
  let original = gdk_rectangle_create 10 20 30 40 in
  let v = Gobject.Value.create gtype_rect in
  Gobject.Value.set_boxed v original;
  let result = (Gobject.Value.get_boxed v : Rectangle.t) in
  check bool "boxed round-trip: result equals original via Rectangle.equal" true
    (Rectangle.equal result original)

(** {2 Test Suite} *)

let () =
  run "GValue enum/flags/variant/int64 wrappers"
    [
      ( "enum_gvalue",
        [
          test_case "enum round-trip via decoder" `Quick
            (require_gtk test_enum_roundtrip_via_decoder);
        ] );
      ( "flags_gvalue",
        [
          test_case "flags round-trip via decoder" `Quick
            (require_gtk test_flags_roundtrip_via_decoder);
          test_case "flags empty list" `Quick
            (require_gtk test_flags_empty_list);
        ] );
      ( "variant_gvalue",
        [ test_case "variant round-trip" `Quick test_variant_roundtrip ] );
      ( "int64_gvalue",
        [ test_case "int64 round-trip" `Quick test_int64_roundtrip ] );
      ( "enum_decoder",
        [
          test_case "enum decoder fails on out-of-range int" `Quick
            test_enum_decoder_fails_on_out_of_range;
          test_case "enum decoder: of_int o to_int = id" `Quick
            test_enum_of_int_to_int_identity;
        ] );
      ( "bitfield_decoder",
        [
          test_case "bitfield decoder: of_int o to_int preserves set" `Quick
            test_bitfield_of_int_to_int_preserves_set;
        ] );
      ( "negative",
        [
          test_case "wrong GValue type raises Invalid_argument" `Quick
            (require_gtk test_wrong_gvalue_type_raises);
        ] );
      ( "version_guarded",
        [
          test_case "NO_MODIFIER_MASK compile-time check" `Quick
            test_version_guarded_no_modifier_mask_compile_time;
        ] );
      ( "boxed_gvalue",
        [
          test_case "boxed round-trip via gir_record bridge" `Quick
            (require_gtk test_boxed_rectangle_roundtrip);
        ] );
    ]
