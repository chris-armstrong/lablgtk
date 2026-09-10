(* Tests for Phase 4: Layer 2 interface inheritance.
 *
 * Verifies that when a class has <implements name="MyIface"/>, the generated
 * Layer 2 g<MyClass>.ml:
 *   - class type <my_class_t> inherits <GMyIface.my_iface_t>
 *   - class <my_class> implementation inherits <GMyIface.my_iface>
 *
 * Also verifies:
 *   - Classes with no implements have no interface inherits
 *   - Method conflict suppression: if both class and interface define the same
 *     method, only one definition appears in the Layer 2 class type
 *
 * All validation uses Ml_ast_helpers / Ml_validation (AST-based).
 * No string matching is used. See docs/code_guidelines/test-patterns.md.
 *)

open Ppxlib
open Ppxlib.Parsetree

(* ========================================================================= *)
(* GIR XML fixtures                                                           *)
(* ========================================================================= *)

(** Interface + class that implements it, in the same namespace. MyIface has
    glib:type-name (so from_gobject exists in Layer 1). MyClass has <implements
    name="MyIface"/>. *)
let gir_class_implements_iface =
  Helpers.wrap_namespace ~version:"4.0"
    {|<interface name="MyIface"
                 c:type="GtkMyIface"
                 glib:type-name="GtkMyIface"
                 glib:get-type="gtk_my_iface_get_type">
        <method name="do_thing" c:identifier="gtk_my_iface_do_thing"
                introspectable="1">
          <return-value transfer-ownership="none">
            <type name="none" c:type="void"/>
          </return-value>
        </method>
      </interface>
      <class name="MyClass"
             c:type="GtkMyClass"
             glib:type-name="GtkMyClass"
             glib:get-type="gtk_my_class_get_type"
             parent="GObject.Object">
        <implements name="MyIface"/>
        <constructor name="new" c:identifier="gtk_my_class_new"
                     introspectable="1">
          <return-value transfer-ownership="none">
            <type name="MyClass" c:type="GtkMyClass*"/>
          </return-value>
        </constructor>
      </class>|}

(** Class with NO implements — should have no interface inherit lines. *)
let gir_class_no_implements =
  Helpers.wrap_namespace ~version:"4.0"
    {|<class name="MyClass"
             c:type="GtkMyClass"
             glib:type-name="GtkMyClass"
             glib:get-type="gtk_my_class_get_type"
             parent="GObject.Object">
        <constructor name="new" c:identifier="gtk_my_class_new"
                     introspectable="1">
          <return-value transfer-ownership="none">
            <type name="MyClass" c:type="GtkMyClass*"/>
          </return-value>
        </constructor>
      </class>|}

(** Class + interface where BOTH define a method with the same name.
    MyClass.do_thing and MyIface.do_thing both exist. The class's own do_thing
    should be suppressed (interface's inherit provides it). *)
let gir_method_conflict =
  Helpers.wrap_namespace ~version:"4.0"
    {|<interface name="MyIface"
                 c:type="GtkMyIface"
                 glib:type-name="GtkMyIface"
                 glib:get-type="gtk_my_iface_get_type">
        <method name="do_thing" c:identifier="gtk_my_iface_do_thing"
                introspectable="1">
          <return-value transfer-ownership="none">
            <type name="none" c:type="void"/>
          </return-value>
        </method>
      </interface>
      <class name="MyClass"
             c:type="GtkMyClass"
             glib:type-name="GtkMyClass"
             glib:get-type="gtk_my_class_get_type"
             parent="GObject.Object">
        <implements name="MyIface"/>
        <constructor name="new" c:identifier="gtk_my_class_new"
                     introspectable="1">
          <return-value transfer-ownership="none">
            <type name="MyClass" c:type="GtkMyClass*"/>
          </return-value>
        </constructor>
        <method name="do_thing" c:identifier="gtk_my_class_do_thing"
                introspectable="1">
          <return-value transfer-ownership="none">
            <type name="none" c:type="void"/>
          </return-value>
        </method>
      </class>|}

(* ========================================================================= *)
(* Runner helper: run gir_gen and return parsed Layer 2 .ml AST              *)
(* ========================================================================= *)

(** Run gir_gen.exe on [gir_content], return (raw_content, ml_ast) for the Layer
    2 g<ClassName>.ml file. [class_name] is the GIR class name (e.g. "MyClass").
    Cleans up temp files on exit. *)
let run_and_parse_layer2_ml gir_content class_name =
  let gir_file = Filename.temp_file "test_iface_inherit" ".gir" in
  let output_dir = Filename.temp_file "test_iface_inherit_out" "" in
  Sys.remove output_dir;
  Unix.mkdir output_dir 0o755;
  Fun.protect
    ~finally:(fun () ->
      (try Sys.remove gir_file with Sys_error _ -> ());
      let generated_dir = Helpers.generated_dir output_dir in
      (try
         Array.iter
           (fun f -> Sys.remove (Filename.concat generated_dir f))
           (Sys.readdir generated_dir);
         Unix.rmdir generated_dir
       with Sys_error _ | Unix.Unix_error _ -> ());
      try
        Array.iter
          (fun f -> Sys.remove (Filename.concat output_dir f))
          (Sys.readdir output_dir);
        Unix.rmdir output_dir
      with Sys_error _ | Unix.Unix_error _ -> ())
    (fun () ->
      Helpers.create_gir_file gir_file gir_content;
      Helpers.ensure_output_dir output_dir;
      ignore (Helpers.run_gir_gen gir_file output_dir);
      let ml_path = Helpers.g_wrapper_file output_dir class_name in
      if not (Helpers.file_exists ml_path) then
        Alcotest.failf "Expected Layer 2 file not found: %s" ml_path;
      let content = Helpers.read_file ml_path in
      (content, Ml_ast_helpers.parse_implementation content))

(* ========================================================================= *)
(* Tests: class type inherits interface class type                            *)
(* ========================================================================= *)

(** The generated class type must inherit the interface's class type. *)
let test_class_type_inherits_interface_type () =
  let _content, ml_ast =
    run_and_parse_layer2_ml gir_class_implements_iface "MyClass"
  in
  Ml_validation.assert_class_type_inherits ml_ast ~class_type:"my_class_t"
    ~parent:"GMy_iface.my_iface_t"

(** The class implementation must inherit the interface class (with
    from_gobject). *)
let test_class_impl_inherits_interface_class () =
  let _content, ml_ast =
    run_and_parse_layer2_ml gir_class_implements_iface "MyClass"
  in
  Ml_validation.assert_class_impl_inherits ml_ast ~class_name:"my_class"
    ~parent_class_name:"GMy_iface.my_iface"

(* ========================================================================= *)
(* Tests: class without implements has no interface inherits                  *)
(* ========================================================================= *)

(** A class with no <implements> must not get any interface inherit lines. *)
let test_class_without_implements_has_no_iface_inherit () =
  let _content, ml_ast =
    run_and_parse_layer2_ml gir_class_no_implements "MyClass"
  in
  Ml_validation.assert_class_type_not_inherits_prefix ml_ast
    ~class_type:"my_class_t" ~parent_prefix:"GMy_iface"

(* ========================================================================= *)
(* Tests: method conflict suppression                                         *)
(* ========================================================================= *)

(** When the class and its interface both define do_thing, the class type must
    not define do_thing itself (it comes from the interface inherit). *)
let test_method_conflict_not_duplicated () =
  let _content, ml_ast =
    run_and_parse_layer2_ml gir_method_conflict "MyClass"
  in
  (* The class type should still inherit the interface type *)
  Ml_validation.assert_class_type_inherits ml_ast ~class_type:"my_class_t"
    ~parent:"GMy_iface.my_iface_t";
  (* do_thing must NOT appear as a separate method declaration in my_class_t,
     since it comes via inheritance — verify by checking the ctd has no
     method fields named do_thing *)
  let ctd =
    Helpers.expect_some "my_class_t not found"
      (Ml_ast_helpers.find_class_type_declaration_impl ml_ast "my_class_t")
      Fun.id
  in
  let has_own_do_thing =
    match ctd.pci_expr.pcty_desc with
    | Pcty_signature { pcsig_fields; _ } ->
        List.exists
          (fun field ->
            match field.pctf_desc with
            | Pctf_method ({ txt; _ }, _, _, _) -> String.equal txt "do_thing"
            | _ -> false)
          pcsig_fields
    | _ -> false
  in
  Alcotest.(check bool)
    "do_thing not re-declared in my_class_t (comes via inherit)" false
    has_own_do_thing

(* ========================================================================= *)
(* Test suite                                                                 *)
(* ========================================================================= *)

let test_suite =
  [
    ( "class type inherits interface class type",
      `Quick,
      test_class_type_inherits_interface_type );
    ( "class implementation inherits interface class with from_gobject",
      `Quick,
      test_class_impl_inherits_interface_class );
    ( "class without implements has no interface inherit",
      `Quick,
      test_class_without_implements_has_no_iface_inherit );
    ( "method conflict: do_thing not re-declared in class type",
      `Quick,
      test_method_conflict_not_duplicated );
  ]
