# Code Guidelines

This directory contains coding guidelines for the ocgtk project, organized by concern.

> **Maintainers**: `agent-summary.md` is a compact digest of all guidelines below.
> **Whenever you add, remove, or materially change a guideline in this directory,
> you MUST update `agent-summary.md` to reflect the change.**

## MANDATORY GUIDELINES INDEX

| Document | Concerns Covered |
|----------|-----------------|
| [core-idioms.md](./core-idioms.md) | Bind operators vs pipelines, polymorphic equality ban, naming intermediates, module extraction heuristics |
| [nesting-and-control-flow.md](./nesting-and-control-flow.md) | Reducing nesting, bind operators |
| [error-handling.md](./error-handling.md) | Result vs exceptions, error context |
| [naming-and-intermediates.md](./naming-and-intermediates.md) | Named values, pipeline clarity |
| [module-boundaries.md](./module-boundaries.md) | .mli files, type annotations, module structure |
| [pattern-matching.md](./pattern-matching.md) | Exhaustive matching, catch-all avoidance |
| [partial-functions.md](./partial-functions.md) | Total functions, banned partials |
| [type-safety.md](./type-safety.md) | Stringly-typed code, phantom types, encapsulation |
| [code-reuse.md](./code-reuse.md) | Record updates, deduplication, labelled args |
| [test-patterns.md](./test-patterns.md) | AST-based validation, test helpers |
| [abstractions.md](./abstractions.md) | Module design, parameter reduction, functors |
| [comments-and-documentation.md](./comments-and-documentation.md) | Comment succinctness, accuracy, no ephemeral references |
| [interface-documentation.md](./interface-documentation.md) | odoc markup in .mli: per-field record docs, @param/@return/@raise, supported tags |
| [atspi-e2e-testing.md](./atspi-e2e-testing.md) | AT-SPI E2E test structure, best practices |
| [ocaml-idioms.md](./ocaml-idioms.md) | ocamlformat, function design |

## AGENT QUICK REFERENCE

| Document | Purpose |
|----------|---------|
| [agent-summary.md](./agent-summary.md) | Compact digest of all guidelines above — agents read this instead of the full index |

## C FFI GUIDELINES

When writing or reviewing OCaml/C bindings, also consult:

| Document | Concerns Covered |
|----------|-----------------|
| [../../architecture/FFI_GUIDELINES.md](../../architecture/FFI_GUIDELINES.md) | GC safety (CAMLlocal), pointer wrapping, GValue memory, GClosure pattern, common pitfalls |

## Usage

MANDATORY: Load ALL the MANDATORY GUIDELINES from the index above.


## Available Libraries

Use these libraries. Only `containers` should be opened at global scope.

- containers
- re
- uutf
- uri
- uuseg
- yojson
- fmt
- xmlm
- fpath

## Priority Order

When guidelines conflict, prefer in this order:
1. Correctness (no bugs)
2. Type safety (catch errors at compile time)
3. Clarity (readable code)
4. Consistency (match surrounding code)
5. Brevity (less code when equally clear)
