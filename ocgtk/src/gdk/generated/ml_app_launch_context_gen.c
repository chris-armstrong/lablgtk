/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AppLaunchContext */

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


CAMLexport CAMLprim value ml_gdk_app_launch_context_set_timestamp(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_app_launch_context_set_timestamp(GdkAppLaunchContext_val(self), UInt32_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_app_launch_context_set_icon_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_app_launch_context_set_icon_name(GdkAppLaunchContext_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_app_launch_context_set_icon(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_app_launch_context_set_icon(GdkAppLaunchContext_val(self), Option_val(arg1, GIcon_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_app_launch_context_set_desktop(value self, value arg1)
{
CAMLparam2(self, arg1);

gdk_app_launch_context_set_desktop(GdkAppLaunchContext_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gdk_app_launch_context_get_display(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GdkAppLaunchContext *obj = (GdkAppLaunchContext *)GdkAppLaunchContext_val(self);
    GdkDisplay *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "display");
if (pspec == NULL) caml_failwith("ml_gdk_app_launch_context_get_display: property 'display' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "display", &prop_gvalue);
          prop_value = (GdkDisplay*)g_value_dup_object(&prop_gvalue);

      result = Val_GdkDisplay(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gdk_app_launch_context_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_app_launch_context_get_type()));
}
