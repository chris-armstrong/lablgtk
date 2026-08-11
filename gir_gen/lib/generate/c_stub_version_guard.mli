(** Version guard stub emission for generated C code.

    Emits the C fallback stubs that raise [caml_failwith] when a class-level
    version check fails, and wraps generated stubs in member-level
    [#if]/[#else]/[#endif] guards driven by [Version_guard.resolve_guard]. *)

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
