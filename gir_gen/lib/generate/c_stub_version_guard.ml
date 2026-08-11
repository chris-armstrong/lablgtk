(* Version guard stub emission for generated C code. *)

open Containers
open StdLabels
open Types

(** Get the display name for a namespace for use in failwith messages *)
let namespace_display_name namespace_name =
  match namespace_name with
  | "Gtk" -> "GTK"
  | "Gdk" -> "GTK"
  | "Gsk" -> "GTK"
  | "Pango" -> "Pango"
  | "PangoCairo" -> "Pango"
  | "GdkPixbuf" -> "GdkPixbuf"
  | "Gio" -> "GLib"
  | "Graphene" -> "Graphene"
  | "Cairo" -> "Cairo"
  | other -> other

(** Format version string for failwith messages: "M.m" (omit micro if 0) *)
let format_version_for_message (version : Version_guard.version) =
  if version.micro = 0 then Fmt.str "%d.%d" version.major version.minor
  else Fmt.str "%d.%d.%d" version.major version.minor version.micro

(** Emit a class-level fallback stub for a constructor. The stub accepts the
    same parameters and raises caml_failwith with the appropriate message. *)
let emit_fallback_constructor_stub ~ctx ~c_type:_ ~class_name ~ml_name
    ~c_identifier:_ ~version (ctor : gir_constructor) =
  let param_count = List.length ctor.ctor_parameters in
  let params, param_names =
    C_stub_helpers.make_constructor_params param_count
  in
  let param_count_for_caml = if param_count = 0 then 1 else param_count in
  let display_ns = namespace_display_name ctx.namespace.namespace_name in
  let failwith_msg =
    Fmt.str "%s requires %s >= %s" class_name display_ns
      (format_version_for_message version)
  in
  C_stub_helpers.emit_failwith_stub_core ~ml_name ~params ~param_names
    ~param_count_for_caml ~failwith_msg

(** Emit a class-level fallback stub for a method. *)
let emit_fallback_method_stub ~ctx ~c_type:_ ~class_name ~ml_name
    ~c_identifier:_ ~version (meth : gir_method) =
  let in_params =
    List.filter
      ~f:(fun p -> match p.direction with Out -> false | In | InOut -> true)
      meth.parameters
  in
  let param_count = 1 + List.length in_params in
  let params, param_names =
    C_stub_helpers.make_method_params (List.length in_params)
  in
  let param_count_for_caml = if param_count = 0 then 1 else min param_count 5 in
  let display_ns = namespace_display_name ctx.namespace.namespace_name in
  let failwith_msg =
    Fmt.str "%s requires %s >= %s" class_name display_ns
      (format_version_for_message version)
  in
  C_stub_helpers.emit_failwith_stub_core ~ml_name ~params ~param_names
    ~param_count_for_caml ~failwith_msg

(** Emit a class-level fallback stub for a property getter. *)
let emit_fallback_property_getter_stub ~ctx ~c_type:_ ~class_name ~ml_name
    ~version (_prop : gir_property) =
  let display_ns = namespace_display_name ctx.namespace.namespace_name in
  let failwith_msg =
    Fmt.str "%s requires %s >= %s" class_name display_ns
      (format_version_for_message version)
  in
  C_stub_helpers.emit_failwith_stub_core ~ml_name ~params:[ "value self" ]
    ~param_names:[ "self" ] ~param_count_for_caml:1 ~failwith_msg

(** Emit a class-level fallback stub for a property setter. *)
let emit_fallback_property_setter_stub ~ctx ~c_type:_ ~class_name ~ml_name
    ~version (_prop : gir_property) =
  let display_ns = namespace_display_name ctx.namespace.namespace_name in
  let failwith_msg =
    Fmt.str "%s requires %s >= %s" class_name display_ns
      (format_version_for_message version)
  in
  C_stub_helpers.emit_failwith_stub_core ~ml_name
    ~params:[ "value self"; "value arg1" ]
    ~param_names:[ "self"; "arg1" ] ~param_count_for_caml:2 ~failwith_msg

(** Emit a class-level fallback stub for a record method. *)
let emit_fallback_record_method_stub ~ctx ~c_type:_ ~class_name ~ml_name
    ~version (meth : gir_method) =
  let in_params =
    List.filter
      ~f:(fun p -> match p.direction with Out -> false | In | InOut -> true)
      meth.parameters
  in
  let param_count = 1 + List.length in_params in
  let params, param_names =
    C_stub_helpers.make_method_params (List.length in_params)
  in
  let param_count_for_caml = if param_count = 0 then 1 else min param_count 5 in
  let display_ns = namespace_display_name ctx.namespace.namespace_name in
  let failwith_msg =
    Fmt.str "%s requires %s >= %s" class_name display_ns
      (format_version_for_message version)
  in
  C_stub_helpers.emit_failwith_stub_core ~ml_name ~params ~param_names
    ~param_count_for_caml ~failwith_msg

(** Wrap a generated stub in a member-level version guard when [resolve_guard]
    returns [Member_guard]. [fallback v] is called with the member version to
    produce the [#else] stub. Falls through to plain emit on parse errors or
    when no guard is needed (e.g. [No_guard] for same-version members). *)
let emit_with_member_guard ~ctx ?(version_namespace : string option = None)
    ~class_version ~member_version ~fallback ~stub buf =
  let guard_ns =
    match version_namespace with
    | Some ns -> ns
    | None -> ctx.namespace.namespace_name
  in
  match Version_guard.resolve_guard ~class_version ~member_version with
  | Ok (Version_guard.Member_guard v) -> (
      match Version_guard.emit_c_guard guard_ns v ~is_opening:true with
      | Ok guard_if -> (
          Buffer.add_char buf '\n';
          Buffer.add_string buf guard_if;
          Buffer.add_char buf '\n';
          Buffer.add_string buf stub;
          Buffer.add_char buf '\n';
          Buffer.add_string buf Version_guard.c_guard_else;
          Buffer.add_char buf '\n';
          Buffer.add_string buf (fallback v);
          match Version_guard.emit_c_guard guard_ns v ~is_opening:false with
          | Ok guard_endif -> Buffer.add_string buf (guard_endif ^ "\n")
          | Error _ -> Buffer.add_string buf "#endif\n")
      | Error _ -> Buffer.add_string buf stub)
  | _ -> Buffer.add_string buf stub
