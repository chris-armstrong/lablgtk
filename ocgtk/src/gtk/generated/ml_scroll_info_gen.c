/* GENERATED CODE - DO NOT EDIT */
/* C bindings for ScrollInfo */

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
/* Conversion functions for GtkScrollInfo (opaque record with hidden fields) */
GtkScrollInfo *GtkScrollInfo_val(value v) {
  return (GtkScrollInfo *)ml_gir_record_ptr_val(v, "GtkScrollInfo");
}

value Val_GtkScrollInfo(const GtkScrollInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gtk_scroll_info_get_type(), ptr);
}

value Val_GtkScrollInfo_option(const GtkScrollInfo *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GtkScrollInfo(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,12,0)


CAMLexport CAMLprim value ml_gtk_scroll_info_new(value unit)
{
CAMLparam1(unit);

GtkScrollInfo *obj = gtk_scroll_info_new();

CAMLreturn(Val_GtkScrollInfo(obj));
}
CAMLexport CAMLprim value ml_gtk_scroll_info_set_enable_vertical(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scroll_info_set_enable_vertical(GtkScrollInfo_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scroll_info_set_enable_horizontal(value self, value arg1)
{
CAMLparam2(self, arg1);

gtk_scroll_info_set_enable_horizontal(GtkScrollInfo_val(self), Bool_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gtk_scroll_info_ref(value self)
{
CAMLparam1(self);

GtkScrollInfo* result = gtk_scroll_info_ref(GtkScrollInfo_val(self));
CAMLreturn(Val_GtkScrollInfo(result));
}

CAMLexport CAMLprim value ml_gtk_scroll_info_get_enable_vertical(value self)
{
CAMLparam1(self);

gboolean result = gtk_scroll_info_get_enable_vertical(GtkScrollInfo_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gtk_scroll_info_get_enable_horizontal(value self)
{
CAMLparam1(self);

gboolean result = gtk_scroll_info_get_enable_horizontal(GtkScrollInfo_val(self));
CAMLreturn(Val_bool(result));
}

GType gtk_scroll_info_get_type (void);


CAMLprim value ml_gtk_scroll_info_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gtk_scroll_info_get_type()));
}

#else


CAMLexport CAMLprim value ml_gtk_scroll_info_new(value unit)
{
CAMLparam1(unit);
(void)unit;
caml_failwith("ScrollInfo requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_scroll_info_get_enable_horizontal(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ScrollInfo requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_scroll_info_get_enable_vertical(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ScrollInfo requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_scroll_info_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("ScrollInfo requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_scroll_info_set_enable_horizontal(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ScrollInfo requires GTK >= 4.12");
return Val_unit;
}


CAMLexport CAMLprim value ml_gtk_scroll_info_set_enable_vertical(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("ScrollInfo requires GTK >= 4.12");
return Val_unit;
}


#endif
