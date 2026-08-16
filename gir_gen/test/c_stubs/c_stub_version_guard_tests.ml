(* C Stub Version Guard Tests
   Validates that emit_with_member_guard and emit_fallback_*_stub produce
   correct #if/#else/#endif guards and error messages. *)

open Gir_gen_lib.Generate.C_stub_version_guard
open Gir_gen_lib.Version_guard

(* ========================================================================= *)
(* Helpers *)
(* ========================================================================= *)

let gtk_ctx =
  Type_factory.make_generation_context
    ~namespace:(Type_factory.make_gir_namespace ~namespace_name:"Gtk" ())
    ()

let gio_ctx =
  Type_factory.make_generation_context
    ~namespace:(Type_factory.make_gir_namespace ~namespace_name:"Gio" ())
    ()

let pango_ctx =
  Type_factory.make_generation_context
    ~namespace:(Type_factory.make_gir_namespace ~namespace_name:"Pango" ())
    ()

let make_void_method ~method_name ~c_identifier ?version () =
  Type_factory.make_gir_method ~method_name ~c_identifier
    ~return_type:
      (Type_factory.make_return_type ~name:"none" ~c_type:(Some "void") ())
    ?version ()

let buf_to_string buf = Buffer.contents buf

let assert_contains ~label ~expected actual =
  if
    not
      (String.length expected = 0
      ||
      let len_e = String.length expected and len_a = String.length actual in
      let rec check i =
        if i + len_e > len_a then false
        else if String.sub actual i len_e = expected then true
        else check (i + 1)
      in
      check 0)
  then Alcotest.failf "%s: expected substring %S in:\n%s" label expected actual

let assert_not_contains ~label ~unexpected actual =
  let len_e = String.length unexpected and len_a = String.length actual in
  let found =
    let rec check i =
      if i + len_e > len_a then false
      else if String.sub actual i len_e = unexpected then true
      else check (i + 1)
    in
    len_e > 0 && check 0
  in
  if found then
    Alcotest.failf "%s: unexpected substring %S found in:\n%s" label unexpected
      actual

(* ========================================================================= *)
(* emit_with_member_guard: No_guard when same version *)
(* ========================================================================= *)

let test_no_guard_when_same_version () =
  let buf = Buffer.create 64 in
  let stub = "STUB_BODY" in
  emit_with_member_guard ~ctx:gtk_ctx ~class_version:(Some "4.10")
    ~member_version:(Some "4.10")
    ~fallback:(fun _ -> "FALLBACK")
    ~stub buf;
  let output = buf_to_string buf in
  Alcotest.(check string) "plain stub emitted" stub output;
  assert_not_contains ~label:"no #if" ~unexpected:"#if" output;
  assert_not_contains ~label:"no #else" ~unexpected:"#else" output

(* ========================================================================= *)
(* emit_with_member_guard: No_guard when no versions at all *)
(* ========================================================================= *)

let test_no_guard_when_no_versions () =
  let buf = Buffer.create 64 in
  let stub = "STUB_BODY" in
  emit_with_member_guard ~ctx:gtk_ctx ~class_version:None ~member_version:None
    ~fallback:(fun _ -> "FALLBACK")
    ~stub buf;
  let output = buf_to_string buf in
  Alcotest.(check string) "plain stub emitted" stub output

(* ========================================================================= *)
(* emit_with_member_guard: Member_guard when member > class *)
(* ========================================================================= *)

let test_member_guard_when_member_higher () =
  let buf = Buffer.create 256 in
  let stub = "REAL_STUB" in
  let fallback_text = "FALLBACK_STUB" in
  emit_with_member_guard ~ctx:gtk_ctx ~class_version:(Some "4.10")
    ~member_version:(Some "4.12")
    ~fallback:(fun _ -> fallback_text)
    ~stub buf;
  let output = buf_to_string buf in
  assert_contains ~label:"opening #if" ~expected:"#if GTK_CHECK_VERSION(4,12,0)"
    output;
  assert_contains ~label:"real stub" ~expected:stub output;
  assert_contains ~label:"#else" ~expected:"#else" output;
  assert_contains ~label:"fallback" ~expected:fallback_text output;
  assert_contains ~label:"#endif" ~expected:"#endif" output

(* ========================================================================= *)
(* emit_with_member_guard: Member_guard when class version is None *)
(* ========================================================================= *)

let test_member_guard_when_class_has_no_version () =
  let buf = Buffer.create 256 in
  emit_with_member_guard ~ctx:gio_ctx ~class_version:None
    ~member_version:(Some "2.40")
    ~fallback:(fun _ -> "FALLBACK")
    ~stub:"REAL" buf;
  let output = buf_to_string buf in
  assert_contains ~label:"opening #if"
    ~expected:"#if GLIB_CHECK_VERSION(2,40,0)" output;
  assert_contains ~label:"#else" ~expected:"#else" output;
  assert_contains ~label:"#endif" ~expected:"#endif" output

(* ========================================================================= *)
(* emit_with_member_guard: #if on its own line (no }#if stray) *)
(* ========================================================================= *)

let test_guard_if_on_own_line () =
  let buf = Buffer.create 256 in
  Buffer.add_string buf "}\n";
  (* simulate end of previous stub *)
  emit_with_member_guard ~ctx:gtk_ctx ~class_version:(Some "4.10")
    ~member_version:(Some "4.12")
    ~fallback:(fun _ -> "")
    ~stub:"S" buf;
  let output = buf_to_string buf in
  (* "}" and "#if" must not appear on the same line *)
  let lines = String.split_on_char '\n' output in
  List.iter
    (fun line ->
      let trimmed = String.trim line in
      if
        String.length trimmed > 0
        && String.get trimmed 0 = '}'
        && String.length trimmed > 1
      then Alcotest.failf "closing brace and #if on same line: %S" line)
    lines

(* ========================================================================= *)
(* Fallback message format *)
(* ========================================================================= *)

let test_fallback_method_message_includes_version () =
  let meth =
    make_void_method ~method_name:"get_foo" ~c_identifier:"gtk_widget_get_foo"
      ()
  in
  let v = { major = 4; minor = 12; micro = 0 } in
  let output =
    emit_fallback_method_stub ~ctx:gtk_ctx ~c_type:"GtkWidget"
      ~class_name:"Widget" ~ml_name:"ml_gtk_widget_get_foo"
      ~c_identifier:"gtk_widget_get_foo" ~version:v meth
  in
  assert_contains ~label:"version in message" ~expected:"requires GTK >= 4.12"
    output

let test_fallback_method_message_pango () =
  let meth =
    make_void_method ~method_name:"get_bar"
      ~c_identifier:"pango_font_map_get_bar" ()
  in
  let v = { major = 1; minor = 46; micro = 0 } in
  let output =
    emit_fallback_method_stub ~ctx:pango_ctx ~c_type:"PangoFontMap"
      ~class_name:"FontMap" ~ml_name:"ml_pango_font_map_get_bar"
      ~c_identifier:"pango_font_map_get_bar" ~version:v meth
  in
  assert_contains ~label:"version in message" ~expected:"requires Pango >= 1.46"
    output

let test_fallback_message_omits_micro_when_zero () =
  let meth = make_void_method ~method_name:"m" ~c_identifier:"gtk_w_m" () in
  let v = { major = 4; minor = 14; micro = 0 } in
  let output =
    emit_fallback_method_stub ~ctx:gtk_ctx ~c_type:"GtkW" ~class_name:"W"
      ~ml_name:"ml_gtk_w_m" ~c_identifier:"gtk_w_m" ~version:v meth
  in
  assert_contains ~label:"version without micro" ~expected:"4.14" output;
  assert_not_contains ~label:"no trailing .0" ~unexpected:"4.14.0" output

let test_fallback_message_includes_micro_when_nonzero () =
  let meth = make_void_method ~method_name:"m" ~c_identifier:"gtk_w_m" () in
  let v = { major = 4; minor = 14; micro = 3 } in
  let output =
    emit_fallback_method_stub ~ctx:gtk_ctx ~c_type:"GtkW" ~class_name:"W"
      ~ml_name:"ml_gtk_w_m" ~c_identifier:"gtk_w_m" ~version:v meth
  in
  assert_contains ~label:"version with micro" ~expected:"4.14.3" output

(* ========================================================================= *)
(* Fallback stubs suppress unused-param warnings *)
(* ========================================================================= *)

let test_fallback_method_suppresses_unused_params () =
  let meth =
    Type_factory.make_gir_method ~method_name:"set_foo"
      ~c_identifier:"gtk_w_set_foo"
      ~return_type:
        (Type_factory.make_return_type ~name:"none" ~c_type:(Some "void") ())
      ~parameters:
        [
          Type_factory.make_gir_param ~param_name:"value"
            ~param_type:
              (Type_factory.make_gir_type ~name:"gboolean" ~c_type:"gboolean" ())
            ();
        ]
      ()
  in
  let v = { major = 4; minor = 12; micro = 0 } in
  let output =
    emit_fallback_method_stub ~ctx:gtk_ctx ~c_type:"GtkW" ~class_name:"W"
      ~ml_name:"ml_gtk_w_set_foo" ~c_identifier:"gtk_w_set_foo" ~version:v meth
  in
  assert_contains ~label:"(void) suppression" ~expected:"(void)" output

(* ========================================================================= *)
(* Test suite *)
(* ========================================================================= *)

let test_suite =
  [
    ("no_guard_when_same_version", `Quick, test_no_guard_when_same_version);
    ("no_guard_when_no_versions", `Quick, test_no_guard_when_no_versions);
    ( "member_guard_when_member_higher",
      `Quick,
      test_member_guard_when_member_higher );
    ( "member_guard_when_class_has_no_version",
      `Quick,
      test_member_guard_when_class_has_no_version );
    ("guard_if_on_own_line", `Quick, test_guard_if_on_own_line);
    ( "fallback_method_message_includes_version",
      `Quick,
      test_fallback_method_message_includes_version );
    ("fallback_method_message_pango", `Quick, test_fallback_method_message_pango);
    ( "fallback_message_omits_micro_when_zero",
      `Quick,
      test_fallback_message_omits_micro_when_zero );
    ( "fallback_message_includes_micro_when_nonzero",
      `Quick,
      test_fallback_message_includes_micro_when_nonzero );
    ( "fallback_method_suppresses_unused_params",
      `Quick,
      test_fallback_method_suppresses_unused_params );
  ]
