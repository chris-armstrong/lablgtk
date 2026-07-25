(* GList/GSList Conversion Code Generation
 *
 * This module generates C code for converting between GList/GSList and
 * OCaml lists. It uses the macro-based approach defined in wrappers.h
 *)

open Printf
open Containers
open StdLabels
open Types

type list_kind = [ `GList | `GSList ]
(** Type of list container *)

(** Get the list kind for a GIR type *)
let list_kind_of_type (gir_type : gir_type) : list_kind option =
  if Gir_type_pred.is_glist gir_type then Some `GList
  else if Gir_type_pred.is_gslist gir_type then Some `GSList
  else None

(** Get the C type for a list kind *)
let c_type_of_list_kind = function `GList -> "GList*" | `GSList -> "GSList*"

(** Get the element converter name for a given element type. This returns the
    Val_* converter function name for converting C element data to OCaml values.
*)
let element_converter_name ~(ctx : generation_context) (elem_type : gir_type) :
    string option =
  match elem_type.name with
  | "utf8" | "filename" | "gchararray" | "gchar*" | "const gchar*" ->
      Some "caml_copy_string((const char*)_tmp->data)"
  | _ ->
      (* For other types, look up the type mapping *)
      Type_mappings.find_type_mapping_for_gir_type ~ctx elem_type
      |> Option.map (fun (tm : type_mapping) ->
          if String.equal tm.c_to_ml "LIST_INLINE" then
            (* Nested list - shouldn't happen in practice *)
            "Val_GList(_tmp->data, Val_GList_string)"
          else
            sprintf "%s((%s)_tmp->data)" tm.c_to_ml
              (Option.value ~default:"gpointer" elem_type.c_type))

(** Generate cleanup code for a GList based on transfer_ownership.

    Transfer ownership rules:
    - TransferNone: List is owned by the callee — caller must NOT free it
    - TransferContainer: Caller owns the list nodes but not the elements
    - TransferFull: Caller owns both list and elements (elements handled by
      GObject finalizers — do not double-unref)
    - TransferFloating: Like Full *)
let generate_list_cleanup ~ctx:(_ctx : generation_context) ~(kind : list_kind)
    ~var ~(xfer : transfer_ownership) ~elem_type:(_elem_type : gir_type) =
  let free_func =
    match kind with `GList -> "g_list_free" | `GSList -> "g_slist_free"
  in
  match xfer with
  | TransferNone ->
      (* Callee still owns this list — freeing it would corrupt callee state *)
      ""
  | TransferContainer | TransferFull | TransferFloating ->
      (* Free the list nodes; GObject element finalizers handle element memory *)
      sprintf "%s(%s);" free_func var

(** [cleanup_for_in_param ~list_kind ~element_unref_fn ~transfer c_var] emits
    the C cleanup for a GList/GSList [in]-parameter after the wrapped C call.
    The stub built the list from an OCaml value, so it owns the list nodes and
    frees them. For transfer-full/floating the callee took ownership of the
    elements, so each is unreffed with [element_unref_fn] (e.g.
    ["g_object_unref"] for GObjects, ["g_free"] for boxed/string elements)
    before the list is freed.

    [element_unref_fn] is parameterized because the correct per-element free
    function depends on the element type — callers pass the function their path
    uses, and a per-element-type dispatch can later replace it. This is distinct
    from [generate_list_cleanup] (the return-value path), which never frees
    elements because the OCaml wrapper's finalizer owns them. *)
let cleanup_for_in_param ~list_kind ~element_unref_fn
    ~(transfer : transfer_ownership) c_var =
  let free_func =
    match list_kind with `GList -> "g_list_free" | `GSList -> "g_slist_free"
  in
  let foreach_func =
    match list_kind with
    | `GList -> "g_list_foreach"
    | `GSList -> "g_slist_foreach"
  in
  match transfer with
  | TransferNone | TransferContainer -> sprintf "%s(%s);" free_func c_var
  | TransferFull | TransferFloating ->
      sprintf "%s(%s, (GFunc)%s, NULL);\n    %s(%s);" foreach_func c_var
        element_unref_fn free_func c_var

(** Generate C code for converting a GList/GSList return value to OCaml list.

    This generates code that: 1. Declares CAMLlocal3(result, item, cell) at
    function scope 2. Calls the appropriate Val_GList_with or Val_GSList_with
    macro 3. Handles transfer ownership cleanup *)
let generate_list_c_to_ml ~(ctx : generation_context) ~var
    ~(elem_type : gir_type) ~(kind : list_kind) ~(xfer : transfer_ownership) =
  let macro_name =
    match kind with `GList -> "Val_GList_with" | `GSList -> "Val_GSList_with"
  in

  match element_converter_name ~ctx elem_type with
  | None ->
      (* Unknown element type - generate a placeholder that will fail to compile
         This helps us identify what converters need to be added *)
      let cleanup = generate_list_cleanup ~ctx ~kind ~var ~xfer ~elem_type in
      ( "CAMLlocal1(result);",
        (* Still need to declare result variable *)
        sprintf
          "/* TODO: Unknown element type '%s' for GList */\n\
          \    %s\n\
          \    result = Val_emptylist;"
          elem_type.name cleanup,
        "CAMLreturn(result);" )
  | Some elem_conv ->
      let cleanup = generate_list_cleanup ~ctx ~kind ~var ~xfer ~elem_type in
      let conv_body =
        if String.length cleanup > 0 then
          sprintf "%s(%s, result, item, cell, %s);\n    %s" macro_name var
            elem_conv cleanup
        else
          sprintf "%s(%s, result, item, cell, %s);" macro_name var elem_conv
      in
      ( "CAMLlocal3(result, item, cell);",
        conv_body,
        "CAMLreturn(result);" )

(** Generate C code for converting an OCaml list parameter to GList/GSList.

    This generates code that: 1. Iterates over the OCaml list 2. Converts each
    element to C 3. Builds the GList/GSList *)
let generate_list_ml_to_c ~(ctx : generation_context) ~var
    ~(elem_type : gir_type) ~(kind : list_kind)
    ~xfer:(_xfer : transfer_ownership) =
  let macro_name =
    match kind with `GList -> "GList_val_with" | `GSList -> "GSList_val_with"
  in

  (* Determine the element conversion expression for the macro *)
  let elem_conv =
    match elem_type.name with
    | "utf8" | "filename" | "gchararray" | "gchar*" | "const gchar*" ->
        "(gpointer)g_strdup(String_val(Field(_iter, 0)))"
    | _ -> (
        match Type_mappings.find_type_mapping_for_gir_type ~ctx elem_type with
        | Some (tm : type_mapping) ->
            if String.equal tm.c_to_ml "LIST_INLINE" then
              "/* Nested lists not supported */ NULL"
            else sprintf "(gpointer)%s(Field(_iter, 0))" tm.ml_to_c
        | None -> sprintf "/* TODO: No converter for %s */ NULL" elem_type.name)
  in

  let result_var = var ^ "_list" in
  let c_list_type =
    match kind with `GList -> "GList*" | `GSList -> "GSList*"
  in
  sprintf "%s %s = NULL;\n    %s(%s, %s, %s);" c_list_type result_var macro_name
    var result_var elem_conv

(** Generate the full return statement for a method returning a GList/GSList.

    This is the main entry point called from c_stub_method.ml. It generates the
    complete C code block for converting the C list to OCaml. *)
let generate_return_list_conversion ~(ctx : generation_context) ~c_var
    ~(gir_type : gir_type) =
  match list_kind_of_type gir_type with
  | None -> None (* Not a list type *)
  | Some kind ->
      let elem_type : gir_type =
        match gir_type.array with
        | Some arr_info -> arr_info.element_type
        | None ->
            {
              name = "gpointer";
              c_type = Some "gpointer";
              nullable = false;
              transfer_ownership = TransferNone;
              array = None;
            }
      in
      Some
        (generate_list_c_to_ml ~ctx ~var:c_var ~elem_type ~kind
           ~xfer:gir_type.transfer_ownership)

(** Generate parameter conversion for a GList/GSList parameter.

    This is the main entry point for handling list parameters. Returns the
    variable name to use in the C function call. *)
let generate_param_list_conversion ~(ctx : generation_context) ~ocaml_var
    ~(gir_type : gir_type) =
  match list_kind_of_type gir_type with
  | None -> None (* Not a list type *)
  | Some kind ->
      let elem_type : gir_type =
        match gir_type.array with
        | Some arr_info -> arr_info.element_type
        | None ->
            {
              name = "gpointer";
              c_type = Some "gpointer";
              nullable = false;
              transfer_ownership = TransferNone;
              array = None;
            }
      in
      let conversion_code =
        generate_list_ml_to_c ~ctx ~var:ocaml_var ~elem_type ~kind
          ~xfer:gir_type.transfer_ownership
      in
      Some (ocaml_var ^ "_list", conversion_code)
