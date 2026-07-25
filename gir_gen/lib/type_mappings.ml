(* Type Mappings for GIR Code Generator *)
open Containers
open StdLabels
open Printf
open Types

let or_else f opt = match opt with Some _ -> opt | None -> f ()

let calculate_layer2_class ~class_module ~class_name =
  {
    class_module = "G" ^ class_module;
    class_type = class_name ^ "_t";
    class_ml_name = class_name;
    class_layer1_accessor = "as_" ^ class_name;
  }

(** Map a cross-namespace type reference to a type mapping. This function is
    used to convert a cross-reference to a type mapping.*)
let map_cross_reference_to_type_mapping ~ctx:_ ~namespace
    (cr : cross_reference_entity) : type_mapping =
  let external_namespace = Utils.external_namespace_to_module_name namespace in

  {
    ocaml_type =
      (match cr.cr_type with
      | Crt_Class _ | Crt_Record _ | Crt_Interface ->
          external_namespace ^ ".Wrappers."
          ^ Utils.module_name_of_class cr.cr_name
          ^ ".t"
      | Crt_Bitfield | Crt_Enum | Crt_Constant ->
          external_namespace ^ "." ^ String.lowercase_ascii cr.cr_name);
    c_type = cr.cr_c_type;
    c_to_ml =
      (match cr.cr_type with
      | Crt_Enum | Crt_Bitfield -> sprintf "Val_%s%s" namespace cr.cr_name
      | Crt_Constant -> sprintf "Val_%s" cr.cr_c_type
      | Crt_Class _ | Crt_Interface | Crt_Record _ -> "Val_" ^ cr.cr_c_type);
    ml_to_c =
      (match cr.cr_type with
      | Crt_Enum | Crt_Bitfield -> sprintf "%s%s_val" namespace cr.cr_name
      | Crt_Constant -> sprintf "%s_val" cr.cr_c_type
      | Crt_Class _ | Crt_Interface | Crt_Record _ -> cr.cr_c_type ^ "_val");
    layer2_class =
      (match cr.cr_type with
      | Crt_Class _ ->
          let c_name = Utils.ocaml_class_name cr.cr_name in
          Some
            {
              class_module =
                external_namespace ^ "." ^ Utils.module_name_of_class cr.cr_name;
              class_type = c_name ^ "_t";
              class_ml_name = c_name;
              class_layer1_accessor = "as_" ^ c_name;
            }
      | Crt_Interface ->
          let c_name = Utils.ocaml_interface_name cr.cr_name in
          Some
            {
              class_module =
                external_namespace ^ "." ^ Utils.module_name_of_class cr.cr_name;
              class_type = c_name ^ "_t";
              class_ml_name = c_name;
              class_layer1_accessor = "as_" ^ c_name;
            }
      | Crt_Record _ ->
          let c_name = Utils.ocaml_record_name cr.cr_name in
          Some
            {
              class_module =
                external_namespace ^ "." ^ Utils.module_name_of_class cr.cr_name;
              class_type = c_name ^ "_t";
              class_ml_name = c_name;
              class_layer1_accessor = "as_" ^ c_name;
            }
      | Crt_Enum | Crt_Bitfield | Crt_Constant -> None);
    is_value_type_record =
      (match cr.cr_type with
      | Crt_Record { opaque = false; _ } -> true
      | Crt_Class _ | Crt_Interface | Crt_Record _ | Crt_Enum | Crt_Bitfield
      | Crt_Constant ->
          false);
    transfer_strategy =
      (match cr.cr_type with
      | Crt_Class _ | Crt_Interface -> Ts_gobject
      | Crt_Record { get_type_func = Some f; _ } -> Ts_boxed f
      | Crt_Enum | Crt_Bitfield | Crt_Constant | Crt_Record { get_type_func = None; _ }
        ->
          Ts_none);
  }

(** Type mappings for built-in / primitive types (integers, strings, etc.) *)
let type_mappings : (string * Types.type_mapping) list =
  [
    ( "guint",
      ({
         Types.ocaml_type = "int";
         Types.c_to_ml = "Val_int";
         Types.ml_to_c = "Int_val";
         layer2_class = None;
         c_type = "guint";
         is_value_type_record = false;
      transfer_strategy = Ts_none;
       }
        : Types.type_mapping) );
    ( "gint",
      {
        ocaml_type = "int";
        c_to_ml = "Val_int";
        ml_to_c = "Int_val";
        layer2_class = None;
        c_type = "gint";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "gdouble",
      {
        ocaml_type = "float";
        c_to_ml = "caml_copy_double";
        ml_to_c = "Double_val";
        layer2_class = None;
        c_type = "gdouble";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "double",
      {
        ocaml_type = "float";
        c_to_ml = "caml_copy_double";
        ml_to_c = "Double_val";
        layer2_class = None;
        c_type = "double";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "gboolean",
      {
        ocaml_type = "bool";
        c_to_ml = "Val_bool";
        ml_to_c = "Bool_val";
        layer2_class = None;
        c_type = "gboolean";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "gchararray",
      {
        ocaml_type = "string";
        c_to_ml = "caml_copy_string";
        ml_to_c = "String_val";
        layer2_class = None;
        c_type = "gchararray";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "const gchar*",
      {
        ocaml_type = "string";
        c_to_ml = "caml_copy_string";
        ml_to_c = "String_val";
        layer2_class = None;
        c_type = "const gchar*";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "gchar*",
      {
        ocaml_type = "string";
        c_to_ml = "caml_copy_string";
        ml_to_c = "String_val";
        layer2_class = None;
        c_type = "gchar*";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "utf8",
      {
        ocaml_type = "string";
        c_to_ml = "caml_copy_string";
        ml_to_c = "String_val";
        layer2_class = None;
        c_type = "utf8";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "filename",
      {
        ocaml_type = "string";
        c_to_ml = "caml_copy_string";
        ml_to_c = "String_val";
        layer2_class = None;
        c_type = "const gchar*";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "const char*",
      {
        ocaml_type = "string";
        c_to_ml = "caml_copy_string";
        ml_to_c = "String_val";
        layer2_class = None;
        c_type = "const char*";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "gfloat",
      {
        ocaml_type = "float";
        c_to_ml = "caml_copy_double";
        ml_to_c = "Double_val";
        layer2_class = None;
        c_type = "gfloat";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "float",
      {
        ocaml_type = "float";
        c_to_ml = "caml_copy_double";
        ml_to_c = "Double_val";
        layer2_class = None;
        c_type = "float";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    (* GObject namespace types — not generated from GIR, mapped to
       hand-written wrappers in src/common/gobject.ml *)
    ( "GObject.Object",
      {
        ocaml_type = "[`object_] Gobject.obj";
        c_to_ml = "ml_gobject_val_of_ext";
        ml_to_c = "GObject_ext_of_val";
        layer2_class = None;
        c_type = "GObject*";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    (* GObject.Value — returned as a borrowed const GValue* by functions like
       gtk_drop_target_get_value.  Val_GValue_copy takes an owned copy so the
       OCaml value's lifetime is independent of the C caller's storage.
       is_value_type_record = true so that for out-parameters the generator
      transfer_strategy = Ts_none;
       passes &var (address of the stack GValue) rather than the struct value. *)
    ( "GObject.Value",
      {
        ocaml_type = "Gobject.Value.t";
        c_to_ml = "Val_GValue_copy";
        ml_to_c = "GValue_val";
        layer2_class = None;
        c_type = "const GValue*";
        is_value_type_record = true;
      transfer_strategy = Ts_none;
      } );
    ( "GObject.InitiallyUnowned",
      {
        ocaml_type = "[`initially_unowned | `object_] Gobject.obj";
        c_to_ml = "ml_gobject_val_of_ext";
        ml_to_c = "GObject_ext_of_val";
        layer2_class = None;
        c_type = "GInitiallyUnowned*";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    (* GLib.List - GList* container type, elements resolved at generation time
       c_to_ml/ml_to_c use LIST_INLINE marker for generator to handle specially *)
    ( "GLib.List",
      {
        ocaml_type = "'a list";
        c_to_ml = "LIST_INLINE";
        ml_to_c = "LIST_INLINE";
        layer2_class = None;
        c_type = "GList*";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    (* GLib.SList - GSList* container type, elements resolved at generation time *)
    ( "GLib.SList",
      {
        ocaml_type = "'a list";
        c_to_ml = "LIST_INLINE";
        ml_to_c = "LIST_INLINE";
        layer2_class = None;
        c_type = "GSList*";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    (* GLib.Variant - Opaque boxed type with reference counting *)
    ( "GLib.Variant",
      {
        ocaml_type = "Gvariant.t";
        c_to_ml = "Val_GVariant";
        ml_to_c = "GVariant_val";
        layer2_class = None;
        c_type = "GVariant*";
        is_value_type_record = false;
      transfer_strategy = Ts_gvariant;
      } );
    (* GLib.VariantType - Immutable type description for GVariant *)
    ( "GLib.VariantType",
      {
        ocaml_type = "Gvariant_type.t";
        c_to_ml = "Val_GVariantType";
        ml_to_c = "GVariantType_val";
        layer2_class = None;
        c_type = "GVariantType*";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    (* GLib.Bytes - Immutable reference-counted byte buffer *)
    ( "GLib.Bytes",
      {
        ocaml_type = "Glib_bytes.t";
        c_to_ml = "Val_GBytes";
        ml_to_c = "GBytes_val";
        layer2_class = None;
        c_type = "GBytes*";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    (* GLib.Error — GError* custom block; Val_GError/GError_val defined in wrappers.h *)
    ( "GLib.Error",
      {
        ocaml_type = "GError.t";
        c_to_ml = "Val_GError";
        ml_to_c = "GError_val";
        layer2_class = None;
        c_type = "GError*";
        is_value_type_record = false;
        transfer_strategy = Ts_none;
      } );
    (* GLib/GObject primitive integer types — not generated from GIR, mapped to
       standard OCaml C API converters. All c:type values match the GIR name
       exactly so a single entry per type is sufficient.
       Note: guint8 is intentionally omitted — it is used primarily as the
       element type of byte-buffer arrays (gpointer/void* C type), which
       require length-erasure infrastructure not yet implemented. *)
    ( "gsize",
      {
        ocaml_type = "Gsize.t";
        c_to_ml = "Val_gsize";
        ml_to_c = "Gsize_val";
        layer2_class = None;
        c_type = "gsize";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "gssize",
      {
        ocaml_type = "int";
        c_to_ml = "Val_long";
        ml_to_c = "Long_val";
        layer2_class = None;
        c_type = "gssize";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    (* GType is typedef gsize — macros Val_GType/GType_val already in wrappers.h *)
    ( "GType",
      {
        ocaml_type = "Gobject.Type.t";
        c_to_ml = "Val_GType";
        ml_to_c = "GType_val";
        layer2_class = None;
        c_type = "GType";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "guint16",
      {
        ocaml_type = "UInt16.t";
        c_to_ml = "Val_uint16";
        ml_to_c = "UInt16_val";
        layer2_class = None;
        c_type = "guint16";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "gint16",
      {
        ocaml_type = "Int16.t";
        c_to_ml = "Val_int16";
        ml_to_c = "Int16_val";
        layer2_class = None;
        c_type = "gint16";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "gint32",
      {
        ocaml_type = "Int32.t";
        c_to_ml = "Val_int32_bounded";
        ml_to_c = "Int32_val_bounded";
        layer2_class = None;
        c_type = "gint32";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    (* guint32 mapped to UInt32.t (bounded private int) — OCaml int is 63-bit on
       64-bit platforms so it covers the full uint32 range without boxing *)
    ( "guint32",
      {
        ocaml_type = "UInt32.t";
        c_to_ml = "Val_uint32";
        ml_to_c = "UInt32_val";
        layer2_class = None;
        c_type = "guint32";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "gint64",
      {
        ocaml_type = "int64";
        c_to_ml = "caml_copy_int64";
        ml_to_c = "Int64_val";
        layer2_class = None;
        c_type = "gint64";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    (* guint64 uses the integers library (already a dependency via GVariant).
       wrappers.h includes <ocaml_integers.h> to expose Uint64_val/integers_copy_uint64.
       Exposed as UInt64.t (via src/common/uInt64.ml) for consistency with the other
       bounded integer modules — the underlying type is still Unsigned.UInt64.t. *)
    ( "guint64",
      {
        ocaml_type = "UInt64.t";
        c_to_ml = "integers_copy_uint64";
        ml_to_c = "Uint64_val";
        layer2_class = None;
        c_type = "guint64";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "gulong",
      {
        ocaml_type = "int";
        c_to_ml = "Val_long";
        ml_to_c = "Long_val";
        layer2_class = None;
        c_type = "gulong";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "gunichar",
      {
        ocaml_type = "int";
        c_to_ml = "Val_long";
        ml_to_c = "Long_val";
        layer2_class = None;
        c_type = "gunichar";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "gchar",
      {
        ocaml_type = "int";
        c_to_ml = "Val_int";
        ml_to_c = "Int_val";
        layer2_class = None;
        c_type = "gchar";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    (* PangoGlyph is a primitive alias for guint32 *)
    ( "Glyph",
      {
        ocaml_type = "int";
        c_to_ml = "Val_int";
        ml_to_c = "Int_val";
        layer2_class = None;
        c_type = "Glyph";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
    ( "PangoGlyph",
      {
        ocaml_type = "int";
        c_to_ml = "Val_int";
        ml_to_c = "Int_val";
        layer2_class = None;
        c_type = "PangoGlyph";
        is_value_type_record = false;
      transfer_strategy = Ts_none;
      } );
  ]

let normalize_c_pointer_type lookup_str =
  let trimmed = String.trim lookup_str in
  let without_const =
    if String.starts_with trimmed ~prefix:"const " then
      String.trim (String.sub trimmed ~pos:6 ~len:(String.length trimmed - 6))
    else trimmed
  in
  let without_trailing_const =
    if String.ends_with without_const ~suffix:"const " then
      String.trim
        (String.sub without_const ~pos:0 ~len:(String.length without_const - 6))
    else without_const
  in
  String.trim without_trailing_const

(** find a class mapping DEPRECATED: does some weird things with pointer types
    that should be externalised *)
let lookup_class classes lookup_str =
  let normalized_lookup =
    let base = normalize_c_pointer_type lookup_str in
    if String.ends_with base ~suffix:"*" then
      String.sub base ~pos:0 ~len:(String.length base - 1)
    else base
  in
  List.find_opt
    ~f:(fun (cls : Types.gir_class) ->
      let normalized_name = Utils.normalize_class_name cls.class_name in
      String.equal cls.class_name normalized_lookup
      || String.equal (cls.c_type ^ "*") lookup_str
      || String.equal ("Gtk" ^ normalized_name) normalized_lookup
      || String.equal ("Gtk" ^ normalized_name ^ "*") lookup_str)
    classes

(** lookup interface mapping DEPRECATED: does some weird things with pointer
    types that should be externalised *)
let lookup_interface interfaces lookup_str =
  let normalized_lookup =
    let base = normalize_c_pointer_type lookup_str in
    if String.ends_with ~suffix:"*" base then
      String.sub base ~pos:0 ~len:(String.length base - 1)
    else base
  in
  List.find_opt
    ~f:(fun (iface : Types.gir_interface) ->
      let normalized_name = Utils.normalize_class_name iface.interface_name in
      String.equal iface.interface_name normalized_lookup
      || String.equal iface.c_type normalized_lookup
      || String.equal (iface.c_type ^ "*") lookup_str
      || String.equal ("Gtk" ^ normalized_name) normalized_lookup
      || String.equal ("Gtk" ^ normalized_name ^ "*") lookup_str)
    interfaces

let is_boxed_record (record : Types.gir_record) =
  (match (record.glib_get_type, record.glib_type_name) with
    | Some _, _ | _, Some _ -> true
    | _ -> false)
  && not record.disguised

(** find a record mapping DEPRECATED: does some weird things with pointer types
    that should be externalised *)
let lookup_record records lookup_str =
  let normalized_lookup = normalize_c_pointer_type lookup_str in
  let is_pointer = String.ends_with normalized_lookup ~suffix:"*" in
  List.find_opt records ~f:(fun record ->
      String.equal record.record_name lookup_str)
  |> Option.map (fun record -> (record, is_pointer, is_boxed_record record))

let calculate_class_or_interface_or_record_module_name ~ctx ~name =
  (* Check if this interface is in the current cycle being generated *)
  if List.mem name ~set:ctx.current_cycle_classes then
    (* Within the same cycle, use just the submodule name *)
    Utils.module_name_of_class name
  else
    match Hashtbl.find_opt ctx.module_groups name with
    | Some combined_module_name ->
        let simple_module_name = Utils.module_name_of_class name in
        (* Check if this is a cyclic module by comparing names *)
        if not (String.equal combined_module_name simple_module_name) then
          (* For cyclic modules, we need CombinedModule.InterfaceName.t *)
          combined_module_name ^ "." ^ simple_module_name
        else
          (* Single module *)
          combined_module_name
    | None -> Utils.module_name_of_class name

(* Attempt to find a class mapping in the context in the current namespace *)
let find_class_mapping ~ctx lookup_str =
  let open Option in
  let* cls = lookup_class ctx.classes lookup_str in
  (* Use proper Layer 1 type based on hierarchy *)
  (* Look up the module name from module_groups table *)
  let module_name =
    calculate_class_or_interface_or_record_module_name ~ctx ~name:cls.class_name
  in
  let ocaml_type = module_name ^ ".t" in
  let ocaml_class_name = Utils.ocaml_class_name cls.class_name in
  let ocaml_class_module =
    match Hashtbl.find_opt ctx.module_groups cls.class_name with
    | Some combined_module_name -> combined_module_name
    | None -> Utils.module_name_of_class cls.class_name
  in
  Some
    {
      ocaml_type;
      layer2_class =
        Some
          (calculate_layer2_class ~class_module:ocaml_class_module
             ~class_name:ocaml_class_name);
      c_to_ml = sprintf "Val_%s" cls.c_type;
      ml_to_c = sprintf "%s_val" cls.c_type;
      c_type = cls.c_type;
      is_value_type_record = false;
      transfer_strategy = Ts_gobject;
    }

(** Attempt to find an interface mapping in the context in the current namespace
*)
let find_interface_mapping ~ctx lookup_str =
  let open Option in
  let* iface = lookup_interface ctx.interfaces lookup_str in
  let module_name =
    calculate_class_or_interface_or_record_module_name ~ctx
      ~name:iface.interface_name
  in
  let ocaml_type =
    (* Look up the module name from module_groups table *)
    module_name ^ ".t"
  in
  let ocaml_class_module =
    match Hashtbl.find_opt ctx.module_groups iface.interface_name with
    | Some combined_module_name -> combined_module_name
    | None -> Utils.module_name_of_class iface.interface_name
  in

  let ocaml_class_name = Utils.ocaml_class_name iface.interface_name in
  Some
    {
      ocaml_type;
      layer2_class =
        Some
          (calculate_layer2_class ~class_module:ocaml_class_module
             ~class_name:ocaml_class_name);
      c_to_ml = sprintf "Val_%s" iface.c_type;
      ml_to_c = sprintf "%s_val" iface.c_type;
      c_type = iface.c_type;
      is_value_type_record = false;
      transfer_strategy = Ts_gobject;
    }

(** Attempt to find a record mapping in the context in the current namespace *)
let find_record_mapping ~ctx lookup_str =
  (* Next, check for known records (boxed/disguised) *)
  let open Option in
  let* record, _, _ = lookup_record ctx.records lookup_str in
  (* Use proper record module type (e.g., Tree_iter.t) instead of Obj.t *)
  let ocaml_type =
    (* Look up the module name from module_groups table *)
    let module_name =
      calculate_class_or_interface_or_record_module_name ~ctx
        ~name:record.record_name
    in
    module_name ^ ".t"
  in
  Some
    {
      ocaml_type;
      c_to_ml = sprintf "Val_%s" record.c_type;
      ml_to_c = sprintf "%s_val" record.c_type;
      layer2_class = None;
      c_type = record.c_type;
      is_value_type_record = not record.opaque;
      transfer_strategy =
        (match record.glib_get_type with
        | Some f -> Ts_boxed f
        | None -> Ts_none);
    }

let find_enum_mapping ~ctx lookup_str =
  (* First, check if this is a known enum in current namespace *)
  let open Option in
  let* enum =
    List.find_opt
      ~f:(fun (e : Types.gir_enum) -> String.equal e.enum_name lookup_str)
      ctx.enums
  in
  (* Use the context's namespace for enums from the current library *)
  let namespace = Utils.enums_module_name ctx enum in
  let c_namespace = ctx.namespace.namespace_name in
  Some
    {
      ocaml_type = namespace ^ "." ^ String.lowercase_ascii enum.enum_name;
      c_type = enum.enum_c_type;
      c_to_ml = sprintf "Val_%s%s" c_namespace enum.enum_name;
      ml_to_c = sprintf "%s%s_val" c_namespace enum.enum_name;
      layer2_class = None;
      is_value_type_record = false;
      transfer_strategy = Ts_none;
    }

let find_bitfield_mapping ~ctx lookup_str =
  (* Check if this is a known bitfield in current namespace *)
  let open Option in
  let* bitfield =
    List.find_opt
      ~f:(fun (b : Types.gir_bitfield) ->
        String.equal b.bitfield_c_type lookup_str
        || String.equal b.bitfield_name lookup_str)
      ctx.bitfields
  in
  (* Use the context's namespace for bitfields from the current library *)
  let namespace = Utils.bitfields_module_name ctx bitfield in
  let c_namespace = ctx.namespace.namespace_name in
  Some
    {
      ocaml_type =
        namespace ^ "." ^ String.lowercase_ascii bitfield.bitfield_name;
      c_to_ml = sprintf "Val_%s%s" c_namespace bitfield.bitfield_name;
      ml_to_c = sprintf "%s%s_val" c_namespace bitfield.bitfield_name;
      layer2_class = None;
      c_type = bitfield.bitfield_c_type;
      is_value_type_record = false;
      transfer_strategy = Ts_none;
    }

type type_kind =
  | Tk_Enum
  | Tk_Bitfield
  | Tk_Class
  | Tk_Interface
  | Tk_Record
  | Tk_Primitive
  | Tk_Unknown

let classify_type ~ctx (gir_type : Types.gir_type) =
  let lookup_str = gir_type.name in
  let namespace, name = Utils.name_to_parts ~ctx lookup_str in
  if String.equal namespace ctx.namespace.namespace_name then
    (* Same namespace: check local lists *)
    if
      List.exists ctx.enums ~f:(fun (e : Types.gir_enum) ->
          String.equal e.enum_name lookup_str)
    then Tk_Enum
    else if
      List.exists ctx.bitfields ~f:(fun (b : Types.gir_bitfield) ->
          String.equal b.bitfield_name lookup_str)
    then Tk_Bitfield
    else if Option.is_some (lookup_class ctx.classes lookup_str) then Tk_Class
    else if Option.is_some (lookup_interface ctx.interfaces lookup_str) then
      Tk_Interface
    else if Option.is_some (lookup_record ctx.records lookup_str) then Tk_Record
    else if List.assoc_opt lookup_str type_mappings |> Option.is_some then
      Tk_Primitive
    else Tk_Unknown
  else
    (* Cross-namespace: check cross_references first, then hardcoded mappings *)
    match StringMap.find_opt namespace ctx.cross_references with
    | Some ncr -> (
        match StringMap.find_opt name ncr.ncr_entities with
        | Some cr -> (
            match cr.cr_type with
            | Crt_Enum -> Tk_Enum
            | Crt_Bitfield -> Tk_Bitfield
            | Crt_Class _ -> Tk_Class
            | Crt_Interface -> Tk_Interface
            | Crt_Record _ -> Tk_Record
            | Crt_Constant -> Tk_Primitive)
        | None ->
            if List.assoc_opt lookup_str type_mappings |> Option.is_some then
              Tk_Primitive
            else Tk_Unknown)
    | None ->
        if List.assoc_opt lookup_str type_mappings |> Option.is_some then
          Tk_Primitive
        else Tk_Unknown

(* Option.bind operator for cleaner sequential logic *)
let ( let* ) = Option.bind

let rec find_type_mapping_for_gir_type ~ctx (gir_type : Types.gir_type) =
  if Gir_type_pred.is_list gir_type then handle_list_type ~ctx gir_type
  else if Option.is_some gir_type.array then handle_array_type ~ctx gir_type
  else normal_type_lookup ~ctx gir_type

(** Determine C type for GList/GSList based on type name *)
and list_c_type_of_gir_type gir_type c_type_opt =
  Option.value c_type_opt
    ~default:(if Gir_type_pred.is_glist gir_type then "GList*" else "GSList*")

(** Build a type mapping for a container type (array or list) with resolved
    element type *)
and build_container_mapping ~(element_mapping : type_mapping) ~container_suffix
    ~c_type ~marker =
  {
    ocaml_type = element_mapping.ocaml_type ^ container_suffix;
    c_type;
    c_to_ml = marker;
    ml_to_c = marker;
    layer2_class = None;
    is_value_type_record = false;
    transfer_strategy = Ts_none;
  }

(** Handle GList/GSList container types. Returns None if the element type cannot
    be resolved (instead of generating a generic type). This ensures we only
    generate typed lists when we can properly resolve the element type. *)
and handle_list_type ~ctx (gir_type : Types.gir_type) =
  match gir_type.array with
  | Some array_info ->
      (* Try to resolve the element type *)
      let* elem_mapping =
        find_type_mapping_for_gir_type ~ctx array_info.element_type
      in
      let c_type =
        Option.value gir_type.c_type
          ~default:(list_c_type_of_gir_type gir_type None)
      in
      Some
        (build_container_mapping ~element_mapping:elem_mapping
           ~container_suffix:" list" ~c_type ~marker:"LIST_INLINE")
  | None ->
      (* GList/GSList without element type info - this shouldn't happen in practice *)
      None

(** Handle array types *)
and handle_array_type ~ctx (gir_type : Types.gir_type) =
  let* array_info = gir_type.array in
  let* elem_mapping =
    find_type_mapping_for_gir_type ~ctx array_info.element_type
  in
  let c_type =
    Option.value gir_type.c_type ~default:(elem_mapping.c_type ^ "*")
  in
  Some
    (build_container_mapping ~element_mapping:elem_mapping
       ~container_suffix:" array" ~c_type ~marker:"ARRAY_INLINE")

and normal_type_lookup ~ctx (gir_type : Types.gir_type) =
  let try_lookup lookup_str =
    let find_hardcoded_mapping () =
      (* Fall back to hardcoded type mappings *)
      List.assoc_opt lookup_str type_mappings
    in
    let find_cross_namespace_type_mapping ~ctx ~namespace ~name =
      let open Option in
      let* ncr_namespace = StringMap.find_opt namespace ctx.cross_references in
      let* cross_reference =
        StringMap.find_opt name ncr_namespace.ncr_entities
      in
      Some (map_cross_reference_to_type_mapping ~ctx ~namespace cross_reference)
    in
    let namespace, name = Utils.name_to_parts ~ctx lookup_str in
    if String.equal namespace ctx.namespace.namespace_name then
      find_class_mapping ~ctx lookup_str
      |> or_else (fun () -> find_interface_mapping ~ctx lookup_str)
      |> or_else (fun () -> find_record_mapping ~ctx lookup_str)
      |> or_else (fun () -> find_enum_mapping ~ctx lookup_str)
      |> or_else (fun () -> find_bitfield_mapping ~ctx lookup_str)
      |> or_else find_hardcoded_mapping
    else
      find_cross_namespace_type_mapping ~ctx ~namespace ~name
      |> or_else find_hardcoded_mapping
  in
  (* Try gir_name first, then c_type if that fails *)
  gir_type.name |> try_lookup
  |> or_else (fun () ->
      Option.bind gir_type.c_type (fun c_type -> try_lookup c_type))

(** Simplify type references when they refer to the current module's type.
    Converts patterns like "CurrentModule.t" or "CurrentModule.t option" to "t"
    or "t option". Handles common type wrappers like "option", "array", and
    combinations. *)
let simplify_self_reference ~class_name ~ocaml_type =
  let current_module = Utils.module_name_of_class class_name in
  let self_type = current_module ^ ".t" in
  if String.equal ocaml_type self_type then "t"
  else
    (* Handle patterns like "Module.t array", "Module.t option", "Module.t array option", etc.
       Use a negative lookbehind for '.' to avoid replacing "Surface.t" inside
       qualified paths like "Ocgtk_cairo.Wrappers.Surface.t" *)
    let pat =
      Re.(
        compile (seq [ group (alt [ bos; char ' '; char '(' ]); str self_type ]))
    in
    Re.replace pat ~all:true ~f:(fun g -> Re.Group.get g 1 ^ "t") ocaml_type
