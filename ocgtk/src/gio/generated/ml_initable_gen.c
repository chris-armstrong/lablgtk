/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Initable */

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

#if GLIB_CHECK_VERSION(2,22,0)


CAMLexport CAMLprim value ml_g_initable_init(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = g_initable_init(GInitable_val(self), Option_val(arg1, GCancellable_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}
CAMLexport CAMLprim value ml_gio_initable_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_INITABLE)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GInitable");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GInitable((GInitable*)gobj));
}

GType g_initable_get_type (void);


CAMLprim value ml_gio_initable_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_initable_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_initable_init(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Initable requires GLib >= 2.22");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_initable_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("Initable requires GTK >= 2.22");
    return Val_unit;
}


#endif
