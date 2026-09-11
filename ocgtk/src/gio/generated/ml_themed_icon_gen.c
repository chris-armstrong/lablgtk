/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ThemedIcon */

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


CAMLexport CAMLprim value ml_g_themed_icon_new(value arg1)
{
CAMLparam1(arg1);

GThemedIcon *obj = g_themed_icon_new(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GThemedIcon(obj));
}
CAMLexport CAMLprim value ml_g_themed_icon_new_from_names(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
    int arg1_length = Wosize_val(arg1);
    const char** c_arg1 = (const char**)g_malloc(sizeof(const char*) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = String_val(Field(arg1, i));
    }

GThemedIcon *obj = g_themed_icon_new_from_names(c_arg1, Int_val(arg2));
if (obj) g_object_ref_sink(obj);

    g_free(c_arg1);
CAMLreturn(Val_GThemedIcon(obj));
}
CAMLexport CAMLprim value ml_g_themed_icon_new_with_default_fallbacks(value arg1)
{
CAMLparam1(arg1);

GThemedIcon *obj = g_themed_icon_new_with_default_fallbacks(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GThemedIcon(obj));
}
#if GLIB_CHECK_VERSION(2,18,0)

CAMLexport CAMLprim value ml_g_themed_icon_prepend_name(value self, value arg1)
{
CAMLparam2(self, arg1);

g_themed_icon_prepend_name(GThemedIcon_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_themed_icon_prepend_name(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ThemedIcon requires GLib >= 2.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_themed_icon_get_names(value self)
{
CAMLparam1(self);

const gchar* const* result = g_themed_icon_get_names(GThemedIcon_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
CAMLreturn(ml_result);
}

CAMLexport CAMLprim value ml_g_themed_icon_append_name(value self, value arg1)
{
CAMLparam2(self, arg1);

g_themed_icon_append_name(GThemedIcon_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_themed_icon_get_use_default_fallbacks(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GThemedIcon *obj = (GThemedIcon *)GThemedIcon_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "use-default-fallbacks");
if (pspec == NULL) caml_failwith("ml_g_themed_icon_get_use_default_fallbacks: property 'use-default-fallbacks' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "use-default-fallbacks", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gio_themed_icon_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_themed_icon_get_type()));
}
