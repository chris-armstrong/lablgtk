/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Icon */

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


#if GLIB_CHECK_VERSION(2,20,0)

CAMLexport CAMLprim value ml_g_icon_to_string(value self)
{
CAMLparam1(self);

gchar* result = g_icon_to_string(GIcon_val(self));
CAMLreturn(Val_option_string(result));
}

#else

CAMLexport CAMLprim value ml_g_icon_to_string(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Icon requires GLib >= 2.20");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,38,0)

CAMLexport CAMLprim value ml_g_icon_serialize(value self)
{
CAMLparam1(self);

GVariant* result = g_icon_serialize(GIcon_val(self));
CAMLreturn(Val_option(result, Val_GVariant));
}

#else

CAMLexport CAMLprim value ml_g_icon_serialize(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Icon requires GLib >= 2.38");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_icon_hash(value self)
{
CAMLparam1(self);

guint result = g_icon_hash(GIcon_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_g_icon_equal(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_icon_equal(GIcon_val(self), Option_val(arg1, GIcon_val, NULL));
CAMLreturn(Val_bool(result));
}
CAMLexport CAMLprim value ml_gio_icon_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_ICON)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GIcon");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GIcon((GIcon*)gobj));
}

GType g_icon_get_type (void);


CAMLprim value ml_gio_icon_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_icon_get_type()));
}
