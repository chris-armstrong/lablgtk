/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Paintable */

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


CAMLexport CAMLprim value ml_gdk_paintable_snapshot(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gdk_paintable_snapshot(GdkPaintable_val(self), GdkSnapshot_val(arg1), Double_val(arg2), Double_val(arg3));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_paintable_invalidate_size(value self)
{
CAMLparam1(self);

gdk_paintable_invalidate_size(GdkPaintable_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_paintable_invalidate_contents(value self)
{
CAMLparam1(self);

gdk_paintable_invalidate_contents(GdkPaintable_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_paintable_get_intrinsic_width(value self)
{
CAMLparam1(self);

int result = gdk_paintable_get_intrinsic_width(GdkPaintable_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_paintable_get_intrinsic_height(value self)
{
CAMLparam1(self);

int result = gdk_paintable_get_intrinsic_height(GdkPaintable_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_paintable_get_intrinsic_aspect_ratio(value self)
{
CAMLparam1(self);

double result = gdk_paintable_get_intrinsic_aspect_ratio(GdkPaintable_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gdk_paintable_get_flags(value self)
{
CAMLparam1(self);

GdkPaintableFlags result = gdk_paintable_get_flags(GdkPaintable_val(self));
CAMLreturn(Val_GdkPaintableFlags(result));
}

CAMLexport CAMLprim value ml_gdk_paintable_get_current_image(value self)
{
CAMLparam1(self);

GdkPaintable* result = gdk_paintable_get_current_image(GdkPaintable_val(self));
CAMLreturn(Val_GdkPaintable(result));
}

CAMLexport CAMLprim value ml_gdk_paintable_compute_concrete_size(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
double out5;
double out6;

gdk_paintable_compute_concrete_size(GdkPaintable_val(self), Double_val(arg1), Double_val(arg2), Double_val(arg3), Double_val(arg4), &out5, &out6);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(out5));
    Store_field(ret, 1, caml_copy_double(out6));
    CAMLreturn(ret);
}
CAMLexport CAMLprim value ml_gdk_paintable_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GDK_TYPE_PAINTABLE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GdkPaintable");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GdkPaintable((GdkPaintable*)gobj));
}

GType gdk_paintable_get_type (void);


CAMLprim value ml_gdk_paintable_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_paintable_get_type()));
}
