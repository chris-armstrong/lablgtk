/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Action */

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

CAMLexport CAMLprim value ml_g_action_get_state_type(value self)
{
CAMLparam1(self);

const GVariantType* result = g_action_get_state_type(GAction_val(self));
CAMLreturn(Val_option(result, Val_GVariantType));
}

#else

CAMLexport CAMLprim value ml_g_action_get_state_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Action requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_get_state_hint(value self)
{
CAMLparam1(self);

GVariant* result = g_action_get_state_hint(GAction_val(self));
CAMLreturn(Val_option(result, Val_GVariant));
}

#else

CAMLexport CAMLprim value ml_g_action_get_state_hint(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Action requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_get_state(value self)
{
CAMLparam1(self);

GVariant* result = g_action_get_state(GAction_val(self));
CAMLreturn(Val_option(result, Val_GVariant));
}

#else

CAMLexport CAMLprim value ml_g_action_get_state(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Action requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_get_parameter_type(value self)
{
CAMLparam1(self);

const GVariantType* result = g_action_get_parameter_type(GAction_val(self));
CAMLreturn(Val_option(result, Val_GVariantType));
}

#else

CAMLexport CAMLprim value ml_g_action_get_parameter_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Action requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_get_name(value self)
{
CAMLparam1(self);

const gchar* result = g_action_get_name(GAction_val(self));
CAMLreturn(caml_copy_string(result));
}

#else

CAMLexport CAMLprim value ml_g_action_get_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Action requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_get_enabled(value self)
{
CAMLparam1(self);

gboolean result = g_action_get_enabled(GAction_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_action_get_enabled(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Action requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,30,0)

CAMLexport CAMLprim value ml_g_action_change_state(value self, value arg1)
{
CAMLparam2(self, arg1);

g_action_change_state(GAction_val(self), GVariant_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_action_change_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Action requires GLib >= 2.30");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_activate(value self, value arg1)
{
CAMLparam2(self, arg1);

g_action_activate(GAction_val(self), Option_val(arg1, GVariant_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_action_activate(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Action requires GLib >= 2.28");
return Val_unit;
}
#endif
CAMLexport CAMLprim value ml_gio_action_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_ACTION)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GAction");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GAction((GAction*)gobj));
}

GType g_action_get_type (void);


CAMLprim value ml_gio_action_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_action_get_type()));
}
