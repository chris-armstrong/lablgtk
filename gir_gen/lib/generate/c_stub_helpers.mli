(** C Stub Code Generation - Shared Helpers This module provides organized C
    stub code generation functionality. Internal modules (Type_analysis,
    Array_conv, GValue, Code_gen, Forward_decl) are hidden to maintain clean
    module boundaries. *)

val include_header_for_namespace : string -> string
(** Get C include header for a namespace. *)

type property_gvalue_info =
  C_stub_type_analysis.Type_analysis.property_gvalue_info
(** Property type analysis. Fields: base_type, base_lower, has_pointer,
    pointer_like, record_info, class_info, is_enum, is_bitfield,
    stack_allocated. *)

val get_c_type_str : ctx:Types.generation_context -> Types.gir_type -> string
(** [get_c_type_str ~ctx gir_type] retrieves the C type string representation
    for a GIR type. Returns the [c_type] directly if present, otherwise consults
    the type mapping context. Falls back to ["void"] if no mapping is found.
    Shared by the method and property C-stub generators. *)

val analyze_property_type :
  ctx:Types.generation_context -> Types.gir_type -> property_gvalue_info
(** Analyze property type and extract GValue conversion information *)

val is_copy_method : Types.gir_method -> bool
(** Check if a method is a copy method that should be skipped in bindings *)

val is_free_method : Types.gir_method -> bool
(** Check if a method is a free method that should be skipped in bindings *)

val is_copy_or_free : Types.gir_method -> bool
(** Check if a method is a copy or free method that should be skipped in
    bindings *)

val fold_mapi :
  f:(int -> 'a -> 'b -> 'a * 'c) -> init:'a -> 'b list -> 'a * 'c list
(** Fold with map and index - combines fold_left_map with index tracking *)

val list_contains : value:string -> string list -> bool
(** Check if list contains a value (case-insensitive comparison for type names)
*)

val is_string_type : string option -> bool
(** Check if a C type is a string type *)

val generate_array_ml_to_c :
  ctx:Types.generation_context ->
  var:string ->
  array_info:Types.gir_array ->
  element_mapping:Types.type_mapping ->
  element_c_type:string ->
  transfer_ownership:Types.transfer_ownership ->
  nullable:bool ->
  string * string * string * string
(** Array conversion - generate conversion code for OCaml array to C array.
    Returns (conversion_code, c_array_var, length_var, cleanup_code) *)

val generate_array_c_to_ml :
  ctx:Types.generation_context ->
  var:string ->
  array_info:Types.gir_array ->
  length_expr:string option ->
  element_c_type:string ->
  transfer_ownership:Types.transfer_ownership ->
  ?nullable:bool ->
  unit ->
  string * string * string
(** Array conversion - generate conversion code for C array to OCaml array. When
    [nullable] is true (default false) the C pointer may be NULL and the
    generated code wraps the result in [Val_none]/[Val_some]. Returns
    (conversion_code, ml_array_var_or_opt_var, cleanup_code) *)

val is_string_array : Types.gir_array -> bool
(** Check if an array contains string elements *)

val generate_gvalue_getter_assignment :
  ml_name:string ->
  prop:Types.gir_property ->
  c_type_name:string ->
  prop_info:property_gvalue_info ->
  string
(** GValue getter/setter generation *)

val generate_gvalue_setter_assignment :
  ml_name:string -> prop_info:property_gvalue_info -> string

val generate_c_file_header :
  ctx:Types.generation_context -> ?class_name:string -> unit -> string
(** Code generation utilities *)

val base_c_type_of : string -> string
(** Extract base C type by removing trailing pointer *)

val build_return_statement :
  throws:bool ->
  string option (** Primary return value expression *) ->
  string list (** Out parameter conversions *) ->
  string
(** Build return statement code based on return type and out parameters. Handles
    both throwing and non-throwing methods. *)

val generate_constructors :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  buf:Buffer.t ->
  generator:
    (ctx:Types.generation_context ->
    c_type:string ->
    class_name:string ->
    Types.gir_constructor ->
    string) ->
  Types.gir_constructor list ->
  unit
(** Generate C code for constructors by iterating and filtering. Applies
    [Filtering.should_generate_constructor] filter and appends generated code to
    the buffer. *)

val generate_methods :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  buf:Buffer.t ->
  generator:
    (ctx:Types.generation_context ->
    c_type:string ->
    Types.gir_method ->
    string ->
    string) ->
  entity_kind:Filtering.entity_kind ->
  Types.gir_method list ->
  unit
(** Generate C code for methods by iterating and filtering. Applies
    [Filtering.should_skip_method_binding] with the supplied [entity_kind] so
    the record copy/free/unref filter is folded into the same answer as varargs
    / unsupported arrays / non-introspectable. Methods are processed in reverse
    order (List.rev). *)

val default_type_mapping : Types.type_mapping
(** Default type mapping for when no mapping is found *)

type param_acc = {
  ocaml_idx : int;
  decls : Buffer.t;
  args : string list;
  cleanups : string list;
}
(** Accumulator for parameter processing - kept at top level for record field
    access *)

val nullable_c_to_ml_expr :
  ctx:Types.generation_context ->
  var:string ->
  gir_type:Types.gir_type ->
  mapping:Types.type_mapping ->
  ?direction:Types.gir_direction ->
  unit ->
  string
(** Generate C-to-ML conversion expression handling nullable types. out
    parameters that are record types are stack allocated, so we need to pass by
    reference to their Val_x function, which will copy them into the OCaml heap
*)

val nullable_ml_to_c_expr :
  var:string -> gir_type:Types.gir_type -> mapping:Types.type_mapping -> string
(** Generate ML-to-C conversion expression handling nullable types. Check for
    string types with transfer-ownership="full" - need to copy to mutable buffer
*)

val generate_forward_decl_section :
  buf:Buffer.t ->
  items:'a list ->
  section_comment:string ->
  generate_one:('a -> unit) ->
  ?deduplicate:bool ->
  unit ->
  unit
(** Forward declaration helper - generate a section of forward declarations.
    Common pattern across record, class, enum, and bitfield modules.

    Parameters:
    - buf: Buffer to append declarations to
    - items: List of items to generate declarations for
    - section_comment: Comment header for this section
    - generate_one: Function to generate declarations for a single item
    - deduplicate: Whether to track seen types with Hashtbl (default: true) *)

(** {1 Version Guard Support} *)

val namespace_display_name : string -> string
(** Get display name for namespace for use in failwith messages *)

val format_version_for_message : Version_guard.version -> string
(** Format version string for failwith messages *)

val emit_fallback_constructor_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  c_identifier:string ->
  version:Version_guard.version ->
  Types.gir_constructor ->
  string
(** Emit a fallback stub for a constructor when class version check fails *)

val emit_fallback_method_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  c_identifier:string ->
  version:Version_guard.version ->
  Types.gir_method ->
  string
(** Emit a fallback stub for a method when class version check fails *)

val emit_fallback_property_getter_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  version:Version_guard.version ->
  Types.gir_property ->
  string
(** Emit a fallback stub for a property getter when class version check fails *)

val emit_fallback_property_setter_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  version:Version_guard.version ->
  Types.gir_property ->
  string
(** Emit a fallback stub for a property setter when class version check fails *)

val emit_fallback_record_method_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  version:Version_guard.version ->
  Types.gir_method ->
  string
(** Emit a fallback stub for a record method when class version check fails *)

val emit_with_member_guard :
  ctx:Types.generation_context ->
  ?version_namespace:string option ->
  class_version:string option ->
  member_version:string option ->
  fallback:(Version_guard.version -> string) ->
  stub:string ->
  Buffer.t ->
  unit
(** Wrap a generated stub in a member-level version guard when [resolve_guard]
    returns [Member_guard]. [fallback v] is called with the member version to
    produce the [#else] stub. Falls through to plain emit on parse errors or
    when no guard is needed. *)

(** {1 OS Guard Support} *)

val os_to_c_guard_open : Os_filter.t -> string
(** Map an [Os_filter.t] to the opening C preprocessor guard line. *)

val os_to_c_guard_close : Os_filter.t -> string
(** Map an [Os_filter.t] to the closing C preprocessor guard line. *)

val os_display_name : Os_filter.t -> string
(** Human-readable display name for an [Os_filter.t] (for failwith messages). *)

val emit_with_os_guard :
  os:Os_filter.t option ->
  failwith_stub:string ->
  stub:string ->
  Buffer.t ->
  unit
(** Wrap a generated stub in an OS guard. [os]: OS filter, or [None] to emit
    stub as-is. [failwith_stub]: content for the [#else] branch. [stub]: the
    actual implementation in the [#if] branch. *)

val emit_os_fallback_constructor_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  c_identifier:string ->
  os:Os_filter.t ->
  Types.gir_constructor ->
  string
(** Emit a fallback constructor stub for the [#else] branch of an OS guard. *)

val emit_os_fallback_method_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  c_identifier:string ->
  os:Os_filter.t ->
  Types.gir_method ->
  string
(** Emit a fallback method stub for the [#else] branch of an OS guard. *)

val emit_os_fallback_property_getter_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  os:Os_filter.t ->
  Types.gir_property ->
  string
(** Emit a fallback property getter stub for the [#else] branch of an OS guard.
*)

val emit_os_fallback_property_setter_stub :
  ctx:Types.generation_context ->
  c_type:string ->
  class_name:string ->
  ml_name:string ->
  os:Os_filter.t ->
  Types.gir_property ->
  string
(** Emit a fallback property setter stub for the [#else] branch of an OS guard.
*)

val generate_multi_param_function :
  ml_name:string ->
  params:string list ->
  param_names:string list ->
  string ->
  string
(** [generate_multi_param_function ~ml_name ~params ~param_names body_code]
    generates both native and bytecode C wrapper variants for functions with
    more than 5 parameters (native uses [CAMLparam5] + [CAMLxparamN] chunks;
    bytecode forwards [argv] to the native variant). Shared by the method and
    constructor C-stub generators to avoid the byte-for-byte duplication that
    previously lived in both modules. *)
