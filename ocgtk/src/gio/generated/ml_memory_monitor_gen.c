/* GENERATED CODE - DO NOT EDIT */
/* C bindings for MemoryMonitor */

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

#if GLIB_CHECK_VERSION(2,64,0)

CAMLexport CAMLprim value ml_gio_memory_monitor_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_MEMORY_MONITOR)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GMemoryMonitor");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GMemoryMonitor((GMemoryMonitor*)gobj));
}


CAMLprim value ml_gio_memory_monitor_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_memory_monitor_get_type()));
}

#else

CAMLexport CAMLprim value ml_gio_memory_monitor_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("MemoryMonitor requires GTK >= 2.64");
    return Val_unit;
}


#endif
