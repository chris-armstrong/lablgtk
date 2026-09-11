/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Stroke */

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
/* Conversion functions for GskStroke (opaque record with hidden fields) */
GskStroke *GskStroke_val(value v) {
  return (GskStroke *)ml_gir_record_ptr_val(v, "GskStroke");
}

value Val_GskStroke(const GskStroke *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gsk_stroke_get_type(), ptr);
}

value Val_GskStroke_option(const GskStroke *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GskStroke(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gsk_stroke_new(value arg1)
{
CAMLparam1(arg1);

GskStroke *obj = gsk_stroke_new(Double_val(arg1));

CAMLreturn(Val_GskStroke(obj));
}
CAMLexport CAMLprim value ml_gsk_stroke_to_cairo(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_stroke_to_cairo(GskStroke_val(self), cairo_t_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_stroke_set_miter_limit(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_stroke_set_miter_limit(GskStroke_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_stroke_set_line_width(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_stroke_set_line_width(GskStroke_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_stroke_set_line_join(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_stroke_set_line_join(GskStroke_val(self), GskLineJoin_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_stroke_set_line_cap(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_stroke_set_line_cap(GskStroke_val(self), GskLineCap_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_stroke_set_dash_offset(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_stroke_set_dash_offset(GskStroke_val(self), Double_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_stroke_set_dash(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
    int arg1_length = 0;
    float* c_arg1 = NULL;
    
    if (Is_some(arg1)) {
        value array = Some_val(arg1);
        arg1_length = Wosize_val(array);
        c_arg1 = (float*)g_malloc(sizeof(float) * arg1_length);
        for (int i = 0; i < arg1_length; i++) {
          c_arg1[i] = Double_val(Field(array, i));
        }
    }

gsk_stroke_set_dash(GskStroke_val(self), c_arg1, Gsize_val(arg2));
    if (c_arg1) g_free(c_arg1);
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_stroke_get_miter_limit(value self)
{
CAMLparam1(self);

float result = gsk_stroke_get_miter_limit(GskStroke_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_stroke_get_line_width(value self)
{
CAMLparam1(self);

float result = gsk_stroke_get_line_width(GskStroke_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_stroke_get_line_join(value self)
{
CAMLparam1(self);

GskLineJoin result = gsk_stroke_get_line_join(GskStroke_val(self));
CAMLreturn(Val_GskLineJoin(result));
}

CAMLexport CAMLprim value ml_gsk_stroke_get_line_cap(value self)
{
CAMLparam1(self);

GskLineCap result = gsk_stroke_get_line_cap(GskStroke_val(self));
CAMLreturn(Val_GskLineCap(result));
}

CAMLexport CAMLprim value ml_gsk_stroke_get_dash_offset(value self)
{
CAMLparam1(self);

float result = gsk_stroke_get_dash_offset(GskStroke_val(self));
CAMLreturn(caml_copy_double(result));
}

CAMLexport CAMLprim value ml_gsk_stroke_get_dash(value self)
{
CAMLparam1(self);
gsize out1;

const float* result = gsk_stroke_get_dash(GskStroke_val(self), &out1);
    CAMLlocal2(ml_result, ml_result_opt);
    if (result == NULL) {
      ml_result_opt = Val_none;
    } else {
      int result_length = out1;
      ml_result = caml_alloc(result_length, 0);
      for (int i = 0; i < result_length; i++) {
        Store_field(ml_result, i, caml_copy_double(result[i]));
      }
      ml_result_opt = Val_some(ml_result);
          }
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, ml_result_opt);
    Store_field(ret, 1, Val_gsize(out1));
    CAMLreturn(ret);
}

GType gsk_stroke_get_type (void);


CAMLprim value ml_gsk_stroke_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_stroke_get_type()));
}

#else


CAMLexport CAMLprim value ml_gsk_stroke_new(value arg1)
{
CAMLparam1(arg1);
(void)arg1;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_get_dash(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_get_dash_offset(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_get_line_cap(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_get_line_join(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_get_line_width(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_get_miter_limit(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_set_dash(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_set_dash_offset(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_set_line_cap(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_set_line_join(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_set_line_width(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_set_miter_limit(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_stroke_to_cairo(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Stroke requires GTK >= 4.14");
return Val_unit;
}


#endif
