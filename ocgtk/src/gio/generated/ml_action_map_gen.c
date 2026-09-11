/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ActionMap */

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

#if GLIB_CHECK_VERSION(2,32,0)


#if GLIB_CHECK_VERSION(2,78,0)

CAMLexport CAMLprim value ml_g_action_map_remove_action_entries(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg1_length = Wosize_val(arg1);
    GActionEntry* c_arg1 = (GActionEntry*)g_malloc(sizeof(GActionEntry) * arg1_length);
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = *GActionEntry_val(Field(arg1, i));
    }

g_action_map_remove_action_entries(GActionMap_val(self), c_arg1, Int_val(arg2));
    g_free(c_arg1);
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_action_map_remove_action_entries(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("ActionMap requires GLib >= 2.78");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_g_action_map_remove_action(value self, value arg1)
{
CAMLparam2(self, arg1);

g_action_map_remove_action(GActionMap_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_g_action_map_lookup_action(value self, value arg1)
{
CAMLparam2(self, arg1);

GAction* result = g_action_map_lookup_action(GActionMap_val(self), String_val(arg1));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GAction));
}

CAMLexport CAMLprim value ml_g_action_map_add_action(value self, value arg1)
{
CAMLparam2(self, arg1);

g_action_map_add_action(GActionMap_val(self), GAction_val(arg1));
CAMLreturn(Val_unit);
}
CAMLexport CAMLprim value ml_gio_action_map_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_ACTION_MAP)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GActionMap");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GActionMap((GActionMap*)gobj));
}


CAMLprim value ml_gio_action_map_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_action_map_get_type()));
}

#else


CAMLexport CAMLprim value ml_g_action_map_add_action(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ActionMap requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_action_map_lookup_action(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ActionMap requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_action_map_remove_action(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ActionMap requires GLib >= 2.32");
return Val_unit;
}


CAMLexport CAMLprim value ml_g_action_map_remove_action_entries(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("ActionMap requires GLib >= 2.32");
return Val_unit;
}

CAMLexport CAMLprim value ml_gio_action_map_from_gobject(value obj)
{
    CAMLparam1(obj);
    (void)obj;
    caml_failwith("ActionMap requires GTK >= 2.32");
    return Val_unit;
}


#endif
