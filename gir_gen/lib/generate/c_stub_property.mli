(** C stub code generation for GObject property getters and setters.

    Generates the C wrapper functions that read and write GObject properties via
    [g_object_get_property] / [g_object_set_property], converting between OCaml
    values and [GValue]s. *)

val generate_c_property_getter :
  ctx:Types.generation_context ->
  c_type:string ->
  Types.gir_property ->
  string ->
  string
(** [generate_c_property_getter ~ctx ~c_type prop class_name] generates the C
    wrapper function that reads the GObject property [prop] of [class_name] and
    converts its value to an OCaml value.

    @param ctx generation context (type mappings, records, classes)
    @param c_type C type of the owning class, e.g. ["GtkButton"]
    @param prop the property to read
    @param class_name OCaml class name used to derive the wrapper function name
    @return
      the complete C function source (without version guards; those are applied
      by the caller at class level) *)

val generate_c_property_setter :
  ctx:Types.generation_context ->
  c_type:string ->
  Types.gir_property ->
  string ->
  string
(** [generate_c_property_setter ~ctx ~c_type prop class_name] generates the C
    wrapper function that converts an OCaml value and writes it to the GObject
    property [prop] of [class_name].

    @param ctx generation context (type mappings, records, classes)
    @param c_type C type of the owning class, e.g. ["GtkButton"]
    @param prop the property to write
    @param class_name OCaml class name used to derive the wrapper function name
    @return
      the complete C function source (without version guards; those are applied
      by the caller at class level) *)
