/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ActionBar */

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


CAMLexport CAMLprim value ml_gtk_action_bar_new(value unit)
{
CAMLparam1(unit);

GtkActionBar *obj = gtk_action_bar_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkActionBar(obj));
}
CAMLexport CAMLprim value ml_gtk_action_bar_set_revealed(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_action_bar_set_revealed(GtkActionBar_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_action_bar_set_center_widget(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_action_bar_set_center_widget(GtkActionBar_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_action_bar_remove(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_action_bar_remove(GtkActionBar_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_action_bar_pack_start(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_action_bar_pack_start(GtkActionBar_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_action_bar_pack_end(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_action_bar_pack_end(GtkActionBar_val(self), GtkWidget_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_action_bar_get_revealed(value self)
{
CAMLparam1(self);

gboolean result = gtk_action_bar_get_revealed(GtkActionBar_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_action_bar_get_center_widget(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_action_bar_get_center_widget(GtkActionBar_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

GType gtk_action_bar_get_type (void);


CAMLprim value ml_gtk_action_bar_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_action_bar_get_type()));
}
