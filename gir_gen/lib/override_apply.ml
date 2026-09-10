(* Apply parsed overrides to GIR data structures. *)

open Types
open Override_types

type apply_result = {
  classes : Types.gir_class list;
  interfaces : Types.gir_interface list;
  enums : Types.gir_enum list;
  bitfields : Types.gir_bitfield list;
  records : Types.gir_record list;
  functions : Types.gir_function list;
  ignored_entities : string list;
  warnings : string list;
}

(* Helper to find a component override by name. *)
let find_component_override ~overrides ~name =
  List.find_opt
    (fun (c : component_override) -> String.equal c.component_name name)
    overrides

(* Warn if component overrides reference names not in the component list. *)
let warn_unknown_components ~entity_name ~entity_kind ~component_kind
    ~(get_name : 'a -> string) ~(components : 'a list)
    ~(overrides : component_override list) ~(warnings : string list ref) =
  List.iter
    (fun (c : component_override) ->
      if
        not
          (List.exists
             (fun x -> String.equal (get_name x) c.component_name)
             components)
      then
        warnings :=
          Fmt.str "unknown %s '%s' in %s '%s'" component_kind c.component_name
            entity_kind entity_name
          :: !warnings)
    overrides

(* Generic: warn about entity-level override names not found in parsed data.
   Always checks original data (not filtered) — catches typos on ignored entities. *)
let check_unknown_entity_names ~entity_kind ~get_override_name ~get_entity_name
    overrides entities =
  List.filter_map
    (fun ov ->
      if
        List.exists
          (fun e -> String.equal (get_entity_name e) (get_override_name ov))
          entities
      then None
      else
        Fmt.kstr
          (fun s -> Some s)
          "unknown %s '%s' in override" entity_kind (get_override_name ov))
    overrides

(* Apply component-level overrides to a single component list.
   Returns the filtered-and-versioned list. *)
let apply_components_by_name ~(get_name : 'a -> string)
    ~(set_version : version_spec -> 'a -> 'a)
    ~(set_os : Os_filter.t -> 'a -> 'a) ~(overrides : component_override list)
    (components : 'a list) : 'a list =
  List.filter_map
    (fun item ->
      match find_component_override ~name:(get_name item) ~overrides with
      | Some { action = Some Ignore; _ } -> None
      | Some { action = Some (Set_version vs); os = comp_os; _ } ->
          let item' = set_version vs item in
          Some (match comp_os with Some o -> set_os o item' | None -> item')
      | Some { action = None; os = comp_os; _ } ->
          Some (match comp_os with Some o -> set_os o item | None -> item)
      | None -> Some item)
    components

(* Per-type set_version helpers — eliminate repeated inline lambdas. *)

let method_set_version vs (m : gir_method) =
  { m with version = Some vs.vs_version; version_namespace = vs.vs_namespace }

let constructor_set_version vs (c : gir_constructor) =
  { c with version = Some vs.vs_version; version_namespace = vs.vs_namespace }

let property_set_version vs (p : gir_property) =
  { p with version = Some vs.vs_version; version_namespace = vs.vs_namespace }

let signal_set_version vs (s : gir_signal) =
  { s with version = Some vs.vs_version; version_namespace = vs.vs_namespace }

let field_set_version vs (f : gir_record_field) =
  { f with field_version = Some vs.vs_version }

let function_set_version vs (f : gir_function) =
  { f with version = Some vs.vs_version; version_namespace = vs.vs_namespace }

let enum_member_set_version vs (m : gir_enum_member) =
  { m with member_version = Some vs.vs_version }

let bitfield_member_set_version vs (f : gir_bitfield_member) =
  { f with flag_version = Some vs.vs_version }

(* Per-type set_os helpers — eliminate repeated inline lambdas.
   All take [Os_filter.t] (not [string]). *)

let method_set_os o (m : gir_method) = { m with os = Some o }
let constructor_set_os o (c : gir_constructor) = { c with os = Some o }
let property_set_os o (p : gir_property) = { p with os = Some o }
let signal_set_os o (s : gir_signal) = { s with os = Some o }
let field_set_os o (f : gir_record_field) = { f with field_os = Some o }
let function_set_os o (f : gir_function) = { f with os = Some o }
let enum_member_set_os o (m : gir_enum_member) = { m with member_os = Some o }

let bitfield_member_set_os o (f : gir_bitfield_member) =
  { f with flag_os = Some o }

(* Per-entity helpers: apply component overrides to a surviving entity. *)

let apply_class_components (ov : class_override) (cls : gir_class) : gir_class =
  let constructors =
    apply_components_by_name
      ~get_name:(fun (c : gir_constructor) -> c.ctor_name)
      ~set_version:constructor_set_version ~set_os:constructor_set_os
      ~overrides:ov.constructors cls.constructors
  in
  let methods =
    apply_components_by_name
      ~get_name:(fun (m : gir_method) -> m.method_name)
      ~set_version:method_set_version ~set_os:method_set_os
      ~overrides:ov.methods cls.methods
  in
  let properties =
    apply_components_by_name
      ~get_name:(fun (p : gir_property) -> p.prop_name)
      ~set_version:property_set_version ~set_os:property_set_os
      ~overrides:ov.properties cls.properties
  in
  let signals =
    apply_components_by_name
      ~get_name:(fun (s : gir_signal) -> s.signal_name)
      ~set_version:signal_set_version ~set_os:signal_set_os
      ~overrides:ov.signals cls.signals
  in
  { cls with constructors; methods; properties; signals }

let apply_interface_components (ov : interface_override) (intf : gir_interface)
    : gir_interface =
  let methods =
    apply_components_by_name
      ~get_name:(fun (m : gir_method) -> m.method_name)
      ~set_version:method_set_version ~set_os:method_set_os
      ~overrides:ov.methods intf.methods
  in
  let properties =
    apply_components_by_name
      ~get_name:(fun (p : gir_property) -> p.prop_name)
      ~set_version:property_set_version ~set_os:property_set_os
      ~overrides:ov.properties intf.properties
  in
  let signals =
    apply_components_by_name
      ~get_name:(fun (s : gir_signal) -> s.signal_name)
      ~set_version:signal_set_version ~set_os:signal_set_os
      ~overrides:ov.signals intf.signals
  in
  { intf with methods; properties; signals }

let apply_record_components (ov : record_override) (rec_ : gir_record) :
    gir_record =
  let fields =
    apply_components_by_name
      ~get_name:(fun (f : gir_record_field) -> f.field_name)
      ~set_version:field_set_version ~set_os:field_set_os ~overrides:ov.fields
      rec_.fields
  in
  let constructors =
    apply_components_by_name
      ~get_name:(fun (c : gir_constructor) -> c.ctor_name)
      ~set_version:constructor_set_version ~set_os:constructor_set_os
      ~overrides:ov.constructors rec_.constructors
  in
  let methods =
    apply_components_by_name
      ~get_name:(fun (m : gir_method) -> m.method_name)
      ~set_version:method_set_version ~set_os:method_set_os
      ~overrides:ov.methods rec_.methods
  in
  let functions =
    apply_components_by_name
      ~get_name:(fun (f : gir_function) -> f.function_name)
      ~set_version:function_set_version ~set_os:function_set_os
      ~overrides:ov.functions rec_.functions
  in
  { rec_ with fields; constructors; methods; functions }

let apply_enum_components (ov : enum_override) (enm : gir_enum) : gir_enum =
  let members =
    apply_components_by_name
      ~get_name:(fun (m : gir_enum_member) -> m.member_name)
      ~set_version:enum_member_set_version ~set_os:enum_member_set_os
      ~overrides:ov.members enm.members
  in
  let functions =
    apply_components_by_name
      ~get_name:(fun (f : gir_function) -> f.function_name)
      ~set_version:function_set_version ~set_os:function_set_os
      ~overrides:ov.functions enm.functions
  in
  { enm with members; functions }

let apply_bitfield_components (ov : bitfield_override) (bf : gir_bitfield) :
    gir_bitfield =
  let flags =
    apply_components_by_name
      ~get_name:(fun (f : gir_bitfield_member) -> f.flag_name)
      ~set_version:bitfield_member_set_version ~set_os:bitfield_member_set_os
      ~overrides:ov.flags bf.flags
  in
  { bf with flags }

(* Generic: entity-level ignore/version/os and component overrides.
   ~get_entity_name / ~get_override_name: name accessors for entity and override types
   ~get_action: extracts the entity-level action from an override record
   ~get_os: extracts the entity-level os from an override record
   ~set_version: applies a version string to the entity record
   ~set_os: applies an os string to the entity record
   ~apply_components: applies all component-level overrides to a surviving entity
   ~check_components: emits component-level unknown-name warnings for one entity *)
let apply_entity_overrides ~get_entity_name ~get_override_name ~get_action
    ~get_os ~set_version ~set_os ~apply_components ~check_components
    all_entities overrides =
  let ignored = ref [] in
  let warnings = ref [] in
  let process entity =
    match
      List.find_opt
        (fun ov -> String.equal (get_override_name ov) (get_entity_name entity))
        overrides
    with
    | None -> Some entity
    | Some ov -> (
        let maybe_apply_os entity' =
          match get_os ov with
          | Some os_val -> set_os os_val entity'
          | None -> entity'
        in
        match get_action ov with
        | Some Ignore ->
            ignored := get_entity_name entity :: !ignored;
            None
        | Some (Set_version vs) ->
            Some
              (maybe_apply_os
                 (apply_components ov (set_version vs.vs_version entity)))
        | None -> Some (maybe_apply_os (apply_components ov entity)))
  in
  let processed = List.filter_map process all_entities in
  (* Warn using the ORIGINAL entity list so that successfully-ignored components
     do not produce false "unknown" warnings. *)
  List.iter
    (fun ov ->
      match get_action ov with
      | Some Ignore -> ()
      | Some _ | None ->
          Option.iter
            (fun entity ->
              check_components ~entity_name:(get_override_name ov) entity ov
                ~warnings)
            (List.find_opt
               (fun e ->
                 String.equal (get_entity_name e) (get_override_name ov))
               all_entities))
    overrides;
  (processed, !ignored, !warnings)

let apply_class_overrides ~class_overrides all_classes =
  apply_entity_overrides
    ~get_entity_name:(fun (c : gir_class) -> c.class_name)
    ~get_override_name:(fun (o : class_override) -> o.class_name)
    ~get_action:(fun (o : class_override) -> o.class_action)
    ~get_os:(fun (o : class_override) -> o.class_os)
    ~set_version:(fun v (c : gir_class) -> { c with version = Some v })
    ~set_os:(fun (o : Os_filter.t) (c : gir_class) -> { c with os = Some o })
    ~apply_components:apply_class_components
    ~check_components:(fun ~entity_name cls ov ~warnings ->
      warn_unknown_components ~entity_name ~entity_kind:"class"
        ~component_kind:"constructor"
        ~get_name:(fun (c : gir_constructor) -> c.ctor_name)
        ~components:cls.constructors ~overrides:ov.constructors ~warnings;
      warn_unknown_components ~entity_name ~entity_kind:"class"
        ~component_kind:"method"
        ~get_name:(fun (m : gir_method) -> m.method_name)
        ~components:cls.methods ~overrides:ov.methods ~warnings;
      warn_unknown_components ~entity_name ~entity_kind:"class"
        ~component_kind:"property"
        ~get_name:(fun (p : gir_property) -> p.prop_name)
        ~components:cls.properties ~overrides:ov.properties ~warnings;
      warn_unknown_components ~entity_name ~entity_kind:"class"
        ~component_kind:"signal"
        ~get_name:(fun (s : gir_signal) -> s.signal_name)
        ~components:cls.signals ~overrides:ov.signals ~warnings)
    all_classes class_overrides

let apply_interface_overrides ~interface_overrides all_interfaces =
  apply_entity_overrides
    ~get_entity_name:(fun (i : gir_interface) -> i.interface_name)
    ~get_override_name:(fun (o : interface_override) -> o.interface_name)
    ~get_action:(fun (o : interface_override) -> o.interface_action)
    ~get_os:(fun (o : interface_override) -> o.interface_os)
    ~set_version:(fun v (i : gir_interface) -> { i with version = Some v })
    ~set_os:(fun o (i : gir_interface) -> { i with os = Some o })
    ~apply_components:apply_interface_components
    ~check_components:(fun ~entity_name intf ov ~warnings ->
      warn_unknown_components ~entity_name ~entity_kind:"interface"
        ~component_kind:"method"
        ~get_name:(fun (m : gir_method) -> m.method_name)
        ~components:intf.methods ~overrides:ov.methods ~warnings;
      warn_unknown_components ~entity_name ~entity_kind:"interface"
        ~component_kind:"property"
        ~get_name:(fun (p : gir_property) -> p.prop_name)
        ~components:intf.properties ~overrides:ov.properties ~warnings;
      warn_unknown_components ~entity_name ~entity_kind:"interface"
        ~component_kind:"signal"
        ~get_name:(fun (s : gir_signal) -> s.signal_name)
        ~components:intf.signals ~overrides:ov.signals ~warnings)
    all_interfaces interface_overrides

let apply_record_overrides ~record_overrides all_records =
  apply_entity_overrides
    ~get_entity_name:(fun (r : gir_record) -> r.record_name)
    ~get_override_name:(fun (o : record_override) -> o.record_name)
    ~get_action:(fun (o : record_override) -> o.record_action)
    ~get_os:(fun (o : record_override) -> o.record_os)
    ~set_version:(fun v (r : gir_record) -> { r with version = Some v })
    ~set_os:(fun o (r : gir_record) -> { r with os = Some o })
    ~apply_components:apply_record_components
    ~check_components:(fun ~entity_name rec_ ov ~warnings ->
      warn_unknown_components ~entity_name ~entity_kind:"record"
        ~component_kind:"field"
        ~get_name:(fun (f : gir_record_field) -> f.field_name)
        ~components:rec_.fields ~overrides:ov.fields ~warnings;
      warn_unknown_components ~entity_name ~entity_kind:"record"
        ~component_kind:"constructor"
        ~get_name:(fun (c : gir_constructor) -> c.ctor_name)
        ~components:rec_.constructors ~overrides:ov.constructors ~warnings;
      warn_unknown_components ~entity_name ~entity_kind:"record"
        ~component_kind:"method"
        ~get_name:(fun (m : gir_method) -> m.method_name)
        ~components:rec_.methods ~overrides:ov.methods ~warnings;
      warn_unknown_components ~entity_name ~entity_kind:"record"
        ~component_kind:"function"
        ~get_name:(fun (f : gir_function) -> f.function_name)
        ~components:rec_.functions ~overrides:ov.functions ~warnings)
    all_records record_overrides

let apply_enum_overrides ~enum_overrides all_enums =
  apply_entity_overrides
    ~get_entity_name:(fun (e : gir_enum) -> e.enum_name)
    ~get_override_name:(fun (o : enum_override) -> o.enum_name)
    ~get_action:(fun (o : enum_override) -> o.enum_action)
    ~get_os:(fun (o : enum_override) -> o.enum_os)
    ~set_version:(fun v (e : gir_enum) -> { e with enum_version = Some v })
    ~set_os:(fun o (e : gir_enum) -> { e with enum_os = Some o })
    ~apply_components:apply_enum_components
    ~check_components:(fun ~entity_name enm ov ~warnings ->
      warn_unknown_components ~entity_name ~entity_kind:"enumeration"
        ~component_kind:"member"
        ~get_name:(fun (m : gir_enum_member) -> m.member_name)
        ~components:enm.members ~overrides:ov.members ~warnings;
      warn_unknown_components ~entity_name ~entity_kind:"enumeration"
        ~component_kind:"function"
        ~get_name:(fun (f : gir_function) -> f.function_name)
        ~components:enm.functions ~overrides:ov.functions ~warnings)
    all_enums enum_overrides

let apply_bitfield_overrides ~bitfield_overrides all_bitfields =
  apply_entity_overrides
    ~get_entity_name:(fun (b : gir_bitfield) -> b.bitfield_name)
    ~get_override_name:(fun (o : bitfield_override) -> o.bitfield_name)
    ~get_action:(fun (o : bitfield_override) -> o.bitfield_action)
    ~get_os:(fun (o : bitfield_override) -> o.bitfield_os)
    ~set_version:(fun v (b : gir_bitfield) ->
      { b with bitfield_version = Some v })
    ~set_os:(fun o (b : gir_bitfield) -> { b with bitfield_os = Some o })
    ~apply_components:apply_bitfield_components
    ~check_components:(fun ~entity_name bf ov ~warnings ->
      warn_unknown_components ~entity_name ~entity_kind:"bitfield"
        ~component_kind:"member"
        ~get_name:(fun (f : gir_bitfield_member) -> f.flag_name)
        ~components:bf.flags ~overrides:ov.flags ~warnings)
    all_bitfields bitfield_overrides

(* Process standalone functions: ignore or version override. *)
let apply_function_overrides ~(function_overrides : component_override list)
    (functions : gir_function list) =
  let ignored = ref [] in
  let warnings = ref [] in
  let processed =
    List.filter_map
      (fun (fn : gir_function) ->
        match
          find_component_override ~name:fn.function_name
            ~overrides:function_overrides
        with
        | Some { action = Some Ignore; _ } ->
            ignored := fn.function_name :: !ignored;
            None
        | Some { action = Some (Set_version vs); os = comp_os; _ } ->
            let fn' =
              {
                fn with
                version = Some vs.vs_version;
                version_namespace = vs.vs_namespace;
              }
            in
            Some
              (match comp_os with
              | Some o -> { fn' with os = Some o }
              | None -> fn')
        | Some { action = None; os = comp_os; _ } ->
            Some
              (match comp_os with
              | Some o -> { fn with os = Some o }
              | None -> fn)
        | None -> Some fn)
      functions
  in
  List.iter
    (fun (c : component_override) ->
      if
        not
          (List.exists
             (fun (fn : gir_function) ->
               String.equal fn.function_name c.component_name)
             functions)
      then
        warnings :=
          Fmt.str "unknown standalone function '%s'" c.component_name
          :: !warnings)
    function_overrides;
  (processed, !ignored, !warnings)

let apply_overrides ~(overrides : library_overrides) ~classes:original_classes
    ~interfaces:original_interfaces ~enums:original_enums
    ~bitfields:original_bitfields ~records:original_records
    ~functions:original_functions =
  let classes, class_ignored, class_warnings =
    apply_class_overrides ~class_overrides:overrides.classes original_classes
  in
  let interfaces, interface_ignored, interface_warnings =
    apply_interface_overrides ~interface_overrides:overrides.interfaces
      original_interfaces
  in
  let records, record_ignored, record_warnings =
    apply_record_overrides ~record_overrides:overrides.records original_records
  in
  let enums, enum_ignored, enum_warnings =
    apply_enum_overrides ~enum_overrides:overrides.enums original_enums
  in
  let bitfields, bitfield_ignored, bitfield_warnings =
    apply_bitfield_overrides ~bitfield_overrides:overrides.bitfields
      original_bitfields
  in
  let functions, function_ignored, function_warnings =
    apply_function_overrides ~function_overrides:overrides.functions
      original_functions
  in
  (* Check for unknown entity names using original (unfiltered) data so that
     ignored entities don't produce false positives. *)
  let entity_warnings =
    check_unknown_entity_names ~entity_kind:"class"
      ~get_override_name:(fun (ov : class_override) -> ov.class_name)
      ~get_entity_name:(fun (cls : gir_class) -> cls.class_name)
      overrides.classes original_classes
    @ check_unknown_entity_names ~entity_kind:"interface"
        ~get_override_name:(fun (ov : interface_override) -> ov.interface_name)
        ~get_entity_name:(fun (intf : gir_interface) -> intf.interface_name)
        overrides.interfaces original_interfaces
    @ check_unknown_entity_names ~entity_kind:"record"
        ~get_override_name:(fun (ov : record_override) -> ov.record_name)
        ~get_entity_name:(fun (rec_ : gir_record) -> rec_.record_name)
        overrides.records original_records
    @ check_unknown_entity_names ~entity_kind:"enumeration"
        ~get_override_name:(fun (ov : enum_override) -> ov.enum_name)
        ~get_entity_name:(fun (enm : gir_enum) -> enm.enum_name)
        overrides.enums original_enums
    @ check_unknown_entity_names ~entity_kind:"bitfield"
        ~get_override_name:(fun (ov : bitfield_override) -> ov.bitfield_name)
        ~get_entity_name:(fun (bf : gir_bitfield) -> bf.bitfield_name)
        overrides.bitfields original_bitfields
  in
  let ignored_entities =
    class_ignored @ interface_ignored @ record_ignored @ enum_ignored
    @ bitfield_ignored @ function_ignored
  in
  let warnings =
    class_warnings @ interface_warnings @ record_warnings @ enum_warnings
    @ bitfield_warnings @ function_warnings @ entity_warnings
  in
  {
    classes;
    interfaces;
    enums;
    bitfields;
    records;
    functions;
    ignored_entities;
    warnings;
  }
