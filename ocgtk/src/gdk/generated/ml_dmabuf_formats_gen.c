/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DmabufFormats */

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

#if GTK_CHECK_VERSION(4,14,0)
/* Conversion functions for GdkDmabufFormats (opaque record with hidden fields) */
GdkDmabufFormats *GdkDmabufFormats_val(value v) {
  return (GdkDmabufFormats *)ml_gir_record_ptr_val(v, "GdkDmabufFormats");
}

value Val_GdkDmabufFormats(const GdkDmabufFormats *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gdk_dmabuf_formats_get_type(), ptr);
}

value Val_GdkDmabufFormats_option(const GdkDmabufFormats *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GdkDmabufFormats(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gdk_dmabuf_formats_ref(value self)
{
CAMLparam1(self);

GdkDmabufFormats* result = gdk_dmabuf_formats_ref(GdkDmabufFormats_val(self));
CAMLreturn(Val_GdkDmabufFormats(result));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_formats_get_n_formats(value self)
{
CAMLparam1(self);

gsize result = gdk_dmabuf_formats_get_n_formats(GdkDmabufFormats_val(self));
CAMLreturn(Val_gsize(result));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_formats_get_format(value self, value arg1)
{
CAMLparam2(self, arg1);
guint32 out2;
guint64 out3;

gdk_dmabuf_formats_get_format(GdkDmabufFormats_val(self), Gsize_val(arg1), &out2, &out3);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_uint32(out2));
    Store_field(ret, 1, integers_copy_uint64(out3));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_dmabuf_formats_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_dmabuf_formats_equal(GdkDmabufFormats_val(self), Option_val(arg1, GdkDmabufFormats_val, NULL));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_dmabuf_formats_contains(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gdk_dmabuf_formats_contains(GdkDmabufFormats_val(self), UInt32_val(arg1), Uint64_val(arg2));
CAMLreturn(Val_bool(result));
}

GType gdk_dmabuf_formats_get_type (void);


CAMLprim value ml_gdk_dmabuf_formats_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_dmabuf_formats_get_type()));
}

#else


CAMLexport CAMLprim value ml_gdk_dmabuf_formats_contains(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("DmabufFormats requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_formats_equal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufFormats requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_formats_get_format(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DmabufFormats requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_formats_get_n_formats(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufFormats requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gdk_dmabuf_formats_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DmabufFormats requires GTK >= 4.14");
return Val_unit;
}


#endif
