(* Converter method generation for hierarchies and classes *)

open! Containers

(* Drop-in for [bprintf] that flushes to the buffer. [Format.fprintf]
   on a [formatter_of_buffer] does not auto-flush, so flush in [kfprintf]'s
   continuation. *)
let bprintf buf fmt =
  Format.kfprintf
    (fun fmtr -> Format.pp_print_flush fmtr ())
    (Format.formatter_of_buffer buf)
    fmt

let generate_class_converter_method_sig ~ctx ~class_name buf =
  bprintf buf "    method as_%s : %s.t\n"
    (Utils.ocaml_class_name class_name)
    (Class_utils.get_qualified_module_name ~ctx class_name)

let generate_class_converter_method_impl ~class_name buf =
  bprintf buf "    method as_%s = obj\n" (Utils.ocaml_class_name class_name)
