(* Factories for [Gir_gen_lib.Types] records.

   Every factory takes optional arguments defaulting to the empty/[None]
   value, so call sites only spell out the fields that matter for the test. *)

val entity_of_class : Gir_gen_lib.Types.gir_class -> Gir_gen_lib.Types.entity
(** [entity_of_class cls] converts a GIR class into the generic [entity]
    representation. *)

(** {1 GIR Type Factories} *)

val make_return_type :
  name:string ->
  c_type:string option ->
  ?nullable:bool ->
  ?transfer_ownership:Gir_gen_lib.Types.transfer_ownership ->
  ?array:Gir_gen_lib.Types.gir_array ->
  unit ->
  Gir_gen_lib.Types.gir_type
(** [make_return_type ~name ~c_type ?nullable ?transfer_ownership ?array ()]
    builds a [gir_type] for a return value. *)

val make_gir_type :
  name:string ->
  ?c_type:string ->
  ?nullable:bool ->
  ?transfer_ownership:Gir_gen_lib.Types.transfer_ownership ->
  ?array:Gir_gen_lib.Types.gir_array ->
  unit ->
  Gir_gen_lib.Types.gir_type
(** [make_gir_type ~name ?c_type ?nullable ?transfer_ownership ?array ()] builds
    a [gir_type] with the given name and optional C type. *)

val make_gir_array :
  ?length:int ->
  ?zero_terminated:bool ->
  ?fixed_size:int ->
  ?array_name:string ->
  element_type:Gir_gen_lib.Types.gir_type ->
  unit ->
  Gir_gen_lib.Types.gir_array
(** [make_gir_array ?length ?zero_terminated ?fixed_size ?array_name
     ~element_type ()] builds a [gir_array] over [element_type]. *)

val make_gir_param :
  param_name:string ->
  param_type:Gir_gen_lib.Types.gir_type ->
  ?direction:Gir_gen_lib.Types.gir_direction ->
  ?nullable:bool ->
  ?varargs:bool ->
  ?caller_allocates:bool ->
  unit ->
  Gir_gen_lib.Types.gir_param
(** [make_gir_param ~param_name ~param_type ?direction ?nullable ?varargs
     ?caller_allocates ()] builds a [gir_param]. *)

val make_gir_method :
  method_name:string ->
  c_identifier:string ->
  return_type:Gir_gen_lib.Types.gir_type ->
  ?parameters:Gir_gen_lib.Types.gir_param list ->
  ?doc:string ->
  ?throws:bool ->
  ?introspectable:bool ->
  ?get_property:string ->
  ?set_property:string ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_method
(** [make_gir_method ~method_name ~c_identifier ~return_type ?parameters ?doc
     ?throws ?introspectable ?get_property ?set_property ?version ()] builds a
    [gir_method]. *)

val make_gir_function :
  function_name:string ->
  c_identifier:string ->
  return_type:Gir_gen_lib.Types.gir_type ->
  ?parameters:Gir_gen_lib.Types.gir_param list ->
  ?doc:string ->
  ?throws:bool ->
  ?introspectable:bool ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_function
(** [make_gir_function ~function_name ~c_identifier ~return_type ?parameters
     ?doc ?throws ?introspectable ?version ()] builds a [gir_function]. *)

val make_gir_signal :
  signal_name:string ->
  return_type:Gir_gen_lib.Types.gir_type ->
  ?sig_parameters:Gir_gen_lib.Types.gir_param list ->
  ?doc:string ->
  ?version:string ->
  ?run_when:Gir_gen_lib.Types.signal_run_when ->
  ?action:bool ->
  ?no_recurse:bool ->
  ?no_hooks:bool ->
  unit ->
  Gir_gen_lib.Types.gir_signal
(** [make_gir_signal ~signal_name ~return_type ?sig_parameters ?doc ?version
     ?run_when ?action ?no_recurse ?no_hooks ()] builds a [gir_signal]. *)

val make_gir_constructor :
  ctor_name:string ->
  c_identifier:string ->
  ?ctor_parameters:Gir_gen_lib.Types.gir_param list ->
  ?ctor_doc:string ->
  ?throws:bool ->
  ?ctor_introspectable:bool ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_constructor
(** [make_gir_constructor ~ctor_name ~c_identifier ?ctor_parameters ?ctor_doc
     ?throws ?ctor_introspectable ?version ()] builds a [gir_constructor]. *)

val make_gir_property :
  prop_name:string ->
  prop_type:Gir_gen_lib.Types.gir_type ->
  ?readable:bool ->
  ?writable:bool ->
  ?construct_only:bool ->
  ?prop_doc:string ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_property
(** [make_gir_property ~prop_name ~prop_type ?readable ?writable ?construct_only
     ?prop_doc ?version ()] builds a [gir_property]. *)

val make_gir_record_field :
  field_name:string ->
  ?field_type:Gir_gen_lib.Types.gir_type ->
  ?readable:bool ->
  ?writable:bool ->
  ?field_doc:string ->
  unit ->
  Gir_gen_lib.Types.gir_record_field
(** [make_gir_record_field ~field_name ?field_type ?readable ?writable
     ?field_doc ()] builds a [gir_record_field]. *)

val make_gir_record :
  ?record_name:string ->
  ?c_type:string ->
  ?glib_type_name:string ->
  ?glib_get_type:string ->
  ?opaque:bool ->
  ?disguised:bool ->
  ?introspectable:bool ->
  ?c_symbol_prefix:string ->
  ?is_gtype_struct_for:string ->
  ?fields:Gir_gen_lib.Types.gir_record_field list ->
  ?constructors:Gir_gen_lib.Types.gir_constructor list ->
  ?methods:Gir_gen_lib.Types.gir_method list ->
  ?functions:Gir_gen_lib.Types.gir_function list ->
  ?record_doc:string ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_record
(** [make_gir_record ?record_name ?c_type ?glib_type_name ?glib_get_type ?opaque
     ?disguised ?introspectable ?c_symbol_prefix ?is_gtype_struct_for ?fields
     ?constructors ?methods ?functions ?record_doc ?version ()] builds a
    [gir_record]. *)

val make_gir_enum_member :
  ?member_name:string ->
  ?member_value:int ->
  ?c_identifier:string ->
  ?member_doc:string ->
  unit ->
  Gir_gen_lib.Types.gir_enum_member
(** [make_gir_enum_member ?member_name ?member_value ?c_identifier ?member_doc
     ()] builds a [gir_enum_member]. *)

val make_gir_enum :
  ?enum_name:string ->
  ?enum_c_type:string ->
  ?members:Gir_gen_lib.Types.gir_enum_member list ->
  ?functions:Gir_gen_lib.Types.gir_function list ->
  ?enum_doc:string ->
  ?enum_version:string ->
  unit ->
  Gir_gen_lib.Types.gir_enum
(** [make_gir_enum ?enum_name ?enum_c_type ?members ?functions ?enum_doc
     ?enum_version ()] builds a [gir_enum]. *)

val make_gir_bitfield_member :
  ?flag_name:string ->
  ?flag_value:int ->
  ?flag_c_identifier:string ->
  ?flag_doc:string ->
  unit ->
  Gir_gen_lib.Types.gir_bitfield_member
(** [make_gir_bitfield_member ?flag_name ?flag_value ?flag_c_identifier
     ?flag_doc ()] builds a [gir_bitfield_member]. *)

val make_gir_bitfield :
  ?bitfield_name:string ->
  ?bitfield_c_type:string ->
  ?flags:Gir_gen_lib.Types.gir_bitfield_member list ->
  ?bitfield_doc:string ->
  ?bitfield_version:string ->
  unit ->
  Gir_gen_lib.Types.gir_bitfield
(** [make_gir_bitfield ?bitfield_name ?bitfield_c_type ?flags ?bitfield_doc
     ?bitfield_version ()] builds a [gir_bitfield]. *)

val make_gir_constant :
  ?constant_name:string ->
  ?constant_c_type:string ->
  ?value:string ->
  ?value_type:Gir_gen_lib.Types.gir_type ->
  ?constant_doc:string ->
  ?version:string ->
  ?introspectable:bool ->
  unit ->
  Gir_gen_lib.Types.gir_constant
(** [make_gir_constant ?constant_name ?constant_c_type ?value ?value_type
     ?constant_doc ?version ?introspectable ()] builds a [gir_constant]. *)

val make_gir_class :
  ?class_name:string ->
  ?c_type:string ->
  ?parent:string ->
  ?implements:string list ->
  ?introspectable:bool ->
  ?constructors:Gir_gen_lib.Types.gir_constructor list ->
  ?methods:Gir_gen_lib.Types.gir_method list ->
  ?properties:Gir_gen_lib.Types.gir_property list ->
  ?signals:Gir_gen_lib.Types.gir_signal list ->
  ?class_doc:string ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_class
(** [make_gir_class ?class_name ?c_type ?parent ?implements ?introspectable
     ?constructors ?methods ?properties ?signals ?class_doc ?version ()] builds
    a [gir_class]. *)

val make_gir_interface :
  ?interface_name:string ->
  ?c_type:string ->
  ?c_symbol_prefix:string ->
  ?glib_type_name:string option ->
  ?glib_get_type:string option ->
  ?prerequisites:string list ->
  ?introspectable:bool ->
  ?methods:Gir_gen_lib.Types.gir_method list ->
  ?properties:Gir_gen_lib.Types.gir_property list ->
  ?signals:Gir_gen_lib.Types.gir_signal list ->
  ?interface_doc:string ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_interface
(** [make_gir_interface ?interface_name ?c_type ?c_symbol_prefix ?glib_type_name
     ?glib_get_type ?prerequisites ?introspectable ?methods ?properties ?signals
     ?interface_doc ?version ()] builds a [gir_interface]. *)

(** {1 Namespace and Repository Factories} *)

val make_gir_namespace :
  ?namespace_name:string ->
  ?namespace_version:string ->
  ?namespace_shared_library:string ->
  ?namespace_c_identifier_prefixes:string ->
  ?namespace_c_symbol_prefixes:string ->
  unit ->
  Gir_gen_lib.Types.gir_namespace
(** [make_gir_namespace ?namespace_name ?namespace_version
     ?namespace_shared_library ?namespace_c_identifier_prefixes
     ?namespace_c_symbol_prefixes ()] builds a [gir_namespace]. *)

val make_gir_repository :
  ?repository_includes:Gir_gen_lib.Types.gir_include list ->
  ?repository_c_includes:string list ->
  ?repository_packages:string list ->
  unit ->
  Gir_gen_lib.Types.gir_repository
(** [make_gir_repository ?repository_includes ?repository_c_includes
     ?repository_packages ()] builds a [gir_repository]. *)

(** {1 Cross-Reference Factories} *)

val make_cross_reference_type :
  ?parent:string ->
  [< `Bitfield | `Class | `Constant | `Enum | `Interface | `Record of bool ] ->
  Gir_gen_lib.Types.cross_reference_type
(** [make_cross_reference_type ?parent kind] builds a [cross_reference_type]
    from the polymorphic-variant [kind]. *)

val make_cross_reference_entity :
  ?cr_name:string ->
  ?cr_type:Gir_gen_lib.Types.cross_reference_type ->
  ?cr_c_type:string ->
  unit ->
  Gir_gen_lib.Types.cross_reference_entity
(** [make_cross_reference_entity ?cr_name ?cr_type ?cr_c_type ()] builds a
    [cross_reference_entity]. *)

val make_cross_reference_namespace :
  ?cr_namespace_name:string ->
  ?cr_namespace_packages:string list ->
  ?cr_namespace_includes:string list ->
  ?cr_namespace_c_includes:string list ->
  ?cr_entities:Gir_gen_lib.Types.cross_reference_entity list ->
  unit ->
  Gir_gen_lib.Types.cross_reference_namespace
(** [make_cross_reference_namespace ?cr_namespace_name ?cr_namespace_packages
     ?cr_namespace_includes ?cr_namespace_c_includes ?cr_entities ()] builds a
    [cross_reference_namespace]. *)

val make_cross_reference_map :
  (Gir_gen_lib.Types.StringMap.key * 'a) list ->
  'a Gir_gen_lib.Types.StringMap.t
(** [make_cross_reference_map pairs] builds a [StringMap] of cross-namespace
    references from an association list of [(namespace_name, ncr)] pairs.
    Intended to be used with [Helpers.make_ncr]. *)

(** {1 Generation Context Factory} *)

val make_generation_context :
  ?namespace:Gir_gen_lib.Types.gir_namespace ->
  ?repository:Gir_gen_lib.Types.gir_repository ->
  ?classes:Gir_gen_lib.Types.gir_class list ->
  ?interfaces:Gir_gen_lib.Types.gir_interface list ->
  ?enums:Gir_gen_lib.Types.gir_enum list ->
  ?bitfields:Gir_gen_lib.Types.gir_bitfield list ->
  ?records:Gir_gen_lib.Types.gir_record list ->
  ?constants:Gir_gen_lib.Types.gir_constant list ->
  ?module_groups:(string * string) list ->
  ?current_cycle_classes:string list ->
  ?cross_references:
    Gir_gen_lib.Types.generation_context_namespace_cross_references
    Gir_gen_lib.Types.StringMap.t ->
  unit ->
  Gir_gen_lib.Types.generation_context
(** [make_generation_context ?namespace ?repository ?classes ?interfaces ?enums
     ?bitfields ?records ?constants ?module_groups ?current_cycle_classes
     ?cross_references ()] builds a [generation_context]. *)

(** {1 Common GIR Types} *)

val void_type : Gir_gen_lib.Types.gir_type
(** The [void] GIR type. *)

val utf8_type : Gir_gen_lib.Types.gir_type
(** The [utf8] GIR type ([const gchar*]). *)

val gint_type : Gir_gen_lib.Types.gir_type
(** The [gint] GIR type. *)

val guint_type : Gir_gen_lib.Types.gir_type
(** The [guint] GIR type. *)

val gdouble_type : Gir_gen_lib.Types.gir_type
(** The [gdouble] GIR type. *)

val gboolean_type : Gir_gen_lib.Types.gir_type
(** The [gboolean] GIR type. *)

val make_widget_type : ?nullable:bool -> unit -> Gir_gen_lib.Types.gir_type
(** [make_widget_type ?nullable ()] builds the [GtkWidget] GIR type. *)

val widget_type : Gir_gen_lib.Types.gir_type
(** The non-nullable [GtkWidget] GIR type. *)

val string_option_type : Gir_gen_lib.Types.gir_type
(** The nullable [utf8] GIR type. *)

(** {1 Convenience Helper Factories for Common Test Patterns} *)

val make_void_method :
  method_name:string ->
  c_identifier:string ->
  ?parameters:Gir_gen_lib.Types.gir_param list ->
  ?throws:bool ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_method
(** [make_void_method ~method_name ~c_identifier ?parameters ?throws ?version
     ()] builds a method returning [void]. *)

val make_string_method :
  method_name:string ->
  c_identifier:string ->
  ?parameters:Gir_gen_lib.Types.gir_param list ->
  ?throws:bool ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_method
(** [make_string_method ~method_name ~c_identifier ?parameters ?throws ?version
     ()] builds a method returning [utf8]. *)

val make_int_method :
  method_name:string ->
  c_identifier:string ->
  ?parameters:Gir_gen_lib.Types.gir_param list ->
  ?throws:bool ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_method
(** [make_int_method ~method_name ~c_identifier ?parameters ?throws ?version ()]
    builds a method returning [gint]. *)

val make_string_param :
  param_name:string -> ?nullable:bool -> unit -> Gir_gen_lib.Types.gir_param
(** [make_string_param ~param_name ?nullable ()] builds a [utf8] parameter. *)

val make_int_param :
  param_name:string -> ?nullable:bool -> unit -> Gir_gen_lib.Types.gir_param
(** [make_int_param ~param_name ?nullable ()] builds a [gint] parameter. *)

val make_bool_param :
  param_name:string -> ?nullable:bool -> unit -> Gir_gen_lib.Types.gir_param
(** [make_bool_param ~param_name ?nullable ()] builds a [gboolean] parameter. *)

val make_widget_param :
  param_name:string -> ?nullable:bool -> unit -> Gir_gen_lib.Types.gir_param
(** [make_widget_param ~param_name ?nullable ()] builds a [GtkWidget] parameter.
*)

val make_void_signal :
  signal_name:string ->
  ?sig_parameters:Gir_gen_lib.Types.gir_param list ->
  ?version:string ->
  unit ->
  Gir_gen_lib.Types.gir_signal
(** [make_void_signal ~signal_name ?sig_parameters ?version ()] builds a signal
    returning [void]. *)
