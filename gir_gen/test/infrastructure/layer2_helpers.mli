(* Layer 2 test infrastructure: helpers for testing class hierarchies and
   inheritance *)

(** {1 Signal Creation Helpers} *)

val create_test_signal : name:string -> Gir_gen_lib.Types.gir_signal
(** [create_test_signal ~name] builds a minimal GIR signal with a void return
    type and no parameters. *)

(** {1 Class Inheritance Validation Helpers} *)

val validate_class_inherits :
  structure:Ppxlib.Parsetree.structure ->
  class_name:string ->
  parent_class:string ->
  unit
(** [validate_class_inherits ~structure ~class_name ~parent_class] fails the
    test unless the class [class_name] in [structure] inherits from
    [parent_class]. *)

val validate_class_type_inherits :
  signature:Ppxlib.Parsetree.signature ->
  class_name:string ->
  parent_class_type:string ->
  unit
(** [validate_class_type_inherits ~signature ~class_name ~parent_class_type]
    fails the test unless the class type [class_name] in [signature] inherits
    from [parent_class_type]. *)

(** {1 Method Type Annotation Validation Helpers} *)

val validate_method_type_annotation :
  structure:Ppxlib.Parsetree.structure ->
  class_name:string ->
  method_name:string ->
  expected_type:string ->
  unit
(** [validate_method_type_annotation ~structure ~class_name ~method_name
     ~expected_type] fails the test unless the method [method_name] of class
    [class_name] in [structure] carries the type annotation [expected_type]. *)

val validate_method_type_annotation_sig :
  signature:Ppxlib.Parsetree.signature ->
  class_name:string ->
  method_name:string ->
  expected_type:string ->
  unit
(** [validate_method_type_annotation_sig ~signature ~class_name ~method_name
     ~expected_type] fails the test unless the method [method_name] of class
    [class_name] in [signature] carries the type annotation [expected_type]. *)
