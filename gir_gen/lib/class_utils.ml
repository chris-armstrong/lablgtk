open Types

(** Return the fully qualified module name for a class, accounting for cyclic
    module groups: classes in a cyclic group are addressed as
    [CombinedModule.ClassName], all others by their plain module name. *)
let get_qualified_module_name ~ctx class_name =
  (* Always check if this class is in a cyclic group and use the full path if so *)
  match Hashtbl.find_opt ctx.module_groups class_name with
  | Some combined_module_name ->
      let simple_module_name = Utils.module_name_of_class class_name in
      (* Check if this is a cyclic module by comparing names *)
      if combined_module_name <> simple_module_name then
        (* For cyclic modules, we need CombinedModule.ClassName *)
        combined_module_name ^ "." ^ simple_module_name
      else
        (* Single module (non-cyclic even though in module_groups table) *)
        combined_module_name
  | None -> Utils.module_name_of_class class_name
