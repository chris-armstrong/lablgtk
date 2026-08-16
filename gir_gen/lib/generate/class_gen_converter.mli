(** Generation of the [as_<class>] converter methods for layer 2 classes. *)

val generate_class_converter_method_sig :
  ctx:Types.generation_context -> class_name:string -> Buffer.t -> unit
(** [generate_class_converter_method_sig ~ctx ~class_name buf] emits the
    [method as_<class> : <layer1_module>.t] signature line into [buf]. *)

val generate_class_converter_method_impl : class_name:string -> Buffer.t -> unit
(** [generate_class_converter_method_impl ~class_name buf] emits the
    [method as_<class> = obj] implementation line into [buf]. *)
