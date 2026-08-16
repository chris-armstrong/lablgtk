(* Array Conversion Helpers *)

open Containers
open StdLabels
open Types

(** Array conversion helpers *)
module Array_conv = struct
  (* Strip const qualifier from C type for array allocation.
     When allocating arrays for input parameters, we need non-const arrays
     even if the parameter type is const. *)
  let strip_const c_type =
    c_type |> String.trim
    |> CCString.replace ~sub:"const " ~by:""
    |> CCString.replace ~sub:" const" ~by:""
    |> String.trim

  (** Check if an array contains string elements. Delegates to the canonical
      definition in [Filtering]. *)
  let is_string_array = Filtering.is_string_array

  (** Check if a C type is a string type. Delegates to the canonical definition
      in [Filtering]. *)
  let is_string_type = Filtering.is_string_type

  (** Generate conversion code for zero-terminated arrays. Handles both pointer
      arrays (NULL-terminated) and non-pointer arrays (structs).
      [elem_type_alloc] is the pre-computed element type for allocation —
      callers are responsible for preserving or stripping const as appropriate.
  *)
  let zero_terminated_conversion ~length_var ~c_array_var ~var ~elem_type_alloc
      ~element_tm ~is_pointer_array ~deref_prefix =
    if is_pointer_array then
      Fmt.str
        "int %s = Wosize_val(%s);\n\
        \    %s* %s = (%s*)g_malloc(sizeof(%s) * (%s + 1));\n\
        \    for (int i = 0; i < %s; i++) {\n\
        \      %s[i] = %s(Field(%s, i));\n\
        \    }\n\
        \    %s[%s] = NULL;"
        length_var var elem_type_alloc c_array_var elem_type_alloc
        elem_type_alloc length_var length_var c_array_var element_tm.ml_to_c var
        c_array_var length_var
    else
      Fmt.str
        "int %s = Wosize_val(%s);\n\
        \    %s* %s = (%s*)g_malloc(sizeof(%s) * (%s + 1));\n\
        \    for (int i = 0; i < %s; i++) {\n\
        \      %s[i] = %s%s(Field(%s, i));\n\
        \    }\n\
        \    %s[%s] = (%s){0};"
        length_var var elem_type_alloc c_array_var elem_type_alloc
        elem_type_alloc length_var length_var c_array_var deref_prefix
        element_tm.ml_to_c var c_array_var length_var elem_type_alloc

  (** Generate conversion code for non-zero-terminated arrays. Allocates memory
      without extra slot for NULL terminator. [elem_type_alloc] is the
      pre-computed element type for allocation. *)
  let non_zero_terminated_conversion ~length_var ~c_array_var ~var
      ~elem_type_alloc ~element_tm ~deref_prefix =
    Fmt.str
      "int %s = Wosize_val(%s);\n\
      \    %s* %s = (%s*)g_malloc(sizeof(%s) * %s);\n\
      \    for (int i = 0; i < %s; i++) {\n\
      \      %s[i] = %s%s(Field(%s, i));\n\
      \    }"
      length_var var elem_type_alloc c_array_var elem_type_alloc elem_type_alloc
      length_var length_var c_array_var deref_prefix element_tm.ml_to_c var

  (** Generate length code when length is explicitly provided. *)
  let length_code_explicit ~length_var ~expr =
    Fmt.str "int %s = %s;" length_var expr

  (** Generate length code for zero-terminated pointer arrays. *)
  let length_code_for_zero_terminated_pointer ~length_var ~var =
    Fmt.str "int %s = 0;\n    while (%s[%s] != NULL) %s++;" length_var var
      length_var length_var

  (** Generate length code for zero-terminated non-pointer arrays. *)
  let length_code_for_zero_terminated_nonpointer ~length_var ~var
      ~element_c_type =
    Fmt.str "int %s = 0;\n    while (%s[%s] != (%s)0) %s++;" length_var var
      length_var element_c_type length_var

  (** Generate length code for string arrays (NULL-terminated). *)
  let length_code_for_string_array ~length_var ~var =
    Fmt.str "int %s = 0;\n    while (%s[%s] != NULL) %s++;" length_var var
      length_var length_var

  (** Generate cleanup code for string arrays (frees each string and then the
      container). *)
  let cleanup_for_string_array ~length_var ~var =
    Fmt.str
      "for (int i = 0; i < %s; i++) {\n\
      \      g_free((gpointer)%s[i]);\n\
      \    }\n\
      \    g_free(%s);"
      length_var var var

  (** Generate cleanup code for pointer arrays (just frees the container). *)
  let cleanup_for_pointer_array ~var = Fmt.str "g_free(%s);" var

  (** Generate length code for arrays when no explicit length is provided.
      Returns the appropriate length code based on array properties. *)
  let length_code_for_array ~var ~length_var ~array_info ~is_pointer_array
      ~element_c_type =
    (* First, check for fixed-size arrays - the length is known at compile time *)
    match array_info.fixed_size with
    | Some size ->
        (* Fixed-size array: use the constant size directly *)
        Fmt.str "int %s = %d;" length_var size
    | None ->
        if array_info.zero_terminated then
          if is_pointer_array then
            length_code_for_zero_terminated_pointer ~length_var ~var
          else
            length_code_for_zero_terminated_nonpointer ~length_var ~var
              ~element_c_type
        else if is_string_array array_info then
          length_code_for_string_array ~length_var ~var
        else if is_pointer_array then
          (* For pointer arrays without explicit length info, assume zero-terminated
             This handles cases where the GIR file is missing zero-terminated="1" *)
          length_code_for_zero_terminated_pointer ~length_var ~var
        else
          (* Check for common C patterns that suggest zero-terminated arrays *)
          let elem_c_type =
            Option.value ~default:"" array_info.element_type.c_type
          in
          if String.contains elem_c_type '*' then
            (* Element type is a pointer - assume zero-terminated pointer array *)
            length_code_for_zero_terminated_pointer ~length_var ~var
          else
            (* No length information and not a string array - cannot safely convert *)
            failwith
              (Fmt.str
                 "Array has no length information for %s (element type: %s). \
                  Either zero-terminated, length, or fixed-size attribute \
                  required."
                 var array_info.element_type.name)

  (** Generate cleanup code for TransferFull ownership. Returns appropriate
      cleanup based on array properties. *)
  let cleanup_code_for_transfer_full ~array_info ~is_pointer_array ~length_var
      ~var =
    if is_string_array array_info then cleanup_for_string_array ~length_var ~var
    else if is_pointer_array then
      (* Generic pointer array: might need element-wise freeing, but we can't know the type *)
      (* For now, just free the container - this may leak if elements need freeing *)
      (* TODO: Add heuristics or metadata to determine if elements need freeing *)
      cleanup_for_pointer_array ~var
    else
      (* Primitive array: just free the container *)
      cleanup_for_pointer_array ~var

  (* Generate inline code for converting OCaml array to C array *)
  let generate_array_ml_to_c ~ctx ~var ~(array_info : gir_array)
      ~element_mapping:(_ : Types.type_mapping) ~element_c_type
      ~transfer_ownership ~nullable =
    (* Get element type mapping for conversion *)
    match
      Type_mappings.find_type_mapping_for_gir_type ~ctx array_info.element_type
    with
    | None ->
        failwith
          (Fmt.str "Array element type '%s' not supported"
             array_info.element_type.name)
    | Some element_tm ->
        let length_var = var ^ "_length" in
        let c_array_var = "c_" ^ var in

        (* For string arrays, String_val returns const char* — preserve const so
           the array element type is const char* and assignments don't discard
           the qualifier.  For all other types, strip const so we get a mutable
           array we can fill in. *)
        let is_string_elem = String.equal element_tm.ml_to_c "String_val" in
        let elem_type_alloc =
          if is_string_elem then "const char*" else strip_const element_c_type
        in
        let is_pointer_array = String.contains elem_type_alloc '*' in

        (* Determine if this array should be zero-terminated *)
        let should_zero_terminate =
          array_info.zero_terminated
          ||
          (* Default: string arrays without explicit length are typically zero-terminated in GTK *)
          (is_string_array array_info && Option.is_none array_info.length)
        in

        (* For struct arrays (non-pointer elements), we need to dereference the
           conversion result only if the converter returns a pointer.
           Primitive converters (Int_val, Double_val, Bool_val, String_val)
           return values directly, not pointers.
           GObject converters (GObject_ext_of_val etc.) return pointers that
           should be stored directly into gpointer arrays without dereference. *)
        let is_primitive_converter =
          String.equal element_tm.ml_to_c "Int_val"
          || String.equal element_tm.ml_to_c "Double_val"
          || String.equal element_tm.ml_to_c "Bool_val"
          || String.equal element_tm.ml_to_c "Long_val"
          || String.equal element_tm.ml_to_c "GType_val"
          || String.equal element_tm.ml_to_c "Int32_val"
          || String.equal element_tm.ml_to_c "Int64_val"
          || String.equal element_tm.ml_to_c "Uint64_val"
          || is_string_elem
        in
        let is_gobject_converter =
          String.equal element_tm.ml_to_c "GObject_ext_of_val"
        in
        let deref_prefix =
          if is_pointer_array || is_primitive_converter || is_gobject_converter
          then ""
          else "*"
        in

        (* Generate conversion code based on array type and nullable *)
        let conversion_code =
          if nullable then
            (* For nullable arrays, wrap in option check *)
            let inner_conversion =
              if should_zero_terminate then
                Fmt.str
                  "value array = Some_val(%s);\n\
                  \        %s = Wosize_val(array);\n\
                  \        %s = (%s*)g_malloc(sizeof(%s) * (%s + 1));\n\
                  \        for (int i = 0; i < %s; i++) {\n\
                  \          %s[i] = %s%s(Field(array, i));\n\
                  \        }\n\
                  \        %s[%s] = %s;"
                  var length_var c_array_var elem_type_alloc elem_type_alloc
                  length_var length_var c_array_var deref_prefix
                  element_tm.ml_to_c c_array_var length_var
                  (if is_pointer_array then "NULL"
                   else Fmt.str "(%s){0}" elem_type_alloc)
              else
                Fmt.str
                  "value array = Some_val(%s);\n\
                  \        %s = Wosize_val(array);\n\
                  \        %s = (%s*)g_malloc(sizeof(%s) * %s);\n\
                  \        for (int i = 0; i < %s; i++) {\n\
                  \          %s[i] = %s%s(Field(array, i));\n\
                  \        }"
                  var length_var c_array_var elem_type_alloc elem_type_alloc
                  length_var length_var c_array_var deref_prefix
                  element_tm.ml_to_c
            in
            Fmt.str
              "int %s = 0;\n\
              \    %s* %s = NULL;\n\
              \    \n\
              \    if (Is_some(%s)) {\n\
              \        %s\n\
              \    }"
              length_var elem_type_alloc c_array_var var inner_conversion
          else if
            (* Non-nullable: direct conversion *)
            should_zero_terminate
          then
            zero_terminated_conversion ~length_var ~c_array_var ~var
              ~elem_type_alloc ~element_tm ~is_pointer_array ~deref_prefix
          else
            non_zero_terminated_conversion ~length_var ~c_array_var ~var
              ~elem_type_alloc ~element_tm ~deref_prefix
        in

        (* Generate cleanup code if needed (TransferNone means we still own the memory) *)
        let cleanup_code =
          match transfer_ownership with
          | Types.TransferNone ->
              (* GTK won't free it, we must clean up after the call *)
              let cleanup_expr = Fmt.str "g_free(%s);" c_array_var in
              if nullable then Fmt.str "if (%s) %s" c_array_var cleanup_expr
              else cleanup_expr
          | Types.TransferFull | Types.TransferContainer
          | Types.TransferFloating ->
              (* GTK takes ownership, no cleanup needed *)
              ""
        in

        (conversion_code, c_array_var, length_var, cleanup_code)

  (* Check if an array is a GPtrArray (GLib.PtrArray) *)
  let is_gptr_array (array_info : gir_array) =
    match array_info.array_name with
    | Some name -> String.equal name "GLib.PtrArray"
    | None -> false

  (* Generate inline code for converting C array to OCaml array.
     When [nullable] is true the C pointer can be NULL; the generated code
     emits a NULL guard and returns either [Val_none] or [Val_some(array)].
     The returned [ml_array_var] name is the option-wrapping variable in that
     case so callers can use it uniformly. *)
  let generate_array_c_to_ml ~ctx ~var ~(array_info : gir_array) ~length_expr
      ~element_c_type ~transfer_ownership ?(nullable = false) () =
    match
      Type_mappings.find_type_mapping_for_gir_type ~ctx array_info.element_type
    with
    | None ->
        failwith
          (Fmt.str "Array element type '%s' not supported"
             array_info.element_type.name)
    | Some element_tm ->
        let ml_array_var = "ml_" ^ var in
        let ml_opt_var = ml_array_var ^ "_opt" in
        let length_var = var ^ "_length" in
        let is_pointer_array = String.contains element_c_type '*' in

        (* Check if this is a GPtrArray *)
        let is_gptr_array = is_gptr_array array_info in

        (* Generate code to compute length and access data *)
        let length_code, data_var =
          if is_gptr_array then
            (* GPtrArray: use ->len and ->pdata fields *)
            ( Fmt.str "guint %s = %s->len;\n    gpointer* %s_pdata = %s->pdata;"
                length_var var var var,
              var ^ "_pdata" )
          else
            (* Regular array *)
            let lcode =
              match length_expr with
              | Some expr -> length_code_explicit ~length_var ~expr
              | None ->
                  length_code_for_array ~var ~length_var ~array_info
                    ~is_pointer_array ~element_c_type
            in
            (lcode, var)
        in

        (* Generate conversion loop *)
        (* For struct arrays (non-pointer elements stored by value in C array),
           we need to take the address when passing to conversion functions that expect pointers.
           Primitive converters (caml_copy_double, Val_int, etc.) work with values directly.
           Enum and bitfield converters also take values directly (not pointers). *)
        let is_primitive_converter =
          String.equal element_tm.c_to_ml "Val_int"
          || String.equal element_tm.c_to_ml "Val_bool"
          || String.equal element_tm.c_to_ml "caml_copy_double"
          || String.equal element_tm.c_to_ml "caml_copy_string"
          || String.equal element_tm.c_to_ml "Val_long"
          || String.equal element_tm.c_to_ml "Val_GType"
          || String.equal element_tm.c_to_ml "caml_copy_int32"
          || String.equal element_tm.c_to_ml "caml_copy_int64"
          || String.equal element_tm.c_to_ml "integers_copy_uint64"
        in
        (* Check if element type is an enum or bitfield - these take values, not pointers.
           Use classify_type to handle both same-namespace and cross-namespace types. *)
        let element_type_kind =
          Type_mappings.classify_type ~ctx array_info.element_type
        in
        let is_value_type =
          is_primitive_converter
          ||
          match element_type_kind with
          | Type_mappings.Tk_Enum | Type_mappings.Tk_Bitfield -> true
          | _ -> false
        in
        let addr_prefix =
          if is_pointer_array || is_value_type then "" else "&"
        in

        (* Inner body: array alloc + loop, WITHOUT the CAMLlocal1 declaration.
           Used inside the nullable else-branch where ml_array_var is already
           declared by CAMLlocal2. *)
        let inner_body_code =
          if is_gptr_array then
            Fmt.str
              "%s\n\
              \      %s = caml_alloc(%s, 0);\n\
              \      for (int i = 0; i < %s; i++) {\n\
              \        Store_field(%s, i, %s((%s)%s[i]));\n\
              \      }"
              length_code ml_array_var length_var length_var ml_array_var
              element_tm.c_to_ml element_c_type data_var
          else
            Fmt.str
              "%s\n\
              \      %s = caml_alloc(%s, 0);\n\
              \      for (int i = 0; i < %s; i++) {\n\
              \        Store_field(%s, i, %s(%s%s[i]));\n\
              \      }"
              length_code ml_array_var length_var length_var ml_array_var
              element_tm.c_to_ml addr_prefix data_var
        in

        (* Inner conversion WITH CAMLlocal1: used in the non-nullable path where
           no outer CAMLlocal declaration exists for ml_array_var. *)
        let inner_conversion_code_with_local =
          if is_gptr_array then
            Fmt.str
              "%s\n\
              \    CAMLlocal1(%s);\n\
              \    %s = caml_alloc(%s, 0);\n\
              \    for (int i = 0; i < %s; i++) {\n\
              \      Store_field(%s, i, %s((%s)%s[i]));\n\
              \    }"
              length_code ml_array_var ml_array_var length_var length_var
              ml_array_var element_tm.c_to_ml element_c_type data_var
          else
            Fmt.str
              "%s\n\
              \    CAMLlocal1(%s);\n\
              \    %s = caml_alloc(%s, 0);\n\
              \    for (int i = 0; i < %s; i++) {\n\
              \      Store_field(%s, i, %s(%s%s[i]));\n\
              \    }"
              length_code ml_array_var ml_array_var length_var length_var
              ml_array_var element_tm.c_to_ml addr_prefix data_var
        in

        (* Cleanup expression for non-nullable path (appended after the call) *)
        let outer_cleanup_code =
          match transfer_ownership with
          | Types.TransferNone | Types.TransferFloating ->
              (* GTK owns the array - don't free it *)
              ""
          | Types.TransferContainer ->
              (* We own the container but not the elements *)
              if is_gptr_array then
                (* GPtrArray: use g_ptr_array_unref *)
                Fmt.str "g_ptr_array_unref(%s);" var
              else cleanup_for_pointer_array ~var
          | Types.TransferFull ->
              (* We own everything *)
              if is_gptr_array then
                (* GPtrArray: free with g_ptr_array_unref (TRUE to free elements) *)
                Fmt.str "g_ptr_array_free(%s, TRUE);" var
              else
                cleanup_code_for_transfer_full ~array_info ~is_pointer_array
                  ~length_var ~var
        in

        (* When nullable, wrap the inner body in a NULL guard and return an
           option (Val_none / Val_some).  CAMLlocal2 declares both ml_array_var
           and ml_opt_var so the inner body must NOT redeclare ml_array_var.

           Cleanup code (if any) uses result_length which is declared inside the
           else-block, so it must be emitted inside the else-branch rather than
           appended after the if/else.  We return an empty cleanup string for the
           nullable path so callers don't append it again at the wrong scope. *)
        let conversion_code, result_var, cleanup_code =
          if nullable then
            let inline_cleanup =
              if String.length outer_cleanup_code > 0 then
                Fmt.str "      %s\n" outer_cleanup_code
              else ""
            in
            ( Fmt.str
                "CAMLlocal2(%s, %s);\n\
                \    if (%s == NULL) {\n\
                \      %s = Val_none;\n\
                \    } else {\n\
                \      %s\n\
                \      %s = Val_some(%s);\n\
                \      %s    }"
                ml_array_var ml_opt_var var ml_opt_var inner_body_code
                ml_opt_var ml_array_var inline_cleanup,
              ml_opt_var,
              "" (* cleanup already inlined above *) )
          else
            (inner_conversion_code_with_local, ml_array_var, outer_cleanup_code)
        in

        (conversion_code, result_var, cleanup_code)
end
