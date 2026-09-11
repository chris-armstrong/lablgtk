/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Scrollable */

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


CAMLexport CAMLprim value ml_gtk_scrollable_set_vscroll_policy(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrollable_set_vscroll_policy(GtkScrollable_val(self), GtkScrollablePolicy_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrollable_set_vadjustment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrollable_set_vadjustment(GtkScrollable_val(self), Option_val(arg1, GtkAdjustment_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrollable_set_hscroll_policy(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrollable_set_hscroll_policy(GtkScrollable_val(self), GtkScrollablePolicy_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrollable_set_hadjustment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scrollable_set_hadjustment(GtkScrollable_val(self), Option_val(arg1, GtkAdjustment_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scrollable_get_vscroll_policy(value self)
{
CAMLparam1(self);

GtkScrollablePolicy result = gtk_scrollable_get_vscroll_policy(GtkScrollable_val(self));
CAMLreturn(Val_GtkScrollablePolicy(result));
}

CAMLexport CAMLprim value ml_gtk_scrollable_get_vadjustment(value self)
{
CAMLparam1(self);

GtkAdjustment* result = gtk_scrollable_get_vadjustment(GtkScrollable_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkAdjustment));
}

CAMLexport CAMLprim value ml_gtk_scrollable_get_hscroll_policy(value self)
{
CAMLparam1(self);

GtkScrollablePolicy result = gtk_scrollable_get_hscroll_policy(GtkScrollable_val(self));
CAMLreturn(Val_GtkScrollablePolicy(result));
}

CAMLexport CAMLprim value ml_gtk_scrollable_get_hadjustment(value self)
{
CAMLparam1(self);

GtkAdjustment* result = gtk_scrollable_get_hadjustment(GtkScrollable_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkAdjustment));
}

CAMLexport CAMLprim value ml_gtk_scrollable_get_border(value self)
{
CAMLparam1(self);
GtkBorder out1;

gboolean result = gtk_scrollable_get_border(GtkScrollable_val(self), &out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GtkBorder(&out1));
    CAMLreturn(ret);
}
CAMLexport CAMLprim value ml_gtk_scrollable_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_SCROLLABLE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkScrollable");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkScrollable((GtkScrollable*)gobj));
}

GType gtk_scrollable_get_type (void);


CAMLprim value ml_gtk_scrollable_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_scrollable_get_type()));
}
