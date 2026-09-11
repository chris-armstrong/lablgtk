/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Native */

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


CAMLexport CAMLprim value ml_gtk_native_unrealize(value self)
{
CAMLparam1(self);

gtk_native_unrealize(GtkNative_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_native_realize(value self)
{
CAMLparam1(self);

gtk_native_realize(GtkNative_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_native_get_surface_transform(value self)
{
CAMLparam1(self);
double out1;
double out2;

gtk_native_get_surface_transform(GtkNative_val(self), &out1, &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, caml_copy_double(out1));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_native_get_surface(value self)
{
CAMLparam1(self);

GdkSurface* result = gtk_native_get_surface(GtkNative_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkSurface));
}

CAMLexport CAMLprim value ml_gtk_native_get_renderer(value self)
{
CAMLparam1(self);

GskRenderer* result = gtk_native_get_renderer(GtkNative_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GskRenderer));
}
CAMLexport CAMLprim value ml_gtk_native_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_NATIVE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkNative");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkNative((GtkNative*)gobj));
}

GType gtk_native_get_type (void);


CAMLprim value ml_gtk_native_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_native_get_type()));
}
