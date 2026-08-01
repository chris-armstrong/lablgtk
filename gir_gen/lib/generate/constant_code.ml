(* Constant Code Generation *)

open StdLabels
open Gen_buffer
open Types

(** Derive the OCaml name for a constant by lowercasing the GIR name. GIR
    constant names are SCREAMING_SNAKE_CASE (e.g. "PANGO_SCALE"); lowercasing
    yields valid OCaml identifiers (e.g. "pango_scale"). *)
let ocaml_name_of_constant name = String.lowercase_ascii name

(** Map a GIR type name to its OCaml type string for constant declarations.
    Reuses [Type_mappings.type_mappings] -- the same table the rest of the
    generator uses -- rather than a second hand-rolled mapping, so each integer
    width/sign resolves to its own module (gint32->Int32.t, gint64->int64,
    guint32->UInt32.t, guint64->UInt64.t, gsize->Gsize.t) instead of collapsing
    to [int]. Returns [None] for types that cannot back a pure-OCaml literal
    constant (records/classes/enums, or anything not in the table) -- those are
    skipped with a warning. *)
let ocaml_type_of_gir_type_name type_name =
  (* Only these OCaml types can be written as a pure-OCaml literal/expression
     with no C stub (see [serialize_value]). Class/record/enum mappings are
     rejected here even if [type_mappings] knows them. *)
  let serializable = function
    | ( "int" | "Int32.t" | "int64" | "UInt32.t" | "UInt64.t" | "Gsize.t"
      | "float" | "bool" | "string" ) as t ->
        Some t
    | _ -> None
  in
  match List.assoc_opt type_name Type_mappings.type_mappings with
  | Some tm -> serializable tm.ocaml_type
  | None -> None

(** Serialize a constant value string to an OCaml literal or construction
    expression for [ocaml_type]. *)
let serialize_value ~ocaml_type value =
  match ocaml_type with
  | "string" -> Fmt.str "%S" value (* escapes quotes and backslashes *)
  | "bool" -> value (* GIR uses "true"/"false" literally *)
  | "float" ->
      (* Ensure OCaml float syntax: add ".0" if no decimal point *)
      if String.contains value '.' then value else value ^ ".0"
  | "int" -> value (* decimal literal as-is *)
  | "Int32.t" -> value ^ "l" (* OCaml int32 literal suffix *)
  | "int64" -> value ^ "L" (* OCaml int64 literal suffix *)
  | "UInt32.t" -> "UInt32.of_int " ^ value
  | "UInt64.t" -> "UInt64.of_int " ^ value
  | "Gsize.t" -> "Gsize.of_int " ^ value
  | _ -> value (* unreachable: ocaml_type_of_gir_type_name filters first *)

(** Iterate [constants], resolving each one's OCaml type. Calls [emit] for every
    mappable constant. For unmappable types, warns to stderr when
    [warn_unmappable] is true and otherwise skips silently — the warning is
    emitted by whichever pass runs first (the .mli pass), so the .ml pass passes
    [false] to avoid duplicating it. Sharing this iterator removes the
    duplicated resolve/type-check/skip logic that previously existed between the
    .mli and .ml emitters. *)
let iter_mappable_constants ~warn_unmappable ~emit constants =
  List.iter
    ~f:(fun (cst : gir_constant) ->
      let ocaml_name = ocaml_name_of_constant cst.constant_name in
      match ocaml_type_of_gir_type_name cst.value_type.name with
      | None ->
          if warn_unmappable then
            Fmt.epr "  Warning: skipping constant %s with unmappable type %s\n"
              cst.constant_name cst.value_type.name
      | Some ocaml_type -> emit ~ocaml_name ~ocaml_type cst)
    constants

(** Emit the OCamldoc line preceding a [val] declaration, using [constant_doc]
    (sanitized) and the native [version] attribute rendered as [@since]. *)
let emit_doc buf (cst : gir_constant) =
  match cst.constant_doc with
  | Some doc ->
      let doc_text = Utils.sanitize_doc doc in
      bprintf buf "(** %s" doc_text;
      (match cst.version with
      | Some v -> bprintf buf "\n    @since %s" v
      | None -> ());
      bprintf buf " *)\n"
  | None -> (
      match cst.version with
      | Some v -> bprintf buf "(** [%s] @since %s *)\n" cst.constant_c_type v
      | None -> ())

(** Generate the .mli content for the constants of a namespace. Returns just the
    file header when [constants] is empty. *)
let generate_constants_interface ~namespace constants =
  let buf = Buffer.create 4096 in
  bprintf buf "(* GENERATED CODE - DO NOT EDIT *)\n";
  bprintf buf "(* %s Constants *)\n\n" namespace;
  iter_mappable_constants ~warn_unmappable:true
    ~emit:(fun ~ocaml_name ~ocaml_type cst ->
      emit_doc buf cst;
      bprintf buf "val %s : %s\n\n" ocaml_name ocaml_type)
    constants;
  Buffer.contents buf

(** Generate the .ml content for the constants of a namespace. Returns just the
    file header when [constants] is empty. *)
let generate_constants_implementation ~namespace constants =
  let buf = Buffer.create 4096 in
  bprintf buf "(* GENERATED CODE - DO NOT EDIT *)\n";
  bprintf buf "(* %s Constants *)\n\n" namespace;
  iter_mappable_constants ~warn_unmappable:false
    ~emit:(fun ~ocaml_name ~ocaml_type cst ->
      let value = serialize_value ~ocaml_type cst.value in
      bprintf buf "let %s = %s\n" ocaml_name value)
    constants;
  Buffer.contents buf

(** Generate both <ns>_constants.mli and <ns>_constants.ml under [output_dir]
    for the constants carried by [ctx]. Does nothing when there are no
    constants, so namespaces without constants (e.g. Cairo) produce no constants
    module. *)
let generate_constants_files ~ctx ~namespace ~output_dir =
  let constants = ctx.constants in
  if List.length constants = 0 then ()
  else begin
    let ns_lower = String.lowercase_ascii namespace in
    let mli_path =
      Filename.concat output_dir (Fmt.str "%s_constants.mli" ns_lower)
    in
    let ml_path =
      Filename.concat output_dir (Fmt.str "%s_constants.ml" ns_lower)
    in
    let write path content =
      let oc = open_out path in
      output_string oc content;
      close_out oc;
      Fmt.pr "Writing %s...\n" path
    in
    write mli_path (generate_constants_interface ~namespace constants);
    write ml_path (generate_constants_implementation ~namespace constants)
  end
