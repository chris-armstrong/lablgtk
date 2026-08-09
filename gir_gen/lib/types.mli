type transfer_ownership =
  | TransferNone
  | TransferFull
  | TransferContainer
  | TransferFloating

type gir_array = {
  length : int option;
  zero_terminated : bool;
  fixed_size : int option;
  element_type : gir_type;
  array_name : string option;
}

and gir_type = {
  name : string;
  c_type : string option;
  nullable : bool;
  transfer_ownership : transfer_ownership;
  array : gir_array option;
}

type gir_direction = In | Out | InOut

type gir_param = {
  param_name : string;
  param_type : gir_type;
  direction : gir_direction;
  nullable : bool;
  varargs : bool;
  caller_allocates : bool;
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

type entity_kind =
  | Class of gir_class
  | Interface of gir_interface
  | Record of gir_record

type entity = {
  kind : entity_kind;
  name : string;
  c_type : string;
  doc : string option;
  parent : string option;
  implements : string list;
  constructors : gir_constructor list;
  methods : gir_method list;
  properties : gir_property list;
  signals : gir_signal list;
  version : string option;
  os : Os_filter.t option;
}

val entity_of_class : gir_class -> entity
val entity_of_interface : gir_interface -> entity
val entity_of_record : gir_record -> entity

type ocaml_class = {
  class_module : string;
  class_type : string;
  class_ml_name : string;
  class_layer1_accessor : string;
}

type type_mapping = {
  ocaml_type : string;
  c_type : string;
  c_to_ml : string;
  ml_to_c : string;
  layer2_class : ocaml_class option;
  is_value_type_record : bool;
  transfer_strategy : transfer_strategy;
}

and transfer_strategy =
  | Ts_none
  | Ts_gobject
  | Ts_boxed of string
  | Ts_gvariant

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
  | Crt_Class of { parent : string option; implements : string list }
  | Crt_Interface
  | Crt_Record of { opaque : bool; get_type_func : string option }
  | Crt_Enum
  | Crt_Bitfield
  | Crt_Constant

val cross_reference_type_of_sexp : Sexplib0.Sexp.t -> cross_reference_type
val sexp_of_cross_reference_type : cross_reference_type -> Sexplib0.Sexp.t

type cross_reference_entity = {
  cr_name : string;
  cr_type : cross_reference_type;
  cr_c_type : string;
}

val cross_reference_entity_of_sexp : Sexplib0.Sexp.t -> cross_reference_entity
val sexp_of_cross_reference_entity : cross_reference_entity -> Sexplib0.Sexp.t

type cross_reference_namespace = {
  cr_namespace_name : string;
  cr_namespace_packages : string list;
  cr_namespace_includes : string list;
  cr_namespace_c_includes : string list;
  cr_entities : cross_reference_entity list;
}

val cross_reference_namespace_of_sexp :
  Sexplib0.Sexp.t -> cross_reference_namespace

val sexp_of_cross_reference_namespace :
  cross_reference_namespace -> Sexplib0.Sexp.t

module StringMap : sig
  type key = String.t
  type 'a t = 'a Stdlib__Map.Make(String).t

  val empty : 'a t
  val add : key -> 'a -> 'a t -> 'a t
  val add_to_list : key -> 'a -> 'a list t -> 'a list t
  val update : key -> ('a option -> 'a option) -> 'a t -> 'a t
  val singleton : key -> 'a -> 'a t
  val remove : key -> 'a t -> 'a t

  val merge :
    (key -> 'a option -> 'b option -> 'c option) -> 'a t -> 'b t -> 'c t

  val union : (key -> 'a -> 'a -> 'a option) -> 'a t -> 'a t -> 'a t
  val cardinal : 'a t -> int
  val bindings : 'a t -> (key * 'a) list
  val min_binding : 'a t -> key * 'a
  val min_binding_opt : 'a t -> (key * 'a) option
  val max_binding : 'a t -> key * 'a
  val max_binding_opt : 'a t -> (key * 'a) option
  val choose : 'a t -> key * 'a
  val choose_opt : 'a t -> (key * 'a) option
  val find : key -> 'a t -> 'a
  val find_opt : key -> 'a t -> 'a option
  val find_first : (key -> bool) -> 'a t -> key * 'a
  val find_first_opt : (key -> bool) -> 'a t -> (key * 'a) option
  val find_last : (key -> bool) -> 'a t -> key * 'a
  val find_last_opt : (key -> bool) -> 'a t -> (key * 'a) option
  val iter : (key -> 'a -> unit) -> 'a t -> unit
  val fold : (key -> 'a -> 'acc -> 'acc) -> 'a t -> 'acc -> 'acc
  val map : ('a -> 'b) -> 'a t -> 'b t
  val mapi : (key -> 'a -> 'b) -> 'a t -> 'b t
  val filter : (key -> 'a -> bool) -> 'a t -> 'a t
  val filter_map : (key -> 'a -> 'b option) -> 'a t -> 'b t
  val partition : (key -> 'a -> bool) -> 'a t -> 'a t * 'a t
  val split : key -> 'a t -> 'a t * 'a option * 'a t
  val is_empty : 'a t -> bool
  val mem : key -> 'a t -> bool
  val equal : ('a -> 'a -> bool) -> 'a t -> 'a t -> bool
  val compare : ('a -> 'a -> int) -> 'a t -> 'a t -> int
  val for_all : (key -> 'a -> bool) -> 'a t -> bool
  val exists : (key -> 'a -> bool) -> 'a t -> bool
  val to_list : 'a t -> (key * 'a) list
  val of_list : (key * 'a) list -> 'a t
  val to_seq : 'a t -> (key * 'a) Seq.t
  val to_rev_seq : 'a t -> (key * 'a) Seq.t
  val to_seq_from : key -> 'a t -> (key * 'a) Seq.t
  val add_seq : (key * 'a) Seq.t -> 'a t -> 'a t
  val of_seq : (key * 'a) Seq.t -> 'a t
end

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
  module_groups : (string, string) Sexplib.Std.Hashtbl.t;
  current_cycle_classes : string list;
  cross_references : generation_context_namespace_cross_references StringMap.t;
}
