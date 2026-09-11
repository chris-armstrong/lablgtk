/* GENERATED CODE - DO NOT EDIT */
/* C bindings for StringList */

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


CAMLexport CAMLprim value ml_gtk_string_list_new(value arg1)
{
CAMLparam1(arg1);
    int arg1_length = 0;
    const char** c_arg1 = NULL;
    
    if (Is_some(arg1)) {
        value array = Some_val(arg1);
        arg1_length = Wosize_val(array);
        c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
        for (int i = 0; i < arg1_length; i++) {
          c_arg1[i] = String_val(Field(array, i));
        }
        c_arg1[arg1_length] = NULL;
    }

GtkStringList *obj = gtk_string_list_new(c_arg1);
if (obj) g_object_ref_sink(obj);

    if (c_arg1) g_free(c_arg1);
CAMLreturn(Val_GtkStringList(obj));
}
CAMLexport CAMLprim value ml_gtk_string_list_take(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_string_list_take(GtkStringList_val(self), String_copy(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_string_list_splice(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
    int arg3_length = 0;
    const char** c_arg3 = NULL;
    
    if (Is_some(arg3)) {
        value array = Some_val(arg3);
        arg3_length = Wosize_val(array);
        c_arg3 = (const char**)g_malloc(sizeof(const char*) * (arg3_length + 1));
        for (int i = 0; i < arg3_length; i++) {
          c_arg3[i] = String_val(Field(array, i));
        }
        c_arg3[arg3_length] = NULL;
    }

gtk_string_list_splice(GtkStringList_val(self), Int_val(arg1), Int_val(arg2), c_arg3);
    if (c_arg3) g_free(c_arg3);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_string_list_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_string_list_remove(GtkStringList_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_string_list_get_string(value self, value arg1)
{
CAMLparam2(self, arg1);

const char* result = gtk_string_list_get_string(GtkStringList_val(self), Int_val(arg1));
CAMLreturn(Val_option_string(result));
}

#if GTK_CHECK_VERSION(4,18,0)

CAMLexport CAMLprim value ml_gtk_string_list_find(value self, value arg1)
{
CAMLparam2(self, arg1);

guint result = gtk_string_list_find(GtkStringList_val(self), String_val(arg1));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_gtk_string_list_find(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("StringList requires GTK >= 4.18");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_string_list_append(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_string_list_append(GtkStringList_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_string_list_get_item_type(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkStringList *obj = (GtkStringList *)GtkStringList_val(self);
    GType *prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "item-type");
if (pspec == NULL) caml_failwith("ml_gtk_string_list_get_item_type: property 'item-type' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "item-type", &prop_gvalue);
          caml_failwith("unsupported property type");

      result = Val_GType(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_string_list_get_item_type(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("StringList requires GTK >= 4.14");
return Val_unit;
}
#endif

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_string_list_get_n_items(value self)
{
    CAMLparam1(self);
    CAMLlocal1(result);
GtkStringList *obj = (GtkStringList *)GtkStringList_val(self);
    guint prop_value;
GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), "n-items");
if (pspec == NULL) caml_failwith("ml_gtk_string_list_get_n_items: property 'n-items' not found");
GValue prop_gvalue = G_VALUE_INIT;
g_value_init(&prop_gvalue, pspec->value_type);
      g_object_get_property(G_OBJECT(obj), "n-items", &prop_gvalue);
          prop_value = g_value_get_uint(&prop_gvalue);

      result = Val_int(prop_value);
g_value_unset(&prop_gvalue);
CAMLreturn(result);}

#else

CAMLexport CAMLprim value ml_gtk_string_list_get_n_items(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("StringList requires GTK >= 4.14");
return Val_unit;
}
#endif

GType gtk_string_list_get_type (void);


CAMLprim value ml_gtk_string_list_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_string_list_get_type()));
}
