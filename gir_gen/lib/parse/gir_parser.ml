(* GIR XML Parser using xmlm *)

open StdLabels
open Types
module StringSet = Set.Make (String)

(* Accumulator for folding the children of a <class> or <interface>
   element. [cc_methods] and [cc_virtual_methods] are kept separate so
   [merge_methods] can dedupe at the end; [cc_implements] is used by <class>
   and [cc_prerequisites] by <interface>. *)
type class_contents = {
  cc_constructors : gir_constructor list;
  cc_methods : gir_method list;
  cc_virtual_methods : gir_method list;
  cc_properties : gir_property list;
  cc_signals : gir_signal list;
  cc_implements : string list;
  cc_prerequisites : string list;
  cc_doc : string option;
  cc_deprecated_doc : string option;
}

(* Namespace-resolution context. [ns] maps an XML namespace prefix (e.g. "c",
   "glib") to its URI. The mapping is built from the document's own xmlns
   declarations — which Xmlm surfaces as attributes on the root element — by
   [make_ctx], so the parser hardcodes no prefix→URI knowledge: Xmlm resolves
   the prefixes from the document, we collect them. [get_attr] uses [ctx.ns]
   to turn a prefixed attribute name like "c:type" into the (uri, local) pair
   Xmlm produces in the attribute list. *)
type ctx = { ns : string -> string option }

(* The xmlns namespace, under which namespace declarations appear as
   attributes (xmlns:c="...", xmlns:glib="..."). *)
let xmlns_uri = "http://www.w3.org/2000/xmlns/"

(* [make_ctx root_attrs] builds a namespace context from the root element's
   attributes: every attribute in the xmlns namespace whose local name is a
   real prefix (i.e. not the default-namespace declaration "xmlns") contributes
   prefix → URI. *)
let make_ctx (root_attrs : Xmlm.attribute list) : ctx =
  let map =
    List.fold_left root_attrs ~init:[] ~f:(fun acc ((uri, local), v) ->
        if String.equal uri xmlns_uri && not (String.equal local "xmlns") then
          (local, v) :: acc
        else acc)
  in
  { ns = (fun prefix -> List.assoc_opt prefix map) }

(* [peek_root_ctx input] peeks the document's root element (skipping any Dtd)
   and builds a namespace context from its xmlns declarations. The root's
   [`El_start] is left unconsumed so the caller's fold reads it normally. *)
let peek_root_ctx input =
  let rec skip () =
    match Xmlm.peek input with
    | `Dtd _ ->
        ignore (Xmlm.input input);
        skip ()
    | `El_start (_, attrs) -> attrs
    | _ -> failwith "gir_parser: expected root element"
  in
  make_ctx (skip ())

(* [get_attr ~ctx name attrs] looks up attribute [name] in [attrs]. [name] may
   carry a namespace prefix (e.g. "c:type", "glib:get-type"); the prefix is
   resolved to its URI via [ctx.ns] and the attribute is looked up as the
   (uri, local) pair Xmlm produces. A name with no prefix is looked up in the
   default namespace ("", name) — where unprefixed attributes live, since
   XML's default namespace does not apply to attributes. *)
let get_attr ~ctx name attrs =
  match String.index_opt name ':' with
  | Some idx -> (
      let prefix = String.sub name ~pos:0 ~len:idx in
      let local =
        String.sub name ~pos:(idx + 1) ~len:(String.length name - idx - 1)
      in
      match ctx.ns prefix with
      | Some uri -> List.assoc_opt (uri, local) attrs
      | None -> None)
  | None -> List.assoc_opt ("", name) attrs

let ns namespace =
  match namespace with
  | "glib" -> Some "http://www.gtk.org/introspection/glib/1.0"
  | "gtk" -> Some "http://www.gtk.org/introspection/c/1.0"
  | _ -> None

(* Common helper: extract local name from potentially namespaced tag *)
let local_name tag =
  match String.index_opt tag ':' with
  | Some idx -> String.sub ~pos:(idx + 1) ~len:(String.length tag - idx - 1) tag
  | None -> tag

(* Common helper: skip to end of current element. Delegates to the
   canonical [Gir_xml_fold.skip_element] so the imperative primitive lives in
   one place; the parser only references it for the few genuine cases (entry
   guards on missing element attributes, [parse_doc_text] skipping markup,
   and the GLib.HashTable <type> body that has no element type). *)
let skip_element = Gir_xml_fold.skip_element

(* [guard_element ~input ~attrs ~extract build] is the entry-guard idiom of a
   [parse_X] function: if the element's required attributes ([extract attrs])
   are missing, skip the whole element and return [None]; otherwise [build v]
   consumes the element and returns [Some result]. It is the declarative form
   of [match required_attrs with Some _ -> parse_body | _ -> skip_element
   input 1; None], removing the imperative skip from the head of every
   parse_X. *)
let guard_element ~input ~attrs ~extract build =
  match extract attrs with
  | Some v -> build v
  | None ->
      skip_element input 1;
      None

(* Common helper: extract text content from a <doc> element, skipping nested
   XML elements (e.g. <link>, <code>) rather than failing on them. This is
   the single doc-text extractor of the parser; every doc-bearing site routes
   through it. *)
let rec parse_doc_text input ?(text = "") () =
  match Xmlm.input input with
  | `Data s -> parse_doc_text input ~text:(text ^ s) ()
  | `El_end -> if text = "" then None else Some text
  | `El_start _ ->
      skip_element input 1;
      parse_doc_text input ~text ()
  | `Dtd _ -> parse_doc_text input ~text ()

(* Build the [gir_deprecation] carried by an element's [deprecated] and
   [deprecated-version] attributes; [None] when the element carries no
   deprecation marker. The <doc-deprecated> prose is attached later by
   [add_deprecated_doc]. *)
let deprecation_of_attrs ~ctx attrs =
  let deprecated = get_attr ~ctx "deprecated" attrs |> Utils.parse_bool in
  let deprecated_version = get_attr ~ctx "deprecated-version" attrs in
  if deprecated || Option.is_some deprecated_version then
    Some { deprecated; deprecated_version; deprecated_doc = None }
  else None

(* Attach <doc-deprecated> prose [d] to [deprecation]. An empty
   <doc-deprecated> on an element with no deprecation attributes leaves the
   accumulator unchanged (all three fields absent → [None]). *)
let add_deprecated_doc d deprecation =
  match (deprecation, d) with
  | None, None -> None
  | Some dep, None -> Some dep
  | dep_opt, Some doc ->
      Some
        (match dep_opt with
        | Some dep -> { dep with deprecated_doc = Some doc }
        | None ->
            {
              deprecated = false;
              deprecated_version = None;
              deprecated_doc = Some doc;
            })

(* Dispatch-arm fragments for the two doc-carrying children shared by every
   doc-bearing element: <doc> is the element's primary prose,
   <doc-deprecated> its deprecation prose. Both are read by
   [parse_doc_text]; the setters store the extracted text (None for an empty
   element) into the site's accumulator. Composed under a site's own
   dispatch with a trailing [| tag -> doc_arms ... tag] arm; other tags
   yield [None] so the fold skips them. *)
let doc_arms ~input ~(doc : string option -> 'acc -> 'acc)
    ~(deprecated_doc : string option -> 'acc -> 'acc) :
    Xmlm.name -> 'acc Gir_xml_fold.handler option = function
  | _, "doc" -> Some (fun ~attrs:_ acc -> doc (parse_doc_text input ()) acc)
  | _, "doc-deprecated" ->
      Some (fun ~attrs:_ acc -> deprecated_doc (parse_doc_text input ()) acc)
  | _ -> None

(* Fold a <member>'s children for its optional <doc> and <doc-deprecated>
   children, read by [parse_doc_text]. Shared by [parse_enumeration] and
   [parse_bitfield]; returns the (doc, deprecated_doc) pair. *)
let parse_member_doc input =
  Gir_xml_fold.fold_element ~input
    ~dispatch:
      (doc_arms ~input
         ~doc:(fun d (_, dd) -> (d, dd))
         ~deprecated_doc:(fun d (doc, _) -> (doc, d)))
    ~init:(None, None) ()

(* Extract the (name, value, c:identifier) triple that every <member> /
   <flag> must carry; [None] means the child is malformed and should be
   skipped. *)
let member_attrs ~ctx attrs =
  let open Containers.Option.Infix in
  let+ member_name = get_attr ~ctx "name" attrs
  and+ value_str = get_attr ~ctx "value" attrs
  and+ c_id = get_attr ~ctx "c:identifier" attrs in
  (member_name, value_str, c_id)

(* Extract the (name, c:identifier) pair that <method>, <virtual-method>,
   and <constructor> all carry; [None] means the child is malformed and should
   be skipped. *)
let name_and_c_identifier ~ctx attrs =
  let open Containers.Option.Infix in
  let+ name = get_attr ~ctx "name" attrs
  and+ c_id = get_attr ~ctx "c:identifier" attrs in
  (name, c_id)

(* Shared: Parse enumeration element. <member> recurses into [fold_element]
   for its <doc>; <function> is dispatched to the optional [parse_functions]
   callback (or skipped when none is supplied, e.g. for external namespaces). *)
let parse_enumeration ~ctx input ?parse_functions attrs =
  let build (name, c_type) =
    let init =
      {
        enum_name = name;
        enum_c_type = c_type;
        members = [];
        functions = [];
        enum_doc = None;
        enum_version = get_attr ~ctx "version" attrs;
        enum_os = None;
        deprecation = deprecation_of_attrs ~ctx attrs;
      }
    in
    let dispatch = function
      | _, "member" ->
          Some
            (Gir_xml_fold.required ~input ~extract:(member_attrs ~ctx)
               ~build:(fun ~attrs (member_name, value_str, c_id) acc ->
                 let value =
                   Option.value ~default:0 (int_of_string_opt value_str)
                 in
                 let member_doc, member_deprecated_doc =
                   parse_member_doc input
                 in
                 let member_deprecation =
                   add_deprecated_doc member_deprecated_doc
                     (deprecation_of_attrs ~ctx attrs)
                 in
                 {
                   acc with
                   members =
                     {
                       member_name;
                       member_value = value;
                       c_identifier = c_id;
                       member_doc;
                       member_version = get_attr ~ctx "version" attrs;
                       member_os = None;
                       deprecation = member_deprecation;
                     }
                     :: acc.members;
                 }))
      | _, "function" -> (
          match parse_functions with
          | Some parse_fn ->
              Some
                (fun ~attrs acc ->
                  let function_ = parse_fn input attrs in
                  { acc with functions = function_ :: acc.functions })
          | None -> None)
      | tag ->
          doc_arms ~input
            ~doc:(fun d acc -> { acc with enum_doc = d })
            ~deprecated_doc:(fun d acc ->
              { acc with deprecation = add_deprecated_doc d acc.deprecation })
            tag
    in
    let result = Gir_xml_fold.fold_element ~input ~dispatch ~init () in
    (* [functions] is intentionally not reversed, matching the original. *)
    Some { result with members = List.rev result.members }
  in
  guard_element ~input ~attrs
    ~extract:(fun attrs ->
      let open Containers.Option.Infix in
      let+ name = get_attr ~ctx "name" attrs
      and+ c_type = get_attr ~ctx "c:type" attrs in
      (name, c_type))
    build

(* Shared: Merge concrete and virtual methods, removing duplicates *)
let merge_methods ~concrete ~virtuals =
  let is_dup m =
    List.exists
      ~f:(fun (c : gir_method) ->
        c.method_name = m.method_name || c.c_identifier = m.c_identifier)
      concrete
  in
  concrete @ List.filter ~f:(fun m -> not (is_dup m)) virtuals

(* [element_type_of_type_child] parses the element type nested inside a
   container <type> (e.g. the <type> child of <return-value> or <parameter>'s
   <type>). GLib.HashTable is special-cased: its body carries key/value
   types that we don't model, so the body is skipped and [None] is returned.
   [transfer_ownership] is the container's transfer, inherited by the element
   type. The body + matching [`El_end] are consumed in either branch. *)
let element_type_of_type_child ~ctx ~input ~type_name ~transfer_ownership =
  if Gir_type_pred.is_hash_table_name type_name then begin
    skip_element input 1;
    None
  end
  else
    Gir_xml_fold.fold_element ~input
      ~dispatch:(function
        | _, "type" ->
            Some
              (Gir_xml_fold.leaf ~input (fun ~attrs _ ->
                   let elem_name =
                     Option.value ~default:"unknown"
                       (get_attr ~ctx "name" attrs)
                   in
                   let elem_c_type = get_attr ~ctx "c:type" attrs in
                   Some
                     {
                       name = elem_name;
                       c_type = elem_c_type;
                       nullable = false;
                       transfer_ownership;
                       array = None;
                     }))
        | _ -> None)
      ~init:None ()

(* [array_of_element_type] wraps a parsed element type into a [gir_type]'s
   [array] field: an unbounded single-element array named after the container
   type, or [None] when there was no element type (e.g. GLib.HashTable, or a
   <type> with no nested <type> child). *)
let array_of_element_type ~type_name = function
  | None -> None
  | Some element_type ->
      Some
        {
          Types.length = None;
          zero_terminated = false;
          fixed_size = None;
          element_type;
          array_name = Some type_name;
        }

(* Shared: Parse bitfield element. [Gir_xml_fold.fold_element] owns the
   sibling-advance loop; each <member> handler consumes its child (recursing
   into [parse_member_doc] for its <doc>) and prepends to [flags]. The list is
   reversed once at the end. *)
let parse_bitfield ~ctx input attrs =
  let build (name, c_type) =
    let init =
      {
        bitfield_name = name;
        bitfield_c_type = c_type;
        flags = [];
        bitfield_doc = None;
        bitfield_version = get_attr ~ctx "version" attrs;
        bitfield_os = None;
        deprecation = deprecation_of_attrs ~ctx attrs;
      }
    in
    let dispatch = function
      | _, "member" ->
          Some
            (Gir_xml_fold.required ~input ~extract:(member_attrs ~ctx)
               ~build:(fun ~attrs (flag_name, value_str, c_id) acc ->
                 let value =
                   Option.value ~default:0 (int_of_string_opt value_str)
                 in
                 let flag_doc, flag_deprecated_doc = parse_member_doc input in
                 let flag_deprecation =
                   add_deprecated_doc flag_deprecated_doc
                     (deprecation_of_attrs ~ctx attrs)
                 in
                 {
                   acc with
                   flags =
                     {
                       flag_name;
                       flag_value = value;
                       flag_c_identifier = c_id;
                       flag_doc;
                       flag_version = get_attr ~ctx "version" attrs;
                       flag_os = None;
                       deprecation = flag_deprecation;
                     }
                     :: acc.flags;
                 }))
      | tag ->
          doc_arms ~input
            ~doc:(fun d acc -> { acc with bitfield_doc = d })
            ~deprecated_doc:(fun d acc ->
              { acc with deprecation = add_deprecated_doc d acc.deprecation })
            tag
    in
    let result = Gir_xml_fold.fold_element ~input ~dispatch ~init () in
    Some { result with flags = List.rev result.flags }
  in
  guard_element ~input ~attrs
    ~extract:(fun attrs ->
      let open Containers.Option.Infix in
      let+ name = get_attr ~ctx "name" attrs
      and+ c_type = get_attr ~ctx "c:type" attrs in
      (name, c_type))
    build

(* Parse constant element. <type> is a leaf (attributes only, body skipped via
   [Gir_xml_fold.leaf]); <doc> is a text leaf read by [parse_doc_text]. *)
let parse_constant ~ctx input attrs =
  let build (name, value, c_type) =
    let init =
      {
        constant_name = name;
        constant_c_type = c_type;
        value;
        value_type =
          {
            name = "void";
            c_type = None;
            nullable = false;
            transfer_ownership = Types.TransferNone;
            array = None;
          };
        constant_doc = None;
        version = get_attr ~ctx "version" attrs;
        os = None;
        introspectable =
          get_attr ~ctx "introspectable" attrs |> Utils.parse_bool ~default:true;
        deprecation = deprecation_of_attrs ~ctx attrs;
      }
    in
    let dispatch = function
      | _, "type" ->
          Some
            (Gir_xml_fold.leaf ~input (fun ~attrs acc ->
                 let type_name =
                   match get_attr ~ctx "name" attrs with
                   | Some n -> n
                   | None -> "void"
                 in
                 let c_type_name = get_attr ~ctx "c:type" attrs in
                 let nullable =
                   get_attr ~ctx "nullable" attrs |> Utils.parse_bool
                 in
                 {
                   acc with
                   value_type =
                     {
                       name = type_name;
                       c_type = c_type_name;
                       nullable;
                       transfer_ownership = Types.TransferNone;
                       array = None;
                     };
                 }))
      | tag ->
          doc_arms ~input
            ~doc:(fun d acc -> { acc with constant_doc = d })
            ~deprecated_doc:(fun d acc ->
              { acc with deprecation = add_deprecated_doc d acc.deprecation })
            tag
    in
    Some (Gir_xml_fold.fold_element ~input ~dispatch ~init ())
  in
  guard_element ~input ~attrs
    ~extract:(fun attrs ->
      let open Containers.Option.Infix in
      let+ name = get_attr ~ctx "name" attrs
      and+ value = get_attr ~ctx "value" attrs
      and+ c_type = get_attr ~ctx "c:type" attrs in
      (name, value, c_type))
    build

(* Parse only enums and bitfields from a GIR file (for external namespaces) *)
let parse_gir_enums_only filename =
  let ic = open_in filename in
  let input = Xmlm.make_input ~ns ~strip:true (`Channel ic) in
  (* Build the namespace context from the root's xmlns declarations; the
     root's [`El_start] is left for the fold below to consume. *)
  let ctx = peek_root_ctx input in

  let enums = ref [] in
  let bitfields = ref [] in

  (* Main parsing loop - only look for enums and bitfields. <repository> and
     <namespace> are descended into via a nested [fold_element] so the enums
     and bitfields inside the namespace are found. *)
  let rec dispatch = function
    | _, "enumeration" ->
        Some
          (fun ~attrs () ->
            match parse_enumeration ~ctx input attrs with
            | Some enum -> enums := enum :: !enums
            | None -> ())
    | _, "bitfield" ->
        Some
          (fun ~attrs () ->
            match parse_bitfield ~ctx input attrs with
            | Some bitfield -> bitfields := bitfield :: !bitfields
            | None -> ())
    | _, "repository" | _, "namespace" ->
        Some
          (fun ~attrs:_ () ->
            Gir_xml_fold.fold_element ~input ~dispatch ~init:() ())
    | _ -> None
  in

  Gir_xml_fold.fold_document ~input ~dispatch ~init:() ();
  close_in ic;
  (List.rev !enums, List.rev !bitfields)

(* Parse a full GIR file including classes, interfaces, enums, and bitfields *)
let parse_gir_file filename filter_classes =
  let ic = open_in filename in
  let input = Xmlm.make_input ~strip:true (`Channel ic) in
  (* Build the namespace context from the root's xmlns declarations; the
     root's [`El_start] is left for the fold below to consume. *)
  let ctx = peek_root_ctx input in

  let controllers = ref [] in
  let interfaces : gir_interface list ref = ref [] in
  let enums = ref [] in
  let bitfields = ref [] in
  let records : gir_record list ref = ref [] in
  let constants = ref [] in
  let namespace : gir_namespace option ref = ref None in
  let repository =
    ref
      {
        repository_c_includes = [];
        repository_includes = [];
        repository_packages = [];
        repository_doc_format = None;
      }
  in

  let normalized_filters =
    List.fold_left filter_classes ~init:StringSet.empty ~f:(fun acc name ->
        StringSet.add
          (Utils.normalize_class_name name |> String.lowercase_ascii)
          acc)
  in
  let should_include_class name =
    if StringSet.is_empty normalized_filters then true
    else
      let normalized =
        Utils.normalize_class_name name |> String.lowercase_ascii
      in
      StringSet.mem normalized normalized_filters
  in

  (* Parse a class element *)
  let rec parse_class attrs =
    let build name =
      let c_type =
        match get_attr ~ctx "c:type" attrs with
        | Some t -> t
        | None ->
            (* Use namespace c:identifier-prefixes; if no namespace is set the
              file is malformed and there is nothing useful to generate. *)
            let prefix =
              match !namespace with
              | Some ns -> ns.namespace_c_identifier_prefixes
              | None ->
                  failwith
                    "gir_parser: <class> missing c:type and no namespace \
                     c:identifier-prefixes available"
            in
            prefix ^ name
      in
      let parent = get_attr ~ctx "parent" attrs in
      let introspectable =
        get_attr ~ctx "introspectable" attrs |> Utils.parse_bool ~default:true
      in
      let init =
        {
          cc_constructors = [];
          cc_methods = [];
          cc_virtual_methods = [];
          cc_properties = [];
          cc_signals = [];
          cc_implements = [];
          cc_prerequisites = [];
          cc_doc = None;
          cc_deprecated_doc = None;
        }
      in
      let dispatch = function
        | _, "implements" ->
            Some
              (Gir_xml_fold.leaf ~input (fun ~attrs acc ->
                   {
                     acc with
                     cc_implements =
                       (match get_attr ~ctx "name" attrs with
                       | Some n -> n :: acc.cc_implements
                       | None -> acc.cc_implements);
                   }))
        | _, "constructor" ->
            Some
              (Gir_xml_fold.required ~input
                 ~extract:(name_and_c_identifier ~ctx)
                 ~build:(fun ~attrs (ctor_name, c_id) acc ->
                   let c = build_constructor ~attrs (ctor_name, c_id) in
                   { acc with cc_constructors = c :: acc.cc_constructors }))
        | _, "signal" ->
            Some
              (fun ~attrs acc ->
                match parse_signal attrs with
                | Some signal ->
                    { acc with cc_signals = signal :: acc.cc_signals }
                | None -> acc (* already skipped by parse_signal *))
        | _, "method" ->
            Some
              (Gir_xml_fold.required ~input
                 ~extract:(name_and_c_identifier ~ctx)
                 ~build:(fun ~attrs (method_name, c_id) acc ->
                   let m = build_method ~attrs (method_name, c_id) in
                   { acc with cc_methods = m :: acc.cc_methods }))
        | _, "virtual-method" ->
            Some
              (Gir_xml_fold.required ~input
                 ~extract:(name_and_c_identifier ~ctx)
                 ~build:(fun ~attrs (method_name, c_id) acc ->
                   let m = build_method ~attrs (method_name, c_id) in
                   { acc with cc_virtual_methods = m :: acc.cc_virtual_methods }))
        | _, "property" ->
            Some
              (Gir_xml_fold.required ~input
                 ~extract:(fun attrs -> get_attr ~ctx "name" attrs)
                 ~build:(fun ~attrs prop_name acc ->
                   let prop = parse_property prop_name attrs in
                   { acc with cc_properties = prop :: acc.cc_properties }))
        | tag ->
            doc_arms ~input
              ~doc:(fun d acc -> { acc with cc_doc = d })
              ~deprecated_doc:(fun d acc -> { acc with cc_deprecated_doc = d })
              tag
      in
      let cc = Gir_xml_fold.fold_element ~input ~dispatch ~init () in
      let methods =
        merge_methods ~concrete:(List.rev cc.cc_methods)
          ~virtuals:(List.rev cc.cc_virtual_methods)
      in
      Some
        {
          class_name = name;
          c_type;
          parent;
          implements = List.rev cc.cc_implements;
          introspectable;
          constructors = List.rev cc.cc_constructors;
          methods;
          properties = List.rev cc.cc_properties;
          signals = List.rev cc.cc_signals;
          class_doc = cc.cc_doc;
          version = get_attr ~ctx "version" attrs;
          os = None;
          deprecation =
            add_deprecated_doc cc.cc_deprecated_doc
              (deprecation_of_attrs ~ctx attrs);
        }
    in
    guard_element ~input ~attrs
      ~extract:(fun attrs ->
        Option.bind (get_attr ~ctx "name" attrs) (fun name ->
            if should_include_class name then Some name else None))
      build
  (* Parse property element *)
  and parse_property prop_name attrs =
    let readable =
      match get_attr ~ctx "readable" attrs with Some "0" -> false | _ -> true
    in
    let writable =
      match get_attr ~ctx "writable" attrs with Some "1" -> true | _ -> false
    in
    let construct_only =
      match get_attr ~ctx "construct-only" attrs with
      | Some "1" -> true
      | _ -> false
    in
    let property_nullable =
      get_attr ~ctx "nullable" attrs |> Utils.parse_bool
    in
    (* Fold the property's children into (prop_type, prop_doc,
       deprecated_doc). <type> is a leaf, <array> is consumed by
       [parse_array_type], and <doc>/<doc-deprecated> are read by
       [parse_doc_text] via [doc_arms]. *)
    let init =
      ( {
          name = "unknown";
          c_type = None;
          nullable = false;
          transfer_ownership = Types.TransferNone;
          array = None;
        },
        None,
        None )
    in
    let dispatch = function
      | _, "type" ->
          Some
            (Gir_xml_fold.leaf ~input (fun ~attrs (_ptype, pdoc, ddoc) ->
                 let type_name =
                   Option.value ~default:"unknown" (get_attr ~ctx "name" attrs)
                 in
                 let c_type_name = get_attr ~ctx "c:type" attrs in
                 let nullable =
                   get_attr ~ctx "nullable" attrs |> Utils.parse_bool
                   || property_nullable
                 in
                 ( {
                     name = type_name;
                     c_type = c_type_name;
                     nullable;
                     transfer_ownership = Types.TransferNone;
                     array = None;
                   },
                   pdoc,
                   ddoc )))
      | _, "array" ->
          Some
            (fun ~attrs (_ptype, pdoc, ddoc) ->
              let array_info =
                parse_array_type attrs Types.TransferNone property_nullable
              in
              ( {
                  name = "array";
                  c_type = get_attr ~ctx "c:type" attrs;
                  nullable = property_nullable;
                  transfer_ownership = Types.TransferNone;
                  array = array_info;
                },
                pdoc,
                ddoc ))
      | tag ->
          doc_arms ~input
            ~doc:(fun d (ptype, _, ddoc) -> (ptype, d, ddoc))
            ~deprecated_doc:(fun d (ptype, pdoc, _) -> (ptype, pdoc, d))
            tag
    in
    let prop_type, prop_doc, prop_deprecated_doc =
      Gir_xml_fold.fold_element ~input ~dispatch ~init ()
    in
    {
      prop_name;
      prop_type;
      readable;
      writable;
      construct_only;
      prop_doc;
      version = get_attr ~ctx "version" attrs;
      version_namespace = None;
      os = None;
      deprecation =
        add_deprecated_doc prop_deprecated_doc (deprecation_of_attrs ~ctx attrs);
    }
  (* [fold_callable_body] folds the children shared by <method>,
     <virtual-method>, <constructor>, and <signal> into
     (return_type, params, doc, return_doc, deprecated_doc):
     <return-value> via [parse_return_value], <parameters> via
     [parse_parameters], <doc>/<doc-deprecated> via [doc_arms].
     [params] is in reverse order; callers [List.rev] it. *)
  and fold_callable_body () =
    let void_type =
      {
        name = "void";
        c_type = None;
        nullable = false;
        transfer_ownership = Types.TransferNone;
        array = None;
      }
    in
    let dispatch = function
      | _, "return-value" ->
          Some
            (fun ~attrs (_rt, params, doc, _rdoc, ddoc) ->
              let rt', rdoc = parse_return_value attrs in
              (rt', params, doc, rdoc, ddoc))
      | _, "parameters" ->
          Some
            (fun ~attrs:_ (rt, _params, doc, rdoc, ddoc) ->
              (rt, parse_parameters (), doc, rdoc, ddoc))
      | tag ->
          doc_arms ~input
            ~doc:(fun d (rt, params, _, rdoc, ddoc) ->
              (rt, params, d, rdoc, ddoc))
            ~deprecated_doc:(fun d (rt, params, doc, rdoc, _) ->
              (rt, params, doc, rdoc, d))
            tag
    in
    Gir_xml_fold.fold_element ~input ~dispatch
      ~init:(void_type, [], None, None, None)
      ()
  (* Fold a method/virtual-method/constructor body via [fold_callable_body].
     The glib:get/set-property attributes are read by [build_method] from the
     element's own [attrs]. *)
  and parse_method () =
    let return_type, params, doc, return_doc, deprecated_doc =
      fold_callable_body ()
    in
    (return_type, List.rev params, doc, return_doc, deprecated_doc)
  (* [build_method] is the shared body of a <method> or <virtual-method>:
     given the (name, c:identifier) pair — already validated by the caller via
     [Gir_xml_fold.required] on [name_and_c_identifier] — it reads the
     throws/introspectable attributes and folds the child body via
     [parse_method], returning the resulting [gir_method]. The caller's
     [required] guard skips malformed children (missing name/c:identifier), so
     this is only called with a valid pair; no [skip_element] / [option] here. *)
  and build_method ~attrs (method_name, c_id) =
    let throws = get_attr ~ctx "throws" attrs |> Utils.parse_bool in
    let introspectable =
      get_attr ~ctx "introspectable" attrs |> Utils.parse_bool ~default:true
    in
    let get_property = get_attr ~ctx "glib:get-property" attrs in
    let set_property = get_attr ~ctx "glib:set-property" attrs in
    let return_type, params, doc, return_doc, deprecated_doc =
      parse_method ()
    in
    {
      method_name;
      c_identifier = c_id;
      return_type;
      parameters = params;
      doc;
      return_doc;
      throws;
      get_property;
      set_property;
      introspectable;
      version = get_attr ~ctx "version" attrs;
      version_namespace = None;
      os = None;
      deprecation =
        add_deprecated_doc deprecated_doc (deprecation_of_attrs ~ctx attrs);
    }
  (* [build_constructor] is the shared body of a <constructor>: given the
     (name, c:identifier) pair — validated by the caller via [required] — it
     reads the throws/introspectable attributes and folds the child body via
     [parse_method] (using only params/doc), returning the resulting
     [gir_constructor]. *)
  and build_constructor ~attrs (ctor_name, c_id) =
    let throws = get_attr ~ctx "throws" attrs = Some "1" in
    let ctor_introspectable =
      get_attr ~ctx "introspectable" attrs |> Utils.parse_bool ~default:true
    in
    let _return_type, params, doc, _return_doc, deprecated_doc =
      parse_method ()
    in
    {
      ctor_name;
      c_identifier = c_id;
      ctor_parameters = params;
      ctor_doc = doc;
      throws;
      ctor_introspectable;
      version = get_attr ~ctx "version" attrs;
      version_namespace = None;
      os = None;
      deprecation =
        add_deprecated_doc deprecated_doc (deprecation_of_attrs ~ctx attrs);
    }
  (* Parse glib:signal elements via [fold_callable_body]. *)
  and parse_signal attrs =
    let build signal_name =
      let return_type, params, doc, return_doc, deprecated_doc =
        fold_callable_body ()
      in
      let run_when =
        match get_attr ~ctx "when" attrs with
        | Some "first" -> Some Types.RunFirst
        | Some "last" -> Some Types.RunLast
        | Some "cleanup" -> Some Types.RunCleanup
        | Some other ->
            failwith
              (Printf.sprintf
                 "Invalid 'when' attribute value on signal '%s': %s" signal_name
                 other)
        | None -> None
      in
      Some
        {
          signal_name;
          return_type;
          sig_parameters = List.rev params;
          doc;
          return_doc;
          version = get_attr ~ctx "version" attrs;
          version_namespace = None;
          os = None;
          run_when;
          action = get_attr ~ctx "action" attrs |> Utils.parse_bool;
          no_recurse = get_attr ~ctx "no-recurse" attrs |> Utils.parse_bool;
          no_hooks = get_attr ~ctx "no-hooks" attrs |> Utils.parse_bool;
          deprecation =
            add_deprecated_doc deprecated_doc (deprecation_of_attrs ~ctx attrs);
        }
    in
    guard_element ~input ~attrs ~extract:(get_attr ~ctx "name") build
  (* Parse array element *)
  and parse_array_type attrs transfer_ownership_attr nullable_attr =
    let length =
      match get_attr ~ctx "length" attrs with
      | Some s -> int_of_string_opt s
      | None -> None
    in
    let zero_terminated =
      get_attr ~ctx "zero-terminated" attrs |> Utils.parse_bool
    in
    let fixed_size =
      match get_attr ~ctx "fixed-size" attrs with
      | Some s -> int_of_string_opt s
      | None -> None
    in
    let array_name = get_attr ~ctx "name" attrs in
    (* Parse the element type from the nested <type> child. *)
    let init =
      {
        name = "unknown";
        c_type = None;
        nullable = false;
        transfer_ownership = transfer_ownership_attr;
        array = None;
      }
    in
    let dispatch = function
      | _, "type" ->
          Some
            (Gir_xml_fold.leaf ~input (fun ~attrs _acc ->
                 let type_name =
                   Option.value ~default:"unknown" (get_attr ~ctx "name" attrs)
                 in
                 let c_type_name = get_attr ~ctx "c:type" attrs in
                 let nullable =
                   get_attr ~ctx "nullable" attrs |> Utils.parse_bool
                   || nullable_attr
                 in
                 {
                   name = type_name;
                   c_type = c_type_name;
                   nullable;
                   transfer_ownership = transfer_ownership_attr;
                   array = None;
                 }))
      | _ -> None
    in
    let element_type = Gir_xml_fold.fold_element ~input ~dispatch ~init () in
    Some { Types.length; zero_terminated; fixed_size; element_type; array_name }
  (* Parse return value type. <type> is not a leaf here: for non-HashTable
     types a nested <type> child is parsed as the element type and wrapped in
     an array info; GLib.HashTable is skipped (it carries key/value types, not
     an element type). <array> is consumed by [parse_array_type]. *)
  (* Parse return value type. <type> is not a leaf here: for non-HashTable
     types a nested <type> child is parsed as the element type and wrapped in
     an array info; GLib.HashTable is skipped (it carries key/value types, not
     an element type). <array> is consumed by [parse_array_type]. The fold
     accumulates (return_type, return_doc); <doc> is read by
     [parse_doc_text]. *)
  and parse_return_value attrs =
    let nullable_attr = get_attr ~ctx "nullable" attrs |> Utils.parse_bool in
    let transfer_ownership_attr =
      match get_attr ~ctx "transfer-ownership" attrs with
      | Some "none" -> Types.TransferNone
      | Some "full" -> Types.TransferFull
      | Some "container" -> Types.TransferContainer
      | Some "floating" -> Types.TransferFloating
      | _ -> Types.TransferNone (* default to none if not specified *)
    in
    let init =
      ( {
          name = "void";
          c_type = None;
          nullable = nullable_attr;
          transfer_ownership = transfer_ownership_attr;
          array = None;
        },
        None )
    in
    let dispatch = function
      | _, "type" ->
          Some
            (fun ~attrs (_t, rdoc) ->
              let type_name =
                Option.value ~default:"void" (get_attr ~ctx "name" attrs)
              in
              let c_type_name = get_attr ~ctx "c:type" attrs in
              let nullable =
                get_attr ~ctx "nullable" attrs |> Utils.parse_bool
                || nullable_attr
              in
              let element_type =
                element_type_of_type_child ~ctx ~input ~type_name
                  ~transfer_ownership:transfer_ownership_attr
              in
              ( {
                  name = type_name;
                  c_type = c_type_name;
                  nullable;
                  transfer_ownership = transfer_ownership_attr;
                  array = array_of_element_type ~type_name element_type;
                },
                rdoc ))
      | _, "array" ->
          Some
            (fun ~attrs (_t, rdoc) ->
              let array_info =
                parse_array_type attrs transfer_ownership_attr nullable_attr
              in
              ( {
                  name = "array";
                  c_type = get_attr ~ctx "c:type" attrs;
                  nullable = nullable_attr;
                  transfer_ownership = transfer_ownership_attr;
                  array = array_info;
                },
                rdoc ))
      | _, "doc" -> Some (fun ~attrs:_ (t, _) -> (t, parse_doc_text input ()))
      | _ -> None
    in
    Gir_xml_fold.fold_element ~input ~dispatch ~init ()
  and parse_function attrs =
    let function_name = get_attr ~ctx "name" attrs in
    let c_identifier = get_attr ~ctx "c:identifier" attrs in
    let throws = get_attr ~ctx "throws" attrs |> Utils.parse_bool in
    let introspectable =
      get_attr ~ctx "introspectable" attrs |> Utils.parse_bool ~default:true
    in
    (* Fold the function's children into
       (return_type, params, doc, return_doc, deprecated_doc).
       <return-value> keeps the leaf-based attribute read of the original
       parser (its name/c:type/nullable attributes, children skipped) but is
       now a fold so its <doc> child feeds [return_doc]; <parameters> is
       consumed by [parse_parameters]; <doc>/<doc-deprecated> by [doc_arms]. *)
    let dispatch = function
      | _, "return-value" ->
          Some
            (fun ~attrs (_rt, params, doc, rdoc, ddoc) ->
              let type_name =
                Option.value ~default:"void" (get_attr ~ctx "name" attrs)
              in
              let c_type_name = get_attr ~ctx "c:type" attrs in
              let nullable =
                get_attr ~ctx "nullable" attrs
                |> Utils.parse_bool ~default:false
              in
              let return_doc =
                Gir_xml_fold.fold_element ~input
                  ~dispatch:(function
                    | _, "doc" ->
                        Some (fun ~attrs:_ _ -> parse_doc_text input ())
                    | _ -> None)
                  ~init:rdoc ()
              in
              ( Some
                  {
                    name = type_name;
                    c_type = c_type_name;
                    nullable;
                    transfer_ownership = Types.TransferNone;
                    array = None;
                  },
                params,
                doc,
                return_doc,
                ddoc ))
      | _, "parameters" ->
          Some
            (fun ~attrs:_ (rt, _params, doc, rdoc, ddoc) ->
              (rt, parse_parameters (), doc, rdoc, ddoc))
      | tag ->
          doc_arms ~input
            ~doc:(fun d (rt, params, _, rdoc, ddoc) ->
              (rt, params, d, rdoc, ddoc))
            ~deprecated_doc:(fun d (rt, params, doc, rdoc, _) ->
              (rt, params, doc, rdoc, d))
            tag
    in
    let return_type, params, doc, return_doc, deprecated_doc =
      Gir_xml_fold.fold_element ~input ~dispatch
        ~init:(None, [], None, None, None)
        ()
    in
    match (function_name, c_identifier, return_type) with
    | Some function_name, Some c_identifier, Some return_type ->
        {
          function_name;
          c_identifier;
          return_type;
          parameters = List.rev params;
          doc;
          return_doc;
          throws;
          introspectable;
          version = get_attr ~ctx "version" attrs;
          version_namespace = None;
          os = None;
          deprecation =
            add_deprecated_doc deprecated_doc (deprecation_of_attrs ~ctx attrs);
        }
    | _, _, _ -> failwith "Unable to parse function correctly"
  (* [parse_parameter_type] folds a <parameter>'s children into
     (param_type, varargs, param_doc): <varargs> marks the parameter as
     variadic, <type> is the parameter type (with an optional nested element
     type for containers), <array> is consumed by [parse_array_type], and
     <doc> is read by [parse_doc_text]. [param_attrs] are the <parameter>'s
     own attributes, captured so the <array> handler can read the
     parameter-level nullable flag. [transfer_ownership] is the parameter's
     transfer, inherited by the type and array. *)
  and parse_parameter_type ~param_attrs ~transfer_ownership () =
    let init_type =
      ( {
          name = "void";
          c_type = None;
          nullable = false;
          transfer_ownership;
          array = None;
        },
        false,
        None )
    in
    Gir_xml_fold.fold_element ~input
      ~dispatch:(function
        | _, "varargs" ->
            Some
              (Gir_xml_fold.leaf ~input (fun ~attrs:_ (t, _, pd) ->
                   (t, true, pd)))
        | _, "type" ->
            Some
              (fun ~attrs (_t, varargs, pd) ->
                let type_name =
                  Option.value ~default:"void" (get_attr ~ctx "name" attrs)
                in
                let c_type_name = get_attr ~ctx "c:type" attrs in
                let nullable =
                  get_attr ~ctx "nullable" attrs |> Utils.parse_bool
                in
                let element_type =
                  element_type_of_type_child ~ctx ~input ~type_name
                    ~transfer_ownership
                in
                ( {
                    name = type_name;
                    c_type = c_type_name;
                    nullable;
                    transfer_ownership;
                    array = array_of_element_type ~type_name element_type;
                  },
                  varargs,
                  pd ))
        | _, "array" ->
            Some
              (fun ~attrs (_t, varargs, pd) ->
                let nullable_param =
                  get_attr ~ctx "nullable" param_attrs |> Utils.parse_bool
                in
                let array_info =
                  parse_array_type attrs transfer_ownership nullable_param
                in
                ( {
                    name = "array";
                    c_type = get_attr ~ctx "c:type" attrs;
                    nullable = nullable_param;
                    transfer_ownership;
                    array = array_info;
                  },
                  varargs,
                  pd ))
        | _, "doc" ->
            Some
              (fun ~attrs:_ (t, varargs, _) ->
                (t, varargs, parse_doc_text input ()))
        | _ -> None)
      ~init:init_type ()
  (* Parse parameters list. The outer fold collects <parameter> children
     (skipping <instance-parameter>); each <parameter> handler reads its own
     attributes and delegates its children to [parse_parameter_type]. The list
     is returned in reverse order; callers [List.rev] it. *)
  and parse_parameters () =
    let dispatch = function
      | _, "parameter" ->
          Some
            (fun ~attrs acc ->
              let param_attrs = attrs in
              let param_name =
                Option.value ~default:"arg" (get_attr ~ctx "name" attrs)
              in
              let nullable =
                match get_attr ~ctx "nullable" attrs with
                | Some "1" -> true
                | _ -> false
              in
              let direction =
                match get_attr ~ctx "direction" attrs with
                | Some "out" -> Out
                | Some "inout" -> InOut
                | _ -> In
              in
              let caller_allocates =
                get_attr ~ctx "caller-allocates" attrs |> Utils.parse_bool
              in
              let transfer_ownership =
                match get_attr ~ctx "transfer-ownership" attrs with
                | Some "none" -> Types.TransferNone
                | Some "full" -> Types.TransferFull
                | Some "container" -> Types.TransferContainer
                | Some "floating" -> Types.TransferFloating
                | _ -> Types.TransferNone
              in
              let param_type, varargs, param_doc =
                parse_parameter_type ~param_attrs ~transfer_ownership ()
              in
              {
                param_name;
                param_type;
                direction;
                nullable;
                varargs;
                caller_allocates;
                param_doc;
              }
              :: acc)
      | _, "instance-parameter" -> None
      | _ -> None
    in
    Gir_xml_fold.fold_element ~input ~dispatch ~init:[] ()
  and parse_repository _ =
    let init =
      {
        repository_c_includes = [];
        repository_includes = [];
        repository_packages = [];
        repository_doc_format = None;
      }
    in
    let dispatch = function
      | "http://www.gtk.org/introspection/c/1.0", "include" ->
          Some
            (Gir_xml_fold.leaf ~input (fun ~attrs acc ->
                 {
                   acc with
                   repository_c_includes =
                     (match get_attr ~ctx "name" attrs with
                     | Some name -> name :: acc.repository_c_includes
                     | None -> acc.repository_c_includes);
                 }))
      | "http://www.gtk.org/introspection/core/1.0", "include" ->
          Some
            (Gir_xml_fold.leaf ~input (fun ~attrs acc ->
                 {
                   acc with
                   repository_includes =
                     (match
                        ( get_attr ~ctx "name" attrs,
                          get_attr ~ctx "version" attrs )
                      with
                     | Some name, Some version ->
                         { include_name = name; include_version = version }
                         :: acc.repository_includes
                     | _ -> acc.repository_includes);
                 }))
      | "http://www.gtk.org/introspection/core/1.0", "package" ->
          Some
            (Gir_xml_fold.leaf ~input (fun ~attrs acc ->
                 {
                   acc with
                   repository_packages =
                     (match get_attr ~ctx "name" attrs with
                     | Some name -> name :: acc.repository_packages
                     | None -> acc.repository_packages);
                 }))
      | "http://www.gtk.org/introspection/doc/1.0", "format" ->
          Some
            (Gir_xml_fold.leaf ~input (fun ~attrs acc ->
                 {
                   acc with
                   repository_doc_format =
                     (match get_attr ~ctx "name" attrs with
                     | Some name -> Some name
                     | None -> acc.repository_doc_format);
                 }))
      | _ -> None
    in
    (* Stop before the <namespace> sibling, leaving it for [parse_document]'s
       namespace handler. The lists are returned in reverse order, matching
       the original parser. *)
    Gir_xml_fold.fold_element ~input ~dispatch
      ~stop_on:(function _, "namespace" -> true | _ -> false)
      ~init ()
  (* [parse_field_type] folds a <field>'s children into (field_type,
     field_doc, field_deprecated_doc): <type> is a leaf, <array> is consumed
     by [parse_array_type], and <doc>/<doc-deprecated> are read by
     [parse_doc_text] via [doc_arms]. Fields carry no transfer ownership
     (always [TransferNone]) and are never nullable at the array level. *)
  and parse_field_type () =
    Gir_xml_fold.fold_element ~input
      ~dispatch:(function
        | _, "type" ->
            Some
              (Gir_xml_fold.leaf ~input (fun ~attrs (_ftype, fdoc, fddoc) ->
                   let type_name =
                     Option.value ~default:"unknown"
                       (get_attr ~ctx "name" attrs)
                   in
                   let c_type_name = get_attr ~ctx "c:type" attrs in
                   let nullable =
                     get_attr ~ctx "nullable" attrs |> Utils.parse_bool
                   in
                   ( Some
                       {
                         name = type_name;
                         c_type = c_type_name;
                         nullable;
                         transfer_ownership = Types.TransferNone;
                         array = None;
                       },
                     fdoc,
                     fddoc )))
        | _, "array" ->
            Some
              (fun ~attrs (_ftype, fdoc, fddoc) ->
                let array_info =
                  parse_array_type attrs Types.TransferNone false
                in
                ( Some
                    {
                      name = "array";
                      c_type = get_attr ~ctx "c:type" attrs;
                      nullable = false;
                      transfer_ownership = Types.TransferNone;
                      array = array_info;
                    },
                  fdoc,
                  fddoc ))
        | tag ->
            doc_arms ~input
              ~doc:(fun d (ftype, _, fddoc) -> (ftype, d, fddoc))
              ~deprecated_doc:(fun d (ftype, fdoc, _) -> (ftype, fdoc, d))
              tag)
      ~init:(None, None, None) ()
  (* Parse a record element *)
  and parse_record attrs =
    let build (record_name, c_type) =
      let introspectable =
        get_attr ~ctx "introspectable" attrs |> Utils.parse_bool ~default:true
      in
      (* glib:type-name/get-type are namespaced attributes; the local names
         are "type-name" and "get-type" *)
      let glib_type_name =
        match get_attr ~ctx "type-name" attrs with
        | Some v -> Some v
        | None -> get_attr ~ctx "glib:type-name" attrs
      in
      let glib_get_type =
        match get_attr ~ctx "get-type" attrs with
        | Some v -> Some v
        | None -> get_attr ~ctx "glib:get-type" attrs
      in
      let is_gtype_struct_for =
        match get_attr ~ctx "is-gtype-struct-for" attrs with
        | Some v -> Some v
        | None -> get_attr ~ctx "glib:is-gtype-struct-for" attrs
      in
      let opaque = get_attr ~ctx "opaque" attrs |> Utils.parse_bool in
      let disguised = get_attr ~ctx "disguised" attrs |> Utils.parse_bool in
      let c_symbol_prefix = get_attr ~ctx "c:symbol-prefix" attrs in
      let init =
        {
          record_name;
          c_type;
          glib_type_name;
          glib_get_type;
          opaque;
          disguised;
          introspectable;
          c_symbol_prefix;
          is_gtype_struct_for;
          fields = [];
          constructors = [];
          methods = [];
          functions = [];
          record_doc = None;
          version = get_attr ~ctx "version" attrs;
          os = None;
          deprecation = deprecation_of_attrs ~ctx attrs;
        }
      in
      let dispatch = function
        | _, "field" ->
            Some
              (fun ~attrs acc ->
                let field_name = get_attr ~ctx "name" attrs in
                let readable =
                  get_attr ~ctx "readable" attrs |> Utils.parse_bool
                in
                let writable =
                  get_attr ~ctx "writable" attrs |> Utils.parse_bool
                in
                let field_type, field_doc, field_deprecated_doc =
                  parse_field_type ()
                in
                match field_name with
                | Some name ->
                    {
                      acc with
                      fields =
                        {
                          field_name = name;
                          field_type;
                          readable;
                          writable;
                          field_doc;
                          field_version = get_attr ~ctx "version" attrs;
                          field_os = None;
                          deprecation =
                            add_deprecated_doc field_deprecated_doc
                              (deprecation_of_attrs ~ctx attrs);
                        }
                        :: acc.fields;
                    }
                | None -> acc)
        | _, "constructor" ->
            Some
              (Gir_xml_fold.required ~input
                 ~extract:(name_and_c_identifier ~ctx)
                 ~build:(fun ~attrs (ctor_name, c_id) (acc : gir_record) ->
                   let c = build_constructor ~attrs (ctor_name, c_id) in
                   { acc with constructors = c :: acc.constructors }))
        | _, "method" ->
            Some
              (Gir_xml_fold.required ~input
                 ~extract:(name_and_c_identifier ~ctx)
                 ~build:(fun ~attrs (method_name, c_id) (acc : gir_record) ->
                   let m = build_method ~attrs (method_name, c_id) in
                   { acc with methods = m :: acc.methods }))
        | _, "function" ->
            Some
              (fun ~attrs acc ->
                let function_ = parse_function attrs in
                { acc with functions = function_ :: acc.functions })
        | tag ->
            doc_arms ~input
              ~doc:(fun d acc -> { acc with record_doc = d })
              ~deprecated_doc:(fun d acc ->
                { acc with deprecation = add_deprecated_doc d acc.deprecation })
              tag
      in
      let result = Gir_xml_fold.fold_element ~input ~dispatch ~init () in
      (* [functions] is intentionally not reversed here, matching the
         original parser's behaviour; fields/constructors/methods are. *)
      Some
        {
          result with
          fields = List.rev result.fields;
          constructors = List.rev result.constructors;
          methods = List.rev result.methods;
        }
    in
    guard_element ~input ~attrs
      ~extract:(fun attrs ->
        let open Containers.Option.Infix in
        let+ record_name = get_attr ~ctx "name" attrs
        and+ c_type = get_attr ~ctx "c:type" attrs in
        (record_name, c_type))
      build
  and parse_interface attrs () =
    let build name =
      let c_type =
        match get_attr ~ctx "c:type" attrs with
        | Some t -> t
        | None ->
            (* Use namespace c:identifier-prefixes; if no namespace is set the
              file is malformed and there is nothing useful to generate. *)
            let prefix =
              match !namespace with
              | Some ns -> ns.namespace_c_identifier_prefixes
              | None ->
                  failwith
                    "gir_parser: <interface> missing c:type and no namespace \
                     c:identifier-prefixes available"
            in
            prefix ^ name
      in
      let introspectable =
        get_attr ~ctx "introspectable" attrs |> Utils.parse_bool ~default:true
      in
      let init =
        {
          cc_constructors = [];
          cc_methods = [];
          cc_virtual_methods = [];
          cc_properties = [];
          cc_signals = [];
          cc_implements = [];
          cc_prerequisites = [];
          cc_doc = None;
          cc_deprecated_doc = None;
        }
      in
      let dispatch = function
        | _, "signal" ->
            Some
              (fun ~attrs acc ->
                match parse_signal attrs with
                | Some signal ->
                    { acc with cc_signals = signal :: acc.cc_signals }
                | None -> acc (* already skipped by parse_signal *))
        | _, "method" ->
            Some
              (Gir_xml_fold.required ~input
                 ~extract:(name_and_c_identifier ~ctx)
                 ~build:(fun ~attrs (method_name, c_id) acc ->
                   let m = build_method ~attrs (method_name, c_id) in
                   { acc with cc_methods = m :: acc.cc_methods }))
        | _, "virtual-method" ->
            Some
              (Gir_xml_fold.required ~input
                 ~extract:(name_and_c_identifier ~ctx)
                 ~build:(fun ~attrs (method_name, c_id) acc ->
                   let m = build_method ~attrs (method_name, c_id) in
                   { acc with cc_virtual_methods = m :: acc.cc_virtual_methods }))
        | _, "property" ->
            Some
              (Gir_xml_fold.required ~input
                 ~extract:(fun attrs -> get_attr ~ctx "name" attrs)
                 ~build:(fun ~attrs prop_name acc ->
                   let prop = parse_property prop_name attrs in
                   { acc with cc_properties = prop :: acc.cc_properties }))
        | _, "prerequisite" ->
            Some
              (Gir_xml_fold.leaf ~input (fun ~attrs acc ->
                   {
                     acc with
                     cc_prerequisites =
                       (match get_attr ~ctx "name" attrs with
                       | Some n -> n :: acc.cc_prerequisites
                       | None -> acc.cc_prerequisites);
                   }))
        | tag ->
            doc_arms ~input
              ~doc:(fun d acc -> { acc with cc_doc = d })
              ~deprecated_doc:(fun d acc -> { acc with cc_deprecated_doc = d })
              tag
      in
      let cc = Gir_xml_fold.fold_element ~input ~dispatch ~init () in
      let methods =
        merge_methods ~concrete:(List.rev cc.cc_methods)
          ~virtuals:(List.rev cc.cc_virtual_methods)
      in
      Some
        {
          interface_name = name;
          c_type;
          c_symbol_prefix =
            (match get_attr ~ctx "c:symbol-prefix" attrs with
            | Some p -> p
            | None -> String.lowercase_ascii name);
          glib_type_name = get_attr ~ctx "glib:type-name" attrs;
          glib_get_type = get_attr ~ctx "glib:get-type" attrs;
          prerequisites = List.rev cc.cc_prerequisites;
          introspectable;
          methods;
          properties = List.rev cc.cc_properties;
          signals = List.rev cc.cc_signals;
          interface_doc = cc.cc_doc;
          version = get_attr ~ctx "version" attrs;
          os = None;
          deprecation =
            add_deprecated_doc cc.cc_deprecated_doc
              (deprecation_of_attrs ~ctx attrs);
        }
    in
    guard_element ~input ~attrs ~extract:(get_attr ~ctx "name") build
  in

  (* Main parsing loop: fold the top-level element sequence until end-of-input.
     <repository> is consumed by [parse_repository] (which stops before the
     <namespace>); the <namespace> handler records the namespace and then
     consumes it by folding its children with the same [dispatch], so the
     class/interface/... entities inside it are parsed here rather than
     leaked to the top level. *)
  let rec dispatch = function
    | _, "class" ->
        Some
          (fun ~attrs () ->
            match parse_class attrs with
            | Some cls -> controllers := cls :: !controllers
            | None -> ())
    | _, "interface" ->
        Some
          (fun ~attrs () ->
            match parse_interface attrs () with
            | Some cls -> interfaces := cls :: !interfaces
            | None -> ())
    | _, "enumeration" ->
        Some
          (fun ~attrs () ->
            match
              parse_enumeration ~ctx input
                ~parse_functions:(fun _ -> parse_function)
                attrs
            with
            | Some enum -> enums := enum :: !enums
            | None -> ())
    | _, "bitfield" ->
        Some
          (fun ~attrs () ->
            match parse_bitfield ~ctx input attrs with
            | Some bitfield -> bitfields := bitfield :: !bitfields
            | None -> ())
    | _, "record" ->
        Some
          (fun ~attrs () ->
            match parse_record attrs with
            | Some record -> records := record :: !records
            | None -> ())
    | _, "constant" ->
        Some
          (fun ~attrs () ->
            match parse_constant ~ctx input attrs with
            | Some constant -> constants := constant :: !constants
            | None -> ())
    | _, "namespace" ->
        Some
          (fun ~attrs () ->
            (match
               ( get_attr ~ctx "name" attrs,
                 get_attr ~ctx "version" attrs,
                 get_attr ~ctx "shared-library" attrs,
                 get_attr ~ctx "c:identifier-prefixes" attrs,
                 get_attr ~ctx "c:symbol-prefixes" attrs )
             with
            | ( Some name,
                Some version,
                Some shared_library,
                Some c_id_prefixes,
                Some c_sym_prefixes ) ->
                namespace :=
                  Some
                    {
                      namespace_name = name;
                      namespace_version = version;
                      namespace_shared_library = shared_library;
                      namespace_c_identifier_prefixes = c_id_prefixes;
                      namespace_c_symbol_prefixes = c_sym_prefixes;
                    }
            | _ ->
                (* A well-formed GIR <repository> always carries one
                     <namespace> with all five attributes; if any is missing
                     the file is malformed and there is nothing useful to
                     generate. *)
                failwith
                  "gir_parser: <namespace> missing one of name, version, \
                   shared-library, c:identifier-prefixes, c:symbol-prefixes");
            (* Consume the namespace by folding its children with the same
                dispatch, so class/interface/... inside it are parsed here. *)
            Gir_xml_fold.fold_element ~input ~dispatch ~init:() ())
    | _, "repository" ->
        Some (fun ~attrs () -> repository := parse_repository attrs)
    | _ -> None
  in

  Gir_xml_fold.fold_document ~input ~dispatch ~init:() ();
  close_in ic;

  ( !repository,
    (match !namespace with
    | Some ns -> ns
    | None -> failwith "Unable to parse namespace correctly"),
    List.rev !controllers,
    List.rev !interfaces,
    List.rev !enums,
    List.rev !bitfields,
    List.rev !records,
    List.rev !constants )
