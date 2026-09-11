# FFI Guidelines

## Canonical FFI Paths

Every OCaml-visible FFI value in ocgtk falls into one of seven Custom-block
kinds, each identified by a stable `struct custom_operations` pointer.  The
table below is the authoritative reference; use it when writing new bindings
or reading existing ones.

| Kind | ops struct (extern) | identifier | Allocator | Reader |
|------|---------------------|------------|-----------|--------|
| GObject | `ocgtk_gobject_ops` | `"ocgtk.gobject"` | `ml_gobject_val_of_ext` | `ml_gobject_ext_of_val` (or per-class `<X>_val` macros from generated `<ns>_decls.h`) |
| GIR record (opaque or boxed) | `ocgtk_gir_record_ops` | `"ocgtk.gir_record"` | `ml_gir_record_val_ptr` / `ml_gir_record_val_ptr_with_type` | `ml_gir_record_ptr_val(v, "<TypeName>")` (or per-record `<X>_val` macros) |
| GVariant | `ocgtk_gvariant_ops` | `"ocgtk.gvariant"` | `Val_GVariant` | `GVariant_val` |
| GVariantType | `ocgtk_gvariant_type_ops` | `"ocgtk.gvariant_type"` | `Val_GVariantType` | `GVariantType_val` |
| GBytes | `ocgtk_gbytes_ops` | `"ocgtk.gbytes"` | `Val_GBytes` | `GBytes_val` |
| GValue | `ocgtk_gvalue_ops` | `"ocgtk.gvalue"` | (internal — `GObject.Value` module) | `GValue_val` |
| GClosure | `ocgtk_gclosure_ops` | `"ocgtk.gclosure"` | (internal — signal infrastructure) | `GClosure_val` |

All seven `extern struct custom_operations ocgtk_<kind>_ops` declarations are
in `ocgtk/src/common/value_kinds.h`.  Include that header to access them.

## The Registry and `ocgtk_classify`

`ocgtk/src/common/value_kinds.h` exposes the seven extern `custom_operations`
structs described above, along with the `ocgtk_kind` enum and the
`ocgtk_classify(value v) -> ocgtk_kind` function (implemented in
`ocgtk/src/common/wrappers.c`).  `ocgtk_classify` is the canonical way to ask
"what kind of FFI value am I holding?" at dynamic-dispatch sites — for example
signal marshallers and `GValue`↔OCaml decoders.

**Pointer comparison is preferred** over identifier-string comparison:

```c
/* Preferred — single pointer load, no strcmp */
if (Custom_ops_val(v) == &ocgtk_gobject_ops) { ... }

/* Also available — but slower and unnecessary in this codebase */
if (strcmp(Custom_ops_val(v)->identifier, "ocgtk.gobject") == 0) { ... }
```

Pointer comparison is faster, it is stronger (it proves the value came through
the same translation-unit chain as the ops struct definition), and ocgtk has no
dynamic loading where string comparison would be safer.

The `OCGTK_ASSERT_OPS(v, ops_ptr)` macro (defined in `value_kinds.h`) is
provided for asserting accessors.  In `NDEBUG` builds it compiles away; the
load is a single pointer comparison.

## FFI History — Retired Abstractions

The following helpers have been deleted from the codebase.  Do not reintroduce
them.

**`val_of_ext` / `ext_of_val`** (1-field Abstract block, payload at
`Data_abstract_val`) — retired in **Phase 6** of the value-kinds-registry plan.
Their two remaining callers were inlined into their respective translation units:

- `Val_lookup_info` / `Lookup_info_val` replaced by `static inline
  val_lookup_info` / `lookup_info_val` in `wrappers.c` (TU-internal, used by
  `ml_lookup_from_c` and `ml_lookup_to_c`).
- `Val_GMainLoop` / `GMainLoop_val` in `ml_glib.c` migrated to direct
  `caml_alloc(1, Abstract_tag)` + `Data_abstract_val` reads, with writer and
  reader now consistent (the old reader incorrectly used `Field(val, 0)`).

**`Val_pointer` / `Pointer_val`** (2-field Abstract block, payload at field 1)
— a separate, incompatible Abstract-block layout — **was deleted in Phase 0a**
of the value-kinds-registry plan.  The two Abstract-block layouts (1-field and
2-field) are NOT interchangeable, and neither is compatible with Custom blocks.
Do not reintroduce `Val_pointer` / `Pointer_val`.

## Adding a New Kind (Recipe)

Follow these steps when adding a new custom-block kind to the registry.

1. **Define the ops struct** in the appropriate `.c` file with
   `"ocgtk.<kind>"` as the identifier and the correct finalizer:
   ```c
   struct custom_operations ocgtk_<kind>_ops = {
       "ocgtk.<kind>",
       finalize_<kind>,
       custom_compare_default,
       custom_hash_default,
       custom_serialize_default,
       custom_deserialize_default,
       custom_compare_ext_default
   };
   ```

2. **Promote to `extern`** and add the declaration to `value_kinds.h`:
   ```c
   extern struct custom_operations ocgtk_<kind>_ops;  /* "ocgtk.<kind>" */
   ```

3. **Add an enum value** `OCGTK_KIND_<KIND>` to the `ocgtk_kind` enum in
   `value_kinds.h`, before `OCGTK_KIND_OPAQUE_BLOCK`.

4. **Extend the switch** in `ocgtk_classify` (in `wrappers.c`) to return the
   new kind for the new ops pointer:
   ```c
   if (ops == &ocgtk_<kind>_ops) return OCGTK_KIND_<KIND>;
   ```

5. **Write an asserting accessor** — typical form is a pointer cast through
   `Data_custom_val`, guarded by `OCGTK_ASSERT_OPS`:
   ```c
   static inline <C type>* <kind>_val(value v) {
       OCGTK_ASSERT_OPS(v, ocgtk_<kind>_ops);
       return (<C type>*)Data_custom_val(v);
   }
   ```

6. **Add a test case** to `ocgtk/tests/gtk/test_value_kinds.ml` covering the
   classification round-trip for the new kind.

## OCaml/C FFI Critical Lessons

### 1. GValue Memory Management

**Critical**: GValues cannot be shallow-copied with memcpy. Use g_value_copy:

```c
/* WRONG - shallow copy, dangling pointers */
memcpy(dest_gvalue, src_gvalue, sizeof(GValue));

/* RIGHT - deep copy */
g_value_init(dest_gvalue, G_VALUE_TYPE(src_gvalue));
g_value_copy(src_gvalue, dest_gvalue);
```

**ml_gvalue wrapper pattern**:
```c
typedef struct {
    GValue gvalue;
    int initialized;  // Track initialization for safe finalization
} ml_gvalue;
```

### 2. GClosure Pattern (from lablgtk3)

Store OCaml closure **directly** in `closure->data`:
```c
GClosure *closure = g_closure_new_simple(sizeof(GClosure), (gpointer)callback);
caml_register_global_root((value*)&closure->data);  // Prevent GC
g_closure_set_marshal(closure, ml_closure_marshal);
g_closure_add_invalidate_notifier(closure, NULL, ml_closure_invalidate);
g_closure_ref(closure);
g_closure_sink(closure);
```

In marshaller:
```c
value callback = (value)closure->data;  // Direct access
caml_callback_exn(callback, argv_val);
```

In invalidate notifier:
```c
caml_remove_global_root((value*)&closure->data);  // Cleanup
```

### 3. Debugging FFI Issues

**File-based debugging** when stderr doesn't work:
```c
FILE *f = fopen("/tmp/debug.txt", "a");
if (f) {
    fprintf(f, "Debug: value = %p\n", (void*)val);
    fclose(f);
}
```

**Check pointer values** to catch corruption early:
```c
fprintf(f, "Created: %p, Received: %p\n", original_ptr, received_ptr);
// If different, wrapping/unwrapping is broken!
```

### 4. GC Safety: Always Use CAMLlocal for Local `value` Variables

**Rule**: Every local C variable of type `value` MUST be declared with `CAMLlocal1` (or `CAMLlocal2`, etc.), not as a plain C stack variable.

**Why**: The OCaml GC can only run during OCaml allocations, but this is a fragile invariant. A bare `value result = Val_*(...)` on the C stack is not a GC root. If any allocation is ever inserted between the `Val_*` call and `CAMLreturn`, the GC may move or collect the object that `result` points to, causing a silent use-after-free.

**Wrong** (currently safe but violates FFI contract):
```c
CAMLprim value ml_g_variant_get_variant(value v) {
    CAMLparam1(v);
    GVariant *child = g_variant_get_variant(GVariant_val(v));
    value result = Val_GVariant(child);   /* NOT a GC root! */
    g_variant_unref(child);
    CAMLreturn(result);
}
```

**Right**:
```c
CAMLprim value ml_g_variant_get_variant(value v) {
    CAMLparam1(v);
    CAMLlocal1(result);                   /* registered GC root */
    GVariant *child = g_variant_get_variant(GVariant_val(v));
    result = Val_GVariant(child);
    g_variant_unref(child);
    CAMLreturn(result);
}
```

**Also applies to `CAMLreturn(Val_*(...))`**: Calling `Val_*` directly inside `CAMLreturn` is fine — the macro captures the result into a compiler-managed variable before popping the GC frame. But if you need to use the value before returning, always use `CAMLlocal`.

**Note on C pointers (`GVariant*`, `GObject*`, etc.)**: These are GLib-managed heap pointers, not OCaml values. The OCaml GC does not move or collect them. Only OCaml `value` variables need GC root registration.

**Never store a raw C pointer in a scanned OCaml block** (`Store_field` into a
tag < `No_scan_tag` block, `caml_alloc` field of a record/tuple/array): the GC
treats every field of such a block as a well-formed OCaml value and will
follow the pointer during any collection triggered afterwards — reading
arbitrary memory at the pointer as a block header and chasing it into the C
stack. This crashed the closure marshaller: `Store_field(argv, 2,
(value)param_values)` segfaulted whenever a major GC ran inside a signal
callback. If a C pointer must cross into OCaml, either copy what it points to
into OCaml-owned storage (deep copy), or wrap it in a custom block / a block
with a non-scanned tag.

### 5. Common Pitfalls

| Pitfall | Symptom | Solution |
|---------|---------|----------|
| memcpy GValues | Segfault on access/finalization | Use g_value_init + g_value_copy |
| Raw C pointer stored via Store_field | GC crash/corruption on the next collection | Deep copy into OCaml-owned values, or custom/non-scanned block |
| Forgetting ml_gvalue.initialized flag | Segfault in finalizer | Always set after initialization |
| `value result = Val_*(...)` without CAMLlocal | Silent GC corruption if allocation added later | Always use `CAMLlocal1(result)` |
| Not checking lablgtk3 | Hours of debugging | **ALWAYS check lablgtk3 first!** |

**Note**: All GObject/record/variant values use Custom blocks — use the
allocator and reader listed in the **Canonical FFI Paths** table at the top of
this document.  `Val_pointer`/`Pointer_val` (deleted in phase-0a) and
`val_of_ext`/`ext_of_val` (legacy, phase-6 retirement) are covered in the
**Legacy Paths** section above.

## Security

### Allocation Safety

- **Check all allocation results**: `malloc`, `g_new`, `g_malloc` can return NULL.
  Raise `caml_raise_out_of_memory()` on failure.
- **Check integer overflow before allocation**: before `count * item_size`,
  verify `count <= SIZE_MAX / item_size`.
- **Free resources on all error paths**: before calling `caml_failwith` or
  `caml_raise_*`, free all locally allocated resources (or document intentional
  leaks for small, rare allocations).

### Pointer and Buffer Safety

- **Validate pointer arguments before dereference**: check for NULL after
  unwrapping, raise `caml_invalid_argument` with a descriptive message.
- **Validate buffer bounds for memcpy/strcpy**: ensure `src_len <= dest_size`,
  check `src != NULL` and `dest != NULL` when `len > 0`.
- **NULL-terminate after strncpy**: always `buffer[size-1] = '\0'`.
- **Never use unbounded strlen on external pointers**: use `strnlen` with a
  reasonable maximum.

### GLib/GTK Patterns

- **Check g_object_new result**: can return NULL; raise on failure.
- **Handle GError properly**: `caml_failwith` never returns. Either document
  intentional leaks, use stack buffers, or use static strings.
- **Validate GList/GSList structure during conversion**: check `Is_block` and
  `Wosize_val >= 2` for each cell; free allocated GList on error before raising.
- **Reference counting**: new GObjects have floating refs — use
  `g_object_ref_sink` to take ownership; always `g_object_unref` in finalizer.

### Callback Safety

- **Use caml_callback_exn and check Is_exception_result**: log or handle
  exceptions; never silently swallow them.
- **Don't store pointers to temporary data in OCaml values**: if the C pointer
  lifetime is shorter than the OCaml value lifetime, document the constraint
  or copy the data.
- **Protect closures with global roots**: `caml_register_global_root` when
  storing OCaml values in C structures; `caml_remove_global_root` on destroy.

### Integer Safety

- **Validate integer ranges**: check for negative where invalid, maximum values,
  and overflow in calculations.
- **OCaml int range**: on 64-bit, OCaml ints are 63-bit (tagged). Use
  `caml_copy_int32`/`int64`/`nativeint` for full-range integers.

### Use-After-Free Prevention

- Use custom blocks with finalizers that NULL the pointer after cleanup.
- Connect to GTK "destroy" signals to NULL stored widget pointers.
- Never access a GObject after `g_object_unref`.

### Code Review Checklist

- [ ] All malloc/g_new results checked for NULL
- [ ] Integer overflow checked before allocation calculations
- [ ] Resources freed on all error paths (or documented intentional leak)
- [ ] CAMLparam/CAMLlocal/CAMLreturn used correctly
- [ ] Global roots registered/removed for OCaml values in C structures
- [ ] No shallow copies of GValue or complex structures
- [ ] NULL pointer checks before dereferencing
- [ ] Integer ranges validated
- [ ] caml_callback_exn used and results checked
- [ ] Temporary C pointers not stored in OCaml values
- [ ] Reference counting correct (ref_sink for new objects)
