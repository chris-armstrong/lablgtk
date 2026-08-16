# Interface Documentation (.mli) Guidelines

These rules govern odoc/ocamldoc markup in `.mli` files. The project has
deliberately **not** adopted merlint's E4xx documentation rules (see
`merlint.toml`), so documentation consistency is a written convention, not a
lint gate. Follow it when writing or reviewing any `.mli`.

> **Priority**: a correct, readable summary line always beats mechanically
> generated tags. When a rule and a terse summary conflict, prefer the
> summary — but keep the conventions below for records, fields, and
> exceptions.

---

## 1. Every public value gets a prose summary line

Every `val`, `type`, `module`, and `module type` in an `.mli` has a `(** ... *)`
doc comment whose first line is a single sentence starting with an imperative
verb or a `[name args]` call sketch.

```ocaml
val lookup_class :
  classes:Types.gir_class list -> lookup_str:string -> Types.gir_class option
(** [lookup_class ~classes ~lookup_str] finds the class whose GIR name or C
    type matches [lookup_str], or returns [None]. *)
```

The `[f ~x ~y] ...` call-sketch style is the **house style** for functions:
fold every parameter and the return value into the prose. Do **not** use
odoc `@param` or `@return` tags — they are not used anywhere in this project;
prose carries the meaning. (Existing `@param`/`@return` blocks should be
removed when a module is touched.)

---

## 2. Records: document each field, not the record

Field documentation goes **inline on each field**, not in a prose paragraph
attached to the record. odoc renders per-field comments as the field's own
documentation; a record-level paragraph that names fields in prose does not,
and it drifts as fields are added or removed.

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

## 3. `@raise` is mandatory when a value can raise

`@raise Exn desc` is the **only** odoc tag routinely used in this project, and
it is **mandatory** whenever a `raise`/`failwith`/`Invalid_argument` path is
reachable from the public signature. State the condition, not just the
exception name.

```ocaml
val lookup_record : ctx:Types.generation_context -> string -> Types.gir_record
(** [lookup_record ~ctx name] returns the record named [name].

    @raise Not_found when no record with that name exists in [ctx]. *)
```

Do not invent tags odoc does not support (e.g. `@returns`, `@throws`,
`@param foo,bar`). They render as literal text.

---

## 4. Do not attach `(** ... *)` to anonymous positional arg types

In a `val` signature, a `(** ... *)` immediately after an **unnamed positional**
argument's type is attached by odoc to the type expression, not to a
parameter — it does not render as parameter documentation and is misleading.

### Bad
```ocaml
val build_return_statement :
  throws:bool ->
  string option (** Primary return value expression *) ->
  string list (** Out parameter conversions *) ->
  string
```

### Good — name the args, then document them in the prose
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

## 6. Inline markup

odoc/ocamldoc supports:

- `[code]` — inline code.
- `{e text}` — emphasis; `{b text}` — bold.
- `{[ ... ]}` — a code block.
- `{1 Title}` / `{2 Subtitle}` — section headings (place above a block of
  related `val`s, not on every value).
- `@raise`, `@since`, `@deprecated`, `@before`, `@see`, `@author`, `@version` —
  as needed (see §3 for `@raise`).

---

## 7. Review checklist for `.mli` files

- [ ] Every `val`, `type`, `module`, `module type` has a prose summary-line
      doc comment.
- [ ] No `@param` or `@return` tags (fold into the prose summary).
- [ ] Every record field has an inline `(** ... *)`; the record-level comment
      states only the record's purpose.
- [ ] Every variant constructor that is not self-evident has an inline comment.
- [ ] `@raise` is present for every value that can raise.
- [ ] No `(** ... *)` attached to anonymous positional argument types.
- [ ] No invented tags (`@returns`, `@throws`, ...).
- [ ] Documentation still matches the implementation after edits.