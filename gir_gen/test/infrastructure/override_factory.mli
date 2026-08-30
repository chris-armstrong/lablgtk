val make_version_spec :
  ?namespace:string option ->
  version:string ->
  unit ->
  Gir_gen_lib.Override_types.version_spec

val make_component :
  ?action:Gir_gen_lib.Override_types.override_action option ->
  ?os:Gir_gen_lib.Os_filter.t option ->
  name:string ->
  unit ->
  Gir_gen_lib.Override_types.component_override

val ignore_component :
  name:string -> Gir_gen_lib.Override_types.component_override

val version_component :
  ?namespace:string option option ->
  name:string ->
  version:string ->
  unit ->
  Gir_gen_lib.Override_types.component_override

val make_class_override :
  ?action:Gir_gen_lib.Override_types.override_action option ->
  ?os:Gir_gen_lib.Os_filter.t option ->
  ?constructors:Gir_gen_lib.Override_types.component_override list ->
  ?methods:Gir_gen_lib.Override_types.component_override list ->
  ?properties:Gir_gen_lib.Override_types.component_override list ->
  ?signals:Gir_gen_lib.Override_types.component_override list ->
  name:string ->
  unit ->
  Gir_gen_lib.Override_types.class_override

val make_interface_override :
  ?action:Gir_gen_lib.Override_types.override_action option ->
  ?os:Gir_gen_lib.Os_filter.t option ->
  ?methods:Gir_gen_lib.Override_types.component_override list ->
  ?properties:Gir_gen_lib.Override_types.component_override list ->
  ?signals:Gir_gen_lib.Override_types.component_override list ->
  name:string ->
  unit ->
  Gir_gen_lib.Override_types.interface_override

val make_record_override :
  ?action:Gir_gen_lib.Override_types.override_action option ->
  ?os:Gir_gen_lib.Os_filter.t option ->
  ?fields:Gir_gen_lib.Override_types.component_override list ->
  ?constructors:Gir_gen_lib.Override_types.component_override list ->
  ?methods:Gir_gen_lib.Override_types.component_override list ->
  ?functions:Gir_gen_lib.Override_types.component_override list ->
  name:string ->
  unit ->
  Gir_gen_lib.Override_types.record_override

val make_enum_override :
  ?action:Gir_gen_lib.Override_types.override_action option ->
  ?os:Gir_gen_lib.Os_filter.t option ->
  ?members:Gir_gen_lib.Override_types.component_override list ->
  ?functions:Gir_gen_lib.Override_types.component_override list ->
  name:string ->
  unit ->
  Gir_gen_lib.Override_types.enum_override

val make_bitfield_override :
  ?action:Gir_gen_lib.Override_types.override_action option ->
  ?os:Gir_gen_lib.Os_filter.t option ->
  ?flags:Gir_gen_lib.Override_types.component_override list ->
  name:string ->
  unit ->
  Gir_gen_lib.Override_types.bitfield_override

val make_library_overrides :
  ?classes:Gir_gen_lib.Override_types.class_override list ->
  ?interfaces:Gir_gen_lib.Override_types.interface_override list ->
  ?records:Gir_gen_lib.Override_types.record_override list ->
  ?enums:Gir_gen_lib.Override_types.enum_override list ->
  ?bitfields:Gir_gen_lib.Override_types.bitfield_override list ->
  ?functions:Gir_gen_lib.Override_types.component_override list ->
  ?headers:Gir_gen_lib.Override_types.header_override list ->
  name:string ->
  unit ->
  Gir_gen_lib.Override_types.library_overrides

val make_empty_library_overrides :
  name:string -> Gir_gen_lib.Override_types.library_overrides
