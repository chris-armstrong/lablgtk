/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Popup */

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


CAMLexport CAMLprim value ml_gdk_popup_present(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

gboolean result = gdk_popup_present(GdkPopup_val(self), Int_val(arg1), Int_val(arg2), GdkPopupLayout_val(arg3));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gdk_popup_get_surface_anchor(value self)
{
CAMLparam1(self);

GdkGravity result = gdk_popup_get_surface_anchor(GdkPopup_val(self));
CAMLreturn(Val_GdkGravity(result));
}

CAMLexport CAMLprim value ml_gdk_popup_get_rect_anchor(value self)
{
CAMLparam1(self);

GdkGravity result = gdk_popup_get_rect_anchor(GdkPopup_val(self));
CAMLreturn(Val_GdkGravity(result));
}

CAMLexport CAMLprim value ml_gdk_popup_get_position_y(value self)
{
CAMLparam1(self);

int result = gdk_popup_get_position_y(GdkPopup_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_popup_get_position_x(value self)
{
CAMLparam1(self);

int result = gdk_popup_get_position_x(GdkPopup_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gdk_popup_get_parent(value self)
{
CAMLparam1(self);

GdkSurface* result = gdk_popup_get_parent(GdkPopup_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GdkSurface));
}

CAMLexport CAMLprim value ml_gdk_popup_get_autohide(value self)
{
CAMLparam1(self);

gboolean result = gdk_popup_get_autohide(GdkPopup_val(self));
CAMLreturn(Val_bool(result));
}
CAMLexport CAMLprim value ml_gdk_popup_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GDK_TYPE_POPUP)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GdkPopup");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GdkPopup((GdkPopup*)gobj));
}


CAMLprim value ml_gdk_popup_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_popup_get_type()));
}
