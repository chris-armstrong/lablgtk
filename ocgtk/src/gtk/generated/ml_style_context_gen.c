/* GENERATED CODE - DO NOT EDIT */
/* C bindings for StyleContext */

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


CAMLexport CAMLprim value ml_gtk_style_context_to_string(value self, value arg1)
{
CAMLparam2(self, arg1);

char* result = gtk_style_context_to_string(GtkStyleContext_val(self), GtkStyleContextPrintFlags_val(arg1));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_style_context_set_state(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_style_context_set_state(GtkStyleContext_val(self), GtkStateFlags_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_style_context_set_scale(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_style_context_set_scale(GtkStyleContext_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_style_context_set_display(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_style_context_set_display(GtkStyleContext_val(self), GdkDisplay_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_style_context_save(value self)
{
CAMLparam1(self);

gtk_style_context_save(GtkStyleContext_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_style_context_restore(value self)
{
CAMLparam1(self);

gtk_style_context_restore(GtkStyleContext_val(self));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_style_context_remove_provider(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_style_context_remove_provider(GtkStyleContext_val(self), GtkStyleProvider_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_style_context_remove_class(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_style_context_remove_class(GtkStyleContext_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_style_context_lookup_color(value self, value arg1)
{
CAMLparam2(self, arg1);
GdkRGBA out2;

gboolean result = gtk_style_context_lookup_color(GtkStyleContext_val(self), String_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GdkRGBA(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gtk_style_context_has_class(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_style_context_has_class(GtkStyleContext_val(self), String_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_style_context_get_state(value self)
{
CAMLparam1(self);

GtkStateFlags result = gtk_style_context_get_state(GtkStyleContext_val(self));
CAMLreturn(Val_GtkStateFlags(result));
}

CAMLexport CAMLprim value ml_gtk_style_context_get_scale(value self)
{
CAMLparam1(self);

int result = gtk_style_context_get_scale(GtkStyleContext_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_style_context_get_padding(value self)
{
CAMLparam1(self);
GtkBorder out1;

gtk_style_context_get_padding(GtkStyleContext_val(self), &out1);
CAMLreturn(Val_GtkBorder(&out1));
}

CAMLexport CAMLprim value ml_gtk_style_context_get_margin(value self)
{
CAMLparam1(self);
GtkBorder out1;

gtk_style_context_get_margin(GtkStyleContext_val(self), &out1);
CAMLreturn(Val_GtkBorder(&out1));
}

CAMLexport CAMLprim value ml_gtk_style_context_get_display(value self)
{
CAMLparam1(self);

GdkDisplay* result = gtk_style_context_get_display(GtkStyleContext_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GdkDisplay(result));
}

CAMLexport CAMLprim value ml_gtk_style_context_get_color(value self)
{
CAMLparam1(self);
GdkRGBA out1;

gtk_style_context_get_color(GtkStyleContext_val(self), &out1);
CAMLreturn(Val_GdkRGBA(&out1));
}

CAMLexport CAMLprim value ml_gtk_style_context_get_border(value self)
{
CAMLparam1(self);
GtkBorder out1;

gtk_style_context_get_border(GtkStyleContext_val(self), &out1);
CAMLreturn(Val_GtkBorder(&out1));
}

CAMLexport CAMLprim value ml_gtk_style_context_add_provider(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gtk_style_context_add_provider(GtkStyleContext_val(self), GtkStyleProvider_val(arg1), Int_val(arg2));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_style_context_add_class(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_style_context_add_class(GtkStyleContext_val(self), String_val(arg1));
CAMLreturn(Val_unit);
}

GType gtk_style_context_get_type (void);


CAMLprim value ml_gtk_style_context_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_style_context_get_type()));
}
