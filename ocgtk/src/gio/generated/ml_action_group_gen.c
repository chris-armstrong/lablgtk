/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ActionGroup */

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

CAMLexport CAMLprim value ml_g_action_group_list_actions(value self)
{
CAMLparam1(self);

gchar** result = g_action_group_list_actions(GActionGroup_val(self));
    int result_length = 0;
    while (result[result_length] != NULL) result_length++;
    CAMLlocal1(ml_result);
    ml_result = caml_alloc(result_length, 0);
    for (int i = 0; i < result_length; i++) {
      Store_field(ml_result, i, caml_copy_string(result[i]));
    }
    for (int i = 0; i < result_length; i++) {
      g_free((gpointer)result[i]);
    }
    g_free(result);
CAMLreturn(ml_result);
}

#else

CAMLexport CAMLprim value ml_g_action_group_list_actions(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_group_has_action(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_action_group_has_action(GActionGroup_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_action_group_has_action(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_group_get_action_state_type(value self, value arg1)
{
CAMLparam2(self, arg1);

const GVariantType* result = g_action_group_get_action_state_type(GActionGroup_val(self), String_val(arg1));
CAMLreturn(Val_option(result, Val_GVariantType));
}

#else

CAMLexport CAMLprim value ml_g_action_group_get_action_state_type(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_group_get_action_state_hint(value self, value arg1)
{
CAMLparam2(self, arg1);

GVariant* result = g_action_group_get_action_state_hint(GActionGroup_val(self), String_val(arg1));
CAMLreturn(Val_option(result, Val_GVariant));
}

#else

CAMLexport CAMLprim value ml_g_action_group_get_action_state_hint(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_group_get_action_state(value self, value arg1)
{
CAMLparam2(self, arg1);

GVariant* result = g_action_group_get_action_state(GActionGroup_val(self), String_val(arg1));
CAMLreturn(Val_option(result, Val_GVariant));
}

#else

CAMLexport CAMLprim value ml_g_action_group_get_action_state(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_group_get_action_parameter_type(value self, value arg1)
{
CAMLparam2(self, arg1);

const GVariantType* result = g_action_group_get_action_parameter_type(GActionGroup_val(self), String_val(arg1));
CAMLreturn(Val_option(result, Val_GVariantType));
}

#else

CAMLexport CAMLprim value ml_g_action_group_get_action_parameter_type(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_group_get_action_enabled(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = g_action_group_get_action_enabled(GActionGroup_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_g_action_group_get_action_enabled(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_group_change_action_state(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_action_group_change_action_state(GActionGroup_val(self), String_val(arg1), GVariant_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_action_group_change_action_state(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_group_activate_action(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_action_group_activate_action(GActionGroup_val(self), String_val(arg1), Option_val(arg2, GVariant_val, NULL));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_action_group_activate_action(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_group_action_state_changed(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_action_group_action_state_changed(GActionGroup_val(self), String_val(arg1), GVariant_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_action_group_action_state_changed(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_group_action_removed(value self, value arg1)
{
CAMLparam2(self, arg1);

g_action_group_action_removed(GActionGroup_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_action_group_action_removed(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_group_action_enabled_changed(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_action_group_action_enabled_changed(GActionGroup_val(self), String_val(arg1), Bool_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_action_group_action_enabled_changed(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,28,0)

CAMLexport CAMLprim value ml_g_action_group_action_added(value self, value arg1)
{
CAMLparam2(self, arg1);

g_action_group_action_added(GActionGroup_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_action_group_action_added(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ActionGroup requires GLib >= 2.28");
return Val_unit;
}
#endif
CAMLexport CAMLprim value ml_gio_action_group_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_ACTION_GROUP)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GActionGroup");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GActionGroup((GActionGroup*)gobj));
}

GType g_action_group_get_type (void);


CAMLprim value ml_gio_action_group_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_action_group_get_type()));
}
