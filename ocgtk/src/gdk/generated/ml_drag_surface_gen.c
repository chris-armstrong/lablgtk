/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DragSurface */

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


CAMLexport CAMLprim value ml_gdk_drag_surface_present(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gdk_drag_surface_present(GdkDragSurface_val(self), Int_val(arg1), Int_val(arg2));
CAMLreturn(Val_bool(result));
}
CAMLexport CAMLprim value ml_gdk_drag_surface_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GDK_TYPE_DRAG_SURFACE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GdkDragSurface");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GdkDragSurface((GdkDragSurface*)gobj));
}


CAMLprim value ml_gdk_drag_surface_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gdk_drag_surface_get_type()));
}
