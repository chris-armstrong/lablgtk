(* Toolchain probe for dependent-memory custom block support.

   Detects whether the OCaml runtime headers provide
   [caml_alloc_custom_dep] together with the two-argument
   [caml_free_dependent_memory (value, mlsize_t)] — the pair the OxCaml
   runtime uses for GC pacing of external memory.  On stock OCaml 5.x
   [caml_alloc_custom_dep] is absent and [caml_free_dependent_memory]
   takes a single argument, so the probe program below fails to compile
   there (conflicting prototype), selecting the [caml_alloc_custom_mem]
   path instead.

   The probe only re-declares the functions (it never references them),
   so it compiles and links without the OCaml runtime library; a
   mismatched prototype is a hard C compile error, which is exactly the
   discriminator we need.

   Usage:
     probe_custom_dep.exe --out FILE

   Writes a dune sexp flag file containing
   [-DOCGTK_HAS_CAML_ALLOC_CUSTOM_DEP] when the toolchain supports the
   dependent-memory API, or an empty flag list otherwise. *)

let probe_program =
  {|
#include <caml/mlvalues.h>
#include <caml/custom.h>
#include <caml/memory.h>

/* Re-declarations with the dependent-memory signatures.  On a toolchain
   whose headers declare caml_free_dependent_memory with one argument,
   the second declaration conflicts and compilation fails. */
CAMLextern value caml_alloc_custom_dep(const struct custom_operations *ops,
                                       uintnat size, mlsize_t mem);
CAMLextern void caml_free_dependent_memory(value v, mlsize_t bsz);

int main(void) { return 0; }
|}

let () =
  let out = ref None in
  let spec =
    [
      ( "--out",
        Arg.String (fun s -> out := Some s),
        "FILE  Output sexp file for C compiler flags" );
    ]
  in
  Arg.parse spec
    (fun s -> failwith ("Unexpected argument: " ^ s))
    "probe_custom_dep --out FILE";
  let out =
    match !out with
    | None -> failwith "probe_custom_dep: --out is required"
    | Some f -> f
  in
  let conf = Configurator.V1.create "ocgtk" in
  let stdlib =
    Configurator.V1.ocaml_config_var_exn conf "standard_library"
  in
  let supported =
    Configurator.V1.c_test conf ~c_flags:[ "-I"; stdlib ] probe_program
  in
  let flags =
    if supported then [ "-DOCGTK_HAS_CAML_ALLOC_CUSTOM_DEP" ] else []
  in
  Configurator.V1.Flags.write_sexp out flags
