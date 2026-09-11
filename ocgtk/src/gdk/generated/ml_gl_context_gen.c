/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GLContext */

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


CAMLexport CAMLprim value ml_gdk_gl_context_set_use_es(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_context_set_use_es(GdkGLContext_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_gl_context_set_required_version(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gdk_gl_context_set_required_version(GdkGLContext_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_gl_context_set_forward_compatible(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_context_set_forward_compatible(GdkGLContext_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_gl_context_set_debug_enabled(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_context_set_debug_enabled(GdkGLContext_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gdk_gl_context_set_allowed_apis(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_gl_context_set_allowed_apis(GdkGLContext_val(self), GdkGLAPI_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gdk_gl_context_set_allowed_apis(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLContext requires GTK >= 4.6");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_gl_context_realize(value self)
{
CAMLparam1(self);
GError *error = NULL;

gboolean result = gdk_gl_context_realize(GdkGLContext_val(self), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gdk_gl_context_make_current(value self)
{
CAMLparam1(self);

gdk_gl_context_make_current(GdkGLContext_val(self));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,4,0)

CAMLexport CAMLprim value ml_gdk_gl_context_is_shared(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gdk_gl_context_is_shared(GdkGLContext_val(self), GdkGLContext_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gdk_gl_context_is_shared(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLContext requires GTK >= 4.4");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gdk_gl_context_is_legacy(value self)
{
CAMLparam1(self);

gboolean result = gdk_gl_context_is_legacy(GdkGLContext_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_gl_context_get_version(value self)
{
CAMLparam1(self);
int out1;
int out2;

gdk_gl_context_get_version(GdkGLContext_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_gl_context_get_use_es(value self)
{
CAMLparam1(self);

gboolean result = gdk_gl_context_get_use_es(GdkGLContext_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_gl_context_get_surface(value self)
{
CAMLparam1(self);

GdkSurface* result = gdk_gl_context_get_surface(GdkGLContext_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkSurface));
}

CAMLexport CAMLprim value ml_gdk_gl_context_get_shared_context(value self)
{
CAMLparam1(self);

GdkGLContext* result = gdk_gl_context_get_shared_context(GdkGLContext_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkGLContext));
}

CAMLexport CAMLprim value ml_gdk_gl_context_get_required_version(value self)
{
CAMLparam1(self);
int out1;
int out2;

gdk_gl_context_get_required_version(GdkGLContext_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gdk_gl_context_get_forward_compatible(value self)
{
CAMLparam1(self);

gboolean result = gdk_gl_context_get_forward_compatible(GdkGLContext_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_gl_context_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gdk_gl_context_get_display(GdkGLContext_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDisplay));
}

CAMLexport CAMLprim value ml_gdk_gl_context_get_debug_enabled(value self)
{
CAMLparam1(self);

gboolean result = gdk_gl_context_get_debug_enabled(GdkGLContext_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gdk_gl_context_get_api(value self)
{
CAMLparam1(self);

GdkGLAPI result = gdk_gl_context_get_api(GdkGLContext_val(self));
CAMLreturn(Val_GdkGLAPI(result));
}

#else

CAMLexport CAMLprim value ml_gdk_gl_context_get_api(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLContext requires GTK >= 4.6");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,6,0)

CAMLexport CAMLprim value ml_gdk_gl_context_get_allowed_apis(value self)
{
CAMLparam1(self);

GdkGLAPI result = gdk_gl_context_get_allowed_apis(GdkGLContext_val(self));
CAMLreturn(Val_GdkGLAPI(result));
}

#else

CAMLexport CAMLprim value ml_gdk_gl_context_get_allowed_apis(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLContext requires GTK >= 4.6");
return Val_unit;
}
#endif


CAMLprim value ml_gdk_gl_context_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_gl_context_get_type()));
}
