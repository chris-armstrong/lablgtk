(* Layer 1 Constructor - Constructor generation for OCaml interfaces *)

open StdLabels
open Gen_buffer
open Types

(** Build constructor signature string from parameters *)
let build_constructor_signature ~ctx ~class_name ctor =
  let param_types =
    List.map
      ~f:(Layer1_helpers.map_constructor_param ~ctx ~class_name)
      ctor.ctor_parameters
  in
  let return_type =
    match ctor.throws with true -> "(t, GError.t) result" | false -> "t"
  in
  (* Generate signature: param1 -> param2 -> ... -> t *)
  if List.length param_types = 0 then Fmt.str "unit -> %s" return_type
  else String.concat ~sep:" -> " (param_types @ [ return_type ])

(** Format constructor external declaration with bytecode/native support *)
let format_constructor_external ~ocaml_ctor_name ~signature ~ml_name ctor =
  let param_count =
    if List.length ctor.ctor_parameters = 0 then 1
    else List.length ctor.ctor_parameters
  in
  Layer1_helpers.format_external ~ocaml_name:ocaml_ctor_name ~signature ~ml_name
    ~param_count

(** Check if a constructor should be generated in the interface. Delegates to
    the shared [Filtering.should_generate_constructor] so that layer 0 (C stubs)
    and layer 1 (OCaml externals) agree on what is emitted. *)
let should_generate_constructor ~ctx (ctor : gir_constructor) =
  Filtering.should_generate_constructor ~ctx ctor

(** Generate a single constructor declaration and write it to the buffer *)
let generate_constructor_decl ~ctx ~class_name ~buf (ctor : gir_constructor) =
  bprintf buf "(** Create a new %s *)\n" class_name;
  let ml_name = Utils.ml_constructor_name ~class_name ~constructor:ctor in
  let ocaml_ctor_name = Utils.ocaml_constructor_name ~class_name ctor in

  let signature = build_constructor_signature ~ctx ~class_name ctor in
  let decl =
    format_constructor_external ~ocaml_ctor_name ~signature ~ml_name ctor
  in
  bprintf buf "%s" decl
