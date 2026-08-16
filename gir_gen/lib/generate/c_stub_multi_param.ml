(* Multi-parameter C wrapper generation for functions with more than 5 params *)

open Containers
open StdLabels

(* [generate_multi_param_function ~ml_name ~params ~param_names body_code]
   generates both native and bytecode C wrapper variants for functions with >5 parameters.
   Shared by generate_c_constructor and generate_c_method to eliminate the
   byte-for-byte duplication that previously lived in both modules.
   Takes the function name, C parameter declarations, parameter names, and body code.
   Returns the combined native + bytecode function code as a string. *)
let generate_multi_param_function ~ml_name ~params ~param_names body_code =
  let first_five = List.filteri ~f:(fun i _ -> i < 5) param_names in
  let rest = List.filteri ~f:(fun i _ -> i >= 5) param_names in

  (* Split remaining params into chunks of at most 5 for CAMLxparam *)
  let rec chunk_params params =
    match params with
    | [] -> []
    | _ ->
        let chunk = List.filteri ~f:(fun i _ -> i < 5) params in
        let remaining = List.filteri ~f:(fun i _ -> i >= 5) params in
        chunk :: chunk_params remaining
  in
  let xparam_chunks = chunk_params rest in
  let xparam_lines =
    String.concat ~sep:"\n"
      (List.map
         ~f:(fun chunk ->
           Fmt.str "CAMLxparam%d(%s);" (List.length chunk)
             (String.concat ~sep:", " chunk))
         xparam_chunks)
  in

  let native_func =
    Fmt.str
      "\nCAMLexport CAMLprim value %s_native(%s)\n{\nCAMLparam5(%s);\n%s\n%s}\n"
      ml_name
      (String.concat ~sep:", " params)
      (String.concat ~sep:", " first_five)
      xparam_lines body_code
  in

  let bytecode_func =
    Fmt.str
      "\n\
       CAMLexport CAMLprim value %s_bytecode(value * argv, int argn)\n\
       {\n\
       return %s_native(%s);\n\
       }\n"
      ml_name ml_name
      (String.concat ~sep:", "
         (List.mapi ~f:(fun i _ -> Fmt.str "argv[%d]" i) param_names))
  in

  native_func ^ bytecode_func
