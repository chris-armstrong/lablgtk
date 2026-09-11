/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DevicePad */

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


CAMLexport CAMLprim value ml_gdk_device_pad_get_n_groups(value self)
{
CAMLparam1(self);

int result = gdk_device_pad_get_n_groups(GdkDevicePad_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_device_pad_get_n_features(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gdk_device_pad_get_n_features(GdkDevicePad_val(self), GdkDevicePadFeature_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_device_pad_get_group_n_modes(value self, value arg1)
{
CAMLparam2(self, arg1);

int result = gdk_device_pad_get_group_n_modes(GdkDevicePad_val(self), Int_val(arg1));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_device_pad_get_feature_group(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

int result = gdk_device_pad_get_feature_group(GdkDevicePad_val(self), GdkDevicePadFeature_val(arg1), Int_val(arg2));
CAMLreturn(Val_int(result));
}
CAMLexport CAMLprim value ml_gdk_device_pad_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GDK_TYPE_DEVICE_PAD)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GdkDevicePad");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GdkDevicePad((GdkDevicePad*)gobj));
}

GType gdk_device_pad_get_type (void);


CAMLprim value ml_gdk_device_pad_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_device_pad_get_type()));
}
