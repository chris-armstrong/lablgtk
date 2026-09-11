/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Resource */

#include <gio/gio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gio/gio.h>
/* Include library-specific type conversions and forward declarations */
#include "gio_decls.h"

#if GLIB_CHECK_VERSION(2,32,0)
/* Conversion functions for GResource (opaque record with hidden fields) */
GResource *GResource_val(value v) {
  return (GResource *)ml_gir_record_ptr_val(v, "GResource");
}

value Val_GResource(const GResource *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(g_resource_get_type(), ptr);
}

value Val_GResource_option(const GResource *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GResource(ptr));
}
#endif

#if GLIB_CHECK_VERSION(2,32,0)


CAMLexport CAMLprim value ml_g_resource_new_from_data(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GResource *obj = g_resource_new_from_data(GBytes_val(arg1), &error);

if (error == NULL) CAMLreturn(Res_Ok(Val_GResource(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_g_resource_ref(value self)
{
CAMLparam1(self);

GResource* result = g_resource_ref(GResource_val(self));
CAMLreturn(Val_GResource(result));
}

CAMLexport CAMLprim value ml_g_resource_open_stream(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

GInputStream* result = g_resource_open_stream(GResource_val(self), String_val(arg1), GioResourceLookupFlags_val(arg2), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GInputStream(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_resource_lookup_data(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

GBytes* result = g_resource_lookup_data(GResource_val(self), String_val(arg1), GioResourceLookupFlags_val(arg2), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GBytes(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#if GLIB_CHECK_VERSION(2,84,0)

CAMLexport CAMLprim value ml_g_resource_has_children(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_resource_has_children(GResource_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_resource_has_children(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Resource requires GLib >= 2.84");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_resource_get_info(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;
gsize out3;
guint32 out4;

gboolean result = g_resource_get_info(GResource_val(self), String_val(arg1), GioResourceLookupFlags_val(arg2), &out3, &out4, &error);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_gsize(out3));
    Store_field(ret, 2, Val_uint32(out4));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_resource_enumerate_children(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

char** result = g_resource_enumerate_children(GResource_val(self), String_val(arg1), GioResourceLookupFlags_val(arg2), &error);
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
    for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
if (error == NULL) CAMLreturn(Res_Ok(ml_result)); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_g_resources_unregister(value self)
{
CAMLparam1(self);

g_resources_unregister(GResource_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_resources_register(value self)
{
CAMLparam1(self);

g_resources_register(GResource_val(self));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gio_resource_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_resource_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_resource_new_from_data(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("Resource requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_resources_register(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Resource requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_resources_unregister(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Resource requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_resource_enumerate_children(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Resource requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_resource_get_info(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Resource requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_resource_has_children(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Resource requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_resource_lookup_data(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Resource requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_resource_open_stream(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Resource requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_resource_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Resource requires GLib >= 2.32");
return Val_unit;
}


#endif
