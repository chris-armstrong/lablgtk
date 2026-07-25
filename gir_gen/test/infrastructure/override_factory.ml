(* Shared factories for [Gir_gen_lib.Override_types] records.

   These mirror the style of [Type_factory]: every field has an optional
   argument defaulting to the empty/None value, so call sites only spell out
   the fields that matter for the test. See [ignore_component] and
   [version_component] for the two most common [component_override] shapes. *)

open Gir_gen_lib.Override_types

let make_version_spec ?(namespace = None) ~version () =
  { vs_version = version; vs_namespace = namespace }

let make_component ?(action = None) ?(os = None) ~name () =
  { component_name = name; action; os }

(** [ignore_component ~name] is the single most common [component_override] in
    the test suite — a component marked [Some Ignore]. *)
let ignore_component ~name = make_component ~action:(Some Ignore) ~name ()

(** [version_component ~name ~v] marks [name] for a [Set_version] action with no
    namespace override. *)
let version_component ?(namespace = None) ~name ~version () =
  make_component
    ~action:(Some (Set_version (make_version_spec ~version ?namespace ())))
    ~name ()

let make_class_override ?(action = None) ?(os = None) ?(constructors = [])
    ?(methods = []) ?(properties = []) ?(signals = []) ~name () =
  {
    class_name = name;
    class_action = action;
    class_os = os;
    constructors;
    methods;
    properties;
    signals;
  }

let make_interface_override ?(action = None) ?(os = None) ?(methods = [])
    ?(properties = []) ?(signals = []) ~name () =
  {
    interface_name = name;
    interface_action = action;
    interface_os = os;
    methods;
    properties;
    signals;
  }

let make_record_override ?(action = None) ?(os = None) ?(fields = [])
    ?(constructors = []) ?(methods = []) ?(functions = []) ~name () =
  {
    record_name = name;
    record_action = action;
    record_os = os;
    fields;
    constructors;
    methods;
    functions;
  }

let make_enum_override ?(action = None) ?(os = None) ?(members = [])
    ?(functions = []) ~name () =
  { enum_name = name; enum_action = action; enum_os = os; members; functions }

let make_bitfield_override ?(action = None) ?(os = None) ?(flags = []) ~name ()
    =
  { bitfield_name = name; bitfield_action = action; bitfield_os = os; flags }

let make_library_overrides ?(classes = []) ?(interfaces = []) ?(records = [])
    ?(enums = []) ?(bitfields = []) ?(functions = []) ?(headers = []) ~name () =
  {
    library_name = name;
    classes;
    interfaces;
    records;
    enums;
    bitfields;
    functions;
    headers;
  }

(** [make_empty_library_overrides ~name] builds a [library_overrides] with every
    component list empty. *)
let make_empty_library_overrides ~name = make_library_overrides ~name ()
