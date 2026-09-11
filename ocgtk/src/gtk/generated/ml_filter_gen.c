/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Filter */

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


CAMLexport CAMLprim value ml_gtk_filter_match(value self, value arg1)
{
CAMLparam2(self, arg1);

gboolean result = gtk_filter_match(GtkFilter_val(self), GObject_ext_of_val(arg1));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_filter_get_strictness(value self)
{
CAMLparam1(self);

GtkFilterMatch result = gtk_filter_get_strictness(GtkFilter_val(self));
CAMLreturn(Val_GtkFilterMatch(result));
}

CAMLexport CAMLprim value ml_gtk_filter_changed(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_filter_changed(GtkFilter_val(self), GtkFilterChange_val(arg1));
CAMLreturn(Val_unit);
}

GType gtk_filter_get_type (void);


CAMLprim value ml_gtk_filter_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_filter_get_type()));
}
