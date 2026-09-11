/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PixbufAnimation */

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


CAMLexport CAMLprim value ml_gdk_pixbuf_animation_new_from_file(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GdkPixbufAnimation *obj = gdk_pixbuf_animation_new_from_file(String_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbufAnimation(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#if GDK_PIXBUF_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_animation_new_from_resource(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GdkPixbufAnimation *obj = gdk_pixbuf_animation_new_from_resource(String_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbufAnimation(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_pixbuf_animation_new_from_resource(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("PixbufAnimation requires GdkPixbuf >= 2.28");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_animation_new_from_stream(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
GError *error = NULL;
    
GdkPixbufAnimation *obj = gdk_pixbuf_animation_new_from_stream(GInputStream_val(arg1), Option_val(arg2, GCancellable_val, NULL), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbufAnimation(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_pixbuf_animation_new_from_stream(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("PixbufAnimation requires GdkPixbuf >= 2.28");
return Val_unit;
}
#endif

#if GDK_PIXBUF_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_gdk_pixbuf_animation_new_from_stream_finish(value arg1)
{
CAMLparam1(arg1);
GError *error = NULL;
    
GdkPixbufAnimation *obj = gdk_pixbuf_animation_new_from_stream_finish(GAsyncResult_val(arg1), &error);
if (obj) g_object_ref_sink(obj);

if (error == NULL) CAMLreturn(Res_Ok(Val_GdkPixbufAnimation(obj))); else CAMLreturn(Res_Error(Val_GError(error)));
}
#else

CAMLexport CAMLprim value ml_gdk_pixbuf_animation_new_from_stream_finish(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("PixbufAnimation requires GdkPixbuf >= 2.28");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_pixbuf_animation_is_static_image(value self)
{
CAMLparam1(self);

gboolean result = gdk_pixbuf_animation_is_static_image(GdkPixbufAnimation_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_animation_get_width(value self)
{
CAMLparam1(self);

int result = gdk_pixbuf_animation_get_width(GdkPixbufAnimation_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_animation_get_static_image(value self)
{
CAMLparam1(self);

GdkPixbuf* result = gdk_pixbuf_animation_get_static_image(GdkPixbufAnimation_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkPixbuf(result));
}

CAMLexport CAMLprim value ml_gdk_pixbuf_animation_get_height(value self)
{
CAMLparam1(self);

int result = gdk_pixbuf_animation_get_height(GdkPixbufAnimation_val(self));
CAMLreturn(Val_int(result));
}


CAMLprim value ml_gdk_pixbuf_pixbuf_animation_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_pixbuf_animation_get_type()));
}
