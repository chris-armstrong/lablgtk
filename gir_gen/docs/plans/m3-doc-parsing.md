# M3 Doc Parsing Plan — capture `<doc>` and related GIR elements into the AST

**Status: DRAFT**
**Created: 2026-09-08**
**Branch: `feat/m3-doc-parsing`** (from `docs/m3-reference-documentation-prd`)

## Overview

First leg of Milestone 3 (reference documentation). Scope is **parsing
only**: extend the GIR parser and AST so that every doc-carrying element and
attribute the [M3 design PRD](../research/reference-documentation.md)
requires is captured. No odoc translation, no emission changes — generated
bindings must remain byte-identical.

The PRD sections this plan services:

- §3.1 `<doc>` text capture (parser already uses `Xmlm` `Data` accumulation)
- §3.2 `<doc:format>` (parsed for diagnostics only, **not** a dispatch key)
- §3.6 `<doc-deprecated>` + `deprecated` / `deprecated-version` attributes
- §3.7 parameter / return-value `<doc>` (feed the `@param` / `@return` mapping)

## Gap analysis (audited against `gir_gen/lib/parse/gir_parser.ml` + `types.ml`)

| Item | Status today | This plan |
|---|---|---|
| `<doc>` on method / ctor / signal / function | ✅ captured | keep |
| `<doc>` on constant | ✅ `constant_doc` | keep |
| `<doc>` on record, record fields, enum/bitfield **members** | ✅ captured | keep |
| `<doc>` on **class** | ❌ `class_doc = None` hardcoded, no dispatch arm | capture |
| `<doc>` on **interface** | ❌ `interface_doc = None` hardcoded | capture |
| `<doc>` on **property** | ❌ text consumed then discarded, `prop_doc = None` (PRD §12 flags this) | capture |
| `<doc>` on **enum / bitfield themselves** | ❌ `enum_doc` / `bitfield_doc` exist but never set | capture |
| `<doc>` on **`<parameter>`** | ❌ not parsed; `gir_param` has no doc field | capture → `param_doc` |
| `<doc>` on **`<return-value>`** | ❌ not parsed; no field anywhere | capture → `return_doc` |
| **`<doc-deprecated>`** element | ❌ silently skipped everywhere (fold default) | capture on every doc-bearing node |
| **`deprecated` / `deprecated-version` attrs** | ❌ on no AST node (only `version` is captured) | capture |
| **`<doc:format>`** | ❌ skipped | capture `name` into `gir_repository` |
| **Stability attr** | ❌ | **defer** — zero corpus hits, spelling unverified (PRD §3.10, Q14) |
| **`<docsection>`** (Graphene ×2) | ❌ skipped | **defer** — belongs to `index.mld` planning (PRD §6.6) |
| Top-level namespace `<function>` | ❌ never parsed (`bin/gir_gen.ml:1069` documents this) | out of scope; noted for `[func@]` resolution later |

Confirmed non-issues:

- Unknown children (incl. `<doc-deprecated>` today) are safely skipped by
  `Gir_xml_fold.fold_element`'s default arm.
- `<doc:format>` lives in the `http://www.gtk.org/introspection/doc/1.0`
  namespace; dispatch keys on the `(uri, "format")` pair via the existing
  `ctx` namespace resolution.
- Doc text extraction is inconsistent: `element_data` (which `failwith`s on
  nested elements) is used in `fold_callable_body`, `parse_function`, and
  `parse_record`/`parse_property`, while `parse_doc_text` (robust, skips
  stray markup) is used for constants and members. The corpus has zero
  nested elements inside `<doc>` (PRD §3.1), so both behave identically
  today; unify on `parse_doc_text` as the PRD blesses.

## Design decisions

1. **Nested deprecation record** (decided). One semantic bundle added as a
   single field per entity, capping the per-type diff:

   ```ocaml
   type gir_deprecation = {
     deprecated : bool;
     deprecated_version : string option;
     deprecated_doc : string option; (* <doc-deprecated> prose *)
   }
   ```

   Carried as `deprecation : gir_deprecation option` on the entity types
   below. The `None`/`Some _` distinction keeps "not deprecated" from
   allocating noise and gives emitters one optional to match on.

2. **Where the fields land** (`gir_gen/lib/types.ml`):

   | Type | New/changed fields |
   |---|---|
   | `gir_param` | `+ param_doc : string option` |
   | `gir_method` | `+ return_doc : string option`, `+ deprecation` |
   | `gir_function` | `+ return_doc : string option`, `+ deprecation` |
   | `gir_signal` | `+ return_doc : string option`, `+ deprecation` |
   | `gir_constructor` | `+ deprecation` (constructors have no return doc) |
   | `gir_class`, `gir_interface`, `gir_record` | `+ deprecation`; class/interface docs now actually populated |
   | `gir_property` | `prop_doc` now populated; `+ deprecation` |
   | `gir_enum`, `gir_bitfield` | `enum_doc` / `bitfield_doc` now populated; `+ deprecation` |
   | `gir_enum_member`, `gir_bitfield_member` | `+ deprecation` |
   | `gir_constant` | `+ deprecation` |
   | `gir_record_field` | `+ deprecation` |
   | `entity` (unified view) | `+ deprecation`, threaded through `entity_of_class` / `_interface` / `_record` |
   | `gir_repository` | `+ repository_doc_format : string option` |

3. **Return-value docs** live on the callable, not the type:
   `return_doc : string option` on `gir_method`, `gir_function`,
   `gir_signal`.

4. **Params**: `gir_param.param_doc` also feeds the PRD §9 name-match gate
   for `@param` tags later. `<instance-parameter>` remains skipped.

5. **`<doc:format>`** goes on `gir_repository` (it is a repository-level
   element). Diagnostics only — never a translator dispatch key (PRD §3.2).

6. **Byte-identical output invariant**: no generator consumes the new
   fields in this leg. Verified by regenerating bindings and diffing
   (steps 2 and 3 below must both preserve this).

## Implementation steps

### Step 1 — AST extension + `<doc>` gap closure (one PR)

`gir_gen/lib/types.ml`:

- Add `gir_deprecation` and the fields from decision 2 (all `None`/`false`
  defaults at construction sites).
- Thread `deprecation` through the three `entity_of_*` builders.

`gir_gen/lib/parse/gir_parser.ml`:

- Unified doc extraction: replace the remaining `element_data` doc reads
  (`fold_callable_body`, `parse_function`, `parse_record`'s `"doc"` arm,
  `parse_property`'s discard) with `parse_doc_text`.
- Add `"doc"` dispatch arms where missing:
  - `parse_class` and `parse_interface` (new `cc_doc` accumulator in
    `class_contents`, or a post-fold record update) → `class_doc` /
    `interface_doc`.
  - `parse_property` → `prop_doc`.
  - `parse_enumeration`, `parse_bitfield` → `enum_doc` / `bitfield_doc`.
- `parse_parameter_type`'s fold gains a `"doc"` arm → `param_doc`.
- Return-value docs: `parse_return_value` and `parse_function`'s
  return-value arm are currently `leaf`-based (attributes only, children
  skipped); convert to folds that also accept a `"doc"` child →
  `return_doc` on methods/functions/signals (via `fold_callable_body`,
  which becomes a 4-tuple: return_type, params, doc, return_doc).
- Compile fallout: all record-construction sites (parser, generators, test
  factories) gain the new fields explicitly.

**Acceptance:** `dune build @all` clean; regenerated bindings
byte-identical to pre-change output (diff a regenerated namespace).

### Step 2 — `<doc-deprecated>`, deprecation attributes, `<doc:format>` (one PR)

- Shared helper in the parser capturing the doc pair — one `"doc"` /
  `"doc-deprecated"` arm pair reused at every site, returning
  `(doc, deprecated_doc)`.
- Attribute capture at every attribute-reading site: `deprecated`
  (`Utils.parse_bool`) + `deprecated-version` → `gir_deprecation`, on
  class, interface, record, method, virtual-method, constructor, property,
  signal, function, enum, bitfield, enum/bitfield member, constant, field
  (superset per PRD Q6; the corpus carries them on most of these).
- `parse_repository`: dispatch arm for
  `("http://www.gtk.org/introspection/doc/1.0", "format")` reading the
  `name` attribute → `repository_doc_format`.

**Acceptance:** same byte-identical invariant; corpus spot checks below
pass.

### Step 3 — Tests (one PR)

New `gir_gen/test/interface/doc_parsing_tests.ml`, registered in
`gir_gen/test/dune`, following `parsing_tests.ml` conventions
(`Helpers.wrap_namespace` for synthetic XML + real `Gtk-4.0.gir`):

Synthetic XML cases:

- class / interface / enum / bitfield / property entity `<doc>` capture.
- parameter `<doc>` → `param_doc`; return-value `<doc>` → `return_doc`.
- `<doc-deprecated>` + `deprecated="1"` + `deprecated-version="4.10"` →
  `Some { deprecated = true; deprecated_version = Some "4.10";
  deprecated_doc = Some … }`.
- `<doc:format name="gi-docgen">` → `repository_doc_format`.
- A `<doc>` containing no text → `None` (existing `parse_doc_text`
  behaviour).

Real-GIR spot checks (anchors measured in the PRD):

- `Gtk.Button` `class_doc` is non-empty.
- `Gtk.Calendar` class: `deprecated_version = Some "4.10"`, deprecated doc
  mentions `set_date` (PRD §3.6 real example).
- `Gtk.Orientable` property `orientation` has `prop_doc`.
- An enum-level and bitfield-level doc are populated (e.g. from
  `Gtk-4.0.gir`).
- `doc:format` per namespace matches the PRD §3.2 table across all nine
  `gir/*.gir` files: Gtk/Gio/Gdk/Pango/Gsk/PangoCairo = `gi-docgen`,
  Graphene/GdkPixbuf = `unknown`, cairo = absent (`None`).

## Verification (every step)

```bash
opam exec -- dune build @all
opam exec -- dune test gir_gen/ && xvfb-run $(which dune) test ocgtk/
# plus: regenerate bindings for a namespace and diff — must be empty
```

Read build/test output in full (no `head`/`grep` truncation).

## Explicitly out of scope (later M3 legs)

- The §6 gi-docgen-markdown → odoc translator.
- The §7 cross-reference resolver (incl. `.refs` indices).
- The §11 page model / emission into `.mli` files; synthetic synopses (§12).
- `Stability` attribute capture (zero corpus hits; spelling unverified).
- `<docsection>` capture (Graphene ×2; part of `index.mld` planning).
- Top-level namespace `<function>` parsing (separate gap; `[func@]`
  fallbacks per PRD §7 until then).
- Any change to emitted bindings or C stubs.
