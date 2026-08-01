(* pkg-config configurator for ocgtk.
   Queries pkg-config packages and writes dune sexp flag files for C
   compilation and linking.

   Usage:
     config_flags.exe [--pkg PKG]... [--pkg-optional PKG]...
                      [--cflags-out FILE] [--libs-out FILE]

   --pkg           Required package: fails if not found
   --pkg-optional  Optional package: silently skipped if not found
   --cflags-out    Output sexp file for C compiler flags
   --libs-out      Output sexp file for linker flags
*)

let dedup lst =
  List.fold_left
    (fun acc x -> if List.mem x acc then acc else acc @ [ x ])
    [] lst

let () =
  let pkgs = ref [] in
  let optional_pkgs = ref [] in
  let cflags_out = ref None in
  let libs_out = ref None in
  let spec =
    [
      ( "--pkg",
        Arg.String (fun s -> pkgs := !pkgs @ [ s ]),
        "PKG  Required pkg-config package (fails if absent)" );
      ( "--pkg-optional",
        Arg.String (fun s -> optional_pkgs := !optional_pkgs @ [ s ]),
        "PKG  Optional pkg-config package (skipped if absent)" );
      ( "--cflags-out",
        Arg.String (fun s -> cflags_out := Some s),
        "FILE  Output sexp file for C compiler flags" );
      ( "--libs-out",
        Arg.String (fun s -> libs_out := Some s),
        "FILE  Output sexp file for linker flags" );
    ]
  in
  Arg.parse spec
    (fun s -> failwith ("Unexpected argument: " ^ s))
    "config_flags [options]";
  let conf = Configurator.V1.create "ocgtk" in
  match Configurator.V1.Pkg_config.get conf with
  | None -> failwith "pkg-config is not available"
  | Some pc ->
      let query_required pkg =
        match Configurator.V1.Pkg_config.query pc ~package:pkg with
        | None ->
            failwith ("Required pkg-config package '" ^ pkg ^ "' not found")
        | Some info -> info
      in
      let query_optional pkg =
        Configurator.V1.Pkg_config.query pc ~package:pkg
      in
      let required_infos = List.map query_required !pkgs in
      let optional_infos = List.filter_map query_optional !optional_pkgs in
      let all_infos = required_infos @ optional_infos in
      let all_cflags =
        dedup
          (List.concat_map
             (fun i -> i.Configurator.V1.Pkg_config.cflags)
             all_infos)
      in
      let all_libs =
        dedup
          (List.concat_map
             (fun i -> i.Configurator.V1.Pkg_config.libs)
             required_infos)
      in
      Option.iter
        (fun f -> Configurator.V1.Flags.write_sexp f all_cflags)
        !cflags_out;
      Option.iter
        (fun f -> Configurator.V1.Flags.write_sexp f all_libs)
        !libs_out
