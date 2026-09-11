/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Root */

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


CAMLexport CAMLprim value ml_gtk_root_set_focus(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_root_set_focus(GtkRoot_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_root_get_focus(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_root_get_focus(GtkRoot_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_root_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gtk_root_get_display(GtkRoot_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDisplay(result));
}
CAMLexport CAMLprim value ml_gtk_root_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_ROOT)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkRoot");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkRoot((GtkRoot*)gobj));
}

GType gtk_root_get_type (void);


CAMLprim value ml_gtk_root_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_root_get_type()));
}
