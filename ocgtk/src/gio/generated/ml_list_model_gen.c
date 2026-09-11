/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ListModel */

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


#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_list_model_items_changed(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);

g_list_model_items_changed(GListModel_val(self), Int_val(arg1), Int_val(arg2), Int_val(arg3));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_list_model_items_changed(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
caml_failwith("ListModel requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_list_model_get_object(value self, value arg1)
{
CAMLparam2(self, arg1);

GObject* result = g_list_model_get_object(GListModel_val(self), Int_val(arg1));
CAMLreturn(Val_option(result, ml_gobject_val_of_ext));
}

#else

CAMLexport CAMLprim value ml_g_list_model_get_object(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ListModel requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_list_model_get_n_items(value self)
{
CAMLparam1(self);

guint result = g_list_model_get_n_items(GListModel_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_g_list_model_get_n_items(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListModel requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_list_model_get_item_type(value self)
{
CAMLparam1(self);

GType result = g_list_model_get_item_type(GListModel_val(self));
CAMLreturn(Val_GType(result));
}

#else

CAMLexport CAMLprim value ml_g_list_model_get_item_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListModel requires GLib >= 2.44");
return Val_unit;
}
#endif
CAMLexport CAMLprim value ml_gio_list_model_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), G_TYPE_LIST_MODEL)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GListModel");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GListModel((GListModel*)gobj));
}


CAMLprim value ml_gio_list_model_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_list_model_get_type()));
}
