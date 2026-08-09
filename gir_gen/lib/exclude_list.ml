(* Exclusion lists and filtering logic for GIR Code Generator *)

open StdLabels
open Types

module Log =
  (val Logs.src_log
         (Logs.Src.create "gir_gen.exclude_list"
            ~doc:"Exclusion lists and filtering logic for GIR Code Generator"))

(** Decide whether a method should be skipped because its return type or any
    parameter type cannot be resolved to a type mapping. The [enums] and
    [bitfields] arguments are unused; they are kept for signature symmetry. *)
let should_skip_method
    ~(find_type_mapping : Types.gir_type -> Types.type_mapping option)
    ~enums:(_ : Types.gir_enum list) ~bitfields:(_ : Types.gir_bitfield list)
    (meth : Types.gir_method) =
  (* Skip if return type is unknown and not void *)
  let has_unknown_return =
    if
      not
        (Option.equal String.equal meth.Types.return_type.Types.c_type
           (Some "void"))
    then
      match find_type_mapping meth.Types.return_type with
      | None ->
          Fmt.epr "Skipping method %s: unknown return type %s\n"
            meth.Types.method_name meth.Types.return_type.Types.name;
          true
      | Some _ -> false
    else false
  in

  (* Skip if any parameter has an unknown type *)
  let has_unknown_params =
    List.exists
      ~f:(fun (p : Types.gir_param) ->
        if p.Types.varargs then false
        else
          match find_type_mapping p.Types.param_type with
          | None ->
              Fmt.epr
                "Skipping method %s: unknown parameter type %s for parameter %s\n"
                meth.Types.method_name p.Types.param_type.Types.name
                p.Types.param_name;
              true
          | Some _ -> false)
      meth.Types.parameters
  in

  Log.debug (fun m ->
      m "Exclude_list.should_skip_method: %s -> %s=%b %b\n"
        meth.Types.method_name meth.Types.return_type.name has_unknown_return
        has_unknown_params);
  has_unknown_return || has_unknown_params

(** Decide whether a constructor should be skipped because any parameter type
    cannot be resolved to a type mapping. The [enums] and [bitfields] arguments
    are unused; they are kept for signature symmetry. *)
let should_skip_constructor
    ~(find_type_mapping : Types.gir_type -> Types.type_mapping option)
    ~enums:(_ : Types.gir_enum list) ~bitfields:(_ : Types.gir_bitfield list)
    (ctor : Types.gir_constructor) =
  (* Skip if any parameter has an unknown type *)
  let has_unknown_params =
    List.exists
      ~f:(fun (p : Types.gir_param) ->
        if p.Types.varargs then false
        else
          match find_type_mapping p.Types.param_type with
          | None ->
              Fmt.epr
                "Skipping constructor %s: unknown parameter type %s for \
                 parameter %s\n"
                ctor.Types.ctor_name p.Types.param_type.Types.name
                p.Types.param_name;
              true
          | Some _ -> false)
      ctor.Types.ctor_parameters
  in

  Log.debug (fun m ->
      m "Exclude_list.should_skip_constructor: %s -> %b\n" ctor.Types.ctor_name
        has_unknown_params);
  has_unknown_params
