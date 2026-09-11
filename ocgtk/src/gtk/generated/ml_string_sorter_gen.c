/* GENERATED CODE - DO NOT EDIT */
/* C bindings for StringSorter */

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


CAMLexport CAMLprim value ml_gtk_string_sorter_new(value arg1)
{
CAMLparam1(arg1);

GtkStringSorter *obj = gtk_string_sorter_new(Option_val(arg1, GtkExpression_val, NULL));
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkStringSorter(obj));
}
CAMLexport CAMLprim value ml_gtk_string_sorter_set_ignore_case(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_string_sorter_set_ignore_case(GtkStringSorter_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_string_sorter_set_expression(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_string_sorter_set_expression(GtkStringSorter_val(self), Option_val(arg1, GtkExpression_val, NULL));
CAMLreturn(Val_unit);
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_string_sorter_set_collation(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_string_sorter_set_collation(GtkStringSorter_val(self), GtkCollation_val(arg1));
CAMLreturn(Val_unit);
}

#else

CAMLexport CAMLprim value ml_gtk_string_sorter_set_collation(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("StringSorter requires GTK >= 4.10");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_string_sorter_get_ignore_case(value self)
{
CAMLparam1(self);

gboolean result = gtk_string_sorter_get_ignore_case(GtkStringSorter_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_string_sorter_get_expression(value self)
{
CAMLparam1(self);

GtkExpression* result = gtk_string_sorter_get_expression(GtkStringSorter_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkExpression));
}

#if GTK_CHECK_VERSION(4,10,0)

CAMLexport CAMLprim value ml_gtk_string_sorter_get_collation(value self)
{
CAMLparam1(self);

GtkCollation result = gtk_string_sorter_get_collation(GtkStringSorter_val(self));
CAMLreturn(Val_GtkCollation(result));
}

#else

CAMLexport CAMLprim value ml_gtk_string_sorter_get_collation(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("StringSorter requires GTK >= 4.10");
return Val_unit;
}
#endif

GType gtk_string_sorter_get_type (void);


CAMLprim value ml_gtk_string_sorter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_string_sorter_get_type()));
}
