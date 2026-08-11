(* OS guard stub emission for generated C code. *)

open Containers
open StdLabels
open Types

(** Map a single OS platform name to its C defined() expression. *)
let os_name_to_c_expr = function
  | "linux" -> "defined(__linux__)"
  | "macos" -> "(defined(__APPLE__) && defined(__MACH__))"
  | "freebsd" -> "defined(__FreeBSD__)"
  | "unix" -> "defined(G_OS_UNIX)"
  | "windows" -> "defined(_WIN32)"
  | os -> Fmt.str "defined(OS_%s)" (String.uppercase_ascii os)

(** Map an [Os_filter.t] to the opening C preprocessor guard line. *)
let os_to_c_guard_open = function
  | Os_filter.Os_only names ->
      let parts = List.map ~f:os_name_to_c_expr names in
      Fmt.str "#if %s" (String.concat ~sep:" || " parts)
  | Os_filter.Os_except names ->
      let parts =
        List.map ~f:(fun n -> Fmt.str "!(%s)" (os_name_to_c_expr n)) names
      in
      Fmt.str "#if %s" (String.concat ~sep:" && " parts)

(** Map an [Os_filter.t] to the closing C preprocessor guard line. *)
let os_to_c_guard_close = function
  | Os_filter.Os_only names ->
      Fmt.str "#endif /* %s */" (String.concat ~sep:" || " names)
  | Os_filter.Os_except names ->
      Fmt.str "#endif /* not %s */" (String.concat ~sep:", " names)

(** Human-readable display name for an [Os_filter.t] (used in failwith
    messages). *)
let os_display_name = function
  | Os_filter.Os_only [ "linux" ] -> "Linux"
  | Os_filter.Os_only [ "macos" ] -> "macOS"
  | Os_filter.Os_only [ "freebsd" ] -> "FreeBSD"
  | Os_filter.Os_only [ "unix" ] -> "Unix"
  | Os_filter.Os_only [ "windows" ] -> "Windows"
  | Os_filter.Os_only names -> String.concat ~sep:" or " names
  | Os_filter.Os_except names ->
      Fmt.str "non-%s" (String.concat ~sep:"/non-" names)

(** Wrap a generated stub in an OS guard. [os]: OS filter, or [None] to emit
    stub as-is. [failwith_stub]: string placed in the [#else] branch. [stub]:
    the actual implementation placed in the [#if] branch. *)
let emit_with_os_guard ~os ~failwith_stub ~stub buf =
  match os with
  | None -> Buffer.add_string buf stub
  | Some os_filter ->
      Buffer.add_char buf '\n';
      Buffer.add_string buf (os_to_c_guard_open os_filter);
      Buffer.add_char buf '\n';
      Buffer.add_string buf stub;
      Buffer.add_char buf '\n';
      Buffer.add_string buf "#else\n";
      Buffer.add_string buf failwith_stub;
      Buffer.add_char buf '\n';
      Buffer.add_string buf (os_to_c_guard_close os_filter);
      Buffer.add_char buf '\n'

(** Emit an OS-fallback constructor stub that raises [caml_failwith]. Used in
    the [#else] branch of an OS guard. *)
let emit_os_fallback_constructor_stub ~ctx:_ ~c_type:_ ~class_name ~ml_name
    ~c_identifier:_ ~os (ctor : gir_constructor) =
  let param_count = List.length ctor.ctor_parameters in
  let params, param_names =
    C_stub_helpers.make_constructor_params param_count
  in
  let param_count_for_caml = if param_count = 0 then 1 else param_count in
  let failwith_msg =
    Fmt.str "%s is only available on %s" class_name (os_display_name os)
  in
  C_stub_helpers.emit_failwith_stub_core ~ml_name ~params ~param_names
    ~param_count_for_caml ~failwith_msg

(** Emit an OS-fallback method stub that raises [caml_failwith]. *)
let emit_os_fallback_method_stub ~ctx:_ ~c_type:_ ~class_name ~ml_name
    ~c_identifier:_ ~os (meth : gir_method) =
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
  let failwith_msg =
    Fmt.str "%s is only available on %s" class_name (os_display_name os)
  in
  C_stub_helpers.emit_failwith_stub_core ~ml_name ~params ~param_names
    ~param_count_for_caml ~failwith_msg

(** Emit an OS-fallback property getter stub that raises [caml_failwith]. *)
let emit_os_fallback_property_getter_stub ~ctx:_ ~c_type:_ ~class_name ~ml_name
    ~os (_prop : gir_property) =
  let failwith_msg =
    Fmt.str "%s is only available on %s" class_name (os_display_name os)
  in
  C_stub_helpers.emit_failwith_stub_core ~ml_name ~params:[ "value self" ]
    ~param_names:[ "self" ] ~param_count_for_caml:1 ~failwith_msg

(** Emit an OS-fallback property setter stub that raises [caml_failwith]. *)
let emit_os_fallback_property_setter_stub ~ctx:_ ~c_type:_ ~class_name ~ml_name
    ~os (_prop : gir_property) =
  let failwith_msg =
    Fmt.str "%s is only available on %s" class_name (os_display_name os)
  in
  C_stub_helpers.emit_failwith_stub_core ~ml_name
    ~params:[ "value self"; "value arg1" ]
    ~param_names:[ "self"; "arg1" ] ~param_count_for_caml:2 ~failwith_msg
