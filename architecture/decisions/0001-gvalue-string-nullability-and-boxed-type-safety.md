# ADR 0001: GValue string nullability and boxed getter type safety

- **Status**: Proposed
- **Date**: 2025
- **Scope**: `ocgtk/src/common/{gobject.ml,gobject.mli,ml_gobject.c}`, `gir_gen/lib/generate/signal_marshaller.ml`, `ocgtk/tests/gtk/test_gvalue_safety.ml`

## Context

Two related safety gaps in the `Gobject.Value` runtime API were found by
comparing ocgtk against PyGObject, Rust gtk-rs/glib, and grust.

### 1. GValue strings are nullable; ocgtk collapses NULL to `""`

`g_value_get_string` is nullable in GLib (`const gchar*`, may be `NULL` for an
unset string property). Other bindings surface this:

- **PyGObject**: `Value.get_string() -> str | None`; `set_string(str | None)`.
- **gtk-rs / glib**: `String` is `ValueTypeOptional`. `Value::get::<String>()`
  returns `Err(UnexpectedNone)` on NULL; `Value::get::<Option<String>>()`
  returns `Ok(None)`. `ToValueOptional for str` writes NULL for `None`.
- **grust**: `get_string() -> Option<&CStr>`.

ocgtk instead maps NULL to `""` (`ml_gobject.c:311`, `ml_g_value_get_string`):
the C stub does `caml_copy_string(str == NULL ? "" : str)`. The OCaml surface is
`get_string : t -> string` / `set_string : t -> string -> unit`, both
non-nullable. The `.mli` documents this as deliberate: "generated bindings
declare string parameters non-nullable."

That rationale is only *enforced* by the signal marshaller's
`primitive_marshallers` table (`signal_marshaller.ml:63-75`), which hardcodes the
OCaml type `string` for `utf8`/`filename`/`gchararray`/`gchar*`/`const gchar*`
and ignores `gir_type.nullable` — unlike `classify_gobject` (lines ~205-224),
which honors `nullable` for objects and emits `t option` vs bare `t`. So a
nullable string signal argument or return is silently represented as `string`
with NULL flattened to `""`, losing the unset/empty distinction (real for
properties like `Gtk.Label:label` and for nullable string returns).

The **property path is already nullable-correct**: generated property getters
emit `prop_value = g_value_get_string(&prop_gvalue)` into a `const char*` and
wrap via `C_stub_helpers.nullable_c_to_ml_expr`, which produces
`caml_copy_string(prop_value)` for non-nullable and `Val_option_string(prop_value)`
for nullable (`c_stub_helpers.ml:318`). So this decision touches only the
`Gobject.Value` runtime API and the signal marshaller, not property generation.

### 2. `get_boxed` is unchecked; `set_boxed` already validates

`set_boxed` (`ml_gobject.c:597`) is already strongly typed at runtime: it pulls
the record's GType via `ml_gir_record_gtype_val`, checks `G_TYPE_IS_BOXED` and
`g_type_is_a(rec_type, val_type)`, and raises `Invalid_argument` naming both
types. This is stronger than PyGObject (which only warns on non-boxed).

`get_boxed` (`ml_gobject.c:550`) only checks `G_VALUE_HOLDS_BOXED` and non-NULL,
then returns `'a obj` for call-site ascription: `(Value.get_boxed v : Rectangle.t)`.
The gir_record custom block **does** carry the captured GType (`box->type` in
`wrappers.c`), so the information to validate exists, but the getter does not
use it. The phantom type `` [`rectangle] Gobject.obj `` vs
`` [`tree_iter] Gobject.obj `` has no runtime tag, so the OCaml type system
cannot stop mis-ascription: `(Value.get_boxed v : Tree_iter.t)` when `v` holds a
`GdkRectangle` returns a mis-typed block whose finalizer will run a foreign
`g_boxed_free` — the exact memory-corruption hazard `set_boxed` was written to
prevent.

Other bindings close this gap by carrying the GType on the type token:
gtk-rs runs `T::Checker::check()` → `g_type_check_value_holds(value,
T::static_type())`; grust does `debug_assert!(self.value_type() ==
boxed::type_of::<T>())`.

No generated code currently calls `Gobject.Value.get_boxed` — boxed record
signal args are `Unsupported "boxed type ... not yet supported"` in
`signal_marshaller.ml` `classify`, and property getters use `g_value_get_boxed`
directly in C. So the blast radius of changing the getter is the runtime API,
hand-written callers, and tests.

## Decision

### Decision 1: Make `Gobject.Value` strings nullable-aware

Adopt the existing `get_object` / `get_object_exn` + `set_object` /
`set_object_exn` pattern (in `gobject.ml`) for strings:

- `get_string : t -> string option` — `NULL` maps to `None`, else `Some s`.
- `get_string_exn : t -> string` — raises `Failure` on NULL (surfaces a
  contract violation for non-nullable GIR args instead of silently returning
  `""`). This replaces the current NULL→`""` mapping.
- `set_string : t -> string option -> unit` — `None` writes `NULL` via
  `g_value_set_string(gv, NULL)`.
- `set_string_exn : t -> string -> unit` — current behavior (writes the string).

All four keep the existing `G_VALUE_HOLDS_STRING` → `Invalid_argument` check.

C stubs (`ml_gobject.c`): implement the two getters and two setters. The
option getter uses `caml_alloc_small(0, 0)`/`Val_some` (or the project's
existing option idiom — check `Val_option`/`ml_some` usage in the file and
match it). The option setter uses `Is_none`/`String_val(Field(...,0))`.

**Signal marshaller** (`signal_marshaller.ml`): move the string entries
(`utf8`, `filename`, `gchararray`, `gchar*`, `const gchar*`) out of the static
`primitive_marshallers` table into an explicit `classify_string ~gir_type`
helper that branches on `gir_type.nullable`, mirroring `classify_gobject`:

- nullable → `ocaml_type = "string option"`, getter =
  `"Gobject.Value.get_string v"`, setter = `"Gobject.Value.set_string v x"`,
  `nullable = true`.
- non-nullable → `ocaml_type = "string"`, getter =
  `"Gobject.Value.get_string_exn v"`, setter =
  `"Gobject.Value.set_string_exn v x"`, `nullable = false`.

Wire `classify_string` into `classify` ahead of the `primitive_marshallers`
lookup (next to the `is_glib_variant` / `is_gobject_value` special cases).
Preserve the existing `is_string_type` helper's notion of which GIR names count
as strings; reuse it so the two lists cannot drift.

**Property generation is unchanged** — it already handles nullable strings
correctly via `Val_option_string`.

### Decision 2: Add a GType-validated boxed getter

Add to `Gobject.Value`:

- `get_boxed_checked : t -> g_type -> 'a obj` — validates that the GValue's
  `G_VALUE_TYPE` is a boxed type and that the *expected* GType passed by the
  caller is a supertype relationship: `g_type_is_a(G_VALUE_TYPE gv, expected)`
  (a GValue holding a derived boxed type is acceptable for a base-type
  request, matching `set_boxed`'s `g_type_is_a(rec_type, val_type)` direction).
  Raises `Invalid_argument` naming both the actual and expected types on
  mismatch, and on a non-boxed GValue. On success returns the gir_record block
  exactly as `get_boxed` does today.
- Keep `get_boxed : t -> 'a obj` as the unchecked ascription form, but update
  its `.mli` comment to cross-reference `get_boxed_checked` and state that the
  caller is responsible for the ascription (the unchecked form remains for
  ergonomics and existing tests).

C stub (`ml_gobject.c`): `ml_g_value_get_boxed_checked(value val, value
expected_type)` — extract `expected = Long_val(expected_type)` (or however
`g_type` is marshalled — match `ml_g_value_init_gtype` / `Type.to_int`), reuse
the `G_TYPE_VALUE` unwrap, check `G_VALUE_HOLDS_BOXED`, then
`g_type_is_a(G_VALUE_TYPE(gv), expected)`, then the existing `g_boxed_copy` +
`ml_gir_record_val_ptr_with_type` path.

No generated code changes for Decision 2 (no generated caller yet); this is a
runtime API + tests change only.

## Consequences

- **Breaking change** to `Gobject.Value.get_string` / `set_string` signatures.
  The only generated consumer is the signal marshaller, updated in lockstep.
  Hand-written callers (tests) must be updated: the `NULL→""` test in
  `test_gvalue_safety.ml` (`test_get_string_maps_null_to_empty`) becomes a
  `None` assertion against `get_string`, and `get_string_exn` is added to the
  round-trip coverage.
- Nullable string signal args/returns now surface as `string option`,
  eliminating the silent unset/empty conflation. Non-nullable string args use
  `get_string_exn`, which raises on a NULL that violates the GIR contract
  instead of returning `""`.
- `get_boxed_checked` gives hand-written and future generated callers a way
  to validate the boxed GType at the boundary, closing the asymmetry with
  `set_boxed`. The unchecked `get_boxed` remains for the ascription idiom but is
  now documented as the caller's responsibility.
- Tests added: `get_string` returns `None` on a NULL property;
  `get_string_exn` raises on a NULL property; `set_string None` writes NULL
  (round-trips to `get_string = None`); `get_boxed_checked` accepts a matching
  GType and rejects a mismatched one with `Invalid_argument`; `get_boxed_checked`
  rejects a non-boxed GValue.

## Verification

```
opam exec -- dune build @all
opam exec -- dune test gir_gen/
xvfb-run opam exec -- dune test ocgtk/
```

The string and boxed tests live in `ocgtk/tests/gtk/test_gvalue_safety.ml`.
Regenerate any generated signal marshaller output the build expects promoted
(`opam exec -- dune promote` if promoted files diverge).