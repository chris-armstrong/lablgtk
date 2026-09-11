/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CenterLayout */

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


CAMLexport CAMLprim value ml_gtk_center_layout_new(value unit)
{
CAMLparam1(unit);

GtkCenterLayout *obj = gtk_center_layout_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkCenterLayout(obj));
}
CAMLexport CAMLprim value ml_gtk_center_layout_set_start_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_center_layout_set_start_widget(GtkCenterLayout_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_center_layout_set_shrink_center_last(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_center_layout_set_shrink_center_last(GtkCenterLayout_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_center_layout_set_shrink_center_last(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("CenterLayout requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_center_layout_set_orientation(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_center_layout_set_orientation(GtkCenterLayout_val(self), GtkOrientation_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_center_layout_set_end_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_center_layout_set_end_widget(GtkCenterLayout_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_center_layout_set_center_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_center_layout_set_center_widget(GtkCenterLayout_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_center_layout_set_baseline_position(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_center_layout_set_baseline_position(GtkCenterLayout_val(self), GtkBaselinePosition_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_center_layout_get_start_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_center_layout_get_start_widget(GtkCenterLayout_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_center_layout_get_shrink_center_last(value self)
{
CAMLparam1(self);

gboolean result = gtk_center_layout_get_shrink_center_last(GtkCenterLayout_val(self));
CAMLreturn(Val_bool(result));
}

#else

CAMLexport CAMLprim value ml_gtk_center_layout_get_shrink_center_last(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CenterLayout requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_center_layout_get_orientation(value self)
{
CAMLparam1(self);

GtkOrientation result = gtk_center_layout_get_orientation(GtkCenterLayout_val(self));
CAMLreturn(Val_GtkOrientation(result));
}

CAMLexport CAMLprim value ml_gtk_center_layout_get_end_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_center_layout_get_end_widget(GtkCenterLayout_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_center_layout_get_center_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_center_layout_get_center_widget(GtkCenterLayout_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

CAMLexport CAMLprim value ml_gtk_center_layout_get_baseline_position(value self)
{
CAMLparam1(self);

GtkBaselinePosition result = gtk_center_layout_get_baseline_position(GtkCenterLayout_val(self));
CAMLreturn(Val_GtkBaselinePosition(result));
}

GType gtk_center_layout_get_type (void);


CAMLprim value ml_gtk_center_layout_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_center_layout_get_type()));
}
