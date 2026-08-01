open Sexplib.Std
open StdLabels
module Types = Gir_gen_lib.Types
module Signal_gen = Gir_gen_lib.Generate.Signal_gen

type classification_outcome =
  | Supported of { class_or_iface : string; signal_name : string }
  | Unsupported of {
      class_or_iface : string;
      signal_name : string;
      reason : string;
    }

let build_context (namespace : Types.gir_namespace)
    (repository : Types.gir_repository) (classes : Types.gir_class list)
    (interfaces : Types.gir_interface list) (enums : Types.gir_enum list)
    (bitfields : Types.gir_bitfield list) (records : Types.gir_record list)
    (constants : Types.gir_constant list) : Types.generation_context =
  {
    Types.namespace;
    repository;
    classes;
    interfaces;
    enums;
    bitfields;
    records;
    constants;
    module_groups = Hashtbl.create 0;
    current_cycle_classes = [];
    cross_references = Types.StringMap.empty;
  }

let classify_signals_of_file filepath =
  let ( repository,
        namespace,
        classes,
        interfaces,
        enums,
        bitfields,
        records,
        constants ) =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file filepath []
  in
  let ctx =
    build_context namespace repository classes interfaces enums bitfields
      records constants
  in
  let classify_entity class_name signal =
    match Signal_gen.classify ~ctx signal with
    | Ok _ ->
        Supported
          { class_or_iface = class_name; signal_name = signal.signal_name }
    | Error reason ->
        Unsupported
          {
            class_or_iface = class_name;
            signal_name = signal.signal_name;
            reason;
          }
  in
  let class_outcomes =
    List.concat_map classes ~f:(fun (cls : Types.gir_class) ->
        List.map cls.Types.signals ~f:(classify_entity cls.Types.class_name))
  in
  let iface_outcomes =
    List.concat_map interfaces ~f:(fun (iface : Types.gir_interface) ->
        List.map iface.Types.signals
          ~f:(classify_entity iface.Types.interface_name))
  in
  class_outcomes @ iface_outcomes

type signal_coverage = {
  namespace : string;
  total_signals : int;
  supported : int;
  unsupported : int;
  by_reason : (string * int) list;
}
[@@deriving sexp]

let coverage_of_namespace (ns_name : string)
    (outcomes : classification_outcome list) : signal_coverage =
  let total_signals = List.length outcomes in
  let supported =
    List.fold_left outcomes ~init:0 ~f:(fun acc -> function
      | Supported _ -> acc + 1
      | _ -> acc)
  in
  let unsupported = total_signals - supported in
  let reason_counts =
    List.fold_left outcomes ~init:[] ~f:(fun acc -> function
      | Unsupported { reason; _ } ->
          let current =
            List.assoc_opt reason acc |> function Some n -> n + 1 | None -> 1
          in
          (reason, current)
          :: List.filter acc ~f:(fun (r, _) -> not (String.equal r reason))
      | Supported _ -> acc)
  in
  let by_reason =
    List.sort reason_counts ~cmp:(fun (a, _) (b, _) -> String.compare a b)
  in
  { namespace = ns_name; total_signals; supported; unsupported; by_reason }

let coverage_of_file filepath =
  let _, namespace, _, _, _, _, _, _ =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file filepath []
  in
  let outcomes = classify_signals_of_file filepath in
  coverage_of_namespace namespace.Types.namespace_name outcomes

let gir_files =
  [
    ("Gtk", "Gtk-4.0.gir");
    ("Gdk", "Gdk-4.0.gir");
    ("Gio", "Gio-2.0.gir");
    ("Pango", "Pango-1.0.gir");
    ("Gsk", "Gsk-4.0.gir");
    ("GdkPixbuf", "GdkPixbuf-2.0.gir");
    ("Graphene", "Graphene-1.0.gir");
  ]

let () =
  let gir_dir =
    match Array.to_list Sys.argv with
    | [ _; dir ] -> dir
    | _ -> Filename.concat (Sys.getcwd ()) "gir"
  in
  let coverages =
    List.map gir_files ~f:(fun (_ns, filename) ->
        let filepath = Filename.concat gir_dir filename in
        Fmt.epr "Processing %s...\n" filepath;
        coverage_of_file filepath)
  in
  let sexp_items = List.map coverages ~f:sexp_of_signal_coverage in
  let sexp = Sexplib.Sexp.List sexp_items in
  let output_path =
    Filename.concat (Sys.getcwd ())
      "gir_gen/test/corpus/signal_corpus_baseline.sexp"
  in
  let oc = open_out output_path in
  output_string oc (Sexplib.Sexp.to_string_hum sexp);
  output_char oc '\n';
  close_out oc;
  Fmt.epr "Baseline written to %s\n" output_path
