# Agent Style Summary

Compact reference for all mandatory guidelines. Read this instead of the full index.
**Maintainers**: update this file whenever you change any guideline in this directory.

---

## Formatter

Run `ocamlformat` after every edit (`dune fmt` or `ocamlformat --inplace`).

## Allowed Libraries (open `containers` at global scope only)

`containers` · `re` · `uutf` · `uri` · `uuseg` · `yojson` · `fmt` · `xmlm` · `fpath`

---

## Nesting and Control Flow

- Max 2 levels of nesting. Use `let*`/`let+` from `Result.Syntax`/`Option.Syntax` to flatten chains.
- Exit early on failures (guard clauses first, happy path at top level).
- Extract complex logic into named helpers.

## Error Handling

- Prefer `Result` over exceptions for expected failures.
- Use `Option` for "found / not found"; use `Result` when there are multiple failure modes or callers need context.
- Errors must include context (what, why, where). No silent failures.
- Tests: use `Alcotest.fail` / `Helpers.expect_some` / `Helpers.assert_some` — never silent `None` matches.

## Naming and Intermediate Values

See [core-idioms.md](./core-idioms.md) for pipeline naming and predicate extraction rules.

- `snake_case` for variables/functions/types; `PascalCase` for modules.
- Boolean names must read naturally: `is_deprecated`, `has_methods`, `should_skip`.
- Full words; single letters only for well-known roles (`acc`, `i`, `f`).

## Module Boundaries

See [core-idioms.md](./core-idioms.md) for module extraction heuristics.

- Public modules must have `.mli` files. Abstract types hide implementation.
- 2+ parameters of the same type → use labeled arguments.
- One responsibility per module. Expose minimal interface.
- Document invariants in `.mli` comments.

## Pattern Matching

- No catch-all `_` that hides unhandled cases (compiler should catch additions).
- Catch-all only for intentionally grouped cases or open types like strings.
- Prefer pattern matching over if-else chains.
- Destructure fields in the pattern itself, not after matching.
- Use or-patterns for shared handling; avoid deeply nested `match`.

## Partial Functions — BANNED

| Banned | Use Instead |
|--------|-------------|
| `List.hd` / `List.tl` | pattern match |
| `List.nth` | `List.nth_opt` |
| `Map.find` / `Hashtbl.find` | `*_opt` variants |
| `int_of_string` / `float_of_string` | `*_opt` variants |
| `Option.get` | `Option.value ~default:` or pattern match |
| `Stdlib.(=)` | `String.equal`, `Int.equal`, etc. |

Intentional partial functions must have `_exn` suffix.

## Type Safety

- No stringly-typed code: use variants/ADTs instead of string comparisons.
- Distinct string identifiers → phantom types to prevent confusion.
- Data with invariants → smart constructors that return `Result`.
- Public module types must be abstract in `.mli`.

## Code Reuse

- Use `{ record with field = v }` for record updates, never manual reconstruction.
- Duplicate logic in 3+ places → extract to a shared module.
- Helpers must be used more than once; don't over-abstract.
- Higher-order functions over copy-paste with variations.

## OCaml Idioms

See [core-idioms.md](./core-idioms.md) for bind operators vs pipelines, polymorphic equality ban, and module extraction heuristics.

- Labeled args when 2+ params have the same type or unclear position.
- Parameter order: most-general first.

## Abstractions

See [core-idioms.md](./core-idioms.md) for module extraction heuristics.

- 3+ same parameters passed to 3+ functions → context record.
- Maintain clear dependency direction (application → generation → infrastructure → parsing).
- Functors for the same algorithm with different types.

## Comments and Documentation

- Comment only the WHY (hidden constraint, subtle invariant, external workaround).
- Never describe WHAT the code does.
- No ephemeral references (no stage/phase/sprint/ticket mentions in comments).
- Keep comments up to date when modifying code.

### Interface (.mli) documentation

See [interface-documentation.md](./interface-documentation.md) for the full
rules. Key points:

- Every `val`/`type`/`module` in an `.mli` has a summary-line doc comment.
- Record fields are documented **inline per field**, not in a record-level
  prose paragraph. Same for variant constructors.
- `@raise` is mandatory for any value that can raise.
- `@param`/`@return` are used consistently within a module — not on a random
  subset of values. The tag is `@return`, not `@returns`.
- No `(** ... *)` attached to anonymous positional argument types in a `val`.
- No invented tags — use only the odoc/ocamldoc-supported set.

## Test Patterns

- **AST-based validation is mandatory** — no string matching on generated code structure.
- Use `Ml_ast_helpers.parse_implementation` / `parse_interface` then `Ml_validation.*`.
- Use `Helpers.expect_some` / `Helpers.assert_some` for option results.
- Test names: describe what is tested, the condition, and the expected outcome.
- Structure: Arrange → Act → Assert.
- Before writing test helpers: read `ml_validation.ml`, `ml_ast_helpers.ml`, `helpers.ml` in full.

## C FFI (when writing OCaml/C bindings)

Read `architecture/FFI_GUIDELINES.md` in full. Key rules:
- Use `CAMLparam`/`CAMLlocal`/`CAMLreturn` macros — never skip.
- Free all allocated resources; no raw GC-unsafe pointers.
- Follow [FFI Guidelines](../../architecture/FFI_GUIDELINES.md) for input validation at FFI boundaries.
