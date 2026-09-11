/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DisplayManager */

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


CAMLexport CAMLprim value ml_gdk_display_manager_set_default_display(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_display_manager_set_default_display(GdkDisplayManager_val(self), GdkDisplay_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_display_manager_open_display(value self, value arg1)
{
CAMLparam2(self, arg1);

GdkDisplay* result = gdk_display_manager_open_display(GdkDisplayManager_val(self), String_option_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDisplay));
}

CAMLexport CAMLprim value ml_gdk_display_manager_list_displays(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gdk_display_manager_list_displays(GdkDisplayManager_val(self));
Val_GSList_with(c_result, result, item, cell, Val_GdkDisplay((gpointer)_tmp->data));
    g_slist_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gdk_display_manager_get_default_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gdk_display_manager_get_default_display(GdkDisplayManager_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkDisplay));
}


CAMLprim value ml_gdk_display_manager_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_display_manager_get_type()));
}
