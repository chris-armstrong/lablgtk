(* Layer 1 helpers - shared utilities for OCaml interface generation. *)

(** Mode for code generation: interface (.mli) or implementation (.ml). *)
type output_mode =
  | Interface  (** Generate an .mli interface file *)
  | Implementation  (** Generate an .ml implementation file *)

val detect_class_hierarchy_names :
  ctx:Types.generation_context ->
  class_name:string ->
  parent_chain:string list ->
  unit ->
  string * string
(** Return the normalized class name and the polymorphic-variant hierarchy type
    [[`tag | ...] Gobject.obj] for the class and its parent chain. *)

val print_indent : string -> Buffer.t -> unit
(** Indent [contents] by two spaces into [buf], preserving empty lines. *)

val combine_return_and_out_types : string -> string list -> string
(** Combine a return type with output-parameter types into a single OCaml type
    expression. *)

val map_gir_type_to_ocaml :
  ctx:Types.generation_context ->
  class_name:string ->
  gir_type:Types.gir_type ->
  is_nullable:bool ->
  string
(** Map a GIR type to its OCaml representation, simplifying self-references to
    [class_name]. Returns "unit" for unknown types, with a warning to stderr. *)

val map_constructor_param :
  ctx:Types.generation_context -> class_name:string -> Types.gir_param -> string
(** Map a constructor parameter to its OCaml type representation. *)

val convert_method_param_to_ocaml_type :
  ctx:Types.generation_context ->
  class_name:string ->
  Types.gir_param ->
  string option
(** Map an input method parameter to its OCaml type; [None] for out parameters.
*)

val convert_out_param_to_ocaml_type :
  ctx:Types.generation_context ->
  class_name:string ->
  Types.gir_param ->
  string option
(** Map an out parameter to its OCaml type; [None] for in/in-out parameters. *)

val format_external :
  ocaml_name:string ->
  signature:string ->
  ml_name:string ->
  param_count:int ->
  string
(** Format an [external] declaration, splitting native and bytecode variants
    when [param_count] exceeds 5. *)

val property_naming :
  prop:Types.gir_property -> type_mapping:Types.type_mapping -> string * string
(** Return the snake-cased property name and its OCaml type expression
    (option-wrapped when nullable). *)
