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
if (obj) g_object_ref_sink(obj);

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


CAMLprim value ml_gtk_event_controller_key_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_event_controller_key_get_type()));
}
