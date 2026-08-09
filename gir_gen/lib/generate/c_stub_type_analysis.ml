(* Type Analysis Helpers for Property Type Introspection *)

open Containers
open StdLabels
open Types

(** Type analysis helpers for property type introspection *)
module Type_analysis = struct
  type property_gvalue_info = {
    base_type : string;
    base_lower : string;
    has_pointer : bool;
    pointer_like : bool;
    record_info : (gir_record * bool * bool) option;
    class_info : gir_class option;
    is_enum : bool;
    is_bitfield : bool;
    stack_allocated : bool;
  }
  (** Result of analyzing a property's GIR type: the C representation details
      needed to generate GValue conversion code. *)

  (** [list_contains ~value list] returns [true] when [value] is a member of
      [list] (exact string comparison). *)
  let list_contains ~value list =
    List.exists list ~f:(fun candidate -> String.equal candidate value)

  let ends_with ~suffix str =
    let len_s = String.length suffix and len_str = String.length str in
    len_str >= len_s
    && String.equal (String.sub str ~pos:(len_str - len_s) ~len:len_s) suffix

  (* Predicates moved to Filtering. *)

  (** Fold with map and index - combines fold_left_map with index tracking *)
  let fold_mapi ~f ~init list =
    let rec aux idx acc = function
      | [] -> (acc, [])
      | x :: xs ->
          let acc', y = f idx acc x in
          let final_acc, ys = aux (idx + 1) acc' xs in
          (final_acc, y :: ys)
    in
    aux 0 init list

  (** C type names treated as strings (e.g. ["gchar"], ["utf8"]). *)
  let string_base_types = [ "gchar"; "char"; "utf8"; "gchararray" ]

  (** C type names mapped to 32-bit signed integers. *)
  let int32_types =
    [ "gint"; "int"; "gint32"; "int32"; "gint16"; "int16"; "gint8"; "int8" ]

  (** C type names mapped to 32-bit unsigned integers. *)
  let uint32_types =
    [
      "guint";
      "uint";
      "guint32";
      "uint32";
      "guint16";
      "uint16";
      "guint8";
      "uint8";
    ]

  (** C type names mapped to 64-bit signed integers. *)
  let int64_types = [ "gint64"; "int64" ]

  (** C type names mapped to 64-bit unsigned integers. *)
  let uint64_types = [ "guint64"; "uint64" ]

  (** C type names mapped to [glong]-style signed long integers. *)
  let long_types = [ "glong"; "long"; "goffset"; "off_t" ]

  (** C type names mapped to [gulong]-style unsigned long integers. *)
  let ulong_types = [ "gulong"; "ulong" ]

  (** C type names mapped to [gssize]-style signed size integers. *)
  let ssize_types = [ "gssize"; "ssize_t" ]

  (** C type names mapped to [gsize]-style unsigned size integers. *)
  let size_types = [ "gsize"; "size_t" ]

  (** C type names mapped to single-precision floats. *)
  let float_types = [ "gfloat"; "float" ]

  (** C type names mapped to double-precision floats. *)
  let double_types = [ "gdouble"; "double" ]

  let pointer_types = [ "gpointer"; "gconstpointer" ]

  let all_stack_allocated_builtins =
    string_base_types @ int32_types @ uint32_types @ int64_types @ uint64_types
    @ long_types @ ulong_types @ ssize_types @ float_types @ double_types
    @ pointer_types

  (** Check if a C type is a string type. Delegates to the canonical definition
      in [Filtering]. *)
  let is_string_type = Filtering.is_string_type

  (** Analyze property type and extract GValue conversion information *)
  let analyze_property_type ~ctx (gir_type : gir_type) =
    let c_type =
      match gir_type.c_type with
      | Some c_type -> c_type
      | None ->
          Type_mappings.find_type_mapping_for_gir_type ~ctx gir_type
          |> Option.map (fun (tm : type_mapping) -> tm.c_type)
          |> Option.value ~default:"void"
    in
    let normalized =
      Type_mappings.normalize_c_pointer_type c_type |> String.trim
    in
    let rec find_last idx =
      if idx < 0 then None
      else
        match String.get normalized idx with
        | ' ' | '\t' -> find_last (idx - 1)
        | '*' -> Some idx
        | _ -> None
    in
    let base_type, has_pointer =
      match find_last (String.length normalized - 1) with
      | Some idx ->
          let stripped = String.trim (String.sub normalized ~pos:0 ~len:idx) in
          (stripped, true)
      | None -> (normalized, false)
    in
    let base_lower = String.lowercase_ascii gir_type.name in
    let record_info =
      Type_mappings.lookup_record ~records:ctx.records ~lookup_str:gir_type.name
    in
    let class_info =
      Type_mappings.lookup_class ~classes:ctx.classes ~lookup_str:gir_type.name
    in
    let type_kind = Type_mappings.classify_type ~ctx gir_type in
    let is_enum =
      match type_kind with Type_mappings.Tk_Enum -> true | _ -> false
    in
    let is_bitfield =
      match type_kind with Type_mappings.Tk_Bitfield -> true | _ -> false
    in
    let pointer_like =
      has_pointer
      || List.exists pointer_types ~f:(fun candidate ->
          String.equal candidate base_lower)
    in
    let stack_allocated =
      is_enum || is_bitfield
      || List.exists ~f:(String.equal normalized) all_stack_allocated_builtins
    in
    {
      base_type;
      base_lower;
      has_pointer;
      pointer_like;
      record_info;
      class_info;
      is_enum;
      is_bitfield;
      stack_allocated;
    }
end
