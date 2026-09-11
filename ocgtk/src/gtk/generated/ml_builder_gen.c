/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Builder */

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


CAMLexport CAMLprim value ml_gtk_builder_new(value unit)
{
CAMLparam1(unit);

GtkBuilder *obj = gtk_builder_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkBuilder(obj));
}
CAMLexport CAMLprim value ml_gtk_builder_new_from_file(value arg1)
{
CAMLparam1(arg1);

GtkBuilder *obj = gtk_builder_new_from_file(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkBuilder(obj));
}
CAMLexport CAMLprim value ml_gtk_builder_new_from_resource(value arg1)
{
CAMLparam1(arg1);

GtkBuilder *obj = gtk_builder_new_from_resource(String_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkBuilder(obj));
}
CAMLexport CAMLprim value ml_gtk_builder_new_from_string(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkBuilder *obj = gtk_builder_new_from_string(String_val(arg1), Long_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkBuilder(obj));
}
CAMLexport CAMLprim value ml_gtk_builder_value_from_string_type(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;
GValue out3;

gboolean result = gtk_builder_value_from_string_type(GtkBuilder_val(self), GType_val(arg1), String_val(arg2), &out3, &error);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GValue_copy(&out3));
    if (error == NULL) CAMLreturn(Res_Ok(ret)); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_builder_set_translation_domain(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_builder_set_translation_domain(GtkBuilder_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_builder_set_scope(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_builder_set_scope(GtkBuilder_val(self), Option_val(arg1, GtkBuilderScope_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_builder_set_current_object(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_builder_set_current_object(GtkBuilder_val(self), Option_val(arg1, GObject_ext_of_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_builder_get_type_from_name(value self, value arg1)
{
CAMLparam2(self, arg1);

GType result = gtk_builder_get_type_from_name(GtkBuilder_val(self), String_val(arg1));
CAMLreturn(Val_GType(result));
}

CAMLexport CAMLprim value ml_gtk_builder_get_translation_domain(value self)
{
CAMLparam1(self);

const char* result = gtk_builder_get_translation_domain(GtkBuilder_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_builder_get_scope(value self)
{
CAMLparam1(self);

GtkBuilderScope* result = gtk_builder_get_scope(GtkBuilder_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkBuilderScope(result));
}

CAMLexport CAMLprim value ml_gtk_builder_get_objects(value self)
{
CAMLparam1(self);

CAMLlocal3(result, item, cell);
    GList* c_result = gtk_builder_get_objects(GtkBuilder_val(self));
Val_GSList_with(c_result, result, item, cell, ml_gobject_val_of_ext((gpointer)_tmp->data));
    g_slist_free(c_result);
    CAMLreturn(result);
}

CAMLexport CAMLprim value ml_gtk_builder_get_object(value self, value arg1)
{
CAMLparam2(self, arg1);

GObject* result = gtk_builder_get_object(GtkBuilder_val(self), String_val(arg1));
CAMLreturn(Val_option(result, ml_gobject_val_of_ext));
}

CAMLexport CAMLprim value ml_gtk_builder_get_current_object(value self)
{
CAMLparam1(self);

GObject* result = gtk_builder_get_current_object(GtkBuilder_val(self));
CAMLreturn(Val_option(result, ml_gobject_val_of_ext));
}

CAMLexport CAMLprim value ml_gtk_builder_extend_with_template(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
GError *error = NULL;

gboolean result = gtk_builder_extend_with_template(GtkBuilder_val(self), GObject_ext_of_val(arg1), GType_val(arg2), String_val(arg3), Long_val(arg4), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_builder_expose_object(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_builder_expose_object(GtkBuilder_val(self), String_val(arg1), GObject_ext_of_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_builder_add_objects_from_string(value self, value arg1, value arg2, value arg3)
{
CAMLparam4(self, arg1, arg2, arg3);
GError *error = NULL;
    int arg3_length = Wosize_val(arg3);
    const char** c_arg3 = (const char**)g_malloc(sizeof(const char*) * (arg3_length + 1));
    for (int i = 0; i < arg3_length; i++) {
      c_arg3[i] = String_val(Field(arg3, i));
    }
    c_arg3[arg3_length] = NULL;

gboolean result = gtk_builder_add_objects_from_string(GtkBuilder_val(self), String_val(arg1), Long_val(arg2), c_arg3, &error);
    g_free(c_arg3);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_builder_add_objects_from_resource(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;
    int arg2_length = Wosize_val(arg2);
    const char** c_arg2 = (const char**)g_malloc(sizeof(const char*) * (arg2_length + 1));
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = String_val(Field(arg2, i));
    }
    c_arg2[arg2_length] = NULL;

gboolean result = gtk_builder_add_objects_from_resource(GtkBuilder_val(self), String_val(arg1), c_arg2, &error);
    g_free(c_arg2);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_builder_add_objects_from_file(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;
    int arg2_length = Wosize_val(arg2);
    const char** c_arg2 = (const char**)g_malloc(sizeof(const char*) * (arg2_length + 1));
    for (int i = 0; i < arg2_length; i++) {
      c_arg2[i] = String_val(Field(arg2, i));
    }
    c_arg2[arg2_length] = NULL;

gboolean result = gtk_builder_add_objects_from_file(GtkBuilder_val(self), String_val(arg1), c_arg2, &error);
    g_free(c_arg2);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_builder_add_from_string(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GError *error = NULL;

gboolean result = gtk_builder_add_from_string(GtkBuilder_val(self), String_val(arg1), Long_val(arg2), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_builder_add_from_resource(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gtk_builder_add_from_resource(GtkBuilder_val(self), String_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_builder_add_from_file(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gtk_builder_add_from_file(GtkBuilder_val(self), String_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}


CAMLprim value ml_gtk_builder_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_builder_get_type()));
}
