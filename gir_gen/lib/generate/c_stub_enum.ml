(* C Stub Code Generation - Enum Support *)

(* Drop-in for [bprintf] that flushes to the buffer. [Format.fprintf]
   on a [formatter_of_buffer] does not auto-flush, so flush in [kfprintf]'s
   continuation. *)
let bprintf buf fmt =
  Format.kfprintf
    (fun fmtr -> Format.pp_print_flush fmtr ())
    (Format.formatter_of_buffer buf)
    fmt

open StdLabels
open Types

(** DEPRECATION NOTICE: External enum forward declarations removed

    As of Phase 2 (cross_namespace_phase2 plan), external enum forward
    declarations are no longer generated in this file. External enum
    declarations now come from included dependency headers (e.g., #include
    "gdk_decls.h").

    See: .opencode/plans/cross_namespace_phase2.json - Stage 2 See:
    architecture/todo/CROSS_NAMESPACE_PLAN.md - Section 2.2

    This function now only generates declarations for enums in the current
    namespace. *)

(** Generate forward declarations for enum converters.

    This function generates declarations only for enums in the current
    namespace. External enum declarations come from included headers via the
    library-specific <ns>_decls.h files as part of Phase 2 cross-namespace
    header refactoring.

    @param namespace_prefix
      The namespace prefix for the current library (e.g., "gtk_")
    @param gtk_enums List of local enums to generate declarations for
    @return String containing forward declarations for enum converters *)
let emit_version_guard_open buf ~namespace version_str =
  let ( let* ) = Result.bind in
  match
    let* version = Version_guard.parse_version version_str in
    Version_guard.emit_c_guard namespace version ~is_opening:true
  with
  | Error msg -> failwith msg
  | Ok guard -> Buffer.add_string buf (guard ^ "\n")

let generate_forward_decls ~namespace_prefix ~gtk_enums =
  let buf = Buffer.create 1024 in

  (* Add forward declarations for local namespace enum converters *)
  if List.length gtk_enums > 0 then begin
    Buffer.add_string buf "/* Forward declarations for enum converters */\n";
    List.iter
      ~f:(fun (enum : gir_enum) ->
        Option.iter
          (emit_version_guard_open buf ~namespace:namespace_prefix)
          enum.enum_version;
        bprintf buf "value Val_%s%s(%s val);\n" namespace_prefix enum.enum_name
          enum.enum_c_type;
        bprintf buf "%s %s%s_val(value val);\n" enum.enum_c_type
          namespace_prefix enum.enum_name;
        Option.iter
          (fun _ -> Buffer.add_string buf "#endif\n")
          enum.enum_version)
      gtk_enums;
    Buffer.add_string buf "\n"
  end;

  Buffer.contents buf
