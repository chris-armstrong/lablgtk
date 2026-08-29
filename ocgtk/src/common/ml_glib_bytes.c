/**************************************************************************/
/*                ocgtk - OCaml bindings for GTK4                         */
/*                                                                        */
/*    This program is free software; you can redistribute it              */
/*    and/or modify it under the terms of the GNU Library General         */
/*    Public License version 2, as published by the           */
/*    Free Software Foundation with the exception described in file       */
/*    COPYING which comes with the library.                               */
/*                                                                        */
/*    Based on lablgtk3 /https://github.com/garrigue/lablgtk/             */
/*                                                                        */
/**************************************************************************/

/* GBytes C bindings for ocgtk
 *
 * Implements an opaque OCaml wrapper for GBytes (GLib's immutable
 * reference-counted byte buffer).
 */

#include <string.h>
#include <glib.h>

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/fail.h>
#include <caml/custom.h>
#include <caml/bigarray.h>

#include "wrappers.h"
#include "value_kinds.h"

/* ==================================================================== */
/* GBytes custom block with reference counting                          */
/* ==================================================================== */

/* GC pacing of the C-heap payload.
 *
 * Every allocation site below declares the real GBytes payload size to
 * the GC so its pacing accounts for the off-heap memory.  Two runtime
 * APIs exist for this:
 *
 *   - Stock OCaml 5.x: caml_alloc_custom_mem paces via
 *     custom_major_ratio; there is no caml_alloc_custom_dep.
 *   - OxCaml: caml_alloc_custom_mem only picks minor-vs-major placement
 *     (caml_adjust_gc_speed is a compat no-op), so it is inert for
 *     pacing.  caml_alloc_custom_dep tracks dependent bytes instead,
 *     and the finalizer must balance it with caml_free_dependent_memory
 *     (two-arg form there).
 *
 * OCGTK_HAS_CAML_ALLOC_CUSTOM_DEP comes from the configurator probe
 * (src/configurator/probe_custom_dep.ml); OCAML_VERSION cannot
 * discriminate the two because OxCaml reports a stock version number.
 *
 * The freed byte count must equal the declared one; both are the GBytes
 * payload size, which is immutable, so g_bytes_get_size in the
 * finalizer always matches the size declared at allocation. */
static value alloc_gbytes_custom(gsize payload_size) {
#ifdef OCGTK_HAS_CAML_ALLOC_CUSTOM_DEP
    return caml_alloc_custom_dep(&ocgtk_gbytes_ops, sizeof(GBytes*),
                                 (mlsize_t)payload_size);
#else
    return caml_alloc_custom_mem(&ocgtk_gbytes_ops, sizeof(GBytes*),
                                 (mlsize_t)payload_size);
#endif
}

static void finalize_gbytes(value v) {
    GBytes *bytes = GBytes_val(v);
    if (bytes != NULL) {
#ifdef OCGTK_HAS_CAML_ALLOC_CUSTOM_DEP
        caml_free_dependent_memory(v, (mlsize_t)g_bytes_get_size(bytes));
#endif
        g_bytes_unref(bytes);
    }
}

static int compare_gbytes(value v1, value v2) {
    return g_bytes_compare(GBytes_val(v1), GBytes_val(v2));
}

static intnat hash_gbytes(value v) {
    return (intnat)g_bytes_hash(GBytes_val(v));
}

struct custom_operations ocgtk_gbytes_ops = {
    "ocgtk.gbytes",
    finalize_gbytes,
    compare_gbytes,
    hash_gbytes,
    custom_serialize_default,
    custom_deserialize_default,
    custom_compare_ext_default,
    custom_fixed_length_default
};

/* Val_GBytes: wrap a GBytes pointer, taking a reference.
 *
 * Ownership rules:
 *   transfer-full return  -> pass directly: Val_GBytes(result)
 *   transfer-none return  -> caller must ref first: Val_GBytes(g_bytes_ref(result))
 */
CAMLexport value Val_GBytes(GBytes *bytes) {
    CAMLparam0();
    CAMLlocal1(result);

    if (bytes == NULL) {
        caml_failwith("Val_GBytes: NULL bytes");
    }

    gsize size = g_bytes_get_size(bytes);

    result = alloc_gbytes_custom(size);
    *((GBytes**)Data_custom_val(result)) = bytes;

    CAMLreturn(result);
}

/* ==================================================================== */
/* ml_g_bytes_new: create GBytes from OCaml string                     */
/* ==================================================================== */

/* GC safety: read string data and length BEFORE any OCaml allocation.
 * g_bytes_new copies the data (pure C allocation, no GC), so ml_str
 * may be moved by GC only after g_bytes_new returns safely.
 */
CAMLprim value ml_g_bytes_new(value ml_str) {
    CAMLparam1(ml_str);
    CAMLlocal1(result);

    /* Read string data before any allocation */
    const char *data = String_val(ml_str);
    mlsize_t len = caml_string_length(ml_str);

    /* g_bytes_new copies the data - pure C allocation, no OCaml GC */
    GBytes *bytes = g_bytes_new(data, (gsize)len);

    /* Now allocate the custom block - takes ownership, no extra ref needed.
     * alloc_gbytes_custom declares the real C-heap payload size to the
     * GC so its pacing accounts for it; it may trigger a GC, but `bytes`
     * is a C local, not read from an OCaml heap value, so that is safe. */
    result = alloc_gbytes_custom((gsize)len);
    *((GBytes**)Data_custom_val(result)) = bytes;

    CAMLreturn(result);
}

/* ==================================================================== */
/* ml_g_bytes_new_from_bigarray: create GBytes from a Bigarray.Array1   */
/* ==================================================================== */

/* GC safety: read the bigarray data pointer and byte size, then call
 * g_bytes_new immediately -- no OCaml allocation happens in between, so
 * nothing can move the bigarray out from under Caml_ba_data_val before
 * g_bytes_new has finished copying it. g_bytes_new copies the data (pure
 * C allocation, no OCaml GC involvement), so the OCaml-side bigarray and
 * the returned GBytes share no memory once this returns.
 */
CAMLprim value ml_g_bytes_new_from_bigarray(value ba) {
    CAMLparam1(ba);
    CAMLlocal1(result);

    void *data = Caml_ba_data_val(ba);
    gsize len = (gsize)caml_ba_byte_size(Caml_ba_array_val(ba));

    /* g_bytes_new copies the data - pure C allocation, no OCaml GC */
    GBytes *bytes = g_bytes_new(data, len);

    /* Now allocate the custom block - takes ownership, no extra ref needed.
     * Same `len` local used for g_bytes_new above and declared to the GC
     * here, so the two never drift. alloc_gbytes_custom may trigger a
     * GC, but `bytes` is a C local, not read from an OCaml heap value. */
    result = alloc_gbytes_custom(len);
    *((GBytes**)Data_custom_val(result)) = bytes;

    CAMLreturn(result);
}

/* ==================================================================== */
/* ml_g_bytes_get_data_as_string: copy GBytes data to OCaml string     */
/* ==================================================================== */

/* GC safety: call g_bytes_get_data first (no OCaml alloc), then
 * caml_alloc_string (may trigger GC), then memcpy.
 * The data pointer from g_bytes_get_data is stable because GBytes is
 * immutable and ref-counted - the GC will not touch it.
 */
CAMLprim value ml_g_bytes_get_data_as_string(value ml_bytes) {
    CAMLparam1(ml_bytes);
    CAMLlocal1(result);

    GBytes *bytes = GBytes_val(ml_bytes);
    gsize size;
    const void *data = g_bytes_get_data(bytes, &size);

    result = caml_alloc_string(size);
    if (size > 0) {
        memcpy(Bytes_val(result), data, size);
    }

    CAMLreturn(result);
}

/* ==================================================================== */
/* ml_g_bytes_get_size: get size of GBytes                             */
/* ==================================================================== */

CAMLprim value ml_g_bytes_get_size(value ml_bytes) {
    CAMLparam1(ml_bytes);
    GBytes *bytes = GBytes_val(ml_bytes);
    gsize size = g_bytes_get_size(bytes);
    CAMLreturn(Val_long((long)size));
}
