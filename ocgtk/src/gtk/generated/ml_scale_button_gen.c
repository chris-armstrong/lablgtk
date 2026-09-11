/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ScaleButton */

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


CAMLexport CAMLprim value ml_gtk_scale_button_new(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);
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

GtkScaleButton *obj = gtk_scale_button_new(Double_val(arg1), Double_val(arg2), Double_val(arg3), c_arg4);
if (obj) g_object_ref_sink(obj);

    if (c_arg4) g_free(c_arg4);
CAMLreturn(Val_GtkScaleButton(obj));
}
CAMLexport CAMLprim value ml_gtk_scale_button_set_value(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scale_button_set_value(GtkScaleButton_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scale_button_set_icons(value self, value arg1)
{
CAMLparam2(self, arg1);
    int arg1_length = Wosize_val(arg1);
    const char** c_arg1 = (const char**)g_malloc(sizeof(const char*) * (arg1_length + 1));
    for (int i = 0; i < arg1_length; i++) {
      c_arg1[i] = String_val(Field(arg1, i));
    }
    c_arg1[arg1_length] = NULL;

gtk_scale_button_set_icons(GtkScaleButton_val(self), c_arg1);
    g_free(c_arg1);
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_scale_button_set_has_frame(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scale_button_set_has_frame(GtkScaleButton_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_scale_button_set_has_frame(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ScaleButton requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_scale_button_set_adjustment(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scale_button_set_adjustment(GtkScaleButton_val(self), GtkAdjustment_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scale_button_get_value(value self)
{
CAMLparam1(self);

double result = gtk_scale_button_get_value(GtkScaleButton_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_scale_button_get_popup(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_scale_button_get_popup(GtkScaleButton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkWidget(result));
}

CAMLexport CAMLprim value ml_gtk_scale_button_get_plus_button(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_scale_button_get_plus_button(GtkScaleButton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkButton(result));
}

CAMLexport CAMLprim value ml_gtk_scale_button_get_minus_button(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_scale_button_get_minus_button(GtkScaleButton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkButton(result));
}

#if GTK_CHECK_VERSION(4,14,0)

CAMLexport CAMLprim value ml_gtk_scale_button_get_has_frame(value self)
{
CAMLparam1(self);

gboolean result = gtk_scale_button_get_has_frame(GtkScaleButton_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_scale_button_get_has_frame(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ScaleButton requires GTK >= 4.14");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_scale_button_get_adjustment(value self)
{
CAMLparam1(self);

GtkAdjustment* result = gtk_scale_button_get_adjustment(GtkScaleButton_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkAdjustment(result));
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_scale_button_get_active(value self)
{
CAMLparam1(self);

gboolean result = gtk_scale_button_get_active(GtkScaleButton_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_scale_button_get_active(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ScaleButton requires GTK >= 4.10");
return Val_unit;
}
#endif


CAMLprim value ml_gtk_scale_button_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_scale_button_get_type()));
}
