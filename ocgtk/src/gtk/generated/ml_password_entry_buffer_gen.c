/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PasswordEntryBuffer */

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

#if GTK_CHECK_VERSION(4,4,0)


CAMLexport CAMLprim value ml_gtk_password_entry_buffer_new(value unit)
{
CAMLparam1(unit);

GtkPasswordEntryBuffer *obj = gtk_password_entry_buffer_new();
if (obj) g_object_ref_sink(obj);

CAMLreturn(Val_GtkPasswordEntryBuffer(obj));
}

CAMLprim value ml_gtk_password_entry_buffer_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_password_entry_buffer_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_password_entry_buffer_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("PasswordEntryBuffer requires GTK >= 4.4");
return Val_unit;
}


#endif
