(* ML AST Helpers - Wrapper around OCaml compiler-libs for parsing and inspecting ML/MLI files *)

open Ppxlib
open Ppxlib.Parsetree
open Ppxlib.Asttypes

(* ========================================================================= *)
(* Parsing Functions *)
(* ========================================================================= *)

(* Parse .ml implementation code into AST *)

(** Parse an OCaml implementation (.ml) source string into its AST. *)
let parse_implementation code =
  let lexbuf = Lexing.from_string code in
  try Ppxlib.Parse.implementation lexbuf with
  | Ppxlib.Location.Error _ as e ->
      Fmt.epr "Syntax error while parsing implementation:\n%s\n" code;
      raise e
  | e ->
      Fmt.epr "Error while parsing implementation:\n%s\n" code;
      raise e

(* Parse .mli interface/signature code into AST *)

(** Parse an OCaml interface (.mli) source string into its AST. *)
let parse_interface code =
  let lexbuf = Lexing.from_string code in
  try Ppxlib.Parse.interface lexbuf with
  | Ppxlib.Location.Error _ as e ->
      Fmt.epr "Syntax error while parsing interface:\n%s\n" code;
      raise e
  | e ->
      Fmt.epr "Error while parsing interface:\n%s\n" code;
      raise e

(* ========================================================================= *)
(* Type Declaration Helpers *)
(* ========================================================================= *)

(* Find a type declaration by name in a structure (implementation) *)

(** Find a type declaration by name in an implementation AST. *)
let find_type_declaration (ast : structure) (name : string) :
    type_declaration option =
  List.find_map
    (fun item ->
      match item.pstr_desc with
      | Pstr_type (_, type_decls) ->
          List.find_opt (fun td -> td.ptype_name.txt = name) type_decls
      | _ -> None)
    ast

(* Find a type declaration by name in a signature (interface) *)

(** Find a type declaration by name in an interface AST. *)
let find_type_declaration_sig (ast : signature) (name : string) :
    type_declaration option =
  List.find_map
    (fun item ->
      match item.psig_desc with
      | Psig_type (_, type_decls) ->
          List.find_opt (fun td -> td.ptype_name.txt = name) type_decls
      | _ -> None)
    ast

(* Get all type declarations from a structure *)

(** Return all type declarations in an implementation AST, in order. *)
let get_all_type_declarations (ast : structure) : type_declaration list =
  List.concat_map
    (fun item ->
      match item.pstr_desc with
      | Pstr_type (_, type_decls) -> type_decls
      | _ -> [])
    ast

(* ========================================================================= *)
(* External Declaration Helpers *)
(* ========================================================================= *)

(* Find an external declaration by name in a structure *)

(** Find an [external] declaration by name in an implementation AST. *)
let find_external (ast : structure) (name : string) : value_description option =
  List.find_map
    (fun item ->
      match item.pstr_desc with
      | Pstr_primitive vd when vd.pval_name.txt = name -> Some vd
      | _ -> None)
    ast

(* Find an external declaration by name in a signature *)

(** Find an [external] declaration by name in an interface AST. *)
let find_external_sig (ast : signature) (name : string) :
    value_description option =
  List.find_map
    (fun item ->
      match item.psig_desc with
      | Psig_value vd when vd.pval_name.txt = name ->
          (* Check if it's actually an external by looking at pval_prim *)
          if vd.pval_prim <> [] then Some vd else None
      | _ -> None)
    ast

(* Get the C function name from an external declaration *)

(** Return the C function name of an external declaration. *)
let get_external_c_name (ext_decl : value_description) : string option =
  match ext_decl.pval_prim with c_name :: _ -> Some c_name | [] -> None

(* Get all external declarations from a structure *)

(** Return all [external] declarations in an implementation AST, in order. *)
let get_all_externals (ast : structure) : value_description list =
  List.filter_map
    (fun item ->
      match item.pstr_desc with Pstr_primitive vd -> Some vd | _ -> None)
    ast

(* ========================================================================= *)
(* Value Declaration Helpers *)
(* ========================================================================= *)

(* Find a let binding by name in an implementation *)

(** Find a [let] binding by name in an implementation AST. *)
let find_let_binding (ast : structure) (name : string) : value_binding option =
  List.find_map
    (fun item ->
      match item.pstr_desc with
      | Pstr_value (_, bindings) ->
          List.find_opt
            (fun vb ->
              match vb.pvb_pat.ppat_desc with
              | Ppat_var { txt; _ } when txt = name -> true
              | _ -> false)
            bindings
      | _ -> None)
    ast

(* Find a value declaration (let binding) by name in a signature *)

(** Find a [val] declaration by name in an interface AST. *)
let find_value_declaration_sig (ast : signature) (name : string) :
    value_description option =
  List.find_map
    (fun item ->
      match item.psig_desc with
      | Psig_value vd when vd.pval_name.txt = name -> Some vd
      | _ -> None)
    ast

(* Get all value declarations from a signature *)

(** Return all [val] declarations in an interface AST as [(name, type)] pairs,
    in order. *)
let get_all_value_declarations_sig (ast : signature) : (string * core_type) list
    =
  List.filter_map
    (fun item ->
      match item.psig_desc with
      | Psig_value vd -> Some (vd.pval_name.txt, vd.pval_type)
      | _ -> None)
    ast

(* ========================================================================= *)
(* Type Inspection Helpers *)
(* ========================================================================= *)

(* Convert a longident_loc to a simple string - handles common cases *)
let longident_loc_to_string (lid_loc : Longident.t Asttypes.loc) : string =
  let rec to_str lid =
    match lid with
    | Longident.Lident s -> s
    | Longident.Ldot (parent, s) -> to_str parent ^ "." ^ s
    | Longident.Lapply _ -> "<apply>"
  in
  to_str lid_loc.txt

(* Convert a core_type to a string representation (simplified) *)

(** Render a [core_type] as a simplified string. *)
let rec core_type_to_string (ct : core_type) : string =
  match ct.ptyp_desc with
  | Ptyp_any -> "_"
  | Ptyp_var v -> "'" ^ v
  | Ptyp_constr (lid_loc, []) -> longident_loc_to_string lid_loc
  | Ptyp_constr (lid_loc, [ arg ]) ->
      (* Single argument: use postfix notation (e.g., "t option", not "option<t>") *)
      Fmt.str "%s %s" (core_type_to_string arg)
        (longident_loc_to_string lid_loc)
  | Ptyp_constr (lid_loc, args) ->
      (* Multiple arguments: use prefix notation with parens *)
      let args_str = String.concat ", " (List.map core_type_to_string args) in
      Fmt.str "(%s) %s" args_str (longident_loc_to_string lid_loc)
  | Ptyp_tuple types ->
      (* ppxlib uses version-independent tuple representation without labels *)
      let types_str =
        String.concat " * " (List.map core_type_to_string types)
      in
      Fmt.str "(%s)" types_str
  | Ptyp_arrow (_, param_type, return_type) ->
      Fmt.str "%s -> %s"
        (core_type_to_string param_type)
        (core_type_to_string return_type)
  | Ptyp_variant (row_fields, _, _) ->
      let tags =
        List.map
          (fun rf ->
            match rf.prf_desc with
            | Rtag (label_loc, _, _) -> "`" ^ label_loc.txt
            | Rinherit _ -> "<inherit>")
          row_fields
      in
      Fmt.str "[%s]" (String.concat " | " tags)
  | Ptyp_poly (vars, poly_ct) -> (
      (* Polymorphic type like 'a. t -> u *)
      let var_strs = List.map (fun { txt; _ } -> "'" ^ txt) vars in
      let poly_str = core_type_to_string poly_ct in
      match var_strs with
      | [] -> poly_str
      | [ v ] -> v ^ ". " ^ poly_str
      | _ -> "(" ^ String.concat ", " var_strs ^ "). " ^ poly_str)
  | Ptyp_alias (ct, { txt = alias; _ }) ->
      (* Type alias like 'a as 'b or 'a as #Widget *)
      Fmt.str "(%s as '%s)" (core_type_to_string ct) alias
  | Ptyp_class (lid_loc, []) ->
      (* Hierarchy type like #Widget *)
      "#" ^ longident_loc_to_string lid_loc
  | Ptyp_class (lid_loc, args) ->
      (* Hierarchy type with arguments like #Widget('a, 'b) *)
      let args_str = String.concat ", " (List.map core_type_to_string args) in
      Fmt.str "#%s (%s)" (longident_loc_to_string lid_loc) args_str
  | _ -> "<complex type>"

(* Extract parameter types from a function type *)

(** Extract the parameter types of a function type, in order. *)
let rec get_param_types (ct : core_type) : core_type list =
  match ct.ptyp_desc with
  | Ptyp_arrow (_, param_type, return_type) ->
      param_type :: get_param_types return_type
  | _ -> []

(* Extract the return type from a function type *)

(** Extract the return type of a function type. *)
let rec get_return_type (ct : core_type) : core_type =
  match ct.ptyp_desc with
  | Ptyp_arrow (_, _, return_type) -> get_return_type return_type
  | _ -> ct

(* Check if a type is an option type *)
let is_option_type (ct : core_type) : bool =
  match ct.ptyp_desc with
  | Ptyp_constr (lid_loc, [ _ ]) -> (
      match lid_loc.txt with Longident.Lident "option" -> true | _ -> false)
  | _ -> false

(* Check if a type is unit *)

(** Check whether a type is [unit]. *)
let is_unit_type (ct : core_type) : bool =
  match ct.ptyp_desc with
  | Ptyp_constr (lid_loc, []) -> (
      match lid_loc.txt with Longident.Lident "unit" -> true | _ -> false)
  | _ -> false

(* Check if a type is a string *)

(** Check whether a type is [string]. *)
let is_string_type (ct : core_type) : bool =
  match ct.ptyp_desc with
  | Ptyp_constr (lid_loc, []) -> (
      match lid_loc.txt with Longident.Lident "string" -> true | _ -> false)
  | _ -> false

(* Check if a type is "string option" *)

(** Check whether a type is [string option]. *)
let is_string_option_type (ct : core_type) : bool =
  match ct.ptyp_desc with
  | Ptyp_constr (lid_loc, [ inner ]) -> (
      match lid_loc.txt with
      | Longident.Lident "option" -> is_string_type inner
      | _ -> false)
  | _ -> false

(* Check if a type is a result type with GError.t as error (e.g., "(T, GError.t) result") *)

(** Check whether a type is a [result] whose error type is [GError.t]. *)
let is_result_type_with_ginfo_error (ct : core_type) : bool =
  match ct.ptyp_desc with
  | Ptyp_constr (lid_loc, [ _ok_type; error_type ]) -> (
      match lid_loc.txt with
      | Longident.Lident "result" -> (
          (* Check if error type is GError.t *)
          match error_type.ptyp_desc with
          | Ptyp_constr (error_lid, []) -> (
              match error_lid.txt with
              | Longident.Ldot (Longident.Lident "GError", "t") -> true
              | _ -> false)
          | _ -> false)
      | _ -> false)
  | _ -> false

(* Extract variant tags from a polymorphic variant type *)

(** Extract the tag names of a polymorphic variant type declaration. *)
let get_variant_tags (type_decl : type_declaration) : string list =
  match type_decl.ptype_manifest with
  | Some { ptyp_desc = Ptyp_variant (row_fields, _, _); _ } ->
      List.filter_map
        (fun rf ->
          match rf.prf_desc with
          | Rtag (label_loc, _, _) -> Some label_loc.txt
          | Rinherit _ -> None)
        row_fields
  | Some
      {
        ptyp_desc =
          Ptyp_constr (_, [ { ptyp_desc = Ptyp_variant (row_fields, _, _); _ } ]);
        _;
      } ->
      (* Handle case like: type t = [`button | `widget] Gobject.obj *)
      List.filter_map
        (fun rf ->
          match rf.prf_desc with
          | Rtag (label_loc, _, _) -> Some label_loc.txt
          | Rinherit _ -> None)
        row_fields
  | _ -> []

(* Check if a type wraps Gobject.obj *)

(** Check whether a type declaration's manifest is [Gobject.obj _]. *)
let wraps_gobject_obj (type_decl : type_declaration) : bool =
  match type_decl.ptype_manifest with
  | Some { ptyp_desc = Ptyp_constr (lid_loc, [ _ ]); _ } -> (
      match lid_loc.txt with
      | Longident.Ldot (parent, s) -> (
          match (parent, s) with
          | Longident.Lident "Gobject", "obj" -> true
          | _ -> false)
      | _ -> false)
  | _ -> false

(* Check if a type is a polymorphic variant *)

(** Check whether a type declaration's manifest is a polymorphic variant. *)
let is_polymorphic_variant (type_decl : type_declaration) : bool =
  match type_decl.ptype_manifest with
  | Some { ptyp_desc = Ptyp_variant _; _ } -> true
  | _ -> false

(* Check if a type is abstract (no manifest) *)

(** Check whether a type declaration has no manifest (i.e. is abstract). *)
let is_abstract_type (type_decl : type_declaration) : bool =
  type_decl.ptype_manifest = None

(* ========================================================================= *)
(* Class Declaration Helpers *)
(* ========================================================================= *)

(* Find a class declaration by name in a structure *)

(** Find a class declaration by name in an implementation AST. *)
let find_class_declaration (ast : structure) (name : string) :
    class_declaration option =
  List.find_map
    (fun item ->
      match item.pstr_desc with
      | Pstr_class class_decls ->
          List.find_opt (fun cd -> cd.pci_name.txt = name) class_decls
      | _ -> None)
    ast

(* Find a class type declaration by name in a signature *)

(** Find a class type declaration by name in an interface AST. *)
let find_class_type_declaration (ast : signature) (name : string) :
    class_type_declaration option =
  List.find_map
    (fun item ->
      match item.psig_desc with
      | Psig_class class_decls ->
          List.find_opt (fun cd -> cd.pci_name.txt = name) class_decls
      | Psig_class_type class_type_decls ->
          List.find_opt (fun cd -> cd.pci_name.txt = name) class_type_decls
      | _ -> None)
    ast

(* Get inherit clauses from a class expression *)

(** Return the names of the classes inherited by a class expression. *)
let rec get_class_inherit_clauses (class_expr : class_expr) : string list =
  match class_expr.pcl_desc with
  | Pcl_constr ({ txt = Longident.Lident name; _ }, []) -> [ name ]
  | Pcl_constr ({ txt = Longident.Ldot (parent, name); _ }, []) ->
      [
        longident_loc_to_string
          { txt = Longident.Ldot (parent, name); loc = Location.none };
      ]
  | Pcl_apply (cexp, _) -> get_class_inherit_clauses cexp
  | Pcl_structure { pcstr_fields; _ } ->
      (* Extract inherit clauses from class structure *)
      List.filter_map
        (fun cf ->
          match cf.pcf_desc with
          | Pcf_inherit (_, inherit_expr, _) -> (
              match inherit_expr.pcl_desc with
              | Pcl_constr (lid, _) -> Some (longident_loc_to_string lid)
              | Pcl_apply (func, _) -> (
                  match func.pcl_desc with
                  | Pcl_constr (lid, _) -> Some (longident_loc_to_string lid)
                  | _ -> None)
              | _ -> None)
          | _ -> None)
        pcstr_fields
  | Pcl_fun (_, _, _, body) ->
      (* For class with parameters, recurse into the body *)
      get_class_inherit_clauses body
  | Pcl_constraint (body, _) -> get_class_inherit_clauses body
  | _ -> []

(* Get inherit clauses from a class type definition *)

(** Return the names of the class types inherited by a class type. *)
let get_class_type_inherit_clauses (class_type : class_type) : string list =
  match class_type.pcty_desc with
  | Pcty_signature { pcsig_fields; _ } ->
      List.filter_map
        (fun ctf ->
          match ctf.pctf_desc with
          | Pctf_inherit ct -> (
              match ct.pcty_desc with
              | Pcty_constr (lid, _) -> Some (longident_loc_to_string lid)
              | _ -> None)
          | _ -> None)
        pcsig_fields
  | _ -> []

(* Find a method by name in a class expression *)

(** Find a method by name in a class expression. *)
let rec find_method_in_class (class_expr : class_expr) (method_name : string) :
    class_field option =
  match class_expr.pcl_desc with
  | Pcl_structure { pcstr_fields; _ } ->
      List.find_opt
        (fun cf ->
          match cf.pcf_desc with
          | Pcf_method ({ txt; _ }, _, _) when String.equal txt method_name ->
              true
          | _ -> false)
        pcstr_fields
  | Pcl_fun (_, _, _, body) ->
      (* Recursively search in the body of the function *)
      find_method_in_class body method_name
  | Pcl_apply (expr, _) ->
      (* Recursively search in the applied expression *)
      find_method_in_class expr method_name
  | Pcl_constraint (body, _) -> find_method_in_class body method_name
  | _ -> None

(* Get the type annotation of a method *)

(** Return the type annotation of a method field. *)
let get_method_type (class_field : class_field) : core_type option =
  match class_field.pcf_desc with
  | Pcf_method (_, _, Cfk_virtual virtual_type) ->
      (* virtual_type is already a core_type, return it directly *)
      Some virtual_type
  | Pcf_method
      (_, _, Cfk_concrete (_, { pexp_desc = Pexp_poly (_, Some poly_type); _ }))
    ->
      Some poly_type
  | Pcf_method (_, _, Cfk_concrete (_, { pexp_desc = Pexp_poly (_, None); _ }))
    ->
      (* Poly type with no explicit type - infer from body (not implemented) *)
      None
  | _ -> None

(* Extract the method body expression from a class_field *)

(** Return the body expression of a concrete method field. *)
let get_method_body (class_field : class_field) : expression option =
  match class_field.pcf_desc with
  | Pcf_method (_, _, Cfk_concrete (_, { pexp_desc = Pexp_poly (body, _); _ }))
    ->
      (* For polymorphic methods, the body is the expression wrapped in Pexp_poly *)
      Some body
  | _ -> None

(* Find a method by name in a class type (signature) *)

(** Find a method by name in a class type. *)
let rec find_method_in_class_type (class_type : class_type)
    (method_name : string) : class_type_field option =
  match class_type.pcty_desc with
  | Pcty_signature { pcsig_fields; _ } ->
      List.find_opt
        (fun ctf ->
          match ctf.pctf_desc with
          | Pctf_method ({ txt; _ }, _, _, _) -> String.equal txt method_name
          | _ -> false)
        pcsig_fields
  | Pcty_arrow (_, _, rest) ->
      (* Recursively search in the rest of the arrow type *)
      find_method_in_class_type rest method_name
  | _ -> None

(* Get the type annotation of a method from a class type field (signature) *)

(** Return the type annotation of a method field in a class type. *)
let get_method_type_from_class_type_field (class_type_field : class_type_field)
    : core_type option =
  match class_type_field.pctf_desc with
  | Pctf_method (_, _, _, method_type) ->
      Some method_type (* Fourth arg is the method type *)
  | _ -> None

(* Convert class expression to string for debugging *)
let rec class_expr_to_string (class_expr : class_expr) : string =
  match class_expr.pcl_desc with
  | Pcl_constr ({ txt = Longident.Lident name; _ }, []) -> "class " ^ name
  | Pcl_constr ({ txt = Longident.Ldot (parent, name); _ }, []) ->
      "class "
      ^ longident_loc_to_string
          { txt = Longident.Ldot (parent, name); loc = Location.none }
  | Pcl_structure { pcstr_self; pcstr_fields } ->
      let self_str =
        match pcstr_self with
        | { ppat_desc = Ppat_var { txt; _ }; _ } -> txt
        | _ -> "<self>"
      in
      let field_strs =
        List.map
          (fun cf ->
            match cf.pcf_desc with
            | Pcf_method ({ txt; _ }, _, _) -> "method " ^ txt
            | Pcf_val ({ txt; _ }, _, _) -> "val " ^ txt
            | Pcf_inherit _ -> "inherit ..."
            | _ -> "...")
          pcstr_fields
      in
      Fmt.str "class %s = { %s }" self_str (String.concat "; " field_strs)
  | Pcl_apply (cexp, _) -> class_expr_to_string cexp
  | _ -> "<class expression>"

(* ========================================================================= *)
(* Hierarchy Type Helpers *)
(* ========================================================================= *)

(* Check if a longident represents a hierarchy type (starts with capital letter or is #-prefixed) *)
let rec longident_is_hierarchy_type (lid : Longident.t) : bool =
  match lid with
  | Longident.Lident s ->
      (* Single uppercase identifier like "Widget" or "#Widget" *)
      let s =
        if String.length s > 0 && s.[0] = '#' then
          String.sub s 1 (String.length s - 1)
        else s
      in
      s <> "" && Char.uppercase_ascii s.[0] = s.[0] && s.[0] <> '_'
  | Longident.Ldot (parent, _) ->
      (* Dotted path like GWidget.widget - check if parent is hierarchy type *)
      longident_is_hierarchy_type parent
  | Longident.Lapply _ -> false

(* Check if a longident_loc represents a hierarchy type *)
let longident_loc_is_hierarchy_type (lid_loc : Longident.t Asttypes.loc) : bool
    =
  longident_is_hierarchy_type lid_loc.txt

(* Recursively check if a core_type contains a hierarchy type *)

(** Recursively check whether a [core_type] contains a hierarchy type. *)
let rec contains_hierarchy_type (ct : core_type) : bool =
  match ct.ptyp_desc with
  | Ptyp_class _ -> true (* This is a hierarchy type! *)
  | Ptyp_constr (lid_loc, args) ->
      (* Check if the constr itself is a hierarchy type or if its args contain one *)
      longident_loc_is_hierarchy_type lid_loc
      || List.exists contains_hierarchy_type args
  | Ptyp_arrow (_, arg_type, return_type) ->
      contains_hierarchy_type arg_type || contains_hierarchy_type return_type
  | Ptyp_tuple types -> List.exists contains_hierarchy_type types
  | Ptyp_variant (row_fields, _, _) ->
      List.exists
        (fun rf ->
          match rf.prf_desc with
          | Rtag (_, _, types) -> List.exists contains_hierarchy_type types
          | Rinherit ct -> contains_hierarchy_type ct)
        row_fields
  | Ptyp_object (fields, _) ->
      List.exists
        (fun field ->
          match field.pof_desc with
          | Otag (_, ct) -> contains_hierarchy_type ct
          | Oinherit ct -> contains_hierarchy_type ct)
        fields
  | Ptyp_poly (_, ct) -> contains_hierarchy_type ct
  | Ptyp_alias (ct, _) ->
      contains_hierarchy_type ct (* Check aliased types for hierarchy types *)
  | _ -> false

(* Check if a method parameter has a hierarchy type (#widget syntax) *)
(* Hierarchy types use Ptyp_class in the AST, NOT Ptyp_constr *)
let has_hierarchy_parameter (class_field : class_field) : bool =
  match class_field.pcf_desc with
  | Pcf_method
      (_, _, Cfk_concrete (_, { pexp_desc = Pexp_poly (_, poly_type); _ })) -> (
      match poly_type with
      | Some ct -> contains_hierarchy_type ct
      | None -> false)
  | _ -> false

(* Assert that a method in a class has a hierarchy parameter *)

(** Assert that a method in a class has a hierarchy-type parameter. *)
let assert_method_has_hierarchy_param ast class_name method_name =
  Helpers.expect_some
    (Fmt.str "Class %s not found" class_name)
    (find_class_declaration ast class_name)
  @@ fun cd ->
  Helpers.expect_some
    (Fmt.str "Method %s not found" method_name)
    (find_method_in_class cd.pci_expr method_name)
  @@ fun cf ->
  if not (has_hierarchy_parameter cf) then
    Alcotest.fail
      (Fmt.str "Method %s does not have hierarchy parameter" method_name)

(* ========================================================================= *)
(* Structural Type Helpers (Ptyp_object) *)
(* ========================================================================= *)

(* Recursively check if a core_type contains a Ptyp_object (structural type) *)
let rec contains_structural_type (ct : core_type) : bool =
  match ct.ptyp_desc with
  | Ptyp_object _ -> true (* This is a structural type! *)
  | Ptyp_alias _ ->
      (* If we see Ptyp_alias, it's likely wrapping a structural type *)
      (* For now, assume all Ptyp_alias in this context are structural types *)
      true
  | Ptyp_constr (_, args) -> List.exists contains_structural_type args
  | Ptyp_poly (_, poly_ct) -> contains_structural_type poly_ct
  | Ptyp_arrow (_, arg_type, return_type) ->
      contains_structural_type arg_type || contains_structural_type return_type
  | Ptyp_tuple types -> List.exists contains_structural_type types
  | Ptyp_variant (row_fields, _, _) ->
      List.exists
        (fun rf ->
          match rf.prf_desc with
          | Rtag (_, _, types) -> List.exists contains_structural_type types
          | Rinherit ct -> contains_structural_type ct)
        row_fields
  | _ -> false

(* Check if a method has a structural type parameter like `<as_widget: Widget.t; ..>` *)
let has_structural_type_parameter (class_field : class_field) : bool =
  match class_field.pcf_desc with
  | Pcf_method
      (_, _, Cfk_concrete (_, { pexp_desc = Pexp_poly (_, poly_type); _ })) -> (
      match poly_type with
      | Some ct -> contains_structural_type ct
      | None -> false)
  | _ -> false

(* Check if a method parameter has a structural type with a specific field *)
let method_param_has_structural_type_with_field (class_field : class_field)
    (field_name : string) : bool =
  match class_field.pcf_desc with
  | Pcf_method
      (_, _, Cfk_concrete (_, { pexp_desc = Pexp_poly (_, Some poly_type); _ }))
    ->
      let rec search_for_field ct =
        match ct.ptyp_desc with
        | Ptyp_object (fields, _) ->
            List.exists
              (fun field ->
                match field.pof_desc with
                | Otag (name_loc, _) when String.equal name_loc.txt field_name
                  ->
                    true
                | _ -> false)
              fields
        | Ptyp_alias _ ->
            let type_str = core_type_to_string ct in
            String.contains type_str field_name.[0]
        | Ptyp_arrow (_, arg_type, return_type) ->
            search_for_field arg_type || search_for_field return_type
        | Ptyp_constr (_, args) -> List.exists search_for_field args
        | Ptyp_poly (_, inner_ct) ->
            (* For polymorphic methods like 'a. (<...> as 'a) -> ..., search inside *)
            search_for_field inner_ct
        | _ -> false
      in
      search_for_field poly_type
  | _ -> false

(* Assert that a method in a class has a structural type parameter *)
let assert_method_has_structural_type_param ast class_name method_name =
  Helpers.expect_some
    (Fmt.str "Class %s not found" class_name)
    (find_class_declaration ast class_name)
  @@ fun cd ->
  Helpers.expect_some
    (Fmt.str "Method %s not found" method_name)
    (find_method_in_class cd.pci_expr method_name)
  @@ fun cf ->
  if not (has_structural_type_parameter cf) then
    Alcotest.fail
      (Fmt.str "Method %s does not have structural type parameter" method_name)

(* Assert that a method has a structural type parameter with a specific field *)
let assert_method_has_structural_field ast class_name method_name field_name =
  Helpers.expect_some
    (Fmt.str "Class %s not found" class_name)
    (find_class_declaration ast class_name)
  @@ fun cd ->
  Helpers.expect_some
    (Fmt.str "Method %s not found" method_name)
    (find_method_in_class cd.pci_expr method_name)
  @@ fun cf ->
  if not (method_param_has_structural_type_with_field cf field_name) then
    Alcotest.fail
      (Fmt.str "Method %s does not have structural field '%s'" method_name
         field_name)

(* ========================================================================= *)
(* Function Call Validation Helpers *)
(* ========================================================================= *)

(* Convert longident to string for comparison *)
let rec longident_to_string (lid : Longident.t) : string =
  match lid with
  | Longident.Lident s -> s
  | Longident.Ldot (parent, s) -> longident_to_string parent ^ "." ^ s
  | Longident.Lapply _ -> "<apply>"

(* Check if an expression contains a function call to a specific function *)

(** Recursively check whether an expression contains a call to the named
    function. *)
let rec contains_function_call (expr : expression) (func_name : string) : bool =
  match expr.pexp_desc with
  | Pexp_ident { txt = Longident.Lident name; _ } when name = func_name -> true
  | Pexp_ident { txt = Longident.Ldot (parent, name); _ } ->
      let full_name = Fmt.str "%s.%s" (longident_to_string parent) name in
      full_name = func_name
  | Pexp_apply (func_expr, args) ->
      contains_function_call func_expr func_name
      || List.exists (fun (_, arg) -> contains_function_call arg func_name) args
  | Pexp_let (_, bindings, body) ->
      List.exists
        (fun vb -> contains_function_call vb.pvb_expr func_name)
        bindings
      || contains_function_call body func_name
  | Pexp_sequence (e1, e2) ->
      contains_function_call e1 func_name || contains_function_call e2 func_name
  | Pexp_ifthenelse (cond, if_true, if_false_opt) -> (
      contains_function_call cond func_name
      || contains_function_call if_true func_name
      ||
      match if_false_opt with
      | Some e -> contains_function_call e func_name
      | None -> false)
  | Pexp_match (expr, cases) ->
      contains_function_call expr func_name
      || List.exists
           (fun case -> contains_function_call case.pc_rhs func_name)
           cases
  | Pexp_try (expr, cases) ->
      contains_function_call expr func_name
      || List.exists
           (fun case -> contains_function_call case.pc_rhs func_name)
           cases
  | Pexp_tuple exprs | Pexp_array exprs ->
      List.exists (fun e -> contains_function_call e func_name) exprs
  | Pexp_record (fields, base_opt) -> (
      List.exists
        (fun (_, field_expr) -> contains_function_call field_expr func_name)
        fields
      ||
      match base_opt with
      | Some e -> contains_function_call e func_name
      | None -> false)
  | Pexp_field (expr, _) -> contains_function_call expr func_name
  | Pexp_setfield (expr1, _, expr2) ->
      contains_function_call expr1 func_name
      || contains_function_call expr2 func_name
  | Pexp_function (_, _, Pfunction_body body) ->
      contains_function_call body func_name
  | Pexp_function (_, _, Pfunction_cases (cases, _, _)) ->
      List.exists
        (fun case -> contains_function_call case.pc_rhs func_name)
        cases
  | Pexp_assert expr
  | Pexp_lazy expr
  | Pexp_coerce (expr, _, _)
  | Pexp_constraint (expr, _)
  | Pexp_send (expr, _)
  | Pexp_variant (_, Some expr)
  | Pexp_open (_, expr) ->
      contains_function_call expr func_name
  | _ -> false

(* Check if a method body contains a call to a specific function.
   This properly handles Pexp_function (lambda) by examining its body. *)

(** Check whether a method body calls a specific module-qualified function. *)
let method_body_calls_function (expr : expression) (module_name : string)
    (func_name : string) : bool =
  let rec check_expression (e : expression) : bool =
    match e.pexp_desc with
    | Pexp_apply (func_expr, _args) -> (
        (* Check if the function being called is the target function *)
        match func_expr.pexp_desc with
        | Pexp_ident { txt = Longident.Ldot (parent, name); _ } ->
            let parent_str = longident_to_string parent in
            parent_str = module_name && name = func_name
        | _ -> check_expression func_expr)
    | Pexp_let (_, bindings, body) ->
        List.exists (fun vb -> check_expression vb.pvb_expr) bindings
        || check_expression body
    | Pexp_sequence (e1, e2) -> check_expression e1 || check_expression e2
    | Pexp_ifthenelse (cond, if_true, if_false_opt) -> (
        check_expression cond || check_expression if_true
        ||
        match if_false_opt with
        | Some e -> check_expression e
        | None -> false)
    | Pexp_match (expr, cases) ->
        check_expression expr
        || List.exists (fun case -> check_expression case.pc_rhs) cases
    | Pexp_function (_, _, Pfunction_body body) -> check_expression body
    | Pexp_function (_, _, Pfunction_cases (cases, _, _)) ->
        List.exists (fun case -> check_expression case.pc_rhs) cases
    | _ -> false
  in
  check_expression expr

(* Assert that a let binding contains a specific function call *)

(** Assert that a [let] binding's body calls the named function. *)
let assert_let_binding_calls_function ast func_name binding_name =
  Helpers.expect_some
    (Fmt.str "Function %s not found" binding_name)
    (find_let_binding ast binding_name)
  @@ fun binding ->
  if not (contains_function_call binding.pvb_expr func_name) then
    Alcotest.fail
      (Fmt.str "Function %s does not call %s" binding_name func_name)

(* Check if an expression contains a method send (#method_name) *)

(** Recursively check whether an expression contains a method send
    ([#method_name]). *)
let rec contains_method_send (expr : expression) (method_name : string) : bool =
  match expr.pexp_desc with
  | Pexp_send (_, { txt; _ }) when String.equal txt method_name -> true
  | Pexp_send (recv, _) -> contains_method_send recv method_name
  | Pexp_apply (func_expr, args) ->
      contains_method_send func_expr method_name
      || List.exists (fun (_, arg) -> contains_method_send arg method_name) args
  | Pexp_let (_, bindings, body) ->
      List.exists
        (fun vb -> contains_method_send vb.pvb_expr method_name)
        bindings
      || contains_method_send body method_name
  | Pexp_constraint (expr, _) -> contains_method_send expr method_name
  | Pexp_function (_, _, Pfunction_body body) ->
      contains_method_send body method_name
  | Pexp_function (_, _, Pfunction_cases (cases, _, _)) ->
      List.exists
        (fun case -> contains_method_send case.pc_rhs method_name)
        cases
  | Pexp_sequence (e1, e2) ->
      contains_method_send e1 method_name || contains_method_send e2 method_name
  | Pexp_ifthenelse (cond, if_true, if_false_opt) -> (
      contains_method_send cond method_name
      || contains_method_send if_true method_name
      ||
      match if_false_opt with
      | Some e -> contains_method_send e method_name
      | None -> false)
  | Pexp_tuple exprs | Pexp_array exprs ->
      List.exists (fun e -> contains_method_send e method_name) exprs
  | _ -> false

(* Assert that a let binding contains a method send (#method_name) *)

(** Assert that a [let] binding's body sends the named method. *)
let assert_let_binding_sends_method ast method_name binding_name =
  Helpers.expect_some
    (Fmt.str "Function %s not found" binding_name)
    (find_let_binding ast binding_name)
  @@ fun binding ->
  if not (contains_method_send binding.pvb_expr method_name) then
    Alcotest.fail
      (Fmt.str "Function %s does not send #%s" binding_name method_name)

(* ========================================================================= *)
(* Method Conflict Detection Helpers *)
(* ========================================================================= *)

(* Check if a method exists as an actual method definition (not commented out) in a class *)

(** Check whether a method exists as an actual definition (virtual or concrete)
    in a class expression. *)
let method_exists_as_definition (class_expr : class_expr) (method_name : string)
    : bool =
  match find_method_in_class class_expr method_name with
  | Some cf -> (
      (* Check if the method field is not just a comment by verifying it has a concrete body or virtual type *)
      match cf.pcf_desc with
      | Pcf_method (_, _, Cfk_virtual _) ->
          true (* Virtual methods are actual definitions *)
      | Pcf_method (_, _, Cfk_concrete _) ->
          true (* Concrete methods are actual definitions *)
      | _ -> false)
  | None -> false

(* Check if a method signature exists in a class type (signature) *)

(** Check whether a method signature exists in a class type. *)
let method_signature_exists (class_type : class_type) (method_name : string) :
    bool =
  match find_method_in_class_type class_type method_name with
  | Some _ -> true (* Method signature exists in class type *)
  | None -> false

(* Find all method names in a class expression (actual definitions, not commented) *)
let find_all_methods_in_class (class_expr : class_expr) : string list =
  let rec find_methods_in_class_expr (cexp : class_expr) : string list =
    match cexp.pcl_desc with
    | Pcl_structure { pcstr_fields; _ } ->
        List.filter_map
          (fun cf ->
            match cf.pcf_desc with
            | Pcf_method ({ txt; _ }, _, Cfk_virtual _) -> Some txt
            | Pcf_method ({ txt; _ }, _, Cfk_concrete _) -> Some txt
            | _ -> None)
          pcstr_fields
    | Pcl_fun (_, _, _, body) -> find_methods_in_class_expr body
    | Pcl_apply (expr, _) -> find_methods_in_class_expr expr
    | Pcl_constraint (body, _) -> find_methods_in_class_expr body
    | _ -> []
  in
  find_methods_in_class_expr class_expr

(* Check if a method is mentioned in a comment within the class structure *)
let method_mentioned_in_comment (code : string) (method_name : string) : bool =
  (* Check for patterns like "(* method %s" which indicate commented methods *)
  let comment_pattern = Fmt.str "(* method %s" method_name in
  try
    ignore (Re.Str.search_forward (Re.Str.regexp_string comment_pattern) code 0);
    true
  with Not_found -> false

(* Validate that a conflicting method is properly commented out *)
let validate_method_is_commented_out ~(class_expr : class_expr)
    ~(class_code : string) ~(method_name : string) : unit =
  (* Method should NOT exist as an actual definition in the AST *)
  if method_exists_as_definition class_expr method_name then
    Alcotest.fail
      (Fmt.str
         "Method '%s' should be commented out but is present as a definition"
         method_name);

  (* Method SHOULD be mentioned in a comment in the generated code *)
  if not (method_mentioned_in_comment class_code method_name) then
    Alcotest.fail
      (Fmt.str "Method '%s' should be mentioned in a comment but is not"
         method_name)

(* Validate that a non-conflicting method is properly generated *)
let validate_method_is_generated ~(class_expr : class_expr)
    ~(method_name : string) : unit =
  if not (method_exists_as_definition class_expr method_name) then
    Alcotest.fail
      (Fmt.str "Method '%s' should be generated but is not present" method_name)

(* ========================================================================= *)
(* Class Type Declaration Helpers (for Layer 2 class type validation)        *)
(* ========================================================================= *)

(** Format a Longident to a dot-separated string. *)
let rec longident_to_string_phase4 = function
  | Longident.Lident s -> s
  | Longident.Ldot (lid, s) -> longident_to_string_phase4 lid ^ "." ^ s
  | Longident.Lapply (l, r) ->
      longident_to_string_phase4 l ^ "(" ^ longident_to_string_phase4 r ^ ")"

(** Extract a dotted-name string from a class_type node. Returns None if the
    node is not a simple constr reference. *)
let class_type_constr_name (cty : class_type) : string option =
  match cty.pcty_desc with
  | Pcty_constr ({ txt; _ }, _) -> Some (longident_to_string_phase4 txt)
  | _ -> None

(** Find a class type declaration by name in a structure (.ml). *)
let find_class_type_declaration_impl (ast : structure) (name : string) :
    class_type_declaration option =
  List.find_map
    (fun item ->
      match item.pstr_desc with
      | Pstr_class_type ctds ->
          List.find_opt (fun ctd -> String.equal ctd.pci_name.txt name) ctds
      | _ -> None)
    ast

(** Find a class type declaration by name in a signature (.mli). *)
let find_class_type_declaration_sig2 (ast : signature) (name : string) :
    class_type_declaration option =
  List.find_map
    (fun item ->
      match item.psig_desc with
      | Psig_class_type ctds ->
          List.find_opt (fun ctd -> String.equal ctd.pci_name.txt name) ctds
      | _ -> None)
    ast

(** Extract the list of inherited class type names from a
    class_type_declaration. *)
let get_class_type_inherit_names (ctd : class_type_declaration) : string list =
  match ctd.pci_expr.pcty_desc with
  | Pcty_signature { pcsig_fields; _ } ->
      List.filter_map
        (fun field ->
          match field.pctf_desc with
          | Pctf_inherit cty -> class_type_constr_name cty
          | _ -> None)
        pcsig_fields
  | _ -> []

(** Find a class definition by name in a structure (.ml). *)
let find_class_definition (ast : structure) (name : string) :
    class_declaration option =
  List.find_map
    (fun item ->
      match item.pstr_desc with
      | Pstr_class cds ->
          List.find_opt (fun cd -> String.equal cd.pci_name.txt name) cds
      | _ -> None)
    ast

(** Collect inherit names from a class expression (the rhs of class foo = ...).
*)
let rec collect_class_expr_inherits (cexpr : class_expr) : string list =
  match cexpr.pcl_desc with
  | Pcl_structure { pcstr_fields; _ } ->
      List.filter_map
        (fun field ->
          match field.pcf_desc with
          | Pcf_inherit (_, ce, _) -> (
              match ce.pcl_desc with
              | Pcl_apply (fn, _) -> (
                  match fn.pcl_desc with
                  | Pcl_constr ({ txt; _ }, _) ->
                      Some (longident_to_string_phase4 txt)
                  | _ -> None)
              | Pcl_constr ({ txt; _ }, _) ->
                  Some (longident_to_string_phase4 txt)
              | _ -> None)
          | _ -> None)
        pcstr_fields
  | Pcl_fun (_, _, _, body) -> collect_class_expr_inherits body
  | Pcl_constraint (ce, _) -> collect_class_expr_inherits ce
  | _ -> []

(** Get the list of inherited class names from a class declaration's body. *)
let get_class_inherit_names (cd : class_declaration) : string list =
  collect_class_expr_inherits cd.pci_expr

(* ========================================================================= *)
(* Arrow Type Label and Parameter Helpers                                     *)
(* ========================================================================= *)

(** Extract all (arg_label, core_type) pairs from a function type, in order.
    Stops at the final return type. *)
let rec get_arrow_params_with_labels (ct : core_type) :
    (arg_label * core_type) list =
  match ct.ptyp_desc with
  | Ptyp_arrow (lbl, param_type, rest) ->
      (lbl, param_type) :: get_arrow_params_with_labels rest
  | _ -> []

(** Find the labelled parameter with the given name in a function type. Matches
    both [Labelled name] and [Optional name]. *)
let find_labelled_param (ct : core_type) (label : string) : core_type option =
  let params = get_arrow_params_with_labels ct in
  List.find_map
    (fun (lbl, param_ct) ->
      match lbl with
      | Labelled l when l = label -> Some param_ct
      | Optional l when l = label -> Some param_ct
      | _ -> None)
    params

(** Check whether the labelled parameter [label] exists in the function type
    with a [core_type] whose string representation matches [type_str]. *)
let has_labelled_param_with_type (ct : core_type) (label : string)
    (type_str : string) : bool =
  match find_labelled_param ct label with
  | None -> false
  | Some param_ct -> String.equal (core_type_to_string param_ct) type_str

(** Check that no positional ([Nolabel]) parameter in a function type has a
    label — i.e. check [label] does not appear as any arrow label in [ct]. *)
let has_no_labelled_param (ct : core_type) (label : string) : bool =
  let params = get_arrow_params_with_labels ct in
  not
    (List.exists
       (fun (lbl, _) ->
         match lbl with
         | Labelled l | Optional l -> String.equal l label
         | Nolabel -> false)
       params)

(* ========================================================================= *)
(* Closure.nth Position Helpers                                               *)
(* ========================================================================= *)

(** Collect the integer values of all [~pos:N] labels in [Gobject.Closure.nth]
    calls within [expr]. Returns the list of positions found. *)
let collect_closure_nth_positions (expr : expression) : int list =
  let positions = ref [] in
  let rec scan (e : expression) =
    match e.pexp_desc with
    | Pexp_apply (func_expr, args) ->
        (* Check if the function being called is Gobject.Closure.nth *)
        let is_closure_nth =
          match func_expr.pexp_desc with
          | Pexp_ident { txt = Longident.Ldot (parent, "nth"); _ } ->
              longident_to_string parent = "Gobject.Closure"
          | _ -> false
        in
        if is_closure_nth then
          List.iter
            (fun (lbl, arg_expr) ->
              match lbl with
              | Labelled "pos" -> (
                  match arg_expr.pexp_desc with
                  | Pexp_constant (Pconst_integer (s, _)) -> (
                      match int_of_string_opt s with
                      | Some n -> positions := n :: !positions
                      | None -> ())
                  | _ -> ())
              | _ -> ())
            args;
        scan func_expr;
        List.iter (fun (_, arg) -> scan arg) args
    | Pexp_let (_, bindings, body) ->
        List.iter (fun vb -> scan vb.pvb_expr) bindings;
        scan body
    | Pexp_sequence (e1, e2) ->
        scan e1;
        scan e2
    | Pexp_function (_, _, Pfunction_body body) -> scan body
    | Pexp_function (_, _, Pfunction_cases (cases, _, _)) ->
        List.iter (fun case -> scan case.pc_rhs) cases
    | Pexp_match (scrutinee, cases) ->
        scan scrutinee;
        List.iter (fun case -> scan case.pc_rhs) cases
    | Pexp_ifthenelse (cond, if_true, if_false_opt) ->
        scan cond;
        scan if_true;
        Option.iter scan if_false_opt
    | Pexp_tuple exprs | Pexp_array exprs -> List.iter scan exprs
    | Pexp_constraint (inner, _) -> scan inner
    | Pexp_coerce (inner, _, _) -> scan inner
    | _ -> ()
  in
  scan expr;
  !positions

(** Return [true] iff no [Gobject.Closure.nth] call in [expr] uses [~pos:0]. *)
let no_closure_nth_at_pos_zero (expr : expression) : bool =
  let positions = collect_closure_nth_positions expr in
  not (List.mem 0 positions)

(* ========================================================================= *)
(* Callback Labelled-Arg Helpers                                              *)
(* ========================================================================= *)

(** Collect all labelled argument names used in applications of [func_name]
    within [expr]. Returns the list of label strings. *)
let collect_labelled_args_of_call (expr : expression) (func_name : string) :
    string list =
  let labels = ref [] in
  let rec scan (e : expression) =
    match e.pexp_desc with
    | Pexp_apply (func_expr, args) ->
        let is_target =
          match func_expr.pexp_desc with
          | Pexp_ident { txt = Longident.Lident name; _ } ->
              String.equal name func_name
          | _ -> false
        in
        if is_target then
          List.iter
            (fun (lbl, _) ->
              match lbl with
              | Labelled l | Optional l -> labels := l :: !labels
              | Nolabel -> ())
            args;
        scan func_expr;
        List.iter (fun (_, arg) -> scan arg) args
    | Pexp_let (_, bindings, body) ->
        List.iter (fun vb -> scan vb.pvb_expr) bindings;
        scan body
    | Pexp_sequence (e1, e2) ->
        scan e1;
        scan e2
    | Pexp_function (_, _, Pfunction_body body) -> scan body
    | Pexp_function (_, _, Pfunction_cases (cases, _, _)) ->
        List.iter (fun case -> scan case.pc_rhs) cases
    | Pexp_match (scrutinee, cases) ->
        scan scrutinee;
        List.iter (fun case -> scan case.pc_rhs) cases
    | Pexp_ifthenelse (cond, if_true, if_false_opt) ->
        scan cond;
        scan if_true;
        Option.iter scan if_false_opt
    | Pexp_tuple exprs | Pexp_array exprs -> List.iter scan exprs
    | Pexp_constraint (inner, _) -> scan inner
    | Pexp_coerce (inner, _, _) -> scan inner
    | _ -> ()
  in
  scan expr;
  !labels
