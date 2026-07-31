(* Signal_gen pure-data API unit tests.
   All 14 test cases from the Phase 2 plan — replaces the 4 old tests
   that called the now-removed generate_signal_class function. *)

open Containers
open Gir_gen_lib.Types
module Signal_gen = Gir_gen_lib.Generate.Signal_gen
module Signal_marshaller = Gir_gen_lib.Generate.Signal_marshaller

(* ========================================================================= *)
(* Shared context builders                                                    *)
(* ========================================================================= *)

(** Minimal Gtk namespace context — no entities. *)
let gtk_ctx () =
  Type_factory.make_generation_context
    ~namespace:
      (Type_factory.make_gir_namespace ~namespace_name:"Gtk"
         ~namespace_version:"4.0" ~namespace_shared_library:"libgtk-4.so.1"
         ~namespace_c_identifier_prefixes:"Gtk"
         ~namespace_c_symbol_prefixes:"gtk" ())
    ()

(** Gtk context with a cross-namespace Gdk.ModifierType bitfield. *)
let gtk_ctx_with_gdk_modifiertype () =
  let gdk_entities =
    StringMap.empty
    |> StringMap.add "ModifierType"
         (Type_factory.make_cross_reference_entity ~cr_name:"ModifierType"
            ~cr_type:(Type_factory.make_cross_reference_type `Bitfield)
            ~cr_c_type:"GdkModifierType" ())
  in
  let cross_refs =
    Type_factory.make_cross_reference_map
      [ Helpers.make_ncr "Gdk" gdk_entities ]
  in
  { (gtk_ctx ()) with cross_references = cross_refs }

(* ========================================================================= *)
(* Shared signal builders                                                     *)
(* ========================================================================= *)

(** Void zero-param 'clicked' signal used in many tests. *)
let make_clicked_signal () =
  Type_factory.make_gir_signal ~signal_name:"clicked"
    ~return_type:Type_factory.void_type ()

(** Minimal Gtk context reused by tests that don't need entities. *)
let shared_ctx = gtk_ctx ()

(* ========================================================================= *)
(* Result-check helpers                                                       *)
(* ========================================================================= *)

let expect_ok label result f =
  match result with
  | Error reason ->
      Alcotest.failf "%s: expected Ok but got Error: %s" label reason
  | Ok v -> f v

let expect_error label result =
  match result with
  | Ok _ -> Alcotest.failf "%s: expected Error but got Ok" label
  | Error reason -> reason

(* ========================================================================= *)
(* Case 1: void zero-param signal uses connect_simple in L1 let              *)
(* ========================================================================= *)

let test_void_zero_param_emits_connect_simple_in_l1_let () =
  let ctx = shared_ctx in
  let signal = make_clicked_signal () in
  let emission =
    expect_ok "clicked classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  let l1_let = Signal_gen.emit_l1_let emission in
  let ast = Ml_ast_helpers.parse_implementation l1_let in
  Helpers.assert_some "on_clicked let binding"
    (Ml_ast_helpers.find_let_binding ast "on_clicked");
  (* The body must call Gobject.Signal.connect_simple *)
  Helpers.expect_some "on_clicked binding for body check"
    (Ml_ast_helpers.find_let_binding ast "on_clicked")
  @@ fun vb ->
  if
    not
      (Ml_ast_helpers.method_body_calls_function vb.pvb_expr "Gobject.Signal"
         "connect_simple")
  then Alcotest.fail "on_clicked body should call Gobject.Signal.connect_simple"

(* ========================================================================= *)
(* Case 2 (sig side): emit_l1_val for clicked signal                         *)
(* ========================================================================= *)

let test_void_zero_param_emits_val_in_l1_val () =
  let ctx = shared_ctx in
  let signal = make_clicked_signal () in
  let emission =
    expect_ok "clicked classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  let l1_val = Signal_gen.emit_l1_val ~current_class:"Button" emission in
  let ast = Ml_ast_helpers.parse_interface l1_val in
  Helpers.assert_some "val on_clicked in interface"
    (Ml_ast_helpers.find_value_declaration_sig ast "on_clicked")

(* ========================================================================= *)
(* Case 2: void signal with primitive params uses Closure.create             *)
(* ========================================================================= *)

let test_void_primitive_params_uses_closure_create () =
  let ctx = shared_ctx in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"pressed"
      ~return_type:Type_factory.void_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"n_press"
            ~param_type:Type_factory.gint_type ();
          Type_factory.make_gir_param ~param_name:"x"
            ~param_type:Type_factory.gdouble_type ();
          Type_factory.make_gir_param ~param_name:"y"
            ~param_type:Type_factory.gdouble_type ();
        ]
      ()
  in
  let emission =
    expect_ok "pressed classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  (* L1 let body must contain Gobject.Closure.create *)
  let l1_let = Signal_gen.emit_l1_let emission in
  let ast = Ml_ast_helpers.parse_implementation l1_let in
  Helpers.expect_some "on_pressed binding"
    (Ml_ast_helpers.find_let_binding ast "on_pressed")
  @@ fun vb ->
  if
    not
      (Ml_ast_helpers.method_body_calls_function vb.pvb_expr "Gobject.Closure"
         "create")
  then Alcotest.fail "on_pressed body should call Gobject.Closure.create";
  (* The l1_val callback type must have labelled params n_press:int, x:float, y:float *)
  let l1_val = Signal_gen.emit_l1_val ~current_class:"Button" emission in
  let val_ast = Ml_ast_helpers.parse_interface l1_val in
  Helpers.expect_some "on_pressed val declaration"
    (Ml_ast_helpers.find_value_declaration_sig val_ast "on_pressed")
  @@ fun vd ->
  let callback_type =
    Helpers.expect_some "callback labelled param in on_pressed sig"
      (Ml_ast_helpers.find_labelled_param vd.pval_type "callback")
      Fun.id
  in
  if
    not
      (Ml_ast_helpers.has_labelled_param_with_type callback_type "n_press" "int")
  then
    Alcotest.failf "callback type should have 'n_press:int'; type string: %s"
      (Ml_ast_helpers.core_type_to_string callback_type);
  if not (Ml_ast_helpers.has_labelled_param_with_type callback_type "x" "float")
  then
    Alcotest.failf "callback type should have 'x:float'; type string: %s"
      (Ml_ast_helpers.core_type_to_string callback_type);
  if not (Ml_ast_helpers.has_labelled_param_with_type callback_type "y" "float")
  then
    Alcotest.failf "callback type should have 'y:float'; type string: %s"
      (Ml_ast_helpers.core_type_to_string callback_type);
  (* Strategy must be Closure, not Connect_simple *)
  match emission.strategy with
  | `Closure -> ()
  | `Connect_simple ->
      Alcotest.fail "expected strategy=Closure but got Connect_simple"

(* ========================================================================= *)
(* Case 3: zero-param signal with bool return uses Closure.create            *)
(* ========================================================================= *)

let test_bool_return_zero_param_uses_closure_create () =
  let ctx = shared_ctx in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"close-request"
      ~return_type:Type_factory.gboolean_type ()
  in
  let emission =
    expect_ok "close-request classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  (match emission.strategy with
  | `Closure -> ()
  | `Connect_simple ->
      Alcotest.fail
        "close-request: expected strategy=Closure but got Connect_simple");
  let l1_let = Signal_gen.emit_l1_let emission in
  let ast = Ml_ast_helpers.parse_implementation l1_let in
  Helpers.expect_some "on_close_request binding"
    (Ml_ast_helpers.find_let_binding ast "on_close_request")
  @@ fun vb ->
  if
    not
      (Ml_ast_helpers.method_body_calls_function vb.pvb_expr "Gobject.Closure"
         "create")
  then Alcotest.fail "on_close_request body should call Gobject.Closure.create";
  (* L1 val callback type must have a bool return type *)
  let l1_val = Signal_gen.emit_l1_val ~current_class:"Button" emission in
  let val_ast = Ml_ast_helpers.parse_interface l1_val in
  Helpers.expect_some "on_close_request val declaration"
    (Ml_ast_helpers.find_value_declaration_sig val_ast "on_close_request")
  @@ fun vd ->
  let callback_type =
    Helpers.expect_some "callback labelled param in on_close_request sig"
      (Ml_ast_helpers.find_labelled_param vd.pval_type "callback")
      Fun.id
  in
  let return_type = Ml_ast_helpers.get_return_type callback_type in
  let return_type_str = Ml_ast_helpers.core_type_to_string return_type in
  if not (String.equal "bool" return_type_str) then
    Alcotest.failf "callback return type should be 'bool' but got: %s"
      return_type_str

(* ========================================================================= *)
(* Case 4: bool param + bool return round-trip                                *)
(* ========================================================================= *)

let test_bool_return_bool_param_round_trip () =
  let ctx = shared_ctx in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"state-set"
      ~return_type:Type_factory.gboolean_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"state"
            ~param_type:Type_factory.gboolean_type ();
        ]
      ()
  in
  let emission =
    expect_ok "state-set classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  Alcotest.(check string)
    "l1_callback_type" "state:bool -> bool"
    (Signal_gen.l1_callback_type ~current_class:"Button" emission);
  let l1_let = Signal_gen.emit_l1_let emission in
  let ast = Ml_ast_helpers.parse_implementation l1_let in
  Helpers.expect_some "on_state_set binding"
    (Ml_ast_helpers.find_let_binding ast "on_state_set")
  @@ fun vb ->
  (* Body must reference Gobject.Closure.nth *)
  if
    not
      (Ml_ast_helpers.contains_function_call vb.pvb_expr "Gobject.Closure.nth")
  then Alcotest.fail "on_state_set body should reference Gobject.Closure.nth";
  (* Body must reference Value.set_boolean for return *)
  if
    not
      (Ml_ast_helpers.contains_function_call vb.pvb_expr
         "Gobject.Value.set_boolean")
  then
    Alcotest.fail
      "on_state_set body should call Gobject.Value.set_boolean for return"

(* ========================================================================= *)
(* Case 5: key-pressed shape with cross-ns ModifierType bitfield             *)
(* ========================================================================= *)

let test_mixed_params_key_pressed_shape () =
  let ctx = gtk_ctx_with_gdk_modifiertype () in
  let modifiertype_gir =
    Type_factory.make_gir_type ~name:"Gdk.ModifierType"
      ~c_type:"GdkModifierType" ()
  in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"key-pressed"
      ~return_type:Type_factory.gboolean_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"keyval"
            ~param_type:Type_factory.guint_type ();
          Type_factory.make_gir_param ~param_name:"keycode"
            ~param_type:Type_factory.guint_type ();
          Type_factory.make_gir_param ~param_name:"state"
            ~param_type:modifiertype_gir ();
        ]
      ()
  in
  let emission =
    expect_ok "key-pressed classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  Alcotest.(check int)
    "3 param marshallers" 3
    (List.length emission.param_marshallers);
  (* Third entry is the ModifierType — check getter_expr *)
  let _, third_m =
    match emission.param_marshallers with
    | [ _; _; third ] -> third
    | _ -> Alcotest.fail "expected exactly 3 param marshallers"
  in
  Alcotest.(check string)
    "getter_expr"
    "Ocgtk_gdk.Gdk_enums.modifiertype_of_int (Gobject.Value.get_flags_int v)"
    third_m.getter_expr;
  Alcotest.(check string)
    "setter_expr"
    "Gobject.Value.set_flags_int v (Ocgtk_gdk.Gdk_enums.modifiertype_to_int x)"
    third_m.setter_expr

(* ========================================================================= *)
(* Case 6: unsupported signal returns Error                                   *)
(* ========================================================================= *)

let test_unsupported_signal_returns_error () =
  let ctx = shared_ctx in
  let callback_gir =
    Type_factory.make_gir_type ~name:"DestroyFunc" ~c_type:"GDestroyNotify" ()
  in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"destroy-with-callback"
      ~return_type:Type_factory.void_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"notify"
            ~param_type:callback_gir ();
        ]
      ()
  in
  let result = Signal_gen.classify ~ctx signal in
  let reason = expect_error "callback signal should fail" result in
  if String.equal "" reason then
    Alcotest.fail "Error reason should be non-empty"

(* ========================================================================= *)
(* Case 7: no Closure.nth uses pos:0                                         *)
(* ========================================================================= *)

let test_sender_not_at_pos_0 () =
  let ctx = shared_ctx in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"pressed"
      ~return_type:Type_factory.void_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"n_press"
            ~param_type:Type_factory.gint_type ();
          Type_factory.make_gir_param ~param_name:"x"
            ~param_type:Type_factory.gdouble_type ();
        ]
      ()
  in
  let emission =
    expect_ok "pressed classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  let l1_let = Signal_gen.emit_l1_let emission in
  (* pos 0 (sender) should never appear in any Gobject.Closure.nth call *)
  let ast = Ml_ast_helpers.parse_implementation l1_let in
  Helpers.expect_some "on_pressed binding for pos check"
    (Ml_ast_helpers.find_let_binding ast "on_pressed")
  @@ fun vb ->
  if not (Ml_ast_helpers.no_closure_nth_at_pos_zero vb.pvb_expr) then
    Alcotest.fail
      "L1 let body must not use ~pos:0 in any Gobject.Closure.nth call (sender \
       is implicit)"

(* ========================================================================= *)
(* Case 8: keyword param name gets trailing underscore                       *)
(* ========================================================================= *)

let test_keyword_param_name_sanitised () =
  let ctx = shared_ctx in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"typed"
      ~return_type:Type_factory.void_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"type"
            ~param_type:Type_factory.gint_type ();
        ]
      ()
  in
  let emission =
    expect_ok "typed classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  let l1_let = Signal_gen.emit_l1_let emission in
  let ast = Ml_ast_helpers.parse_implementation l1_let in
  Helpers.expect_some "on_typed binding"
    (Ml_ast_helpers.find_let_binding ast "on_typed")
  @@ fun vb ->
  let callback_labels =
    Ml_ast_helpers.collect_labelled_args_of_call vb.pvb_expr "callback"
  in
  if not (List.mem "type_" callback_labels) then
    Alcotest.failf
      "L1 let body should call callback with labelled arg '~type_'; found \
       labels: [%s]"
      (String.concat ", " callback_labels)

(* ========================================================================= *)
(* Case 9: gint64 param maps to Int64.t                                      *)
(* ========================================================================= *)

let test_int64_param_maps_to_int64_t () =
  let ctx = shared_ctx in
  let gint64_type =
    Type_factory.make_gir_type ~name:"gint64" ~c_type:"gint64" ()
  in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"value-changed"
      ~return_type:Type_factory.void_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"value"
            ~param_type:gint64_type ();
        ]
      ()
  in
  let emission =
    expect_ok "value-changed classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  let _, m =
    match emission.param_marshallers with
    | [ entry ] -> entry
    | _ -> Alcotest.fail "expected exactly 1 param marshaller"
  in
  Alcotest.(check string) "ocaml_type" "Int64.t" m.ocaml_type;
  Alcotest.(check string)
    "getter_expr" "Gobject.Value.get_int64 v" m.getter_expr;
  Alcotest.(check string)
    "setter_expr" "Gobject.Value.set_int64 v x" m.setter_expr

(* ========================================================================= *)
(* Case 10: GLib.Variant param maps to Gvariant.t                            *)
(* ========================================================================= *)

let test_variant_param_maps_to_gvariant () =
  let ctx = shared_ctx in
  let variant_gir =
    Type_factory.make_gir_type ~name:"GLib.Variant" ~c_type:"GVariant*" ()
  in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"change-value"
      ~return_type:Type_factory.void_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"value"
            ~param_type:variant_gir ();
        ]
      ()
  in
  let emission =
    expect_ok "change-value classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  let _, m =
    match emission.param_marshallers with
    | [ entry ] -> entry
    | _ -> Alcotest.fail "expected exactly 1 param marshaller"
  in
  Alcotest.(check string) "ocaml_type" "Gvariant.t" m.ocaml_type;
  Alcotest.(check string)
    "getter_expr" "Gobject.Value.get_variant v" m.getter_expr;
  Alcotest.(check string)
    "setter_expr" "Gobject.Value.set_variant v x" m.setter_expr

(* ========================================================================= *)
(* Case 11: L2 forwarder shape                                                *)
(* ========================================================================= *)

let test_l2_forwarder_shape () =
  let ctx = shared_ctx in
  let signal = make_clicked_signal () in
  let emission =
    expect_ok "clicked classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  let l2 =
    Signal_gen.emit_l2_method ~current_layer2_module:"GButton"
      ~layer1_module_name:"Window" ~class_snake:"window" emission
  in
  (* Parse as a class body fragment by wrapping it *)
  let wrapped = Printf.sprintf "class test_class = object\n%send\n" l2 in
  let ast = Ml_ast_helpers.parse_implementation wrapped in
  Helpers.expect_some "test_class declaration"
    (Ml_ast_helpers.find_class_declaration ast "test_class")
  @@ fun cd ->
  Helpers.expect_some "method on_clicked"
    (Ml_ast_helpers.find_method_in_class cd.pci_expr "on_clicked")
  @@ fun cf ->
  Helpers.expect_some "method on_clicked body"
    (Ml_ast_helpers.get_method_body cf)
  @@ fun body ->
  if not (Ml_ast_helpers.method_body_calls_function body "Window" "on_clicked")
  then Alcotest.fail "L2 method body should call Window.on_clicked";
  if not (Ml_ast_helpers.contains_method_send body "as_window") then
    Alcotest.fail "L2 method body should reference self#as_window"

(* ========================================================================= *)
(* Case 12: L1 obj is positional, not labelled                               *)
(* ========================================================================= *)

let test_l1_obj_is_positional_not_labelled () =
  let ctx = shared_ctx in
  let signal = make_clicked_signal () in
  let emission =
    expect_ok "clicked classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  let l1_val = Signal_gen.emit_l1_val ~current_class:"Button" emission in
  let ast = Ml_ast_helpers.parse_interface l1_val in
  Helpers.expect_some "on_clicked val declaration"
    (Ml_ast_helpers.find_value_declaration_sig ast "on_clicked")
  @@ fun vd ->
  (* The second positional arg must be Nolabel with type 't' *)
  let params = Ml_ast_helpers.get_arrow_params_with_labels vd.pval_type in
  let second_param =
    match params with _ :: second :: _ -> Some second | _ -> None
  in
  Helpers.expect_some "second parameter in on_clicked val type" second_param
  @@ fun (lbl, param_ct) ->
  (match lbl with
  | Ppxlib.Asttypes.Nolabel -> ()
  | _ ->
      Alcotest.failf
        "second parameter of on_clicked must be positional (Nolabel) but got \
         label");
  let type_str = Ml_ast_helpers.core_type_to_string param_ct in
  if not (String.equal "t" type_str) then
    Alcotest.failf "second parameter type should be 't' but got: %s" type_str;
  (* Also confirm 'obj' does not appear as any labelled arg name *)
  if not (Ml_ast_helpers.has_no_labelled_param vd.pval_type "obj") then
    Alcotest.fail "on_clicked val should not have a labelled 'obj' parameter"

(* ========================================================================= *)
(* Case 13: signal_gen.mli has no file-writing functions                     *)
(* ========================================================================= *)

let test_no_signals_files_generated () =
  (* Verify the mli does not export generate_signal_class.
     We test this structurally by confirming the module only exports the
     expected public names.  The MLI file is read from the source tree. *)
  let mli_path =
    (* The test binary is run from _build/default/gir_gen; walk up to find src *)
    let rec find_root dir =
      let candidate =
        Filename.concat dir "gir_gen/lib/generate/signal_gen.mli"
      in
      if Sys.file_exists candidate then candidate
      else
        let parent = Filename.dirname dir in
        if String.equal parent dir then
          Alcotest.fail "Could not find signal_gen.mli from build tree"
        else find_root parent
    in
    find_root (Sys.getcwd ())
  in
  let ic = open_in mli_path in
  let len = in_channel_length ic in
  let mli_content = Bytes.create len in
  really_input ic mli_content 0 len;
  close_in ic;
  let mli_str = Bytes.to_string mli_content in
  let ast = Ml_ast_helpers.parse_interface mli_str in
  (* Must not export generate_signal_class *)
  if
    Option.is_some
      (Ml_ast_helpers.find_value_declaration_sig ast "generate_signal_class")
  then Alcotest.fail "signal_gen.mli must not export 'generate_signal_class'";
  (* Must export the expected public names *)
  let expected_names =
    [
      "sanitize_signal_name";
      "classify";
      "emit_l1_val";
      "emit_l1_let";
      "emit_l2_method";
    ]
  in
  List.iter
    (fun name ->
      if Option.is_none (Ml_ast_helpers.find_value_declaration_sig ast name)
      then
        Alcotest.failf "signal_gen.mli should export '%s' but it is missing"
          name)
    expected_names

(* ========================================================================= *)
(* Case 14: L2 method output has no inherit _signals line                    *)
(* ========================================================================= *)

let test_l2_has_no_inherit_signals_line () =
  let ctx = shared_ctx in
  let signal = make_clicked_signal () in
  let emission =
    expect_ok "clicked classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  let l2 =
    Signal_gen.emit_l2_method ~current_layer2_module:"GButton"
      ~layer1_module_name:"Button" ~class_snake:"button" emission
  in
  let wrapped = Printf.sprintf "class test_class = object\n%send\n" l2 in
  let ast = Ml_ast_helpers.parse_implementation wrapped in
  Helpers.expect_some "test_class declaration"
    (Ml_ast_helpers.find_class_declaration ast "test_class")
  @@ fun cd ->
  let inherit_names = Ml_ast_helpers.get_class_inherit_clauses cd.pci_expr in
  let has_signals_inherit =
    List.exists (fun name -> String.mem ~sub:"_signals" name) inherit_names
  in
  if has_signals_inherit then
    Alcotest.fail
      "L2 method output should not contain any 'inherit *_signals' clause"

(* ========================================================================= *)
(* Stage 2 integration: generate_ml_interface emits L1 signal bindings       *)
(* ========================================================================= *)

module Ml_interface = Gir_gen_lib.Generate.Ml_interface

let test_l1_val_in_generated_module_interface () =
  (* Arrange: minimal Gtk context and one void zero-param signal *)
  let ctx = shared_ctx in
  let clicked_signal = make_clicked_signal () in
  (* Act: call the L1 interface generator in Interface mode with the signal *)
  let mli_content =
    Ml_interface.generate_ml_interface ~ctx ~output_mode:Ml_interface.Interface
      ~class_name:"Button" ~class_doc:None ~c_type:"GtkButton"
      ~parent_chain:[ "Widget" ] ~constructors:None ~methods:[] ~properties:[]
      ~signals:[ clicked_signal ]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in
  (* Assert: val on_clicked present in the module signature *)
  let ast = Ml_ast_helpers.parse_interface mli_content in
  Helpers.assert_some "val on_clicked should appear in generated .mli"
    (Ml_ast_helpers.find_value_declaration_sig ast "on_clicked")

let test_l1_let_in_generated_module_impl () =
  (* Arrange: minimal Gtk context and one void zero-param signal *)
  let ctx = shared_ctx in
  let clicked_signal = make_clicked_signal () in
  (* Act: call the L1 interface generator in Implementation mode with the
     signal *)
  let ml_content =
    Ml_interface.generate_ml_interface ~ctx
      ~output_mode:Ml_interface.Implementation ~class_name:"Button"
      ~class_doc:None ~c_type:"GtkButton" ~parent_chain:[ "Widget" ]
      ~constructors:None ~methods:[] ~properties:[] ~signals:[ clicked_signal ]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in
  (* Assert: let on_clicked present in the module body *)
  let ast = Ml_ast_helpers.parse_implementation ml_content in
  Helpers.assert_some "let on_clicked should appear in generated .ml"
    (Ml_ast_helpers.find_let_binding ast "on_clicked")

(* ========================================================================= *)
(* Stage 3: class_gen body contains on_signal method forwarders               *)
(* ========================================================================= *)

module Class_gen = Gir_gen_lib.Generate.Class_gen

(** Build a Gtk ctx with Button registered as a class (required for type
    resolution inside the class body generators). *)
let gtk_ctx_with_button () =
  let button_class =
    Type_factory.make_gir_class ~class_name:"Button" ~c_type:"GtkButton" ()
  in
  { (gtk_ctx ()) with classes = [ button_class ] }

let test_l2_class_body_contains_on_signal_method () =
  (* Arrange: Button class with a void zero-param 'clicked' signal *)
  let ctx = gtk_ctx_with_button () in
  let clicked_signal = make_clicked_signal () in
  (* Act: generate the L2 class module (.ml) *)
  let ml_code =
    Class_gen.generate_class_module ~ctx ~class_name:"Button"
      ~c_type:"GtkButton" ~parent_chain:[] ~methods:[] ~properties:[]
      ~signals:[ clicked_signal ] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in
  let ast = Ml_ast_helpers.parse_implementation ml_code in
  (* Assert: the 'button' class exists and contains method on_clicked *)
  Helpers.expect_some "class 'button' not found in generated .ml"
    (Ml_ast_helpers.find_class_declaration ast "button")
  @@ fun cd ->
  Helpers.expect_some "method 'on_clicked' not found in class 'button'"
    (Ml_ast_helpers.find_method_in_class cd.pci_expr "on_clicked")
  @@ fun cf ->
  Helpers.expect_some "could not extract body of method 'on_clicked'"
    (Ml_ast_helpers.get_method_body cf)
  @@ fun body ->
  (* Body must forward to Button.on_clicked *)
  if not (Ml_ast_helpers.method_body_calls_function body "Button" "on_clicked")
  then
    Alcotest.fail
      "on_clicked body should call Button.on_clicked (L1 forwarder missing)";
  (* Body must reference self#as_button *)
  if not (Ml_ast_helpers.contains_method_send body "as_button") then
    Alcotest.fail "on_clicked body should reference self#as_button"

let test_l2_class_type_contains_on_signal_method_sig () =
  (* Arrange: same Button with clicked signal *)
  let ctx = gtk_ctx_with_button () in
  let clicked_signal = make_clicked_signal () in
  (* Act: generate the L2 class signature (.mli) *)
  let mli_code =
    Class_gen.generate_class_signature ~ctx ~class_name:"Button"
      ~c_type:"GtkButton" ~parent_chain:[] ~methods:[] ~properties:[]
      ~signals:[ clicked_signal ] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in
  let sig_ast = Ml_ast_helpers.parse_interface mli_code in
  (* Assert: the 'button_t' class type contains method on_clicked *)
  Helpers.expect_some "class type 'button_t' not found in generated .mli"
    (Ml_ast_helpers.find_class_type_declaration sig_ast "button_t")
  @@ fun ctd ->
  if not (Ml_ast_helpers.method_signature_exists ctd.pci_expr "on_clicked") then
    Alcotest.fail
      "method 'on_clicked' signature not found in class type 'button_t'";
  (* No inherit _signals in the output *)
  let inherit_names =
    Ml_ast_helpers.get_class_type_inherit_clauses ctd.pci_expr
  in
  let has_signals_inherit =
    List.exists (fun name -> String.mem ~sub:"_signals" name) inherit_names
  in
  if has_signals_inherit then
    Alcotest.fail
      "class type 'button_t' should not contain any 'inherit *_signals' clause"

let test_l2_no_inherit_signals_in_generated_class () =
  (* Arrange: Button class with a void zero-param 'clicked' signal *)
  let ctx = gtk_ctx_with_button () in
  let clicked_signal = make_clicked_signal () in
  (* Act: generate the L2 class module (.ml) *)
  let ml_code =
    Class_gen.generate_class_module ~ctx ~class_name:"Button"
      ~c_type:"GtkButton" ~parent_chain:[] ~methods:[] ~properties:[]
      ~signals:[ clicked_signal ] ~constructors:[]
      ~entity_kind:Gir_gen_lib.Generate.Filtering.Class
  in
  let ast = Ml_ast_helpers.parse_implementation ml_code in
  (* Assert: no Pcf_inherit references a name ending in _signals *)
  Helpers.expect_some "class 'button' not found in generated .ml"
    (Ml_ast_helpers.find_class_declaration ast "button")
  @@ fun cd ->
  let inherit_names = Ml_ast_helpers.get_class_inherit_clauses cd.pci_expr in
  let has_signals_inherit =
    List.exists (fun name -> String.mem ~sub:"_signals" name) inherit_names
  in
  if has_signals_inherit then
    Alcotest.fail
      "generated class 'button' must not contain any 'inherit G*_signals' \
       clause"

(* ========================================================================= *)
(* Epoch 2 stages 3-4: class-param signal coverage                           *)
(* ========================================================================= *)

(** Gtk context with Widget registered as a same-namespace class. *)
let gtk_ctx_with_widget () =
  let widget_class =
    Type_factory.make_gir_class ~class_name:"Widget" ~c_type:"GtkWidget" ()
  in
  { (gtk_ctx ()) with classes = [ widget_class ] }

(** Gtk context with a cross-namespace Gio.File interface. *)
let gtk_ctx_with_gio_file () =
  let gio_entities =
    StringMap.empty
    |> StringMap.add "File"
         (Type_factory.make_cross_reference_entity ~cr_name:"File"
            ~cr_type:(Type_factory.make_cross_reference_type `Interface)
            ~cr_c_type:"GFile*" ())
  in
  let cross_refs =
    Type_factory.make_cross_reference_map
      [ Helpers.make_ncr "Gio" gio_entities ]
  in
  { (gtk_ctx ()) with cross_references = cross_refs }

let test_class_param_marshaller_type_correct () =
  (* Non-nullable same-NS class param → ocaml_type = "Widget.t" *)
  let ctx = gtk_ctx_with_widget () in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"child-notify"
      ~return_type:Type_factory.void_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"widget"
            ~param_type:
              (Type_factory.make_gir_type ~name:"Widget" ~c_type:"GtkWidget*" ())
            ();
        ]
      ()
  in
  let emission =
    expect_ok "child-notify classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  let _, m =
    match emission.param_marshallers with
    | [ entry ] -> entry
    | _ -> Alcotest.fail "expected exactly 1 param marshaller"
  in
  Alcotest.(check string) "ocaml_type" "Widget.t" m.ocaml_type;
  Alcotest.(check string)
    "getter_expr" "Gobject.Value.get_object_exn v" m.getter_expr

let test_class_param_nullable_marshaller_type_has_option () =
  (* Nullable same-NS class param → ocaml_type = "Widget.t option" *)
  let ctx = gtk_ctx_with_widget () in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"child-notify"
      ~return_type:Type_factory.void_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"widget"
            ~param_type:
              (Type_factory.make_gir_type ~name:"Widget" ~c_type:"GtkWidget*"
                 ~nullable:true ())
            ();
        ]
      ()
  in
  let emission =
    expect_ok "child-notify nullable classify"
      (Signal_gen.classify ~ctx signal)
      Fun.id
  in
  let _, m =
    match emission.param_marshallers with
    | [ entry ] -> entry
    | _ -> Alcotest.fail "expected exactly 1 param marshaller"
  in
  Alcotest.(check string) "ocaml_type" "Widget.t option" m.ocaml_type;
  Alcotest.(check string)
    "getter_expr" "Gobject.Value.get_object v" m.getter_expr

let test_class_param_l1_let_parses () =
  (* emit_l1_let for a class-param signal produces valid OCaml *)
  let ctx = gtk_ctx_with_widget () in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"child-notify"
      ~return_type:Type_factory.void_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"widget"
            ~param_type:
              (Type_factory.make_gir_type ~name:"Widget" ~c_type:"GtkWidget*" ())
            ();
        ]
      ()
  in
  let emission =
    expect_ok "child-notify classify" (Signal_gen.classify ~ctx signal) Fun.id
  in
  let l1_let = Signal_gen.emit_l1_let emission in
  let ast = Ml_ast_helpers.parse_implementation l1_let in
  Helpers.assert_some "on_child_notify binding should be present"
    (Ml_ast_helpers.find_let_binding ast "on_child_notify")

let test_e2e_same_ns_class_param_l1_interface () =
  (* generate_ml_interface emits val for a signal with a same-NS class param *)
  let ctx = gtk_ctx_with_widget () in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"child-notify"
      ~return_type:Type_factory.void_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"widget"
            ~param_type:
              (Type_factory.make_gir_type ~name:"Widget" ~c_type:"GtkWidget*" ())
            ();
        ]
      ()
  in
  let mli_content =
    Ml_interface.generate_ml_interface ~ctx ~output_mode:Ml_interface.Interface
      ~class_name:"Window" ~class_doc:None ~c_type:"GtkWindow"
      ~parent_chain:[ "Widget" ] ~constructors:None ~methods:[] ~properties:[]
      ~signals:[ signal ] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in
  let ast = Ml_ast_helpers.parse_interface mli_content in
  Helpers.assert_some
    "val on_child_notify should appear in .mli for same-NS class-param signal"
    (Ml_ast_helpers.find_value_declaration_sig ast "on_child_notify")

let test_e2e_cross_ns_class_param_l1_interface () =
  (* generate_ml_interface emits val for a signal with a cross-NS class param *)
  let ctx = gtk_ctx_with_gio_file () in
  let signal =
    Type_factory.make_gir_signal ~signal_name:"file-opened"
      ~return_type:Type_factory.void_type
      ~sig_parameters:
        [
          Type_factory.make_gir_param ~param_name:"file"
            ~param_type:
              (Type_factory.make_gir_type ~name:"Gio.File" ~c_type:"GFile*" ())
            ();
        ]
      ()
  in
  let mli_content =
    Ml_interface.generate_ml_interface ~ctx ~output_mode:Ml_interface.Interface
      ~class_name:"Button" ~class_doc:None ~c_type:"GtkButton"
      ~parent_chain:[ "Widget" ] ~constructors:None ~methods:[] ~properties:[]
      ~signals:[ signal ] ~entity_kind:Gir_gen_lib.Generate.Filtering.Class ()
  in
  let ast = Ml_ast_helpers.parse_interface mli_content in
  Helpers.assert_some
    "val on_file_opened should appear in .mli for cross-NS class-param signal"
    (Ml_ast_helpers.find_value_declaration_sig ast "on_file_opened")

(* ========================================================================= *)
(* Test suite                                                                 *)
(* ========================================================================= *)

let tests =
  [
    Alcotest.test_case "void zero-param: connect_simple in L1 let" `Quick
      test_void_zero_param_emits_connect_simple_in_l1_let;
    Alcotest.test_case "void zero-param: val on_clicked in L1 val" `Quick
      test_void_zero_param_emits_val_in_l1_val;
    Alcotest.test_case "void primitive params: Closure.create in L1 let" `Quick
      test_void_primitive_params_uses_closure_create;
    Alcotest.test_case "bool return zero-param: Closure.create in L1 let" `Quick
      test_bool_return_zero_param_uses_closure_create;
    Alcotest.test_case "bool return + bool param round-trip" `Quick
      test_bool_return_bool_param_round_trip;
    Alcotest.test_case "key-pressed shape: cross-ns ModifierType bitfield"
      `Quick test_mixed_params_key_pressed_shape;
    Alcotest.test_case "unsupported callback param returns Error" `Quick
      test_unsupported_signal_returns_error;
    Alcotest.test_case "no Closure.nth uses pos:0 (sender implicit)" `Quick
      test_sender_not_at_pos_0;
    Alcotest.test_case "keyword param 'type' sanitised to 'type_'" `Quick
      test_keyword_param_name_sanitised;
    Alcotest.test_case "gint64 param maps to Int64.t" `Quick
      test_int64_param_maps_to_int64_t;
    Alcotest.test_case "GLib.Variant param maps to Gvariant.t" `Quick
      test_variant_param_maps_to_gvariant;
    Alcotest.test_case "L2 forwarder shape: calls L1 and self#as_window" `Quick
      test_l2_forwarder_shape;
    Alcotest.test_case "L1 obj is positional, not labelled ~obj" `Quick
      test_l1_obj_is_positional_not_labelled;
    Alcotest.test_case "signal_gen.mli has no generate_signal_class export"
      `Quick test_no_signals_files_generated;
    Alcotest.test_case "L2 method output has no inherit _signals line" `Quick
      test_l2_has_no_inherit_signals_line;
    Alcotest.test_case
      "generate_ml_interface Interface mode emits val on_clicked" `Quick
      test_l1_val_in_generated_module_interface;
    Alcotest.test_case
      "generate_ml_interface Implementation mode emits let on_clicked" `Quick
      test_l1_let_in_generated_module_impl;
    Alcotest.test_case "L2 class body contains on_clicked method forwarder"
      `Quick test_l2_class_body_contains_on_signal_method;
    Alcotest.test_case "L2 class type contains on_clicked method signature"
      `Quick test_l2_class_type_contains_on_signal_method_sig;
    Alcotest.test_case
      "L2 generated class has no inherit G*_signals in class body" `Quick
      test_l2_no_inherit_signals_in_generated_class;
    Alcotest.test_case "same-NS class param: marshaller type is Widget.t" `Quick
      test_class_param_marshaller_type_correct;
    Alcotest.test_case
      "nullable same-NS class param: marshaller type is Widget.t option" `Quick
      test_class_param_nullable_marshaller_type_has_option;
    Alcotest.test_case "same-NS class param: emit_l1_let parses" `Quick
      test_class_param_l1_let_parses;
    Alcotest.test_case
      "e2e: same-NS class param signal emits val in L1 interface" `Quick
      test_e2e_same_ns_class_param_l1_interface;
    Alcotest.test_case
      "e2e: cross-NS class param signal emits val in L1 interface" `Quick
      test_e2e_cross_ns_class_param_l1_interface;
  ]
