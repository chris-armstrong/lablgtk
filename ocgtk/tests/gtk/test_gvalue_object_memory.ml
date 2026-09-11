(** Ownership and reference-counting tests for the GValue <-> GObject bridge.

    [ml_g_value_get_object] wraps a transfer-none (borrowed) GObject pointer in
    an OCaml custom block whose finalizer unconditionally [g_object_unref]s. The
    only way that unref stays balanced is for the getter to [g_object_ref]
    before wrapping; these tests pin down the full ownership chain by observing
    [Gobject.get_ref_count] deltas:

    - constructor: the OCaml wrapper owns exactly one reference
    - [Value.set_object]: the GValue takes its own reference
    - [Value.get_object]: must add one more reference (the borrowed pointer
      otherwise has no ref of its own, and the wrapper finalizer would steal one
      from the GValue or the widget's parent)
    - OCaml GC of the wrapper / GValue: must release exactly the references
      taken, never fewer, never more

    The parent-owned-child case is the regression test for the original bug: a
    child widget's reference stolen by an unbalanced finalizer unref gets
    destroyed while its container still holds it. *)

open Alcotest
open Ocgtk_gtk.Gtk
module Widget = Wrappers.Widget
module Value = Gobject.Value
module Type = Gobject.Type

let require_gtk = Gtk_test_helpers.require_gtk
let rc obj = Gobject.get_ref_count obj

(** Custom-block finalizers run during major collections. A second cycle covers
    values kept alive by the first cycle's allocations. *)
let collect () =
  Gc.full_major ();
  Gc.full_major ()

let check_rc label expected obj = check int label expected (rc obj)

(* Cell for pinning a GValue across [collect ()]. It must be module-level:
   a local [ref] never escapes its scope, so the compiler promotes it to a
   stack slot, whose liveness ends at the binding's last use — the very
   GC-safety assumption under test. A global binding is a GC root. *)
let gvalue_holder : Gobject.Value.t option ref = ref None

let drop_target () =
  Wrappers.Drop_target.new_ (Gobject.Type.from_name "gchararray") []

(** [g_value_get_object] must add a reference of its own on top of the GValue's,
    and the OCaml wrapper's finalizer must release exactly that reference once
    collected. *)
let test_get_object_takes_its_own_reference () =
  let obj = drop_target () in
  let base = rc obj in
  (* Pin the GValue in a GC-rooted cell so that [collect ()] below can only
     finalize the fetched wrapper: its finalizer must unref exactly once,
     while the GValue keeps holding its own reference. *)
  let scoped () =
    let v = Value.create Type.object_ in
    Value.set_object_exn v Type.object_ obj;
    check_rc "set_object adds the GValue's own reference" (base + 1) obj;
    let fetched = Value.get_object_exn v Type.object_ in
    check bool "get_object returns the same GObject" true
      (Gobject.same fetched obj);
    check_rc "get_object takes its own reference (transfer none honored)"
      (base + 2) obj;
    gvalue_holder := Some v
  in
  scoped ();
  collect ();
  check_rc "wrapper finalizer released exactly one reference" (base + 1) obj;
  gvalue_holder := None;
  collect ();
  check_rc "GValue finalizer releases its own reference" base obj

(** After the wrapper and the GValue are both collected, the object must be back
    to its pre-GValue reference count: every reference taken through the bridge
    was returned. *)
let test_gvalue_object_lifecycle_returns_to_baseline () =
  let obj = drop_target () in
  let base = rc obj in
  let scoped () =
    let v = Value.create Type.object_ in
    Value.set_object_exn v Type.object_ obj;
    ignore (Value.get_object_exn v Type.object_);
    ()
  in
  scoped ();
  collect ();
  check_rc "all bridge references released after GC" base obj

(** The regression scenario: a child owned by a container. A stolen reference
    here means the container is left holding a dangling pointer once the OCaml
    side lets go, and the child is destroyed out from under the live container.
*)
let test_parent_owned_child_survives_gvalue_gc () =
  let box = Wrappers.Box.new_ `HORIZONTAL 0 in
  let child = Wrappers.Button.new_ () in
  Wrappers.Button.set_label child "do-not-steal-my-ref";
  let base = rc child in
  Wrappers.Box.append box (child :> Widget.t);
  check_rc "append gives the container its own reference" (base + 1) child;
  let scoped () =
    let v = Value.create Type.object_ in
    Value.set_object_exn v Type.object_ child;
    let fetched = Value.get_object_exn v Type.object_ in
    check bool "child round-trips through the GValue" true
      (Gobject.same fetched child);
    check_rc "get_object refs the parent-owned child" (base + 3) child
  in
  scoped ();
  collect ();
  check_rc "borrowed refs returned; container ref intact" (base + 1) child;
  (* Aliveness must not depend on our reference: the box still owns a live
     child and can hand it back out. *)
  (match Widget.get_first_child (box :> Widget.t) with
  | None -> fail "box lost its first child (ref was stolen)"
  | Some first ->
      check bool "first child is the same button" true
        (Gobject.same first child));
  (* And the child is still functional. *)
  check (option string) "child still usable after bridge GC"
    (Some "do-not-steal-my-ref")
    (Wrappers.Button.get_label child)

(** [g_object_get_property] auto-initializes an empty (zero-filled) GValue since
    GLib 2.60, behind this binding's back. For object-valued properties the
    getter stores its own reference; the GValue finalizer must still unset such
    values or that reference leaks. *)
let test_property_get_into_empty_value_releases_reference () =
  let window = Wrappers.Window.new_ () in
  let child = Wrappers.Button.new_ () in
  Wrappers.Window.set_child window (Some (child :> Widget.t));
  let base = rc child in
  let scoped () =
    let v = Value.create_empty () in
    Gobject.Property.get_value window ~name:"child" v;
    let expected = Gobject.Property.get_type window ~name:"child" in
    check bool "GLib auto-initialized the empty GValue" true
      (Gobject.Type.equal (Value.get_type v) expected);
    check_rc "auto-initialized value holds a reference to the child" (base + 1)
      child
  in
  scoped ();
  collect ();
  check_rc "finalizer unsets GLib-initialized values (no leaked ref)" base child

let () =
  Alcotest.run "GValue object memory"
    [
      ( "transfer semantics",
        [
          Alcotest.test_case "get_object takes its own reference" `Quick
            (require_gtk test_get_object_takes_its_own_reference);
          Alcotest.test_case "lifecycle returns to baseline" `Quick
            (require_gtk test_gvalue_object_lifecycle_returns_to_baseline);
          Alcotest.test_case "parent-owned child survives GValue GC" `Quick
            (require_gtk test_parent_owned_child_survives_gvalue_gc);
          Alcotest.test_case "auto-initialized value finalizer" `Quick
            (require_gtk test_property_get_into_empty_value_releases_reference);
        ] );
    ]
