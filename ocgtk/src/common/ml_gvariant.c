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

/* GVariant C bindings for ocgtk
 *
 * Complete implementation of all GVariant scalar types:
 * - b: boolean
 * - y: byte (uint8)
 * - n: int16
 * - q: uint16
 * - i: int32  
 * - u: uint32
 * - x: int64
 * - t: uint64
 * - d: double
 * - s: string
 * - o: object_path
 * - g: signature
 * - h: handle
 * - v: variant
 */

#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <glib.h>
#include <glib-object.h>

#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/custom.h>

#include "wrappers.h"
#include "value_kinds.h"

/* ==================================================================== */
/* GVariant custom block with reference counting                        */
/* ==================================================================== */

static void finalize_gvariant(value v) {
    GVariant *variant = *((GVariant**)Data_custom_val(v));
    if (variant != NULL) {
        g_variant_unref(variant);
    }
}

/* Compare two GVariants.
 * For same-typed basic variants uses g_variant_compare (natural ordering).
 * For containers or mixed types falls back to text-representation comparison.
 */
static int compare_gvariant(value v1, value v2) {
    GVariant *g1 = *((GVariant**)Data_custom_val(v1));
    GVariant *g2 = *((GVariant**)Data_custom_val(v2));
    if (g1 == g2) return 0;
    if (g_variant_type_is_basic(g_variant_get_type(g1)) &&
        g_variant_is_of_type(g2, g_variant_get_type(g1))) {
        return g_variant_compare(g1, g2);
    }
    if (g_variant_equal(g1, g2)) return 0;
    /* Stable ordering for containers/mixed types via text representation */
    gchar *s1 = g_variant_print(g1, TRUE);
    gchar *s2 = g_variant_print(g2, TRUE);
    int cmp = strcmp(s1, s2);
    g_free(s1);
    g_free(s2);
    return cmp;
}

/* Hash a GVariant.
 * Uses g_variant_hash for basic types; falls back to hashing the
 * text representation for containers.
 */
static intnat hash_gvariant(value v) {
    GVariant *g = *((GVariant**)Data_custom_val(v));
    if (g_variant_type_is_basic(g_variant_get_type(g))) {
        return (intnat)g_variant_hash(g);
    }
    gchar *str = g_variant_print(g, TRUE);
    guint h = g_str_hash(str);
    g_free(str);
    return (intnat)h;
}

struct custom_operations ocgtk_gvariant_ops = {
    "ocgtk.gvariant",
    finalize_gvariant,
    compare_gvariant,
    hash_gvariant,
    custom_serialize_default,
    custom_deserialize_default,
    custom_compare_ext_default,
    custom_fixed_length_default
};

/* Wrap a GVariant pointer in a custom block, taking ownership of the
 * reference.  The finalizer calls g_variant_unref exactly once.
 *
 * Ownership rules:
 *   transfer-full return  → pass directly: Val_GVariant(result)
 *   transfer-none return  → caller must ref first: Val_GVariant(g_variant_ref(result))
 *
 * Note that "transfer-full" here means a genuine owned, non-floating
 * reference -- every g_variant_new_*() constructor below instead returns a
 * FLOATING reference (GVariant's own floating-ref convention, distinct
 * from GInitiallyUnowned but the same hazard class).
 * Passing a floating ref straight to Val_GVariant looks transfer-full
 * (the pointer is "ours") but isn't: the first API that takes ownership of
 * it (e.g. g_menu_item_set_attribute_value) calls g_variant_ref_sink()
 * itself, which on an UNSUNK floating ref just clears the floating bit
 * without bumping the count -- so the refcount stays 1, now "owned" by
 * that API, while our OCaml custom block still believes it owns that same
 * reference too. Its finalizer's g_variant_unref then drops the count to
 * 0 and frees memory the other owner still points at. Every
 * g_variant_new_*() wrapper below therefore sinks with g_variant_ref_sink()
 * BEFORE calling Val_GVariant, converting the floating ref into a real
 * transfer-full one first: sinking an already-floating ref of refcount 1
 * leaves the count at 1 (still ours, no longer floating), so a later
 * ref_sink by a GTK/GIO API now genuinely increments to 2, and our
 * finalizer's single unref correctly drops it back to 1 instead of 0. */
CAMLexport value Val_GVariant(GVariant *variant) {
    CAMLparam0();
    CAMLlocal1(v);

    if (variant == NULL) {
        caml_failwith("Val_GVariant: NULL variant");
    }

    v = caml_alloc_custom(&ocgtk_gvariant_ops, sizeof(GVariant*), 0, 1);
    *((GVariant**)Data_custom_val(v)) = variant;

    CAMLreturn(v);
}

/* ==================================================================== */
/* Type Introspection                                                   */
/* ==================================================================== */

CAMLprim value ml_g_variant_get_type_string(value variant) {
    CAMLparam1(variant);
    GVariant *v = GVariant_val(variant);
    const gchar *type_str = g_variant_get_type_string(v);
    CAMLreturn(caml_copy_string(type_str));
}

CAMLprim value ml_g_variant_is_of_type(value variant, value type_str) {
    CAMLparam2(variant, type_str);
    GVariant *v = GVariant_val(variant);
    const gchar *type = String_val(type_str);
    CAMLreturn(Val_bool(g_variant_is_of_type(v, G_VARIANT_TYPE(type))));
}

/* ==================================================================== */
/* Boolean                                                              */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_boolean(value bool_val) {
    CAMLparam1(bool_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_boolean(Bool_val(bool_val)));
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_boolean(value variant) {
    CAMLparam1(variant);
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_BOOLEAN)) {
        caml_failwith("GVariant.get_boolean: variant is not a boolean");
    }
    CAMLreturn(Val_bool(g_variant_get_boolean(v)));
}

/* ==================================================================== */
/* Byte (uint8)                                                         */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_byte(value byte_val) {
    CAMLparam1(byte_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_byte(Int_val(byte_val)));
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_byte(value variant) {
    CAMLparam1(variant);
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_BYTE)) {
        caml_failwith("GVariant.get_byte: variant is not a byte");
    }
    CAMLreturn(Val_int(g_variant_get_byte(v)));
}

/* ==================================================================== */
/* Int16                                                                */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_int16(value int16_val) {
    CAMLparam1(int16_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_int16((gint16)Int_val(int16_val)));
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_int16(value variant) {
    CAMLparam1(variant);
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_INT16)) {
        caml_failwith("GVariant.get_int16: variant is not an int16");
    }
    CAMLreturn(Val_int(g_variant_get_int16(v)));
}

/* ==================================================================== */
/* UInt16                                                               */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_uint16(value uint16_val) {
    CAMLparam1(uint16_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_uint16((guint16)UInt16_val(uint16_val)));
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_uint16(value variant) {
    CAMLparam1(variant);
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_UINT16)) {
        caml_failwith("GVariant.get_uint16: variant is not a uint16");
    }
    CAMLreturn(Val_uint16(g_variant_get_uint16(v)));
}

/* ==================================================================== */
/* Int32                                                                */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_int32(value int32_val) {
    CAMLparam1(int32_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_int32(Int32_val(int32_val)));
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_int32(value variant) {
    CAMLparam1(variant);
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_INT32)) {
        caml_failwith("GVariant.get_int32: variant is not an int32");
    }
    CAMLreturn(caml_copy_int32(g_variant_get_int32(v)));
}

/* ==================================================================== */
/* UInt32                                                               */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_uint32(value uint32_val) {
    CAMLparam1(uint32_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_uint32((guint32)UInt32_val(uint32_val)));
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_uint32(value variant) {
    CAMLparam1(variant);
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_UINT32)) {
        caml_failwith("GVariant.get_uint32: variant is not a uint32");
    }
    CAMLreturn(Val_uint32(g_variant_get_uint32(v)));
}

/* ==================================================================== */
/* Int64                                                                */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_int64(value int64_val) {
    CAMLparam1(int64_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_int64(Int64_val(int64_val)));
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_int64(value variant) {
    CAMLparam1(variant);
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_INT64)) {
        caml_failwith("GVariant.get_int64: variant is not an int64");
    }
    CAMLreturn(caml_copy_int64(g_variant_get_int64(v)));
}

/* ==================================================================== */
/* UInt64                                                               */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_uint64(value uint64_val) {
    CAMLparam1(uint64_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_uint64((guint64)Uint64_val(uint64_val)));
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_uint64(value variant) {
    CAMLparam1(variant);
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_UINT64)) {
        caml_failwith("GVariant.get_uint64: variant is not a uint64");
    }
    CAMLreturn(integers_copy_uint64(g_variant_get_uint64(v)));
}

/* ==================================================================== */
/* Double                                                               */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_double(value double_val) {
    CAMLparam1(double_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_double(Double_val(double_val)));
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_double(value variant) {
    CAMLparam1(variant);
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_DOUBLE)) {
        caml_failwith("GVariant.get_double: variant is not a double");
    }
    CAMLreturn(caml_copy_double(g_variant_get_double(v)));
}

/* ==================================================================== */
/* String                                                               */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_string(value string_val) {
    CAMLparam1(string_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_string(String_val(string_val)));
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_string(value variant) {
    CAMLparam1(variant);
    CAMLlocal1(result);
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_STRING) &&
        !g_variant_is_of_type(v, G_VARIANT_TYPE_OBJECT_PATH) &&
        !g_variant_is_of_type(v, G_VARIANT_TYPE_SIGNATURE)) {
        caml_failwith("GVariant.get_string: variant is not a string, object path, or signature");
    }
    gsize length;
    const gchar *str = g_variant_get_string(v, &length);
    result = caml_copy_string(str);
    CAMLreturn(result);
}

/* ==================================================================== */
/* Object Path                                                          */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_object_path(value path_val) {
    CAMLparam1(path_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_object_path(String_val(path_val)));
    CAMLreturn(Val_GVariant(v));
}

/* ==================================================================== */
/* Signature                                                            */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_signature(value sig_val) {
    CAMLparam1(sig_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_signature(String_val(sig_val)));
    CAMLreturn(Val_GVariant(v));
}

/* ==================================================================== */
/* Handle (File Descriptor)                                             */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_handle(value handle_val) {
    CAMLparam1(handle_val);
    GVariant *v = g_variant_ref_sink(g_variant_new_handle(Int_val(handle_val)));
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_handle(value variant) {
    CAMLparam1(variant);
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_HANDLE)) {
        caml_failwith("GVariant.get_handle: variant is not a handle");
    }
    CAMLreturn(Val_int(g_variant_get_handle(v)));
}

/* ==================================================================== */
/* Variant (Boxed Value)                                                */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_variant(value variant_val) {
    CAMLparam1(variant_val);
    GVariant *v = GVariant_val(variant_val);
    GVariant *result = g_variant_ref_sink(g_variant_new_variant(v));
    CAMLreturn(Val_GVariant(result));
}

CAMLprim value ml_g_variant_get_variant(value variant_val) {
    CAMLparam1(variant_val);
    CAMLlocal1(result);
    GVariant *v = GVariant_val(variant_val);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_VARIANT)) {
        caml_failwith("GVariant.get_variant: variant is not a variant type");
    }
    GVariant *child = g_variant_get_variant(v);
    result = Val_GVariant(child);  /* takes ownership of the ref returned by get_variant */
    CAMLreturn(result);
}

/* ==================================================================== */
/* Maybe (Nullable)                                                     */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_maybe(value type_val, value child_val) {
    CAMLparam2(type_val, child_val);
    GVariantType *type = GVariantType_val(type_val);
    GVariant *child = (child_val == Val_none) ? NULL : GVariant_val(Field(child_val, 0));
    GVariant *result = g_variant_ref_sink(g_variant_new_maybe(type, child));
    CAMLreturn(Val_GVariant(result));
}

CAMLprim value ml_g_variant_get_maybe(value variant) {
    CAMLparam1(variant);
    CAMLlocal2(result, child_val);
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_MAYBE)) {
        caml_failwith("GVariant.get_maybe: variant is not a maybe type");
    }
    GVariant *child = g_variant_get_maybe(v);
    if (child == NULL) {
        result = Val_none;
    } else {
        /* Val_GVariant takes ownership of child's ref returned by get_maybe.
         * Must be called before caml_alloc to avoid leaving the Some block
         * with an uninitialised field 0 visible to the GC. */
        child_val = Val_GVariant(child);
        result = caml_alloc(1, 0); /* Some */
        Store_field(result, 0, child_val);
    }
    CAMLreturn(result);
}

/* ==================================================================== */
/* String Arrays                                                        */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_strv(value arr) {
    CAMLparam1(arr);
    CAMLlocal1(item);
    
    int length = Wosize_val(arr);
    const gchar **strv = g_new(const gchar*, length + 1);
    if (strv == NULL) {
        caml_raise_out_of_memory();
    }
    
    for (int i = 0; i < length; i++) {
        item = Field(arr, i);
        strv[i] = String_val(item);
    }
    strv[length] = NULL;
    
    GVariant *v = g_variant_ref_sink(g_variant_new_strv(strv, length));
    g_free(strv);
    
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_strv(value variant) {
    CAMLparam1(variant);
    CAMLlocal2(result, str);
    
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_STRING_ARRAY)) {
        caml_failwith("GVariant.get_strv: variant is not a string array");
    }
    gsize length;
    const gchar **strv = g_variant_get_strv(v, &length);
    
    result = caml_alloc(length, 0);
    for (gsize i = 0; i < length; i++) {
        str = caml_copy_string(strv[i]);
        Store_field(result, i, str);
    }
    
    g_free(strv);
    CAMLreturn(result);
}

/* ==================================================================== */
/* Object Path Arrays                                                   */
/* ==================================================================== */

CAMLprim value ml_g_variant_new_objv(value arr) {
    CAMLparam1(arr);
    CAMLlocal1(item);
    
    int length = Wosize_val(arr);
    const gchar **objv = g_new(const gchar*, length + 1);
    if (objv == NULL) {
        caml_raise_out_of_memory();
    }
    
    for (int i = 0; i < length; i++) {
        item = Field(arr, i);
        objv[i] = String_val(item);
    }
    objv[length] = NULL;
    
    GVariant *v = g_variant_ref_sink(g_variant_new_objv(objv, length));
    g_free(objv);
    
    CAMLreturn(Val_GVariant(v));
}

CAMLprim value ml_g_variant_get_objv(value variant) {
    CAMLparam1(variant);
    CAMLlocal2(result, str);
    
    GVariant *v = GVariant_val(variant);
    if (!g_variant_is_of_type(v, G_VARIANT_TYPE_OBJECT_PATH_ARRAY)) {
        caml_failwith("GVariant.get_objv: variant is not an object path array");
    }
    gsize length;
    const gchar **objv = g_variant_get_objv(v, &length);
    
    result = caml_alloc(length, 0);
    for (gsize i = 0; i < length; i++) {
        str = caml_copy_string(objv[i]);
        Store_field(result, i, str);
    }
    
    g_free(objv);
    CAMLreturn(result);
}

/* ==================================================================== */
/* Dictionary Lookups (a{sv} pattern)                                   */
/* ==================================================================== */

CAMLprim value ml_g_variant_lookup_string(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, str_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_STRING);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    const gchar *str = g_variant_get_string(child, NULL);
    str_val = caml_copy_string(str);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, str_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_lookup_int32(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, int_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_INT32);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    gint32 val = g_variant_get_int32(child);
    int_val = caml_copy_int32(val);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, int_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_lookup_boolean(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, bool_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_BOOLEAN);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    gboolean val = g_variant_get_boolean(child);
    bool_val = Val_bool(val);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, bool_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_lookup_byte(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, byte_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_BYTE);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    guchar val = g_variant_get_byte(child);
    byte_val = Val_int(val);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, byte_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_lookup_int16(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, int_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_INT16);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    gint16 val = g_variant_get_int16(child);
    int_val = Val_int(val);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, int_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_lookup_uint16(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, int_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_UINT16);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    guint16 val = g_variant_get_uint16(child);
    int_val = Val_int(val);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, int_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_lookup_uint32(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, int_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_UINT32);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    guint32 val = g_variant_get_uint32(child);
    int_val = Val_uint32(val);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, int_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_lookup_int64(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, int_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_INT64);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    gint64 val = g_variant_get_int64(child);
    int_val = caml_copy_int64(val);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, int_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_lookup_uint64(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, int_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_UINT64);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    guint64 val = g_variant_get_uint64(child);
    int_val = integers_copy_uint64(val);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, int_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_lookup_double(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, dbl_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_DOUBLE);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    gdouble val = g_variant_get_double(child);
    dbl_val = caml_copy_double(val);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, dbl_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_lookup_object_path(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, str_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_OBJECT_PATH);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    const gchar *str = g_variant_get_string(child, NULL);
    str_val = caml_copy_string(str);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, str_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_lookup_signature(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, str_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_SIGNATURE);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    const gchar *str = g_variant_get_string(child, NULL);
    str_val = caml_copy_string(str);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, str_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_lookup_handle(value variant, value key) {
    CAMLparam2(variant, key);
    CAMLlocal2(result, handle_val);
    
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_lookup_value(v, String_val(key), G_VARIANT_TYPE_HANDLE);
    
    if (child == NULL) {
        CAMLreturn(Val_none);
    }
    
    gint32 val = g_variant_get_handle(child);
    handle_val = Val_int(val);
    result = caml_alloc(1, 0); /* Some */
    Store_field(result, 0, handle_val);
    g_variant_unref(child);
    
    CAMLreturn(result);
}

/* ==================================================================== */
/* Child Access                                                         */
/* ==================================================================== */

CAMLprim value ml_g_variant_n_children(value variant) {
    CAMLparam1(variant);
    GVariant *v = GVariant_val(variant);
    CAMLreturn(Val_int(g_variant_n_children(v)));
}

CAMLprim value ml_g_variant_get_child_value(value variant, value index) {
    CAMLparam2(variant, index);
    CAMLlocal1(result);
    GVariant *v = GVariant_val(variant);
    GVariant *child = g_variant_get_child_value(v, Int_val(index));
    if (child == NULL) {
        caml_failwith("ml_g_variant_get_child_value: invalid index");
    }
    result = Val_GVariant(child);  /* takes ownership */
    CAMLreturn(result);
}

/* ==================================================================== */
/* Serialization                                                        */
/* ==================================================================== */

CAMLprim value ml_g_variant_print(value variant, value type_annotate) {
    CAMLparam2(variant, type_annotate);
    CAMLlocal1(result);
    
    GVariant *v = GVariant_val(variant);
    gchar *str = g_variant_print(v, Bool_val(type_annotate));
    result = caml_copy_string(str);
    g_free(str);
    
    CAMLreturn(result);
}

CAMLprim value ml_g_variant_parse(value text) {
    CAMLparam1(text);
    CAMLlocal1(result);
    
    GVariant *v;
    GError *error = NULL;
    
    v = g_variant_parse(NULL, String_val(text), NULL, NULL, &error);
    
    if (v == NULL) {
        char msg[256];
        snprintf(msg, sizeof(msg), "GVariant parse error: %s", error->message);
        g_error_free(error);
        caml_failwith(msg);
    }
    
    result = Val_GVariant(v);  /* takes ownership of the ref from g_variant_parse */
    CAMLreturn(result);
}
