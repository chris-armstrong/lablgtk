/* GENERATED CODE - DO NOT EDIT */
/* C bindings for BoxLayout */

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


CAMLexport CAMLprim value ml_gtk_box_layout_new(value arg1)
{
CAMLparam1(arg1);

GtkBoxLayout *obj = gtk_box_layout_new(GtkOrientation_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkBoxLayout(obj));
}
CAMLexport CAMLprim value ml_gtk_box_layout_set_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_box_layout_set_spacing(GtkBoxLayout_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_box_layout_set_homogeneous(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_box_layout_set_homogeneous(GtkBoxLayout_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_box_layout_set_baseline_position(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_box_layout_set_baseline_position(GtkBoxLayout_val(self), GtkBaselinePosition_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_box_layout_set_baseline_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_box_layout_set_baseline_child(GtkBoxLayout_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_box_layout_set_baseline_child(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("BoxLayout requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_box_layout_get_spacing(value self)
{
CAMLparam1(self);

guint result = gtk_box_layout_get_spacing(GtkBoxLayout_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_box_layout_get_homogeneous(value self)
{
CAMLparam1(self);

gboolean result = gtk_box_layout_get_homogeneous(GtkBoxLayout_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_box_layout_get_baseline_position(value self)
{
CAMLparam1(self);

GtkBaselinePosition result = gtk_box_layout_get_baseline_position(GtkBoxLayout_val(self));
CAMLreturn(Val_GtkBaselinePosition(result));
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_box_layout_get_baseline_child(value self)
{
CAMLparam1(self);

int result = gtk_box_layout_get_baseline_child(GtkBoxLayout_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_gtk_box_layout_get_baseline_child(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("BoxLayout requires GTK >= 4.12");
return Val_unit;
}
#endif


CAMLprim value ml_gtk_box_layout_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_box_layout_get_type()));
}
