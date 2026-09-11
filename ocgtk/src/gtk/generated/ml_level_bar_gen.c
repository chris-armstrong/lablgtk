/* GENERATED CODE - DO NOT EDIT */
/* C bindings for LevelBar */

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


CAMLexport CAMLprim value ml_gtk_level_bar_new(value unit)
{
CAMLparam1(unit);

GtkLevelBar *obj = gtk_level_bar_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkLevelBar(obj));
}
CAMLexport CAMLprim value ml_gtk_level_bar_new_for_interval(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkLevelBar *obj = gtk_level_bar_new_for_interval(Double_val(arg1), Double_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkLevelBar(obj));
}
CAMLexport CAMLprim value ml_gtk_level_bar_set_value(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_level_bar_set_value(GtkLevelBar_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_level_bar_set_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_level_bar_set_mode(GtkLevelBar_val(self), GtkLevelBarMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_level_bar_set_min_value(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_level_bar_set_min_value(GtkLevelBar_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_level_bar_set_max_value(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_level_bar_set_max_value(GtkLevelBar_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_level_bar_set_inverted(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_level_bar_set_inverted(GtkLevelBar_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_level_bar_remove_offset_value(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_level_bar_remove_offset_value(GtkLevelBar_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_level_bar_get_value(value self)
{
CAMLparam1(self);

double result = gtk_level_bar_get_value(GtkLevelBar_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_level_bar_get_offset_value(value self, value arg1)
{
CAMLparam2(self, arg1);
double out2;

gboolean result = gtk_level_bar_get_offset_value(GtkLevelBar_val(self), String_option_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, caml_copy_double(out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_level_bar_get_mode(value self)
{
CAMLparam1(self);

GtkLevelBarMode result = gtk_level_bar_get_mode(GtkLevelBar_val(self));
CAMLreturn(Val_GtkLevelBarMode(result));
}

CAMLexport CAMLprim value ml_gtk_level_bar_get_min_value(value self)
{
CAMLparam1(self);

double result = gtk_level_bar_get_min_value(GtkLevelBar_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_level_bar_get_max_value(value self)
{
CAMLparam1(self);

double result = gtk_level_bar_get_max_value(GtkLevelBar_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_level_bar_get_inverted(value self)
{
CAMLparam1(self);

gboolean result = gtk_level_bar_get_inverted(GtkLevelBar_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_level_bar_add_offset_value(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_level_bar_add_offset_value(GtkLevelBar_val(self), String_val(arg1), Double_val(arg2));
CAMLreturn(Val_unit);
}


CAMLprim value ml_gtk_level_bar_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_level_bar_get_type()));
}
