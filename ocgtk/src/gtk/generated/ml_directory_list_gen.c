/* GENERATED CODE - DO NOT EDIT */
/* C bindings for DirectoryList */

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


CAMLexport CAMLprim value ml_gtk_directory_list_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkDirectoryList *obj = gtk_directory_list_new(String_option_val(arg1), Option_val(arg2, GFile_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkDirectoryList(obj));
}
CAMLexport CAMLprim value ml_gtk_directory_list_set_monitored(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_directory_list_set_monitored(GtkDirectoryList_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_directory_list_set_io_priority(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_directory_list_set_io_priority(GtkDirectoryList_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_directory_list_set_file(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_directory_list_set_file(GtkDirectoryList_val(self), Option_val(arg1, GFile_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_directory_list_set_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_directory_list_set_attributes(GtkDirectoryList_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_directory_list_is_loading(value self)
{
CAMLparam1(self);

gboolean result = gtk_directory_list_is_loading(GtkDirectoryList_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_directory_list_get_monitored(value self)
{
CAMLparam1(self);

gboolean result = gtk_directory_list_get_monitored(GtkDirectoryList_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_directory_list_get_io_priority(value self)
{
CAMLparam1(self);

int result = gtk_directory_list_get_io_priority(GtkDirectoryList_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_directory_list_get_file(value self)
{
CAMLparam1(self);

GFile* result = gtk_directory_list_get_file(GtkDirectoryList_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GFile));
}

CAMLexport CAMLprim value ml_gtk_directory_list_get_error(value self)
{
CAMLparam1(self);

const GError* result = gtk_directory_list_get_error(GtkDirectoryList_val(self));
CAMLreturn(Val_option(result, Val_GError));
}

CAMLexport CAMLprim value ml_gtk_directory_list_get_attributes(value self)
{
CAMLparam1(self);

const char* result = gtk_directory_list_get_attributes(GtkDirectoryList_val(self));
CAMLreturn(Val_option_string(result));
}

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_directory_list_get_item_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkDirectoryList *obj = (GtkDirectoryList *)GtkDirectoryList_val(self);
    GType *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "item-type");
if (pspec == NULL) caml_failwith("ml_gtk_directory_list_get_item_type: property 'item-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "item-type", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_directory_list_get_item_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DirectoryList requires GTK >= 4.8");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,8,0)

CAMLexport CAMLprim value ml_gtk_directory_list_get_n_items(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkDirectoryList *obj = (GtkDirectoryList *)GtkDirectoryList_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "n-items");
if (pspec == NULL) caml_failwith("ml_gtk_directory_list_get_n_items: property 'n-items' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "n-items", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_directory_list_get_n_items(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("DirectoryList requires GTK >= 4.8");
return Val_unit;
}
#endif

GType gtk_directory_list_get_type (void);


CAMLprim value ml_gtk_directory_list_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_directory_list_get_type()));
}
