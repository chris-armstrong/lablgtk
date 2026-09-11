/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ListHeader */

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

#if GTK_CHECK_VERSION(4,12,0)


CAMLexport CAMLprim value ml_gtk_list_header_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_list_header_set_child(GtkListHeader_val(self), Option_val(arg1, GtkWidget_val, NULL));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_list_header_get_start(value self)
{
CAMLparam1(self);

guint result = gtk_list_header_get_start(GtkListHeader_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_list_header_get_n_items(value self)
{
CAMLparam1(self);

guint result = gtk_list_header_get_n_items(GtkListHeader_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_list_header_get_item(value self)
{
CAMLparam1(self);

gpointer result = gtk_list_header_get_item(GtkListHeader_val(self));
CAMLreturn(ml_gobject_val_of_ext(result));
}

CAMLexport CAMLprim value ml_gtk_list_header_get_end(value self)
{
CAMLparam1(self);

guint result = gtk_list_header_get_end(GtkListHeader_val(self));
CAMLreturn(Val_int(result));
}

CAMLexport CAMLprim value ml_gtk_list_header_get_child(value self)
{
CAMLparam1(self);

GtkWidget* result = gtk_list_header_get_child(GtkListHeader_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GtkWidget));
}

GType gtk_list_header_get_type (void);


CAMLprim value ml_gtk_list_header_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_list_header_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_list_header_get_child(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListHeader requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_list_header_get_end(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListHeader requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_list_header_get_item(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListHeader requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_list_header_get_n_items(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListHeader requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_list_header_get_start(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ListHeader requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_list_header_set_child(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ListHeader requires GTK >= 4.12");
return Val_unit;
}


#endif
