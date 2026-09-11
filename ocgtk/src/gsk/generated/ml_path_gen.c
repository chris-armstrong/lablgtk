/* GENERATED CODE - DO NOT EDIT */
/* C bindings for Path */

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
/* Conversion functions for GskPath (opaque record with hidden fields) */
GskPath *GskPath_val(value v) {
  return (GskPath *)ml_gir_record_ptr_val(v, "GskPath");
}

value Val_GskPath(const GskPath *ptr) {
  if (ptr == NULL) return Val_none;
  return ml_gir_record_val_ptr_with_type(gsk_path_get_type(), ptr);
}

value Val_GskPath_option(const GskPath *ptr) {
  if (ptr == NULL) return Val_none;
  return Val_some(Val_GskPath(ptr));
}
#endif

#if GTK_CHECK_VERSION(4,14,0)


CAMLexport CAMLprim value ml_gsk_path_to_string(value self)
{
CAMLparam1(self);

char* result = gsk_path_to_string(GskPath_val(self));
CAMLreturn(caml_copy_string(result));
}

CAMLexport CAMLprim value ml_gsk_path_to_cairo(value self, value arg1)
{
CAMLparam2(self, arg1);

gsk_path_to_cairo(GskPath_val(self), cairo_t_val(arg1));
CAMLreturn(Val_unit);
}

CAMLexport CAMLprim value ml_gsk_path_ref(value self)
{
CAMLparam1(self);

GskPath* result = gsk_path_ref(GskPath_val(self));
CAMLreturn(Val_GskPath(result));
}

CAMLexport CAMLprim value ml_gsk_path_is_empty(value self)
{
CAMLparam1(self);

gboolean result = gsk_path_is_empty(GskPath_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gsk_path_is_closed(value self)
{
CAMLparam1(self);

gboolean result = gsk_path_is_closed(GskPath_val(self));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gsk_path_in_fill(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);

gboolean result = gsk_path_in_fill(GskPath_val(self), graphene_point_t_val(arg1), GskFillRule_val(arg2));
CAMLreturn(Val_bool(result));
}

CAMLexport CAMLprim value ml_gsk_path_get_stroke_bounds(value self, value arg1)
{
CAMLparam2(self, arg1);
graphene_rect_t out2;

gboolean result = gsk_path_get_stroke_bounds(GskPath_val(self), GskStroke_val(arg1), &out2);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_graphene_rect_t(&out2));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gsk_path_get_start_point(value self)
{
CAMLparam1(self);
GskPathPoint out1;

gboolean result = gsk_path_get_start_point(GskPath_val(self), &out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GskPathPoint(&out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gsk_path_get_end_point(value self)
{
CAMLparam1(self);
GskPathPoint out1;

gboolean result = gsk_path_get_end_point(GskPath_val(self), &out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GskPathPoint(&out1));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gsk_path_get_closest_point(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
GskPathPoint out3;
float out4;

gboolean result = gsk_path_get_closest_point(GskPath_val(self), graphene_point_t_val(arg1), Double_val(arg2), &out3, &out4);
CAMLlocal1(ret);
    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_GskPathPoint(&out3));
    Store_field(ret, 2, caml_copy_double(out4));
    CAMLreturn(ret);
}

CAMLexport CAMLprim value ml_gsk_path_get_bounds(value self)
{
CAMLparam1(self);
graphene_rect_t out1;

gboolean result = gsk_path_get_bounds(GskPath_val(self), &out1);
CAMLlocal1(ret);
    ret = caml_alloc(2, 0);
    Store_field(ret, 0, Val_bool(result));
    Store_field(ret, 1, Val_graphene_rect_t(&out1));
    CAMLreturn(ret);
}

GType gsk_path_get_type (void);


CAMLprim value ml_gsk_path_get_type(value unit)
{
  CAMLparam1(unit);
  CAMLreturn(Val_long(gsk_path_get_type()));
}

#else


CAMLexport CAMLprim value ml_gsk_path_get_bounds(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Path requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_get_closest_point(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Path requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_get_end_point(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Path requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_get_start_point(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Path requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_get_stroke_bounds(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Path requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_in_fill(value self, value arg1, value arg2)
{
CAMLparam3(self, arg1, arg2);
(void)self;
(void)arg1;
(void)arg2;
caml_failwith("Path requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_is_closed(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Path requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_is_empty(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Path requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_ref(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Path requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_to_cairo(value self, value arg1)
{
CAMLparam2(self, arg1);
(void)self;
(void)arg1;
caml_failwith("Path requires GTK >= 4.14");
return Val_unit;
}


CAMLexport CAMLprim value ml_gsk_path_to_string(value self)
{
CAMLparam1(self);
(void)self;
caml_failwith("Path requires GTK >= 4.14");
return Val_unit;
}


#endif
