(* GList/GSList Conversion Tests - validates transfer-ownership handling *)

open Gir_gen_lib.Types
open Type_factory

let make_glist_return ?(nullable = false) ?(transfer_ownership = TransferNone)
    () =
  let elem = make_gir_type ~name:"GtkWidget" ~c_type:"GtkWidget*" () in
  let arr = make_gir_array ~array_name:"GLib.List" ~element_type:elem () in
  make_gir_type ~name:"GLib.List" ~c_type:"GList*" ~nullable ~array:arr
    ~transfer_ownership ()

let make_gslist_return ?(nullable = false) ?(transfer_ownership = TransferNone)
    () =
  let elem = make_gir_type ~name:"GtkWidget" ~c_type:"GtkWidget*" () in
  let arr = make_gir_array ~array_name:"GLib.SList" ~element_type:elem () in
  make_gir_type ~name:"GLib.SList" ~c_type:"GSList*" ~nullable ~array:arr
    ~transfer_ownership ()

(* ========================================================================= *)
(* GList Return Transfer Ownership Tests                                      *)
(* ========================================================================= *)

(* transfer-ownership=none: the list belongs to the callee.
   Calling g_list_free would corrupt the callee's internal state. *)
let test_glist_return_transfer_none () =
  let meth =
    make_gir_method ~method_name:"get_windows"
      ~c_identifier:"gtk_application_get_windows"
      ~return_type:(make_glist_return ~transfer_ownership:TransferNone ())
      ()
  in
  let func =
    Helpers.generate_and_find_c_method ~log_label:"GList transfer-none"
      ~c_type:"GtkApplication" ~class_name:"Application" meth
  in
  Alcotest.(check bool)
    "transfer-none GList return must NOT call g_list_free" false
    (C_ast.function_calls_function func "g_list_free")

(* transfer-ownership=container: caller owns the list nodes, not the elements.
   Must call g_list_free to free the list nodes. *)
let test_glist_return_transfer_container () =
  let meth =
    make_gir_method ~method_name:"get_cells"
      ~c_identifier:"gtk_cell_layout_get_cells"
      ~return_type:
        (make_glist_return ~transfer_ownership:TransferContainer ())
      ()
  in
  let func =
    Helpers.generate_and_find_c_method ~log_label:"GList transfer-container"
      ~c_type:"GtkCellLayout" ~class_name:"CellLayout" meth
  in
  Alcotest.(check bool)
    "transfer-container GList return must call g_list_free" true
    (C_ast.function_calls_function func "g_list_free")

(* transfer-ownership=full: caller owns both list nodes and elements.
   Must call g_list_free; element memory is handled by GObject finalizers. *)
let test_glist_return_transfer_full () =
  let meth =
    make_gir_method ~method_name:"get_items"
      ~c_identifier:"gtk_recent_manager_get_items"
      ~return_type:(make_glist_return ~transfer_ownership:TransferFull ())
      ()
  in
  let func =
    Helpers.generate_and_find_c_method ~log_label:"GList transfer-full"
      ~c_type:"GtkRecentManager" ~class_name:"RecentManager" meth
  in
  Alcotest.(check bool)
    "transfer-full GList return must call g_list_free" true
    (C_ast.function_calls_function func "g_list_free")

(* Same transfer-none check for GSList *)
let test_gslist_return_transfer_none () =
  let meth =
    make_gir_method ~method_name:"get_widgets"
      ~c_identifier:"gtk_size_group_get_widgets"
      ~return_type:(make_gslist_return ~transfer_ownership:TransferNone ())
      ()
  in
  let func =
    Helpers.generate_and_find_c_method ~log_label:"GSList transfer-none"
      ~c_type:"GtkSizeGroup" ~class_name:"SizeGroup" meth
  in
  Alcotest.(check bool)
    "transfer-none GSList return must NOT call g_slist_free" false
    (C_ast.function_calls_function func "g_slist_free")

(* ========================================================================= *)
(* GList/GSList in-parameter cleanup tests                                    *)
(*                                                                            *)
(* Regression for the latent method-path bug where in-param GList cleanup    *)
(* hardcoded g_list_free/g_list_foreach even for GSList parameters. The shared*)
(* [C_stub_list_conv.cleanup_for_in_param] now dispatches on list_kind, so a  *)
(* GSList in-param must emit g_slist_free/g_slist_foreach.                    *)
(* ========================================================================= *)

let make_list_in_param ~list_name ~transfer () =
  let elem = make_gir_type ~name:"GtkWidget" ~c_type:"GtkWidget*" () in
  let arr = make_gir_array ~array_name:list_name ~element_type:elem () in
  let c_type =
    if String.equal list_name "GLib.SList" then "GSList*" else "GList*"
  in
  let ty =
    make_gir_type ~name:list_name ~c_type ~array:arr
      ~transfer_ownership:transfer ()
  in
  make_gir_param ~param_name:"items" ~param_type:ty ()

let void_return () = make_gir_type ~name:"none" ~c_type:"void" ()

(* GSList transfer-none in-param: caller frees the list nodes with
   g_slist_free, never g_list_free. *)
let test_gslist_in_param_transfer_none () =
  let meth =
    make_gir_method ~method_name:"set_widgets"
      ~c_identifier:"gtk_size_group_set_widgets" ~return_type:(void_return ())
      ~parameters:
        [ make_list_in_param ~transfer:TransferNone ~list_name:"GLib.SList" () ]
      ()
  in
  let func =
    Helpers.generate_and_find_c_method ~log_label:"GSList in-param none"
      ~c_type:"GtkSizeGroup" ~class_name:"SizeGroup" meth
  in
  Alcotest.(check bool)
    "GSList transfer-none in-param must call g_slist_free" true
    (C_ast.function_calls_function func "g_slist_free");
  Alcotest.(check bool)
    "GSList transfer-none in-param must NOT call g_list_free" false
    (C_ast.function_calls_function func "g_list_free")

(* GSList transfer-full in-param: caller frees nodes AND unrefs elements, all
   with the GSList variants. *)
let test_gslist_in_param_transfer_full () =
  let meth =
    make_gir_method ~method_name:"set_items"
      ~c_identifier:"gtk_recent_chooser_set_items" ~return_type:(void_return ())
      ~parameters:
        [ make_list_in_param ~transfer:TransferFull ~list_name:"GLib.SList" () ]
      ()
  in
  let func =
    Helpers.generate_and_find_c_method ~log_label:"GSList in-param full"
      ~c_type:"GtkRecentChooser" ~class_name:"RecentChooser" meth
  in
  Alcotest.(check bool)
    "GSList transfer-full in-param must call g_slist_free" true
    (C_ast.function_calls_function func "g_slist_free");
  Alcotest.(check bool)
    "GSList transfer-full in-param must call g_slist_foreach" true
    (C_ast.function_calls_function func "g_slist_foreach");
  Alcotest.(check bool)
    "GSList transfer-full in-param must NOT call g_list_free" false
    (C_ast.function_calls_function func "g_list_free");
  Alcotest.(check bool)
    "GSList transfer-full in-param must NOT call g_list_foreach" false
    (C_ast.function_calls_function func "g_list_foreach")

(* GList transfer-full in-param: lock the GList behaviour (g_list_free +
   g_list_foreach) so the GSList fix does not regress GList. *)
let test_glist_in_param_transfer_full () =
  let meth =
    make_gir_method ~method_name:"add_items"
      ~c_identifier:"gtk_recent_manager_add_items" ~return_type:(void_return ())
      ~parameters:
        [ make_list_in_param ~transfer:TransferFull ~list_name:"GLib.List" () ]
      ()
  in
  let func =
    Helpers.generate_and_find_c_method ~log_label:"GList in-param full"
      ~c_type:"GtkRecentManager" ~class_name:"RecentManager" meth
  in
  Alcotest.(check bool)
    "GList transfer-full in-param must call g_list_free" true
    (C_ast.function_calls_function func "g_list_free");
  Alcotest.(check bool)
    "GList transfer-full in-param must call g_list_foreach" true
    (C_ast.function_calls_function func "g_list_foreach");
  Alcotest.(check bool)
    "GList transfer-full in-param must NOT call g_slist_free" false
    (C_ast.function_calls_function func "g_slist_free")

let tests =
  [
    Alcotest.test_case "GList return transfer-none: no g_list_free" `Quick
      test_glist_return_transfer_none;
    Alcotest.test_case "GList return transfer-container: calls g_list_free"
      `Quick test_glist_return_transfer_container;
    Alcotest.test_case "GList return transfer-full: calls g_list_free" `Quick
      test_glist_return_transfer_full;
    Alcotest.test_case "GSList return transfer-none: no g_slist_free" `Quick
      test_gslist_return_transfer_none;
    Alcotest.test_case "GSList in-param transfer-none: g_slist_free" `Quick
      test_gslist_in_param_transfer_none;
    Alcotest.test_case "GSList in-param transfer-full: g_slist_foreach" `Quick
      test_gslist_in_param_transfer_full;
    Alcotest.test_case "GList in-param transfer-full: g_list_foreach" `Quick
      test_glist_in_param_transfer_full;
  ]
