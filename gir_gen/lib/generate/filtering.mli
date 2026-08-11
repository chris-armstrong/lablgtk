(** Shared filtering helpers for GIR generators. *)

open Types

val should_generate_property :
  ctx:generation_context ->
  class_name:'a ->
  methods:gir_method list ->
  gir_property ->
  bool
(** Check if a property should be generated. *)

val property_method_names :
  ctx:generation_context ->
  class_name:string ->
  methods:gir_method list ->
  gir_property list ->
  string list
(** Get property method names. *)

val property_base_names :
  ctx:generation_context ->
  class_name:string ->
  methods:gir_method list ->
  gir_property list ->
  string list
(** Get property base names. *)

(** Discriminator for the entity flavour a method belongs to. Threaded as a
    non-optional argument through every method-emission entry point so the
    record-specific copy/free/unref filter can be folded into one predicate
    instead of multiple ad-hoc list-level pre-filters. *)
type entity_kind = Class | Interface | Record

val entity_kind_of_entity : entity -> entity_kind
(** Convenience: project a [Types.entity] to its kind. *)

val should_skip_method_binding :
  ctx:generation_context -> entity_kind:entity_kind -> gir_method -> bool
(** Check if a method should be skipped. [entity_kind] tells the predicate which
    entity flavour the method belongs to. For [Record] entities the predicate
    additionally returns true for copy/free/unref methods, since the gir_record
    custom-block finalizer already owns the wrapped pointer and exposing those
    would race the GC. *)

val is_copy_method : gir_method -> bool
(** True if the method's name or c-identifier looks like a record copy
    constructor (e.g. [gtk_tree_path_copy], [pango_attribute_copy]). *)

val is_free_method : gir_method -> bool
(** True if the method's name or c-identifier looks like a record destructor
    (matches [free] / [_free] / [unref] / [_unref]). *)

val is_copy_or_free : gir_method -> bool
(** True if the method is a record copy or destructor. Equivalent to
    [is_copy_method m || is_free_method m]. *)

val should_generate_constructor :
  ctx:generation_context -> gir_constructor -> bool
(** Check if a constructor should be generated. *)

val should_generate_record : gir_record -> bool
(** Check if a record should be generated. For example, private records are
    excluded from generation. *)

val should_generate_class : gir_class -> bool
(** Check if a class should be generated. *)

val should_generate_interface : gir_interface -> bool
(** Check if an interface should be generated. *)

val is_string_type : string option -> bool
(** Check if a C type is a string type. *)

val is_string_array : gir_array -> bool
(** Check if an array contains string elements. *)
