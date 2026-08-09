(* Converter method generation for hierarchies and classes *)

open! Containers
open Gen_buffer

(** Emit the [method as_<class> : <layer1_module>.t] signature line for the
    class converter method. *)
let generate_class_converter_method_sig ~ctx ~class_name buf =
  bprintf buf "    method as_%s : %s.t\n"
    (Utils.ocaml_class_name class_name)
    (Class_utils.get_qualified_module_name ~ctx class_name)

(** Emit the [method as_<class> = obj] implementation line for the class
    converter method. *)
let generate_class_converter_method_impl ~class_name buf =
  bprintf buf "    method as_%s = obj\n" (Utils.ocaml_class_name class_name)
