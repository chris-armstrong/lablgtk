/* GENERATED CODE - DO NOT EDIT */
/* C bindings for SimpleAction */

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


#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_simple_action_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GSimpleAction *obj = g_simple_action_new(String_val(arg1), Option_val(arg2, GVariantType_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GSimpleAction(obj));
}
#else

CAMLexport CAMLprim value ml_g_simple_action_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("SimpleAction requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_simple_action_new_stateful(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GSimpleAction *obj = g_simple_action_new_stateful(String_val(arg1), Option_val(arg2, GVariantType_val, NULL), GVariant_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GSimpleAction(obj));
}
#else

CAMLexport CAMLprim value ml_g_simple_action_new_stateful(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("SimpleAction requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_simple_action_set_state_hint(value self, value arg1)
{
CAMLparam2(self, arg1);

g_simple_action_set_state_hint(GSimpleAction_val(self), Option_val(arg1, GVariant_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_simple_action_set_state_hint(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SimpleAction requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_simple_action_set_state(value self, value arg1)
{
CAMLparam2(self, arg1);

g_simple_action_set_state(GSimpleAction_val(self), GVariant_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_simple_action_set_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SimpleAction requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_simple_action_set_enabled(value self, value arg1)
{
CAMLparam2(self, arg1);

g_simple_action_set_enabled(GSimpleAction_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_simple_action_set_enabled(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("SimpleAction requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_simple_action_get_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSimpleAction *obj = (GSimpleAction *)GSimpleAction_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "name");
if (pspec == NULL) caml_failwith("ml_g_simple_action_get_name: property 'name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_simple_action_get_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SimpleAction requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_simple_action_get_parameter_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSimpleAction *obj = (GSimpleAction *)GSimpleAction_val(self);
    GVariantType* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "parameter-type");
if (pspec == NULL) caml_failwith("ml_g_simple_action_get_parameter_type: property 'parameter-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "parameter-type", &prop_gvalue);
          prop_value = (GVariantType*)g_value_get_pointer(&prop_gvalue);

      result = Val_GVariantType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_simple_action_get_parameter_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SimpleAction requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_simple_action_get_state_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GSimpleAction *obj = (GSimpleAction *)GSimpleAction_val(self);
    GVariantType* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "state-type");
if (pspec == NULL) caml_failwith("ml_g_simple_action_get_state_type: property 'state-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "state-type", &prop_gvalue);
          prop_value = (GVariantType*)g_value_get_pointer(&prop_gvalue);

      result = Val_GVariantType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_simple_action_get_state_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("SimpleAction requires GLib >= 2.28");
return Val_unit;
}
#endif


CAMLprim value ml_gio_simple_action_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_simple_action_get_type()));
}
