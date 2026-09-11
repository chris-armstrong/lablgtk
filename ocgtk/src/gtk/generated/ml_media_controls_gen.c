/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MediaControls */

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


CAMLexport CAMLprim value ml_gtk_media_controls_new(value arg1)
{
CAMLparam1(arg1);

GtkMediaControls *obj = gtk_media_controls_new(Option_val(arg1, GtkMediaStream_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkMediaControls(obj));
}
CAMLexport CAMLprim value ml_gtk_media_controls_set_media_stream(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_media_controls_set_media_stream(GtkMediaControls_val(self), Option_val(arg1, GtkMediaStream_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_media_controls_get_media_stream(value self)
{
CAMLparam1(self);

GtkMediaStream* result = gtk_media_controls_get_media_stream(GtkMediaControls_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkMediaStream));
}


CAMLprim value ml_gtk_media_controls_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_media_controls_get_type()));
}
