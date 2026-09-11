/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DebugController */

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

#if GLIB_CHECK_VERSION(2,72,0)


CAMLexport CAMLprim value ml_g_debug_controller_set_debug_enabled(value self, value arg1)
{
CAMLparam2(self, arg1);

g_debug_controller_set_debug_enabled(GDebugController_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_debug_controller_get_debug_enabled(value self)
{
CAMLparam1(self);

gboolean result = g_debug_controller_get_debug_enabled(GDebugController_val(self));
CAMLreturn(Val_bool(result));
}
CAMLexport CAMLprim value ml_gio_debug_controller_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_DEBUG_CONTROLLER)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GDebugController");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GDebugController((GDebugController*)gobj));
}


CAMLprim value ml_gio_debug_controller_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_debug_controller_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_debug_controller_get_debug_enabled(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DebugController requires GLib >= 2.72");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_debug_controller_set_debug_enabled(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("DebugController requires GLib >= 2.72");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_debug_controller_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("DebugController requires GTK >= 2.72");
    return Val_unit;
}


#endif
