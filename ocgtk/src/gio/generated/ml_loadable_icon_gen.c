/* GENERATED CODE - DO NOT EDIT */
/* C bindings for LoadableIcon */

#include <gio/gio.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gio/gio.h>
/* Include library-specific type conversions and forward declarations */
#include "gio_decls.h"

CAMLexport CAMLprim value ml_gio_loadable_icon_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_LOADABLE_ICON)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GLoadableIcon");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GLoadableIcon((GLoadableIcon*)gobj));
}

GType g_loadable_icon_get_type (void);


CAMLprim value ml_gio_loadable_icon_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_loadable_icon_get_type()));
}
