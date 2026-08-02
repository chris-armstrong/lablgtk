(* Button Widget Tests *)

open Alcotest
open Ocgtk_gtk.Gtk
module Helpers = Gtk_test_helpers

let require_gtk = Helpers.require_gtk
let require_gtk_412 f = require_gtk (Helpers.require_gtk_version 4 12 0 f)

(* Test button creation and basic properties *)
let test_button_creation () =
  let btn = Wrappers.Button.new_ () in
  check bool "button created" true (Gobject.get_ref_count btn > 0);
  Wrappers.Button.set_label btn "Test Button";
  check (option string) "button label" (Some "Test Button")
    (Wrappers.Button.get_label btn);
  Wrappers.Button.set_has_frame btn false;
  check bool "button has_frame" false (Wrappers.Button.get_has_frame btn)

let test_button_with_label () =
  let btn = Wrappers.Button.new_with_label "Click me" in
  check (option string) "button label from constructor" (Some "Click me")
    (Wrappers.Button.get_label btn)

let test_button_with_mnemonic () =
  let btn = Wrappers.Button.new_with_mnemonic "_File" in
  check (option string) "button mnemonic label" (Some "_File")
    (Wrappers.Button.get_label btn);
  Wrappers.Button.set_use_underline btn true;
  check bool "button use_underline" true (Wrappers.Button.get_use_underline btn)

let test_button_icon_name () =
  let btn = Wrappers.Button.new_from_icon_name "document-open" in
  check (option string) "button icon_name" (Some "document-open")
    (Wrappers.Button.get_icon_name btn);
  Wrappers.Button.set_icon_name btn "document-save";
  check (option string) "button icon changed" (Some "document-save")
    (Wrappers.Button.get_icon_name btn)

let test_button_properties () =
  let btn = Wrappers.Button.new_ () in
  Wrappers.Button.set_can_shrink btn true;
  check bool "can_shrink set" true (Wrappers.Button.get_can_shrink btn);
  Wrappers.Button.set_can_shrink btn false;
  check bool "can_shrink unset" false (Wrappers.Button.get_can_shrink btn)

let test_check_button_creation () =
  let btn = Wrappers.Check_button.new_ () in
  check bool "check button created" true (Gobject.get_ref_count btn > 0);
  check bool "check button initial active" false
    (Wrappers.Check_button.get_active btn);
  Wrappers.Check_button.set_active btn true;
  check bool "check button activated" true
    (Wrappers.Check_button.get_active btn)

let test_check_button_with_label () =
  let btn = Wrappers.Check_button.new_with_label (Some "Enable feature") in
  check (option string) "check button label" (Some "Enable feature")
    (Wrappers.Check_button.get_label btn)

let test_check_button_grouping () =
  (* Test nullable parameter support - set_group accepts widget option *)
  let btn1 = Wrappers.Check_button.new_ () in
  let btn2 = Wrappers.Check_button.new_ () in
  (* Group btn2 with btn1 - btn1 is the group leader *)
  Wrappers.Check_button.set_group btn2 (Some btn1);
  (* Set btn1 active *)
  Wrappers.Check_button.set_active btn1 true;
  check bool "btn1 is active" true (Wrappers.Check_button.get_active btn1)

let test_check_button_inconsistent () =
  let btn = Wrappers.Check_button.new_ () in
  Wrappers.Check_button.set_inconsistent btn true;
  check bool "check button inconsistent" true
    (Wrappers.Check_button.get_inconsistent btn);
  Wrappers.Check_button.set_inconsistent btn false;
  check bool "check button not inconsistent" false
    (Wrappers.Check_button.get_inconsistent btn)

let test_toggle_button_creation () =
  let btn = Wrappers.Toggle_button.new_ () in
  check bool "toggle button created" true (Gobject.get_ref_count btn > 0);
  check bool "toggle button initial active" false
    (Wrappers.Toggle_button.get_active btn)

let test_toggle_button_with_label () =
  let btn = Wrappers.Toggle_button.new_with_label "Toggle me" in
  Wrappers.Toggle_button.set_active btn true;
  check bool "toggle button activated" true
    (Wrappers.Toggle_button.get_active btn)

let test_toggle_button_toggled () =
  (* Note: gtk_toggle_button_toggled() emits the "toggled" signal but
     does NOT change the active state. To change state, use set_active. *)
  let btn = Wrappers.Toggle_button.new_ () in
  Wrappers.Toggle_button.set_active btn false;
  (* Call toggled - it should emit signal but not change state *)
  Wrappers.Toggle_button.toggled btn;
  check bool "toggle button state unchanged after toggled" false
    (Wrappers.Toggle_button.get_active btn);
  (* Try with active=true *)
  Wrappers.Toggle_button.set_active btn true;
  Wrappers.Toggle_button.toggled btn;
  check bool "toggle button state still true after toggled" true
    (Wrappers.Toggle_button.get_active btn)

let test_high_level_button () =
  let obj = Wrappers.Button.new_ () in
  Wrappers.Button.set_label obj "Click me";
  Wrappers.Button.set_has_frame obj true;
  let btn = new Button.button obj in
  check (option string) "GButton label" (Some "Click me") (btn#get_label ());
  btn#set_label "Updated";
  check (option string) "GButton label updated" (Some "Updated")
    (btn#get_label ());
  btn#set_has_frame false;
  check bool "GButton has_frame" false (btn#get_has_frame ())

let test_high_level_button_with_icon () =
  let obj = Wrappers.Button.new_ () in
  Wrappers.Button.set_icon_name obj "document-open";
  let btn = new Button.button obj in
  check (option string) "GButton icon" (Some "document-open")
    (btn#get_icon_name ());
  btn#set_icon_name "document-save";
  check (option string) "GButton icon changed" (Some "document-save")
    (btn#get_icon_name ())

let () =
  run "Button Tests"
    [
      ( "low_level_button",
        [
          test_case "button_creation" `Quick (require_gtk test_button_creation);
          test_case "button_with_label" `Quick
            (require_gtk test_button_with_label);
          test_case "button_with_mnemonic" `Quick
            (require_gtk test_button_with_mnemonic);
          test_case "button_icon_name" `Quick
            (require_gtk test_button_icon_name);
          test_case "button_properties" `Quick
            (require_gtk_412 test_button_properties);
        ] );
      ( "low_level_check_button",
        [
          test_case "check_button_creation" `Quick
            (require_gtk test_check_button_creation);
          test_case "check_button_with_label" `Quick
            (require_gtk test_check_button_with_label);
          test_case "check_button_grouping" `Quick
            (require_gtk test_check_button_grouping);
          test_case "check_button_inconsistent" `Quick
            (require_gtk test_check_button_inconsistent);
        ] );
      ( "low_level_toggle_button",
        [
          test_case "toggle_button_creation" `Quick
            (require_gtk test_toggle_button_creation);
          test_case "toggle_button_with_label" `Quick
            (require_gtk test_toggle_button_with_label);
          test_case "toggle_button_toggled" `Quick
            (require_gtk test_toggle_button_toggled);
        ] );
      ( "high_level",
        [
          test_case "gbutton" `Quick (require_gtk test_high_level_button);
          test_case "gbutton_icon" `Quick
            (require_gtk test_high_level_button_with_icon);
        ] );
    ]
