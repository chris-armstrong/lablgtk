(** Generation of the [as_<class>] converter methods for layer 2 classes. *)

val generate_class_converter_method_sig :
  ctx:Types.generation_context -> class_name:string -> Buffer.t -> unit
(** Emit the [method as_<class> : <layer1_module>.t] signature line for the
    class converter method into [buf].

    Parameters:
    - ctx: generation context, used to resolve the layer 1 module name
    - class_name: GIR class name (e.g. "GtkWidget")
    - buf: output buffer

    Returns: unit (appends to [buf]). *)

val generate_class_converter_method_impl : class_name:string -> Buffer.t -> unit
(** Emit the [method as_<class> = obj] implementation line for the class
    converter method into [buf].

    Parameters:
    - class_name: GIR class name (e.g. "GtkWidget")
    - buf: output buffer

    Returns: unit (appends to [buf]). *)
