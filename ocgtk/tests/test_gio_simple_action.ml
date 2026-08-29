(** Regression tests for two GVariant lifetime bugs, both found while
    building a GTK menu bar of parameter-less [GSimpleAction]s:

    1. [GSimpleAction]'s "activate" signal legitimately carries a NULL
       [GVariant] parameter when the action was created with no parameter
       type ([Simple_action.new_ name None] -- every plain menu-item
       action). ocgtk's generated [on_activate] marshaller used to call
       [Gobject.Value.get_variant] unconditionally, which [caml_failwith]s
       on a NULL variant, so activating any such action always raised
       inside the marshaller -- silently eaten by the closure's own
       exception guard, making every menu click a no-op.

    2. Every [g_variant_new_*] constructor in [ml_gvariant.c] returns a
       FLOATING GVariant reference but wrapped it in [Val_GVariant]
       without sinking it first. [Val_GVariant]'s own contract requires a
       genuine transfer-full (non-floating) reference. Handing the
       resulting OCaml value to an API that itself calls
       [g_variant_ref_sink] on receipt (e.g. [GMenuItem#set_attribute_value])
       left BOTH the OCaml wrapper and that API believing they owned the
       single reference: the OCaml finalizer's [g_variant_unref] then
       dropped the count to 0 and freed memory the other owner still
       pointed at -- a delayed-onset use-after-free, not caught by any
       existing test because none of them hand a constructed variant to an
       external ref-sinking consumer before dropping the OCaml side. *)

open Alcotest
module Gio = Ocgtk_gio.Gio

let test_simple_action_no_parameter_activate () =
  let action = Gio.Simple_action.new_ "test-action" None in
  let received = ref `Not_called in
  let (_ : Gobject.Signal.handler_id) =
    action#on_activate
      ~callback:(fun ~parameter ->
        received := (match parameter with None -> `Called_none | Some _ -> `Called_some))
      ()
  in
  (* [action#activate] emits "activate" synchronously (it's the direct
     OCaml binding of [g_action_activate]) -- a parameter-less action's
     real GAction contract is a NULL parameter here. Before the fix this
     raised Failure("g_value_get_variant: NULL variant") inside the
     marshaller, before the callback ever ran. *)
  action#activate None;
  check bool "callback ran (activate did not raise)" true (!received <> `Not_called);
  check bool "parameter was None, not garbage/Some" true (!received = `Called_none)

let test_menu_item_accel_survives_gc_compact () =
  let item = Gio.Menu_item.new_ (Some "Test Item") (Some "win.test-action") in
  (* Deliberately not held onto beyond this call -- the whole point of the
     regression is that nothing outside [item] keeps the GVariant alive;
     [item] itself only holds a reference GMenuItem's own ref_sink took. *)
  item#set_attribute_value "accel" (Some (Gvariant.of_string "r"));
  Gc.compact ();
  Gc.compact ();
  match item#get_attribute_value "accel" None with
  | None -> Alcotest.fail "accel attribute vanished after Gc.compact"
  | Some v -> check string "accel attribute survives Gc.compact" "r" (Gvariant.to_string v)

let () =
  run "GIO SimpleAction/MenuItem GVariant lifetime"
    [ ( "simple_action"
      , [ test_case "parameter-less activation does not raise" `Quick
            test_simple_action_no_parameter_activate
        ] )
    ; ( "menu_item"
      , [ test_case "accel attribute survives Gc.compact" `Quick
            test_menu_item_accel_survives_gc_compact
        ] )
    ]
