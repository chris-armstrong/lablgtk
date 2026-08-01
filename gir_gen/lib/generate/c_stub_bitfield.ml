(* C Stub Code Generation - Bitfield Support *)

open Gen_buffer
open StdLabels
open Types

(** DEPRECATION NOTICE: External bitfield forward declarations removed

    As of Phase 2 (cross_namespace_phase2 plan), external bitfield forward
    declarations are no longer generated in this file. External bitfield
    declarations now come from included dependency headers (e.g., #include
    "gdk_decls.h").

    See: .opencode/plans/cross_namespace_phase2.json - Stage 3 See:
    architecture/todo/CROSS_NAMESPACE_PLAN.md - Section 2.2

    This file now only generates declarations for bitfields in the current
    namespace. *)

let emit_bitfield_proto buf ~namespace (bitfield : gir_bitfield) =
  let is_pixbuf_format_flags =
    String.equal bitfield.bitfield_c_type "GdkPixbufFormatFlags"
  in
  if is_pixbuf_format_flags then begin
    bprintf buf
      "/* GdkPixbufFormatFlags is in GIR but marked skip in C headers */\n";
    bprintf buf "#ifndef GDK_PIXBUF_FORMAT_WRITABLE\n"
  end;
  if is_pixbuf_format_flags then begin
    bprintf buf "typedef enum {\n";
    List.iter
      ~f:(fun flag ->
        bprintf buf "  %s = %d,\n" flag.flag_c_identifier flag.flag_value)
      bitfield.flags;
    bprintf buf "} GdkPixbufFormatFlags;\n"
  end;
  bprintf buf "value Val_%s%s(%s flags);\n" namespace bitfield.bitfield_name
    bitfield.bitfield_c_type;
  bprintf buf "%s %s%s_val(value list);\n" bitfield.bitfield_c_type namespace
    bitfield.bitfield_name;
  if is_pixbuf_format_flags then bprintf buf "#endif\n"

(** Generate forward declarations for bitfield converters.

    Note: External bitfield declarations have been removed as of Stage 3 (Phase
    2). External bitfield declarations now come from included dependency
    headers.

    @param namespace_prefix
      The namespace prefix for the current library (e.g., "Gtk")
    @param gtk_bitfields List of local bitfields to generate declarations for
    @return String containing forward declarations for bitfield converters *)
let emit_version_guard_open buf ~namespace version_str =
  let ( let* ) = Result.bind in
  match
    let* version = Version_guard.parse_version version_str in
    Version_guard.emit_c_guard namespace version ~is_opening:true
  with
  | Error msg -> failwith msg
  | Ok guard -> Buffer.add_string buf (guard ^ "\n")

let generate_forward_decls ~namespace_prefix ~gtk_bitfields =
  let buf = Buffer.create 1024 in

  if List.length gtk_bitfields > 0 then begin
    Buffer.add_string buf "/* Forward declarations for bitfield converters */\n";
    List.iter
      ~f:(fun (bitfield : gir_bitfield) ->
        Option.iter
          (emit_version_guard_open buf ~namespace:namespace_prefix)
          bitfield.bitfield_version;
        let is_pixbuf_format_flags =
          String.equal bitfield.bitfield_c_type "GdkPixbufFormatFlags"
        in
        if is_pixbuf_format_flags then
          bprintf buf "#ifndef GDK_PIXBUF_FORMAT_WRITABLE\ntypedef enum {\n";
        if is_pixbuf_format_flags then begin
          List.iter
            ~f:(fun flag ->
              bprintf buf "  %s = %d,\n" flag.flag_c_identifier flag.flag_value)
            bitfield.flags;
          bprintf buf "} GdkPixbufFormatFlags;\n"
        end;
        bprintf buf "value Val_%s%s(%s flags);\n" namespace_prefix
          bitfield.bitfield_name bitfield.bitfield_c_type;
        bprintf buf "%s %s%s_val(value list);\n" bitfield.bitfield_c_type
          namespace_prefix bitfield.bitfield_name;
        if is_pixbuf_format_flags then bprintf buf "#endif\n";
        Option.iter
          (fun _ -> Buffer.add_string buf "#endif\n")
          bitfield.bitfield_version)
      gtk_bitfields;
    Buffer.add_string buf "\n"
  end;

  Buffer.contents buf
