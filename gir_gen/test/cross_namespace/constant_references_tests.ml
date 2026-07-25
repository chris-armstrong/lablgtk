(* Unit tests for Crt_Constant cross-namespace reference emission.

The `references` command (bin/gir_gen.ml) emits each constant as a
[cross_reference_entity] with [cr_type = Crt_Constant]. These tests pin the
sexp round-trip for that variant: a namespace carrying a constant serializes
to sexp, parses back, and the constant round-trips with [Crt_Constant] and the
right [cr_c_type]. *)

open Gir_gen_lib.Types

(* A constant entity as the `references` command would emit it. *)
let constant_entity =
  Type_factory.make_cross_reference_entity
    ~cr_name:"ACCESSIBLE_ATTRIBUTE_BACKGROUND" ~cr_type:Crt_Constant
    ~cr_c_type:"GTK_ACCESSIBLE_ATTRIBUTE_BACKGROUND" ()

let ns =
  Type_factory.make_cross_reference_namespace ~cr_namespace_name:"Gtk"
    ~cr_namespace_packages:[ "gtk4" ] ~cr_entities:[ constant_entity ] ()

let roundtrip () =
  let sexp = sexp_of_cross_reference_namespace ns in
  (* Parse the sexp back through the generated of_sexp. *)
  let parsed = cross_reference_namespace_of_sexp sexp in
  Alcotest.(check string)
    "namespace name round-trips" "Gtk" parsed.cr_namespace_name;
  Alcotest.(check int) "one entity" 1 (List.length parsed.cr_entities);
  let entity = List.hd parsed.cr_entities in
  Alcotest.(check string)
    "entity name" "ACCESSIBLE_ATTRIBUTE_BACKGROUND" entity.cr_name;
  Alcotest.(check string)
    "entity c_type" "GTK_ACCESSIBLE_ATTRIBUTE_BACKGROUND" entity.cr_c_type;
  (* cr_type is Crt_Constant (no payload), so structural equality is fine. *)
  Alcotest.(check bool)
    "cr_type is Crt_Constant"
    (match entity.cr_type with Crt_Constant -> true | _ -> false)
    true

(* A constant alongside an enum and a record: ensure Crt_Constant coexists with
   the other variants in one namespace without confusing the of_sexp. *)
let mixed_namespace () =
  let entities =
    [
      Type_factory.make_cross_reference_entity ~cr_name:"E" ~cr_type:Crt_Enum
        ~cr_c_type:"E" ();
      Type_factory.make_cross_reference_entity ~cr_name:"R"
        ~cr_type:(Crt_Record { opaque = true; get_type_func = None })
        ~cr_c_type:"R" ();
      constant_entity;
    ]
  in
  let n =
    Type_factory.make_cross_reference_namespace ~cr_namespace_name:"Gtk"
      ~cr_entities:entities ()
  in
  let parsed =
    cross_reference_namespace_of_sexp (sexp_of_cross_reference_namespace n)
  in
  let types = List.map (fun e -> e.cr_type) parsed.cr_entities in
  Alcotest.(check int) "three entities" 3 (List.length types);
  Alcotest.(check bool)
    "includes Crt_Constant"
    (List.exists (function Crt_Constant -> true | _ -> false) types)
    true;
  Alcotest.(check bool)
    "includes Crt_Enum"
    (List.exists (function Crt_Enum -> true | _ -> false) types)
    true

(* The constant tag must appear in the serialized sexp so downstream consumers
   (and human readers) can confirm constants were emitted. *)
let sexp_contains_constant_tag () =
  let sexp_str =
    Sexplib.Sexp.to_string_hum (sexp_of_cross_reference_namespace ns)
  in
  Helpers.string_contains sexp_str "Crt_Constant" |> fun b ->
  Alcotest.(check bool) "sexp has Crt_Constant tag" true b

let tests =
  [
    ("Crt_Constant round-trips", `Quick, roundtrip);
    ("Crt_Constant in mixed namespace", `Quick, mixed_namespace);
    ("sexp contains Crt_Constant tag", `Quick, sexp_contains_constant_tag);
  ]
