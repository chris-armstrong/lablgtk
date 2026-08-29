/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MemoryTexture */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk/gdk.h>
/* Include library-specific type conversions and forward declarations */
#include "gdk_decls.h"


CAMLexport CAMLprim value ml_gdk_memory_texture_new(value arg1, value arg2, value arg3, value arg4, value arg5)
{
CAMLparam5(arg1, arg2, arg3, arg4, arg5);

/* gdk_memory_texture_new is transfer-full, and GdkTexture is NOT a
 * GInitiallyUnowned type -- unlike a floating-ref widget constructor
 * (see ml_button_gen.c), this call already returns a single owned, non-
 * floating reference. wrappers.c's finalize_gobject drops exactly one
 * reference, so wrapping is correct as-is; the generator's boilerplate
 * g_object_ref_sink() here added a SECOND reference that nothing ever
 * dropped, leaking every texture this constructor ever built (observed as
 * unbounded RSS growth). A companion PR gates ref_sink on the constructor
 * return transfer in gir_gen; once that lands, regeneration will emit this
 * stub as it stands here. */
GdkMemoryTexture *obj = gdk_memory_texture_new(Int_val(arg1), Int_val(arg2), GdkMemoryFormat_val(arg3), GBytes_val(arg4), Gsize_val(arg5));

CAMLreturn(Val_GdkMemoryTexture(obj));
}