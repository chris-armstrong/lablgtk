(* Exclusion lists and filtering logic for GIR Code Generator *)

val should_skip_method :
  ctx:Types.generation_context -> Types.gir_method -> bool
(** [should_skip_method ~ctx meth] returns [true] when [meth]'s return type or
    any parameter type cannot be resolved to a type mapping. *)

val should_skip_constructor :
  ctx:Types.generation_context -> Types.gir_constructor -> bool
(** [should_skip_constructor ~ctx ctor] returns [true] when any parameter type
    of [ctor] cannot be resolved to a type mapping. *)
