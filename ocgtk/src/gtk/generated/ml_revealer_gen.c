/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Revealer */

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


CAMLexport CAMLprim value ml_gtk_revealer_new(value unit)
{
CAMLparam1(unit);

GtkRevealer *obj = gtk_revealer_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkRevealer(obj));
}
CAMLexport CAMLprim value ml_gtk_revealer_set_transition_type(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_revealer_set_transition_type(GtkRevealer_val(self), GtkRevealerTransitionType_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_revealer_set_transition_duration(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_revealer_set_transition_duration(GtkRevealer_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_revealer_set_reveal_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_revealer_set_reveal_child(GtkRevealer_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_revealer_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_revealer_set_child(GtkRevealer_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_revealer_get_transition_type(value self)
{
CAMLparam1(self);

GtkRevealerTransitionType result = gtk_revealer_get_transition_type(GtkRevealer_val(self));
CAMLreturn(Val_GtkRevealerTransitionType(result));
}

CAMLexport CAMLprim value ml_gtk_revealer_get_transition_duration(value self)
{
CAMLparam1(self);

guint result = gtk_revealer_get_transition_duration(GtkRevealer_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_revealer_get_reveal_child(value self)
{
CAMLparam1(self);

gboolean result = gtk_revealer_get_reveal_child(GtkRevealer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_revealer_get_child_revealed(value self)
{
CAMLparam1(self);

gboolean result = gtk_revealer_get_child_revealed(GtkRevealer_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_revealer_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_revealer_get_child(GtkRevealer_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

GType gtk_revealer_get_type (void);


CAMLprim value ml_gtk_revealer_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_revealer_get_type()));
}
