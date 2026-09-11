/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PropertyAction */

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

#if GLIB_CHECK_VERSION(2,38,0)


CAMLexport CAMLprim value ml_g_property_action_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GPropertyAction *obj = g_property_action_new(String_val(arg1), GObject_ext_of_val(arg2), String_val(arg3));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GPropertyAction(obj));
}
CAMLexport CAMLprim value ml_g_property_action_get_enabled(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GPropertyAction *obj = (GPropertyAction *)GPropertyAction_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "enabled");
if (pspec == NULL) caml_failwith("ml_g_property_action_get_enabled: property 'enabled' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "enabled", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#if GLIB_CHECK_VERSION(2,46,0)

CAMLexport CAMLprim value ml_g_property_action_get_invert_boolean(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GPropertyAction *obj = (GPropertyAction *)GPropertyAction_val(self);
    gboolean *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "invert-boolean");
if (pspec == NULL) caml_failwith("ml_g_property_action_get_invert_boolean: property 'invert-boolean' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "invert-boolean", &prop_gvalue);
          prop_value = g_value_get_boolean(&prop_gvalue);

      result = Val_bool(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_property_action_get_invert_boolean(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PropertyAction requires GLib >= 2.46");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_property_action_get_name(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GPropertyAction *obj = (GPropertyAction *)GPropertyAction_val(self);
    gchar* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "name");
if (pspec == NULL) caml_failwith("ml_g_property_action_get_name: property 'name' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "name", &prop_gvalue);
          prop_value = g_value_get_string(&prop_gvalue);

      result = caml_copy_string(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_property_action_get_parameter_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GPropertyAction *obj = (GPropertyAction *)GPropertyAction_val(self);
    GVariantType* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "parameter-type");
if (pspec == NULL) caml_failwith("ml_g_property_action_get_parameter_type: property 'parameter-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "parameter-type", &prop_gvalue);
          prop_value = (GVariantType*)g_value_get_pointer(&prop_gvalue);

      result = Val_GVariantType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_property_action_get_state(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GPropertyAction *obj = (GPropertyAction *)GPropertyAction_val(self);
    GVariant* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "state");
if (pspec == NULL) caml_failwith("ml_g_property_action_get_state: property 'state' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "state", &prop_gvalue);
          prop_value = g_variant_ref(g_value_get_variant(&prop_gvalue));

      result = Val_GVariant(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

CAMLexport CAMLprim value ml_g_property_action_get_state_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GPropertyAction *obj = (GPropertyAction *)GPropertyAction_val(self);
    GVariantType* *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "state-type");
if (pspec == NULL) caml_failwith("ml_g_property_action_get_state_type: property 'state-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "state-type", &prop_gvalue);
          prop_value = (GVariantType*)g_value_get_pointer(&prop_gvalue);

      result = Val_GVariantType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}


CAMLprim value ml_gio_property_action_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_property_action_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_property_action_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("PropertyAction requires GLib >= 2.38");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_property_action_get_enabled(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PropertyAction requires GLib >= 2.38");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_property_action_get_invert_boolean(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PropertyAction requires GLib >= 2.38");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_property_action_get_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PropertyAction requires GLib >= 2.38");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_property_action_get_parameter_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PropertyAction requires GLib >= 2.38");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_property_action_get_state(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PropertyAction requires GLib >= 2.38");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_property_action_get_state_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PropertyAction requires GLib >= 2.38");
return Val_unit;
}


#endif
