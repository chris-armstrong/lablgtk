(** OS guard stub emission for generated C code.

    Maps [Os_filter.t] values to C preprocessor guard lines and emits the
    OS-fallback stubs that raise [caml_failwith] in the [#else] branch. *)

val os_to_c_guard_open : Os_filter.t -> string
(** Map an [Os_filter.t] to the opening C preprocessor guard line. *)

val os_to_c_guard_close : Os_filter.t -> string
(** Map an [Os_filter.t] to the closing C preprocessor guard line. *)

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
