/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GestureClick */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"
#include "converters.h"

#include <gtk/gtk.h>
/* Include library-specific type conversions and forward declarations */
#include "gtk_decls.h"


CAMLexport CAMLprim value ml_gtk_gesture_click_new(value unit)
{
CAMLparam1(unit);

GtkGestureClick *obj = gtk_gesture_click_new();
/* gtk_gesture_click_new is transfer-full and GtkGestureClick is NOT
 * GInitiallyUnowned -- the return is already a single owned, non-floating
 * reference, so the generator boilerplate g_object_ref_sink here added a
 * second reference nothing ever dropped (bounded leak per attach). Same
 * class as the ml_gdk_memory_texture_new fix in this commit. A companion
 * PR gates ref_sink on the constructor return transfer in gir_gen; once
 * that lands, regeneration will emit this stub as it stands here. */

CAMLreturn(Val_GtkGestureClick(obj));
}