open Gir_gen_lib.Types

(** [entity_of_class cls] converts a GIR class into the generic [entity]
    representation. *)
let entity_of_class = Gir_gen_lib.Types.entity_of_class

(** [make_return_type ~name ~c_type ?nullable ?transfer_ownership ?array ()]
    builds a [gir_type] for a return value. *)
let make_return_type ~name ~c_type ?nullable ?transfer_ownership ?array () =
  {
    name;
    c_type;
    nullable = Option.value nullable ~default:false;
    transfer_ownership = Option.value transfer_ownership ~default:TransferNone;
    array;
  }

(** [make_gir_type ~name ?c_type ?nullable ?transfer_ownership ?array ()] builds
    a [gir_type] with the given name and optional C type. *)
let make_gir_type ~name ?c_type ?nullable ?transfer_ownership ?array () =
  {
    name;
    c_type;
    nullable = Option.value nullable ~default:false;
    transfer_ownership = Option.value transfer_ownership ~default:TransferNone;
    array;
  }

(** [make_gir_array ?length ?zero_terminated ?fixed_size ?array_name
     ~element_type ()] builds a [gir_array] over [element_type]. *)
let make_gir_array ?length ?(zero_terminated = false) ?fixed_size ?array_name
    ~element_type () =
  { length; zero_terminated; fixed_size; array_name; element_type }

(** [make_gir_param ~param_name ~param_type ?direction ?nullable ?varargs
     ?caller_allocates ()] builds a [gir_param]. *)
let make_gir_param ~param_name ~param_type ?direction ?nullable ?varargs
    ?caller_allocates () =
  {
    param_name;
    param_type;
    direction = Option.value direction ~default:In;
    nullable = Option.value nullable ~default:false;
    varargs = Option.value varargs ~default:false;
    caller_allocates = Option.value caller_allocates ~default:false;
  }

(** [make_gir_method ~method_name ~c_identifier ~return_type ?parameters ?doc
     ?throws ?introspectable ?get_property ?set_property ?version ()] builds a
    [gir_method]. *)
let make_gir_method ~method_name ~c_identifier ~return_type ?parameters ?doc
    ?throws ?introspectable ?get_property ?set_property ?version () =
  {
    method_name;
    c_identifier;
    return_type;
    parameters = Option.value parameters ~default:[];
    doc;
    throws = Option.value throws ~default:false;
    introspectable = Option.value introspectable ~default:true;
    get_property;
    set_property;
    version;
    version_namespace = None;
    os = None;
  }

(** [make_gir_function ~function_name ~c_identifier ~return_type ?parameters
     ?doc ?throws ?introspectable ?version ()] builds a [gir_function]. *)
let make_gir_function ~function_name ~c_identifier ~return_type ?parameters ?doc
    ?throws ?introspectable ?version () =
  {
    function_name;
    c_identifier;
    return_type;
    parameters = Option.value parameters ~default:[];
    doc;
    throws = Option.value throws ~default:false;
    introspectable = Option.value introspectable ~default:true;
    version;
    version_namespace = None;
    os = None;
  }

(** [make_gir_signal ~signal_name ~return_type ?sig_parameters ?doc ?version
     ?run_when ?action ?no_recurse ?no_hooks ()] builds a [gir_signal]. *)
let make_gir_signal ~signal_name ~return_type ?(sig_parameters = []) ?doc
    ?version ?run_when ?(action = false) ?(no_recurse = false)
    ?(no_hooks = false) () =
  {
    signal_name;
    return_type;
    sig_parameters;
    doc;
    version;
    version_namespace = None;
    os = None;
    run_when;
    action;
    no_recurse;
    no_hooks;
  }

(** [make_gir_constructor ~ctor_name ~c_identifier ?ctor_parameters ?ctor_doc
     ?throws ?ctor_introspectable ?version ()] builds a [gir_constructor]. *)
let make_gir_constructor ~ctor_name ~c_identifier ?(ctor_parameters = [])
    ?ctor_doc ?throws ?ctor_introspectable ?version () =
  {
    ctor_name;
    c_identifier;
    ctor_parameters;
    ctor_doc;
    throws = Option.value throws ~default:false;
    ctor_introspectable = Option.value ctor_introspectable ~default:true;
    version;
    version_namespace = None;
    os = None;
  }

(** [make_gir_property ~prop_name ~prop_type ?readable ?writable ?construct_only
     ?prop_doc ?version ()] builds a [gir_property]. *)
let make_gir_property ~prop_name ~prop_type ?(readable = true)
    ?(writable = true) ?(construct_only = false) ?prop_doc ?version () =
  {
    prop_name;
    prop_type;
    readable;
    writable;
    construct_only;
    prop_doc;
    version;
    version_namespace = None;
    os = None;
  }

(** [make_gir_record_field ~field_name ?field_type ?readable ?writable
     ?field_doc ()] builds a [gir_record_field]. *)
let make_gir_record_field ~field_name ?field_type ?(readable = true)
    ?(writable = false) ?field_doc () =
  {
    field_name;
    field_type;
    readable;
    writable;
    field_doc;
    field_version = None;
    field_os = None;
  }

(** [make_gir_record ?record_name ?c_type ?glib_type_name ?glib_get_type ?opaque
     ?disguised ?introspectable ?c_symbol_prefix ?is_gtype_struct_for ?fields
     ?constructors ?methods ?functions ?record_doc ?version ()] builds a
    [gir_record]. *)
let make_gir_record ?(record_name = "TestRecord") ?(c_type = "TestRecord")
    ?glib_type_name ?glib_get_type ?(opaque = false) ?(disguised = false)
    ?(introspectable = true) ?c_symbol_prefix ?is_gtype_struct_for
    ?(fields = []) ?(constructors = []) ?(methods = []) ?(functions = [])
    ?record_doc ?version () =
  {
    record_name;
    c_type;
    glib_type_name;
    glib_get_type;
    opaque;
    disguised;
    introspectable;
    c_symbol_prefix;
    is_gtype_struct_for;
    fields;
    constructors;
    methods;
    functions;
    record_doc;
    version;
    os = None;
  }

(** [make_gir_enum_member ?member_name ?member_value ?c_identifier ?member_doc
     ()] builds a [gir_enum_member]. *)
let make_gir_enum_member ?(member_name = "NONE") ?(member_value = 0)
    ?(c_identifier = "TEST_NONE") ?member_doc () =
  {
    member_name;
    member_value;
    c_identifier;
    member_doc;
    member_version = None;
    member_os = None;
  }

(** [make_gir_enum ?enum_name ?enum_c_type ?members ?functions ?enum_doc
     ?enum_version ()] builds a [gir_enum]. *)
let make_gir_enum ?(enum_name = "TestEnum") ?(enum_c_type = "TestEnum")
    ?(members = []) ?(functions = []) ?enum_doc ?enum_version () =
  {
    enum_name;
    enum_c_type;
    members;
    functions;
    enum_doc;
    enum_version;
    enum_os = None;
  }

(** [make_gir_bitfield_member ?flag_name ?flag_value ?flag_c_identifier
     ?flag_doc ()] builds a [gir_bitfield_member]. *)
let make_gir_bitfield_member ?(flag_name = "NONE") ?(flag_value = 0)
    ?(flag_c_identifier = "TEST_NONE") ?flag_doc () =
  {
    flag_name;
    flag_value;
    flag_c_identifier;
    flag_doc;
    flag_version = None;
    flag_os = None;
  }

(** [make_gir_bitfield ?bitfield_name ?bitfield_c_type ?flags ?bitfield_doc
     ?bitfield_version ()] builds a [gir_bitfield]. *)
let make_gir_bitfield ?(bitfield_name = "TestFlags")
    ?(bitfield_c_type = "TestFlags") ?(flags = []) ?bitfield_doc
    ?bitfield_version () =
  {
    bitfield_name;
    bitfield_c_type;
    flags;
    bitfield_doc;
    bitfield_version;
    bitfield_os = None;
  }

(** [make_gir_constant ?constant_name ?constant_c_type ?value ?value_type
     ?constant_doc ?version ?introspectable ()] builds a [gir_constant]. *)
let make_gir_constant ?(constant_name = "TestConstant")
    ?(constant_c_type = "TEST_CONSTANT") ?(value = "0")
    ?(value_type = make_gir_type ~name:"gint" ~c_type:"gint" ()) ?constant_doc
    ?version ?(introspectable = true) () =
  {
    constant_name;
    constant_c_type;
    value;
    value_type;
    constant_doc;
    version;
    os = None;
    introspectable;
  }

(** [make_gir_class ?class_name ?c_type ?parent ?implements ?introspectable
     ?constructors ?methods ?properties ?signals ?class_doc ?version ()] builds
    a [gir_class]. *)
let make_gir_class ?(class_name = "TestClass") ?(c_type = "TestClass") ?parent
    ?(implements = []) ?(introspectable = true) ?(constructors = [])
    ?(methods = []) ?(properties = []) ?(signals = []) ?class_doc ?version () =
  {
    class_name;
    c_type;
    parent;
    implements;
    introspectable;
    constructors;
    methods;
    properties;
    signals;
    class_doc;
    version;
    os = None;
  }

(** [make_gir_interface ?interface_name ?c_type ?c_symbol_prefix ?glib_type_name
     ?glib_get_type ?prerequisites ?introspectable ?methods ?properties ?signals
     ?interface_doc ?version ()] builds a [gir_interface]. *)
let make_gir_interface ?(interface_name = "TestInterface")
    ?(c_type = "TestInterface") ?(c_symbol_prefix = "test_interface")
    ?(glib_type_name = None) ?(glib_get_type = None) ?(prerequisites = [])
    ?(introspectable = true) ?(methods = []) ?(properties = []) ?(signals = [])
    ?interface_doc ?version () =
  {
    interface_name;
    c_type;
    c_symbol_prefix;
    glib_type_name;
    glib_get_type;
    prerequisites;
    introspectable;
    methods;
    properties;
    signals;
    interface_doc;
    version;
    os = None;
  }

(** [make_gir_namespace ?namespace_name ?namespace_version
     ?namespace_shared_library ?namespace_c_identifier_prefixes
     ?namespace_c_symbol_prefixes ()] builds a [gir_namespace]. *)
let make_gir_namespace ?(namespace_name = "Test") ?(namespace_version = "1.0")
    ?(namespace_shared_library = "libtest.so")
    ?(namespace_c_identifier_prefixes = "Test")
    ?(namespace_c_symbol_prefixes = "test") () =
  {
    namespace_name;
    namespace_version;
    namespace_shared_library;
    namespace_c_identifier_prefixes;
    namespace_c_symbol_prefixes;
  }

(** [make_gir_repository ?repository_includes ?repository_c_includes
     ?repository_packages ()] builds a [gir_repository]. *)
let make_gir_repository ?(repository_includes = [])
    ?(repository_c_includes = []) ?(repository_packages = []) () =
  { repository_includes; repository_c_includes; repository_packages }

(** [make_cross_reference_type ?parent kind] builds a [cross_reference_type]
    from the polymorphic-variant [kind]. *)
let make_cross_reference_type ?parent = function
  | `Class -> Crt_Class { parent; implements = [] }
  | `Interface -> Crt_Interface
  | `Record opaque -> Crt_Record { opaque; get_type_func = None }
  | `Enum -> Crt_Enum
  | `Bitfield -> Crt_Bitfield
  | `Constant -> Crt_Constant

(** [make_cross_reference_entity ?cr_name ?cr_type ?cr_c_type ()] builds a
    [cross_reference_entity]. *)
let make_cross_reference_entity ?(cr_name = "TestEntity")
    ?(cr_type = Crt_Interface) ?(cr_c_type = "TestEntity") () =
  { cr_name; cr_type; cr_c_type }

(** [make_cross_reference_namespace ?cr_namespace_name ?cr_namespace_packages
     ?cr_namespace_includes ?cr_namespace_c_includes ?cr_entities ()] builds a
    [cross_reference_namespace]. *)
let make_cross_reference_namespace ?(cr_namespace_name = "Test")
    ?(cr_namespace_packages = []) ?(cr_namespace_includes = [])
    ?(cr_namespace_c_includes = []) ?(cr_entities = []) () =
  {
    cr_namespace_name;
    cr_namespace_packages;
    cr_namespace_includes;
    cr_namespace_c_includes;
    cr_entities;
  }

(** [make_cross_reference_map pairs] builds a [StringMap] of cross-namespace
    references from an association list of [(namespace_name, ncr)] pairs.
    Intended to be used with [Helpers.make_ncr]:

    {[
    make_cross_reference_map
      [
        Helpers.make_ncr "Gdk" gdk_entities;
        Helpers.make_ncr "cairo" cairo_entities;
      ]
    ]} *)
let make_cross_reference_map pairs =
  List.fold_left
    (fun acc (name, ncr) -> StringMap.add name ncr acc)
    StringMap.empty pairs

(** [make_generation_context ?namespace ?repository ?classes ?interfaces ?enums
     ?bitfields ?records ?constants ?module_groups ?current_cycle_classes
     ?cross_references ()] builds a [generation_context]. *)
let make_generation_context ?(namespace = make_gir_namespace ())
    ?(repository = make_gir_repository ()) ?(classes = []) ?(interfaces = [])
    ?(enums = []) ?(bitfields = []) ?(records = []) ?(constants = [])
    ?module_groups ?(current_cycle_classes = [])
    ?(cross_references = StringMap.empty) () =
  let module_groups_table =
    match module_groups with
    | None -> Hashtbl.create 0
    | Some items ->
        let ht = Hashtbl.create (List.length items) in
        List.iter (fun (k, v) -> Hashtbl.add ht k v) items;
        ht
  in
  {
    namespace;
    repository;
    classes;
    interfaces;
    enums;
    bitfields;
    records;
    constants;
    module_groups = module_groups_table;
    current_cycle_classes;
    cross_references;
  }

(** The [void] GIR type. *)
let void_type = make_gir_type ~name:"none" ~c_type:"void" ()

(** The [utf8] GIR type ([const gchar*]). *)
let utf8_type = make_gir_type ~name:"utf8" ~c_type:"const gchar*" ()

(** The [gint] GIR type. *)
let gint_type = make_gir_type ~name:"gint" ~c_type:"gint" ()

(** The [guint] GIR type. *)
let guint_type = make_gir_type ~name:"guint" ~c_type:"guint" ()

(** The [gdouble] GIR type. *)
let gdouble_type = make_gir_type ~name:"gdouble" ~c_type:"gdouble" ()

(** The [gboolean] GIR type. *)
let gboolean_type = make_gir_type ~name:"gboolean" ~c_type:"gboolean" ()

(** [make_widget_type ?nullable ()] builds the [GtkWidget] GIR type. *)
let make_widget_type ?(nullable = false) () =
  make_gir_type ~name:"GtkWidget" ~c_type:"GtkWidget*" ~nullable ()

(* ========================================================================= *)
(* Convenience Helper Factories for Common Test Patterns *)
(* ========================================================================= *)

(* Common object types *)

(** The non-nullable [GtkWidget] GIR type. *)
let widget_type = make_widget_type ()

(** The nullable [utf8] GIR type. *)
let string_option_type =
  make_gir_type ~name:"utf8" ~c_type:"const gchar*" ~nullable:true ()

(* Quick method factories for common return types *)

(** [make_void_method ~method_name ~c_identifier ?parameters ?throws ?version
     ()] builds a method returning [void]. *)
let make_void_method ~method_name ~c_identifier ?parameters ?throws ?version ()
    =
  make_gir_method ~method_name ~c_identifier ~return_type:void_type ?parameters
    ?throws ?version ()

(** [make_string_method ~method_name ~c_identifier ?parameters ?throws ?version
     ()] builds a method returning [utf8]. *)
let make_string_method ~method_name ~c_identifier ?parameters ?throws ?version
    () =
  make_gir_method ~method_name ~c_identifier ~return_type:utf8_type ?parameters
    ?throws ?version ()

(** [make_int_method ~method_name ~c_identifier ?parameters ?throws ?version ()]
    builds a method returning [gint]. *)
let make_int_method ~method_name ~c_identifier ?parameters ?throws ?version () =
  make_gir_method ~method_name ~c_identifier ~return_type:gint_type ?parameters
    ?throws ?version ()

(* Quick parameter factories *)

(** [make_string_param ~param_name ?nullable ()] builds a [utf8] parameter. *)
let make_string_param ~param_name ?nullable () =
  make_gir_param ~param_name ~param_type:utf8_type ?nullable ()

(** [make_int_param ~param_name ?nullable ()] builds a [gint] parameter. *)
let make_int_param ~param_name ?nullable () =
  make_gir_param ~param_name ~param_type:gint_type ?nullable ()

(** [make_bool_param ~param_name ?nullable ()] builds a [gboolean] parameter. *)
let make_bool_param ~param_name ?nullable () =
  make_gir_param ~param_name ~param_type:gboolean_type ?nullable ()

let make_object_param ~param_name ~type_name ~c_type ?nullable () =
  let param_type = make_gir_type ~name:type_name ~c_type ?nullable () in
  make_gir_param ~param_name ~param_type ()

(** [make_widget_param ~param_name ?nullable ()] builds a [GtkWidget] parameter.
*)
let make_widget_param ~param_name ?nullable () =
  make_object_param ~param_name ~type_name:"Widget" ~c_type:"GtkWidget*"
    ?nullable ()

(* Signal factories *)

(** [make_void_signal ~signal_name ?sig_parameters ?version ()] builds a signal
    returning [void]. *)
let make_void_signal ~signal_name ?sig_parameters ?version () =
  make_gir_signal ~signal_name ~return_type:void_type ?sig_parameters ?version
    ()
