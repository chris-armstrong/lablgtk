/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Converter */

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

#if GLIB_CHECK_VERSION(2,24,0)


CAMLexport CAMLprim value ml_g_converter_reset(value self)
{
CAMLparam1(self);

g_converter_reset(GConverter_val(self));
CAMLreturn(Val_unit);
}

#if GLIB_CHECK_VERSION(2,82,0)

CAMLexport CAMLprim value ml_g_converter_convert_bytes(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GBytes* result = g_converter_convert_bytes(GConverter_val(self), GBytes_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GBytes(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

#else

CAMLexport CAMLprim value ml_g_converter_convert_bytes(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Converter requires GLib >= 2.82");
return Val_unit;
}
#endif
CAMLexport CAMLprim value ml_gio_converter_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_CONVERTER)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GConverter");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GConverter((GConverter*)gobj));
}


CAMLprim value ml_gio_converter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_converter_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_converter_convert_bytes(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Converter requires GLib >= 2.24");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_converter_reset(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Converter requires GLib >= 2.24");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_converter_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("Converter requires GTK >= 2.24");
    return Val_unit;
}


#endif
