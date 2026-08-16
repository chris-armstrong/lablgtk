(* Type Definitions for GIR Code Generator *)

(** How ownership of a value is transferred between C and OCaml code. *)
type transfer_ownership =
  | TransferNone
  | TransferFull
  | TransferContainer
  | TransferFloating

type gir_array = {
  length : int option;
      (** Parameter index containing the array length, if applicable. *)
  zero_terminated : bool;  (** Whether the array is null/zero-terminated. *)
  fixed_size : int option;
      (** Fixed size of the array, if known at compile time. *)
  element_type : gir_type;  (** Type of the array elements. *)
  array_name : string option;
      (** Array type name (e.g. "GLib.PtrArray" for GPtrArray). *)
}
(** An array annotation attached to a GIR type. *)

and gir_type = {
  name : string;  (** GIR type name, e.g. "GtkWidget" or "gboolean". *)
  c_type : string option;  (** C type name, e.g. "GtkWidget*". *)
  nullable : bool;  (** Whether the value may be NULL. *)
  transfer_ownership : transfer_ownership;  (** Ownership transfer rules. *)
  array : gir_array option;  (** Present if this type represents an array. *)
}
(** A GIR type reference. *)

(** Direction of a parameter in a C function signature. *)
type gir_direction = In | Out | InOut

type gir_param = {
  param_name : string;  (** Parameter name as it appears in the GIR XML. *)
  param_type : gir_type;  (** Type of the parameter. *)
  direction : gir_direction;
      (** Whether the parameter is in, out, or in-out. *)
  nullable : bool;  (** Whether the parameter may be NULL. *)
  varargs : bool;  (** Whether this is a variadic (...) parameter. *)
  caller_allocates : bool;
      (** True if the caller allocates the buffer for out params. *)
}
(** A single parameter of a GIR method, function, or constructor. *)

type gir_method = {
  method_name : string;  (** Method name as it appears in the GIR XML. *)
  c_identifier : string;  (** C function name, e.g. "gtk_widget_show". *)
  return_type : gir_type;  (** Return type of the method. *)
  parameters : gir_param list;  (** Method parameters. *)
  doc : string option;  (** Documentation string from the GIR XML. *)
  throws : bool;  (** Whether the method can raise a GError. *)
  get_property : string option;  (** Property name if this is a getter. *)
  set_property : string option;  (** Property name if this is a setter. *)
  introspectable : bool;  (** Whether the method is marked introspectable. *)
  version : string option;  (** Version the method was introduced in. *)
  version_namespace : string option;  (** Namespace of the version. *)
  os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A method of a GIR class, interface, or record. *)

type gir_function = {
  function_name : string;  (** Function name as it appears in the GIR XML. *)
  c_identifier : string;  (** C function name. *)
  return_type : gir_type;  (** Return type of the function. *)
  parameters : gir_param list;  (** Function parameters. *)
  doc : string option;  (** Documentation string from the GIR XML. *)
  throws : bool;  (** Whether the function can raise a GError. *)
  introspectable : bool;  (** Whether the function is marked introspectable. *)
  version : string option;  (** Version the function was introduced in. *)
  version_namespace : string option;  (** Namespace of the version. *)
  os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A free function of a GIR namespace, class, or record. *)

(** When a signal handler runs relative to the default handler. *)
type signal_run_when = RunFirst | RunLast | RunCleanup

type gir_signal = {
  signal_name : string;  (** Signal name as it appears in the GIR XML. *)
  return_type : gir_type;  (** Return type of the signal handler. *)
  sig_parameters : gir_param list;  (** Parameters passed to the handler. *)
  doc : string option;  (** Documentation string from the GIR XML. *)
  version : string option;  (** Version the signal was introduced in. *)
  version_namespace : string option;  (** Namespace of the version. *)
  os : Os_filter.t option;  (** OS filter restricting availability. *)
  run_when : signal_run_when option;  (** When the handler runs. *)
  action : bool;  (** Whether the signal is an action signal. *)
  no_recurse : bool;  (** Whether the signal does not recurse. *)
  no_hooks : bool;  (** Whether the signal has no hooks. *)
}
(** A signal of a GIR class or interface. *)

type gir_constructor = {
  ctor_name : string;  (** Constructor name as it appears in the GIR XML. *)
  c_identifier : string;  (** C function name, e.g. "gtk_widget_new". *)
  ctor_parameters : gir_param list;  (** Constructor parameters. *)
  ctor_doc : string option;  (** Documentation string from the GIR XML. *)
  throws : bool;  (** Whether the constructor can raise a GError. *)
  ctor_introspectable : bool;  (** Whether the constructor is introspectable. *)
  version : string option;  (** Version the constructor was introduced in. *)
  version_namespace : string option;  (** Namespace of the version. *)
  os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A constructor of a GIR class or record. *)

type gir_property = {
  prop_name : string;  (** Property name as it appears in the GIR XML. *)
  prop_type : gir_type;  (** Type of the property. *)
  readable : bool;  (** Whether the property has a getter. *)
  writable : bool;  (** Whether the property has a setter. *)
  construct_only : bool;
      (** Whether the property is set only at construction. *)
  prop_doc : string option;  (** Documentation string from the GIR XML. *)
  version : string option;  (** Version the property was introduced in. *)
  version_namespace : string option;  (** Namespace of the version. *)
  os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A property of a GIR class or interface. *)

type gir_record_field = {
  field_name : string;  (** Field name as it appears in the GIR XML. *)
  field_type : gir_type option;  (** Type of the field. *)
  readable : bool;  (** Whether the field is readable. *)
  writable : bool;  (** Whether the field is writable. *)
  field_doc : string option;  (** Documentation string from the GIR XML. *)
  field_version : string option;  (** Version the field was introduced in. *)
  field_os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A field of a GIR record. *)

type gir_record = {
  record_name : string;  (** Record name as it appears in the GIR XML. *)
  c_type : string;  (** C type name, e.g. "GtkBitset". *)
  glib_type_name : string option;  (** GLib type name, e.g. "GtkBitset". *)
  glib_get_type : string option;
      (** Name of the get_type function, if boxed. *)
  opaque : bool;  (** Whether the record is opaque (no public fields). *)
  disguised : bool;  (** Whether the record is disguised (typedef'd pointer). *)
  introspectable : bool;  (** Whether the record is marked introspectable. *)
  c_symbol_prefix : string option;  (** C symbol prefix for the record. *)
  is_gtype_struct_for : string option;
      (** glib:is-gtype-struct-for attribute — class structs to skip. *)
  fields : gir_record_field list;  (** Record fields. *)
  constructors : gir_constructor list;  (** Record constructors. *)
  methods : gir_method list;  (** Record methods. *)
  functions : gir_function list;
      (** Free functions associated with the record. *)
  record_doc : string option;  (** Documentation string from the GIR XML. *)
  version : string option;  (** Version the record was introduced in. *)
  os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A GIR record (C struct). *)

type gir_enum_member = {
  member_name : string;  (** Member name as it appears in the GIR XML. *)
  member_value : int;  (** Numeric value of the member. *)
  c_identifier : string;  (** C identifier, e.g. "GTK_ALIGN_FILL". *)
  member_doc : string option;  (** Documentation string from the GIR XML. *)
  member_version : string option;  (** Version the member was introduced in. *)
  member_os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A member of a GIR enum. *)

type gir_enum = {
  enum_name : string;  (** Enum name as it appears in the GIR XML. *)
  enum_c_type : string;  (** C type name, e.g. "GtkAlign". *)
  members : gir_enum_member list;  (** Enum members. *)
  functions : gir_function list;
      (** Free functions associated with the enum. *)
  enum_doc : string option;  (** Documentation string from the GIR XML. *)
  enum_version : string option;  (** Version the enum was introduced in. *)
  enum_os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A GIR enum. *)

type gir_bitfield_member = {
  flag_name : string;  (** Flag name as it appears in the GIR XML. *)
  flag_value : int;  (** Numeric value of the flag. *)
  flag_c_identifier : string;
      (** C identifier, e.g. "GTK_STATE_FLAG_ACTIVE". *)
  flag_doc : string option;  (** Documentation string from the GIR XML. *)
  flag_version : string option;  (** Version the flag was introduced in. *)
  flag_os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A member of a GIR bitfield (flags). *)

type gir_constant = {
  constant_name : string;  (** Constant name as it appears in the GIR XML. *)
  constant_c_type : string;  (** C type name of the constant. *)
  value : string;  (** String representation of the constant value. *)
  value_type : gir_type;  (** Type of the constant value. *)
  constant_doc : string option;  (** Documentation string from the GIR XML. *)
  version : string option;  (** Version the constant was introduced in. *)
  os : Os_filter.t option;  (** OS filter restricting availability. *)
  introspectable : bool;  (** Whether the constant is marked introspectable. *)
}
(** A GIR constant. *)

type gir_bitfield = {
  bitfield_name : string;  (** Bitfield name as it appears in the GIR XML. *)
  bitfield_c_type : string;  (** C type name, e.g. "GtkStateFlags". *)
  flags : gir_bitfield_member list;  (** Bitfield members. *)
  bitfield_doc : string option;  (** Documentation string from the GIR XML. *)
  bitfield_version : string option;
      (** Version the bitfield was introduced in. *)
  bitfield_os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A GIR bitfield (flags). *)

type gir_class = {
  class_name : string;  (** Class name as it appears in the GIR XML. *)
  c_type : string;  (** C type name, e.g. "GtkWidget". *)
  parent : string option;  (** Name of the parent class, if any. *)
  implements : string list;  (** Names of implemented interfaces. *)
  introspectable : bool;  (** Whether the class is marked introspectable. *)
  constructors : gir_constructor list;  (** Class constructors. *)
  methods : gir_method list;  (** Class methods. *)
  properties : gir_property list;  (** Class properties. *)
  signals : gir_signal list;  (** Class signals. *)
  class_doc : string option;  (** Documentation string from the GIR XML. *)
  version : string option;  (** Version the class was introduced in. *)
  os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A GIR class. *)

type gir_interface = {
  interface_name : string;  (** Interface name as it appears in the GIR XML. *)
  c_type : string;  (** C type name, e.g. "GtkScrollable". *)
  c_symbol_prefix : string;  (** C symbol prefix for the interface. *)
  glib_type_name : string option;  (** GLib type name, if any. *)
  glib_get_type : string option;  (** Name of the get_type function, if any. *)
  prerequisites : string list;  (** Names of prerequisite interfaces. *)
  introspectable : bool;  (** Whether the interface is marked introspectable. *)
  methods : gir_method list;  (** Interface methods. *)
  properties : gir_property list;  (** Interface properties. *)
  signals : gir_signal list;  (** Interface signals. *)
  interface_doc : string option;  (** Documentation string from the GIR XML. *)
  version : string option;  (** Version the interface was introduced in. *)
  os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A GIR interface. *)

(** Unified entity kind for classes, interfaces, and records. *)
type entity_kind =
  | Class of gir_class
  | Interface of gir_interface
  | Record of gir_record

type entity = {
  kind : entity_kind;  (** Which kind of entity this is. *)
  name : string;  (** Entity name. *)
  c_type : string;  (** C type name. *)
  doc : string option;  (** Documentation string from the GIR XML. *)
  parent : string option;
      (** Parent class name (None for interfaces/records). *)
  implements : string list;
      (** Implemented interfaces (empty for interfaces). *)
  constructors : gir_constructor list;
      (** Constructors (empty for interfaces). *)
  methods : gir_method list;  (** Methods. *)
  properties : gir_property list;  (** Properties. *)
  signals : gir_signal list;  (** Signals. *)
  version : string option;  (** Version the entity was introduced in. *)
  os : Os_filter.t option;  (** OS filter restricting availability. *)
}
(** A unified view of a class, interface, or record, used by the generators that
    treat all three uniformly. *)

val entity_of_class : gir_class -> entity
(** Build an [entity] from a [gir_class]. *)

val entity_of_interface : gir_interface -> entity
(** Build an [entity] from a [gir_interface]. *)

val entity_of_record : gir_record -> entity
(** Build an [entity] from a [gir_record]. *)

type ocaml_class = {
  class_module : string;
      (** Module path of the Layer 2 class, e.g. "GWidget". *)
  class_type : string;  (** Type name of the class, e.g. "widget_t". *)
  class_ml_name : string;  (** OCaml name of the class, e.g. "widget". *)
  class_layer1_accessor : string;  (** Accessor method name, e.g. "as_widget". *)
}
(** Layer 2 class wrapper information for a generated OCaml class. *)

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

(** Ownership strategy for wrapping a C return value into OCaml.

    Used by [generate_ref_sink_stmt] to emit the correct ownership transfer call
    after a C function returns a value with [transfer-ownership="none"]. *)
and transfer_strategy =
  | Ts_none
      (** No special ownership action: primitives, strings, enums, bitfields,
          and container types. The C value is copied or the OCaml runtime
          manages the memory. *)
  | Ts_gobject
      (** GObject class or interface: emit [g_object_ref_sink(result)] for
          transfer-none and floating returns so the OCaml finalizer always holds
          a strong reference. *)
  | Ts_boxed of string
      (** GObject boxed type (record with [glib:get-type]): emit
          [result = g_boxed_copy(<get_type_func>(), result)] for transfer-none
          returns. The string is the C get-type function name, e.g.
          ["gdk_content_formats_get_type"]. *)
  | Ts_gvariant
      (** [GVariant]: emit [g_variant_ref(result)] for transfer-none returns.
          GVariant is ref-counted but uses its own API rather than the generic
          boxed interface. *)

type gir_namespace = {
  namespace_name : string;  (** Namespace name, e.g. "Gtk". *)
  namespace_version : string;  (** Namespace version, e.g. "4.0". *)
  namespace_shared_library : string;
      (** Shared library the namespace maps to. *)
  namespace_c_identifier_prefixes : string;  (** C identifier prefixes. *)
  namespace_c_symbol_prefixes : string;  (** C symbol prefixes. *)
}
(** A GIR namespace (library), e.g. "Gtk" or "Gdk". *)

type gir_include = { include_name : string; include_version : string }
(** An include of one GIR namespace by another. *)

type gir_repository = {
  repository_includes : gir_include list;  (** Included GIR namespaces. *)
  repository_c_includes : string list;  (** C headers to include. *)
  repository_packages : string list;  (** pkg-config packages. *)
}
(** The repository-level metadata of a GIR file. *)

(** The kind of a cross-namespace type reference. *)
type cross_reference_type =
  | Crt_Class of { parent : string option; implements : string list }
  | Crt_Interface
  | Crt_Record of { opaque : bool; get_type_func : string option }
  | Crt_Enum
  | Crt_Bitfield
  | Crt_Constant

type cross_reference_entity = {
  cr_name : string;  (** Entity name, e.g. "Surface". *)
  cr_type : cross_reference_type;  (** Kind of the referenced entity. *)
  cr_c_type : string;  (** C type name, e.g. "GdkSurface". *)
}
(** A single cross-namespace type reference. *)

type cross_reference_namespace = {
  cr_namespace_name : string;  (** External namespace name, e.g. "Gdk". *)
  cr_namespace_packages : string list;  (** pkg-config packages. *)
  cr_namespace_includes : string list;  (** GIR includes. *)
  cr_namespace_c_includes : string list;  (** C headers to include. *)
  cr_entities : cross_reference_entity list;  (** Referenced entities. *)
}
(** All cross-namespace references to one external namespace. *)

val cross_reference_namespace_of_sexp :
  Sexplib0.Sexp.t -> cross_reference_namespace
(** Deserialize a [cross_reference_namespace] from an s-expression. *)

val sexp_of_cross_reference_namespace :
  cross_reference_namespace -> Sexplib0.Sexp.t
(** Serialize a [cross_reference_namespace] to an s-expression. *)

(** A map keyed by [String.t], used for cross-references and module groups. *)
module StringMap : sig
  type key = String.t
  type 'a t

  val empty : 'a t
  val add : key -> 'a -> 'a t -> 'a t
  val find_opt : key -> 'a t -> 'a option
  val fold : (key -> 'a -> 'acc -> 'acc) -> 'a t -> 'acc -> 'acc
end

type generation_context_namespace_cross_references = {
  ncr_namespace_name : string;  (** External namespace name. *)
  ncr_namespace_packages : string list;  (** pkg-config packages. *)
  ncr_namespace_includes : string list;  (** GIR includes. *)
  ncr_namespace_c_includes : string list;  (** C headers to include. *)
  ncr_entities : cross_reference_entity StringMap.t;  (** Referenced entities. *)
}
(** Cross-references to one external namespace, keyed by entity name. *)

type generation_context = {
  namespace : gir_namespace;  (** The namespace being generated. *)
  repository : gir_repository;  (** Repository-level metadata. *)
  classes : gir_class list;  (** All classes in the namespace. *)
  interfaces : gir_interface list;  (** All interfaces in the namespace. *)
  enums : gir_enum list;  (** All enums in the namespace. *)
  bitfields : gir_bitfield list;  (** All bitfields in the namespace. *)
  records : gir_record list;  (** All records in the namespace. *)
  constants : gir_constant list;  (** All constants in the namespace. *)
  module_groups : (string, string) Hashtbl.t;
      (** Maps class name to combined module name for cyclic modules. *)
  current_cycle_classes : string list;
      (** Class names in the current cyclic module being generated. *)
  cross_references : generation_context_namespace_cross_references StringMap.t;
      (** Cross-namespace references, keyed by namespace name. *)
}
(** The full generation context passed to all generators. *)
