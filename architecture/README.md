# ocgtk Architecture

This directory contains architecture documentation for ocgtk contributors.

Start with **[overview.md](./overview.md)** — it walks through the whole system:
project layout, the binding layers, the gir_gen pipeline, dependency analysis and
cycle handling, dead code elimination, closures and signals, and cross-namespace
types.

## Documents

| Document | Contents |
|----------|----------|
| [overview.md](./overview.md) | Comprehensive architecture introduction |
| [gir_gen/overrides.md](./gir_gen/overrides.md) | Override sexp file format and pipeline position |
| [special_case_generation.md](./special_case_generation.md) | Arrays, GList, nullable, out-params, enums, version guards, and suppressed patterns |
| [closures_and_signals.md](./closures_and_signals.md) | GObject closure mechanism, signal_marshaller.ml, and Layer 1/2 signal generation |
| [cross_namespace_types.md](./cross_namespace_types.md) | Reference files, `<ns>_decls.h`, and the two-phase generation script |
| [linking_and_dead_code_elimination.md](./linking_and_dead_code_elimination.md) | Per-class DCE, linker behaviour, verification commands |
| [integer_type_design.md](./integer_type_design.md) | Bounded integer types (UInt16, Int32, …) — rationale and C macro layer |
| [FFI_GUIDELINES.md](./FFI_GUIDELINES.md) | OCaml/C binding best practices |
| [adding_gir_library.md](./adding_gir_library.md) | Step-by-step: adding a new GIR namespace |
| [ci_distro_testing.md](./ci_distro_testing.md) | Docker-based multi-distro CI |
| [ROADMAP.md](../ROADMAP.md) | Known limitations, deferred features, and outstanding work |

## Decision Records (ADRs)

Architectural decisions with lasting consequences are recorded as ADRs under
[`decisions/`](./decisions/). Each is numbered and states context, decision,
and consequences.

| ADR | Topic |
|-----|-------|
| [0001](./decisions/0001-gvalue-string-nullability-and-boxed-type-safety.md) | GValue string nullability and boxed getter type safety |
