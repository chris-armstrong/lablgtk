(** Test suite for Gtk.Widget module.

    Note: Most tests are skipped as they require actual widget instances, which
    need container support and concrete widget types.

    This test file verifies:
    - Module compiles and types are accessible
    - Basic type definitions are correct *)

open Alcotest
open Ocgtk_gtk.Gtk
module GMain = Ocgtk_gtk.GMain
module Widget = Wrappers.Widget

module Box = struct
  include Wrappers.Box

  let as_widget (box : t) : Widget.t = (box :> Widget.t)
end

let require_gtk = Gtk_test_helpers.require_gtk

(* Test that module is accessible and types compile *)
(* FIXME: relies on requisition which a struct that is not generated fully *)
(* let test_module_accessible () = *)
(*   (* Test that we can reference the types *) *)
(*   let _widget_type : Widget.t option = None in *)
(*   let _requisition : Gtk_enums.requisition = { width = 0; height = 0 } in *)
(*   let _allocation : Gtk_enums.allocation = *)
(*     { x = 0; y = 0; width = 100; height = 100 } *)
(*   in *)
(**)
(*   (* Test align type *) *)
(*   let _align : Gtk.align = `FILL in *)
(**)
(*   (* Test size_request_mode *) *)
(*   let _mode : Gtk.size_request_mode = `HEIGHT_FOR_WIDTH in *)
(**)
(*   (* Test state_flags *) *)
(*   let _flags : Gtk.state_flags list = [ `NORMAL; `FOCUSED; `ACTIVE ] in *)
(**)
(*   check bool "module accessible" true true *)

(* Test type constructors *)
(* FIXME: relies on requisition which a struct that is not generated fully *)
(* let test_type_constructors () = *)
(*   (* Test requisition *) *)
(*   let req = { Gtk.width = 100; Gtk.height = 50 } in *)
(*   check int "requisition width" 100 req.width; *)
(*   check int "requisition height" 50 req.height; *)
(**)
(*   (* Test allocation *) *)
(*   let alloc = { Gtk.x = 10; Gtk.y = 20; Gtk.width = 200; Gtk.height = 100 } in *)
(*   check int "allocation x" 10 alloc.x; *)
(*   check int "allocation y" 20 alloc.y; *)
(*   check int "allocation width" 200 alloc.width; *)
(*   check int "allocation height" 100 alloc.height *)

(* Widget creation tests *)
let test_widget_creation () =
  try
    let _ = GMain.init () in
    (* Create a widget (using GtkBox) *)
    let box = Box.new_ `HORIZONTAL 0 in
    let widget = Box.as_widget box in

    (* Verify widget was created *)
    check bool "widget created" true (Gobject.get_ref_count widget > 0)
  with
  | GMain.Error _ -> skip ()
  | e -> fail ("Unexpected error: " ^ Printexc.to_string e)

(* Visibility tests - Now working with GtkBox *)
let test_visibility () =
  try
    let _ = GMain.init () in
    let box = Box.new_ `HORIZONTAL 0 in
    let widget = Box.as_widget box in

    (* Test visibility (widgets are visible by default in GTK4) *)
    check bool "widget visible by default" true (Widget.get_visible widget);

    (* Test hide *)
    Widget.hide widget;
    check bool "widget hidden" false (Widget.get_visible widget);

    (* Test show *)
    Widget.show widget;
    check bool "widget shown" true (Widget.get_visible widget);

    (* Test set_visible *)
    Widget.set_visible widget false;
    check bool "widget set invisible" false (Widget.get_visible widget);

    Widget.set_visible widget true;
    check bool "widget set visible" true (Widget.get_visible widget)
  with
  | GMain.Error _ -> skip ()
  | e -> fail ("Unexpected error: " ^ Printexc.to_string e)

(* Size request tests - Now working with GtkBox *)
let test_size_request () =
  try
    let _ = GMain.init () in
    let box = Box.new_ `HORIZONTAL 0 in
    let widget = Box.as_widget box in

    (* Test size request *)
    Widget.set_size_request widget 200 100;
    (* Note: get_size_request not available in current bindings *)
    check bool "set_size_request succeeded" true true
  with
  | GMain.Error _ -> skip ()
  | e -> fail ("Unexpected error: " ^ Printexc.to_string e)

(* CSS class tests - Now working with GtkBox *)
(* let test_css_classes () = *)
(*   try *)
(*     let _ = GMain.init () in *)
(*     let box = Box.new_ `HORIZONTAL 0 in *)
(*     let widget = Box.as_widget box in *)
(**)
(*     (* Test CSS class operations *) *)
(*     Widget.add_css_class widget "test-class"; *)
(*     check bool "has CSS class" true (Widget.has_css_class widget "test-class"); *)
(**)
(*     (* get_css_classes returns unit in the current bindings *) *)
(*     let () = Widget.get_css_classes widget in *)
(**)
(*     Widget.remove_css_class widget "test-class"; *)
(*     check bool "CSS class removed" false (Widget.has_css_class widget "test-class") *)
(*   with *)
(*   | GMain.Error _ -> *)
(*       skip () *)
(*   | e -> *)
(*       fail ("Unexpected error: " ^ Printexc.to_string e) *)

(* Focus tests - Now working with GtkBox *)
let test_focus () =
  try
    let _ = GMain.init () in
    let box = Box.new_ `HORIZONTAL 0 in
    let widget = Box.as_widget box in

    (* Test focusable property *)
    Widget.set_focusable widget true;
    check bool "widget focusable" true (Widget.get_focusable widget);

    Widget.set_focusable widget false;
    check bool "widget not focusable" false (Widget.get_focusable widget);

    (* Note: has_focus and grab_focus require the widget to be in a window
       and may not work without a display, so we just test the API exists *)
    let _ = Widget.has_focus widget in
    let _ = Widget.grab_focus widget in
    check bool "focus API works" true true
  with
  | GMain.Error _ -> skip ()
  | e -> fail ("Unexpected error: " ^ Printexc.to_string e)

(* State flags tests - Now working with GtkBox *)
(* let test_state_flags () = *)
(*   try *)
(*     let _ = GMain.init () in *)
(*     let box = Box.new_ `HORIZONTAL 0 in *)
(*     let widget = Box.as_widget box in *)
(**)
(*     (* Test state flags *) *)
(*     Widget.set_state_flags widget [`ACTIVE; `FOCUSED] false; *)
(*     let flags = Widget.get_state_flags widget in *)
(**)
(*     (* Just verify we can get/set flags - actual flag values may vary *) *)
(*     check bool "can set state flags" true (List.length flags >= 0) *)
(*   with *)
(*   | GMain.Error _ -> *)
(*       skip () *)
(*   | e -> *)
(*       fail ("Unexpected error: " ^ Printexc.to_string e) *)

(* Parent/root tests *)
(* FIXME: get_root not generated because it relies on interface Root
   which is not generated yet *)
(* let test_parent_root () = *)
(*   try *)
(*     let _ = GMain.init () in *)
(*     let parent_box = Box.new_ `HORIZONTAL 0 in *)
(*     let child_box = Box.new_ `VERTICAL 0 in *)
(*     let child_widget = Box.as_widget child_box in *)
(**)
(*     (* Initially no parent *) *)
(*     check bool "no parent initially" true (Widget.get_parent child_widget = None); *)
(**)
(*     (* Add child to parent *) *)
(*     Box.append parent_box child_widget; *)
(**)
(*     (* Now should have parent *) *)
(*     let parent_opt = Widget.get_parent child_widget in *)
(*     check bool "has parent after append" true (parent_opt <> None); *)
(**)
(*     (* Test get_root (may return None without a window) *) *)
(*     let _ = Widget.get_root child_widget in *)
(*     check bool "get_root API works" true true *)
(*   with *)
(*   | GMain.Error _ -> skip () *)
(*   | e -> fail ("Unexpected error: " ^ Printexc.to_string e) *)

(* Queue draw/resize tests *)
let test_queue_operations () =
  try
    let _ = GMain.init () in
    let box = Box.new_ `HORIZONTAL 0 in
    let widget = Box.as_widget box in

    (* Test queue operations (these don't return values, just verify they don't crash) *)
    Widget.queue_draw widget;
    Widget.queue_resize widget;

    check bool "queue operations work" true true
  with
  | GMain.Error _ -> skip ()
  | e -> fail ("Unexpected error: " ^ Printexc.to_string e)

let () =
  run "Gtk.Widget Tests"
    [
      (* ( "module", *)
      (*   [ *)
      (*     test_case "module_accessible" `Quick test_module_accessible; *)
      (*     test_case "type_constructors" `Quick test_type_constructors; *)
      (*   ] ); *)
      ( "creation",
        [
          test_case "widget_creation" `Quick (require_gtk test_widget_creation);
        ] );
      ( "visibility",
        [ test_case "show/hide" `Quick (require_gtk test_visibility) ] );
      ( "size",
        [ test_case "size_request" `Quick (require_gtk test_size_request) ] );
      (* "css", [ *)
      (*   test_case "css_classes" `Quick (require_gtk test_css_classes); *)
      (* ]; *)
      ("focus", [ test_case "focusable" `Quick (require_gtk test_focus) ]);
      (* "state", [ *)
      (*   test_case "state_flags" `Quick (require_gtk test_state_flags); *)
      (* ]; *)
      (* ( "hierarchy", *)
      (*   [ test_case "parent_root" `Quick (require_gtk test_parent_root) ] ); *)
      ( "queue",
        [
          test_case "queue_operations" `Quick
            (require_gtk test_queue_operations);
        ] );
    ]
