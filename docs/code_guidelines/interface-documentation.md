# Interface Documentation (.mli) Guidelines

These rules govern odoc/ocamldoc markup in `.mli` files. They exist because the
project has deliberately **not** adopted merlint's E4xx documentation rules (see
`merlint.toml`), so documentation consistency is a written convention, not a
lint gate. Follow it when writing or reviewing any `.mli`.

> **Priority**: a correct, readable summary line always beats mechanically
> generated tags. When this guideline and a terse summary conflict, prefer the
> summary — but keep the conventions below for records, fields, and exceptions.

---

## 1. Every public value gets a summary line

Every `val`, `type`, `module`, and `module type` in an `.mli` has a `(** ... *)`
doc comment whose first line is a single sentence starting with an imperative
verb or a `[name args]` call sketch.

```ocaml
val lookup_class :
  classes:Types.gir_class list -> lookup_str:string -> Types.gir_class option
(** [lookup_class ~classes ~lookup_str] finds the class whose GIR name or C
    type matches [lookup_str], or returns [None]. *)
```

The `[f ~x ~y] ...` call-sketch style is the **default** for functions; it
reads naturally and renders identically under odoc and ocamlldoc.

---

## 2. Records: document each field, not the record

Field documentation goes **inline on each field**, not in a prose paragraph
attached to the record. odoc renders per-field comments as the field's
documentation; a record-level paragraph that names fields in prose does not, and
it drifts as fields are added or removed.

### Bad — fields described only in the record comment
```ocaml
type property_gvalue_info = {
  base_type : string;
  base_lower : string;
  has_pointer : bool;
  pointer_like : bool;
  record_info : (Types.gir_record * bool * bool) option;
  class_info : Types.gir_class option;
  is_enum : bool;
  is_bitfield : bool;
  stack_allocated : bool;
}
(** Result of analyzing a property's GIR type. [base_type] is the C type with
    any trailing pointer stripped; [base_lower] is the lowercased GIR type name;
    [has_pointer] reports ...; [pointer_like] is true when ...; [record_info]
    and [class_info] hold ...; [is_enum] / [is_bitfield] report ...;
    [stack_allocated] is true when ... *)
```

### Good — one comment per field
```ocaml
type property_gvalue_info = {
  base_type : string;
      (** C type with any trailing pointer stripped. *)
  base_lower : string;
      (** Lowercased GIR type name. *)
  has_pointer : bool;
      (** Whether the C type carries a pointer suffix. *)
  pointer_like : bool;
      (** True for pointers and known pointer builtins ([gpointer],
          [gconstpointer]). *)
  record_info : (Types.gir_record * bool * bool) option;
      (** Resolved record, whether the lookup was a pointer type, and whether
          the record is boxed, when the type names a record. *)
  class_info : Types.gir_class option;
      (** Resolved class, when the type names a class. *)
  is_enum : bool;  (** Whether the GIR type is an enum. *)
  is_bitfield : bool;  (** Whether the GIR type is a bitfield. *)
  stack_allocated : bool;
      (** True when the value can live on the C stack (enums, bitfields,
          non-pointer builtins). *)
}
(** Result of analyzing a property's GIR type, used to drive GValue
    conversion. *)
```

The record-level comment then states only the **purpose** of the record as a
whole; it does not restate each field.

### Variants

Apply the same rule to variant constructors: document each constructor inline.

```ocaml
type transfer_strategy =
  | Ts_none
      (** No special ownership action: primitives, strings, enums, bitfields. *)
  | Ts_gobject
      (** GObject class/interface: emit [g_object_ref_sink] for transfer-none. *)
  | Ts_boxed of string
      (** Boxed type: emit [g_boxed_copy(<get_type>(), result)]. The argument
          is the C get-type function name. *)
  | Ts_gvariant
      (** [GVariant]: emit [g_variant_ref] for transfer-none returns. *)
```

---

## 3. `@param` / `@return` / `@raise`: when to use them

The call-sketch summary (§1) is the default. Use the odoc tags below **when the
summary cannot carry the meaning cleanly** — typically: many parameters,
non-obvious return semantics, or documented failure modes.

| Tag | Use it when | Notes |
|-----|-------------|-------|
| `@param label desc` | A labelled or positional parameter needs more than the summary conveys; or the function has 3+ parameters worth documenting individually. | For **unlabelled positional** args, odoc has no way to attach `@param` by position — either name the arg (add a label) or describe it in the summary. Do **not** write `@param` for positional args with a guessed name. |
| `@return desc` | The return value's shape/semantics are non-obvious (e.g. a tuple/record of several values, conditional meaning). | The tag is `@return`, **not** `@returns`. |
| `@raise Exn desc` | The function can raise. **Mandatory** whenever a `raise`/`failwith`/`Invalid_argument` path is reachable from the public signature. | State the condition, not just the exception name. |
| `@since ver` | The value was introduced in a specific version. | Optional; use when versioning is meaningful. |
| `@deprecated msg` | The value is deprecated and a replacement exists. | Name the replacement. |
| `@before ver desc` | Behaviour changed at `ver`; describe the old behaviour. | Rare. |
| `@see <uri> desc` / `@see "doc" desc` / `@see 'file' desc` | External reference (URL, document, or file path). | Use sparingly. |
| `@author` / `@version` | Module-level authorship. | Rare in this project. |

**Do not** mix the two styles within one module: pick the call-sketch style for
the common case and add `@param`/`@return`/`@raise` tags to the few values that
need them, rather than tagging some values and not others arbitrarily.

### Inline markup supported by odoc/ocamldob

- `[code]` — inline code.
- `{e text}` — emphasis; `{b text}` — bold.
- `{[ ... ]}` — a code block.
- `{1 Title}` / `{2 Subtitle}` — section headings (place above a block of
  related `val`s, not on every value).
- `@param`, `@return`, `@raise`, `@since`, `@deprecated`, `@before`, `@see`,
  `@author`, `@version` — as above.

Do not invent tags odoc does not support (e.g. `@returns`, `@throws`,
`@param foo,bar`). They render as literal text.

---

## 4. Do not attach `(** ... *)` to anonymous positional arg types

In a `val` signature, a `(** ... *)` immediately after an **unnamed positional**
argument's type is attached by odoc to the type expression, not to a parameter.
It does not render as parameter documentation and is misleading.

### Bad
```ocaml
val build_return_statement :
  throws:bool ->
  string option (** Primary return value expression *) ->
  string list (** Out parameter conversions *) ->
  string
```

### Good — name the args, then document them
```ocaml
val build_return_statement :
  throws:bool ->
  return_expr:string option ->
  out_conversions:string list ->
  string
(** [build_return_statement ~throws ~return_expr ~out_conversions] builds the
    C [return] statement. [return_expr] is the primary return value; none when
    the method returns unit. [out_conversions] are the out-parameter conversion
    statements to thread through the return. *)
```

If the args cannot be labelled (e.g. they're genuinely positional), describe
them in the summary by position instead.

---

## 5. Section headings group related declarations

Use `{1 ...}` / `{2 ...}` to group a block of related `val`s or `type`s in a
large `.mli`. A heading is not required on every value; use it when the
interface has clear subsections (e.g. "Factories", "Queries", "C AST Types").

---

## 6. Review checklist for `.mli` files

- [ ] Every `val`, `type`, `module`, `module type` has a summary-line doc
      comment.
- [ ] Every record field has an inline `(** ... *)`; the record-level comment
      states only the record's purpose.
- [ ] Every variant constructor that is not self-evident has an inline comment.
- [ ] `@raise` is present for every value that can raise.
- [ ] `@param`/`@return` are used consistently within a module (not on a random
      subset of values).
- [ ] No `(** ... *)` attached to anonymous positional argument types.
- [ ] No invented tags (`@returns`, `@throws`, ...).
- [ ] Documentation still matches the implementation after edits.