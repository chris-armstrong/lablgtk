/* GENERATED CODE - DO NOT EDIT */
/* C bindings for CssSection */

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

/* Conversion functions for GtkCssSection (opaque record with hidden fields) */
GtkCssSection *GtkCssSection_val(value v) {
  return (GtkCssSection *)ml_gir_record_ptr_val(v, "GtkCssSection");
}

value Val_GtkCssSection(const GtkCssSection *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gtk_css_section_get_type(), ptr);
}

value Val_GtkCssSection_option(const GtkCssSection *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GtkCssSection(ptr));
}


CAMLexport CAMLprim value ml_gtk_css_section_new(value arg1, value arg2, value arg3)
{
CAMLparam3(arg1, arg2, arg3);

GtkCssSection *obj = gtk_css_section_new(Option_val(arg1, GFile_val, NULL), GtkCssLocation_val(arg2), GtkCssLocation_val(arg3));

CAMLreturn(Val_GtkCssSection(obj));
}
#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gtk_css_section_new_with_bytes(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);

GtkCssSection *obj = gtk_css_section_new_with_bytes(Option_val(arg1, GFile_val, NULL), Option_val(arg2, GBytes_val, NULL), GtkCssLocation_val(arg3), GtkCssLocation_val(arg4));

CAMLreturn(Val_GtkCssSection(obj));
}
#else

CAMLexport CAMLprim value ml_gtk_css_section_new_with_bytes(value arg1, value arg2, value arg3, value arg4)
{
CAMLparam4(arg1, arg2, arg3, arg4);
(void)arg1;
(void)arg2;
(void)arg3;
(void)arg4;
caml_failwith("CssSection requires GTK >= 4.16");
return Val_unit;
}
#endif

CAMLexport CAMLprim value ml_gtk_css_section_to_string(value self)
{
CAMLparam1(self);

char* result = gtk_css_section_to_string(GtkCssSection_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gtk_css_section_ref(value self)
{
CAMLparam1(self);

GtkCssSection* result = gtk_css_section_ref(GtkCssSection_val(self));
CAMLreturn(Val_GtkCssSection(result));
}

CAMLexport CAMLprim value ml_gtk_css_section_get_start_location(value self)
{
CAMLparam1(self);

const GtkCssLocation* result = gtk_css_section_get_start_location(GtkCssSection_val(self));
CAMLreturn(Val_GtkCssLocation(result));
}

CAMLexport CAMLprim value ml_gtk_css_section_get_parent(value self)
{
CAMLparam1(self);

GtkCssSection* result = gtk_css_section_get_parent(GtkCssSection_val(self));
if (result) result = g_boxed_copy(gtk_css_section_get_type(), result);
CAMLreturn(Val_option(result, Val_GtkCssSection));
}

CAMLexport CAMLprim value ml_gtk_css_section_get_file(value self)
{
CAMLparam1(self);

GFile* result = gtk_css_section_get_file(GtkCssSection_val(self));
if (result) g_object_ref_sink(result);
CAMLreturn(Val_option(result, Val_GFile));
}

CAMLexport CAMLprim value ml_gtk_css_section_get_end_location(value self)
{
CAMLparam1(self);

const GtkCssLocation* result = gtk_css_section_get_end_location(GtkCssSection_val(self));
CAMLreturn(Val_GtkCssLocation(result));
}

#if GTK_CHECK_VERSION(4,16,0)

CAMLexport CAMLprim value ml_gtk_css_section_get_bytes(value self)
{
CAMLparam1(self);

GBytes* result = gtk_css_section_get_bytes(GtkCssSection_val(self));
CAMLreturn(Val_option(result, Val_GBytes));
}

#else

CAMLexport CAMLprim value ml_gtk_css_section_get_bytes(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("CssSection requires GTK >= 4.16");
return Val_unit;
}
#endif

GType gtk_css_section_get_type (void);


CAMLprim value ml_gtk_css_section_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_css_section_get_type()));
}
