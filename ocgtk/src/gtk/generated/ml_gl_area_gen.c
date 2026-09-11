/* GENERATED CODE - DO NOT EDIT */
/* C bindings for GLArea */

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


CAMLexport CAMLprim value ml_gtk_gl_area_new(value unit)
{
CAMLparam1(unit);

GtkGLArea *obj = gtk_gl_area_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkGLArea(obj));
}
CAMLexport CAMLprim value ml_gtk_gl_area_set_use_es(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_gl_area_set_use_es(GtkGLArea_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gl_area_set_required_version(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_gl_area_set_required_version(GtkGLArea_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gl_area_set_has_stencil_buffer(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_gl_area_set_has_stencil_buffer(GtkGLArea_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gl_area_set_has_depth_buffer(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_gl_area_set_has_depth_buffer(GtkGLArea_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gl_area_set_error(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_gl_area_set_error(GtkGLArea_val(self), Option_val(arg1, GError_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gl_area_set_auto_render(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_gl_area_set_auto_render(GtkGLArea_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_gl_area_set_allowed_apis(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_gl_area_set_allowed_apis(GtkGLArea_val(self), GdkGLAPI_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_gl_area_set_allowed_apis(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("GLArea requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_gl_area_queue_render(value self)
{
CAMLparam1(self);

gtk_gl_area_queue_render(GtkGLArea_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gl_area_make_current(value self)
{
CAMLparam1(self);

gtk_gl_area_make_current(GtkGLArea_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_gl_area_get_use_es(value self)
{
CAMLparam1(self);

gboolean result = gtk_gl_area_get_use_es(GtkGLArea_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_gl_area_get_required_version(value self)
{
CAMLparam1(self);
int out1;
int out2;

gtk_gl_area_get_required_version(GtkGLArea_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_int(out1));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_gl_area_get_has_stencil_buffer(value self)
{
CAMLparam1(self);

gboolean result = gtk_gl_area_get_has_stencil_buffer(GtkGLArea_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_gl_area_get_has_depth_buffer(value self)
{
CAMLparam1(self);

gboolean result = gtk_gl_area_get_has_depth_buffer(GtkGLArea_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_gl_area_get_error(value self)
{
CAMLparam1(self);

GError* result = gtk_gl_area_get_error(GtkGLArea_val(self));
CAMLreturn(Val_option(result, Val_GError));
}

CAMLexport CAMLprim value ml_gtk_gl_area_get_context(value self)
{
CAMLparam1(self);

GdkGLContext* result = gtk_gl_area_get_context(GtkGLArea_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkGLContext));
}

CAMLexport CAMLprim value ml_gtk_gl_area_get_auto_render(value self)
{
CAMLparam1(self);

gboolean result = gtk_gl_area_get_auto_render(GtkGLArea_val(self));
CAMLreturn(Val_bool(result));
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_gl_area_get_api(value self)
{
CAMLparam1(self);

GdkGLAPI result = gtk_gl_area_get_api(GtkGLArea_val(self));
CAMLreturn(Val_GdkGLAPI(result));
}

#else

CAMLexport CAMLprim value ml_gtk_gl_area_get_api(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLArea requires GTK >= 4.12");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_gl_area_get_allowed_apis(value self)
{
CAMLparam1(self);

GdkGLAPI result = gtk_gl_area_get_allowed_apis(GtkGLArea_val(self));
CAMLreturn(Val_GdkGLAPI(result));
}

#else

CAMLexport CAMLprim value ml_gtk_gl_area_get_allowed_apis(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("GLArea requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_gl_area_attach_buffers(value self)
{
CAMLparam1(self);

gtk_gl_area_attach_buffers(GtkGLArea_val(self));
CAMLreturn(Val_unit);
}

GType gtk_gl_area_get_type (void);


CAMLprim value ml_gtk_gl_area_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_gl_area_get_type()));
}
