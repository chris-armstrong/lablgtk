(** C stub code generation - shared primitives.

    Provides the C stub generation primitives shared across the stub generators
    and the guard fallback emitters. Concern-specific generation lives in
    dedicated modules ([C_stub_array_conv], [C_stub_gvalue],
    [C_stub_forward_decl], [C_stub_multi_param], [C_stub_version_guard],
    [C_stub_os_guard], [C_stub_type_analysis]). *)

val include_header_for_namespace : string -> string
(** Get C include header for a namespace. *)

val get_c_type_str : ctx:Types.generation_context -> Types.gir_type -> string
(** [get_c_type_str ~ctx gir_type] retrieves the C type string representation
    for a GIR type. Returns the [c_type] directly if present, otherwise consults
    the type mapping context. Falls back to ["void"] if no mapping is found.
    Shared by the method and property C-stub generators. *)

val is_copy_method : Types.gir_method -> bool
(** Check if a method is a copy method that should be skipped in bindings *)

val fold_mapi :
  f:(int -> 'a -> 'b -> 'a * 'c) -> init:'a -> 'b list -> 'a * 'c list
(** Fold with map and index - combines fold_left_map with index tracking *)

val generate_c_file_header :
  ctx:Types.generation_context -> ?class_name:string -> unit -> string
(** Emit the standard header of a generated C stub file: the
    [GENERATED CODE - DO NOT EDIT] banner, a class or namespace comment, the
    namespace include, the caml includes, [wrappers.h], and (for GTK)
    [converters.h]. *)

val base_c_type_of : string -> string
(** Extract base C type by removing trailing pointer *)

val build_return_statement :
  throws:bool ->
  ml_primary:string option ->
  out_conversions:string list ->
  string
(** [build_return_statement ~throws ~ml_primary ~out_conversions] builds the C
    [return] statement for a stub. [ml_primary] is the primary return value
    expression ([None] when the method returns unit); [out_conversions] are the
    out-parameter conversion statements to thread through the return. Handles
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
  ocaml_idx : int;  (** Next OCaml argument index to allocate. *)
  decls : Buffer.t;  (** Accumulated C declarations for parameters. *)
  args : string list;
      (** Accumulated argument expressions passed to the C call. *)
  cleanups : string list;  (** Cleanup statements to run after the C call. *)
}
(** Accumulator threaded through parameter processing. *)

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

val emit_failwith_stub_core :
  ml_name:string ->
  params:string list ->
  param_names:string list ->
  param_count_for_caml:int ->
  failwith_msg:string ->
  string
(** Build a CAMLprim failwith stub. [params] and [param_names] must correspond.
    [param_count_for_caml] controls how many names appear in CAMLparam. Shared
    by the version-guard and OS-guard fallback stub emitters. *)

val make_constructor_params : int -> string list * string list
(** Build params and param_names for a constructor with [n] parameters. *)

val make_method_params : int -> string list * string list
(** Build params and param_names for a method with [n] in-parameters plus self.
*)
