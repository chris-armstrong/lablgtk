val create_test_class_with_parent :
  name:string ->
  c_type:string ->
  ?parent:string option ->
  unit ->
  Gir_gen_lib.Types.gir_class

val create_parent_class :
  name:string -> c_type:string -> unit -> Gir_gen_lib.Types.gir_class

val create_child_class :
  name:string ->
  c_type:string ->
  parent_name:string ->
  unit ->
  Gir_gen_lib.Types.gir_class

val create_test_class_with_methods :
  name:string ->
  c_type:string ->
  methods:Gir_gen_lib.Types.gir_method list ->
  unit ->
  Gir_gen_lib.Types.gir_class

val create_test_method :
  name:string -> c_identifier:string -> unit -> Gir_gen_lib.Types.gir_method

val create_test_method_with_param :
  name:string ->
  c_identifier:string ->
  param_name:string ->
  param_type:Gir_gen_lib.Types.gir_type ->
  unit ->
  Gir_gen_lib.Types.gir_method

val create_test_method_with_params :
  name:string ->
  c_identifier:string ->
  params:Gir_gen_lib.Types.gir_param list ->
  unit ->
  Gir_gen_lib.Types.gir_method

val create_test_method_with_return :
  name:string ->
  c_identifier:string ->
  return_type:Gir_gen_lib.Types.gir_type ->
  unit ->
  Gir_gen_lib.Types.gir_method

val create_test_method_throwing :
  name:string -> c_identifier:string -> unit -> Gir_gen_lib.Types.gir_method

val validate_layer2_output :
  output_dir:string ->
  module_name:string ->
  expected_types:string list ->
  string
  * string
  * Ppxlib_ast__Import.Js.Ast.Parsetree.structure
  * Ppxlib_ast__Import.Js.Ast.Parsetree.signature

val validate_accessor_method :
  ml_ast:Ppxlib.Parsetree.structure -> accessor_name:string -> unit

val validate_inheritance :
  ml_ast:Ppxlib.Parsetree.structure ->
  parent_name:string ->
  child_name:string ->
  unit

val validate_method_generation :
  ml_ast:Ppxlib.Parsetree.structure -> method_name:string -> unit

val check_mli_vs_ml_consistency :
  mli_ast:Ppxlib.Parsetree.signature ->
  ml_ast:Ppxlib.Parsetree.structure ->
  type_name:string ->
  unit

val check_externals_consistency :
  mli_ast:Ppxlib.Parsetree.signature ->
  ml_ast:Ppxlib.Parsetree.structure ->
  external_name:string ->
  unit

val validate_function_signature_consistency :
  mli_ast:Ppxlib.Parsetree.signature ->
  ml_ast:Ppxlib.Parsetree.structure ->
  func_name:string ->
  unit

val validate_conversion_methods :
  ml_ast:Ppxlib.Parsetree.structure -> from_type:'a -> to_type:string -> unit

val validate_base_type_conversion :
  ml_ast:Ppxlib.Parsetree.structure -> class_name:'a -> base_type:string -> unit

val validate_property_generation :
  ml_ast:Ppxlib.Parsetree.structure -> property_name:string -> unit

val validate_signal_generation :
  ml_ast:Ppxlib.Parsetree.structure -> signal_name:string -> unit

val validate_abstract_type_wrapper :
  mli_ast:Ppxlib.Parsetree.signature -> type_name:string -> unit

val validate_gobject_wrapper :
  ml_ast:Ppxlib.Parsetree.structure -> type_name:string -> unit

val validate_structural_type_parameter :
  mli_ast:Ppxlib.Parsetree.signature ->
  type_name:string ->
  field_name:string ->
  field_type:string ->
  unit

val validate_hierarchy_coercion :
  mli_ast:Ppxlib.Parsetree.signature ->
  function_name:string ->
  param_idx:int ->
  expected_coercion:String.t ->
  unit

val validate_wrapped_return :
  ml_ast:Ppxlib.Parsetree.structure ->
  function_name:string ->
  wrapper_class:string ->
  unit

val validate_signal_handler_inheritance :
  mli_ast:Ppxlib.Parsetree.signature ->
  signal_handler_name:string ->
  parent_signal:string ->
  unit

val create_test_signal : name:string -> Gir_gen_lib.Types.gir_signal

val create_test_signal_with_return :
  name:string ->
  return_type:Gir_gen_lib.Types.gir_type ->
  Gir_gen_lib.Types.gir_signal

val create_test_signal_with_params :
  name:string ->
  return_type:Gir_gen_lib.Types.gir_type ->
  params:Gir_gen_lib.Types.gir_param list ->
  Gir_gen_lib.Types.gir_signal

val create_test_class_with_signals :
  name:string ->
  c_type:string ->
  signals:Gir_gen_lib.Types.gir_signal list ->
  unit ->
  Gir_gen_lib.Types.gir_class

val validate_class_inherits :
  structure:Ppxlib.Parsetree.structure ->
  class_name:string ->
  parent_class:string ->
  unit

val validate_class_type_inherits :
  signature:Ppxlib.Parsetree.signature ->
  class_name:string ->
  parent_class_type:string ->
  unit

val validate_method_type_annotation :
  structure:Ppxlib.Parsetree.structure ->
  class_name:string ->
  method_name:string ->
  expected_type:String.t ->
  unit

val validate_method_type_annotation_sig :
  signature:Ppxlib.Parsetree.signature ->
  class_name:string ->
  method_name:string ->
  expected_type:String.t ->
  unit

val create_gir_class_with_parent :
  class_name:string -> c_type:string -> parent_name:string -> string

val create_gir_method : method_name:string -> c_name:string -> string

val create_gir_method_with_param :
  method_name:string ->
  c_name:string ->
  param_name:string ->
  param_type:string ->
  string

val add_class_with_hierarchy :
  context:Gir_gen_lib.Types.generation_context ->
  class_name:string ->
  parent_name:string ->
  layer2_module:'a ->
  base_type:'b ->
  Gir_gen_lib.Types.generation_context

val create_test_context_with_hierarchy_chain :
  base_class:string ->
  derived_classes:string list ->
  Gir_gen_lib.Types.generation_context
