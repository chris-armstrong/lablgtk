(* S-expression parser for GIR override files. *)

open Override_types

type parse_error =
  | Invalid_format of { location : string; message : string }
  | Unknown_entity_kind of string
  | Unknown_component_kind of {
      entity_name : string;
      kind : string;
      valid_kinds : string list;
    }
  | Duplicate_entity of { kind : string; name : string }
  | Duplicate_component of {
      entity : string;
      component_kind : string;
      name : string;
    }
  | Invalid_version of { name : string; version : string; reason : string }

let format_error = function
  | Invalid_format { location; message } -> Fmt.str "%s: %s" location message
  | Unknown_entity_kind kind -> Fmt.str "Unknown entity kind: %s" kind
  | Unknown_component_kind { entity_name; kind; valid_kinds } ->
      Fmt.str "%s: Unknown component kind '%s' (expected one of: %s)"
        entity_name kind
        (String.concat ", " valid_kinds)
  | Duplicate_entity { kind; name } -> Fmt.str "Duplicate %s '%s'" kind name
  | Duplicate_component { entity; component_kind; name } ->
      Fmt.str "Duplicate %s '%s' in %s" component_kind name entity
  | Invalid_version { name; version; reason } ->
      Fmt.str "Invalid version '%s' for '%s': %s" version name reason

module Sexp = Sexplib.Sexp

let ( let* ) = Result.bind

let validate_version ~name ~version_str =
  match Version_guard.parse_version version_str with
  | Ok _ -> Ok ()
  | Error reason ->
      Error (Invalid_version { name; version = version_str; reason })

let parse_version_spec ~comp_name sexp_args =
  (* (version "X.Y")  — default namespace *)
  (* (version (lib "X.Y")) — cross-namespace *)
  match sexp_args with
  | [ Sexp.Atom v ] -> (
      match validate_version ~name:comp_name ~version_str:v with
      | Error e -> Error e
      | Ok () -> Ok (Set_version { vs_version = v; vs_namespace = None }))
  | [ Sexp.List [ Sexp.Atom lib; Sexp.Atom v ] ] -> (
      match Version_guard.normalize_namespace lib with
      | Error msg ->
          Error
            (Invalid_format
               { location = Fmt.str "%s (version)" comp_name; message = msg })
      | Ok ns -> (
          match validate_version ~name:comp_name ~version_str:v with
          | Error e -> Error e
          | Ok () -> Ok (Set_version { vs_version = v; vs_namespace = Some ns })
          ))
  | _ ->
      Error
        (Invalid_format
           {
             location = Fmt.str "%s (version)" comp_name;
             message = "Expected (version \"X.Y\") or (version (lib \"X.Y\"))";
           })

(** Build an [Os_filter.t option] from collected os/not_os name lists. Returns
    [Error] if both lists are non-empty (mixing is forbidden). *)
let build_os_filter ~context os_vals not_os_vals =
  match (os_vals, not_os_vals) with
  | [], [] -> Ok None
  | names, [] -> Ok (Some (Os_filter.Os_only names))
  | [], names -> Ok (Some (Os_filter.Os_except names))
  | _ ->
      Error
        (Invalid_format
           {
             location = context;
             message = "Cannot mix (os ...) and (not_os ...) on the same entity";
           })

(** Parse optional qualifiers from a component body: (ignore), (version ...),
    (os "..."), (not_os "..."). Returns [(action, os)] where both are options.
*)
let parse_component_qualifiers ~comp_name body =
  let rec go action os_vals not_os_vals = function
    | [] -> (
        match
          build_os_filter ~context:comp_name (List.rev os_vals)
            (List.rev not_os_vals)
        with
        | Error e -> Error e
        | Ok os -> Ok (action, os))
    | Sexp.Atom "ignore" :: rest | Sexp.List [ Sexp.Atom "ignore" ] :: rest ->
        go (Some Ignore) os_vals not_os_vals rest
    | Sexp.List (Sexp.Atom "version" :: args) :: rest -> (
        match parse_version_spec ~comp_name args with
        | Error e -> Error e
        | Ok a -> go (Some a) os_vals not_os_vals rest)
    | Sexp.List [ Sexp.Atom "os"; Sexp.Atom os_val ] :: rest ->
        go action (os_val :: os_vals) not_os_vals rest
    | Sexp.List [ Sexp.Atom "not_os"; Sexp.Atom os_val ] :: rest ->
        go action os_vals (os_val :: not_os_vals) rest
    | Sexp.List (Sexp.Atom k :: _) :: _ ->
        Error
          (Invalid_format
             {
               location = Fmt.str "%s" comp_name;
               message =
                 Fmt.str
                   "Unknown qualifier '%s'; expected ignore, version, os, or \
                    not_os"
                   k;
             })
    | _ :: rest -> go action os_vals not_os_vals rest
  in
  go None [] [] body

let parse_component ~entity_name sexp =
  match sexp with
  (* Legacy short form: (kind name ignore) *)
  | Sexp.List [ Sexp.Atom _comp_kind; Sexp.Atom comp_name; Sexp.Atom "ignore" ]
  | Sexp.List
      [
        Sexp.Atom _comp_kind;
        Sexp.Atom comp_name;
        Sexp.List [ Sexp.Atom "ignore" ];
      ] ->
      Ok { component_name = comp_name; action = Some Ignore; os = None }
  (* General form: (kind name qualifier...) *)
  | Sexp.List (Sexp.Atom _comp_kind :: Sexp.Atom comp_name :: body) -> (
      match parse_component_qualifiers ~comp_name body with
      | Error e -> Error e
      | Ok (None, None) ->
          Error
            (Invalid_format
               {
                 location = Fmt.str "%s %s" entity_name comp_name;
                 message =
                   "Expected at least one qualifier: (ignore), (version \
                    \"X.Y\"), or (os \"...\")";
               })
      | Ok (action, os) -> Ok { component_name = comp_name; action; os })
  | _ ->
      Error
        (Invalid_format
           { location = entity_name; message = "Malformed component override" })

let parse_components_of_kind ~entity_name ~kind sexps =
  let rec parse acc = function
    | [] -> Ok (List.rev acc)
    | sexp :: rest -> (
        match sexp with
        | Sexp.List (Sexp.Atom k :: _) when String.equal k kind -> (
            match parse_component ~entity_name sexp with
            | Ok comp -> parse (comp :: acc) rest
            | Error e -> Error e)
        | _ -> parse acc rest)
  in
  parse [] sexps

let has_ignore_marker body =
  List.exists
    (function
      | Sexp.Atom "ignore" -> true
      | Sexp.List [ Sexp.Atom "ignore" ] -> true
      | _ -> false)
    body

(** Extract [(os "...")] / [(not_os "...")] markers from an entity body. Returns
    [Ok (Some filter)] when present, [Ok None] when absent, or [Error] when both
    [(os ...)] and [(not_os ...)] are mixed. *)
let extract_os_from_body ~context body =
  let os_vals =
    List.filter_map
      (function
        | Sexp.List [ Sexp.Atom "os"; Sexp.Atom v ] -> Some v | _ -> None)
      body
  in
  let not_os_vals =
    List.filter_map
      (function
        | Sexp.List [ Sexp.Atom "not_os"; Sexp.Atom v ] -> Some v | _ -> None)
      body
  in
  build_os_filter ~context os_vals not_os_vals

(** Validate that every list-form element in an entity body starts with one of
    [valid_kinds] (or is an action marker like [ignore] / [version] / [os]).
    Returns [Error (Unknown_component_kind ...)] on the first unrecognised kind.
*)
let validate_body_elements ~entity_name ~valid_kinds body =
  let rec check = function
    | [] -> Ok ()
    | sexp :: rest -> (
        match sexp with
        | Sexp.Atom _ ->
            check rest (* bare atoms: ignore / other – handled elsewhere *)
        | Sexp.List [] -> check rest
        | Sexp.List (Sexp.Atom k :: _) ->
            if
              List.mem k valid_kinds || String.equal k "ignore"
              || String.equal k "version" || String.equal k "os"
              || String.equal k "not_os"
            then check rest
            else
              Error
                (Unknown_component_kind { entity_name; kind = k; valid_kinds })
        | Sexp.List _ -> check rest)
  in
  check body

(** Parse the common header shared by all entity overrides: the entity name and
    optional ignore/action marker. Returns [(name, action_opt, body)] on
    success. *)
let parse_entity_header ~kind sexp =
  match sexp with
  | Sexp.List (Sexp.Atom k :: Sexp.Atom name :: body) when String.equal k kind
    ->
      let action = if has_ignore_marker body then Some Ignore else None in
      let* os = extract_os_from_body ~context:name body in
      Ok (name, action, os, body)
  | _ ->
      Error
        (Invalid_format
           { location = kind; message = Fmt.str "Expected (%s Name ...)" kind })

let parse_class_override sexp =
  let* name, class_action, class_os, body =
    parse_entity_header ~kind:"class" sexp
  in
  let* () =
    validate_body_elements ~entity_name:name
      ~valid_kinds:[ "constructor"; "method"; "property"; "signal" ]
      body
  in
  let* constructors =
    parse_components_of_kind ~entity_name:name ~kind:"constructor" body
  in
  let* methods =
    parse_components_of_kind ~entity_name:name ~kind:"method" body
  in
  let* properties =
    parse_components_of_kind ~entity_name:name ~kind:"property" body
  in
  let* signals =
    parse_components_of_kind ~entity_name:name ~kind:"signal" body
  in
  Ok
    {
      class_name = name;
      class_action;
      class_os;
      constructors;
      methods;
      properties;
      signals;
    }

let parse_interface_override sexp =
  let* name, interface_action, interface_os, body =
    parse_entity_header ~kind:"interface" sexp
  in
  let* () =
    validate_body_elements ~entity_name:name
      ~valid_kinds:[ "method"; "property"; "signal" ]
      body
  in
  let* methods =
    parse_components_of_kind ~entity_name:name ~kind:"method" body
  in
  let* properties =
    parse_components_of_kind ~entity_name:name ~kind:"property" body
  in
  let* signals =
    parse_components_of_kind ~entity_name:name ~kind:"signal" body
  in
  Ok
    {
      interface_name = name;
      interface_action;
      interface_os;
      methods;
      properties;
      signals;
    }

let parse_record_override sexp =
  let* name, record_action, record_os, body =
    parse_entity_header ~kind:"record" sexp
  in
  let* () =
    validate_body_elements ~entity_name:name
      ~valid_kinds:[ "field"; "constructor"; "method"; "function" ]
      body
  in
  let* fields = parse_components_of_kind ~entity_name:name ~kind:"field" body in
  let* constructors =
    parse_components_of_kind ~entity_name:name ~kind:"constructor" body
  in
  let* methods =
    parse_components_of_kind ~entity_name:name ~kind:"method" body
  in
  let* functions =
    parse_components_of_kind ~entity_name:name ~kind:"function" body
  in
  Ok
    {
      record_name = name;
      record_action;
      record_os;
      fields;
      constructors;
      methods;
      functions;
    }

let parse_enum_override sexp =
  let* name, enum_action, enum_os, body =
    parse_entity_header ~kind:"enumeration" sexp
  in
  let* () =
    validate_body_elements ~entity_name:name
      ~valid_kinds:[ "member"; "function" ] body
  in
  let* members =
    parse_components_of_kind ~entity_name:name ~kind:"member" body
  in
  let* functions =
    parse_components_of_kind ~entity_name:name ~kind:"function" body
  in
  Ok { enum_name = name; enum_action; enum_os; members; functions }

let parse_bitfield_override sexp =
  let* name, bitfield_action, bitfield_os, body =
    parse_entity_header ~kind:"bitfield" sexp
  in
  let* () =
    validate_body_elements ~entity_name:name ~valid_kinds:[ "member" ] body
  in
  let* flags = parse_components_of_kind ~entity_name:name ~kind:"member" body in
  Ok { bitfield_name = name; bitfield_action; bitfield_os; flags }

let extract_library_name body =
  List.find_map
    (function
      | Sexp.List [ Sexp.Atom "library"; Sexp.Atom name ] -> Some name
      | _ -> None)
    body
  |> Option.value ~default:""

(** Process one element of the overrides body. For standalone functions: parses
    directly (no duplicate check). For entities: validates kind, checks for
    duplicates, type-specific parse + accumulate. For library declarations:
    skipped. *)
let parse_header_override sexp =
  match sexp with
  | Sexp.List (Sexp.Atom "header" :: Sexp.Atom path :: rest) ->
      let* header_os = extract_os_from_body ~context:path rest in
      Ok { header_path = path; header_os }
  | _ ->
      Error
        (Invalid_format
           {
             location = "header";
             message =
               "Expected (header \"path\" [(os \"...\") | (not_os \"...\")])";
           })

let process_element ~seen ~errors ~classes ~interfaces ~records ~enums
    ~bitfields ~functions ~headers sexp =
  match sexp with
  | Sexp.List [ Sexp.Atom "library"; _ ] -> ()
  | Sexp.List (Sexp.Atom "header" :: _) -> (
      match parse_header_override sexp with
      | Ok h -> headers := h :: !headers
      | Error e -> errors := e :: !errors)
  | Sexp.List (Sexp.Atom "function" :: Sexp.Atom name :: _) ->
      let key = ("function", name) in
      if Hashtbl.mem seen key then
        errors := Duplicate_entity { kind = "function"; name } :: !errors
      else begin
        Hashtbl.add seen key true;
        match parse_component ~entity_name:"top-level" sexp with
        | Ok f -> functions := f :: !functions
        | Error e -> errors := e :: !errors
      end
  | Sexp.List
      (Sexp.Atom
         (("class" | "interface" | "record" | "enumeration" | "bitfield") as
          kind)
      :: Sexp.Atom name
      :: _) ->
      let key = (kind, name) in
      if Hashtbl.mem seen key then
        errors := Duplicate_entity { kind; name } :: !errors
      else begin
        Hashtbl.add seen key true;
        match kind with
        | "class" -> (
            match parse_class_override sexp with
            | Ok v -> classes := v :: !classes
            | Error e -> errors := e :: !errors)
        | "interface" -> (
            match parse_interface_override sexp with
            | Ok v -> interfaces := v :: !interfaces
            | Error e -> errors := e :: !errors)
        | "record" -> (
            match parse_record_override sexp with
            | Ok v -> records := v :: !records
            | Error e -> errors := e :: !errors)
        | "enumeration" -> (
            match parse_enum_override sexp with
            | Ok v -> enums := v :: !enums
            | Error e -> errors := e :: !errors)
        | "bitfield" -> (
            match parse_bitfield_override sexp with
            | Ok v -> bitfields := v :: !bitfields
            | Error e -> errors := e :: !errors)
        | _ -> assert false
      end
  | Sexp.List (Sexp.Atom kind :: _) ->
      errors := Unknown_entity_kind kind :: !errors
  | _ ->
      errors :=
        Invalid_format
          { location = "top level"; message = "Malformed entity override" }
        :: !errors

(** Walk all elements in the overrides body, stopping at the first error. *)
let collect_overrides ~seen ~errors ~classes ~interfaces ~records ~enums
    ~bitfields ~functions ~headers body =
  List.iter
    (fun sexp ->
      if List.length !errors > 0 then ()
      else
        process_element ~seen ~errors ~classes ~interfaces ~records ~enums
          ~bitfields ~functions ~headers sexp)
    body

let parse_overrides_sexp sexp =
  match sexp with
  | Sexp.List (Sexp.Atom "overrides" :: body) -> (
      let library_name = extract_library_name body in
      let classes = ref [] in
      let interfaces = ref [] in
      let records = ref [] in
      let enums = ref [] in
      let bitfields = ref [] in
      let functions = ref [] in
      let headers = ref [] in
      let errors = ref [] in
      let seen = Hashtbl.create 16 in
      collect_overrides ~seen ~errors ~classes ~interfaces ~records ~enums
        ~bitfields ~functions ~headers body;
      match !errors with
      | e :: _ -> Error e
      | [] ->
          Ok
            {
              library_name;
              classes = List.rev !classes;
              interfaces = List.rev !interfaces;
              records = List.rev !records;
              enums = List.rev !enums;
              bitfields = List.rev !bitfields;
              functions = List.rev !functions;
              headers = List.rev !headers;
            })
  | _ ->
      Error
        (Invalid_format
           { location = "root"; message = "Expected (overrides ...)" })

let parse_overrides filename =
  try
    let sexp = Sexp.load_sexp filename in
    parse_overrides_sexp sexp
  with
  | Sexplib.Sexp.Parse_error e ->
      Error (Invalid_format { location = filename; message = e.err_msg })
  | Failure msg -> Error (Invalid_format { location = filename; message = msg })
  | Sys_error msg ->
      Error (Invalid_format { location = filename; message = msg })

let parse_overrides_from_string content =
  try parse_overrides_sexp (Sexp.of_string content) with
  | Sexplib.Sexp.Parse_error e ->
      Error (Invalid_format { location = "<string>"; message = e.err_msg })
  | Failure msg ->
      Error (Invalid_format { location = "<string>"; message = msg })
