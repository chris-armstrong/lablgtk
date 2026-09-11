/* GENERATED CODE - DO NOT EDIT */
/* C bindings for AlertDialog */

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


CAMLexport CAMLprim value ml_gtk_alert_dialog_show(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_alert_dialog_show(GtkAlertDialog_val(self), Option_val(arg1, GtkWindow_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_alert_dialog_set_modal(GtkAlertDialog_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_set_message(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_alert_dialog_set_message(GtkAlertDialog_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_set_detail(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_alert_dialog_set_detail(GtkAlertDialog_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_set_default_button(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_alert_dialog_set_default_button(GtkAlertDialog_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_set_cancel_button(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_alert_dialog_set_cancel_button(GtkAlertDialog_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_set_buttons(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = Wosize_val(arg1);
    const char** c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = String_val(Field(arg1, i));
    }
    c_arg1[arg1_length] = NULL;

gtk_alert_dialog_set_buttons(GtkAlertDialog_val(self), c_arg1);
    g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_get_modal(value self)
{
CAMLparam1(self);

gboolean result = gtk_alert_dialog_get_modal(GtkAlertDialog_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_get_message(value self)
{
CAMLparam1(self);

const char* result = gtk_alert_dialog_get_message(GtkAlertDialog_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_get_detail(value self)
{
CAMLparam1(self);

const char* result = gtk_alert_dialog_get_detail(GtkAlertDialog_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_get_default_button(value self)
{
CAMLparam1(self);

int result = gtk_alert_dialog_get_default_button(GtkAlertDialog_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_get_cancel_button(value self)
{
CAMLparam1(self);

int result = gtk_alert_dialog_get_cancel_button(GtkAlertDialog_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_get_buttons(value self)
{
CAMLparam1(self);

const char* const* result = gtk_alert_dialog_get_buttons(GtkAlertDialog_val(self));
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = 0;
    while (result[result_length] != NULL) result_length++;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, caml_copy_string(result[i]));
      }
      ml_result_opt = Val_some(ml_result);
          }
CAMLreturn(ml_result_opt);
}

CAMLexport CAMLprim value ml_gtk_alert_dialog_choose_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
GError *error = NULL;

int result = gtk_alert_dialog_choose_finish(GtkAlertDialog_val(self), GAsyncResult_val(arg1), &error);
if (error == NULL) CAMLreturn(Res_Ok(Val_int(result))); else CAMLreturn(Res_Error(Val_GError(error)));
}


CAMLprim value ml_gtk_alert_dialog_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_alert_dialog_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_alert_dialog_choose_finish(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_get_buttons(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_get_cancel_button(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_get_default_button(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_get_detail(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_get_message(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_get_modal(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_set_buttons(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_set_cancel_button(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_set_default_button(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_set_detail(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_set_message(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_set_modal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_alert_dialog_show(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("AlertDialog requires GTK >= 4.10");
return Val_unit;
}


#endif
