(* Dune File Generation *)

open ContainersLabels
open Gen_buffer

(* Maximum C stub files per batch library. Windows (CreateProcess) has a
   32 767-char command-line limit; ~80 stubs × ~55-char path ≈ 4 400 chars,
   leaving enough headroom for the ar/ld invocation. *)
let stub_batch_size = 80

(* Split a list into chunks of at most n elements, preserving order. *)
let list_chunks n lst =
  let rec go acc cur cnt = function
    | [] ->
        if List.is_empty cur then List.rev acc
        else List.rev (List.rev cur :: acc)
    | x :: rest ->
        if cnt = n then go (List.rev cur :: acc) [ x ] 1 rest
        else go acc (x :: cur) (cnt + 1) rest
  in
  go [] [] 0 lst

(* Map GIR namespace names to pkg-config package names *)
let pkg_config_name_of_namespace ~ctx namespace_name =
  let open Types in
  if List.mem ~eq:String.equal namespace_name C_stubs.base_namespaces then []
  else
    let ncr_namespace =
      StringMap.find_opt namespace_name ctx.cross_references
    in
    let namespace_packages =
      ncr_namespace
      |> Option.get_exn_or
           ("Unable to find packages for namespace " ^ namespace_name)
      |> fun ncr_namespace -> ncr_namespace.ncr_namespace_packages
    in
    namespace_packages

(* Recursively collect all pkg-config packages from a namespace and its
   transitive includes. This is needed because C headers form a transitive
   inclusion chain (e.g. pangocairo_decls.h -> pango_decls.h -> gio_decls.h)
   so all transitive pkg-config packages must be available for compilation.
   Dune does not propagate foreign-stub include flags between libraries, so
   each generated stubs library must receive the full transitive cflag set. *)
let rec collect_transitive_packages ~ctx ~visited namespace_name =
  let open Types in
  if
    List.mem ~eq:String.equal namespace_name visited
    || List.mem ~eq:String.equal namespace_name C_stubs.base_namespaces
  then []
  else
    let visited = namespace_name :: visited in
    let direct = pkg_config_name_of_namespace ~ctx namespace_name in
    let transitive =
      match StringMap.find_opt namespace_name ctx.cross_references with
      | None -> []
      | Some ncr ->
          ncr.ncr_namespace_includes
          |> List.map ~f:(collect_transitive_packages ~ctx ~visited)
          |> List.flatten
    in
    direct @ transitive

(* Whether namespace_name is, or transitively includes, target_namespace. *)
let rec transitively_includes ~ctx ~visited ~target namespace_name =
  let open Types in
  String.equal namespace_name target
  ||
  if List.mem ~eq:String.equal namespace_name visited then false
  else
    let visited = namespace_name :: visited in
    match StringMap.find_opt namespace_name ctx.cross_references with
    | None -> false
    | Some ncr ->
        List.exists
          ~f:(transitively_includes ~ctx ~visited ~target)
          ncr.ncr_namespace_includes

(* Map namespace to library name for dune (ocgtk.<ns>) *)
let library_name_of_namespace namespace_name =
  let ns_lower = String.lowercase_ascii namespace_name in
  Fmt.str "ocgtk.%s" ns_lower

(* Emit the pkg-config rule that generates cflag and clink sexp files. *)
let emit_pkg_config_rule buf ~cflag_file ~clink_file ~all_packages ~is_optional
    =
  bprintf buf "(rule\n";
  bprintf buf " (targets %s %s)\n" cflag_file clink_file;
  bprintf buf " (action\n";
  bprintf buf "  (run\n";
  bprintf buf "   %%{exe:../configurator/config_flags.exe}\n";
  List.iter
    ~f:(fun package_name ->
      let flag =
        if is_optional package_name then "--pkg-optional" else "--pkg"
      in
      bprintf buf "   %s\n   %s\n" flag package_name)
    all_packages;
  bprintf buf "   --cflags-out\n   %s\n" cflag_file;
  bprintf buf "   --libs-out\n   %s)))\n\n" clink_file

(* Emit one library stanza containing C foreign stubs (either the single
   stubs library or one batch of it). *)
let emit_stub_library buf ~name ~public_name ~dep_libraries ~stub_names
    ~cflag_file ~clink_file =
  bprintf buf "(library\n";
  bprintf buf " (name %s)\n" name;
  (match public_name with
  | Some pn -> bprintf buf " (public_name %s)\n" pn
  | None -> ());
  Buffer.add_string buf " (wrapped false)\n";
  Buffer.add_string buf " (modules)  ; No OCaml modules, only C stubs\n";
  let libraries_clause =
    if String.equal dep_libraries "" then
      " (libraries ocgtk_common)  ; Depend on common for header files\n"
    else
      Fmt.str
        " (libraries %s ocgtk_common)  ; Dependencies and common for header \
         files\n"
        dep_libraries
  in
  Buffer.add_string buf libraries_clause;
  Buffer.add_string buf " (foreign_stubs\n";
  Buffer.add_string buf "  (language c)\n";
  Buffer.add_string buf "  (names\n";
  List.iter ~f:(fun s -> bprintf buf "   %s\n" s) stub_names;
  Buffer.add_string buf "  )\n";
  bprintf buf
    "  (flags -fPIC -Igenerated -Icore -I../common (:include %s) \
     -Wno-deprecated-declarations -Wno-incompatible-pointer-types \
     -Wno-int-conversion))\n"
    cflag_file;
  bprintf buf " (c_library_flags (:include %s)))\n\n" clink_file

(* Generate dune library stanza for generated C stubs *)
let generate_dune_library ~ctx ~lib_name ~stub_names ~repository =
  let buf = Buffer.create 2048 in

  let lib_name_snake = lib_name |> Utils.to_snake_case in
  let cflag_file = Fmt.str "cflag-%s.sexp" (String.lowercase_ascii lib_name) in
  let clink_file = Fmt.str "clink-%s.sexp" (String.lowercase_ascii lib_name) in

  Buffer.add_string buf "; Auto-generated library for generated C bindings\n";
  Buffer.add_string buf "; Regenerate by running gir_gen\n\n";

  (* Collect pkg-config packages from dependencies, recursively following
     cross-namespace includes to pick up transitive pkg-config deps *)
  let dep_packages =
    let open Types in
    repository.repository_includes
    |> List.map ~f:(fun include_ ->
        collect_transitive_packages ~ctx ~visited:[] include_.include_name)
    |> List.flatten
    |> List.sort_uniq ~cmp:String.compare
  in
  (* Our hand-written gio_core.h unconditionally #includes gio-unix-2.0
     headers on Linux (see src/gio/core/gio_core.h). Newer GLib (>=2.86)
     split Gio's Unix-specific types out into a separate GioUnix-2.0
     namespace, so Gio-2.0.gir no longer declares <package
     name="gio-unix-2.0"/> and it won't show up via repository_packages or
     dep_packages below. Force it in for Gio itself and for anything that
     transitively pulls in Gio's headers, regardless of what the GIR
     declares. *)
  let needs_gio_unix =
    String.equal lib_name "Gio"
    || List.exists
         ~f:(fun { Types.include_name; _ } ->
           transitively_includes ~ctx ~visited:[] ~target:"Gio" include_name)
         repository.repository_includes
  in
  let all_packages =
    (if needs_gio_unix then [ "gio-unix-2.0" ] else [])
    @ repository.repository_packages @ dep_packages
    |> List.sort_uniq ~cmp:String.compare
  in

  (* Packages that are Linux-only (e.g. gio-unix-2.0 is absent on macOS /
     FreeBSD where Homebrew GLib ships no separate .pc file). These are
     queried with --pkg-optional so the configurator silently skips them
     on platforms where they don't exist. *)
  let optional_packages = [ "gio-unix-2.0" ] in
  let is_optional p = List.mem ~eq:String.equal p optional_packages in

  emit_pkg_config_rule buf ~cflag_file ~clink_file ~all_packages ~is_optional;

  (* Compute the dep_libraries string (used in C stubs (libraries ...) clause
     for transitive header include paths). *)
  let rec collect_transitive_namespaces ~visited namespace_name =
    let open Types in
    if
      List.mem ~eq:String.equal namespace_name visited
      || List.mem ~eq:String.equal namespace_name C_stubs.base_namespaces
    then []
    else
      let visited = namespace_name :: visited in
      let transitive =
        match StringMap.find_opt namespace_name ctx.cross_references with
        | None -> []
        | Some ncr ->
            ncr.ncr_namespace_includes
            |> List.map ~f:(collect_transitive_namespaces ~visited)
            |> List.flatten
      in
      namespace_name :: transitive
  in
  let dep_libraries =
    Types.(repository.repository_includes)
    |> List.map ~f:(fun { Types.include_name; _ } ->
        collect_transitive_namespaces ~visited:[] include_name)
    |> List.flatten
    |> List.sort_uniq ~cmp:String.compare
    |> List.map ~f:library_name_of_namespace
    |> String.concat ~sep:" "
  in

  let n_stubs = List.length stub_names in
  if n_stubs <= stub_batch_size then begin
    (* Small enough to fit in a single library stanza *)
    emit_stub_library buf
      ~name:(Fmt.str "ocgtk_%s_generated_stubs" lib_name_snake)
      ~public_name:(Some (Fmt.str "ocgtk.%s.generated_stubs" lib_name_snake))
      ~dep_libraries ~stub_names ~cflag_file ~clink_file
  end
  else begin
    (* Too many stubs for a single Windows command line — split into batches.
       Each batch is a private library; a public facade library depends on all
       of them so downstream consumers need only list the facade. *)
    let batches = list_chunks stub_batch_size stub_names in
    let batch_lib_names =
      List.mapi
        ~f:(fun i _ ->
          Fmt.str "ocgtk_%s_generated_stubs_batch_%d" lib_name_snake i)
        batches
    in
    let batch_public_names =
      List.mapi
        ~f:(fun i _ ->
          Fmt.str "ocgtk.%s.generated_stubs_batch_%d" lib_name_snake i)
        batches
    in
    (* Emit each batch library with a public name (required because the public
       facade library lists them as dependencies). *)
    List.iter2
      ~f:(fun (batch_name, batch_public) batch_stubs ->
        emit_stub_library buf ~name:batch_name ~public_name:(Some batch_public)
          ~dep_libraries ~stub_names:batch_stubs ~cflag_file ~clink_file)
      (List.combine batch_lib_names batch_public_names)
      batches;
    (* Emit the public facade library that depends on all batches.
       The facade carries no C stubs itself; dune propagates the C archives
       of the batch libraries transitively when linking downstream targets. *)
    bprintf buf "(library\n";
    bprintf buf " (name ocgtk_%s_generated_stubs)\n" lib_name_snake;
    bprintf buf " (public_name ocgtk.%s.generated_stubs)\n" lib_name_snake;
    Buffer.add_string buf " (wrapped false)\n";
    Buffer.add_string buf " (modules)  ; No OCaml modules, only C stubs\n";
    let batch_deps = String.concat ~sep:" " batch_lib_names in
    bprintf buf " (libraries %s))\n" batch_deps
  end;

  Buffer.contents buf
