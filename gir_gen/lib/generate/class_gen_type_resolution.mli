(* Class-specific type resolution (layer 2). *)

val resolve_layer2_class_ref :
  ctx:Types.generation_context ->
  current_layer2_module:StdLabels.String.t ->
  gir_type:Types.gir_type ->
  string option
(** Resolve a GIR type to its layer 2 class type reference (with [_t] suffix),
    qualified with the module prefix when the class lives in another module.
    Returns [None] when no mapping exists. *)

val resolve_layer2_class_name :
  ctx:Types.generation_context ->
  current_layer2_module:StdLabels.String.t ->
  gir_type:Types.gir_type ->
  string option
(** Like [resolve_layer2_class_ref] but returns the bare class name (without
    [_t] suffix), for use in [new] expressions. *)

val resolve_ocaml_type :
  ctx:Types.generation_context ->
  current_layer2_module:StdLabels.String.t ->
  gir_type:Types.gir_type ->
  string option
(** Resolve a GIR type to its OCaml type string, wrapped in [option] when the
    type is nullable. Returns [None] when no type mapping exists. *)
