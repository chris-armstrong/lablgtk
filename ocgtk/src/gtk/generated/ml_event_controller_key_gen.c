/* GENERATED CODE - DO NOT EDIT */
/* C bindings for EventControllerKey */

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


CAMLexport CAMLprim value ml_gtk_event_controller_key_new(value unit)
{
CAMLparam1(unit);

GtkEventControllerKey *obj = gtk_event_controller_key_new();
/* gtk_event_controller_key_new is transfer-full and GtkEventControllerKey is NOT
 * GInitiallyUnowned -- the return is already a single owned, non-floating
 * reference, so the generator boilerplate g_object_ref_sink here added a
 * second reference nothing ever dropped (bounded leak per attach). Same
 * class as the ml_gdk_memory_texture_new fix in this commit. A companion
 * PR gates ref_sink on the constructor return transfer in gir_gen; once
 * that lands, regeneration will emit this stub as it stands here. */

CAMLreturn(Val_GtkEventControllerKey(obj));
}
CAMLexport CAMLprim value ml_gtk_event_controller_key_set_im_context(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_event_controller_key_set_im_context(GtkEventControllerKey_val(self), Option_val(arg1, GtkIMContext_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_event_controller_key_get_im_context(value self)
{
CAMLparam1(self);

GtkIMContext* result = gtk_event_controller_key_get_im_context(GtkEventControllerKey_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkIMContext));
}

CAMLexport CAMLprim value ml_gtk_event_controller_key_get_group(value self)
{
CAMLparam1(self);

guint result = gtk_event_controller_key_get_group(GtkEventControllerKey_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_event_controller_key_forward(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_event_controller_key_forward(GtkEventControllerKey_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_bool(result));
}
