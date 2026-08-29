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

(** Get the element converter expression for a given element type: the
    Val_* conversion applied to [_tmp->data], with the element's ownership
    handled per the return's transfer mode.

    For [TransferNone]/[TransferContainer] returns the ELEMENTS are
    borrowed (owned by the callee), but every owning wrapper's finalizer
    unconditionally releases (g_object_unref / g_boxed_free /
    g_variant_unref) — so a borrowed pointer must first gain a reference
    the wrapper can own: g_object_ref_sink for GObjects (the
    flow_box get_selected_children double-click crash class), g_boxed_copy
    for opaque boxed records, g_variant_ref for GVariants. Copying
    converters (strings, value-like records) and value-encoded types
    (enums, bitfields, primitives) are ownership-agnostic and need
    nothing. A borrowed GType-less opaque record ([Ts_none] with a class
    wrapper, e.g. GIOExtension) has no way to take a reference at all —
    return [None] so the caller emits the loud TODO placeholder instead of
    a finalizer that frees callee-owned memory. *)
let element_converter_name ~(ctx : generation_context)
    ~(xfer : transfer_ownership) (elem_type : gir_type) : string option =
  let elements_borrowed =
    match xfer with
    | TransferNone | TransferContainer -> true
    | TransferFull | TransferFloating -> false
  in
  match elem_type.name with
  | "utf8" | "filename" | "gchararray" | "gchar*" | "const gchar*" ->
      Some "caml_copy_string((const char*)_tmp->data)"
  | _ -> (
      (* For other types, look up the type mapping *)
      match Type_mappings.find_type_mapping_for_gir_type ~ctx elem_type with
      | None -> None
      | Some (tm : type_mapping) ->
          if String.equal tm.c_to_ml "LIST_INLINE" then
            (* Nested list - shouldn't happen in practice *)
            Some "Val_GList(_tmp->data, Val_GList_string)"
          else
            let cast = Option.value ~default:"gpointer" elem_type.c_type in
            if not elements_borrowed then
              Some (sprintf "%s((%s)_tmp->data)" tm.c_to_ml cast)
            else (
              match tm.transfer_strategy with
              | Ts_gobject ->
                  Some
                    (sprintf "%s((%s)g_object_ref_sink(_tmp->data))"
                       tm.c_to_ml cast)
              | Ts_boxed get_type when not tm.is_value_type_record ->
                  Some
                    (sprintf "%s((%s)g_boxed_copy(%s(), _tmp->data))"
                       tm.c_to_ml cast get_type)
              | Ts_boxed _ (* value-like: converter already copies *) ->
                  Some (sprintf "%s((%s)_tmp->data)" tm.c_to_ml cast)
              | Ts_gvariant ->
                  Some
                    (sprintf "%s(g_variant_ref((GVariant*)_tmp->data))"
                       tm.c_to_ml)
              | Ts_none
                when (not tm.is_value_type_record)
                     && Option.map_or ~default:false
                          (fun c -> Stdlib.String.ends_with ~suffix:"*" c)
                          elem_type.c_type ->
                  (* Borrowed pointer to a GType-less opaque record (e.g.
                     GIOExtension): its wrapper's finalizer g_frees, and
                     there is no way to take a reference — unrepresentable,
                     fall through to the loud TODO placeholder. *)
                  None
              | Ts_none ->
                  (* Value-encoded element (enum/bitfield/primitive):
                     ownership-agnostic. *)
                  Some (sprintf "%s((%s)_tmp->data)" tm.c_to_ml cast)))

(** Generate cleanup code for a GList based on transfer_ownership.

    Transfer ownership rules:
    - TransferNone: List is owned by the callee — caller must NOT free it
    - TransferContainer: Caller owns the list nodes but not the elements
    - TransferFull: Caller owns both list and elements. Elements whose
      wrapper ADOPTS the pointer (GObject, opaque boxed, GVariant) are
      handled by the wrapper's finalizer — do not double-unref; elements
      whose converter COPIES (strings, value-like records) leave the owned
      original behind, so it must be freed here
    - TransferFloating: Like Full *)
let generate_list_cleanup ~(ctx : generation_context) ~(kind : list_kind) ~var
    ~(xfer : transfer_ownership) ~(elem_type : gir_type) =
  let free_func =
    match kind with `GList -> "g_list_free" | `GSList -> "g_slist_free"
  in
  let free_full_func =
    match kind with
    | `GList -> "g_list_free_full"
    | `GSList -> "g_slist_free_full"
  in
  match xfer with
  | TransferNone ->
      (* Callee still owns this list — freeing it would corrupt callee state *)
      ""
  | TransferContainer ->
      (* Free the list nodes only; the callee still owns the elements *)
      sprintf "%s(%s);" free_func var
  | TransferFull | TransferFloating -> (
      match elem_type.name with
      | "utf8" | "filename" | "gchararray" | "gchar*" | "const gchar*" ->
          (* caml_copy_string copied; the owned originals must go too *)
          sprintf "%s(%s, g_free);" free_full_func var
      | _ -> (
          match Type_mappings.find_type_mapping_for_gir_type ~ctx elem_type with
          | Some
              {
                transfer_strategy = Ts_boxed get_type;
                is_value_type_record = true;
                _;
              } ->
              (* Value-like record: the converter copied the struct, so the
                 owned boxed originals must be freed alongside the nodes *)
              sprintf
                "{ %s _l; for (_l = %s; _l != NULL; _l = _l->next) \
                 g_boxed_free(%s(), _l->data); %s(%s); }"
                (c_type_of_list_kind kind) var get_type free_func var
          | _ ->
              (* Adopting wrapper owns each element; free the nodes only *)
              sprintf "%s(%s);" free_func var))

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

  match element_converter_name ~ctx ~xfer elem_type with
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
        else sprintf "%s(%s, result, item, cell, %s);" macro_name var elem_conv
      in
      ("CAMLlocal3(result, item, cell);", conv_body, "CAMLreturn(result);")

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
