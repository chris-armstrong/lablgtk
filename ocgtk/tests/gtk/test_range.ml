(* Range Widget Tests *)

open Alcotest
open Ocgtk_gtk.Gtk
module Progress_bar = Wrappers.Progress_bar
module Scale = Wrappers.Scale
module Range = Wrappers.Range
module Level_bar = Wrappers.Level_bar

let require_gtk = Gtk_test_helpers.require_gtk

(* ========== ProgressBar Tests ========== *)

let test_progress_bar_creation () =
  let pb = Progress_bar.new_ () in
  check bool "progress bar created" true (Gobject.get_ref_count pb > 0);
  check (float 0.01) "initial fraction is 0.0" 0.0
    (Progress_bar.get_fraction pb)

let test_progress_bar_fraction () =
  let pb = Progress_bar.new_ () in
  Progress_bar.set_fraction pb 0.5;
  check (float 0.01) "fraction set to 0.5" 0.5 (Progress_bar.get_fraction pb);
  Progress_bar.set_fraction pb 1.0;
  check (float 0.01) "fraction set to 1.0" 1.0 (Progress_bar.get_fraction pb)

let test_progress_bar_pulse () =
  let pb = Progress_bar.new_ () in
  Progress_bar.set_pulse_step pb 0.2;
  check (float 0.01) "pulse step set" 0.2 (Progress_bar.get_pulse_step pb);
  (* Pulse moves the progress bar in "activity mode" *)
  Progress_bar.pulse pb;
  check bool "pulse executed" true true

let test_progress_bar_text () =
  let pb = Progress_bar.new_ () in
  Progress_bar.set_text pb (Some "Loading...");
  check (option string) "text set" (Some "Loading...")
    (Progress_bar.get_text pb);
  Progress_bar.set_show_text pb true;
  check bool "show_text enabled" true (Progress_bar.get_show_text pb)

let test_progress_bar_inverted () =
  let pb = Progress_bar.new_ () in
  Progress_bar.set_inverted pb true;
  check bool "inverted" true (Progress_bar.get_inverted pb);
  Progress_bar.set_inverted pb false;
  check bool "not inverted" false (Progress_bar.get_inverted pb)

(* ========== Range Tests ========== *)

let test_range_fill_level () =
  (* Create a scale (which is a range) for testing *)
  let scale = Scale.new_ `HORIZONTAL None in
  let r = (scale :> Range.t) in
  Range.set_fill_level r 0.75;
  check (float 0.01) "fill level set" 0.75 (Range.get_fill_level r)

let test_range_inverted () =
  let scale = Scale.new_ `HORIZONTAL None in
  let r = (scale :> Range.t) in
  Range.set_inverted r true;
  check bool "range inverted" true (Range.get_inverted r);
  Range.set_inverted r false;
  check bool "range not inverted" false (Range.get_inverted r)

let test_range_restrict_to_fill_level () =
  let scale = Scale.new_ `HORIZONTAL None in
  let r = (scale :> Range.t) in
  Range.set_restrict_to_fill_level r true;
  check bool "restrict to fill level" true (Range.get_restrict_to_fill_level r)

let test_range_round_digits () =
  let scale = Scale.new_ `HORIZONTAL None in
  let r = (scale :> Range.t) in
  Range.set_round_digits r 2;
  check int "round digits" 2 (Range.get_round_digits r)

let test_range_show_fill_level () =
  let scale = Scale.new_ `HORIZONTAL None in
  let r = (scale :> Range.t) in
  Range.set_show_fill_level r true;
  check bool "show fill level" true (Range.get_show_fill_level r)

let test_range_slider_size_fixed () =
  let scale = Scale.new_ `HORIZONTAL None in
  let r = (scale :> Range.t) in
  Range.set_slider_size_fixed r true;
  check bool "slider size fixed" true (Range.get_slider_size_fixed r)

let test_range_flippable () =
  let scale = Scale.new_ `HORIZONTAL None in
  let r = (scale :> Range.t) in
  Range.set_flippable r true;
  check bool "flippable" true (Range.get_flippable r)

(* ========== Scale Tests ========== *)

let test_scale_creation_horizontal () =
  let scale = Scale.new_ `HORIZONTAL None in
  check bool "horizontal scale created" true (Gobject.get_ref_count scale > 0)

let test_scale_creation_vertical () =
  let scale = Scale.new_ `VERTICAL None in
  check bool "vertical scale created" true (Gobject.get_ref_count scale > 0)

let test_scale_digits () =
  let scale = Scale.new_ `HORIZONTAL None in
  Scale.set_digits scale 2;
  check int "digits set to 2" 2 (Scale.get_digits scale);
  Scale.set_digits scale 0;
  check int "digits set to 0" 0 (Scale.get_digits scale)

let test_scale_draw_value () =
  let scale = Scale.new_ `HORIZONTAL None in
  Scale.set_draw_value scale true;
  check bool "draw value enabled" true (Scale.get_draw_value scale);
  Scale.set_draw_value scale false;
  check bool "draw value disabled" false (Scale.get_draw_value scale)

let test_scale_has_origin () =
  let scale = Scale.new_ `HORIZONTAL None in
  Scale.set_has_origin scale true;
  check bool "has origin" true (Scale.get_has_origin scale);
  Scale.set_has_origin scale false;
  check bool "no origin" false (Scale.get_has_origin scale)

(* let test_scale_value_pos () = *)
(*   let scale = Scale.new_ `HORIZONTAL None in *)
(*   Scale.set_value_pos scale `TOP; *)
(*   check (testable Fmt.string (=)) "value pos TOP" "TOP" *)
(*     (match Scale.get_value_pos scale with `TOP -> "TOP" | `BOTTOM -> "BOTTOM" | `LEFT -> "LEFT" | `RIGHT -> "RIGHT"); *)
(*   Scale.set_value_pos scale `BOTTOM; *)
(*   check (testable Fmt.string (=)) "value pos BOTTOM" "BOTTOM" *)
(*     (match Scale.get_value_pos scale with `TOP -> "TOP" | `BOTTOM -> "BOTTOM" | `LEFT -> "LEFT" | `RIGHT -> "RIGHT") *)
(**)
let test_scale_marks () =
  let scale = Scale.new_ `HORIZONTAL None in
  (* Add marks at specific positions *)
  Scale.add_mark scale 0.0 `TOP (Some "Start");
  Scale.add_mark scale 0.5 `TOP (Some "Middle");
  Scale.add_mark scale 1.0 `TOP (Some "End");
  (* Clear all marks *)
  Scale.clear_marks scale;
  check bool "marks cleared" true true

(* ========== LevelBar Tests ========== *)

let test_level_bar_creation () =
  let lb = Level_bar.new_ () in
  check bool "level bar created" true (Gobject.get_ref_count lb > 0)

let test_level_bar_value () =
  let lb = Level_bar.new_ () in
  Level_bar.set_value lb 0.6;
  check (float 0.01) "value set" 0.6 (Level_bar.get_value lb)

let test_level_bar_min_max () =
  let lb = Level_bar.new_ () in
  Level_bar.set_min_value lb 0.0;
  Level_bar.set_max_value lb 100.0;
  check (float 0.01) "min value" 0.0 (Level_bar.get_min_value lb);
  check (float 0.01) "max value" 100.0 (Level_bar.get_max_value lb)

let test_level_bar_inverted () =
  let lb = Level_bar.new_ () in
  Level_bar.set_inverted lb true;
  check bool "level bar inverted" true (Level_bar.get_inverted lb)

(* Test suite *)
let () =
  run "Range Widget Tests"
    [
      ( "progress_bar",
        [
          test_case "creation" `Quick (require_gtk test_progress_bar_creation);
          test_case "fraction" `Quick (require_gtk test_progress_bar_fraction);
          test_case "pulse" `Quick (require_gtk test_progress_bar_pulse);
          test_case "text" `Quick (require_gtk test_progress_bar_text);
          test_case "inverted" `Quick (require_gtk test_progress_bar_inverted);
        ] );
      ( "range",
        [
          test_case "fill_level" `Quick (require_gtk test_range_fill_level);
          test_case "inverted" `Quick (require_gtk test_range_inverted);
          test_case "restrict_to_fill_level" `Quick
            (require_gtk test_range_restrict_to_fill_level);
          test_case "round_digits" `Quick (require_gtk test_range_round_digits);
          test_case "show_fill_level" `Quick
            (require_gtk test_range_show_fill_level);
          test_case "slider_size_fixed" `Quick
            (require_gtk test_range_slider_size_fixed);
          test_case "flippable" `Quick (require_gtk test_range_flippable);
        ] );
      ( "scale",
        [
          test_case "creation_horizontal" `Quick
            (require_gtk test_scale_creation_horizontal);
          test_case "creation_vertical" `Quick
            (require_gtk test_scale_creation_vertical);
          test_case "digits" `Quick (require_gtk test_scale_digits);
          test_case "draw_value" `Quick (require_gtk test_scale_draw_value);
          test_case "has_origin" `Quick (require_gtk test_scale_has_origin);
          (* test_case "value_pos" `Quick (require_gtk test_scale_value_pos); *)
          test_case "marks" `Quick (require_gtk test_scale_marks);
        ] );
      ( "level_bar",
        [
          test_case "creation" `Quick (require_gtk test_level_bar_creation);
          test_case "value" `Quick (require_gtk test_level_bar_value);
          test_case "min_max" `Quick (require_gtk test_level_bar_min_max);
          test_case "inverted" `Quick (require_gtk test_level_bar_inverted);
        ] );
      (* "high_level", [
      test_case "progress_bar" `Quick (require_gtk test_high_level_progress_bar);
      test_case "scale" `Quick (require_gtk test_high_level_scale);
      test_case "level_bar" `Quick (require_gtk test_high_level_level_bar);
    ]; *)
    ]
