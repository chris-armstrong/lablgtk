/* GENERATED CODE - DO NOT EDIT */
/* C bindings for FileDialog */

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

#if GTK_CHECK_VERSION(4,10,0)


CAMLexport CAMLprim value ml_gtk_file_dialog_new(value unit)
{
CAMLparam1(unit);

GtkFileDialog *obj = gtk_file_dialog_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkFileDialog(obj));
}
CAMLexport CAMLprim value ml_gtk_file_dialog_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_dialog_set_title(GtkFileDialog_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_dialog_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_dialog_set_modal(GtkFileDialog_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_dialog_set_initial_name(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_dialog_set_initial_name(GtkFileDialog_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_dialog_set_initial_folder(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_dialog_set_initial_folder(GtkFileDialog_val(self), Option_val(arg1, GFile_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_dialog_set_initial_file(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_dialog_set_initial_file(GtkFileDialog_val(self), Option_val(arg1, GFile_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_dialog_set_filters(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_dialog_set_filters(GtkFileDialog_val(self), Option_val(arg1, GListModel_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_dialog_set_default_filter(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_dialog_set_default_filter(GtkFileDialog_val(self), Option_val(arg1, GtkFileFilter_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_dialog_set_accept_label(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_file_dialog_set_accept_label(GtkFileDialog_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_file_dialog_select_multiple_folders_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GListModel* result = gtk_file_dialog_select_multiple_folders_finish(GtkFileDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GListModel(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_file_dialog_select_folder_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GFile* result = gtk_file_dialog_select_folder_finish(GtkFileDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GFile(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_file_dialog_save_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GFile* result = gtk_file_dialog_save_finish(GtkFileDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GFile(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_file_dialog_open_multiple_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GListModel* result = gtk_file_dialog_open_multiple_finish(GtkFileDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GListModel(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_file_dialog_open_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

GFile* result = gtk_file_dialog_open_finish(GtkFileDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_GFile(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}

CAMLexport CAMLprim value ml_gtk_file_dialog_get_title(value self)
{
CAMLparam1(self);

const char* result = gtk_file_dialog_get_title(GtkFileDialog_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_file_dialog_get_modal(value self)
{
CAMLparam1(self);

gboolean result = gtk_file_dialog_get_modal(GtkFileDialog_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_file_dialog_get_initial_name(value self)
{
CAMLparam1(self);

const char* result = gtk_file_dialog_get_initial_name(GtkFileDialog_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_file_dialog_get_initial_folder(value self)
{
CAMLparam1(self);

GFile* result = gtk_file_dialog_get_initial_folder(GtkFileDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GFile));
}

CAMLexport CAMLprim value ml_gtk_file_dialog_get_initial_file(value self)
{
CAMLparam1(self);

GFile* result = gtk_file_dialog_get_initial_file(GtkFileDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GFile));
}

CAMLexport CAMLprim value ml_gtk_file_dialog_get_filters(value self)
{
CAMLparam1(self);

GListModel* result = gtk_file_dialog_get_filters(GtkFileDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GListModel));
}

CAMLexport CAMLprim value ml_gtk_file_dialog_get_default_filter(value self)
{
CAMLparam1(self);

GtkFileFilter* result = gtk_file_dialog_get_default_filter(GtkFileDialog_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkFileFilter));
}

CAMLexport CAMLprim value ml_gtk_file_dialog_get_accept_label(value self)
{
CAMLparam1(self);

const char* result = gtk_file_dialog_get_accept_label(GtkFileDialog_val(self));
CAMLreturn(Val_option_string(result));
}

GType gtk_file_dialog_get_type (void);


CAMLprim value ml_gtk_file_dialog_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_file_dialog_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_file_dialog_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_get_accept_label(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_get_default_filter(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_get_filters(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_get_initial_file(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_get_initial_folder(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_get_initial_name(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_get_modal(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_get_title(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_open_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_open_multiple_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_save_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_select_folder_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_select_multiple_folders_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_set_accept_label(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_set_default_filter(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_set_filters(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_set_initial_file(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_set_initial_folder(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_set_initial_name(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_file_dialog_set_title(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("FileDialog requires GTK >= 4.10");
return Val_unit;
}


#endif
