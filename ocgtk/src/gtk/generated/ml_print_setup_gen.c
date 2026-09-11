/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PrintSetup */

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

#if GTK_CHECK_VERSION(4,14,0)
/* Conversion functions for GtkPrintSetup (opaque record with hidden fields) */
GtkPrintSetup *GtkPrintSetup_val(value v) {
  return (GtkPrintSetup *)ml_gir_record_ptr_val(v, "GtkPrintSetup");
}

value Val_GtkPrintSetup(const GtkPrintSetup *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gtk_print_setup_get_type(), ptr);
}

value Val_GtkPrintSetup_option(const GtkPrintSetup *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GtkPrintSetup(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gtk_print_setup_ref(value self)
{
CAMLparam1(self);

GtkPrintSetup* result = gtk_print_setup_ref(GtkPrintSetup_val(self));
CAMLreturn(Val_GtkPrintSetup(result));
}

CAMLexport CAMLprim value ml_gtk_print_setup_get_print_settings(value self)
{
CAMLparam1(self);

GtkPrintSettings* result = gtk_print_setup_get_print_settings(GtkPrintSetup_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkPrintSettings(result));
}

CAMLexport CAMLprim value ml_gtk_print_setup_get_page_setup(value self)
{
CAMLparam1(self);

GtkPageSetup* result = gtk_print_setup_get_page_setup(GtkPrintSetup_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_GtkPageSetup(result));
}

GType gtk_print_setup_get_type (void);


CAMLprim value ml_gtk_print_setup_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_print_setup_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_print_setup_get_page_setup(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PrintSetup requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_setup_get_print_settings(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PrintSetup requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_print_setup_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PrintSetup requires GTK >= 4.14");
return Val_unit;
}


#endif
