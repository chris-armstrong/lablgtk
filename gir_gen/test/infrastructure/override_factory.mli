(* Shared factories for [Gir_gen_lib.Override_types] records.

   Every factory takes optional arguments defaulting to the empty/[None]
   value, so call sites only spell out the fields that matter for the test. *)

val make_version_spec :
  ?namespace:string option ->
  version:string ->
  unit ->
  Gir_gen_lib.Override_types.version_spec
(** [make_version_spec ?namespace ~version ()] builds a [version_spec] for
    [version], optionally scoped to [namespace]. *)

val ignore_component :
  name:string -> Gir_gen_lib.Override_types.component_override
(** [ignore_component ~name] marks the component [name] with the [Ignore]
    action. *)

val version_component :
  ?namespace:string option option ->
  name:string ->
  version:string ->
  unit ->
  Gir_gen_lib.Override_types.component_override
(** [version_component ?namespace ~name ~version ()] marks the component [name]
    with a [Set_version] action for [version], optionally scoped to [namespace].
*)

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
(** [make_class_override ?action ?os ?constructors ?methods ?properties ?signals
     ~name ()] builds a [class_override] for the class [name]. *)

val make_interface_override :
  ?action:Gir_gen_lib.Override_types.override_action option ->
  ?os:Gir_gen_lib.Os_filter.t option ->
  ?methods:Gir_gen_lib.Override_types.component_override list ->
  ?properties:Gir_gen_lib.Override_types.component_override list ->
  ?signals:Gir_gen_lib.Override_types.component_override list ->
  name:string ->
  unit ->
  Gir_gen_lib.Override_types.interface_override
(** [make_interface_override ?action ?os ?methods ?properties ?signals ~name ()]
    builds an [interface_override] for the interface [name]. *)

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
(** [make_record_override ?action ?os ?fields ?constructors ?methods ?functions
     ~name ()] builds a [record_override] for the record [name]. *)

val make_enum_override :
  ?action:Gir_gen_lib.Override_types.override_action option ->
  ?os:Gir_gen_lib.Os_filter.t option ->
  ?members:Gir_gen_lib.Override_types.component_override list ->
  ?functions:Gir_gen_lib.Override_types.component_override list ->
  name:string ->
  unit ->
  Gir_gen_lib.Override_types.enum_override
(** [make_enum_override ?action ?os ?members ?functions ~name ()] builds an
    [enum_override] for the enum [name]. *)

val make_bitfield_override :
  ?action:Gir_gen_lib.Override_types.override_action option ->
  ?os:Gir_gen_lib.Os_filter.t option ->
  ?flags:Gir_gen_lib.Override_types.component_override list ->
  name:string ->
  unit ->
  Gir_gen_lib.Override_types.bitfield_override
(** [make_bitfield_override ?action ?os ?flags ~name ()] builds a
    [bitfield_override] for the bitfield [name]. *)

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
(** [make_library_overrides ?classes ?interfaces ?records ?enums ?bitfields
     ?functions ?headers ~name ()] builds a [library_overrides] for the library
    [name]. *)

val make_empty_library_overrides :
  name:string -> Gir_gen_lib.Override_types.library_overrides
(** [make_empty_library_overrides ~name] builds a [library_overrides] with every
    component list empty. *)
