/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Inscription */

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

#if GTK_CHECK_VERSION(4,8,0)


CAMLexport CAMLprim value ml_gtk_inscription_new(value arg1)
{
CAMLparam1(arg1);

GtkInscription *obj = gtk_inscription_new(String_option_val(arg1));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkInscription(obj));
}
CAMLexport CAMLprim value ml_gtk_inscription_set_yalign(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_inscription_set_yalign(GtkInscription_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_inscription_set_xalign(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_inscription_set_xalign(GtkInscription_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_inscription_set_wrap_mode(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_inscription_set_wrap_mode(GtkInscription_val(self), PangoWrapMode_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_inscription_set_text_overflow(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_inscription_set_text_overflow(GtkInscription_val(self), GtkInscriptionOverflow_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_inscription_set_text(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_inscription_set_text(GtkInscription_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_inscription_set_nat_lines(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_inscription_set_nat_lines(GtkInscription_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_inscription_set_nat_chars(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_inscription_set_nat_chars(GtkInscription_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_inscription_set_min_lines(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_inscription_set_min_lines(GtkInscription_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_inscription_set_min_chars(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_inscription_set_min_chars(GtkInscription_val(self), Int_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_inscription_set_markup(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_inscription_set_markup(GtkInscription_val(self), String_option_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_inscription_set_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_inscription_set_attributes(GtkInscription_val(self), Option_val(arg1, PangoAttrList_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_inscription_get_yalign(value self)
{
CAMLparam1(self);

float result = gtk_inscription_get_yalign(GtkInscription_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_inscription_get_xalign(value self)
{
CAMLparam1(self);

float result = gtk_inscription_get_xalign(GtkInscription_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gtk_inscription_get_wrap_mode(value self)
{
CAMLparam1(self);

PangoWrapMode result = gtk_inscription_get_wrap_mode(GtkInscription_val(self));
CAMLreturn(Val_PangoWrapMode(result));
}

CAMLexport CAMLprim value ml_gtk_inscription_get_text_overflow(value self)
{
CAMLparam1(self);

GtkInscriptionOverflow result = gtk_inscription_get_text_overflow(GtkInscription_val(self));
CAMLreturn(Val_GtkInscriptionOverflow(result));
}

CAMLexport CAMLprim value ml_gtk_inscription_get_text(value self)
{
CAMLparam1(self);

const char* result = gtk_inscription_get_text(GtkInscription_val(self));
CAMLreturn(Val_option_string(result));
}

CAMLexport CAMLprim value ml_gtk_inscription_get_nat_lines(value self)
{
CAMLparam1(self);

guint result = gtk_inscription_get_nat_lines(GtkInscription_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_inscription_get_nat_chars(value self)
{
CAMLparam1(self);

guint result = gtk_inscription_get_nat_chars(GtkInscription_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_inscription_get_min_lines(value self)
{
CAMLparam1(self);

guint result = gtk_inscription_get_min_lines(GtkInscription_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_inscription_get_min_chars(value self)
{
CAMLparam1(self);

guint result = gtk_inscription_get_min_chars(GtkInscription_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_inscription_get_attributes(value self)
{
CAMLparam1(self);

PangoAttrList* result = gtk_inscription_get_attributes(GtkInscription_val(self));
if (result) result = g_boxed_copy(pango_attr_list_get_type(), result);
CAMLreturn(Val_option(result, Val_PangoAttrList));
}


CAMLprim value ml_gtk_inscription_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_inscription_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_inscription_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_get_attributes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_get_min_chars(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_get_min_lines(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_get_nat_chars(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_get_nat_lines(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_get_text(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_get_text_overflow(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_get_wrap_mode(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_get_xalign(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_get_yalign(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_set_attributes(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_set_markup(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_set_min_chars(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_set_min_lines(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_set_nat_chars(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_set_nat_lines(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_set_text(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_set_text_overflow(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_set_wrap_mode(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_set_xalign(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_inscription_set_yalign(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Inscription requires GTK >= 4.8");
return Val_unit;
}


#endif
