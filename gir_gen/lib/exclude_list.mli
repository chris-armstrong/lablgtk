(* Exclusion lists and filtering logic for GIR Code Generator *)

val should_skip_method :
  find_type_mapping:(Types.gir_type -> Types.type_mapping option) ->
  Types.gir_method ->
  bool
(** [should_skip_method ~find_type_mapping meth] returns [true] when [meth]'s
    return type or any parameter type cannot be resolved to a type mapping. *)

val should_skip_constructor :
  find_type_mapping:(Types.gir_type -> Types.type_mapping option) ->
  Types.gir_constructor ->
  bool
(** [should_skip_constructor ~find_type_mapping ctor] returns [true] when any
    parameter type of [ctor] cannot be resolved to a type mapping. *)
