/* GENERATED CODE - DO NOT EDIT */
/* C bindings for EmblemedIcon */

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


#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_emblemed_icon_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GEmblemedIcon *obj = g_emblemed_icon_new(GIcon_val(arg1), Option_val(arg2, GEmblem_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GEmblemedIcon(obj));
}
#else

CAMLexport CAMLprim value ml_g_emblemed_icon_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("EmblemedIcon requires GLib >= 2.18");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_emblemed_icon_get_icon(value self)
{
CAMLparam1(self);

GIcon* result = g_emblemed_icon_get_icon(GEmblemedIcon_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GIcon(result));
}

#else

CAMLexport CAMLprim value ml_g_emblemed_icon_get_icon(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("EmblemedIcon requires GLib >= 2.18");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_emblemed_icon_get_emblems(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = g_emblemed_icon_get_emblems(GEmblemedIcon_val(self));
Val_GList_with(c_result, result, item, cell, Val_GEmblem((gpointer)_tmp->data));
    CAMLreturn(result);
}

#else

CAMLexport CAMLprim value ml_g_emblemed_icon_get_emblems(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("EmblemedIcon requires GLib >= 2.18");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_emblemed_icon_clear_emblems(value self)
{
CAMLparam1(self);

g_emblemed_icon_clear_emblems(GEmblemedIcon_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_emblemed_icon_clear_emblems(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("EmblemedIcon requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_emblemed_icon_add_emblem(value self, value arg1)
{
CAMLparam2(self, arg1);

g_emblemed_icon_add_emblem(GEmblemedIcon_val(self), GEmblem_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_emblemed_icon_add_emblem(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("EmblemedIcon requires GLib >= 2.18");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_emblemed_icon_get_gicon(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GEmblemedIcon *obj = (GEmblemedIcon *)GEmblemedIcon_val(self);
    GIcon *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "gicon");
if (pspec == NULL) caml_failwith("ml_g_emblemed_icon_get_gicon: property 'gicon' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "gicon", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GIcon(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_emblemed_icon_get_gicon(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("EmblemedIcon requires GLib >= 2.18");
return Val_unit;
}
#endif

GType g_emblemed_icon_get_type (void);


CAMLprim value ml_gio_emblemed_icon_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_emblemed_icon_get_type()));
}
