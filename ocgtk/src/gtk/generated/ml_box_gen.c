/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Box */

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


CAMLexport CAMLprim value ml_gtk_box_new(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GtkBox *obj = gtk_box_new(GtkOrientation_val(arg1), Int_val(arg2));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkBox(obj));
}
CAMLexport CAMLprim value ml_gtk_box_set_spacing(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_box_set_spacing(GtkBox_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_box_set_homogeneous(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_box_set_homogeneous(GtkBox_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_box_set_baseline_position(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_box_set_baseline_position(GtkBox_val(self), GtkBaselinePosition_val(arg1));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_box_set_baseline_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_box_set_baseline_child(GtkBox_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_box_set_baseline_child(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Box requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_box_reorder_child_after(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_box_reorder_child_after(GtkBox_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_box_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_box_remove(GtkBox_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_box_prepend(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_box_prepend(GtkBox_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_box_insert_child_after(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_box_insert_child_after(GtkBox_val(self), GtkWidget_val(arg1), Option_val(arg2, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_box_get_spacing(value self)
{
CAMLparam1(self);

int result = gtk_box_get_spacing(GtkBox_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_box_get_homogeneous(value self)
{
CAMLparam1(self);

gboolean result = gtk_box_get_homogeneous(GtkBox_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_box_get_baseline_position(value self)
{
CAMLparam1(self);

GtkBaselinePosition result = gtk_box_get_baseline_position(GtkBox_val(self));
CAMLreturn(Val_GtkBaselinePosition(result));
}

#if GTK_CHECK_VERSION(4,12,0)

CAMLexport CAMLprim value ml_gtk_box_get_baseline_child(value self)
{
CAMLparam1(self);

int result = gtk_box_get_baseline_child(GtkBox_val(self));
CAMLreturn(Val_int(result));
}

#else

CAMLexport CAMLprim value ml_gtk_box_get_baseline_child(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Box requires GTK >= 4.12");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_box_append(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_box_append(GtkBox_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

GType gtk_box_get_type (void);


CAMLprim value ml_gtk_box_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_box_get_type()));
}
