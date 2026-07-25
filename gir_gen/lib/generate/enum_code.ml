(* Enum and Bitfield Code Generation *)

open StdLabels
open Printf
open Types

(** Derive the canonical uppercase variant name from a raw member name,
    prefixing digit-leading names with "V". This is shared between .mli and .ml
    emission so both always agree on the tag spelling. *)
let variant_name_of_member name =
  let upper = String.uppercase_ascii name in
  if String.length upper > 0 && upper.[0] >= '0' && upper.[0] <= '9' then
    "V" ^ upper
  else upper

(** Emit a single converter branch, optionally wrapped in a per-member version
    guard. [~class_version]: the enum/bitfield entity-level version (outer
    guard, if any) [~member_version]: this specific member's version override
    [~fallback_line]: if [Some s], emit [#else s] between guard and [#endif]; if
    [None], emit only [#if branch #endif] (C->OCaml direction, where the
    [default:] case handles unknown values) [~branch]: the C source line(s) to
    guard (no trailing newline required) *)
let emit_member_branch ~namespace ~class_version ~member_version ~fallback_line
    ~branch buf =
  match Version_guard.resolve_guard ~class_version ~member_version with
  | Error _ | Ok (Version_guard.No_guard | Version_guard.Class_guard _) ->
      Buffer.add_string buf branch
  | Ok (Version_guard.Member_guard v) -> (
      match Version_guard.emit_c_guard namespace v ~is_opening:true with
      | Error _ -> Buffer.add_string buf branch
      | Ok guard_if -> (
          bprintf buf "%s\n%s\n" guard_if branch;
          (match fallback_line with
          | None -> ()
          | Some fb -> bprintf buf "%s\n%s\n" Version_guard.c_guard_else fb);
          match Version_guard.emit_c_guard namespace v ~is_opening:false with
          | Ok guard_endif -> Buffer.add_string buf (guard_endif ^ "\n")
          | Error _ -> Buffer.add_string buf "#endif\n"))

(* Generate OCaml enum type definition plus val declarations for converters *)
let generate_ocaml_enum enum =
  let buf = Buffer.create 512 in
  let lower_name = Utils.ocaml_enum_name enum in

  bprintf buf "(* %s - enumeration *)\n" enum.enum_name;
  (match enum.enum_doc with
  | Some doc -> bprintf buf "(** %s *)\n" (Utils.sanitize_doc doc)
  | None -> ());

  bprintf buf "type %s = [\n" lower_name;

  List.iteri
    ~f:(fun i member ->
      let vname = variant_name_of_member member.member_name in
      (match member.member_doc with
      | Some doc -> bprintf buf "  (** %s *)\n" (Utils.sanitize_doc doc)
      | None -> ());
      bprintf buf "  | `%s" vname;
      if i < List.length enum.members - 1 then bprintf buf "\n"
      else bprintf buf "\n]\n\n")
    enum.members;

  bprintf buf "val %s_of_int : int -> %s\n" lower_name lower_name;
  bprintf buf "val %s_to_int : %s -> int\n\n" lower_name lower_name;

  Buffer.contents buf

(* Generate OCaml bitfield type definition plus val declarations for
   converters *)
let generate_ocaml_bitfield bitfield =
  let buf = Buffer.create 512 in
  let lower_name = Utils.ocaml_bitfield_name bitfield in

  bprintf buf "(* %s - bitfield/flags *)\n" bitfield.bitfield_name;
  (match bitfield.bitfield_doc with
  | Some doc -> bprintf buf "(** %s *)\n" (Utils.sanitize_doc doc)
  | None -> ());

  bprintf buf "type %s_flag = [\n" lower_name;

  List.iteri
    ~f:(fun i flag ->
      let vname = variant_name_of_member flag.flag_name in
      (match flag.flag_doc with
      | Some doc -> bprintf buf "  (** %s *)\n" (Utils.sanitize_doc doc)
      | None -> ());
      bprintf buf "  | `%s" vname;
      if i < List.length bitfield.flags - 1 then bprintf buf "\n"
      else bprintf buf "\n]\n\n")
    bitfield.flags;

  bprintf buf "type %s = %s_flag list\n\n" lower_name lower_name;

  bprintf buf "val %s_of_int : int -> %s\n" lower_name lower_name;
  bprintf buf "val %s_to_int : %s -> int\n\n" lower_name lower_name;

  Buffer.contents buf

(* Generate C conversion functions for enum *)
let generate_c_enum_converters ~namespace ~class_version enum =
  (* Skip enums with no members *)
  if List.length enum.members = 0 then ""
  else begin
    let buf = Buffer.create 1024 in
    let val_func = sprintf "Val_%s%s" namespace enum.enum_name in
    let c_val_func = sprintf "%s%s_val" namespace enum.enum_name in
    (* Generate C to OCaml converter *)
    bprintf buf "/* Convert %s to OCaml value */\n" enum.enum_c_type;
    bprintf buf "value %s(%s val) {\n" val_func enum.enum_c_type;
    bprintf buf "  switch (val) {\n";

    (* Track seen values to avoid duplicate case statements *)
    let seen_values = Hashtbl.create 10 in
    List.iter
      ~f:(fun enum_member ->
        if not (Hashtbl.mem seen_values enum_member.member_value) then begin
          Hashtbl.add seen_values enum_member.member_value true;
          let variant_name = variant_name_of_member enum_member.member_name in
          let case_line =
            sprintf "    case %s: return caml_hash_variant(\"%s\"); /* `%s */\n"
              enum_member.c_identifier variant_name variant_name
          in
          emit_member_branch ~namespace ~class_version
            ~member_version:enum_member.member_version ~fallback_line:None
            ~branch:case_line buf
        end)
      enum.members;

    bprintf buf "    default: {\n";
    bprintf buf "      char msg[128];\n";
    bprintf buf
      "      g_snprintf(msg, sizeof(msg), \"Unknown %s value: %%d\", (int)val);\n"
      enum.enum_c_type;
    bprintf buf "      g_warning(\"%%s\", msg);\n";
    bprintf buf "      caml_failwith(msg);\n";
    bprintf buf "    }\n";
    bprintf buf "  }\n";
    bprintf buf "}\n\n";

    (* Generate OCaml to C converter *)
    bprintf buf "/* Convert OCaml value to %s */\n" enum.enum_c_type;
    bprintf buf "%s %s(value val) {\n" enum.enum_c_type c_val_func;

    List.iteri
      ~f:(fun i enum_member ->
        let variant_name = variant_name_of_member enum_member.member_name in
        let fallback_line =
          match enum_member.member_version with
          | None -> None
          | Some v_str ->
              let msg =
                sprintf
                  "  %sif (val == caml_hash_variant(\"%s\")) \
                   caml_failwith(\"%s.%s requires %s\");"
                  (if i = 0 then "" else "else ")
                  variant_name enum.enum_c_type variant_name v_str
              in
              Some msg
        in
        let branch_line =
          sprintf
            "  %sif (val == caml_hash_variant(\"%s\")) return %s; /* `%s */\n"
            (if i = 0 then "" else "else ")
            variant_name enum_member.c_identifier variant_name
        in
        emit_member_branch ~namespace ~class_version
          ~member_version:enum_member.member_version ~fallback_line
          ~branch:branch_line buf)
      enum.members;

    bprintf buf "  else {\n";
    bprintf buf "    char msg[128];\n";
    bprintf buf
      "    g_snprintf(msg, sizeof(msg), \"Unknown %s tag: %%ld\", val);\n"
      enum.enum_c_type;
    bprintf buf "    g_warning(\"%%s\", msg);\n";
    bprintf buf "    caml_failwith(msg);\n";
    bprintf buf "  }\n";
    bprintf buf "}\n\n";

    Buffer.contents buf
  end

(* Generate C conversion functions for bitfield *)
let generate_c_bitfield_converters ~namespace ~class_version bitfield =
  (* Skip bitfields with no flags *)
  if List.length bitfield.flags = 0 then ""
  else begin
    let buf = Buffer.create 1024 in
    let val_func = sprintf "Val_%s%s" namespace bitfield.bitfield_name in
    let c_val_func = sprintf "%s%s_val" namespace bitfield.bitfield_name in

    (* Special case: GdkPixbufFormatFlags is in GIR but marked skip in C headers *)
    if String.equal bitfield.bitfield_c_type "GdkPixbufFormatFlags" then begin
      bprintf buf
        "/* GdkPixbufFormatFlags is in GIR but marked skip in C headers */\n";
      bprintf buf "#ifndef GDK_PIXBUF_FORMAT_WRITABLE\n";
      bprintf buf "typedef enum {\n";
      List.iter
        ~f:(fun flag ->
          bprintf buf "  %s = %d,\n" flag.flag_c_identifier flag.flag_value)
        bitfield.flags;
      bprintf buf "} GdkPixbufFormatFlags;\n";
      bprintf buf "#endif\n\n"
    end;

    (* Generate C to OCaml converter (int flags -> list of variants) *)
    bprintf buf "/* Convert %s to OCaml flag list */\n" bitfield.bitfield_c_type;
    bprintf buf "value %s(%s flags) {\n" val_func bitfield.bitfield_c_type;
    bprintf buf "  CAMLparam0();\n";
    bprintf buf "  CAMLlocal2(result, cons);\n";
    bprintf buf "  result = Val_emptylist;\n\n";

    (* Check each flag bit and add to list if set *)
    List.iter
      ~f:(fun flag ->
        let variant_name = variant_name_of_member flag.flag_name in
        let branch =
          sprintf
            "  if (flags & %s) {\n\
            \    cons = caml_alloc(2, 0);\n\
            \    Store_field(cons, 0, caml_hash_variant(\"%s\")); /* `%s */\n\
            \    Store_field(cons, 1, result);\n\
            \    result = cons;\n\
            \  }\n"
            flag.flag_c_identifier variant_name variant_name
        in
        emit_member_branch ~namespace ~class_version
          ~member_version:flag.flag_version ~fallback_line:None ~branch buf)
      bitfield.flags;

    bprintf buf "\n  CAMLreturn(result);\n";
    bprintf buf "}\n\n";

    (* Generate OCaml to C converter (list of variants -> int flags) *)
    bprintf buf "/* Convert OCaml flag list to %s */\n" bitfield.bitfield_c_type;
    bprintf buf "%s %s(value list) {\n" bitfield.bitfield_c_type c_val_func;
    bprintf buf "  %s result = 0;\n" bitfield.bitfield_c_type;
    bprintf buf "  while (list != Val_emptylist) {\n";
    bprintf buf "    value tag = Field(list, 0);\n";

    List.iteri
      ~f:(fun i flag ->
        let variant_name = variant_name_of_member flag.flag_name in
        let fallback_line =
          match flag.flag_version with
          | None -> None
          | Some v_str ->
              let msg =
                sprintf
                  "    %sif (tag == caml_hash_variant(\"%s\")) \
                   caml_failwith(\"%s.%s requires %s\");"
                  (if i = 0 then "" else "else ")
                  variant_name bitfield.bitfield_c_type variant_name v_str
              in
              Some msg
        in
        let branch_line =
          sprintf
            "    %sif (tag == caml_hash_variant(\"%s\")) result |= %s; /* `%s */\n"
            (if i = 0 then "" else "else ")
            variant_name flag.flag_c_identifier variant_name
        in
        emit_member_branch ~namespace ~class_version
          ~member_version:flag.flag_version ~fallback_line ~branch:branch_line
          buf)
      bitfield.flags;

    bprintf buf "    list = Field(list, 1);\n";
    bprintf buf "  }\n";
    bprintf buf "  return result;\n";
    bprintf buf "}\n\n";

    Buffer.contents buf
  end

(** Generate the pure-OCaml [<lower>_of_int] and [<lower>_to_int] functions for
    an enum. The [_of_int] function is an exhaustive match on integer values;
    unknown integers raise [Failure] with a descriptive message. The [_to_int]
    function is a plain reverse match. Members with duplicate integer values
    emit only one arm in [_of_int] (first occurrence wins, matching the C
    behaviour). Version-guarded members are emitted unconditionally because the
    [.mli] lists all tags and there is no OCaml-side ppx for conditional
    compilation. *)
let generate_ocaml_enum_impl enum =
  if List.length enum.members = 0 then ""
  else begin
    let buf = Buffer.create 512 in
    let lower_name = Utils.ocaml_enum_name enum in

    (* Emit type declaration so the .ml is self-contained *)
    bprintf buf "type %s = [\n" lower_name;
    List.iteri
      ~f:(fun i member ->
        let vname = variant_name_of_member member.member_name in
        bprintf buf "  | `%s" vname;
        if i < List.length enum.members - 1 then bprintf buf "\n"
        else bprintf buf "\n]\n\n")
      enum.members;

    (* _of_int: match on integer values *)
    bprintf buf "let %s_of_int n =\n" lower_name;
    bprintf buf "  match n with\n";

    (* Track seen integer values to avoid duplicate match arms *)
    let seen_values = Hashtbl.create 16 in
    List.iter
      ~f:(fun member ->
        if not (Hashtbl.mem seen_values member.member_value) then begin
          Hashtbl.add seen_values member.member_value true;
          let vname = variant_name_of_member member.member_name in
          bprintf buf "  | %d -> `%s\n" member.member_value vname
        end)
      enum.members;

    bprintf buf
      "  | n -> failwith (Printf.sprintf \"%s: unknown int %%d\" n)\n\n"
      enum.enum_name;

    (* _to_int: match on polymorphic variant tags *)
    bprintf buf "let %s_to_int v =\n" lower_name;
    bprintf buf "  match v with\n";
    List.iter
      ~f:(fun member ->
        let vname = variant_name_of_member member.member_name in
        bprintf buf "  | `%s -> %d\n" vname member.member_value)
      enum.members;

    bprintf buf "\n";
    Buffer.contents buf
  end

(** Generate the pure-OCaml [<lower>_of_int] and [<lower>_to_int] functions for
    a bitfield. The [_of_int] function tests each known bit and accumulates a
    list of matching tags (empty for 0). The [_to_int] function folds the list
    with [lor]. Version-guarded members are emitted unconditionally (same
    rationale as {!generate_ocaml_enum_impl}). The round-trip property
    [to_int (of_int n) = n] holds for any [n] whose bits are all known. *)
let generate_ocaml_bitfield_impl bitfield =
  if List.length bitfield.flags = 0 then ""
  else begin
    let buf = Buffer.create 512 in
    let lower_name = Utils.ocaml_bitfield_name bitfield in

    (* Emit type declarations so the .ml is self-contained *)
    bprintf buf "type %s_flag = [\n" lower_name;
    List.iteri
      ~f:(fun i flag ->
        let vname = variant_name_of_member flag.flag_name in
        bprintf buf "  | `%s" vname;
        if i < List.length bitfield.flags - 1 then bprintf buf "\n"
        else bprintf buf "\n]\n\n")
      bitfield.flags;
    bprintf buf "type %s = %s_flag list\n\n" lower_name lower_name;

    (* _of_int: iterate over flags testing each bit, build up acc list *)
    bprintf buf "let %s_of_int flags =\n" lower_name;
    bprintf buf "  let acc = [] in\n";
    List.iter
      ~f:(fun flag ->
        let vname = variant_name_of_member flag.flag_name in
        bprintf buf
          "  let acc = if flags land %d <> 0 then `%s :: acc else acc in\n"
          flag.flag_value vname)
      bitfield.flags;
    bprintf buf "  acc\n\n";

    (* _to_int: fold the flag list with lor *)
    bprintf buf "let %s_to_int flags =\n" lower_name;
    bprintf buf "  List.fold_left\n";
    bprintf buf "    (fun acc flag ->\n";
    bprintf buf "      match flag with\n";
    List.iter
      ~f:(fun flag ->
        let vname = variant_name_of_member flag.flag_name in
        bprintf buf "      | `%s -> acc lor %d\n" vname flag.flag_value)
      bitfield.flags;
    bprintf buf "    )\n";
    bprintf buf "    0 flags\n\n";

    Buffer.contents buf
  end
