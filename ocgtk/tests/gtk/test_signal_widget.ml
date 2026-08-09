(** Runtime tests for wired widget signals (L1 + L2 class methods).

    Exercises Button.on_clicked, CheckButton.on_toggled, Notebook.on_page_added,
    Window.on_close_request, and EventControllerKey.on_key_pressed against real
    GTK widgets. Must be run under xvfb-run because all tests need a GTK
    display. *)

open Alcotest
open Ocgtk_gtk.Gtk
module Helpers = Gtk_test_helpers
module Gdk_enums = Ocgtk_gdk.Gdk_enums

let require_gtk = Helpers.require_gtk

external emit_key_pressed_signal :
  Wrappers.Event_controller_key.t -> int -> int -> int -> bool
  = "ml_test_emit_key_pressed_signal"
(** Emit "key-pressed" signal on an EventControllerKey via C stub. Returns the
    boolean result of the signal handler chain. *)

(** {2 Test 0: Signal disconnect} *)

let test_signal_disconnect () =
  let btn_obj = Wrappers.Button.new_ () in
  let btn = new Button.button btn_obj in
  let called = ref false in
  let handler_id = btn#on_clicked ~callback:(fun () -> called := true) () in
  (* Emit signal -- handler should fire *)
  Gobject.Signal.emit_by_name btn_obj ~name:"clicked";
  check bool "callback invoked before disconnect" true !called;
  (* Disconnect and reset *)
  called := false;
  Gobject.Signal.disconnect btn_obj handler_id;
  (* Emit again -- handler should NOT fire *)
  Gobject.Signal.emit_by_name btn_obj ~name:"clicked";
  check bool "callback not invoked after disconnect" false !called

(** {2 Test 1: Button clicked (simple)} *)

let test_button_clicked () =
  let btn_obj = Wrappers.Button.new_ () in
  let btn = new Button.button btn_obj in
  let called = ref false in
  ignore (btn#on_clicked ~callback:(fun () -> called := true) ());
  Gobject.Signal.emit_by_name btn_obj ~name:"clicked";
  check bool "callback was invoked" true !called

(** {2 Test 2: Button clicked after} *)

let test_button_clicked_after () =
  let btn_obj = Wrappers.Button.new_ () in
  let btn = new Button.button btn_obj in
  let order = ref [] in
  ignore (btn#on_clicked ~callback:(fun () -> order := "first" :: !order) ());
  ignore
    (btn#on_clicked ~after:true
       ~callback:(fun () -> order := "second" :: !order)
       ());
  Gobject.Signal.emit_by_name btn_obj ~name:"clicked";
  check (list string) "handlers fire in order: second then first"
    [ "second"; "first" ] !order

(** {2 Test 3: CheckButton toggled} *)

let test_check_button_toggled () =
  let btn_obj = Wrappers.Check_button.new_ () in
  let btn = new Check_button.check_button btn_obj in
  Wrappers.Check_button.set_active btn_obj false;
  let called = ref false in
  ignore (btn#on_toggled ~callback:(fun () -> called := true) ());
  Wrappers.Check_button.set_active btn_obj true;
  check bool "toggled callback was invoked" true !called;
  check bool "check button is active" true
    (Wrappers.Check_button.get_active btn_obj)

(** {2 Test 4: Notebook page-added} *)

let test_page_added () =
  let nb_obj = Wrappers.Notebook.new_ () in
  let nb = new Notebook.notebook nb_obj in
  let btn_obj = Wrappers.Button.new_ () in
  let child_obj : Wrappers.Widget.t = (btn_obj :> Wrappers.Widget.t) in
  let captured_child = ref None in
  let captured_page_num = ref 0 in
  ignore
    (nb#on_page_added
       ~callback:(fun ~child ~page_num ->
         captured_child := Some child;
         captured_page_num := page_num)
       ());
  let _page_num = Wrappers.Notebook.append_page nb_obj child_obj None in
  let child_matches =
    match !captured_child with Some _ -> true | None -> false
  in
  check bool "page-added child is Some" true child_matches;
  check int "page_num is 0" 0 !captured_page_num

(** {2 Test 5: Window close-request} *)

let test_close_request () =
  let win_obj = Wrappers.Window.new_ () in
  let win = new Window.window win_obj in
  let handler_id = win#on_close_request ~callback:(fun () -> false) () in
  (* Verify handler was connected (handler_id > 0 means success).
     Note: we only test handler registration here because emitting
     close-request on an unrealized window does not invoke callbacks,
     and g_signal_emit_by_name does not handle boolean-return signals. *)
  check bool "close-request handler connected" true
    (Int.compare handler_id 0 > 0)

(** {2 Test 6: EventControllerKey key-pressed (cross-namespace)} *)

let test_key_pressed_cross_namespace () =
  let ctrl_obj = Wrappers.Event_controller_key.new_ () in
  let ctrl = new Event_controller_key.event_controller_key ctrl_obj in
  let captured_keyval = ref 0 in
  let captured_keycode = ref 0 in
  let captured_state = ref [] in
  ignore
    (ctrl#on_key_pressed
       ~callback:(fun ~keyval ~keycode ~state ->
         captured_keyval := keyval;
         captured_keycode := keycode;
         captured_state := state;
         true)
       ());
  let result =
    emit_key_pressed_signal ctrl_obj 97 12
      (Gdk_enums.modifiertype_to_int [ `SHIFT_MASK ])
  in
  check bool "key-pressed signal returns true" true result;
  check int "keyval captured" 97 !captured_keyval;
  check int "keycode captured" 12 !captured_keycode;
  check bool "state contains SHIFT_MASK" true
    (List.mem `SHIFT_MASK !captured_state)

let () =
  run "Signal Widget"
    [
      ( "button",
        [
          test_case "signal disconnect" `Quick
            (require_gtk test_signal_disconnect);
          test_case "button clicked" `Quick (require_gtk test_button_clicked);
          test_case "button clicked after" `Quick
            (require_gtk test_button_clicked_after);
        ] );
      ( "check_button",
        [
          test_case "check button toggled" `Quick
            (require_gtk test_check_button_toggled);
        ] );
      ( "notebook",
        [ test_case "page added" `Quick (require_gtk test_page_added) ] );
      ( "window",
        [ test_case "close request" `Quick (require_gtk test_close_request) ] );
      ( "event_controller_key",
        [
          test_case "key pressed cross-namespace" `Quick
            (require_gtk test_key_pressed_cross_namespace);
        ] );
    ]
