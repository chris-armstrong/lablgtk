/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ListStore */

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

CAMLexport CAMLprim value ml_g_list_store_new(value arg1)
{
CAMLparam1(arg1);

GListStore *obj = g_list_store_new(GType_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GListStore(obj));
}
#else

CAMLexport CAMLprim value ml_g_list_store_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("ListStore requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_list_store_splice(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
    int arg3_length = Wosize_val(arg3);
    gpointer* c_arg3 = (gpointer*)g_malloc(sizeof(gpointer) * arg3_length);
    for (int i = 0; i < arg3_length; i++) {
      c_arg3[i] = GObject_ext_of_val(Field(arg3, i));
    }

g_list_store_splice(GListStore_val(self), Int_val(arg1), Int_val(arg2), c_arg3, Int_val(arg4));
    g_free(c_arg3);
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_list_store_splice(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
(void)self;
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("ListStore requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_list_store_remove_all(value self)
{
CAMLparam1(self);

g_list_store_remove_all(GListStore_val(self));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_list_store_remove_all(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListStore requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_list_store_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

g_list_store_remove(GListStore_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_list_store_remove(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ListStore requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_list_store_insert(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

g_list_store_insert(GListStore_val(self), Int_val(arg1), GObject_ext_of_val(arg2));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_list_store_insert(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("ListStore requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,64,0)

CAMLexport CAMLprim value ml_g_list_store_find(value self, value arg1)
{
CAMLparam2(self, arg1);
guint out2;

gboolean result = g_list_store_find(GListStore_val(self), GObject_ext_of_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_int(out2));
    CAMLreturn(ret);
}

#else

CAMLexport CAMLprim value ml_g_list_store_find(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ListStore requires GLib >= 2.64");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_list_store_append(value self, value arg1)
{
CAMLparam2(self, arg1);

g_list_store_append(GListStore_val(self), GObject_ext_of_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_g_list_store_append(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ListStore requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,44,0)

CAMLexport CAMLprim value ml_g_list_store_get_item_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GListStore *obj = (GListStore *)GListStore_val(self);
    GType *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "item-type");
if (pspec == NULL) caml_failwith("ml_g_list_store_get_item_type: property 'item-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "item-type", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_list_store_get_item_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListStore requires GLib >= 2.44");
return Val_unit;
}
#endif

#if GLIB_CHECK_VERSION(2,74,0)

CAMLexport CAMLprim value ml_g_list_store_get_n_items(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GListStore *obj = (GListStore *)GListStore_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "n-items");
if (pspec == NULL) caml_failwith("ml_g_list_store_get_n_items: property 'n-items' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "n-items", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_g_list_store_get_n_items(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListStore requires GLib >= 2.74");
return Val_unit;
}
#endif

GType g_list_store_get_type (void);


CAMLprim value ml_gio_list_store_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(g_list_store_get_type()));
}
