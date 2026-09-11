/* GENERATED CODE - DO NOT EDIT */
/* C bindings for BookmarkList */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"
#include "converters.h"

#include <gtk/gtk.h>
/* Include library-specific type conversions and forward declarations */
#include "gtk_decls.h"


CAMLexport CAMLprim value ml_gtk_bookmark_list_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkBookmarkList *obj = gtk_bookmark_list_new(String_option_val(arg1), String_option_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkBookmarkList(obj));
}
CAMLexport CAMLprim value ml_gtk_bookmark_list_set_io_priority(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_bookmark_list_set_io_priority(GtkBookmarkList_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bookmark_list_set_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_bookmark_list_set_attributes(GtkBookmarkList_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_bookmark_list_is_loading(value self)
{
CAMLparam1(self);

gboolean result = gtk_bookmark_list_is_loading(GtkBookmarkList_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_bookmark_list_get_io_priority(value self)
{
CAMLparam1(self);

int result = gtk_bookmark_list_get_io_priority(GtkBookmarkList_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_bookmark_list_get_filename(value self)
{
CAMLparam1(self);

const char* result = gtk_bookmark_list_get_filename(GtkBookmarkList_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_bookmark_list_get_attributes(value self)
{
CAMLparam1(self);

const char* result = gtk_bookmark_list_get_attributes(GtkBookmarkList_val(self));
CAMLreturn(Val_option_string(result));
}

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_bookmark_list_get_item_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkBookmarkList *obj = (GtkBookmarkList *)GtkBookmarkList_val(self);
    GType *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "item-type");
if (pspec == NULL) caml_failwith("ml_gtk_bookmark_list_get_item_type: property 'item-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "item-type", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_bookmark_list_get_item_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("BookmarkList requires GTK >= 4.8");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_bookmark_list_get_n_items(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkBookmarkList *obj = (GtkBookmarkList *)GtkBookmarkList_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "n-items");
if (pspec == NULL) caml_failwith("ml_gtk_bookmark_list_get_n_items: property 'n-items' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "n-items", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_bookmark_list_get_n_items(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("BookmarkList requires GTK >= 4.8");
return Val_unit;
}
#endif


CAMLprim value ml_gtk_bookmark_list_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_bookmark_list_get_type()));
}
