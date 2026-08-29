open Containers

type version = { major : int; minor : int; micro : int }
type guard_kind = No_guard | Class_guard of version | Member_guard of version
type macro_kind = Standard of string | EncodeComparison of (string * string)

let namespace_macro_kind namespace =
  match namespace with
  | "Gtk" -> Ok (Standard "GTK_CHECK_VERSION")
  | "Gdk" -> Ok (Standard "GTK_CHECK_VERSION")
  | "Gsk" -> Ok (Standard "GTK_CHECK_VERSION")
  | "Pango" -> Ok (Standard "PANGO_VERSION_CHECK")
  | "PangoCairo" -> Ok (Standard "PANGO_VERSION_CHECK")
  | "GdkPixbuf" -> Ok (Standard "GDK_PIXBUF_CHECK_VERSION")
  | "Gio" -> Ok (Standard "GLIB_CHECK_VERSION")
  (* Graphene has a check macro, but its inverted in some versions. It's headers suggest comparing against the encoded version *)
  | "Graphene" ->
      Ok (EncodeComparison ("GRAPHENE_VERSION", "GRAPHENE_ENCODE_VERSION"))
  (* Cairo needs an encode comparison macro too *)
  | "Cairo" -> Ok (EncodeComparison ("CAIRO_VERSION", "CAIRO_VERSION_ENCODE"))
  | other -> Error (Printf.sprintf "Unknown namespace: %s" other)

(** Map a user-supplied (case-insensitive) library name to the canonical GIR
    namespace name accepted by {!namespace_macro_kind}. Returns [Error] for
    unknown names. *)
let normalize_namespace s =
  match String.lowercase_ascii s with
  | "gtk" -> Ok "Gtk"
  | "gdk" -> Ok "Gdk"
  | "gsk" -> Ok "Gsk"
  | "pango" -> Ok "Pango"
  | "pangocairo" | "pango-cairo" -> Ok "PangoCairo"
  | "gio" | "glib" -> Ok "Gio"
  | "gdkpixbuf" | "gdk-pixbuf" -> Ok "GdkPixbuf"
  | "graphene" -> Ok "Graphene"
  | "cairo" -> Ok "Cairo"
  | _ ->
      Error
        (Printf.sprintf
           "Unknown library name '%s'. Expected one of: gtk, gdk, gsk, pango, \
            pangocairo, gio, glib, gdkpixbuf, graphene, cairo"
           s)

let parse_component ~version_str ~s =
  match int_of_string_opt s with
  | Some n -> Ok n
  | None ->
      Error
        (Printf.sprintf
           "Invalid version format '%s': component '%s' is not an integer"
           version_str s)

let parse_version version_str =
  let parts = String.split_on_char '.' version_str in
  let ( let* ) = Stdlib.Result.bind in
  match parts with
  | [ major_str; minor_str ] ->
      let* major = parse_component ~version_str ~s:major_str in
      let* minor = parse_component ~version_str ~s:minor_str in
      Ok { major; minor; micro = 0 }
  | [ major_str; minor_str; micro_str ] ->
      let* major = parse_component ~version_str ~s:major_str in
      let* minor = parse_component ~version_str ~s:minor_str in
      let* micro = parse_component ~version_str ~s:micro_str in
      Ok { major; minor; micro }
  | _ ->
      Error
        (Printf.sprintf
           "Invalid version format '%s', expected 'major.minor' or \
            'major.minor.micro'"
           version_str)

let compare_versions v1 v2 =
  match Int.compare v1.major v2.major with
  | 0 -> (
      match Int.compare v1.minor v2.minor with
      | 0 -> Int.compare v1.micro v2.micro
      | c -> c)
  | c -> c

let resolve_guard ~class_version ~member_version =
  let ( let* ) = Stdlib.Result.bind in
  match (class_version, member_version) with
  | None, None -> Ok No_guard
  | Some class_v_str, None ->
      let* class_v = parse_version class_v_str in
      Ok (Class_guard class_v)
  | None, Some member_v_str ->
      let* member_v = parse_version member_v_str in
      Ok (Member_guard member_v)
  | Some class_v_str, Some member_v_str ->
      let* class_v = parse_version class_v_str in
      let* member_v = parse_version member_v_str in
      if compare_versions member_v class_v > 0 then Ok (Member_guard member_v)
      else Ok (Class_guard class_v)

let format_version_args version =
  Printf.sprintf "%d,%d,%d" version.major version.minor version.micro

let emit_c_guard namespace version ~is_opening =
  let ( let* ) = Stdlib.Result.bind in
  let* macro_kind = namespace_macro_kind namespace in
  let guard_expr =
    match macro_kind with
    | EncodeComparison (version_macro, encode_macro_name) ->
        Printf.sprintf "%s >= %s(%s)" version_macro encode_macro_name
          (format_version_args version)
    | Standard macro_name ->
        Printf.sprintf "%s(%s)" macro_name (format_version_args version)
  in
  if is_opening then Ok (Printf.sprintf "#if %s" guard_expr) else Ok "#endif"

let c_guard_else = "#else"
