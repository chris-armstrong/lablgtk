/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ContentProvider */

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


CAMLexport CAMLprim value ml_gdk_content_provider_new_for_bytes(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GdkContentProvider *obj = gdk_content_provider_new_for_bytes(String_val(arg1), GBytes_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkContentProvider(obj));
}
CAMLexport CAMLprim value ml_gdk_content_provider_new_for_value(value arg1)
{
CAMLparam1(arg1);

GdkContentProvider *obj = gdk_content_provider_new_for_value(GValue_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkContentProvider(obj));
}
CAMLexport CAMLprim value ml_gdk_content_provider_new_union(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
    int arg1_length = 0;
    GdkContentProvider** c_arg1 = NULL;
    
    if (Is_some(arg1)) {
        value array = Some_val(arg1);
        arg1_length = Wosize_val(array);
        c_arg1 = (GdkContentProvider**)g_malloc(sizeof(GdkContentProvider*) * arg1_length);
        for (int i = 0; i < arg1_length; i++) {
          c_arg1[i] = GdkContentProvider_val(Field(array, i));
        }
    }

GdkContentProvider *obj = gdk_content_provider_new_union(c_arg1, Gsize_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkContentProvider(obj));
}
CAMLexport CAMLprim value ml_gdk_content_provider_write_mime_type_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gdk_content_provider_write_mime_type_finish(GdkContentProvider_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gdk_content_provider_ref_storable_formats(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gdk_content_provider_ref_storable_formats(GdkContentProvider_val(self));
CAMLreturn(Val_GdkContentFormats(result));
}

CAMLexport CAMLprim value ml_gdk_content_provider_ref_formats(value self)
{
CAMLparam1(self);

GdkContentFormats* result = gdk_content_provider_ref_formats(GdkContentProvider_val(self));
CAMLreturn(Val_GdkContentFormats(result));
}

CAMLexport CAMLprim value ml_gdk_content_provider_get_value(value self)
{
CAMLparam1(self);
GError *error = NULL;
GValue out1;

gboolean result = gdk_content_provider_get_value(GdkContentProvider_val(self), &out1, &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GValue_copy(&out1));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gdk_content_provider_content_changed(value self)
{
CAMLparam1(self);

gdk_content_provider_content_changed(GdkContentProvider_val(self));
CAMLreturn(Val_unit);
}

GType gdk_content_provider_get_type (void);


CAMLprim value ml_gdk_content_provider_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_content_provider_get_type()));
}
