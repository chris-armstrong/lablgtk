(* Exclusion lists and filtering logic for GIR Code Generator *)

val should_skip_method :
  find_type_mapping:(Types.gir_type -> Types.type_mapping option) ->
  Types.gir_method ->
  bool
(** Decide whether a method should be skipped because its return type or any
    parameter type cannot be resolved to a type mapping.

    @param find_type_mapping resolves a GIR type to a type mapping
    @param meth the method to check
    @return [true] if the method has an unknown return or parameter type *)

val should_skip_constructor :
  find_type_mapping:(Types.gir_type -> Types.type_mapping option) ->
  Types.gir_constructor ->
  bool
(** Decide whether a constructor should be skipped because any parameter type
    cannot be resolved to a type mapping.

    @param find_type_mapping resolves a GIR type to a type mapping
    @param ctor the constructor to check
    @return [true] if the constructor has an unknown parameter type *)
