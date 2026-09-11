/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PixbufLoader */

#include <gdk-pixbuf/gdk-pixbuf.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gdk-pixbuf/gdk-pixbuf.h>
/* Include library-specific type conversions and forward declarations */
#include "gdkpixbuf_decls.h"


CAMLexport CAMLprim value ml_gdk_pixbuf_loader_new(value unit)
{
CAMLparam1(unit);

GdkPixbufLoader *obj = gdk_pixbuf_loader_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GdkPixbufLoader(obj));
}
#if GDK_PIXBUF_CHECK_VERSION(2,4,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_loader_new_with_mime_type(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GdkPixbufLoader *obj = gdk_pixbuf_loader_new_with_mime_type(String_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbufLoader(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_pixbuf_loader_new_with_mime_type(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("PixbufLoader requires GdkPixbuf >= 2.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_loader_new_with_type(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GdkPixbufLoader *obj = gdk_pixbuf_loader_new_with_type(String_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbufLoader(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#if GDK_PIXBUF_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_loader_write_bytes(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gdk_pixbuf_loader_write_bytes(GdkPixbufLoader_val(self), GBytes_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_loader_write_bytes(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PixbufLoader requires GdkPixbuf >= 2.30");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,2,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_loader_set_size(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_pixbuf_loader_set_size(GdkPixbufLoader_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_loader_set_size(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("PixbufLoader requires GdkPixbuf >= 2.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_loader_get_pixbuf(value self)
{
CAMLparam1(self);

GdkPixbuf* result = gdk_pixbuf_loader_get_pixbuf(GdkPixbufLoader_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkPixbuf));
}

#if GDK_PIXBUF_CHECK_VERSION(2,2,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_loader_get_format(value self)
{
CAMLparam1(self);

GdkPixbufFormat* result = gdk_pixbuf_loader_get_format(GdkPixbufLoader_val(self));
if (result) result = g_boxed_copy(gdk_pixbuf_format_get_type(), result);
CAMLreturn(Val_option(result, Val_GdkPixbufFormat));
}

#else

CAMLexport CAMLprim value ml_gdk_pixbuf_loader_get_format(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PixbufLoader requires GdkPixbuf >= 2.2");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_loader_get_animation(value self)
{
CAMLparam1(self);

GdkPixbufAnimation* result = gdk_pixbuf_loader_get_animation(GdkPixbufLoader_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkPixbufAnimation));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_loader_close(value self)
{
CAMLparam1(self);
GError *error = NULL;

gboolean result = gdk_pixbuf_loader_close(GdkPixbufLoader_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

GType gdk_pixbuf_loader_get_type (void);


CAMLprim value ml_gdk_pixbuf_pixbuf_loader_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_pixbuf_loader_get_type()));
}
