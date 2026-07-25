(* Type Definitions for GIR Code Generator *)

open Sexplib.Std

type transfer_ownership =
  | TransferNone
  | TransferFull
  | TransferContainer
  | TransferFloating

type gir_array = {
  length : int option;
      (* Parameter index containing array length, if applicable *)
  zero_terminated : bool; (* Whether the array is null/zero-terminated *)
  fixed_size : int option; (* Fixed size of array, if known at compile time *)
  element_type : gir_type; (* Type of array elements *)
  array_name : string option;
      (* Array type name (e.g., "GLib.PtrArray" for GPtrArray) *)
}

and gir_type = {
  name : string;
  c_type : string option;
  nullable : bool;
  transfer_ownership : transfer_ownership;
  array : gir_array option; (* Present if this type represents an array *)
}

type gir_direction = In | Out | InOut

type gir_param = {
  param_name : string;
  param_type : gir_type;
  direction : gir_direction;
  nullable : bool;
  varargs : bool;
  caller_allocates : bool;
      (* True if caller allocates the buffer for out params *)
}

type gir_method = {
  method_name : string;
  c_identifier : string;
  return_type : gir_type;
  parameters : gir_param list;
  doc : string option;
  throws : bool;
  get_property : string option;
  set_property : string option;
  introspectable : bool;
  version : string option;
  version_namespace : string option;
  os : Os_filter.t option;
}

type gir_function = {
  function_name : string;
  c_identifier : string;
  return_type : gir_type;
  parameters : gir_param list;
  doc : string option;
  throws : bool;
  introspectable : bool;
  version : string option;
  version_namespace : string option;
  os : Os_filter.t option;
}

type signal_run_when = RunFirst | RunLast | RunCleanup

type gir_signal = {
  signal_name : string;
  return_type : gir_type;
  sig_parameters : gir_param list;
  doc : string option;
  version : string option;
  version_namespace : string option;
  os : Os_filter.t option;
  run_when : signal_run_when option;
  action : bool;
  no_recurse : bool;
  no_hooks : bool;
}

type gir_constructor = {
  ctor_name : string;
  c_identifier : string;
  ctor_parameters : gir_param list;
  ctor_doc : string option;
  throws : bool;
  ctor_introspectable : bool;
  version : string option;
  version_namespace : string option;
  os : Os_filter.t option;
}

type gir_property = {
  prop_name : string;
  prop_type : gir_type;
  readable : bool;
  writable : bool;
  construct_only : bool;
  prop_doc : string option;
  version : string option;
  version_namespace : string option;
  os : Os_filter.t option;
}

type gir_record_field = {
  field_name : string;
  field_type : gir_type option;
  readable : bool;
  writable : bool;
  field_doc : string option;
  field_version : string option;
  field_os : Os_filter.t option;
}

type gir_record = {
  record_name : string;
  c_type : string;
  glib_type_name : string option;
  glib_get_type : string option;
  opaque : bool;
  disguised : bool;
  introspectable : bool;
  c_symbol_prefix : string option;
  is_gtype_struct_for : string option;
      (* glib:is-gtype-struct-for attribute - class structs to skip *)
  fields : gir_record_field list;
  constructors : gir_constructor list;
  methods : gir_method list;
  functions : gir_function list;
  record_doc : string option;
  version : string option;
  os : Os_filter.t option;
}

type gir_enum_member = {
  member_name : string;
  member_value : int;
  c_identifier : string;
  member_doc : string option;
  member_version : string option;
  member_os : Os_filter.t option;
}

type gir_enum = {
  enum_name : string;
  enum_c_type : string;
  members : gir_enum_member list;
  functions : gir_function list;
  enum_doc : string option;
  enum_version : string option;
  enum_os : Os_filter.t option;
}

type gir_bitfield_member = {
  flag_name : string;
  flag_value : int;
  flag_c_identifier : string;
  flag_doc : string option;
  flag_version : string option;
  flag_os : Os_filter.t option;
}

type gir_constant = {
  constant_name : string;
  constant_c_type : string;
  value : string;
  value_type : gir_type;
  constant_doc : string option;
  version : string option;
  os : Os_filter.t option;
  introspectable : bool;
}

type gir_bitfield = {
  bitfield_name : string;
  bitfield_c_type : string;
  flags : gir_bitfield_member list;
  bitfield_doc : string option;
  bitfield_version : string option;
  bitfield_os : Os_filter.t option;
}

type gir_class = {
  class_name : string;
  c_type : string;
  parent : string option;
  implements : string list;
  introspectable : bool;
  constructors : gir_constructor list;
  methods : gir_method list;
  properties : gir_property list;
  signals : gir_signal list;
  class_doc : string option;
  version : string option;
  os : Os_filter.t option;
}

type gir_interface = {
  interface_name : string;
  c_type : string;
  c_symbol_prefix : string;
  glib_type_name : string option;
  glib_get_type : string option;
  prerequisites : string list;
  introspectable : bool;
  methods : gir_method list;
  properties : gir_property list;
  signals : gir_signal list;
  interface_doc : string option;
  version : string option;
  os : Os_filter.t option;
}

(* Unified entity type for classes, interfaces, and records *)
type entity_kind =
  | Class of gir_class
  | Interface of gir_interface
  | Record of gir_record

type entity = {
  kind : entity_kind;
  name : string;
  c_type : string;
  doc : string option;
  parent : string option; (* None for interfaces *)
  implements : string list; (* Empty for interfaces *)
  constructors : gir_constructor list; (* Empty for interfaces *)
  methods : gir_method list;
  properties : gir_property list;
  signals : gir_signal list;
  version : string option;
  os : Os_filter.t option;
}

let entity_of_class (cls : gir_class) : entity =
  {
    kind = Class cls;
    name = cls.class_name;
    c_type = cls.c_type;
    doc = cls.class_doc;
    parent = cls.parent;
    implements = cls.implements;
    constructors = cls.constructors;
    methods = cls.methods;
    properties = cls.properties;
    signals = cls.signals;
    version = cls.version;
    os = cls.os;
  }

let entity_of_interface (intf : gir_interface) : entity =
  {
    kind = Interface intf;
    name = intf.interface_name;
    c_type = intf.c_type;
    doc = intf.interface_doc;
    parent = None;
    implements = [];
    constructors = [];
    methods = intf.methods;
    properties = intf.properties;
    signals = intf.signals;
    version = intf.version;
    os = intf.os;
  }

let entity_of_record (rec_ : gir_record) : entity =
  {
    kind = Record rec_;
    name = rec_.record_name;
    c_type = rec_.c_type;
    doc = rec_.record_doc;
    parent = None;
    implements = [];
    constructors = rec_.constructors;
    methods = rec_.methods;
    properties = [];
    signals = [];
    version = rec_.version;
    os = rec_.os;
  }

(* A generated OCaml class for a GIR Class or Interface *)
type ocaml_class = {
  class_module : string;
  class_type : string;
  class_ml_name : string;
  class_layer1_accessor : string;
}

type type_mapping = {
  ocaml_type : string;
      (** Layer 1 OCaml type expression. Same-namespace classes/records:
          ["Widget.t"], ["Bitset.t"]. Cross-namespace classes/records:
          ["Ocgtk_gdk.Wrappers.Surface.t"], ["Ocgtk_gdk.Wrappers.Rgb_a.t"].
          Same-namespace enums/bitfields: ["Gtk.align"]. Cross-namespace
          enums/bitfields: ["Ocgtk_pango.alignment"]. Primitives: ["int"],
          ["float"], ["string"], ["bool"]. *)
  c_type : string;
      (** The C type name without pointer suffix. Same-namespace: ["GtkWidget"],
          ["GtkBitset"], ["GtkAlign"]. Cross-namespace: ["GdkSurface"],
          ["GdkRGBA"], ["PangoAlignment"]. *)
  c_to_ml : string;
      (** C macro/function that converts a C value to an OCaml [value].
          Same-namespace: ["Val_GtkWidget"], ["Val_GtkBitset"]. Cross-namespace:
          ["Val_GdkRGBA"], ["Val_PangoAlignment"]. Primitives: ["Val_int"],
          ["caml_copy_double"], ["caml_copy_string"]. For non-opaque records,
          the generated function expects a const pointer argument, not a value.
      *)
  ml_to_c : string;
      (** C macro/function that converts an OCaml [value] to a C value.
          Same-namespace: ["GtkWidget_val"], ["GtkBitset_val"]. Cross-namespace:
          ["GdkRGBA_val"], ["PangoAlignment_val"]. Primitives: ["Int_val"],
          ["Double_val"], ["String_val"]. *)
  layer2_class : ocaml_class option;
      (** Layer 2 class wrapper info. Present for GObject classes, interfaces,
          AND records that have OCaml class wrappers. Used by Layer 2 generators
          for method signatures (e.g. [#widget -> unit]) and coercion accessors
          (e.g. [obj#as_widget]).

          Same-namespace classes: [Some {class_module="GWidget"; ...}].
          Cross-namespace classes: [Some {class_module="Ocgtk_gdk"; ...}].
          Cross-namespace records: [Some {class_module="Ocgtk_gdk"; ...}].
          Same-namespace records: [None] (layer 2 refs resolved differently).
          Enums/bitfields/primitives: [None].

          {b Important}: presence does NOT imply the type is a GObject — cross-
          namespace records also have this set for Layer 2 class references. Use
          [is_value_type_record] to distinguish records from GObjects. *)
  is_value_type_record : bool;
      (** True for non-opaque records: stack-allocated C structs like
          [graphene_rect_t] or [GdkRGBA]. Affects code generation in two ways:
          1. Out-parameters need [&var] when calling [c_to_ml] (the Val function
          expects a pointer, but the out-param is a stack-allocated value). 2.
          Return values must NOT get [g_object_ref_sink] — these are plain
          structs, not GObjects with floating references.

          True for: same-namespace non-opaque records, cross-namespace
          non-opaque records ([Crt_Record {opaque=false}]). False for: classes,
          interfaces, opaque records, enums, bitfields, primitives. *)
  transfer_strategy : transfer_strategy;
      (** How to handle ownership when wrapping a return value. Drives
          [generate_ref_sink_stmt] in the C stub generator. *)
}
(* Ownership strategy for wrapping a C return value into OCaml.

   Used by [generate_ref_sink_stmt] to emit the correct ownership transfer
   call after a C function returns a value with [transfer-ownership="none"]. *)
and transfer_strategy =
  | Ts_none
      (** No special ownership action: primitives, strings, enums, bitfields,
          and container types. The C value is copied or the OCaml runtime
          manages the memory. *)
  | Ts_gobject
      (** GObject class or interface: emit [g_object_ref_sink(result)] for
          transfer-none and floating returns so the OCaml finalizer always
          holds a strong reference. *)
  | Ts_boxed of string
      (** GObject boxed type (record with [glib:get-type]): emit
          [result = g_boxed_copy(<get_type_func>(), result)] for transfer-none
          returns. The string is the C get-type function name, e.g.
          ["gdk_content_formats_get_type"]. *)
  | Ts_gvariant
      (** [GVariant]: emit [g_variant_ref(result)] for transfer-none returns.
          GVariant is ref-counted but uses its own API rather than the
          generic boxed interface. *)
(** Maps a GIR type to its C and OCaml representations for code generation.

    Used by both Layer 0 (C stubs) and Layer 2 (OCaml class wrappers) generators
    to convert between C and OCaml values.

    {2 Same-namespace vs cross-namespace examples}

    When generating Gtk bindings:

    {b Same-namespace class} ([GtkWidget] within Gtk):
    - [ocaml_type = "Widget.t"]
    - [c_type = "GtkWidget"]
    - [c_to_ml = "Val_GtkWidget"], [ml_to_c = "GtkWidget_val"]
    - [layer2_class = Some {class_module="GWidget"; class_type="widget"; ...}]
    - [is_value_type_record = false]

    {b Cross-namespace class} ([GdkSurface] from Gdk, used in Gtk):
    - [ocaml_type = "Ocgtk_gdk.Wrappers.Surface.t"]
    - [c_type = "GdkSurface"]
    - [c_to_ml = "Val_GdkSurface"], [ml_to_c = "GdkSurface_val"]
    - [layer2_class = Some {class_module="Ocgtk_gdk"; class_type="surface";
       ...}]
    - [is_value_type_record = false]

    {b Same-namespace record} ([GtkBitset] within Gtk):
    - [ocaml_type = "Bitset.t"]
    - [c_type = "GtkBitset"]
    - [c_to_ml = "Val_GtkBitset"], [ml_to_c = "GtkBitset_val"]
    - [layer2_class = None]
    - [is_value_type_record = true] (if non-opaque)

    {b Cross-namespace record} ([GdkRGBA] from Gdk, used in Gsk):
    - [ocaml_type = "Ocgtk_gdk.Wrappers.Rgb_a.t"]
    - [c_type = "GdkRGBA"]
    - [c_to_ml = "Val_GdkRGBA"], [ml_to_c = "GdkRGBA_val"]
    - [layer2_class = Some {class_module="Ocgtk_gdk"; class_type="rgba"; ...}]
    - [is_value_type_record = true]

    {b Cross-namespace enum} ([PangoAlignment] from Pango, used in Gtk):
    - [ocaml_type = "Ocgtk_pango.alignment"]
    - [c_type = "PangoAlignment"]
    - [c_to_ml = "Val_PangoAlignment"], [ml_to_c = "PangoAlignment_val"]
    - [layer2_class = None]
    - [is_value_type_record = false] *)

type gir_namespace = {
  namespace_name : string;
  namespace_version : string;
  namespace_shared_library : string;
  namespace_c_identifier_prefixes : string;
  namespace_c_symbol_prefixes : string;
}

type gir_include = { include_name : string; include_version : string }

type gir_repository = {
  repository_includes : gir_include list;
  repository_c_includes : string list;
  repository_packages : string list;
}

type cross_reference_type =
  | Crt_Class of {
      parent : string option;
      implements : string list; [@sexp.list]
    }
  | Crt_Interface
  | Crt_Record of { opaque : bool; get_type_func : string option [@sexp.option] }
  | Crt_Enum
  | Crt_Bitfield
  | Crt_Constant
[@@deriving sexp]

type cross_reference_entity = {
  cr_name : string;
  cr_type : cross_reference_type;
  cr_c_type : string;
}
[@@deriving sexp]

type cross_reference_namespace = {
  cr_namespace_name : string;
  cr_namespace_packages : string list;
  cr_namespace_includes : string list;
  cr_namespace_c_includes : string list;
  cr_entities : cross_reference_entity list;
}
[@@deriving sexp]

module StringMap = Map.Make (String)

type generation_context_namespace_cross_references = {
  ncr_namespace_name : string;
  ncr_namespace_packages : string list;
  ncr_namespace_includes : string list;
  ncr_namespace_c_includes : string list;
  ncr_entities : cross_reference_entity StringMap.t;
}

type generation_context = {
  namespace : gir_namespace;
  repository : gir_repository;
  classes : gir_class list;
  interfaces : gir_interface list;
  enums : gir_enum list;
  bitfields : gir_bitfield list;
  records : gir_record list;
  constants : gir_constant list;
  module_groups : (string, string) Hashtbl.t;
      (* class_name -> combined_module_name *)
  current_cycle_classes : string list;
      (* Class names in the current cyclic module being generated *)
  cross_references : generation_context_namespace_cross_references StringMap.t;
}
