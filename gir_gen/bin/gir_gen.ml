(* Main Entry Point for GIR Code Generator *)

open Gir_gen_lib.Gen_buffer
open StdLabels
open Cmdliner
open Gir_gen_lib.Types

(* Helper function to write content to a file *)
let write_file ~path ~content =
  Fmt.pr "Writing %s...\n" path;
  let oc = open_out path in
  output_string oc content;
  close_out oc

(* Helper function to get the generated output directory *)
let generated_output_dir output_dir = Filename.concat output_dir "generated"

(* Ensure the generated directory exists *)
let ensure_generated_dir output_dir =
  let gen_dir = generated_output_dir output_dir in
  if not (Sys.file_exists gen_dir) then Unix.mkdir gen_dir 0o755

type entity_generators = {
  generate_c_stub_headers :
    ctx:generation_context -> entity:entity -> Buffer.t -> unit;
  generate_c_stub_converters :
    ctx:generation_context -> entity:entity -> Buffer.t -> unit;
  generate_c_stub_constructors :
    ctx:generation_context -> entity:entity -> Buffer.t -> unit;
  generate_c_stub_methods :
    ctx:generation_context -> entity:entity -> Buffer.t -> unit;
  generate_c_stub_properties :
    ctx:generation_context -> entity:entity -> Buffer.t -> unit;
}

let entity_generator_by_entity_type =
  let open Gir_gen_lib.Generate in
  fun entity_type ->
    let generate_c_stub_headers =
     fun ~ctx ~entity buf ->
      (* Add header *)
      Buffer.add_string buf
        (C_stub_helpers.generate_c_file_header ~ctx ~class_name:entity.name ())
    in
    let generate_c_stub_constructors =
     fun ~ctx ~(entity : entity) buf ->
      List.iter
        ~f:(fun (ctor : gir_constructor) ->
          if Filtering.should_generate_constructor ~ctx ctor then
            try
              let stub =
                C_stub_constructor.generate_c_constructor ~ctx
                  ~c_type:entity.c_type ~class_name:entity.name ctor
              in
              let ml_name =
                Gir_gen_lib.Utils.ml_constructor_name ~constructor:ctor
              in
              C_stub_helpers.emit_with_member_guard ~ctx
                ~version_namespace:ctor.version_namespace
                ~class_version:entity.version ~member_version:ctor.version ~stub
                buf ~fallback:(fun v ->
                  C_stub_helpers.emit_fallback_constructor_stub ~ctx
                    ~c_type:entity.c_type ~class_name:entity.name ~ml_name
                    ~c_identifier:ctor.c_identifier ~version:v ctor)
            with Failure msg ->
              Fmt.epr "  Warning: skipping constructor %s: %s\n" ctor.ctor_name
                msg)
        entity.constructors
    in
    let generate_c_stub_methods =
     fun ~ctx ~(entity : entity) buf ->
      let entity_kind = Filtering.entity_kind_of_entity entity in
      List.iter
        ~f:(fun (meth : gir_method) ->
          if not (Filtering.should_skip_method_binding ~ctx ~entity_kind meth)
          then
            try
              let stub =
                C_stub_method.generate_c_method ~ctx ~c_type:entity.c_type meth
                  entity.name
              in
              let ml_name = Gir_gen_lib.Utils.ml_method_name meth in
              (* For method-level OS guards, use a temp buffer so we can wrap *)
              match meth.os with
              | None ->
                  C_stub_helpers.emit_with_member_guard ~ctx
                    ~version_namespace:meth.version_namespace
                    ~class_version:entity.version ~member_version:meth.version
                    ~stub buf ~fallback:(fun v ->
                      C_stub_helpers.emit_fallback_method_stub ~ctx
                        ~c_type:entity.c_type ~class_name:entity.name ~ml_name
                        ~c_identifier:meth.c_identifier ~version:v meth)
              | Some os_val ->
                  (* Generate version-guarded content into temp buffer *)
                  let method_buf = Buffer.create 256 in
                  C_stub_helpers.emit_with_member_guard ~ctx
                    ~version_namespace:meth.version_namespace
                    ~class_version:entity.version ~member_version:meth.version
                    ~stub method_buf ~fallback:(fun v ->
                      C_stub_helpers.emit_fallback_method_stub ~ctx
                        ~c_type:entity.c_type ~class_name:entity.name ~ml_name
                        ~c_identifier:meth.c_identifier ~version:v meth);
                  let method_content = Buffer.contents method_buf in
                  let os_fallback =
                    Gir_gen_lib.Generate.C_stub_helpers
                    .emit_os_fallback_method_stub ~ctx ~c_type:entity.c_type
                      ~class_name:entity.name ~ml_name
                      ~c_identifier:meth.c_identifier ~os:os_val meth
                  in
                  Gir_gen_lib.Generate.C_stub_helpers.emit_with_os_guard
                    ~os:(Some os_val) ~failwith_stub:os_fallback
                    ~stub:method_content buf
            with Failure msg ->
              Fmt.epr "  Warning: skipping method %s: %s\n" meth.method_name msg)
        (List.rev entity.methods)
    in
    let generate_c_stub_properties =
     fun ~ctx ~(entity : entity) buf ->
      let class_name = entity.name in
      let methods = entity.methods in
      let c_type = entity.c_type in
      List.iter
        ~f:(fun (prop : gir_property) ->
          if Filtering.should_generate_property ~ctx ~class_name ~methods prop
          then begin
            if prop.readable then begin
              let stub =
                C_stub_property.generate_c_property_getter ~ctx ~c_type prop
                  class_name
              in
              let ml_name =
                Gir_gen_lib.Utils.ml_property_name ~ctx ~class_name prop
              in
              C_stub_helpers.emit_with_member_guard ~ctx
                ~version_namespace:prop.version_namespace
                ~class_version:entity.version ~member_version:prop.version ~stub
                buf ~fallback:(fun v ->
                  C_stub_helpers.emit_fallback_property_getter_stub ~ctx ~c_type
                    ~class_name ~ml_name ~version:v prop)
            end;
            if prop.writable && not prop.construct_only then begin
              let stub =
                C_stub_property.generate_c_property_setter ~ctx ~c_type prop
                  class_name
              in
              let ml_name =
                Gir_gen_lib.Utils.ml_property_setter_name ~ctx ~class_name prop
              in
              C_stub_helpers.emit_with_member_guard ~ctx
                ~version_namespace:prop.version_namespace
                ~class_version:entity.version ~member_version:prop.version ~stub
                buf ~fallback:(fun v ->
                  C_stub_helpers.emit_fallback_property_setter_stub ~ctx ~c_type
                    ~class_name ~ml_name ~version:v prop)
            end
          end)
        entity.properties
    in
    let generate_c_stub_converters ~ctx ~entity buf =
      match entity.kind with
      | Class _ | Interface _ -> ()
      | Record record ->
          let namespace_prefix = ctx.namespace.namespace_name in
          C_stub_record.generate_record_converters ~namespace_prefix ~buf record
    in

    match entity_type with
    | Class _ ->
        {
          generate_c_stub_headers;
          generate_c_stub_converters;
          generate_c_stub_constructors;
          generate_c_stub_methods;
          generate_c_stub_properties;
        }
    | Interface _ ->
        {
          generate_c_stub_headers;
          generate_c_stub_converters;
          generate_c_stub_constructors;
          generate_c_stub_methods;
          generate_c_stub_properties;
        }
    | Record _ ->
        {
          generate_c_stub_headers;
          generate_c_stub_converters;
          generate_c_stub_constructors;
          generate_c_stub_methods;
          generate_c_stub_properties;
        }

(** Generate the from_gobject C function for an interface. Raises [Failure] if
    [intf.glib_type_name] is [None] — callers must guard with
    [Option.is_some intf.glib_type_name] before calling. *)
let gtype_macro_from_get_type get_type_fn =
  (* Derive the GType macro from the glib:get-type function name.
     e.g. "g_dbus_interface_get_type" -> "G_TYPE_DBUS_INTERFACE"
          "gtk_editable_get_type"      -> "GTK_TYPE_EDITABLE"
     This avoids using to_snake_case on the type name, which incorrectly
     splits names like "GDBusInterface" into "gd_bus_interface". *)
  let name =
    let suffix = "_get_type" in
    let slen = String.length suffix in
    if
      String.length get_type_fn > slen
      && String.equal
           (String.sub get_type_fn
              ~pos:(String.length get_type_fn - slen)
              ~len:slen)
           suffix
    then String.sub get_type_fn ~pos:0 ~len:(String.length get_type_fn - slen)
    else get_type_fn
  in
  let screaming = String.uppercase_ascii name in
  match String.index_opt screaming '_' with
  | None -> screaming
  | Some i ->
      let prefix = String.sub screaming ~pos:0 ~len:i in
      let rest =
        String.sub screaming ~pos:(i + 1) ~len:(String.length screaming - i - 1)
      in
      prefix ^ "_TYPE_" ^ rest

let generate_from_gobject_stub ~namespace_name (intf : gir_interface) =
  match (intf.glib_type_name, intf.glib_get_type) with
  | None, _ ->
      Fmt.failwith
        "generate_from_gobject_stub: interface %s has no glib_type_name"
        intf.interface_name
  | Some type_name, get_type_opt ->
      let fn_name =
        Fmt.str "ml_%s_%s_from_gobject"
          (String.lowercase_ascii namespace_name)
          (Gir_gen_lib.Utils.to_snake_case intf.interface_name)
      in
      (* Prefer deriving the GType macro from glib:get-type (already snake_case)
         to avoid to_snake_case mishandling acronym-heavy names like GDBusInterface *)
      let gtype_macro =
        match get_type_opt with
        | Some get_type_fn -> gtype_macro_from_get_type get_type_fn
        | None -> Gir_gen_lib.Utils.gtype_macro_of_type_name type_name
      in
      Fmt.str
        {|CAMLexport CAMLprim value %s(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), %s)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%%s' does not implement %%s",
            G_OBJECT_TYPE_NAME(gobj), "%s");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(%s((%s*)gobj));
}
|}
        fn_name gtype_macro type_name
        (Fmt.str "Val_%s" intf.c_type)
        intf.c_type

(* Generate C stub file for a single entity (class or interface or record) *)
let generate_c_stub ~ctx ~output_dir entity =
  begin
    Fmt.pr "  - %s (%d methods, %d properties)\n" entity.Gir_gen_lib.Types.name
      (List.length entity.Gir_gen_lib.Types.methods)
      (List.length entity.Gir_gen_lib.Types.properties);

    let stub_name =
      Fmt.str "ml_%s_gen"
        (Gir_gen_lib.Utils.to_snake_case entity.Gir_gen_lib.Types.name)
    in
    let c_file =
      Filename.concat (generated_output_dir output_dir) (stub_name ^ ".c")
    in
    let buf = Buffer.create 4096 in

    (* Note: Record-specific conversions are generated in generate_record_c_code, not here *)
    let {
      generate_c_stub_headers;
      generate_c_stub_converters;
      generate_c_stub_constructors;
      generate_c_stub_methods;
      generate_c_stub_properties;
      _;
    } =
      entity_generator_by_entity_type entity.kind
    in
    generate_c_stub_headers ~ctx ~entity buf;

    (* Converters must NOT be wrapped with version guard because they are used by other stubs *)
    generate_c_stub_converters ~ctx ~entity buf;

    (* Check if the entity has a version and wrap body with class-level guard *)
    let body_buf = Buffer.create 4096 in
    generate_c_stub_constructors ~ctx ~entity body_buf;
    generate_c_stub_methods ~ctx ~entity body_buf;
    generate_c_stub_properties ~ctx ~entity body_buf;

    (* Append from_gobject stub for interfaces that have a glib_type_name *)
    (match entity.kind with
    | Gir_gen_lib.Types.Interface intf when Option.is_some intf.glib_type_name
      ->
        let stub =
          generate_from_gobject_stub
            ~namespace_name:ctx.namespace.namespace_name intf
        in
        Buffer.add_string body_buf stub
    | _ -> ());

    (* Append get_type stub for records registered with the GType system *)
    (match entity.kind with
    | Gir_gen_lib.Types.Record record -> (
        match record.glib_get_type with
        | Some get_type_func ->
            let ns_snake =
              Gir_gen_lib.Utils.to_snake_case ctx.namespace.namespace_name
            in
            let class_snake =
              Gir_gen_lib.Utils.to_snake_case record.record_name
            in
            let ml_name = Fmt.str "ml_%s_%s_get_type" ns_snake class_snake in
            Buffer.add_string body_buf
              (Fmt.str
                 "\n\
                  CAMLprim value %s(value unit)\n\
                  {\n\
                 \  CAMLparam1(unit);\n\
                 \  CAMLreturn(Val_long(%s()));\n\
                  }\n"
                 ml_name get_type_func)
        | None -> ())
    | _ -> ());

    let body_content = Buffer.contents body_buf in

    (* Apply version guard (inner) to produce version_guarded_content *)
    let version_buf = Buffer.create 4096 in
    (match entity.version with
    | None ->
        (* No version, emit body as-is *)
        Buffer.add_string version_buf body_content
    | Some version_str -> (
        (* Entity has version, wrap body with class-level guard *)
        match
          Gir_gen_lib.Version_guard.resolve_guard
            ~class_version:(Some version_str) ~member_version:None
        with
        | Error _ ->
            (* If parsing fails, emit without guard *)
            Buffer.add_string version_buf body_content
        | Ok Gir_gen_lib.Version_guard.No_guard ->
            (* No guard needed *)
            Buffer.add_string version_buf body_content
        | Ok (Gir_gen_lib.Version_guard.Class_guard version) -> (
            (* Emit class-level guard *)
            match
              Gir_gen_lib.Version_guard.emit_c_guard
                ctx.namespace.namespace_name version ~is_opening:true
            with
            | Error _ -> Buffer.add_string version_buf body_content
            | Ok guard_if -> (
                Buffer.add_string version_buf guard_if;
                Buffer.add_string version_buf "\n\n";
                Buffer.add_string version_buf body_content;
                Buffer.add_string version_buf "\n";
                Buffer.add_string version_buf
                  Gir_gen_lib.Version_guard.c_guard_else;
                Buffer.add_string version_buf "\n\n";

                (* Generate fallback stubs for all members *)
                List.iter
                  ~f:(fun (ctor : gir_constructor) ->
                    if
                      Gir_gen_lib.Generate.Filtering.should_generate_constructor
                        ~ctx ctor
                    then (
                      let ml_name =
                        Gir_gen_lib.Utils.ml_constructor_name ~constructor:ctor
                      in
                      Buffer.add_string version_buf
                        (Gir_gen_lib.Generate.C_stub_helpers
                         .emit_fallback_constructor_stub ~ctx
                           ~c_type:entity.c_type ~class_name:entity.name
                           ~ml_name ~c_identifier:ctor.c_identifier ~version
                           ctor);
                      Buffer.add_string version_buf "\n"))
                  entity.constructors;

                let entity_kind =
                  Gir_gen_lib.Generate.Filtering.entity_kind_of_entity entity
                in
                List.iter
                  ~f:(fun (meth : gir_method) ->
                    if
                      not
                        (Gir_gen_lib.Generate.Filtering
                         .should_skip_method_binding ~ctx ~entity_kind meth)
                    then (
                      let ml_name = Gir_gen_lib.Utils.ml_method_name meth in
                      Buffer.add_string version_buf
                        (Gir_gen_lib.Generate.C_stub_helpers
                         .emit_fallback_method_stub ~ctx ~c_type:entity.c_type
                           ~class_name:entity.name ~ml_name
                           ~c_identifier:meth.c_identifier ~version meth);
                      Buffer.add_string version_buf "\n"))
                  entity.methods;

                List.iter
                  ~f:(fun (prop : gir_property) ->
                    if
                      Gir_gen_lib.Generate.Filtering.should_generate_property
                        ~ctx ~class_name:entity.name ~methods:entity.methods
                        prop
                    then
                      begin if prop.readable then (
                        let ml_name =
                          Gir_gen_lib.Utils.ml_property_name ~ctx
                            ~class_name:entity.name prop
                        in
                        Buffer.add_string version_buf
                          (Gir_gen_lib.Generate.C_stub_helpers
                           .emit_fallback_property_getter_stub ~ctx
                             ~c_type:entity.c_type ~class_name:entity.name
                             ~ml_name ~version prop);
                        Buffer.add_string version_buf "\n";
                        if prop.writable && not prop.construct_only then (
                          let ml_name =
                            Gir_gen_lib.Utils.ml_property_setter_name ~ctx
                              ~class_name:entity.name prop
                          in
                          Buffer.add_string version_buf
                            (Gir_gen_lib.Generate.C_stub_helpers
                             .emit_fallback_property_setter_stub ~ctx
                               ~c_type:entity.c_type ~class_name:entity.name
                               ~ml_name ~version prop);
                          Buffer.add_string version_buf "\n"))
                      end)
                  entity.properties;

                (* Generate fallback from_gobject stub for versioned interfaces *)
                (match entity.kind with
                | Gir_gen_lib.Types.Interface intf
                  when Option.is_some intf.glib_type_name ->
                    let fn_name =
                      Fmt.str "ml_%s_%s_from_gobject"
                        (String.lowercase_ascii ctx.namespace.namespace_name)
                        (Gir_gen_lib.Utils.to_snake_case entity.name)
                    in
                    Buffer.add_string version_buf
                      (Fmt.str
                         {|CAMLexport CAMLprim value %s(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("%s requires GTK >= %s");
    return Val_unit;
}
|}
                         fn_name entity.name version_str);
                    Buffer.add_string version_buf "\n"
                | _ -> ());

                Buffer.add_string version_buf "\n";
                match
                  Gir_gen_lib.Version_guard.emit_c_guard
                    ctx.namespace.namespace_name version ~is_opening:false
                with
                | Error _ -> Buffer.add_string version_buf "#endif\n"
                | Ok guard_endif ->
                    Buffer.add_string version_buf (guard_endif ^ "\n")))
        | Ok (Gir_gen_lib.Version_guard.Member_guard _) ->
            (* Member guard at class level doesn't make sense, emit without guard *)
            Buffer.add_string version_buf body_content));

    (* Apply OS guard (outer) wrapping the version-guarded content *)
    let version_guarded = Buffer.contents version_buf in
    (match entity.os with
    | None -> Buffer.add_string buf version_guarded
    | Some os_val ->
        (* Generate OS-fallback stubs for the #else branch *)
        let os_fallback_buf = Buffer.create 2048 in
        List.iter
          ~f:(fun (ctor : gir_constructor) ->
            if
              Gir_gen_lib.Generate.Filtering.should_generate_constructor ~ctx
                ctor
            then (
              let ml_name =
                Gir_gen_lib.Utils.ml_constructor_name ~constructor:ctor
              in
              Buffer.add_string os_fallback_buf
                (Gir_gen_lib.Generate.C_stub_helpers
                 .emit_os_fallback_constructor_stub ~ctx ~c_type:entity.c_type
                   ~class_name:entity.name ~ml_name
                   ~c_identifier:ctor.c_identifier ~os:os_val ctor);
              Buffer.add_string os_fallback_buf "\n"))
          entity.constructors;
        let entity_kind =
          Gir_gen_lib.Generate.Filtering.entity_kind_of_entity entity
        in
        List.iter
          ~f:(fun (meth : gir_method) ->
            if
              not
                (Gir_gen_lib.Generate.Filtering.should_skip_method_binding ~ctx
                   ~entity_kind meth)
            then (
              let ml_name = Gir_gen_lib.Utils.ml_method_name meth in
              Buffer.add_string os_fallback_buf
                (Gir_gen_lib.Generate.C_stub_helpers
                 .emit_os_fallback_method_stub ~ctx ~c_type:entity.c_type
                   ~class_name:entity.name ~ml_name
                   ~c_identifier:meth.c_identifier ~os:os_val meth);
              Buffer.add_string os_fallback_buf "\n"))
          entity.methods;
        List.iter
          ~f:(fun (prop : gir_property) ->
            if
              Gir_gen_lib.Generate.Filtering.should_generate_property ~ctx
                ~class_name:entity.name ~methods:entity.methods prop
            then
              begin if prop.readable then (
                let ml_name =
                  Gir_gen_lib.Utils.ml_property_name ~ctx
                    ~class_name:entity.name prop
                in
                Buffer.add_string os_fallback_buf
                  (Gir_gen_lib.Generate.C_stub_helpers
                   .emit_os_fallback_property_getter_stub ~ctx
                     ~c_type:entity.c_type ~class_name:entity.name ~ml_name
                     ~os:os_val prop);
                Buffer.add_string os_fallback_buf "\n";
                if prop.writable && not prop.construct_only then (
                  let ml_name =
                    Gir_gen_lib.Utils.ml_property_setter_name ~ctx
                      ~class_name:entity.name prop
                  in
                  Buffer.add_string os_fallback_buf
                    (Gir_gen_lib.Generate.C_stub_helpers
                     .emit_os_fallback_property_setter_stub ~ctx
                       ~c_type:entity.c_type ~class_name:entity.name ~ml_name
                       ~os:os_val prop);
                  Buffer.add_string os_fallback_buf "\n"))
              end)
          entity.properties;
        let os_fallback = Buffer.contents os_fallback_buf in
        Buffer.add_char buf '\n';
        Buffer.add_string buf
          (Gir_gen_lib.Generate.C_stub_helpers.os_to_c_guard_open os_val);
        Buffer.add_char buf '\n';
        Buffer.add_string buf version_guarded;
        Buffer.add_char buf '\n';
        Buffer.add_string buf "#else\n\n";
        Buffer.add_string buf os_fallback;
        Buffer.add_char buf '\n';
        Buffer.add_string buf
          (Gir_gen_lib.Generate.C_stub_helpers.os_to_c_guard_close os_val);
        Buffer.add_char buf '\n');

    write_file ~path:c_file ~content:(Buffer.contents buf);
    Some stub_name
  end

(* Generate C stub files for all entities *)
let generate_all_c_stubs ~ctx ~output_dir ~generated_stubs entities =
  List.iter
    ~f:(fun entity ->
      generate_c_stub ~ctx ~output_dir entity
      |> Option.iter (fun c_file ->
          generated_stubs := c_file :: !generated_stubs))
    entities

(* Output file kind for ML generation *)
type output_file_kind = Interface | Implementation

(* Namespace information for enum/bitfield generation *)
type namespace_info = {
  name : string; (* Display name, e.g., "Gtk" *)
  prefix : string; (* Lowercase prefix for files, e.g., "gtk" *)
  include_header : string;
      (* C include directive, e.g., "#include <gtk/gtk.h>" *)
}

(* Generate a single ML file (interface or implementation) for an entity *)
let generate_ml_file ~ctx ~output_dir ~kind ~parent_chain ?from_gobject_c_name
    entity =
  let ext = match kind with Interface -> ".mli" | Implementation -> ".ml" in
  let ml_file =
    Filename.concat
      (generated_output_dir output_dir)
      (Fmt.str "%s%s"
         (Gir_gen_lib.Utils.to_snake_case entity.Gir_gen_lib.Types.name)
         ext)
  in

  let output_mode =
    match kind with
    | Interface -> Gir_gen_lib.Generate.Ml_interface.Interface
    | Implementation -> Gir_gen_lib.Generate.Ml_interface.Implementation
  in

  let entity_kind =
    Gir_gen_lib.Generate.Filtering.entity_kind_of_entity entity
  in
  let glib_get_type =
    match entity.Gir_gen_lib.Types.kind with
    | Gir_gen_lib.Types.Record record -> record.glib_get_type
    | _ -> None
  in
  let content =
    Gir_gen_lib.Generate.Ml_interface.generate_ml_interface ~ctx ~output_mode
      ~class_name:entity.Gir_gen_lib.Types.name
      ~class_doc:entity.Gir_gen_lib.Types.doc
      ~c_type:entity.Gir_gen_lib.Types.c_type ~parent_chain
      ~constructors:
        (if List.length entity.Gir_gen_lib.Types.constructors > 0 then
           Some entity.Gir_gen_lib.Types.constructors
         else None)
      ~methods:entity.Gir_gen_lib.Types.methods ~entity_kind
      ~properties:entity.Gir_gen_lib.Types.properties
      ~signals:entity.Gir_gen_lib.Types.signals ?from_gobject_c_name
      ?glib_get_type ()
  in

  write_file ~path:ml_file ~content

(* Generate both .mli and .ml files for an entity *)
let generate_ml_interfaces ~ctx ~output_dir ~parent_chain entity =
  match entity.kind with
  | Gir_gen_lib.Types.Class clazz ->
      if Gir_gen_lib.Generate.Filtering.should_generate_class clazz then begin
        generate_ml_file ~ctx ~output_dir ~kind:Interface ~parent_chain entity;
        generate_ml_file ~ctx ~output_dir ~kind:Implementation ~parent_chain
          entity
      end
  | Gir_gen_lib.Types.Interface intf ->
      if Gir_gen_lib.Generate.Filtering.should_generate_interface intf then begin
        let from_gobject_c_name =
          Option.map
            (fun _ ->
              Fmt.str "ml_%s_%s_from_gobject"
                (String.lowercase_ascii
                   ctx.Gir_gen_lib.Types.namespace.namespace_name)
                (Gir_gen_lib.Utils.to_snake_case intf.interface_name))
            intf.glib_type_name
        in
        generate_ml_file ~ctx ~output_dir ~kind:Interface ~parent_chain
          ?from_gobject_c_name entity;
        generate_ml_file ~ctx ~output_dir ~kind:Implementation ~parent_chain
          ?from_gobject_c_name entity
      end
  | Gir_gen_lib.Types.Record record ->
      if Gir_gen_lib.Generate.Filtering.should_generate_record record then begin
        generate_ml_file ~ctx ~output_dir ~kind:Interface ~parent_chain entity;
        generate_ml_file ~ctx ~output_dir ~kind:Implementation ~parent_chain
          entity
      end

(* Generate high-level wrapper class (g<Widget>.ml) for a class entity *)
let generate_high_level_class ~ctx ~output_dir entity parent_chain =
  let generate_ () =
    let g_file =
      Filename.concat
        (generated_output_dir output_dir)
        (Gir_gen_lib.Utils.layer2_module_filename entity.Gir_gen_lib.Types.name
        ^ ".ml")
    in
    let g_sig_file =
      Filename.concat
        (generated_output_dir output_dir)
        (Gir_gen_lib.Utils.layer2_module_filename entity.Gir_gen_lib.Types.name
        ^ ".mli")
    in

    (* Check if we're generating to src directory *)
    let output_under_src =
      let norm p = Filename.concat (Filename.dirname p) (Filename.basename p) in
      String.equal (Filename.basename output_dir) "src"
      || String.equal (norm output_dir) (norm "src")
    in

    let g_file_exists = output_under_src && Sys.file_exists g_file in

    (* Always overwrite to enable wholesale regeneration *)
    if g_file_exists then
      Fmt.pr "Overwriting %s (wholesale regeneration enabled)\n" g_file
    else Fmt.pr "Creating %s\n" g_file;

    let entity_kind =
      Gir_gen_lib.Generate.Filtering.entity_kind_of_entity entity
    in
    write_file ~path:g_file
      ~content:
        (Gir_gen_lib.Generate.Class_gen.generate_class_module ~ctx
           ~c_type:entity.Gir_gen_lib.Types.c_type
           ~class_name:entity.Gir_gen_lib.Types.name ~parent_chain
           ~methods:entity.Gir_gen_lib.Types.methods ~entity_kind
           ~properties:entity.Gir_gen_lib.Types.properties
           ~signals:entity.Gir_gen_lib.Types.signals
           ~constructors:entity.Gir_gen_lib.Types.constructors);

    (* Always overwrite signature files too *)
    let g_sig_exists = output_under_src && Sys.file_exists g_sig_file in
    if g_sig_exists then
      Fmt.pr "Overwriting %s (wholesale regeneration enabled)\n" g_sig_file
    else Fmt.pr "Creating %s\n" g_sig_file;
    write_file ~path:g_sig_file
      ~content:
        (Gir_gen_lib.Generate.Class_gen.generate_class_signature ~ctx
           ~c_type:entity.Gir_gen_lib.Types.c_type
           ~class_name:entity.Gir_gen_lib.Types.name ~parent_chain
           ~methods:entity.Gir_gen_lib.Types.methods ~entity_kind
           ~properties:entity.Gir_gen_lib.Types.properties
           ~signals:entity.Gir_gen_lib.Types.signals
           ~constructors:entity.Gir_gen_lib.Types.constructors)
  in
  match entity.kind with
  | Gir_gen_lib.Types.Class clazz ->
      if Gir_gen_lib.Generate.Filtering.should_generate_class clazz then
        generate_ ()
  | Gir_gen_lib.Types.Interface intf ->
      if Gir_gen_lib.Generate.Filtering.should_generate_interface intf then
        generate_ ()
  | Gir_gen_lib.Types.Record record ->
      if Gir_gen_lib.Generate.Filtering.should_generate_record record then
        generate_ ()

(* Generate combined .ml + .mli for cyclic Layer 1 modules *)
let generate_combined_ml_files ~ctx ~output_dir ~module_group
    ~parent_chain_for_class =
  let entities =
    Gir_gen_lib.Dependency_analysis.entities_of_group module_group
  in
  let combined_name =
    Gir_gen_lib.Dependency_analysis.module_name_of_group module_group
  in
  let combined_snake = Gir_gen_lib.Utils.to_snake_case combined_name in

  let mli_path =
    Filename.concat (generated_output_dir output_dir) (combined_snake ^ ".mli")
  in
  let ml_path =
    Filename.concat (generated_output_dir output_dir) (combined_snake ^ ".ml")
  in

  let parent_chain_for_entity name = parent_chain_for_class name in

  (* Create a context with current_cycle_classes set *)
  let cycle_class_names =
    List.map ~f:(fun e -> e.Gir_gen_lib.Types.name) entities
  in
  let ctx_with_cycle =
    { ctx with Gir_gen_lib.Types.current_cycle_classes = cycle_class_names }
  in

  let from_gobject_c_name_for_entity (entity : Gir_gen_lib.Types.entity) =
    match entity.kind with
    | Gir_gen_lib.Types.Interface intf ->
        Option.map
          (fun _ ->
            Fmt.str "ml_%s_%s_from_gobject"
              (String.lowercase_ascii
                 ctx.Gir_gen_lib.Types.namespace.namespace_name)
              (Gir_gen_lib.Utils.to_snake_case intf.interface_name))
          intf.glib_type_name
    | Gir_gen_lib.Types.Class _ | Gir_gen_lib.Types.Record _ -> None
  in
  let mli_content =
    Gir_gen_lib.Generate.Ml_interface.generate_combined_ml_modules
      ~ctx:ctx_with_cycle
      ~output_mode:Gir_gen_lib.Generate.Ml_interface.Interface ~entities
      ~parent_chain_for_entity ~from_gobject_c_name_for_entity ()
  in
  let ml_content =
    Gir_gen_lib.Generate.Ml_interface.generate_combined_ml_modules
      ~ctx:ctx_with_cycle
      ~output_mode:Gir_gen_lib.Generate.Ml_interface.Implementation ~entities
      ~parent_chain_for_entity ~from_gobject_c_name_for_entity ()
  in

  write_file ~path:mli_path ~content:mli_content;
  write_file ~path:ml_path ~content:ml_content

(* Generate combined g*.ml + g*.mli for cyclic Layer 2 classes *)
let generate_combined_class_files ~ctx ~output_dir ~module_group
    ~parent_chain_for_class =
  let entities =
    Gir_gen_lib.Dependency_analysis.entities_of_group module_group
  in
  let combined_name =
    Gir_gen_lib.Dependency_analysis.module_name_of_group module_group
  in
  let g_file =
    Filename.concat
      (generated_output_dir output_dir)
      (Gir_gen_lib.Utils.layer2_module_filename combined_name ^ ".ml")
  in
  let g_sig_file =
    Filename.concat
      (generated_output_dir output_dir)
      (Gir_gen_lib.Utils.layer2_module_filename combined_name ^ ".mli")
  in

  let parent_chain_for_entity name = parent_chain_for_class name in

  (* For class layer (g*.ml files), do NOT set current_cycle_classes *)
  (* Class files are not mutually recursive - they reference the combined C binding module *)
  (* So all references must be fully qualified *)
  let g_content =
    Gir_gen_lib.Generate.Class_gen.generate_combined_class_module ~ctx
      ~combined_module_name:combined_name ~entities ~parent_chain_for_entity
  in
  let g_sig =
    Gir_gen_lib.Generate.Class_gen.generate_combined_class_signature ~ctx
      ~combined_module_name:combined_name ~entities ~parent_chain_for_entity
  in

  write_file ~path:g_file ~content:g_content;
  write_file ~path:g_sig_file ~content:g_sig

(* Generate shim modules for entities in cyclic groups *)
let generate_cyclic_shim_files ~ctx ~output_dir ~combined_module_name ~entity =
  let open Gir_gen_lib in
  let open Gir_gen_lib.Generate in
  (* Get the shim module names (gWindow, gApplication, etc.) *)
  let shim_module_name =
    Gir_gen_lib.Utils.layer2_module_filename entity.Types.name
  in
  let shim_file =
    Filename.concat (generated_output_dir output_dir) (shim_module_name ^ ".ml")
  in
  let shim_sig_file =
    Filename.concat (generated_output_dir output_dir) (shim_module_name ^ ".mli")
  in

  (* Get the combined G module name *)
  let combined_g_module_name = Utils.layer2_module_name combined_module_name in

  (* Generate content using class_gen functions *)
  let ml_content =
    Class_gen.generate_cyclic_shim_module ~ctx ~entity ~combined_module_name
      ~g_combined_module_name:combined_g_module_name
  in
  let mli_content =
    Class_gen.generate_cyclic_shim_signature ~ctx ~entity ~combined_module_name
      ~g_combined_module_name:combined_g_module_name
  in

  (* Write files *)
  write_file ~path:shim_file ~content:ml_content;
  write_file ~path:shim_sig_file ~content:mli_content

(* Generate enum and bitfield files for a namespace *)
let generate_enum_files ~output_dir ~generated_stubs namespace enums bitfields =
  if List.length enums = 0 && List.length bitfields = 0 then ()
  else begin
    (* Generate OCaml .mli file with type definitions *)
    let enum_file =
      Filename.concat
        (generated_output_dir output_dir)
        (Fmt.str "%s_enums.mli" namespace.prefix)
    in
    let ocaml_content_parts =
      [
        "(* GENERATED CODE - DO NOT EDIT *)\n";
        Fmt.str "(* %s Enumeration and Bitfield Types *)\n\n" namespace.name;
      ]
      @ List.map ~f:Gir_gen_lib.Generate.Enum_code.generate_ocaml_enum enums
      @ List.map ~f:Gir_gen_lib.Generate.Enum_code.generate_ocaml_bitfield
          bitfields
    in
    write_file ~path:enum_file
      ~content:(String.concat ~sep:"" ocaml_content_parts);

    (* Generate OCaml .ml file with pure-OCaml _of_int/_to_int implementations *)
    let enum_ml_file =
      Filename.concat
        (generated_output_dir output_dir)
        (Fmt.str "%s_enums.ml" namespace.prefix)
    in
    let ocaml_ml_content_parts =
      [
        "(* GENERATED CODE - DO NOT EDIT *)\n";
        Fmt.str "(* %s Enumeration and Bitfield Converters *)\n\n"
          namespace.name;
      ]
      @ List.map ~f:Gir_gen_lib.Generate.Enum_code.generate_ocaml_enum_impl
          enums
      @ List.map ~f:Gir_gen_lib.Generate.Enum_code.generate_ocaml_bitfield_impl
          bitfields
    in
    write_file ~path:enum_ml_file
      ~content:(String.concat ~sep:"" ocaml_ml_content_parts);

    (* Generate C converter file *)
    let stub_name = Fmt.str "ml_%s_enums_gen" namespace.prefix in
    let c_file =
      Filename.concat (generated_output_dir output_dir) (stub_name ^ ".c")
    in
    let c_content_parts =
      [
        "/* GENERATED CODE - DO NOT EDIT */\n";
        Fmt.str "/* %s enum/bitfield converters */\n\n" namespace.name;
        "#include <caml/mlvalues.h>\n";
        "#include <caml/memory.h>\n";
        "#include <caml/alloc.h>\n";
        "#include <caml/fail.h>\n";
        "#include <caml/hash.h>\n";
        "#include <glib.h>\n";
        namespace.include_header ^ "\n";
      ]
      @ List.map
          ~f:(fun (enum : gir_enum) ->
            let converters =
              Gir_gen_lib.Generate.Enum_code.generate_c_enum_converters
                ~namespace:namespace.name ~class_version:enum.enum_version enum
            in
            match enum.enum_version with
            | None -> converters
            | Some version_str -> (
                match Gir_gen_lib.Version_guard.parse_version version_str with
                | Error _ -> converters
                | Ok version -> (
                    match
                      Gir_gen_lib.Version_guard.emit_c_guard namespace.name
                        version ~is_opening:true
                    with
                    | Error _ -> converters
                    | Ok guard_if -> guard_if ^ "\n" ^ converters ^ "#endif\n\n"
                    )))
          enums
      @ List.map
          ~f:(fun (bitfield : gir_bitfield) ->
            let converters =
              Gir_gen_lib.Generate.Enum_code.generate_c_bitfield_converters
                ~namespace:namespace.name
                ~class_version:bitfield.bitfield_version bitfield
            in
            match bitfield.bitfield_version with
            | None -> converters
            | Some version_str -> (
                match Gir_gen_lib.Version_guard.parse_version version_str with
                | Error _ -> converters
                | Ok version -> (
                    match
                      Gir_gen_lib.Version_guard.emit_c_guard namespace.name
                        version ~is_opening:true
                    with
                    | Error _ -> converters
                    | Ok guard_if -> guard_if ^ "\n" ^ converters ^ "#endif\n\n"
                    )))
          bitfields
    in
    write_file ~path:c_file ~content:(String.concat ~sep:"" c_content_parts);

    generated_stubs := stub_name :: !generated_stubs
  end

let load_reference_files reference_files =
  let open Gir_gen_lib.Types in
  let converter = cross_reference_namespace_of_sexp in
  List.fold_left reference_files ~init:StringMap.empty ~f:(fun acc file ->
      (* NOTE: this loads everything at once into memory so it is slower than a progressive load, but we're embedding something valuable at the start so we don't have a homogenous list to play with *)
      let cr_namespace = Sexplib.Sexp.load_sexp_conv_exn file converter in
      let ncr_namespace =
        {
          ncr_namespace_name = cr_namespace.cr_namespace_name;
          ncr_namespace_packages = cr_namespace.cr_namespace_packages;
          ncr_namespace_c_includes = cr_namespace.cr_namespace_c_includes;
          ncr_namespace_includes = cr_namespace.cr_namespace_includes;
          ncr_entities =
            List.fold_left cr_namespace.cr_entities ~init:StringMap.empty
              ~f:(fun sm cr -> StringMap.add cr.cr_name cr sm);
        }
      in
      StringMap.add cr_namespace.cr_namespace_name ncr_namespace acc)

(* Main generation function *)
let generate_bindings filter_file gir_file output_dir reference_files
    overrides_file =
  Fmt.pr "Current directory: %s\n" (Sys.getcwd ());
  Fmt.pr "Parsing %s ...\n" gir_file;

  (* Log reference files if provided *)
  if List.length reference_files > 0 then begin
    Fmt.pr "Using %d reference file(s) for cross-namespace validation:\n"
      (List.length reference_files);
    List.iter ~f:(fun path -> Fmt.pr "  - %s\n" path) reference_files
  end;

  (* ==== INITIALIZATION ==== *)

  (* Ensure generated/ directory exists *)
  ensure_generated_dir output_dir;

  (* Track generated C stub files *)
  let generated_stubs = ref [] in

  (* Read filter file if specified *)
  let filter_classes =
    match filter_file with
    | Some f ->
        Fmt.pr "Reading filter file: %s\n" f;
        let classes = Gir_gen_lib.Utils.read_filter_file f in
        Fmt.pr "Filter includes %d classes\n" (List.length classes);
        classes
    | None -> []
  in

  (* ==== PARSING STAGE ==== *)

  (* Parse GTK GIR file *)
  let ( repository,
        namespace,
        classes,
        interfaces,
        gtk_enums,
        gtk_bitfields,
        gtk_records,
        gtk_constants ) =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file gir_file filter_classes
  in

  Fmt.pr "Found %d classes\n" (List.length classes);
  Fmt.pr "Found %d interfaces\n" (List.length interfaces);
  Fmt.pr "Found %d Gtk enumerations\n" (List.length gtk_enums);
  Fmt.pr "Found %d Gtk bitfields\n" (List.length gtk_bitfields);
  Fmt.pr "Found %d records\n" (List.length gtk_records);
  Fmt.pr "Found %d constants\n" (List.length gtk_constants);

  (* ==== OVERRIDE APPLICATION STAGE ==== *)

  (* Apply overrides before building type-mapping context. Ignored entities
     must be absent from ctx so that find_type_mapping_for_gir_type returns
     None for their types. *)
  let ( classes,
        interfaces,
        gtk_enums,
        gtk_bitfields,
        gtk_records,
        header_overrides ) =
    match overrides_file with
    | None -> (classes, interfaces, gtk_enums, gtk_bitfields, gtk_records, [])
    | Some file -> (
        Fmt.pr "Loading overrides from %s\n" file;
        match Gir_gen_lib.Override_parser.parse_overrides file with
        | Error e ->
            Fmt.epr "Error: override parse failed: %s\n"
              (Gir_gen_lib.Override_parser.format_error e);
            exit 1
        | Ok ov ->
            let result =
              (* parse_gir_file does not extract top-level namespace functions,
             so ~functions:[] is correct — there is nothing to filter. *)
              Gir_gen_lib.Override_apply.apply_overrides ~overrides:ov ~classes
                ~interfaces ~enums:gtk_enums ~bitfields:gtk_bitfields
                ~records:gtk_records ~functions:[]
            in
            List.iter result.warnings ~f:(fun w -> Fmt.epr "Warning: %s\n" w);
            if result.ignored_entities <> [] then
              Fmt.pr "Ignored %d entity(ies): %s\n"
                (List.length result.ignored_entities)
                (String.concat ~sep:", " result.ignored_entities);
            ( result.classes,
              result.interfaces,
              result.enums,
              result.bitfields,
              result.records,
              ov.headers ))
  in

  (* ==== PREPROCESSING STAGE ==== *)

  (* Load cross-references early so parent chain can use them *)
  let cross_references = load_reference_files reference_files in

  (* Build parent lookup table for inheritance chains *)
  let parent_table = Hashtbl.create (List.length classes + 10) in
  List.iter
    ~f:(fun (cls : Gir_gen_lib.Types.gir_class) ->
      Hashtbl.replace parent_table
        (Gir_gen_lib.Utils.normalize_class_name cls.class_name)
        (Option.map
           (fun p ->
             if String.contains p '.' then
               (* Cross-namespace parent: preserve qualified name (e.g. "Gio.Application") *)
               p
             else Gir_gen_lib.Utils.normalize_class_name p)
           cls.parent))
    classes;

  (* Resolve parent chain through cross-namespace references.
     Note: GObject namespace is not in cross-references, so GObject.Object
     is handled as a known terminal producing the `object_` tag.
     WARNING: without namespace-prefixed tags, a type from one namespace could
     be coerced to a same-named type in another namespace even if there is no
     actual GObject inheritance relationship. Namespace-prefixed tags would fix
     this but require a larger L1 type system change. *)
  (* Known classes in the GObject namespace with their parents.
     GObject/GLib aren't generated from GIR, so we hardcode the hierarchy
     here so that parent chain resolution can continue through them. *)
  let gobject_known_classes =
    [ ("Object", None); ("InitiallyUnowned", Some "Object") ]
  in

  let cross_ns_parent_chain ns name =
    let open Gir_gen_lib.Types in
    let rec aux ns name depth =
      if depth > 100 then []
      else if String.equal ns "GObject" then
        let qualified = ns ^ "." ^ name in
        match List.assoc_opt name gobject_known_classes with
        | Some (Some parent) -> qualified :: aux ns parent (depth + 1)
        | Some None -> [ qualified ] (* root class *)
        | None -> [ qualified ] (* unknown GObject class, treat as terminal *)
      else
        match StringMap.find_opt ns cross_references with
        | None -> [ ns ^ "." ^ name ]
        | Some ncr -> (
            match StringMap.find_opt name ncr.ncr_entities with
            | None -> [ ns ^ "." ^ name ]
            | Some cr -> (
                let qualified = ns ^ "." ^ name in
                match cr.cr_type with
                | Crt_Class { parent = Some p; _ } ->
                    if String.contains p '.' then
                      let dot = String.rindex p '.' in
                      let p_ns = String.sub p ~pos:0 ~len:dot in
                      let p_name =
                        String.sub p ~pos:(dot + 1)
                          ~len:(String.length p - dot - 1)
                      in
                      qualified :: aux p_ns p_name (depth + 1)
                    else qualified :: aux ns p (depth + 1)
                | Crt_Class { parent = None; _ } -> [ qualified ]
                | _ -> [ qualified ]))
    in
    aux ns name 0
  in

  let parent_chain_for_class name =
    let rec aux current depth =
      if depth > 100 then []
      else
        match Hashtbl.find_opt parent_table current with
        | Some (Some parent) ->
            if String.contains parent '.' then
              (* Cross-namespace parent: resolve full chain via cross-references *)
              let dot = String.rindex parent '.' in
              let ns = String.sub parent ~pos:0 ~len:dot in
              let pname =
                String.sub parent ~pos:(dot + 1)
                  ~len:(String.length parent - dot - 1)
              in
              cross_ns_parent_chain ns pname
            else parent :: aux parent (depth + 1)
        | _ -> []
    in
    aux (Gir_gen_lib.Utils.normalize_class_name name) 0
  in

  (* Combine all enums and bitfields for type mapping lookups *)
  let all_classes =
    classes
    |> List.filter ~f:(fun (cls : Gir_gen_lib.Types.gir_class) ->
        Gir_gen_lib.Generate.Filtering.should_generate_class cls)
  in
  let all_interfaces =
    interfaces
    |> List.filter ~f:(fun (intf : Gir_gen_lib.Types.gir_interface) ->
        Gir_gen_lib.Generate.Filtering.should_generate_interface intf)
  in
  let all_enums = gtk_enums in
  let all_bitfields = gtk_bitfields in

  let all_records =
    let open Gir_gen_lib.Generate in
    List.filter
      ~f:(fun record -> Filtering.should_generate_record record)
      gtk_records
  in

  (* Create generation context with all type information *)
  let ctx_initial : Gir_gen_lib.Types.generation_context =
    {
      namespace;
      repository;
      classes;
      interfaces;
      enums = all_enums;
      bitfields = all_bitfields;
      records = all_records;
      constants = gtk_constants;
      module_groups = Hashtbl.create 0;
      (* Temporary empty map *)
      current_cycle_classes = [];
      (* No cycle context initially *)
      cross_references;
      (* cross references initialised to empty *)
    }
  in

  (* Create unified entity list combining classes, interfaces, and records *)
  let entities : Gir_gen_lib.Types.entity list =
    List.map ~f:Gir_gen_lib.Types.entity_of_class all_classes
    @ List.map ~f:Gir_gen_lib.Types.entity_of_interface all_interfaces
    @ List.map ~f:Gir_gen_lib.Types.entity_of_record all_records
  in

  (* Compute module groups using SCC algorithm to populate module_groups *)
  let module_groups_list =
    Gir_gen_lib.Dependency_analysis.compute_module_groups ctx_initial entities
  in
  let module_groups =
    Gir_gen_lib.Dependency_analysis.create_module_groups_table
      module_groups_list
  in

  (* Create context with module_groups populated *)
  let ctx_with_modules =
    { ctx_initial with module_groups; current_cycle_classes = [] }
  in

  let ctx = ctx_with_modules in

  (* ==== GENERATION STAGE ==== *)

  (* Generate enum and bitfield files for current namespace *)
  let ns_name = ctx.namespace.namespace_name in
  let ns_lower = String.lowercase_ascii ns_name in

  (* Generate common header file *)
  let header_file =
    Filename.concat
      (generated_output_dir output_dir)
      (Fmt.str "%s_decls.h" ns_lower)
  in
  Fmt.pr "\n";
  let header_content =
    Gir_gen_lib.Generate.C_stubs.generate_decls_header ~ctx ~header_overrides
      ~classes:ctx.classes ~gtk_enums ~gtk_bitfields ~records:ctx.records
      ~interfaces:ctx.interfaces ()
  in
  write_file ~path:header_file ~content:header_content;

  let current_namespace =
    {
      name = ns_name;
      prefix = ns_lower;
      include_header =
        Gir_gen_lib.Generate.C_stubs.include_header_for_namespace ns_name;
    }
  in
  generate_enum_files ~output_dir ~generated_stubs current_namespace gtk_enums
    gtk_bitfields;

  (* Generate constant files for current namespace *)
  Gir_gen_lib.Generate.Constant_code.generate_constants_files ~ctx
    ~namespace:ns_name
    ~output_dir:(generated_output_dir output_dir);

  (* Generate C files for all entities (classes and interfaces and records only) *)
  generate_all_c_stubs ~ctx ~output_dir ~generated_stubs entities;

  (* ==== SCC-BASED GENERATION ==== *)

  (* Use the already computed module groups *)
  Fmt.pr "\nUsing computed dependency groups...\n";
  Fmt.pr "Found %d module groups (%d cyclic, %d acyclic)\n"
    (List.length module_groups_list)
    (List.length
       (List.filter module_groups_list
          ~f:Gir_gen_lib.Dependency_analysis.is_cyclic_group))
    (List.length
       (List.filter module_groups_list ~f:(fun g ->
            not (Gir_gen_lib.Dependency_analysis.is_cyclic_group g))));

  (* Generate Layer 1 files (OCaml interfaces) *)
  Fmt.pr "\nGenerating Layer 1 interface files...\n";
  List.iter
    ~f:(fun group ->
      match group with
      | Gir_gen_lib.Dependency_analysis.Single entity ->
          let parent_chain =
            parent_chain_for_class entity.Gir_gen_lib.Types.name
          in
          generate_ml_interfaces ~ctx ~output_dir ~parent_chain entity
      | Gir_gen_lib.Dependency_analysis.Cycle cycle_entities ->
          let names =
            String.concat ~sep:", "
              (List.map cycle_entities ~f:(fun e -> e.Gir_gen_lib.Types.name))
          in
          Fmt.pr "  Generating combined module for cycle: %s\n" names;
          generate_combined_ml_files ~ctx ~output_dir ~module_group:group
            ~parent_chain_for_class)
    module_groups_list;

  (* Generate Layer 2 files (high-level wrapper classes) *)
  Fmt.pr "\nGenerating Layer 2 class files...\n";
  List.iter
    ~f:(fun group ->
      match group with
      | Gir_gen_lib.Dependency_analysis.Single entity ->
          let parent_chain =
            parent_chain_for_class entity.Gir_gen_lib.Types.name
          in
          generate_high_level_class ~ctx ~output_dir entity parent_chain
      | Gir_gen_lib.Dependency_analysis.Cycle cycle_entities ->
          let names =
            String.concat ~sep:", "
              (List.map cycle_entities ~f:(fun e -> e.Gir_gen_lib.Types.name))
          in
          Fmt.pr "  Generating combined class for cycle: %s\n" names;
          generate_combined_class_files ~ctx ~output_dir ~module_group:group
            ~parent_chain_for_class;
          (* Generate shim modules for each entity in the cycle *)
          let combined_module_name =
            Gir_gen_lib.Dependency_analysis.module_name_of_group group
          in
          List.iter cycle_entities ~f:(fun entity ->
              generate_cyclic_shim_files ~ctx ~output_dir ~combined_module_name
                ~entity))
    module_groups_list;

  (* ==== BUILD CONFIGURATION ==== *)

  (* Generate dune file in generated/ subdirectory *)
  let dune_file =
    Filename.concat (generated_output_dir output_dir) "dune-generated.inc"
  in
  Fmt.pr "\n";
  let stub_list = List.rev !generated_stubs |> List.sort ~cmp:String.compare in

  (* ==== LIBRARY TOP-LEVEL MODULE ==== *)
  Fmt.pr "Generating library top-level module...\n";
  let lib_name = String.capitalize_ascii namespace.namespace_name in
  let lib_ml_file =
    Filename.concat (generated_output_dir output_dir) (lib_name ^ ".ml")
  in
  let lib_mli_file =
    Filename.concat (generated_output_dir output_dir) (lib_name ^ ".mli")
  in
  let lib_ml_content, lib_mli_content =
    Gir_gen_lib.Generate.Library_module.generate_library_module ~ctx
  in
  write_file ~path:lib_ml_file ~content:lib_ml_content;
  write_file ~path:lib_mli_file ~content:lib_mli_content;

  (* ==== LIBRARY WRAPPER MODULE ==== *)
  (* Generate ocgtk_<ns>.ml that re-exports the library module as the
     dune wrapper, hiding internal module structure *)
  let wrapper_name =
    Gir_gen_lib.Utils.library_wrapper_name namespace.namespace_name
  in
  let wrapper_ml_file =
    Filename.concat (generated_output_dir output_dir) (wrapper_name ^ ".ml")
  in
  (* Scan for hand-written modules in core/ subdirectory *)
  let core_dir = Filename.concat output_dir "core" in
  let core_modules =
    if Sys.file_exists core_dir && Sys.is_directory core_dir then
      Sys.readdir core_dir |> Array.to_list
      |> List.filter_map ~f:(fun f ->
          if
            Filename.check_suffix f ".ml"
            && not (Filename.check_suffix f ".mli")
          then Some (String.capitalize_ascii (Filename.chop_suffix f ".ml"))
          else None)
      |> List.sort ~cmp:String.compare
    else []
  in
  let core_module_lines =
    List.map core_modules ~f:(fun m -> Fmt.str "module %s = %s" m m)
  in
  let enums_module_name =
    Gir_gen_lib.Utils.internal_namespace_to_module_name namespace.namespace_name
    ^ "_enums"
  in
  let enums_ml_path =
    Filename.concat
      (generated_output_dir output_dir)
      (String.lowercase_ascii namespace.namespace_name ^ "_enums.ml")
  in
  let enums_alias_line =
    if Sys.file_exists enums_ml_path then
      Fmt.str "module %s = %s\n" enums_module_name enums_module_name
    else ""
  in
  let constants_module_name =
    Gir_gen_lib.Utils.internal_namespace_to_module_name namespace.namespace_name
    ^ "_constants"
  in
  let constants_ml_path =
    Filename.concat
      (generated_output_dir output_dir)
      (String.lowercase_ascii namespace.namespace_name ^ "_constants.ml")
  in
  let constants_alias_line =
    if Sys.file_exists constants_ml_path then
      Fmt.str "module %s = %s\n" constants_module_name constants_module_name
    else ""
  in
  let wrapper_content =
    Fmt.str
      "(* GENERATED CODE - DO NOT EDIT *)\n\
       (* Library wrapper module - re-exports %s as the public API *)\n\n\
       module %s = %s\n\
       %s%s%s\n"
      lib_name lib_name lib_name enums_alias_line constants_alias_line
      (String.concat ~sep:"\n" core_module_lines)
  in
  write_file ~path:wrapper_ml_file ~content:wrapper_content;

  let dune_content =
    Gir_gen_lib.Generate.Dune_file.generate_dune_library ~ctx
      ~stub_names:stub_list ~lib_name:namespace.namespace_name ~repository
  in
  write_file ~path:dune_file ~content:dune_content;

  (* ==== SUMMARY ==== *)
  let boxed_record_count =
    List.length
      (List.filter all_records ~f:Gir_gen_lib.Type_mappings.is_boxed_record)
  in
  let record_binding_count =
    List.length
      (List.filter all_records ~f:(fun r ->
           Gir_gen_lib.Type_mappings.is_boxed_record r
           && (List.length r.Gir_gen_lib.Types.constructors > 0
              || List.length r.Gir_gen_lib.Types.methods > 0)))
  in

  Fmt.pr "\n✓ Code generation complete!\n";
  Fmt.pr "  Generated: %d C files (classes/interfaces) and %d record stubs\n"
    (List.length all_classes + List.length interfaces)
    boxed_record_count;
  Fmt.pr "  Generated: %d OCaml interface files and %d record bindings\n"
    (List.length all_classes + List.length interfaces)
    record_binding_count;
  if List.length gtk_enums > 0 || List.length gtk_bitfields > 0 then begin
    let ns_name = ctx.namespace.namespace_name in
    Fmt.pr
      "  Generated: %s_enums.mli and ml_%s_enums_gen.c (%d enumerations, %d \
       bitfields)\n"
      (String.lowercase_ascii ns_name)
      (String.lowercase_ascii ns_name)
      (List.length gtk_enums)
      (List.length gtk_bitfields)
  end;
  Fmt.pr "  Generated: dune-generated.inc with %d C stub names\n"
    (List.length stub_list);
  Fmt.pr "  Generated: %s.ml/.mli (library top-level module)\n" lib_name;
  `Ok ()

(* References generation function *)
let generate_references gir_file output_file overrides_file =
  Fmt.pr "Parsing %s for references...\n" gir_file;

  let filter_classes = [] in

  let ( repository,
        namespace,
        classes,
        interfaces,
        enums,
        bitfields,
        records,
        constants ) =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file gir_file filter_classes
  in

  (* Apply overrides to filter ignored entities from references *)
  let classes, interfaces, enums, bitfields, records =
    match overrides_file with
    | None -> (classes, interfaces, enums, bitfields, records)
    | Some file -> (
        Fmt.pr "Loading overrides from %s\n" file;
        match Gir_gen_lib.Override_parser.parse_overrides file with
        | Error e ->
            Fmt.epr "Error: override parse failed: %s\n"
              (Gir_gen_lib.Override_parser.format_error e);
            exit 1
        | Ok ov ->
            let result =
              (* parse_gir_file does not extract top-level namespace functions,
             so ~functions:[] is correct — there is nothing to filter. *)
              Gir_gen_lib.Override_apply.apply_overrides ~overrides:ov ~classes
                ~interfaces ~enums ~bitfields ~records ~functions:[]
            in
            List.iter result.warnings ~f:(fun w -> Fmt.epr "Warning: %s\n" w);
            ( result.classes,
              result.interfaces,
              result.enums,
              result.bitfields,
              result.records ))
  in

  Fmt.pr "References will be written to: %s\n" output_file;
  let entities =
    (classes
    |> List.filter ~f:Gir_gen_lib.Generate.Filtering.should_generate_class
    |> List.map ~f:(fun cls ->
        {
          cr_name = cls.class_name;
          cr_type =
            Crt_Class { parent = cls.parent; implements = cls.implements };
          cr_c_type = cls.c_type;
        }))
    @ (interfaces
      |> List.map ~f:(fun intf ->
          {
            cr_name = intf.interface_name;
            cr_type = Crt_Interface;
            cr_c_type = intf.c_type;
          }))
    @ List.map
        ~f:(fun enms ->
          {
            cr_name = enms.enum_name;
            cr_type = Crt_Enum;
            cr_c_type = enms.enum_c_type;
          })
        enums
    @ List.map
        ~f:(fun bitfield ->
          {
            cr_name = bitfield.bitfield_name;
            cr_type = Crt_Bitfield;
            cr_c_type = bitfield.bitfield_c_type;
          })
        bitfields
    @ (records
      |> List.filter ~f:Gir_gen_lib.Generate.Filtering.should_generate_record
      |> List.map ~f:(fun rec_ ->
          {
            cr_name = rec_.record_name;
            cr_type =
              Crt_Record
                { opaque = rec_.opaque; get_type_func = rec_.glib_get_type };
            cr_c_type = rec_.c_type;
          }))
    @ List.map
        ~f:(fun cst ->
          {
            cr_name = cst.constant_name;
            cr_type = Crt_Constant;
            cr_c_type = cst.constant_c_type;
          })
        constants
  in
  let crns =
    Gir_gen_lib.Types.
      {
        cr_namespace_name = namespace.namespace_name;
        cr_namespace_packages = repository.repository_packages;
        cr_namespace_c_includes = repository.repository_c_includes;
        cr_namespace_includes =
          (* FIXME: we should probably include the include version too *)
          List.map
            ~f:(fun { include_name; _ } -> include_name)
            repository.repository_includes;
        cr_entities = entities;
      }
  in
  let converter = Gir_gen_lib.Types.sexp_of_cross_reference_namespace in
  Sexplib.Sexp.(save_hum output_file (converter crns));
  `Ok ()

let extract_since_version = Gir_gen_lib.Override_extractor.extract_since_version

let render_version_component ~kind (name : string) (version : string) =
  Fmt.str "    (%s %s (version \"%s\"))" kind name version

(* Render a single component override back to human-friendly sexp. *)
let render_component ~kind (c : Gir_gen_lib.Override_types.component_override) =
  match c.action with
  | Some Gir_gen_lib.Override_types.Ignore ->
      Fmt.str "    (%s %s (ignore))" kind c.component_name
  | Some (Gir_gen_lib.Override_types.Set_version vs) ->
      Fmt.str "    (%s %s (version \"%s\"))" kind c.component_name vs.vs_version
  | None -> Fmt.str "    (%s %s)" kind c.component_name

(* Render an enum override entry, merging existing ignores with fresh version data.
   [ignore_components]: component-level ignores to preserve from the existing file.
   [version_data]: fresh (name, version) pairs from GIR.
   [entity_action]: entity-level ignore to preserve, if any. *)
let render_enum_entry entity_kind component_kind entity_name entity_action
    ignore_components version_data =
  let buf = Buffer.create 128 in
  bprintf buf "\n  (%s %s\n" entity_kind entity_name;
  (match entity_action with
  | Some Gir_gen_lib.Override_types.Ignore -> bprintf buf "    (ignore)\n"
  | Some (Gir_gen_lib.Override_types.Set_version vs) ->
      bprintf buf "    (version \"%s\")\n" vs.vs_version
  | None -> ());
  List.iter
    ~f:(fun c -> bprintf buf "%s\n" (render_component ~kind:component_kind c))
    ignore_components;
  List.iter
    ~f:(fun (name, version) ->
      bprintf buf "%s\n"
        (render_version_component ~kind:component_kind name version))
    version_data;
  bprintf buf "  )";
  Buffer.contents buf

(* Merge GIR-extracted version data into an existing override file's entity list.
   Preserves all (ignore) directives; replaces version annotations with fresh GIR data.
   [existing]: parsed existing override entities (may be empty if file is new).
   [gir_versions]: map from entity_name -> [(component_name, version_str)].
   [get_name / get_action / get_components]: accessors for the entity type.
   [component_kind]: "member" or "field" for rendering.
   [entity_kind]: "enumeration", "bitfield", or "record" for rendering. *)
let merge_version_entities ~entity_kind ~component_kind ~existing ~gir_versions
    ~get_name ~get_entity_action ~get_components =
  let buf = Buffer.create 512 in
  (* Track which existing entities we've processed *)
  let processed = Hashtbl.create 16 in
  (* Emit entities that appear in GIR version data *)
  List.iter
    ~f:(fun (entity_name, version_data) ->
      Hashtbl.replace processed entity_name true;
      let existing_ov =
        List.find_opt
          ~f:(fun e -> String.equal (get_name e) entity_name)
          existing
      in
      let entity_action, ignore_components =
        match existing_ov with
        | None -> (None, [])
        | Some ov ->
            let ignores =
              List.filter
                ~f:(fun (c : Gir_gen_lib.Override_types.component_override) ->
                  match c.action with
                  | Some Gir_gen_lib.Override_types.Ignore -> true
                  | Some (Gir_gen_lib.Override_types.Set_version _) | None ->
                      false)
                (get_components ov)
            in
            (get_entity_action ov, ignores)
      in
      bprintf buf "%s\n"
        (render_enum_entry entity_kind component_kind entity_name entity_action
           ignore_components version_data))
    gir_versions;
  (* Emit existing entities that had no GIR version data (preserve as-is) *)
  List.iter
    ~f:(fun e ->
      let name = get_name e in
      if not (Hashtbl.mem processed name) then begin
        let entity_action = get_entity_action e in
        let all_components = get_components e in
        bprintf buf "%s\n"
          (render_enum_entry entity_kind component_kind name entity_action
             all_components [])
      end)
    existing;
  Buffer.contents buf

(* Collect version overrides from Since annotations in member doc text.
   The parser handles version XML attributes natively; this only extracts
   unstructured "Since X.Y" text that is not captured by the parser. *)
let member_versions_from_docs members get_name get_doc =
  List.filter_map
    ~f:(fun m ->
      match get_doc m with
      | None -> None
      | Some doc -> (
          match extract_since_version doc with
          | None -> None
          | Some v -> Some (get_name m, v)))
    members

(* Generate overrides sexp file from parsed GIR data, merging with any existing file.
   Existing (ignore) entries are always preserved. Version annotations are replaced
   with fresh data extracted from GIR <doc> text. *)
let generate_overrides gir_file output_file =
  Fmt.pr "Parsing %s for Since version annotations...\n" gir_file;

  let ( _repository,
        namespace,
        _classes,
        _interfaces,
        enums,
        bitfields,
        records,
        _constants ) =
    Gir_gen_lib.Parse.Gir_parser.parse_gir_file gir_file []
  in
  let lib_name = namespace.namespace_name in

  (* Load existing overrides if the file already exists *)
  let existing =
    if Sys.file_exists output_file then begin
      Fmt.pr "Merging with existing %s...\n" output_file;
      match Gir_gen_lib.Override_parser.parse_overrides output_file with
      | Ok ov -> ov
      | Error e ->
          Fmt.epr
            "Warning: could not parse existing override file (%s); starting \
             fresh\n"
            (Gir_gen_lib.Override_parser.format_error e);
          {
            Gir_gen_lib.Override_types.library_name = lib_name;
            classes = [];
            interfaces = [];
            records = [];
            enums = [];
            bitfields = [];
            functions = [];
            headers = [];
          }
    end
    else
      {
        Gir_gen_lib.Override_types.library_name = lib_name;
        classes = [];
        interfaces = [];
        records = [];
        enums = [];
        bitfields = [];
        functions = [];
        headers = [];
      }
  in

  let buf = Buffer.create 4096 in
  Buffer.add_string buf (Fmt.str "(overrides\n  (library \"%s\")\n" lib_name);

  (* Emit class/interface/function overrides from existing file unchanged *)
  List.iter
    ~f:(fun (o : Gir_gen_lib.Override_types.class_override) ->
      let buf2 = Buffer.create 64 in
      bprintf buf2 "\n  (class %s\n" o.class_name;
      (match o.class_action with
      | Some Gir_gen_lib.Override_types.Ignore -> bprintf buf2 "    (ignore)\n"
      | Some (Gir_gen_lib.Override_types.Set_version vs) ->
          bprintf buf2 "    (version \"%s\")\n" vs.vs_version
      | None -> ());
      List.iter
        ~f:(fun c ->
          bprintf buf2 "%s\n" (render_component ~kind:"constructor" c))
        o.constructors;
      List.iter
        ~f:(fun c -> bprintf buf2 "%s\n" (render_component ~kind:"method" c))
        o.methods;
      List.iter
        ~f:(fun c -> bprintf buf2 "%s\n" (render_component ~kind:"property" c))
        o.properties;
      List.iter
        ~f:(fun c -> bprintf buf2 "%s\n" (render_component ~kind:"signal" c))
        o.signals;
      bprintf buf2 "  )";
      bprintf buf "%s\n" (Buffer.contents buf2))
    existing.classes;

  (* Merge enum version data with existing enum ignores *)
  let enum_versions =
    List.filter_map
      ~f:(fun (enm : gir_enum) ->
        let vs =
          member_versions_from_docs enm.members
            (fun m -> m.member_name)
            (fun m -> m.member_doc)
        in
        if vs <> [] then Some (enm.enum_name, vs) else None)
      enums
  in
  Buffer.add_string buf
    (merge_version_entities ~entity_kind:"enumeration" ~component_kind:"member"
       ~existing:existing.enums ~gir_versions:enum_versions
       ~get_name:(fun (o : Gir_gen_lib.Override_types.enum_override) ->
         o.enum_name)
       ~get_entity_action:(fun o -> o.enum_action)
       ~get_components:(fun o -> o.members));

  (* Merge bitfield version data with existing bitfield ignores *)
  let bitfield_versions =
    List.filter_map
      ~f:(fun (bf : gir_bitfield) ->
        let vs =
          member_versions_from_docs bf.flags
            (fun f -> f.flag_name)
            (fun f -> f.flag_doc)
        in
        if vs <> [] then Some (bf.bitfield_name, vs) else None)
      bitfields
  in
  Buffer.add_string buf
    (merge_version_entities ~entity_kind:"bitfield" ~component_kind:"member"
       ~existing:existing.bitfields ~gir_versions:bitfield_versions
       ~get_name:(fun (o : Gir_gen_lib.Override_types.bitfield_override) ->
         o.bitfield_name)
       ~get_entity_action:(fun o -> o.bitfield_action)
       ~get_components:(fun o -> o.flags));

  (* Merge record field version data with existing record ignores *)
  let record_versions =
    List.filter_map
      ~f:(fun (rec_ : gir_record) ->
        let vs =
          member_versions_from_docs rec_.fields
            (fun f -> f.field_name)
            (fun f -> f.field_doc)
        in
        if vs <> [] then Some (rec_.record_name, vs) else None)
      records
  in
  Buffer.add_string buf
    (merge_version_entities ~entity_kind:"record" ~component_kind:"field"
       ~existing:existing.records ~gir_versions:record_versions
       ~get_name:(fun (o : Gir_gen_lib.Override_types.record_override) ->
         o.record_name)
       ~get_entity_action:(fun o -> o.record_action)
       ~get_components:(fun o ->
         (* Only carry forward ignore-action field components; version ones are replaced *)
         List.filter
           ~f:(fun (c : Gir_gen_lib.Override_types.component_override) ->
             match c.action with
             | Some Gir_gen_lib.Override_types.Ignore -> true
             | Some (Gir_gen_lib.Override_types.Set_version _) | None -> false)
           o.fields));

  Buffer.add_string buf ")\n";

  let content = Buffer.contents buf in
  write_file ~path:output_file ~content;
  Fmt.pr "✓ Overrides written to %s\n" output_file;
  `Ok ()

(* Cmdliner argument definitions *)
let filter_arg =
  let doc = "Filter file specifying which classes to generate" in
  Arg.(value & opt (some file) None & info [ "f"; "filter" ] ~docv:"FILE" ~doc)

let gir_file_arg =
  let doc = "Path to GTK GIR file (e.g., gir/Gtk-4.0.gir)" in
  Arg.(required & pos 0 (some file) None & info [] ~docv:"GIR_FILE" ~doc)

let output_dir_arg =
  let doc = "Output directory for generated files" in
  Arg.(required & pos 1 (some dir) None & info [] ~docv:"OUTPUT_DIR" ~doc)

let reference_files_arg =
  let doc =
    "Path to reference file for cross-namespace type validation (can be \
     specified multiple times)"
  in
  Arg.(value & opt_all file [] & info [ "r"; "reference" ] ~docv:"FILE" ~doc)

let overrides_arg =
  let doc = "Override file (s-expression) for GIR generation configuration" in
  Arg.(
    value & opt (some file) None & info [ "o"; "overrides" ] ~docv:"FILE" ~doc)

(* Arguments for references command *)
let gir_file_arg_refs =
  let doc = "Path to GIR file to parse for references" in
  Arg.(required & pos 0 (some file) None & info [] ~docv:"GIR_FILE" ~doc)

let output_file_arg_refs =
  let doc = "Output file path for generated references" in
  Arg.(required & pos 1 (some string) None & info [] ~docv:"OUTPUT_FILE" ~doc)

let overrides_arg_refs =
  let doc = "Override file for filtering references" in
  Arg.(
    value & opt (some file) None & info [ "o"; "overrides" ] ~docv:"FILE" ~doc)

(* Command definitions *)

(* Generate subcommand *)
let generate_cmd =
  let doc = "Generate C FFI bindings and OCaml modules from GTK GIR files" in
  let man =
    [
      `S Manpage.s_description;
      `P
        "The generate command parses GTK GObject Introspection (GIR) files and \
         generates C FFI bindings and OCaml module interfaces for GTK4 event \
         controllers and widgets.";
      `S Manpage.s_examples;
      `P "Generate event controller bindings:";
      `Pre "  gir_gen generate gir/Gtk-4.0.gir ./output";
      `P "Generate with cross-namespace references:";
      `Pre
        "  gir_gen generate -r gtk_refs.txt -r gdk_refs.txt gir/Gtk-4.0.gir \
         ./output";
      `P "Generate with override file:";
      `Pre
        "  gir_gen generate -o ocgtk/overrides/gtk.sexp gir/Gtk-4.0.gir \
         ./output";
    ]
  in
  let info = Cmd.info "generate" ~doc ~man in
  Cmd.v info
    Term.(
      ret
        (const generate_bindings $ filter_arg $ gir_file_arg $ output_dir_arg
       $ reference_files_arg $ overrides_arg))

(* Arguments for overrides command *)
let gir_file_arg_overrides =
  let doc = "Path to GIR file to parse for Since version annotations" in
  Arg.(required & pos 0 (some file) None & info [] ~docv:"GIR_FILE" ~doc)

let output_file_arg_overrides =
  let doc = "Output file path for generated override sexp" in
  Arg.(required & pos 1 (some string) None & info [] ~docv:"OUTPUT_FILE" ~doc)

(* Overrides subcommand *)
let overrides_cmd =
  let doc =
    "Extract Since version annotations from a GIR file into an override sexp"
  in
  let man =
    [
      `S Manpage.s_description;
      `P
        "The overrides command parses a GIR file and generates a partial \
         override file containing version entries extracted from Since \
         comments in member/field doc strings. The output can be combined with \
         manually-authored ignore entries to form a complete override file.";
      `S Manpage.s_examples;
      `P "Extract version overrides from GTK GIR:";
      `Pre "  gir_gen overrides gir/Gtk-4.0.gir ocgtk/overrides/gtk.sexp";
    ]
  in
  let info = Cmd.info "overrides" ~doc ~man in
  Cmd.v info
    Term.(
      ret
        (const generate_overrides $ gir_file_arg_overrides
       $ output_file_arg_overrides))

(* References subcommand *)
let references_cmd =
  let doc = "Generate cross-namespace reference list from a GIR file" in
  let man =
    [
      `S Manpage.s_description;
      `P
        "The references command parses a GIR file and generates a reference \
         list that can be used for cross-namespace type validation during code \
         generation.";
      `S Manpage.s_examples;
      `P "Generate reference list:";
      `Pre "  gir_gen references gir/Gtk-4.0.gir gtk_refs.txt";
      `P "Generate reference list with overrides:";
      `Pre
        "  gir_gen references -o ocgtk/overrides/gtk.sexp gir/Gtk-4.0.gir \
         gtk_refs.txt";
    ]
  in
  let info = Cmd.info "references" ~doc ~man in
  Cmd.v info
    Term.(
      ret
        (const generate_references $ gir_file_arg_refs $ output_file_arg_refs
       $ overrides_arg_refs))

(* Main command *)
let gir_gen_cmd =
  let doc = "Generate C FFI bindings and OCaml modules from GTK GIR files" in
  let man =
    [
      `S Manpage.s_description;
      `P
        "gir_gen parses GTK GObject Introspection (GIR) files and generates C \
         FFI bindings and OCaml module interfaces for GTK4 event controllers \
         and widgets.";
      `S Manpage.s_commands;
      `P "Available commands:";
      `I ("generate", "Generate C FFI bindings and OCaml modules");
      `I ("references", "Generate cross-namespace reference list");
      `I ("overrides", "Extract Since version annotations into override sexp");
      `S Manpage.s_bugs;
      `P "Report bugs to https://github.com/chris-armstrong/ocgtk/issues";
    ]
  in
  let info = Cmd.info "gir_gen" ~version:"5.0.0" ~doc ~man in
  let default = Term.(ret (const (`Help (`Pager, None)))) in
  Cmd.group info ~default [ generate_cmd; references_cmd; overrides_cmd ]

(* Main entry point *)
let () = exit (Cmd.eval gir_gen_cmd)
