/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FileChooser */

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


CAMLexport CAMLprim value ml_gtk_file_chooser_set_select_multiple(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_chooser_set_select_multiple(GtkFileChooser_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_chooser_set_filter(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_chooser_set_filter(GtkFileChooser_val(self), GtkFileFilter_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_chooser_set_file(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gtk_file_chooser_set_file(GtkFileChooser_val(self), GFile_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_set_current_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_chooser_set_current_name(GtkFileChooser_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_chooser_set_current_folder(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gtk_file_chooser_set_current_folder(GtkFileChooser_val(self), Option_val(arg1, GFile_val, NULL), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_set_create_folders(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_chooser_set_create_folders(GtkFileChooser_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_chooser_set_choice(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_file_chooser_set_choice(GtkFileChooser_val(self), String_val(arg1), String_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_chooser_set_action(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_chooser_set_action(GtkFileChooser_val(self), GtkFileChooserAction_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_chooser_remove_shortcut_folder(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gtk_file_chooser_remove_shortcut_folder(GtkFileChooser_val(self), GFile_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_remove_filter(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_chooser_remove_filter(GtkFileChooser_val(self), GtkFileFilter_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_chooser_remove_choice(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_chooser_remove_choice(GtkFileChooser_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_chooser_get_shortcut_folders(value self)
{
CAMLparam1(self);

GListModel* result = gtk_file_chooser_get_shortcut_folders(GtkFileChooser_val(self));
CAMLreturn(Val_GListModel(result));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_get_select_multiple(value self)
{
CAMLparam1(self);

gboolean result = gtk_file_chooser_get_select_multiple(GtkFileChooser_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_get_filters(value self)
{
CAMLparam1(self);

GListModel* result = gtk_file_chooser_get_filters(GtkFileChooser_val(self));
CAMLreturn(Val_GListModel(result));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_get_filter(value self)
{
CAMLparam1(self);

GtkFileFilter* result = gtk_file_chooser_get_filter(GtkFileChooser_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkFileFilter));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_get_files(value self)
{
CAMLparam1(self);

GListModel* result = gtk_file_chooser_get_files(GtkFileChooser_val(self));
CAMLreturn(Val_GListModel(result));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_get_file(value self)
{
CAMLparam1(self);

GFile* result = gtk_file_chooser_get_file(GtkFileChooser_val(self));
CAMLreturn(Val_option(result, Val_GFile));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_get_current_name(value self)
{
CAMLparam1(self);

char* result = gtk_file_chooser_get_current_name(GtkFileChooser_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_get_current_folder(value self)
{
CAMLparam1(self);

GFile* result = gtk_file_chooser_get_current_folder(GtkFileChooser_val(self));
CAMLreturn(Val_option(result, Val_GFile));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_get_create_folders(value self)
{
CAMLparam1(self);

gboolean result = gtk_file_chooser_get_create_folders(GtkFileChooser_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_get_choice(value self, value arg1)
{
CAMLparam2(self, arg1);

const char* result = gtk_file_chooser_get_choice(GtkFileChooser_val(self), String_val(arg1));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_get_action(value self)
{
CAMLparam1(self);

GtkFileChooserAction result = gtk_file_chooser_get_action(GtkFileChooser_val(self));
CAMLreturn(Val_GtkFileChooserAction(result));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_add_shortcut_folder(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

gboolean result = gtk_file_chooser_add_shortcut_folder(GtkFileChooser_val(self), GFile_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_bool(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_file_chooser_add_filter(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_chooser_add_filter(GtkFileChooser_val(self), GtkFileFilter_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_chooser_add_choice(value self, value arg1, value arg2, value arg3, value arg4)
{
CAMLparam5(self, arg1, arg2, arg3, arg4);
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
    int arg4_length = 0;
    const char** c_arg4 = NULL;
    
    if (Is_some(arg4)) {
        value array = Some_val(arg4);
        arg4_length = Wosize_val(array);
        c_arg4 = (const char**)g_malloc(sizeof(const char*) * (arg4_length + 1));
        for (int i = 0; i < arg4_length; i++) {
          c_arg4[i] = String_val(Field(array, i));
        }
        c_arg4[arg4_length] = NULL;
    }

gtk_file_chooser_add_choice(GtkFileChooser_val(self), String_val(arg1), String_val(arg2), c_arg3, c_arg4);
    if (c_arg3) g_free(c_arg3);
    if (c_arg4) g_free(c_arg4);
CAMLreturn(Val_unit);
}
CAMLexport CAMLprim value ml_gtk_file_chooser_from_gobject(value obj)
{
    CAMLparam1(obj);
    GObject *gobj = GObject_ext_of_val(obj);
    if (!g_type_is_a(G_OBJECT_TYPE(gobj), GTK_TYPE_FILE_CHOOSER)) {
        char msg[256];
        snprintf(msg, sizeof(msg),
            "from_gobject: object of type '%s' does not implement %s",
            G_OBJECT_TYPE_NAME(gobj), "GtkFileChooser");
        caml_failwith(msg);
    }
    g_object_ref(gobj);
    CAMLreturn(Val_GtkFileChooser((GtkFileChooser*)gobj));
}

GType gtk_file_chooser_get_type (void);


CAMLprim value ml_gtk_file_chooser_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_file_chooser_get_type()));
}
