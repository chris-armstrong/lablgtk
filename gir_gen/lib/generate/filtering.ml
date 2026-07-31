(* Shared filtering helpers for GIR generators *)

open StdLabels
open Types
module StringSet = Set.Make (String)

module Log =
  (val Logs.src_log
         (Logs.Src.create "gir_gen.filtering"
            ~doc:"Shared filtering helpers for GIR generators"))

let has_simple_type ~ctx (gir_type : gir_type) =
  match Type_mappings.find_type_mapping_for_gir_type ~ctx gir_type with
  | Some _ ->
      Logs.debug (fun m -> m "has_simple_type: %s -> true\n" gir_type.name);
      true
  | None -> false

(* Check if a type is an array type - arrays require inline code generation
   and can't be handled by simple type mapping macros *)
let is_array_type (gir_type : gir_type) = Option.is_some gir_type.array

let should_generate_property ~ctx ~class_name:_ ~methods (prop : gir_property) =
  (* Array-typed properties can't be generated — the GObject property system
       would require marshalling arrays through GValue which we don't support *)
  if is_array_type prop.prop_type then false
  else
    let matches_method =
      List.exists
        ~f:(fun m ->
          m.set_property
          |> Option.map (String.equal prop.prop_name)
          |> Option.value ~default:false
          || m.get_property
             |> Option.map (String.equal prop.prop_name)
             |> Option.value ~default:false)
        methods
    in
    Log.debug (fun m ->
        m "matches method %s=%b\n" prop.prop_name matches_method);
    (not matches_method) && has_simple_type ~ctx prop.prop_type

let property_method_names ~ctx ~class_name ~methods
    (properties : gir_property list) =
  let names, _ =
    List.fold_left properties ~init:([], StringSet.empty)
      ~f:(fun (acc, seen) (prop : gir_property) ->
        if not (should_generate_property ~ctx ~class_name ~methods prop) then
          (acc, seen)
        else
          let prop_snake = Utils.sanitize_property_name prop.prop_name in
          let acc, seen =
            if prop.readable && not (StringSet.mem ("get_" ^ prop_snake) seen)
            then
              ( ("get_" ^ prop_snake) :: acc,
                StringSet.add ("get_" ^ prop_snake) seen )
            else (acc, seen)
          in
          let acc, seen =
            if
              prop.writable && (not prop.construct_only)
              && not (StringSet.mem ("set_" ^ prop_snake) seen)
            then
              ( ("set_" ^ prop_snake) :: acc,
                StringSet.add ("set_" ^ prop_snake) seen )
            else (acc, seen)
          in
          (acc, seen))
  in
  names

let property_base_names ~ctx ~class_name ~methods
    (properties : gir_property list) =
  properties
  |> List.filter ~f:(fun prop ->
      should_generate_property ~ctx ~class_name ~methods prop)
  |> List.map ~f:(fun (prop : gir_property) ->
      Utils.sanitize_property_name prop.prop_name)

(** Check if a C type is a string type. *)
let is_string_type ctype =
  match ctype with
  | Some
      ( "char*" | "gchararray" | "gchar*" | "utf8" | "const gchar*"
      | "const char*" ) ->
      true
  | _ -> false

(** Check if an array contains string elements. *)
let is_string_array (array_info : gir_array) =
  let elem_name = String.lowercase_ascii array_info.element_type.name in
  let elem_ctype = array_info.element_type.c_type in
  String.equal elem_name "utf8"
  || String.equal elem_name "gchararray"
  || String.equal elem_name "filename"
  || is_string_type elem_ctype

(** Check if an array type lacks sufficient length information for C code
    generation. This matches the failure condition in
    [C_stub_array_conv.Array_conv.length_code_for_array]: arrays with no
    fixed_size, not zero_terminated, not a string array, and whose element type
    is a non-pointer primitive will cause the C generator to throw. *)
let array_lacks_length_info (arr : gir_array) =
  let is_string = is_string_array arr in
  let elem_c_type = Option.value ~default:"" arr.element_type.c_type in
  let is_pointer_element = String.contains elem_c_type '*' in
  Option.is_none arr.fixed_size
  && (not arr.zero_terminated) && (not is_string) && (not is_pointer_element)
  && Option.is_none arr.length

(** Check if a method has any array (in parameters or return type) that would
    cause the C code generator to fail due to missing length information.

    GList and GSList types are always supported since they use macro-based
    conversion and don't need explicit length information.

    GLib.HashTable is not an array type and should not be checked as such. *)
let method_has_unsupported_arrays ~ctx:_ (meth : gir_method) =
  (* Check if the array type is a GList/GSList - these are always supported *)
  let is_glist_or_gslist (arr : gir_array) =
    match arr.array_name with
    | Some n -> Gir_type_pred.is_glist_name n || Gir_type_pred.is_gslist_name n
    | None -> false
  in
  let return_array_unsupported =
    match meth.return_type.array with
    | Some arr when is_glist_or_gslist arr ->
        false (* GList/GSList with any element type is supported *)
    | Some arr when Gir_type_pred.is_hash_table_array arr ->
        false (* HashTable is not an array *)
    | Some arr -> array_lacks_length_info arr
    | None -> false
  in
  let param_array_unsupported =
    List.exists meth.parameters ~f:(fun (p : gir_param) ->
        match p.param_type.array with
        | Some arr
          when Gir_type_pred.Gir_direction.is_in_only p.direction
               && is_glist_or_gslist arr ->
            false (* GList/GSList params are supported *)
        | Some arr
          when Gir_type_pred.Gir_direction.is_in_only p.direction
               && Gir_type_pred.is_hash_table_array arr ->
            false (* HashTable is not an array *)
        | Some arr when Gir_type_pred.Gir_direction.is_in_only p.direction ->
            array_lacks_length_info arr
        | _ -> false)
  in
  return_array_unsupported || param_array_unsupported

(** Check if a method has out-parameter arrays that cannot be safely converted.
    This covers two cases: 1. Arrays with zero_terminated=false and no length or
    fixed_size info 2. Double-pointer out-params not marked as arrays in GIR *)
let method_has_unsupported_out_arrays (meth : gir_method) =
  List.exists meth.parameters ~f:(fun (p : gir_param) ->
      match p.direction with
      | Out | InOut -> (
          match p.param_type.array with
          | Some arr ->
              (not arr.zero_terminated) && Option.is_none arr.length
              && Option.is_none arr.fixed_size
          | None -> (
              (* Double-pointer out-param not marked as array - likely a hidden array *)
              match p.param_type.c_type with
              | Some ct ->
                  let len = String.length ct in
                  len >= 2 && ct.[len - 1] = '*' && ct.[len - 2] = '*'
              | None -> false))
      | In -> false)

(* ========== Entity kind ADT ==========

   Carries the "what kind of entity is being emitted" signal through the
   generator without dragging the full [Types.entity_kind] payload, and
   lets the central method-skip predicate fold the record-destructor
   filter into its single answer. The ADT is intentionally non-optional
   at every call site so a future entity kind (e.g. boxed enum) cannot
   silently inherit the wrong filter. *)

type entity_kind = Class | Interface | Record

let entity_kind_of_entity (entity : Types.entity) : entity_kind =
  match entity.Types.kind with
  | Types.Class _ -> Class
  | Types.Interface _ -> Interface
  | Types.Record _ -> Record

(* ========== Method-name predicates ========== *)

let private_ends_with ~suffix str =
  let ls = String.length suffix and lt = String.length str in
  lt >= ls && String.equal (String.sub str ~pos:(lt - ls) ~len:ls) suffix

(* A copy method — record's [_copy] symbol or a method literally named
   "copy". Records own their lifetime via the gir_record custom-block
   finalizer, so an exposed [copy] is redundant noise. *)
let is_copy_method (meth : gir_method) =
  let lower_name = String.lowercase_ascii meth.method_name in
  let lower_cid = String.lowercase_ascii meth.c_identifier in
  String.equal lower_name "copy" || private_ends_with ~suffix:"_copy" lower_cid

(* A free or unref method on a record — _free for boxed records, _unref for
   refcounted ones. Both fight the custom-block finalizer (which calls
   g_boxed_free, which itself dispatches to _unref for refcounted boxed
   types) and so manual invocation is a double-free hazard. *)
let is_free_method (meth : gir_method) =
  let lower_name = String.lowercase_ascii meth.method_name in
  let lower_cid = String.lowercase_ascii meth.c_identifier in
  String.equal lower_name "free"
  || String.equal lower_name "unref"
  || private_ends_with ~suffix:"_free" lower_cid
  || private_ends_with ~suffix:"_unref" lower_cid

let is_copy_or_free meth = is_copy_method meth || is_free_method meth

(* ========== Per-method emission predicate ========== *)

(* Single source of truth for "should we drop this method from emission".
   [entity_kind] tells the predicate which entity flavour the method
   belongs to so record-specific hazards (copy/free/unref) can be folded
   into the same answer. *)
let should_skip_method_binding ~ctx ~entity_kind (meth : gir_method) =
  let has_unknown_type =
    Exclude_list.should_skip_method
      ~find_type_mapping:(Type_mappings.find_type_mapping_for_gir_type ~ctx)
      ~enums:ctx.enums ~bitfields:ctx.bitfields meth
  in
  let is_variadic = List.exists meth.parameters ~f:(fun p -> p.varargs) in
  let is_not_introspectable = not meth.introspectable in
  let has_unsupported_out_arrays = method_has_unsupported_out_arrays meth in
  let has_unsupported_arrays = method_has_unsupported_arrays ~ctx meth in
  let is_record_destructor =
    match entity_kind with
    | Record -> is_copy_or_free meth
    | Class | Interface -> false
  in
  Logs.debug (fun m ->
      m "should_skip_method_binding: %s -> %b %b %b %b %b %b\n"
        meth.c_identifier is_variadic has_unknown_type is_not_introspectable
        has_unsupported_out_arrays has_unsupported_arrays is_record_destructor);

  is_variadic || has_unknown_type || is_not_introspectable
  || has_unsupported_out_arrays || has_unsupported_arrays
  || is_record_destructor

let constructor_has_varargs (ctor : gir_constructor) =
  List.exists ctor.ctor_parameters ~f:(fun p -> p.varargs)

(* Check if a constructor should be generated based on multiple criteria:
   - Not throwing GError
   - No varargs
   - No unknown parameter types *)
let should_generate_constructor ~ctx (ctor : gir_constructor) =
  let has_unknown_type =
    Exclude_list.should_skip_constructor
      ~find_type_mapping:(Type_mappings.find_type_mapping_for_gir_type ~ctx)
      ~enums:ctx.enums ~bitfields:ctx.bitfields ctor
  in
  ctor.ctor_introspectable
  && (not (constructor_has_varargs ctor))
  && not has_unknown_type

(* Check if a record name ends with "Private" - these are typically internal
   GObject private data structures that don't appear in public headers *)
let should_skip_private_record (record : gir_record) =
  let name = record.record_name in
  let len = String.length name in
  len > 7 && String.equal (String.sub name ~pos:(len - 7) ~len:7) "Private"

(* Check if a record should be generated *)
let should_generate_record (record : gir_record) =
  record.Types.introspectable
  (* Filter out GObject class structs (records with is_gtype_struct_for attribute) *)
  && Option.is_none record.Types.is_gtype_struct_for
  (* Also filter out *Private records - internal structures not in public headers *)
  && not (should_skip_private_record record)

let should_generate_class (cls : gir_class) = cls.introspectable
let should_generate_interface (_intf : gir_interface) = true

(* Check if a standalone function should be generated *)
let should_generate_function (func : gir_function) = func.introspectable
