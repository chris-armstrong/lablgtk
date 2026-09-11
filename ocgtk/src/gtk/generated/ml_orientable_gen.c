/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Orientable */

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


CAMLexport CAMLprim value ml_gtk_orientable_set_orientation(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_orientable_set_orientation(GtkOrientable_val(self), GtkOrientation_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_orientable_get_orientation(value self)
{
CAMLparam1(self);

GtkOrientation result = gtk_orientable_get_orientation(GtkOrientable_val(self));
CAMLreturn(Val_GtkOrientation(result));
}
CAMLexport CAMLprim value ml_gtk_orientable_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_ORIENTABLE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkOrientable");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkOrientable((GtkOrientable*)gobj));
}


CAMLprim value ml_gtk_orientable_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_orientable_get_type()));
}
