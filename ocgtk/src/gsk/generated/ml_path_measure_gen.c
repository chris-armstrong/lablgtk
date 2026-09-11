/* GENERATED CODE - DO NOT EDIT */
/* C bindings for PathMeasure */

#include <gtk/gtk.h>
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/callback.h>
#include <caml/fail.h>
#include <caml/hash.h>
#include <caml/custom.h>
#include "wrappers.h"

#include <gsk/gsk.h>
/* Include library-specific type conversions and forward declarations */
#include "gsk_decls.h"

#if GTK_CHECK_VERSION(4,14,0)
/* Conversion functions for GskPathMeasure (opaque record with hidden fields) */
GskPathMeasure *GskPathMeasure_val(value v) {
  return (GskPathMeasure *)ml_gir_record_ptr_val(v, "GskPathMeasure");
}

value Val_GskPathMeasure(const GskPathMeasure *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gsk_path_measure_get_type(), ptr);
}

value Val_GskPathMeasure_option(const GskPathMeasure *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GskPathMeasure(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gsk_path_measure_new(value arg1)
{
CAMLparam1(arg1);

GskPathMeasure *obj = gsk_path_measure_new(GskPath_val(arg1));

CAMLreturn(Val_GskPathMeasure(obj));
}
CAMLexport CAMLprim value ml_gsk_path_measure_new_with_tolerance(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);

GskPathMeasure *obj = gsk_path_measure_new_with_tolerance(GskPath_val(arg1), Double_val(arg2));

CAMLreturn(Val_GskPathMeasure(obj));
}
CAMLexport CAMLprim value ml_gsk_path_measure_ref(value self)
{
CAMLparam1(self);

GskPathMeasure* result = gsk_path_measure_ref(GskPathMeasure_val(self));
CAMLreturn(Val_GskPathMeasure(result));
}

CAMLexport CAMLprim value ml_gsk_path_measure_get_tolerance(value self)
{
CAMLparam1(self);

float result = gsk_path_measure_get_tolerance(GskPathMeasure_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_path_measure_get_point(value self, value arg1)
{
CAMLparam2(self, arg1);
GskPathPoint out2;

gboolean result = gsk_path_measure_get_point(GskPathMeasure_val(self), Double_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GskPathPoint(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gsk_path_measure_get_path(value self)
{
CAMLparam1(self);

GskPath* result = gsk_path_measure_get_path(GskPathMeasure_val(self));
if (result) result = g_boxed_copy(gsk_path_get_type(), result);
CAMLreturn(Val_GskPath(result));
}

CAMLexport CAMLprim value ml_gsk_path_measure_get_length(value self)
{
CAMLparam1(self);

float result = gsk_path_measure_get_length(GskPathMeasure_val(self));
CAMLreturn(caml_copy_double(result));
}


CAMLprim value ml_gsk_path_measure_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_path_measure_get_type()));
}

#else


CAMLexport CAMLprim value ml_gsk_path_measure_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("PathMeasure requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_measure_new_with_tolerance(value arg1, value arg2)
{
CAMLparam2(arg1, arg2);
(void)arg1;
(void)arg2;
caml_failwith("PathMeasure requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_measure_get_length(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PathMeasure requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_measure_get_path(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PathMeasure requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_measure_get_point(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("PathMeasure requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_measure_get_tolerance(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PathMeasure requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_measure_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("PathMeasure requires GTK >= 4.14");
return Val_unit;
}


#endif
